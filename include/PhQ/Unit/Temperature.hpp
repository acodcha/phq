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

#ifndef PHQ_UNIT_TEMPERATURE_HPP
#define PHQ_UNIT_TEMPERATURE_HPP

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
template <typename Number>
inline constexpr void Conversion<Unit::Temperature, Unit::Temperature::Kelvin>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Temperature, Unit::Temperature::Kelvin>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Temperature, Unit::Temperature::Celsius>::FromStandard(
    Number& value) noexcept {
  value -= static_cast<Number>(273.15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Temperature, Unit::Temperature::Celsius>::ToStandard(
    Number& value) noexcept {
  value += static_cast<Number>(273.15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Temperature, Unit::Temperature::Rankine>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.8L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Temperature, Unit::Temperature::Rankine>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.8L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Temperature, Unit::Temperature::Fahrenheit>::FromStandard(
    Number& value) noexcept {
  value = static_cast<Number>(1.8L) * value - static_cast<Number>(459.67L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Temperature, Unit::Temperature::Fahrenheit>::ToStandard(
    Number& value) noexcept {
  value = (value + static_cast<Number>(459.67L)) / static_cast<Number>(1.8L);
}

template <typename Number>
inline const std::map<Unit::Temperature,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Temperature, Number>{
        {Unit::Temperature::Kelvin,
         Conversions<Unit::Temperature, Unit::Temperature::Kelvin>::FromStandard<Number>    },
        {Unit::Temperature::Celsius,
         Conversions<Unit::Temperature, Unit::Temperature::Celsius>::FromStandard<Number>   },
        {Unit::Temperature::Rankine,
         Conversions<Unit::Temperature, Unit::Temperature::Rankine>::FromStandard<Number>   },
        {Unit::Temperature::Fahrenheit,
         Conversions<Unit::Temperature, Unit::Temperature::Fahrenheit>::FromStandard<Number>},
};

template <typename Number>
inline const std::map<Unit::Temperature,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Temperature, Number>{
        {Unit::Temperature::Kelvin,
         Conversions<Unit::Temperature, Unit::Temperature::Kelvin>::ToStandard<Number>    },
        {Unit::Temperature::Celsius,
         Conversions<Unit::Temperature, Unit::Temperature::Celsius>::ToStandard<Number>   },
        {Unit::Temperature::Rankine,
         Conversions<Unit::Temperature, Unit::Temperature::Rankine>::ToStandard<Number>   },
        {Unit::Temperature::Fahrenheit,
         Conversions<Unit::Temperature, Unit::Temperature::Fahrenheit>::ToStandard<Number>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_TEMPERATURE_HPP
