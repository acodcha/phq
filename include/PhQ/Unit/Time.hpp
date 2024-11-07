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

#ifndef PHQ_UNIT_TIME_HPP
#define PHQ_UNIT_TIME_HPP

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

/// \brief Time units.
enum class Time : int8_t {
  /// \brief Second (s) time unit.
  Second,

  /// \brief Nanosecond (ns) time unit.
  Nanosecond,

  /// \brief Microsecond (μs) time unit.
  Microsecond,

  /// \brief Millisecond (ms) time unit.
  Millisecond,

  /// \brief Minute (min) time unit.
  Minute,

  /// \brief Hour (hr) time unit.
  Hour,
};

}  // namespace Unit

/// \brief Standard time unit: second (s).
template <>
inline constexpr const Unit::Time Standard<Unit::Time>{Unit::Time::Second};

/// \brief Physical dimension set of time units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Time>{
  Dimensions{Dimension::Time{1}, Dimension::Length{0}, Dimension::Mass{0},
             Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
             Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Time unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Time> ConsistentUnits<Unit::Time>{
  {UnitSystem::MetreKilogramSecondKelvin,  Unit::Time::Second},
  {UnitSystem::MillimetreGramSecondKelvin, Unit::Time::Second},
  {UnitSystem::FootPoundSecondRankine,     Unit::Time::Second},
  {UnitSystem::InchPoundSecondRankine,     Unit::Time::Second},
};

template <>
inline const std::map<Unit::Time, UnitSystem> RelatedUnitSystems<Unit::Time>{};

// clang-format off

template <>
inline const std::map<Unit::Time, std::string_view> Abbreviations<Unit::Time>{
    {Unit::Time::Second,      "s"  },
    {Unit::Time::Nanosecond,  "ns" },
    {Unit::Time::Microsecond, "μs" },
    {Unit::Time::Millisecond, "ms" },
    {Unit::Time::Minute,      "min"},
    {Unit::Time::Hour,        "hr" },
};

template <>
inline const std::unordered_map<std::string_view, Unit::Time> Spellings<Unit::Time>{
    {"s",            Unit::Time::Second     },
    {"second",       Unit::Time::Second     },
    {"seconds",      Unit::Time::Second     },
    {"ns",           Unit::Time::Nanosecond },
    {"nanosecond",   Unit::Time::Nanosecond },
    {"nanoseconds",  Unit::Time::Nanosecond },
    {"μs",           Unit::Time::Microsecond},
    {"us",           Unit::Time::Microsecond},
    {"microsecond",  Unit::Time::Microsecond},
    {"microseconds", Unit::Time::Microsecond},
    {"ms",           Unit::Time::Millisecond},
    {"millisecond",  Unit::Time::Millisecond},
    {"milliseconds", Unit::Time::Millisecond},
    {"min",          Unit::Time::Minute     },
    {"mins",         Unit::Time::Minute     },
    {"minute",       Unit::Time::Minute     },
    {"minutes",      Unit::Time::Minute     },
    {"hr",           Unit::Time::Hour       },
    {"hrs",          Unit::Time::Hour       },
    {"hour",         Unit::Time::Hour       },
    {"hours",        Unit::Time::Hour       },
};

// clang-format on

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Second>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Second>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Nanosecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Nanosecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Microsecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Microsecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Millisecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Millisecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Minute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Minute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Hour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Time, Unit::Time::Hour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L);
}

template <typename NumericType>
inline const std::map<Unit::Time, std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Time, NumericType>{
      {Unit::Time::Second,      Conversions<Unit::Time, Unit::Time::Second>::FromStandard<NumericType>     },
      {Unit::Time::Nanosecond,
       Conversions<Unit::Time,                          Unit::Time::Nanosecond>::FromStandard<NumericType> },
      {Unit::Time::Microsecond,
       Conversions<Unit::Time,                          Unit::Time::Microsecond>::FromStandard<NumericType>},
      {Unit::Time::Millisecond,
       Conversions<Unit::Time,                          Unit::Time::Millisecond>::FromStandard<NumericType>},
      {Unit::Time::Minute,      Conversions<Unit::Time, Unit::Time::Minute>::FromStandard<NumericType>     },
      {Unit::Time::Hour,        Conversions<Unit::Time, Unit::Time::Hour>::FromStandard<NumericType>       },
};

template <typename NumericType>
inline const std::
    map<Unit::Time, std::function<void(NumericType* const values, const std::size_t size)>>
        MapOfConversionsToStandard<Unit::Time, NumericType>{
          {Unit::Time::Second,
           Conversions<Unit::Time,                          Unit::Time::Second>::ToStandard<NumericType>     },
          {Unit::Time::Nanosecond,
           Conversions<Unit::Time,                          Unit::Time::Nanosecond>::ToStandard<NumericType> },
          {Unit::Time::Microsecond,
           Conversions<Unit::Time,                          Unit::Time::Microsecond>::ToStandard<NumericType>},
          {Unit::Time::Millisecond,
           Conversions<Unit::Time,                          Unit::Time::Millisecond>::ToStandard<NumericType>},
          {Unit::Time::Minute,
           Conversions<Unit::Time,                          Unit::Time::Minute>::ToStandard<NumericType>     },
          {Unit::Time::Hour,        Conversions<Unit::Time, Unit::Time::Hour>::ToStandard<NumericType>       },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_TIME_HPP
