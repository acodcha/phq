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
#include "PlanarVectorArea.hpp"
#include "Unit/Area.hpp"
#include "Vector.hpp"

namespace PhQ {

/// \brief Vector-area. The vector analog to a scalar area. See also PhQ::Area.
template <typename Number = double>
class VectorArea : public DimensionalVector<Unit::Area, Number> {
public:
  /// \brief Default constructor. Constructs a vector area with an uninitialized value.
  VectorArea() = default;

  /// \brief Constructor. Constructs a vector area with a given value expressedin a given area unit.
  VectorArea(const Vector<Number>& value, const Unit::Area unit)
    : DimensionalVector<Unit::Area, Number>(value, unit) {}

  /// \brief Constructor. Constructs a vector area from a given area and direction.
  constexpr VectorArea(const Area<Number>& area, const Direction<Number>& direction)
    : VectorArea<Number>(area.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs a vector area from a given planar vector area in the XY plane.
  /// This vector area's z-component is initialized to zero.
  explicit constexpr VectorArea(const PlanarVectorArea<Number>& planar_force)
    : VectorArea<Number>(Vector<Number>{planar_force.Value()}) {}

  /// \brief Destructor. Destroys this vector area.
  ~VectorArea() noexcept = default;

  /// \brief Copy constructor. Constructs a vector area by copying another one.
  constexpr VectorArea(const VectorArea<Number>& other) = default;

  /// \brief Copy constructor. Constructs a vector area by copying another one.
  template <typename OtherNumber>
  explicit constexpr VectorArea(const VectorArea<OtherNumber>& other)
    : VectorArea(static_cast<Vector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a vector area by moving another one.
  constexpr VectorArea(VectorArea<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this vector area by copying another one.
  constexpr VectorArea<Number>& operator=(const VectorArea<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this vector area by copying another one.
  template <typename OtherNumber>
  constexpr VectorArea<Number>& operator=(const VectorArea<OtherNumber>& other) {
    this->value = static_cast<Vector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this vector area by moving another one.
  constexpr VectorArea<Number>& operator=(VectorArea<Number>&& other) noexcept = default;

  /// \brief Statically creates a vector area of zero.
  static constexpr VectorArea<Number> Zero() {
    return VectorArea<Number>{Vector<Number>::Zero()};
  }

  /// \brief Statically creates a vector area from the given x, y, and z Cartesian components
  /// expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea<Number> Create(const Number x, const Number y, const Number z) {
    return VectorArea<Number>{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(Vector<Number>{x, y, z})};
  }

  /// \brief Statically creates a vector area from the given x, y, and z Cartesian components
  /// expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea<Number> Create(const std::array<Number, 3>& x_y_z) {
    return VectorArea<Number>{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(Vector<Number>{x_y_z})};
  }

  /// \brief Statically creates a vector area with a given value expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr VectorArea<Number> Create(const Vector<Number>& value) {
    return VectorArea<Number>{StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(value)};
  }

  /// \brief Returns the x Cartesian component of this vector area.
  [[nodiscard]] constexpr Area<Number> x() const noexcept {
    return Area<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this vector area.
  [[nodiscard]] constexpr Area<Number> y() const noexcept {
    return Area<Number>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this vector area.
  [[nodiscard]] constexpr Area<Number> z() const noexcept {
    return Area<Number>{this->value.z()};
  }

  /// \brief Returns the magnitude of this vector area.
  [[nodiscard]] Area<Number> Magnitude() const {
    return Area<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this vector area.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this vector area and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const VectorArea<Number>& vector_area) const {
    return PhQ::Angle<Number>{*this, vector_area};
  }

  constexpr VectorArea<Number> operator+(const VectorArea<Number>& vector_area) const {
    return VectorArea<Number>{this->value + vector_area.value};
  }

  constexpr VectorArea<Number> operator-(const VectorArea<Number>& vector_area) const {
    return VectorArea<Number>{this->value - vector_area.value};
  }

  constexpr VectorArea<Number> operator*(const Number number) const {
    return VectorArea<Number>{this->value * number};
  }

  constexpr VectorArea<Number> operator/(const Number number) const {
    return VectorArea<Number>{this->value / number};
  }

  constexpr void operator+=(const VectorArea<Number>& vector_area) noexcept {
    this->value += vector_area.value;
  }

  constexpr void operator-=(const VectorArea<Number>& vector_area) noexcept {
    this->value -= vector_area.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a vector area with a given value expressed in the standard area
  /// unit.
  explicit constexpr VectorArea(const Vector<Number>& value)
    : DimensionalVector<Unit::Area, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const VectorArea<Number>& left, const VectorArea<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const VectorArea<Number>& vector_area) {
  stream << vector_area.Print();
  return stream;
}

template <typename Number>
inline constexpr VectorArea<Number> operator*(
    const Number number, const VectorArea<Number>& vector_area) {
  return vector_area * number;
}

template <typename Number>
inline Direction<Number>::Direction(const VectorArea<Number>& vector_area)
  : Direction<Number>(vector_area.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(
    const VectorArea<Number>& vector_area_1, const VectorArea<Number>& vector_area_2)
  : Angle<Number>(vector_area_1.Value(), vector_area_2.Value()) {}

template <typename Number>
inline constexpr VectorArea<Number> Direction<Number>::operator*(const Area<Number>& area) const {
  return VectorArea<Number>{area, *this};
}

template <typename Number>
inline constexpr VectorArea<Number> Area<Number>::operator*(
    const Direction<Number>& direction) const {
  return VectorArea<Number>{*this, direction};
}

template <typename Number>
inline constexpr PlanarVectorArea<Number>::PlanarVectorArea(const VectorArea<Number>& vector_area)
  : PlanarVectorArea(PlanarVector<Number>{vector_area.Value()}) {}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::VectorArea<Number>> {
  inline size_t operator()(const PhQ::VectorArea<Number>& vector_area) const {
    return hash<PhQ::Vector<Number>>()(vector_area.Value());
  }
};

}  // namespace std

#endif  // PHQ_VECTOR_AREA_HPP
