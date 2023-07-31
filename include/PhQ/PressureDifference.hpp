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

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declarations for class PressureDifference.
class KinematicPressureDifference;
class MassDensity;
class StaticPressure;

// Pressure difference.
class PressureDifference : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  constexpr PressureDifference() noexcept
    : DimensionalScalarQuantity<Unit::Pressure>() {}

  PressureDifference(const double value, const Unit::Pressure unit) noexcept
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr PressureDifference(
      const KinematicPressureDifference& kinematic_pressure_difference,
      const MassDensity& mass_density) noexcept;

  static constexpr PressureDifference Zero() noexcept {
    return PressureDifference{0.0};
  }

  template<Unit::Pressure Unit>
  static constexpr PressureDifference Create(const double value) noexcept {
    return PressureDifference{
        StaticConvertCopy<Unit::Pressure, Unit, StandardUnit<Unit::Pressure>>(
            value)};
  }

  inline constexpr StaticPressure operator+(
      const StaticPressure& static_pressure) const noexcept;

  inline constexpr PressureDifference operator+(
      const PressureDifference& pressure_difference) const noexcept {
    return PressureDifference{value_ + pressure_difference.value_};
  }

  inline constexpr StaticPressure operator-(
      const StaticPressure& static_pressure) const noexcept;

  inline constexpr PressureDifference operator-(
      const PressureDifference& pressure_difference) const noexcept {
    return PressureDifference{value_ - pressure_difference.value_};
  }

  inline constexpr PressureDifference operator*(
      const double number) const noexcept {
    return PressureDifference{value_ * number};
  }

  inline constexpr PressureDifference operator/(
      const double number) const noexcept {
    return PressureDifference{value_ / number};
  }

  inline constexpr KinematicPressureDifference operator/(
      const MassDensity& mass_density) const noexcept;

  inline constexpr double operator/(
      const PressureDifference& pressure_difference) const noexcept {
    return value_ / pressure_difference.value_;
  }

  inline constexpr void operator+=(
      const PressureDifference& pressure_difference) noexcept {
    value_ += pressure_difference.value_;
  }

  inline constexpr void operator-=(
      const PressureDifference& pressure_difference) noexcept {
    value_ -= pressure_difference.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr PressureDifference(const double value) noexcept
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
    std::ostream& stream,
    const PressureDifference& pressure_difference) noexcept {
  stream << pressure_difference.Print();
  return stream;
}

inline constexpr PressureDifference operator*(
    const double number,
    const PressureDifference& pressure_difference) noexcept {
  return pressure_difference * number;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::PressureDifference> {
  size_t operator()(const PhQ::PressureDifference& pressure_difference) const {
    return hash<double>()(pressure_difference.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_PRESSURE_DIFFERENCE_HPP
