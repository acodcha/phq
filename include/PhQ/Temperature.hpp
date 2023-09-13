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

// Temperature.
class Temperature : public DimensionalScalarQuantity<Unit::Temperature> {
public:
  constexpr Temperature() noexcept
    : DimensionalScalarQuantity<Unit::Temperature>() {}

  Temperature(const double value, const Unit::Temperature unit) noexcept
    : DimensionalScalarQuantity<Unit::Temperature>(value, unit) {}

  static constexpr Temperature Zero() noexcept {
    return Temperature{0.0};
  }

  template <Unit::Temperature Unit>
  static constexpr Temperature Create(const double value) noexcept {
    return Temperature{
        StaticConvertCopy<Unit::Temperature, Unit, Standard<Unit::Temperature>>(
            value)};
  }

  constexpr Temperature operator+(
      const Temperature& temperature) const noexcept {
    return Temperature{value_ + temperature.value_};
  }

  constexpr Temperature operator+(
      const TemperatureDifference& temperature_difference) const noexcept {
    return Temperature{value_ + temperature_difference.Value()};
  }

  constexpr TemperatureDifference operator-(
      const Temperature& temperature) const noexcept {
    return TemperatureDifference{value_ - temperature.value_};
  }

  constexpr Temperature operator-(
      const TemperatureDifference& temperature_difference) const noexcept {
    return Temperature{value_ - temperature_difference.Value()};
  }

  constexpr Temperature operator*(const double number) const noexcept {
    return Temperature{value_ * number};
  }

  constexpr Temperature operator/(const double number) const noexcept {
    return Temperature{value_ / number};
  }

  constexpr double operator/(const Temperature& temperature) const noexcept {
    return value_ / temperature.value_;
  }

  constexpr void operator+=(const Temperature& temperature) noexcept {
    value_ += temperature.value_;
  }

  constexpr void operator+=(
      const TemperatureDifference& temperature_difference) noexcept {
    value_ += temperature_difference.Value();
  }

  constexpr void operator-=(const Temperature& temperature) noexcept {
    value_ -= temperature.value_;
  }

  constexpr void operator-=(
      const TemperatureDifference& temperature_difference) noexcept {
    value_ -= temperature_difference.Value();
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Temperature(const double value) noexcept
    : DimensionalScalarQuantity<Unit::Temperature>(value) {}

  friend class TemperatureDifference;
};

inline constexpr bool operator==(
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Temperature& temperature) noexcept {
  stream << temperature.Print();
  return stream;
}

inline constexpr Temperature operator*(
    const double number, const Temperature& temperature) noexcept {
  return temperature * number;
}

inline constexpr Temperature TemperatureDifference::operator+(
    const Temperature& temperature) const noexcept {
  return Temperature{value_ + temperature.Value()};
}

inline constexpr Temperature TemperatureDifference::operator-(
    const Temperature& temperature) const noexcept {
  return Temperature{value_ - temperature.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Temperature> {
  inline size_t operator()(const PhQ::Temperature& temperature) const {
    return hash<double>()(temperature.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_HPP
