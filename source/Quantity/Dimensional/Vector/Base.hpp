#pragma once

#include "../../../Value/Vector.hpp"
#include "../Scalar/Base.hpp"

namespace PhQ {

template <typename Unit> class DimensionalCartesianVectorQuantity : public DimensionalQuantity<Unit> {

public:

  constexpr DimensionalCartesianVectorQuantity() noexcept : DimensionalQuantity<Unit>() {}

  constexpr DimensionalCartesianVectorQuantity(const PhQ::Value::CartesianVector& vector, Unit unit) noexcept : DimensionalQuantity<Unit>(), value_(PhQ::Unit::convert(vector, unit, this->unit())) {}

  constexpr DimensionalCartesianVectorQuantity(DimensionalScalarQuantity<Unit> scalar, const PhQ::CartesianDirection& direction) noexcept : DimensionalQuantity<Unit>(), value_(direction * scalar.value_) {}

  PhQ::Value::CartesianVector value() const noexcept {
    return value_;
  }

  PhQ::Value::CartesianVector convert(const System system) const noexcept {
    return PhQ::Unit::convert(value_, this->unit(), system);
  }

  PhQ::Value::CartesianVector convert(const Unit unit) const noexcept {
    return PhQ::Unit::convert(value_, this->unit(), unit);
  }

  CartesianDirection direction() const {
    return {*this};
  }

  std::string print(System system) const noexcept {
    return convert(system).print() + " " + PhQ::Unit::abbreviation(PhQ::unit<Unit>(system));
  }

  std::string print(Unit unit) const noexcept {
    return convert(unit).print() + " " + PhQ::Unit::abbreviation(unit);
  }

  std::string json(System system) const noexcept {
    return "{ \"value\": " + convert(system).print() + ", \"unit\": " + PhQ::Unit::abbreviation(PhQ::unit<Unit>(system)) + "}";
  }

  std::string json(Unit unit) const noexcept {
    return "{ \"value\": " + convert(unit).print() + ", \"unit\": " + PhQ::Unit::abbreviation(unit) + "}";
  }

  std::string xml(System system) const noexcept {
    return "<value>" + convert(system).print() + "</value><unit>" + PhQ::Unit::abbreviation(PhQ::unit<Unit>(system)) + "</unit>";
  }

  std::string xml(Unit unit) const noexcept {
    return "<value>" + convert(unit).print() + "</value><unit>" + PhQ::Unit::abbreviation(unit) + "</unit>";
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

  PhQ::Value::CartesianVector operator/(const DimensionalScalarQuantity<Unit>& scalar) const {
    if (scalar.value() != 0.0) {
      return {value_ / scalar.value()};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

  constexpr void operator/=(double real) noexcept {
    if (real != 0.0) {
      value_ /= real;
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  constexpr void operator/=(const DimensionlessScalarQuantity& scalar) noexcept {
    if (scalar.value() != 0.0) {
      value_ /= scalar.value();
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

protected:

  constexpr DimensionalCartesianVectorQuantity(const PhQ::Value::CartesianVector& vector) noexcept : DimensionalQuantity<Unit>(), value_(vector) {}

  PhQ::Value::CartesianVector value_;

  friend class DimensionalScalarQuantity<Unit>;

};

template <typename Unit> DimensionalCartesianVectorQuantity<Unit> DimensionalScalarQuantity<Unit>::operator*(const CartesianDirection& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ

template <typename Unit> std::ostream& operator<<(std::ostream& output_stream, const PhQ::DimensionalCartesianVectorQuantity<Unit>& vector) noexcept {
  output_stream << vector.print(PhQ::standard);
  return output_stream;
}
