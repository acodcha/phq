// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

/// \brief Scalar area. Can also represent a component or the magnitude of a vector area. See also
/// PhQ::VectorArea.
template <typename Number = double>
class Area : public DimensionalScalar<Unit::Area, Number> {
public:
  /// \brief Default constructor. Constructs an area with an uninitialized value.
  Area() = default;

  /// \brief Constructor. Constructs an area with a given value expressed in a given area unit.
  Area(const Number value, const Unit::Area unit)
    : DimensionalScalar<Unit::Area, Number>(value, unit) {}

  /// \brief Constructor. Constructs an area from two given lengths.
  constexpr Area(const Length<Number>& length1, const Length<Number>& length2)
    : Area<Number>(length1.Value() * length2.Value()) {}

  /// \brief Constructor. Constructs an area from a given volume and length.
  constexpr Area(const Volume<Number>& volume, const Length<Number>& length);

  /// \brief Constructor. Constructs an area from a given scalar force magnitude and static pressure
  /// using the definition of pressure.
  constexpr Area(
      const ScalarForce<Number>& scalar_force, const StaticPressure<Number>& static_pressure);

  /// \brief Destructor. Destroys this area.
  ~Area() noexcept = default;

  /// \brief Copy constructor. Constructs an area by copying another one.
  constexpr Area(const Area<Number>& other) = default;

  /// \brief Copy constructor. Constructs an area by copying another one.
  template <typename OtherNumber>
  explicit constexpr Area(const Area<OtherNumber>& other)
    : Area(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs an area by moving another one.
  constexpr Area(Area<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this area by copying another one.
  constexpr Area<Number>& operator=(const Area<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this area by copying another one.
  template <typename OtherNumber>
  constexpr Area<Number>& operator=(const Area<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this area by moving another one.
  constexpr Area<Number>& operator=(Area<Number>&& other) noexcept = default;

  /// \brief Statically creates an area of zero.
  static constexpr Area<Number> Zero() {
    return Area<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates an area with a given value expressed in a given area unit.
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
  /// \brief Constructor. Constructs an area with a given value expressed in the standard area unit.
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
