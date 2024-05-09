// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHQ_DIMENSIONAL_VECTOR_HPP
#define PHQ_DIMENSIONAL_VECTOR_HPP

#include <cstddef>
#include <functional>
#include <ostream>
#include <string>

#include "Base.hpp"
#include "Dimensions.hpp"
#include "Unit.hpp"
#include "Vector.hpp"

namespace PhQ {

// Abstract base class that represents any dimensional vector physical quantity. Such a physical
// quantity is composed of a value and a unit of measure where the value is a three-dimensional
// vector.
template <typename UnitType, typename Number = double>
class DimensionalVector {
public:
  // Physical dimension set of this physical quantity.
  static constexpr const PhQ::Dimensions& Dimensions() {
    return PhQ::RelatedDimensions<UnitType>;
  }

  // Standard unit of measure for this physical quantity. This physical quantity's value is stored
  // internally in this unit of measure.
  static constexpr UnitType Unit() {
    return PhQ::Standard<UnitType>;
  }

  // Value of this physical quantity expressed in its standard unit of measure.
  [[nodiscard]] constexpr const PhQ::Vector<Number>& Value() const noexcept {
    return value;
  }

  // Value of this physical quantity expressed in a given unit of measure.
  [[nodiscard]] PhQ::Vector<Number> Value(const UnitType unit) const {
    PhQ::Vector<Number> result{value};
    PhQ::Convert(result, PhQ::Standard<UnitType>, unit);
    return result;
  }

  // Value of this physical quantity expressed in a given unit of measure. This method can be
  // evaluated statically at compile-time.
  template <UnitType NewUnit>
  [[nodiscard]] constexpr PhQ::Vector<Number> StaticValue() const {
    return PhQ::StaticConvertCopy<UnitType, PhQ::Standard<UnitType>, NewUnit>(value);
  }

  // Returns the value of this physical quantity expressed in its standard unit of measure as a
  // mutable value.
  constexpr PhQ::Vector<Number>& MutableValue() noexcept {
    return value;
  }

  // Sets the value of this physical quantity expressed in its standard unit of measure to the given
  // value.
  constexpr void SetValue(const PhQ::Vector<Number>& value) noexcept {
    this->value = value;
  }

  // Prints this physical quantity as a string. This physical quantity's value is expressed in its
  // standard unit of measure and printed to Number floating point precision.
  [[nodiscard]] std::string Print() const {
    return value.Print().append(" ").append(PhQ::Abbreviation(PhQ::Standard<UnitType>));
  }

  // Prints this physical quantity as a string. This physical quantity's value is expressed in the
  // given unit of measure and printed to Number floating point precision.
  [[nodiscard]] std::string Print(const UnitType unit) const {
    return Value(unit).Print().append(" ").append(PhQ::Abbreviation(unit));
  }

  // Serializes this physical quantity as a JSON message. This physical quantity's value is
  // expressed in its standard unit of measure.
  [[nodiscard]] std::string JSON() const {
    return std::string{"{\"value\":"}
        .append(value.JSON())
        .append(R"(,"unit":")")
        .append(PhQ::Abbreviation(PhQ::Standard<UnitType>))
        .append("\"}");
  }

  // Serializes this physical quantity as a JSON message. This physical quantity's value is
  // expressed in the given unit of measure.
  [[nodiscard]] std::string JSON(const UnitType unit) const {
    return std::string{"{\"value\":"}
        .append(Value(unit).JSON())
        .append(R"(,"unit":")")
        .append(PhQ::Abbreviation(unit))
        .append("\"}");
  }

  // Serializes this physical quantity as an XML message. This physical quantity's value is
  // expressed in its standard unit of measure.
  [[nodiscard]] std::string XML() const {
    return std::string{"<value>"}
        .append(value.XML())
        .append("</value><unit>")
        .append(PhQ::Abbreviation(PhQ::Standard<UnitType>))
        .append("</unit>");
  }

  // Serializes this physical quantity as an XML message. This physical quantity's value is
  // expressed in the given unit of measure.
  [[nodiscard]] std::string XML(const UnitType unit) const {
    return std::string{"<value>"}
        .append(Value(unit).XML())
        .append("</value><unit>")
        .append(PhQ::Abbreviation(unit))
        .append("</unit>");
  }

  // Serializes this physical quantity as a YAML message. This physical quantity's value is
  // expressed in its standard unit of measure.
  [[nodiscard]] std::string YAML() const {
    return std::string{"{value:"}
        .append(value.YAML())
        .append(",unit:\"")
        .append(PhQ::Abbreviation(PhQ::Standard<UnitType>))
        .append("\"}");
  }

  // Serializes this physical quantity as a YAML message. This physical quantity's value is
  // expressed in the given unit of measure.
  [[nodiscard]] std::string YAML(const UnitType unit) const {
    return std::string{"{value:"}
        .append(Value(unit).YAML())
        .append(",unit:\"")
        .append(PhQ::Abbreviation(unit))
        .append("\"}");
  }

protected:
  // Default constructor. Constructs a dimensional vector physical quantity with an uninitialized
  // value.
  DimensionalVector() = default;

  // Constructor. Constructs a dimensional vector physical quantity with a given value expressed in
  // its standard unit of measure.
  explicit constexpr DimensionalVector(const PhQ::Vector<Number>& value) : value(value) {}

  // Constructor. Constructs a dimensional vector physical quantity with a given value expressed in
  // a given unit of measure.
  DimensionalVector(const PhQ::Vector<Number>& value, const UnitType unit) : value(value) {
    Convert(this->value, unit, PhQ::Standard<UnitType>);
  }

  // Destructor. Destroys this dimensional vector physical quantity.
  ~DimensionalVector() noexcept = default;

  // Copy constructor. Constructs a dimensional vector physical quantity by copying another one.
  constexpr DimensionalVector(const DimensionalVector<UnitType, Number>& other) = default;

  // Copy constructor. Constructs a dimensional vector physical quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr DimensionalVector(const DimensionalVector<UnitType, OtherNumber>& other)
    : value(static_cast<PhQ::Vector<Number>>(other.Value())) {}

  // Move constructor. Constructs a dimensional vector physical quantity by moving another one.
  constexpr DimensionalVector(DimensionalVector<UnitType, Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensional vector physical quantity by copying another
  // one.
  constexpr DimensionalVector<UnitType, Number>& operator=(
      const DimensionalVector<UnitType, Number>& other) = default;

  // Copy assignment operator. Assigns this dimensional vector physical quantity by copying another
  // one.
  template <typename OtherNumber>
  constexpr DimensionalVector<UnitType, Number>& operator=(
      const DimensionalVector<UnitType, OtherNumber>& other) {
    value = static_cast<PhQ::Vector<Number>>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this dimensional vector physical quantity by moving another
  // one.
  constexpr DimensionalVector<UnitType, Number>& operator=(
      DimensionalVector<UnitType, Number>&& other) noexcept = default;

  // Value of this physical quantity expressed in its standard unit of measure.
  PhQ::Vector<Number> value;
};

}  // namespace PhQ

#endif  // PHQ_DIMENSIONAL_VECTOR_HPP
