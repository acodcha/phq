// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_VECTOR_AREA_HPP
#define PHQ_VECTOR_AREA_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "Area.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "Unit/Area.hpp"
#include "Vector.hpp"

namespace PhQ {

/// \brief Three-dimensional Euclidean vector area. Contains three components in Cartesian
/// coordinates: x, y, and z. A vector area is an oriented area; it is the three-dimensional
/// Euclidean vector representation of an area. Any closed surface has a vector area: it is the
/// surface integral of its surface normal direction. For the scalar components of a vector area or
/// for the magnitude of a vector area, see PhQ::Area.
template <typename NumericType = double>
class VectorArea : public DimensionalVector<Unit::Area, NumericType> {
public:
  /// \brief Default constructor. Constructs a vector area with an uninitialized value.
  VectorArea() = default;

  /// \brief Constructor. Constructs a vector area with a given value expressed in a given area
  /// unit.
  VectorArea(const Vector<NumericType>& value, const Unit::Area unit)
    : DimensionalVector<Unit::Area, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a vector area from a given set of area components.
  VectorArea(const Area<NumericType>& x, const Area<NumericType>& y, const Area<NumericType>& z)
    : VectorArea<NumericType>({x.Value(), y.Value(), z.Value()}) {}

  /// \brief Constructor. Constructs a vector area from a given area and direction.
  constexpr VectorArea(const Area<NumericType>& area, const Direction<NumericType>& direction)
    : VectorArea<NumericType>(area.Value() * direction.Value()) {}

  /// \brief Destructor. Destroys this vector area.
  ~VectorArea() noexcept = default;

  /// \brief Copy constructor. Constructs a vector area by copying another one.
  constexpr VectorArea(const VectorArea<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a vector area by copying another one.
  template <typename OtherNumericType>
  explicit constexpr VectorArea(const VectorArea<OtherNumericType>& other)
    : VectorArea(static_cast<Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a vector area by moving another one.
  constexpr VectorArea(VectorArea<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this vector area by copying another one.
  constexpr VectorArea<NumericType>& operator=(const VectorArea<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this vector area by copying another one.
  template <typename OtherNumericType>
  constexpr VectorArea<NumericType>& operator=(const VectorArea<OtherNumericType>& other) {
    this->value = static_cast<Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this vector area by moving another one.
  constexpr VectorArea<NumericType>& operator=(VectorArea<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a vector area of zero.
  static constexpr VectorArea<NumericType> Zero() {
    return VectorArea<NumericType>{Vector<NumericType>::Zero()};
  }

  /// \brief Statically creates a vector area from the given x, y, and z Cartesian components
  /// expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea<NumericType> Create(
      const NumericType x, const NumericType y, const NumericType z) {
    return VectorArea<NumericType>{
        ConvertStatically<Unit::Area, Unit, Standard<Unit::Area>>(Vector<NumericType>{x, y, z})};
  }

  /// \brief Statically creates a vector area from the given x, y, and z Cartesian components
  /// expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea<NumericType> Create(const std::array<NumericType, 3>& x_y_z) {
    return VectorArea<NumericType>{
        ConvertStatically<Unit::Area, Unit, Standard<Unit::Area>>(Vector<NumericType>{x_y_z})};
  }

  /// \brief Statically creates a vector area with a given value expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea<NumericType> Create(const Vector<NumericType>& value) {
    return VectorArea<NumericType>{
        ConvertStatically<Unit::Area, Unit, Standard<Unit::Area>>(value)};
  }

  /// \brief Returns the x Cartesian component of this vector area.
  [[nodiscard]] constexpr Area<NumericType> x() const noexcept {
    return Area<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this vector area.
  [[nodiscard]] constexpr Area<NumericType> y() const noexcept {
    return Area<NumericType>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this vector area.
  [[nodiscard]] constexpr Area<NumericType> z() const noexcept {
    return Area<NumericType>{this->value.z()};
  }

  /// \brief Returns the magnitude of this vector area.
  [[nodiscard]] Area<NumericType> Magnitude() const {
    return Area<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this vector area.
  [[nodiscard]] PhQ::Direction<NumericType> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this vector area and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const VectorArea<NumericType>& vector_area) const {
    return PhQ::Angle<NumericType>{*this, vector_area};
  }

  constexpr VectorArea<NumericType> operator+(const VectorArea<NumericType>& vector_area) const {
    return VectorArea<NumericType>{this->value + vector_area.value};
  }

  constexpr VectorArea<NumericType> operator-(const VectorArea<NumericType>& vector_area) const {
    return VectorArea<NumericType>{this->value - vector_area.value};
  }

  constexpr VectorArea<NumericType> operator*(const NumericType number) const {
    return VectorArea<NumericType>{this->value * number};
  }

  constexpr VectorArea<NumericType> operator/(const NumericType number) const {
    return VectorArea<NumericType>{this->value / number};
  }

  constexpr void operator+=(const VectorArea<NumericType>& vector_area) noexcept {
    this->value += vector_area.value;
  }

  constexpr void operator-=(const VectorArea<NumericType>& vector_area) noexcept {
    this->value -= vector_area.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a vector area with a given value expressed in the standard area
  /// unit.
  explicit constexpr VectorArea(const Vector<NumericType>& value)
    : DimensionalVector<Unit::Area, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const VectorArea<NumericType>& left, const VectorArea<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const VectorArea<NumericType>& left, const VectorArea<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const VectorArea<NumericType>& left, const VectorArea<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const VectorArea<NumericType>& left, const VectorArea<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const VectorArea<NumericType>& left, const VectorArea<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const VectorArea<NumericType>& left, const VectorArea<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const VectorArea<NumericType>& vector_area) {
  stream << vector_area.Print();
  return stream;
}

template <typename NumericType>
inline constexpr VectorArea<NumericType> operator*(
    const NumericType number, const VectorArea<NumericType>& vector_area) {
  return vector_area * number;
}

template <typename NumericType>
inline Direction<NumericType>::Direction(const VectorArea<NumericType>& vector_area)
  : Direction<NumericType>(vector_area.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(
    const VectorArea<NumericType>& vector_area_1, const VectorArea<NumericType>& vector_area_2)
  : Angle<NumericType>(vector_area_1.Value(), vector_area_2.Value()) {}

template <typename NumericType>
inline constexpr VectorArea<NumericType> Direction<NumericType>::operator*(
    const Area<NumericType>& area) const {
  return VectorArea<NumericType>{area, *this};
}

template <typename NumericType>
inline constexpr VectorArea<NumericType> Area<NumericType>::operator*(
    const Direction<NumericType>& direction) const {
  return VectorArea<NumericType>{*this, direction};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::VectorArea<NumericType>> {
  inline size_t operator()(const PhQ::VectorArea<NumericType>& vector_area) const {
    return hash<PhQ::Vector<NumericType>>()(vector_area.Value());
  }
};

}  // namespace std

#endif  // PHQ_VECTOR_AREA_HPP
