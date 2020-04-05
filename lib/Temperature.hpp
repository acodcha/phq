#pragma once

#include "TemperatureDifference.hpp"

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

  Temperature operator+(const TemperatureDifference& temperature_difference) const noexcept {
    return {value_ + temperature_difference.value_};
  }

  constexpr void operator+=(const Temperature& temperature) noexcept {
    value_ += temperature.value_;
  }

  constexpr void operator+=(const TemperatureDifference& temperature_difference) noexcept {
    value_ += temperature_difference.value_;
  }

  TemperatureDifference operator-(const Temperature& temperature) const noexcept {
    return {value_ - temperature.value_};
  }

  Temperature operator-(const TemperatureDifference& temperature_difference) const noexcept {
    return {value_ - temperature_difference.value_};
  }

  constexpr void operator-=(const Temperature& temperature) noexcept {
    value_ -= temperature.value_;
  }

  constexpr void operator-=(const TemperatureDifference& temperature_difference) noexcept {
    value_ -= temperature_difference.value_;
  }

protected:

  constexpr Temperature(double value) noexcept : DimensionalScalarQuantity<Unit::Temperature>(value) {}

  friend class TemperatureDifference;

};

Temperature TemperatureDifference::operator+(const Temperature& temperature) const noexcept {
  return {value_ + temperature.value_};
}

Temperature TemperatureDifference::operator-(const Temperature& temperature) const noexcept {
  return {value_ - temperature.value_};
}

} // namespace PhQ
