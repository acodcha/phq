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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_KINEMATIC_PRESSURE_DIFFERENCE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_KINEMATIC_PRESSURE_DIFFERENCE_HPP

#include "MassDensity.hpp"
#include "PressureDifference.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

// Forward declaration for class KinematicPressureDifference.
class StaticKinematicPressure;

// Kinematic pressure difference.
class KinematicPressureDifference
  : public DimensionalScalarQuantity<Unit::SpecificEnergy> {
public:
  constexpr KinematicPressureDifference()
    : DimensionalScalarQuantity<Unit::SpecificEnergy>() {}

  KinematicPressureDifference(
      const double value, const Unit::SpecificEnergy unit)
    : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr KinematicPressureDifference(
      const PressureDifference& pressure_difference,
      const MassDensity& mass_density)
    : KinematicPressureDifference(
        pressure_difference.Value() / mass_density.Value()) {}

  static constexpr KinematicPressureDifference Zero() {
    return KinematicPressureDifference{0.0};
  }

  template <Unit::SpecificEnergy Unit>
  static constexpr KinematicPressureDifference Create(const double value) {
    return KinematicPressureDifference{
        StaticConvertCopy<Unit::SpecificEnergy, Unit,
                          Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr StaticKinematicPressure operator+(
      const StaticKinematicPressure& kinematic_static_pressure) const;

  constexpr KinematicPressureDifference operator+(
      const KinematicPressureDifference& kinematic_pressure_difference) const {
    return KinematicPressureDifference{
        value_ + kinematic_pressure_difference.value_};
  }

  constexpr StaticKinematicPressure operator-(
      const StaticKinematicPressure& kinematic_static_pressure) const;

  constexpr KinematicPressureDifference operator-(
      const KinematicPressureDifference& kinematic_pressure_difference) const {
    return KinematicPressureDifference{
        value_ - kinematic_pressure_difference.value_};
  }

  constexpr KinematicPressureDifference operator*(const double number) const {
    return KinematicPressureDifference{value_ * number};
  }

  constexpr PressureDifference operator*(
      const MassDensity& mass_density) const {
    return {*this, mass_density};
  }

  constexpr KinematicPressureDifference operator/(const double number) const {
    return KinematicPressureDifference{value_ / number};
  }

  constexpr double
  operator/(const KinematicPressureDifference& kinematic_pressure_difference)
      const noexcept {
    return value_ / kinematic_pressure_difference.value_;
  }

  constexpr void operator+=(const KinematicPressureDifference&
                                kinematic_pressure_difference) noexcept {
    value_ += kinematic_pressure_difference.value_;
  }

  constexpr void operator-=(const KinematicPressureDifference&
                                kinematic_pressure_difference) noexcept {
    value_ -= kinematic_pressure_difference.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr KinematicPressureDifference(const double value)
    : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}

  friend class StaticKinematicPressure;
};

inline constexpr bool operator==(
    const KinematicPressureDifference& left,
    const KinematicPressureDifference& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const KinematicPressureDifference& left,
    const KinematicPressureDifference& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const KinematicPressureDifference& left,
    const KinematicPressureDifference& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const KinematicPressureDifference& left,
    const KinematicPressureDifference& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const KinematicPressureDifference& left,
    const KinematicPressureDifference& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const KinematicPressureDifference& left,
    const KinematicPressureDifference& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const KinematicPressureDifference& kinematic_pressure_difference) {
  stream << kinematic_pressure_difference.Print();
  return stream;
}

inline constexpr KinematicPressureDifference operator*(
    const double number,
    const KinematicPressureDifference& kinematic_pressure_difference) {
  return kinematic_pressure_difference * number;
}

inline constexpr PressureDifference::PressureDifference(
    const KinematicPressureDifference& kinematic_pressure_difference,
    const MassDensity& mass_density)
  : PressureDifference(
      kinematic_pressure_difference.Value() * mass_density.Value()) {}

inline constexpr KinematicPressureDifference PressureDifference::operator/(
    const MassDensity& mass_density) const {
  return {*this, mass_density};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::KinematicPressureDifference> {
  inline size_t operator()(
      const PhQ::KinematicPressureDifference& kinematic_pressure_difference)
      const {
    return hash<double>()(kinematic_pressure_difference.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_KINEMATIC_PRESSURE_DIFFERENCE_HPP
