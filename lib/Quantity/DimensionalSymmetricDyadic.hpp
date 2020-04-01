#pragma once

#include "../Value/SymmetricDyadic.hpp"
#include "DimensionalVector.hpp"
#include "DimensionlessSymmetricDyadic.hpp"

namespace PhQ {

template <typename Unit> class DimensionalSymmetricDyadicQuantity : public DimensionalQuantity<Unit> {

public:

  constexpr DimensionalSymmetricDyadicQuantity() noexcept : DimensionalQuantity<Unit>() {}

  constexpr DimensionalSymmetricDyadicQuantity(const Value::SymmetricDyadic& value, Unit unit) noexcept : DimensionalQuantity<Unit>(), value_(convert(value, unit, standard_unit<Unit>)) {}

  constexpr const Value::SymmetricDyadic& value() const noexcept {
    return value_;
  }

  Value::SymmetricDyadic value(const Unit unit) const noexcept {
    if (unit == standard_unit<Unit>) {
      return value_;
    } else {
      return convert(value_, standard_unit<Unit>, unit);
    }
  }

  Value::SymmetricDyadic value(const System system) const noexcept {
    if (system == standard_system) {
      return value_;
    } else {
      return convert(value_, standard_unit<Unit>, system);
    }
  }

  std::string print() const noexcept {
    return value_.print() + " " + abbreviation(standard_unit<Unit>);
  }

  std::string print(Unit unit) const noexcept {
    return value(unit).print() + " " + abbreviation(unit);
  }

  std::string print(System system) const noexcept {
    return value(system).print() + " " + abbreviation(unit<Unit>(system));
  }

  std::string json() const noexcept {
    return "{ \"value\": " + value_.print() + ", \"unit\": " + abbreviation(standard_unit<Unit>) + "}";
  }

  std::string json(Unit unit) const noexcept {
    return "{ \"value\": " + value(unit).print() + ", \"unit\": " + abbreviation(unit) + "}";
  }

  std::string json(System system) const noexcept {
    return "{ \"value\": " + value(system).print() + ", \"unit\": " + abbreviation(unit<Unit>(system)) + "}";
  }

  std::string xml() const noexcept {
    return "<value>" + value_.print() + "</value><unit>" + abbreviation(standard_unit<Unit>) + "</unit>";
  }

  std::string xml(Unit unit) const noexcept {
    return "<value>" + value(unit).print() + "</value><unit>" + abbreviation(unit) + "</unit>";
  }

  std::string xml(System system) const noexcept {
    return "<value>" + value(system).print() + "</value><unit>" + abbreviation(unit<Unit>(system)) + "</unit>";
  }

  constexpr DimensionalSymmetricDyadicQuantity<Unit> operator*(double real) const noexcept {
    return {value_ * real};
  }

  constexpr DimensionalSymmetricDyadicQuantity<Unit> operator*(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ * scalar.value()};
  }

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  constexpr void operator*=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ *= scalar.value();
  }

  DimensionalSymmetricDyadicQuantity<Unit> operator/(double real) const {
    if (real != 0.0) {
      return {value_ / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  DimensionalSymmetricDyadicQuantity<Unit> operator/(const DimensionlessScalarQuantity& scalar) const {
    if (scalar.value() != 0.0) {
      return {value_ / scalar.value()};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

  Value::SymmetricDyadic operator/(const DimensionalScalarQuantity<Unit>& scalar) const {
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

  constexpr DimensionalSymmetricDyadicQuantity(const Value::SymmetricDyadic& value) noexcept : DimensionalQuantity<Unit>(), value_(value) {}

  Value::SymmetricDyadic value_;

  friend class DimensionalScalarQuantity<Unit>;
  friend class DimensionalVectorQuantity<Unit>;

};

} // namespace PhQ

template <typename Unit> constexpr PhQ::DimensionalSymmetricDyadicQuantity<Unit> operator*(double real, const PhQ::DimensionalSymmetricDyadicQuantity<Unit>& dyadic) noexcept {
  return {dyadic * real};
}

template <typename Unit> constexpr PhQ::DimensionalSymmetricDyadicQuantity<Unit> operator*(const PhQ::DimensionlessScalarQuantity& scalar, const PhQ::DimensionalSymmetricDyadicQuantity<Unit>& dyadic) noexcept {
  return {dyadic * scalar.value()};
}

template <typename Unit> std::ostream& operator<<(std::ostream& output_stream, const PhQ::DimensionalSymmetricDyadicQuantity<Unit>& dyadic) noexcept {
  output_stream << dyadic.print();
  return output_stream;
}
