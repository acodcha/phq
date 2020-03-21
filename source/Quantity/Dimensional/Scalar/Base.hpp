#pragma once

#include "../../Direction.hpp"
#include "../../Dimensionless/Scalar/Base.hpp"
#include "../Base.hpp"

namespace PhQ {

// Forward declaration.
template <typename Unit> class DimensionalCartesianVectorQuantity;

template <typename Unit> class DimensionalScalarQuantity : public DimensionalQuantity<Unit> {

public:

  constexpr DimensionalScalarQuantity() noexcept : DimensionalQuantity<Unit>() {}

  constexpr DimensionalScalarQuantity(double value, Unit unit) noexcept : DimensionalQuantity<Unit>(), value_(PhQ::convert(value, unit, this->unit())) {}

  constexpr double value() const noexcept {
    return value_;
  }

  constexpr double convert(const System system) const noexcept {
    return PhQ::convert(value_, this->unit(), system);
  }

  constexpr double convert(const Unit unit) const noexcept {
    return PhQ::convert(value_, this->unit(), unit);
  }

  std::string print(System system) const noexcept {
    return PhQ::number_to_string(convert(system)) + " " + PhQ::abbreviation(PhQ::unit<Unit>(system));
  }

  std::string print(Unit unit) const noexcept {
    return PhQ::number_to_string(convert(unit)) + " " + PhQ::abbreviation(unit);
  }

  std::string json(System system) const noexcept {
    return "{ \"value\": " + PhQ::number_to_string(convert(system)) + ", \"unit\": " + PhQ::abbreviation(PhQ::unit<Unit>(system)) + "}";
  }

  std::string json(Unit unit) const noexcept {
    return "{ \"value\": " + PhQ::number_to_string(convert(unit)) + ", \"unit\": " + PhQ::abbreviation(unit) + "}";
  }

  std::string xml(System system) const noexcept {
    return "<value>" + PhQ::number_to_string(convert(system)) + "</value><unit>" + PhQ::abbreviation(PhQ::unit<Unit>(system)) + "</unit>";
  }

  std::string xml(Unit unit) const noexcept {
    return "<value>" + PhQ::number_to_string(convert(unit)) + "</value><unit>" + PhQ::abbreviation(unit) + "</unit>";
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

  DimensionalCartesianVectorQuantity<Unit> operator*(const CartesianDirection& cartesian_direction) const noexcept;

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
      throw std::runtime_error{"Division of " + print(standard_unit<Unit>) + " by 0."};
    }
  }

  double operator/(const DimensionlessScalarQuantity& scalar) const {
    if (scalar != 0.0) {
      return {value_ / scalar.value()};
    } else {
      throw std::runtime_error{"Division of " + print(standard_unit<Unit>) + " by " + scalar.print(standard_unit<Unit>) + "."};
    }
  }

  double operator/(const DimensionalScalarQuantity<Unit>& scalar) const {
    if (scalar != 0.0) {
      return {value_ / scalar.value()};
    } else {
      throw std::runtime_error{"Division of " + print(standard_unit<Unit>) + " by " + scalar.print(standard_unit<Unit>) + "."};
    }
  }

  void operator/=(double real) {
    if (real != 0.0) {
      value_ /= real;
    } else {
      throw std::runtime_error{"Division of " + print(standard_unit<Unit>) + " by 0."};
    }
  }

protected:

  constexpr DimensionalScalarQuantity(double value) noexcept : DimensionalQuantity<Unit>(), value_(value) {}

  double value_;

  friend class DimensionalCartesianVectorQuantity<Unit>;

};

template <typename Unit> constexpr DimensionalCartesianVectorQuantity<Unit> CartesianDirection::operator*(const DimensionalScalarQuantity<Unit>& scalar) const noexcept {
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
  output_stream << scalar.print(PhQ::standard_system);
  return output_stream;
}
