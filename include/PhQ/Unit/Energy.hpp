// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Energy : uint_least8_t {
  Joule,
  Millijoule,
  Microjoule,
  Nanojoule,
  Kilojoule,
  Megajoule,
  Gigajoule,
  FootPound,
  InchPound
};

} // namespace Unit

template <> const std::map<Unit::Energy, std::string> abbreviations<Unit::Energy>{
  {Unit::Energy::Joule, "J"},
  {Unit::Energy::Millijoule, "mJ"},
  {Unit::Energy::Microjoule, "μJ"},
  {Unit::Energy::Nanojoule, "nJ"},
  {Unit::Energy::Kilojoule, "kJ"},
  {Unit::Energy::Megajoule, "MJ"},
  {Unit::Energy::Gigajoule, "GJ"},
  {Unit::Energy::FootPound, "ft·lbf"},
  {Unit::Energy::InchPound, "in·lbf"}
};

template <> const std::unordered_map<std::string, Unit::Energy> spellings<Unit::Energy>{
  {"J", Unit::Energy::Joule},
  {"N·m", Unit::Energy::Joule},
  {"N*m", Unit::Energy::Joule},
  {"kg·m^2/s^2", Unit::Energy::Joule},
  {"kg*m^2/s^2", Unit::Energy::Joule},
  {"kg·m2/s2", Unit::Energy::Joule},
  {"kg*m2/s2", Unit::Energy::Joule},
  {"mJ", Unit::Energy::Millijoule},
  {"μJ", Unit::Energy::Microjoule},
  {"uJ", Unit::Energy::Microjoule},
  {"nJ", Unit::Energy::Nanojoule},
  {"μN·mm", Unit::Energy::Nanojoule},
  {"μN*mm", Unit::Energy::Nanojoule},
  {"uN·mm", Unit::Energy::Nanojoule},
  {"uN*mm", Unit::Energy::Nanojoule},
  {"g·mm^2/s^2", Unit::Energy::Nanojoule},
  {"g*mm^2/s^2", Unit::Energy::Nanojoule},
  {"g·mm2/s2", Unit::Energy::Nanojoule},
  {"g*mm2/s2", Unit::Energy::Nanojoule},
  {"kJ", Unit::Energy::Kilojoule},
  {"MJ", Unit::Energy::Megajoule},
  {"GJ", Unit::Energy::Gigajoule},
  {"ft·lbf", Unit::Energy::FootPound},
  {"ft*lbf", Unit::Energy::FootPound},
  {"ft·lb", Unit::Energy::FootPound},
  {"ft*lb", Unit::Energy::FootPound},
  {"in·lbf", Unit::Energy::InchPound},
  {"in*lbf", Unit::Energy::InchPound},
  {"in·lb", Unit::Energy::InchPound},
  {"in*lb", Unit::Energy::InchPound}
};

template <> const std::map<System, Unit::Energy> consistent_units<Unit::Energy>{
  {System::MetreKilogramSecondKelvin, Unit::Energy::Joule},
  {System::MillimetreGramSecondKelvin, Unit::Energy::Nanojoule},
  {System::FootPoundSecondRankine, Unit::Energy::FootPound},
  {System::InchPoundSecondRankine, Unit::Energy::InchPound}
};

template <> constexpr const Unit::Energy standard_unit<Unit::Energy>{Unit::Energy::Joule};

template <> constexpr const Dimension::Set dimension<Unit::Energy>{Dimension::Set{Dimension::Length{2}, Dimension::Mass{1}, Dimension::Time{-2}}};

template <> const std::map<Unit::Energy, std::map<Unit::Energy, std::function<void(std::vector<double>&)>>> conversions<Unit::Energy>{
  {Unit::Energy::Joule, {
    {Unit::Energy::Joule, [](std::vector<double>& values)->void{}},
    {Unit::Energy::Millijoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Energy::Microjoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6;});}},
    {Unit::Energy::Nanojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9;});}},
    {Unit::Energy::Kilojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Energy::Megajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6;});}},
    {Unit::Energy::Gigajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9;});}},
    {Unit::Energy::FootPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::InchPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Energy::Millijoule, {
    {Unit::Energy::Joule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Energy::Millijoule, [](std::vector<double>& values)->void{}},
    {Unit::Energy::Microjoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Energy::Nanojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6;});}},
    {Unit::Energy::Kilojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6;});}},
    {Unit::Energy::Megajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9;});}},
    {Unit::Energy::Gigajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-12;});}},
    {Unit::Energy::FootPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e3 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::InchPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e3 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Energy::Microjoule, {
    {Unit::Energy::Joule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6;});}},
    {Unit::Energy::Millijoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Energy::Microjoule, [](std::vector<double>& values)->void{}},
    {Unit::Energy::Nanojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Energy::Kilojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9;});}},
    {Unit::Energy::Megajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-12;});}},
    {Unit::Energy::Gigajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-15;});}},
    {Unit::Energy::FootPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e6 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::InchPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e6 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Energy::Nanojoule, {
    {Unit::Energy::Joule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9;});}},
    {Unit::Energy::Millijoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6;});}},
    {Unit::Energy::Microjoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Energy::Nanojoule, [](std::vector<double>& values)->void{}},
    {Unit::Energy::Kilojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-12;});}},
    {Unit::Energy::Megajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-15;});}},
    {Unit::Energy::Gigajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-18;});}},
    {Unit::Energy::FootPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e9 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::InchPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e9 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Energy::Kilojoule, {
    {Unit::Energy::Joule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Energy::Millijoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6;});}},
    {Unit::Energy::Microjoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9;});}},
    {Unit::Energy::Nanojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e12;});}},
    {Unit::Energy::Kilojoule, [](std::vector<double>& values)->void{}},
    {Unit::Energy::Megajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Energy::Gigajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6;});}},
    {Unit::Energy::FootPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-3 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::InchPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-3 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Energy::Megajoule, {
    {Unit::Energy::Joule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6;});}},
    {Unit::Energy::Millijoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9;});}},
    {Unit::Energy::Microjoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e12;});}},
    {Unit::Energy::Nanojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e15;});}},
    {Unit::Energy::Kilojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Energy::Megajoule, [](std::vector<double>& values)->void{}},
    {Unit::Energy::Gigajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3;});}},
    {Unit::Energy::FootPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-6 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::InchPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-6 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Energy::Gigajoule, {
    {Unit::Energy::Joule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9;});}},
    {Unit::Energy::Millijoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e12;});}},
    {Unit::Energy::Microjoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e15;});}},
    {Unit::Energy::Nanojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e18;});}},
    {Unit::Energy::Kilojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6;});}},
    {Unit::Energy::Megajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3;});}},
    {Unit::Energy::Gigajoule, [](std::vector<double>& values)->void{}},
    {Unit::Energy::FootPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-9 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::InchPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.0e-9 * 0.0254 * 0.45359237 * 9.80665;});}}
  }},
  {Unit::Energy::FootPound, {
    {Unit::Energy::Joule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Millijoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Microjoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Nanojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Kilojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Megajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Gigajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9 * 0.3048 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::FootPound, [](std::vector<double>& values)->void{}},
    {Unit::Energy::InchPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12.0;});}}
  }},
  {Unit::Energy::InchPound, {
    {Unit::Energy::Joule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Millijoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e3 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Microjoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e6 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Nanojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e9 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Kilojoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-3 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Megajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-6 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::Gigajoule, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.0e-9 * 0.0254 * 0.45359237 * 9.80665;});}},
    {Unit::Energy::FootPound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12.0;});}},
    {Unit::Energy::InchPound, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
