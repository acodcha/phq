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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_CONDUCTIVITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_CONDUCTIVITY_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class ThermalConductivity : int_least8_t {
  WattPerMetrePerKelvin,
  NanowattPerMillimetrePerKelvin,
  PoundPerSecondPerRankine,
};

}  // namespace Unit

template <>
inline constexpr const Unit::ThermalConductivity
    StandardUnit<Unit::ThermalConductivity>{
        Unit::ThermalConductivity::WattPerMetrePerKelvin};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::ThermalConductivity>{
    Dimension::Set{Dimension::Time{-3}, Dimension::Length{1},
                   Dimension::Mass{1}, Dimension::ElectricCurrent{},
                   Dimension::Temperature{-1}}};

template <>
inline const std::map<UnitSystem, Unit::ThermalConductivity>
    ConsistentUnits<Unit::ThermalConductivity>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {UnitSystem::FootPoundSecondRankine,
         Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {UnitSystem::InchPoundSecondRankine,
         Unit::ThermalConductivity::PoundPerSecondPerRankine},
    };

template <>
inline const std::map<Unit::ThermalConductivity, UnitSystem>
    RelatedUnitSystems<Unit::ThermalConductivity>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin,
         UnitSystem::MetreKilogramSecondKelvin},
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin,
         UnitSystem::MillimetreGramSecondKelvin},
    };

template <>
inline const std::map<Unit::ThermalConductivity, std::string_view>
    Abbreviations<Unit::ThermalConductivity>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin, "W/m/K"},
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin, "nW/mm/K"},
        {Unit::ThermalConductivity::PoundPerSecondPerRankine, "lbf/s/°R"},
    };

// W/(m*K) = J/(m*s*K) = N/(s*K) = kg*m/(s^3*K)

template <>
inline const std::unordered_map<std::string_view, Unit::ThermalConductivity>
    Spellings<Unit::ThermalConductivity>{
        {"W/m/K", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/m/°K", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/m/degK", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/m/°C", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/m/degC", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/m/C", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m·K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m·°K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m·degK)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m·°C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m·degC)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m·C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m*K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m*°K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m*degK)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m*°C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m*degC)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"W/(m*C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/s^3/K", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/s^3/°K", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/s^3/degK", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/s^3/C", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/s^3/°C", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/s^3/degC", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/s^3/K", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/s^3/°K", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/s^3/degK", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/s^3/C", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/s^3/°C", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/s^3/degC", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/(s^3·K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/(s^3·°K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/(s^3·degK)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/(s^3·C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/(s^3·°C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg·m/(s^3·degC)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/(s^3*K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/(s^3*°K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/(s^3*degK)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/(s^3*C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/(s^3*°C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"kg*m/(s^3*degC)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
        {"nW/mm/K", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/mm/°K", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/mm/degK",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/mm/°C", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/mm/degC",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/mm/C", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm·K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm·°K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm·degK)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm·°C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm·degC)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm·C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm*K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm*°K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm*degK)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm*°C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm*degC)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm*C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/s^3/K",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/s^3/°K",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/s^3/degK",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/s^3/C",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/s^3/°C",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/s^3/degC",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/s^3/K",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/s^3/°K",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/s^3/degK",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/s^3/C",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/s^3/°C",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/s^3/degC",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/(s^3·K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/(s^3·°K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/(s^3·degK)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/(s^3·C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/(s^3·°C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g·mm/(s^3·degC)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/(s^3*K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/(s^3*°K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/(s^3*degK)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/(s^3*C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/(s^3*°C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"g*mm/(s^3*degC)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"lbf/s/°R", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/s/R", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/s/degR", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/s/°F", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/s/F", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/s/degF", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s·°R)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s·R)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s·degR)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s·°F)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s·F)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s·degF)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s*°R)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s*R)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s*degR)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s*°F)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s*F)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lbf/(s*degF)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/s/°R", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/s/R", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/s/degR", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/s/°F", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/s/F", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/s/degF", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s·°R)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s·R)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s·degR)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s·°F)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s·F)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s·degF)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s*°R)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s*R)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s*degR)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s*°F)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s*F)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {"lb/(s*degF)", Unit::ThermalConductivity::PoundPerSecondPerRankine},
    };

template <>
inline const std::map<
    Unit::ThermalConductivity,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::ThermalConductivity>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::ThermalConductivity::PoundPerSecondPerRankine,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.45359237 * 9.80665 * 1.8;
           }
         }},
    };

template <>
inline const std::map<
    Unit::ThermalConductivity,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::ThermalConductivity>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::ThermalConductivity::PoundPerSecondPerRankine,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 * 1.8;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_CONDUCTIVITY_HPP
