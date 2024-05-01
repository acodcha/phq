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

#ifndef PHQ_UNIT_HPP
#define PHQ_UNIT_HPP

#include <functional>
#include <vector>

#include "Dimensions.hpp"
#include "Dyad.hpp"
#include "SymmetricDyad.hpp"
#include "UnitSystem.hpp"
#include "Vector.hpp"

namespace PhQ {

// Namespace that contains units of measure.
namespace Unit {}

// Physical dimension set of a given type of unit of measure. Units of measure are organized into
// types that share the same physical dimension set.
template <typename Unit>
inline constexpr Dimensions RelatedDimensions;

namespace Internal {

// Abstract function for converting a value expressed in the standard unit of measure of a given
// type to any given unit of measure of that type. Internal implementation detail not intended to be
// used outside of the PhQ::Internal::ConversionsFromStandard function.
template <typename Unit, Unit NewUnit, typename NumberType = double>
inline constexpr void ConversionFromStandard(NumberType& value) noexcept;

// Abstract function for converting a value expressed in any given unit of measure of a given type
// to the standard unit of measure of that type. Internal implementation detail not intended to be
// used outside of the PhQ::Internal::ConversionsToStandard function.
template <typename Unit, Unit OriginalUnit, typename NumberType = double>
inline constexpr void ConversionToStandard(NumberType& value) noexcept;

// Function for converting a series of values expressed in the standard unit of measure of a given
// type to any given unit of measure of that type. Internal implementation detail not intended to be
// used outside of the functions: PhQ::Convert, PhQ::ConvertCopy, and PhQ::StaticConvertCopy.
template <typename Unit, Unit NewUnit, typename NumberType = double>
inline constexpr void ConversionsFromStandard(NumberType* values, const std::size_t size) noexcept {
  const NumberType* const end{values + size};
  for (; values < end; ++values) {
    ConversionFromStandard<Unit, NewUnit, NumberType>(*values);
  }
}

// Function for converting a series of values expressed in any given unit of measure of a given type
// to the standard unit of measure of that type. Internal implementation detail not intended to be
// used outside of the functions: PhQ::Convert, PhQ::ConvertCopy, and PhQ::StaticConvertCopy.
template <typename Unit, Unit OriginalUnit, typename NumberType = double>
inline constexpr void ConversionsToStandard(NumberType* values, const std::size_t size) noexcept {
  const NumberType* const end{values + size};
  for (; values < end; ++values) {
    ConversionToStandard<Unit, OriginalUnit, NumberType>(*values);
  }
}

// Abstract map of functions for converting a series of values expressed in the standard unit of
// measure of a given type to any given unit of measure of that type. Internal implementation detail
// not intended to be used outside of the functions: PhQ::Convert, PhQ::ConvertCopy, and
// PhQ::StaticConvertCopy.
template <typename Unit, typename NumberType = double>
inline const std::map<Unit, std::function<void(NumberType* values, const std::size_t size)>>
    MapOfConversionsFromStandard;

// Abstract map of functions for converting a series of values expressed in any given unit of
// measure of a given type to the standard unit of measure of that type. Internal implementation
// detail not intended to be used outside of the functions: PhQ::Convert, PhQ::ConvertCopy, and
// PhQ::StaticConvertCopy.
template <typename Unit, typename NumberType = double>
inline const std::map<Unit, std::function<void(NumberType* values, const std::size_t size)>>
    MapOfConversionsToStandard;

}  // namespace Internal

// Converts a value expressed in a given unit of measure to a new unit of measure. The conversion is
// performed in-place.
template <typename Unit, typename NumberType = double>
inline void Convert(NumberType& value, const Unit original_unit, const Unit new_unit) {
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit, NumberType>.find(original_unit)->second(&value, 1);
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit, NumberType>.find(new_unit)->second(&value, 1);
  }
}

// Converts an array of values expressed in a given unit of measure to a new unit of measure. The
// conversion is performed in-place.
template <typename Unit, std::size_t Size, typename NumberType = double>
inline void Convert(
    std::array<NumberType, Size>& values, const Unit original_unit, const Unit new_unit) {
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit, NumberType>.find(original_unit)->second(values.data(), Size);
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit, NumberType>.find(new_unit)->second(
        values.data(), Size);
  }
}

// Converts a vector of values expressed in a given unit of measure to a new unit of measure. The
// conversion is performed in-place.
template <typename Unit, typename NumberType = double>
inline void Convert(
    std::vector<NumberType>& values, const Unit original_unit, const Unit new_unit) {
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit, NumberType>.find(original_unit)->second(values.data(), values.size());
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit, NumberType>.find(new_unit)->second(
        values.data(), values.size());
  }
}

// Converts a three-dimensional vector expressed in a given unit of measure to a new unit of
// measure. The conversion is performed in-place.
template <typename Unit, typename NumberType = double>
inline void Convert(Vector<NumberType>& value, const Unit original_unit, const Unit new_unit) {
  Convert<Unit, 3, NumberType>(value.Mutable_x_y_z(), original_unit, new_unit);
}

// Converts a three-dimensional symmetric dyadic tensor expressed in a given unit of measure to a
// new unit of measure. The conversion is performed in-place.
template <typename Unit, typename NumberType = double>
inline void Convert(
    SymmetricDyad<NumberType>& value, const Unit original_unit, const Unit new_unit) {
  Convert<Unit, 6, NumberType>(value.Mutable_xx_xy_xz_yy_yz_zz(), original_unit, new_unit);
}

// Converts a three-dimensional dyadic tensor expressed in a given unit of measure to a new unit of
// measure. The conversion is performed in-place.
template <typename Unit, typename NumberType = double>
inline void Convert(Dyad<NumberType>& value, const Unit original_unit, const Unit new_unit) {
  Convert<Unit, 9, NumberType>(value.Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz(), original_unit, new_unit);
}

// Converts a value expressed in a given unit of measure to a new unit of measure. Returns a copy of
// the converted value. The original value remains unchanged.
template <typename Unit, typename NumberType = double>
inline NumberType ConvertCopy(
    const NumberType value, const Unit original_unit, const Unit new_unit) {
  NumberType result{value};
  Convert<Unit, NumberType>(result, original_unit, new_unit);
  return result;
}

// Converts an array of values expressed in a given unit of measure to a new unit of measure.
// Returns a copy of the converted values. The original values remain unchanged.
template <typename Unit, std::size_t Size, typename NumberType = double>
inline std::array<NumberType, Size> ConvertCopy(
    const std::array<NumberType, Size>& values, const Unit original_unit, const Unit new_unit) {
  std::array<NumberType, Size> result{values};
  Convert<Unit, Size, NumberType>(result, original_unit, new_unit);
  return result;
}

// Converts a vector of values expressed in a given unit of measure to a new unit of measure.
// Returns a copy of the converted values. The original values remain unchanged.
template <typename Unit, typename NumberType = double>
inline std::vector<NumberType> ConvertCopy(
    const std::vector<NumberType>& values, const Unit original_unit, const Unit new_unit) {
  std::vector<NumberType> result{values};
  Convert<Unit, NumberType>(result, original_unit, new_unit);
  return result;
}

// Converts a three-dimensional vector expressed in a given unit of measure to a new unit of
// measure. Returns a copy of the converted value. The original value remains unchanged.
template <typename Unit, typename NumberType = double>
inline Vector<NumberType> ConvertCopy(
    const Vector<NumberType>& value, const Unit original_unit, const Unit new_unit) {
  return Vector{ConvertCopy<Unit, 3, NumberType>(value.x_y_z(), original_unit, new_unit)};
}

// Converts a three-dimensional symmetric dyadic tensor expressed in a given unit of measure to a
// new unit of measure. Returns a copy of the converted value. The original value remains unchanged.
template <typename Unit, typename NumberType = double>
inline SymmetricDyad<NumberType> ConvertCopy(
    const SymmetricDyad<NumberType>& value, const Unit original_unit, const Unit new_unit) {
  return SymmetricDyad{
      ConvertCopy<Unit, 6, NumberType>(value.xx_xy_xz_yy_yz_zz(), original_unit, new_unit)};
}

// Converts a three-dimensional dyadic tensor expressed in a given unit of measure to a new unit of
// measure. Returns a copy of the converted value. The original value remains unchanged.
template <typename Unit, typename NumberType = double>
inline Dyad<NumberType> ConvertCopy(
    const Dyad<NumberType>& value, const Unit original_unit, const Unit new_unit) {
  return Dyad{ConvertCopy<Unit, 9, NumberType>(
      value.xx_xy_xz_yx_yy_yz_zx_zy_zz(), original_unit, new_unit)};
}

// Converts a value expressed in a given unit of measure to a new unit of measure. Returns a copy of
// the converted value. The original value remains unchanged. This function can be evaluated at
// compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename NumberType = double>
inline constexpr NumberType StaticConvertCopy(const NumberType value) {
  NumberType result{value};
  Internal::ConversionToStandard<Unit, OriginalUnit, NumberType>(result);
  Internal::ConversionFromStandard<Unit, NewUnit, NumberType>(result);
  return result;
}

// Converts an array of values expressed in a given unit of measure to a new unit of measure.
// Returns a copy of the converted values. The original values remain unchanged. This function can
// be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, std::size_t Size,
          typename NumberType = double>
inline constexpr std::array<NumberType, Size> StaticConvertCopy(
    const std::array<NumberType, Size>& values) {
  std::array<NumberType, Size> result{values};
  Internal::ConversionsToStandard<Unit, OriginalUnit, NumberType>(result.data(), Size);
  Internal::ConversionsFromStandard<Unit, NewUnit, NumberType>(result.data(), Size);
  return result;
}

// Converts a three-dimensional vector expressed in a given unit of measure to a new unit of
// measure. Returns a copy of the converted value. The original value remains unchanged. This
// function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename NumberType = double>
inline constexpr Vector<NumberType> StaticConvertCopy(const Vector<NumberType>& value) {
  return Vector{StaticConvertCopy<Unit, OriginalUnit, NewUnit, 3, NumberType>(value.x_y_z())};
}

// Converts a three-dimensional symmetric dyadic tensor expressed in a given unit of measure to a
// new unit of measure. Returns a copy of the converted value. The original value remains unchanged.
// This function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename NumberType = double>
inline constexpr SymmetricDyad<NumberType> StaticConvertCopy(
    const SymmetricDyad<NumberType>& value) {
  return SymmetricDyad{
      StaticConvertCopy<Unit, OriginalUnit, NewUnit, 6, NumberType>(value.xx_xy_xz_yy_yz_zz())};
}

// Converts a three-dimensional dyadic tensor expressed in a given unit of measure to a new unit of
// measure. Returns a copy of the converted value. The original value remains unchanged. This
// function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename NumberType = double>
inline constexpr Dyad<NumberType> StaticConvertCopy(const Dyad<NumberType>& value) {
  return Dyad{StaticConvertCopy<Unit, OriginalUnit, NewUnit, 9, NumberType>(
      value.xx_xy_xz_yx_yy_yz_zx_zy_zz())};
}

}  // namespace PhQ

#endif  // PHQ_UNIT_HPP
