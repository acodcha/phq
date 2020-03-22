#pragma once

#include "../../../Value/Vector.hpp"
#include "../Scalar/Base.hpp"

namespace PhQ {

template <typename Unit> class DimensionalCartesianVectorQuantity : public DimensionalQuantity<Unit> {

public:

  constexpr DimensionalCartesianVectorQuantity() noexcept : DimensionalQuantity<Unit>() {}

  constexpr DimensionalCartesianVectorQuantity(const Value::CartesianVector& vector, Unit unit) noexcept : DimensionalQuantity<Unit>(), value_(convert(vector, unit, standard_unit<Unit>)) {}

  constexpr DimensionalCartesianVectorQuantity(DimensionalScalarQuantity<Unit> scalar, const CartesianDirection& direction) noexcept : DimensionalQuantity<Unit>(), value_(direction * scalar.value_) {}

  const Value::CartesianVector& value() const noexcept {
    return value_;
  }

  Value::CartesianVector value(const Unit unit) const noexcept {
    if (unit == standard_unit<Unit>) {
      return value_;
    } else {
      return convert(value_, standard_unit<Unit>, unit);
    }
  }

  Value::CartesianVector value(const System system) const noexcept {
    if (system == standard_system) {
      return value_;
    } else {
      return convert(value_, standard_unit<Unit>, system);
    }
  }

  CartesianDirection direction() const {
    return {value_};
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

  constexpr bool operator==(const DimensionalCartesianVectorQuantity<Unit>& vector) const noexcept {
    return value_ == vector.value_;
  }

  constexpr bool operator!=(const DimensionalCartesianVectorQuantity<Unit>& vector) const noexcept {
    return value_ != vector.value_;
  }

  DimensionalCartesianVectorQuantity<Unit> operator+(const DimensionalCartesianVectorQuantity<Unit>& vector) const noexcept {
    return {value_ + vector.value_};
  }

  constexpr void operator+=(const DimensionalCartesianVectorQuantity<Unit>& vector) noexcept {
    value_ += vector.value_;
  }

  DimensionalCartesianVectorQuantity<Unit> operator-(const DimensionalCartesianVectorQuantity<Unit>& vector) const noexcept {
    return {value_ - vector.value_};
  }

  constexpr void operator-=(const DimensionalCartesianVectorQuantity<Unit>& vector) noexcept {
    value_ -= vector.value_;
  }

  DimensionalCartesianVectorQuantity<Unit> operator*(double real) const noexcept {
    return {value_ * real};
  }

  DimensionalCartesianVectorQuantity<Unit> operator*(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ * scalar.value()};
  }

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  DimensionalCartesianVectorQuantity<Unit> operator/(double real) const {
    if (real != 0.0) {
      return {value_ / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  DimensionalCartesianVectorQuantity<Unit> operator/(const DimensionlessScalarQuantity& scalar) const {
    if (scalar.value() != 0.0) {
      return {value_ / scalar.value()};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

  Value::CartesianVector operator/(const DimensionalScalarQuantity<Unit>& scalar) const {
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

  constexpr DimensionalCartesianVectorQuantity(const Value::CartesianVector& vector) noexcept : DimensionalQuantity<Unit>(), value_(vector) {}

  Value::CartesianVector value_;

  friend class DimensionalScalarQuantity<Unit>;

};

template <typename Unit> DimensionalCartesianVectorQuantity<Unit> DimensionalScalarQuantity<Unit>::operator*(const CartesianDirection& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ

template <typename Unit> std::ostream& operator<<(std::ostream& output_stream, const PhQ::DimensionalCartesianVectorQuantity<Unit>& vector) noexcept {
  output_stream << vector.print();
  return output_stream;
}
