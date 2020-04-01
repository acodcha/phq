#pragma once

#include "ForceMagnitude.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration.
class Traction;

class Pressure : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr Pressure() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  constexpr Pressure(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr Pressure(const Traction& traction) noexcept;

  constexpr bool operator==(const Pressure& pressure) const noexcept {
    return value_ == pressure.value_;
  }

  constexpr bool operator!=(const Pressure& pressure) const noexcept {
    return value_ != pressure.value_;
  }

  constexpr bool operator<(const Pressure& pressure) const noexcept {
    return value_ < pressure.value_;
  }

  constexpr bool operator<=(const Pressure& pressure) const noexcept {
    return value_ <= pressure.value_;
  }

  constexpr bool operator>(const Pressure& pressure) const noexcept {
    return value_ > pressure.value_;
  }

  constexpr bool operator>=(const Pressure& pressure) const noexcept {
    return value_ >= pressure.value_;
  }

  constexpr Pressure operator+(const Pressure& pressure) const noexcept {
    return {value_ + pressure.value_};
  }

  constexpr void operator+=(const Pressure& pressure) noexcept {
    value_ += pressure.value_;
  }

  constexpr Pressure operator-(const Pressure& pressure) const noexcept {
    return {value_ - pressure.value_};
  }

  constexpr void operator-=(const Pressure& pressure) noexcept {
    value_ -= pressure.value_;
  }

  ForceMagnitude operator*(const Area& area) const noexcept {
    return {value_ * area.value_};
  }

protected:

  constexpr Pressure(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

  friend class Area;
  friend class ForceMagnitude;
  friend class Traction;

};

constexpr ForceMagnitude Area::operator*(const Pressure& pressure) const noexcept {
  return {value_ * pressure.value_};
}

Pressure ForceMagnitude::operator/(const Area& area) const {
  if (area.value_ != 0.0) {
    return {value_ / area.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + area.print() + "."};
  }
}

} // namespace PhQ
