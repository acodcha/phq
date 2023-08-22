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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_HPP

#include <functional>
#include <vector>

#include "Dimensions.hpp"
#include "UnitSystem.hpp"
#include "Value/Dyad.hpp"

namespace PhQ {

// Physical dimension set of a given type of unit of measure. Units of measure
// are organized into types that share the same physical dimension set.
template<typename Unit> inline constexpr Dimensions RelatedDimensions;

namespace Internal {

// Abstract function for converting a value expressed in the standard unit of
// measure of a given type to any given unit of measure of that type. Internal
// implementation detail not intended to be used outside of the
// PhQ::Internal::ConversionsFromStandard function.
template<typename Unit, Unit NewUnit>
inline constexpr void ConversionFromStandard(double& value) noexcept;

// Abstract function for converting a value expressed in any given unit of
// measure of a given type to the standard unit of measure of that type.
// Internal implementation detail not intended to be used outside of the
// PhQ::Internal::ConversionsToStandard function.
template<typename Unit, Unit OriginalUnit>
inline constexpr void ConversionToStandard(double& value) noexcept;

// Function for converting a series of values expressed in the standard unit of
// measure of a given type to any given unit of measure of that type. Internal
// implementation detail not intended to be used outside of the functions:
// PhQ::Convert, PhQ::ConvertCopy, PhQ::StaticConvert, and
// PhQ::StaticConvertCopy.
template<typename Unit, Unit NewUnit> inline constexpr void
ConversionsFromStandard(double* values, const std::size_t size) noexcept {
  const double* const end{values + size};
  for (; values < end; ++values) {
    ConversionFromStandard<Unit, NewUnit>(*values);
  }
}

// Function for converting a series of values expressed in any given unit of
// measure of a given type to the standard unit of measure of that type.
// Internal implementation detail not intended to be used outside of the
// functions: PhQ::Convert, PhQ::ConvertCopy, PhQ::StaticConvert, and
// PhQ::StaticConvertCopy.
template<typename Unit, Unit OriginalUnit> inline constexpr void
ConversionsToStandard(double* values, const std::size_t size) noexcept {
  const double* const end{values + size};
  for (; values < end; ++values) {
    ConversionToStandard<Unit, OriginalUnit>(*values);
  }
}

// Abstract map of functions for converting a series of values expressed in the
// standard unit of measure of a given type to any given unit of measure of that
// type. Internal implementation detail not intended to be used outside of the
// functions: PhQ::Convert, PhQ::ConvertCopy, PhQ::StaticConvert, and
// PhQ::StaticConvertCopy.
template<typename Unit> inline const std::map<
    Unit, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard;

// Abstract map of functions for converting a series of values expressed in any
// given unit of measure of a given type to the standard unit of measure of that
// type. Internal implementation detail not intended to be used outside of the
// functions: PhQ::Convert, PhQ::ConvertCopy, PhQ::StaticConvert, and
// PhQ::StaticConvertCopy.
template<typename Unit> inline const std::map<
    Unit, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsToStandard;

}  // namespace Internal

// Converts a value expressed in a given unit of measure to a new unit of
// measure. The conversion is performed in-place.
template<typename Unit> inline void Convert(
    double& value, const Unit original_unit, const Unit new_unit) noexcept {
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit>.find(original_unit)->second(&value, 1);
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit>.find(new_unit)->second(
        &value, 1);
  }
}

// Converts an array of values expressed in a given unit of measure to a new
// unit of measure. The conversion is performed in-place.
template<typename Unit, std::size_t Size> inline void Convert(
    std::array<double, Size>& values, const Unit original_unit,
    const Unit new_unit) noexcept {
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit>.find(original_unit)->second(&values[0], Size);
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit>.find(new_unit)->second(
        &values[0], Size);
  }
}

// Converts a vector of values expressed in a given unit of measure to a new
// unit of measure. The conversion is performed in-place.
template<typename Unit> inline void Convert(
    std::vector<double>& values, const Unit original_unit,
    const Unit new_unit) noexcept {
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit>.find(original_unit)->second(
        &values[0], values.size());
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit>.find(new_unit)->second(
        &values[0], values.size());
  }
}

// Converts a three-dimensional vector value expressed in a given unit of
// measure to a new unit of measure. The conversion is performed in-place.
template<typename Unit> inline void Convert(
    Value::Vector& value, const Unit original_unit,
    const Unit new_unit) noexcept {
  Convert<Unit, 3>(value.mutable_x_y_z(), original_unit, new_unit);
}

// Converts a symmetric dyadic tensor value expressed in a given unit of measure
// to a new unit of measure. The conversion is performed in-place.
template<typename Unit> inline void Convert(
    Value::SymmetricDyad& value, const Unit original_unit,
    const Unit new_unit) noexcept {
  Convert<Unit, 6>(value.mutable_xx_xy_xz_yy_yz_zz(), original_unit, new_unit);
}

// Converts a dyadic tensor value expressed in a given unit of measure to a new
// unit of measure. The conversion is performed in-place.
template<typename Unit> inline void Convert(
    Value::Dyad& value, const Unit original_unit,
    const Unit new_unit) noexcept {
  Convert<Unit, 9>(
      value.mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz(), original_unit, new_unit);
}

// Converts a value expressed in a given unit of measure to a new unit of
// measure. Returns a copy of the converted value. The original value remains
// unchanged.
template<typename Unit> inline double ConvertCopy(
    const double value, const Unit original_unit,
    const Unit new_unit) noexcept {
  double result{value};
  Convert<Unit>(result, original_unit, new_unit);
  return result;
}

// Converts an array of values expressed in a given unit of measure to a new
// unit of measure. Returns a copy of the converted values. The original values
// remain unchanged.
template<typename Unit, std::size_t Size> inline std::array<double, Size>
ConvertCopy(const std::array<double, Size>& values, const Unit original_unit,
            const Unit new_unit) noexcept {
  std::array<double, Size> result{values};
  Convert<Unit, Size>(result, original_unit, new_unit);
  return result;
}

// Converts a vector of values expressed in a given unit of measure to a new
// unit of measure. Returns a copy of the converted values. The original values
// remain unchanged.
template<typename Unit> inline std::vector<double> ConvertCopy(
    const std::vector<double>& values, const Unit original_unit,
    const Unit new_unit) noexcept {
  std::vector<double> result{values};
  Convert<Unit>(result, original_unit, new_unit);
  return result;
}

// Converts a three-dimensional vector value expressed in a given unit of
// measure to a new unit of measure. Returns a copy of the converted value. The
// original value remains unchanged.
template<typename Unit> inline Value::Vector ConvertCopy(
    const Value::Vector& value, const Unit original_unit,
    const Unit new_unit) noexcept {
  return Value::Vector{
      ConvertCopy<Unit, 3>(value.x_y_z(), original_unit, new_unit)};
}

// Converts a symmetric dyadic tensor value expressed in a given unit of measure
// to a new unit of measure. Returns a copy of the converted value. The original
// value remains unchanged.
template<typename Unit> inline Value::SymmetricDyad ConvertCopy(
    const Value::SymmetricDyad& value, const Unit original_unit,
    const Unit new_unit) noexcept {
  return Value::SymmetricDyad{
      ConvertCopy<Unit, 6>(value.xx_xy_xz_yy_yz_zz(), original_unit, new_unit)};
}

// Converts a dyadic tensor value expressed in a given unit of measure to a new
// unit of measure. Returns a copy of the converted value. The original value
// remains unchanged.
template<typename Unit> inline Value::Dyad ConvertCopy(
    const Value::Dyad& value, const Unit original_unit,
    const Unit new_unit) noexcept {
  return Value::Dyad{ConvertCopy<Unit, 9>(
      value.xx_xy_xz_yx_yy_yz_zx_zy_zz(), original_unit, new_unit)};
}

// Converts a value expressed in a given unit of measure to a new unit of
// measure. The conversion is performed in-place. This function can be evaluated
// at compile time.
template<typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr void StaticConvert(double& value) noexcept {
  Internal::ConversionToStandard<Unit, OriginalUnit>(value);
  Internal::ConversionFromStandard<Unit, NewUnit>(value);
}

// Converts an array of values expressed in a given unit of measure to a new
// unit of measure. The conversion is performed in-place. This function can be
// evaluated at compile time.
template<typename Unit, Unit OriginalUnit, Unit NewUnit, std::size_t Size>
inline constexpr void StaticConvert(std::array<double, Size>& values) noexcept {
  Internal::ConversionsToStandard<Unit, OriginalUnit>(&values[0], Size);
  Internal::ConversionsFromStandard<Unit, NewUnit>(&values[0], Size);
}

// Converts a three-dimensional vector value expressed in a given unit of
// measure to a new unit of measure. The conversion is performed in-place. This
// function can be evaluated at compile time.
template<typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr void StaticConvert(Value::Vector& value) noexcept {
  StaticConvert<Unit, OriginalUnit, NewUnit, 3>(value.mutable_x_y_z());
}

// Converts a symmetric dyadic tensor value expressed in a given unit of measure
// to a new unit of measure. The conversion is performed in-place. This function
// can be evaluated at compile time.
template<typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr void StaticConvert(Value::SymmetricDyad& value) noexcept {
  StaticConvert<Unit, OriginalUnit, NewUnit, 6>(
      value.mutable_xx_xy_xz_yy_yz_zz());
}

// Converts a dyadic tensor value expressed in a given unit of measure to a new
// unit of measure. The conversion is performed in-place. This function can be
// evaluated at compile time.
template<typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr void StaticConvert(Value::Dyad& value) noexcept {
  StaticConvert<Unit, OriginalUnit, NewUnit, 9>(
      value.mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz());
}

// Converts a value expressed in a given unit of measure to a new unit of
// measure. Returns a copy of the converted value. The original value remains
// unchanged. This function can be evaluated at compile time.
template<typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr double StaticConvertCopy(const double value) noexcept {
  double result{value};
  Internal::ConversionToStandard<Unit, OriginalUnit>(result);
  Internal::ConversionFromStandard<Unit, NewUnit>(result);
  return result;
}

// Converts an array of values expressed in a given unit of measure to a new
// unit of measure. Returns a copy of the converted values. The original values
// remain unchanged. This function can be evaluated at compile time.
template<typename Unit, Unit OriginalUnit, Unit NewUnit, std::size_t Size>
inline constexpr std::array<double, Size>
StaticConvertCopy(const std::array<double, Size>& values) noexcept {
  std::array<double, Size> result{values};
  Internal::ConversionsToStandard<Unit, OriginalUnit>(&result[0], Size);
  Internal::ConversionsFromStandard<Unit, NewUnit>(&result[0], Size);
  return result;
}

// Converts a three-dimensional vector value expressed in a given unit of
// measure to a new unit of measure. Returns a copy of the converted value. The
// original value remains unchanged. This function can be evaluated at compile
// time.
template<typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr Value::Vector
StaticConvertCopy(const Value::Vector& value) noexcept {
  return Value::Vector{
      StaticConvertCopy<Unit, OriginalUnit, NewUnit, 3>(value.x_y_z())};
}

// Converts a symmetric dyadic tensor value expressed in a given unit of measure
// to a new unit of measure. Returns a copy of the converted value. The original
// value remains unchanged. This function can be evaluated at compile time.
template<typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr Value::SymmetricDyad
StaticConvertCopy(const Value::SymmetricDyad& value) noexcept {
  return Value::SymmetricDyad{StaticConvertCopy<Unit, OriginalUnit, NewUnit, 6>(
      value.xx_xy_xz_yy_yz_zz())};
}

// Converts a dyadic tensor value expressed in a given unit of measure to a new
// unit of measure. Returns a copy of the converted value. The original value
// remains unchanged. This function can be evaluated at compile time.
template<typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr Value::Dyad
StaticConvertCopy(const Value::Dyad& value) noexcept {
  return Value::Dyad{StaticConvertCopy<Unit, OriginalUnit, NewUnit, 9>(
      value.xx_xy_xz_yx_yy_yz_zx_zy_zz())};
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_HPP
