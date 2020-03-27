#pragma once

#include "Time.hpp"

namespace PhQ {

// Forward declarations.
class Length;
class Speed;
class AccelerationMagnitude;

class Duration : public DimensionalScalarQuantity<Unit::Time> {

public:

  constexpr Duration() noexcept : DimensionalScalarQuantity<Unit::Time>() {}

  constexpr Duration(double value, Unit::Time unit) noexcept : DimensionalScalarQuantity<Unit::Time>(value, unit) {}

  constexpr bool operator==(const Duration& duration) const noexcept {
    return value_ == duration.value_;
  }

  constexpr bool operator!=(const Duration& duration) const noexcept {
    return value_ != duration.value_;
  }

  constexpr bool operator<(const Duration& duration) const noexcept {
    return value_ < duration.value_;
  }

  constexpr bool operator<=(const Duration& duration) const noexcept {
    return value_ <= duration.value_;
  }

  constexpr bool operator>(const Duration& duration) const noexcept {
    return value_ > duration.value_;
  }

  constexpr bool operator>=(const Duration& duration) const noexcept {
    return value_ >= duration.value_;
  }

  Time operator+(const Time& time) const noexcept {
    return {value_ + time.value_};
  }

  Duration operator+(const Duration& duration) const noexcept {
    return {value_ + duration.value_};
  }

  constexpr void operator+=(const Time& time) noexcept; // Never defined, because nonsensical.

  constexpr void operator+=(const Duration& duration) noexcept {
    value_ += duration.value_;
  }

  Time operator-(const Time& time) const noexcept {
    return {value_ - time.value_};
  }

  Duration operator-(const Duration& duration) const noexcept {
    return {value_ - duration.value_};
  }

  constexpr void operator-=(const Time& time) noexcept; // Never defined, because nonsensical.

  constexpr void operator-=(const Duration& duration) noexcept {
    value_ -= duration.value_;
  }

protected:

  constexpr Duration(double value) noexcept : DimensionalScalarQuantity<Unit::Time>(value) {}

  friend class Length;

  friend class Time;

  friend class Speed;

  friend class AccelerationMagnitude;

  friend class Displacement;

  friend class Velocity;

  friend class Acceleration;

};

Time Time::operator+(const Duration& duration) const noexcept {
  return {value_ + duration.value_};
}

constexpr void Time::operator+=(const Duration& duration) noexcept {
  value_ += duration.value_;
}

Duration Time::operator-(const Time& time) const noexcept {
  return {value_ - time.value_};
}

Time Time::operator-(const Duration& duration) const noexcept {
  return {value_ - duration.value_};
}

constexpr void Time::operator-=(const Duration& duration) noexcept {
  value_ -= duration.value_;
}

} // namespace PhQ
