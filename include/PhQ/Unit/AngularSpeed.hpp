// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class AngularSpeed : uint_least8_t {
  RadianPerSecond,
  RadianPerMinute,
  RadianPerHour,
  DegreePerSecond,
  DegreePerMinute,
  DegreePerHour,
  RevolutionPerSecond,
  RevolutionPerMinute,
  RevolutionPerHour
};

} // namespace Unit

template <> const std::map<Unit::AngularSpeed, std::string> abbreviations<Unit::AngularSpeed>{
  {Unit::AngularSpeed::RadianPerSecond, "rad/s"},
  {Unit::AngularSpeed::RadianPerMinute, "rad/min"},
  {Unit::AngularSpeed::RadianPerHour, "rad/hr"},
  {Unit::AngularSpeed::DegreePerSecond, "deg/s"},
  {Unit::AngularSpeed::DegreePerMinute, "deg/min"},
  {Unit::AngularSpeed::DegreePerHour, "deg/hr"},
  {Unit::AngularSpeed::RevolutionPerSecond, "rev/s"},
  {Unit::AngularSpeed::RevolutionPerMinute, "rev/min"},
  {Unit::AngularSpeed::RevolutionPerHour, "rev/hr"},
};

template <> const std::unordered_map<std::string, Unit::AngularSpeed> spellings<Unit::AngularSpeed>{
  {"rad/s", Unit::AngularSpeed::RadianPerSecond},
  {"rad/sec", Unit::AngularSpeed::RadianPerSecond},
  {"rad/min", Unit::AngularSpeed::RadianPerMinute},
  {"rad/hr", Unit::AngularSpeed::RadianPerHour},
  {"°/s", Unit::AngularSpeed::DegreePerSecond},
  {"°/sec", Unit::AngularSpeed::DegreePerSecond},
  {"deg/s", Unit::AngularSpeed::DegreePerSecond},
  {"deg/sec", Unit::AngularSpeed::DegreePerSecond},
  {"°/min", Unit::AngularSpeed::DegreePerMinute},
  {"deg/min", Unit::AngularSpeed::DegreePerMinute},
  {"°/hr", Unit::AngularSpeed::DegreePerHour},
  {"deg/hr", Unit::AngularSpeed::DegreePerHour},
  {"rev/s", Unit::AngularSpeed::RevolutionPerSecond},
  {"rev/sec", Unit::AngularSpeed::RevolutionPerSecond},
  {"rev/min", Unit::AngularSpeed::RevolutionPerMinute},
  {"rev/hr", Unit::AngularSpeed::RevolutionPerHour}
};

template <> const std::map<System, Unit::AngularSpeed> consistent_units<Unit::AngularSpeed>{
  {System::MetreKilogramSecondKelvin, Unit::AngularSpeed::RadianPerSecond},
  {System::MillimetreGramSecondKelvin, Unit::AngularSpeed::RadianPerSecond},
  {System::FootPoundSecondRankine, Unit::AngularSpeed::RadianPerSecond},
  {System::InchPoundSecondRankine, Unit::AngularSpeed::RadianPerSecond}
};

template <> constexpr const Unit::AngularSpeed standard_unit<Unit::AngularSpeed>{Unit::AngularSpeed::RadianPerSecond};

template <> constexpr const Dimension::Set dimension<Unit::AngularSpeed>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{-1}}};

template <> const std::map<Unit::AngularSpeed, std::map<Unit::AngularSpeed, std::function<void(std::vector<double>&)>>> conversions<Unit::AngularSpeed>{
  {Unit::AngularSpeed::RadianPerSecond, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::vector<double>& values)->void{}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 180.0 / Pi;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 10800.0 / Pi;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 648000.0 / Pi;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.5 / Pi;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 30.0 / Pi;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1800.0 / Pi;});}}
  }},
  {Unit::AngularSpeed::RadianPerMinute, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::vector<double>& values)->void{}},
    {Unit::AngularSpeed::RadianPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3.0 / Pi;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 180.0 / Pi;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 10800.0 / Pi;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 120.0 * Pi;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.5 / Pi;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 30.0 / Pi;});}}
  }},
  {Unit::AngularSpeed::RadianPerHour, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::vector<double>& values)->void{}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.05 / Pi;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3.0 / Pi;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 180.0 / Pi;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 7200.0 * Pi;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 120.0 * Pi;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.5 / Pi;});}}
  }},
  {Unit::AngularSpeed::DegreePerSecond, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 180.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 3.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 20.0 * Pi;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::vector<double>& values)->void{}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 360.0;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 6.0;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 10.0;});}}
  }},
  {Unit::AngularSpeed::DegreePerMinute, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 10800.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 180.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 3.0;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::vector<double>& values)->void{}},
    {Unit::AngularSpeed::DegreePerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 21600.0;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 360.0;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 6.0;});}}
  }},
  {Unit::AngularSpeed::DegreePerHour, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 648000.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 10800.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 180.0;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::vector<double>& values)->void{}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1296000.0;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 21600.0;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 360.0;});}}
  }},
  {Unit::AngularSpeed::RevolutionPerSecond, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 2.0 * Pi;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 120.0 * Pi;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 7200.0 * Pi;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 360.0;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 21600.0;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1296000.0;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::vector<double>& values)->void{}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}}
  }},
  {Unit::AngularSpeed::RevolutionPerMinute, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 30.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 2.0 * Pi;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 120.0 * Pi;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 6.0;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 360.0;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 21600.0;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::vector<double>& values)->void{}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}}
  }},
  {Unit::AngularSpeed::RevolutionPerHour, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 1800.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 30.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 2.0 * Pi;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.1;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 6.0;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 360.0;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
