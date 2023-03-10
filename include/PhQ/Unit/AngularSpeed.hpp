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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ANGULAR_SPEED_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ANGULAR_SPEED_HPP

#include "../Base/Constant.hpp"
#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class AngularSpeed : int_least8_t {
  RadianPerSecond,
  RadianPerMinute,
  RadianPerHour,
  DegreePerSecond,
  DegreePerMinute,
  DegreePerHour,
  RevolutionPerSecond,
  RevolutionPerMinute,
  RevolutionPerHour,
};

}  // namespace Unit

template <>
inline constexpr const Unit::AngularSpeed StandardUnit<Unit::AngularSpeed>{
    Unit::AngularSpeed::RadianPerSecond};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::AngularSpeed>{
    Dimension::Set{Dimension::Time{-1}}};

template <>
inline const std::map<UnitSystem, Unit::AngularSpeed>
    ConsistentUnits<Unit::AngularSpeed>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::AngularSpeed::RadianPerSecond},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::AngularSpeed::RadianPerSecond},
        {UnitSystem::FootPoundSecondRankine,
         Unit::AngularSpeed::RadianPerSecond},
        {UnitSystem::InchPoundSecondRankine,
         Unit::AngularSpeed::RadianPerSecond},
    };

template <>
inline const std::map<Unit::AngularSpeed, UnitSystem>
    RelatedUnitSystems<Unit::AngularSpeed>{};

template <>
inline const std::map<Unit::AngularSpeed, std::string_view>
    Abbreviations<Unit::AngularSpeed>{
        {Unit::AngularSpeed::RadianPerSecond, "rad/s"},
        {Unit::AngularSpeed::RadianPerMinute, "rad/min"},
        {Unit::AngularSpeed::RadianPerHour, "rad/hr"},
        {Unit::AngularSpeed::DegreePerSecond, "deg/s"},
        {Unit::AngularSpeed::DegreePerMinute, "deg/min"},
        {Unit::AngularSpeed::DegreePerHour, "deg/hr"},
        {Unit::AngularSpeed::RevolutionPerSecond, "rev/s"},
        {Unit::AngularSpeed::RevolutionPerMinute, "rev/min"},
        {Unit::AngularSpeed::RevolutionPerHour, "rev/hr"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::AngularSpeed>
    Spellings<Unit::AngularSpeed>{
        {"rad/s", Unit::AngularSpeed::RadianPerSecond},
        {"rad/sec", Unit::AngularSpeed::RadianPerSecond},
        {"rad/min", Unit::AngularSpeed::RadianPerMinute},
        {"rad/hr", Unit::AngularSpeed::RadianPerHour},
        {"°/s", Unit::AngularSpeed::DegreePerSecond},
        {"°/sec", Unit::AngularSpeed::DegreePerSecond},
        {"deg/s", Unit::AngularSpeed::DegreePerSecond},
        {"deg/sec", Unit::AngularSpeed::DegreePerSecond},
        {"°/min", Unit::AngularSpeed::DegreePerMinute},
        {"deg/min", Unit::AngularSpeed::DegreePerMinute},
        {"°/hr", Unit::AngularSpeed::DegreePerHour},
        {"deg/hr", Unit::AngularSpeed::DegreePerHour},
        {"rev/s", Unit::AngularSpeed::RevolutionPerSecond},
        {"rev/sec", Unit::AngularSpeed::RevolutionPerSecond},
        {"rev/min", Unit::AngularSpeed::RevolutionPerMinute},
        {"rev/hr", Unit::AngularSpeed::RevolutionPerHour},
    };

template <>
inline const std::map<
    Unit::AngularSpeed,
    std::function<void(double* const values, const std::size_t size)>>
    Internal::MapOfConversionsFromStandard<Unit::AngularSpeed>{
        {Unit::AngularSpeed::RadianPerSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::AngularSpeed::RadianPerMinute,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 60.0;
           }
         }},
        {Unit::AngularSpeed::RadianPerHour,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 3600.0;
           }
         }},
        {Unit::AngularSpeed::DegreePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 180.0 / Pi;
           }
         }},
        {Unit::AngularSpeed::DegreePerMinute,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 10800.0 / Pi;
           }
         }},
        {Unit::AngularSpeed::DegreePerHour,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 648000.0 / Pi;
           }
         }},
        {Unit::AngularSpeed::RevolutionPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.5 / Pi;
           }
         }},
        {Unit::AngularSpeed::RevolutionPerMinute,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 30.0 / Pi;
           }
         }},
        {Unit::AngularSpeed::RevolutionPerHour,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1800.0 / Pi;
           }
         }},
    };

template <>
inline const std::map<
    Unit::AngularSpeed,
    std::function<void(double* const values, const std::size_t size)>>
    Internal::MapOfConversionsToStandard<Unit::AngularSpeed>{
        {Unit::AngularSpeed::RadianPerSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::AngularSpeed::RadianPerMinute,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 60.0;
           }
         }},
        {Unit::AngularSpeed::RadianPerHour,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 3600.0;
           }
         }},
        {Unit::AngularSpeed::DegreePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= Pi / 180.0;
           }
         }},
        {Unit::AngularSpeed::DegreePerMinute,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= Pi / 10800.0;
           }
         }},
        {Unit::AngularSpeed::DegreePerHour,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= Pi / 648000.0;
           }
         }},
        {Unit::AngularSpeed::RevolutionPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 2.0 * Pi;
           }
         }},
        {Unit::AngularSpeed::RevolutionPerMinute,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= Pi / 30.0;
           }
         }},
        {Unit::AngularSpeed::RevolutionPerHour,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= Pi / 1800.0;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ANGULAR_SPEED_HPP
