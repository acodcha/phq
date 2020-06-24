// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class MassRate : uint_least8_t {
  KilogramPerSecond,
  GramPerSecond,
  SlugPerSecond,
  SlinchPerSecond,
  PoundPerSecond
};

} // namespace Unit

template <> const std::map<Unit::MassRate, std::string> abbreviations<Unit::MassRate>{
  {Unit::MassRate::KilogramPerSecond, "kg/s"},
  {Unit::MassRate::GramPerSecond, "g/s"},
  {Unit::MassRate::SlugPerSecond, "slug/s"},
  {Unit::MassRate::SlinchPerSecond, "slinch/s"},
  {Unit::MassRate::PoundPerSecond, "lbm/s"}
};

template <> const std::unordered_map<std::string, Unit::MassRate> spellings<Unit::MassRate>{
  {"kg/s", Unit::MassRate::KilogramPerSecond},
  {"kg/sec", Unit::MassRate::KilogramPerSecond},
  {"g/s", Unit::MassRate::GramPerSecond},
  {"g/sec", Unit::MassRate::GramPerSecond},
  {"slug/s", Unit::MassRate::SlugPerSecond},
  {"slug/sec", Unit::MassRate::SlugPerSecond},
  {"slinch/s", Unit::MassRate::SlinchPerSecond},
  {"slinch/sec", Unit::MassRate::SlinchPerSecond},
  {"lbm/s", Unit::MassRate::PoundPerSecond},
  {"lbm/sec", Unit::MassRate::PoundPerSecond},
  {"lb/s", Unit::MassRate::PoundPerSecond},
  {"lb/sec", Unit::MassRate::PoundPerSecond}
};

template <> const std::map<System, Unit::MassRate> consistent_units<Unit::MassRate>{
  {System::MetreKilogramSecondKelvin, Unit::MassRate::KilogramPerSecond},
  {System::MillimetreGramSecondKelvin, Unit::MassRate::GramPerSecond},
  {System::FootPoundSecondRankine, Unit::MassRate::SlugPerSecond},
  {System::InchPoundSecondRankine, Unit::MassRate::SlinchPerSecond}
};

template <> constexpr const Unit::MassRate standard_unit<Unit::MassRate>{Unit::MassRate::KilogramPerSecond};

template <> constexpr const Dimension::Set dimension<Unit::MassRate>{Dimension::Set{Dimension::Length{0}, Dimension::Mass{1}, Dimension::Time{-1}}};

template <> const std::map<Unit::MassRate, std::map<Unit::MassRate, std::function<void(std::vector<double>&)>>> conversions<Unit::MassRate>{
  {Unit::MassRate::KilogramPerSecond, {
    {Unit::MassRate::KilogramPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MassRate::GramPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::MassRate::SlugPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.3048 / (0.45359237 * 9.80665);});}},
    {Unit::MassRate::SlinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0254 / (0.45359237 * 9.80665);});}},
    {Unit::MassRate::PoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.45359237;});}}
  }},
  {Unit::MassRate::GramPerSecond, {
    {Unit::MassRate::KilogramPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::MassRate::GramPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MassRate::SlugPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0003048 / (0.45359237 * 9.80665);});}},
    {Unit::MassRate::SlinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0000254 / (0.45359237 * 9.80665);});}},
    {Unit::MassRate::PoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 453.59237;});}}
  }},
  {Unit::MassRate::SlugPerSecond, {
    {Unit::MassRate::KilogramPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / 0.3048;});}},
    {Unit::MassRate::GramPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 453.59237 * 9.80665 / 0.3048;});}},
    {Unit::MassRate::SlugPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MassRate::SlinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12.0;});}},
    {Unit::MassRate::PoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 9.80665 / 0.3048;});}}
  }},
  {Unit::MassRate::SlinchPerSecond, {
    {Unit::MassRate::KilogramPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / 0.0254;});}},
    {Unit::MassRate::GramPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 453.59237 * 9.80665 / 0.0254;});}},
    {Unit::MassRate::SlugPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12.0;});}},
    {Unit::MassRate::SlinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MassRate::PoundPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 9.80665 / 0.0254;});}}
  }},
  {Unit::MassRate::PoundPerSecond, {
    {Unit::MassRate::KilogramPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237;});}},
    {Unit::MassRate::GramPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 453.59237;});}},
    {Unit::MassRate::SlugPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.3048 / 9.80665;});}},
    {Unit::MassRate::SlinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0254 / 9.80665;});}},
    {Unit::MassRate::SlinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}
  }}
};

} // namespace PhQ
