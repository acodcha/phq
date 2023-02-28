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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_SYMMETRIC_DYAD_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_SYMMETRIC_DYAD_HPP

#include <utility>

#include "../Value/SymmetricDyad.hpp"
#include "Dimensional.hpp"

namespace PhQ {

template <typename Unit>
class DimensionalSymmetricDyadQuantity : public DimensionalQuantity<Unit> {
public:
  virtual ~DimensionalSymmetricDyadQuantity() noexcept = default;

  constexpr const Value::SymmetricDyad& Value() const noexcept {
    return value_;
  }

  Value::SymmetricDyad Value(const Unit unit) const noexcept {
    Value::SymmetricDyad result{value_};
    Convert(result, StandardUnit<Unit>, unit);
    return result;
  }

  std::string Print() const noexcept override {
    return value_.Print().append(" ").append(Abbreviation(StandardUnit<Unit>));
  }

  std::string Print(const Unit unit) const noexcept override {
    return Value(unit).Print().append(" ").append(Abbreviation(unit));
  }

  std::string Json() const noexcept override {
    return std::string{"{\"value\":"}
        .append(value_.Json())
        .append(",\"unit\":\"")
        .append(Abbreviation(StandardUnit<Unit>))
        .append("\"}");
  }

  std::string Json(const Unit unit) const noexcept override {
    return std::string{"{\"value\":"}
        .append(Value(unit).Json())
        .append(",\"unit\":\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

  std::string Xml() const noexcept override {
    return std::string{"<value>"}
        .append(value_.Xml())
        .append("</value><unit>")
        .append(Abbreviation(StandardUnit<Unit>))
        .append("</unit>");
  }

  std::string Xml(const Unit unit) const noexcept override {
    return std::string{"<value>"}
        .append(Value(unit).Xml())
        .append("</value><unit>")
        .append(Abbreviation(unit))
        .append("</unit>");
  }

  std::string Yaml() const noexcept override {
    return std::string{"{value:"}
        .append(value_.Yaml())
        .append(",unit:\"")
        .append(Abbreviation(StandardUnit<Unit>))
        .append("\"}");
  }

  std::string Yaml(const Unit unit) const noexcept override {
    return std::string{"{value:"}
        .append(Value(unit).Yaml())
        .append(",unit:\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

protected:
  constexpr DimensionalSymmetricDyadQuantity() noexcept
      : DimensionalQuantity<Unit>(), value_() {}

  constexpr DimensionalSymmetricDyadQuantity(
      const Value::SymmetricDyad& value) noexcept
      : DimensionalQuantity<Unit>(), value_(value) {}

  constexpr DimensionalSymmetricDyadQuantity(
      Value::SymmetricDyad&& value) noexcept
      : DimensionalQuantity<Unit>(), value_(std::move(value)) {}

  DimensionalSymmetricDyadQuantity(const Value::SymmetricDyad& value,
                                   const Unit unit) noexcept
      : DimensionalQuantity<Unit>(), value_(value) {
    Convert(value_, unit, StandardUnit<Unit>);
  }

  DimensionalSymmetricDyadQuantity(Value::SymmetricDyad&& value,
                                   const Unit unit) noexcept
      : DimensionalQuantity<Unit>(), value_(std::move(value)) {
    Convert(value_, unit, StandardUnit<Unit>);
  }

  void operator=(const Value::SymmetricDyad& value) noexcept { value_ = value; }

  void operator=(Value::SymmetricDyad&& value) noexcept {
    value_ = std::move(value);
  }

  Value::SymmetricDyad value_;
};

}  // namespace PhQ

namespace std {

template <typename Unit>
struct hash<PhQ::DimensionalSymmetricDyadQuantity<Unit>> {
  size_t operator()(
      const PhQ::DimensionalSymmetricDyadQuantity<Unit>& quantity) const {
    return hash<PhQ::Value::SymmetricDyad>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_SYMMETRIC_DYAD_HPP
