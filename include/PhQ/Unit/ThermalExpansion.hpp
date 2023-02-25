// Copyright 2020 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_EXPANSION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_EXPANSION_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class ThermalExpansion : int_least8_t {
  PerKelvin,
  PerCelsius,
  PerRankine,
  PerFahrenheit
};

}  // namespace Unit

template <>
inline constexpr const Unit::ThermalExpansion
    StandardUnit<Unit::ThermalExpansion>{Unit::ThermalExpansion::PerKelvin};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::ThermalExpansion>{
    Dimension::Set{Dimension::Time{}, Dimension::Length{}, Dimension::Mass{},
                   Dimension::ElectricCurrent{}, Dimension::Temperature{-1}}};

template <>
inline const std::map<UnitSystem, Unit::ThermalExpansion> ConsistentUnits<
    Unit::ThermalExpansion>{
    {UnitSystem::MetreKilogramSecondKelvin, Unit::ThermalExpansion::PerKelvin},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::ThermalExpansion::PerKelvin},
    {UnitSystem::FootPoundSecondRankine, Unit::ThermalExpansion::PerRankine},
    {UnitSystem::InchPoundSecondRankine, Unit::ThermalExpansion::PerRankine}};

template <>
inline const std::map<Unit::ThermalExpansion, UnitSystem>
    RelatedUnitSystems<Unit::ThermalExpansion>{};

template <>
inline const std::map<Unit::ThermalExpansion, std::string_view>
    Abbreviations<Unit::ThermalExpansion>{
        {Unit::ThermalExpansion::PerKelvin, "1/K"},
        {Unit::ThermalExpansion::PerCelsius, "1/°C"},
        {Unit::ThermalExpansion::PerRankine, "1/°R"},
        {Unit::ThermalExpansion::PerFahrenheit, "1/°F"}};

template <>
inline const std::unordered_map<std::string_view, Unit::ThermalExpansion>
    Spellings<Unit::ThermalExpansion>{
        {"1/K", Unit::ThermalExpansion::PerKelvin},
        {"1/°K", Unit::ThermalExpansion::PerKelvin},
        {"1/degK", Unit::ThermalExpansion::PerKelvin},
        {"/K", Unit::ThermalExpansion::PerKelvin},
        {"/°K", Unit::ThermalExpansion::PerKelvin},
        {"/degK", Unit::ThermalExpansion::PerKelvin},
        {"1/°C", Unit::ThermalExpansion::PerCelsius},
        {"1/C", Unit::ThermalExpansion::PerCelsius},
        {"1/degC", Unit::ThermalExpansion::PerCelsius},
        {"/°C", Unit::ThermalExpansion::PerCelsius},
        {"/C", Unit::ThermalExpansion::PerCelsius},
        {"/degC", Unit::ThermalExpansion::PerCelsius},
        {"1/°R", Unit::ThermalExpansion::PerRankine},
        {"1/R", Unit::ThermalExpansion::PerRankine},
        {"1/degR", Unit::ThermalExpansion::PerRankine},
        {"/°R", Unit::ThermalExpansion::PerRankine},
        {"/R", Unit::ThermalExpansion::PerRankine},
        {"/degR", Unit::ThermalExpansion::PerRankine},
        {"1/°F", Unit::ThermalExpansion::PerFahrenheit},
        {"1/F", Unit::ThermalExpansion::PerFahrenheit},
        {"1/degF", Unit::ThermalExpansion::PerFahrenheit},
        {"/°F", Unit::ThermalExpansion::PerFahrenheit},
        {"/F", Unit::ThermalExpansion::PerFahrenheit},
        {"/degF", Unit::ThermalExpansion::PerFahrenheit}};

template <>
inline const std::map<
    Unit::ThermalExpansion,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::ThermalExpansion>{
        {Unit::ThermalExpansion::PerKelvin,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::ThermalExpansion::PerCelsius,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::ThermalExpansion::PerRankine,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1.8;
           }
         }},
        {Unit::ThermalExpansion::PerFahrenheit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1.8;
           }
         }},
    };

template <>
inline const std::map<
    Unit::ThermalExpansion,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::ThermalExpansion>{
        {Unit::ThermalExpansion::PerKelvin,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::ThermalExpansion::PerCelsius,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::ThermalExpansion::PerRankine,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1.8;
           }
         }},
        {Unit::ThermalExpansion::PerFahrenheit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1.8;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_EXPANSION_HPP
