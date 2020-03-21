#pragma once

#include "../Base.hpp"

namespace PhQ {

class DimensionlessScalarQuantity : public DimensionlessQuantity {

public:

  DimensionlessScalarQuantity() noexcept : DimensionlessQuantity() {}

  constexpr DimensionlessScalarQuantity(double value) noexcept : DimensionlessQuantity(), value_(value) {}

  constexpr double value() const noexcept {
    return value_;
  }

  std::string print() const noexcept {
    return number_to_string(value_);
  }

  std::string json() const noexcept {
    return number_to_string(value_);
  }

  std::string xml() const noexcept {
    return number_to_string(value_);
  }

  constexpr bool operator==(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ == scalar.value_;
  }

  constexpr bool operator!=(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ != scalar.value_;
  }

  constexpr bool operator<(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ < scalar.value_;
  }

  constexpr bool operator<=(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ <= scalar.value_;
  }

  constexpr bool operator>(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ > scalar.value_;
  }

  constexpr bool operator>=(const DimensionlessScalarQuantity& scalar) const noexcept {
    return value_ >= scalar.value_;
  }

  DimensionlessScalarQuantity operator+(double real) const noexcept {
    return {value_ + real};
  }

  DimensionlessScalarQuantity operator+(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ + scalar.value_};
  }

  constexpr void operator+=(double real) noexcept {
    value_ += real;
  }

  constexpr void operator+=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ += scalar.value_;
  }

  DimensionlessScalarQuantity operator-(double real) const noexcept {
    return {value_ - real};
  }

  DimensionlessScalarQuantity operator-(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ - scalar.value_};
  }

  constexpr void operator-=(double real) noexcept {
    value_ -= real;
  }

  constexpr void operator-=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ -= scalar.value_;
  }

  constexpr DimensionlessScalarQuantity operator*(double real) const noexcept {
    return {value_ * real};
  }

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  DimensionlessScalarQuantity operator/(double real) const {
    if (real != 0.0) {
      return {value_ / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  constexpr double operator/(const DimensionlessScalarQuantity& scalar) const {
    if (scalar.value_ != 0.0) {
      return value_ / scalar.value_;
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

protected:

  double value_;

};

} // namespace PhQ

namespace std {

double cbrt(const PhQ::DimensionlessScalarQuantity& scalar) {
  return cbrt(scalar.value());
};

double exp(const PhQ::DimensionlessScalarQuantity& scalar) {
  return exp(scalar.value());
};

double log(const PhQ::DimensionlessScalarQuantity& scalar) {
  return log(scalar.value());
};

double log10(const PhQ::DimensionlessScalarQuantity& scalar) {
  return log10(scalar.value());
};

double pow(const PhQ::DimensionlessScalarQuantity& scalar, int_least64_t exponent) {
  return pow(scalar.value(), exponent);
};

double pow(const PhQ::DimensionlessScalarQuantity& scalar, double exponent) {
  return pow(scalar.value(), exponent);
};

double sqrt(const PhQ::DimensionlessScalarQuantity& scalar) {
  return sqrt(scalar.value());
};

} // namespace std
