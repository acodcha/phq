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
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareNauticalMile>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareNauticalMile>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMile>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMile>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareKilometre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareKilometre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::Hectare>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::Hectare>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(10000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::Acre>::FromStandard(
    Number& value) noexcept {
  value *= 640.0 / (static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::Acre>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L) / 640.0;
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMetre>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMetre>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareYard>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareYard>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareFoot>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareFoot>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareDecimetre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(100.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareDecimetre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.01L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareInch>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareInch>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareCentimetre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(10000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareCentimetre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMillimetre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMillimetre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMilliinch>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0000254L) * static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMilliinch>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L) * static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMicrometre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMicrometre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000000000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMicroinch>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0000000254L) * static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMicroinch>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L) * static_cast<Number>(0.0000000254L);
}

template <typename Number>
inline const std::map<Unit::Area, std::function<void(Number* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Area, Number>{
        {Unit::Area::SquareNauticalMile,
         Conversions<Unit::Area,                                 Unit::Area::SquareNauticalMile>::FromStandard<Number>},
        {Unit::Area::SquareMile,
         Conversions<Unit::Area,                                 Unit::Area::SquareMile>::FromStandard<Number>        },
        {Unit::Area::SquareKilometre,
         Conversions<Unit::Area,                                 Unit::Area::SquareKilometre>::FromStandard<Number>   },
        {Unit::Area::Hectare,            Conversions<Unit::Area, Unit::Area::Hectare>::FromStandard<Number>           },
        {Unit::Area::Acre,               Conversions<Unit::Area, Unit::Area::Acre>::FromStandard<Number>              },
        {Unit::Area::SquareMetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMetre>::FromStandard<Number>       },
        {Unit::Area::SquareYard,
         Conversions<Unit::Area,                                 Unit::Area::SquareYard>::FromStandard<Number>        },
        {Unit::Area::SquareFoot,
         Conversions<Unit::Area,                                 Unit::Area::SquareFoot>::FromStandard<Number>        },
        {Unit::Area::SquareDecimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareDecimetre>::FromStandard<Number>   },
        {Unit::Area::SquareInch,
         Conversions<Unit::Area,                                 Unit::Area::SquareInch>::FromStandard<Number>        },
        {Unit::Area::SquareCentimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareCentimetre>::FromStandard<Number>  },
        {Unit::Area::SquareMillimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMillimetre>::FromStandard<Number>  },
        {Unit::Area::SquareMilliinch,
         Conversions<Unit::Area,                                 Unit::Area::SquareMilliinch>::FromStandard<Number>   },
        {Unit::Area::SquareMicrometre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMicrometre>::FromStandard<Number>  },
        {Unit::Area::SquareMicroinch,
         Conversions<Unit::Area,                                 Unit::Area::SquareMicroinch>::FromStandard<Number>   },
};

template <typename Number>
inline const std::map<Unit::Area, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Area, Number>{
        {Unit::Area::SquareNauticalMile,
         Conversions<Unit::Area,                                 Unit::Area::SquareNauticalMile>::ToStandard<Number>},
        {Unit::Area::SquareMile,
         Conversions<Unit::Area,                                 Unit::Area::SquareMile>::ToStandard<Number>        },
        {Unit::Area::SquareKilometre,
         Conversions<Unit::Area,                                 Unit::Area::SquareKilometre>::ToStandard<Number>   },
        {Unit::Area::Hectare,            Conversions<Unit::Area, Unit::Area::Hectare>::ToStandard<Number>           },
        {Unit::Area::Acre,               Conversions<Unit::Area, Unit::Area::Acre>::ToStandard<Number>              },
        {Unit::Area::SquareMetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMetre>::ToStandard<Number>       },
        {Unit::Area::SquareYard,
         Conversions<Unit::Area,                                 Unit::Area::SquareYard>::ToStandard<Number>        },
        {Unit::Area::SquareFoot,
         Conversions<Unit::Area,                                 Unit::Area::SquareFoot>::ToStandard<Number>        },
        {Unit::Area::SquareDecimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareDecimetre>::ToStandard<Number>   },
        {Unit::Area::SquareInch,
         Conversions<Unit::Area,                                 Unit::Area::SquareInch>::ToStandard<Number>        },
        {Unit::Area::SquareCentimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareCentimetre>::ToStandard<Number>  },
        {Unit::Area::SquareMillimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMillimetre>::ToStandard<Number>  },
        {Unit::Area::SquareMilliinch,
         Conversions<Unit::Area,                                 Unit::Area::SquareMilliinch>::ToStandard<Number>   },
        {Unit::Area::SquareMicrometre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMicrometre>::ToStandard<Number>  },
        {Unit::Area::SquareMicroinch,
         Conversions<Unit::Area,                                 Unit::Area::SquareMicroinch>::ToStandard<Number>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_AREA_HPP
