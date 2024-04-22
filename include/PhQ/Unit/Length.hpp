// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_LENGTH_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_LENGTH_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

// Length units.
enum class Length : int8_t {
  // Nautical mile (nmi) length unit.
  NauticalMile,

  // Mile (mi) length unit.
  Mile,

  // Kilometre (km) length unit.
  Kilometre,

  // Metre (m) length unit.
  Metre,

  // Yard (yd) length unit.
  Yard,

  // Foot (ft) length unit.
  Foot,

  // Decimetre (dm) length unit.
  Decimetre,

  // Inch (in) length unit.
  Inch,

  // Centimetre (cm) length unit.
  Centimetre,

  // Millimetre (mm) length unit.
  Millimetre,

  // Milliinch (mil) length unit.
  Milliinch,

  // Micrometre (μm) length unit.
  Micrometre,

  // Microinch (μin) length unit.
  Microinch,
};

}  // namespace Unit

// Standard length unit: metre (m).
template <>
inline constexpr const Unit::Length Standard<Unit::Length>{Unit::Length::Metre};

// Physical dimension set of length units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Length>{
    Dimensions{Dimension::Time{0}, Dimension::Length{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Length unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Length> ConsistentUnits<Unit::Length>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Length::Metre     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Length::Millimetre},
    {UnitSystem::FootPoundSecondRankine,     Unit::Length::Foot      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Length::Inch      },
};

template <>
inline const std::map<Unit::Length, UnitSystem> RelatedUnitSystems<Unit::Length>{
    {Unit::Length::Metre,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Length::Millimetre, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Length::Foot,       UnitSystem::FootPoundSecondRankine    },
    {Unit::Length::Inch,       UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::Length, std::string_view> Abbreviations<Unit::Length>{
    {Unit::Length::NauticalMile, "nmi"},
    {Unit::Length::Mile,         "mi" },
    {Unit::Length::Kilometre,    "km" },
    {Unit::Length::Metre,        "m"  },
    {Unit::Length::Yard,         "yd" },
    {Unit::Length::Foot,         "ft" },
    {Unit::Length::Decimetre,    "dm" },
    {Unit::Length::Inch,         "in" },
    {Unit::Length::Centimetre,   "cm" },
    {Unit::Length::Millimetre,   "mm" },
    {Unit::Length::Milliinch,    "mil"},
    {Unit::Length::Micrometre,   "μm" },
    {Unit::Length::Microinch,    "μin"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Length> Spellings<Unit::Length>{
    {"nmi",            Unit::Length::NauticalMile},
    {"NM",             Unit::Length::NauticalMile},
    {"nautical mile",  Unit::Length::NauticalMile},
    {"nautical miles", Unit::Length::NauticalMile},
    {"mi",             Unit::Length::Mile        },
    {"mile",           Unit::Length::Mile        },
    {"miles",          Unit::Length::Mile        },
    {"km",             Unit::Length::Kilometre   },
    {"kilometer",      Unit::Length::Kilometre   },
    {"kilometers",     Unit::Length::Kilometre   },
    {"kilometre",      Unit::Length::Kilometre   },
    {"kilometres",     Unit::Length::Kilometre   },
    {"m",              Unit::Length::Metre       },
    {"meter",          Unit::Length::Metre       },
    {"meters",         Unit::Length::Metre       },
    {"metre",          Unit::Length::Metre       },
    {"metres",         Unit::Length::Metre       },
    {"yd",             Unit::Length::Yard        },
    {"yard",           Unit::Length::Yard        },
    {"yards",          Unit::Length::Yard        },
    {"ft",             Unit::Length::Foot        },
    {"foot",           Unit::Length::Foot        },
    {"feet",           Unit::Length::Foot        },
    {"dm",             Unit::Length::Decimetre   },
    {"decimeter",      Unit::Length::Decimetre   },
    {"decimeters",     Unit::Length::Decimetre   },
    {"decimetre",      Unit::Length::Decimetre   },
    {"decimetres",     Unit::Length::Decimetre   },
    {"in",             Unit::Length::Inch        },
    {"inch",           Unit::Length::Inch        },
    {"inches",         Unit::Length::Inch        },
    {"cm",             Unit::Length::Centimetre  },
    {"centimeter",     Unit::Length::Centimetre  },
    {"centimeters",    Unit::Length::Centimetre  },
    {"centimetre",     Unit::Length::Centimetre  },
    {"centimetres",    Unit::Length::Centimetre  },
    {"mm",             Unit::Length::Millimetre  },
    {"millimeter",     Unit::Length::Millimetre  },
    {"millimeters",    Unit::Length::Millimetre  },
    {"millimetre",     Unit::Length::Millimetre  },
    {"millimetres",    Unit::Length::Millimetre  },
    {"milin",          Unit::Length::Milliinch   },
    {"milliinch",      Unit::Length::Milliinch   },
    {"milliinches",    Unit::Length::Milliinch   },
    {"mil",            Unit::Length::Milliinch   },
    {"mils",           Unit::Length::Milliinch   },
    {"thou",           Unit::Length::Milliinch   },
    {"thous",          Unit::Length::Milliinch   },
    {"thousandth",     Unit::Length::Milliinch   },
    {"thousandths",    Unit::Length::Milliinch   },
    {"μm",             Unit::Length::Micrometre  },
    {"um",             Unit::Length::Micrometre  },
    {"micrometer",     Unit::Length::Micrometre  },
    {"micrometers",    Unit::Length::Micrometre  },
    {"Micrometre",     Unit::Length::Micrometre  },
    {"Micrometres",    Unit::Length::Micrometre  },
    {"micron",         Unit::Length::Micrometre  },
    {"microns",        Unit::Length::Micrometre  },
    {"μin",            Unit::Length::Microinch   },
    {"uin",            Unit::Length::Microinch   },
    {"microinch",      Unit::Length::Microinch   },
    {"microinches",    Unit::Length::Microinch   },
};

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::NauticalMile>(
    double& value) noexcept {
  value *= 1.0 / 1852.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::NauticalMile>(
    double& value) noexcept {
  value *= 1852.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Mile>(
    double& value) noexcept {
  value *= 1.0 / 1609.344;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Mile>(
    double& value) noexcept {
  value *= 1609.344;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Kilometre>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Kilometre>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Metre>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Metre>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Yard>(
    double& value) noexcept {
  value *= 1.0 / 0.9144;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Yard>(
    double& value) noexcept {
  value *= 0.9144;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Foot>(
    double& value) noexcept {
  value *= 1.0 / 0.3048;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Foot>(
    double& value) noexcept {
  value *= 0.3048;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Decimetre>(
    double& value) noexcept {
  value *= 10.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Decimetre>(
    double& value) noexcept {
  value *= 0.1;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Inch>(
    double& value) noexcept {
  value *= 1.0 / 0.0254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Inch>(
    double& value) noexcept {
  value *= 0.0254;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Centimetre>(
    double& value) noexcept {
  value *= 100.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Centimetre>(
    double& value) noexcept {
  value *= 0.01;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Millimetre>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Millimetre>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Milliinch>(
    double& value) noexcept {
  value *= 1.0 / 0.0000254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Milliinch>(
    double& value) noexcept {
  value *= 0.0000254;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Micrometre>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Micrometre>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Length, Unit::Length::Microinch>(
    double& value) noexcept {
  value *= 1.0 / 0.0000000254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Length, Unit::Length::Microinch>(
    double& value) noexcept {
  value *= 0.0000000254;
}

template <>
inline const std::map<Unit::Length, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Length>{
        {Unit::Length::NauticalMile,
         ConversionsFromStandard<Unit::Length,                             Unit::Length::NauticalMile>},
        {Unit::Length::Mile,         ConversionsFromStandard<Unit::Length, Unit::Length::Mile>        },
        {Unit::Length::Kilometre,    ConversionsFromStandard<Unit::Length, Unit::Length::Kilometre>   },
        {Unit::Length::Metre,        ConversionsFromStandard<Unit::Length, Unit::Length::Metre>       },
        {Unit::Length::Yard,         ConversionsFromStandard<Unit::Length, Unit::Length::Yard>        },
        {Unit::Length::Foot,         ConversionsFromStandard<Unit::Length, Unit::Length::Foot>        },
        {Unit::Length::Decimetre,    ConversionsFromStandard<Unit::Length, Unit::Length::Decimetre>   },
        {Unit::Length::Inch,         ConversionsFromStandard<Unit::Length, Unit::Length::Inch>        },
        {Unit::Length::Centimetre,   ConversionsFromStandard<Unit::Length, Unit::Length::Centimetre>  },
        {Unit::Length::Millimetre,   ConversionsFromStandard<Unit::Length, Unit::Length::Millimetre>  },
        {Unit::Length::Milliinch,    ConversionsFromStandard<Unit::Length, Unit::Length::Milliinch>   },
        {Unit::Length::Micrometre,   ConversionsFromStandard<Unit::Length, Unit::Length::Micrometre>  },
        {Unit::Length::Microinch,    ConversionsFromStandard<Unit::Length, Unit::Length::Microinch>   },
};

template <>
inline const std::map<Unit::Length,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Length>{
        {Unit::Length::NauticalMile,
         ConversionsToStandard<Unit::Length,                             Unit::Length::NauticalMile>},
        {Unit::Length::Mile,         ConversionsToStandard<Unit::Length, Unit::Length::Mile>        },
        {Unit::Length::Kilometre,    ConversionsToStandard<Unit::Length, Unit::Length::Kilometre>   },
        {Unit::Length::Metre,        ConversionsToStandard<Unit::Length, Unit::Length::Metre>       },
        {Unit::Length::Yard,         ConversionsToStandard<Unit::Length, Unit::Length::Yard>        },
        {Unit::Length::Foot,         ConversionsToStandard<Unit::Length, Unit::Length::Foot>        },
        {Unit::Length::Decimetre,    ConversionsToStandard<Unit::Length, Unit::Length::Decimetre>   },
        {Unit::Length::Inch,         ConversionsToStandard<Unit::Length, Unit::Length::Inch>        },
        {Unit::Length::Centimetre,   ConversionsToStandard<Unit::Length, Unit::Length::Centimetre>  },
        {Unit::Length::Millimetre,   ConversionsToStandard<Unit::Length, Unit::Length::Millimetre>  },
        {Unit::Length::Milliinch,    ConversionsToStandard<Unit::Length, Unit::Length::Milliinch>   },
        {Unit::Length::Micrometre,   ConversionsToStandard<Unit::Length, Unit::Length::Micrometre>  },
        {Unit::Length::Microinch,    ConversionsToStandard<Unit::Length, Unit::Length::Microinch>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_LENGTH_HPP
