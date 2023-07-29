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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_POWER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_POWER_HPP

#include "Energy.hpp"
#include "Frequency.hpp"
#include "Unit/Power.hpp"

namespace PhQ {

// Power. Time rate of change of energy. Can also represent an energy transfer
// rate.
class Power : public DimensionalScalarQuantity<Unit::Power> {
public:
  constexpr Power() noexcept : DimensionalScalarQuantity<Unit::Power>() {}

  Power(const double value, const Unit::Power unit) noexcept
    : DimensionalScalarQuantity<Unit::Power>(value, unit) {}

  constexpr Power(const Energy& energy, const Time& time) noexcept
    : Power(energy.Value() / time.Value()) {}

  constexpr Power(const Energy& energy, const Frequency& frequency) noexcept
    : Power(energy.Value() * frequency.Value()) {}

  constexpr Power(
      const SpecificPower& specific_power, const Mass& mass) noexcept;

  static constexpr Power Zero() noexcept { return Power{0.0}; }

  template<Unit::Power Unit>
  static constexpr Power Create(const double value) noexcept {
    return Power{
        StaticConvertCopy<Unit::Power, Unit, StandardUnit<Unit::Power>>(value)};
  }

  inline constexpr Power operator+(const Power& power) const noexcept {
    return Power{value_ + power.value_};
  }

  inline constexpr Power operator-(const Power& power) const noexcept {
    return Power{value_ - power.value_};
  }

  inline constexpr Power operator*(const double number) const noexcept {
    return Power{value_ * number};
  }

  inline constexpr Energy operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  inline constexpr Power operator/(const double number) const noexcept {
    return Power{value_ / number};
  }

  inline constexpr Energy operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  inline constexpr Frequency operator/(const Energy& energy) const noexcept {
    return {*this, energy};
  }

  inline constexpr SpecificPower operator/(const Mass& mass) const noexcept;

  inline constexpr Mass operator/(
      const SpecificPower& specific_power) const noexcept;

  inline constexpr void operator+=(const Power& power) noexcept {
    value_ += power.value_;
  }

  inline constexpr void operator-=(const Power& power) noexcept {
    value_ -= power.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Power(const double value) noexcept
    : DimensionalScalarQuantity<Unit::Power>(value) {}
};

inline constexpr bool operator==(
    const Power& left, const Power& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Power& left, const Power& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Power& left, const Power& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Power& left, const Power& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Power& left, const Power& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Power& left, const Power& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Power& power) noexcept {
  stream << power.Print();
  return stream;
}

inline constexpr Power operator*(
    const double number, const Power& power) noexcept {
  return power * number;
}

inline constexpr Time::Time(const Power& power, const Energy& energy) noexcept
  : Time(energy.Value() / power.Value()) {}

inline constexpr Frequency::Frequency(
    const Power& power, const Energy& energy) noexcept
  : Frequency(power.Value() / energy.Value()) {}

inline constexpr Energy::Energy(const Power& power, const Time& time) noexcept
  : Energy(power.Value() * time.Value()) {}

inline constexpr Energy::Energy(
    const Power& power, const Frequency& frequency) noexcept
  : Energy(power.Value() / frequency.Value()) {}

inline constexpr Energy Time::operator*(const Power& power) const noexcept {
  return {power, *this};
}

inline constexpr Power Frequency::operator*(
    const Energy& energy) const noexcept {
  return {energy, *this};
}

inline constexpr Power Energy::operator*(
    const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline constexpr Power Energy::operator/(const Time& time) const noexcept {
  return {*this, time};
}

inline constexpr Time Energy::operator/(const Power& power) const noexcept {
  return {power, *this};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::Power> {
  size_t operator()(const PhQ::Power& power) const {
    return hash<double>()(power.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_POWER_HPP
