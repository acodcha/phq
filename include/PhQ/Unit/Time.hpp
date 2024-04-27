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
inline constexpr void ConversionFromStandard<Unit::Time, Unit::Time::Nanosecond>(
    double& value) noexcept {
  value *= 1.0e9;
}

template <>
inline constexpr void ConversionToStandard<Unit::Time, Unit::Time::Nanosecond>(
    double& value) noexcept {
  value *= 1.0e-9;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Time, Unit::Time::Microsecond>(
    double& value) noexcept {
  value *= 1.0e6;
}

template <>
inline constexpr void ConversionToStandard<Unit::Time, Unit::Time::Microsecond>(
    double& value) noexcept {
  value *= 1.0e-6;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Time, Unit::Time::Millisecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Time, Unit::Time::Millisecond>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Time, Unit::Time::Second>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionToStandard<Unit::Time, Unit::Time::Second>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionFromStandard<Unit::Time, Unit::Time::Minute>(
    double& value) noexcept {
  value *= 1.0 / 60.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Time, Unit::Time::Minute>(double& value) noexcept {
  value *= 60.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Time, Unit::Time::Hour>(double& value) noexcept {
  value *= 1.0 / 3600.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Time, Unit::Time::Hour>(double& value) noexcept {
  value *= 3600.0;
}

template <>
inline const std::map<Unit::Time, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Time>{
        {Unit::Time::Nanosecond,  ConversionsFromStandard<Unit::Time, Unit::Time::Nanosecond> },
        {Unit::Time::Microsecond, ConversionsFromStandard<Unit::Time, Unit::Time::Microsecond>},
        {Unit::Time::Millisecond, ConversionsFromStandard<Unit::Time, Unit::Time::Millisecond>},
        {Unit::Time::Second,      ConversionsFromStandard<Unit::Time, Unit::Time::Second>     },
        {Unit::Time::Minute,      ConversionsFromStandard<Unit::Time, Unit::Time::Minute>     },
        {Unit::Time::Hour,        ConversionsFromStandard<Unit::Time, Unit::Time::Hour>       },
};

template <>
inline const std::map<Unit::Time, std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Time>{
        {Unit::Time::Nanosecond,  ConversionsToStandard<Unit::Time, Unit::Time::Nanosecond> },
        {Unit::Time::Microsecond, ConversionsToStandard<Unit::Time, Unit::Time::Microsecond>},
        {Unit::Time::Millisecond, ConversionsToStandard<Unit::Time, Unit::Time::Millisecond>},
        {Unit::Time::Second,      ConversionsToStandard<Unit::Time, Unit::Time::Second>     },
        {Unit::Time::Minute,      ConversionsToStandard<Unit::Time, Unit::Time::Minute>     },
        {Unit::Time::Hour,        ConversionsToStandard<Unit::Time, Unit::Time::Hour>       },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_TIME_HPP
