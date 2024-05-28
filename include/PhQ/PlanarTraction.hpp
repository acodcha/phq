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

#ifndef PHQ_PLANAR_TRACTION_HPP
#define PHQ_PLANAR_TRACTION_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Area.hpp"
#include "DimensionalPlanarVector.hpp"
#include "PlanarDirection.hpp"
#include "PlanarForce.hpp"
#include "PlanarVector.hpp"
#include "ScalarTraction.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class PhQ::PlanarTraction.
template <typename Number>
class Stress;

/// \brief Two-dimensional Euclidean traction vector in the XY plane. Contains two components in
/// Cartesian coordinates: x and y. Traction is similar to pressure; however, traction can act in
/// any direction, whereas pressure always acts compressively perpendicular to a surface. For a
/// three-dimensional Euclidean traction vector, see PhQ::Traction. For scalar traction components
/// or for the magnitude of a traction vector, see PhQ::ScalarTraction.
template <typename Number = double>
class PlanarTraction : public DimensionalPlanarVector<Unit::Pressure, Number> {
public:
  /// \brief Default constructor. Constructs a planar traction vector with an uninitialized value.
  PlanarTraction() = default;

  /// \brief Constructor. Constructs a planar traction vector with a given value expressed in a
  /// given pressure unit.
  PlanarTraction(const PlanarVector<Number>& value, const Unit::Pressure unit)
    : DimensionalPlanarVector<Unit::Pressure, Number>(value, unit) {}

  /// \brief Constructor. Constructs a planar traction vector from a given set of scalar traction
  /// components.
  PlanarTraction(const ScalarTraction<Number>& x, const ScalarTraction<Number>& y)
    : PlanarTraction<Number>({x.Value(), y.Value()}) {}

  /// \brief Constructor. Constructs a planar traction vector from a given scalar traction and
  /// planar direction.
  constexpr PlanarTraction(const ScalarTraction<Number>& scalar_traction,
                           const PlanarDirection<Number>& planar_direction)
    : PlanarTraction<Number>(scalar_traction.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar traction vector from a given traction vector by
  /// projecting the traction vector onto the XY plane.
  explicit constexpr PlanarTraction(const Traction<Number>& traction);

  /// \brief Constructor. Constructs a planar traction vector from a given planar force and area
  /// using the definition of traction.
  constexpr PlanarTraction(const PlanarForce<Number>& planar_force, const Area<Number>& area)
    : PlanarTraction<Number>(planar_force.Value() / area.Value()) {}

  /// \brief Constructor. Constructs a planar traction vector from a given stress and direction
  /// using the definition of traction.
  constexpr PlanarTraction(
      const Stress<Number>& stress, const PlanarDirection<Number>& planar_direction);

  /// \brief Destructor. Destroys this planar traction vector.
  ~PlanarTraction() noexcept = default;

  /// \brief Copy constructor. Constructs a planar traction vector by copying another one.
  constexpr PlanarTraction(const PlanarTraction<Number>& other) = default;

  /// \brief Copy constructor. Constructs a planar traction vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr PlanarTraction(const PlanarTraction<OtherNumber>& other)
    : PlanarTraction(static_cast<PlanarVector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar traction vector by moving another one.
  constexpr PlanarTraction(PlanarTraction<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar traction vector by copying another one.
  constexpr PlanarTraction<Number>& operator=(const PlanarTraction<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar traction vector by copying another one.
  template <typename OtherNumber>
  constexpr PlanarTraction<Number>& operator=(const PlanarTraction<OtherNumber>& other) {
    this->value = static_cast<PlanarVector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar traction vector by moving another one.
  constexpr PlanarTraction<Number>& operator=(PlanarTraction<Number>&& other) noexcept = default;

  /// \brief Statically creates a planar traction vector of zero.
  static constexpr PlanarTraction<Number> Zero() {
    return PlanarTraction<Number>{PlanarVector<Number>::Zero()};
  }

  /// \brief Statically creates a planar traction vector from the given x and y Cartesian components
  /// expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr PlanarTraction<Number> Create(const Number x, const Number y) {
    return PlanarTraction<Number>{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        PlanarVector<Number>{x, y})};
  }

  /// \brief Statically creates a planar traction vector from the given x and y Cartesian components
  /// expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr PlanarTraction<Number> Create(const std::array<Number, 2>& x_y) {
    return PlanarTraction<Number>{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        PlanarVector<Number>{x_y})};
  }

  /// \brief Statically creates a planar traction vector with a given value expressed in a given
  /// pressure unit.
  template <Unit::Pressure Unit>
  static constexpr PlanarTraction<Number> Create(const PlanarVector<Number>& value) {
    return PlanarTraction<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar traction vector.
  [[nodiscard]] constexpr ScalarTraction<Number> x() const noexcept {
    return ScalarTraction<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar traction vector.
  [[nodiscard]] constexpr ScalarTraction<Number> y() const noexcept {
    return ScalarTraction<Number>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar traction vector.
  [[nodiscard]] ScalarTraction<Number> Magnitude() const {
    return ScalarTraction<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this planar traction vector.
  [[nodiscard]] PhQ::PlanarDirection<Number> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar traction vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const PlanarTraction<Number>& planar_traction) const {
    return PhQ::Angle<Number>{*this, planar_traction};
  }

  constexpr PlanarTraction<Number> operator+(const PlanarTraction<Number>& planar_traction) const {
    return PlanarTraction<Number>{this->value + planar_traction.value};
  }

  constexpr PlanarTraction<Number> operator-(const PlanarTraction<Number>& planar_traction) const {
    return PlanarTraction<Number>{this->value - planar_traction.value};
  }

  constexpr PlanarTraction<Number> operator*(const Number number) const {
    return PlanarTraction<Number>{this->value * number};
  }

  constexpr PlanarForce<Number> operator*(const Area<Number>& area) const {
    return PlanarForce<Number>{*this, area};
  }

  constexpr PlanarTraction<Number> operator/(const Number number) const {
    return PlanarTraction<Number>{this->value / number};
  }

  constexpr void operator+=(const PlanarTraction<Number>& planar_traction) noexcept {
    this->value += planar_traction.value;
  }

  constexpr void operator-=(const PlanarTraction<Number>& planar_traction) noexcept {
    this->value -= planar_traction.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar traction vector with a given value expressed in the
  /// standard pressure unit.
  explicit constexpr PlanarTraction(const PlanarVector<Number>& value)
    : DimensionalPlanarVector<Unit::Pressure, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const PlanarTraction<Number>& left, const PlanarTraction<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PlanarTraction<Number>& left, const PlanarTraction<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PlanarTraction<Number>& left, const PlanarTraction<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PlanarTraction<Number>& left, const PlanarTraction<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PlanarTraction<Number>& left, const PlanarTraction<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PlanarTraction<Number>& left, const PlanarTraction<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarTraction<Number>& planar_traction) {
  stream << planar_traction.Print();
  return stream;
}

template <typename Number>
inline constexpr PlanarTraction<Number> operator*(
    const Number number, const PlanarTraction<Number>& planar_traction) {
  return planar_traction * number;
}

template <typename Number>
inline PlanarDirection<Number>::PlanarDirection(const PlanarTraction<Number>& planar_traction)
  : PlanarDirection<Number>(planar_traction.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const PlanarTraction<Number>& planar_traction_1,
                            const PlanarTraction<Number>& planar_traction_2)
  : Angle<Number>(planar_traction_1.Value(), planar_traction_2.Value()) {}

template <typename Number>
inline constexpr PlanarForce<Number>::PlanarForce(
    const PlanarTraction<Number>& planar_traction, const Area<Number>& area)
  : PlanarForce<Number>(planar_traction.Value() * area.Value()) {}

template <typename Number>
inline constexpr PlanarTraction<Number> PlanarDirection<Number>::operator*(
    const ScalarTraction<Number>& scalar_traction) const {
  return PlanarTraction<Number>{scalar_traction, *this};
}

template <typename Number>
inline constexpr PlanarTraction<Number> ScalarTraction<Number>::operator*(
    const PlanarDirection<Number>& planar_direction) const {
  return PlanarTraction<Number>{*this, planar_direction};
}

template <typename Number>
inline constexpr PlanarTraction<Number> PlanarForce<Number>::operator/(
    const Area<Number>& area) const {
  return PlanarTraction<Number>{*this, area};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PlanarTraction<Number>> {
  inline size_t operator()(const PhQ::PlanarTraction<Number>& planar_traction) const {
    return hash<PhQ::PlanarVector<Number>>()(planar_traction.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_TRACTION_HPP
