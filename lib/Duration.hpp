#pragma once

#include "Time.hpp"

namespace PhQ {

// Forward declarations.
class Length;
class Speed;
class AccelerationMagnitude;
class Memory;
class MemoryRate;
class Frequency;

class Duration : public DimensionalScalarQuantity<Unit::Time> {

public:

  constexpr Duration() noexcept : DimensionalScalarQuantity<Unit::Time>() {}

  constexpr Duration(double value, Unit::Time unit) noexcept : DimensionalScalarQuantity<Unit::Time>(value, unit) {}

  Frequency frequency() const;

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

  constexpr double operator*(const Frequency& frequency) const noexcept;

protected:

  constexpr Duration(double value) noexcept : DimensionalScalarQuantity<Unit::Time>(value) {}

  friend class Length;

  friend class Time;

  friend class Speed;

  friend class AccelerationMagnitude;

  friend class Displacement;

  friend class Velocity;

  friend class Acceleration;

  friend class Memory;

  friend class MemoryRate;

  friend class Frequency;

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
