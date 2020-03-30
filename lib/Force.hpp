#pragma once

#include "Angle.hpp"
#include "ForceMagnitude.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

class Force : public DimensionalVectorQuantity<Unit::Force> {

public:

  constexpr Force() noexcept : DimensionalVectorQuantity<Unit::Force>() {}

  constexpr Force(const Value::Vector& value, Unit::Force unit) noexcept : DimensionalVectorQuantity<Unit::Force>(value, unit) {}

  constexpr ForceMagnitude magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Force& force) const noexcept {
    return value_.angle(force.value_);
  }

  constexpr bool operator==(const Force& force) const noexcept {
    return value_ == force.value_;
  }

  constexpr bool operator!=(const Force& force) const noexcept {
    return value_ != force.value_;
  }

  constexpr Force operator+(const Force& force) const noexcept {
    return {value_ + force.value_};
  }

  constexpr void operator+=(const Force& force) noexcept {
    value_ += force.value_;
  }

  constexpr Force operator-(const Force& force) const noexcept {
    return {value_ - force.value_};
  }

  constexpr void operator-=(const Force& force) noexcept {
    value_ -= force.value_;
  }

protected:

  constexpr Force(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Force>(value) {}

};

constexpr Angle::Angle(const Force& force1, const Force& force2) noexcept : DimensionalScalarQuantity<Unit::Angle>(force1.angle(force2)) {}

constexpr ForceMagnitude::ForceMagnitude(const Force& force) noexcept : ForceMagnitude(force.magnitude()) {}

} // namespace PhQ
