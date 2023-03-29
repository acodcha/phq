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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_MASS_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_MASS_RATE_HPP

#include "Frequency.hpp"
#include "Mass.hpp"
#include "Unit/MassRate.hpp"

namespace PhQ {

class MassRate : public DimensionalScalarQuantity<Unit::MassRate> {
public:
  constexpr MassRate() noexcept : DimensionalScalarQuantity<Unit::MassRate>() {}

  MassRate(const double value, const Unit::MassRate unit) noexcept
      : DimensionalScalarQuantity<Unit::MassRate>(value, unit) {}

  constexpr MassRate(const Mass& mass, const Time& time) noexcept
      : MassRate(mass.Value() / time.Value()) {}

  constexpr MassRate(const Mass& mass, const Frequency& frequency) noexcept
      : MassRate(mass.Value() * frequency.Value()) {}

  template <Unit::MassRate Unit>
  static constexpr MassRate Create(const double value) noexcept {
    return MassRate{
        StaticConvertCopy<Unit::MassRate, Unit, StandardUnit<Unit::MassRate>>(
            value)};
  }

  inline MassRate operator+(const MassRate& mass_rate) const noexcept {
    return MassRate{value_ + mass_rate.value_};
  }

  inline MassRate operator-(const MassRate& mass_rate) const noexcept {
    return MassRate{value_ - mass_rate.value_};
  }

  inline MassRate operator*(const double number) const noexcept {
    return MassRate{value_ * number};
  }

  inline Mass operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  inline MassRate operator/(const double number) const noexcept {
    return MassRate{value_ / number};
  }

  inline Frequency operator/(const Mass& mass) const noexcept {
    return {*this, mass};
  }

  inline Mass operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  inline constexpr void operator+=(const MassRate& mass_rate) noexcept {
    value_ += mass_rate.value_;
  }

  inline constexpr void operator-=(const MassRate& mass_rate) noexcept {
    value_ -= mass_rate.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr MassRate(const double value) noexcept
      : DimensionalScalarQuantity<Unit::MassRate>(value) {}
};

inline constexpr bool operator==(const MassRate& left,
                                 const MassRate& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const MassRate& left,
                                 const MassRate& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const MassRate& left,
                                const MassRate& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const MassRate& left,
                                const MassRate& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const MassRate& left,
                                 const MassRate& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const MassRate& left,
                                 const MassRate& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const MassRate& mass_rate) noexcept {
  stream << mass_rate.Print();
  return stream;
}

inline MassRate operator*(const double number,
                          const MassRate& mass_rate) noexcept {
  return mass_rate * number;
}

inline constexpr Time::Time(const MassRate& mass_rate,
                            const Mass& mass) noexcept
    : Time(mass.Value() / mass_rate.Value()) {}

inline constexpr Frequency::Frequency(const MassRate& mass_rate,
                                      const Mass& mass) noexcept
    : Frequency(mass_rate.Value() / mass.Value()) {}

inline constexpr Mass::Mass(const MassRate& mass_rate,
                            const Time& time) noexcept
    : Mass(mass_rate.Value() * time.Value()) {}

inline constexpr Mass::Mass(const MassRate& mass_rate,
                            const Frequency& frequency) noexcept
    : Mass(mass_rate.Value() / frequency.Value()) {}

inline Mass Time::operator*(const MassRate& mass_rate) const noexcept {
  return {mass_rate, *this};
}

inline MassRate Mass::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

inline MassRate Frequency::operator*(const Mass& mass) const noexcept {
  return {mass, *this};
}

inline MassRate Mass::operator/(const Time& time) const noexcept {
  return {*this, time};
}

inline Time Mass::operator/(const MassRate& mass_rate) const noexcept {
  return {mass_rate, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::MassRate> {
  size_t operator()(const PhQ::MassRate& mass_rate) const {
    return hash<double>()(mass_rate.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_MASS_RATE_HPP
