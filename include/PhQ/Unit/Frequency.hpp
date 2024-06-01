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

/// \brief Frequency units.
enum class Frequency : int8_t {
  /// \brief Hertz (Hz) frequency unit.
  Hertz,

  /// \brief Kilohertz (kHz) frequency unit.
  Kilohertz,

  /// \brief Megahertz (MHz) frequency unit.
  Megahertz,

  /// \brief Gigahertz (GHz) frequency unit.
  Gigahertz,

  /// \brief Per minute (/min) frequency unit.
  PerMinute,

  /// \brief Per hour (/hr) frequency unit.
  PerHour,
};

}  // namespace Unit

/// \brief Standard frequency unit: hertz (Hz).
template <>
inline constexpr const Unit::Frequency Standard<Unit::Frequency>{Unit::Frequency::Hertz};

/// \brief Physical dimension set of frequency units.
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
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Hertz>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Hertz>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Kilohertz>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Kilohertz>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Megahertz>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Megahertz>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Gigahertz>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::Gigahertz>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::PerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::PerMinute>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::PerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Frequency, Unit::Frequency::PerHour>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600.0L);
}

template <typename NumericType>
inline const std::map<Unit::Frequency,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Frequency, NumericType>{
        {Unit::Frequency::Hertz,
         Conversions<Unit::Frequency, Unit::Frequency::Hertz>::FromStandard<NumericType>    },
        {Unit::Frequency::Kilohertz,
         Conversions<Unit::Frequency, Unit::Frequency::Kilohertz>::FromStandard<NumericType>},
        {Unit::Frequency::Megahertz,
         Conversions<Unit::Frequency, Unit::Frequency::Megahertz>::FromStandard<NumericType>},
        {Unit::Frequency::Gigahertz,
         Conversions<Unit::Frequency, Unit::Frequency::Gigahertz>::FromStandard<NumericType>},
        {Unit::Frequency::PerMinute,
         Conversions<Unit::Frequency, Unit::Frequency::PerMinute>::FromStandard<NumericType>},
        {Unit::Frequency::PerHour,
         Conversions<Unit::Frequency, Unit::Frequency::PerHour>::FromStandard<NumericType>  },
};

template <typename NumericType>
inline const std::map<Unit::Frequency,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Frequency, NumericType>{
        {Unit::Frequency::Hertz,
         Conversions<Unit::Frequency, Unit::Frequency::Hertz>::ToStandard<NumericType>    },
        {Unit::Frequency::Kilohertz,
         Conversions<Unit::Frequency, Unit::Frequency::Kilohertz>::ToStandard<NumericType>},
        {Unit::Frequency::Megahertz,
         Conversions<Unit::Frequency, Unit::Frequency::Megahertz>::ToStandard<NumericType>},
        {Unit::Frequency::Gigahertz,
         Conversions<Unit::Frequency, Unit::Frequency::Gigahertz>::ToStandard<NumericType>},
        {Unit::Frequency::PerMinute,
         Conversions<Unit::Frequency, Unit::Frequency::PerMinute>::ToStandard<NumericType>},
        {Unit::Frequency::PerHour,
         Conversions<Unit::Frequency, Unit::Frequency::PerHour>::ToStandard<NumericType>  },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_FREQUENCY_HPP
