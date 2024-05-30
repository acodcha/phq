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

#ifndef PHQ_SCALAR_STRAIN_RATE_HPP
#define PHQ_SCALAR_STRAIN_RATE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "ScalarStrain.hpp"
#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

/// \brief Scalar component or resultant of a three-dimensional Euclidean strain rate symmetric
/// dyadic tensor. For the related tensor, see PhQ::StrainRate. See also PhQ::ScalarStrain,
/// PhQ::Time, and PhQ::Frequency.
template <typename NumericType = double>
class ScalarStrainRate : public DimensionalScalar<Unit::Frequency, NumericType> {
public:
  /// \brief Default constructor. Constructs a scalar strain rate with an uninitialized value.
  ScalarStrainRate() = default;

  /// \brief Constructor. Constructs a scalar strain rate with a given value expressed in a given
  /// frequency unit.
  ScalarStrainRate(const NumericType value, const Unit::Frequency unit)
    : DimensionalScalar<Unit::Frequency, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a scalar strain rate from a given scalar strain and time using
  /// the definition of strain rate.
  constexpr ScalarStrainRate(
      const ScalarStrain<NumericType>& scalar_strain, const Time<NumericType>& time)
    : ScalarStrainRate<NumericType>(scalar_strain.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a scalar strain rate from a given scalar strain and frequency
  /// using the definition of strain rate.
  constexpr ScalarStrainRate(
      const ScalarStrain<NumericType>& scalar_strain, const Frequency<NumericType>& frequency)
    : ScalarStrainRate<NumericType>(scalar_strain.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this scalar strain rate.
  ~ScalarStrainRate() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar strain rate by copying another one.
  constexpr ScalarStrainRate(const ScalarStrainRate<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a scalar strain rate by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ScalarStrainRate(const ScalarStrainRate<OtherNumericType>& other)
    : ScalarStrainRate(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar strain rate by moving another one.
  constexpr ScalarStrainRate(ScalarStrainRate<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar strain rate by copying another one.
  constexpr ScalarStrainRate<NumericType>& operator=(
      const ScalarStrainRate<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar strain rate by copying another one.
  template <typename OtherNumericType>
  constexpr ScalarStrainRate<NumericType>& operator=(
      const ScalarStrainRate<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar strain rate by moving another one.
  constexpr ScalarStrainRate<NumericType>& operator=(
      ScalarStrainRate<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a scalar strain rate of zero.
  static constexpr ScalarStrainRate<NumericType> Zero() {
    return ScalarStrainRate<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a scalar strain rate with a given value expressed in a given
  /// frequency unit.
  template <Unit::Frequency Unit>
  static constexpr ScalarStrainRate<NumericType> Create(const NumericType value) {
    return ScalarStrainRate<NumericType>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  constexpr ScalarStrainRate<NumericType> operator+(
      const ScalarStrainRate<NumericType>& other) const {
    return ScalarStrainRate<NumericType>{this->value + other.value};
  }

  constexpr ScalarStrainRate<NumericType> operator-(
      const ScalarStrainRate<NumericType>& other) const {
    return ScalarStrainRate<NumericType>{this->value - other.value};
  }

  constexpr ScalarStrainRate<NumericType> operator*(const NumericType number) const {
    return ScalarStrainRate<NumericType>{this->value * number};
  }

  constexpr ScalarStrainRate<NumericType> operator/(const NumericType number) const {
    return ScalarStrainRate<NumericType>{this->value / number};
  }

  constexpr ScalarStrain<NumericType> operator*(const Time<NumericType>& time) const {
    return ScalarStrain<NumericType>{*this, time};
  }

  constexpr NumericType operator/(const ScalarStrainRate<NumericType>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr ScalarStrain<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return ScalarStrain<NumericType>{*this, frequency};
  }

  constexpr void operator+=(const ScalarStrainRate<NumericType>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const ScalarStrainRate<NumericType>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar strain rate with a given value expressed in the
  /// standard frequency unit.
  explicit constexpr ScalarStrainRate(const NumericType value)
    : DimensionalScalar<Unit::Frequency, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class StrainRate;
};

template <typename NumericType>
inline constexpr bool operator==(const ScalarStrainRate<NumericType>& left,
                                 const ScalarStrainRate<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const ScalarStrainRate<NumericType>& left,
                                 const ScalarStrainRate<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const ScalarStrainRate<NumericType>& left,
                                const ScalarStrainRate<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const ScalarStrainRate<NumericType>& left,
                                const ScalarStrainRate<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const ScalarStrainRate<NumericType>& left,
                                 const ScalarStrainRate<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const ScalarStrainRate<NumericType>& left,
                                 const ScalarStrainRate<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarStrainRate<NumericType>& scalar_strain_rate) {
  stream << scalar_strain_rate.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ScalarStrainRate<NumericType> operator*(
    const NumericType number, const ScalarStrainRate<NumericType>& scalar_strain_rate) {
  return scalar_strain_rate * number;
}

template <typename NumericType>
inline constexpr ScalarStrain<NumericType>::ScalarStrain(
    const ScalarStrainRate<NumericType>& scalar_strain_rate, const Time<NumericType>& time)
  : ScalarStrain<NumericType>(scalar_strain_rate.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr ScalarStrain<NumericType>::ScalarStrain(
    const ScalarStrainRate<NumericType>& scalar_strain_rate,
    const Frequency<NumericType>& frequency)
  : ScalarStrain<NumericType>(scalar_strain_rate.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr ScalarStrainRate<NumericType> ScalarStrain<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return ScalarStrainRate<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr ScalarStrainRate<NumericType> ScalarStrain<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return ScalarStrainRate<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr ScalarStrain<NumericType> Time<NumericType>::operator*(
    const ScalarStrainRate<NumericType>& scalar_strain_rate) const {
  return ScalarStrain<NumericType>{scalar_strain_rate, *this};
}

template <typename NumericType>
inline constexpr ScalarStrainRate<NumericType> Frequency<NumericType>::operator*(
    const ScalarStrain<NumericType>& scalar_strain) const {
  return ScalarStrainRate<NumericType>{scalar_strain, *this};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ScalarStrainRate<NumericType>> {
  inline size_t operator()(const PhQ::ScalarStrainRate<NumericType>& scalar_strain_rate) const {
    return hash<NumericType>()(scalar_strain_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_STRAIN_RATE_HPP
