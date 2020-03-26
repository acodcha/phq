#pragma once

#include "Length.hpp"
#include "Time.hpp"
#include "Unit/Speed.hpp"

namespace PhQ {

// Forward declarations.
class Velocity;
class AccelerationMagnitude;

class Speed : public DimensionalScalarQuantity<Unit::Speed> {

public:

  constexpr Speed() noexcept : DimensionalScalarQuantity<Unit::Speed>() {}

  constexpr Speed(const DimensionalScalarQuantity<Unit::Speed>& quantity) noexcept : DimensionalScalarQuantity<Unit::Speed>(quantity) {}

  constexpr Speed(double value, Unit::Speed unit) noexcept : DimensionalScalarQuantity<Unit::Speed>(value, unit) {}

  constexpr Speed(const Velocity& velocity) noexcept;

  Length operator*(const Time& time) const noexcept {
    return {value_ * time.value_};
  }

  AccelerationMagnitude operator/(const Time& time) const;

protected:

  constexpr Speed(double value) noexcept : DimensionalScalarQuantity<Unit::Speed>(value) {}

  friend class Length;

  friend class Time;

  friend class Velocity;

  friend class AccelerationMagnitude;

};

Speed Length::operator/(const Time& time) const {
  if (time.value_ != 0.0) {
    return {value_ / time.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + time.print() + "."};
  }
}

} // namespace PhQ
