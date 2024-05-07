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

#ifndef PHQ_ISENTROPIC_BULK_MODULUS_HPP
#define PHQ_ISENTROPIC_BULK_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declarations for class IsentropicBulkModulus.
class MassDensity;
class SoundSpeed;

// Isentropic bulk modulus. Not to be confused with the isothermal bulk modulus.
class IsentropicBulkModulus : public DimensionalScalar<Unit::Pressure, double> {
public:
  // Default constructor. Constructs an isentropic bulk modulus with an uninitialized value.
  IsentropicBulkModulus() = default;

  // Constructor. Constructs an isentropic bulk modulus with a given value expressed in a given
  // pressure unit.
  IsentropicBulkModulus(const double value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure>(value, unit) {}

  // Constructor. Constructs an isentropic bulk modulus from a given mass density and sound speed
  // using the definition of the isentropic bulk modulus.
  constexpr IsentropicBulkModulus(const MassDensity& mass_density, const SoundSpeed& sound_speed);

  // Destructor. Destroys this isentropic bulk modulus.
  ~IsentropicBulkModulus() noexcept = default;

  // Copy constructor. Constructs an isentropic bulk modulus by copying another one.
  constexpr IsentropicBulkModulus(const IsentropicBulkModulus& other) = default;

  // Move constructor. Constructs an isentropic bulk modulus by moving another one.
  constexpr IsentropicBulkModulus(IsentropicBulkModulus&& other) noexcept = default;

  // Copy assignment operator. Assigns this isentropic bulk modulus by copying another one.
  constexpr IsentropicBulkModulus& operator=(const IsentropicBulkModulus& other) = default;

  // Move assignment operator. Assigns this isentropic bulk modulus by moving another one.
  constexpr IsentropicBulkModulus& operator=(IsentropicBulkModulus&& other) noexcept = default;

  // Statically creates an isentropic bulk modulus of zero.
  static constexpr IsentropicBulkModulus Zero() {
    return IsentropicBulkModulus{0.0};
  }

  // Statically creates an isentropic bulk modulus with a given value expressed in a given pressure
  // unit.
  template <Unit::Pressure Unit>
  static constexpr IsentropicBulkModulus Create(const double value) {
    return IsentropicBulkModulus{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr IsentropicBulkModulus operator+(
      const IsentropicBulkModulus& isentropic_bulk_modulus) const {
    return IsentropicBulkModulus{value + isentropic_bulk_modulus.value};
  }

  constexpr IsentropicBulkModulus operator-(
      const IsentropicBulkModulus& isentropic_bulk_modulus) const {
    return IsentropicBulkModulus{value - isentropic_bulk_modulus.value};
  }

  constexpr IsentropicBulkModulus operator*(const double number) const {
    return IsentropicBulkModulus{value * number};
  }

  constexpr IsentropicBulkModulus operator/(const double number) const {
    return IsentropicBulkModulus{value / number};
  }

  constexpr double operator/(const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return value / isentropic_bulk_modulus.value;
  }

  constexpr void operator+=(const IsentropicBulkModulus& isentropic_bulk_modulus) noexcept {
    value += isentropic_bulk_modulus.value;
  }

  constexpr void operator-=(const IsentropicBulkModulus& isentropic_bulk_modulus) noexcept {
    value -= isentropic_bulk_modulus.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs an isentropic bulk modulus with a given value expressed in the standard
  // pressure unit.
  explicit constexpr IsentropicBulkModulus(const double value)
    : DimensionalScalar<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(
    const IsentropicBulkModulus& left, const IsentropicBulkModulus& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const IsentropicBulkModulus& left, const IsentropicBulkModulus& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const IsentropicBulkModulus& left, const IsentropicBulkModulus& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const IsentropicBulkModulus& left, const IsentropicBulkModulus& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const IsentropicBulkModulus& left, const IsentropicBulkModulus& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const IsentropicBulkModulus& left, const IsentropicBulkModulus& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const IsentropicBulkModulus& isentropic_bulk_modulus) {
  stream << isentropic_bulk_modulus.Print();
  return stream;
}

inline constexpr IsentropicBulkModulus operator*(
    const double number, const IsentropicBulkModulus& isentropic_bulk_modulus) {
  return isentropic_bulk_modulus * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::IsentropicBulkModulus> {
  inline size_t operator()(const PhQ::IsentropicBulkModulus& isentropic_bulk_modulus) const {
    return hash<double>()(isentropic_bulk_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_ISENTROPIC_BULK_MODULUS_HPP
