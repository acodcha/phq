// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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
/// outside of the PhQ::ConvertInPlace, PhQ::Convert, and PhQ::ConvertStatically functions.
template <typename Unit, Unit UnitValue>
class Conversion {
public:
  /// \brief Converts a value expressed in the standard unit of measure of a given unit type to any
  /// given unit of measure of that type. Internal implementation detail not intended to be used
  /// outside of the PhQ::ConvertInPlace, PhQ::Convert, and PhQ::ConvertStatically functions.
  template <typename NumericType>
  static inline constexpr void FromStandard(NumericType& value) noexcept;

  /// \brief Converts a value expressed in any given unit of measure of a given unit type to the
  /// standard unit of measure of that type. Internal implementation detail not intended to be used
  /// outside of the PhQ::ConvertInPlace, PhQ::Convert, and PhQ::ConvertStatically functions.
  template <typename NumericType>
  static inline constexpr void ToStandard(NumericType& value) noexcept;
};

/// \brief Abstract class for converting a sequence of values expressed in a unit of measure to or
/// from the standard unit of measure of that type. Internal implementation detail not intended to
/// be used outside of the PhQ::ConvertInPlace, PhQ::Convert, and PhQ::ConvertStatically functions.
template <typename Unit, Unit UnitValue>
class Conversions {
public:
  /// \brief Converts a sequence of values expressed in the standard unit of measure of a given unit
  /// type to any given unit of measure of that type. Internal implementation detail not intended to
  /// be used outside of the PhQ::ConvertInPlace, PhQ::Convert, and PhQ::ConvertStatically
  /// functions.
  template <typename NumericType>
  static inline constexpr void FromStandard(NumericType* values, const std::size_t size) noexcept {
    static_assert(std::is_floating_point<NumericType>::value,
                  "The NumericType template parameter of PhQ::Conversions::FromStandard must be a "
                  "numeric floating-point type: float, double, or long double.");
    const NumericType* const end{values + size};
    for (; values < end; ++values) {
      Conversion<Unit, UnitValue>::FromStandard(*values);
    }
  }

  /// \brief Converts a sequence of values expressed in any given unit of measure of a given unit
  /// type to the standard unit of measure of that type. Internal implementation detail not intended
  /// to be used outside of the PhQ::ConvertInPlace, PhQ::Convert, and PhQ::ConvertStatically
  /// functions.
  template <typename NumericType>
  static inline constexpr void ToStandard(NumericType* values, const std::size_t size) noexcept {
    static_assert(std::is_floating_point<NumericType>::value,
                  "The NumericType template parameter of PhQ::Conversions::ToStandard must be a "
                  "numeric floating-point type: float, double, or long double.");
    const NumericType* const end{values + size};
    for (; values < end; ++values) {
      Conversion<Unit, UnitValue>::ToStandard(*values);
    }
  }
};

/// \brief Abstract map of functions for converting a sequence of values expressed in the standard
/// unit of measure of a given type to any given unit of measure of that type. Internal
/// implementation detail not intended to be used outside of the PhQ::ConvertInPlace, PhQ::Convert,
/// and PhQ::ConvertStatically functions.
template <typename Unit, typename NumericType>
inline const std::map<Unit, std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard;

/// \brief Abstract map of functions for converting a sequence of values expressed in any given unit
/// of measure of a given type to the standard unit of measure of that type. Internal implementation
/// detail not intended to be used outside of the PhQ::ConvertInPlace, PhQ::Convert, and
/// PhQ::ConvertStatically functions.
template <typename Unit, typename NumericType>
inline const std::map<Unit, std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsToStandard;

}  // namespace Internal

/// \brief Converts a value expressed in a given unit of measure to a new unit of measure. The
/// conversion is performed in-place.
template <typename Unit, typename NumericType>
inline void ConvertInPlace(NumericType& value, const Unit original_unit, const Unit new_unit) {
  static_assert(std::is_floating_point<NumericType>::value,
                "The NumericType template parameter of PhQ::ConvertInPlace must be a numeric "
                "floating-point type: float, double, or long double.");
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit, NumericType>.find(original_unit)->second(&value, 1);
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit, NumericType>.find(new_unit)->second(&value, 1);
  }
}

/// \brief Converts an array of values expressed in a given unit of measure to a new unit of
/// measure. The conversion is performed in-place.
template <typename Unit, std::size_t Size, typename NumericType>
inline void ConvertInPlace(
    std::array<NumericType, Size>& values, const Unit original_unit, const Unit new_unit) {
  static_assert(std::is_floating_point<NumericType>::value,
                "The NumericType template parameter of PhQ::ConvertInPlace must be a numeric "
                "floating-point type: float, double, or long double.");
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit, NumericType>.find(original_unit)->second(values.data(), Size);
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit, NumericType>.find(new_unit)->second(
        values.data(), Size);
  }
}

/// \brief Converts a vector of values expressed in a given unit of measure to a new unit of
/// measure. The conversion is performed in-place.
template <typename Unit, typename NumericType>
inline void ConvertInPlace(
    std::vector<NumericType>& values, const Unit original_unit, const Unit new_unit) {
  static_assert(std::is_floating_point<NumericType>::value,
                "The NumericType template parameter of PhQ::ConvertInPlace must be a numeric "
                "floating-point type: float, double, or long double.");
  if (original_unit != Standard<Unit>) {
    Internal::MapOfConversionsToStandard<Unit, NumericType>.find(original_unit)->second(values.data(), values.size());
  }
  if (new_unit != Standard<Unit>) {
    Internal::MapOfConversionsFromStandard<Unit, NumericType>.find(new_unit)->second(
        values.data(), values.size());
  }
}

/// \brief Converts a two-dimensional Euclidean planar vector in the XY plane expressed in a given
/// unit of measure to a new unit of measure. The conversion is performed in-place.
template <typename Unit, typename NumericType>
inline void ConvertInPlace(
    PlanarVector<NumericType>& planar_vector, const Unit original_unit, const Unit new_unit) {
  ConvertInPlace<Unit, 2, NumericType>(planar_vector.Mutable_x_y(), original_unit, new_unit);
}

/// \brief Converts a three-dimensional Euclidean vector expressed in a given unit of measure to a
/// new unit of measure. The conversion is performed in-place.
template <typename Unit, typename NumericType>
inline void ConvertInPlace(
    Vector<NumericType>& vector, const Unit original_unit, const Unit new_unit) {
  ConvertInPlace<Unit, 3, NumericType>(vector.Mutable_x_y_z(), original_unit, new_unit);
}

/// \brief Converts a three-dimensional Euclidean symmetric dyadic tensor expressed in a given unit
/// of measure to a new unit of measure. The conversion is performed in-place.
template <typename Unit, typename NumericType>
inline void ConvertInPlace(
    SymmetricDyad<NumericType>& symmetric_dyad, const Unit original_unit, const Unit new_unit) {
  ConvertInPlace<Unit, 6, NumericType>(
      symmetric_dyad.Mutable_xx_xy_xz_yy_yz_zz(), original_unit, new_unit);
}

/// \brief Converts a three-dimensional Euclidean dyadic tensor expressed in a given unit of measure
/// to a new unit of measure. The conversion is performed in-place.
template <typename Unit, typename NumericType>
inline void ConvertInPlace(Dyad<NumericType>& dyad, const Unit original_unit, const Unit new_unit) {
  ConvertInPlace<Unit, 9, NumericType>(
      dyad.Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz(), original_unit, new_unit);
}

/// \brief Converts a value expressed in a given unit of measure to a new unit of measure. Returns
/// the converted value. The original value remains unchanged.
template <typename Unit, typename NumericType>
inline NumericType Convert(const NumericType value, const Unit original_unit, const Unit new_unit) {
  NumericType result{value};
  ConvertInPlace<Unit, NumericType>(result, original_unit, new_unit);
  return result;
}

/// \brief Converts an array of values expressed in a given unit of measure to a new unit of
/// measure. Returns the converted values. The original values remain unchanged.
template <typename Unit, std::size_t Size, typename NumericType>
inline std::array<NumericType, Size> Convert(
    const std::array<NumericType, Size>& values, const Unit original_unit, const Unit new_unit) {
  std::array<NumericType, Size> result{values};
  ConvertInPlace<Unit, Size, NumericType>(result, original_unit, new_unit);
  return result;
}

/// \brief Converts a vector of values expressed in a given unit of measure to a new unit of
/// measure. Returns the converted values. The original values remain unchanged.
template <typename Unit, typename NumericType>
inline std::vector<NumericType> Convert(
    const std::vector<NumericType>& values, const Unit original_unit, const Unit new_unit) {
  std::vector<NumericType> result{values};
  ConvertInPlace<Unit, NumericType>(result, original_unit, new_unit);
  return result;
}

/// \brief Converts a two-dimensional Euclidean planar vector in the XY plane expressed in a given
/// unit of measure to a new unit of measure. Returns the converted vector. The original vector
/// remains unchanged.
template <typename Unit, typename NumericType>
inline PlanarVector<NumericType> Convert(
    const PlanarVector<NumericType>& planar_vector, const Unit original_unit, const Unit new_unit) {
  return PlanarVector{Convert<Unit, 2, NumericType>(planar_vector.x_y(), original_unit, new_unit)};
}

/// \brief Converts a three-dimensional Euclidean vector expressed in a given unit of measure to a
/// new unit of measure. Returns the converted vector. The original vector remains unchanged.
template <typename Unit, typename NumericType>
inline Vector<NumericType> Convert(
    const Vector<NumericType>& vector, const Unit original_unit, const Unit new_unit) {
  return Vector{Convert<Unit, 3, NumericType>(vector.x_y_z(), original_unit, new_unit)};
}

/// \brief Converts a three-dimensional Euclidean symmetric dyadic tensor expressed in a given unit
/// of measure to a new unit of measure. Returns the converted tensor. The original tensor remains
/// unchanged.
template <typename Unit, typename NumericType>
inline SymmetricDyad<NumericType> Convert(const SymmetricDyad<NumericType>& symmetric_dyad,
                                          const Unit original_unit, const Unit new_unit) {
  return SymmetricDyad{
      Convert<Unit, 6, NumericType>(symmetric_dyad.xx_xy_xz_yy_yz_zz(), original_unit, new_unit)};
}

/// \brief Converts a three-dimensional Euclidean dyadic tensor expressed in a given unit of measure
/// to a new unit of measure. Returns the converted tensor. The original tensor remains unchanged.
template <typename Unit, typename NumericType>
inline Dyad<NumericType> Convert(
    const Dyad<NumericType>& dyad, const Unit original_unit, const Unit new_unit) {
  return Dyad{
      Convert<Unit, 9, NumericType>(dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz(), original_unit, new_unit)};
}

/// \brief Converts a value expressed in a given unit of measure to a new unit of measure. Returns
/// the converted value. The original value remains unchanged. This function can be evaluated at
/// compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename NumericType>
inline constexpr NumericType ConvertStatically(const NumericType value) {
  static_assert(std::is_floating_point<NumericType>::value,
                "The NumericType template parameter of PhQ::ConvertStatically must be a numeric "
                "floating-point type: float, double, or long double.");
  NumericType result{value};
  Internal::Conversion<Unit, OriginalUnit>::ToStandard(result);
  Internal::Conversion<Unit, NewUnit>::FromStandard(result);
  return result;
}

/// \brief Converts an array of values expressed in a given unit of measure to a new unit of
/// measure. Returns the converted values. The original values remain unchanged. This function can
/// be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, std::size_t Size, typename NumericType>
inline constexpr std::array<NumericType, Size> ConvertStatically(
    const std::array<NumericType, Size>& values) {
  static_assert(std::is_floating_point<NumericType>::value,
                "The NumericType template parameter of PhQ::ConvertStatically must be a numeric "
                "floating-point type: float, double, or long double.");
  std::array<NumericType, Size> result{values};
  Internal::Conversions<Unit, OriginalUnit>::ToStandard(result.data(), Size);
  Internal::Conversions<Unit, NewUnit>::FromStandard(result.data(), Size);
  return result;
}

/// \brief Converts a two-dimensional Euclidean planar vector in the XY plane expressed in a given
/// unit of measure to a new unit of measure. Returns the converted vector. The original vector
/// remains unchanged. This function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename NumericType>
inline constexpr PlanarVector<NumericType> ConvertStatically(
    const PlanarVector<NumericType>& planar_vector) {
  return PlanarVector{
      ConvertStatically<Unit, OriginalUnit, NewUnit, 2, NumericType>(planar_vector.x_y())};
}

/// \brief Converts a three-dimensional Euclidean vector expressed in a given unit of measure to a
/// new unit of measure. Returns the converted vector. The original vector remains unchanged. This
/// function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename NumericType>
inline constexpr Vector<NumericType> ConvertStatically(const Vector<NumericType>& vector) {
  return Vector{ConvertStatically<Unit, OriginalUnit, NewUnit, 3, NumericType>(vector.x_y_z())};
}

/// \brief Converts a three-dimensional Euclidean symmetric dyadic tensor expressed in a given unit
/// of measure to a new unit of measure. Returns the converted tensor. The original tensor remains
/// unchanged. This function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename NumericType>
inline constexpr SymmetricDyad<NumericType> ConvertStatically(
    const SymmetricDyad<NumericType>& symmetric_dyad) {
  return SymmetricDyad{ConvertStatically<Unit, OriginalUnit, NewUnit, 6, NumericType>(
      symmetric_dyad.xx_xy_xz_yy_yz_zz())};
}

/// \brief Converts a three-dimensional Euclidean dyadic tensor expressed in a given unit of measure
/// to a new unit of measure. Returns the converted tensor. The original tensor remains unchanged.
/// This function can be evaluated at compile time.
template <typename Unit, Unit OriginalUnit, Unit NewUnit, typename NumericType>
inline constexpr Dyad<NumericType> ConvertStatically(const Dyad<NumericType>& dyad) {
  return Dyad{ConvertStatically<Unit, OriginalUnit, NewUnit, 9, NumericType>(
      dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz())};
}

}  // namespace PhQ

#endif  // PHQ_UNIT_HPP
