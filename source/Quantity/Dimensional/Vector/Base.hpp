#pragma once

#include "../../../Vector.hpp"
#include "../Scalar/Base.hpp"

namespace PhQ {

template <typename Unit> class DimensionalCartesianVectorQuantity : public DimensionalQuantity<Unit> {

public:

  constexpr DimensionalCartesianVectorQuantity() noexcept : DimensionalQuantity<Unit>() {}

  constexpr DimensionalCartesianVectorQuantity(const PhQ::Value::CartesianVector& vector, Unit unit) noexcept : DimensionalQuantity<Unit>(), value_(PhQ::Unit::convert(vector, unit, this->unit())) {}

  constexpr DimensionalCartesianVectorQuantity(DimensionalScalarQuantity<Unit> scalar, const PhQ::CartesianDirection& direction) noexcept : DimensionalQuantity<Unit>(), value_(direction * scalar.value_) {}

  constexpr PhQ::Value::CartesianVector value() const noexcept {
    return value_;
  }

  constexpr PhQ::Value::CartesianVector convert(const System system) const noexcept {
    return PhQ::Unit::convert(value_, this->unit(), system);
  }

  constexpr PhQ::Value::CartesianVector convert(const Unit unit) const noexcept {
    return PhQ::Unit::convert(value_, this->unit(), unit);
  }

  constexpr CartesianDirection direction() const {
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

  void operator+=(const DimensionalCartesianVectorQuantity<Unit>& vector) noexcept {
    value_ += vector.value_;
  }

  DimensionalCartesianVectorQuantity<Unit> operator-(const DimensionalCartesianVectorQuantity<Unit>& vector) const noexcept {
    return {value_ - vector.value_};
  }

  void operator-=(const DimensionalCartesianVectorQuantity<Unit>& vector) noexcept {
    value_ -= vector.value_;
  }

  DimensionalCartesianVectorQuantity<Unit> operator*(double real) const noexcept {
    return {value_ * real};
  }

  void operator*=(double real) noexcept {
    value_ *= real;
  }

  DimensionalCartesianVectorQuantity<Unit> operator/(double real) const {
    return PhQ::division<DimensionalCartesianVectorQuantity<Unit>, DimensionalCartesianVectorQuantity<Unit>>(*this, real);
  }

  PhQ::Value::CartesianVector operator/(const DimensionalScalarQuantity<Unit>& scalar) const {
    return PhQ::division<DimensionalCartesianVectorQuantity<Unit>, DimensionalScalarQuantity<Unit>, PhQ::Value::CartesianVector>(*this, scalar);
  }

  void operator/=(double real) noexcept {
    if (real != 0.0) {
      value_ /= real;
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

protected:

  constexpr DimensionalCartesianVectorQuantity(const PhQ::Value::CartesianVector& vector) noexcept : DimensionalQuantity<Unit>(), value_(vector) {}

  PhQ::Value::CartesianVector value_;

  friend class DimensionalScalarQuantity<Unit>;

};

} // namespace PhQ
