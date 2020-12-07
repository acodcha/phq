// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Frequency : uint_least8_t {
  Hertz,
  Kilohertz,
  Megahertz,
  Gigahertz
};

} // namespace Unit

template <> const std::map<Unit::Frequency, std::string> abbreviations<Unit::Frequency>{
  {Unit::Frequency::Hertz, "Hz"},
  {Unit::Frequency::Kilohertz, "kHz"},
  {Unit::Frequency::Megahertz, "MHz"},
  {Unit::Frequency::Gigahertz, "GHz"}
};

template <> const std::unordered_map<std::string, Unit::Frequency> spellings<Unit::Frequency>{
  {"Hz", Unit::Frequency::Hertz},
  {"1/s", Unit::Frequency::Hertz},
  {"/s", Unit::Frequency::Hertz},
  {"kHz", Unit::Frequency::Kilohertz},
  {"MHz", Unit::Frequency::Megahertz},
  {"GHz", Unit::Frequency::Gigahertz}
};

template <> const std::map<System, Unit::Frequency> consistent_units<Unit::Frequency>{
  {System::MetreKilogramSecondKelvin, Unit::Frequency::Hertz},
  {System::MillimetreGramSecondKelvin, Unit::Frequency::Hertz},
  {System::FootPoundSecondRankine, Unit::Frequency::Hertz},
  {System::InchPoundSecondRankine, Unit::Frequency::Hertz}
};

template <> constexpr const Unit::Frequency standard_unit<Unit::Frequency>{Unit::Frequency::Hertz};

template <> constexpr const Dimension::Set dimension<Unit::Frequency>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{-1}}};

template <> const std::map<Unit::Frequency, std::map<Unit::Frequency, std::function<void(std::vector<double>&)>>> conversions<Unit::Frequency>{
  {Unit::Frequency::Hertz, {
    {Unit::Frequency::Hertz, [](std::vector<double>& values)->void{}},
    {Unit::Frequency::Kilohertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::Frequency::Megahertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000001;});}},
    {Unit::Frequency::Gigahertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000000001;});}}
  }},
  {Unit::Frequency::Kilohertz, {
    {Unit::Frequency::Hertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::Frequency::Kilohertz, [](std::vector<double>& values)->void{}},
    {Unit::Frequency::Megahertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::Frequency::Gigahertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000001;});}}
  }},
  {Unit::Frequency::Megahertz, {
    {Unit::Frequency::Hertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0;});}},
    {Unit::Frequency::Kilohertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::Frequency::Megahertz, [](std::vector<double>& values)->void{}},
    {Unit::Frequency::Gigahertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}}
  }},
  {Unit::Frequency::Gigahertz, {
    {Unit::Frequency::Hertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000000.0;});}},
    {Unit::Frequency::Kilohertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0;});}},
    {Unit::Frequency::Megahertz, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::Frequency::Gigahertz, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
