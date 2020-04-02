#pragma once

#include "Duration.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Forward declarations.
class Acceleration;
class AccelerationMagnitude;
class Angle;
class AngularAccelerationMagnitude;
class AngularSpeed;
class Displacement;
class Length;
class Memory;
class MemoryRate;
class Speed;
class Velocity;

class Frequency : public DimensionalScalarQuantity<Unit::Frequency> {

public:

  constexpr Frequency() noexcept : DimensionalScalarQuantity<Unit::Frequency>() {}

  constexpr Frequency(double value, Unit::Frequency unit) noexcept : DimensionalScalarQuantity<Unit::Frequency>(value, unit) {}

  Duration period() const {
    if (value_ != 0.0) {
      return {1.0 / value_};
    } else {
      throw std::runtime_error{"Inversion of " + print() + "."};
    }
  }

  constexpr bool operator==(const Frequency& frequency) const noexcept {
    return value_ == frequency.value_;
  }

  constexpr bool operator!=(const Frequency& frequency) const noexcept {
    return value_ != frequency.value_;
  }

  constexpr bool operator<(const Frequency& frequency) const noexcept {
    return value_ < frequency.value_;
  }

  constexpr bool operator<=(const Frequency& frequency) const noexcept {
    return value_ <= frequency.value_;
  }

  constexpr bool operator>(const Frequency& frequency) const noexcept {
    return value_ > frequency.value_;
  }

  constexpr bool operator>=(const Frequency& frequency) const noexcept {
    return value_ >= frequency.value_;
  }

  constexpr Frequency operator+(const Frequency& frequency) const noexcept {
    return {value_ + frequency.value_};
  }

  constexpr void operator+=(const Frequency& frequency) noexcept {
    value_ += frequency.value_;
  }

  constexpr Frequency operator-(const Frequency& frequency) const noexcept {
    return {value_ - frequency.value_};
  }

  constexpr void operator-=(const Frequency& frequency) noexcept {
    value_ -= frequency.value_;
  }

  constexpr double operator*(const Duration& duration) const noexcept {
    return value_ * duration.value_;
  }

  constexpr Speed operator*(const Length& length) const noexcept;

  constexpr AngularSpeed operator*(const Angle& angle) const noexcept;

  constexpr Velocity operator*(const Displacement& displacement) const noexcept;

  constexpr MemoryRate operator*(const Memory& memory) const noexcept;

  constexpr AccelerationMagnitude operator*(const Speed& speed) const noexcept;

  constexpr AngularAccelerationMagnitude operator*(const AngularSpeed& angular_speed) const noexcept;

protected:

  constexpr Frequency(double value) noexcept : DimensionalScalarQuantity<Unit::Frequency>(value) {}

  friend class Acceleration;
  friend class AccelerationMagnitude;
  friend class Angle;
  friend class AngularAccelerationMagnitude;
  friend class AngularSpeed;
  friend class Displacement;
  friend class Duration;
  friend class Length;
  friend class Memory;
  friend class MemoryRate;
  friend class Speed;
  friend class Velocity;

};

Frequency Duration::frequency() const {
  if (value_ != 0.0) {
    return {1.0 / value_};
  } else {
    throw std::runtime_error{"Inversion of " + print() + "."};
  }
}

constexpr double Duration::operator*(const Frequency& frequency) const noexcept {
  return value_ * frequency.value_;
}

} // namespace PhQ
