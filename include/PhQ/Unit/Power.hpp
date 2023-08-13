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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_POWER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_POWER_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

// Power units.
enum class Power : int_least8_t {
  Watt,
  Milliwatt,
  Microwatt,
  Nanowatt,
  Kilowatt,
  Megawatt,
  Gigawatt,
  FootPoundPerSecond,
  InchPoundPerSecond,
};

}  // namespace Unit

// Standard power unit: watt.
template<>
inline constexpr const Unit::Power StandardUnit<Unit::Power>{Unit::Power::Watt};

// Physical dimension set of power units.
template<> inline constexpr const Dimension::Set Dimensions<Unit::Power>{
    Dimension::Set{
                   Dimension::Time{-3}, Dimension::Length{2}, Dimension::Mass{1}}
};

namespace Internal {

template<>
inline const std::map<UnitSystem, Unit::Power> ConsistentUnits<Unit::Power>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Power::Watt              },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Power::Nanowatt          },
    {UnitSystem::FootPoundSecondRankine,     Unit::Power::FootPoundPerSecond},
    {UnitSystem::InchPoundSecondRankine,     Unit::Power::InchPoundPerSecond},
};

template<>
inline const std::map<Unit::Power, UnitSystem> RelatedUnitSystems<Unit::Power>{
    {Unit::Power::Watt,               UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Power::Nanowatt,           UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Power::FootPoundPerSecond, UnitSystem::FootPoundSecondRankine    },
    {Unit::Power::InchPoundPerSecond, UnitSystem::InchPoundSecondRankine    },
};

template<>
inline const std::map<Unit::Power, std::string_view> Abbreviations<Unit::Power>{
    {Unit::Power::Watt,               "W"       },
    {Unit::Power::Milliwatt,          "mW"      },
    {Unit::Power::Microwatt,          "μW"      },
    {Unit::Power::Nanowatt,           "nW"      },
    {Unit::Power::Kilowatt,           "kW"      },
    {Unit::Power::Megawatt,           "MW"      },
    {Unit::Power::Gigawatt,           "GW"      },
    {Unit::Power::FootPoundPerSecond, "ft·lbf/s"},
    {Unit::Power::InchPoundPerSecond, "in·lbf/s"},
};

template<> inline const std::unordered_map<std::string_view, Unit::Power>
    Spellings<Unit::Power>{
        {"W",          Unit::Power::Watt              },
        {"J/s",        Unit::Power::Watt              },
        {"N·m/s",      Unit::Power::Watt              },
        {"N*m/s",      Unit::Power::Watt              },
        {"kg·m^2/s^3", Unit::Power::Watt              },
        {"kg*m^2/s^3", Unit::Power::Watt              },
        {"kg·m2/s3",   Unit::Power::Watt              },
        {"kg*m2/s3",   Unit::Power::Watt              },
        {"mW",         Unit::Power::Milliwatt         },
        {"mJ/s",       Unit::Power::Milliwatt         },
        {"μW",         Unit::Power::Microwatt         },
        {"μJ/s",       Unit::Power::Microwatt         },
        {"uW",         Unit::Power::Microwatt         },
        {"uJ/s",       Unit::Power::Microwatt         },
        {"nW",         Unit::Power::Nanowatt          },
        {"nJ/s",       Unit::Power::Nanowatt          },
        {"μN·mm/s",    Unit::Power::Nanowatt          },
        {"μN*mm/s",    Unit::Power::Nanowatt          },
        {"uN·mm/s",    Unit::Power::Nanowatt          },
        {"uN*mm/s",    Unit::Power::Nanowatt          },
        {"g·mm^2/s^3", Unit::Power::Nanowatt          },
        {"g*mm^2/s^3", Unit::Power::Nanowatt          },
        {"g·mm2/s3",   Unit::Power::Nanowatt          },
        {"g*mm2/s3",   Unit::Power::Nanowatt          },
        {"kW",         Unit::Power::Kilowatt          },
        {"kJ/s",       Unit::Power::Kilowatt          },
        {"MW",         Unit::Power::Megawatt          },
        {"MJ/s",       Unit::Power::Megawatt          },
        {"GW",         Unit::Power::Gigawatt          },
        {"GJ/s",       Unit::Power::Gigawatt          },
        {"ft·lbf/s",   Unit::Power::FootPoundPerSecond},
        {"ft*lbf/s",   Unit::Power::FootPoundPerSecond},
        {"ft·lb/s",    Unit::Power::FootPoundPerSecond},
        {"ft*lb/s",    Unit::Power::FootPoundPerSecond},
        {"in·lbf/s",   Unit::Power::InchPoundPerSecond},
        {"in*lbf/s",   Unit::Power::InchPoundPerSecond},
        {"in·lb/s",    Unit::Power::InchPoundPerSecond},
        {"in*lb/s",    Unit::Power::InchPoundPerSecond},
};

template<> inline constexpr void
ConversionFromStandard<Unit::Power, Unit::Power::Watt>(double& value) noexcept {
}

template<> inline constexpr void
ConversionFromStandard<Unit::Power, Unit::Power::Milliwatt>(
    double& value) noexcept {
  value *= 1000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Power, Unit::Power::Microwatt>(
    double& value) noexcept {
  value *= 1000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Power, Unit::Power::Nanowatt>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Power, Unit::Power::Kilowatt>(
    double& value) noexcept {
  value *= 0.001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Power, Unit::Power::Megawatt>(
    double& value) noexcept {
  value *= 0.000001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Power, Unit::Power::Gigawatt>(
    double& value) noexcept {
  value *= 0.000000001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Power, Unit::Power::FootPoundPerSecond>(
    double& value) noexcept {
  value /= 0.3048 * 0.45359237 * 9.80665;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Power, Unit::Power::InchPoundPerSecond>(
    double& value) noexcept {
  value /= 0.0254 * 0.45359237 * 9.80665;
}

template<> inline constexpr void
ConversionToStandard<Unit::Power, Unit::Power::Watt>(double& value) noexcept {}

template<>
inline constexpr void ConversionToStandard<Unit::Power, Unit::Power::Milliwatt>(
    double& value) noexcept {
  value *= 0.001;
}

template<>
inline constexpr void ConversionToStandard<Unit::Power, Unit::Power::Microwatt>(
    double& value) noexcept {
  value *= 0.000001;
}

template<>
inline constexpr void ConversionToStandard<Unit::Power, Unit::Power::Nanowatt>(
    double& value) noexcept {
  value *= 0.000000001;
}

template<>
inline constexpr void ConversionToStandard<Unit::Power, Unit::Power::Kilowatt>(
    double& value) noexcept {
  value *= 1000.0;
}

template<>
inline constexpr void ConversionToStandard<Unit::Power, Unit::Power::Megawatt>(
    double& value) noexcept {
  value *= 1000000.0;
}

template<>
inline constexpr void ConversionToStandard<Unit::Power, Unit::Power::Gigawatt>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Power, Unit::Power::FootPoundPerSecond>(
    double& value) noexcept {
  value *= 0.3048 * 0.45359237 * 9.80665;
}

template<> inline constexpr void
ConversionToStandard<Unit::Power, Unit::Power::InchPoundPerSecond>(
    double& value) noexcept {
  value *= 0.0254 * 0.45359237 * 9.80665;
}

template<> inline const std::map<
    Unit::Power, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Power>{
        {Unit::Power::Watt,
         ConversionsFromStandard<Unit::Power, Unit::Power::Watt>              },
        {Unit::Power::Milliwatt,
         ConversionsFromStandard<Unit::Power, Unit::Power::Milliwatt>         },
        {Unit::Power::Microwatt,
         ConversionsFromStandard<Unit::Power, Unit::Power::Microwatt>         },
        {Unit::Power::Nanowatt,
         ConversionsFromStandard<Unit::Power, Unit::Power::Nanowatt>          },
        {Unit::Power::Kilowatt,
         ConversionsFromStandard<Unit::Power, Unit::Power::Kilowatt>          },
        {Unit::Power::Megawatt,
         ConversionsFromStandard<Unit::Power, Unit::Power::Megawatt>          },
        {Unit::Power::Gigawatt,
         ConversionsFromStandard<Unit::Power, Unit::Power::Gigawatt>          },
        {Unit::Power::FootPoundPerSecond,
         ConversionsFromStandard<Unit::Power, Unit::Power::FootPoundPerSecond>},
        {Unit::Power::InchPoundPerSecond,
         ConversionsFromStandard<Unit::Power, Unit::Power::InchPoundPerSecond>},
};

template<>
inline const std::map<Unit::Power, std::function<void(double* const values,
                                                      const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Power>{
        {Unit::Power::Watt,
         ConversionsToStandard<Unit::Power, Unit::Power::Watt>              },
        {Unit::Power::Milliwatt,
         ConversionsToStandard<Unit::Power, Unit::Power::Milliwatt>         },
        {Unit::Power::Microwatt,
         ConversionsToStandard<Unit::Power, Unit::Power::Microwatt>         },
        {Unit::Power::Nanowatt,
         ConversionsToStandard<Unit::Power, Unit::Power::Nanowatt>          },
        {Unit::Power::Kilowatt,
         ConversionsToStandard<Unit::Power, Unit::Power::Kilowatt>          },
        {Unit::Power::Megawatt,
         ConversionsToStandard<Unit::Power, Unit::Power::Megawatt>          },
        {Unit::Power::Gigawatt,
         ConversionsToStandard<Unit::Power, Unit::Power::Gigawatt>          },
        {Unit::Power::FootPoundPerSecond,
         ConversionsToStandard<Unit::Power, Unit::Power::FootPoundPerSecond>},
        {Unit::Power::InchPoundPerSecond,
         ConversionsToStandard<Unit::Power, Unit::Power::InchPoundPerSecond>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_POWER_HPP
