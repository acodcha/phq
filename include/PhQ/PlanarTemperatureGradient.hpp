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

#ifndef PHQ_PLANAR_TEMPERATURE_GRADIENT_HPP
#define PHQ_PLANAR_TEMPERATURE_GRADIENT_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalPlanarVector.hpp"
#include "PlanarDirection.hpp"
#include "PlanarVector.hpp"
#include "ScalarTemperatureGradient.hpp"
#include "Unit/TemperatureGradient.hpp"

namespace PhQ {

/// \brief Two-dimensional Euclidean temperature gradient vector in the XY plane. Contains two
/// components in Cartesian coordinates: x and y. For a three-dimensional Euclidean temperature
/// gradient vector, see PhQ::TemperatureGradient. For scalar temperature gradient components or for
/// the magnitude of a temperature gradient vector, see PhQ::ScalarTemperatureGradient.
template <typename NumericType = double>
class PlanarTemperatureGradient
  : public DimensionalPlanarVector<Unit::TemperatureGradient, NumericType> {
public:
  /// \brief Default constructor. Constructs a planar temperature gradient vector with an
  /// uninitialized value.
  PlanarTemperatureGradient() = default;

  /// \brief Constructor. Constructs a planar temperature gradient vector with a given value
  /// expressed in a given temperature gradient unit.
  PlanarTemperatureGradient(
      const PlanarVector<NumericType>& value, const Unit::TemperatureGradient unit)
    : DimensionalPlanarVector<Unit::TemperatureGradient, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a planar temperature gradient vector from a given set of scalar
  /// temperature gradient components.
  PlanarTemperatureGradient(const ScalarTemperatureGradient<NumericType>& x,
                            const ScalarTemperatureGradient<NumericType>& y)
    : PlanarTemperatureGradient<NumericType>({x.Value(), y.Value()}) {}

  /// \brief Constructor. Constructs a planar temperature gradient vector from a given scalar
  /// temperature gradient magnitude and planar direction.
  constexpr PlanarTemperatureGradient(
      const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient,
      const PlanarDirection<NumericType>& planar_direction)
    : PlanarTemperatureGradient<NumericType>(
        scalar_temperature_gradient.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar temperature gradient vector from a given temperature
  /// gradient vector by projecting the temperature gradient vector onto the XY plane.
  explicit constexpr PlanarTemperatureGradient(
      const TemperatureGradient<NumericType>& temperature_gradient);

  /// \brief Destructor. Destroys this planar temperature gradient vector.
  ~PlanarTemperatureGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a planar temperature gradient vector by copying another
  /// one.
  constexpr PlanarTemperatureGradient(
      const PlanarTemperatureGradient<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a planar temperature gradient vector by copying another
  /// one.
  template <typename OtherNumericType>
  explicit constexpr PlanarTemperatureGradient(
      const PlanarTemperatureGradient<OtherNumericType>& other)
    : PlanarTemperatureGradient(static_cast<PlanarVector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar temperature gradient vector by moving another
  /// one.
  constexpr PlanarTemperatureGradient(
      PlanarTemperatureGradient<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar temperature gradient vector by copying
  /// another one.
  constexpr PlanarTemperatureGradient<NumericType>& operator=(
      const PlanarTemperatureGradient<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar temperature gradient vector by copying
  /// another one.
  template <typename OtherNumericType>
  constexpr PlanarTemperatureGradient<NumericType>& operator=(
      const PlanarTemperatureGradient<OtherNumericType>& other) {
    this->value = static_cast<PlanarVector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar temperature gradient vector by moving
  /// another one.
  constexpr PlanarTemperatureGradient<NumericType>& operator=(
      PlanarTemperatureGradient<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a planar temperature gradient vector of zero.
  [[nodiscard]] static constexpr PlanarTemperatureGradient<NumericType> Zero() {
    return PlanarTemperatureGradient<NumericType>{PlanarVector<NumericType>::Zero()};
  }

  /// \brief Statically creates a planar temperature gradient vector from the given x and y
  /// Cartesian components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  [[nodiscard]] static constexpr PlanarTemperatureGradient<NumericType> Create(
      const NumericType x, const NumericType y) {
    return PlanarTemperatureGradient<NumericType>{
        ConvertStatically<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            PlanarVector<NumericType>{x, y})};
  }

  /// \brief Statically creates a planar temperature gradient vector from the given x and y
  /// Cartesian components expressed in a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  [[nodiscard]] static constexpr PlanarTemperatureGradient<NumericType> Create(
      const std::array<NumericType, 2>& x_y) {
    return PlanarTemperatureGradient<NumericType>{
        ConvertStatically<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            PlanarVector<NumericType>{x_y})};
  }

  /// \brief Statically creates a planar temperature gradient vector with a given value expressed in
  /// a given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  [[nodiscard]] static constexpr PlanarTemperatureGradient<NumericType> Create(
      const PlanarVector<NumericType>& value) {
    return PlanarTemperatureGradient<NumericType>{
        ConvertStatically<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            value)};
  }

  /// \brief Returns the x Cartesian component of this planar temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<NumericType> x() const noexcept {
    return ScalarTemperatureGradient<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar temperature gradient vector.
  [[nodiscard]] constexpr ScalarTemperatureGradient<NumericType> y() const noexcept {
    return ScalarTemperatureGradient<NumericType>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar temperature gradient vector.
  [[nodiscard]] ScalarTemperatureGradient<NumericType> Magnitude() const {
    return ScalarTemperatureGradient<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this planar temperature gradient vector.
  [[nodiscard]] PhQ::PlanarDirection<NumericType> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar temperature gradient vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(
      const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient) const {
    return PhQ::Angle<NumericType>{*this, planar_temperature_gradient};
  }

  constexpr PlanarTemperatureGradient<NumericType> operator+(
      const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient) const {
    return PlanarTemperatureGradient<NumericType>{this->value + planar_temperature_gradient.value};
  }

  constexpr PlanarTemperatureGradient<NumericType> operator-(
      const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient) const {
    return PlanarTemperatureGradient<NumericType>{this->value - planar_temperature_gradient.value};
  }

  constexpr PlanarTemperatureGradient<NumericType> operator*(const NumericType number) const {
    return PlanarTemperatureGradient<NumericType>{this->value * number};
  }

  constexpr PlanarTemperatureGradient<NumericType> operator/(const NumericType number) const {
    return PlanarTemperatureGradient<NumericType>{this->value / number};
  }

  constexpr void operator+=(
      const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient) noexcept {
    this->value += planar_temperature_gradient.value;
  }

  constexpr void operator-=(
      const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient) noexcept {
    this->value -= planar_temperature_gradient.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar temperature gradient vector with a given value
  /// expressed in the standard temperature gradient unit.
  explicit constexpr PlanarTemperatureGradient(const PlanarVector<NumericType>& value)
    : DimensionalPlanarVector<Unit::TemperatureGradient, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const PlanarTemperatureGradient<NumericType>& left,
                                 const PlanarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const PlanarTemperatureGradient<NumericType>& left,
                                 const PlanarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const PlanarTemperatureGradient<NumericType>& left,
                                const PlanarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const PlanarTemperatureGradient<NumericType>& left,
                                const PlanarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const PlanarTemperatureGradient<NumericType>& left,
                                 const PlanarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const PlanarTemperatureGradient<NumericType>& left,
                                 const PlanarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream,
    const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient) {
  stream << planar_temperature_gradient.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PlanarTemperatureGradient<NumericType> operator*(
    const NumericType number,
    const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient) {
  return planar_temperature_gradient * number;
}

template <typename NumericType>
inline PlanarDirection<NumericType>::PlanarDirection(
    const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient)
  : PlanarDirection<NumericType>(planar_temperature_gradient.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(
    const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient_1,
    const PlanarTemperatureGradient<NumericType>& planar_temperature_gradient_2)
  : Angle<NumericType>(
      planar_temperature_gradient_1.Value(), planar_temperature_gradient_2.Value()) {}

template <typename NumericType>
inline constexpr PlanarTemperatureGradient<NumericType> PlanarDirection<NumericType>::operator*(
    const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) const {
  return PlanarTemperatureGradient<NumericType>{scalar_temperature_gradient, *this};
}

template <typename NumericType>
inline constexpr PlanarTemperatureGradient<NumericType>
ScalarTemperatureGradient<NumericType>::operator*(
    const PlanarDirection<NumericType>& planar_direction) const {
  return PlanarTemperatureGradient<NumericType>{*this, planar_direction};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PlanarTemperatureGradient<NumericType>> {
  inline size_t operator()(
      const PhQ::PlanarTemperatureGradient<NumericType>& planar_temperature_gradient) const {
    return hash<PhQ::PlanarVector<NumericType>>()(planar_temperature_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_TEMPERATURE_GRADIENT_HPP
