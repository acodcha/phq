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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_STATIC_KINEMATIC_PRESSURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_STATIC_KINEMATIC_PRESSURE_HPP

#include "KinematicPressureDifference.hpp"
#include "StaticPressure.hpp"

namespace PhQ {

// Forward declarations for class StaticKinematicPressure.
class DynamicKinematicPressure;
class TotalKinematicPressure;

// Static kinematic pressure.
class StaticKinematicPressure
  : public DimensionalScalarQuantity<Unit::SpecificEnergy> {
public:
  constexpr StaticKinematicPressure() noexcept
    : DimensionalScalarQuantity<Unit::SpecificEnergy>() {}

  StaticKinematicPressure(
      const double value, const Unit::SpecificEnergy unit) noexcept
    : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr StaticKinematicPressure(
      const TotalKinematicPressure& total_kinematic_pressure,
      const DynamicKinematicPressure& dynamic_kinematic_pressure) noexcept;

  constexpr StaticKinematicPressure(const StaticPressure& static_pressure,
                                    const MassDensity& mass_density) noexcept
    : StaticKinematicPressure(static_pressure.Value() / mass_density.Value()) {}

  static constexpr StaticKinematicPressure Zero() noexcept {
    return StaticKinematicPressure{0.0};
  }

  template <Unit::SpecificEnergy Unit>
  static constexpr StaticKinematicPressure Create(const double value) noexcept {
    return StaticKinematicPressure{
        StaticConvertCopy<Unit::SpecificEnergy, Unit,
                          Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr StaticKinematicPressure operator+(
      const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return StaticKinematicPressure{value_ + static_kinematic_pressure.value_};
  }

  constexpr StaticKinematicPressure
  operator+(const KinematicPressureDifference& kinematic_pressure_difference)
      const noexcept {
    return StaticKinematicPressure{
        value_ + kinematic_pressure_difference.Value()};
  }

  constexpr TotalKinematicPressure
  operator+(const DynamicKinematicPressure& dynamic_kinematic_pressure)
      const noexcept;

  constexpr KinematicPressureDifference operator-(
      const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return KinematicPressureDifference{
        value_ - static_kinematic_pressure.value_};
  }

  constexpr StaticKinematicPressure
  operator-(const KinematicPressureDifference& kinematic_pressure_difference)
      const noexcept {
    return StaticKinematicPressure{
        value_ - kinematic_pressure_difference.Value()};
  }

  constexpr StaticKinematicPressure operator*(
      const double number) const noexcept {
    return StaticKinematicPressure{value_ * number};
  }

  constexpr StaticPressure operator*(
      const MassDensity& mass_density) const noexcept {
    return {*this, mass_density};
  }

  constexpr StaticKinematicPressure operator/(
      const double number) const noexcept {
    return StaticKinematicPressure{value_ / number};
  }

  constexpr double operator/(
      const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return value_ / static_kinematic_pressure.value_;
  }

  constexpr void operator+=(
      const StaticKinematicPressure& static_kinematic_pressure) noexcept {
    value_ += static_kinematic_pressure.value_;
  }

  constexpr void operator+=(const KinematicPressureDifference&
                                kinematic_pressure_difference) noexcept {
    value_ += kinematic_pressure_difference.Value();
  }

  constexpr void operator-=(
      const StaticKinematicPressure& static_kinematic_pressure) noexcept {
    value_ -= static_kinematic_pressure.value_;
  }

  constexpr void operator-=(const KinematicPressureDifference&
                                kinematic_pressure_difference) noexcept {
    value_ -= kinematic_pressure_difference.Value();
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr StaticKinematicPressure(const double value) noexcept
    : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}

  friend class KinematicPressureDifference;
};

inline constexpr bool operator==(
    const StaticKinematicPressure& left,
    const StaticKinematicPressure& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const StaticKinematicPressure& left,
    const StaticKinematicPressure& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const StaticKinematicPressure& left,
                                const StaticKinematicPressure& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const StaticKinematicPressure& left,
                                const StaticKinematicPressure& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const StaticKinematicPressure& left,
    const StaticKinematicPressure& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const StaticKinematicPressure& left,
    const StaticKinematicPressure& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const StaticKinematicPressure& static_kinematic_pressure) noexcept {
  stream << static_kinematic_pressure.Print();
  return stream;
}

inline constexpr StaticKinematicPressure operator*(
    const double number,
    const StaticKinematicPressure& static_kinematic_pressure) noexcept {
  return static_kinematic_pressure * number;
}

inline constexpr StaticPressure::StaticPressure(
    const StaticKinematicPressure& static_kinematic_pressure,
    const MassDensity& mass_density) noexcept
  : StaticPressure(static_kinematic_pressure.Value() * mass_density.Value()) {}

inline constexpr StaticKinematicPressure StaticPressure::operator/(
    const MassDensity& mass_density) const noexcept {
  return {*this, mass_density};
}

inline constexpr StaticKinematicPressure KinematicPressureDifference::operator+(
    const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
  return StaticKinematicPressure{value_ + static_kinematic_pressure.Value()};
}

inline constexpr StaticKinematicPressure KinematicPressureDifference::operator-(
    const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
  return StaticKinematicPressure{value_ - static_kinematic_pressure.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::StaticKinematicPressure> {
  inline size_t operator()(
      const PhQ::StaticKinematicPressure& static_kinematic_pressure) const {
    return hash<double>()(static_kinematic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_STATIC_KINEMATIC_PRESSURE_HPP
