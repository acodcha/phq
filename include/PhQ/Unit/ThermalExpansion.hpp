// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class ThermalExpansion : uint_least8_t {
  PerKelvin,
  PerCelsius,
  PerRankine,
  PerFahrenheit
};

} // namespace Unit

template <> const std::map<Unit::ThermalExpansion, std::string> abbreviations<Unit::ThermalExpansion>{
  {Unit::ThermalExpansion::PerKelvin, "1/K"},
  {Unit::ThermalExpansion::PerCelsius, "1/°C"},
  {Unit::ThermalExpansion::PerRankine, "1/°R"},
  {Unit::ThermalExpansion::PerFahrenheit, "1/°F"}
};

template <> const std::unordered_map<std::string, Unit::ThermalExpansion> spellings<Unit::ThermalExpansion>{
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
  {"/degF", Unit::ThermalExpansion::PerFahrenheit}
};

template <> const std::map<System, Unit::ThermalExpansion> consistent_units<Unit::ThermalExpansion>{
  {System::MetreKilogramSecondKelvin, Unit::ThermalExpansion::PerKelvin},
  {System::MillimetreGramSecondKelvin, Unit::ThermalExpansion::PerKelvin},
  {System::FootPoundSecondRankine, Unit::ThermalExpansion::PerRankine},
  {System::InchPoundSecondRankine, Unit::ThermalExpansion::PerRankine}
};

template <> constexpr const Unit::ThermalExpansion standard_unit<Unit::ThermalExpansion>{Unit::ThermalExpansion::PerKelvin};

template <> constexpr const Dimension::Set dimension<Unit::ThermalExpansion>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{}, Dimension::ElectricCurrent{}, Dimension::Temperature{-1}}};

template <> const std::map<Unit::ThermalExpansion, std::map<Unit::ThermalExpansion, std::function<void(std::vector<double>&)>>> conversions<Unit::ThermalExpansion>{
  {Unit::ThermalExpansion::PerKelvin, {
    {Unit::ThermalExpansion::PerKelvin, [](std::vector<double>& values)->void{}},
    {Unit::ThermalExpansion::PerCelsius, [](std::vector<double>& values)->void{}},
    {Unit::ThermalExpansion::PerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8;});}},
    {Unit::ThermalExpansion::PerFahrenheit, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8;});}}
  }},
  {Unit::ThermalExpansion::PerCelsius, {
    {Unit::ThermalExpansion::PerKelvin, [](std::vector<double>& values)->void{}},
    {Unit::ThermalExpansion::PerCelsius, [](std::vector<double>& values)->void{}},
    {Unit::ThermalExpansion::PerRankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8;});}},
    {Unit::ThermalExpansion::PerFahrenheit, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8;});}}
  }},
  {Unit::ThermalExpansion::PerRankine, {
    {Unit::ThermalExpansion::PerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8;});}},
    {Unit::ThermalExpansion::PerCelsius, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8;});}},
    {Unit::ThermalExpansion::PerRankine, [](std::vector<double>& values)->void{}},
    {Unit::ThermalExpansion::PerFahrenheit, [](std::vector<double>& values)->void{}}
  }},
  {Unit::ThermalExpansion::PerFahrenheit, {
    {Unit::ThermalExpansion::PerKelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8;});}},
    {Unit::ThermalExpansion::PerCelsius, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8;});}},
    {Unit::ThermalExpansion::PerRankine, [](std::vector<double>& values)->void{}},
    {Unit::ThermalExpansion::PerFahrenheit, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
