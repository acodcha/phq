#pragma once

#include "Duration.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Forward declarations.
class Memory;
class MemoryRate;
class Length;
class Speed;
class AccelerationMagnitude;
class Displacement;
class Velocity;
class Acceleration;

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

  constexpr Velocity operator*(const Displacement& displacement) const noexcept;

  constexpr MemoryRate operator*(const Memory& memory) const noexcept;

  constexpr AccelerationMagnitude operator*(const Speed& speed) const noexcept;

protected:

  constexpr Frequency(double value) noexcept : DimensionalScalarQuantity<Unit::Frequency>(value) {}

  friend class Duration;

  friend class Length;

  friend class Speed;

  friend class AccelerationMagnitude;

  friend class Memory;

  friend class MemoryRate;

  friend class Displacement;

  friend class Velocity;

  friend class Acceleration;

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
