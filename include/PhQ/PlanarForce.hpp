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

#ifndef PHQ_PLANAR_FORCE_HPP
#define PHQ_PLANAR_FORCE_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalPlanarVector.hpp"
#include "PlanarDirection.hpp"
#include "PlanarVector.hpp"
#include "ScalarForce.hpp"
#include "Unit/Force.hpp"

namespace PhQ {

// Forward declaration for class PhQ::PlanarForce.
template <typename Number>
class PlanarTraction;

/// \brief Planar force vector in the XY plane. See also PhQ::Force and PhQ::ScalarForce.
template <typename Number = double>
class PlanarForce : public DimensionalPlanarVector<Unit::Force, Number> {
public:
  /// \brief Default constructor. Constructs a planar force vector with an uninitialized value.
  PlanarForce() = default;

  /// \brief Constructor. Constructs a planar force vector with a given value expressed in a given
  /// force unit.
  PlanarForce(const PlanarVector<Number>& value, const Unit::Force unit)
    : DimensionalPlanarVector<Unit::Force, Number>(value, unit) {}

  /// \brief Constructor. Constructs a planar force vector from a given scalar force magnitude and
  /// planar direction.
  constexpr PlanarForce(
      const ScalarForce<Number>& scalar_force, const PlanarDirection<Number>& planar_direction)
    : PlanarForce<Number>(scalar_force.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar force vector from a given planar traction and area
  /// using the definition of traction.
  constexpr PlanarForce(const PlanarTraction<Number>& planar_traction, const Area<Number>& area);

  /// \brief Destructor. Destroys this planar force vector.
  ~PlanarForce() noexcept = default;

  /// \brief Copy constructor. Constructs a planar force vector by copying another one.
  constexpr PlanarForce(const PlanarForce<Number>& other) = default;

  /// \brief Copy constructor. Constructs a planar force vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr PlanarForce(const PlanarForce<OtherNumber>& other)
    : PlanarForce(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar force vector by moving another one.
  constexpr PlanarForce(PlanarForce<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar force vector by copying another one.
  constexpr PlanarForce<Number>& operator=(const PlanarForce<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar force vector by copying another one.
  template <typename OtherNumber>
  constexpr PlanarForce<Number>& operator=(const PlanarForce<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar force vector by moving another one.
  constexpr PlanarForce<Number>& operator=(PlanarForce<Number>&& other) noexcept = default;

  /// \brief Statically creates a planar force vector of zero.
  static constexpr PlanarForce<Number> Zero() {
    return PlanarForce<Number>{PlanarVector<Number>::Zero()};
  }

  /// \brief Statically creates a planar force vector from the given x and y Cartesian components
  /// expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr PlanarForce<Number> Create(const Number x, const Number y) {
    return PlanarForce<Number>{
        StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(PlanarVector<Number>{x, y})};
  }

  /// \brief Statically creates a planar force vector from the given x and y Cartesian components
  /// expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr PlanarForce<Number> Create(const std::array<Number, 2>& x_y) {
    return PlanarForce<Number>{
        StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(PlanarVector<Number>{x_y})};
  }

  /// \brief Statically creates a planar force vector with a given value expressed in a given force
  /// unit.
  template <Unit::Force Unit>
  static constexpr PlanarForce<Number> Create(const PlanarVector<Number>& value) {
    return PlanarForce<Number>{StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar force vector.
  [[nodiscard]] constexpr ScalarForce<Number> x() const noexcept {
    return ScalarForce<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar force vector.
  [[nodiscard]] constexpr ScalarForce<Number> y() const noexcept {
    return ScalarForce<Number>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar force vector.
  [[nodiscard]] ScalarForce<Number> Magnitude() const {
    return ScalarForce<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the planar direction of this planar force vector.
  [[nodiscard]] PhQ::PlanarDirection<Number> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar force vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const PlanarForce<Number>& planar_force) const {
    return PhQ::Angle<Number>{*this, planar_force};
  }

  constexpr PlanarForce<Number> operator+(const PlanarForce<Number>& planar_force) const {
    return PlanarForce<Number>{this->value + planar_force.value};
  }

  constexpr PlanarForce<Number> operator-(const PlanarForce<Number>& planar_force) const {
    return PlanarForce<Number>{this->value - planar_force.value};
  }

  constexpr PlanarForce<Number> operator*(const Number number) const {
    return PlanarForce<Number>{this->value * number};
  }

  constexpr PlanarForce<Number> operator/(const Number number) const {
    return PlanarForce<Number>{this->value / number};
  }

  constexpr PlanarTraction<Number> operator/(const Area<Number>& area) const;

  constexpr void operator+=(const PlanarForce<Number>& planar_force) noexcept {
    this->value += planar_force.value;
  }

  constexpr void operator-=(const PlanarForce<Number>& planar_force) noexcept {
    this->value -= planar_force.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar force vector with a given value expressed in the
  /// standard force unit.
  explicit constexpr PlanarForce(const PlanarVector<Number>& value)
    : DimensionalPlanarVector<Unit::Force, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const PlanarForce<Number>& left, const PlanarForce<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PlanarForce<Number>& left, const PlanarForce<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PlanarForce<Number>& left, const PlanarForce<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PlanarForce<Number>& left, const PlanarForce<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PlanarForce<Number>& left, const PlanarForce<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PlanarForce<Number>& left, const PlanarForce<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const PlanarForce<Number>& planar_force) {
  stream << planar_force.Print();
  return stream;
}

template <typename Number>
inline constexpr PlanarForce<Number> operator*(
    const Number number, const PlanarForce<Number>& planar_force) {
  return planar_force * number;
}

template <typename Number>
inline PlanarDirection<Number>::PlanarDirection(const PlanarForce<Number>& planar_force)
  : PlanarDirection<Number>(planar_force.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(
    const PlanarForce<Number>& planar_force_1, const PlanarForce<Number>& planar_force_2)
  : Angle<Number>(planar_force_1.Value(), planar_force_2.Value()) {}

template <typename Number>
inline constexpr PlanarForce<Number> PlanarDirection<Number>::operator*(
    const ScalarForce<Number>& scalar_force) const {
  return PlanarForce<Number>{scalar_force, *this};
}

template <typename Number>
inline constexpr PlanarForce<Number> ScalarForce<Number>::operator*(
    const PlanarDirection<Number>& planar_direction) const {
  return PlanarForce<Number>{*this, planar_direction};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PlanarForce<Number>> {
  inline size_t operator()(const PhQ::PlanarForce<Number>& planar_force) const {
    return hash<PhQ::PlanarVector<Number>>()(planar_force.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_FORCE_HPP
