#pragma once

#include "Quantity/DimensionalVector.hpp"
#include "Speed.hpp"

namespace PhQ {

class Velocity : public DimensionalVectorQuantity<Unit::Speed> {

public:

  constexpr Velocity() noexcept : DimensionalVectorQuantity<Unit::Speed>() {}

  constexpr Velocity(const DimensionalVectorQuantity<Unit::Speed>& quantity) noexcept : DimensionalVectorQuantity<Unit::Speed>(quantity) {}

  constexpr Velocity(const Value::Vector& value, Unit::Speed unit) noexcept : DimensionalVectorQuantity<Unit::Speed>(value, unit) {}

  constexpr Speed magnitude() const noexcept {
    return {value_.magnitude()};
  }

  friend class Speed;

};

constexpr Speed::Speed(const Velocity& velocity) noexcept : Speed(velocity.magnitude()) {}

} // namespace PhQ
