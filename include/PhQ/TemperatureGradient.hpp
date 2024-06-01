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

#ifndef PHQ_TEMPERATURE_GRADIENT_HPP
#define PHQ_TEMPERATURE_GRADIENT_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "PlanarTemperatureGradient.hpp"
#include "ScalarTemperatureGradient.hpp"
#include "Unit/TemperatureGradient.hpp"
#include "Vector.hpp"

namespace PhQ {

/// \brief Three-dimensional Euclidean temperature gradient vector. Contains three components in
/// Cartesian coordinates: x, y, and z. For a two-dimensional Euclidean temperature gradient vector
/// in the XY plane, see PhQ::PlanarTemperatureGradient. For scalar temperature gradient components
/// or for the magnitude of a temperature gradient vector, see PhQ::ScalarTemperatureGradient.
template <typename NumericType = double>
class TemperatureGradient : public DimensionalVector<Unit::TemperatureGradient, NumericType> {
public:
  /// \brief Default constructor. Constructs a temperature gradient vector with an uninitialized
  /// value.
  TemperatureGradient() = default;

  /// \brief Constructor. Constructs a temperature gradient vector with a given value expressed in a
  /// given temperature gradient unit.
  TemperatureGradient(const Vector<NumericType>& value, const Unit::TemperatureGradient unit)
    : DimensionalVector<Unit::TemperatureGradient, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a temperature gradient vector from a given set of scalar
  /// temperature gradient components.
  TemperatureGradient(const ScalarTemperatureGradient<NumericType>& x,
                      const ScalarTemperatureGradient<NumericType>& y,
                      const ScalarTemperatureGradient<NumericType>& z)
    : TemperatureGradient<NumericType>({x.Value(), y.Value(), z.Value()}) {}

  /// \brief Constructor. Constructs a temperature gradient vector from a given scalar temperature
  /// gradient magnitude and direction.
  constexpr TemperatureGradient(
      const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient,
      const Direction<NumericType>& direction)
    : TemperatureGradient<NumericType>(scalar_temperature_gradient.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs a temperature gradient vector from a given planar temperature
  /// gradient vector in the XY plane. This temperature gradient vector's z-component is initialized
  /// to zero.
  explicit constexpr TemperatureGradient(
      const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient)
    : TemperatureGradient<NumericType>(Vector<NumericType>{planar_temperature_gradient.Value()}) {}

  /// \brief Destructor. Destroys this temperature gradient vector.
  ~TemperatureGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a temperature gradient vector by copying another one.
  constexpr TemperatureGradient(const TemperatureGradient<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a temperature gradient vector by copying another one.
  template <typename OtherNumericType>
  explicit constexpr TemperatureGradient(const TemperatureGradient<OtherNumericType>& other)
    : TemperatureGradient(static_cast<Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a temperature gradient vector by moving another one.
  constexpr TemperatureGradient(TemperatureGradient<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this temperature gradient vector by copying another
  /// one.
  constexpr TemperatureGradient<NumericType>& operator=(
      const TemperatureGradient<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this temperature gradient vector by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr TemperatureGradient<NumericType>& operator=(
      const TemperatureGradient<OtherNumericType>& other) {
    this->value = static_cast<Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this temperature gradient vector by moving another
  /// one.
  constexpr TemperatureGradient<NumericType>& operator=(
      TemperatureGradient<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a temperature gradient vector of zero.
  static constexpr TemperatureGradient<NumericType> Zero() {
    return TemperatureGradient<NumericType>{Vector<NumericType>::Zero()};
  }

  /// \brief Statically creates a temperature gradient vector from the given x, y, and z Cartesian
  /// components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient<NumericType> Create(
      const NumericType x, const NumericType y, const NumericType z) {
    return TemperatureGradient<NumericType>{
        ConvertStatically<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            Vector<NumericType>{x, y, z})};
  }

  /// \brief Statically creates a temperature gradient vector from the given x, y, and z Cartesian
  /// components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient<NumericType> Create(
      const std::array<NumericType, 3>& x_y_z) {
    return TemperatureGradient<NumericType>{
        ConvertStatically<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            Vector<NumericType>{x_y_z})};
  }

  /// \brief Statically creates a temperature gradient vector with a given value expressed in a
  /// given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradient<NumericType> Create(const Vector<NumericType>& value) {
    return TemperatureGradient<NumericType>{
        ConvertStatically<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            value)};
  }

  /// \brief Returns the x Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<NumericType> x() const noexcept {
    return ScalarTemperatureGradient<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<NumericType> y() const noexcept {
    return ScalarTemperatureGradient<NumericType>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<NumericType> z() const noexcept {
    return ScalarTemperatureGradient<NumericType>{this->value.z()};
  }

  /// \brief Returns the magnitude of this temperature gradient vector.
  [[nodiscard]] ScalarTemperatureGradient<NumericType> Magnitude() const {
    return ScalarTemperatureGradient<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this temperature gradient vector.
  [[nodiscard]] PhQ::Direction<NumericType> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this temperature gradient vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(
      const TemperatureGradient<NumericType>& temperature_gradient) const {
    return PhQ::Angle<NumericType>{*this, temperature_gradient};
  }

  constexpr TemperatureGradient<NumericType> operator+(
      const TemperatureGradient<NumericType>& temperature_gradient) const {
    return TemperatureGradient<NumericType>{this->value + temperature_gradient.value};
  }

  constexpr TemperatureGradient<NumericType> operator-(
      const TemperatureGradient<NumericType>& temperature_gradient) const {
    return TemperatureGradient<NumericType>{this->value - temperature_gradient.value};
  }

  constexpr TemperatureGradient<NumericType> operator*(const NumericType number) const {
    return TemperatureGradient<NumericType>{this->value * number};
  }

  constexpr TemperatureGradient<NumericType> operator/(const NumericType number) const {
    return TemperatureGradient<NumericType>{this->value / number};
  }

  constexpr void operator+=(const TemperatureGradient<NumericType>& temperature_gradient) noexcept {
    this->value += temperature_gradient.value;
  }

  constexpr void operator-=(const TemperatureGradient<NumericType>& temperature_gradient) noexcept {
    this->value -= temperature_gradient.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a temperature gradient vector with a given value expressed in
  /// the standard temperature gradient unit.
  explicit constexpr TemperatureGradient(const Vector<NumericType>& value)
    : DimensionalVector<Unit::TemperatureGradient, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const TemperatureGradient<NumericType>& left,
                                 const TemperatureGradient<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const TemperatureGradient<NumericType>& left,
                                 const TemperatureGradient<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const TemperatureGradient<NumericType>& left,
                                const TemperatureGradient<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const TemperatureGradient<NumericType>& left,
                                const TemperatureGradient<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const TemperatureGradient<NumericType>& left,
                                 const TemperatureGradient<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const TemperatureGradient<NumericType>& left,
                                 const TemperatureGradient<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const TemperatureGradient<NumericType>& temperature_gradient) {
  stream << temperature_gradient.Print();
  return stream;
}

template <typename NumericType>
inline constexpr TemperatureGradient<NumericType> operator*(
    const NumericType number, const TemperatureGradient<NumericType>& temperature_gradient) {
  return temperature_gradient * number;
}

template <typename NumericType>
inline Direction<NumericType>::Direction(
    const TemperatureGradient<NumericType>& temperature_gradient)
  : Direction<NumericType>(temperature_gradient.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(const TemperatureGradient<NumericType>& temperature_gradient_1,
                                 const TemperatureGradient<NumericType>& temperature_gradient_2)
  : Angle<NumericType>(temperature_gradient_1.Value(), temperature_gradient_2.Value()) {}

template <typename NumericType>
inline constexpr TemperatureGradient<NumericType> Direction<NumericType>::operator*(
    const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) const {
  return TemperatureGradient<NumericType>{scalar_temperature_gradient, *this};
}

template <typename NumericType>
inline constexpr TemperatureGradient<NumericType> ScalarTemperatureGradient<NumericType>::operator*(
    const Direction<NumericType>& direction) const {
  return TemperatureGradient<NumericType>{*this, direction};
}

template <typename NumericType>
inline constexpr PlanarTemperatureGradient<NumericType>::PlanarTemperatureGradient(
    const TemperatureGradient<NumericType>& temperature_gradient)
  : PlanarTemperatureGradient(PlanarVector<NumericType>{temperature_gradient.Value()}) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::TemperatureGradient<NumericType>> {
  inline size_t operator()(
      const PhQ::TemperatureGradient<NumericType>& temperature_gradient) const {
    return hash<PhQ::Vector<NumericType>>()(temperature_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_TEMPERATURE_GRADIENT_HPP
