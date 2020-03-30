#pragma once

#include "Displacement.hpp"
#include "Duration.hpp"
#include "Speed.hpp"

namespace PhQ {

// Forward declaration.
class Acceleration;

class Velocity : public DimensionalVectorQuantity<Unit::Speed> {

public:

  constexpr Velocity() noexcept : DimensionalVectorQuantity<Unit::Speed>() {}

  constexpr Velocity(const DimensionalVectorQuantity<Unit::Speed>& quantity) noexcept : DimensionalVectorQuantity<Unit::Speed>(quantity) {}

  constexpr Velocity(const Value::Vector& value, Unit::Speed unit) noexcept : DimensionalVectorQuantity<Unit::Speed>(value, unit) {}

  constexpr Speed magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Velocity& velocity) const noexcept {
    return value_.angle(velocity.value_);
  }

  constexpr bool operator==(const Velocity& velocity) const noexcept {
    return value_ == velocity.value_;
  }

  constexpr bool operator!=(const Velocity& velocity) const noexcept {
    return value_ != velocity.value_;
  }

  constexpr Velocity operator+(const Velocity& velocity) const noexcept {
    return {value_ + velocity.value_};
  }

  constexpr void operator+=(const Velocity& velocity) noexcept {
    value_ += velocity.value_;
  }

  constexpr Velocity operator-(const Velocity& velocity) const noexcept {
    return {value_ - velocity.value_};
  }

  constexpr void operator-=(const Velocity& velocity) noexcept {
    value_ -= velocity.value_;
  }

  constexpr Displacement operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

  Acceleration operator/(const Duration& duration) const;

protected:

  constexpr Velocity(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Speed>(value) {}

  friend class Duration;

  friend class Speed;

  friend class Displacement;

  friend class Acceleration;

};

constexpr Angle::Angle(const Velocity& velocity1, const Velocity& velocity2) noexcept : DimensionalScalarQuantity<Unit::Angle>(velocity1.angle(velocity2)) {}

constexpr Speed::Speed(const Velocity& velocity) noexcept : Speed(velocity.magnitude()) {}

Velocity Displacement::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

} // namespace PhQ
