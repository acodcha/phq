#pragma once

#include "Quantity/DimensionlessDyadic.hpp"

namespace PhQ {

class DisplacementGradient : public DimensionlessDyadicQuantity {

public:

  DisplacementGradient() noexcept : DimensionlessDyadicQuantity() {}

  constexpr DisplacementGradient(const Value::Dyadic& value) noexcept : DimensionlessDyadicQuantity(value) {}

  constexpr bool operator==(const DisplacementGradient& displacement_gradient) const noexcept {
    return value_ == displacement_gradient.value_;
  }

  constexpr bool operator!=(const DisplacementGradient& displacement_gradient) const noexcept {
    return value_ != displacement_gradient.value_;
  }

  constexpr DisplacementGradient operator+(const DisplacementGradient& displacement_gradient) const noexcept {
    return {value_ + displacement_gradient.value_};
  }

  constexpr void operator+=(const DisplacementGradient& displacement_gradient) noexcept {
    value_ += displacement_gradient.value_;
  }

  constexpr DisplacementGradient operator-(const DisplacementGradient& displacement_gradient) const noexcept {
    return {value_ - displacement_gradient.value_};
  }

  constexpr void operator-=(const DisplacementGradient& displacement_gradient) noexcept {
    value_ -= displacement_gradient.value_;
  }

};

} // namespace PhQ
