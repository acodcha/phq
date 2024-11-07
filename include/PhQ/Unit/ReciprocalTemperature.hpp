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

#ifndef PHQ_UNIT_RECIPROCAL_TEMPERATURE_HPP
#define PHQ_UNIT_RECIPROCAL_TEMPERATURE_HPP

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

/// \brief Reciprocal temperature units. Reciprocal temperature is the inverse of temperature.
enum class ReciprocalTemperature : int8_t {
  /// \brief Per kelvin (/K) reciprocal temperature unit.
  PerKelvin,

  /// \brief Per degree Celsius (/°C) reciprocal temperature unit.
  PerCelsius,

  /// \brief Per degree Rankine (/°R) reciprocal temperature unit.
  PerRankine,

  /// \brief Per degree Fahrenheit (/°F) reciprocal temperature unit.
  PerFahrenheit
};

}  // namespace Unit

/// \brief Standard reciprocal temperature unit: per kelvin (/K).
template <>
inline constexpr const Unit::ReciprocalTemperature Standard<Unit::ReciprocalTemperature>{
  Unit::ReciprocalTemperature::PerKelvin};

/// \brief Physical dimension set of reciprocal temperature units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::ReciprocalTemperature>{
  Dimensions{Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
             Dimension::ElectricCurrent{0}, Dimension::Temperature{-1},
             Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::ReciprocalTemperature unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::ReciprocalTemperature>
    ConsistentUnits<Unit::ReciprocalTemperature>{
      {UnitSystem::MetreKilogramSecondKelvin,  Unit::ReciprocalTemperature::PerKelvin },
      {UnitSystem::MillimetreGramSecondKelvin, Unit::ReciprocalTemperature::PerKelvin },
      {UnitSystem::FootPoundSecondRankine,     Unit::ReciprocalTemperature::PerRankine},
      {UnitSystem::InchPoundSecondRankine,     Unit::ReciprocalTemperature::PerRankine},
};

template <>
inline const std::map<Unit::ReciprocalTemperature, UnitSystem>
    RelatedUnitSystems<Unit::ReciprocalTemperature>{};

// clang-format off

template <>
inline const std::map<Unit::ReciprocalTemperature, std::string_view>
    Abbreviations<Unit::ReciprocalTemperature>{
        {Unit::ReciprocalTemperature::PerKelvin,     "/K" },
        {Unit::ReciprocalTemperature::PerCelsius,    "/°C"},
        {Unit::ReciprocalTemperature::PerRankine,    "/°R"},
        {Unit::ReciprocalTemperature::PerFahrenheit, "/°F"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::ReciprocalTemperature>
    Spellings<Unit::ReciprocalTemperature>{
        {"1/K",    Unit::ReciprocalTemperature::PerKelvin    },
        {"1/°K",   Unit::ReciprocalTemperature::PerKelvin    },
        {"1/degK", Unit::ReciprocalTemperature::PerKelvin    },
        {"/K",     Unit::ReciprocalTemperature::PerKelvin    },
        {"/°K",    Unit::ReciprocalTemperature::PerKelvin    },
        {"/degK",  Unit::ReciprocalTemperature::PerKelvin    },
        {"1/°C",   Unit::ReciprocalTemperature::PerCelsius   },
        {"1/C",    Unit::ReciprocalTemperature::PerCelsius   },
        {"1/degC", Unit::ReciprocalTemperature::PerCelsius   },
        {"/°C",    Unit::ReciprocalTemperature::PerCelsius   },
        {"/C",     Unit::ReciprocalTemperature::PerCelsius   },
        {"/degC",  Unit::ReciprocalTemperature::PerCelsius   },
        {"1/°R",   Unit::ReciprocalTemperature::PerRankine   },
        {"1/R",    Unit::ReciprocalTemperature::PerRankine   },
        {"1/degR", Unit::ReciprocalTemperature::PerRankine   },
        {"/°R",    Unit::ReciprocalTemperature::PerRankine   },
        {"/R",     Unit::ReciprocalTemperature::PerRankine   },
        {"/degR",  Unit::ReciprocalTemperature::PerRankine   },
        {"1/°F",   Unit::ReciprocalTemperature::PerFahrenheit},
        {"1/F",    Unit::ReciprocalTemperature::PerFahrenheit},
        {"1/degF", Unit::ReciprocalTemperature::PerFahrenheit},
        {"/°F",    Unit::ReciprocalTemperature::PerFahrenheit},
        {"/F",     Unit::ReciprocalTemperature::PerFahrenheit},
        {"/degF",  Unit::ReciprocalTemperature::PerFahrenheit},
};

// clang-format on

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerKelvin>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerKelvin>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerCelsius>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerCelsius>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerRankine>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.8L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerRankine>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.8L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerFahrenheit>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.8L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerFahrenheit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.8L);
}

template <typename NumericType>
inline const std::map<Unit::ReciprocalTemperature,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::ReciprocalTemperature, NumericType>{
      {Unit::ReciprocalTemperature::PerKelvin,
       Conversions<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerKelvin>::
           FromStandard<NumericType>},
      {Unit::ReciprocalTemperature::PerCelsius,
       Conversions<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerCelsius>::
           FromStandard<NumericType>},
      {Unit::ReciprocalTemperature::PerRankine,
       Conversions<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerRankine>::
           FromStandard<NumericType>},
      {Unit::ReciprocalTemperature::PerFahrenheit,
       Conversions<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerFahrenheit>::
           FromStandard<NumericType>},
};

template <typename NumericType>
inline const std::map<Unit::ReciprocalTemperature,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::ReciprocalTemperature, NumericType>{
      {Unit::ReciprocalTemperature::PerKelvin,
       Conversions<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerKelvin>::
           ToStandard<NumericType>},
      {Unit::ReciprocalTemperature::PerCelsius,
       Conversions<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerCelsius>::
           ToStandard<NumericType>},
      {Unit::ReciprocalTemperature::PerRankine,
       Conversions<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerRankine>::
           ToStandard<NumericType>},
      {Unit::ReciprocalTemperature::PerFahrenheit,
       Conversions<Unit::ReciprocalTemperature, Unit::ReciprocalTemperature::PerFahrenheit>::
           ToStandard<NumericType>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_RECIPROCAL_TEMPERATURE_HPP
