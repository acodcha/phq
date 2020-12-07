// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Force : uint_least8_t {
  Newton,
  Micronewton,
  Pound
};

} // namespace Unit

template <> const std::map<Unit::Force, std::string> abbreviations<Unit::Force>{
  {Unit::Force::Newton, "N"},
  {Unit::Force::Micronewton, "μN"},
  {Unit::Force::Pound, "lbf"}
};

template <> const std::unordered_map<std::string, Unit::Force> spellings<Unit::Force>{
  {"N", Unit::Force::Newton},
  {"kg*m/s^2", Unit::Force::Newton},
  {"kg*m/s2", Unit::Force::Newton},
  {"μN", Unit::Force::Micronewton},
  {"uN", Unit::Force::Micronewton},
  {"g*mm/s^2", Unit::Force::Micronewton},
  {"g*mm/s2", Unit::Force::Micronewton},
  {"lbf", Unit::Force::Pound},
  {"lb", Unit::Force::Pound}
};

template <> const std::map<System, Unit::Force> consistent_units<Unit::Force>{
  {System::MetreKilogramSecondKelvin, Unit::Force::Newton},
  {System::MillimetreGramSecondKelvin, Unit::Force::Micronewton},
  {System::FootPoundSecondRankine, Unit::Force::Pound},
  {System::InchPoundSecondRankine, Unit::Force::Pound}
};

template <> constexpr const Unit::Force standard_unit<Unit::Force>{Unit::Force::Newton};

template <> constexpr const Dimension::Set dimension<Unit::Force>{Dimension::Set{Dimension::Length{1}, Dimension::Mass{1}, Dimension::Time{-2}}};

template <> const std::map<Unit::Force, std::map<Unit::Force, std::function<void(std::vector<double>&)>>> conversions<Unit::Force>{
  {Unit::Force::Newton, {
    {Unit::Force::Newton, [](std::vector<double>& values)->void{}},
    {Unit::Force::Micronewton, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0;});}},
    {Unit::Force::Pound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.45359237 * 9.80665;});}}
  }},
  {Unit::Force::Micronewton, {
    {Unit::Force::Newton, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000001;});}},
    {Unit::Force::Micronewton, [](std::vector<double>& values)->void{}},
    {Unit::Force::Pound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 453592.37 * 9.80665;});}}
  }},
  {Unit::Force::Pound, {
    {Unit::Force::Newton, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665;});}},
    {Unit::Force::Micronewton, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 453592.37 * 9.80665;});}},
    {Unit::Force::Pound, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
