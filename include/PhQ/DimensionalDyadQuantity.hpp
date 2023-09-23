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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_DYAD_QUANTITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_DYAD_QUANTITY_HPP

#include "Unit.hpp"
#include "Value/Dyad.hpp"

namespace PhQ {

// Abstract base class that represents any dimensional dyadic tensor physical
// quantity. Such a physical quantity is composed of a value and a unit of
// measure where the value is a tensor of rank two and dimension three. The
// tensor may be non-symmetric.
template <typename U>
class DimensionalDyadQuantity {
public:
  // Physical dimension set of this physical quantity.
  static constexpr const PhQ::Dimensions& Dimensions() {
    return RelatedDimensions<U>;
  }

  // Standard unit of measure for this physical quantity. This physical
  // quantity's value is stored internally in this unit of measure.
  static constexpr U Unit() {
    return Standard<U>;
  }

  // Value of this physical quantity expressed in its standard unit of measure.
  constexpr const Value::Dyad& Value() const noexcept {
    return value_;
  }

  // Value of this physical quantity expressed in a given unit of measure.
  Value::Dyad Value(const U unit) const {
    Value::Dyad result{value_};
    Convert(result, Standard<U>, unit);
    return result;
  }

  // Value of this physical quantity expressed in a given unit of measure. This
  // method can be evaluated statically at compile-time.
  template <U NewUnit>
  constexpr Value::Dyad StaticValue() const {
    return StaticConvertCopy<U, Standard<U>, NewUnit>(value_);
  }

  // Returns the value of this physical quantity expressed in its standard unit
  // of measure as a mutable value.
  constexpr Value::Dyad& MutableValue() noexcept {
    return value_;
  }

  // Sets the value of this physical quantity expressed in its standard unit of
  // measure to the given value.
  constexpr void SetValue(const Value::Dyad& value) noexcept {
    value_ = value;
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in its standard unit of measure and printed to double floating
  // point precision.
  std::string Print() const {
    return value_.Print().append(" ").append(Abbreviation(Standard<U>));
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in its standard unit of measure and printed to the given
  // floating point precision.
  std::string Print(const Precision precision) const {
    return value_.Print(precision).append(" ").append(
        Abbreviation(Standard<U>));
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in the given unit of measure and printed to double floating
  // point precision.
  std::string Print(const U unit) const {
    return Value(unit).Print().append(" ").append(Abbreviation(unit));
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in the given unit of measure and printed to the given floating
  // point precision.
  std::string Print(const U unit, const Precision precision) const {
    return Value(unit).Print(precision).append(" ").append(Abbreviation(unit));
  }

  // Serializes this physical quantity as a JSON message. This physical
  // quantity's value is expressed in its standard unit of measure.
  std::string JSON() const {
    return std::string{"{\"value\":"}
        .append(value_.JSON())
        .append(",\"unit\":\"")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  // Serializes this physical quantity as a JSON message. This physical
  // quantity's value is expressed in the given unit of measure.
  std::string JSON(const U unit) const {
    return std::string{"{\"value\":"}
        .append(Value(unit).JSON())
        .append(",\"unit\":\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

  // Serializes this physical quantity as an XML message. This physical
  // quantity's value is expressed in its standard unit of measure.
  std::string XML() const {
    return std::string{"<value>"}
        .append(value_.XML())
        .append("</value><unit>")
        .append(Abbreviation(Standard<U>))
        .append("</unit>");
  }

  // Serializes this physical quantity as an XML message. This physical
  // quantity's value is expressed in the given unit of measure.
  std::string XML(const U unit) const {
    return std::string{"<value>"}
        .append(Value(unit).XML())
        .append("</value><unit>")
        .append(Abbreviation(unit))
        .append("</unit>");
  }

  // Serializes this physical quantity as a YAML message. This physical
  // quantity's value is expressed in its standard unit of measure.
  std::string YAML() const {
    return std::string{"{value:"}
        .append(value_.YAML())
        .append(",unit:\"")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  // Serializes this physical quantity as a YAML message. This physical
  // quantity's value is expressed in the given unit of measure.
  std::string YAML(const U unit) const {
    return std::string{"{value:"}
        .append(Value(unit).YAML())
        .append(",unit:\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

protected:
  // Default constructor. Constructs a dimensional dyadic tensor physical
  // quantity with an uninitialized value expressed in its standard unit of
  // measure.
  DimensionalDyadQuantity() = default;

  // Constructor. Constructs a dimensional dyadic tensor physical quantity with
  // a given value expressed in its standard unit of measure.
  explicit constexpr DimensionalDyadQuantity(const Value::Dyad& value)
    : value_(value) {}

  // Constructor. Constructs a dimensional dyadic tensor physical quantity by
  // moving a given value expressed in its standard unit of measure.
  explicit constexpr DimensionalDyadQuantity(Value::Dyad&& value) noexcept
    : value_(std::move(value)) {}

  // Constructor. Constructs a dimensional dimensional dyadic tensor physical
  // quantity with a given value expressed in a given unit of measure.
  DimensionalDyadQuantity(const Value::Dyad& value, const U unit)
    : value_(value) {
    Convert(value_, unit, Standard<U>);
  }

  // Constructor. Constructs a dimensional dimensional dyadic tensor physical
  // quantity by moving a given value expressed in a given unit of measure.
  DimensionalDyadQuantity(Value::Dyad&& value, const U unit)
    : value_(std::move(value)) {
    Convert(value_, unit, Standard<U>);
  }

  // Destructor. Destroys this dimensional dyadic tensor physical
  // quantity.
  ~DimensionalDyadQuantity() noexcept = default;

  // Copy constructor. Constructs a dimensional dyadic tensor physical quantity
  // by copying another one.
  constexpr DimensionalDyadQuantity(
      const DimensionalDyadQuantity& other) = default;

  // Move constructor. Constructs a dimensional dyadic tensor physical quantity
  // by moving another one.
  constexpr DimensionalDyadQuantity(
      DimensionalDyadQuantity&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensional dyadic tensor physical
  // quantity by copying another one.
  constexpr DimensionalDyadQuantity& operator=(
      const DimensionalDyadQuantity& other) = default;

  // Move assignment operator. Assigns this dimensional dyadic tensor physical
  // quantity by moving another one.
  constexpr DimensionalDyadQuantity& operator=(
      DimensionalDyadQuantity&& other) noexcept = default;

  // Value of this dimensional dyadic tensor physical quantity expressed in its
  // standard unit of measure.
  Value::Dyad value_;
};

template <typename U>
inline std::ostream&
operator<<(std::ostream& stream, const DimensionalDyadQuantity<U>& quantity) {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename U>
struct hash<PhQ::DimensionalDyadQuantity<U>> {
  inline size_t operator()(
      const PhQ::DimensionalDyadQuantity<U>& quantity) const {
    return hash<PhQ::Value::Dyad>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_DYAD_QUANTITY_HPP
