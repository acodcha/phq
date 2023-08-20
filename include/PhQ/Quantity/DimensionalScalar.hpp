// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_SCALAR_HPP

#include "../Base/String.hpp"
#include "Dimensional.hpp"

namespace PhQ {

// Abstract base class that represents any dimensional scalar physical quantity.
// Such a physical quantity is composed of a value and a unit of measure where
// the value is a scalar number.
template<typename U> class DimensionalScalarQuantity
  : public DimensionalQuantity<U> {
public:
  inline constexpr double Value() const noexcept { return value_; }

  inline double Value(const U unit) const noexcept {
    double result{value_};
    Convert(result, Standard<U>, unit);
    return result;
  }

  template<U NewUnit> inline constexpr double StaticValue() const noexcept {
    return StaticConvertCopy<U, Standard<U>, NewUnit>(value_);
  }

  inline constexpr double& MutableValue() noexcept { return value_; }

  inline constexpr void SetValue(const double value) noexcept {
    value_ = value;
  }

  std::string Print() const noexcept override {
    return PhQ::Print(value_).append(" ").append(Abbreviation(Standard<U>));
  }

  std::string Print(const Precision precision) const noexcept override {
    return PhQ::Print(value_, precision)
        .append(" ")
        .append(Abbreviation(Standard<U>));
  }

  std::string Print(const U unit) const noexcept override {
    return PhQ::Print(Value(unit)).append(" ").append(Abbreviation(unit));
  }

  std::string Print(
      const U unit, const Precision precision) const noexcept override {
    return PhQ::Print(Value(unit), precision)
        .append(" ")
        .append(Abbreviation(unit));
  }

  std::string JSON() const noexcept override {
    return std::string{"{\"value\":"}
        .append(PhQ::Print(value_))
        .append(",\"unit\":\"")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  std::string JSON(const U unit) const noexcept override {
    return std::string{"{\"value\":"}
        .append(PhQ::Print(Value(unit)))
        .append(",\"unit\":\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

  std::string XML() const noexcept override {
    return std::string{"<value>"}
        .append(PhQ::Print(value_))
        .append("</value><unit>")
        .append(Abbreviation(Standard<U>))
        .append("</unit>");
  }

  std::string XML(const U unit) const noexcept override {
    return std::string{"<value>"}
        .append(PhQ::Print(Value(unit)))
        .append("</value><unit>")
        .append(Abbreviation(unit))
        .append("</unit>");
  }

  std::string YAML() const noexcept override {
    return std::string{"{value:"}
        .append(PhQ::Print(value_))
        .append(",unit:\"")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  std::string YAML(const U unit) const noexcept override {
    return std::string{"{value:"}
        .append(PhQ::Print(Value(unit)))
        .append(",unit:\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

protected:
  constexpr DimensionalScalarQuantity() noexcept
    : DimensionalQuantity<U>(), value_() {}

  constexpr DimensionalScalarQuantity(const double value) noexcept
    : DimensionalQuantity<U>(), value_(value) {}

  DimensionalScalarQuantity(const double value, const U unit) noexcept
    : DimensionalQuantity<U>(), value_(value) {
    Convert(value_, unit, Standard<U>);
  }

  ~DimensionalScalarQuantity() noexcept = default;

  constexpr void operator=(const double value) noexcept { value_ = value; }

  double value_;
};

}  // namespace PhQ

namespace std {

template<typename U> struct hash<PhQ::DimensionalScalarQuantity<U>> {
  size_t operator()(const PhQ::DimensionalScalarQuantity<U>& quantity) const {
    return hash<double>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_SCALAR_HPP
