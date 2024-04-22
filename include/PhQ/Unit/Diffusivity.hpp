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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DIFFUSIVITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DIFFUSIVITY_HPP

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

// Diffusivity units.
enum class Diffusivity : int8_t {
  // Square nautical mile per second (nmi^2/s) diffusivity unit.
  SquareNauticalMilePerSecond,

  // Square mile per second (mi^2/s) diffusivity unit.
  SquareMilePerSecond,

  // Square kilometre per second (km^2/s) diffusivity unit.
  SquareKilometrePerSecond,

  // Hectare per second (ha/s) diffusivity unit.
  HectarePerSecond,

  // Acre per second (ac/s) diffusivity unit.
  AcrePerSecond,

  // Square metre per second (m^2/s) diffusivity unit.
  SquareMetrePerSecond,

  // Square yard per second (yd^2/s) diffusivity unit.
  SquareYardPerSecond,

  // Square foot per second (ft^2/s) diffusivity unit.
  SquareFootPerSecond,

  // Square decimetre per second (dm^2/s) diffusivity unit.
  SquareDecimetrePerSecond,

  // Square inch per second (in^2/s) diffusivity unit.
  SquareInchPerSecond,

  // Square centimetre per second (cm^2/s) diffusivity unit.
  SquareCentimetrePerSecond,

  // Square millimetre per second (mm^2/s) diffusivity unit.
  SquareMillimetrePerSecond,

  // Square milliinch per second (mil^2/s) diffusivity unit.
  SquareMilliinchPerSecond,

  // Square micrometre per second (μm^2/s) diffusivity unit.
  SquareMicrometrePerSecond,

  // Square microinch per second (μin^2/s) diffusivity unit.
  SquareMicroinchPerSecond,
};

}  // namespace Unit

// Standard diffusivity unit: square metre per second (m^2/s).
template <>
inline constexpr const Unit::Diffusivity Standard<Unit::Diffusivity>{
    Unit::Diffusivity::SquareMetrePerSecond};

// Physical dimension set of diffusivity units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Diffusivity>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{2}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Diffusivity unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Diffusivity> ConsistentUnits<Unit::Diffusivity>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Diffusivity::SquareMetrePerSecond     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Diffusivity::SquareMillimetrePerSecond},
    {UnitSystem::FootPoundSecondRankine,     Unit::Diffusivity::SquareFootPerSecond      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Diffusivity::SquareInchPerSecond      },
};

template <>
inline const std::map<Unit::Diffusivity, UnitSystem> RelatedUnitSystems<Unit::Diffusivity>{
    {Unit::Diffusivity::SquareMetrePerSecond,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Diffusivity::SquareMillimetrePerSecond, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Diffusivity::SquareFootPerSecond,       UnitSystem::FootPoundSecondRankine    },
    {Unit::Diffusivity::SquareInchPerSecond,       UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::Diffusivity, std::string_view> Abbreviations<Unit::Diffusivity>{
    {Unit::Diffusivity::SquareNauticalMilePerSecond, "nmi^2/s"},
    {Unit::Diffusivity::SquareMilePerSecond,         "mi^2/s" },
    {Unit::Diffusivity::SquareKilometrePerSecond,    "km^2/s" },
    {Unit::Diffusivity::HectarePerSecond,            "ha/s"   },
    {Unit::Diffusivity::AcrePerSecond,               "ac/s"   },
    {Unit::Diffusivity::SquareMetrePerSecond,        "m^2/s"  },
    {Unit::Diffusivity::SquareYardPerSecond,         "yd^2/s" },
    {Unit::Diffusivity::SquareFootPerSecond,         "ft^2/s" },
    {Unit::Diffusivity::SquareDecimetrePerSecond,    "dm^2/s" },
    {Unit::Diffusivity::SquareInchPerSecond,         "in^2/s" },
    {Unit::Diffusivity::SquareCentimetrePerSecond,   "cm^2/s" },
    {Unit::Diffusivity::SquareMillimetrePerSecond,   "mm^2/s" },
    {Unit::Diffusivity::SquareMilliinchPerSecond,    "mil^2/s"},
    {Unit::Diffusivity::SquareMicrometrePerSecond,   "μm^2/s" },
    {Unit::Diffusivity::SquareMicroinchPerSecond,    "μin^2/s"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Diffusivity> Spellings<Unit::Diffusivity>{
    {"nmi^2/s",       Unit::Diffusivity::SquareNauticalMilePerSecond},
    {"nmi2/s",        Unit::Diffusivity::SquareNauticalMilePerSecond},
    {"mi^2/s",        Unit::Diffusivity::SquareMilePerSecond        },
    {"mi2/s",         Unit::Diffusivity::SquareMilePerSecond        },
    {"km^2/s",        Unit::Diffusivity::SquareKilometrePerSecond   },
    {"km2/s",         Unit::Diffusivity::SquareKilometrePerSecond   },
    {"ha/s",          Unit::Diffusivity::HectarePerSecond           },
    {"ac/s",          Unit::Diffusivity::AcrePerSecond              },
    {"m^2/s",         Unit::Diffusivity::SquareMetrePerSecond       },
    {"m2/s",          Unit::Diffusivity::SquareMetrePerSecond       },
    {"yd^2/s",        Unit::Diffusivity::SquareYardPerSecond        },
    {"yd2/s",         Unit::Diffusivity::SquareYardPerSecond        },
    {"ft^2/s",        Unit::Diffusivity::SquareFootPerSecond        },
    {"ft2/s",         Unit::Diffusivity::SquareFootPerSecond        },
    {"dm^2/s",        Unit::Diffusivity::SquareDecimetrePerSecond   },
    {"dm2/s",         Unit::Diffusivity::SquareDecimetrePerSecond   },
    {"in^2/s",        Unit::Diffusivity::SquareInchPerSecond        },
    {"in2/s",         Unit::Diffusivity::SquareInchPerSecond        },
    {"cm^2/s",        Unit::Diffusivity::SquareCentimetrePerSecond  },
    {"cm2/s",         Unit::Diffusivity::SquareCentimetrePerSecond  },
    {"mm^2/s",        Unit::Diffusivity::SquareMillimetrePerSecond  },
    {"mm2/s",         Unit::Diffusivity::SquareMillimetrePerSecond  },
    {"millinch^2/s",  Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"millinch2/s",   Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"milliinch^2/s", Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"milliinch2/s",  Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"mil^2/s",       Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"mil2/s",        Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"thou^2/s",      Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"thou2/s",       Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"μm^2/s",        Unit::Diffusivity::SquareMicrometrePerSecond  },
    {"μm2/s",         Unit::Diffusivity::SquareMicrometrePerSecond  },
    {"um^2/s",        Unit::Diffusivity::SquareMicrometrePerSecond  },
    {"um2/s",         Unit::Diffusivity::SquareMicrometrePerSecond  },
    {"μin^2/s",       Unit::Diffusivity::SquareMicroinchPerSecond   },
    {"μin2/s",        Unit::Diffusivity::SquareMicroinchPerSecond   },
    {"uin^2/s",       Unit::Diffusivity::SquareMicroinchPerSecond   },
    {"uin2/s",        Unit::Diffusivity::SquareMicroinchPerSecond   },
};

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareNauticalMilePerSecond>(
    double& value) noexcept {
  value *= 1.0 / (1852.0 * 1852.0);
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareNauticalMilePerSecond>(
    double& value) noexcept {
  value *= 1852.0 * 1852.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMilePerSecond>(
    double& value) noexcept {
  value *= 1.0 / (1609.344 * 1609.344);
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMilePerSecond>(
    double& value) noexcept {
  value *= 1609.344 * 1609.344;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareKilometrePerSecond>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareKilometrePerSecond>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::HectarePerSecond>(
    double& value) noexcept {
  value *= 0.0001;
}

template <>
inline constexpr void ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::HectarePerSecond>(
    double& value) noexcept {
  value *= 10000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::AcrePerSecond>(
    double& value) noexcept {
  value *= 640.0 / (1609.344 * 1609.344);
}

template <>
inline constexpr void ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::AcrePerSecond>(
    double& value) noexcept {
  value *= 1609.344 * 1609.344 / 640.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMetrePerSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMetrePerSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareYardPerSecond>(
    double& value) noexcept {
  value *= 1.0 / (0.9144 * 0.9144);
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareYardPerSecond>(
    double& value) noexcept {
  value *= 0.9144 * 0.9144;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareFootPerSecond>(
    double& value) noexcept {
  value *= 1.0 / (0.3048 * 0.3048);
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareFootPerSecond>(
    double& value) noexcept {
  value *= 0.3048 * 0.3048;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareDecimetrePerSecond>(
    double& value) noexcept {
  value *= 100.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareDecimetrePerSecond>(
    double& value) noexcept {
  value *= 0.01;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareInchPerSecond>(
    double& value) noexcept {
  value *= 1.0 / (0.0254 * 0.0254);
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareInchPerSecond>(
    double& value) noexcept {
  value *= 0.0254 * 0.0254;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareCentimetrePerSecond>(
    double& value) noexcept {
  value *= 10000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareCentimetrePerSecond>(
    double& value) noexcept {
  value *= 0.0001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMillimetrePerSecond>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMillimetrePerSecond>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMilliinchPerSecond>(
    double& value) noexcept {
  value *= 1.0 / (0.0000254 * 0.0000254);
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMilliinchPerSecond>(
    double& value) noexcept {
  value *= 0.0000254 * 0.0000254;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMicrometrePerSecond>(
    double& value) noexcept {
  value *= 1000000000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMicrometrePerSecond>(
    double& value) noexcept {
  value *= 0.000000000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMicroinchPerSecond>(
    double& value) noexcept {
  value *= 1.0 / (0.0000000254 * 0.0000000254);
}

template <>
inline constexpr void
ConversionToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMicroinchPerSecond>(
    double& value) noexcept {
  value *= 0.0000000254 * 0.0000000254;
}

template <>
inline const std::map<Unit::Diffusivity, std::function<void(double* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Diffusivity>{
        {Unit::Diffusivity::SquareNauticalMilePerSecond,
         ConversionsFromStandard<Unit::Diffusivity,
         Unit::Diffusivity::SquareNauticalMilePerSecond>                                         },
        {Unit::Diffusivity::SquareMilePerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMilePerSecond>      },
        {Unit::Diffusivity::SquareKilometrePerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareKilometrePerSecond> },
        {Unit::Diffusivity::HectarePerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::HectarePerSecond>         },
        {Unit::Diffusivity::AcrePerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::AcrePerSecond>            },
        {Unit::Diffusivity::SquareMetrePerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMetrePerSecond>     },
        {Unit::Diffusivity::SquareYardPerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareYardPerSecond>      },
        {Unit::Diffusivity::SquareFootPerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareFootPerSecond>      },
        {Unit::Diffusivity::SquareDecimetrePerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareDecimetrePerSecond> },
        {Unit::Diffusivity::SquareInchPerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareInchPerSecond>      },
        {Unit::Diffusivity::SquareCentimetrePerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareCentimetrePerSecond>},
        {Unit::Diffusivity::SquareMillimetrePerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMillimetrePerSecond>},
        {Unit::Diffusivity::SquareMilliinchPerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMilliinchPerSecond> },
        {Unit::Diffusivity::SquareMicrometrePerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMicrometrePerSecond>},
        {Unit::Diffusivity::SquareMicroinchPerSecond,
         ConversionsFromStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMicroinchPerSecond> },
};

template <>
inline const std::map<Unit::Diffusivity,
                      std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Diffusivity>{
        {Unit::Diffusivity::SquareNauticalMilePerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareNauticalMilePerSecond>},
        {Unit::Diffusivity::SquareMilePerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMilePerSecond>        },
        {Unit::Diffusivity::SquareKilometrePerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareKilometrePerSecond>   },
        {Unit::Diffusivity::HectarePerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::HectarePerSecond>           },
        {Unit::Diffusivity::AcrePerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::AcrePerSecond>              },
        {Unit::Diffusivity::SquareMetrePerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMetrePerSecond>       },
        {Unit::Diffusivity::SquareYardPerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareYardPerSecond>        },
        {Unit::Diffusivity::SquareFootPerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareFootPerSecond>        },
        {Unit::Diffusivity::SquareDecimetrePerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareDecimetrePerSecond>   },
        {Unit::Diffusivity::SquareInchPerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareInchPerSecond>        },
        {Unit::Diffusivity::SquareCentimetrePerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareCentimetrePerSecond>  },
        {Unit::Diffusivity::SquareMillimetrePerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMillimetrePerSecond>  },
        {Unit::Diffusivity::SquareMilliinchPerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMilliinchPerSecond>   },
        {Unit::Diffusivity::SquareMicrometrePerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMicrometrePerSecond>  },
        {Unit::Diffusivity::SquareMicroinchPerSecond,
         ConversionsToStandard<Unit::Diffusivity, Unit::Diffusivity::SquareMicroinchPerSecond>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DIFFUSIVITY_HPP
