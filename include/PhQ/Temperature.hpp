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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_HPP

#include "TemperatureDifference.hpp"
#include "Unit/Temperature.hpp"

namespace PhQ {

class Temperature : public DimensionalScalarQuantity<Unit::Temperature> {
public:
  constexpr Temperature() noexcept
      : DimensionalScalarQuantity<Unit::Temperature>() {}

  Temperature(const double value, const Unit::Temperature unit) noexcept
      : DimensionalScalarQuantity<Unit::Temperature>(value, unit) {}

  inline Temperature operator+(const Temperature& temperature) const noexcept {
    return Temperature{value_ + temperature.value_};
  }

  inline Temperature operator+(
      const TemperatureDifference& temperature_difference) const noexcept {
    return Temperature{value_ + temperature_difference.Value()};
  }

  inline TemperatureDifference operator-(
      const Temperature& temperature) const noexcept {
    return {value_ - temperature.value_};
  }

  inline Temperature operator-(
      const TemperatureDifference& temperature_difference) const noexcept {
    return Temperature{value_ - temperature_difference.Value()};
  }

  inline Temperature operator*(const double number) const noexcept {
    return Temperature{value_ * number};
  }

  inline Temperature operator/(const double number) const noexcept {
    return Temperature{value_ / number};
  }

  inline constexpr void operator+=(const Temperature& temperature) noexcept {
    value_ += temperature.value_;
  }

  inline constexpr void operator+=(
      const TemperatureDifference& temperature_difference) noexcept {
    value_ += temperature_difference.Value();
  }

  inline constexpr void operator-=(const Temperature& temperature) noexcept {
    value_ -= temperature.value_;
  }

  inline constexpr void operator-=(
      const TemperatureDifference& temperature_difference) noexcept {
    value_ -= temperature_difference.Value();
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Temperature(const double value) noexcept
      : DimensionalScalarQuantity<Unit::Temperature>(value) {}

  friend class TemperatureDifference;
};

inline constexpr bool operator==(const Temperature& left,
                                 const Temperature& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Temperature& left,
                                 const Temperature& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Temperature& left,
                                const Temperature& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Temperature& left,
                                const Temperature& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Temperature& left,
                                 const Temperature& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Temperature& left,
                                 const Temperature& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Temperature& temperature) noexcept {
  stream << temperature.Print();
  return stream;
}

inline Temperature operator*(const double number,
                             const Temperature& temperature) noexcept {
  return temperature * number;
}

inline Temperature TemperatureDifference::operator+(
    const Temperature& temperature) const noexcept {
  return Temperature{value_ + temperature.Value()};
}

inline Temperature TemperatureDifference::operator-(
    const Temperature& temperature) const noexcept {
  return Temperature{value_ - temperature.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Temperature> {
  size_t operator()(const PhQ::Temperature& temperature) const {
    return hash<double>()(temperature.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_HPP
