#pragma once

#include "../Direction.hpp"
#include "Dimensional.hpp"
#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declaration.
template <typename Unit> class DimensionalVectorQuantity;

template <typename Unit> class DimensionalScalarQuantity : public DimensionalQuantity<Unit> {

public:

  constexpr DimensionalScalarQuantity() noexcept : DimensionalQuantity<Unit>() {}

  constexpr DimensionalScalarQuantity(double value, Unit unit) noexcept : DimensionalQuantity<Unit>(), value_(convert(value, unit, standard_unit<Unit>)) {}

  constexpr double value() const noexcept {
    return value_;
  }

  constexpr double value(const Unit unit) const noexcept {
    if (unit == standard_unit<Unit>) {
      return value_;
    } else {
      return convert(value_, standard_unit<Unit>, unit);
    }
  }

  constexpr double value(const System system) const noexcept {
    if (system == standard_system) {
      return value_;
    } else {
      return convert(value_, standard_unit<Unit>, system);
    }
  }

  std::string print() const noexcept {
    return number_to_string(value_) + " " + abbreviation(standard_unit<Unit>);
  }

  std::string print(Unit unit) const noexcept {
    return number_to_string(value(unit)) + " " + abbreviation(unit);
  }

  std::string print(System system) const noexcept {
    return number_to_string(value(system)) + " " + abbreviation(unit<Unit>(system));
  }

  std::string json() const noexcept {
    return "{ \"value\": " + number_to_string(value_) + ", \"unit\": " + abbreviation(standard_unit<Unit>) + "}";
  }

  std::string json(Unit unit) const noexcept {
    return "{ \"value\": " + number_to_string(value(unit)) + ", \"unit\": " + abbreviation(unit) + "}";
  }

  std::string json(System system) const noexcept {
    return "{ \"value\": " + number_to_string(value(system)) + ", \"unit\": " + abbreviation(unit<Unit>(system)) + "}";
  }

  std::string xml() const noexcept {
    return "<value>" + number_to_string(value_) + "</value><unit>" + abbreviation(standard_unit<Unit>) + "</unit>";
  }

  std::string xml(Unit unit) const noexcept {
    return "<value>" + number_to_string(value(unit)) + "</value><unit>" + abbreviation(unit) + "</unit>";
  }

  std::string xml(System system) const noexcept {
    return "<value>" + number_to_string(value(system)) + "</value><unit>" + abbreviation(unit<Unit>(system)) + "</unit>";
  }

  constexpr bool operator==(const DimensionalScalarQuantity<Unit>& scalar) const noexcept {
    return value_ == scalar.value_;
  }

  constexpr bool operator!=(const DimensionalScalarQuantity<Unit>& scalar) const noexcept {
    return value_ != scalar.value_;
  }

  constexpr bool operator<(const DimensionalScalarQuantity<Unit>& scalar) const noexcept {
    return value_ < scalar.value_;
  }

  constexpr bool operator<=(const DimensionalScalarQuantity<Unit>& scalar) const noexcept {
    return value_ <= scalar.value_;
  }

  constexpr bool operator>(const DimensionalScalarQuantity<Unit>& scalar) const noexcept {
    return value_ > scalar.value_;
  }

  constexpr bool operator>=(const DimensionalScalarQuantity<Unit>& scalar) const noexcept {
    return value_ >= scalar.value_;
  }

  DimensionalScalarQuantity<Unit> operator+(const DimensionalScalarQuantity<Unit>& scalar) const noexcept {
    return {value_ + scalar.value_};
  }

  void operator+=(const DimensionalScalarQuantity<Unit>& scalar) noexcept {
    value_ += scalar.value_;
  }

  DimensionalScalarQuantity<Unit> operator-(const DimensionalScalarQuantity<Unit>& scalar) const noexcept {
    return {value_ - scalar.value_};
  }

  void operator-=(const DimensionalScalarQuantity<Unit>& scalar) noexcept {
    value_ -= scalar.value_;
  }

  DimensionalScalarQuantity<Unit> operator*(double real) const noexcept {
    return {value_ * real};
  }

  DimensionalScalarQuantity<Unit> operator*(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ * scalar.value()};
  }

  DimensionalVectorQuantity<Unit> operator*(const Direction& cartesian_direction) const noexcept;

  void operator*=(double real) noexcept {
    value_ *= real;
  }

  void operator*=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ *= scalar.value();
  }

  DimensionalScalarQuantity<Unit> operator/(double real) const {
    if (real != 0.0) {
      return {value_ / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  double operator/(const DimensionlessScalarQuantity& scalar) const {
    if (scalar != 0.0) {
      return {value_ / scalar.value()};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

  double operator/(const DimensionalScalarQuantity<Unit>& scalar) const {
    if (scalar != 0.0) {
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

protected:

  constexpr DimensionalScalarQuantity(double value) noexcept : DimensionalQuantity<Unit>(), value_(value) {}

  double value_;

  friend class DimensionalVectorQuantity<Unit>;

};

template <typename Unit> constexpr DimensionalVectorQuantity<Unit> Direction::operator*(const DimensionalScalarQuantity<Unit>& scalar) const noexcept {
  return {scalar, *this};
}

} // namespace PhQ

namespace std {

template <typename Unit> double cbrt(const PhQ::DimensionalScalarQuantity<Unit>& scalar) {
  return cbrt(scalar.value());
};

template <typename Unit> double exp(const PhQ::DimensionalScalarQuantity<Unit>& scalar) {
  return exp(scalar.value());
};

template <typename Unit> double log(const PhQ::DimensionalScalarQuantity<Unit>& scalar) {
  return log(scalar.value());
};

template <typename Unit> double log10(const PhQ::DimensionalScalarQuantity<Unit>& scalar) {
  return log10(scalar.value());
};

template <typename Unit> double pow(const PhQ::DimensionalScalarQuantity<Unit>& scalar, int_least64_t exponent) {
  return pow(scalar.value(), exponent);
};

template <typename Unit> double pow(const PhQ::DimensionalScalarQuantity<Unit>& scalar, double exponent) {
  return pow(scalar.value(), exponent);
};

template <typename Unit> double sqrt(const PhQ::DimensionalScalarQuantity<Unit>& scalar) {
  return sqrt(scalar.value());
};

} // namespace std

template <typename Unit> std::ostream& operator<<(std::ostream& output_stream, const PhQ::DimensionalScalarQuantity<Unit>& scalar) noexcept {
  output_stream << scalar.print();
  return output_stream;
}
