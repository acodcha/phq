// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Duration.hpp"

namespace PhQ {

class Time : public DimensionalScalarQuantity<Unit::Time> {

public:

  constexpr Time() noexcept : DimensionalScalarQuantity<Unit::Time>() {}

  constexpr Time(double value, Unit::Time unit) noexcept : DimensionalScalarQuantity<Unit::Time>(value, unit) {}

  constexpr bool operator==(const Time& time) const noexcept {
    return value_ == time.value_;
  }

  constexpr bool operator!=(const Time& time) const noexcept {
    return value_ != time.value_;
  }

  constexpr bool operator<(const Time& time) const noexcept {
    return value_ < time.value_;
  }

  constexpr bool operator<=(const Time& time) const noexcept {
    return value_ <= time.value_;
  }

  constexpr bool operator>(const Time& time) const noexcept {
    return value_ > time.value_;
  }

  constexpr bool operator>=(const Time& time) const noexcept {
    return value_ >= time.value_;
  }

  constexpr Time operator+(const Time& time) const noexcept {
    return {value_ + time.value_};
  }

  constexpr Time operator+(const Duration& duration) const noexcept {
    return {value_ + duration.value_};
  }

  constexpr void operator+=(const Time& time) noexcept {
    value_ += time.value_;
  }

  constexpr void operator+=(const Duration& duration) noexcept {
    value_ += duration.value_;
  }

  constexpr Duration operator-(const Time& time) const noexcept {
    return {value_ - time.value_};
  }

  constexpr Time operator-(const Duration& duration) const noexcept {
    return {value_ - duration.value_};
  }

  constexpr void operator-=(const Time& time) noexcept {
    value_ -= time.value_;
  }

  constexpr void operator-=(const Duration& duration) noexcept {
    value_ -= duration.value_;
  }

protected:

  constexpr Time(double value) noexcept : DimensionalScalarQuantity<Unit::Time>(value) {}

  friend class Duration;

};

template <> constexpr bool sort(const Time& time_1, const Time& time_2) noexcept {
  return time_1.value() < time_2.value();
}

constexpr Time Duration::operator+(const Time& time) const noexcept {
  return {value_ + time.value_};
}

constexpr Time Duration::operator-(const Time& time) const noexcept {
  return {value_ - time.value_};
}

} // namespace PhQ
