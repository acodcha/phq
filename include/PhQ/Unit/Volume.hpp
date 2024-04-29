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

#ifndef PHQ_UNIT_VOLUME_HPP
#define PHQ_UNIT_VOLUME_HPP

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

// Volume units.
enum class Volume : int8_t {
  // Cubic nautical mile (nmi^3) volume unit.
  CubicNauticalMile,

  // Cubic mile (mi^3) volume unit.
  CubicMile,

  // Cubic kilometre (km^3) volume unit.
  CubicKilometre,

  // Cubic metre (m^3) volume unit.
  CubicMetre,

  // Cubic yard (yd^3) volume unit.
  CubicYard,

  // Cubic foot (ft^3) volume unit.
  CubicFoot,

  // Cubic decimetre (dm^3) volume unit.
  CubicDecimetre,

  // Litre (L) volume unit.
  Litre,

  // Cubic inch (in^3) volume unit.
  CubicInch,

  // Cubic centimetre (cm^3) volume unit.
  CubicCentimetre,

  // Millilitre (mL) volume unit.
  Millilitre,

  // Cubic millimetre (mm^3) volume unit.
  CubicMillimetre,

  // Cubic milliinch (mil^3) volume unit.
  CubicMilliinch,

  // Cubic micrometre (μm^3) volume unit.
  CubicMicrometre,

  // Cubic microinch (μin^3) volume unit.
  CubicMicroinch,
};

}  // namespace Unit

// Standard volume unit: cubic metre (m^3).
template <>
inline constexpr const Unit::Volume Standard<Unit::Volume>{Unit::Volume::CubicMetre};

// Physical dimension set of volume units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Volume>{
    Dimensions{Dimension::Time{}, Dimension::Length{3}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Volume unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Volume> ConsistentUnits<Unit::Volume>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Volume::CubicMetre     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Volume::CubicMillimetre},
    {UnitSystem::FootPoundSecondRankine,     Unit::Volume::CubicFoot      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Volume::CubicInch      },
};

template <>
inline const std::map<Unit::Volume, UnitSystem> RelatedUnitSystems<Unit::Volume>{
    {Unit::Volume::CubicMetre,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Volume::CubicMillimetre, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Volume::CubicFoot,       UnitSystem::FootPoundSecondRankine    },
    {Unit::Volume::CubicInch,       UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::Volume, std::string_view> Abbreviations<Unit::Volume>{
    {Unit::Volume::CubicNauticalMile, "nmi^3"},
    {Unit::Volume::CubicMile,         "mi^3" },
    {Unit::Volume::CubicKilometre,    "km^3" },
    {Unit::Volume::CubicMetre,        "m^3"  },
    {Unit::Volume::CubicYard,         "yd^3" },
    {Unit::Volume::CubicFoot,         "ft^3" },
    {Unit::Volume::CubicDecimetre,    "dm^3" },
    {Unit::Volume::Litre,             "L"    },
    {Unit::Volume::CubicInch,         "in^3" },
    {Unit::Volume::CubicCentimetre,   "cm^3" },
    {Unit::Volume::Millilitre,        "mL"   },
    {Unit::Volume::CubicMillimetre,   "mm^3" },
    {Unit::Volume::CubicMilliinch,    "mil^3"},
    {Unit::Volume::CubicMicrometre,   "μm^3" },
    {Unit::Volume::CubicMicroinch,    "μin^3"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Volume> Spellings<Unit::Volume>{
    {"nmi^3",       Unit::Volume::CubicNauticalMile},
    {"nmi3",        Unit::Volume::CubicNauticalMile},
    {"mi^3",        Unit::Volume::CubicMile        },
    {"mi3",         Unit::Volume::CubicMile        },
    {"km^3",        Unit::Volume::CubicKilometre   },
    {"km3",         Unit::Volume::CubicKilometre   },
    {"m^3",         Unit::Volume::CubicMetre       },
    {"m3",          Unit::Volume::CubicMetre       },
    {"yd^3",        Unit::Volume::CubicYard        },
    {"yd3",         Unit::Volume::CubicYard        },
    {"ft^3",        Unit::Volume::CubicFoot        },
    {"ft3",         Unit::Volume::CubicFoot        },
    {"dm^3",        Unit::Volume::CubicDecimetre   },
    {"dm3",         Unit::Volume::CubicDecimetre   },
    {"L",           Unit::Volume::Litre            },
    {"in^3",        Unit::Volume::CubicInch        },
    {"in3",         Unit::Volume::CubicInch        },
    {"cm^3",        Unit::Volume::CubicCentimetre  },
    {"cm3",         Unit::Volume::CubicCentimetre  },
    {"mL",          Unit::Volume::Millilitre       },
    {"mm^3",        Unit::Volume::CubicMillimetre  },
    {"mm3",         Unit::Volume::CubicMillimetre  },
    {"millinch^3",  Unit::Volume::CubicMilliinch   },
    {"millinch3",   Unit::Volume::CubicMilliinch   },
    {"milliinch^3", Unit::Volume::CubicMilliinch   },
    {"milliinch3",  Unit::Volume::CubicMilliinch   },
    {"mil^3",       Unit::Volume::CubicMilliinch   },
    {"mil3",        Unit::Volume::CubicMilliinch   },
    {"thou^3",      Unit::Volume::CubicMilliinch   },
    {"thou3",       Unit::Volume::CubicMilliinch   },
    {"μm^3",        Unit::Volume::CubicMicrometre  },
    {"μm3",         Unit::Volume::CubicMicrometre  },
    {"um^3",        Unit::Volume::CubicMicrometre  },
    {"um3",         Unit::Volume::CubicMicrometre  },
    {"μin^3",       Unit::Volume::CubicMicroinch   },
    {"μin3",        Unit::Volume::CubicMicroinch   },
    {"uin^3",       Unit::Volume::CubicMicroinch   },
    {"uin3",        Unit::Volume::CubicMicroinch   },
};

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicNauticalMile>(
    double& value) noexcept {
  value /= (1852.0 * 1852.0 * 1852.0);
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicNauticalMile>(
    double& value) noexcept {
  value *= 1852.0 * 1852.0 * 1852.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMile>(
    double& value) noexcept {
  value /= (1609.344 * 1609.344 * 1609.344);
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicMile>(
    double& value) noexcept {
  value *= 1609.344 * 1609.344 * 1609.344;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicKilometre>(
    double& value) noexcept {
  value *= 1.0e-9;
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicKilometre>(
    double& value) noexcept {
  value *= 1.0e9;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMetre>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicMetre>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicYard>(
    double& value) noexcept {
  value /= (0.9144 * 0.9144 * 0.9144);
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicYard>(
    double& value) noexcept {
  value *= 0.9144 * 0.9144 * 0.9144;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicFoot>(
    double& value) noexcept {
  value /= (0.3048 * 0.3048 * 0.3048);
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicFoot>(
    double& value) noexcept {
  value *= 0.3048 * 0.3048 * 0.3048;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicDecimetre>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicDecimetre>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::Litre>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::Litre>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicInch>(
    double& value) noexcept {
  value /= (0.0254 * 0.0254 * 0.0254);
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicInch>(
    double& value) noexcept {
  value *= 0.0254 * 0.0254 * 0.0254;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicCentimetre>(
    double& value) noexcept {
  value *= 1.0e6;
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicCentimetre>(
    double& value) noexcept {
  value *= 1.0e-6;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::Millilitre>(
    double& value) noexcept {
  value *= 1.0e6;
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::Millilitre>(
    double& value) noexcept {
  value *= 1.0e-6;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMillimetre>(
    double& value) noexcept {
  value *= 1.0e9;
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicMillimetre>(
    double& value) noexcept {
  value *= 1.0e-9;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMilliinch>(
    double& value) noexcept {
  value /= (0.0000254 * 0.0000254 * 0.0000254);
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicMilliinch>(
    double& value) noexcept {
  value *= 0.0000254 * 0.0000254 * 0.0000254;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMicrometre>(
    double& value) noexcept {
  value *= 1.0e18;
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicMicrometre>(
    double& value) noexcept {
  value *= 1.0e-18;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMicroinch>(
    double& value) noexcept {
  value /= (0.0000000254 * 0.0000000254 * 0.0000000254);
}

template <>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::CubicMicroinch>(
    double& value) noexcept {
  value *= 0.0000000254 * 0.0000000254 * 0.0000000254;
}

template <>
inline const std::map<Unit::Volume, std::function<void(double* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Volume>{
        {Unit::Volume::CubicNauticalMile,
         ConversionsFromStandard<Unit::Volume,                                  Unit::Volume::CubicNauticalMile>},
        {Unit::Volume::CubicMile,         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicMile>        },
        {Unit::Volume::CubicKilometre,
         ConversionsFromStandard<Unit::Volume,                                  Unit::Volume::CubicKilometre>   },
        {Unit::Volume::CubicMetre,        ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicMetre>       },
        {Unit::Volume::CubicYard,         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicYard>        },
        {Unit::Volume::CubicFoot,         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicFoot>        },
        {Unit::Volume::CubicDecimetre,
         ConversionsFromStandard<Unit::Volume,                                  Unit::Volume::CubicDecimetre>   },
        {Unit::Volume::Litre,             ConversionsFromStandard<Unit::Volume, Unit::Volume::Litre>            },
        {Unit::Volume::CubicInch,         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicInch>        },
        {Unit::Volume::CubicCentimetre,
         ConversionsFromStandard<Unit::Volume,                                  Unit::Volume::CubicCentimetre>  },
        {Unit::Volume::Millilitre,        ConversionsFromStandard<Unit::Volume, Unit::Volume::Millilitre>       },
        {Unit::Volume::CubicMillimetre,
         ConversionsFromStandard<Unit::Volume,                                  Unit::Volume::CubicMillimetre>  },
        {Unit::Volume::CubicMilliinch,
         ConversionsFromStandard<Unit::Volume,                                  Unit::Volume::CubicMilliinch>   },
        {Unit::Volume::CubicMicrometre,
         ConversionsFromStandard<Unit::Volume,                                  Unit::Volume::CubicMicrometre>  },
        {Unit::Volume::CubicMicroinch,
         ConversionsFromStandard<Unit::Volume,                                  Unit::Volume::CubicMicroinch>   },
};

template <>
inline const std::map<Unit::Volume, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Volume>{
        {Unit::Volume::CubicNauticalMile,
         ConversionsToStandard<Unit::Volume,                                  Unit::Volume::CubicNauticalMile>},
        {Unit::Volume::CubicMile,         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicMile>        },
        {Unit::Volume::CubicKilometre,
         ConversionsToStandard<Unit::Volume,                                  Unit::Volume::CubicKilometre>   },
        {Unit::Volume::CubicMetre,        ConversionsToStandard<Unit::Volume, Unit::Volume::CubicMetre>       },
        {Unit::Volume::CubicYard,         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicYard>        },
        {Unit::Volume::CubicFoot,         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicFoot>        },
        {Unit::Volume::CubicDecimetre,
         ConversionsToStandard<Unit::Volume,                                  Unit::Volume::CubicDecimetre>   },
        {Unit::Volume::Litre,             ConversionsToStandard<Unit::Volume, Unit::Volume::Litre>            },
        {Unit::Volume::CubicInch,         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicInch>        },
        {Unit::Volume::CubicCentimetre,
         ConversionsToStandard<Unit::Volume,                                  Unit::Volume::CubicCentimetre>  },
        {Unit::Volume::Millilitre,        ConversionsToStandard<Unit::Volume, Unit::Volume::Millilitre>       },
        {Unit::Volume::CubicMillimetre,
         ConversionsToStandard<Unit::Volume,                                  Unit::Volume::CubicMillimetre>  },
        {Unit::Volume::CubicMilliinch,
         ConversionsToStandard<Unit::Volume,                                  Unit::Volume::CubicMilliinch>   },
        {Unit::Volume::CubicMicrometre,
         ConversionsToStandard<Unit::Volume,                                  Unit::Volume::CubicMicrometre>  },
        {Unit::Volume::CubicMicroinch,
         ConversionsToStandard<Unit::Volume,                                  Unit::Volume::CubicMicroinch>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_VOLUME_HPP
