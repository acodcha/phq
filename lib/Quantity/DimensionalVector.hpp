// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Value/Vector.hpp"
#include "DimensionalScalar.hpp"

namespace PhQ {

template <typename Unit> class DimensionalVectorQuantity : public DimensionalQuantity<Unit> {

public:

  constexpr DimensionalVectorQuantity() noexcept : DimensionalQuantity<Unit>() {}

  constexpr DimensionalVectorQuantity(const Value::Vector& value, Unit unit) noexcept : DimensionalQuantity<Unit>(), value_(convert(value, unit, standard_unit<Unit>)) {}

  constexpr DimensionalVectorQuantity(DimensionalScalarQuantity<Unit> scalar, const Direction& direction) noexcept : DimensionalQuantity<Unit>(), value_(direction * scalar.value_) {}

  const Value::Vector& value() const noexcept {
    return value_;
  }

  Value::Vector value(const Unit unit) const noexcept {
    if (unit == standard_unit<Unit>) {
      return value_;
    } else {
      return convert(value_, standard_unit<Unit>, unit);
    }
  }

  Value::Vector value(const System system) const noexcept {
    if (system == standard_system) {
      return value_;
    } else {
      return convert(value_, standard_unit<Unit>, system);
    }
  }

  constexpr Direction direction() const {
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

  constexpr DimensionalVectorQuantity<Unit> operator*(double real) const noexcept {
    return {value_ * real};
  }

  constexpr DimensionalVectorQuantity<Unit> operator*(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ * scalar.value()};
  }

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  constexpr void operator*=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ *= scalar.value();
  }

  DimensionalVectorQuantity<Unit> operator/(double real) const {
    if (real != 0.0) {
      return {value_ / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  DimensionalVectorQuantity<Unit> operator/(const DimensionlessScalarQuantity& scalar) const {
    if (scalar.value() != 0.0) {
      return {value_ / scalar.value()};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

  Value::Vector operator/(const DimensionalScalarQuantity<Unit>& scalar) const {
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

  constexpr DimensionalVectorQuantity(const Value::Vector& value) noexcept : DimensionalQuantity<Unit>(), value_(value) {}

  Value::Vector value_;

  friend class DimensionalScalarQuantity<Unit>;
  friend class DimensionalSymmetricDyadicQuantity<Unit>;

};

template <typename Unit> constexpr DimensionalVectorQuantity<Unit> Direction::operator*(const DimensionalScalarQuantity<Unit>& scalar) const noexcept {
  return {scalar, *this};
}

template <typename Unit> DimensionalVectorQuantity<Unit> DimensionalScalarQuantity<Unit>::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ

template <typename Unit> constexpr PhQ::DimensionalVectorQuantity<Unit> operator*(double real, const PhQ::DimensionalVectorQuantity<Unit>& vector) noexcept {
  return {vector * real};
}

template <typename Unit> constexpr PhQ::DimensionalVectorQuantity<Unit> operator*(const PhQ::DimensionlessScalarQuantity& scalar, const PhQ::DimensionalVectorQuantity<Unit>& vector) noexcept {
  return {vector * scalar.value()};
}

template <typename Unit> std::ostream& operator<<(std::ostream& output_stream, const PhQ::DimensionalVectorQuantity<Unit>& vector) noexcept {
  output_stream << vector.print();
  return output_stream;
}
