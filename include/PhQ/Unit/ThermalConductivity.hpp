// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class ThermalConductivity : uint_least8_t {
  WattPerMetrePerKelvin,
  NanowattPerMillimetrePerKelvin,
  PoundPerSecondPerRankine
};

} // namespace Unit

template <> const std::map<Unit::ThermalConductivity, std::string> abbreviations<Unit::ThermalConductivity>{
  {Unit::ThermalConductivity::WattPerMetrePerKelvin, "W/m/K"},
  {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin, "nW/mm/K"},
  {Unit::ThermalConductivity::PoundPerSecondPerRankine, "lbf/s/°R"}
};

template <> const std::unordered_map<std::string, Unit::ThermalConductivity> spellings<Unit::ThermalConductivity>{
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
  {"kg*m/s/K", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg*m/s/°K", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg*m/s/degK", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg*m/s/C", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg*m/s/°C", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg*m/s/degC", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/s/K", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/s/°K", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/s/degK", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/s/C", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/s/°C", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/s/degC", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/(s·K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/(s·°K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/(s·degK)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/(s·C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/(s·°C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg·m/(s·degC)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg*m/(s*K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg*m/(s*°K)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg*m/(s*degK)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg*m/(s*C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg*m/(s*°C)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"kg*m/(s*degC)", Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {"nW/mm/K", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/mm/°K", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/mm/degK", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/mm/°C", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/mm/degC", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/mm/C", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm·K)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm·°K)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm·degK)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm·°C)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm·degC)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm·C)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm*K)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm*°K)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm*degK)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm*°C)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm*degC)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"nW/(mm*C)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/s/K", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/s/°K", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/s/degK", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/s/C", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/s/°C", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/s/degC", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/s/K", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/s/°K", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/s/degK", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/s/C", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/s/°C", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/s/degC", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/(s·K)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/(s·°K)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/(s·degK)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/(s·C)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/(s·°C)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g·mm/(s·degC)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/(s*K)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/(s*°K)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/(s*degK)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/(s*C)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/(s*°C)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {"g*mm/(s*degC)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
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
  {"lb/(s*degF)", Unit::ThermalConductivity::PoundPerSecondPerRankine}
};

template <> const std::map<System, Unit::ThermalConductivity> consistent_units<Unit::ThermalConductivity>{
  {System::MetreKilogramSecondKelvin, Unit::ThermalConductivity::WattPerMetrePerKelvin},
  {System::MillimetreGramSecondKelvin, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
  {System::FootPoundSecondRankine, Unit::ThermalConductivity::PoundPerSecondPerRankine},
  {System::InchPoundSecondRankine, Unit::ThermalConductivity::PoundPerSecondPerRankine}
};

template <> const std::map<Unit::ThermalConductivity, System> related_systems<Unit::ThermalConductivity>{
  {Unit::ThermalConductivity::WattPerMetrePerKelvin, System::MetreKilogramSecondKelvin},
  {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin, System::MillimetreGramSecondKelvin},
  {Unit::ThermalConductivity::PoundPerSecondPerRankine, System::FootPoundSecondRankine},
  {Unit::ThermalConductivity::PoundPerSecondPerRankine, System::InchPoundSecondRankine},
};

template <> constexpr const Unit::ThermalConductivity standard_unit<Unit::ThermalConductivity>{Unit::ThermalConductivity::WattPerMetrePerKelvin};

// W/m/K = N/s/K = kg*m/s^3/K

// N/s/K -> lbf/s/R

template <> constexpr const Dimension::Set dimension<Unit::ThermalConductivity>{Dimension::Set{Dimension::Length{1}, Dimension::Mass{1}, Dimension::Time{-3}, Dimension::ElectricCurrent{}, Dimension::Temperature{-1}}};

template <> const std::map<Unit::ThermalConductivity, std::map<Unit::ThermalConductivity, std::function<void(std::vector<double>&)>>> conversions<Unit::ThermalConductivity>{
  {Unit::ThermalConductivity::WattPerMetrePerKelvin, {
    {Unit::ThermalConductivity::WattPerMetrePerKelvin, [](std::vector<double>& values)->void{}},
    {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6;});}},
    {Unit::ThermalConductivity::PoundPerSecondPerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.45359237 * 9.80665 * 9.0 / 5.0;});}}
  }},
  {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin, {
    {Unit::ThermalConductivity::WattPerMetrePerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6;});}},
    {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin, [](std::vector<double>& values)->void{}},
    {Unit::ThermalConductivity::PoundPerSecondPerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e6 * 0.45359237 * 9.80665 * 9.0 / 5.0;});}}
  }},
  {Unit::ThermalConductivity::PoundPerSecondPerRankine, {
    {Unit::ThermalConductivity::WattPerMetrePerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 * 9.0 / 5.0;});}},
    {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6 * 0.45359237 * 9.80665 * 9.0 / 5.0;});}},
    {Unit::ThermalConductivity::PoundPerSecondPerRankine, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
