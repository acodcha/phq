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

template <typename Unit>
class DimensionalScalarQuantity : public DimensionalQuantity<Unit> {
public:
  virtual ~DimensionalScalarQuantity() noexcept = default;

  constexpr double Value() const noexcept { return value_; }

  double Value(const Unit unit) const noexcept {
    double result{value_};
    Convert(result, StandardUnit<Unit>, unit);
    return result;
  }

  std::string Print() const noexcept override {
    return PhQ::Print(value_).append(" ").append(
        Abbreviation(StandardUnit<Unit>));
  }

  std::string Print(const Unit unit) const noexcept override {
    return PhQ::Print(Value(unit)).append(" ").append(Abbreviation(unit));
  }

  std::string Json() const noexcept override {
    return std::string{"{\"value\":"}
        .append(PhQ::Print(value_))
        .append(",\"unit\":\"")
        .append(Abbreviation(StandardUnit<Unit>))
        .append("\"}");
  }

  std::string Json(const Unit unit) const noexcept override {
    return std::string{"{\"value\":"}
        .append(PhQ::Print(Value(unit)))
        .append(",\"unit\":\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

  std::string Xml() const noexcept override {
    return std::string{"<value>"}
        .append(PhQ::Print(value_))
        .append("</value><unit>")
        .append(Abbreviation(StandardUnit<Unit>))
        .append("</unit>");
  }

  std::string Xml(const Unit unit) const noexcept override {
    return std::string{"<value>"}
        .append(PhQ::Print(Value(unit)))
        .append("</value><unit>")
        .append(Abbreviation(unit))
        .append("</unit>");
  }

  std::string Yaml() const noexcept override {
    return std::string{"{value:"}
        .append(PhQ::Print(value_))
        .append(",unit:\"")
        .append(Abbreviation(StandardUnit<Unit>))
        .append("\"}");
  }

  std::string Yaml(const Unit unit) const noexcept override {
    return std::string{"{value:"}
        .append(PhQ::Print(Value(unit)))
        .append(",unit:\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

protected:
  constexpr DimensionalScalarQuantity() noexcept
      : DimensionalQuantity<Unit>(), value_() {}

  constexpr DimensionalScalarQuantity(const double value) noexcept
      : DimensionalQuantity<Unit>(), value_(value) {}

  DimensionalScalarQuantity(const double value, const Unit unit) noexcept
      : DimensionalQuantity<Unit>(), value_(value) {
    Convert(value_, unit, StandardUnit<Unit>);
  }

  void operator=(const double value) noexcept { value_ = value; }

  double value_;
};

}  // namespace PhQ

namespace std {

template <typename Unit>
struct hash<PhQ::DimensionalScalarQuantity<Unit>> {
  size_t operator()(
      const PhQ::DimensionalScalarQuantity<Unit>& quantity) const {
    return hash<double>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_SCALAR_HPP
