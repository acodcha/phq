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

#ifndef PHQ_STRAIN_RATE_HPP
#define PHQ_STRAIN_RATE_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalSymmetricDyad.hpp"
#include "Frequency.hpp"
#include "ScalarStrainRate.hpp"
#include "Strain.hpp"
#include "SymmetricDyad.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Forward declaration for class PhQ::StrainRate.
template <typename NumericType>
class VelocityGradient;

/// \brief Three-dimensional Euclidean strain rate symmetric dyadic tensor. Time rate of change of
/// strain. Contains six components in Cartesian coordinates: xx, xy = yx, xz = zx, yy, yz = zy, and
/// zz. For the scalar components or resultants of a strain rate tensor, see PhQ::ScalarStrainRate.
/// See also PhQ::Strain, PhQ::Time, and PhQ::Frequency.
template <typename NumericType = double>
class StrainRate : public DimensionalSymmetricDyad<Unit::Frequency, NumericType> {
public:
  /// \brief Default constructor. Constructs a strain rate tensor with an uninitialized value.
  StrainRate() = default;

  /// \brief Constructor. Constructs a strain rate tensor with a given value expressed in a given
  /// frequency unit.
  StrainRate(const SymmetricDyad<NumericType>& value, Unit::Frequency unit)
    : DimensionalSymmetricDyad<Unit::Frequency, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a strain rate tensor from a given set of scalar strain rate
  /// components.
  StrainRate(const ScalarStrainRate<NumericType>& xx, const ScalarStrainRate<NumericType>& xy,
             const ScalarStrainRate<NumericType>& xz, const ScalarStrainRate<NumericType>& yy,
             const ScalarStrainRate<NumericType>& yz, const ScalarStrainRate<NumericType>& zz)
    : StrainRate<NumericType>(
        {xx.Value(), xy.Value(), xz.Value(), yy.Value(), yz.Value(), zz.Value()}) {}

  /// \brief Constructor. Constructs a strain rate tensor from a given strain tensor and time using
  /// the definition of the strain rate tensor.
  constexpr StrainRate(const Strain<NumericType>& strain, const Time<NumericType>& time)
    : StrainRate<NumericType>(strain.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a strain rate tensor from a given strain tensor and frequency
  /// using the definition of the strain rate tensor.
  constexpr StrainRate(const Strain<NumericType>& strain, const Frequency<NumericType>& frequency)
    : StrainRate<NumericType>(strain.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs a strain rate tensor from a given velocity gradient using the
  /// definition of the strain rate tensor.
  explicit constexpr StrainRate(const VelocityGradient<NumericType>& velocity_gradient);

  /// \brief Destructor. Destroys this strain rate tensor.
  ~StrainRate() noexcept = default;

  /// \brief Copy constructor. Constructs a strain rate tensor by copying another one.
  constexpr StrainRate(const StrainRate<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a strain rate tensor by copying another one.
  template <typename OtherNumericType>
  explicit constexpr StrainRate(const StrainRate<OtherNumericType>& other)
    : StrainRate(static_cast<SymmetricDyad<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a strain rate tensor by moving another one.
  constexpr StrainRate(StrainRate<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this strain rate tensor by copying another one.
  constexpr StrainRate<NumericType>& operator=(const StrainRate<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this strain rate tensor by copying another one.
  template <typename OtherNumericType>
  constexpr StrainRate<NumericType>& operator=(const StrainRate<OtherNumericType>& other) {
    this->value = static_cast<SymmetricDyad<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this strain rate tensor by moving another one.
  constexpr StrainRate<NumericType>& operator=(StrainRate<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a strain rate tensor of zero.
  [[nodiscard]] static constexpr StrainRate<NumericType> Zero() {
    return StrainRate<NumericType>{SymmetricDyad<NumericType>::Zero()};
  }

  /// \brief Statically creates a strain rate tensor from the given xx, xy, xz, yy, yz, and zz
  /// Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  [[nodiscard]] static constexpr StrainRate<NumericType> Create(
      const NumericType xx, const NumericType xy, const NumericType xz, const NumericType yy,
      const NumericType yz, const NumericType zz) {
    return StrainRate<NumericType>{
        ConvertStatically<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            SymmetricDyad<NumericType>{xx, xy, xz, yy, yz, zz})};
  }

  /// \brief Statically creates a strain rate tensor from the given xx, xy, xz, yy, yz, and zz
  /// Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  [[nodiscard]] static constexpr StrainRate<NumericType> Create(
      const std::array<NumericType, 6>& xx_xy_xz_yy_yz_zz) {
    return StrainRate<NumericType>{
        ConvertStatically<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
            SymmetricDyad<NumericType>{xx_xy_xz_yy_yz_zz})};
  }

  /// \brief Statically creates a strain rate tensor with a given value expressed in a given
  /// frequency unit.
  template <Unit::Frequency Unit>
  [[nodiscard]] static constexpr StrainRate<NumericType> Create(
      const SymmetricDyad<NumericType>& value) {
    return StrainRate<NumericType>{
        ConvertStatically<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  /// \brief Returns the xx Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<NumericType> xx() const noexcept {
    return ScalarStrainRate<NumericType>{this->value.xx()};
  }

  /// \brief Returns the xy = yx Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<NumericType> xy() const noexcept {
    return ScalarStrainRate<NumericType>{this->value.xy()};
  }

  /// \brief Returns the xz = zx Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<NumericType> xz() const noexcept {
    return ScalarStrainRate<NumericType>{this->value.xz()};
  }

  /// \brief Returns the yx = xy Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<NumericType> yx() const noexcept {
    return ScalarStrainRate<NumericType>{this->value.yx()};
  }

  /// \brief Returns the yy Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<NumericType> yy() const noexcept {
    return ScalarStrainRate<NumericType>{this->value.yy()};
  }

  /// \brief Returns the yz = zy Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<NumericType> yz() const noexcept {
    return ScalarStrainRate<NumericType>{this->value.yz()};
  }

  /// \brief Returns the zx = xz Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<NumericType> zx() const noexcept {
    return ScalarStrainRate<NumericType>{this->value.zx()};
  }

  /// \brief Returns the zy = yz Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<NumericType> zy() const noexcept {
    return ScalarStrainRate<NumericType>{this->value.zy()};
  }

  /// \brief Returns the zz Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<NumericType> zz() const noexcept {
    return ScalarStrainRate<NumericType>{this->value.zz()};
  }

  constexpr StrainRate operator+(const StrainRate<NumericType>& strain_rate) const {
    return StrainRate<NumericType>{this->value + strain_rate.value};
  }

  constexpr StrainRate<NumericType> operator-(const StrainRate<NumericType>& strain_rate) const {
    return StrainRate<NumericType>{this->value - strain_rate.value};
  }

  constexpr StrainRate<NumericType> operator*(const NumericType number) const {
    return StrainRate<NumericType>{this->value * number};
  }

  constexpr Strain<NumericType> operator*(const Time<NumericType>& time) const {
    return Strain<NumericType>{*this, time};
  }

  constexpr StrainRate<NumericType> operator/(const NumericType number) const {
    return StrainRate<NumericType>{this->value / number};
  }

  constexpr Strain<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return Strain<NumericType>{*this, frequency};
  }

  constexpr void operator+=(const StrainRate<NumericType>& strain_rate) noexcept {
    this->value += strain_rate.value;
  }

  constexpr void operator-=(const StrainRate<NumericType>& strain_rate) noexcept {
    this->value -= strain_rate.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a strain rate tensor with a given value expressed in the
  /// standard frequency unit.
  explicit constexpr StrainRate(const SymmetricDyad<NumericType>& value)
    : DimensionalSymmetricDyad<Unit::Frequency, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const StrainRate<NumericType>& left, const StrainRate<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const StrainRate<NumericType>& left, const StrainRate<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const StrainRate<NumericType>& left, const StrainRate<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const StrainRate<NumericType>& left, const StrainRate<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const StrainRate<NumericType>& left, const StrainRate<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const StrainRate<NumericType>& left, const StrainRate<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const StrainRate<NumericType>& strain_rate) {
  stream << strain_rate.Print();
  return stream;
}

template <typename NumericType>
inline constexpr StrainRate<NumericType> operator*(
    const NumericType number, const StrainRate<NumericType>& strain_rate) {
  return strain_rate * number;
}

template <typename NumericType>
inline constexpr Strain<NumericType>::Strain(
    const StrainRate<NumericType>& strain_rate, const Time<NumericType>& time)
  : Strain<NumericType>(strain_rate.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr Strain<NumericType>::Strain(
    const StrainRate<NumericType>& strain_rate, const Frequency<NumericType>& frequency)
  : Strain<NumericType>(strain_rate.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr StrainRate<NumericType> Strain<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return StrainRate<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr StrainRate<NumericType> Strain<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return StrainRate<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr Strain<NumericType> Time<NumericType>::operator*(
    const StrainRate<NumericType>& strain_rate) const {
  return Strain<NumericType>{strain_rate, *this};
}

template <typename NumericType>
inline constexpr StrainRate<NumericType> Frequency<NumericType>::operator*(
    const Strain<NumericType>& strain) const {
  return StrainRate<NumericType>{strain, *this};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::StrainRate<NumericType>> {
  inline size_t operator()(const PhQ::StrainRate<NumericType>& strain_rate) const {
    return hash<PhQ::SymmetricDyad<NumericType>>()(strain_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRAIN_RATE_HPP
