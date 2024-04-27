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

#ifndef PHQ_UNIT_AREA_HPP
#define PHQ_UNIT_AREA_HPP

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

// Area units.
enum class Area : int8_t {
  // Square nautical mile (nmi^2) area unit.
  SquareNauticalMile,

  // Square mile (mi^2) area unit.
  SquareMile,

  // Square kilometre (km^2) area unit.
  SquareKilometre,

  // Hectare (ha) area unit.
  Hectare,

  // Acre (ac) area unit.
  Acre,

  // Square metre (m^2) area unit.
  SquareMetre,

  // Square yard (yd^2) area unit.
  SquareYard,

  // Square foot (ft^2) area unit.
  SquareFoot,

  // Square decimetre (dm^2) area unit.
  SquareDecimetre,

  // Square inch (in^2) area unit.
  SquareInch,

  // Square centimetre (cm^2) area unit.
  SquareCentimetre,

  // Square millimetre (mm^2) area unit.
  SquareMillimetre,

  // Square milliinch (mil^2) area unit.
  SquareMilliinch,

  // Square micrometre (μm^2) area unit.
  SquareMicrometre,

  // Square microinch (μin^2) area unit.
  SquareMicroinch,
};

}  // namespace Unit

// Standard area unit: square metre (m^2).
template <>
inline constexpr const Unit::Area Standard<Unit::Area>{Unit::Area::SquareMetre};

// Physical dimension set of area units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Area>{
    Dimensions{Dimension::Time{0}, Dimension::Length{2}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Area unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Area> ConsistentUnits<Unit::Area>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Area::SquareMetre     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Area::SquareMillimetre},
    {UnitSystem::FootPoundSecondRankine,     Unit::Area::SquareFoot      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Area::SquareInch      },
};

template <>
inline const std::map<Unit::Area, UnitSystem> RelatedUnitSystems<Unit::Area>{
    {Unit::Area::SquareMetre,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Area::SquareMillimetre, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Area::SquareFoot,       UnitSystem::FootPoundSecondRankine    },
    {Unit::Area::SquareInch,       UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::Area, std::string_view> Abbreviations<Unit::Area>{
    {Unit::Area::SquareNauticalMile, "nmi^2"},
    {Unit::Area::SquareMile,         "mi^2" },
    {Unit::Area::SquareKilometre,    "km^2" },
    {Unit::Area::Hectare,            "ha"   },
    {Unit::Area::Acre,               "ac"   },
    {Unit::Area::SquareMetre,        "m^2"  },
    {Unit::Area::SquareYard,         "yd^2" },
    {Unit::Area::SquareFoot,         "ft^2" },
    {Unit::Area::SquareDecimetre,    "dm^2" },
    {Unit::Area::SquareInch,         "in^2" },
    {Unit::Area::SquareCentimetre,   "cm^2" },
    {Unit::Area::SquareMillimetre,   "mm^2" },
    {Unit::Area::SquareMilliinch,    "mil^2"},
    {Unit::Area::SquareMicrometre,   "μm^2" },
    {Unit::Area::SquareMicroinch,    "μin^2"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Area> Spellings<Unit::Area>{
    {"nmi^2",       Unit::Area::SquareNauticalMile},
    {"nmi2",        Unit::Area::SquareNauticalMile},
    {"NM^2",        Unit::Area::SquareNauticalMile},
    {"NM",          Unit::Area::SquareNauticalMile},
    {"mi^2",        Unit::Area::SquareMile        },
    {"mi2",         Unit::Area::SquareMile        },
    {"km^2",        Unit::Area::SquareKilometre   },
    {"km2",         Unit::Area::SquareKilometre   },
    {"ha",          Unit::Area::Hectare           },
    {"ac",          Unit::Area::Acre              },
    {"m^2",         Unit::Area::SquareMetre       },
    {"m2",          Unit::Area::SquareMetre       },
    {"yd^2",        Unit::Area::SquareYard        },
    {"yd2",         Unit::Area::SquareYard        },
    {"ft^2",        Unit::Area::SquareFoot        },
    {"ft2",         Unit::Area::SquareFoot        },
    {"dm^2",        Unit::Area::SquareDecimetre   },
    {"dm2",         Unit::Area::SquareDecimetre   },
    {"in^2",        Unit::Area::SquareInch        },
    {"in2",         Unit::Area::SquareInch        },
    {"cm^2",        Unit::Area::SquareCentimetre  },
    {"cm2",         Unit::Area::SquareCentimetre  },
    {"mm^2",        Unit::Area::SquareMillimetre  },
    {"mm2",         Unit::Area::SquareMillimetre  },
    {"millinch^2",  Unit::Area::SquareMilliinch   },
    {"millinch2",   Unit::Area::SquareMilliinch   },
    {"milliinch^2", Unit::Area::SquareMilliinch   },
    {"milliinch2",  Unit::Area::SquareMilliinch   },
    {"mil^2",       Unit::Area::SquareMilliinch   },
    {"mil2",        Unit::Area::SquareMilliinch   },
    {"thou^2",      Unit::Area::SquareMilliinch   },
    {"thou2",       Unit::Area::SquareMilliinch   },
    {"μm^2",        Unit::Area::SquareMicrometre  },
    {"μm2",         Unit::Area::SquareMicrometre  },
    {"um^2",        Unit::Area::SquareMicrometre  },
    {"um2",         Unit::Area::SquareMicrometre  },
    {"μin^2",       Unit::Area::SquareMicroinch   },
    {"μin2",        Unit::Area::SquareMicroinch   },
    {"uin^2",       Unit::Area::SquareMicroinch   },
    {"uin2",        Unit::Area::SquareMicroinch   },
};

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareNauticalMile>(
    double& value) noexcept {
  value *= 1.0 / (1852.0 * 1852.0);
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareNauticalMile>(
    double& value) noexcept {
  value *= 1852.0 * 1852.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareMile>(
    double& value) noexcept {
  value *= 1.0 / (1609.344 * 1609.344);
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareMile>(
    double& value) noexcept {
  value *= 1609.344 * 1609.344;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareKilometre>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareKilometre>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::Hectare>(
    double& value) noexcept {
  value *= 0.0001;
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::Hectare>(
    double& value) noexcept {
  value *= 10000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::Acre>(double& value) noexcept {
  value *= 640.0 / (1609.344 * 1609.344);
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::Acre>(double& value) noexcept {
  value *= 1609.344 * 1609.344 / 640.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareMetre>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareMetre>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareYard>(
    double& value) noexcept {
  value *= 1.0 / (0.9144 * 0.9144);
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareYard>(
    double& value) noexcept {
  value *= 0.9144 * 0.9144;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareFoot>(
    double& value) noexcept {
  value *= 1.0 / (0.3048 * 0.3048);
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareFoot>(
    double& value) noexcept {
  value *= 0.3048 * 0.3048;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareDecimetre>(
    double& value) noexcept {
  value *= 100.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareDecimetre>(
    double& value) noexcept {
  value *= 0.01;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareInch>(
    double& value) noexcept {
  value *= 1.0 / (0.0254 * 0.0254);
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareInch>(
    double& value) noexcept {
  value *= 0.0254 * 0.0254;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareCentimetre>(
    double& value) noexcept {
  value *= 10000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareCentimetre>(
    double& value) noexcept {
  value *= 0.0001;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareMillimetre>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareMillimetre>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareMilliinch>(
    double& value) noexcept {
  value *= 1.0 / (0.0000254 * 0.0000254);
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareMilliinch>(
    double& value) noexcept {
  value *= 0.0000254 * 0.0000254;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareMicrometre>(
    double& value) noexcept {
  value *= 1000000000000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareMicrometre>(
    double& value) noexcept {
  value *= 0.000000000001;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Area, Unit::Area::SquareMicroinch>(
    double& value) noexcept {
  value *= 1.0 / (0.0000000254 * 0.0000000254);
}

template <>
inline constexpr void ConversionToStandard<Unit::Area, Unit::Area::SquareMicroinch>(
    double& value) noexcept {
  value *= 0.0000000254 * 0.0000000254;
}

template <>
inline const std::map<Unit::Area, std::function<void(double* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Area>{
        {Unit::Area::SquareNauticalMile,
         ConversionsFromStandard<Unit::Area,                                 Unit::Area::SquareNauticalMile>},
        {Unit::Area::SquareMile,         ConversionsFromStandard<Unit::Area, Unit::Area::SquareMile>        },
        {Unit::Area::SquareKilometre,
         ConversionsFromStandard<Unit::Area,                                 Unit::Area::SquareKilometre>   },
        {Unit::Area::Hectare,            ConversionsFromStandard<Unit::Area, Unit::Area::Hectare>           },
        {Unit::Area::Acre,               ConversionsFromStandard<Unit::Area, Unit::Area::Acre>              },
        {Unit::Area::SquareMetre,        ConversionsFromStandard<Unit::Area, Unit::Area::SquareMetre>       },
        {Unit::Area::SquareYard,         ConversionsFromStandard<Unit::Area, Unit::Area::SquareYard>        },
        {Unit::Area::SquareFoot,         ConversionsFromStandard<Unit::Area, Unit::Area::SquareFoot>        },
        {Unit::Area::SquareDecimetre,
         ConversionsFromStandard<Unit::Area,                                 Unit::Area::SquareDecimetre>   },
        {Unit::Area::SquareInch,         ConversionsFromStandard<Unit::Area, Unit::Area::SquareInch>        },
        {Unit::Area::SquareCentimetre,
         ConversionsFromStandard<Unit::Area,                                 Unit::Area::SquareCentimetre>  },
        {Unit::Area::SquareMillimetre,
         ConversionsFromStandard<Unit::Area,                                 Unit::Area::SquareMillimetre>  },
        {Unit::Area::SquareMilliinch,
         ConversionsFromStandard<Unit::Area,                                 Unit::Area::SquareMilliinch>   },
        {Unit::Area::SquareMicrometre,
         ConversionsFromStandard<Unit::Area,                                 Unit::Area::SquareMicrometre>  },
        {Unit::Area::SquareMicroinch,
         ConversionsFromStandard<Unit::Area,                                 Unit::Area::SquareMicroinch>   },
};

template <>
inline const std::map<Unit::Area, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Area>{
        {Unit::Area::SquareNauticalMile,
         ConversionsToStandard<Unit::Area,                                 Unit::Area::SquareNauticalMile>},
        {Unit::Area::SquareMile,         ConversionsToStandard<Unit::Area, Unit::Area::SquareMile>        },
        {Unit::Area::SquareKilometre,
         ConversionsToStandard<Unit::Area,                                 Unit::Area::SquareKilometre>   },
        {Unit::Area::Hectare,            ConversionsToStandard<Unit::Area, Unit::Area::Hectare>           },
        {Unit::Area::Acre,               ConversionsToStandard<Unit::Area, Unit::Area::Acre>              },
        {Unit::Area::SquareMetre,        ConversionsToStandard<Unit::Area, Unit::Area::SquareMetre>       },
        {Unit::Area::SquareYard,         ConversionsToStandard<Unit::Area, Unit::Area::SquareYard>        },
        {Unit::Area::SquareFoot,         ConversionsToStandard<Unit::Area, Unit::Area::SquareFoot>        },
        {Unit::Area::SquareDecimetre,
         ConversionsToStandard<Unit::Area,                                 Unit::Area::SquareDecimetre>   },
        {Unit::Area::SquareInch,         ConversionsToStandard<Unit::Area, Unit::Area::SquareInch>        },
        {Unit::Area::SquareCentimetre,
         ConversionsToStandard<Unit::Area,                                 Unit::Area::SquareCentimetre>  },
        {Unit::Area::SquareMillimetre,
         ConversionsToStandard<Unit::Area,                                 Unit::Area::SquareMillimetre>  },
        {Unit::Area::SquareMilliinch,
         ConversionsToStandard<Unit::Area,                                 Unit::Area::SquareMilliinch>   },
        {Unit::Area::SquareMicrometre,
         ConversionsToStandard<Unit::Area,                                 Unit::Area::SquareMicrometre>  },
        {Unit::Area::SquareMicroinch,
         ConversionsToStandard<Unit::Area,                                 Unit::Area::SquareMicroinch>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_AREA_HPP
