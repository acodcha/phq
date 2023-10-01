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

// Kinematic pressure difference. Kinematic pressure is pressure divided by mass
// density, so kinematic pressure difference is pressure difference divided by
// mass density.
class KinematicPressureDifference
  : public DimensionalScalarQuantity<Unit::SpecificEnergy> {
public:
  // Default constructor. Constructs a kinematic pressure difference with an
  // uninitialized value.
  KinematicPressureDifference() = default;

  // Constructor. Constructs a kinematic pressure difference with a given value
  // expressed in a given specific energy unit.
  KinematicPressureDifference(
      const double value, const Unit::SpecificEnergy unit)
    : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  // Constructor. Constructs a kinematic pressure difference from a given
  // pressure difference and mass density using the definition of kinematic
  // pressure difference.
  constexpr KinematicPressureDifference(
      const PressureDifference& pressure_difference,
      const MassDensity& mass_density)
    : KinematicPressureDifference(
        pressure_difference.Value() / mass_density.Value()) {}

  // Destructor. Destroys this kinematic pressure difference.
  ~KinematicPressureDifference() noexcept = default;

  // Copy constructor. Constructs a kinematic pressure difference by copying
  // another one.
  constexpr KinematicPressureDifference(
      const KinematicPressureDifference& other) = default;

  // Move constructor. Constructs a kinematic pressure difference by moving
  // another one.
  constexpr KinematicPressureDifference(
      KinematicPressureDifference&& other) noexcept = default;

  // Copy assignment operator. Assigns this kinematic pressure difference by
  // copying another one.
  constexpr KinematicPressureDifference& operator=(
      const KinematicPressureDifference& other) = default;

  // Move assignment operator. Assigns this kinematic pressure difference by
  // moving another one.
  constexpr KinematicPressureDifference& operator=(
      KinematicPressureDifference&& other) noexcept = default;

  // Statically creates a kinematic pressure difference of zero.
  static constexpr KinematicPressureDifference Zero() {
    return KinematicPressureDifference{0.0};
  }

  // Statically creates a kinematic pressure difference with a given value
  // expressed in a given specific energy unit.
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
  // Constructor. Constructs a kinematic pressure difference with a given value
  // expressed in the standard specific energy unit.
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
