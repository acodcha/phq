// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Temperature : int_least8_t {
  Kelvin,
  Celsius,
  Rankine,
  Fahrenheit
};

} // namespace Unit

template <> const std::map<Unit::Temperature, std::string> abbreviations<Unit::Temperature>{
  {Unit::Temperature::Kelvin, "K"},
  {Unit::Temperature::Celsius, "°C"},
  {Unit::Temperature::Rankine, "°R"},
  {Unit::Temperature::Fahrenheit, "°F"}
};

template <> const std::unordered_map<std::string, Unit::Temperature> spellings<Unit::Temperature>{
  {"K", Unit::Temperature::Kelvin},
  {"°K", Unit::Temperature::Kelvin},
  {"degK", Unit::Temperature::Kelvin},
  {"°C", Unit::Temperature::Celsius},
  {"C", Unit::Temperature::Celsius},
  {"degC", Unit::Temperature::Celsius},
  {"°R", Unit::Temperature::Rankine},
  {"R", Unit::Temperature::Rankine},
  {"degR", Unit::Temperature::Rankine},
  {"°F", Unit::Temperature::Fahrenheit},
  {"F", Unit::Temperature::Fahrenheit},
  {"degF", Unit::Temperature::Fahrenheit}
};

template <> const std::map<System, Unit::Temperature> consistent_units<Unit::Temperature>{
  {System::MetreKilogramSecondKelvin, Unit::Temperature::Kelvin},
  {System::MillimetreGramSecondKelvin, Unit::Temperature::Kelvin},
  {System::FootPoundSecondRankine, Unit::Temperature::Rankine},
  {System::InchPoundSecondRankine, Unit::Temperature::Rankine}
};

template <> constexpr const Unit::Temperature standard_unit<Unit::Temperature>{Unit::Temperature::Kelvin};

template <> constexpr const Dimension::Set dimension<Unit::Temperature>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{}, Dimension::ElectricCurrent{}, Dimension::Temperature{1}}};

template <> const std::map<Unit::Temperature, std::map<Unit::Temperature, std::function<void(std::vector<double>&)>>> conversions<Unit::Temperature>{
  {Unit::Temperature::Kelvin, {
    {Unit::Temperature::Kelvin, [](std::vector<double>& values)->void{}},
    {Unit::Temperature::Celsius, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value -= 273.15;});}},
    {Unit::Temperature::Rankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8;});}},
    {Unit::Temperature::Fahrenheit, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value = (value * 1.8) - 459.67;});}}
  }},
  {Unit::Temperature::Celsius, {
    {Unit::Temperature::Kelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value += 273.15;});}},
    {Unit::Temperature::Celsius, [](std::vector<double>& values)->void{}},
    {Unit::Temperature::Rankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value = (value + 273.15) * 1.8;});}},
    {Unit::Temperature::Fahrenheit, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value = (value * 1.8) + 32.0;});}}
  }},
  {Unit::Temperature::Rankine, {
    {Unit::Temperature::Kelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8;});}},
    {Unit::Temperature::Celsius, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value = (value - 491.67) / 1.8;});}},
    {Unit::Temperature::Rankine, [](std::vector<double>& values)->void{}},
    {Unit::Temperature::Fahrenheit, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value -= 459.67;});}}
  }},
  {Unit::Temperature::Fahrenheit, {
    {Unit::Temperature::Kelvin, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value = (value + 459.67) / 1.8;});}},
    {Unit::Temperature::Celsius, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value = (value - 32.0) / 1.8;});}},
    {Unit::Temperature::Rankine, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value += 459.67;});}},
    {Unit::Temperature::Fahrenheit, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
