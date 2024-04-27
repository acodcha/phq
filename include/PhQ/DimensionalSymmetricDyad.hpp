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

#ifndef PHQ_DIMENSIONAL_SYMMETRIC_DYAD_HPP
#define PHQ_DIMENSIONAL_SYMMETRIC_DYAD_HPP

#include <cstddef>
#include <functional>
#include <ostream>
#include <string>

#include "Base.hpp"
#include "Dimensions.hpp"
#include "SymmetricDyad.hpp"
#include "Unit.hpp"

namespace PhQ {

// Abstract base class that represents any dimensional symmetric dyadic tensor physical quantity.
// Such a physical quantity is composed of a value and a unit of measure where the value is a
// three-dimensional symmetric dyadic tensor.
template <typename U>
class DimensionalSymmetricDyad {
public:
  // Physical dimension set of this physical quantity.
  static constexpr const PhQ::Dimensions& Dimensions() {
    return RelatedDimensions<U>;
  }

  // Standard unit of measure for this physical quantity. This physical quantity's value is stored
  // internally in this unit of measure.
  static constexpr U Unit() {
    return Standard<U>;
  }

  // Value of this physical quantity expressed in its standard unit of measure.
  [[nodiscard]] constexpr const SymmetricDyad& Value() const noexcept {
    return value;
  }

  // Value of this physical quantity expressed in a given unit of measure.
  [[nodiscard]] SymmetricDyad Value(const U unit) const {
    SymmetricDyad result{value};
    Convert(result, Standard<U>, unit);
    return result;
  }

  // Value of this physical quantity expressed in a given unit of measure. This method can be
  // evaluated statically at compile-time.
  template <U NewUnit>
  [[nodiscard]] constexpr SymmetricDyad StaticValue() const {
    return StaticConvertCopy<U, Standard<U>, NewUnit>(value);
  }

  // Returns the value of this physical quantity expressed in its standard unit of measure as a
  // mutable value.
  constexpr SymmetricDyad& MutableValue() noexcept {
    return value;
  }

  // Sets the value of this physical quantity expressed in its standard unit of measure to the given
  // value.
  constexpr void SetValue(const SymmetricDyad& value) noexcept {
    this->value = value;
  }

  // Prints this physical quantity as a string. This physical quantity's value is expressed in its
  // standard unit of measure and printed to double floating point precision.
  [[nodiscard]] std::string Print() const {
    return value.Print().append(" ").append(Abbreviation(Standard<U>));
  }

  // Prints this physical quantity as a string. This physical quantity's value is expressed in its
  // standard unit of measure and printed to the given floating point precision.
  [[nodiscard]] std::string Print(const Precision precision) const {
    return value.Print(precision).append(" ").append(Abbreviation(Standard<U>));
  }

  // Prints this physical quantity as a string. This physical quantity's value is expressed in the
  // given unit of measure and printed to double floating point precision.
  [[nodiscard]] std::string Print(const U unit) const {
    return Value(unit).Print().append(" ").append(Abbreviation(unit));
  }

  // Prints this physical quantity as a string. This physical quantity's value is expressed in the
  // given unit of measure and printed to the given floating point precision.
  [[nodiscard]] std::string Print(const U unit, const Precision precision) const {
    return Value(unit).Print(precision).append(" ").append(Abbreviation(unit));
  }

  // Serializes this physical quantity as a JSON message. This physical quantity's value is
  // expressed in its standard unit of measure.
  [[nodiscard]] std::string JSON() const {
    return std::string{"{\"value\":"}
        .append(value.JSON())
        .append(R"(,"unit":")")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  // Serializes this physical quantity as a JSON message. This physical quantity's value is
  // expressed in the given unit of measure.
  [[nodiscard]] std::string JSON(const U unit) const {
    return std::string{"{\"value\":"}
        .append(Value(unit).JSON())
        .append(R"(,"unit":")")
        .append(Abbreviation(unit))
        .append("\"}");
  }

  // Serializes this physical quantity as an XML message. This physical quantity's value is
  // expressed in its standard unit of measure.
  [[nodiscard]] std::string XML() const {
    return std::string{"<value>"}
        .append(value.XML())
        .append("</value><unit>")
        .append(Abbreviation(Standard<U>))
        .append("</unit>");
  }

  // Serializes this physical quantity as an XML message. This physical quantity's value is
  // expressed in the given unit of measure.
  [[nodiscard]] std::string XML(const U unit) const {
    return std::string{"<value>"}
        .append(Value(unit).XML())
        .append("</value><unit>")
        .append(Abbreviation(unit))
        .append("</unit>");
  }

  // Serializes this physical quantity as a YAML message. This physical quantity's value is
  // expressed in its standard unit of measure.
  [[nodiscard]] std::string YAML() const {
    return std::string{"{value:"}
        .append(value.YAML())
        .append(",unit:\"")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  // Serializes this physical quantity as a YAML message. This physical quantity's value is
  // expressed in the given unit of measure.
  [[nodiscard]] std::string YAML(const U unit) const {
    return std::string{"{value:"}
        .append(Value(unit).YAML())
        .append(",unit:\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

protected:
  // Default constructor. Constructs a dimensional symmetric dyadic tensor physical quantity with an
  // uninitialized value expressed in its standard unit of measure.
  DimensionalSymmetricDyad() = default;

  // Constructor. Constructs a dimensional symmetric dyadic tensor physical quantity with a given
  // value expressed in its standard unit of measure.
  explicit constexpr DimensionalSymmetricDyad(const SymmetricDyad& value) : value(value) {}

  // Constructor. Constructs a dimensional dimensional symmetric dyadic tensor physical quantity
  // with a given value expressed in a given unit of measure.
  DimensionalSymmetricDyad(const SymmetricDyad& value, const U unit) : value(value) {
    Convert(this->value, unit, Standard<U>);
  }

  // Destructor. Destroys this dimensional symmetric dyadic tensor physical quantity.
  ~DimensionalSymmetricDyad() noexcept = default;

  // Copy constructor. Constructs a dimensional symmetric dyadic tensor physical quantity by copying
  // another one.
  constexpr DimensionalSymmetricDyad(const DimensionalSymmetricDyad& other) = default;

  // Move constructor. Constructs a dimensional symmetric dyadic tensor physical quantity by moving
  // another one.
  constexpr DimensionalSymmetricDyad(DimensionalSymmetricDyad&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensional symmetric dyadic tensor physical quantity by
  // copying another one.
  constexpr DimensionalSymmetricDyad& operator=(const DimensionalSymmetricDyad& other) = default;

  // Move assignment operator. Assigns this dimensional symmetric dyadic tensor physical quantity by
  // moving another one.
  constexpr DimensionalSymmetricDyad& operator=(
      DimensionalSymmetricDyad&& other) noexcept = default;

  // Value of this dimensional symmetric dyadic tensor physical quantity expressed in its standard
  // unit of measure.
  SymmetricDyad value;
};

template <typename U>
inline std::ostream& operator<<(std::ostream& stream, const DimensionalSymmetricDyad<U>& quantity) {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename U>
struct hash<PhQ::DimensionalSymmetricDyad<U>> {
  inline size_t operator()(const PhQ::DimensionalSymmetricDyad<U>& quantity) const {
    return hash<PhQ::SymmetricDyad>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIMENSIONAL_SYMMETRIC_DYAD_HPP
