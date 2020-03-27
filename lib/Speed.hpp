#pragma once

#include "Duration.hpp"
#include "Length.hpp"
#include "Unit/Speed.hpp"

namespace PhQ {

// Forward declarations.
class Velocity;
class AccelerationMagnitude;

class Speed : public DimensionalScalarQuantity<Unit::Speed> {

public:

  constexpr Speed() noexcept : DimensionalScalarQuantity<Unit::Speed>() {}

  constexpr Speed(double value, Unit::Speed unit) noexcept : DimensionalScalarQuantity<Unit::Speed>(value, unit) {}

  constexpr Speed(const Velocity& velocity) noexcept;

  constexpr bool operator==(const Speed& speed) const noexcept {
    return value_ == speed.value_;
  }

  constexpr bool operator!=(const Speed& speed) const noexcept {
    return value_ != speed.value_;
  }

  constexpr bool operator<(const Speed& speed) const noexcept {
    return value_ < speed.value_;
  }

  constexpr bool operator<=(const Speed& speed) const noexcept {
    return value_ <= speed.value_;
  }

  constexpr bool operator>(const Speed& speed) const noexcept {
    return value_ > speed.value_;
  }

  constexpr bool operator>=(const Speed& speed) const noexcept {
    return value_ >= speed.value_;
  }

  Speed operator+(const Speed& speed) const noexcept {
    return {value_ + speed.value_};
  }

  constexpr void operator+=(const Speed& speed) noexcept {
    value_ += speed.value_;
  }

  Speed operator-(const Speed& speed) const noexcept {
    return {value_ - speed.value_};
  }

  constexpr void operator-=(const Speed& speed) noexcept {
    value_ -= speed.value_;
  }

  Length operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

  AccelerationMagnitude operator/(const Duration& duration) const;

protected:

  constexpr Speed(double value) noexcept : DimensionalScalarQuantity<Unit::Speed>(value) {}

  friend class Length;

  friend class Duration;

  friend class Velocity;

  friend class AccelerationMagnitude;

};

Speed Length::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

} // namespace PhQ
