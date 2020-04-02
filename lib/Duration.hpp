#pragma once

#include "Time.hpp"

namespace PhQ {

// Forward declarations.
class AccelerationMagnitude;
class Angle;
class AngularAccelerationMagnitude;
class AngularSpeed;
class Frequency;
class Length;
class Memory;
class MemoryRate;
class Speed;

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

  friend class Acceleration;
  friend class AccelerationMagnitude;
  friend class Angle;
  friend class AngularAccelerationMagnitude;
  friend class AngularSpeed;
  friend class Displacement;
  friend class Frequency;
  friend class Length;
  friend class Memory;
  friend class MemoryRate;
  friend class Speed;
  friend class Time;
  friend class Velocity;

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
