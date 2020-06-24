// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Power : uint_least8_t {
  Watt,
  Milliwatt,
  Microwatt,
  Nanowatt,
  Kilowatt,
  Megawatt,
  Gigawatt,
  FootPoundPerSecond,
  InchPoundPerSecond
};

} // namespace Unit

template <> const std::map<Unit::Power, std::string> abbreviations<Unit::Power>{
  {Unit::Power::Watt, "W"},
  {Unit::Power::Milliwatt, "mW"},
  {Unit::Power::Microwatt, "μW"},
  {Unit::Power::Nanowatt, "nW"},
  {Unit::Power::Kilowatt, "kW"},
  {Unit::Power::Megawatt, "MW"},
  {Unit::Power::Gigawatt, "GW"},
  {Unit::Power::FootPoundPerSecond, "ft·lbf/s"},
  {Unit::Power::InchPoundPerSecond, "in·lbf/s"}
};

template <> const std::unordered_map<std::string, Unit::Power> spellings<Unit::Power>{
  {"W", Unit::Power::Watt},
  {"N·m/s", Unit::Power::Watt},
  {"N*m/s", Unit::Power::Watt},
  {"kg·m^2/s^3", Unit::Power::Watt},
  {"kg*m^2/s^3", Unit::Power::Watt},
  {"kg·m2/s3", Unit::Power::Watt},
  {"kg*m2/s3", Unit::Power::Watt},
  {"mW", Unit::Power::Milliwatt},
  {"μW", Unit::Power::Microwatt},
  {"uW", Unit::Power::Microwatt},
  {"nW", Unit::Power::Nanowatt},
  {"μN·mm/s", Unit::Power::Nanowatt},
  {"μN*mm/s", Unit::Power::Nanowatt},
  {"uN·mm/s", Unit::Power::Nanowatt},
  {"uN*mm/s", Unit::Power::Nanowatt},
  {"g·mm^2/s^3", Unit::Power::Nanowatt},
  {"g*mm^2/s^3", Unit::Power::Nanowatt},
  {"g·mm2/s3", Unit::Power::Nanowatt},
  {"g*mm2/s3", Unit::Power::Nanowatt},
  {"kW", Unit::Power::Kilowatt},
  {"MW", Unit::Power::Megawatt},
  {"GW", Unit::Power::Gigawatt},
  {"ft·lbf/s", Unit::Power::FootPoundPerSecond},
  {"ft*lbf/s", Unit::Power::FootPoundPerSecond},
  {"ft·lb/s", Unit::Power::FootPoundPerSecond},
  {"ft*lb/s", Unit::Power::FootPoundPerSecond},
  {"in·lbf/s", Unit::Power::InchPoundPerSecond},
  {"in*lbf/s", Unit::Power::InchPoundPerSecond},
  {"in·lb/s", Unit::Power::InchPoundPerSecond},
  {"in*lb/s", Unit::Power::InchPoundPerSecond}
};

template <> const std::map<System, Unit::Power> consistent_units<Unit::Power>{
  {System::MetreKilogramSecondKelvin, Unit::Power::Watt},
  {System::MillimetreGramSecondKelvin, Unit::Power::Nanowatt},
  {System::FootPoundSecondRankine, Unit::Power::FootPoundPerSecond},
  {System::InchPoundSecondRankine, Unit::Power::InchPoundPerSecond}
};

template <> constexpr const Unit::Power standard_unit<Unit::Power>{Unit::Power::Watt};

template <> constexpr const Dimension::Set dimension<Unit::Power>{Dimension::Set{Dimension::Length{2}, Dimension::Mass{1}, Dimension::Time{-3}}};

template <> const std::map<Unit::Power, std::map<Unit::Power, std::function<void(std::vector<double>&)>>> conversions<Unit::Power>{
  {Unit::Power::Watt, {
    {Unit::Power::Watt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Power::Milliwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Power::Microwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6;});}},
    {Unit::Power::Nanowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9;});}},
    {Unit::Power::Kilowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Power::Megawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6;});}},
    {Unit::Power::Gigawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9;});}},
    {Unit::Power::FootPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::InchPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Power::Milliwatt, {
    {Unit::Power::Watt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Power::Milliwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Power::Microwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Power::Nanowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6;});}},
    {Unit::Power::Kilowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6;});}},
    {Unit::Power::Megawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9;});}},
    {Unit::Power::Gigawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-12;});}},
    {Unit::Power::FootPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e3 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::InchPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e3 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Power::Microwatt, {
    {Unit::Power::Watt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6;});}},
    {Unit::Power::Milliwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Power::Microwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Power::Nanowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Power::Kilowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9;});}},
    {Unit::Power::Megawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-12;});}},
    {Unit::Power::Gigawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-15;});}},
    {Unit::Power::FootPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e6 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::InchPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e6 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Power::Nanowatt, {
    {Unit::Power::Watt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9;});}},
    {Unit::Power::Milliwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6;});}},
    {Unit::Power::Microwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Power::Nanowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Power::Kilowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-12;});}},
    {Unit::Power::Megawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-15;});}},
    {Unit::Power::Gigawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-18;});}},
    {Unit::Power::FootPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e9 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::InchPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e9 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Power::Kilowatt, {
    {Unit::Power::Watt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Power::Milliwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6;});}},
    {Unit::Power::Microwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9;});}},
    {Unit::Power::Nanowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e12;});}},
    {Unit::Power::Kilowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Power::Megawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Power::Gigawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6;});}},
    {Unit::Power::FootPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-3 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::InchPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-3 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Power::Megawatt, {
    {Unit::Power::Watt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6;});}},
    {Unit::Power::Milliwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9;});}},
    {Unit::Power::Microwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e12;});}},
    {Unit::Power::Nanowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e15;});}},
    {Unit::Power::Kilowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Power::Megawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Power::Gigawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Power::FootPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-6 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::InchPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-6 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Power::Gigawatt, {
    {Unit::Power::Watt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9;});}},
    {Unit::Power::Milliwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e12;});}},
    {Unit::Power::Microwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e15;});}},
    {Unit::Power::Nanowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e18;});}},
    {Unit::Power::Kilowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6;});}},
    {Unit::Power::Megawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Power::Gigawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Power::FootPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-9 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::InchPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-9 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Power::FootPoundPerSecond, {
    {Unit::Power::Watt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Milliwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Microwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Nanowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Kilowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Megawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Gigawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Power::FootPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Power::InchPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12.0;});}}
  }},
  {Unit::Power::InchPoundPerSecond, {
    {Unit::Power::Watt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Milliwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Microwatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Nanowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Kilowatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Megawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Power::Gigawatt, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Power::FootPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12.0;});}},
    {Unit::Power::InchPoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}
  }}
};

} // namespace PhQ
