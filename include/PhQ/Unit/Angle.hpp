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

#ifndef PHQ_UNIT_ANGLE_HPP
#define PHQ_UNIT_ANGLE_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimension/ElectricCurrent.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/LuminousIntensity.hpp"
#include "../Dimension/Mass.hpp"
#include "../Dimension/SubstanceAmount.hpp"
#include "../Dimension/Temperature.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

/// \brief Angle units.
enum class Angle : int8_t {
  /// \brief Radian (rad) angle unit.
  Radian,

  /// \brief Degree (deg) angle unit.
  Degree,

  /// \brief Arcminute (arcmin) angle unit.
  Arcminute,

  /// \brief Arcsecond (arcsec) angle unit.
  Arcsecond,

  /// \brief Revolution (rev) angle unit.
  Revolution,
};

}  // namespace Unit

/// \brief Standard angle unit: radian (rad).
template <>
inline constexpr const Unit::Angle Standard<Unit::Angle>{Unit::Angle::Radian};

/// \brief Physical dimension set of angle units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Angle>{Dimensionless};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Angle unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Angle> ConsistentUnits<Unit::Angle>{
  {UnitSystem::MetreKilogramSecondKelvin,  Unit::Angle::Radian},
  {UnitSystem::MillimetreGramSecondKelvin, Unit::Angle::Radian},
  {UnitSystem::FootPoundSecondRankine,     Unit::Angle::Radian},
  {UnitSystem::InchPoundSecondRankine,     Unit::Angle::Radian},
};

template <>
inline const std::map<Unit::Angle, UnitSystem> RelatedUnitSystems<Unit::Angle>{};

template <>
inline const std::map<Unit::Angle, std::string_view> Abbreviations<Unit::Angle>{
  {Unit::Angle::Radian,     "rad"   },
  {Unit::Angle::Degree,     "deg"   },
  {Unit::Angle::Arcminute,  "arcmin"},
  {Unit::Angle::Arcsecond,  "arcsec"},
  {Unit::Angle::Revolution, "rev"   },
};

// clang-format off

template <>
inline const std::unordered_map<std::string_view, Unit::Angle> Spellings<Unit::Angle>{
    {"rad",         Unit::Angle::Radian    },
    {"radian",      Unit::Angle::Radian    },
    {"radians",     Unit::Angle::Radian    },
    {"deg",         Unit::Angle::Degree    },
    {"degree",      Unit::Angle::Degree    },
    {"degrees",     Unit::Angle::Degree    },
    {"°",           Unit::Angle::Degree    },
    {"'",           Unit::Angle::Arcminute },
    {"am",          Unit::Angle::Arcminute },
    {"arcmin",      Unit::Angle::Arcminute },
    {"arcminute",   Unit::Angle::Arcminute },
    {"arcminutes",  Unit::Angle::Arcminute },
    {"\"",          Unit::Angle::Arcsecond },
    {"as",          Unit::Angle::Arcsecond },
    {"arcs",        Unit::Angle::Arcsecond },
    {"arcsec",      Unit::Angle::Arcsecond },
    {"arcsecond",   Unit::Angle::Arcsecond },
    {"arcseconds",  Unit::Angle::Arcsecond },
    {"rev",         Unit::Angle::Revolution},
    {"revolution",  Unit::Angle::Revolution},
    {"revolutions", Unit::Angle::Revolution},
};

// clang-format on

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Radian>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Radian>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Degree>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(180.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Degree>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(180.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Arcminute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(10800.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Arcminute>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(10800.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Arcsecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(648000.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Arcsecond>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(648000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Revolution>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.5L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Revolution>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(2.0L) * Pi<NumericType>;
}

template <typename NumericType>
inline const std::map<Unit::Angle, std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Angle, NumericType>{
      {Unit::Angle::Radian,
       Conversions<Unit::Angle, Unit::Angle::Radian>::FromStandard<NumericType>    },
      {Unit::Angle::Degree,
       Conversions<Unit::Angle, Unit::Angle::Degree>::FromStandard<NumericType>    },
      {Unit::Angle::Arcminute,
       Conversions<Unit::Angle, Unit::Angle::Arcminute>::FromStandard<NumericType> },
      {Unit::Angle::Arcsecond,
       Conversions<Unit::Angle, Unit::Angle::Arcsecond>::FromStandard<NumericType> },
      {Unit::Angle::Revolution,
       Conversions<Unit::Angle, Unit::Angle::Revolution>::FromStandard<NumericType>},
};

template <typename NumericType>
inline const std::
    map<Unit::Angle, std::function<void(NumericType* const values, const std::size_t size)>>
        MapOfConversionsToStandard<Unit::Angle, NumericType>{
          {Unit::Angle::Radian,
           Conversions<Unit::Angle, Unit::Angle::Radian>::ToStandard<NumericType>    },
          {Unit::Angle::Degree,
           Conversions<Unit::Angle, Unit::Angle::Degree>::ToStandard<NumericType>    },
          {Unit::Angle::Arcminute,
           Conversions<Unit::Angle, Unit::Angle::Arcminute>::ToStandard<NumericType> },
          {Unit::Angle::Arcsecond,
           Conversions<Unit::Angle, Unit::Angle::Arcsecond>::ToStandard<NumericType> },
          {Unit::Angle::Revolution,
           Conversions<Unit::Angle, Unit::Angle::Revolution>::ToStandard<NumericType>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ANGLE_HPP
