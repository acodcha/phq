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
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

// Time units.
enum class Time : int8_t {
  // Nanosecond (ns) time unit.
  Nanosecond,

  // Microsecond (μs) time unit.
  Microsecond,

  // Millisecond (ms) time unit.
  Millisecond,

  // Second (s) time unit.
  Second,

  // Minute (min) time unit.
  Minute,

  // Hour (hr) time unit.
  Hour,
};

}  // namespace Unit

// Standard time unit: second (s).
template <>
inline constexpr const Unit::Time Standard<Unit::Time>{Unit::Time::Second};

// Physical dimension set of time units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Time>{Dimensions{Dimension::Time{1}}};

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

template <>
inline const std::map<Unit::Time, std::string_view> Abbreviations<Unit::Time>{
    {Unit::Time::Nanosecond,  "ns" },
    {Unit::Time::Microsecond, "μs" },
    {Unit::Time::Millisecond, "ms" },
    {Unit::Time::Second,      "s"  },
    {Unit::Time::Minute,      "min"},
    {Unit::Time::Hour,        "hr" },
};

template <>
inline const std::unordered_map<std::string_view, Unit::Time> Spellings<Unit::Time>{
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
    {"s",            Unit::Time::Second     },
    {"second",       Unit::Time::Second     },
    {"seconds",      Unit::Time::Second     },
    {"min",          Unit::Time::Minute     },
    {"mins",         Unit::Time::Minute     },
    {"minute",       Unit::Time::Minute     },
    {"minutes",      Unit::Time::Minute     },
    {"hr",           Unit::Time::Hour       },
    {"hrs",          Unit::Time::Hour       },
    {"hour",         Unit::Time::Hour       },
    {"hours",        Unit::Time::Hour       },
};

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Nanosecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Nanosecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Microsecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Microsecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Millisecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Millisecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Second>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Second>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Minute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Minute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Hour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Time, Unit::Time::Hour>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <typename Number>
inline const std::map<Unit::Time, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Time, Number>{
        {Unit::Time::Nanosecond,
         Conversions<Unit::Time,                          Unit::Time::Nanosecond>::FromStandard<Number> },
        {Unit::Time::Microsecond,
         Conversions<Unit::Time,                          Unit::Time::Microsecond>::FromStandard<Number>},
        {Unit::Time::Millisecond,
         Conversions<Unit::Time,                          Unit::Time::Millisecond>::FromStandard<Number>},
        {Unit::Time::Second,      Conversions<Unit::Time, Unit::Time::Second>::FromStandard<Number>     },
        {Unit::Time::Minute,      Conversions<Unit::Time, Unit::Time::Minute>::FromStandard<Number>     },
        {Unit::Time::Hour,        Conversions<Unit::Time, Unit::Time::Hour>::FromStandard<Number>       },
};

template <typename Number>
inline const std::map<Unit::Time, std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Time, Number>{
        {Unit::Time::Nanosecond,
         Conversions<Unit::Time,                          Unit::Time::Nanosecond>::ToStandard<Number> },
        {Unit::Time::Microsecond,
         Conversions<Unit::Time,                          Unit::Time::Microsecond>::ToStandard<Number>},
        {Unit::Time::Millisecond,
         Conversions<Unit::Time,                          Unit::Time::Millisecond>::ToStandard<Number>},
        {Unit::Time::Second,      Conversions<Unit::Time, Unit::Time::Second>::ToStandard<Number>     },
        {Unit::Time::Minute,      Conversions<Unit::Time, Unit::Time::Minute>::ToStandard<Number>     },
        {Unit::Time::Hour,        Conversions<Unit::Time, Unit::Time::Hour>::ToStandard<Number>       },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_TIME_HPP
