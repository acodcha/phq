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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_AREA_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_AREA_HPP

#include "Length.hpp"
#include "Unit/Area.hpp"

namespace PhQ {

// Forward declarations for class Area.
class AreaVector;
class Direction;
class Force;
class ForceMagnitude;
class StaticPressure;
class Traction;

// Area. Scalar quantity. Can also represent the magnitude of a vector area.
class Area : public DimensionalScalarQuantity<Unit::Area> {
public:
  constexpr Area() noexcept : DimensionalScalarQuantity<Unit::Area>() {}

  Area(const double value, const Unit::Area unit) noexcept
    : DimensionalScalarQuantity<Unit::Area>(value, unit) {}

  Area(const AreaVector& area_vector) noexcept;

  constexpr Area(const StaticPressure& static_pressure,
                 const ForceMagnitude& force_magnitude) noexcept;

  static constexpr Area Zero() noexcept { return Area{0.0}; }

  template<Unit::Area Unit>
  static constexpr Area Create(const double value) noexcept {
    return Area{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(value)};
  }

  inline constexpr Area operator+(const Area& area) const noexcept {
    return Area{value_ + area.value_};
  }

  inline constexpr Area operator-(const Area& area) const noexcept {
    return Area{value_ - area.value_};
  }

  inline constexpr Area operator*(const double number) const noexcept {
    return Area{value_ * number};
  }

  inline constexpr Volume operator*(const Length& length) const noexcept;

  inline constexpr ForceMagnitude operator*(
      const StaticPressure& static_pressure) const noexcept;

  inline constexpr AreaVector operator*(
      const Direction& direction) const noexcept;

  inline constexpr Area operator/(const double number) const noexcept {
    return Area{value_ / number};
  }

  inline constexpr Length operator/(const Length& length) const noexcept {
    return Length{value_ / length.Value()};
  }

  inline constexpr double operator/(const Area& area) const noexcept {
    return value_ / area.value_;
  }

  inline constexpr void operator+=(const Area& area) noexcept {
    value_ += area.value_;
  }

  inline constexpr void operator-=(const Area& area) noexcept {
    value_ -= area.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Area(const double value) noexcept
    : DimensionalScalarQuantity<Unit::Area>(value) {}

  friend class Length;
  friend class Volume;
};

inline constexpr bool operator==(const Area& left, const Area& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Area& left, const Area& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Area& left, const Area& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Area& left, const Area& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Area& left, const Area& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Area& left, const Area& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Area& area) noexcept {
  stream << area.Print();
  return stream;
}

inline constexpr Area operator*(
    const double number, const Area& area) noexcept {
  return area * number;
}

inline constexpr Area Length::operator*(const Length& length) const noexcept {
  return Area{value_ * length.Value()};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::Area> {
  size_t operator()(const PhQ::Area& area) const {
    return hash<double>()(area.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_AREA_HPP
