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

#ifndef PHQ_UNIT_MASS_DENSITY_HPP
#define PHQ_UNIT_MASS_DENSITY_HPP

#include <cmath>
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

/// \brief Mass density units.
enum class MassDensity : int8_t {
  /// \brief Kilogram per cubic metre (kg/m^3) mass density unit.
  KilogramPerCubicMetre,

  /// \brief Gram per cubic millimetre (g/mm^3) mass density unit.
  GramPerCubicMillimetre,

  /// \brief Slug per cubic foot (slug/ft^3) mass density unit.
  SlugPerCubicFoot,

  /// \brief Slinch per cubic inch (slinch/in^3) mass density unit.
  SlinchPerCubicInch,

  /// \brief Pound per cubic foot (lbm/ft^3) mass density unit.
  PoundPerCubicFoot,

  /// \brief Pound per cubic inch (lbm/in^3) mass density unit.
  PoundPerCubicInch,
};

}  // namespace Unit

/// \brief Standard mass density unit: kilogram per cubic metre (kg/m^3).
template <>
inline constexpr const Unit::MassDensity Standard<Unit::MassDensity>{
    Unit::MassDensity::KilogramPerCubicMetre};

/// \brief Physical dimension set of mass density units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::MassDensity>{
    Dimensions{Dimension::Time{0}, Dimension::Length{-3}, Dimension::Mass{1},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::MassDensity unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::MassDensity> ConsistentUnits<Unit::MassDensity>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::MassDensity::KilogramPerCubicMetre },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::MassDensity::GramPerCubicMillimetre},
    {UnitSystem::FootPoundSecondRankine,     Unit::MassDensity::SlugPerCubicFoot      },
    {UnitSystem::InchPoundSecondRankine,     Unit::MassDensity::SlinchPerCubicInch    },
};

template <>
inline const std::map<Unit::MassDensity, UnitSystem> RelatedUnitSystems<Unit::MassDensity>{
    {Unit::MassDensity::KilogramPerCubicMetre,  UnitSystem::MetreKilogramSecondKelvin },
    {Unit::MassDensity::GramPerCubicMillimetre, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::MassDensity::SlugPerCubicFoot,       UnitSystem::FootPoundSecondRankine    },
    {Unit::MassDensity::SlinchPerCubicInch,     UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::MassDensity, std::string_view> Abbreviations<Unit::MassDensity>{
    {Unit::MassDensity::KilogramPerCubicMetre,  "kg/m^3"     },
    {Unit::MassDensity::GramPerCubicMillimetre, "g/mm^3"     },
    {Unit::MassDensity::SlugPerCubicFoot,       "slug/ft^3"  },
    {Unit::MassDensity::SlinchPerCubicInch,     "slinch/in^3"},
    {Unit::MassDensity::PoundPerCubicFoot,      "lbm/ft^3"   },
    {Unit::MassDensity::PoundPerCubicInch,      "lbm/in^3"   },
};

template <>
inline const std::unordered_map<std::string_view, Unit::MassDensity> Spellings<Unit::MassDensity>{
    {"kg/m^3",          Unit::MassDensity::KilogramPerCubicMetre },
    {"kg/m3",           Unit::MassDensity::KilogramPerCubicMetre },
    {"kg/m/m/m",        Unit::MassDensity::KilogramPerCubicMetre },
    {"g/mm^3",          Unit::MassDensity::GramPerCubicMillimetre},
    {"g/mm3",           Unit::MassDensity::GramPerCubicMillimetre},
    {"g/mm/mm/mm",      Unit::MassDensity::GramPerCubicMillimetre},
    {"slug/ft^3",       Unit::MassDensity::SlugPerCubicFoot      },
    {"slug/ft3",        Unit::MassDensity::SlugPerCubicFoot      },
    {"slug/ft/ft/ft",   Unit::MassDensity::SlugPerCubicFoot      },
    {"slinch/in^3",     Unit::MassDensity::SlinchPerCubicInch    },
    {"slinch/in3",      Unit::MassDensity::SlinchPerCubicInch    },
    {"slinch/in/in/in", Unit::MassDensity::SlinchPerCubicInch    },
    {"lbm/ft^3",        Unit::MassDensity::PoundPerCubicFoot     },
    {"lbm/ft3",         Unit::MassDensity::PoundPerCubicFoot     },
    {"lbm/ft/ft/ft",    Unit::MassDensity::PoundPerCubicFoot     },
    {"lb/ft^3",         Unit::MassDensity::PoundPerCubicFoot     },
    {"lb/ft3",          Unit::MassDensity::PoundPerCubicFoot     },
    {"lb/ft/ft/ft",     Unit::MassDensity::PoundPerCubicFoot     },
    {"lbm/in^3",        Unit::MassDensity::PoundPerCubicInch     },
    {"lbm/in3",         Unit::MassDensity::PoundPerCubicInch     },
    {"lbm/in/in/in",    Unit::MassDensity::PoundPerCubicInch     },
    {"lb/in^3",         Unit::MassDensity::PoundPerCubicInch     },
    {"lb/in3",          Unit::MassDensity::PoundPerCubicInch     },
    {"lb/in/in/in",     Unit::MassDensity::PoundPerCubicInch     },
};

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::KilogramPerCubicMetre>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::KilogramPerCubicMetre>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::GramPerCubicMillimetre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::GramPerCubicMillimetre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::SlugPerCubicFoot>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L)
           * static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::SlugPerCubicFoot>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / std::pow(static_cast<Number>(0.3048L), 4);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::SlinchPerCubicInch>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L)
           * static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::SlinchPerCubicInch>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / std::pow(static_cast<Number>(0.0254L), 4);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::PoundPerCubicFoot>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L)
           * static_cast<Number>(0.3048L) / static_cast<Number>(0.45359237L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::PoundPerCubicFoot>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) / std::pow(static_cast<Number>(0.3048L), 3);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::PoundPerCubicInch>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L)
           * static_cast<Number>(0.0254L) / static_cast<Number>(0.45359237L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MassDensity, Unit::MassDensity::PoundPerCubicInch>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) / std::pow(static_cast<Number>(0.0254L), 3);
}

template <typename Number>
inline const std::map<Unit::MassDensity,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::MassDensity, Number>{
        {Unit::MassDensity::KilogramPerCubicMetre,
         Conversions<Unit::MassDensity,
         Unit::MassDensity::KilogramPerCubicMetre>::FromStandard<Number>                          },
        {Unit::MassDensity::GramPerCubicMillimetre,
         Conversions<Unit::MassDensity,
         Unit::MassDensity::GramPerCubicMillimetre>::FromStandard<Number>                         },
        {Unit::MassDensity::SlugPerCubicFoot,
         Conversions<Unit::MassDensity, Unit::MassDensity::SlugPerCubicFoot>::FromStandard<Number>},
        {Unit::MassDensity::SlinchPerCubicInch,
         Conversions<Unit::MassDensity,
         Unit::MassDensity::SlinchPerCubicInch>::FromStandard<Number>                             },
        {Unit::MassDensity::PoundPerCubicFoot,
         Conversions<Unit::MassDensity,
         Unit::MassDensity::PoundPerCubicFoot>::FromStandard<Number>                              },
        {Unit::MassDensity::PoundPerCubicInch,
         Conversions<Unit::MassDensity,
         Unit::MassDensity::PoundPerCubicInch>::FromStandard<Number>                              },
};

template <typename Number>
inline const std::map<Unit::MassDensity,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::MassDensity, Number>{
        {Unit::MassDensity::KilogramPerCubicMetre,
         Conversions<Unit::MassDensity,
         Unit::MassDensity::KilogramPerCubicMetre>::ToStandard<Number>                            },
        {Unit::MassDensity::GramPerCubicMillimetre,
         Conversions<Unit::MassDensity,
         Unit::MassDensity::GramPerCubicMillimetre>::ToStandard<Number>                           },
        {Unit::MassDensity::SlugPerCubicFoot,
         Conversions<Unit::MassDensity, Unit::MassDensity::SlugPerCubicFoot>::ToStandard<Number>  },
        {Unit::MassDensity::SlinchPerCubicInch,
         Conversions<Unit::MassDensity, Unit::MassDensity::SlinchPerCubicInch>::ToStandard<Number>},
        {Unit::MassDensity::PoundPerCubicFoot,
         Conversions<Unit::MassDensity, Unit::MassDensity::PoundPerCubicFoot>::ToStandard<Number> },
        {Unit::MassDensity::PoundPerCubicInch,
         Conversions<Unit::MassDensity, Unit::MassDensity::PoundPerCubicInch>::ToStandard<Number> },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_MASS_DENSITY_HPP
