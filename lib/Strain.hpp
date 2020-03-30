#pragma once

#include "Quantity/DimensionlessSymmetricDyadic.hpp"

namespace PhQ {

class Strain : public DimensionlessSymmetricDyadicQuantity {

public:

  Strain() noexcept : DimensionlessSymmetricDyadicQuantity() {}

  constexpr Strain(const Value::SymmetricDyadic& value) noexcept : DimensionlessSymmetricDyadicQuantity(value) {}

  constexpr bool operator==(const Strain& strain) const noexcept {
    return value_ == strain.value_;
  }

  constexpr bool operator!=(const Strain& strain) const noexcept {
    return value_ != strain.value_;
  }

  constexpr Strain operator+(const Strain& strain) const noexcept {
    return {value_ + strain.value_};
  }

  constexpr void operator+=(const Strain& strain) noexcept {
    value_ += strain.value_;
  }

  constexpr Strain operator-(const Strain& strain) const noexcept {
    return {value_ - strain.value_};
  }

  constexpr void operator-=(const Strain& strain) noexcept {
    value_ -= strain.value_;
  }

};

} // namespace PhQ
