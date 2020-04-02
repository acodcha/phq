#pragma once

#include "Temperature.hpp"

namespace PhQ {

class TemperatureDifference : public DimensionalScalarQuantity<Unit::Temperature> {

public:

  constexpr TemperatureDifference() noexcept : DimensionalScalarQuantity<Unit::Temperature>() {}

  constexpr TemperatureDifference(double value, Unit::Temperature unit) noexcept : DimensionalScalarQuantity<Unit::Temperature>(value, unit) {}

  constexpr bool operator==(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ == temperature_difference.value_;
  }

  constexpr bool operator!=(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ != temperature_difference.value_;
  }

  constexpr bool operator<(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ < temperature_difference.value_;
  }

  constexpr bool operator<=(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ <= temperature_difference.value_;
  }

  constexpr bool operator>(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ > temperature_difference.value_;
  }

  constexpr bool operator>=(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ >= temperature_difference.value_;
  }

  Temperature operator+(const Temperature& temperature) const noexcept {
    return {value_ + temperature.value_};
  }

  TemperatureDifference operator+(const TemperatureDifference& temperature_difference) const noexcept {
    return {value_ + temperature_difference.value_};
  }

  constexpr void operator+=(const TemperatureDifference& temperature_difference) noexcept {
    value_ += temperature_difference.value_;
  }

  Temperature operator-(const Temperature& temperature) const noexcept {
    return {value_ - temperature.value_};
  }

  TemperatureDifference operator-(const TemperatureDifference& temperature_difference) const noexcept {
    return {value_ - temperature_difference.value_};
  }

  constexpr void operator-=(const TemperatureDifference& temperature_difference) noexcept {
    value_ -= temperature_difference.value_;
  }

protected:

  constexpr TemperatureDifference(double value) noexcept : DimensionalScalarQuantity<Unit::Temperature>(value) {}

  friend class Temperature;

};

Temperature Temperature::operator+(const TemperatureDifference& temperature_difference) const noexcept {
  return {value_ + temperature_difference.value_};
}

constexpr void Temperature::operator+=(const TemperatureDifference& temperature_difference) noexcept {
  value_ += temperature_difference.value_;
}

TemperatureDifference Temperature::operator-(const Temperature& temperature) const noexcept {
  return {value_ - temperature.value_};
}

Temperature Temperature::operator-(const TemperatureDifference& temperature_difference) const noexcept {
  return {value_ - temperature_difference.value_};
}

constexpr void Temperature::operator-=(const TemperatureDifference& temperature_difference) noexcept {
  value_ -= temperature_difference.value_;
}

} // namespace PhQ
