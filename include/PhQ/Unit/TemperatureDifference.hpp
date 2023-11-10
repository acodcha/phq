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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_DIFFERENCE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_DIFFERENCE_HPP

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

// Temperature difference units. Not to be confused with temperature units. For example, a
// temperature difference of +20 °C corresponds to a temperature difference of +36 °F, whereas a
// temperature of 20 °C corresponds to a temperature of 68 °F.
enum class TemperatureDifference : int8_t {
  // Kelvin (K) temperature difference unit.
  Kelvin,

  // Degree Celsius (°C) temperature difference unit.
  Celsius,

  // Degree Rankine (°R) temperature difference unit.
  Rankine,

  // Degree Fahrenheit (°F) temperature difference unit.
  Fahrenheit,
};

}  // namespace Unit

// Standard temperature difference unit: kelvin (K).
template <>
inline constexpr const Unit::TemperatureDifference Standard<Unit::TemperatureDifference>{
    Unit::TemperatureDifference::Kelvin};

// Physical dimension set of temperature difference units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::TemperatureDifference>{
    Dimensions{Dimension::Time{}, Dimension::Length{}, Dimension::Mass{},
               Dimension::ElectricCurrent{}, Dimension::Temperature{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::TemperatureDifference unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::TemperatureDifference>
    ConsistentUnits<Unit::TemperatureDifference>{
        {UnitSystem::MetreKilogramSecondKelvin,  Unit::TemperatureDifference::Kelvin },
        {UnitSystem::MillimetreGramSecondKelvin, Unit::TemperatureDifference::Kelvin },
        {UnitSystem::FootPoundSecondRankine,     Unit::TemperatureDifference::Rankine},
        {UnitSystem::InchPoundSecondRankine,     Unit::TemperatureDifference::Rankine},
};

template <>
inline const std::map<Unit::TemperatureDifference, UnitSystem>
    RelatedUnitSystems<Unit::TemperatureDifference>{};

template <>
inline const std::map<Unit::TemperatureDifference, std::string_view>
    Abbreviations<Unit::TemperatureDifference>{
        {Unit::TemperatureDifference::Kelvin,     "K" },
        {Unit::TemperatureDifference::Celsius,    "°C"},
        {Unit::TemperatureDifference::Rankine,    "°R"},
        {Unit::TemperatureDifference::Fahrenheit, "°F"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::TemperatureDifference>
    Spellings<Unit::TemperatureDifference>{
        {"K",    Unit::TemperatureDifference::Kelvin    },
        {"°K",   Unit::TemperatureDifference::Kelvin    },
        {"degK", Unit::TemperatureDifference::Kelvin    },
        {"°C",   Unit::TemperatureDifference::Celsius   },
        {"C",    Unit::TemperatureDifference::Celsius   },
        {"degC", Unit::TemperatureDifference::Celsius   },
        {"°R",   Unit::TemperatureDifference::Rankine   },
        {"R",    Unit::TemperatureDifference::Rankine   },
        {"degR", Unit::TemperatureDifference::Rankine   },
        {"°F",   Unit::TemperatureDifference::Fahrenheit},
        {"F",    Unit::TemperatureDifference::Fahrenheit},
        {"degF", Unit::TemperatureDifference::Fahrenheit},
};

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Kelvin>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Celsius>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Rankine>(
    double& value) noexcept {
  value *= 1.8;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Fahrenheit>(
    double& value) noexcept {
  value *= 1.8;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Kelvin>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Celsius>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Rankine>(
    double& value) noexcept {
  value /= 1.8;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Fahrenheit>(
    double& value) noexcept {
  value /= 1.8;
}

template <>
inline const std::map<Unit::TemperatureDifference,
                      std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::TemperatureDifference>{
        {Unit::TemperatureDifference::Kelvin,
         ConversionsFromStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Kelvin>},
        {Unit::TemperatureDifference::Celsius,
         ConversionsFromStandard<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Celsius>                                                    },
        {Unit::TemperatureDifference::Rankine,
         ConversionsFromStandard<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Rankine>                                                    },
        {Unit::TemperatureDifference::Fahrenheit,
         ConversionsFromStandard<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Fahrenheit>                                                 },
};

template <>
inline const std::map<Unit::TemperatureDifference,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::TemperatureDifference>{
        {Unit::TemperatureDifference::Kelvin,
         ConversionsToStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Kelvin> },
        {Unit::TemperatureDifference::Celsius,
         ConversionsToStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Celsius>},
        {Unit::TemperatureDifference::Rankine,
         ConversionsToStandard<Unit::TemperatureDifference, Unit::TemperatureDifference::Rankine>},
        {Unit::TemperatureDifference::Fahrenheit,
         ConversionsToStandard<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Fahrenheit>                                                },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_DIFFERENCE_HPP
