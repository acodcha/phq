#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Mass.hpp"

namespace PhQ {

class Mass : public DimensionalScalarQuantity<Unit::Mass> {

public:

  constexpr Mass() noexcept : DimensionalScalarQuantity<Unit::Mass>() {}

  constexpr Mass(double value, Unit::Mass unit) noexcept : DimensionalScalarQuantity<Unit::Mass>(value, unit) {}

  constexpr bool operator==(const Mass& mass) const noexcept {
    return value_ == mass.value_;
  }

  constexpr bool operator!=(const Mass& mass) const noexcept {
    return value_ != mass.value_;
  }

  constexpr bool operator<(const Mass& mass) const noexcept {
    return value_ < mass.value_;
  }

  constexpr bool operator<=(const Mass& mass) const noexcept {
    return value_ <= mass.value_;
  }

  constexpr bool operator>(const Mass& mass) const noexcept {
    return value_ > mass.value_;
  }

  constexpr bool operator>=(const Mass& mass) const noexcept {
    return value_ >= mass.value_;
  }

  Mass operator+(const Mass& mass) const noexcept {
    return {value_ + mass.value_};
  }

  constexpr void operator+=(const Mass& mass) noexcept {
    value_ += mass.value_;
  }

  Mass operator-(const Mass& mass) const noexcept {
    return {value_ - mass.value_};
  }

  constexpr void operator-=(const Mass& mass) noexcept {
    value_ -= mass.value_;
  }

protected:

  constexpr Mass(double value) noexcept : DimensionalScalarQuantity<Unit::Mass>(value) {}

};

} // namespace PhQ
