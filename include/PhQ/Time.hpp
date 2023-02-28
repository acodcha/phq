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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TIME_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TIME_HPP

#include "Duration.hpp"

namespace PhQ {

class Time : public DimensionalScalarQuantity<Unit::Time> {
public:
  constexpr Time() noexcept : DimensionalScalarQuantity<Unit::Time>() {}

  Time(const double value, const Unit::Time unit) noexcept
      : DimensionalScalarQuantity<Unit::Time>(value, unit) {}

  inline Time operator+(const Time& time) const noexcept {
    return Time{value_ + time.value_};
  }

  inline Time operator+(const Duration& duration) const noexcept {
    return Time{value_ + duration.Value()};
  }

  inline Duration operator-(const Time& time) const noexcept {
    return Duration{value_ - time.value_};
  }

  inline Time operator-(const Duration& duration) const noexcept {
    return Time{value_ - duration.Value()};
  }

  inline Time operator*(const double number) const noexcept {
    return Time{value_ * number};
  }

  inline Time operator/(const double number) const noexcept {
    return Time{value_ / number};
  }

  inline constexpr void operator+=(const Time& time) noexcept {
    value_ += time.value_;
  }

  inline constexpr void operator+=(const Duration& duration) noexcept {
    value_ += duration.Value();
  }

  inline constexpr void operator-=(const Time& time) noexcept {
    value_ -= time.value_;
  }

  inline constexpr void operator-=(const Duration& duration) noexcept {
    value_ -= duration.Value();
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Time(const double value) noexcept
      : DimensionalScalarQuantity<Unit::Time>(value) {}

  friend class Duration;
};

inline constexpr bool operator==(const Time& left, const Time& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Time& left, const Time& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Time& left, const Time& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Time& left, const Time& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Time& left, const Time& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Time& left, const Time& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Time& time) noexcept {
  stream << time.Print();
  return stream;
}

inline Time operator*(const double number, const Time& time) noexcept {
  return time * number;
}

inline Time Duration::operator+(const Time& time) const noexcept {
  return Time{value_ + time.Value()};
}

inline Time Duration::operator-(const Time& time) const noexcept {
  return Time{value_ - time.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Time> {
  size_t operator()(const PhQ::Time& time) const {
    return hash<double>()(time.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TIME_HPP
