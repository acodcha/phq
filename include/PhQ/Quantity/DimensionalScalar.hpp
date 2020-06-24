// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Dimensional.hpp"
#include "DimensionlessScalar.hpp"

namespace PhQ {

template <typename Unit> class DimensionalScalarQuantity : public DimensionalQuantity<Unit> {

public:

  constexpr double value() const noexcept {
    return value_;
  }

  double value(const Unit unit) const noexcept {
    if (unit == standard_unit<Unit>) {
      return value_;
    } else {
      return convert(value_, standard_unit<Unit>, unit);
    }
  }

  double value(const System system) const noexcept {
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

  std::string yaml() const noexcept {
    return "{value: " + number_to_string(value_) + " , unit: " + abbreviation(standard_unit<Unit>) + "}";
  }

  std::string yaml(Unit unit) const noexcept {
    return "{value: " + number_to_string(value(unit)) + " , unit: " + abbreviation(unit) + "}";
  }

  std::string yaml(System system) const noexcept {
    return "{value: " + number_to_string(value(system)) + " , unit: " + abbreviation(unit<Unit>(system)) + "}";
  }

  std::string json() const noexcept {
    return "{\"value\": " + number_to_string(value_) + " , \"unit\": \"" + abbreviation(standard_unit<Unit>) + "\"}";
  }

  std::string json(Unit unit) const noexcept {
    return "{\"value\": " + number_to_string(value(unit)) + " , \"unit\": \"" + abbreviation(unit) + "\"}";
  }

  std::string json(System system) const noexcept {
    return "{\"value\": " + number_to_string(value(system)) + " , \"unit\": \"" + abbreviation(unit<Unit>(system)) + "\"}";
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

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  constexpr void operator*=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ *= scalar.value();
  }

  constexpr DimensionalScalarQuantity<Unit> operator/(double real) const noexcept {
    return {value_ / real};
  }

  constexpr double operator/(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ / scalar.value()};
  }

  constexpr void operator/=(double real) noexcept {
    value_ /= real;
  }

  constexpr void operator/=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ /= scalar.value();
  }

protected:

  constexpr DimensionalScalarQuantity() noexcept : DimensionalQuantity<Unit>(), value_() {}

  constexpr DimensionalScalarQuantity(double value) noexcept : DimensionalQuantity<Unit>(), value_(value) {}

  constexpr DimensionalScalarQuantity(double value, Unit unit) noexcept : DimensionalQuantity<Unit>(), value_(convert(value, unit, standard_unit<Unit>)) {}

  double value_;

};

template <typename Unit> constexpr DimensionalScalarQuantity<Unit> DimensionlessScalarQuantity::operator*(const DimensionalScalarQuantity<Unit>& dimensional_scalar) noexcept {
  return {dimensional_scalar * value_};
}

} // namespace PhQ

template <typename Unit> constexpr PhQ::DimensionalScalarQuantity<Unit> operator*(double real, const PhQ::DimensionalScalarQuantity<Unit>& scalar) noexcept {
  return {scalar * real};
}

template <typename Unit> std::ostream& operator<<(std::ostream& output_stream, const PhQ::DimensionalScalarQuantity<Unit>& scalar) noexcept {
  output_stream << scalar.print();
  return output_stream;
}
