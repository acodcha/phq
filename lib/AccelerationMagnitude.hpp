#pragma once

#include "Speed.hpp"
#include "Unit/Acceleration.hpp"

namespace PhQ {

// Forward declarations.
class Acceleration;

class AccelerationMagnitude : public DimensionalScalarQuantity<Unit::Acceleration> {

public:

  constexpr AccelerationMagnitude() noexcept : DimensionalScalarQuantity<Unit::Acceleration>() {}

  constexpr AccelerationMagnitude(const DimensionalScalarQuantity<Unit::Acceleration>& quantity) noexcept : DimensionalScalarQuantity<Unit::Acceleration>(quantity) {}

  constexpr AccelerationMagnitude(double value, Unit::Acceleration unit) noexcept : DimensionalScalarQuantity<Unit::Acceleration>(value, unit) {}

  constexpr AccelerationMagnitude(const Acceleration& acceleration) noexcept;

  Speed operator*(const Time& time) const noexcept {
    return {value_ * time.value_};
  }

protected:

  constexpr AccelerationMagnitude(double value) noexcept : DimensionalScalarQuantity<Unit::Acceleration>(value) {}

  friend class Time;

  friend class Speed;

  friend class Acceleration;

};

AccelerationMagnitude Speed::operator/(const Time& time) const {
  if (time.value_ != 0.0) {
    return {value_ / time.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + time.print() + "."};
  }
}

} // namespace PhQ
