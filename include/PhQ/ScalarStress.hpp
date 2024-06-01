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

#ifndef PHQ_SCALAR_STRESS_HPP
#define PHQ_SCALAR_STRESS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarStress.
template <typename NumericType>
class Stress;

/// \brief Scalar component or resultant of a three-dimensional Euclidean Cauchy stress symmetric
/// dyadic tensor. For the related tensor, see PhQ::Stress.
template <typename NumericType = double>
class ScalarStress : public DimensionalScalar<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a scalar stress with an uninitialized value.
  ScalarStress() = default;

  /// \brief Constructor. Constructs a scalar stress with a given value expressed in a given
  /// pressure unit.
  ScalarStress(const NumericType value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Destructor. Destroys this scalar stress.
  ~ScalarStress() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar stress by copying another one.
  constexpr ScalarStress(const ScalarStress<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a scalar stress by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ScalarStress(const ScalarStress<OtherNumericType>& other)
    : ScalarStress(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar stress by moving another one.
  constexpr ScalarStress(ScalarStress<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar stress by copying another one.
  constexpr ScalarStress<NumericType>& operator=(const ScalarStress<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar stress by copying another one.
  template <typename OtherNumericType>
  constexpr ScalarStress<NumericType>& operator=(const ScalarStress<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar stress by moving another one.
  constexpr ScalarStress<NumericType>& operator=(
      ScalarStress<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a scalar stress of zero.
  static constexpr ScalarStress<NumericType> Zero() {
    return ScalarStress<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a scalar stress with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr ScalarStress<NumericType> Create(const NumericType value) {
    return ScalarStress<NumericType>{
        ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr ScalarStress<NumericType> operator+(
      const ScalarStress<NumericType>& scalar_stress) const {
    return ScalarStress<NumericType>{this->value + scalar_stress.value};
  }

  constexpr ScalarStress<NumericType> operator-(
      const ScalarStress<NumericType>& scalar_stress) const {
    return ScalarStress<NumericType>{this->value - scalar_stress.value};
  }

  constexpr ScalarStress<NumericType> operator*(const NumericType number) const {
    return ScalarStress<NumericType>{this->value * number};
  }

  constexpr ScalarStress<NumericType> operator/(const NumericType number) const {
    return ScalarStress<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const ScalarStress<NumericType>& scalar_stress) const noexcept {
    return this->value / scalar_stress.value;
  }

  constexpr void operator+=(const ScalarStress<NumericType>& scalar_stress) noexcept {
    this->value += scalar_stress.value;
  }

  constexpr void operator-=(const ScalarStress<NumericType>& scalar_stress) noexcept {
    this->value -= scalar_stress.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar stress with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr ScalarStress(const NumericType value)
    : DimensionalScalar<Unit::Pressure, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class Stress;
};

template <typename NumericType>
inline constexpr bool operator==(
    const ScalarStress<NumericType>& left, const ScalarStress<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const ScalarStress<NumericType>& left, const ScalarStress<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const ScalarStress<NumericType>& left, const ScalarStress<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const ScalarStress<NumericType>& left, const ScalarStress<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const ScalarStress<NumericType>& left, const ScalarStress<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const ScalarStress<NumericType>& left, const ScalarStress<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarStress<NumericType>& scalar_stress) {
  stream << scalar_stress.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ScalarStress<NumericType> operator*(
    const NumericType number, const ScalarStress<NumericType>& scalar_stress) {
  return scalar_stress * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ScalarStress<NumericType>> {
  inline size_t operator()(const PhQ::ScalarStress<NumericType>& scalar_stress) const {
    return hash<NumericType>()(scalar_stress.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_STRESS_HPP
