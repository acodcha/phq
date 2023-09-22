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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_SCALAR_QUANTITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_SCALAR_QUANTITY_HPP

#include "Unit.hpp"

namespace PhQ {

// Abstract base class that represents any dimensional scalar physical quantity.
// Such a physical quantity is composed of a value and a unit of measure where
// the value is a scalar number.
template <typename U>
class DimensionalScalarQuantity {
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
  constexpr double Value() const noexcept {
    return value_;
  }

  // Value of this physical quantity expressed in a given unit of measure.
  double Value(const U unit) const {
    double result{value_};
    Convert(result, Standard<U>, unit);
    return result;
  }

  // Value of this physical quantity expressed in a given unit of measure. This
  // method can be evaluated statically at compile-time.
  template <U NewUnit>
  constexpr double StaticValue() const {
    return StaticConvertCopy<U, Standard<U>, NewUnit>(value_);
  }

  // Returns the value of this physical quantity expressed in its standard unit
  // of measure as a mutable value.
  constexpr double& MutableValue() noexcept {
    return value_;
  }

  // Sets the value of this physical quantity expressed in its standard unit of
  // measure to the given value.
  constexpr void SetValue(const double value) noexcept {
    value_ = value;
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in its standard unit of measure and printed to double floating
  // point precision.
  std::string Print() const {
    return PhQ::Print(value_).append(" ").append(Abbreviation(Standard<U>));
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in its standard unit of measure and printed to the given
  // floating point precision.
  std::string Print(const Precision precision) const {
    return PhQ::Print(value_, precision)
        .append(" ")
        .append(Abbreviation(Standard<U>));
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in the given unit of measure and printed to double floating
  // point precision.
  std::string Print(const U unit) const {
    return PhQ::Print(Value(unit)).append(" ").append(Abbreviation(unit));
  }

  // Prints this physical quantity as a string. This physical quantity's value
  // is expressed in the given unit of measure and printed to the given floating
  // point precision.
  std::string Print(const U unit, const Precision precision) const {
    return PhQ::Print(Value(unit), precision)
        .append(" ")
        .append(Abbreviation(unit));
  }

  // Serializes this physical quantity as a JSON message. This physical
  // quantity's value is expressed in its standard unit of measure.
  std::string JSON() const {
    return std::string{"{\"value\":"}
        .append(PhQ::Print(value_))
        .append(",\"unit\":\"")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  // Serializes this physical quantity as a JSON message. This physical
  // quantity's value is expressed in the given unit of measure.
  std::string JSON(const U unit) const {
    return std::string{"{\"value\":"}
        .append(PhQ::Print(Value(unit)))
        .append(",\"unit\":\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

  // Serializes this physical quantity as an XML message. This physical
  // quantity's value is expressed in its standard unit of measure.
  std::string XML() const {
    return std::string{"<value>"}
        .append(PhQ::Print(value_))
        .append("</value><unit>")
        .append(Abbreviation(Standard<U>))
        .append("</unit>");
  }

  // Serializes this physical quantity as an XML message. This physical
  // quantity's value is expressed in the given unit of measure.
  std::string XML(const U unit) const {
    return std::string{"<value>"}
        .append(PhQ::Print(Value(unit)))
        .append("</value><unit>")
        .append(Abbreviation(unit))
        .append("</unit>");
  }

  // Serializes this physical quantity as a YAML message. This physical
  // quantity's value is expressed in its standard unit of measure.
  std::string YAML() const {
    return std::string{"{value:"}
        .append(PhQ::Print(value_))
        .append(",unit:\"")
        .append(Abbreviation(Standard<U>))
        .append("\"}");
  }

  // Serializes this physical quantity as a YAML message. This physical
  // quantity's value is expressed in the given unit of measure.
  std::string YAML(const U unit) const {
    return std::string{"{value:"}
        .append(PhQ::Print(Value(unit)))
        .append(",unit:\"")
        .append(Abbreviation(unit))
        .append("\"}");
  }

protected:
  // Default constructor. Constructs a dimensional scalar physical quantity with
  // an uninitialized value expressed in its standard unit of measure.
  constexpr DimensionalScalarQuantity() : value_() {}

  // Constructor. Constructs a dimensional scalar physical quantity with a given
  // value expressed in its standard unit of measure.
  constexpr DimensionalScalarQuantity(const double value) : value_(value) {}

  // Constructor. Constructs a dimensional scalar physical quantity with a given
  // value expressed in a given unit of measure.
  DimensionalScalarQuantity(const double value, const U unit) : value_(value) {
    Convert(value_, unit, Standard<U>);
  }

  // Destructor. Destroys this dimensional scalar physical quantity.
  ~DimensionalScalarQuantity() noexcept = default;

  // Copy assignment operator. Assigns the value of this dimensional scalar
  // physical quantity from a given value.
  constexpr void operator=(const double value) {
    value_ = value;
  }

  double value_;
};

template <typename U>
inline std::ostream&
operator<<(std::ostream& stream, const DimensionalScalarQuantity<U>& quantity) {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename U>
struct hash<PhQ::DimensionalScalarQuantity<U>> {
  inline size_t operator()(
      const PhQ::DimensionalScalarQuantity<U>& quantity) const {
    return hash<double>()(quantity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_SCALAR_QUANTITY_HPP
