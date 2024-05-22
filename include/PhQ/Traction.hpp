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

#ifndef PHQ_TRACTION_HPP
#define PHQ_TRACTION_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Area.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "Force.hpp"
#include "StaticPressure.hpp"
#include "Unit/Pressure.hpp"
#include "Vector.hpp"

namespace PhQ {

/// \brief Traction vector.
template <typename Number = double>
class Traction : public DimensionalVector<Unit::Pressure, Number> {
public:
  /// \brief Default constructor. Constructs a traction vector with an uninitialized value.
  Traction() = default;

  /// \brief Constructor. Constructs a traction vector with a given value expressed in a given
  /// pressure unit.
  Traction(const Vector<Number>& value, const Unit::Pressure unit)
    : DimensionalVector<Unit::Pressure, Number>(value, unit) {}

  /// \brief Constructor. Constructs a traction vector from a given static pressure and direction.
  /// Since pressure is compressive, the negative of the static pressure contributes to the traction
  /// vector.
  constexpr Traction(
      const StaticPressure<Number>& static_pressure, const Direction<Number>& direction)
    : Traction<Number>(-static_pressure.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs a traction vector from a given force and area using the
  /// definition of traction.
  constexpr Traction(const Force<Number>& force, const Area<Number>& area)
    : Traction<Number>(force.Value() / area.Value()) {}

  /// \brief Constructor. Constructs a traction vector from a given stress and direction using the
  /// definition of traction.
  constexpr Traction(const Stress<Number>& stress, const Direction<Number>& direction);

  /// \brief Destructor. Destroys this traction vector.
  ~Traction() noexcept = default;

  /// \brief Copy constructor. Constructs a traction vector by copying another one.
  constexpr Traction(const Traction<Number>& other) = default;

  /// \brief Copy constructor. Constructs a traction vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr Traction(const Traction<OtherNumber>& other)
    : Traction(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a traction vector by moving another one.
  constexpr Traction(Traction<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this traction vector by copying another one.
  constexpr Traction<Number>& operator=(const Traction<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this traction vector by copying another one.
  template <typename OtherNumber>
  constexpr Traction<Number>& operator=(const Traction<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this traction vector by moving another one.
  constexpr Traction<Number>& operator=(Traction<Number>&& other) noexcept = default;

  /// \brief Statically creates a traction vector of zero.
  static constexpr Traction<Number> Zero() {
    return Traction<Number>{Vector<Number>::Zero()};
  }

  /// \brief Statically creates a traction vector from the given x, y, and z Cartesian components
  /// expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Traction<Number> Create(const Number x, const Number y, const Number z) {
    return Traction<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(Vector<Number>{x, y, z})};
  }

  /// \brief Statically creates a traction vector from the given x, y, and z Cartesian components
  /// expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Traction<Number> Create(const std::array<Number, 3>& x_y_z) {
    return Traction<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(Vector<Number>{x_y_z})};
  }

  /// \brief Statically creates a traction vector with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr Traction<Number> Create(const Vector<Number>& value) {
    return Traction<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  /// \brief Returns the x Cartesian component of this traction vector.
  [[nodiscard]] constexpr StaticPressure<Number> x() const noexcept {
    return StaticPressure<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this traction vector.
  [[nodiscard]] constexpr StaticPressure<Number> y() const noexcept {
    return StaticPressure<Number>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this traction vector.
  [[nodiscard]] constexpr StaticPressure<Number> z() const noexcept {
    return StaticPressure<Number>{this->value.z()};
  }

  /// \brief Returns the magnitude of this traction vector. Since pressure is compressive, the
  /// static pressure that corresponds to the magnitude of this traction vector is negative.
  [[nodiscard]] StaticPressure<Number> Magnitude() const {
    return StaticPressure<Number>{-this->value.Magnitude()};
  }

  /// \brief Returns the direction of this traction vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this traction vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const Traction<Number>& traction) const {
    return PhQ::Angle<Number>{*this, traction};
  }

  constexpr Traction<Number> operator+(const Traction<Number>& traction) const {
    return Traction<Number>{this->value + traction.value};
  }

  constexpr Traction<Number> operator-(const Traction<Number>& traction) const {
    return Traction<Number>{this->value - traction.value};
  }

  constexpr Traction<Number> operator*(const Number number) const {
    return Traction<Number>{this->value * number};
  }

  constexpr Force<Number> operator*(const Area<Number>& area) const {
    return Force<Number>{*this, area};
  }

  constexpr Traction<Number> operator/(const Number number) const {
    return Traction<Number>{this->value / number};
  }

  constexpr void operator+=(const Traction<Number>& traction) noexcept {
    this->value += traction.value;
  }

  constexpr void operator-=(const Traction<Number>& traction) noexcept {
    this->value -= traction.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a traction vector with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr Traction(const Vector<Number>& value)
    : DimensionalVector<Unit::Pressure, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const Traction<Number>& left, const Traction<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const Traction<Number>& left, const Traction<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const Traction<Number>& left, const Traction<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const Traction<Number>& left, const Traction<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const Traction<Number>& left, const Traction<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const Traction<Number>& left, const Traction<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Traction<Number>& traction) {
  stream << traction.Print();
  return stream;
}

template <typename Number>
inline constexpr Traction<Number> operator*(const Number number, const Traction<Number>& traction) {
  return traction * number;
}

template <typename Number>
inline Direction<Number>::Direction(const Traction<Number>& traction)
  : Direction<Number>(traction.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const Traction<Number>& traction1, const Traction<Number>& traction2)
  : Angle<Number>(traction1.Value(), traction2.Value()) {}

template <typename Number>
inline constexpr Force<Number>::Force(const Traction<Number>& traction, const Area<Number>& area)
  : Force<Number>(traction.Value() * area.Value()) {}

template <typename Number>
inline constexpr Traction<Number> Direction<Number>::operator*(
    const StaticPressure<Number>& static_pressure) const {
  return Traction<Number>{static_pressure, *this};
}

template <typename Number>
inline constexpr Traction<Number> StaticPressure<Number>::operator*(
    const Direction<Number>& direction) const {
  return Traction<Number>{*this, direction};
}

template <typename Number>
inline constexpr Traction<Number> Force<Number>::operator/(const Area<Number>& area) const {
  return Traction<Number>{*this, area};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Traction<Number>> {
  inline size_t operator()(const PhQ::Traction<Number>& traction) const {
    return hash<PhQ::Vector<Number>>()(traction.Value());
  }
};

}  // namespace std

#endif  // PHQ_TRACTION_HPP
