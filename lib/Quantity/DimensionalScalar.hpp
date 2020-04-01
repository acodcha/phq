#pragma once

#include "../Direction.hpp"
#include "Dimensional.hpp"
#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declarations.
template <typename Unit> class DimensionalVectorQuantity;
template <typename Unit> class DimensionalSymmetricDyadicQuantity;
template <typename Unit> class DimensionalDyadicQuantity;

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

  constexpr DimensionalScalarQuantity<Unit> operator*(double real) const noexcept {
    return {value_ * real};
  }

  constexpr DimensionalScalarQuantity<Unit> operator*(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ * scalar.value()};
  }

  DimensionalVectorQuantity<Unit> operator*(const Direction& direction) const noexcept;

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  constexpr void operator*=(const DimensionlessScalarQuantity& scalar) noexcept {
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
  friend class DimensionalSymmetricDyadicQuantity<Unit>;

};

} // namespace PhQ

template <typename Unit> constexpr PhQ::DimensionalVectorQuantity<Unit> operator*(const PhQ::DimensionalScalarQuantity<Unit>& scalar, const PhQ::Direction& direction) noexcept {
  return {scalar, direction};
}

template <typename Unit> constexpr PhQ::DimensionalScalarQuantity<Unit> operator*(double real, const PhQ::DimensionalScalarQuantity<Unit>& scalar) noexcept {
  return {scalar * real};
}

template <typename Unit> constexpr PhQ::DimensionalScalarQuantity<Unit> operator*(const PhQ::DimensionlessScalarQuantity& dimensionless, const PhQ::DimensionalScalarQuantity<Unit>& dimensional) noexcept {
  return {dimensional * dimensionless.value()};
}

template <typename Unit> std::ostream& operator<<(std::ostream& output_stream, const PhQ::DimensionalScalarQuantity<Unit>& scalar) noexcept {
  output_stream << scalar.print();
  return output_stream;
}
