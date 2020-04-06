// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

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

template <size_t size> const std::map<Unit::AngularSpeed, std::map<Unit::AngularSpeed, std::function<void(std::array<double, size>&)>>> conversions<Unit::AngularSpeed, size>{
  {Unit::AngularSpeed::RadianPerSecond, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 180.0 / M_PI;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 10800.0 / M_PI;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 648000.0 / M_PI;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.5 / M_PI;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 30.0 / M_PI;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1800.0 / M_PI;});}}}},
  {Unit::AngularSpeed::RadianPerMinute, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3.0 / M_PI;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 180.0 / M_PI;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 10800.0 / M_PI;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 120.0 * M_PI;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.5 / M_PI;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 30.0 / M_PI;});}}}},
  {Unit::AngularSpeed::RadianPerHour, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.05 / M_PI;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3.0 / M_PI;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 180.0 / M_PI;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 7200.0 * M_PI;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 120.0 * M_PI;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.5 / M_PI;});}}}},
  {Unit::AngularSpeed::DegreePerSecond, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= M_PI / 180.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= M_PI / 3.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 20.0 * M_PI;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 360.0;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 6.0;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 10.0;});}}}},
  {Unit::AngularSpeed::DegreePerMinute, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= M_PI / 10800.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= M_PI / 180.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= M_PI / 3.0;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 21600.0;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 360.0;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 6.0;});}}}},
  {Unit::AngularSpeed::DegreePerHour, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= M_PI / 648000.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= M_PI / 10800.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= M_PI / 180.0;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1296000.0;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 21600.0;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 360.0;});}}}},
  {Unit::AngularSpeed::RevolutionPerSecond, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 2.0 * M_PI;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 120.0 * M_PI;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 7200.0 * M_PI;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 360.0;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 21600.0;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1296000.0;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 3600.0;});}}}},
  {Unit::AngularSpeed::RevolutionPerMinute, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= M_PI / 30.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 2.0 * M_PI;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 120.0 * M_PI;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 6.0;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 360.0;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 21600.0;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 60.0;});}}}},
  {Unit::AngularSpeed::RevolutionPerHour, {
    {Unit::AngularSpeed::RadianPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= M_PI / 1800.0;});}},
    {Unit::AngularSpeed::RadianPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= M_PI / 30.0;});}},
    {Unit::AngularSpeed::RadianPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 2.0 * M_PI;});}},
    {Unit::AngularSpeed::DegreePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.1;});}},
    {Unit::AngularSpeed::DegreePerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 6.0;});}},
    {Unit::AngularSpeed::DegreePerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 360.0;});}},
    {Unit::AngularSpeed::RevolutionPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 3600.0;});}},
    {Unit::AngularSpeed::RevolutionPerMinute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 60.0;});}},
    {Unit::AngularSpeed::RevolutionPerHour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}}}
};

} // namespace PhQ
