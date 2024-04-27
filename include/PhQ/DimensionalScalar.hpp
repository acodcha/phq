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

#ifndef PHQ_DIMENSIONAL_SCALAR_HPP
#define PHQ_DIMENSIONAL_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>
#include <string>

#include "Base.hpp"
#include "Dimensions.hpp"
#include "Unit.hpp"

namespace PhQ {

// Abstract base class that represents any dimensional scalar physical quantity. Such a physical
// quantity is composed of a value and a unit of measure where the value is a scalar number.
template <typename U>
class DimensionalScalar {
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
  [[nodiscard]] constexpr double Value() const noexcept {
    return value;
  }

  // Value of this physical quantity expressed in a given unit of measure.
  [[nodiscard]] double Value(const U unit) const {
    double result{value};
    Convert(result, Standard<U>, unit);
    return result;
  }

  // Value of this physical quantity expressed in a given unit of measure. This method can be
  // evaluated statically at compile-time.
  template <U NewUnit>
  [[nodiscard]] constexpr double StaticValue() const {
    return StaticConvertCopy<U, Standard<U>, NewUnit>(value);
  }

  // Returns the value of this physical quantity expressed in its standard unit of measure as a
  // mutable value.
  constexpr double& MutableValue() noexcept {
    return value;
  }

  // Sets the value of this physical quantity expressed in its standard unit of measure to the given
  // value.
  constexpr void SetValue(const double value) noexcept {
    this->value = value;
  }

  // Prints this physical quantity as a string. This physical quantity's value is expressed in its
  // standard unit of measure and printed to double floating point precision.
  [[nodiscard]] std::string Print() const {
    return PhQ::Print(value).append(" ").append(Abbreviation(Standard<U>));
  }

  // Prints this physical quantity as a string. This physical quantity's value is expressed in its
  // standard unit of measure and printed to the given floating point precision.
  [[nodiscard]] std::string Print(const Precision precision) const {
    return PhQ::Print(value, precision).append(" ").append(Abbreviation(Standard<U>));
  }

  // Prints this physical quantity as a string. This physical quantity's value is expressed in the
  // given unit of measure and printed to double floating point precision.
  [[nodiscard]] std::string Print(const U unit) const {
    return PhQ::Print(Value(unit)).append(" ").append(Abbreviation(unit));
  }

  // Prints this physical quantity as a string. This physical quantity's value is expressed in the
  // given unit of measure and printed to the given floating point precision.
  [[nodiscard]] std::string Print(const U unit, const Precision precision) const {
    return PhQ::Print(Value(unit), precision).append(" ").append(Abbreviation(unit));
  }

  // Serializes this physical quantity as a JSON message. This physical quantity's value is
  // expressed in its standard unit of measure.
  [[nodiscard]] std::string JSON() const {
    return std::string{"{\"value\":"}
        .append(PhQ::Print(value))
        .append(R"(,"unit":")")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  // Serializes this physical quantity as a JSON message. This physical quantity's value is
  // expressed in the given unit of measure.
  [[nodiscard]] std::string JSON(const U unit) const {
    return std::string{"{\"value\":"}
        .append(PhQ::Print(Value(unit)))
        .append(R"(,"unit":")")
        .append(Abbreviation(unit))
        .append("\"}");
  }

  // Serializes this physical quantity as an XML message. This physical quantity's value is
  // expressed in its standard unit of measure.
  [[nodiscard]] std::string XML() const {
    return std::string{"<value>"}
        .append(PhQ::Print(value))
        .append("</value><unit>")
        .append(Abbreviation(Standard<U>))
        .append("</unit>");
  }

  // Serializes this physical quantity as an XML message. This physical quantity's value is
  // expressed in the given unit of measure.
  [[nodiscard]] std::string XML(const U unit) const {
    return std::string{"<value>"}
        .append(PhQ::Print(Value(unit)))
        .append("</value><unit>")
        .append(Abbreviation(unit))
        .append("</unit>");
  }

  // Serializes this physical quantity as a YAML message. This physical quantity's value is
  // expressed in its standard unit of measure.
  [[nodiscard]] std::string YAML() const {
    return std::string{"{value:"}
        .append(PhQ::Print(value))
        .append(",unit:\"")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  // Serializes this physical quantity as a YAML message. This physical quantity's value is
  // expressed in the given unit of measure.
  [[nodiscard]] std::string YAML(const U unit) const {
    return std::string{"{value:"}
        .append(PhQ::Print(Value(unit)))
        .append(",unit:\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

protected:
  // Default constructor. Constructs a dimensional scalar physical quantity with an uninitialized
  // value expressed in its standard unit of measure.
  DimensionalScalar() = default;

  // Constructor. Constructs a dimensional scalar physical quantity with a given value expressed in
  // its standard unit of measure.
  explicit constexpr DimensionalScalar(const double value) : value(value) {}

  // Constructor. Constructs a dimensional scalar physical quantity with a given value expressed in
  // a given unit of measure.
  DimensionalScalar(const double value, const U unit) : value(value) {
    Convert(this->value, unit, Standard<U>);
  }

  // Destructor. Destroys this dimensional scalar physical quantity.
  ~DimensionalScalar() noexcept = default;

  // Copy constructor. Constructs a dimensional scalar physical quantity by copying another one.
  constexpr DimensionalScalar(const DimensionalScalar& other) = default;

  // Move constructor. Constructs a dimensional scalar physical quantity by moving another one.
  constexpr DimensionalScalar(DimensionalScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this dimensional scalar physical quantity by copying another
  // one.
  constexpr DimensionalScalar& operator=(const DimensionalScalar& other) = default;

  // Move assignment operator. Assigns this dimensional scalar physical quantity by moving another
  // one.
  constexpr DimensionalScalar& operator=(DimensionalScalar&& other) noexcept = default;

  // Value of this dimensional scalar physical quantity expressed in its standard unit of measure.
  double value;
};

template <typename U>
inline std::ostream& operator<<(std::ostream& stream, const DimensionalScalar<U>& quantity) {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename U>
struct hash<PhQ::DimensionalScalar<U>> {
  inline size_t operator()(const PhQ::DimensionalScalar<U>& quantity) const {
    return hash<double>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIMENSIONAL_SCALAR_HPP
