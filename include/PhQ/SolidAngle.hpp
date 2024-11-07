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

#ifndef PHQ_SOLID_ANGLE_HPP
#define PHQ_SOLID_ANGLE_HPP

#include <cmath>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/SolidAngle.hpp"

namespace PhQ {

/// \brief Solid angle. Measures the field of view of a portion of the surface of the unit sphere
/// viewed from the center of the unit sphere. Typically measured in steradians (sr), which are
/// square radians. The unit sphere has a total solid angle of 4π steradians.
template <typename NumericType = double>
class SolidAngle : public DimensionalScalar<Unit::SolidAngle, NumericType> {
public:
  /// \brief Default constructor. Constructs a solid angle with an uninitialized value.
  SolidAngle() = default;

  /// \brief Constructor. Constructs a solid angle with a given value expressed in a given solid
  /// angle unit.
  SolidAngle(const NumericType value, const Unit::SolidAngle unit)
    : DimensionalScalar<Unit::SolidAngle, NumericType>(value, unit) {}

  /// \brief Destructor. Destroys this solid angle.
  ~SolidAngle() noexcept = default;

  /// \brief Copy constructor. Constructs a solid angle by copying another one.
  constexpr SolidAngle(const SolidAngle<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a solid angle by copying another one.
  template <typename OtherNumericType>
  explicit constexpr SolidAngle(const SolidAngle<OtherNumericType>& other)
    : SolidAngle(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a solid angle by moving another one.
  constexpr SolidAngle(SolidAngle<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this solid angle by copying another one.
  constexpr SolidAngle<NumericType>& operator=(const SolidAngle<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this solid angle by copying another one.
  template <typename OtherNumericType>
  constexpr SolidAngle<NumericType>& operator=(const SolidAngle<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this solid angle by moving another one.
  constexpr SolidAngle<NumericType>& operator=(SolidAngle<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a solid angle of zero.
  [[nodiscard]] static constexpr SolidAngle<NumericType> Zero() {
    return SolidAngle<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a solid angle with a given value expressed in a given solid angle
  /// unit.
  template <Unit::SolidAngle Unit>
  [[nodiscard]] static constexpr SolidAngle<NumericType> Create(const NumericType value) {
    return SolidAngle<NumericType>{
      ConvertStatically<Unit::SolidAngle, Unit, Standard<Unit::SolidAngle>>(value)};
  }

  constexpr SolidAngle<NumericType> operator+(const SolidAngle<NumericType>& other) const {
    return SolidAngle<NumericType>{this->value + other.value};
  }

  constexpr SolidAngle<NumericType> operator-(const SolidAngle<NumericType>& other) const {
    return SolidAngle<NumericType>{this->value - other.value};
  }

  constexpr SolidAngle<NumericType> operator*(const NumericType number) const {
    return SolidAngle<NumericType>{this->value * number};
  }

  constexpr SolidAngle<NumericType> operator/(const NumericType number) const {
    return SolidAngle<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const SolidAngle<NumericType>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr void operator+=(const SolidAngle<NumericType>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const SolidAngle<NumericType>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a solid angle with a given value expressed in the standard
  /// solid angle unit.
  explicit constexpr SolidAngle(const NumericType value)
    : DimensionalScalar<Unit::SolidAngle, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const SolidAngle<NumericType>& left, const SolidAngle<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const SolidAngle<NumericType>& left, const SolidAngle<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const SolidAngle<NumericType>& left, const SolidAngle<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const SolidAngle<NumericType>& left, const SolidAngle<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const SolidAngle<NumericType>& left, const SolidAngle<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const SolidAngle<NumericType>& left, const SolidAngle<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const SolidAngle<NumericType>& solid_angle) {
  stream << solid_angle.Print();
  return stream;
}

template <typename NumericType>
inline constexpr SolidAngle<NumericType> operator*(
    const NumericType number, const SolidAngle<NumericType>& solid_angle) {
  return solid_angle * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::SolidAngle<NumericType>> {
  inline size_t operator()(const PhQ::SolidAngle<NumericType>& solid_angle) const {
    return hash<NumericType>()(solid_angle.Value());
  }
};

}  // namespace std

#endif  // PHQ_SOLID_ANGLE_HPP
