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

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Time : int_least8_t {
  Nanosecond,
  Microsecond,
  Millisecond,
  Second,
  Minute,
  Hour,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Time StandardUnit<Unit::Time>{Unit::Time::Second};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Time>{
    Dimension::Set{Dimension::Time{1}}};

template <>
inline const std::map<UnitSystem, Unit::Time> ConsistentUnits<Unit::Time>{
    {UnitSystem::MetreKilogramSecondKelvin, Unit::Time::Second},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Time::Second},
    {UnitSystem::FootPoundSecondRankine, Unit::Time::Second},
    {UnitSystem::InchPoundSecondRankine, Unit::Time::Second},
};

template <>
inline const std::map<Unit::Time, UnitSystem> RelatedUnitSystems<Unit::Time>{};

template <>
inline const std::map<Unit::Time, std::string_view> Abbreviations<Unit::Time>{
    {Unit::Time::Nanosecond, "ns"},  {Unit::Time::Microsecond, "μs"},
    {Unit::Time::Millisecond, "ms"}, {Unit::Time::Second, "s"},
    {Unit::Time::Minute, "min"},     {Unit::Time::Hour, "hr"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Time>
    Spellings<Unit::Time>{
        {"ns", Unit::Time::Nanosecond},
        {"nanosecond", Unit::Time::Nanosecond},
        {"nanoseconds", Unit::Time::Nanosecond},
        {"μs", Unit::Time::Microsecond},
        {"us", Unit::Time::Microsecond},
        {"microsecond", Unit::Time::Microsecond},
        {"microseconds", Unit::Time::Microsecond},
        {"ms", Unit::Time::Millisecond},
        {"millisecond", Unit::Time::Millisecond},
        {"milliseconds", Unit::Time::Millisecond},
        {"s", Unit::Time::Second},
        {"sec", Unit::Time::Second},
        {"secs", Unit::Time::Second},
        {"second", Unit::Time::Second},
        {"seconds", Unit::Time::Second},
        {"min", Unit::Time::Minute},
        {"mins", Unit::Time::Minute},
        {"minute", Unit::Time::Minute},
        {"minutes", Unit::Time::Minute},
        {"hr", Unit::Time::Hour},
        {"hrs", Unit::Time::Hour},
        {"hour", Unit::Time::Hour},
        {"hours", Unit::Time::Hour},
    };

template <>
inline const std::map<Unit::Time, std::function<void(double* const values,
                                                     const std::size_t size)>>
    ConversionsFromStandard<Unit::Time>{
        {Unit::Time::Nanosecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000000.0;
           }
         }},
        {Unit::Time::Microsecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::Time::Millisecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Time::Second,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Time::Minute,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 60.0;
           }
         }},
        {Unit::Time::Hour,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 3600.0;
           }
         }},
    };

template <>
inline const std::map<Unit::Time, std::function<void(double* const values,
                                                     const std::size_t size)>>
    ConversionsToStandard<Unit::Time>{
        {Unit::Time::Nanosecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000000001;
           }
         }},
        {Unit::Time::Microsecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::Time::Millisecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Time::Second,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Time::Minute,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 60.0;
           }
         }},
        {Unit::Time::Hour,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 3600.0;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TIME_HPP
