#pragma once

#include "../Base.hpp"

namespace PhQ {

template <typename Unit> class DimensionalScalarQuantity : public Quantity {

public:

  constexpr DimensionalScalarQuantity() noexcept : DimensionalQuantity() {}

  constexpr DimensionalScalarQuantity(double value, Unit unit) noexcept : DimensionalQuantity(), value_(Unit::convert(value, unit, Unit::standard<Unit>)) {}

  constexpr double convert(const Unit unit) const noexcept {
    return Unit::convert(value_, this->unit(), unit);
  }

  constexpr double convert(const System system) const noexcept {
    return convert(unit(system));
  }

  std::string print(System system = system()) const noexcept {
    return real_number_to_string(value_) + " " + abbreviation(unit(system));
  }

  std::string print(Unit unit = unit()) const noexcept {
    return real_number_to_string(value_) + " " + abbreviation(unit);
  }

  std::string json(System system = system()) const noexcept {
    return "{ \"value\": " + real_number_to_string(value_) + ", \"unit\": " + abbreviation(unit(system)) + "}";
  }

  std::string json(Unit unit = unit()) const noexcept {
    return "{ \"value\": " + real_number_to_string(value_) + ", \"unit\": " + abbreviation(unit) + "}";
  }

  std::string json(System system = system()) const noexcept {
    return "<value>" + real_number_to_string(value_) + "</value><unit>" + abbreviation(unit(system)) + "</unit>";
  }

  std::string json(Unit unit = unit()) const noexcept {
    return "<value>" + real_number_to_string(value_) + "</value><unit>" + abbreviation(unit) + "</unit>";
  }

  constexpr bool operator==(const DimensionalScalarQuantity<Unit>& other) const noexcept {
    return value_ == other.value_;
  }

  constexpr bool operator!=(const DimensionalScalarQuantity<Unit>& other) const noexcept {
    return value_ != other.value_;
  }

  constexpr bool operator<(const DimensionalScalarQuantity<Unit>& other) const noexcept {
    return value_ < other.value_;
  }

  constexpr bool operator<=(const DimensionalScalarQuantity<Unit>& other) const noexcept {
    return value_ <= other.value_;
  }

  constexpr bool operator>(const DimensionalScalarQuantity<Unit>& other) const noexcept {
    return value_ > other.value_;
  }

  constexpr bool operator>=(const DimensionalScalarQuantity<Unit>& other) const noexcept {
    return value_ >= other.value_;
  }

  DimensionalScalarQuantity<Unit> operator+(const DimensionalScalarQuantity<Unit>& other) const noexcept {
    return {value_ + other.value_, unit()};
  }

  void operator+=(const DimensionalScalarQuantity<Unit>& other) const noexcept {
    value_ += other.value_;
  }

  DimensionalScalarQuantity<Unit> operator-(const DimensionalScalarQuantity<Unit>& other) const noexcept {
    return {value_ - other.value_, unit()};
  }

  void operator-=(const DimensionalScalarQuantity<Unit>& other) const noexcept {
    value_ -= other.value_;
  }

  DimensionalScalarQuantity<Unit> operator*(double number) const noexcept {
    return {value_ * number};
  }

  void operator*=(double number) const noexcept {
    value_ *= number;
  }

  DimensionalScalarQuantity<Unit> operator/(double number) const {
    if (number != 0.0) {
      return {value_ / number};
    } else {
      throw std::runtime_error{"Division by zero."};
    }
  }

  void operator/=(double number) const noexcept {
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

template <typename Unit> double cbrt(const PhQ::DimensionalScalarQuantity<Unit>& quantity) {
  return cbrt(quantity.value());
};

template <typename Unit> double exp(const PhQ::DimensionalScalarQuantity<Unit>& quantity) {
  return exp(quantity.value());
};

template <typename Unit> double log(const PhQ::DimensionalScalarQuantity<Unit>& quantity) {
  return log(quantity.value());
};

template <typename Unit> double log10(const PhQ::DimensionalScalarQuantity<Unit>& quantity) {
  return log10(quantity.value());
};

template <typename Unit> double pow(const PhQ::DimensionalScalarQuantity<Unit>& quantity, int_least64_t exponent) {
  return pow(quantity.value(), exponent);
};

template <typename Unit> double pow(const PhQ::DimensionalScalarQuantity<Unit>& quantity, double exponent) {
  return pow(quantity.value(), exponent);
};

template <typename Unit> double sqrt(const PhQ::DimensionalScalarQuantity<Unit>& quantity) {
  return sqrt(quantity.value());
};

} // namespace std
