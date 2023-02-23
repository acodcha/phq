// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Time : int_least8_t {
  Second,
  Minute,
  Hour
};

} // namespace Unit

template <> const std::map<Unit::Time, std::string> abbreviations<Unit::Time>{
  {Unit::Time::Second, "s"},
  {Unit::Time::Minute, "min"},
  {Unit::Time::Hour, "hr"}
};

template <> const std::unordered_map<std::string, Unit::Time> spellings<Unit::Time>{
  {"s", Unit::Time::Second},
  {"sec", Unit::Time::Second},
  {"secs", Unit::Time::Second},
  {"second", Unit::Time::Second},
  {"seconds", Unit::Time::Second},
  {"min", Unit::Time::Minute},
  {"mins", Unit::Time::Minute},
  {"minute", Unit::Time::Minute},
  {"minutes", Unit::Time::Minute},
  {"hr", Unit::Time::Hour},
  {"hrs", Unit::Time::Hour},
  {"hour", Unit::Time::Hour},
  {"hours", Unit::Time::Hour}
};

template <> const std::map<System, Unit::Time> consistent_units<Unit::Time>{
  {System::MetreKilogramSecondKelvin, Unit::Time::Second},
  {System::MillimetreGramSecondKelvin, Unit::Time::Second},
  {System::FootPoundSecondRankine, Unit::Time::Second},
  {System::InchPoundSecondRankine, Unit::Time::Second}
};

template <> constexpr const Unit::Time standard_unit<Unit::Time>{Unit::Time::Second};

template <> constexpr const Dimension::Set dimension<Unit::Time>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{1}}};

template <> const std::map<Unit::Time, std::map<Unit::Time, std::function<void(std::vector<double>&)>>> conversions<Unit::Time>{
  {Unit::Time::Second, {
    {Unit::Time::Second, [](std::vector<double>& values)->void{}},
    {Unit::Time::Minute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::Time::Hour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}}
  }},
  {Unit::Time::Minute, {
    {Unit::Time::Second, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::Time::Minute, [](std::vector<double>& values)->void{}},
    {Unit::Time::Hour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}}
  }},
  {Unit::Time::Hour, {
    {Unit::Time::Second, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}},
    {Unit::Time::Minute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::Time::Hour, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
