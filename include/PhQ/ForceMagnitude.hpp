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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_MAGNITUDE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_MAGNITUDE_HPP

#include "Area.hpp"
#include "Unit/Force.hpp"

namespace PhQ {

// Forward declarations for class ForceMagnitude.
class Direction;
class Force;
class StaticPressure;

// Force scalar. Magnitude of the force vector.
class ForceMagnitude : public DimensionalScalarQuantity<Unit::Force> {
public:
  constexpr ForceMagnitude() noexcept
    : DimensionalScalarQuantity<Unit::Force>() {}

  ForceMagnitude(const double value, const Unit::Force unit) noexcept
    : DimensionalScalarQuantity<Unit::Force>(value, unit) {}

  constexpr ForceMagnitude(const Force& force) noexcept;

  inline constexpr ForceMagnitude(
      const StaticPressure& static_pressure, const Area& area) noexcept;

  static constexpr ForceMagnitude Zero() noexcept {
    return ForceMagnitude{0.0};
  }

  template<Unit::Force Unit>
  static constexpr ForceMagnitude Create(const double value) noexcept {
    return ForceMagnitude{
        StaticConvertCopy<Unit::Force, Unit, StandardUnit<Unit::Force>>(value)};
  }

  inline constexpr ForceMagnitude operator+(
      const ForceMagnitude& force_magnitude) const noexcept {
    return ForceMagnitude{value_ + force_magnitude.value_};
  }

  inline constexpr ForceMagnitude operator-(
      const ForceMagnitude& force_magnitude) const noexcept {
    return ForceMagnitude{value_ - force_magnitude.value_};
  }

  inline constexpr ForceMagnitude operator*(
      const double number) const noexcept {
    return ForceMagnitude{value_ * number};
  }

  inline constexpr Force operator*(const Direction& direction) const noexcept;

  inline constexpr ForceMagnitude operator/(
      const double number) const noexcept {
    return ForceMagnitude{value_ / number};
  }

  inline constexpr StaticPressure operator/(const Area& area) const noexcept;

  inline constexpr void operator+=(
      const ForceMagnitude& force_magnitude) noexcept {
    value_ += force_magnitude.value_;
  }

  inline constexpr void operator-=(
      const ForceMagnitude& force_magnitude) noexcept {
    value_ -= force_magnitude.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr ForceMagnitude(const double value) noexcept
    : DimensionalScalarQuantity<Unit::Force>(value) {}
};

inline constexpr bool operator==(
    const ForceMagnitude& left, const ForceMagnitude& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ForceMagnitude& left, const ForceMagnitude& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ForceMagnitude& left, const ForceMagnitude& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ForceMagnitude& left, const ForceMagnitude& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ForceMagnitude& left, const ForceMagnitude& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ForceMagnitude& left, const ForceMagnitude& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const ForceMagnitude& force_magnitude) noexcept {
  stream << force_magnitude.Print();
  return stream;
}

inline constexpr ForceMagnitude operator*(
    const double number, const ForceMagnitude& force_magnitude) noexcept {
  return force_magnitude * number;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::ForceMagnitude> {
  size_t operator()(const PhQ::ForceMagnitude& force_magnitude) const {
    return hash<double>()(force_magnitude.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_MAGNITUDE_HPP
