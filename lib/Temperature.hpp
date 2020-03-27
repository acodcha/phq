#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Temperature.hpp"

namespace PhQ {

class Temperature : public DimensionalScalarQuantity<Unit::Temperature> {

public:

  constexpr Temperature() noexcept : DimensionalScalarQuantity<Unit::Temperature>() {}

  constexpr Temperature(double value, Unit::Temperature unit) noexcept : DimensionalScalarQuantity<Unit::Temperature>(value, unit) {}

  constexpr bool operator==(const Temperature& temperature) const noexcept {
    return value_ == temperature.value_;
  }

  constexpr bool operator!=(const Temperature& temperature) const noexcept {
    return value_ != temperature.value_;
  }

  constexpr bool operator<(const Temperature& temperature) const noexcept {
    return value_ < temperature.value_;
  }

  constexpr bool operator<=(const Temperature& temperature) const noexcept {
    return value_ <= temperature.value_;
  }

  constexpr bool operator>(const Temperature& temperature) const noexcept {
    return value_ > temperature.value_;
  }

  constexpr bool operator>=(const Temperature& temperature) const noexcept {
    return value_ >= temperature.value_;
  }

  Temperature operator+(const Temperature& temperature) const noexcept {
    return {value_ + temperature.value_};
  }

  constexpr void operator+=(const Temperature& temperature) noexcept {
    value_ += temperature.value_;
  }

  Temperature operator-(const Temperature& temperature) const noexcept {
    return {value_ - temperature.value_};
  }

  constexpr void operator-=(const Temperature& temperature) noexcept {
    value_ -= temperature.value_;
  }

protected:

  constexpr Temperature(double value) noexcept : DimensionalScalarQuantity<Unit::Temperature>(value) {}

};

} // namespace PhQ
