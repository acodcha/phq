// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class AngularAcceleration : uint_least8_t {
  RadianPerSquareSecond,
  RadianPerSquareMinute,
  RadianPerSquareHour,
  DegreePerSquareSecond,
  DegreePerSquareMinute,
  DegreePerSquareHour,
  RevolutionPerSquareSecond,
  RevolutionPerSquareMinute,
  RevolutionPerSquareHour
};

} // namespace Unit

template <> const std::map<Unit::AngularAcceleration, std::string> abbreviations<Unit::AngularAcceleration>{
  {Unit::AngularAcceleration::RadianPerSquareSecond, "rad/s^2"},
  {Unit::AngularAcceleration::RadianPerSquareMinute, "rad/min^2"},
  {Unit::AngularAcceleration::RadianPerSquareHour, "rad/hr^2"},
  {Unit::AngularAcceleration::DegreePerSquareSecond, "deg/s^2"},
  {Unit::AngularAcceleration::DegreePerSquareMinute, "deg/min^2"},
  {Unit::AngularAcceleration::DegreePerSquareHour, "deg/hr^2"},
  {Unit::AngularAcceleration::RevolutionPerSquareSecond, "rev/s^2"},
  {Unit::AngularAcceleration::RevolutionPerSquareMinute, "rev/min^2"},
  {Unit::AngularAcceleration::RevolutionPerSquareHour, "rev/hr^2"},
};

template <> const std::unordered_map<std::string, Unit::AngularAcceleration> spellings<Unit::AngularAcceleration>{
  {"rad/s^2", Unit::AngularAcceleration::RadianPerSquareSecond},
  {"rad/s2", Unit::AngularAcceleration::RadianPerSquareSecond},
  {"rad/s/s", Unit::AngularAcceleration::RadianPerSquareSecond},
  {"rad/sec^2", Unit::AngularAcceleration::RadianPerSquareSecond},
  {"rad/sec2", Unit::AngularAcceleration::RadianPerSquareSecond},
  {"rad/sec/sec", Unit::AngularAcceleration::RadianPerSquareSecond},
  {"rad/min^2", Unit::AngularAcceleration::RadianPerSquareMinute},
  {"rad/min2", Unit::AngularAcceleration::RadianPerSquareMinute},
  {"rad/min/min", Unit::AngularAcceleration::RadianPerSquareMinute},
  {"rad/hr^2", Unit::AngularAcceleration::RadianPerSquareHour},
  {"rad/hr2", Unit::AngularAcceleration::RadianPerSquareHour},
  {"rad/hr/hr", Unit::AngularAcceleration::RadianPerSquareHour},
  {"°/s^2", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"°/s2", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"°/s/s", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"°/sec^2", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"°/sec2", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"°/sec/sec", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"deg/s^2", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"deg/s2", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"deg/s/s", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"deg/sec^2", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"deg/sec2", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"deg/sec/sec", Unit::AngularAcceleration::DegreePerSquareSecond},
  {"°/min^2", Unit::AngularAcceleration::DegreePerSquareMinute},
  {"°/min2", Unit::AngularAcceleration::DegreePerSquareMinute},
  {"°/min/min", Unit::AngularAcceleration::DegreePerSquareMinute},
  {"deg/min^2", Unit::AngularAcceleration::DegreePerSquareMinute},
  {"deg/min2", Unit::AngularAcceleration::DegreePerSquareMinute},
  {"deg/min/min", Unit::AngularAcceleration::DegreePerSquareMinute},
  {"°/hr^2", Unit::AngularAcceleration::DegreePerSquareHour},
  {"°/hr2", Unit::AngularAcceleration::DegreePerSquareHour},
  {"°/hr/hr", Unit::AngularAcceleration::DegreePerSquareHour},
  {"deg/hr^2", Unit::AngularAcceleration::DegreePerSquareHour},
  {"deg/hr2", Unit::AngularAcceleration::DegreePerSquareHour},
  {"deg/hr/hr", Unit::AngularAcceleration::DegreePerSquareHour},
  {"rev/s^2", Unit::AngularAcceleration::RevolutionPerSquareSecond},
  {"rev/s2", Unit::AngularAcceleration::RevolutionPerSquareSecond},
  {"rev/s/s", Unit::AngularAcceleration::RevolutionPerSquareSecond},
  {"rev/sec^2", Unit::AngularAcceleration::RevolutionPerSquareSecond},
  {"rev/sec2", Unit::AngularAcceleration::RevolutionPerSquareSecond},
  {"rev/sec/sec", Unit::AngularAcceleration::RevolutionPerSquareSecond},
  {"rev/min^2", Unit::AngularAcceleration::RevolutionPerSquareMinute},
  {"rev/min2", Unit::AngularAcceleration::RevolutionPerSquareMinute},
  {"rev/min/min", Unit::AngularAcceleration::RevolutionPerSquareMinute},
  {"rev/hr^2", Unit::AngularAcceleration::RevolutionPerSquareHour},
  {"rev/hr2", Unit::AngularAcceleration::RevolutionPerSquareHour},
  {"rev/hr/hr", Unit::AngularAcceleration::RevolutionPerSquareHour}
};

template <> const std::map<System, Unit::AngularAcceleration> consistent_units<Unit::AngularAcceleration>{
  {System::MetreKilogramSecondKelvin, Unit::AngularAcceleration::RadianPerSquareSecond},
  {System::MillimetreGramSecondKelvin, Unit::AngularAcceleration::RadianPerSquareSecond},
  {System::FootPoundSecondRankine, Unit::AngularAcceleration::RadianPerSquareSecond},
  {System::InchPoundSecondRankine, Unit::AngularAcceleration::RadianPerSquareSecond}
};

template <> constexpr const Unit::AngularAcceleration standard_unit<Unit::AngularAcceleration>{Unit::AngularAcceleration::RadianPerSquareSecond};

template <> constexpr const Dimension::Set dimension<Unit::AngularAcceleration>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{-2}}};

template <> const std::map<Unit::AngularAcceleration, std::map<Unit::AngularAcceleration, std::function<void(std::vector<double>&)>>> conversions<Unit::AngularAcceleration>{
  {Unit::AngularAcceleration::RadianPerSquareSecond, {
    {Unit::AngularAcceleration::RadianPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularAcceleration::RadianPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12960000.0;});}},
    {Unit::AngularAcceleration::DegreePerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 180.0 / Pi;});}},
    {Unit::AngularAcceleration::DegreePerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 648000.0 / Pi;});}},
    {Unit::AngularAcceleration::DegreePerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 2332800000.0 / Pi;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.5 / Pi;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1800.0 / Pi;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 6480000.0 / Pi;});}}
  }},
  {Unit::AngularAcceleration::RadianPerSquareMinute, {
    {Unit::AngularAcceleration::RadianPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularAcceleration::RadianPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}},
    {Unit::AngularAcceleration::DegreePerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.05 / Pi;});}},
    {Unit::AngularAcceleration::DegreePerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 180.0 / Pi;});}},
    {Unit::AngularAcceleration::DegreePerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 648000.0 / Pi;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 7200.0 * Pi;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.5 / Pi;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1800.0 / Pi;});}}
  }},
  {Unit::AngularAcceleration::RadianPerSquareHour, {
    {Unit::AngularAcceleration::RadianPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12960000.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularAcceleration::DegreePerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 72000.0 * Pi;});}},
    {Unit::AngularAcceleration::DegreePerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.05 / Pi;});}},
    {Unit::AngularAcceleration::DegreePerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 180.0 / Pi;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 25920000.0 * Pi;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 7200.0 * Pi;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.5 / Pi;});}}
  }},
  {Unit::AngularAcceleration::DegreePerSquareSecond, {
    {Unit::AngularAcceleration::RadianPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 180.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 20.0 * Pi;});}},
    {Unit::AngularAcceleration::RadianPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 72000.0 * Pi;});}},
    {Unit::AngularAcceleration::DegreePerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularAcceleration::DegreePerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}},
    {Unit::AngularAcceleration::DegreePerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12960000.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 360.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 10.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 36000.0;});}}
  }},
  {Unit::AngularAcceleration::DegreePerSquareMinute, {
    {Unit::AngularAcceleration::RadianPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 648000.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 180.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 20.0 * Pi;});}},
    {Unit::AngularAcceleration::DegreePerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularAcceleration::DegreePerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularAcceleration::DegreePerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1296000.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 360.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 10.0;});}}
  }},
  {Unit::AngularAcceleration::DegreePerSquareHour, {
    {Unit::AngularAcceleration::RadianPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 2332800000.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 648000.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 180.0;});}},
    {Unit::AngularAcceleration::DegreePerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12960000.0;});}},
    {Unit::AngularAcceleration::DegreePerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularAcceleration::DegreePerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularAcceleration::RevolutionPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 4665600000.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1296000.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 360.0;});}}
  }},
  {Unit::AngularAcceleration::RevolutionPerSquareSecond, {
    {Unit::AngularAcceleration::RadianPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 2.0 * Pi;});}},
    {Unit::AngularAcceleration::RadianPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 7200.0 * Pi;});}},
    {Unit::AngularAcceleration::RadianPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 25920000.0 * Pi;});}},
    {Unit::AngularAcceleration::DegreePerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 360.0;});}},
    {Unit::AngularAcceleration::DegreePerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1296000.0;});}},
    {Unit::AngularAcceleration::DegreePerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 4665600000.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularAcceleration::RevolutionPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12960000.0;});}}
  }},
  {Unit::AngularAcceleration::RevolutionPerSquareMinute, {
    {Unit::AngularAcceleration::RadianPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 1800.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 2.0 * Pi;});}},
    {Unit::AngularAcceleration::RadianPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 7200.0 * Pi;});}},
    {Unit::AngularAcceleration::DegreePerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.1;});}},
    {Unit::AngularAcceleration::DegreePerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 360.0;});}},
    {Unit::AngularAcceleration::DegreePerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1296000.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularAcceleration::RevolutionPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}}
  }},
  {Unit::AngularAcceleration::RevolutionPerSquareHour, {
    {Unit::AngularAcceleration::RadianPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 6480000.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= Pi / 1800.0;});}},
    {Unit::AngularAcceleration::RadianPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 2.0 * Pi;});}},
    {Unit::AngularAcceleration::DegreePerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 36000;});}},
    {Unit::AngularAcceleration::DegreePerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.1;});}},
    {Unit::AngularAcceleration::DegreePerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 360.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12960000.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareMinute, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularAcceleration::RevolutionPerSquareHour, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}
  }}
};

} // namespace PhQ
