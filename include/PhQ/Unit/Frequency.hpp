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

#ifndef PHQ_UNIT_FREQUENCY_HPP
#define PHQ_UNIT_FREQUENCY_HPP

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

// Frequency units.
enum class Frequency : int8_t {
  // Hertz (Hz) frequency unit.
  Hertz,

  // Kilohertz (kHz) frequency unit.
  Kilohertz,

  // Megahertz (MHz) frequency unit.
  Megahertz,

  // Gigahertz (GHz) frequency unit.
  Gigahertz,

  // Per minute (/min) frequency unit.
  PerMinute,

  // Per hour (/hr) frequency unit.
  PerHour,
};

}  // namespace Unit

// Standard frequency unit: hertz (Hz).
template <>
inline constexpr const Unit::Frequency Standard<Unit::Frequency>{Unit::Frequency::Hertz};

// Physical dimension set of frequency units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Frequency>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{0}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Frequency unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Frequency> ConsistentUnits<Unit::Frequency>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Frequency::Hertz},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Frequency::Hertz},
    {UnitSystem::FootPoundSecondRankine,     Unit::Frequency::Hertz},
    {UnitSystem::InchPoundSecondRankine,     Unit::Frequency::Hertz},
};

template <>
inline const std::map<Unit::Frequency, UnitSystem> RelatedUnitSystems<Unit::Frequency>{};

template <>
inline const std::map<Unit::Frequency, std::string_view> Abbreviations<Unit::Frequency>{
    {Unit::Frequency::Hertz,     "Hz"  },
    {Unit::Frequency::Kilohertz, "kHz" },
    {Unit::Frequency::Megahertz, "MHz" },
    {Unit::Frequency::Gigahertz, "GHz" },
    {Unit::Frequency::PerMinute, "/min"},
    {Unit::Frequency::PerHour,   "/hr" },
};

template <>
inline const std::unordered_map<std::string_view, Unit::Frequency> Spellings<Unit::Frequency>{
    {"Hz",    Unit::Frequency::Hertz    },
    {"/s",    Unit::Frequency::Hertz    },
    {"1/s",   Unit::Frequency::Hertz    },
    {"kHz",   Unit::Frequency::Kilohertz},
    {"MHz",   Unit::Frequency::Megahertz},
    {"GHz",   Unit::Frequency::Gigahertz},
    {"/min",  Unit::Frequency::PerMinute},
    {"1/min", Unit::Frequency::PerMinute},
    {"/hr",   Unit::Frequency::PerHour  },
    {"1/hr",  Unit::Frequency::PerHour  },
};

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Hertz>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Hertz>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Kilohertz>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Kilohertz>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Megahertz>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Megahertz>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Gigahertz>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Gigahertz>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::PerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::PerMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::PerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::PerHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <typename Number>
inline const std::map<Unit::Frequency, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Frequency, Number>{
        {Unit::Frequency::Hertz,
         Conversions<Unit::Frequency, Unit::Frequency::Hertz>::FromStandard<Number>    },
        {Unit::Frequency::Kilohertz,
         Conversions<Unit::Frequency, Unit::Frequency::Kilohertz>::FromStandard<Number>},
        {Unit::Frequency::Megahertz,
         Conversions<Unit::Frequency, Unit::Frequency::Megahertz>::FromStandard<Number>},
        {Unit::Frequency::Gigahertz,
         Conversions<Unit::Frequency, Unit::Frequency::Gigahertz>::FromStandard<Number>},
        {Unit::Frequency::PerMinute,
         Conversions<Unit::Frequency, Unit::Frequency::PerMinute>::FromStandard<Number>},
        {Unit::Frequency::PerHour,
         Conversions<Unit::Frequency, Unit::Frequency::PerHour>::FromStandard<Number>  },
};

template <typename Number>
inline const std::map<Unit::Frequency,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Frequency, Number>{
        {Unit::Frequency::Hertz,
         Conversions<Unit::Frequency, Unit::Frequency::Hertz>::ToStandard<Number>    },
        {Unit::Frequency::Kilohertz,
         Conversions<Unit::Frequency, Unit::Frequency::Kilohertz>::ToStandard<Number>},
        {Unit::Frequency::Megahertz,
         Conversions<Unit::Frequency, Unit::Frequency::Megahertz>::ToStandard<Number>},
        {Unit::Frequency::Gigahertz,
         Conversions<Unit::Frequency, Unit::Frequency::Gigahertz>::ToStandard<Number>},
        {Unit::Frequency::PerMinute,
         Conversions<Unit::Frequency, Unit::Frequency::PerMinute>::ToStandard<Number>},
        {Unit::Frequency::PerHour,
         Conversions<Unit::Frequency, Unit::Frequency::PerHour>::ToStandard<Number>  },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_FREQUENCY_HPP
