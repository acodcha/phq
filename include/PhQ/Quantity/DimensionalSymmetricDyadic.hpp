// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Value/SymmetricDyadic.hpp"
#include "DimensionalVector.hpp"
#include "DimensionlessSymmetricDyadic.hpp"

namespace PhQ {

template <typename Unit> class DimensionalSymmetricDyadicQuantity : public DimensionalQuantity<Unit> {

public:

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

  std::string yaml() const noexcept {
    return "{value: " + value_.yaml() + ", unit: " + abbreviation(standard_unit<Unit>) + "}";
  }

  std::string yaml(Unit unit) const noexcept {
    return "{value: " + value(unit).yaml() + ", unit: " + abbreviation(unit) + "}";
  }

  std::string yaml(System system) const noexcept {
    return "{value: " + value(system).yaml() + ", unit: " + abbreviation(unit<Unit>(system)) + "}";
  }

  std::string json() const noexcept {
    return "{\"value\": " + value_.json() + ", \"unit\": \"" + abbreviation(standard_unit<Unit>) + "\"}";
  }

  std::string json(Unit unit) const noexcept {
    return "{\"value\": " + value(unit).json() + ", \"unit\": \"" + abbreviation(unit) + "\"}";
  }

  std::string json(System system) const noexcept {
    return "{\"value\": " + value(system).json() + ", \"unit\": \"" + abbreviation(unit<Unit>(system)) + "\"}";
  }

  std::string xml() const noexcept {
    return "<value>" + value_.xml() + "</value><unit>" + abbreviation(standard_unit<Unit>) + "</unit>";
  }

  std::string xml(Unit unit) const noexcept {
    return "<value>" + value(unit).xml() + "</value><unit>" + abbreviation(unit) + "</unit>";
  }

  std::string xml(System system) const noexcept {
    return "<value>" + value(system).xml() + "</value><unit>" + abbreviation(unit<Unit>(system)) + "</unit>";
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

  constexpr DimensionalSymmetricDyadicQuantity<Unit> operator/(double real) const noexcept {
    return {value_ / real};
  }

  constexpr DimensionalSymmetricDyadicQuantity<Unit> operator/(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ / scalar.value()};
  }

  constexpr void operator/=(double real) noexcept {
    value_ /= real;
  }

  constexpr void operator/=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ /= scalar.value();
  }

protected:

  constexpr DimensionalSymmetricDyadicQuantity() noexcept : DimensionalQuantity<Unit>(), value_() {}

  constexpr DimensionalSymmetricDyadicQuantity(const Value::SymmetricDyadic& value) noexcept : DimensionalQuantity<Unit>(), value_(value) {}

  constexpr DimensionalSymmetricDyadicQuantity(const Value::SymmetricDyadic& value, Unit unit) noexcept : DimensionalQuantity<Unit>(), value_(convert(value, unit, standard_unit<Unit>)) {}

  Value::SymmetricDyadic value_;

};

template <typename Unit> constexpr DimensionalSymmetricDyadicQuantity<Unit> DimensionlessScalarQuantity::operator*(const DimensionalSymmetricDyadicQuantity<Unit>& dimensional_symmetric_dyadic) noexcept {
  return {dimensional_symmetric_dyadic * value_};
}

} // namespace PhQ

template <typename Unit> constexpr PhQ::DimensionalSymmetricDyadicQuantity<Unit> operator*(double real, const PhQ::DimensionalSymmetricDyadicQuantity<Unit>& symmetric_dyadic) noexcept {
  return {symmetric_dyadic * real};
}

template <typename Unit> std::ostream& operator<<(std::ostream& output_stream, const PhQ::DimensionalSymmetricDyadicQuantity<Unit>& symmetric_dyadic) noexcept {
  output_stream << symmetric_dyadic.print();
  return output_stream;
}

namespace std {

template <typename Unit> struct hash<PhQ::DimensionalSymmetricDyadicQuantity<Unit>> {
  size_t operator()(const PhQ::DimensionalSymmetricDyadicQuantity<Unit>& quantity) const {
    return hash<PhQ::Value::SymmetricDyadic>()(quantity.value());
  }
};

} // namespace std
