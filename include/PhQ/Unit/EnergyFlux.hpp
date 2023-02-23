// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class EnergyFlux : int_least8_t {
  WattPerSquareMetre,
  NanowattPerSquareMillimetre,
  FootPoundPerSquareFootPerSecond,
  InchPoundPerSquareInchPerSecond
};

} // namespace Unit

template <> const std::map<Unit::EnergyFlux, std::string> abbreviations<Unit::EnergyFlux>{
  {Unit::EnergyFlux::WattPerSquareMetre, "W/m^2"},
  {Unit::EnergyFlux::NanowattPerSquareMillimetre, "nW/mm^2"},
  {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, "ft·lbf/ft^2/s"},
  {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, "in·lbf/in^2/s"}
};

template <> const std::unordered_map<std::string, Unit::EnergyFlux> spellings<Unit::EnergyFlux>{
  {"W/m^2", Unit::EnergyFlux::WattPerSquareMetre},
  {"W/m2", Unit::EnergyFlux::WattPerSquareMetre},
  {"J/(m^2·s)", Unit::EnergyFlux::WattPerSquareMetre},
  {"J/(m^2*s)", Unit::EnergyFlux::WattPerSquareMetre},
  {"J/(m2·s)", Unit::EnergyFlux::WattPerSquareMetre},
  {"J/(m2*s)", Unit::EnergyFlux::WattPerSquareMetre},
  {"J/m^2/s", Unit::EnergyFlux::WattPerSquareMetre},
  {"J/m2/s", Unit::EnergyFlux::WattPerSquareMetre},
  {"N/(m·s)", Unit::EnergyFlux::WattPerSquareMetre},
  {"N/(m*s)", Unit::EnergyFlux::WattPerSquareMetre},
  {"N/m/s", Unit::EnergyFlux::WattPerSquareMetre},
  {"kg/s^3", Unit::EnergyFlux::WattPerSquareMetre},
  {"kg/s3", Unit::EnergyFlux::WattPerSquareMetre},
  {"nW/mm^2", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"nW/mm2", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"nJ/(mm^2·s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"nJ/(mm^2*s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"nJ/(mm2·s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"nJ/(mm2*s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"nJ/mm^2/s", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"nJ/mm2/s", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"μN/(mm·s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"μN/(mm*s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"μN/mm/s", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"uN/(mm·s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"uN/(mm*s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"uN/mm/s", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"g/s^3", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"g/s3", Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {"ft·lbf/(ft^2·s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"ft·lbf/(ft2·s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"ft*lbf/(ft^2*s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"ft*lbf/(ft2*s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"ft·lbf/ft^2/s", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"ft·lbf/ft2/s", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"ft*lbf/ft^2/s", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"ft*lbf/ft2/s", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"lbf/(ft·s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"lbf/(ft*s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"lbf/ft/s", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"slug/s^3", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"slug/s3", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {"in·lbf/(in^2·s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"in·lbf/(in2·s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"in*lbf/(in^2*s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"in*lbf/(in2*s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"in·lbf/in^2/s", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"in·lbf/in2/s", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"in*lbf/in^2/s", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"in*lbf/in2/s", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"lbf/(in·s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"lbf/(in*s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"lbf/in/s", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"slinch/s^3", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
  {"slinch/s3", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond}
};

template <> const std::map<System, Unit::EnergyFlux> consistent_units<Unit::EnergyFlux>{
  {System::MetreKilogramSecondKelvin, Unit::EnergyFlux::WattPerSquareMetre},
  {System::MillimetreGramSecondKelvin, Unit::EnergyFlux::NanowattPerSquareMillimetre},
  {System::FootPoundSecondRankine, Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
  {System::InchPoundSecondRankine, Unit::EnergyFlux::InchPoundPerSquareInchPerSecond}
};

template <> constexpr const Unit::EnergyFlux standard_unit<Unit::EnergyFlux>{Unit::EnergyFlux::WattPerSquareMetre};

template <> constexpr const Dimension::Set dimension<Unit::EnergyFlux>{Dimension::Set{Dimension::Length{0}, Dimension::Mass{1}, Dimension::Time{-3}}};

template <> const std::map<Unit::EnergyFlux, std::map<Unit::EnergyFlux, std::function<void(std::vector<double>&)>>> conversions<Unit::EnergyFlux>{
  {Unit::EnergyFlux::WattPerSquareMetre, {
    {Unit::EnergyFlux::WattPerSquareMetre, [](std::vector<double>& values)->void{}},
    {Unit::EnergyFlux::NanowattPerSquareMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.3048 / (0.45359237 * 9.80665);});}},
    {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0254 / (0.45359237 * 9.80665);});}}
  }},
  {Unit::EnergyFlux::NanowattPerSquareMillimetre, {
    {Unit::EnergyFlux::WattPerSquareMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::EnergyFlux::NanowattPerSquareMillimetre, [](std::vector<double>& values)->void{}},
    {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0003048 / (0.45359237 * 9.80665);});}},
    {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0000254 / (0.45359237 * 9.80665);});}}
  }},
  {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, {
    {Unit::EnergyFlux::WattPerSquareMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / 0.3048;});}},
    {Unit::EnergyFlux::NanowattPerSquareMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 453.59237 * 9.80665 / 0.3048;});}},
    {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, [](std::vector<double>& values)->void{}},
    {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12.0;});}}
  }},
  {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, {
    {Unit::EnergyFlux::WattPerSquareMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / 0.0254;});}},
    {Unit::EnergyFlux::NanowattPerSquareMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 453.59237 * 9.80665 / 0.0254;});}},
    {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12.0;});}},
    {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
