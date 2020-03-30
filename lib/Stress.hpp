#pragma once

#include "Quantity/DimensionalSymmetricDyadic.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

class Stress : public DimensionalSymmetricDyadicQuantity<Unit::Pressure> {

public:

  constexpr Stress() noexcept : DimensionalSymmetricDyadicQuantity<Unit::Pressure>() {}

  constexpr Stress(const Value::SymmetricDyadic& value, Unit::Pressure unit) noexcept : DimensionalSymmetricDyadicQuantity<Unit::Pressure>(value, unit) {}

  constexpr bool operator==(const Stress& stress) const noexcept {
    return value_ == stress.value_;
  }

  constexpr bool operator!=(const Stress& stress) const noexcept {
    return value_ != stress.value_;
  }

  constexpr Stress operator+(const Stress& stress) const noexcept {
    return {value_ + stress.value_};
  }

  constexpr void operator+=(const Stress& stress) noexcept {
    value_ += stress.value_;
  }

  constexpr Stress operator-(const Stress& stress) const noexcept {
    return {value_ - stress.value_};
  }

  constexpr void operator-=(const Stress& stress) noexcept {
    value_ -= stress.value_;
  }

protected:

  constexpr Stress(const Value::SymmetricDyadic& value) noexcept : DimensionalSymmetricDyadicQuantity<Unit::Pressure>(value) {}

};

} // namespace PhQ
