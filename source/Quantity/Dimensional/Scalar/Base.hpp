#pragma once

#include "../Base.hpp"

namespace PhQ {

template <typename Unit> class DimensionalScalarQuantity : public DimensionalQuantity<Unit> {

public:

  constexpr DimensionalScalarQuantity() noexcept : DimensionalQuantity<Unit>() {}

  constexpr DimensionalScalarQuantity(double value, Unit unit) noexcept : DimensionalQuantity<Unit>(), value_(PhQ::Unit::convert(value, unit, this->unit())) {}

  constexpr double value() const noexcept {
    return value_;
  }

  constexpr double convert(const System system) const noexcept {
    return PhQ::Unit::convert(value_, this->unit(), system);
  }

  constexpr double convert(const Unit unit) const noexcept {
    return PhQ::Unit::convert(value_, this->unit(), unit);
  }

  std::string print(System system) const noexcept {
    return PhQ::number_to_string(convert(system)) + " " + PhQ::Unit::abbreviation(PhQ::unit<Unit>(system));
  }

  std::string print(Unit unit) const noexcept {
    return PhQ::number_to_string(convert(unit)) + " " + PhQ::Unit::abbreviation(unit);
  }

  std::string json(System system) const noexcept {
    return "{ \"value\": " + PhQ::number_to_string(convert(system)) + ", \"unit\": " + PhQ::Unit::abbreviation(PhQ::unit<Unit>(system)) + "}";
  }

  std::string json(Unit unit) const noexcept {
    return "{ \"value\": " + PhQ::number_to_string(convert(unit)) + ", \"unit\": " + PhQ::Unit::abbreviation(unit) + "}";
  }

  std::string xml(System system) const noexcept {
    return "<value>" + PhQ::number_to_string(convert(system)) + "</value><unit>" + PhQ::Unit::abbreviation(PhQ::unit<Unit>(system)) + "</unit>";
  }

  std::string xml(Unit unit) const noexcept {
    return "<value>" + PhQ::number_to_string(convert(unit)) + "</value><unit>" + PhQ::Unit::abbreviation(unit) + "</unit>";
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
    return {value_ + other.value_};
  }

  void operator+=(const DimensionalScalarQuantity<Unit>& other) noexcept {
    value_ += other.value_;
  }

  DimensionalScalarQuantity<Unit> operator-(const DimensionalScalarQuantity<Unit>& other) const noexcept {
    return {value_ - other.value_};
  }

  void operator-=(const DimensionalScalarQuantity<Unit>& other) noexcept {
    value_ -= other.value_;
  }

  DimensionalScalarQuantity<Unit> operator*(double number) const noexcept {
    return {value_ * number};
  }

  void operator*=(double number) noexcept {
    value_ *= number;
  }

  DimensionalScalarQuantity<Unit> operator/(double number) const {
    if (number != 0.0) {
      return {value_ / number};
    } else {
      throw std::runtime_error{"Division by zero."};
    }
  }

  void operator/=(double number) noexcept {
    if (number != 0.0) {
      value_ /= number;
    } else {
      throw std::runtime_error{"Division by zero."};
    }
  }

protected:

  constexpr DimensionalScalarQuantity(double value) noexcept : DimensionalQuantity<Unit>(), value_(value) {}

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
