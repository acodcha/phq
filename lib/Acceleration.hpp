#pragma once

#include "AccelerationMagnitude.hpp"
#include "Velocity.hpp"

namespace PhQ {

class Acceleration : public DimensionalVectorQuantity<Unit::Acceleration> {

public:

  constexpr Acceleration() noexcept : DimensionalVectorQuantity<Unit::Acceleration>() {}

  constexpr Acceleration(const DimensionalVectorQuantity<Unit::Acceleration>& quantity) noexcept : DimensionalVectorQuantity<Unit::Acceleration>(quantity) {}

  constexpr Acceleration(const Value::Vector& value, Unit::Acceleration unit) noexcept : DimensionalVectorQuantity<Unit::Acceleration>(value, unit) {}

  constexpr AccelerationMagnitude magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Acceleration& acceleration) const noexcept {
    return value_.angle(acceleration.value_);
  }

  constexpr bool operator==(const Acceleration& acceleration) const noexcept {
    return value_ == acceleration.value_;
  }

  constexpr bool operator!=(const Acceleration& acceleration) const noexcept {
    return value_ != acceleration.value_;
  }

  constexpr Acceleration operator+(const Acceleration& acceleration) const noexcept {
    return {value_ + acceleration.value_};
  }

  constexpr void operator+=(const Acceleration& acceleration) noexcept {
    value_ += acceleration.value_;
  }

  constexpr Acceleration operator-(const Acceleration& acceleration) const noexcept {
    return {value_ - acceleration.value_};
  }

  constexpr void operator-=(const Acceleration& acceleration) noexcept {
    value_ -= acceleration.value_;
  }

  constexpr Velocity operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

protected:

  constexpr Acceleration(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Acceleration>(value) {}

  friend class Duration;

  friend class AccelerationMagnitude;

  friend class Velocity;

};

constexpr Angle::Angle(const Acceleration& acceleration1, const Acceleration& acceleration2) noexcept : DimensionalScalarQuantity<Unit::Angle>(acceleration1.angle(acceleration2)) {}

constexpr AccelerationMagnitude::AccelerationMagnitude(const Acceleration& acceleration) noexcept : AccelerationMagnitude(acceleration.magnitude()) {}

Acceleration Velocity::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

} // namespace PhQ
