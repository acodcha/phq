// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class DynamicViscosity : uint_least8_t {
  PascalSecond,
  KilopascalSecond,
  MegapascalSecond,
  GigapascalSecond,
  PoundSecondPerSquareFoot,
  PoundSecondPerSquareInch
};

} // namespace Unit

template <> const std::map<Unit::DynamicViscosity, std::string> abbreviations<Unit::DynamicViscosity>{
  {Unit::DynamicViscosity::PascalSecond, "Pa·s"},
  {Unit::DynamicViscosity::KilopascalSecond, "kPa·s"},
  {Unit::DynamicViscosity::MegapascalSecond, "MPa·s"},
  {Unit::DynamicViscosity::GigapascalSecond, "GPa·s"},
  {Unit::DynamicViscosity::PoundSecondPerSquareFoot, "lbf·s/ft^2"},
  {Unit::DynamicViscosity::PoundSecondPerSquareInch, "lbf·s/in^2"}
};

template <> const std::unordered_map<std::string, Unit::DynamicViscosity> spellings<Unit::DynamicViscosity>{
  {"Pa·s", Unit::DynamicViscosity::PascalSecond},
  {"Pa*s", Unit::DynamicViscosity::PascalSecond},
  {"N·s/m^2", Unit::DynamicViscosity::PascalSecond},
  {"N·s/m2", Unit::DynamicViscosity::PascalSecond},
  {"N*s/m^2", Unit::DynamicViscosity::PascalSecond},
  {"N*s/m2", Unit::DynamicViscosity::PascalSecond},
  {"kg/(m·s)", Unit::DynamicViscosity::PascalSecond},
  {"kg/(m*s)", Unit::DynamicViscosity::PascalSecond},
  {"kg/m/s", Unit::DynamicViscosity::PascalSecond},
  {"kPa·s", Unit::DynamicViscosity::KilopascalSecond},
  {"kPa*s", Unit::DynamicViscosity::KilopascalSecond},
  {"kN·s/m^2", Unit::DynamicViscosity::KilopascalSecond},
  {"kN·s/m2", Unit::DynamicViscosity::KilopascalSecond},
  {"kN*s/m^2", Unit::DynamicViscosity::KilopascalSecond},
  {"kN*s/m2", Unit::DynamicViscosity::KilopascalSecond},
  {"MPa·s", Unit::DynamicViscosity::MegapascalSecond},
  {"MPa*s", Unit::DynamicViscosity::MegapascalSecond},
  {"N·s/mm^2", Unit::DynamicViscosity::MegapascalSecond},
  {"N·s/mm^2", Unit::DynamicViscosity::MegapascalSecond},
  {"N*s/mm2", Unit::DynamicViscosity::MegapascalSecond},
  {"N*s/mm2", Unit::DynamicViscosity::MegapascalSecond},
  {"MN·s/m^2", Unit::DynamicViscosity::MegapascalSecond},
  {"MN·s/m2", Unit::DynamicViscosity::MegapascalSecond},
  {"MN*s/m^2", Unit::DynamicViscosity::MegapascalSecond},
  {"MN*s/m2", Unit::DynamicViscosity::MegapascalSecond},
  {"GPa·s", Unit::DynamicViscosity::GigapascalSecond},
  {"GPa*s", Unit::DynamicViscosity::GigapascalSecond},
  {"GN·s/m^2", Unit::DynamicViscosity::GigapascalSecond},
  {"GN·s/m2", Unit::DynamicViscosity::GigapascalSecond},
  {"GN*s/m^2", Unit::DynamicViscosity::GigapascalSecond},
  {"GN*s/m2", Unit::DynamicViscosity::GigapascalSecond},
  {"kN·s/mm^2", Unit::DynamicViscosity::GigapascalSecond},
  {"kN·s/mm2", Unit::DynamicViscosity::GigapascalSecond},
  {"kN*s/mm^2", Unit::DynamicViscosity::GigapascalSecond},
  {"kN*s/mm2", Unit::DynamicViscosity::GigapascalSecond},
  {"lbf·s/ft^2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
  {"lbf·s/ft2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
  {"lbf*s/ft^2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
  {"lbf*s/ft2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
  {"lb·s/ft^2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
  {"lb·s/ft2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
  {"lb*s/ft^2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
  {"lb*s/ft2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
  {"psf·s", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
  {"psf*s", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
  {"lbf·s/in^2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
  {"lbf·s/in2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
  {"lbf*s/in^2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
  {"lbf*s/in2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
  {"lb·s/in^2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
  {"lb·s/in2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
  {"lb*s/in^2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
  {"lb*s/in2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
  {"psi·s", Unit::DynamicViscosity::PoundSecondPerSquareInch},
  {"psi*s", Unit::DynamicViscosity::PoundSecondPerSquareInch}
};

template <> const std::map<System, Unit::DynamicViscosity> consistent_units<Unit::DynamicViscosity>{
  {System::MetreKilogramSecondKelvin, Unit::DynamicViscosity::PascalSecond},
  {System::MillimetreGramSecondKelvin, Unit::DynamicViscosity::PascalSecond},
  {System::FootPoundSecondRankine, Unit::DynamicViscosity::PoundSecondPerSquareFoot},
  {System::InchPoundSecondRankine, Unit::DynamicViscosity::PoundSecondPerSquareInch}
};

template <> constexpr const Unit::DynamicViscosity standard_unit<Unit::DynamicViscosity>{Unit::DynamicViscosity::PascalSecond};

template <> constexpr const Dimension::Set dimension<Unit::DynamicViscosity>{Dimension::Set{Dimension::Length{-1}, Dimension::Mass{1}, Dimension::Time{-1}}};

template <> const std::map<Unit::DynamicViscosity, std::map<Unit::DynamicViscosity, std::function<void(std::vector<double>&)>>> conversions<Unit::DynamicViscosity>{
  {Unit::DynamicViscosity::PascalSecond, {
    {Unit::DynamicViscosity::PascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::DynamicViscosity::KilopascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::DynamicViscosity::MegapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000001;});}},
    {Unit::DynamicViscosity::GigapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000000001;});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.3048, 2) / (0.45359237 * 9.80665);});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 2) / (0.45359237 * 9.80665);});}}
  }},
  {Unit::DynamicViscosity::KilopascalSecond, {
    {Unit::DynamicViscosity::PascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::DynamicViscosity::KilopascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::DynamicViscosity::MegapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::DynamicViscosity::GigapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000001;});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0 * std::pow(0.3048, 2) / (0.45359237 * 9.80665);});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0 * std::pow(0.0254, 2) / (0.45359237 * 9.80665);});}}
  }},
  {Unit::DynamicViscosity::MegapascalSecond, {
    {Unit::DynamicViscosity::PascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0;});}},
    {Unit::DynamicViscosity::KilopascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::DynamicViscosity::MegapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::DynamicViscosity::GigapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0 * std::pow(0.3048, 2) / (0.45359237 * 9.80665);});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0 * std::pow(0.0254, 2) / (0.45359237 * 9.80665);});}}
  }},
  {Unit::DynamicViscosity::GigapascalSecond, {
    {Unit::DynamicViscosity::PascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000000.0;});}},
    {Unit::DynamicViscosity::KilopascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0;});}},
    {Unit::DynamicViscosity::MegapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::DynamicViscosity::GigapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000000.0 * std::pow(0.3048, 2) / (0.45359237 * 9.80665);});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000000.0 * std::pow(0.0254, 2) / (0.45359237 * 9.80665);});}}
  }},
  {Unit::DynamicViscosity::PoundSecondPerSquareFoot, {
    {Unit::DynamicViscosity::PascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / std::pow(0.3048, 2);});}},
    {Unit::DynamicViscosity::KilopascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001 * 0.45359237 * 9.80665 / std::pow(0.3048, 2);});}},
    {Unit::DynamicViscosity::MegapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000001 * 0.45359237 * 9.80665 / std::pow(0.3048, 2);});}},
    {Unit::DynamicViscosity::GigapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000000001 * 0.45359237 * 9.80665 / std::pow(0.3048, 2);});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12.0, 2);});}}
  }},
  {Unit::DynamicViscosity::PoundSecondPerSquareInch, {
    {Unit::DynamicViscosity::PascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / std::pow(0.0254, 2);});}},
    {Unit::DynamicViscosity::KilopascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001 * 0.45359237 * 9.80665 / std::pow(0.0254, 2);});}},
    {Unit::DynamicViscosity::MegapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000001 * 0.45359237 * 9.80665 / std::pow(0.0254, 2);});}},
    {Unit::DynamicViscosity::GigapascalSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000000001 * 0.45359237 * 9.80665 / std::pow(0.0254, 2);});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12.0, 2);});}},
    {Unit::DynamicViscosity::PoundSecondPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}
  }}
};

} // namespace PhQ
