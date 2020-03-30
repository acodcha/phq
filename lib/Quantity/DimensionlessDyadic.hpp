#pragma once

#include "../Value/Dyadic.hpp"
#include "DimensionlessSymmetricDyadic.hpp"

namespace PhQ {

class DimensionlessDyadicQuantity : public DimensionlessQuantity {

public:

  DimensionlessDyadicQuantity() noexcept : DimensionlessQuantity() {}

  constexpr DimensionlessDyadicQuantity(const Value::Dyadic& value) noexcept : DimensionlessQuantity(), value_(value) {}

  constexpr const Value::Dyadic& value() const noexcept {
    return value_;
  }

  std::string print() const noexcept {
    return value_.print();
  }

  std::string json() const noexcept {
    return value_.json();
  }

  std::string xml() const noexcept {
    return value_.xml();
  }

  constexpr DimensionlessDyadicQuantity operator*(double real) const noexcept {
    return {value_ * real};
  }

  constexpr DimensionlessDyadicQuantity operator*(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ * scalar.value()};
  }

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  constexpr void operator*=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ *= scalar.value();
  }

  DimensionlessDyadicQuantity operator/(double real) const {
    if (real != 0.0) {
      return {value_ / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  DimensionlessDyadicQuantity operator/(const DimensionlessScalarQuantity& scalar) const {
    if (scalar.value() != 0.0) {
      return {value_ / scalar.value()};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

  void operator/=(double real) {
    if (real != 0.0) {
      value_ /= real;
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  void operator/=(const DimensionlessScalarQuantity& scalar) {
    if (scalar.value() != 0.0) {
      value_ /= scalar.value();
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

protected:

  Value::Dyadic value_;

};

template <> constexpr bool sort(const DimensionlessDyadicQuantity& dyadic1, const DimensionlessDyadicQuantity& dyadic2) noexcept {
  return sort(dyadic1.value(), dyadic2.value());
}

} // namespace PhQ
