#pragma once

#include "ForceMagnitude.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

class Force : public DimensionalVectorQuantity<Unit::Force> {

public:

  constexpr Force() noexcept : DimensionalVectorQuantity<Unit::Force>() {}

  constexpr Force(const DimensionalVectorQuantity<Unit::Force>& quantity) noexcept : DimensionalVectorQuantity<Unit::Force>(quantity) {}

  constexpr Force(const Value::Vector& value, Unit::Force unit) noexcept : DimensionalVectorQuantity<Unit::Force>(value, unit) {}

  constexpr ForceMagnitude magnitude() const noexcept {
    return {value_.magnitude()};
  }

};

constexpr ForceMagnitude::ForceMagnitude(const Force& force) noexcept : ForceMagnitude(force.magnitude()) {}

} // namespace PhQ
