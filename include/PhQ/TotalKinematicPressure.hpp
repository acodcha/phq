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
  constexpr TotalKinematicPressure()
    : DimensionalScalarQuantity<Unit::SpecificEnergy>() {}

  TotalKinematicPressure(const double value, const Unit::SpecificEnergy unit)
    : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr TotalKinematicPressure(
      const DynamicKinematicPressure& dynamic_kinematic_pressure,
      const StaticKinematicPressure& static_kinematic_pressure)
    : TotalKinematicPressure(dynamic_kinematic_pressure.Value()
                             + static_kinematic_pressure.Value()) {}

  constexpr TotalKinematicPressure(
      const TotalPressure& total_pressure, const MassDensity& mass_density)
    : TotalKinematicPressure(total_pressure.Value() / mass_density.Value()) {}

  static constexpr TotalKinematicPressure Zero() {
    return TotalKinematicPressure{0.0};
  }

  template <Unit::SpecificEnergy Unit>
  static constexpr TotalKinematicPressure Create(const double value) {
    return TotalKinematicPressure{
        StaticConvertCopy<Unit::SpecificEnergy, Unit,
                          Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr TotalKinematicPressure operator+(
      const TotalKinematicPressure& total_kinematic_pressure) const {
    return TotalKinematicPressure{value_ + total_kinematic_pressure.value_};
  }

  constexpr TotalKinematicPressure operator-(
      const TotalKinematicPressure& total_kinematic_pressure) const {
    return TotalKinematicPressure{value_ - total_kinematic_pressure.value_};
  }

  constexpr DynamicKinematicPressure operator-(
      const StaticKinematicPressure& static_kinematic_pressure) const {
    return {*this, static_kinematic_pressure};
  }

  constexpr StaticKinematicPressure operator-(
      const DynamicKinematicPressure& dynamic_kinematic_pressure) const {
    return {*this, dynamic_kinematic_pressure};
  }

  constexpr TotalKinematicPressure operator*(const double number) const {
    return TotalKinematicPressure{value_ * number};
  }

  constexpr TotalKinematicPressure operator/(const double number) const {
    return TotalKinematicPressure{value_ / number};
  }

  constexpr double operator/(
      const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return value_ / total_kinematic_pressure.value_;
  }

  constexpr void operator+=(
      const TotalKinematicPressure& total_kinematic_pressure) noexcept {
    value_ += total_kinematic_pressure.value_;
  }

  constexpr void operator-=(
      const TotalKinematicPressure& total_kinematic_pressure) noexcept {
    value_ -= total_kinematic_pressure.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr TotalKinematicPressure(const double value)
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
    const TotalKinematicPressure& total_kinematic_pressure) {
  stream << total_kinematic_pressure.Print();
  return stream;
}

inline constexpr TotalKinematicPressure operator*(
    const double number,
    const TotalKinematicPressure& total_kinematic_pressure) {
  return total_kinematic_pressure * number;
}

inline constexpr TotalPressure::TotalPressure(
    const TotalKinematicPressure& total_kinematic_pressure,
    const MassDensity& mass_density)
  : TotalPressure(total_kinematic_pressure.Value() * mass_density.Value()) {}

inline constexpr StaticKinematicPressure::StaticKinematicPressure(
    const TotalKinematicPressure& total_kinematic_pressure,
    const DynamicKinematicPressure& dynamic_kinematic_pressure)
  : StaticKinematicPressure(
      total_kinematic_pressure.Value() - dynamic_kinematic_pressure.Value()) {}

inline constexpr DynamicKinematicPressure::DynamicKinematicPressure(
    const TotalKinematicPressure& total_kinematic_pressure,
    const StaticKinematicPressure& static_kinematic_pressure)
  : DynamicKinematicPressure(
      total_kinematic_pressure.Value() - static_kinematic_pressure.Value()) {}

inline constexpr TotalKinematicPressure StaticKinematicPressure::operator+(
    const DynamicKinematicPressure& dynamic_kinematic_pressure) const {
  return {dynamic_kinematic_pressure, *this};
}

inline constexpr TotalKinematicPressure DynamicKinematicPressure::operator+(
    const StaticKinematicPressure& static_kinematic_pressure) const {
  return {*this, static_kinematic_pressure};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::TotalKinematicPressure> {
  inline size_t operator()(
      const PhQ::TotalKinematicPressure& total_kinematic_pressure) const {
    return hash<double>()(total_kinematic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TOTAL_KINEMATIC_PRESSURE_HPP
