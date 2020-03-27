#pragma once

#include "Speed.hpp"
#include "Unit/Acceleration.hpp"

namespace PhQ {

// Forward declarations.
class Acceleration;

class AccelerationMagnitude : public DimensionalScalarQuantity<Unit::Acceleration> {

public:

  constexpr AccelerationMagnitude() noexcept : DimensionalScalarQuantity<Unit::Acceleration>() {}

  constexpr AccelerationMagnitude(double value, Unit::Acceleration unit) noexcept : DimensionalScalarQuantity<Unit::Acceleration>(value, unit) {}

  constexpr AccelerationMagnitude(const Acceleration& acceleration) noexcept;

  constexpr bool operator==(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ == acceleration_magnitude.value_;
  }

  constexpr bool operator!=(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ != acceleration_magnitude.value_;
  }

  constexpr bool operator<(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ < acceleration_magnitude.value_;
  }

  constexpr bool operator<=(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ <= acceleration_magnitude.value_;
  }

  constexpr bool operator>(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ > acceleration_magnitude.value_;
  }

  constexpr bool operator>=(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ >= acceleration_magnitude.value_;
  }

  AccelerationMagnitude operator+(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return {value_ + acceleration_magnitude.value_};
  }

  constexpr void operator+=(const AccelerationMagnitude& acceleration_magnitude) noexcept {
    value_ += acceleration_magnitude.value_;
  }

  AccelerationMagnitude operator-(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return {value_ - acceleration_magnitude.value_};
  }

  constexpr void operator-=(const AccelerationMagnitude& acceleration_magnitude) noexcept {
    value_ -= acceleration_magnitude.value_;
  }

  Speed operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

protected:

  constexpr AccelerationMagnitude(double value) noexcept : DimensionalScalarQuantity<Unit::Acceleration>(value) {}

  friend class Duration;

  friend class Speed;

  friend class Acceleration;

};

AccelerationMagnitude Speed::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

} // namespace PhQ
