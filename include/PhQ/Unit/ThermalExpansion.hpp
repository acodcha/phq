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

#ifndef PHQ_UNIT_THERMAL_EXPANSION_HPP
#define PHQ_UNIT_THERMAL_EXPANSION_HPP

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

/// \brief Thermal expansion units.
enum class ThermalExpansion : int8_t {
  /// \brief Per kelvin (/K) thermal expansion unit.
  PerKelvin,

  /// \brief Per degree Celsius (/°C) thermal expansion unit.
  PerCelsius,

  /// \brief Per degree Rankine (/°R) thermal expansion unit.
  PerRankine,

  /// \brief Per degree Fahrenheit (/°F) thermal expansion unit.
  PerFahrenheit
};

}  // namespace Unit

/// \brief Standard thermal expansion unit: per kelvin (/K).
template <>
inline constexpr const Unit::ThermalExpansion Standard<Unit::ThermalExpansion>{
    Unit::ThermalExpansion::PerKelvin};

/// \brief Physical dimension set of thermal expansion units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::ThermalExpansion>{
    Dimensions{Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{-1},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
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
template <typename Number>
inline constexpr void
Conversion<Unit::ThermalExpansion, Unit::ThermalExpansion::PerKelvin>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ThermalExpansion, Unit::ThermalExpansion::PerKelvin>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ThermalExpansion, Unit::ThermalExpansion::PerCelsius>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ThermalExpansion, Unit::ThermalExpansion::PerCelsius>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ThermalExpansion, Unit::ThermalExpansion::PerRankine>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.8L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ThermalExpansion, Unit::ThermalExpansion::PerRankine>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.8L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ThermalExpansion, Unit::ThermalExpansion::PerFahrenheit>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.8L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ThermalExpansion, Unit::ThermalExpansion::PerFahrenheit>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.8L);
}

template <typename Number>
inline const std::map<Unit::ThermalExpansion,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::ThermalExpansion, Number>{
        {Unit::ThermalExpansion::PerKelvin,
         Conversions<Unit::ThermalExpansion,
         Unit::ThermalExpansion::PerKelvin>::FromStandard<Number>    },
        {Unit::ThermalExpansion::PerCelsius,
         Conversions<Unit::ThermalExpansion,
         Unit::ThermalExpansion::PerCelsius>::FromStandard<Number>   },
        {Unit::ThermalExpansion::PerRankine,
         Conversions<Unit::ThermalExpansion,
         Unit::ThermalExpansion::PerRankine>::FromStandard<Number>   },
        {Unit::ThermalExpansion::PerFahrenheit,
         Conversions<Unit::ThermalExpansion,
         Unit::ThermalExpansion::PerFahrenheit>::FromStandard<Number>},
};

template <typename Number>
inline const std::map<Unit::ThermalExpansion,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::ThermalExpansion, Number>{
        {Unit::ThermalExpansion::PerKelvin,
         Conversions<Unit::ThermalExpansion,
         Unit::ThermalExpansion::PerKelvin>::ToStandard<Number>    },
        {Unit::ThermalExpansion::PerCelsius,
         Conversions<Unit::ThermalExpansion,
         Unit::ThermalExpansion::PerCelsius>::ToStandard<Number>   },
        {Unit::ThermalExpansion::PerRankine,
         Conversions<Unit::ThermalExpansion,
         Unit::ThermalExpansion::PerRankine>::ToStandard<Number>   },
        {Unit::ThermalExpansion::PerFahrenheit,
         Conversions<Unit::ThermalExpansion,
         Unit::ThermalExpansion::PerFahrenheit>::ToStandard<Number>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_THERMAL_EXPANSION_HPP
