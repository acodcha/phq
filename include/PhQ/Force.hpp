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

#ifndef PHQ_FORCE_HPP
#define PHQ_FORCE_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "ScalarForce.hpp"
#include "Unit/Force.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Force.
template <typename Number>
class Traction;

/// \brief Force vector. See also PhQ::ScalarForce.
template <typename Number = double>
class Force : public DimensionalVector<Unit::Force, Number> {
public:
  /// \brief Default constructor. Constructs a force vector with an uninitialized value.
  Force() = default;

  /// \brief Constructor. Constructs a force vector with a given value expressed in a given force
  /// unit.
  Force(const Vector<Number>& value, const Unit::Force unit)
    : DimensionalVector<Unit::Force, Number>(value, unit) {}

  /// \brief Constructor. Constructs a force vector from a given scalar force magnitude and
  /// direction.
  constexpr Force(const ScalarForce<Number>& scalar_force, const Direction<Number>& direction)
    : Force<Number>(scalar_force.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs a force vector from a given traction and area using the
  /// definition of traction.
  constexpr Force(const Traction<Number>& traction, const Area<Number>& area);

  /// \brief Destructor. Destroys this force vector.
  ~Force() noexcept = default;

  /// \brief Copy constructor. Constructs a force vector by copying another one.
  constexpr Force(const Force<Number>& other) = default;

  /// \brief Copy constructor. Constructs a force vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr Force(const Force<OtherNumber>& other)
    : Force(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a force vector by moving another one.
  constexpr Force(Force<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this force vector by copying another one.
  constexpr Force<Number>& operator=(const Force<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this force vector by copying another one.
  template <typename OtherNumber>
  constexpr Force<Number>& operator=(const Force<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this force vector by moving another one.
  constexpr Force<Number>& operator=(Force<Number>&& other) noexcept = default;

  /// \brief Statically creates a force vector of zero.
  static constexpr Force<Number> Zero() {
    return Force<Number>{Vector<Number>::Zero()};
  }

  /// \brief Statically creates a force vector from the given x, y, and z Cartesian components
  /// expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr Force<Number> Create(const Number x, const Number y, const Number z) {
    return Force<Number>{
        StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(Vector<Number>{x, y, z})};
  }

  /// \brief Statically creates a force vector from the given x, y, and z Cartesian components
  /// expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr Force<Number> Create(const std::array<Number, 3>& x_y_z) {
    return Force<Number>{
        StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(Vector<Number>{x_y_z})};
  }

  /// \brief Statically creates a force vector with a given value expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr Force<Number> Create(const Vector<Number>& value) {
    return Force<Number>{StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  /// \brief Returns the x Cartesian component of this force vector.
  [[nodiscard]] constexpr ScalarForce<Number> x() const noexcept {
    return ScalarForce<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this force vector.
  [[nodiscard]] constexpr ScalarForce<Number> y() const noexcept {
    return ScalarForce<Number>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this force vector.
  [[nodiscard]] constexpr ScalarForce<Number> z() const noexcept {
    return ScalarForce<Number>{this->value.z()};
  }

  /// \brief Returns the magnitude of this force vector.
  [[nodiscard]] ScalarForce<Number> Magnitude() const {
    return ScalarForce<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this force vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this force vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const Force<Number>& force) const {
    return PhQ::Angle<Number>{*this, force};
  }

  constexpr Force<Number> operator+(const Force<Number>& force) const {
    return Force<Number>{this->value + force.value};
  }

  constexpr Force<Number> operator-(const Force<Number>& force) const {
    return Force<Number>{this->value - force.value};
  }

  constexpr Force<Number> operator*(const Number number) const {
    return Force<Number>{this->value * number};
  }

  constexpr Force<Number> operator/(const Number number) const {
    return Force<Number>{this->value / number};
  }

  constexpr Traction<Number> operator/(const Area<Number>& area) const;

  constexpr void operator+=(const Force<Number>& force) noexcept {
    this->value += force.value;
  }

  constexpr void operator-=(const Force<Number>& force) noexcept {
    this->value -= force.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a force vector with a given value expressed in the standard
  /// force unit.
  explicit constexpr Force(const Vector<Number>& value)
    : DimensionalVector<Unit::Force, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const Force<Number>& left, const Force<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Force<Number>& left, const Force<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Force<Number>& left, const Force<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Force<Number>& left, const Force<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Force<Number>& left, const Force<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Force<Number>& left, const Force<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Force<Number>& force) {
  stream << force.Print();
  return stream;
}

template <typename Number>
inline constexpr Force<Number> operator*(const Number number, const Force<Number>& force) {
  return force * number;
}

template <typename Number>
inline Direction<Number>::Direction(const Force<Number>& force)
  : Direction<Number>(force.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const Force<Number>& force1, const Force<Number>& force2)
  : Angle<Number>(force1.Value(), force2.Value()) {}

template <typename Number>
inline constexpr Force<Number> Direction<Number>::operator*(
    const ScalarForce<Number>& scalar_force) const {
  return Force<Number>{scalar_force, *this};
}

template <typename Number>
inline constexpr Force<Number> ScalarForce<Number>::operator*(
    const Direction<Number>& direction) const {
  return Force<Number>{*this, direction};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Force<Number>> {
  inline size_t operator()(const PhQ::Force<Number>& force) const {
    return hash<PhQ::Vector<Number>>()(force.Value());
  }
};

}  // namespace std

#endif  // PHQ_FORCE_HPP
