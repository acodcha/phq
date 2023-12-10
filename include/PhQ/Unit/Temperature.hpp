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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_HPP

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

// Temperature units. Not to be confused with temperature difference units. For example, a
// temperature of 20 °C corresponds to a temperature of 68 °F, whereas a temperature difference of
// +20 °C corresponds to a temperature difference of +36 °F.
enum class Temperature : int8_t {
  // Kelvin (K) temperature unit.
  Kelvin,

  // Degree Celsius (°C) temperature unit.
  Celsius,

  // Degree Rankine (°R) temperature unit.
  Rankine,

  // Degree Fahrenheit (°F) temperature unit.
  Fahrenheit,
};

}  // namespace Unit

// Standard temperature unit: kelvin (K).
template <>
inline constexpr const Unit::Temperature Standard<Unit::Temperature>{Unit::Temperature::Kelvin};

// Physical dimension set of temperature units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Temperature>{
    Dimensions{Dimension::Time{}, Dimension::Length{}, Dimension::Mass{},
               Dimension::ElectricCurrent{}, Dimension::Temperature{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Temperature unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Temperature> ConsistentUnits<Unit::Temperature>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Temperature::Kelvin },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Temperature::Kelvin },
    {UnitSystem::FootPoundSecondRankine,     Unit::Temperature::Rankine},
    {UnitSystem::InchPoundSecondRankine,     Unit::Temperature::Rankine},
};

template <>
inline const std::map<Unit::Temperature, UnitSystem> RelatedUnitSystems<Unit::Temperature>{};

template <>
inline const std::map<Unit::Temperature, std::string_view> Abbreviations<Unit::Temperature>{
    {Unit::Temperature::Kelvin,     "K" },
    {Unit::Temperature::Celsius,    "°C"},
    {Unit::Temperature::Rankine,    "°R"},
    {Unit::Temperature::Fahrenheit, "°F"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Temperature> Spellings<Unit::Temperature>{
    {"K",    Unit::Temperature::Kelvin    },
    {"°K",   Unit::Temperature::Kelvin    },
    {"degK", Unit::Temperature::Kelvin    },
    {"°C",   Unit::Temperature::Celsius   },
    {"C",    Unit::Temperature::Celsius   },
    {"degC", Unit::Temperature::Celsius   },
    {"°R",   Unit::Temperature::Rankine   },
    {"R",    Unit::Temperature::Rankine   },
    {"degR", Unit::Temperature::Rankine   },
    {"°F",   Unit::Temperature::Fahrenheit},
    {"F",    Unit::Temperature::Fahrenheit},
    {"degF", Unit::Temperature::Fahrenheit},
};

template <>
inline constexpr void ConversionFromStandard<Unit::Temperature, Unit::Temperature::Kelvin>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionFromStandard<Unit::Temperature, Unit::Temperature::Celsius>(
    double& value) noexcept {
  value -= 273.15;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Temperature, Unit::Temperature::Rankine>(
    double& value) noexcept {
  value *= 1.8;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Temperature, Unit::Temperature::Fahrenheit>(
    double& value) noexcept {
  value = (value * 1.8) - 459.67;
}

template <>
inline constexpr void ConversionToStandard<Unit::Temperature, Unit::Temperature::Kelvin>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionToStandard<Unit::Temperature, Unit::Temperature::Celsius>(
    double& value) noexcept {
  value += 273.15;
}

template <>
inline constexpr void ConversionToStandard<Unit::Temperature, Unit::Temperature::Rankine>(
    double& value) noexcept {
  value /= 1.8;
}

template <>
inline constexpr void ConversionToStandard<Unit::Temperature, Unit::Temperature::Fahrenheit>(
    double& value) noexcept {
  value = (value + 459.67) / 1.8;
}

template <>
inline const std::map<Unit::Temperature,
                      std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Temperature>{
        {Unit::Temperature::Kelvin,
         ConversionsFromStandard<Unit::Temperature, Unit::Temperature::Kelvin>    },
        {Unit::Temperature::Celsius,
         ConversionsFromStandard<Unit::Temperature, Unit::Temperature::Celsius>   },
        {Unit::Temperature::Rankine,
         ConversionsFromStandard<Unit::Temperature, Unit::Temperature::Rankine>   },
        {Unit::Temperature::Fahrenheit,
         ConversionsFromStandard<Unit::Temperature, Unit::Temperature::Fahrenheit>},
};

template <>
inline const std::map<Unit::Temperature,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Temperature>{
        {Unit::Temperature::Kelvin,
         ConversionsToStandard<Unit::Temperature, Unit::Temperature::Kelvin>    },
        {Unit::Temperature::Celsius,
         ConversionsToStandard<Unit::Temperature, Unit::Temperature::Celsius>   },
        {Unit::Temperature::Rankine,
         ConversionsToStandard<Unit::Temperature, Unit::Temperature::Rankine>   },
        {Unit::Temperature::Fahrenheit,
         ConversionsToStandard<Unit::Temperature, Unit::Temperature::Fahrenheit>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_HPP
