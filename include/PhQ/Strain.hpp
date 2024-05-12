// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

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
template <typename Number>
class DisplacementGradient;

// Forward declaration for class PhQ::Strain.
template <typename Number>
class Time;

// Forward declaration for class PhQ::Strain.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::Strain.
template <typename Number>
class StrainRate;

// Forward declaration for class PhQ::Strain.
template <typename Number>
class TemperatureDifference;

// Forward declaration for class PhQ::Strain.
template <typename Number>
class VolumetricThermalExpansionCoefficient;

// Strain symmetric dyadic tensor. See also PhQ::ScalarStrain.
template <typename Number = double>
class Strain : public DimensionlessSymmetricDyad<Number> {
public:
  // Default constructor. Constructs a strain tensor with an uninitialized value.
  Strain() = default;

  // Constructor. Constructs a strain tensor whose value has the given xx, xy, xz, yy, yz, and zz
  // Cartesian components.
  constexpr Strain(const Number xx, const Number xy, const Number xz, const Number yy,
                   const Number yz, const Number zz)
    : DimensionlessSymmetricDyad<Number>(xx, xy, xz, yy, yz, zz) {}

  // Constructor. Constructs a strain tensor from a given array representing its value's xx, xy, xz,
  // yy, yz, and zz Cartesian components.
  explicit constexpr Strain(const std::array<Number, 6>& xx_xy_xz_yy_yz_zz)
    : DimensionlessSymmetricDyad<Number>(xx_xy_xz_yy_yz_zz) {}

  // Constructor. Constructs a strain tensor with a given value.
  explicit constexpr Strain(const SymmetricDyad<Number>& value)
    : DimensionlessSymmetricDyad<Number>(value) {}

  // Constructor. Constructs a strain tensor from a given strain rate tensor and time using the
  // definition of the strain rate tensor.
  constexpr Strain(const StrainRate<Number>& strain_rate, const Time<Number>& time);

  // Constructor. Constructs a strain tensor from a given strain rate tensor and frequency using the
  // definition of the strain rate tensor.
  constexpr Strain(const StrainRate<Number>& strain_rate, const Frequency<Number>& frequency);

  // Constructor. Constructs a strain tensor from a given displacement gradient using the definition
  // of the strain tensor.
  explicit constexpr Strain(const DisplacementGradient<Number>& displacement_gradient);

  // Constructor. Constructs a strain tensor from a given volumetric thermal expansion coefficient
  // and temperature difference using the definition of the volumetric thermal expansion
  // coefficient.
  constexpr Strain(
      const VolumetricThermalExpansionCoefficient<Number>& volumetric_thermal_expansion_coefficient,
      const TemperatureDifference<Number>& temperature_difference);

  // Destructor. Destroys this strain tensor.
  ~Strain() noexcept = default;

  // Copy constructor. Constructs a strain tensor by copying another one.
  constexpr Strain(const Strain<Number>& other) = default;

  // Copy constructor. Constructs a strain tensor by copying another one.
  template <typename OtherNumber>
  explicit constexpr Strain(const Strain<OtherNumber>& other)
    : Strain(static_cast<SymmetricDyad<Number>>(other.Value())) {}

  // Move constructor. Constructs a strain tensor by moving another one.
  constexpr Strain(Strain<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this strain tensor by copying another one.
  constexpr Strain<Number>& operator=(const Strain<Number>& other) = default;

  // Copy assignment operator. Assigns this strain tensor by copying another one.
  template <typename OtherNumber>
  constexpr Strain<Number>& operator=(const Strain<OtherNumber>& other) {
    this->value = static_cast<SymmetricDyad<Number>>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this strain tensor by moving another one.
  constexpr Strain<Number>& operator=(Strain<Number>&& other) noexcept = default;

  // Statically creates a strain tensor of zero.
  static constexpr Strain<Number> Zero() {
    return Strain<Number>{SymmetricDyad<Number>::Zero()};
  }

  // Returns the xx Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<Number> xx() const noexcept {
    return ScalarStrain<Number>{this->value.xx()};
  }

  // Returns the xy = yx Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<Number> xy() const noexcept {
    return ScalarStrain<Number>{this->value.xy()};
  }

  // Returns the xz = zx Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<Number> xz() const noexcept {
    return ScalarStrain<Number>{this->value.xz()};
  }

  // Returns the yx = xy Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<Number> yx() const noexcept {
    return ScalarStrain<Number>{this->value.yx()};
  }

  // Returns the yy Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<Number> yy() const noexcept {
    return ScalarStrain<Number>{this->value.yy()};
  }

  // Returns the yz = zy Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<Number> yz() const noexcept {
    return ScalarStrain<Number>{this->value.yz()};
  }

  // Returns the zx = xz Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<Number> zx() const noexcept {
    return ScalarStrain<Number>{this->value.zx()};
  }

  // Returns the zy = yz Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<Number> zy() const noexcept {
    return ScalarStrain<Number>{this->value.zy()};
  }

  // Returns the zz Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain<Number> zz() const noexcept {
    return ScalarStrain<Number>{this->value.zz()};
  }

  constexpr Strain<Number> operator+(const Strain<Number>& strain) const {
    return Strain<Number>{this->value + strain.value};
  }

  constexpr Strain<Number> operator-(const Strain<Number>& strain) const {
    return Strain<Number>{this->value - strain.value};
  }

  constexpr Strain<Number> operator*(const Number number) const {
    return Strain<Number>{this->value * number};
  }

  constexpr StrainRate<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Strain<Number> operator/(const Number number) const {
    return Strain<Number>{this->value / number};
  }

  constexpr StrainRate<Number> operator/(const Time<Number>& time) const;

  constexpr void operator+=(const Strain<Number>& strain) noexcept {
    this->value += strain.value;
  }

  constexpr void operator-=(const Strain<Number>& strain) noexcept {
    this->value -= strain.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }
};

template <typename Number>
inline constexpr bool operator==(const Strain<Number>& left, const Strain<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Strain<Number>& left, const Strain<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Strain<Number>& left, const Strain<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Strain<Number>& left, const Strain<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Strain<Number>& left, const Strain<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Strain<Number>& left, const Strain<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Strain<Number>& strain) {
  stream << strain.Print();
  return stream;
}

template <typename Number>
inline constexpr Strain<Number> operator*(const Number number, const Strain<Number>& strain) {
  return strain * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Strain<Number>> {
  inline size_t operator()(const PhQ::Strain<Number>& strain) const {
    return hash<PhQ::SymmetricDyad<Number>>()(strain.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRAIN_HPP
