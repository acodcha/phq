#pragma once

#include "../../../Vector.hpp"
#include "../Base.hpp"

namespace PhQ {

template <typename Unit> class DimensionalCartesianVectorQuantity : public DimensionalQuantity<Unit> {

public:

  constexpr DimensionalCartesianVectorQuantity() noexcept : DimensionalQuantity<Unit>() {}

  constexpr DimensionalCartesianVectorQuantity(const PhQ::Value::CartesianVector& value, Unit unit) noexcept : DimensionalQuantity<Unit>(), value_(PhQ::Unit::convert(value, unit, this->unit())) {}

  constexpr PhQ::Value::CartesianVector value() const noexcept {
    return value_;
  }

  constexpr PhQ::Value::CartesianVector convert(const System system) const noexcept {
    return PhQ::Unit::convert(value_, this->unit(), system);
  }

  constexpr PhQ::Value::CartesianVector convert(const Unit unit) const noexcept {
    return PhQ::Unit::convert(value_, this->unit(), unit);
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

  constexpr bool operator==(const DimensionalCartesianVectorQuantity<Unit>& other) const noexcept {
    return value_ == other.value_;
  }

  constexpr bool operator!=(const DimensionalCartesianVectorQuantity<Unit>& other) const noexcept {
    return value_ != other.value_;
  }

  DimensionalCartesianVectorQuantity<Unit> operator+(const DimensionalCartesianVectorQuantity<Unit>& other) const noexcept {
    return {value_ + other.value_};
  }

  void operator+=(const DimensionalCartesianVectorQuantity<Unit>& other) noexcept {
    value_ += other.value_;
  }

  DimensionalCartesianVectorQuantity<Unit> operator-(const DimensionalCartesianVectorQuantity<Unit>& other) const noexcept {
    return {value_ - other.value_};
  }

  void operator-=(const DimensionalCartesianVectorQuantity<Unit>& other) noexcept {
    value_ -= other.value_;
  }

  DimensionalCartesianVectorQuantity<Unit> operator*(double number) const noexcept {
    return {value_ * number};
  }

  void operator*=(double number) noexcept {
    value_ *= number;
  }

  DimensionalCartesianVectorQuantity<Unit> operator/(double number) const {
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

  constexpr DimensionalCartesianVectorQuantity(const PhQ::Value::CartesianVector& value) noexcept : DimensionalQuantity<Unit>(), value_(value) {}

  PhQ::Value::CartesianVector value_;

};

} // namespace PhQ
