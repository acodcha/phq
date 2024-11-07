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

#ifndef PHQ_SCALAR_TEMPERATURE_GRADIENT_HPP
#define PHQ_SCALAR_TEMPERATURE_GRADIENT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Length.hpp"
#include "TemperatureDifference.hpp"
#include "Unit/TemperatureGradient.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarTemperatureGradient.
template <typename NumericType>
class Direction;

// Forward declaration for class PhQ::ScalarTemperatureGradient.
template <typename NumericType>
class PlanarDirection;

// Forward declaration for class PhQ::ScalarTemperatureGradient.
template <typename NumericType>
class PlanarTemperatureGradient;

// Forward declaration for class PhQ::ScalarTemperatureGradient.
template <typename NumericType>
class TemperatureGradient;

/// \brief Scalar temperature gradient component or magnitude of a temperature gradient vector. For
/// a three-dimensional Euclidean temperature gradient vector, see PhQ::TemperatureGradient. For a
/// two-dimensional Euclidean temperature gradient vector in the XY plane, see
/// PhQ::PlanarTemperatureGradient.
template <typename NumericType = double>
class ScalarTemperatureGradient : public DimensionalScalar<Unit::TemperatureGradient, NumericType> {
public:
  /// \brief Default constructor. Constructs a scalar temperature gradient with an uninitialized
  /// value.
  ScalarTemperatureGradient() = default;

  /// \brief Constructor. Constructs a scalar temperature gradient with a given value expressed in a
  /// given temperature gradient unit.
  ScalarTemperatureGradient(const NumericType value, const Unit::TemperatureGradient unit)
    : DimensionalScalar<Unit::TemperatureGradient, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a scalar temperature gradient from a given temperature
  /// difference and length using the definition of temperature gradient.
  constexpr ScalarTemperatureGradient(
      const TemperatureDifference<NumericType>& temperature_difference,
      const Length<NumericType>& length)
    : ScalarTemperatureGradient<NumericType>(temperature_difference.Value() / length.Value()) {}

  /// \brief Destructor. Destroys this scalar temperature gradient.
  ~ScalarTemperatureGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar temperature gradient by copying another one.
  constexpr ScalarTemperatureGradient(
      const ScalarTemperatureGradient<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a scalar temperature gradient by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ScalarTemperatureGradient(
      const ScalarTemperatureGradient<OtherNumericType>& other)
    : ScalarTemperatureGradient(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar temperature gradient by moving another one.
  constexpr ScalarTemperatureGradient(
      ScalarTemperatureGradient<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar temperature gradient by copying another
  /// one.
  constexpr ScalarTemperatureGradient<NumericType>& operator=(
      const ScalarTemperatureGradient<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar temperature gradient by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr ScalarTemperatureGradient<NumericType>& operator=(
      const ScalarTemperatureGradient<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar temperature gradient by moving another
  /// one.
  constexpr ScalarTemperatureGradient<NumericType>& operator=(
      ScalarTemperatureGradient<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a scalar temperature gradient of zero.
  [[nodiscard]] static constexpr ScalarTemperatureGradient<NumericType> Zero() {
    return ScalarTemperatureGradient<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a scalar temperature gradient with a given value expressed in a
  /// given temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  [[nodiscard]] static constexpr ScalarTemperatureGradient<NumericType> Create(
      const NumericType value) {
    return ScalarTemperatureGradient<NumericType>{
      ConvertStatically<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
          value)};
  }

  constexpr ScalarTemperatureGradient<NumericType> operator+(
      const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) const {
    return ScalarTemperatureGradient<NumericType>{this->value + scalar_temperature_gradient.value};
  }

  constexpr ScalarTemperatureGradient<NumericType> operator-(
      const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) const {
    return ScalarTemperatureGradient<NumericType>{this->value - scalar_temperature_gradient.value};
  }

  constexpr ScalarTemperatureGradient<NumericType> operator*(const NumericType number) const {
    return ScalarTemperatureGradient<NumericType>{this->value * number};
  }

  constexpr TemperatureDifference<NumericType> operator*(const Length<NumericType>& length) const {
    return TemperatureDifference<NumericType>{*this, length};
  }

  constexpr PlanarTemperatureGradient<NumericType> operator*(
      const PlanarDirection<NumericType>& planar_direction) const;

  constexpr TemperatureGradient<NumericType> operator*(
      const Direction<NumericType>& direction) const;

  constexpr ScalarTemperatureGradient<NumericType> operator/(const NumericType number) const {
    return ScalarTemperatureGradient<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) const noexcept {
    return this->value / scalar_temperature_gradient.value;
  }

  constexpr void operator+=(
      const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) noexcept {
    this->value += scalar_temperature_gradient.value;
  }

  constexpr void operator-=(
      const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) noexcept {
    this->value -= scalar_temperature_gradient.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar temperature gradient with a given value expressed in
  /// the standard temperature gradient unit.
  explicit constexpr ScalarTemperatureGradient(const NumericType value)
    : DimensionalScalar<Unit::TemperatureGradient, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class PlanarTemperatureGradient;

  template <typename OtherNumericType>
  friend class TemperatureGradient;
};

template <typename NumericType>
inline constexpr bool operator==(const ScalarTemperatureGradient<NumericType>& left,
                                 const ScalarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const ScalarTemperatureGradient<NumericType>& left,
                                 const ScalarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const ScalarTemperatureGradient<NumericType>& left,
                                const ScalarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const ScalarTemperatureGradient<NumericType>& left,
                                const ScalarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const ScalarTemperatureGradient<NumericType>& left,
                                 const ScalarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const ScalarTemperatureGradient<NumericType>& left,
                                 const ScalarTemperatureGradient<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream,
    const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) {
  stream << scalar_temperature_gradient.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ScalarTemperatureGradient<NumericType> operator*(
    const NumericType number,
    const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) {
  return scalar_temperature_gradient * number;
}

template <typename NumericType>
inline constexpr TemperatureDifference<NumericType>::TemperatureDifference(
    const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient,
    const Length<NumericType>& length)
  : TemperatureDifference<NumericType>(scalar_temperature_gradient.Value() * length.Value()) {}

template <typename NumericType>
inline constexpr ScalarTemperatureGradient<NumericType> TemperatureDifference<NumericType>::
operator/(const Length<NumericType>& length) const {
  return ScalarTemperatureGradient<NumericType>{*this, length};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ScalarTemperatureGradient<NumericType>> {
  inline size_t operator()(
      const PhQ::ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient) const {
    return hash<NumericType>()(scalar_temperature_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_TEMPERATURE_GRADIENT_HPP
