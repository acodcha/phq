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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_DYAD_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_DYAD_HPP

#include <utility>

#include "../Value/Dyad.hpp"
#include "Dimensional.hpp"

namespace PhQ {

// Abstract base class that represents any dimensional dyadic tensor physical
// quantity. Such a physical quantity is composed of a value and a unit of
// measure where the value is a tensor of rank two and dimension three. The
// tensor may be non-symmetric.
template<typename U> class DimensionalDyadQuantity
  : public DimensionalQuantity<U> {
public:
  inline constexpr const Value::Dyad& Value() const noexcept { return value_; }

  inline Value::Dyad Value(const U unit) const noexcept {
    Value::Dyad result{value_};
    Convert(result, StandardUnit<U>, unit);
    return result;
  }

  template<U NewUnit>
  inline constexpr Value::Dyad StaticValue() const noexcept {
    return StaticConvertCopy<U, StandardUnit<U>, NewUnit>(value_);
  }

  inline constexpr Value::Dyad& MutableValue() noexcept { return value_; }

  inline constexpr void SetValue(const Value::Dyad& value) noexcept {
    value_ = value;
  }

  std::string Print() const noexcept override {
    return value_.Print().append(" ").append(Abbreviation(StandardUnit<U>));
  }

  std::string Print(const U unit) const noexcept override {
    return Value(unit).Print().append(" ").append(Abbreviation(unit));
  }

  std::string JSON() const noexcept override {
    return std::string{"{\"value\":"}
        .append(value_.JSON())
        .append(",\"unit\":\"")
        .append(Abbreviation(StandardUnit<U>))
        .append("\"}");
  }

  std::string JSON(const U unit) const noexcept override {
    return std::string{"{\"value\":"}
        .append(Value(unit).JSON())
        .append(",\"unit\":\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

  std::string XML() const noexcept override {
    return std::string{"<value>"}
        .append(value_.XML())
        .append("</value><unit>")
        .append(Abbreviation(StandardUnit<U>))
        .append("</unit>");
  }

  std::string XML(const U unit) const noexcept override {
    return std::string{"<value>"}
        .append(Value(unit).XML())
        .append("</value><unit>")
        .append(Abbreviation(unit))
        .append("</unit>");
  }

  std::string YAML() const noexcept override {
    return std::string{"{value:"}
        .append(value_.YAML())
        .append(",unit:\"")
        .append(Abbreviation(StandardUnit<U>))
        .append("\"}");
  }

  std::string YAML(const U unit) const noexcept override {
    return std::string{"{value:"}
        .append(Value(unit).YAML())
        .append(",unit:\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

protected:
  constexpr DimensionalDyadQuantity() noexcept
    : DimensionalQuantity<U>(), value_() {}

  constexpr DimensionalDyadQuantity(const Value::Dyad& value) noexcept
    : DimensionalQuantity<U>(), value_(value) {}

  constexpr DimensionalDyadQuantity(Value::Dyad&& value) noexcept
    : DimensionalQuantity<U>(), value_(std::move(value)) {}

  DimensionalDyadQuantity(const Value::Dyad& value, const U unit) noexcept
    : DimensionalQuantity<U>(), value_(value) {
    Convert(value_, unit, StandardUnit<U>);
  }

  DimensionalDyadQuantity(Value::Dyad&& value, const U unit) noexcept
    : DimensionalQuantity<U>(), value_(std::move(value)) {
    Convert(value_, unit, StandardUnit<U>);
  }

  virtual ~DimensionalDyadQuantity() noexcept = default;

  constexpr void operator=(const Value::Dyad& value) noexcept {
    value_ = value;
  }

  constexpr void operator=(Value::Dyad&& value) noexcept {
    value_ = std::move(value);
  }

  Value::Dyad value_;
};

}  // namespace PhQ

namespace std {

template<typename U> struct hash<PhQ::DimensionalDyadQuantity<U>> {
  size_t operator()(const PhQ::DimensionalDyadQuantity<U>& quantity) const {
    return hash<PhQ::Value::Dyad>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_DYAD_HPP
