// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TIME_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TIME_HPP

#include "../Unit.hpp"

namespace PhQ {

namespace Unit {

// Time units.
enum class Time : int_least8_t {
  Nanosecond,
  Microsecond,
  Millisecond,
  Second,
  Minute,
  Hour,
};

}  // namespace Unit

// Standard time unit: second.
template<>
inline constexpr const Unit::Time Standard<Unit::Time>{Unit::Time::Second};

// Physical dimension set of time units.
template<> inline constexpr const Dimensions RelatedDimensions<Unit::Time>{
    Dimensions{Dimension::Time{1}}};

namespace Internal {

template<>
inline const std::map<UnitSystem, Unit::Time> ConsistentUnits<Unit::Time>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Time::Second},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Time::Second},
    {UnitSystem::FootPoundSecondRankine,     Unit::Time::Second},
    {UnitSystem::InchPoundSecondRankine,     Unit::Time::Second},
};

template<>
inline const std::map<Unit::Time, UnitSystem> RelatedUnitSystems<Unit::Time>{};

template<>
inline const std::map<Unit::Time, std::string_view> Abbreviations<Unit::Time>{
    {Unit::Time::Nanosecond,  "ns" },
    {Unit::Time::Microsecond, "μs" },
    {Unit::Time::Millisecond, "ms" },
    {Unit::Time::Second,      "s"  },
    {Unit::Time::Minute,      "min"},
    {Unit::Time::Hour,        "hr" },
};

template<> inline const std::unordered_map<std::string_view, Unit::Time>
    Spellings<Unit::Time>{
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

template<> inline constexpr void
ConversionFromStandard<Unit::Time, Unit::Time::Nanosecond>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Time, Unit::Time::Microsecond>(
    double& value) noexcept {
  value *= 1000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Time, Unit::Time::Millisecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Time, Unit::Time::Second>(double& value) noexcept {
}

template<> inline constexpr void
ConversionFromStandard<Unit::Time, Unit::Time::Minute>(double& value) noexcept {
  value /= 60.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Time, Unit::Time::Hour>(double& value) noexcept {
  value /= 3600.0;
}

template<>
inline constexpr void ConversionToStandard<Unit::Time, Unit::Time::Nanosecond>(
    double& value) noexcept {
  value *= 0.000000001;
}

template<>
inline constexpr void ConversionToStandard<Unit::Time, Unit::Time::Microsecond>(
    double& value) noexcept {
  value *= 0.000001;
}

template<>
inline constexpr void ConversionToStandard<Unit::Time, Unit::Time::Millisecond>(
    double& value) noexcept {
  value *= 0.001;
}

template<> inline constexpr void
ConversionToStandard<Unit::Time, Unit::Time::Second>(double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::Time, Unit::Time::Minute>(double& value) noexcept {
  value *= 60.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Time, Unit::Time::Hour>(double& value) noexcept {
  value *= 3600.0;
}

template<> inline const std::map<
    Unit::Time, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Time>{
        {Unit::Time::Nanosecond,
         ConversionsFromStandard<Unit::Time, Unit::Time::Nanosecond> },
        {Unit::Time::Microsecond,
         ConversionsFromStandard<Unit::Time, Unit::Time::Microsecond>},
        {Unit::Time::Millisecond,
         ConversionsFromStandard<Unit::Time, Unit::Time::Millisecond>},
        {Unit::Time::Second,
         ConversionsFromStandard<Unit::Time, Unit::Time::Second>     },
        {Unit::Time::Minute,
         ConversionsFromStandard<Unit::Time, Unit::Time::Minute>     },
        {Unit::Time::Hour,
         ConversionsFromStandard<Unit::Time, Unit::Time::Hour>       },
};

template<>
inline const std::map<Unit::Time, std::function<void(double* const values,
                                                     const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Time>{
        {Unit::Time::Nanosecond,
         ConversionsToStandard<Unit::Time,                          Unit::Time::Nanosecond> },
        {Unit::Time::Microsecond,
         ConversionsToStandard<Unit::Time,                          Unit::Time::Microsecond>},
        {Unit::Time::Millisecond,
         ConversionsToStandard<Unit::Time,                          Unit::Time::Millisecond>},
        {Unit::Time::Second,
         ConversionsToStandard<Unit::Time,                          Unit::Time::Second>     },
        {Unit::Time::Minute,
         ConversionsToStandard<Unit::Time,                          Unit::Time::Minute>     },
        {Unit::Time::Hour,        ConversionsToStandard<Unit::Time, Unit::Time::Hour>       },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TIME_HPP
