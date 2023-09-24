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
  // Default constructor. Constructs an area with an uninitialized value.
  Area() = default;

  // Constructor. Constructs an area with a given value expressed in a given
  // area unit.
  Area(const double value, const Unit::Area unit)
    : DimensionalScalarQuantity<Unit::Area>(value, unit) {}

  // Constructor. Constructs an area from a given vector area.
  Area(const AreaVector& area_vector);

  // Constructor. Constructs an area from a given static pressure and force
  // magnitude using the definition of pressure.
  constexpr Area(const StaticPressure& static_pressure,
                 const ForceMagnitude& force_magnitude);

  // Destructor. Destroys this area.
  ~Area() noexcept = default;

  // Copy constructor. Constructs an area by copying another one.
  constexpr Area(const Area& other) = default;

  // Move constructor. Constructs an area by moving another one.
  constexpr Area(Area&& other) noexcept = default;

  // Copy assignment operator. Assigns this area by copying another one.
  constexpr Area& operator=(const Area& other) = default;

  // Move assignment operator. Assigns this area by moving another one.
  constexpr Area& operator=(Area&& other) noexcept = default;

  // Statically creates an area of zero.
  static constexpr Area Zero() {
    return Area{0.0};
  }

  // Statically creates an area with a given value expressed in a given area
  // unit.
  template <Unit::Area Unit>
  static constexpr Area Create(const double value) {
    return Area{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(value)};
  }

  constexpr Area operator+(const Area& area) const {
    return Area{value_ + area.value_};
  }

  constexpr Area operator-(const Area& area) const {
    return Area{value_ - area.value_};
  }

  constexpr Area operator*(const double number) const {
    return Area{value_ * number};
  }

  constexpr Volume operator*(const Length& length) const;

  constexpr ForceMagnitude operator*(
      const StaticPressure& static_pressure) const;

  constexpr AreaVector operator*(const Direction& direction) const;

  constexpr Area operator/(const double number) const {
    return Area{value_ / number};
  }

  constexpr Length operator/(const Length& length) const {
    return Length{value_ / length.Value()};
  }

  constexpr double operator/(const Area& area) const noexcept {
    return value_ / area.value_;
  }

  constexpr void operator+=(const Area& area) noexcept {
    value_ += area.value_;
  }

  constexpr void operator-=(const Area& area) noexcept {
    value_ -= area.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs an area with a given value expressed in the
  // standard area unit.
  explicit constexpr Area(const double value)
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

inline std::ostream& operator<<(std::ostream& stream, const Area& area) {
  stream << area.Print();
  return stream;
}

inline constexpr Area operator*(const double number, const Area& area) {
  return area * number;
}

inline constexpr Area Length::operator*(const Length& length) const {
  return Area{value_ * length.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Area> {
  inline size_t operator()(const PhQ::Area& area) const {
    return hash<double>()(area.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_AREA_HPP
