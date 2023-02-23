// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class TemperatureDifference : int_least8_t {
  Kelvin,
  Celsius,
  Rankine,
  Fahrenheit
};

} // namespace Unit

template <> const std::map<Unit::TemperatureDifference, std::string> abbreviations<Unit::TemperatureDifference>{
  {Unit::TemperatureDifference::Kelvin, "K"},
  {Unit::TemperatureDifference::Celsius, "°C"},
  {Unit::TemperatureDifference::Rankine, "°R"},
  {Unit::TemperatureDifference::Fahrenheit, "°F"}
};

template <> const std::unordered_map<std::string, Unit::TemperatureDifference> spellings<Unit::TemperatureDifference>{
  {"K", Unit::TemperatureDifference::Kelvin},
  {"°K", Unit::TemperatureDifference::Kelvin},
  {"degK", Unit::TemperatureDifference::Kelvin},
  {"°C", Unit::TemperatureDifference::Celsius},
  {"C", Unit::TemperatureDifference::Celsius},
  {"degC", Unit::TemperatureDifference::Celsius},
  {"°R", Unit::TemperatureDifference::Rankine},
  {"R", Unit::TemperatureDifference::Rankine},
  {"degR", Unit::TemperatureDifference::Rankine},
  {"°F", Unit::TemperatureDifference::Fahrenheit},
  {"F", Unit::TemperatureDifference::Fahrenheit},
  {"degF", Unit::TemperatureDifference::Fahrenheit}
};

template <> const std::map<System, Unit::TemperatureDifference> consistent_units<Unit::TemperatureDifference>{
  {System::MetreKilogramSecondKelvin, Unit::TemperatureDifference::Kelvin},
  {System::MillimetreGramSecondKelvin, Unit::TemperatureDifference::Kelvin},
  {System::FootPoundSecondRankine, Unit::TemperatureDifference::Rankine},
  {System::InchPoundSecondRankine, Unit::TemperatureDifference::Rankine}
};

template <> constexpr const Unit::TemperatureDifference standard_unit<Unit::TemperatureDifference>{Unit::TemperatureDifference::Kelvin};

template <> constexpr const Dimension::Set dimension<Unit::TemperatureDifference>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{}, Dimension::ElectricCurrent{}, Dimension::Temperature{1}}};

template <> const std::map<Unit::TemperatureDifference, std::map<Unit::TemperatureDifference, std::function<void(std::vector<double>&)>>> conversions<Unit::TemperatureDifference>{
  {Unit::TemperatureDifference::Kelvin, {
    {Unit::TemperatureDifference::Kelvin, [](std::vector<double>& values)->void{}},
    {Unit::TemperatureDifference::Celsius, [](std::vector<double>& values)->void{}},
    {Unit::TemperatureDifference::Rankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8;});}},
    {Unit::TemperatureDifference::Fahrenheit, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8;});}}
  }},
  {Unit::TemperatureDifference::Celsius, {
    {Unit::TemperatureDifference::Kelvin, [](std::vector<double>& values)->void{}},
    {Unit::TemperatureDifference::Celsius, [](std::vector<double>& values)->void{}},
    {Unit::TemperatureDifference::Rankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8;});}},
    {Unit::TemperatureDifference::Fahrenheit, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8;});}}
  }},
  {Unit::TemperatureDifference::Rankine, {
    {Unit::TemperatureDifference::Kelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8;});}},
    {Unit::TemperatureDifference::Celsius, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8;});}},
    {Unit::TemperatureDifference::Rankine, [](std::vector<double>& values)->void{}},
    {Unit::TemperatureDifference::Fahrenheit, [](std::vector<double>& values)->void{}}
  }},
  {Unit::TemperatureDifference::Fahrenheit, {
    {Unit::TemperatureDifference::Kelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8;});}},
    {Unit::TemperatureDifference::Celsius, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8;});}},
    {Unit::TemperatureDifference::Rankine, [](std::vector<double>& values)->void{}},
    {Unit::TemperatureDifference::Fahrenheit, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
