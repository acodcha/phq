// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_UNIT_HPP
#define PHQ_UNIT_HPP

#include <functional>
#include <type_traits>
#include <vector>

#include "Dimensions.hpp"
#include "Dyad.hpp"
#include "PlanarVector.hpp"
#include "SymmetricDyad.hpp"
#include "UnitSystem.hpp"
#include "Vector.hpp"

namespace PhQ {

/// \brief Namespace that contains units of measure.
namespace Unit {}

/// \brief Physical dimension set of a given type of unit of measure. Units of measure are organized
/// into types that share the same physical dimension set.
template <typename Unit>
inline constexpr Dimensions RelatedDimensions;

namespace Internal {

/// \brief Abstract class for converting a value expressed in a unit of measure to or from the
/// standard unit of measure of that type. Internal implementation detail not intended to be used
/// outside of the PhQ::Convert, PhQ::ConvertCopy, and PhQ::StaticConvertCopy functions.
template <typename Unit, Unit UnitValue>
class Conversion {
public:
  /// \brief Converts a value expressed in the standard unit of measure of a given unit type to any
  /// given unit of measure of that type. Internal implementation detail not intended to be used
  /// outside of the PhQ::Convert, PhQ::ConvertCopy, and PhQ::StaticConvertCopy functions.
  template <typename Number>
  static inline constexpr void FromStandard(Number& value) noexcept;

  /// \brief Converts a value expressed in any given unit of measure of a given unit type to the
  /// standard unit of measure of that type. Internal implementation detail not intended to be used
  /// outside of the PhQ::Convert, PhQ::ConvertCopy, and PhQ::StaticConvertCopy functions.
  template <typename Number>
  static inline constexpr void ToStandard(Number& value) noexcept;
};

/// \brief Abstract class for converting a series of values expressed in a unit of measure to or
/// from the standard unit of measure of that type. Internal implementation detail not intended to
/// be used outside of the PhQ::Convert, PhQ::ConvertCopy, and PhQ::StaticConvertCopy functions.
template <typename Unit, Unit UnitValue>
class Conversions {
public:
  /// \brief Converts a series of values expressed in the standard unit of measure of a given unit
  /// type to any given unit of measure of that type. Internal implementation detail not intended to
  /// be used outside of the PhQ::Convert, PhQ::ConvertCopy, and PhQ::StaticConvertCopy functions.
  template <typename Number>
  static inline constexpr void FromStandard(Number* values, const std::size_t size) noexcept {
    static_assert(std::is_floating_point<Number>::value,
                  "The Number template parameter of PhQ::Conversions::FromStandard must be a "
                  "floating-point number type.");
    const Number* const end{values + size};
    for (; values < end; ++values) {
      Conversion<Unit, UnitValue>::FromStandard(*values);
    }
  }

  /// \brief Converts a series of values expressed in any given unit of measure of a given unit type
  /// to the standard unit of measure of that type. Internal implementation detail not intended to
  /// be used outside of the PhQ::Convert, PhQ::ConvertCopy, and PhQ::StaticConvertCopy functions.
  template <typename Number>
  static inline constexpr void ToStandard(Number* values, const std::size_t size) noexcept {
    static_assert(std::is_floating_point<Number>::value,
                  "The Number template parameter of PhQ::Conversions::ToStandard must be a "
                  "floating-point number type.");
    const Number* const end{values + size};
    for (; values < end; ++values) {
      Conversion<Unit, UnitValue>::ToStandard(*values);
    }
  }
};

/// \brief Abstract map of functions for converting a series of values expressed in the standard
/// unit of measure of a given type to any given unit of measure of that type. Internal
/// implementation detail not intended to be used outside of the functions: PhQ::Convert,
/// PhQ::ConvertCopy, and PhQ::StaticConvertCopy.
template <typename Unit, typename Number>
inline const std::map<Unit, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard;

/// \brief Abstract map of functions for converting a series of values expressed in any given unit
/// of measure of a given type to the standard unit of measure of that type. Internal implementation
/// detail not intended to be used outside of the functions: PhQ::Convert, PhQ::ConvertCopy, and
/// PhQ::StaticConvertCopy.
template <typename Unit, typename Number>
inline const std::map<Unit, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsToStandard;

}  // namespace Internal

/// \brief Converts a value expressed in a given unit of measure to a new unit of measure. The
/// conversion is performed in-place.
template <typename Unit, typename Number>
inline void Convert(Number& value, const Unit original_unit, const Unit new_unit) {
  static_assert(
      std::is_floating_point<Number>::value,
      "The Number template parameter of PhQ::Convert must be a floating-point number type.");
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit, Number>.find(original_unit)->second(&value, 1);
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit, Number>.find(new_unit)->second(&value, 1);
  }
}

/// \brief Converts an array of values expressed in a given unit of measure to a new unit of
/// measure. The conversion is performed in-place.
template <typename Unit, std::size_t Size, typename Number>
inline void Convert(
    std::array<Number, Size>& values, const Unit original_unit, const Unit new_unit) {
  static_assert(
      std::is_floating_point<Number>::value,
      "The Number template parameter of PhQ::Convert must be a floating-point number type.");
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit, Number>.find(original_unit)->second(values.data(), Size);
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit, Number>.find(new_unit)->second(
        values.data(), Size);
  }
}

/// \brief Converts a vector of values expressed in a given unit of measure to a new unit of
/// measure. The conversion is performed in-place.
template <typename Unit, typename Number>
inline void Convert(std::vector<Number>& values, const Unit original_unit, const Unit new_unit) {
  static_assert(
      std::is_floating_point<Number>::value,
      "The Number template parameter of PhQ::Convert must be a floating-point number type.");
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit, Number>.find(original_unit)->second(values.data(), values.size());
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit, Number>.find(new_unit)->second(
        values.data(), values.size());
  }
}

/// \brief Converts a two-dimensional planar vector in the XY plane expressed in a given unit of
/// measure to a new unit of measure. The conversion is performed in-place.
template <typename Unit, typename Number>
inline void Convert(PlanarVector<Number>& value, const Unit original_unit, const Unit new_unit) {
  Convert<Unit, 2, Number>(value.Mutable_x_y(), original_unit, new_unit);
}

/// \brief Converts a three-dimensional vector expressed in a given unit of measure to a new unit of
/// measure. The conversion is performed in-place.
template <typename Unit, typename Number>
inline void Convert(Vector<Number>& value, const Unit original_unit, const Unit new_unit) {
  Convert<Unit, 3, Number>(value.Mutable_x_y_z(), original_unit, new_unit);
}

/// \brief Converts a three-dimensional symmetric dyadic tensor expressed in a given unit of measure
/// to a new unit of measure. The conversion is performed in-place.
template <typename Unit, typename Number>
inline void Convert(SymmetricDyad<Number>& value, const Unit original_unit, const Unit new_unit) {
  Convert<Unit, 6, Number>(value.Mutable_xx_xy_xz_yy_yz_zz(), original_unit, new_unit);
}

/// \brief Converts a three-dimensional dyadic tensor expressed in a given unit of measure to a new
/// unit of measure. The conversion is performed in-place.
template <typename Unit, typename Number>
inline void Convert(Dyad<Number>& value, const Unit original_unit, const Unit new_unit) {
  Convert<Unit, 9, Number>(value.Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz(), original_unit, new_unit);
}

/// \brief Converts a value expressed in a given unit of measure to a new unit of measure. Returns a
/// copy of the converted value. The original value remains unchanged.
template <typename Unit, typename Number>
inline Number ConvertCopy(const Number value, const Unit original_unit, const Unit new_unit) {
  Number result{value};
  Convert<Unit, Number>(result, original_unit, new_unit);
  return result;
}

/// \brief Converts an array of values expressed in a given unit of measure to a new unit of
/// measure. Returns a copy of the converted values. The original values remain unchanged.
template <typename Unit, std::size_t Size, typename Number>
inline std::array<Number, Size> ConvertCopy(
    const std::array<Number, Size>& values, const Unit original_unit, const Unit new_unit) {
  std::array<Number, Size> result{values};
  Convert<Unit, Size, Number>(result, original_unit, new_unit);
  return result;
}

/// \brief Converts a vector of values expressed in a given unit of measure to a new unit of
/// measure. Returns a copy of the converted values. The original values remain unchanged.
template <typename Unit, typename Number>
inline std::vector<Number> ConvertCopy(
    const std::vector<Number>& values, const Unit original_unit, const Unit new_unit) {
  std::vector<Number> result{values};
  Convert<Unit, Number>(result, original_unit, new_unit);
  return result;
}

/// \brief Converts a two-dimensional planar vector in the XY plane expressed in a given unit of
/// measure to a new unit of measure. Returns a copy of the converted value. The original value
/// remains unchanged.
template <typename Unit, typename Number>
inline PlanarVector<Number> ConvertCopy(
    const PlanarVector<Number>& value, const Unit original_unit, const Unit new_unit) {
  return PlanarVector{ConvertCopy<Unit, 2, Number>(value.x_y(), original_unit, new_unit)};
}

/// \brief Converts a three-dimensional vector expressed in a given unit of measure to a new unit of
/// measure. Returns a copy of the converted value. The original value remains unchanged.
template <typename Unit, typename Number>
inline Vector<Number> ConvertCopy(
    const Vector<Number>& value, const Unit original_unit, const Unit new_unit) {
  return Vector{ConvertCopy<Unit, 3, Number>(value.x_y_z(), original_unit, new_unit)};
}

/// \brief Converts a three-dimensional symmetric dyadic tensor expressed in a given unit of measure
/// to a new unit of measure. Returns a copy of the converted value. The original value remains
/// unchanged.
template <typename Unit, typename Number>
inline SymmetricDyad<Number> ConvertCopy(
    const SymmetricDyad<Number>& value, const Unit original_unit, const Unit new_unit) {
  return SymmetricDyad{
      ConvertCopy<Unit, 6, Number>(value.xx_xy_xz_yy_yz_zz(), original_unit, new_unit)};
}

/// \brief Converts a three-dimensional dyadic tensor expressed in a given unit of measure to a new
/// unit of measure. Returns a copy of the converted value. The original value remains unchanged.
template <typename Unit, typename Number>
inline Dyad<Number> ConvertCopy(
    const Dyad<Number>& value, const Unit original_unit, const Unit new_unit) {
  return Dyad{
      ConvertCopy<Unit, 9, Number>(value.xx_xy_xz_yx_yy_yz_zx_zy_zz(), original_unit, new_unit)};
}

/// \brief Converts a value expressed in a given unit of measure to a new unit of measure. Returns a
/// copy of the converted value. The original value remains unchanged. This function can be
/// evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename Number>
inline constexpr Number StaticConvertCopy(const Number value) {
  static_assert(std::is_floating_point<Number>::value,
                "The Number template parameter of PhQ::StaticConvertCopy must be a floating-point "
                "number type.");
  Number result{value};
  Internal::Conversion<Unit, OriginalUnit>::ToStandard(result);
  Internal::Conversion<Unit, NewUnit>::FromStandard(result);
  return result;
}

/// \brief Converts an array of values expressed in a given unit of measure to a new unit of
/// measure. Returns a copy of the converted values. The original values remain unchanged. This
/// function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, std::size_t Size, typename Number>
inline constexpr std::array<Number, Size> StaticConvertCopy(
    const std::array<Number, Size>& values) {
  static_assert(std::is_floating_point<Number>::value,
                "The Number template parameter of PhQ::StaticConvertCopy must be a floating-point "
                "number type.");
  std::array<Number, Size> result{values};
  Internal::Conversions<Unit, OriginalUnit>::ToStandard(result.data(), Size);
  Internal::Conversions<Unit, NewUnit>::FromStandard(result.data(), Size);
  return result;
}

/// \brief Converts a two-dimensional planar vector in the XY plane expressed in a given unit of
/// measure to a new unit of measure. Returns a copy of the converted value. The original value
/// remains unchanged. This function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename Number>
inline constexpr PlanarVector<Number> StaticConvertCopy(const PlanarVector<Number>& value) {
  return PlanarVector{StaticConvertCopy<Unit, OriginalUnit, NewUnit, 2, Number>(value.x_y())};
}

/// \brief Converts a three-dimensional vector expressed in a given unit of measure to a new unit of
/// measure. Returns a copy of the converted value. The original value remains unchanged. This
/// function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename Number>
inline constexpr Vector<Number> StaticConvertCopy(const Vector<Number>& value) {
  return Vector{StaticConvertCopy<Unit, OriginalUnit, NewUnit, 3, Number>(value.x_y_z())};
}

/// \brief Converts a three-dimensional symmetric dyadic tensor expressed in a given unit of measure
/// to a new unit of measure. Returns a copy of the converted value. The original value remains
/// unchanged. This function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename Number>
inline constexpr SymmetricDyad<Number> StaticConvertCopy(const SymmetricDyad<Number>& value) {
  return SymmetricDyad{
      StaticConvertCopy<Unit, OriginalUnit, NewUnit, 6, Number>(value.xx_xy_xz_yy_yz_zz())};
}

/// \brief Converts a three-dimensional dyadic tensor expressed in a given unit of measure to a new
/// unit of measure. Returns a copy of the converted value. The original value remains unchanged.
/// This function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename Number>
inline constexpr Dyad<Number> StaticConvertCopy(const Dyad<Number>& value) {
  return Dyad{StaticConvertCopy<Unit, OriginalUnit, NewUnit, 9, Number>(
      value.xx_xy_xz_yx_yy_yz_zx_zy_zz())};
}

}  // namespace PhQ

#endif  // PHQ_UNIT_HPP
