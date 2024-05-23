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
template <typename Number>
class VelocityGradient;

/// \brief Strain rate symmetric dyadic tensor. Time rate of change of the strain symmetric dyadic
/// tensor. See also PhQ::Strain and PhQ::ScalarStrainRate.
template <typename Number = double>
class StrainRate : public DimensionalSymmetricDyad<Unit::Frequency, Number> {
public:
  /// \brief Default constructor. Constructs a strain rate tensor with an uninitialized value.
  StrainRate() = default;

  /// \brief Constructor. Constructs a strain rate tensor with a given value expressed in a given
  /// frequency unit.
  StrainRate(const SymmetricDyad<Number>& value, Unit::Frequency unit)
    : DimensionalSymmetricDyad<Unit::Frequency, Number>(value, unit) {}

  /// \brief Constructor. Constructs a strain rate tensor from a given strain tensor and time using
  /// the definition of the strain rate tensor.
  constexpr StrainRate(const Strain<Number>& strain, const Time<Number>& time)
    : StrainRate<Number>(strain.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a strain rate tensor from a given strain tensor and frequency
  /// using the definition of the strain rate tensor.
  constexpr StrainRate(const Strain<Number>& strain, const Frequency<Number>& frequency)
    : StrainRate<Number>(strain.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs a strain rate tensor from a given velocity gradient using the
  /// definition of the strain rate tensor.
  explicit constexpr StrainRate(const VelocityGradient<Number>& velocity_gradient);

  /// \brief Destructor. Destroys this strain rate tensor.
  ~StrainRate() noexcept = default;

  /// \brief Copy constructor. Constructs a strain rate tensor by copying another one.
  constexpr StrainRate(const StrainRate<Number>& other) = default;

  /// \brief Copy constructor. Constructs a strain rate tensor by copying another one.
  template <typename OtherNumber>
  explicit constexpr StrainRate(const StrainRate<OtherNumber>& other)
    : StrainRate(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a strain rate tensor by moving another one.
  constexpr StrainRate(StrainRate<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this strain rate tensor by copying another one.
  constexpr StrainRate<Number>& operator=(const StrainRate<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this strain rate tensor by copying another one.
  template <typename OtherNumber>
  constexpr StrainRate<Number>& operator=(const StrainRate<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this strain rate tensor by moving another one.
  constexpr StrainRate<Number>& operator=(StrainRate<Number>&& other) noexcept = default;

  /// \brief Statically creates a strain rate tensor of zero.
  static constexpr StrainRate<Number> Zero() {
    return StrainRate<Number>{SymmetricDyad<Number>::Zero()};
  }

  /// \brief Statically creates a strain rate tensor from the given xx, xy, xz, yy, yz, and zz
  /// Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr StrainRate<Number> Create(const Number xx, const Number xy, const Number xz,
                                             const Number yy, const Number yz, const Number zz) {
    return StrainRate<Number>{StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
        SymmetricDyad<Number>{xx, xy, xz, yy, yz, zz})};
  }

  /// \brief Statically creates a strain rate tensor from the given xx, xy, xz, yy, yz, and zz
  /// Cartesian components expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr StrainRate<Number> Create(const std::array<Number, 6>& xx_xy_xz_yy_yz_zz) {
    return StrainRate<Number>{StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(
        SymmetricDyad<Number>{xx_xy_xz_yy_yz_zz})};
  }

  /// \brief Statically creates a strain rate tensor with a given value expressed in a given
  /// frequency unit.
  template <Unit::Frequency Unit>
  static constexpr StrainRate<Number> Create(const SymmetricDyad<Number>& value) {
    return StrainRate<Number>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  /// \brief Returns the xx Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> xx() const noexcept {
    return ScalarStrainRate<Number>{this->value.xx()};
  }

  /// \brief Returns the xy = yx Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> xy() const noexcept {
    return ScalarStrainRate<Number>{this->value.xy()};
  }

  /// \brief Returns the xz = zx Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> xz() const noexcept {
    return ScalarStrainRate<Number>{this->value.xz()};
  }

  /// \brief Returns the yx = xy Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> yx() const noexcept {
    return ScalarStrainRate<Number>{this->value.yx()};
  }

  /// \brief Returns the yy Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> yy() const noexcept {
    return ScalarStrainRate<Number>{this->value.yy()};
  }

  /// \brief Returns the yz = zy Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> yz() const noexcept {
    return ScalarStrainRate<Number>{this->value.yz()};
  }

  /// \brief Returns the zx = xz Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> zx() const noexcept {
    return ScalarStrainRate<Number>{this->value.zx()};
  }

  /// \brief Returns the zy = yz Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> zy() const noexcept {
    return ScalarStrainRate<Number>{this->value.zy()};
  }

  /// \brief Returns the zz Cartesian component of this strain rate tensor.
  [[nodiscard]] constexpr ScalarStrainRate<Number> zz() const noexcept {
    return ScalarStrainRate<Number>{this->value.zz()};
  }

  constexpr StrainRate operator+(const StrainRate<Number>& strain_rate) const {
    return StrainRate<Number>{this->value + strain_rate.value};
  }

  constexpr StrainRate<Number> operator-(const StrainRate<Number>& strain_rate) const {
    return StrainRate<Number>{this->value - strain_rate.value};
  }

  constexpr StrainRate<Number> operator*(const Number number) const {
    return StrainRate<Number>{this->value * number};
  }

  constexpr Strain<Number> operator*(const Time<Number>& time) const {
    return Strain<Number>{*this, time};
  }

  constexpr StrainRate<Number> operator/(const Number number) const {
    return StrainRate<Number>{this->value / number};
  }

  constexpr Strain<Number> operator/(const Frequency<Number>& frequency) const {
    return Strain<Number>{*this, frequency};
  }

  constexpr void operator+=(const StrainRate<Number>& strain_rate) noexcept {
    this->value += strain_rate.value;
  }

  constexpr void operator-=(const StrainRate<Number>& strain_rate) noexcept {
    this->value -= strain_rate.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a strain rate tensor with a given value expressed in the
  /// standard frequency unit.
  explicit constexpr StrainRate(const SymmetricDyad<Number>& value)
    : DimensionalSymmetricDyad<Unit::Frequency, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const StrainRate<Number>& left, const StrainRate<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const StrainRate<Number>& strain_rate) {
  stream << strain_rate.Print();
  return stream;
}

template <typename Number>
inline constexpr StrainRate<Number> operator*(
    const Number number, const StrainRate<Number>& strain_rate) {
  return strain_rate * number;
}

template <typename Number>
inline constexpr Strain<Number>::Strain(
    const StrainRate<Number>& strain_rate, const Time<Number>& time)
  : Strain<Number>(strain_rate.Value() * time.Value()) {}

template <typename Number>
inline constexpr Strain<Number>::Strain(
    const StrainRate<Number>& strain_rate, const Frequency<Number>& frequency)
  : Strain<Number>(strain_rate.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr StrainRate<Number> Strain<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return StrainRate<Number>{*this, frequency};
}

template <typename Number>
inline constexpr StrainRate<Number> Strain<Number>::operator/(const Time<Number>& time) const {
  return StrainRate<Number>{*this, time};
}

template <typename Number>
inline constexpr Strain<Number> Time<Number>::operator*(
    const StrainRate<Number>& strain_rate) const {
  return Strain<Number>{strain_rate, *this};
}

template <typename Number>
inline constexpr StrainRate<Number> Frequency<Number>::operator*(
    const Strain<Number>& strain) const {
  return StrainRate<Number>{strain, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::StrainRate<Number>> {
  inline size_t operator()(const PhQ::StrainRate<Number>& strain_rate) const {
    return hash<PhQ::SymmetricDyad<Number>>()(strain_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRAIN_RATE_HPP
