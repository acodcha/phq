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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_EXPANSION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_EXPANSION_HPP

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
#include "../Dimension/Mass.hpp"
#include "../Dimension/Temperature.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

// Thermal expansion units.
enum class ThermalExpansion : int8_t {
  // Per kelvin (/K) thermal expansion unit.
  PerKelvin,

  // Per degree Celsius (/°C) thermal expansion unit.
  PerCelsius,

  // Per degree Rankine (/°R) thermal expansion unit.
  PerRankine,

  // Per degree Fahrenheit (/°F) thermal expansion unit.
  PerFahrenheit
};

}  // namespace Unit

// Standard thermal expansion unit: per kelvin (/K).
template <>
inline constexpr const Unit::ThermalExpansion Standard<Unit::ThermalExpansion>{
    Unit::ThermalExpansion::PerKelvin};

// Physical dimension set of thermal expansion units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::ThermalExpansion>{
    Dimensions{Dimension::Time{}, Dimension::Length{}, Dimension::Mass{},
               Dimension::ElectricCurrent{}, Dimension::Temperature{-1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::ThermalExpansion unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::ThermalExpansion> ConsistentUnits<Unit::ThermalExpansion>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::ThermalExpansion::PerKelvin },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::ThermalExpansion::PerKelvin },
    {UnitSystem::FootPoundSecondRankine,     Unit::ThermalExpansion::PerRankine},
    {UnitSystem::InchPoundSecondRankine,     Unit::ThermalExpansion::PerRankine},
};

template <>
inline const std::map<Unit::ThermalExpansion, UnitSystem>
    RelatedUnitSystems<Unit::ThermalExpansion>{};

template <>
inline const std::map<Unit::ThermalExpansion, std::string_view>
    Abbreviations<Unit::ThermalExpansion>{
        {Unit::ThermalExpansion::PerKelvin,     "/K" },
        {Unit::ThermalExpansion::PerCelsius,    "/°C"},
        {Unit::ThermalExpansion::PerRankine,    "/°R"},
        {Unit::ThermalExpansion::PerFahrenheit, "/°F"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::ThermalExpansion>
    Spellings<Unit::ThermalExpansion>{
        {"1/K",    Unit::ThermalExpansion::PerKelvin    },
        {"1/°K",   Unit::ThermalExpansion::PerKelvin    },
        {"1/degK", Unit::ThermalExpansion::PerKelvin    },
        {"/K",     Unit::ThermalExpansion::PerKelvin    },
        {"/°K",    Unit::ThermalExpansion::PerKelvin    },
        {"/degK",  Unit::ThermalExpansion::PerKelvin    },
        {"1/°C",   Unit::ThermalExpansion::PerCelsius   },
        {"1/C",    Unit::ThermalExpansion::PerCelsius   },
        {"1/degC", Unit::ThermalExpansion::PerCelsius   },
        {"/°C",    Unit::ThermalExpansion::PerCelsius   },
        {"/C",     Unit::ThermalExpansion::PerCelsius   },
        {"/degC",  Unit::ThermalExpansion::PerCelsius   },
        {"1/°R",   Unit::ThermalExpansion::PerRankine   },
        {"1/R",    Unit::ThermalExpansion::PerRankine   },
        {"1/degR", Unit::ThermalExpansion::PerRankine   },
        {"/°R",    Unit::ThermalExpansion::PerRankine   },
        {"/R",     Unit::ThermalExpansion::PerRankine   },
        {"/degR",  Unit::ThermalExpansion::PerRankine   },
        {"1/°F",   Unit::ThermalExpansion::PerFahrenheit},
        {"1/F",    Unit::ThermalExpansion::PerFahrenheit},
        {"1/degF", Unit::ThermalExpansion::PerFahrenheit},
        {"/°F",    Unit::ThermalExpansion::PerFahrenheit},
        {"/F",     Unit::ThermalExpansion::PerFahrenheit},
        {"/degF",  Unit::ThermalExpansion::PerFahrenheit},
};

template <>
inline constexpr void
ConversionFromStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerKelvin>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerCelsius>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerRankine>(
    double& value) noexcept {
  value /= 1.8;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerFahrenheit>(
    double& value) noexcept {
  value /= 1.8;
}

template <>
inline constexpr void
ConversionToStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerKelvin>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerCelsius>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerRankine>(
    double& value) noexcept {
  value *= 1.8;
}

template <>
inline constexpr void
ConversionToStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerFahrenheit>(
    double& value) noexcept {
  value *= 1.8;
}

template <>
inline const std::map<Unit::ThermalExpansion,
                      std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::ThermalExpansion>{
        {Unit::ThermalExpansion::PerKelvin,
         ConversionsFromStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerKelvin>    },
        {Unit::ThermalExpansion::PerCelsius,
         ConversionsFromStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerCelsius>   },
        {Unit::ThermalExpansion::PerRankine,
         ConversionsFromStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerRankine>   },
        {Unit::ThermalExpansion::PerFahrenheit,
         ConversionsFromStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerFahrenheit>},
};

template <>
inline const std::map<Unit::ThermalExpansion,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::ThermalExpansion>{
        {Unit::ThermalExpansion::PerKelvin,
         ConversionsToStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerKelvin>    },
        {Unit::ThermalExpansion::PerCelsius,
         ConversionsToStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerCelsius>   },
        {Unit::ThermalExpansion::PerRankine,
         ConversionsToStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerRankine>   },
        {Unit::ThermalExpansion::PerFahrenheit,
         ConversionsToStandard<Unit::ThermalExpansion, Unit::ThermalExpansion::PerFahrenheit>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_EXPANSION_HPP
