#pragma once

#include "Angle.hpp"
#include "Frequency.hpp"
#include "Unit/AngularSpeed.hpp"

namespace PhQ {

// Forward declaration.
class AngularAccelerationMagnitude;

class AngularSpeed : public DimensionalScalarQuantity<Unit::AngularSpeed> {

public:

  constexpr AngularSpeed() noexcept : DimensionalScalarQuantity<Unit::AngularSpeed>() {}

  constexpr AngularSpeed(double value, Unit::AngularSpeed unit) noexcept : DimensionalScalarQuantity<Unit::AngularSpeed>(value, unit) {}

  constexpr bool operator==(const AngularSpeed& angular_speed) const noexcept {
    return value_ == angular_speed.value_;
  }

  constexpr bool operator!=(const AngularSpeed& angular_speed) const noexcept {
    return value_ != angular_speed.value_;
  }

  constexpr bool operator<(const AngularSpeed& angular_speed) const noexcept {
    return value_ < angular_speed.value_;
  }

  constexpr bool operator<=(const AngularSpeed& angular_speed) const noexcept {
    return value_ <= angular_speed.value_;
  }

  constexpr bool operator>(const AngularSpeed& angular_speed) const noexcept {
    return value_ > angular_speed.value_;
  }

  constexpr bool operator>=(const AngularSpeed& angular_speed) const noexcept {
    return value_ >= angular_speed.value_;
  }

  constexpr AngularSpeed operator+(const AngularSpeed& angular_speed) const noexcept {
    return {value_ + angular_speed.value_};
  }

  constexpr void operator+=(const AngularSpeed& angular_speed) noexcept {
    value_ += angular_speed.value_;
  }

  constexpr AngularSpeed operator-(const AngularSpeed& angular_speed) const noexcept {
    return {value_ - angular_speed.value_};
  }

  constexpr void operator-=(const AngularSpeed& angular_speed) noexcept {
    value_ -= angular_speed.value_;
  }

  constexpr Angle operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

  constexpr AngularAccelerationMagnitude operator*(const Frequency& frequency) const noexcept;

  AngularAccelerationMagnitude operator/(const Duration& duration) const;

  Angle operator/(const Frequency& frequency) const {
    if (frequency.value_ != 0.0) {
      return {value_ / frequency.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + frequency.print() + "."};
    }
  }

  Frequency operator/(const Angle& angle) const {
    if (angle.value_ != 0.0) {
      return {value_ / angle.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + angle.print() + "."};
    }
  }

protected:

  constexpr AngularSpeed(double value) noexcept : DimensionalScalarQuantity<Unit::AngularSpeed>(value) {}

  friend class Angle;
  friend class AngularAccelerationMagnitude;
  friend class Duration;
  friend class Frequency;

};

constexpr AngularSpeed Angle::operator*(const Frequency& frequency) const noexcept {
  return {value_ * frequency.value_};
}

constexpr AngularSpeed Frequency::operator*(const Angle& angle) const noexcept {
  return {value_ * angle.value_};
}

AngularSpeed Angle::operator/(const Duration& time) const {

}

} // namespace PhQ
