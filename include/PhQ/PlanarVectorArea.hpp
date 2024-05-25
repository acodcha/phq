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

#ifndef PHQ_PLANAR_VECTOR_AREA_HPP
#define PHQ_PLANAR_VECTOR_AREA_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "Area.hpp"
#include "DimensionalPlanarVector.hpp"
#include "PlanarDirection.hpp"
#include "PlanarVector.hpp"
#include "Unit/Area.hpp"

namespace PhQ {

/// \brief Planar vector-area in the XY plane. The planar vector analog to a scalar area. See also
/// PhQ::Area.
template <typename Number = double>
class PlanarVectorArea : public DimensionalPlanarVector<Unit::Area, Number> {
public:
  /// \brief Default constructor. Constructs a planar vector area with an uninitialized value.
  PlanarVectorArea() = default;

  /// \brief Constructor. Constructs a planar vector area with a given value expressedin a given
  /// area unit.
  PlanarVectorArea(const PlanarVector<Number>& value, const Unit::Area unit)
    : DimensionalPlanarVector<Unit::Area, Number>(value, unit) {}

  /// \brief Constructor. Constructs a planar vector area from a given area and direction.
  constexpr PlanarVectorArea(const Area<Number>& area, const PlanarDirection<Number>& direction)
    : PlanarVectorArea<Number>(area.Value() * direction.Value()) {}

  /// \brief Destructor. Destroys this planar vector area.
  ~PlanarVectorArea() noexcept = default;

  /// \brief Copy constructor. Constructs a planar vector area by copying another one.
  constexpr PlanarVectorArea(const PlanarVectorArea<Number>& other) = default;

  /// \brief Copy constructor. Constructs a planar vector area by copying another one.
  template <typename OtherNumber>
  explicit constexpr PlanarVectorArea(const PlanarVectorArea<OtherNumber>& other)
    : PlanarVectorArea(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar vector area by moving another one.
  constexpr PlanarVectorArea(PlanarVectorArea<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar vector area by copying another one.
  constexpr PlanarVectorArea<Number>& operator=(const PlanarVectorArea<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar vector area by copying another one.
  template <typename OtherNumber>
  constexpr PlanarVectorArea<Number>& operator=(const PlanarVectorArea<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar vector area by moving another one.
  constexpr PlanarVectorArea<Number>& operator=(
      PlanarVectorArea<Number>&& other) noexcept = default;

  /// \brief Statically creates a planar vector area of zero.
  static constexpr PlanarVectorArea<Number> Zero() {
    return PlanarVectorArea<Number>{PlanarVector<Number>::Zero()};
  }

  /// \brief Statically creates a planar vector area from the given x and y Cartesian components
  /// expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr PlanarVectorArea<Number> Create(const Number x, const Number y) {
    return PlanarVectorArea<Number>{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(PlanarVector<Number>{x, y})};
  }

  /// \brief Statically creates a planar vector area from the given x and y Cartesian components
  /// expressed in a given area unit.
  template <Unit::Area Unit>
  static constexpr PlanarVectorArea<Number> Create(const std::array<Number, 2>& x_y) {
    return PlanarVectorArea<Number>{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(PlanarVector<Number>{x_y})};
  }

  /// \brief Statically creates a planar vector area with a given value expressed in a given area
  /// unit.
  template <Unit::Area Unit>
  static constexpr PlanarVectorArea<Number> Create(const PlanarVector<Number>& value) {
    return PlanarVectorArea<Number>{
        StaticConvertCopy<Unit::Area, Unit, Standard<Unit::Area>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar vector area.
  [[nodiscard]] constexpr Area<Number> x() const noexcept {
    return Area<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar vector area.
  [[nodiscard]] constexpr Area<Number> y() const noexcept {
    return Area<Number>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar vector area.
  [[nodiscard]] Area<Number> Magnitude() const {
    return Area<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this planar vector area.
  [[nodiscard]] PhQ::PlanarDirection<Number> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar vector area and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const PlanarVectorArea<Number>& planar_vector_area) const {
    return PhQ::Angle<Number>{*this, planar_vector_area};
  }

  constexpr PlanarVectorArea<Number> operator+(
      const PlanarVectorArea<Number>& planar_vector_area) const {
    return PlanarVectorArea<Number>{this->value + planar_vector_area.value};
  }

  constexpr PlanarVectorArea<Number> operator-(
      const PlanarVectorArea<Number>& planar_vector_area) const {
    return PlanarVectorArea<Number>{this->value - planar_vector_area.value};
  }

  constexpr PlanarVectorArea<Number> operator*(const Number number) const {
    return PlanarVectorArea<Number>{this->value * number};
  }

  constexpr PlanarVectorArea<Number> operator/(const Number number) const {
    return PlanarVectorArea<Number>{this->value / number};
  }

  constexpr void operator+=(const PlanarVectorArea<Number>& planar_vector_area) noexcept {
    this->value += planar_vector_area.value;
  }

  constexpr void operator-=(const PlanarVectorArea<Number>& planar_vector_area) noexcept {
    this->value -= planar_vector_area.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar vector area with a given value expressed in the
  /// standard area unit.
  explicit constexpr PlanarVectorArea(const PlanarVector<Number>& value)
    : DimensionalPlanarVector<Unit::Area, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const PlanarVectorArea<Number>& left, const PlanarVectorArea<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PlanarVectorArea<Number>& left, const PlanarVectorArea<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PlanarVectorArea<Number>& left, const PlanarVectorArea<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PlanarVectorArea<Number>& left, const PlanarVectorArea<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PlanarVectorArea<Number>& left, const PlanarVectorArea<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PlanarVectorArea<Number>& left, const PlanarVectorArea<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarVectorArea<Number>& planar_vector_area) {
  stream << planar_vector_area.Print();
  return stream;
}

template <typename Number>
inline constexpr PlanarVectorArea<Number> operator*(
    const Number number, const PlanarVectorArea<Number>& planar_vector_area) {
  return planar_vector_area * number;
}

template <typename Number>
inline PlanarDirection<Number>::PlanarDirection(const PlanarVectorArea<Number>& planar_vector_area)
  : PlanarDirection<Number>(planar_vector_area.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(
    const PlanarVectorArea<Number>& vector_area_1, const PlanarVectorArea<Number>& vector_area_2)
  : Angle<Number>(vector_area_1.Value(), vector_area_2.Value()) {}

template <typename Number>
inline constexpr PlanarVectorArea<Number> PlanarDirection<Number>::operator*(
    const Area<Number>& area) const {
  return PlanarVectorArea<Number>{area, *this};
}

template <typename Number>
inline constexpr PlanarVectorArea<Number> Area<Number>::operator*(
    const PlanarDirection<Number>& direction) const {
  return PlanarVectorArea<Number>{*this, direction};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PlanarVectorArea<Number>> {
  inline size_t operator()(const PhQ::PlanarVectorArea<Number>& planar_vector_area) const {
    return hash<PhQ::PlanarVector<Number>>()(planar_vector_area.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_VECTOR_AREA_HPP
