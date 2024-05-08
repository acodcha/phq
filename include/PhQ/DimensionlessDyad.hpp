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

#ifndef PHQ_DIMENSIONLESS_DYAD_HPP
#define PHQ_DIMENSIONLESS_DYAD_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>
#include <string>
#include <type_traits>

#include "Base.hpp"
#include "Dimensions.hpp"
#include "Dyad.hpp"

namespace PhQ {

// Abstract base class that represents any dimensionless dyadic tensor physical quantity. Such a
// physical quantity is composed only of a value where the value is a three-dimensional dyadic
// tensor. The tensor may be non-symmetric. Such a physical quantity has no unit of measure and no
// dimension set.
template <typename Number = double>
class DimensionlessDyad {
  static_assert(
      std::is_floating_point<Number>::value,
      "The Number template parameter of a physical quantity must be a floating-point number type.");

public:
  // Physical dimension set of this physical quantity. Since this physical quantity is
  // dimensionless, its physical dimension set is simply the null set.
  static constexpr PhQ::Dimensions Dimensions() {
    return PhQ::Dimensionless;
  }

  // Value of this physical quantity.
  [[nodiscard]] constexpr const PhQ::Dyad<Number>& Value() const noexcept {
    return value;
  }

  // Returns the value of this physical quantity as a mutable value.
  constexpr PhQ::Dyad<Number>& MutableValue() noexcept {
    return value;
  }

  // Sets the value of this physical quantity to the given value.
  constexpr void SetValue(const PhQ::Dyad<Number>& value) noexcept {
    this->value = value;
  }

  // Prints this physical quantity as a string.
  [[nodiscard]] std::string Print() const {
    return value.Print();
  }

  // Serializes this physical quantity as a JSON message.
  [[nodiscard]] std::string JSON() const {
    return value.JSON();
  }

  // Serializes this physical quantity as an XML message.
  [[nodiscard]] std::string XML() const {
    return value.XML();
  }

  // Serializes this physical quantity as a YAML message.
  [[nodiscard]] std::string YAML() const {
    return value.YAML();
  }

protected:
  // Default constructor. Constructs a dimensionless dyadic tensor physical quantity with an
  // uninitialized value.
  DimensionlessDyad() = default;

  // Constructor. Constructs a dimensionless dyadic tensor physical quantity whose value has the
  // given xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  constexpr DimensionlessDyad(
      const Number xx, const Number xy, const Number xz, const Number yx, const Number yy,
      const Number yz, const Number zx, const Number zy, const Number zz)
    : value(xx, xy, xz, yx, yy, yz, zx, zy, zz) {}

  // Constructor. Constructs a dimensionless dyadic tensor physical quantity from a given array
  // representing its value's xx, xy, xz, yx, yy, yz, zx, zy, and zz Cartesian components.
  explicit constexpr DimensionlessDyad(const std::array<Number, 9>& xx_xy_xz_yx_yy_yz_zx_zy_zz)
    : value(xx_xy_xz_yx_yy_yz_zx_zy_zz) {}

  // Constructor. Constructs a dimensionless dyadic tensor physical quantity with a given value.
  explicit constexpr DimensionlessDyad(const PhQ::Dyad<Number>& value) : value(value) {}

  // Destructor. Destroys this dimensionless dyadic tensor physical quantity.
  ~DimensionlessDyad() noexcept = default;

  // Copy constructor. Constructs a dimensionless dyadic tensor physical quantity by copying another
  // one.
  constexpr DimensionlessDyad(const DimensionlessDyad& other) = default;

  // Copy constructor. Constructs a dimensionless dyadic tensor physical quantity by copying another
  // one.
  template <typename OtherNumber>
  explicit constexpr DimensionlessDyad(const DimensionlessDyad<OtherNumber>& other)
    : value(static_cast<PhQ::Dyad<Number>>(other.Value())) {}

  // Move constructor. Constructs a dimensionless dyadic tensor physical quantity by moving another
  // one.
  constexpr DimensionlessDyad(DimensionlessDyad&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensionless dyadic tensor physical quantity by copying
  // another one.
  constexpr DimensionlessDyad& operator=(const DimensionlessDyad& other) = default;

  // Copy assignment operator. Assigns this dimensionless dyadic tensor physical quantity by copying
  // another one.
  template <typename OtherNumber>
  constexpr DimensionlessDyad& operator=(const DimensionlessDyad<OtherNumber>& other) {
    value = static_cast<PhQ::Dyad<Number>>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this dimensionless dyadic tensor physical quantity by moving
  // another one.
  constexpr DimensionlessDyad& operator=(DimensionlessDyad&& other) noexcept = default;

  // Value of this physical quantity.
  PhQ::Dyad<Number> value;
};

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const PhQ::DimensionlessDyad<Number>& dimensionless_dyad) {
  stream << dimensionless_dyad.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::DimensionlessDyad<Number>> {
  inline size_t operator()(const PhQ::DimensionlessDyad<Number>& dimensionless_dyad) const {
    return hash<PhQ::Dyad<Number>>()(dimensionless_dyad.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIMENSIONLESS_DYAD_HPP
