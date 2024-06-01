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

/// \brief Area units.
enum class Area : int8_t {
  /// \brief Square nautical mile (nmi^2) area unit.
  SquareNauticalMile,

  /// \brief Square mile (mi^2) area unit.
  SquareMile,

  /// \brief Square kilometre (km^2) area unit.
  SquareKilometre,

  /// \brief Hectare (ha) area unit.
  Hectare,

  /// \brief Acre (ac) area unit.
  Acre,

  /// \brief Square metre (m^2) area unit.
  SquareMetre,

  /// \brief Square yard (yd^2) area unit.
  SquareYard,

  /// \brief Square foot (ft^2) area unit.
  SquareFoot,

  /// \brief Square decimetre (dm^2) area unit.
  SquareDecimetre,

  /// \brief Square inch (in^2) area unit.
  SquareInch,

  /// \brief Square centimetre (cm^2) area unit.
  SquareCentimetre,

  /// \brief Square millimetre (mm^2) area unit.
  SquareMillimetre,

  /// \brief Square milliinch (mil^2) area unit.
  SquareMilliinch,

  /// \brief Square micrometre (μm^2) area unit.
  SquareMicrometre,

  /// \brief Square microinch (μin^2) area unit.
  SquareMicroinch,
};

}  // namespace Unit

/// \brief Standard area unit: square metre (m^2).
template <>
inline constexpr const Unit::Area Standard<Unit::Area>{Unit::Area::SquareMetre};

/// \brief Physical dimension set of area units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Area>{
    Dimensions{Dimension::Time{0}, Dimension::Length{2}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
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
    {"μm^2",       Unit::Area::SquareMicrometre  },
    {"μm2",        Unit::Area::SquareMicrometre  },
    {"um^2",        Unit::Area::SquareMicrometre  },
    {"um2",         Unit::Area::SquareMicrometre  },
    {"μin^2",      Unit::Area::SquareMicroinch   },
    {"μin2",       Unit::Area::SquareMicroinch   },
    {"uin^2",       Unit::Area::SquareMicroinch   },
    {"uin2",        Unit::Area::SquareMicroinch   },
};

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareNauticalMile>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareNauticalMile>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMile>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMile>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareKilometre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareKilometre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::Hectare>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::Hectare>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(10000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::Acre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(640.0L)
           / (static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::Acre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L)
           / static_cast<NumericType>(640.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMetre>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMetre>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareYard>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareYard>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareFoot>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareFoot>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareDecimetre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(100.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareDecimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.01L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareInch>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareInch>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareCentimetre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(10000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareCentimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMillimetre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMillimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMilliinch>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMilliinch>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMicrometre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMicrometre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000000000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMicroinch>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Area, Unit::Area::SquareMicroinch>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L);
}

template <typename NumericType>
inline const std::map<Unit::Area, std::function<void(NumericType* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Area, NumericType>{
        {Unit::Area::SquareNauticalMile,
         Conversions<Unit::Area,                                 Unit::Area::SquareNauticalMile>::FromStandard<NumericType>},
        {Unit::Area::SquareMile,
         Conversions<Unit::Area,                                 Unit::Area::SquareMile>::FromStandard<NumericType>        },
        {Unit::Area::SquareKilometre,
         Conversions<Unit::Area,                                 Unit::Area::SquareKilometre>::FromStandard<NumericType>   },
        {Unit::Area::Hectare,
         Conversions<Unit::Area,                                 Unit::Area::Hectare>::FromStandard<NumericType>           },
        {Unit::Area::Acre,               Conversions<Unit::Area, Unit::Area::Acre>::FromStandard<NumericType>              },
        {Unit::Area::SquareMetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMetre>::FromStandard<NumericType>       },
        {Unit::Area::SquareYard,
         Conversions<Unit::Area,                                 Unit::Area::SquareYard>::FromStandard<NumericType>        },
        {Unit::Area::SquareFoot,
         Conversions<Unit::Area,                                 Unit::Area::SquareFoot>::FromStandard<NumericType>        },
        {Unit::Area::SquareDecimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareDecimetre>::FromStandard<NumericType>   },
        {Unit::Area::SquareInch,
         Conversions<Unit::Area,                                 Unit::Area::SquareInch>::FromStandard<NumericType>        },
        {Unit::Area::SquareCentimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareCentimetre>::FromStandard<NumericType>  },
        {Unit::Area::SquareMillimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMillimetre>::FromStandard<NumericType>  },
        {Unit::Area::SquareMilliinch,
         Conversions<Unit::Area,                                 Unit::Area::SquareMilliinch>::FromStandard<NumericType>   },
        {Unit::Area::SquareMicrometre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMicrometre>::FromStandard<NumericType>  },
        {Unit::Area::SquareMicroinch,
         Conversions<Unit::Area,                                 Unit::Area::SquareMicroinch>::FromStandard<NumericType>   },
};

template <typename NumericType>
inline const std::map<Unit::Area, std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Area, NumericType>{
        {Unit::Area::SquareNauticalMile,
         Conversions<Unit::Area,                                 Unit::Area::SquareNauticalMile>::ToStandard<NumericType>},
        {Unit::Area::SquareMile,
         Conversions<Unit::Area,                                 Unit::Area::SquareMile>::ToStandard<NumericType>        },
        {Unit::Area::SquareKilometre,
         Conversions<Unit::Area,                                 Unit::Area::SquareKilometre>::ToStandard<NumericType>   },
        {Unit::Area::Hectare,
         Conversions<Unit::Area,                                 Unit::Area::Hectare>::ToStandard<NumericType>           },
        {Unit::Area::Acre,               Conversions<Unit::Area, Unit::Area::Acre>::ToStandard<NumericType>              },
        {Unit::Area::SquareMetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMetre>::ToStandard<NumericType>       },
        {Unit::Area::SquareYard,
         Conversions<Unit::Area,                                 Unit::Area::SquareYard>::ToStandard<NumericType>        },
        {Unit::Area::SquareFoot,
         Conversions<Unit::Area,                                 Unit::Area::SquareFoot>::ToStandard<NumericType>        },
        {Unit::Area::SquareDecimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareDecimetre>::ToStandard<NumericType>   },
        {Unit::Area::SquareInch,
         Conversions<Unit::Area,                                 Unit::Area::SquareInch>::ToStandard<NumericType>        },
        {Unit::Area::SquareCentimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareCentimetre>::ToStandard<NumericType>  },
        {Unit::Area::SquareMillimetre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMillimetre>::ToStandard<NumericType>  },
        {Unit::Area::SquareMilliinch,
         Conversions<Unit::Area,                                 Unit::Area::SquareMilliinch>::ToStandard<NumericType>   },
        {Unit::Area::SquareMicrometre,
         Conversions<Unit::Area,                                 Unit::Area::SquareMicrometre>::ToStandard<NumericType>  },
        {Unit::Area::SquareMicroinch,
         Conversions<Unit::Area,                                 Unit::Area::SquareMicroinch>::ToStandard<NumericType>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_AREA_HPP
