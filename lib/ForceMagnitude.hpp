#pragma once

#include "Area.hpp"
#include "Unit/Force.hpp"

namespace PhQ {

// Forward declarations.
class Pressure;
class Force;

class ForceMagnitude : public DimensionalScalarQuantity<Unit::Force> {

public:

  constexpr ForceMagnitude() noexcept : DimensionalScalarQuantity<Unit::Force>() {}

  constexpr ForceMagnitude(double value, Unit::Force unit) noexcept : DimensionalScalarQuantity<Unit::Force>(value, unit) {}

  constexpr ForceMagnitude(const Force& force) noexcept;

  constexpr bool operator==(const ForceMagnitude& force_magnitude) const noexcept {
    return value_ == force_magnitude.value_;
  }

  constexpr bool operator!=(const ForceMagnitude& force_magnitude) const noexcept {
    return value_ != force_magnitude.value_;
  }

  constexpr bool operator<(const ForceMagnitude& force_magnitude) const noexcept {
    return value_ < force_magnitude.value_;
  }

  constexpr bool operator<=(const ForceMagnitude& force_magnitude) const noexcept {
    return value_ <= force_magnitude.value_;
  }

  constexpr bool operator>(const ForceMagnitude& force_magnitude) const noexcept {
    return value_ > force_magnitude.value_;
  }

  constexpr bool operator>=(const ForceMagnitude& force_magnitude) const noexcept {
    return value_ >= force_magnitude.value_;
  }

  ForceMagnitude operator+(const ForceMagnitude& force_magnitude) const noexcept {
    return {value_ + force_magnitude.value_};
  }

  constexpr void operator+=(const ForceMagnitude& force_magnitude) noexcept {
    value_ += force_magnitude.value_;
  }

  ForceMagnitude operator-(const ForceMagnitude& force_magnitude) const noexcept {
    return {value_ - force_magnitude.value_};
  }

  constexpr void operator-=(const ForceMagnitude& force_magnitude) noexcept {
    value_ -= force_magnitude.value_;
  }

  Pressure operator/(const Area& area) const;

protected:

  constexpr ForceMagnitude(double value) noexcept : DimensionalScalarQuantity<Unit::Force>(value) {}

  friend class Area;

  friend class Pressure;

  friend class Force;

};

} // namespace PhQ
