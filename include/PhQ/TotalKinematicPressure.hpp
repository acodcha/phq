// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TOTAL_KINEMATIC_PRESSURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TOTAL_KINEMATIC_PRESSURE_HPP

#include "DynamicKinematicPressure.hpp"
#include "TotalPressure.hpp"

namespace PhQ {

// Total kinematic pressure.
class TotalKinematicPressure
  : public DimensionalScalarQuantity<Unit::SpecificEnergy> {
public:
  constexpr TotalKinematicPressure() noexcept
    : DimensionalScalarQuantity<Unit::SpecificEnergy>() {}

  TotalKinematicPressure(
      const double value, const Unit::SpecificEnergy unit) noexcept
    : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr TotalKinematicPressure(
      const DynamicKinematicPressure& dynamic_kinematic_pressure,
      const StaticKinematicPressure& static_kinematic_pressure) noexcept
    : TotalKinematicPressure(dynamic_kinematic_pressure.Value()
                             + static_kinematic_pressure.Value()) {}

  constexpr TotalKinematicPressure(const TotalPressure& total_pressure,
                                   const MassDensity& mass_density) noexcept
    : TotalKinematicPressure(total_pressure.Value() / mass_density.Value()) {}

  static constexpr TotalKinematicPressure Zero() noexcept {
    return TotalKinematicPressure{0.0};
  }

  template<Unit::SpecificEnergy Unit>
  static constexpr TotalKinematicPressure Create(const double value) noexcept {
    return TotalKinematicPressure{
        StaticConvertCopy<Unit::SpecificEnergy, Unit,
                          Standard<Unit::SpecificEnergy>>(value)};
  }

  inline constexpr TotalKinematicPressure operator+(
      const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return TotalKinematicPressure{value_ + total_kinematic_pressure.value_};
  }

  inline constexpr TotalKinematicPressure operator-(
      const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return TotalKinematicPressure{value_ - total_kinematic_pressure.value_};
  }

  inline constexpr DynamicKinematicPressure operator-(
      const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return {*this, static_kinematic_pressure};
  }

  inline constexpr StaticKinematicPressure
  operator-(const DynamicKinematicPressure& dynamic_kinematic_pressure)
      const noexcept {
    return {*this, dynamic_kinematic_pressure};
  }

  inline constexpr TotalKinematicPressure operator*(
      const double number) const noexcept {
    return TotalKinematicPressure{value_ * number};
  }

  inline constexpr TotalKinematicPressure operator/(
      const double number) const noexcept {
    return TotalKinematicPressure{value_ / number};
  }

  inline constexpr double operator/(
      const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return value_ / total_kinematic_pressure.value_;
  }

  inline constexpr void operator+=(
      const TotalKinematicPressure& total_kinematic_pressure) noexcept {
    value_ += total_kinematic_pressure.value_;
  }

  inline constexpr void operator-=(
      const TotalKinematicPressure& total_kinematic_pressure) noexcept {
    value_ -= total_kinematic_pressure.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr TotalKinematicPressure(const double value) noexcept
    : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}
};

inline constexpr bool operator==(const TotalKinematicPressure& left,
                                 const TotalKinematicPressure& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const TotalKinematicPressure& left,
                                 const TotalKinematicPressure& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const TotalKinematicPressure& left,
                                const TotalKinematicPressure& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const TotalKinematicPressure& left,
                                const TotalKinematicPressure& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const TotalKinematicPressure& left,
                                 const TotalKinematicPressure& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const TotalKinematicPressure& left,
                                 const TotalKinematicPressure& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const TotalKinematicPressure& total_kinematic_pressure) noexcept {
  stream << total_kinematic_pressure.Print();
  return stream;
}

inline constexpr TotalKinematicPressure operator*(
    const double number,
    const TotalKinematicPressure& total_kinematic_pressure) noexcept {
  return total_kinematic_pressure * number;
}

inline constexpr TotalPressure::TotalPressure(
    const TotalKinematicPressure& total_kinematic_pressure,
    const MassDensity& mass_density) noexcept
  : TotalPressure(total_kinematic_pressure.Value() * mass_density.Value()) {}

inline constexpr StaticKinematicPressure::StaticKinematicPressure(
    const TotalKinematicPressure& total_kinematic_pressure,
    const DynamicKinematicPressure& dynamic_kinematic_pressure) noexcept
  : StaticKinematicPressure(
      total_kinematic_pressure.Value() - dynamic_kinematic_pressure.Value()) {}

inline constexpr DynamicKinematicPressure::DynamicKinematicPressure(
    const TotalKinematicPressure& total_kinematic_pressure,
    const StaticKinematicPressure& static_kinematic_pressure) noexcept
  : DynamicKinematicPressure(
      total_kinematic_pressure.Value() - static_kinematic_pressure.Value()) {}

inline constexpr TotalKinematicPressure StaticKinematicPressure::operator+(
    const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept {
  return {dynamic_kinematic_pressure, *this};
}

inline constexpr TotalKinematicPressure DynamicKinematicPressure::operator+(
    const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
  return {*this, static_kinematic_pressure};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::TotalKinematicPressure> {
  size_t operator()(
      const PhQ::TotalKinematicPressure& total_kinematic_pressure) const {
    return hash<double>()(total_kinematic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TOTAL_KINEMATIC_PRESSURE_HPP
