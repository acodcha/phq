// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

/// \brief Abstract base class that represents any dimensional vector physical quantity. Such a
/// physical quantity is composed of a value and a unit of measure where the value is a
/// three-dimensional vector.
/// \tparam UnitType Unit of measure enumeration type.
/// \tparam NumericType Floating-point numeric type: float, double, or long double. Defaults to
/// double if unspecified.
template <typename UnitType, typename NumericType = double>
class DimensionalVector {
public:
  /// \brief Physical dimension set of this physical quantity.
  [[nodiscard]] static constexpr const PhQ::Dimensions& Dimensions() {
    return PhQ::RelatedDimensions<UnitType>;
  }

  /// \brief Standard unit of measure for this physical quantity. This physical quantity's value is
  /// stored internally in this unit of measure.
  [[nodiscard]] static constexpr UnitType Unit() {
    return PhQ::Standard<UnitType>;
  }

  /// \brief Value of this physical quantity expressed in its standard unit of measure.
  [[nodiscard]] constexpr const PhQ::Vector<NumericType>& Value() const noexcept {
    return value;
  }

  /// \brief Value of this physical quantity expressed in a given unit of measure.
  [[nodiscard]] PhQ::Vector<NumericType> Value(const UnitType unit) const {
    return PhQ::Convert(value, PhQ::Standard<UnitType>, unit);
  }

  /// \brief Value of this physical quantity expressed in a given unit of measure. This method can
  /// be evaluated statically at compile-time.
  template <UnitType NewUnit>
  [[nodiscard]] constexpr PhQ::Vector<NumericType> StaticValue() const {
    return PhQ::ConvertStatically<UnitType, PhQ::Standard<UnitType>, NewUnit>(value);
  }

  /// \brief Returns the value of this physical quantity expressed in its standard unit of measure
  /// as a mutable value.
  [[nodiscard]] constexpr PhQ::Vector<NumericType>& MutableValue() noexcept {
    return value;
  }

  /// \brief Sets the value of this physical quantity expressed in its standard unit of measure to
  /// the given value.
  constexpr void SetValue(const PhQ::Vector<NumericType>& value) noexcept {
    this->value = value;
  }

  /// \brief Prints this physical quantity as a string. This physical quantity's value is expressed
  /// in its standard unit of measure.
  [[nodiscard]] std::string Print() const {
    return value.Print().append(" ").append(PhQ::Abbreviation(PhQ::Standard<UnitType>));
  }

  /// \brief Prints this physical quantity as a string. This physical quantity's value is expressed
  /// in the given unit of measure.
  [[nodiscard]] std::string Print(const UnitType unit) const {
    return Value(unit).Print().append(" ").append(PhQ::Abbreviation(unit));
  }

  /// \brief Serializes this physical quantity as a JSON message. This physical quantity's value is
  /// expressed in its standard unit of measure.
  [[nodiscard]] std::string JSON() const {
    return std::string{"{\"value\":"}
        .append(value.JSON())
        .append(R"(,"unit":")")
        .append(PhQ::Abbreviation(PhQ::Standard<UnitType>))
        .append("\"}");
  }

  /// \brief Serializes this physical quantity as a JSON message. This physical quantity's value is
  /// expressed in the given unit of measure.
  [[nodiscard]] std::string JSON(const UnitType unit) const {
    return std::string{"{\"value\":"}
        .append(Value(unit).JSON())
        .append(R"(,"unit":")")
        .append(PhQ::Abbreviation(unit))
        .append("\"}");
  }

  /// \brief Serializes this physical quantity as an XML message. This physical quantity's value is
  /// expressed in its standard unit of measure.
  [[nodiscard]] std::string XML() const {
    return std::string{"<value>"}
        .append(value.XML())
        .append("</value><unit>")
        .append(PhQ::Abbreviation(PhQ::Standard<UnitType>))
        .append("</unit>");
  }

  /// \brief Serializes this physical quantity as an XML message. This physical quantity's value is
  /// expressed in the given unit of measure.
  [[nodiscard]] std::string XML(const UnitType unit) const {
    return std::string{"<value>"}
        .append(Value(unit).XML())
        .append("</value><unit>")
        .append(PhQ::Abbreviation(unit))
        .append("</unit>");
  }

  /// \brief Serializes this physical quantity as a YAML message. This physical quantity's value is
  /// expressed in its standard unit of measure.
  [[nodiscard]] std::string YAML() const {
    return std::string{"{value:"}
        .append(value.YAML())
        .append(",unit:\"")
        .append(PhQ::Abbreviation(PhQ::Standard<UnitType>))
        .append("\"}");
  }

  /// \brief Serializes this physical quantity as a YAML message. This physical quantity's value is
  /// expressed in the given unit of measure.
  [[nodiscard]] std::string YAML(const UnitType unit) const {
    return std::string{"{value:"}
        .append(Value(unit).YAML())
        .append(",unit:\"")
        .append(PhQ::Abbreviation(unit))
        .append("\"}");
  }

protected:
  /// \brief Default constructor. Constructs a dimensional vector physical quantity with an
  /// uninitialized value.
  DimensionalVector() = default;

  /// \brief Constructor. Constructs a dimensional vector physical quantity with a given value
  /// expressed in its standard unit of measure.
  explicit constexpr DimensionalVector(const PhQ::Vector<NumericType>& value) : value(value) {}

  /// \brief Constructor. Constructs a dimensional vector physical quantity with a given value
  /// expressed in a given unit of measure.
  DimensionalVector(const PhQ::Vector<NumericType>& value, const UnitType unit) : value(value) {
    PhQ::ConvertInPlace(this->value, unit, PhQ::Standard<UnitType>);
  }

  /// \brief Destructor. Destroys this dimensional vector physical quantity.
  ~DimensionalVector() noexcept = default;

  /// \brief Copy constructor. Constructs a dimensional vector physical quantity by copying another
  /// one.
  constexpr DimensionalVector(const DimensionalVector<UnitType, NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a dimensional vector physical quantity by copying another
  /// one.
  /// \tparam OtherNumericType Floating-point numeric type of the other physical quantity. Deduced
  /// automatically.
  template <typename OtherNumericType>
  explicit constexpr DimensionalVector(const DimensionalVector<UnitType, OtherNumericType>& other)
    : value(static_cast<PhQ::Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a dimensional vector physical quantity by moving another
  /// one.
  constexpr DimensionalVector(DimensionalVector<UnitType, NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this dimensional vector physical quantity by copying
  /// another one.
  constexpr DimensionalVector<UnitType, NumericType>& operator=(
      const DimensionalVector<UnitType, NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this dimensional vector physical quantity by copying
  /// another one.
  /// \tparam OtherNumericType Floating-point numeric type of the other physical quantity. Deduced
  /// automatically.
  template <typename OtherNumericType>
  constexpr DimensionalVector<UnitType, NumericType>& operator=(
      const DimensionalVector<UnitType, OtherNumericType>& other) {
    value = static_cast<PhQ::Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this dimensional vector physical quantity by moving
  /// another one.
  constexpr DimensionalVector<UnitType, NumericType>& operator=(
      DimensionalVector<UnitType, NumericType>&& other) noexcept = default;

  /// \brief Value of this physical quantity expressed in its standard unit of measure.
  PhQ::Vector<NumericType> value;
};

}  // namespace PhQ

#endif  // PHQ_DIMENSIONAL_VECTOR_HPP
