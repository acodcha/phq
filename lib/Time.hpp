#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Time.hpp"

namespace PhQ {

// Forward declaration.
class Duration;

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

  Time operator+(const Time& time) const noexcept {
    return {value_ + time.value_};
  }

  Time operator+(const Duration& duration) const noexcept;

  constexpr void operator+=(const Time& time) noexcept {
    value_ += time.value_;
  }

  constexpr void operator+=(const Duration& duration) noexcept;

  Duration operator-(const Time& time) const noexcept;

  Time operator-(const Duration& duration) const noexcept;

  constexpr void operator-=(const Time& time) noexcept {
    value_ -= time.value_;
  }

  constexpr void operator-=(const Duration& duration) noexcept;

protected:

  constexpr Time(double value) noexcept : DimensionalScalarQuantity<Unit::Time>(value) {}

  friend class Duration;

};

} // namespace PhQ
