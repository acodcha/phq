// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISENTROPIC_BULK_MODULUS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISENTROPIC_BULK_MODULUS_HPP

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declarations for class IsentropicBulkModulus.
class MassDensity;
class SoundSpeed;

// Isentropic bulk modulus. Not to be confused with the isothermal bulk modulus.
class IsentropicBulkModulus : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  constexpr IsentropicBulkModulus() noexcept
    : DimensionalScalarQuantity<Unit::Pressure>() {}

  IsentropicBulkModulus(const double value, const Unit::Pressure unit) noexcept
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr IsentropicBulkModulus(
      const MassDensity& mass_density, const SoundSpeed& sound_speed) noexcept;

  static constexpr IsentropicBulkModulus Zero() noexcept {
    return IsentropicBulkModulus{0.0};
  }

  template<Unit::Pressure Unit>
  static constexpr IsentropicBulkModulus Create(const double value) noexcept {
    return IsentropicBulkModulus{
        StaticConvertCopy<Unit::Pressure, Unit, StandardUnit<Unit::Pressure>>(
            value)};
  }

  inline constexpr IsentropicBulkModulus operator+(
      const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return IsentropicBulkModulus{value_ + isentropic_bulk_modulus.value_};
  }

  inline constexpr IsentropicBulkModulus operator-(
      const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return IsentropicBulkModulus{value_ - isentropic_bulk_modulus.value_};
  }

  inline constexpr IsentropicBulkModulus operator*(
      const double number) const noexcept {
    return IsentropicBulkModulus{value_ * number};
  }

  inline constexpr IsentropicBulkModulus operator/(
      const double number) const noexcept {
    return IsentropicBulkModulus{value_ / number};
  }

  inline constexpr double operator/(
      const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return value_ / isentropic_bulk_modulus.value_;
  }

  inline constexpr void operator+=(
      const IsentropicBulkModulus& isentropic_bulk_modulus) noexcept {
    value_ += isentropic_bulk_modulus.value_;
  }

  inline constexpr void operator-=(
      const IsentropicBulkModulus& isentropic_bulk_modulus) noexcept {
    value_ -= isentropic_bulk_modulus.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr IsentropicBulkModulus(const double value) noexcept
    : DimensionalScalarQuantity<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(const IsentropicBulkModulus& left,
                                 const IsentropicBulkModulus& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const IsentropicBulkModulus& left,
                                 const IsentropicBulkModulus& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const IsentropicBulkModulus& left,
                                const IsentropicBulkModulus& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const IsentropicBulkModulus& left,
                                const IsentropicBulkModulus& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const IsentropicBulkModulus& left,
                                 const IsentropicBulkModulus& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const IsentropicBulkModulus& left,
                                 const IsentropicBulkModulus& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const IsentropicBulkModulus& isentropic_bulk_modulus) noexcept {
  stream << isentropic_bulk_modulus.Print();
  return stream;
}

inline constexpr IsentropicBulkModulus operator*(
    const double number,
    const IsentropicBulkModulus& isentropic_bulk_modulus) noexcept {
  return isentropic_bulk_modulus * number;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::IsentropicBulkModulus> {
  size_t operator()(
      const PhQ::IsentropicBulkModulus& isentropic_bulk_modulus) const {
    return hash<double>()(isentropic_bulk_modulus.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISENTROPIC_BULK_MODULUS_HPP
