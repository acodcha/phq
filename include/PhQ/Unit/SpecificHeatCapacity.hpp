// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class SpecificHeatCapacity : uint_least8_t {
  JoulePerKilogramPerKelvin,
  NanojoulePerGramPerKelvin,
  FootPoundPerSlugPerRankine,
  InchPoundPerSlinchPerRankine
};

} // namespace Unit

template <> const std::map<Unit::SpecificHeatCapacity, std::string> abbreviations<Unit::SpecificHeatCapacity>{
  {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin, "J/kg/K"},
  {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin, "nJ/g/K"},
  {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine, "ft·lbf/slug/°R"},
  {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine, "in·lbf/slinch/°R"}
};

template <> const std::unordered_map<std::string, Unit::SpecificHeatCapacity> spellings<Unit::SpecificHeatCapacity>{
  {"J/kg/K", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"J/(kg·K)", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"J/(kg*K)", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"N·m/kg/K", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"N·m/(kg·K)", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"N*m/kg/K", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"N*m/(kg*K)", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"m·N/kg/K", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"m·N/(kg·K)", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"m*N/kg/K", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"m*N/(kg*K)", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"m^2/s^2/K", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"m^2/(s^2·K)", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"m^2/(s^2*K)", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"m2/s2/K", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"m2/(s2·K)", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"m2/(s2*K)", Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {"nJ/g/K", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"nJ/(g*K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"nJ/(g·K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"μN·mm/g/K", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"μN·mm/(g·K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"μN*mm/g/K", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"μN*mm/(g*K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"uN·mm/g/K", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"uN·mm/(g·K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"uN*mm/g/K", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"uN*mm/(g*K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm·μN/g/K", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm·μN/(g·K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm*μN/g/K", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm*μN/(g*K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm·uN/g/K", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm·uN/(g·K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm*uN/g/K", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm*uN/(g*K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm^2/s^2/K", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm^2/(s^2·K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm^2/(s^2*K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm2/s2/K", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm2/(s2·K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"mm2/(s2*K)", Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {"ft·lbf/slug/°R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft·lbf/(slug·°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft·lbf/slug/R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft·lbf/(slug·R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft*lbf/slug/°R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft*lbf/(slug*°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft*lbf/slug/R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft*lbf/(slug*R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lbf·ft/slug/°R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lbf·ft/(slug·°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lbf·ft/slug/R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lbf·ft/(slug·R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lbf*ft/slug/°R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lbf*ft/(slug*°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lbf*ft/slug/R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lbf*ft/(slug*R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft·lb/slug/°R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft·lb/(slug·°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft·lb/slug/R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft·lb/(slug·R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft*lb/slug/°R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft*lb/(slug*°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft*lb/slug/R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft*lb/(slug*R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lb·ft/slug/°R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lb·ft/(slug·°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lb·ft/slug/R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lb·ft/(slug·R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lb*ft/slug/°R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lb*ft/(slug*°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lb*ft/slug/R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"lb*ft/(slug*R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft^2/s^2/°R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft^2/(s^2·°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft^2/(s^2*°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft^2/s^2/R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft^2/(s^2·R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft^2/(s^2*R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft2/s2/°R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft2/(s2·°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft2/(s2*°R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft2/s2/R", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft2/(s2·R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"ft2/(s2*R)", Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {"in·lbf/slug/°R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in·lbf/(slug·°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in·lbf/slug/R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in·lbf/(slug·R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in*lbf/slug/°R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in*lbf/(slug*°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in*lbf/slug/R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in*lbf/(slug*R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lbf·in/slug/°R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lbf·in/(slug·°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lbf·in/slug/R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lbf·in/(slug·R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lbf*in/slug/°R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lbf*in/(slug*°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lbf*in/slug/R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lbf*in/(slug*R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in·lb/slug/°R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in·lb/(slug·°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in·lb/slug/R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in·lb/(slug·R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in*lb/slug/°R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in*lb/(slug*°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in*lb/slug/R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in*lb/(slug*R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lb·in/slug/°R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lb·in/(slug·°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lb·in/slug/R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lb·in/(slug·R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lb*in/slug/°R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lb*in/(slug*°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lb*in/slug/R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"lb*in/(slug*R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in^2/s^2/°R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in^2/(s^2·°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in^2/(s^2*°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in^2/s^2/R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in^2/(s^2·R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in^2/(s^2*R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in2/s2/°R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in2/(s2·°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in2/(s2*°R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in2/s2/R", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in2/(s2·R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine},
  {"in2/(s2*R)", Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine}
};

template <> const std::map<System, Unit::SpecificHeatCapacity> consistent_units<Unit::SpecificHeatCapacity>{
  {System::MetreKilogramSecondKelvin, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin},
  {System::MillimetreGramSecondKelvin, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin},
  {System::FootPoundSecondRankine, Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine},
  {System::InchPoundSecondRankine, Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine}
};

template <> const std::map<Unit::SpecificHeatCapacity, System> related_systems<Unit::SpecificHeatCapacity>{
  {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin, System::MetreKilogramSecondKelvin},
  {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin, System::MillimetreGramSecondKelvin},
  {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine, System::FootPoundSecondRankine},
  {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine, System::InchPoundSecondRankine},
};

template <> constexpr const Unit::SpecificHeatCapacity standard_unit<Unit::SpecificHeatCapacity>{Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};

template <> constexpr const Dimension::Set dimension<Unit::SpecificHeatCapacity>{Dimension::Set{Dimension::Length{2}, Dimension::Mass{}, Dimension::Time{-2}, Dimension::ElectricCurrent{}, Dimension::Temperature{-1}}};

template <> const std::map<Unit::SpecificHeatCapacity, std::map<Unit::SpecificHeatCapacity, std::function<void(std::vector<double>&)>>> conversions<Unit::SpecificHeatCapacity>{
  {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin, {
    {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 2);});}},
    {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.3048, 2) * 1.8;});}},
    {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0254, 2) * 1.8;});}}
  }},
  {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin, {
    {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 2);});}},
    {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(304.8, 2) * 1.8;});}},
    {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(25.4, 2) * 1.8;});}}
  }},
  {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine, {
    {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.3048, 2) * 1.8;});}},
    {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(304.8, 2) * 1.8;});}},
    {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12.0, 2);});}}
  }},
  {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine, {
    {Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 2) * 1.8;});}},
    {Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(25.4, 2) * 1.8;});}},
    {Unit::SpecificHeatCapacity::FootPoundPerSlugPerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12.0, 2);});}},
    {Unit::SpecificHeatCapacity::InchPoundPerSlinchPerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}
  }}
};

} // namespace PhQ
