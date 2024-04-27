// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHQ_AREA_HPP
#define PHQ_AREA_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Length.hpp"
#include "Unit/Area.hpp"

namespace PhQ {

// Forward declarations for class Area.
class Direction;
class Force;
class ScalarForce;
class StaticPressure;
class Traction;
class VectorArea;

// Scalar area. Can also represent a component or the magnitude of a vector area (see
// PhQ::VectorArea).
class Area : public DimensionalScalar<Unit::Area> {
public:
  // Default constructor. Constructs an area with an uninitialized value.
  Area() = default;

  // Constructor. Constructs an area with a given value expressed in a given area unit.
  Area(const double value, const Unit::Area unit) : DimensionalScalar<Unit::Area>(value, unit) {}

  // Constructor. Constructs an area from two given lengths.
  constexpr Area(const Length& length1, const Length& length2)
    : Area(length1.Value() * length2.Value()) {}

  // Constructor. Constructs an area from a given volume and length.
  constexpr Area(const Volume& volume, const Length& length);

  // Constructor. Constructs an area from a given scalar force magnitude and static pressure using
  // the definition of pressure.
  constexpr Area(const ScalarForce& scalar_force, const StaticPressure& static_pressure);

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

  // Statically creates an area with a given value expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr Area Create(const double value) {
    return Area{StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(value)};
  }

  constexpr Area operator+(const Area& area) const {
    return Area{value + area.value};
  }

  constexpr Area operator-(const Area& area) const {
    return Area{value - area.value};
  }

  constexpr Area operator*(const double number) const {
    return Area{value * number};
  }

  constexpr Volume operator*(const Length& length) const;

  constexpr ScalarForce operator*(const StaticPressure& static_pressure) const;

  constexpr VectorArea operator*(const Direction& direction) const;

  constexpr Area operator/(const double number) const {
    return Area{value / number};
  }

  constexpr Length operator/(const Length& length) const {
    return Length{*this, length};
  }

  constexpr double operator/(const Area& area) const noexcept {
    return value / area.value;
  }

  constexpr void operator+=(const Area& area) noexcept {
    value += area.value;
  }

  constexpr void operator-=(const Area& area) noexcept {
    value -= area.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs an area with a given value expressed in the standard area unit.
  explicit constexpr Area(const double value) : DimensionalScalar<Unit::Area>(value) {}

  friend class VectorArea;
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

inline constexpr Length::Length(const Area& area, const Length& length)
  : Length(area.Value() / length.Value()) {}

inline constexpr Area Length::operator*(const Length& length) const {
  return Area{*this, length};
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

#endif  // PHQ_AREA_HPP
