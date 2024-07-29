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

/// \brief Length units.
enum class Length : int8_t {
  /// \brief Metre (m) length unit.
  Metre,

  /// \brief Nautical mile (nmi) length unit.
  NauticalMile,

  /// \brief Mile (mi) length unit.
  Mile,

  /// \brief Kilometre (km) length unit.
  Kilometre,

  /// \brief Yard (yd) length unit.
  Yard,

  /// \brief Foot (ft) length unit.
  Foot,

  /// \brief Decimetre (dm) length unit.
  Decimetre,

  /// \brief Inch (in) length unit.
  Inch,

  /// \brief Centimetre (cm) length unit.
  Centimetre,

  /// \brief Millimetre (mm) length unit.
  Millimetre,

  /// \brief Milliinch (mil) length unit.
  Milliinch,

  /// \brief Micrometre (μm) length unit.
  Micrometre,

  /// \brief Microinch (μin) length unit.
  Microinch,
};

}  // namespace Unit

/// \brief Standard length unit: metre (m).
template <>
inline constexpr const Unit::Length Standard<Unit::Length>{Unit::Length::Metre};

/// \brief Physical dimension set of length units.
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

// clang-format off

template <>
inline const std::map<Unit::Length, std::string_view> Abbreviations<Unit::Length>{
    {Unit::Length::Metre,        "m"  },
    {Unit::Length::NauticalMile, "nmi"},
    {Unit::Length::Mile,         "mi" },
    {Unit::Length::Kilometre,    "km" },
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
    {"m",              Unit::Length::Metre       },
    {"meter",          Unit::Length::Metre       },
    {"meters",         Unit::Length::Metre       },
    {"metre",          Unit::Length::Metre       },
    {"metres",         Unit::Length::Metre       },
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

// clang-format on

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Metre>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Metre>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::NauticalMile>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::NauticalMile>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Mile>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Mile>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Kilometre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Kilometre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Yard>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Yard>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Foot>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Foot>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Decimetre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(10.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Decimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.1L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Inch>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Inch>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Centimetre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(100.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Centimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.01L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Millimetre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Millimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Milliinch>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Milliinch>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Micrometre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Micrometre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Microinch>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Length, Unit::Length::Microinch>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L);
}

template <typename NumericType>
inline const std::map<Unit::Length,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Length, NumericType>{
        {Unit::Length::Metre,
         Conversions<Unit::Length, Unit::Length::Metre>::FromStandard<NumericType>       },
        {Unit::Length::NauticalMile,
         Conversions<Unit::Length, Unit::Length::NauticalMile>::FromStandard<NumericType>},
        {Unit::Length::Mile,
         Conversions<Unit::Length, Unit::Length::Mile>::FromStandard<NumericType>        },
        {Unit::Length::Kilometre,
         Conversions<Unit::Length, Unit::Length::Kilometre>::FromStandard<NumericType>   },
        {Unit::Length::Yard,
         Conversions<Unit::Length, Unit::Length::Yard>::FromStandard<NumericType>        },
        {Unit::Length::Foot,
         Conversions<Unit::Length, Unit::Length::Foot>::FromStandard<NumericType>        },
        {Unit::Length::Decimetre,
         Conversions<Unit::Length, Unit::Length::Decimetre>::FromStandard<NumericType>   },
        {Unit::Length::Inch,
         Conversions<Unit::Length, Unit::Length::Inch>::FromStandard<NumericType>        },
        {Unit::Length::Centimetre,
         Conversions<Unit::Length, Unit::Length::Centimetre>::FromStandard<NumericType>  },
        {Unit::Length::Millimetre,
         Conversions<Unit::Length, Unit::Length::Millimetre>::FromStandard<NumericType>  },
        {Unit::Length::Milliinch,
         Conversions<Unit::Length, Unit::Length::Milliinch>::FromStandard<NumericType>   },
        {Unit::Length::Micrometre,
         Conversions<Unit::Length, Unit::Length::Micrometre>::FromStandard<NumericType>  },
        {Unit::Length::Microinch,
         Conversions<Unit::Length, Unit::Length::Microinch>::FromStandard<NumericType>   },
};

template <typename NumericType>
inline const std::map<Unit::Length,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Length, NumericType>{
        {Unit::Length::Metre,
         Conversions<Unit::Length, Unit::Length::Metre>::ToStandard<NumericType>       },
        {Unit::Length::NauticalMile,
         Conversions<Unit::Length, Unit::Length::NauticalMile>::ToStandard<NumericType>},
        {Unit::Length::Mile,
         Conversions<Unit::Length, Unit::Length::Mile>::ToStandard<NumericType>        },
        {Unit::Length::Kilometre,
         Conversions<Unit::Length, Unit::Length::Kilometre>::ToStandard<NumericType>   },
        {Unit::Length::Yard,
         Conversions<Unit::Length, Unit::Length::Yard>::ToStandard<NumericType>        },
        {Unit::Length::Foot,
         Conversions<Unit::Length, Unit::Length::Foot>::ToStandard<NumericType>        },
        {Unit::Length::Decimetre,
         Conversions<Unit::Length, Unit::Length::Decimetre>::ToStandard<NumericType>   },
        {Unit::Length::Inch,
         Conversions<Unit::Length, Unit::Length::Inch>::ToStandard<NumericType>        },
        {Unit::Length::Centimetre,
         Conversions<Unit::Length, Unit::Length::Centimetre>::ToStandard<NumericType>  },
        {Unit::Length::Millimetre,
         Conversions<Unit::Length, Unit::Length::Millimetre>::ToStandard<NumericType>  },
        {Unit::Length::Milliinch,
         Conversions<Unit::Length, Unit::Length::Milliinch>::ToStandard<NumericType>   },
        {Unit::Length::Micrometre,
         Conversions<Unit::Length, Unit::Length::Micrometre>::ToStandard<NumericType>  },
        {Unit::Length::Microinch,
         Conversions<Unit::Length, Unit::Length::Microinch>::ToStandard<NumericType>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_LENGTH_HPP
