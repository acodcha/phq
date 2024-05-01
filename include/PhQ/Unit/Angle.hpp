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
inline constexpr void ConversionFromStandard<Unit::Angle, Unit::Angle::Radian>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionToStandard<Unit::Angle, Unit::Angle::Radian>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionFromStandard<Unit::Angle, Unit::Angle::Degree>(
    double& value) noexcept {
  value *= 180.0 / Pi<double>;
}

template <>
inline constexpr void ConversionToStandard<Unit::Angle, Unit::Angle::Degree>(
    double& value) noexcept {
  value *= Pi<double> / 180.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Angle, Unit::Angle::Arcminute>(
    double& value) noexcept {
  value *= 10800.0 / Pi<double>;
}

template <>
inline constexpr void ConversionToStandard<Unit::Angle, Unit::Angle::Arcminute>(
    double& value) noexcept {
  value *= Pi<double> / 10800.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Angle, Unit::Angle::Arcsecond>(
    double& value) noexcept {
  value *= 648000.0 / Pi<double>;
}

template <>
inline constexpr void ConversionToStandard<Unit::Angle, Unit::Angle::Arcsecond>(
    double& value) noexcept {
  value *= Pi<double> / 648000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Angle, Unit::Angle::Revolution>(
    double& value) noexcept {
  value *= 0.5 / Pi<double>;
}

template <>
inline constexpr void ConversionToStandard<Unit::Angle, Unit::Angle::Revolution>(
    double& value) noexcept {
  value *= 2.0 * Pi<double>;
}

template <>
inline const std::map<Unit::Angle, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Angle>{
        {Unit::Angle::Radian,     ConversionsFromStandard<Unit::Angle, Unit::Angle::Radian>    },
        {Unit::Angle::Degree,     ConversionsFromStandard<Unit::Angle, Unit::Angle::Degree>    },
        {Unit::Angle::Arcminute,  ConversionsFromStandard<Unit::Angle, Unit::Angle::Arcminute> },
        {Unit::Angle::Arcsecond,  ConversionsFromStandard<Unit::Angle, Unit::Angle::Arcsecond> },
        {Unit::Angle::Revolution, ConversionsFromStandard<Unit::Angle, Unit::Angle::Revolution>},
};

template <>
inline const std::map<Unit::Angle,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Angle>{
        {Unit::Angle::Radian,     ConversionsToStandard<Unit::Angle, Unit::Angle::Radian>    },
        {Unit::Angle::Degree,     ConversionsToStandard<Unit::Angle, Unit::Angle::Degree>    },
        {Unit::Angle::Arcminute,  ConversionsToStandard<Unit::Angle, Unit::Angle::Arcminute> },
        {Unit::Angle::Arcsecond,  ConversionsToStandard<Unit::Angle, Unit::Angle::Arcsecond> },
        {Unit::Angle::Revolution, ConversionsToStandard<Unit::Angle, Unit::Angle::Revolution>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ANGLE_HPP
