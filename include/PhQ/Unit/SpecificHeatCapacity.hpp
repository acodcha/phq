// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
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

#ifndef PHQ_UNIT_SPECIFIC_HEAT_CAPACITY_HPP
#define PHQ_UNIT_SPECIFIC_HEAT_CAPACITY_HPP

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

/// \brief Mass-specific heat capacity units.
enum class SpecificHeatCapacity : int8_t {
  /// \brief Joule per kilogram per kelvin (J/kg/K) specific heat capacity unit.
  JoulePerKilogramPerKelvin,

  /// \brief Nanojoule per gram per kelvin (nJ/g/K) specific heat capacity unit.
  NanojoulePerGramPerKelvin,

  /// \brief Foot-pound per slug per degree Rankine (ft·lbf/slug/°R) specific heat capacity unit.
  FootPoundPerSlugPerRankine,

  /// \brief Inch-pound per slinch per degree Rankine (in·lbf/slinch/°R) specific heat capacity
  /// unit.
  InchPoundPerSlinchPerRankine,
};

}  // namespace Unit

/// \brief Standard mass-specific heat capacity unit: joule per kilogram per kelvin (J/kg/K).
template <>
inline constexpr const Unit::SpecificHeatCapacity Standard<Unit::SpecificHeatCapacity>{
    Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};

/// \brief Physical dimension set of mass-specific heat capacity units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::SpecificHeatCapacity>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{-1},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::SpecificHeatCapacity unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::SpecificHeatCapacity> ConsistentUnits<
    Unit::SpecificHeatCapacity>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {UnitSystem::FootPoundSecondRankine,     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {UnitSystem::InchPoundSecondRankine,     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
};

template <>
inline const std::map<Unit::SpecificHeatCapacity, UnitSystem> RelatedUnitSystems<
    Unit::SpecificHeatCapacity>{
    {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin,    UnitSystem::MetreKilogramSecondKelvin },
    {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin,    UnitSystem::MillimetreGramSecondKelvin},
    {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine,   UnitSystem::FootPoundSecondRankine    },
    {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine, UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::SpecificHeatCapacity, std::string_view>
    Abbreviations<Unit::SpecificHeatCapacity>{
        {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin,    "J/kg/K"          },
        {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin,    "nJ/g/K"          },
        {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine,   "ft·lbf/slug/°R"  },
        {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine, "in·lbf/slinch/°R"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::SpecificHeatCapacity> Spellings<
    Unit::SpecificHeatCapacity>{
    {"J/kg/K",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg·K)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg*K)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/kg/K",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/(kg·K)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/kg/K",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/(kg*K)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/kg/K",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/(kg·K)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/kg/K",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/(kg*K)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/s^2/K",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2·K)",        Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2*K)",        Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/s2/K",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2·K)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2*K)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/kg/°C",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg·°C)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg*°C)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/kg/°C",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/(kg·°C)",        Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/kg/°C",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/(kg*°C)",        Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/kg/°C",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/(kg·°C)",        Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/kg/°C",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/(kg*°C)",        Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/s^2/°C",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2·°C)",       Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2*°C)",       Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/s2/°C",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2·°C)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2*°C)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/kg/C",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg·C)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg*C)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/kg/C",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/(kg·C)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/kg/C",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/(kg*C)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/kg/C",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/(kg·C)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/kg/C",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/(kg*C)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/s^2/C",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2·C)",        Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2*C)",        Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/s2/C",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2·C)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2*C)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"nJ/g/K",             Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g*K)",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g·K)",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/g/K",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/(g·K)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/g/K",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/(g*K)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/g/K",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/(g·K)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/g/K",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/(g*K)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/g/K",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/(g·K)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/g/K",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/(g*K)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/g/K",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/(g·K)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/g/K",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/(g*K)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/s^2/K",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2·K)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2*K)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/s2/K",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2·K)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2*K)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/g/°C",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g*°C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g·°C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/g/°C",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/(g·°C)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/g/°C",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/(g*°C)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/g/°C",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/(g·°C)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/g/°C",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/(g*°C)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/g/°C",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/(g·°C)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/g/°C",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/(g*°C)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/g/°C",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/(g·°C)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/g/°C",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/(g*°C)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/s^2/°C",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2·°C)",      Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2*°C)",      Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/s2/°C",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2·°C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2*°C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/g/C",             Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g*C)",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g·C)",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/g/C",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/(g·C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/g/C",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/(g*C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/g/C",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/(g·C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/g/C",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/(g*C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/g/C",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/(g·C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/g/C",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/(g*C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/g/C",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/(g·C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/g/C",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/(g*C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/s^2/C",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2·C)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2*C)",       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/s2/C",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2·C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2*C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"ft·lbf/slug/°R",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/(slug·°R)",   Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/slug/°R",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/(slug*°R)",   Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/slug/°R",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/(slug·°R)",   Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/slug/°R",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/(slug*°R)",   Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/slug/°R",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/(slug·°R)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/slug/°R",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/(slug*°R)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/slug/°R",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/(slug·°R)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/slug/°R",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/(slug*°R)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/s^2/°R",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2·°R)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2*°R)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/s2/°R",          Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2·°R)",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2*°R)",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/slug/R",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/(slug·R)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/slug/R",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/(slug*R)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/slug/R",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/(slug·R)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/slug/R",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/(slug*R)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/slug/R",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/(slug·R)",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/slug/R",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/(slug*R)",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/slug/R",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/(slug·R)",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/slug/R",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/(slug*R)",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/s^2/R",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2·R)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2*R)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/s2/R",           Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2·R)",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2*R)",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/slug/°F",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/(slug·°F)",   Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/slug/°F",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/(slug*°F)",   Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/slug/°F",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/(slug·°F)",   Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/slug/°F",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/(slug*°F)",   Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/slug/°F",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/(slug·°F)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/slug/°F",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/(slug*°F)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/slug/°F",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/(slug·°F)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/slug/°F",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/(slug*°F)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/s^2/°F",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2·°F)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2*°F)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/s2/°F",          Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2·°F)",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2*°F)",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/slug/F",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/(slug·F)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/slug/F",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/(slug*F)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/slug/F",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/(slug·F)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/slug/F",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/(slug*F)",    Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/slug/F",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/(slug·F)",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/slug/F",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/(slug*F)",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/slug/F",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/(slug·F)",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/slug/F",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/(slug*F)",     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/s^2/F",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2·F)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2*F)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/s2/F",           Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2·F)",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2*F)",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"in·lbf/slinch/°R",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lbf/(slinch·°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lbf/slinch/°R",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lbf/(slinch*°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf·in/slinch/°R",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf·in/(slinch·°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf*in/slinch/°R",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf*in/(slinch*°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lb/slinch/°R",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lb/(slinch·°R)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lb/slinch/°R",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lb/(slinch*°R)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb·in/slinch/°R",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb·in/(slinch·°R)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb*in/slinch/°R",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb*in/(slinch*°R)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/s^2/°R",        Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2·°R)",      Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2*°R)",      Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/s2/°R",          Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2·°R)",        Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2*°R)",        Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lbf/slinch/R",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lbf/(slinch·R)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lbf/slinch/R",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lbf/(slinch*R)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf·in/slinch/R",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf·in/(slinch·R)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf*in/slinch/R",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf*in/(slinch*R)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lb/slinch/R",     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lb/(slinch·R)",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lb/slinch/R",     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lb/(slinch*R)",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb·in/slinch/R",     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb·in/(slinch·R)",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb*in/slinch/R",     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb*in/(slinch*R)",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/s^2/R",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2·R)",       Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2*R)",       Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/s2/R",           Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2·R)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2*R)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lbf/slinch/°F",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lbf/(slinch·°F)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lbf/slinch/°F",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lbf/(slinch*°F)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf·in/slinch/°F",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf·in/(slinch·°F)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf*in/slinch/°F",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf*in/(slinch*°F)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lb/slinch/°F",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lb/(slinch·°F)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lb/slinch/°F",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lb/(slinch*°F)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb·in/slinch/°F",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb·in/(slinch·°F)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb*in/slinch/°F",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb*in/(slinch*°F)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/s^2/°F",        Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2·°F)",      Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2*°F)",      Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/s2/°F",          Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2·°F)",        Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2*°F)",        Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lbf/slinch/F",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lbf/(slinch·F)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lbf/slinch/F",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lbf/(slinch*F)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf·in/slinch/F",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf·in/(slinch·F)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf*in/slinch/F",    Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lbf*in/(slinch*F)",  Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lb/slinch/F",     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lb/(slinch·F)",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lb/slinch/F",     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in*lb/(slinch*F)",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb·in/slinch/F",     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb·in/(slinch·F)",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb*in/slinch/F",     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"lb*in/(slinch*F)",   Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/s^2/F",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2·F)",       Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2*F)",       Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/s2/F",           Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2·F)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2*F)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
};

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificHeatCapacity, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>::
    FromStandard(Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificHeatCapacity, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>::
    ToStandard(Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificHeatCapacity, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>::
    FromStandard(Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificHeatCapacity, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>::
    ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificHeatCapacity, Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine>::
    FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(1.8L) * static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificHeatCapacity, Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine>::
    ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(1.8L) * static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificHeatCapacity, Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine>::
    FromStandard(Number& value) noexcept {
  value /= static_cast<Number>(1.8L) * static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificHeatCapacity, Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine>::
    ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(1.8L) * static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L);
}

template <typename Number>
inline const std::map<Unit::SpecificHeatCapacity,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::SpecificHeatCapacity, Number>{
        {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin,
         Conversions<Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>::FromStandard<Number>   },
        {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin,
         Conversions<Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>::FromStandard<Number>   },
        {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine,
         Conversions<Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine>::FromStandard<Number>  },
        {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine,
         Conversions<
             Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine>::FromStandard<Number>},
};

template <typename Number>
inline const std::map<Unit::SpecificHeatCapacity,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::SpecificHeatCapacity, Number>{
        {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin,
         Conversions<Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>::ToStandard<Number>   },
        {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin,
         Conversions<Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>::ToStandard<Number>   },
        {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine,
         Conversions<Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine>::ToStandard<Number>  },
        {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine,
         Conversions<Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine>::ToStandard<Number>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_SPECIFIC_HEAT_CAPACITY_HPP
