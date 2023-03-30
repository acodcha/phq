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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_POWER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_POWER_HPP

#include "SpecificEnergy.hpp"
#include "Unit/SpecificPower.hpp"

namespace PhQ {

class SpecificPower : public DimensionalScalarQuantity<Unit::SpecificPower> {
public:
  constexpr SpecificPower() noexcept
      : DimensionalScalarQuantity<Unit::SpecificPower>() {}

  SpecificPower(const double value, const Unit::SpecificPower unit) noexcept
      : DimensionalScalarQuantity<Unit::SpecificPower>(value, unit) {}

  constexpr SpecificPower(const SpecificEnergy& specific_energy,
                          const Time& time) noexcept
      : SpecificPower(specific_energy.Value() / time.Value()) {}

  constexpr SpecificPower(const SpecificEnergy& specific_energy,
                          const Frequency& frequency) noexcept
      : SpecificPower(specific_energy.Value() * frequency.Value()) {}

  constexpr SpecificPower(const Power& power, const Mass& mass) noexcept
      : SpecificPower(power.Value() / mass.Value()) {}

  template <Unit::SpecificPower Unit>
  static constexpr SpecificPower Create(const double value) noexcept {
    return SpecificPower{
        StaticConvertCopy<Unit::SpecificPower, Unit,
                          StandardUnit<Unit::SpecificPower>>(value)};
  }

  inline constexpr SpecificPower operator+(
      const SpecificPower& specific_power) const noexcept {
    return SpecificPower{value_ + specific_power.value_};
  }

  inline constexpr SpecificPower operator-(
      const SpecificPower& specific_power) const noexcept {
    return SpecificPower{value_ - specific_power.value_};
  }

  inline constexpr SpecificPower operator*(const double number) const noexcept {
    return SpecificPower{value_ * number};
  }

  inline constexpr SpecificEnergy operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  inline constexpr Power operator*(const Mass& mass) const noexcept {
    return {*this, mass};
  }

  inline constexpr SpecificPower operator/(const double number) const noexcept {
    return SpecificPower{value_ / number};
  }

  inline constexpr SpecificEnergy operator/(
      const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  inline constexpr Frequency operator/(
      const SpecificEnergy& specific_energy) const noexcept {
    return {*this, specific_energy};
  }

  inline constexpr void operator+=(
      const SpecificPower& specific_power) noexcept {
    value_ += specific_power.value_;
  }

  inline constexpr void operator-=(
      const SpecificPower& specific_power) noexcept {
    value_ -= specific_power.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr SpecificPower(const double value) noexcept
      : DimensionalScalarQuantity<Unit::SpecificPower>(value) {}
};

inline constexpr bool operator==(const SpecificPower& left,
                                 const SpecificPower& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const SpecificPower& left,
                                 const SpecificPower& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const SpecificPower& left,
                                const SpecificPower& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const SpecificPower& left,
                                const SpecificPower& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const SpecificPower& left,
                                 const SpecificPower& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const SpecificPower& left,
                                 const SpecificPower& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const SpecificPower& specific_power) noexcept {
  stream << specific_power.Print();
  return stream;
}

inline constexpr SpecificPower operator*(
    const double number, const SpecificPower& specific_power) noexcept {
  return specific_power * number;
}

inline constexpr Time::Time(const SpecificPower& specific_power,
                            const SpecificEnergy& specific_energy) noexcept
    : Time(specific_energy.Value() / specific_power.Value()) {}

inline constexpr Frequency::Frequency(
    const SpecificPower& specific_power,
    const SpecificEnergy& specific_energy) noexcept
    : Frequency(specific_power.Value() / specific_energy.Value()) {}

inline constexpr Mass::Mass(const SpecificPower& specific_power,
                            const Power& power) noexcept
    : Mass(power.Value() / specific_power.Value()) {}

inline constexpr Power::Power(const SpecificPower& specific_power,
                              const Mass& mass) noexcept
    : Power(specific_power.Value() * mass.Value()) {}

inline constexpr SpecificEnergy::SpecificEnergy(
    const SpecificPower& specific_power, const Time& time) noexcept
    : SpecificEnergy(specific_power.Value() * time.Value()) {}

inline constexpr SpecificEnergy::SpecificEnergy(
    const SpecificPower& specific_power, const Frequency& frequency) noexcept
    : SpecificEnergy(specific_power.Value() / frequency.Value()) {}

inline constexpr Power Mass::operator*(
    const SpecificPower& specific_power) const noexcept {
  return {specific_power, *this};
}

inline constexpr Mass Power::operator/(
    const SpecificPower& specific_power) const noexcept {
  return {specific_power, *this};
}

inline constexpr SpecificEnergy Time::operator*(
    const SpecificPower& specific_power) const noexcept {
  return {specific_power, *this};
}

inline constexpr SpecificPower Frequency::operator*(
    const SpecificEnergy& specific_energy) const noexcept {
  return {specific_energy, *this};
}

inline constexpr SpecificPower Power::operator/(
    const Mass& mass) const noexcept {
  return {*this, mass};
}

inline constexpr SpecificPower SpecificEnergy::operator*(
    const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline constexpr SpecificPower SpecificEnergy::operator/(
    const Time& time) const noexcept {
  return {*this, time};
}

inline constexpr Time SpecificEnergy::operator/(
    const SpecificPower& specific_power) const noexcept {
  return {specific_power, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SpecificPower> {
  size_t operator()(const PhQ::SpecificPower& specific_power) const {
    return hash<double>()(specific_power.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_POWER_HPP
