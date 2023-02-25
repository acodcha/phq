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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_POWER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_POWER_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Power : int_least8_t {
  Watt,
  Milliwatt,
  Microwatt,
  Nanowatt,
  Kilowatt,
  Megawatt,
  Gigawatt,
  FootPoundPerSecond,
  InchPoundPerSecond,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Power StandardUnit<Unit::Power>{Unit::Power::Watt};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Power>{Dimension::Set{
    Dimension::Time{-3}, Dimension::Length{2}, Dimension::Mass{1}}};

template <>
inline const std::map<UnitSystem, Unit::Power> ConsistentUnits<Unit::Power>{
    {UnitSystem::MetreKilogramSecondKelvin, Unit::Power::Watt},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Power::Nanowatt},
    {UnitSystem::FootPoundSecondRankine, Unit::Power::FootPoundPerSecond},
    {UnitSystem::InchPoundSecondRankine, Unit::Power::InchPoundPerSecond},
};

template <>
inline const std::map<Unit::Power, UnitSystem> RelatedUnitSystems<Unit::Power>{
    {Unit::Power::Watt, UnitSystem::MetreKilogramSecondKelvin},
    {Unit::Power::Nanowatt, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Power::FootPoundPerSecond, UnitSystem::FootPoundSecondRankine},
    {Unit::Power::InchPoundPerSecond, UnitSystem::InchPoundSecondRankine},
};

template <>
inline const std::map<Unit::Power, std::string_view> Abbreviations<Unit::Power>{
    {Unit::Power::Watt, "W"},
    {Unit::Power::Milliwatt, "mW"},
    {Unit::Power::Microwatt, "μW"},
    {Unit::Power::Nanowatt, "nW"},
    {Unit::Power::Kilowatt, "kW"},
    {Unit::Power::Megawatt, "MW"},
    {Unit::Power::Gigawatt, "GW"},
    {Unit::Power::FootPoundPerSecond, "ft·lbf/s"},
    {Unit::Power::InchPoundPerSecond, "in·lbf/s"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Power>
    Spellings<Unit::Power>{
        {"W", Unit::Power::Watt},
        {"N·m/s", Unit::Power::Watt},
        {"N*m/s", Unit::Power::Watt},
        {"kg·m^2/s^3", Unit::Power::Watt},
        {"kg*m^2/s^3", Unit::Power::Watt},
        {"kg·m2/s3", Unit::Power::Watt},
        {"kg*m2/s3", Unit::Power::Watt},
        {"mW", Unit::Power::Milliwatt},
        {"μW", Unit::Power::Microwatt},
        {"uW", Unit::Power::Microwatt},
        {"nW", Unit::Power::Nanowatt},
        {"μN·mm/s", Unit::Power::Nanowatt},
        {"μN*mm/s", Unit::Power::Nanowatt},
        {"uN·mm/s", Unit::Power::Nanowatt},
        {"uN*mm/s", Unit::Power::Nanowatt},
        {"g·mm^2/s^3", Unit::Power::Nanowatt},
        {"g*mm^2/s^3", Unit::Power::Nanowatt},
        {"g·mm2/s3", Unit::Power::Nanowatt},
        {"g*mm2/s3", Unit::Power::Nanowatt},
        {"kW", Unit::Power::Kilowatt},
        {"MW", Unit::Power::Megawatt},
        {"GW", Unit::Power::Gigawatt},
        {"ft·lbf/s", Unit::Power::FootPoundPerSecond},
        {"ft*lbf/s", Unit::Power::FootPoundPerSecond},
        {"ft·lb/s", Unit::Power::FootPoundPerSecond},
        {"ft*lb/s", Unit::Power::FootPoundPerSecond},
        {"in·lbf/s", Unit::Power::InchPoundPerSecond},
        {"in*lbf/s", Unit::Power::InchPoundPerSecond},
        {"in·lb/s", Unit::Power::InchPoundPerSecond},
        {"in*lb/s", Unit::Power::InchPoundPerSecond},
    };

template <>
inline const std::map<Unit::Power, std::function<void(double* const values,
                                                      const std::size_t size)>>
    ConversionsFromStandard<Unit::Power>{
        {Unit::Power::Watt,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Power::Milliwatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Power::Microwatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::Power::Nanowatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000000.0;
           }
         }},
        {Unit::Power::Kilowatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Power::Megawatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::Power::Gigawatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000000001;
           }
         }},
        {Unit::Power::FootPoundPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.3048 * 0.45359237 * 9.80665;
           }
         }},
        {Unit::Power::InchPoundPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.0254 * 0.45359237 * 9.80665;
           }
         }},
    };

template <>
inline const std::map<Unit::Power, std::function<void(double* const values,
                                                      const std::size_t size)>>
    ConversionsToStandard<Unit::Power>{
        {Unit::Power::Watt,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Power::Milliwatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Power::Microwatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::Power::Nanowatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000000001;
           }
         }},
        {Unit::Power::Kilowatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Power::Megawatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::Power::Gigawatt,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000000.0;
           }
         }},
        {Unit::Power::FootPoundPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.3048 * 0.45359237 * 9.80665;
           }
         }},
        {Unit::Power::InchPoundPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0254 * 0.45359237 * 9.80665;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_POWER_HPP
