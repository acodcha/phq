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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ENERGY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ENERGY_HPP

#include "Mass.hpp"
#include "Power.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

// Forward declaration for class SpecificEnergy.
class SpecificPower;

// Specific energy. Energy per unit mass.
class SpecificEnergy : public DimensionalScalarQuantity<Unit::SpecificEnergy> {
public:
  constexpr SpecificEnergy()
    : DimensionalScalarQuantity<Unit::SpecificEnergy>() {}

  SpecificEnergy(const double value, const Unit::SpecificEnergy unit)
    : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr SpecificEnergy(const Energy& energy, const Mass& mass)
    : SpecificEnergy(energy.Value() / mass.Value()) {}

  constexpr SpecificEnergy(
      const SpecificPower& specific_power, const Time& time);

  constexpr SpecificEnergy(
      const SpecificPower& specific_power, const Frequency& frequency);

  static constexpr SpecificEnergy Zero() {
    return SpecificEnergy{0.0};
  }

  template <Unit::SpecificEnergy Unit>
  static constexpr SpecificEnergy Create(const double value) {
    return SpecificEnergy{
        StaticConvertCopy<Unit::SpecificEnergy, Unit,
                          Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr SpecificEnergy operator+(
      const SpecificEnergy& specific_energy) const {
    return SpecificEnergy{value_ + specific_energy.value_};
  }

  constexpr SpecificEnergy operator-(
      const SpecificEnergy& specific_energy) const {
    return SpecificEnergy{value_ - specific_energy.value_};
  }

  constexpr SpecificEnergy operator*(const double number) const {
    return SpecificEnergy{value_ * number};
  }

  constexpr Energy operator*(const Mass& mass) const {
    return {*this, mass};
  }

  constexpr SpecificPower operator*(const Frequency& frequency) const;

  constexpr SpecificEnergy operator/(const double number) const {
    return SpecificEnergy{value_ / number};
  }

  constexpr SpecificPower operator/(const Time& time) const;

  constexpr Time operator/(const SpecificPower& specific_power) const;

  constexpr double operator/(
      const SpecificEnergy& specific_energy) const noexcept {
    return value_ / specific_energy.value_;
  }

  constexpr void operator+=(const SpecificEnergy& specific_energy) noexcept {
    value_ += specific_energy.value_;
  }

  constexpr void operator-=(const SpecificEnergy& specific_energy) noexcept {
    value_ -= specific_energy.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr SpecificEnergy(const double value)
    : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}
};

inline constexpr bool operator==(
    const SpecificEnergy& left, const SpecificEnergy& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const SpecificEnergy& left, const SpecificEnergy& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const SpecificEnergy& left, const SpecificEnergy& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const SpecificEnergy& left, const SpecificEnergy& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const SpecificEnergy& left, const SpecificEnergy& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const SpecificEnergy& left, const SpecificEnergy& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const SpecificEnergy& specific_energy) {
  stream << specific_energy.Print();
  return stream;
}

inline constexpr SpecificEnergy operator*(
    const double number, const SpecificEnergy& specific_energy) {
  return specific_energy * number;
}

inline constexpr Mass::Mass(
    const SpecificEnergy& specific_energy, const Energy& energy)
  : Mass(energy.Value() / specific_energy.Value()) {}

inline constexpr Energy::Energy(
    const SpecificEnergy& specific_energy, const Mass& mass)
  : Energy(specific_energy.Value() * mass.Value()) {}

inline constexpr Energy Mass::operator*(
    const SpecificEnergy& specific_energy) const {
  return {specific_energy, *this};
}

inline constexpr Mass Energy::operator/(
    const SpecificEnergy& specific_energy) const {
  return {specific_energy, *this};
}

inline constexpr SpecificEnergy Energy::operator/(const Mass& mass) const {
  return {*this, mass};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SpecificEnergy> {
  inline size_t operator()(const PhQ::SpecificEnergy& specific_energy) const {
    return hash<double>()(specific_energy.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ENERGY_HPP
