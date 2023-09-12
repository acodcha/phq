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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_SYMMETRIC_DYAD_QUANTITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_SYMMETRIC_DYAD_QUANTITY_HPP

#include "Unit.hpp"
#include "Value/SymmetricDyad.hpp"

namespace PhQ {

// Abstract base class that represents any dimensional symmetric dyadic tensor
// physical quantity. Such a physical quantity is composed of a value and a unit
// of measure where the value is a symmetric tensor of rank two and dimension
// three.
template<typename U> class DimensionalSymmetricDyadQuantity {
public:
  // Physical dimension set of this physical quantity.
  static constexpr const PhQ::Dimensions& Dimensions() noexcept {
    return RelatedDimensions<U>;
  }

  // Standard unit of measure for this physical quantity. This physical
  // quantity's value is stored internally in this unit of measure.
  static constexpr U Unit() noexcept { return Standard<U>; }

  // Value of this physical quantity expressed in its standard unit of measure.
  constexpr const Value::SymmetricDyad& Value() const noexcept {
    return value_;
  }

  // Value of this physical quantity expressed in a given unit of measure.
  Value::SymmetricDyad Value(const U unit) const noexcept {
    Value::SymmetricDyad result{value_};
    Convert(result, Standard<U>, unit);
    return result;
  }

  // Value of this physical quantity expressed in a given unit of measure. This
  // method can be evaluated statically at compile-time.
  template<U NewUnit>
  constexpr Value::SymmetricDyad StaticValue() const noexcept {
    return StaticConvertCopy<U, Standard<U>, NewUnit>(value_);
  }

  // Returns the value of this physical quantity expressed in its standard unit
  // of measure as a mutable value.
  constexpr Value::SymmetricDyad& MutableValue() noexcept { return value_; }

  // Sets the value of this physical quantity expressed in its standard unit of
  // measure to the given value.
  constexpr void SetValue(const Value::SymmetricDyad& value) noexcept {
    value_ = value;
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in its standard unit of measure and printed to double floating
  // point precision.
  std::string Print() const noexcept {
    return value_.Print().append(" ").append(Abbreviation(Standard<U>));
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in its standard unit of measure and printed to the given
  // floating point precision.
  std::string Print(const Precision precision) const noexcept {
    return value_.Print(precision).append(" ").append(
        Abbreviation(Standard<U>));
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in the given unit of measure and printed to double floating
  // point precision.
  std::string Print(const U unit) const noexcept {
    return Value(unit).Print().append(" ").append(Abbreviation(unit));
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in the given unit of measure and printed to the given floating
  // point precision.
  std::string Print(const U unit, const Precision precision) const noexcept {
    return Value(unit).Print(precision).append(" ").append(Abbreviation(unit));
  }

  // Serializes this physical quantity as a JSON message. This physical
  // quantity's value is expressed in its standard unit of measure.
  std::string JSON() const noexcept {
    return std::string{"{\"value\":"}
        .append(value_.JSON())
        .append(",\"unit\":\"")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  // Serializes this physical quantity as a JSON message. This physical
  // quantity's value is expressed in the given unit of measure.
  std::string JSON(const U unit) const noexcept {
    return std::string{"{\"value\":"}
        .append(Value(unit).JSON())
        .append(",\"unit\":\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

  // Serializes this physical quantity as an XML message. This physical
  // quantity's value is expressed in its standard unit of measure.
  std::string XML() const noexcept {
    return std::string{"<value>"}
        .append(value_.XML())
        .append("</value><unit>")
        .append(Abbreviation(Standard<U>))
        .append("</unit>");
  }

  // Serializes this physical quantity as an XML message. This physical
  // quantity's value is expressed in the given unit of measure.
  std::string XML(const U unit) const noexcept {
    return std::string{"<value>"}
        .append(Value(unit).XML())
        .append("</value><unit>")
        .append(Abbreviation(unit))
        .append("</unit>");
  }

  // Serializes this physical quantity as a YAML message. This physical
  // quantity's value is expressed in its standard unit of measure.
  std::string YAML() const noexcept {
    return std::string{"{value:"}
        .append(value_.YAML())
        .append(",unit:\"")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  // Serializes this physical quantity as a YAML message. This physical
  // quantity's value is expressed in the given unit of measure.
  std::string YAML(const U unit) const noexcept {
    return std::string{"{value:"}
        .append(Value(unit).YAML())
        .append(",unit:\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

protected:
  // Default constructor. Constructs a dimensional symmetric dyadic tensor
  // physical quantity with an uninitialized value expressed in its standard
  // unit of measure.
  constexpr DimensionalSymmetricDyadQuantity() noexcept : value_() {}

  // Constructs a dimensional symmetric dyadic tensor physical quantity with a
  // given value expressed in its standard unit of measure.
  constexpr DimensionalSymmetricDyadQuantity(
      const Value::SymmetricDyad& value) noexcept
    : value_(value) {}

  // Constructs a dimensional symmetric dyadic tensor physical quantity with a
  // given value expressed in its standard unit of measure by moving the value.
  constexpr DimensionalSymmetricDyadQuantity(
      Value::SymmetricDyad&& value) noexcept
    : value_(std::move(value)) {}

  // Constructs a dimensional dimensional symmetric dyadic tensor physical
  // quantity with a given value expressed in a given unit of measure.
  DimensionalSymmetricDyadQuantity(
      const Value::SymmetricDyad& value, const U unit) noexcept
    : value_(value) {
    Convert(value_, unit, Standard<U>);
  }

  // Constructs a dimensional dimensional symmetric dyadic tensor physical
  // quantity with a given value expressed in a given unit of measure by moving
  // the value.
  DimensionalSymmetricDyadQuantity(
      Value::SymmetricDyad&& value, const U unit) noexcept
    : value_(std::move(value)) {
    Convert(value_, unit, Standard<U>);
  }

  // Default destructor. Destroys this dimensional symmetric dyadic tensor
  // physical quantity.
  ~DimensionalSymmetricDyadQuantity() noexcept = default;

  constexpr void operator=(const Value::SymmetricDyad& value) noexcept {
    value_ = value;
  }

  constexpr void operator=(Value::SymmetricDyad&& value) noexcept {
    value_ = std::move(value);
  }

  Value::SymmetricDyad value_;
};

template<typename U> inline std::ostream& operator<<(
    std::ostream& stream,
    const DimensionalSymmetricDyadQuantity<U>& quantity) noexcept {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template<typename U> struct hash<PhQ::DimensionalSymmetricDyadQuantity<U>> {
  inline size_t operator()(
      const PhQ::DimensionalSymmetricDyadQuantity<U>& quantity) const {
    return hash<PhQ::Value::SymmetricDyad>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_SYMMETRIC_DYAD_QUANTITY_HPP
