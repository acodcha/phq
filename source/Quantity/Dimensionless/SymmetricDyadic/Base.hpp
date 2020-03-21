#pragma once

#include "../../../Value/SymmetricDyadic.hpp"
#include "../Scalar/Base.hpp"
#include "../Base.hpp"

namespace PhQ {

class DimensionlessSymmetricCartesianDyadicQuantity : public DimensionlessQuantity {

public:

  DimensionlessSymmetricCartesianDyadicQuantity() noexcept : DimensionlessQuantity() {}

  constexpr DimensionlessSymmetricCartesianDyadicQuantity(const Value::SymmetricCartesianDyadic& value) noexcept : DimensionlessQuantity(), value_(value) {}

  constexpr const Value::SymmetricCartesianDyadic& value() const noexcept {
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

  constexpr bool operator==(const DimensionlessSymmetricCartesianDyadicQuantity& dyadic) const noexcept {
    return value_ == dyadic.value_;
  }

  constexpr bool operator!=(const DimensionlessSymmetricCartesianDyadicQuantity& dyadic) const noexcept {
    return value_ != dyadic.value_;
  }

  DimensionlessSymmetricCartesianDyadicQuantity operator+(const Value::SymmetricCartesianDyadic& value) const noexcept {
    return {value_ + value};
  }

  DimensionlessSymmetricCartesianDyadicQuantity operator+(const DimensionlessSymmetricCartesianDyadicQuantity& dyadic) const noexcept {
    return {value_ + dyadic.value_};
  }

  constexpr void operator+=(const Value::SymmetricCartesianDyadic& value) noexcept {
    value_ += value;
  }

  constexpr void operator+=(const DimensionlessSymmetricCartesianDyadicQuantity& dyadic) noexcept {
    value_ += dyadic.value_;
  }

  DimensionlessSymmetricCartesianDyadicQuantity operator-(const Value::SymmetricCartesianDyadic& value) const noexcept {
    return {value_ - value};
  }

  DimensionlessSymmetricCartesianDyadicQuantity operator-(const DimensionlessSymmetricCartesianDyadicQuantity& dyadic) const noexcept {
    return {value_ - dyadic.value_};
  }

  constexpr void operator-=(const Value::SymmetricCartesianDyadic& value) noexcept {
    value_ -= value;
  }

  constexpr void operator-=(const DimensionlessSymmetricCartesianDyadicQuantity& dyadic) noexcept {
    value_ -= dyadic.value_;
  }

  DimensionlessSymmetricCartesianDyadicQuantity operator*(double real) const noexcept {
    return {value_ * real};
  }

  DimensionlessSymmetricCartesianDyadicQuantity operator*(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ * scalar.value()};
  }

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  constexpr void operator*=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ *= scalar.value();
  }

  DimensionlessSymmetricCartesianDyadicQuantity operator/(double real) const {
    if (real != 0.0) {
      return {value_ / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  DimensionlessSymmetricCartesianDyadicQuantity operator/(const DimensionlessScalarQuantity& scalar) const {
    if (scalar.value() != 0.0) {
      return {value_ / scalar.value()};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

  constexpr void operator/=(double real) {
    if (real != 0.0) {
      value_ /= real;
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  constexpr void operator/=(const DimensionlessScalarQuantity& scalar) {
    if (scalar.value() != 0.0) {
      value_ /= scalar.value();
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

protected:

  Value::SymmetricCartesianDyadic value_;

};

template <> constexpr bool sort(const DimensionlessSymmetricCartesianDyadicQuantity& dyadic1, const DimensionlessSymmetricCartesianDyadicQuantity& dyadic2) noexcept {
  return sort(dyadic1.value(), dyadic2.value());
}

} // namespace PhQ
