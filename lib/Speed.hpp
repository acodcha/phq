#pragma once

#include "Frequency.hpp"
#include "Length.hpp"
#include "Unit/Speed.hpp"

namespace PhQ {

// Forward declarations.
class AccelerationMagnitude;
class Velocity;

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

  constexpr Speed operator+(const Speed& speed) const noexcept {
    return {value_ + speed.value_};
  }

  constexpr void operator+=(const Speed& speed) noexcept {
    value_ += speed.value_;
  }

  constexpr Speed operator-(const Speed& speed) const noexcept {
    return {value_ - speed.value_};
  }

  constexpr void operator-=(const Speed& speed) noexcept {
    value_ -= speed.value_;
  }

  constexpr Length operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

  constexpr AccelerationMagnitude operator*(const Frequency& frequency) const noexcept;

  AccelerationMagnitude operator/(const Duration& duration) const;

  Length operator/(const Frequency& frequency) const {
    if (frequency.value_ != 0.0) {
      return {value_ / frequency.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + frequency.print() + "."};
    }
  }

  Frequency operator/(const Length& length) const {
    if (length.value_ != 0.0) {
      return {value_ / length.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + length.print() + "."};
    }
  }

protected:

  constexpr Speed(double value) noexcept : DimensionalScalarQuantity<Unit::Speed>(value) {}

  friend class AccelerationMagnitude;
  friend class Duration;
  friend class Frequency;
  friend class Length;
  friend class Velocity;

};

constexpr Speed Length::operator*(const Frequency& frequency) const noexcept {
  return {value_ * frequency.value_};
}

constexpr Speed Frequency::operator*(const Length& length) const noexcept {
  return {value_ * length.value_};
}

Speed Length::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

} // namespace PhQ
