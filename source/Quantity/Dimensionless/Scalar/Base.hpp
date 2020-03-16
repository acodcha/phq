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
    return real_number_to_string(value_);
  }

  std::string json() const noexcept {
    return real_number_to_string(value_);
  }

  std::string xml() const noexcept {
    return real_number_to_string(value_);
  }

  constexpr bool operator==(const DimensionlessScalarQuantity& other) const noexcept {
    return value_ == other.value_;
  }

  constexpr bool operator!=(const DimensionlessScalarQuantity& other) const noexcept {
    return value_ != other.value_;
  }

  constexpr bool operator<(const DimensionlessScalarQuantity& other) const noexcept {
    return value_ < other.value_;
  }

  constexpr bool operator<=(const DimensionlessScalarQuantity& other) const noexcept {
    return value_ <= other.value_;
  }

  constexpr bool operator>(const DimensionlessScalarQuantity& other) const noexcept {
    return value_ > other.value_;
  }

  constexpr bool operator>=(const DimensionlessScalarQuantity& other) const noexcept {
    return value_ >= other.value_;
  }

  DimensionlessScalarQuantity operator+(double number) const noexcept {
    return {value_ + number};
  }

  DimensionlessScalarQuantity operator+(const DimensionlessScalarQuantity& other) const noexcept {
    return {value_ + other.value_};
  }

  void operator+=(double number) noexcept {
    value_ += number;
  }

  void operator+=(const DimensionlessScalarQuantity& other) noexcept {
    value_ += other.value_;
  }

  DimensionlessScalarQuantity operator-(double number) const noexcept {
    return {value_ - number};
  }

  DimensionlessScalarQuantity operator-(const DimensionlessScalarQuantity& other) const noexcept {
    return {value_ - other.value_};
  }

  void operator-=(double number) noexcept {
    value_ -= number;
  }

  void operator-=(const DimensionlessScalarQuantity& other) noexcept {
    value_ -= other.value_;
  }

  DimensionlessScalarQuantity operator*(double number) const noexcept {
    return {value_ * number};
  }

  void operator*=(double number) noexcept {
    value_ *= number;
  }

  DimensionlessScalarQuantity operator/(double number) const {
    if (number != 0.0) {
      return {value_ / number};
    } else {
      throw std::runtime_error{"Division by zero."};
    }
  }

  double operator/(const DimensionlessScalarQuantity& other) const {
    if (other.value_ != 0.0) {
      return value_ / other.value_;
    } else {
      throw std::runtime_error{"Division by zero."};
    }
  }

  void operator/=(double number) {
    if (number != 0.0) {
      value_ /= number;
    } else {
      throw std::runtime_error{"Division by zero."};
    }
  }

protected:

  double value_;

};

} // namespace PhQ

namespace std {

double cbrt(const PhQ::DimensionlessScalarQuantity& quantity) {
  return cbrt(quantity.value());
};

double exp(const PhQ::DimensionlessScalarQuantity& quantity) {
  return exp(quantity.value());
};

double log(const PhQ::DimensionlessScalarQuantity& quantity) {
  return log(quantity.value());
};

double log10(const PhQ::DimensionlessScalarQuantity& quantity) {
  return log10(quantity.value());
};

double pow(const PhQ::DimensionlessScalarQuantity& quantity, int_least64_t exponent) {
  return pow(quantity.value(), exponent);
};

double pow(const PhQ::DimensionlessScalarQuantity& quantity, double exponent) {
  return pow(quantity.value(), exponent);
};

double sqrt(const PhQ::DimensionlessScalarQuantity& quantity) {
  return sqrt(quantity.value());
};

} // namespace std
