// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPECIFIC_HEAT_CAPACITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPECIFIC_HEAT_CAPACITY_HPP

#include "../Unit.hpp"

namespace PhQ {

namespace Unit {

// Mass-specific heat capacity units.
enum class SpecificHeatCapacity : int_least8_t {
  JoulePerKilogramPerKelvin,
  NanojoulePerGramPerKelvin,
  FootPoundPerSlugPerRankine,
  InchPoundPerSlinchPerRankine,
};

}  // namespace Unit

// Standard mass-specific heat capacity unit: joule per kilogram per kelvin.
template<> inline constexpr const Unit::SpecificHeatCapacity
    Standard<Unit::SpecificHeatCapacity>{
        Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};

// Physical dimension set of mass-specific heat capacity units.
template<>
inline constexpr const Dimensions RelatedDimensions<Unit::SpecificHeatCapacity>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{},
               Dimension::ElectricCurrent{}, Dimension::Temperature{-1}}
};

namespace Internal {

template<> inline const std::map<UnitSystem, Unit::SpecificHeatCapacity>
    ConsistentUnits<Unit::SpecificHeatCapacity>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
        {UnitSystem::FootPoundSecondRankine,
         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
        {UnitSystem::InchPoundSecondRankine,
         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
};

template<> inline const std::map<Unit::SpecificHeatCapacity, UnitSystem>
    RelatedUnitSystems<Unit::SpecificHeatCapacity>{
        {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin,
         UnitSystem::MetreKilogramSecondKelvin },
        {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine,
         UnitSystem::FootPoundSecondRankine    },
        {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine,
         UnitSystem::InchPoundSecondRankine    },
};

template<> inline const std::map<Unit::SpecificHeatCapacity, std::string_view>
    Abbreviations<Unit::SpecificHeatCapacity>{
        {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin,    "J/kg/K"},
        {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin,    "nJ/g/K"},
        {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine,
         "ft·lbf/slug/°R"                                                },
        {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine,
         "in·lbf/slinch/°R"                                              },
};

template<>
inline const std::unordered_map<std::string_view, Unit::SpecificHeatCapacity> Spellings<
    Unit::SpecificHeatCapacity>{
    {"J/kg/K",               Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg·K)",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg*K)",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/kg/K",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/(kg·K)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/kg/K",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/(kg*K)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/kg/K",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/(kg·K)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/kg/K",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/(kg*K)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/s^2/K",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2·K)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2*K)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/s2/K",              Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2·K)",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2*K)",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/kg/°C",              Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg·°C)",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg*°C)",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/kg/°C",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/(kg·°C)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/kg/°C",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/(kg*°C)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/kg/°C",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/(kg·°C)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/kg/°C",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/(kg*°C)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/s^2/°C",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2·°C)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2*°C)",         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/s2/°C",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2·°C)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2*°C)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/kg/C",               Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg·C)",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"J/(kg*C)",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/kg/C",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N·m/(kg·C)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/kg/C",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"N*m/(kg*C)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/kg/C",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m·N/(kg·C)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/kg/C",             Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m*N/(kg*C)",           Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/s^2/C",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2·C)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m^2/(s^2*C)",          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/s2/C",              Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2·C)",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"m2/(s2*C)",            Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin   },
    {"nJ/g/K",               Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g*K)",             Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g·K)",             Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/g/K",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/(g·K)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/g/K",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/(g*K)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/g/K",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/(g·K)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/g/K",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/(g*K)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/g/K",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/(g·K)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/g/K",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/(g*K)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/g/K",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/(g·K)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/g/K",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/(g*K)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/s^2/K",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2·K)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2*K)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/s2/K",             Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2·K)",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2*K)",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/g/°C",              Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g*°C)",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g·°C)",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/g/°C",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/(g·°C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/g/°C",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/(g*°C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/g/°C",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/(g·°C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/g/°C",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/(g*°C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/g/°C",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/(g·°C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/g/°C",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/(g*°C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/g/°C",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/(g·°C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/g/°C",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/(g*°C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/s^2/°C",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2·°C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2*°C)",        Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/s2/°C",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2·°C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2*°C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/g/C",               Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g*C)",             Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"nJ/(g·C)",             Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/g/C",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN·mm/(g·C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/g/C",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"μN*mm/(g*C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/g/C",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN·mm/(g·C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/g/C",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"uN*mm/(g*C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/g/C",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·μN/(g·C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/g/C",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*μN/(g*C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/g/C",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm·uN/(g·C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/g/C",            Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm*uN/(g*C)",          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/s^2/C",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2·C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm^2/(s^2*C)",         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/s2/C",             Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2·C)",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"mm2/(s2*C)",           Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin   },
    {"ft·lbf/slug/°R",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/(slug·°R)",
     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine                          },
    {"ft*lbf/slug/°R",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/(slug*°R)",
     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine                          },
    {"lbf·ft/slug/°R",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/(slug·°R)",
     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine                          },
    {"lbf*ft/slug/°R",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/(slug*°R)",
     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine                          },
    {"ft·lb/slug/°R",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/(slug·°R)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/slug/°R",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/(slug*°R)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/slug/°R",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/(slug·°R)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/slug/°R",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/(slug*°R)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/s^2/°R",          Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2·°R)",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2*°R)",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/s2/°R",            Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2·°R)",          Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2*°R)",          Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/slug/R",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/(slug·R)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/slug/R",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/(slug*R)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/slug/R",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/(slug·R)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/slug/R",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/(slug*R)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/slug/R",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/(slug·R)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/slug/R",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/(slug*R)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/slug/R",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/(slug·R)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/slug/R",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/(slug*R)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/s^2/R",           Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2·R)",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2*R)",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/s2/R",             Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2·R)",           Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2*R)",           Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/slug/°F",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/(slug·°F)",
     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine                          },
    {"ft*lbf/slug/°F",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/(slug*°F)",
     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine                          },
    {"lbf·ft/slug/°F",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/(slug·°F)",
     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine                          },
    {"lbf*ft/slug/°F",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/(slug*°F)",
     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine                          },
    {"ft·lb/slug/°F",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/(slug·°F)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/slug/°F",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/(slug*°F)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/slug/°F",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/(slug·°F)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/slug/°F",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/(slug*°F)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/s^2/°F",          Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2·°F)",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2*°F)",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/s2/°F",            Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2·°F)",          Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2*°F)",          Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/slug/F",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lbf/(slug·F)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/slug/F",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lbf/(slug*F)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/slug/F",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf·ft/(slug·F)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/slug/F",        Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lbf*ft/(slug*F)",      Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/slug/F",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft·lb/(slug·F)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/slug/F",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft*lb/(slug*F)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/slug/F",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb·ft/(slug·F)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/slug/F",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"lb*ft/(slug*F)",       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/s^2/F",           Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2·F)",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft^2/(s^2*F)",         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/s2/F",             Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2·F)",           Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"ft2/(s2*F)",           Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine  },
    {"in·lbf/slinch/°R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lbf/(slinch·°R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lbf/slinch/°R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lbf/(slinch*°R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf·in/slinch/°R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf·in/(slinch·°R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf*in/slinch/°R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf*in/(slinch*°R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lb/slinch/°R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lb/(slinch·°R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lb/slinch/°R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lb/(slinch*°R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb·in/slinch/°R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb·in/(slinch·°R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb*in/slinch/°R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb*in/(slinch*°R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in^2/s^2/°R",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2·°R)",       Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2*°R)",       Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/s2/°R",           Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2·°R)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2*°R)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lbf/slinch/R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lbf/(slinch·R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lbf/slinch/R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lbf/(slinch*R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf·in/slinch/R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf·in/(slinch·R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf*in/slinch/R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf*in/(slinch*R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lb/slinch/R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lb/(slinch·R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lb/slinch/R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lb/(slinch*R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb·in/slinch/R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb·in/(slinch·R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb*in/slinch/R",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb*in/(slinch*R)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in^2/s^2/R",           Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2·R)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2*R)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/s2/R",             Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2·R)",           Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2*R)",           Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lbf/slinch/°F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lbf/(slinch·°F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lbf/slinch/°F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lbf/(slinch*°F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf·in/slinch/°F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf·in/(slinch·°F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf*in/slinch/°F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf*in/(slinch*°F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lb/slinch/°F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lb/(slinch·°F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lb/slinch/°F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lb/(slinch*°F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb·in/slinch/°F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb·in/(slinch·°F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb*in/slinch/°F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb*in/(slinch*°F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in^2/s^2/°F",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2·°F)",       Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2*°F)",       Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/s2/°F",           Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2·°F)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2*°F)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in·lbf/slinch/F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lbf/(slinch·F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lbf/slinch/F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lbf/(slinch*F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf·in/slinch/F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf·in/(slinch·F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf*in/slinch/F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lbf*in/(slinch*F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lb/slinch/F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in·lb/(slinch·F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lb/slinch/F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in*lb/(slinch*F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb·in/slinch/F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb·in/(slinch·F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb*in/slinch/F",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"lb*in/(slinch*F)",
     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine                        },
    {"in^2/s^2/F",           Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2·F)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in^2/(s^2*F)",         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/s2/F",             Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2·F)",           Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
    {"in2/(s2*F)",           Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
};

template<> inline constexpr void
ConversionFromStandard<Unit::SpecificHeatCapacity,
                       Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionFromStandard<Unit::SpecificHeatCapacity,
                       Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>(
    double& value) noexcept {
  value *= 1000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::SpecificHeatCapacity,
                       Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine>(
    double& value) noexcept {
  value /= 1.8 * std::pow(0.3048, 2);
}

template<> inline constexpr void
ConversionFromStandard<Unit::SpecificHeatCapacity,
                       Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine>(
    double& value) noexcept {
  value /= 1.8 * std::pow(0.0254, 2);
}

template<> inline constexpr void
ConversionToStandard<Unit::SpecificHeatCapacity,
                     Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::SpecificHeatCapacity,
                     Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>(
    double& value) noexcept {
  value *= 0.000001;
}

template<> inline constexpr void
ConversionToStandard<Unit::SpecificHeatCapacity,
                     Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine>(
    double& value) noexcept {
  value *= 1.8 * std::pow(0.3048, 2);
}

template<> inline constexpr void
ConversionToStandard<Unit::SpecificHeatCapacity,
                     Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine>(
    double& value) noexcept {
  value *= 1.8 * std::pow(0.0254, 2);
}

template<> inline const std::map<
    Unit::SpecificHeatCapacity,
    std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::SpecificHeatCapacity>{
        {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin,
         ConversionsFromStandard<
             Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>   },
        {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin,
         ConversionsFromStandard<
             Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>   },
        {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine,
         ConversionsFromStandard<
             Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine>  },
        {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine,
         ConversionsFromStandard<
             Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine>},
};

template<> inline const std::map<
    Unit::SpecificHeatCapacity,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::SpecificHeatCapacity>{
        {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin,
         ConversionsToStandard<
             Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>   },
        {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin,
         ConversionsToStandard<
             Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>   },
        {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine,
         ConversionsToStandard<
             Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine>  },
        {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine,
         ConversionsToStandard<
             Unit::SpecificHeatCapacity,
         Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPECIFIC_HEAT_CAPACITY_HPP
