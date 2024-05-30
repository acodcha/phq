// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
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
template <typename NumericType>
class Direction;

// Forward declaration for class PhQ::Area.
template <typename NumericType>
class Force;

// Forward declaration for class PhQ::Area.
template <typename NumericType>
class PlanarVectorArea;

// Forward declaration for class PhQ::Area.
template <typename NumericType>
class ScalarForce;

// Forward declaration for class PhQ::Area.
template <typename NumericType>
class ScalarTraction;

// Forward declaration for class PhQ::Area.
template <typename NumericType>
class StaticPressure;

// Forward declaration for class PhQ::Area.
template <typename NumericType>
class Traction;

// Forward declaration for class PhQ::Area.
template <typename NumericType>
class VectorArea;

/// \brief Surface area or cross-sectional area. Can also represent a scalar component of a vector
/// area or the magnitude of a vector area. Any closed surface has a vector area: it is the surface
/// integral of its surface normal direction. A vector area is an oriented area; it is the
/// three-dimensional Euclidean vector representation of an area; see PhQ::VectorArea.
template <typename NumericType = double>
class Area : public DimensionalScalar<Unit::Area, NumericType> {
public:
  /// \brief Default constructor. Constructs an area with an uninitialized value.
  Area() = default;

  /// \brief Constructor. Constructs an area with a given value expressed in a given area unit.
  Area(const NumericType value, const Unit::Area unit)
    : DimensionalScalar<Unit::Area, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs an area from two given lengths.
  constexpr Area(const Length<NumericType>& length1, const Length<NumericType>& length2)
    : Area<NumericType>(length1.Value() * length2.Value()) {}

  /// \brief Constructor. Constructs an area from a given volume and length.
  constexpr Area(const Volume<NumericType>& volume, const Length<NumericType>& length);

  /// \brief Constructor. Constructs an area from a given scalar force magnitude and scalar traction
  /// magnitude using the definition of traction.
  constexpr Area(const ScalarForce<NumericType>& scalar_force,
                 const ScalarTraction<NumericType>& scalar_traction);

  /// \brief Constructor. Constructs an area from a given scalar force magnitude and static pressure
  /// using the definition of pressure.
  constexpr Area(const ScalarForce<NumericType>& scalar_force,
                 const StaticPressure<NumericType>& static_pressure);

  /// \brief Destructor. Destroys this area.
  ~Area() noexcept = default;

  /// \brief Copy constructor. Constructs an area by copying another one.
  constexpr Area(const Area<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs an area by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Area(const Area<OtherNumericType>& other)
    : Area(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs an area by moving another one.
  constexpr Area(Area<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this area by copying another one.
  constexpr Area<NumericType>& operator=(const Area<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this area by copying another one.
  template <typename OtherNumericType>
  constexpr Area<NumericType>& operator=(const Area<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this area by moving another one.
  constexpr Area<NumericType>& operator=(Area<NumericType>&& other) noexcept = default;

  /// \brief Statically creates an area of zero.
  static constexpr Area<NumericType> Zero() {
    return Area<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates an area with a given value expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr Area<NumericType> Create(const NumericType value) {
    return Area<NumericType>{StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(value)};
  }

  constexpr Area<NumericType> operator+(const Area<NumericType>& area) const {
    return Area<NumericType>{this->value + area.value};
  }

  constexpr Area<NumericType> operator-(const Area<NumericType>& area) const {
    return Area<NumericType>{this->value - area.value};
  }

  constexpr Area<NumericType> operator*(const NumericType number) const {
    return Area<NumericType>{this->value * number};
  }

  constexpr Volume<NumericType> operator*(const Length<NumericType>& length) const;

  constexpr ScalarForce<NumericType> operator*(
      const ScalarTraction<NumericType>& scalar_traction) const;

  constexpr ScalarForce<NumericType> operator*(
      const StaticPressure<NumericType>& static_pressure) const;

  constexpr PlanarVectorArea<NumericType> operator*(
      const PlanarDirection<NumericType>& planar_direction) const;

  constexpr VectorArea<NumericType> operator*(const Direction<NumericType>& direction) const;

  constexpr Area<NumericType> operator/(const NumericType number) const {
    return Area<NumericType>{this->value / number};
  }

  constexpr Length<NumericType> operator/(const Length<NumericType>& length) const {
    return Length<NumericType>{*this, length};
  }

  constexpr NumericType operator/(const Area<NumericType>& area) const noexcept {
    return this->value / area.value;
  }

  constexpr void operator+=(const Area<NumericType>& area) noexcept {
    this->value += area.value;
  }

  constexpr void operator-=(const Area<NumericType>& area) noexcept {
    this->value -= area.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an area with a given value expressed in the standard area unit.
  explicit constexpr Area(const NumericType value)
    : DimensionalScalar<Unit::Area, NumericType>(value) {}

  template <typename OtherArea>
  friend class PlanarVectorArea;

  template <typename OtherArea>
  friend class VectorArea;
};

template <typename NumericType>
inline constexpr bool operator==(
    const Area<NumericType>& left, const Area<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Area<NumericType>& left, const Area<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Area<NumericType>& left, const Area<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Area<NumericType>& left, const Area<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Area<NumericType>& left, const Area<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Area<NumericType>& left, const Area<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Area<NumericType>& area) {
  stream << area.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Area<NumericType> operator*(
    const NumericType number, const Area<NumericType>& area) {
  return area * number;
}

template <typename NumericType>
inline constexpr Length<NumericType>::Length(
    const Area<NumericType>& area, const Length<NumericType>& length)
  : Length<NumericType>(area.Value() / length.Value()) {}

template <typename NumericType>
inline constexpr Area<NumericType> Length<NumericType>::operator*(
    const Length<NumericType>& length) const {
  return Area<NumericType>{*this, length};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Area<NumericType>> {
  inline size_t operator()(const PhQ::Area<NumericType>& area) const {
    return hash<NumericType>()(area.Value());
  }
};

}  // namespace std

#endif  // PHQ_AREA_HPP
