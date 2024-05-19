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

#ifndef PHQ_UNIT_LENGTH_HPP
#define PHQ_UNIT_LENGTH_HPP

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
    Dimensions{Dimension::Time{0}, Dimension::Length{1}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
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
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::NauticalMile>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::NauticalMile>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Mile>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Mile>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Kilometre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Kilometre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Metre>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Metre>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Yard>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Yard>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Foot>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Foot>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Decimetre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(10.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Decimetre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.1L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Inch>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Inch>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Centimetre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(100.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Centimetre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.01L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Millimetre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Millimetre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Milliinch>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Milliinch>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Micrometre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Micrometre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Microinch>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Length, Unit::Length::Microinch>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L);
}

template <typename Number>
inline const std::map<Unit::Length, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Length, Number>{
        {Unit::Length::NauticalMile,
         Conversions<Unit::Length,                             Unit::Length::NauticalMile>::FromStandard<Number>},
        {Unit::Length::Mile,         Conversions<Unit::Length, Unit::Length::Mile>::FromStandard<Number>        },
        {Unit::Length::Kilometre,
         Conversions<Unit::Length,                             Unit::Length::Kilometre>::FromStandard<Number>   },
        {Unit::Length::Metre,        Conversions<Unit::Length, Unit::Length::Metre>::FromStandard<Number>       },
        {Unit::Length::Yard,         Conversions<Unit::Length, Unit::Length::Yard>::FromStandard<Number>        },
        {Unit::Length::Foot,         Conversions<Unit::Length, Unit::Length::Foot>::FromStandard<Number>        },
        {Unit::Length::Decimetre,
         Conversions<Unit::Length,                             Unit::Length::Decimetre>::FromStandard<Number>   },
        {Unit::Length::Inch,         Conversions<Unit::Length, Unit::Length::Inch>::FromStandard<Number>        },
        {Unit::Length::Centimetre,
         Conversions<Unit::Length,                             Unit::Length::Centimetre>::FromStandard<Number>  },
        {Unit::Length::Millimetre,
         Conversions<Unit::Length,                             Unit::Length::Millimetre>::FromStandard<Number>  },
        {Unit::Length::Milliinch,
         Conversions<Unit::Length,                             Unit::Length::Milliinch>::FromStandard<Number>   },
        {Unit::Length::Micrometre,
         Conversions<Unit::Length,                             Unit::Length::Micrometre>::FromStandard<Number>  },
        {Unit::Length::Microinch,
         Conversions<Unit::Length,                             Unit::Length::Microinch>::FromStandard<Number>   },
};

template <typename Number>
inline const std::map<Unit::Length,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Length, Number>{
        {Unit::Length::NauticalMile,
         Conversions<Unit::Length,                             Unit::Length::NauticalMile>::ToStandard<Number>},
        {Unit::Length::Mile,         Conversions<Unit::Length, Unit::Length::Mile>::ToStandard<Number>        },
        {Unit::Length::Kilometre,
         Conversions<Unit::Length,                             Unit::Length::Kilometre>::ToStandard<Number>   },
        {Unit::Length::Metre,        Conversions<Unit::Length, Unit::Length::Metre>::ToStandard<Number>       },
        {Unit::Length::Yard,         Conversions<Unit::Length, Unit::Length::Yard>::ToStandard<Number>        },
        {Unit::Length::Foot,         Conversions<Unit::Length, Unit::Length::Foot>::ToStandard<Number>        },
        {Unit::Length::Decimetre,
         Conversions<Unit::Length,                             Unit::Length::Decimetre>::ToStandard<Number>   },
        {Unit::Length::Inch,         Conversions<Unit::Length, Unit::Length::Inch>::ToStandard<Number>        },
        {Unit::Length::Centimetre,
         Conversions<Unit::Length,                             Unit::Length::Centimetre>::ToStandard<Number>  },
        {Unit::Length::Millimetre,
         Conversions<Unit::Length,                             Unit::Length::Millimetre>::ToStandard<Number>  },
        {Unit::Length::Milliinch,
         Conversions<Unit::Length,                             Unit::Length::Milliinch>::ToStandard<Number>   },
        {Unit::Length::Micrometre,
         Conversions<Unit::Length,                             Unit::Length::Micrometre>::ToStandard<Number>  },
        {Unit::Length::Microinch,
         Conversions<Unit::Length,                             Unit::Length::Microinch>::ToStandard<Number>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_LENGTH_HPP
