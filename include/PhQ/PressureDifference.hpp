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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_PRESSURE_DIFFERENCE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_PRESSURE_DIFFERENCE_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declarations for class PressureDifference.
class KinematicPressureDifference;
class MassDensity;
class StaticPressure;

// Pressure difference.
class PressureDifference : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  // Default constructor. Constructs a pressure difference with an uninitialized
  // value.
  PressureDifference() = default;

  // Constructor. Constructs a pressure difference with a given value expressed
  // in a given pressure unit.
  PressureDifference(const double value, const Unit::Pressure unit)
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  // Constructor. Constructs a pressure difference from a given kinematic
  // pressure difference and mass density using the definition of kinematic
  // pressure difference.
  constexpr PressureDifference(
      const KinematicPressureDifference& kinematic_pressure_difference,
      const MassDensity& mass_density);

  // Destructor. Destroys this pressure difference.
  ~PressureDifference() noexcept = default;

  // Copy constructor. Constructs a pressure difference by copying another one.
  constexpr PressureDifference(const PressureDifference& other) = default;

  // Move constructor. Constructs a pressure difference by moving another one.
  constexpr PressureDifference(PressureDifference&& other) noexcept = default;

  // Copy assignment operator. Assigns this pressure difference by copying
  // another one.
  constexpr PressureDifference& operator=(
      const PressureDifference& other) = default;

  // Move assignment operator. Assigns this pressure difference by moving
  // another one.
  constexpr PressureDifference& operator=(
      PressureDifference&& other) noexcept = default;

  // Statically creates a pressure difference of zero.
  static constexpr PressureDifference Zero() {
    return PressureDifference{0.0};
  }

  // Statically creates a pressure difference with a given value expressed in a
  // given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr PressureDifference Create(const double value) {
    return PressureDifference{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            value)};
  }

  constexpr StaticPressure operator+(
      const StaticPressure& static_pressure) const;

  constexpr PressureDifference operator+(
      const PressureDifference& pressure_difference) const {
    return PressureDifference{value_ + pressure_difference.value_};
  }

  constexpr StaticPressure operator-(
      const StaticPressure& static_pressure) const;

  constexpr PressureDifference operator-(
      const PressureDifference& pressure_difference) const {
    return PressureDifference{value_ - pressure_difference.value_};
  }

  constexpr PressureDifference operator*(const double number) const {
    return PressureDifference{value_ * number};
  }

  constexpr PressureDifference operator/(const double number) const {
    return PressureDifference{value_ / number};
  }

  constexpr KinematicPressureDifference operator/(
      const MassDensity& mass_density) const;

  constexpr double operator/(
      const PressureDifference& pressure_difference) const noexcept {
    return value_ / pressure_difference.value_;
  }

  constexpr void operator+=(
      const PressureDifference& pressure_difference) noexcept {
    value_ += pressure_difference.value_;
  }

  constexpr void operator-=(
      const PressureDifference& pressure_difference) noexcept {
    value_ -= pressure_difference.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a pressure difference with a given value expressed
  // in the standard pressure unit.
  explicit constexpr PressureDifference(const double value)
    : DimensionalScalarQuantity<Unit::Pressure>(value) {}

  friend class StaticPressure;
};

inline constexpr bool operator==(
    const PressureDifference& left, const PressureDifference& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const PressureDifference& left, const PressureDifference& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const PressureDifference& left, const PressureDifference& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const PressureDifference& left, const PressureDifference& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const PressureDifference& left, const PressureDifference& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const PressureDifference& left, const PressureDifference& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const PressureDifference& pressure_difference) {
  stream << pressure_difference.Print();
  return stream;
}

inline constexpr PressureDifference operator*(
    const double number, const PressureDifference& pressure_difference) {
  return pressure_difference * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::PressureDifference> {
  inline size_t operator()(
      const PhQ::PressureDifference& pressure_difference) const {
    return hash<double>()(pressure_difference.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_PRESSURE_DIFFERENCE_HPP
