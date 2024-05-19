// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

// Angle units.
enum class Angle : int8_t {
  // Radian (rad) angle unit.
  Radian,

  // Degree (deg) angle unit.
  Degree,

  // Arcminute (arcmin) angle unit.
  Arcminute,

  // Arcsecond (arcsec) angle unit.
  Arcsecond,

  // Revolution (rev) angle unit.
  Revolution,
};

}  // namespace Unit

// Standard angle unit: radian (rad).
template <>
inline constexpr const Unit::Angle Standard<Unit::Angle>{Unit::Angle::Radian};

// Physical dimension set of angle units.
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

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Radian>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Radian>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Degree>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(180.0) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Degree>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(180.0);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Arcminute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(10800.0) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Arcminute>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(10800.0);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Arcsecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(648000.0) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Arcsecond>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(648000.0);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Revolution>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.5) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Angle, Unit::Angle::Revolution>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(2.0) * Pi<Number>;
}

template <typename Number>
inline const std::map<Unit::Angle, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Angle, Number>{
        {Unit::Angle::Radian,     Conversions<Unit::Angle, Unit::Angle::Radian>::FromStandard<Number>    },
        {Unit::Angle::Degree,     Conversions<Unit::Angle, Unit::Angle::Degree>::FromStandard<Number>    },
        {Unit::Angle::Arcminute,
         Conversions<Unit::Angle,                          Unit::Angle::Arcminute>::FromStandard<Number> },
        {Unit::Angle::Arcsecond,
         Conversions<Unit::Angle,                          Unit::Angle::Arcsecond>::FromStandard<Number> },
        {Unit::Angle::Revolution,
         Conversions<Unit::Angle,                          Unit::Angle::Revolution>::FromStandard<Number>},
};

template <typename Number>
inline const std::map<Unit::Angle,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Angle, Number>{
        {Unit::Angle::Radian,     Conversions<Unit::Angle, Unit::Angle::Radian>::ToStandard<Number>    },
        {Unit::Angle::Degree,     Conversions<Unit::Angle, Unit::Angle::Degree>::ToStandard<Number>    },
        {Unit::Angle::Arcminute,
         Conversions<Unit::Angle,                          Unit::Angle::Arcminute>::ToStandard<Number> },
        {Unit::Angle::Arcsecond,
         Conversions<Unit::Angle,                          Unit::Angle::Arcsecond>::ToStandard<Number> },
        {Unit::Angle::Revolution,
         Conversions<Unit::Angle,                          Unit::Angle::Revolution>::ToStandard<Number>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ANGLE_HPP
