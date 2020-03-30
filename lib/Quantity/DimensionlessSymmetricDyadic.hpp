#pragma once

#include "../Value/SymmetricDyadic.hpp"
#include "DimensionlessScalar.hpp"

namespace PhQ {

class DimensionlessSymmetricDyadicQuantity : public DimensionlessQuantity {

public:

  DimensionlessSymmetricDyadicQuantity() noexcept : DimensionlessQuantity() {}

  constexpr DimensionlessSymmetricDyadicQuantity(const Value::SymmetricDyadic& value) noexcept : DimensionlessQuantity(), value_(value) {}

  constexpr const Value::SymmetricDyadic& value() const noexcept {
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

  constexpr bool operator==(const DimensionlessSymmetricDyadicQuantity& dyadic) const noexcept {
    return value_ == dyadic.value_;
  }

  constexpr bool operator!=(const DimensionlessSymmetricDyadicQuantity& dyadic) const noexcept {
    return value_ != dyadic.value_;
  }

  constexpr DimensionlessSymmetricDyadicQuantity operator+(const Value::SymmetricDyadic& value) const noexcept {
    return {value_ + value};
  }

  constexpr DimensionlessSymmetricDyadicQuantity operator+(const DimensionlessSymmetricDyadicQuantity& dyadic) const noexcept {
    return {value_ + dyadic.value_};
  }

  constexpr void operator+=(const Value::SymmetricDyadic& value) noexcept {
    value_ += value;
  }

  constexpr void operator+=(const DimensionlessSymmetricDyadicQuantity& dyadic) noexcept {
    value_ += dyadic.value_;
  }

  constexpr DimensionlessSymmetricDyadicQuantity operator-(const Value::SymmetricDyadic& value) const noexcept {
    return {value_ - value};
  }

  constexpr DimensionlessSymmetricDyadicQuantity operator-(const DimensionlessSymmetricDyadicQuantity& dyadic) const noexcept {
    return {value_ - dyadic.value_};
  }

  constexpr void operator-=(const Value::SymmetricDyadic& value) noexcept {
    value_ -= value;
  }

  constexpr void operator-=(const DimensionlessSymmetricDyadicQuantity& dyadic) noexcept {
    value_ -= dyadic.value_;
  }

  constexpr DimensionlessSymmetricDyadicQuantity operator*(double real) const noexcept {
    return {value_ * real};
  }

  constexpr DimensionlessSymmetricDyadicQuantity operator*(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ * scalar.value()};
  }

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  constexpr void operator*=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ *= scalar.value();
  }

  DimensionlessSymmetricDyadicQuantity operator/(double real) const {
    if (real != 0.0) {
      return {value_ / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  DimensionlessSymmetricDyadicQuantity operator/(const DimensionlessScalarQuantity& scalar) const {
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

  Value::SymmetricDyadic value_;

};

template <> constexpr bool sort(const DimensionlessSymmetricDyadicQuantity& dyadic1, const DimensionlessSymmetricDyadicQuantity& dyadic2) noexcept {
  return sort(dyadic1.value(), dyadic2.value());
}

} // namespace PhQ
