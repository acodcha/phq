// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#ifndef PHQ_STRAIN_HPP
#define PHQ_STRAIN_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessSymmetricDyad.hpp"
#include "ScalarStrain.hpp"
#include "SymmetricDyad.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Strain.
template <typename NumericType>
class DisplacementGradient;

// Forward declaration for class PhQ::Strain.
template <typename NumericType>
class Time;

// Forward declaration for class PhQ::Strain.
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::Strain.
template <typename NumericType>
class StrainRate;

// Forward declaration for class PhQ::Strain.
template <typename NumericType>
class TemperatureDifference;

// Forward declaration for class PhQ::Strain.
template <typename NumericType>
class VolumetricThermalExpansionCoefficient;

/// \brief Three-dimensional Euclidean strain symmetric dyadic tensor. Contains six components in
/// Cartesian coordinates: xx, xy = yx, xz = zx, yy, yz = zy, and zz. For the scalar components or
/// resultants of a strain tensor, see PhQ::ScalarStrain. For the time rate of change of strain, see
/// PhQ::StrainRate, PhQ::Time, and PhQ::Frequency.
template <typename NumericType = double>
class Strain : public DimensionlessSymmetricDyad<NumericType> {
public:
  /// \brief Default constructor. Constructs a strain tensor with an uninitialized value.
  Strain() = default;

  /// \brief Constructor. Constructs a strain tensor whose value has the given xx, xy, xz, yy, yz,
  /// and zz Cartesian components.
  constexpr Strain(const NumericType xx, const NumericType xy, const NumericType xz,
                   const NumericType yy, const NumericType yz, const NumericType zz)
    : DimensionlessSymmetricDyad<NumericType>(xx, xy, xz, yy, yz, zz) {}

  /// \brief Constructor. Constructs a strain tensor from a given array representing its value's xx,
  /// xy, xz, yy, yz, and zz Cartesian components.
  explicit constexpr Strain(const std::array<NumericType, 6>& xx_xy_xz_yy_yz_zz)
    : DimensionlessSymmetricDyad<NumericType>(xx_xy_xz_yy_yz_zz) {}

  /// \brief Constructor. Constructs a strain tensor with a given value.
  explicit constexpr Strain(const SymmetricDyad<NumericType>& value)
    : DimensionlessSymmetricDyad<NumericType>(value) {}

  /// \brief Constructor. Constructs a strain tensor from a given strain rate tensor and time using
  /// the definition of the strain rate tensor.
  constexpr Strain(const StrainRate<NumericType>& strain_rate, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a strain tensor from a given strain rate tensor and frequency
  /// using the definition of the strain rate tensor.
  constexpr Strain(
      const StrainRate<NumericType>& strain_rate, const Frequency<NumericType>& frequency);

  /// \brief Constructor. Constructs a strain tensor from a given displacement gradient using the
  /// definition of the strain tensor.
  explicit constexpr Strain(const DisplacementGradient<NumericType>& displacement_gradient);

  /// \brief Constructor. Constructs a strain tensor from a given volumetric thermal expansion
  /// coefficient and temperature difference using the definition of the volumetric thermal
  /// expansion coefficient.
  constexpr Strain(const VolumetricThermalExpansionCoefficient<NumericType>&
                       volumetric_thermal_expansion_coefficient,
                   const TemperatureDifference<NumericType>& temperature_difference);

  /// \brief Destructor. Destroys this strain tensor.
  ~Strain() noexcept = default;

  /// \brief Copy constructor. Constructs a strain tensor by copying another one.
  constexpr Strain(const Strain<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a strain tensor by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Strain(const Strain<OtherNumericType>& other)
    : Strain(static_cast<SymmetricDyad<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a strain tensor by moving another one.
  constexpr Strain(Strain<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this strain tensor by copying another one.
  constexpr Strain<NumericType>& operator=(const Strain<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this strain tensor by copying another one.
  template <typename OtherNumericType>
  constexpr Strain<NumericType>& operator=(const Strain<OtherNumericType>& other) {
    this->value = static_cast<SymmetricDyad<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this strain tensor by moving another one.
  constexpr Strain<NumericType>& operator=(Strain<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a strain tensor of zero.
  static constexpr Strain<NumericType> Zero() {
    return Strain<NumericType>{SymmetricDyad<NumericType>::Zero()};
  }

  /// \brief Returns the xx Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<NumericType> xx() const noexcept {
    return ScalarStrain<NumericType>{this->value.xx()};
  }

  /// \brief Returns the xy = yx Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<NumericType> xy() const noexcept {
    return ScalarStrain<NumericType>{this->value.xy()};
  }

  /// \brief Returns the xz = zx Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<NumericType> xz() const noexcept {
    return ScalarStrain<NumericType>{this->value.xz()};
  }

  /// \brief Returns the yx = xy Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<NumericType> yx() const noexcept {
    return ScalarStrain<NumericType>{this->value.yx()};
  }

  /// \brief Returns the yy Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<NumericType> yy() const noexcept {
    return ScalarStrain<NumericType>{this->value.yy()};
  }

  /// \brief Returns the yz = zy Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<NumericType> yz() const noexcept {
    return ScalarStrain<NumericType>{this->value.yz()};
  }

  /// \brief Returns the zx = xz Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<NumericType> zx() const noexcept {
    return ScalarStrain<NumericType>{this->value.zx()};
  }

  /// \brief Returns the zy = yz Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<NumericType> zy() const noexcept {
    return ScalarStrain<NumericType>{this->value.zy()};
  }

  /// \brief Returns the zz Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<NumericType> zz() const noexcept {
    return ScalarStrain<NumericType>{this->value.zz()};
  }

  constexpr Strain<NumericType> operator+(const Strain<NumericType>& strain) const {
    return Strain<NumericType>{this->value + strain.value};
  }

  constexpr Strain<NumericType> operator-(const Strain<NumericType>& strain) const {
    return Strain<NumericType>{this->value - strain.value};
  }

  constexpr Strain<NumericType> operator*(const NumericType number) const {
    return Strain<NumericType>{this->value * number};
  }

  constexpr StrainRate<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr Strain<NumericType> operator/(const NumericType number) const {
    return Strain<NumericType>{this->value / number};
  }

  constexpr StrainRate<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr void operator+=(const Strain<NumericType>& strain) noexcept {
    this->value += strain.value;
  }

  constexpr void operator-=(const Strain<NumericType>& strain) noexcept {
    this->value -= strain.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }
};

template <typename NumericType>
inline constexpr bool operator==(
    const Strain<NumericType>& left, const Strain<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Strain<NumericType>& left, const Strain<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Strain<NumericType>& left, const Strain<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Strain<NumericType>& left, const Strain<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Strain<NumericType>& left, const Strain<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Strain<NumericType>& left, const Strain<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Strain<NumericType>& strain) {
  stream << strain.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Strain<NumericType> operator*(
    const NumericType number, const Strain<NumericType>& strain) {
  return strain * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Strain<NumericType>> {
  inline size_t operator()(const PhQ::Strain<NumericType>& strain) const {
    return hash<PhQ::SymmetricDyad<NumericType>>()(strain.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRAIN_HPP
