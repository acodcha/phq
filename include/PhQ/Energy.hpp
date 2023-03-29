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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ENERGY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ENERGY_HPP

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Energy.hpp"

namespace PhQ {

// Forward declarations for class Energy.
class Time;
class Frequency;
class Mass;
class Power;
class SpecificEnergy;
class SpecificPower;

class Energy : public DimensionalScalarQuantity<Unit::Energy> {
public:
  constexpr Energy() noexcept : DimensionalScalarQuantity<Unit::Energy>() {}

  Energy(const double value, const Unit::Energy unit) noexcept
      : DimensionalScalarQuantity<Unit::Energy>(value, unit) {}

  constexpr Energy(const Power& power, const Time& time) noexcept;

  constexpr Energy(const Power& power, const Frequency& frequency) noexcept;

  constexpr Energy(const SpecificEnergy& specific_energy,
                   const Mass& mass) noexcept;

  template <Unit::Energy Unit>
  static constexpr Energy Create(const double value) noexcept {
    return Energy{
        StaticConvertCopy<Unit::Energy, Unit, StandardUnit<Unit::Energy>>(
            value)};
  }

  inline Energy operator+(const Energy& energy) const noexcept {
    return Energy{value_ + energy.value_};
  }

  inline Energy operator-(const Energy& energy) const noexcept {
    return Energy{value_ - energy.value_};
  }

  inline Energy operator*(const double number) const noexcept {
    return Energy{value_ * number};
  }

  inline Power operator*(const Frequency& frequency) const noexcept;

  inline Energy operator/(const double number) const noexcept {
    return Energy{value_ / number};
  }

  inline Power operator/(const Time& time) const noexcept;

  inline Time operator/(const Power& power) const noexcept;

  inline SpecificEnergy operator/(const Mass& mass) const noexcept;

  inline Mass operator/(const SpecificEnergy& specific_energy) const noexcept;

  inline constexpr void operator+=(const Energy& energy) noexcept {
    value_ += energy.value_;
  }

  inline constexpr void operator-=(const Energy& energy) noexcept {
    value_ -= energy.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Energy(const double value) noexcept
      : DimensionalScalarQuantity<Unit::Energy>(value) {}
};

inline constexpr bool operator==(const Energy& left,
                                 const Energy& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Energy& left,
                                 const Energy& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Energy& left,
                                const Energy& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Energy& left,
                                const Energy& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Energy& left,
                                 const Energy& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Energy& left,
                                 const Energy& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Energy& energy) noexcept {
  stream << energy.Print();
  return stream;
}

inline Energy operator*(const double number, const Energy& energy) noexcept {
  return energy * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Energy> {
  size_t operator()(const PhQ::Energy& energy) const {
    return hash<double>()(energy.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ENERGY_HPP
