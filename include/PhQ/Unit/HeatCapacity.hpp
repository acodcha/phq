// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class HeatCapacity : uint_least8_t {
  JoulePerKelvin,
  NanojoulePerKelvin,
  FootPoundPerRankine,
  InchPoundPerRankine
};

} // namespace Unit

template <> const std::map<Unit::HeatCapacity, std::string> abbreviations<Unit::HeatCapacity>{
  {Unit::HeatCapacity::JoulePerKelvin, "J/K"},
  {Unit::HeatCapacity::NanojoulePerKelvin, "nJ/K"},
  {Unit::HeatCapacity::FootPoundPerRankine, "ft·lbf/°R"},
  {Unit::HeatCapacity::InchPoundPerRankine, "in·lbf/°R"}
};

template <> const std::unordered_map<std::string, Unit::HeatCapacity> spellings<Unit::HeatCapacity>{
  {"J/K", Unit::HeatCapacity::JoulePerKelvin},
  {"N·m/K", Unit::HeatCapacity::JoulePerKelvin},
  {"N*m/K", Unit::HeatCapacity::JoulePerKelvin},
  {"kg·m^2/s^2/K", Unit::HeatCapacity::JoulePerKelvin},
  {"kg*m^2/s^2/K", Unit::HeatCapacity::JoulePerKelvin},
  {"kg·m2/s2/K", Unit::HeatCapacity::JoulePerKelvin},
  {"kg*m2/s2/K", Unit::HeatCapacity::JoulePerKelvin},
  {"kg·m^2/(s^2·K)", Unit::HeatCapacity::JoulePerKelvin},
  {"kg*m^2/(s^2*K)", Unit::HeatCapacity::JoulePerKelvin},
  {"kg·m2/(s2·K)", Unit::HeatCapacity::JoulePerKelvin},
  {"kg*m2/(s2*K)", Unit::HeatCapacity::JoulePerKelvin},
  {"nJ/K", Unit::HeatCapacity::NanojoulePerKelvin},
  {"μN·mm/K", Unit::HeatCapacity::NanojoulePerKelvin},
  {"μN*mm/K", Unit::HeatCapacity::NanojoulePerKelvin},
  {"uN·mm/K", Unit::HeatCapacity::NanojoulePerKelvin},
  {"uN*mm/K", Unit::HeatCapacity::NanojoulePerKelvin},
  {"g·mm^2/s^2/K", Unit::HeatCapacity::NanojoulePerKelvin},
  {"g*mm^2/s^2/K", Unit::HeatCapacity::NanojoulePerKelvin},
  {"g·mm2/s2/K", Unit::HeatCapacity::NanojoulePerKelvin},
  {"g*mm2/s2/K", Unit::HeatCapacity::NanojoulePerKelvin},
  {"g·mm^2/(s^2·K)", Unit::HeatCapacity::NanojoulePerKelvin},
  {"g*mm^2/(s^2*K)", Unit::HeatCapacity::NanojoulePerKelvin},
  {"g·mm2/(s2·K)", Unit::HeatCapacity::NanojoulePerKelvin},
  {"g*mm2/(s2*K)", Unit::HeatCapacity::NanojoulePerKelvin},
  {"ft·lbf/°R", Unit::HeatCapacity::FootPoundPerRankine},
  {"ft·lbf/R", Unit::HeatCapacity::FootPoundPerRankine},
  {"ft*lbf/°R", Unit::HeatCapacity::FootPoundPerRankine},
  {"ft*lbf/R", Unit::HeatCapacity::FootPoundPerRankine},
  {"ft·lb/°R", Unit::HeatCapacity::FootPoundPerRankine},
  {"ft·lb/R", Unit::HeatCapacity::FootPoundPerRankine},
  {"ft*lb/°R", Unit::HeatCapacity::FootPoundPerRankine},
  {"ft*lb/R", Unit::HeatCapacity::FootPoundPerRankine},
  {"in·lbf/°R", Unit::HeatCapacity::InchPoundPerRankine},
  {"in·lbf/R", Unit::HeatCapacity::InchPoundPerRankine},
  {"in*lbf/°R", Unit::HeatCapacity::InchPoundPerRankine},
  {"in*lbf/R", Unit::HeatCapacity::InchPoundPerRankine},
  {"in·lb/°R", Unit::HeatCapacity::InchPoundPerRankine},
  {"in·lb/R", Unit::HeatCapacity::InchPoundPerRankine},
  {"in*lb/°R", Unit::HeatCapacity::InchPoundPerRankine},
  {"in*lb/R", Unit::HeatCapacity::InchPoundPerRankine}
};

template <> const std::map<System, Unit::HeatCapacity> consistent_units<Unit::HeatCapacity>{
  {System::MetreKilogramSecondKelvin, Unit::HeatCapacity::JoulePerKelvin},
  {System::MillimetreGramSecondKelvin, Unit::HeatCapacity::NanojoulePerKelvin},
  {System::FootPoundSecondRankine, Unit::HeatCapacity::FootPoundPerRankine},
  {System::InchPoundSecondRankine, Unit::HeatCapacity::InchPoundPerRankine}
};

template <> constexpr const Unit::HeatCapacity standard_unit<Unit::HeatCapacity>{Unit::HeatCapacity::JoulePerKelvin};

template <> constexpr const Dimension::Set dimension<Unit::HeatCapacity>{Dimension::Set{Dimension::Length{2}, Dimension::Mass{1}, Dimension::Time{-2}, Dimension::ElectricCurrent{}, Dimension::Temperature{-1}}};

template <size_t size> const std::map<Unit::HeatCapacity, std::map<Unit::HeatCapacity, std::function<void(std::array<double, size>&)>>> conversions<Unit::HeatCapacity, size>{
  {Unit::HeatCapacity::JoulePerKelvin, {
    {Unit::HeatCapacity::JoulePerKelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::HeatCapacity::NanojoulePerKelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9;});}},
    {Unit::HeatCapacity::FootPoundPerRankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.3048 * 0.45359237 * 9.80665 * 1.8;});}},
    {Unit::HeatCapacity::InchPoundPerRankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.0254 * 0.45359237 * 9.80665 * 1.8;});}}
  }},
  {Unit::HeatCapacity::NanojoulePerKelvin, {
    {Unit::HeatCapacity::JoulePerKelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9;});}},
    {Unit::HeatCapacity::NanojoulePerKelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::HeatCapacity::FootPoundPerRankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e9 * 0.3048 * 0.45359237 * 9.80665 * 1.8;});}},
    {Unit::HeatCapacity::InchPoundPerRankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e9 * 0.0254 * 0.45359237 * 9.80665 * 1.8;});}}
  }},
  {Unit::HeatCapacity::FootPoundPerRankine, {
    {Unit::HeatCapacity::JoulePerKelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.3048 * 0.45359237 * 9.80665 * 1.8;});}},
    {Unit::HeatCapacity::NanojoulePerKelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9 * 0.3048 * 0.45359237 * 9.80665 * 1.8;});}},
    {Unit::HeatCapacity::FootPoundPerRankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::HeatCapacity::InchPoundPerRankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12.0;});}}
  }},
  {Unit::HeatCapacity::InchPoundPerRankine, {
    {Unit::HeatCapacity::JoulePerKelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0254 * 0.45359237 * 9.80665 * 1.8;});}},
    {Unit::HeatCapacity::NanojoulePerKelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9 * 0.0254 * 0.45359237 * 9.80665 * 1.8;});}},
    {Unit::HeatCapacity::FootPoundPerRankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12.0;});}},
    {Unit::HeatCapacity::InchPoundPerRankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}
  }}
};

} // namespace PhQ
