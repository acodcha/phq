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

#ifndef PHQ_UNIT_TEMPERATURE_DIFFERENCE_HPP
#define PHQ_UNIT_TEMPERATURE_DIFFERENCE_HPP

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

/// \brief Temperature difference units. Not to be confused with temperature units. For example, a
/// temperature difference of +20 °C corresponds to a temperature difference of +36 °F, whereas a
/// temperature of 20 °C corresponds to a temperature of 68 °F.
enum class TemperatureDifference : int8_t {
  /// \brief Kelvin (K) temperature difference unit.
  Kelvin,

  /// \brief Degree Celsius (°C) temperature difference unit.
  Celsius,

  /// \brief Degree Rankine (°R) temperature difference unit.
  Rankine,

  /// \brief Degree Fahrenheit (°F) temperature difference unit.
  Fahrenheit,
};

}  // namespace Unit

/// \brief Standard temperature difference unit: kelvin (K).
template <>
inline constexpr const Unit::TemperatureDifference Standard<Unit::TemperatureDifference>{
    Unit::TemperatureDifference::Kelvin};

/// \brief Physical dimension set of temperature difference units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::TemperatureDifference>{
    Dimensions{Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{1},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
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
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureDifference, Unit::TemperatureDifference::Kelvin>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureDifference, Unit::TemperatureDifference::Kelvin>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureDifference, Unit::TemperatureDifference::Celsius>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureDifference, Unit::TemperatureDifference::Celsius>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureDifference, Unit::TemperatureDifference::Rankine>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.8L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureDifference, Unit::TemperatureDifference::Rankine>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.8L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureDifference, Unit::TemperatureDifference::Fahrenheit>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.8L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureDifference, Unit::TemperatureDifference::Fahrenheit>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.8L);
}

template <typename Number>
inline const std::map<Unit::TemperatureDifference,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::TemperatureDifference, Number>{
        {Unit::TemperatureDifference::Kelvin,
         Conversions<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Kelvin>::FromStandard<Number>    },
        {Unit::TemperatureDifference::Celsius,
         Conversions<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Celsius>::FromStandard<Number>   },
        {Unit::TemperatureDifference::Rankine,
         Conversions<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Rankine>::FromStandard<Number>   },
        {Unit::TemperatureDifference::Fahrenheit,
         Conversions<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Fahrenheit>::FromStandard<Number>},
};

template <typename Number>
inline const std::map<Unit::TemperatureDifference,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::TemperatureDifference, Number>{
        {Unit::TemperatureDifference::Kelvin,
         Conversions<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Kelvin>::ToStandard<Number>    },
        {Unit::TemperatureDifference::Celsius,
         Conversions<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Celsius>::ToStandard<Number>   },
        {Unit::TemperatureDifference::Rankine,
         Conversions<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Rankine>::ToStandard<Number>   },
        {Unit::TemperatureDifference::Fahrenheit,
         Conversions<Unit::TemperatureDifference,
         Unit::TemperatureDifference::Fahrenheit>::ToStandard<Number>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_TEMPERATURE_DIFFERENCE_HPP
