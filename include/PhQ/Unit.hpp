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
template <typename Unit, Unit NewUnit>
inline constexpr void ConversionFromStandard(double& value) noexcept;

// Abstract function for converting a value expressed in any given unit of measure of a given type
// to the standard unit of measure of that type. Internal implementation detail not intended to be
// used outside of the PhQ::Internal::ConversionsToStandard function.
template <typename Unit, Unit OriginalUnit>
inline constexpr void ConversionToStandard(double& value) noexcept;

// Function for converting a series of values expressed in the standard unit of measure of a given
// type to any given unit of measure of that type. Internal implementation detail not intended to be
// used outside of the functions: PhQ::Convert, PhQ::ConvertCopy, and PhQ::StaticConvertCopy.
template <typename Unit, Unit NewUnit>
inline constexpr void ConversionsFromStandard(double* values, const std::size_t size) noexcept {
  const double* const end{values + size};
  for (; values < end; ++values) {
    ConversionFromStandard<Unit, NewUnit>(*values);
  }
}

// Function for converting a series of values expressed in any given unit of measure of a given type
// to the standard unit of measure of that type. Internal implementation detail not intended to be
// used outside of the functions: PhQ::Convert, PhQ::ConvertCopy, and PhQ::StaticConvertCopy.
template <typename Unit, Unit OriginalUnit>
inline constexpr void ConversionsToStandard(double* values, const std::size_t size) noexcept {
  const double* const end{values + size};
  for (; values < end; ++values) {
    ConversionToStandard<Unit, OriginalUnit>(*values);
  }
}

// Abstract map of functions for converting a series of values expressed in the standard unit of
// measure of a given type to any given unit of measure of that type. Internal implementation detail
// not intended to be used outside of the functions: PhQ::Convert, PhQ::ConvertCopy, and
// PhQ::StaticConvertCopy.
template <typename Unit>
inline const std::map<Unit, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard;

// Abstract map of functions for converting a series of values expressed in any given unit of
// measure of a given type to the standard unit of measure of that type. Internal implementation
// detail not intended to be used outside of the functions: PhQ::Convert, PhQ::ConvertCopy, and
// PhQ::StaticConvertCopy.
template <typename Unit>
inline const std::map<Unit, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsToStandard;

}  // namespace Internal

// Converts a value expressed in a given unit of measure to a new unit of measure. The conversion is
// performed in-place.
template <typename Unit>
inline void Convert(double& value, const Unit original_unit, const Unit new_unit) {
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit>.find(original_unit)->second(&value, 1);
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit>.find(new_unit)->second(&value, 1);
  }
}

// Converts an array of values expressed in a given unit of measure to a new unit of measure. The
// conversion is performed in-place.
template <typename Unit, std::size_t Size>
inline void Convert(
    std::array<double, Size>& values, const Unit original_unit, const Unit new_unit) {
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit>.find(original_unit)->second(values.data(), Size);
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit>.find(new_unit)->second(values.data(), Size);
  }
}

// Converts a vector of values expressed in a given unit of measure to a new unit of measure. The
// conversion is performed in-place.
template <typename Unit>
inline void Convert(std::vector<double>& values, const Unit original_unit, const Unit new_unit) {
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit>.find(original_unit)->second(values.data(), values.size());
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit>.find(new_unit)->second(
        values.data(), values.size());
  }
}

// Converts a three-dimensional vector expressed in a given unit of measure to a new unit of
// measure. The conversion is performed in-place.
template <typename Unit>
inline void Convert(Vector& value, const Unit original_unit, const Unit new_unit) {
  Convert<Unit, 3>(value.Mutable_x_y_z(), original_unit, new_unit);
}

// Converts a three-dimensional symmetric dyadic tensor expressed in a given unit of measure to a
// new unit of measure. The conversion is performed in-place.
template <typename Unit>
inline void Convert(SymmetricDyad& value, const Unit original_unit, const Unit new_unit) {
  Convert<Unit, 6>(value.Mutable_xx_xy_xz_yy_yz_zz(), original_unit, new_unit);
}

// Converts a three-dimensional dyadic tensor expressed in a given unit of measure to a new unit of
// measure. The conversion is performed in-place.
template <typename Unit>
inline void Convert(Dyad& value, const Unit original_unit, const Unit new_unit) {
  Convert<Unit, 9>(value.Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz(), original_unit, new_unit);
}

// Converts a value expressed in a given unit of measure to a new unit of measure. Returns a copy of
// the converted value. The original value remains unchanged.
template <typename Unit>
inline double ConvertCopy(const double value, const Unit original_unit, const Unit new_unit) {
  double result{value};
  Convert<Unit>(result, original_unit, new_unit);
  return result;
}

// Converts an array of values expressed in a given unit of measure to a new unit of measure.
// Returns a copy of the converted values. The original values remain unchanged.
template <typename Unit, std::size_t Size>
inline std::array<double, Size> ConvertCopy(
    const std::array<double, Size>& values, const Unit original_unit, const Unit new_unit) {
  std::array<double, Size> result{values};
  Convert<Unit, Size>(result, original_unit, new_unit);
  return result;
}

// Converts a vector of values expressed in a given unit of measure to a new unit of measure.
// Returns a copy of the converted values. The original values remain unchanged.
template <typename Unit>
inline std::vector<double> ConvertCopy(
    const std::vector<double>& values, const Unit original_unit, const Unit new_unit) {
  std::vector<double> result{values};
  Convert<Unit>(result, original_unit, new_unit);
  return result;
}

// Converts a three-dimensional vector expressed in a given unit of measure to a new unit of
// measure. Returns a copy of the converted value. The original value remains unchanged.
template <typename Unit>
inline Vector ConvertCopy(const Vector& value, const Unit original_unit, const Unit new_unit) {
  return Vector{ConvertCopy<Unit, 3>(value.x_y_z(), original_unit, new_unit)};
}

// Converts a three-dimensional symmetric dyadic tensor expressed in a given unit of measure to a
// new unit of measure. Returns a copy of the converted value. The original value remains unchanged.
template <typename Unit>
inline SymmetricDyad ConvertCopy(
    const SymmetricDyad& value, const Unit original_unit, const Unit new_unit) {
  return SymmetricDyad{ConvertCopy<Unit, 6>(value.xx_xy_xz_yy_yz_zz(), original_unit, new_unit)};
}

// Converts a three-dimensional dyadic tensor expressed in a given unit of measure to a new unit of
// measure. Returns a copy of the converted value. The original value remains unchanged.
template <typename Unit>
inline Dyad ConvertCopy(const Dyad& value, const Unit original_unit, const Unit new_unit) {
  return Dyad{ConvertCopy<Unit, 9>(value.xx_xy_xz_yx_yy_yz_zx_zy_zz(), original_unit, new_unit)};
}

// Converts a value expressed in a given unit of measure to a new unit of measure. Returns a copy of
// the converted value. The original value remains unchanged. This function can be evaluated at
// compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr double StaticConvertCopy(const double value) {
  double result{value};
  Internal::ConversionToStandard<Unit, OriginalUnit>(result);
  Internal::ConversionFromStandard<Unit, NewUnit>(result);
  return result;
}

// Converts an array of values expressed in a given unit of measure to a new unit of measure.
// Returns a copy of the converted values. The original values remain unchanged. This function can
// be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, std::size_t Size>
inline constexpr std::array<double, Size> StaticConvertCopy(
    const std::array<double, Size>& values) {
  std::array<double, Size> result{values};
  Internal::ConversionsToStandard<Unit, OriginalUnit>(result.data(), Size);
  Internal::ConversionsFromStandard<Unit, NewUnit>(result.data(), Size);
  return result;
}

// Converts a three-dimensional vector expressed in a given unit of measure to a new unit of
// measure. Returns a copy of the converted value. The original value remains unchanged. This
// function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr Vector StaticConvertCopy(const Vector& value) {
  return Vector{StaticConvertCopy<Unit, OriginalUnit, NewUnit, 3>(value.x_y_z())};
}

// Converts a three-dimensional symmetric dyadic tensor expressed in a given unit of measure to a
// new unit of measure. Returns a copy of the converted value. The original value remains unchanged.
// This function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr SymmetricDyad StaticConvertCopy(const SymmetricDyad& value) {
  return SymmetricDyad{
      StaticConvertCopy<Unit, OriginalUnit, NewUnit, 6>(value.xx_xy_xz_yy_yz_zz())};
}

// Converts a three-dimensional dyadic tensor expressed in a given unit of measure to a new unit of
// measure. Returns a copy of the converted value. The original value remains unchanged. This
// function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
inline constexpr Dyad StaticConvertCopy(const Dyad& value) {
  return Dyad{
      StaticConvertCopy<Unit, OriginalUnit, NewUnit, 9>(value.xx_xy_xz_yx_yy_yz_zx_zy_zz())};
}

}  // namespace PhQ

#endif  // PHQ_UNIT_HPP
