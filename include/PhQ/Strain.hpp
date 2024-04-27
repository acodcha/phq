// Copyright 2020-2023 Alexandre Coderre-Chabot
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

// Forward declarations for class Strain.
class DisplacementGradient;
class Time;
class Frequency;
class StrainRate;

// Strain symmetric dyadic tensor. See also PhQ::ScalarStrain.
class Strain : public DimensionlessSymmetricDyad {
public:
  // Default constructor. Constructs a strain tensor with an uninitialized value.
  Strain() = default;

  // Constructor. Constructs a strain tensor whose value has the given xx, xy, xz, yy, yz, and zz
  // Cartesian components.
  constexpr Strain(const double xx, const double xy, const double xz, const double yy,
                   const double yz, const double zz)
    : DimensionlessSymmetricDyad(xx, xy, xz, yy, yz, zz) {}

  // Constructor. Constructs a strain tensor from a given array representing its value's xx, xy, xz,
  // yy, yz, and zz Cartesian components.
  explicit constexpr Strain(const std::array<double, 6>& xx_xy_xz_yy_yz_zz)
    : DimensionlessSymmetricDyad(xx_xy_xz_yy_yz_zz) {}

  // Constructor. Constructs a strain tensor with a given value.
  explicit constexpr Strain(const SymmetricDyad& value) : DimensionlessSymmetricDyad(value) {}

  // Constructor. Constructs a strain tensor from a given strain rate tensor and time using the
  // definition of the strain rate tensor.
  constexpr Strain(const StrainRate& strain_rate, const Time& time);

  // Constructor. Constructs a strain tensor from a given strain rate tensor and frequency using the
  // definition of the strain rate tensor.
  constexpr Strain(const StrainRate& strain_rate, const Frequency& frequency);

  // Constructor. Constructs a strain tensor from a given displacement gradient using the definition
  // of the strain tensor.
  explicit constexpr Strain(const DisplacementGradient& displacement_gradient);

  // Destructor. Destroys this strain tensor.
  ~Strain() noexcept = default;

  // Copy constructor. Constructs a strain tensor by copying another one.
  constexpr Strain(const Strain& other) = default;

  // Move constructor. Constructs a strain tensor by moving another one.
  constexpr Strain(Strain&& other) noexcept = default;

  // Copy assignment operator. Assigns this strain tensor by copying another one.
  constexpr Strain& operator=(const Strain& other) = default;

  // Move assignment operator. Assigns this strain tensor by moving another one.
  constexpr Strain& operator=(Strain&& other) noexcept = default;

  // Statically creates a strain tensor of zero.
  static constexpr Strain Zero() {
    return Strain{SymmetricDyad::Zero()};
  }

  // Returns the xx Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain xx() const noexcept {
    return ScalarStrain{value.xx()};
  }

  // Returns the xy = yx Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain xy() const noexcept {
    return ScalarStrain{value.xy()};
  }

  // Returns the xz = zx Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain xz() const noexcept {
    return ScalarStrain{value.xz()};
  }

  // Returns the yx = xy Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain yx() const noexcept {
    return ScalarStrain{value.yx()};
  }

  // Returns the yy Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain yy() const noexcept {
    return ScalarStrain{value.yy()};
  }

  // Returns the yz = zy Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain yz() const noexcept {
    return ScalarStrain{value.yz()};
  }

  // Returns the zx = xz Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain zx() const noexcept {
    return ScalarStrain{value.zx()};
  }

  // Returns the zy = yz Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain zy() const noexcept {
    return ScalarStrain{value.zy()};
  }

  // Returns the zz Cartesian component of this strain tensor.
  [[nodiscard]] constexpr ScalarStrain zz() const noexcept {
    return ScalarStrain{value.zz()};
  }

  constexpr Strain operator+(const Strain& strain) const {
    return Strain{value + strain.value};
  }

  constexpr Strain operator-(const Strain& strain) const {
    return Strain{value - strain.value};
  }

  constexpr Strain operator*(const double number) const {
    return Strain{value * number};
  }

  constexpr StrainRate operator*(const Frequency& frequency) const;

  constexpr Strain operator/(const double number) const {
    return Strain{value / number};
  }

  constexpr StrainRate operator/(const Time& time) const;

  constexpr void operator+=(const Strain& strain) noexcept {
    value += strain.value;
  }

  constexpr void operator-=(const Strain& strain) noexcept {
    value -= strain.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }
};

inline constexpr bool operator==(const Strain& left, const Strain& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Strain& left, const Strain& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Strain& left, const Strain& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Strain& left, const Strain& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Strain& left, const Strain& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Strain& left, const Strain& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Strain& strain) {
  stream << strain.Print();
  return stream;
}

inline constexpr Strain operator*(const double number, const Strain& strain) {
  return strain * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Strain> {
  inline size_t operator()(const PhQ::Strain& strain) const {
    return hash<PhQ::SymmetricDyad>()(strain.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRAIN_HPP
