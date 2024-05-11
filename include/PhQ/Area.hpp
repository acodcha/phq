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

// Forward declaration for class PhQ::Area.
template <typename Number>
class Direction;

// Forward declaration for class PhQ::Area.
template <typename Number>
class Force;

// Forward declaration for class PhQ::Area.
template <typename Number>
class ScalarForce;

// Forward declaration for class PhQ::Area.
template <typename Number>
class StaticPressure;

// Forward declaration for class PhQ::Area.
template <typename Number>
class Traction;

// Forward declaration for class PhQ::Area.
template <typename Number>
class VectorArea;

// Scalar area. Can also represent a component or the magnitude of a vector area (see
// PhQ::VectorArea).
template <typename Number = double>
class Area : public DimensionalScalar<Unit::Area, Number> {
public:
  // Default constructor. Constructs an area with an uninitialized value.
  Area() = default;

  // Constructor. Constructs an area with a given value expressed in a given area unit.
  Area(const Number value, const Unit::Area unit)
    : DimensionalScalar<Unit::Area, Number>(value, unit) {}

  // Constructor. Constructs an area from two given lengths.
  constexpr Area(const Length<Number>& length1, const Length<Number>& length2)
    : Area<Number>(length1.Value() * length2.Value()) {}

  // Constructor. Constructs an area from a given volume and length.
  constexpr Area(const Volume<Number>& volume, const Length<Number>& length);

  // Constructor. Constructs an area from a given scalar force magnitude and static pressure using
  // the definition of pressure.
  constexpr Area(
      const ScalarForce<Number>& scalar_force, const StaticPressure<Number>& static_pressure);

  // Destructor. Destroys this area.
  ~Area() noexcept = default;

  // Copy constructor. Constructs an area by copying another one.
  constexpr Area(const Area<Number>& other) = default;

  // Copy constructor. Constructs an area by copying another one.
  template <typename OtherNumber>
  explicit constexpr Area(const Area<OtherNumber>& other)
    : Area(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs an area by moving another one.
  constexpr Area(Area<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this area by copying another one.
  constexpr Area<Number>& operator=(const Area<Number>& other) = default;

  // Copy assignment operator. Assigns this area by copying another one.
  template <typename OtherNumber>
  constexpr Area<Number>& operator=(const Area<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this area by moving another one.
  constexpr Area<Number>& operator=(Area<Number>&& other) noexcept = default;

  // Statically creates an area of zero.
  static constexpr Area<Number> Zero() {
    return Area<Number>{static_cast<Number>(0)};
  }

  // Statically creates an area with a given value expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr Area<Number> Create(const Number value) {
    return Area<Number>{StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(value)};
  }

  constexpr Area<Number> operator+(const Area<Number>& area) const {
    return Area<Number>{this->value + area.value};
  }

  constexpr Area<Number> operator-(const Area<Number>& area) const {
    return Area<Number>{this->value - area.value};
  }

  constexpr Area<Number> operator*(const Number number) const {
    return Area<Number>{this->value * number};
  }

  constexpr Volume<Number> operator*(const Length<Number>& length) const;

  constexpr ScalarForce<Number> operator*(const StaticPressure<Number>& static_pressure) const;

  constexpr VectorArea<Number> operator*(const Direction<Number>& direction) const;

  constexpr Area<Number> operator/(const Number number) const {
    return Area<Number>{this->value / number};
  }

  constexpr Length<Number> operator/(const Length<Number>& length) const {
    return Length<Number>{*this, length};
  }

  constexpr Number operator/(const Area<Number>& area) const noexcept {
    return this->value / area.value;
  }

  constexpr void operator+=(const Area<Number>& area) noexcept {
    this->value += area.value;
  }

  constexpr void operator-=(const Area<Number>& area) noexcept {
    this->value -= area.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs an area with a given value expressed in the standard area unit.
  explicit constexpr Area(const Number value) : DimensionalScalar<Unit::Area, Number>(value) {}

  template <typename OtherArea>
  friend class VectorArea;
};

template <typename Number>
inline constexpr bool operator==(const Area<Number>& left, const Area<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Area<Number>& left, const Area<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Area<Number>& left, const Area<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Area<Number>& left, const Area<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Area<Number>& left, const Area<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Area<Number>& left, const Area<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Area<Number>& area) {
  stream << area.Print();
  return stream;
}

template <typename Number>
inline constexpr Area<Number> operator*(const Number number, const Area<Number>& area) {
  return area * number;
}

template <typename Number>
inline constexpr Length<Number>::Length(const Area<Number>& area, const Length<Number>& length)
  : Length<Number>(area.Value() / length.Value()) {}

template <typename Number>
inline constexpr Area<Number> Length<Number>::operator*(const Length<Number>& length) const {
  return Area<Number>{*this, length};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Area<Number>> {
  inline size_t operator()(const PhQ::Area<Number>& area) const {
    return hash<Number>()(area.Value());
  }
};

}  // namespace std

#endif  // PHQ_AREA_HPP
