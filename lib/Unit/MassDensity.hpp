// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class MassDensity : uint_least8_t {
  KilogramPerCubicMetre,
  GramPerCubicMillimetre,
  SlugPerCubicFoot,
  SlinchPerCubicInch,
  PoundPerCubicFoot,
  PoundPerCubicInch
};

} // namespace Unit

template <> const std::map<Unit::MassDensity, std::string> abbreviations<Unit::MassDensity>{
  {Unit::MassDensity::KilogramPerCubicMetre, "kg/m^3"},
  {Unit::MassDensity::GramPerCubicMillimetre, "g/mm^3"},
  {Unit::MassDensity::SlugPerCubicFoot, "slug/ft^3"},
  {Unit::MassDensity::SlinchPerCubicInch, "slinch/in^3"},
  {Unit::MassDensity::PoundPerCubicFoot, "lbm/ft^3"},
  {Unit::MassDensity::PoundPerCubicInch, "lbm/in^3"}
};

template <> const std::unordered_map<std::string, Unit::MassDensity> spellings<Unit::MassDensity>{
  {"kg/m^3", Unit::MassDensity::KilogramPerCubicMetre},
  {"kg/m3", Unit::MassDensity::KilogramPerCubicMetre},
  {"kg/m/m/m", Unit::MassDensity::KilogramPerCubicMetre},
  {"g/mm^3", Unit::MassDensity::GramPerCubicMillimetre},
  {"g/mm3", Unit::MassDensity::GramPerCubicMillimetre},
  {"g/mm/mm/mm", Unit::MassDensity::GramPerCubicMillimetre},
  {"slug/ft^3", Unit::MassDensity::SlugPerCubicFoot},
  {"slug/ft3", Unit::MassDensity::SlugPerCubicFoot},
  {"slug/ft/ft/ft", Unit::MassDensity::SlugPerCubicFoot},
  {"slinch/in^3", Unit::MassDensity::SlinchPerCubicInch},
  {"slinch/in3", Unit::MassDensity::SlinchPerCubicInch},
  {"slinch/in/in/in", Unit::MassDensity::SlinchPerCubicInch},
  {"lbm/ft^3", Unit::MassDensity::PoundPerCubicFoot},
  {"lbm/ft3", Unit::MassDensity::PoundPerCubicFoot},
  {"lbm/ft/ft/ft", Unit::MassDensity::PoundPerCubicFoot},
  {"lb/ft^3", Unit::MassDensity::PoundPerCubicFoot},
  {"lb/ft3", Unit::MassDensity::PoundPerCubicFoot},
  {"lb/ft/ft/ft", Unit::MassDensity::PoundPerCubicFoot},
  {"lbm/in^3", Unit::MassDensity::PoundPerCubicInch},
  {"lbm/in3", Unit::MassDensity::PoundPerCubicInch},
  {"lbm/in/in/in", Unit::MassDensity::PoundPerCubicInch},
  {"lb/in^3", Unit::MassDensity::PoundPerCubicInch},
  {"lb/in3", Unit::MassDensity::PoundPerCubicInch},
  {"lb/in/in/in", Unit::MassDensity::PoundPerCubicInch}
};

template <> const std::map<System, Unit::MassDensity> consistent_units<Unit::MassDensity>{
  {System::MetreKilogramSecondKelvin, Unit::MassDensity::KilogramPerCubicMetre},
  {System::MillimetreGramSecondKelvin, Unit::MassDensity::GramPerCubicMillimetre},
  {System::FootPoundSecondRankine, Unit::MassDensity::SlugPerCubicFoot},
  {System::InchPoundSecondRankine, Unit::MassDensity::SlinchPerCubicInch}
};

template <> constexpr const Unit::MassDensity standard_unit<Unit::MassDensity>{Unit::MassDensity::KilogramPerCubicMetre};

template <> constexpr const Dimension::Set dimension<Unit::MassDensity>{Dimension::Set{Dimension::Length{-3}, Dimension::Mass{1}}};

template <size_t size> const std::map<Unit::MassDensity, std::map<Unit::MassDensity, std::function<void(std::array<double, size>&)>>> conversions<Unit::MassDensity, size>{
  {Unit::MassDensity::KilogramPerCubicMetre, {
    {Unit::MassDensity::KilogramPerCubicMetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MassDensity::GramPerCubicMillimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1000000.0;});}},
    {Unit::MassDensity::SlugPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.3048, 4) / (0.45359237 * 9.80665);});}},
    {Unit::MassDensity::SlinchPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 4) / (0.45359237 * 9.80665);});}},
    {Unit::MassDensity::PoundPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.3048, 3) / 0.45359237;});}},
    {Unit::MassDensity::PoundPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 3) / 0.45359237;});}}}},
  {Unit::MassDensity::GramPerCubicMillimetre, {
    {Unit::MassDensity::KilogramPerCubicMetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0;});}},
    {Unit::MassDensity::GramPerCubicMillimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MassDensity::SlugPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0 * std::pow(0.3048, 4) / (0.45359237 * 9.80665);});}},
    {Unit::MassDensity::SlinchPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0 * std::pow(0.0254, 4) / (0.45359237 * 9.80665);});}},
    {Unit::MassDensity::PoundPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0 * std::pow(0.3048, 3) / 0.45359237;});}},
    {Unit::MassDensity::PoundPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0 * std::pow(0.0254, 3) / 0.45359237;});}}}},
  {Unit::MassDensity::SlugPerCubicFoot, {
    {Unit::MassDensity::KilogramPerCubicMetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / std::pow(0.3048, 4);});}},
    {Unit::MassDensity::GramPerCubicMillimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / (1000000.0 * std::pow(0.3048, 4));});}},
    {Unit::MassDensity::SlugPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MassDensity::SlinchPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12.0, 4);});}},
    {Unit::MassDensity::PoundPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 9.80665 / 0.3048;});}},
    {Unit::MassDensity::PoundPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 9.80665 / (0.3048 * std::pow(12.0, 3));});}}}},
  {Unit::MassDensity::SlinchPerCubicInch, {
    {Unit::MassDensity::KilogramPerCubicMetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / std::pow(0.0254, 4);});}},
    {Unit::MassDensity::GramPerCubicMillimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / (1000000.0 * std::pow(0.0254, 4));});}},
    {Unit::MassDensity::SlugPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12.0, 4);});}},
    {Unit::MassDensity::SlinchPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MassDensity::PoundPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 9.80665 * std::pow(12.0, 3) / 0.0254;});}},
    {Unit::MassDensity::PoundPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 9.80665 / 0.0254;});}}}},
  {Unit::MassDensity::PoundPerCubicFoot, {
    {Unit::MassDensity::KilogramPerCubicMetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 / std::pow(0.3048, 3);});}},
    {Unit::MassDensity::GramPerCubicMillimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 / (1000000.0 * std::pow(0.3048, 3));});}},
    {Unit::MassDensity::SlugPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.3048 / 9.80665;});}},
    {Unit::MassDensity::SlinchPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0254 / (9.80665 * std::pow(12.0, 3));});}},
    {Unit::MassDensity::PoundPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MassDensity::PoundPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12.0, 3);});}}}},
  {Unit::MassDensity::PoundPerCubicInch, {
    {Unit::MassDensity::KilogramPerCubicMetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 / std::pow(0.0254, 3);});}},
    {Unit::MassDensity::GramPerCubicMillimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 / (1000000.0 * std::pow(0.0254, 3));});}},
    {Unit::MassDensity::SlugPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.3048 * std::pow(12.0, 3) / 9.80665;});}},
    {Unit::MassDensity::SlinchPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0254 / 9.80665;});}},
    {Unit::MassDensity::PoundPerCubicFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12.0, 3);});}},
    {Unit::MassDensity::SlinchPerCubicInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}}}
};

} // namespace PhQ
