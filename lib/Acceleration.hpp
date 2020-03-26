#pragma once

#include "Quantity/DimensionalVector.hpp"
#include "AccelerationMagnitude.hpp"

namespace PhQ {

class Acceleration : public DimensionalVectorQuantity<Unit::Acceleration> {

public:

  constexpr Acceleration() noexcept : DimensionalVectorQuantity<Unit::Acceleration>() {}

  constexpr Acceleration(const DimensionalVectorQuantity<Unit::Acceleration>& quantity) noexcept : DimensionalVectorQuantity<Unit::Acceleration>(quantity) {}

  constexpr Acceleration(const Value::Vector& value, Unit::Acceleration unit) noexcept : DimensionalVectorQuantity<Unit::Acceleration>(value, unit) {}

  constexpr AccelerationMagnitude magnitude() const noexcept {
    return {value_.magnitude()};
  }

  friend class AccelerationMagnitude;

};

constexpr AccelerationMagnitude::AccelerationMagnitude(const Acceleration& acceleration) noexcept : AccelerationMagnitude(acceleration.magnitude()) {}

} // namespace PhQ
