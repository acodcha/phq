#pragma once

#include "../../../Direction.hpp"
#include "../Base.hpp"

namespace PhQ {

// Forward declaration.
template <typename Unit> class DimensionalCartesianVectorQuantity;

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

  constexpr bool operator==(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) const noexcept {
    return value_ == dimensional_scalar_quantity.value_;
  }

  constexpr bool operator!=(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) const noexcept {
    return value_ != dimensional_scalar_quantity.value_;
  }

  constexpr bool operator<(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) const noexcept {
    return value_ < dimensional_scalar_quantity.value_;
  }

  constexpr bool operator<=(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) const noexcept {
    return value_ <= dimensional_scalar_quantity.value_;
  }

  constexpr bool operator>(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) const noexcept {
    return value_ > dimensional_scalar_quantity.value_;
  }

  constexpr bool operator>=(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) const noexcept {
    return value_ >= dimensional_scalar_quantity.value_;
  }

  DimensionalScalarQuantity<Unit> operator+(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) const noexcept {
    return {value_ + dimensional_scalar_quantity.value_};
  }

  void operator+=(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) noexcept {
    value_ += dimensional_scalar_quantity.value_;
  }

  DimensionalScalarQuantity<Unit> operator-(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) const noexcept {
    return {value_ - dimensional_scalar_quantity.value_};
  }

  void operator-=(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) noexcept {
    value_ -= dimensional_scalar_quantity.value_;
  }

  DimensionalScalarQuantity<Unit> operator*(double number) const noexcept {
    return {value_ * number};
  }

  DimensionalCartesianVectorQuantity<Unit> operator*(const CartesianDirection& cartesian_direction) const noexcept {
    return {*this, cartesian_direction};
  }

  void operator*=(double number) noexcept {
    value_ *= number;
  }

  DimensionalScalarQuantity<Unit> operator/(double number) const {
    return PhQ::division<DimensionalScalarQuantity<Unit>, DimensionalScalarQuantity<Unit>>(*this, number);
  }

  double operator/(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) const {
    return PhQ::division<DimensionalScalarQuantity<Unit>, DimensionalScalarQuantity<Unit>, double>(*this, dimensional_scalar_quantity);
  }

  void operator/=(double number) noexcept {
    if (number != 0.0) {
      value_ /= number;
    } else {
      throw std::runtime_error{"Division of a " + this->name() + " by a zero scalar."};
    }
  }

protected:

  constexpr DimensionalScalarQuantity(double value) noexcept : DimensionalQuantity<Unit>(), value_(value) {}

  double value_;

  friend class DimensionalCartesianVectorQuantity<Unit>;

};

template <typename Unit> constexpr DimensionalCartesianVectorQuantity<Unit> CartesianDirection::operator*(const DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) const noexcept {
  return {dimensional_scalar_quantity, *this};
}

} // namespace PhQ

namespace std {

template <typename Unit> double cbrt(const PhQ::DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) {
  return cbrt(dimensional_scalar_quantity.value());
};

template <typename Unit> double exp(const PhQ::DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) {
  return exp(dimensional_scalar_quantity.value());
};

template <typename Unit> double log(const PhQ::DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) {
  return log(dimensional_scalar_quantity.value());
};

template <typename Unit> double log10(const PhQ::DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) {
  return log10(dimensional_scalar_quantity.value());
};

template <typename Unit> double pow(const PhQ::DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity, int_least64_t exponent) {
  return pow(dimensional_scalar_quantity.value(), exponent);
};

template <typename Unit> double pow(const PhQ::DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity, double exponent) {
  return pow(dimensional_scalar_quantity.value(), exponent);
};

template <typename Unit> double sqrt(const PhQ::DimensionalScalarQuantity<Unit>& dimensional_scalar_quantity) {
  return sqrt(dimensional_scalar_quantity.value());
};

} // namespace std
