#pragma once


#include "Force.hpp"
#include "Pressure.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

class Traction : public DimensionalVectorQuantity<Unit::Pressure> {

public:

  constexpr Traction() noexcept : DimensionalVectorQuantity<Unit::Pressure>() {}

  constexpr Traction(const Value::Vector& value, Unit::Pressure unit) noexcept : DimensionalVectorQuantity<Unit::Pressure>(value, unit) {}

  constexpr Pressure magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Traction& traction) const noexcept {
    return value_.angle(traction.value_);
  }

  constexpr bool operator==(const Traction& traction) const noexcept {
    return value_ == traction.value_;
  }

  constexpr bool operator!=(const Traction& traction) const noexcept {
    return value_ != traction.value_;
  }

  constexpr Traction operator+(const Traction& traction) const noexcept {
    return {value_ + traction.value_};
  }

  constexpr void operator+=(const Traction& traction) noexcept {
    value_ += traction.value_;
  }

  constexpr Traction operator-(const Traction& traction) const noexcept {
    return {value_ - traction.value_};
  }

  constexpr void operator-=(const Traction& traction) noexcept {
    value_ -= traction.value_;
  }

  constexpr Force operator*(const Area& area) const noexcept {
    return {value_ * area.value_};
  }

protected:

  constexpr Traction(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Pressure>(value) {}

  friend class Area;
  friend class Force;

};

constexpr Angle::Angle(const Traction& traction1, const Traction& traction2) noexcept : DimensionalScalarQuantity<Unit::Angle>(traction1.angle(traction2)) {}

constexpr Pressure::Pressure(const Traction& traction) noexcept : Pressure(traction.magnitude()) {}

Traction Force::operator/(const Area& area) const {
  if (area.value_ != 0.0) {
    return {value_ / area.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + area.print() + "."};
  }
}

} // namespace PhQ
