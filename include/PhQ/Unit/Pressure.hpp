// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Pressure : uint_least8_t {
  Pascal,
  Kilopascal,
  Megapascal,
  Gigapascal,
  Bar,
  Atmosphere,
  PoundPerSquareFoot,
  PoundPerSquareInch
};

} // namespace Unit

template <> const std::map<Unit::Pressure, std::string> abbreviations<Unit::Pressure>{
  {Unit::Pressure::Pascal, "Pa"},
  {Unit::Pressure::Kilopascal, "kPa"},
  {Unit::Pressure::Megapascal, "MPa"},
  {Unit::Pressure::Gigapascal, "GPa"},
  {Unit::Pressure::Bar, "bar"},
  {Unit::Pressure::Atmosphere, "atm"},
  {Unit::Pressure::PoundPerSquareFoot, "lbf/ft^2"},
  {Unit::Pressure::PoundPerSquareInch, "lbf/in^2"}
};

template <> const std::unordered_map<std::string, Unit::Pressure> spellings<Unit::Pressure>{
  {"Pa", Unit::Pressure::Pascal},
  {"N/m^2", Unit::Pressure::Pascal},
  {"N/m2", Unit::Pressure::Pascal},
  {"kg/(m·s^2)", Unit::Pressure::Pascal},
  {"kg/(m·s2)", Unit::Pressure::Pascal},
  {"kg/(m*s^2)", Unit::Pressure::Pascal},
  {"kg/(m*s2)", Unit::Pressure::Pascal},
  {"kg/m/s^2", Unit::Pressure::Pascal},
  {"kg/m/s2", Unit::Pressure::Pascal},
  {"kPa", Unit::Pressure::Kilopascal},
  {"kN/m^2", Unit::Pressure::Kilopascal},
  {"kN/m2", Unit::Pressure::Kilopascal},
  {"MPa", Unit::Pressure::Megapascal},
  {"N/mm^2", Unit::Pressure::Megapascal},
  {"N/mm2", Unit::Pressure::Megapascal},
  {"MN/m^2", Unit::Pressure::Megapascal},
  {"MN/m2", Unit::Pressure::Megapascal},
  {"GPa", Unit::Pressure::Gigapascal},
  {"GN/m^2", Unit::Pressure::Gigapascal},
  {"GN/m2", Unit::Pressure::Gigapascal},
  {"kN/mm^2", Unit::Pressure::Gigapascal},
  {"kN/mm2", Unit::Pressure::Gigapascal},
  {"bar", Unit::Pressure::Bar},
  {"atm", Unit::Pressure::Atmosphere},
  {"atmosphere", Unit::Pressure::Atmosphere},
  {"lbf/ft^2", Unit::Pressure::PoundPerSquareFoot},
  {"lbf/ft2", Unit::Pressure::PoundPerSquareFoot},
  {"lb/ft^2", Unit::Pressure::PoundPerSquareFoot},
  {"lb/ft2", Unit::Pressure::PoundPerSquareFoot},
  {"psf", Unit::Pressure::PoundPerSquareFoot},
  {"lbf/in^2", Unit::Pressure::PoundPerSquareInch},
  {"lbf/in2", Unit::Pressure::PoundPerSquareInch},
  {"lb/in^2", Unit::Pressure::PoundPerSquareInch},
  {"lb/in2", Unit::Pressure::PoundPerSquareInch},
  {"psi", Unit::Pressure::PoundPerSquareInch}
};

template <> const std::map<System, Unit::Pressure> consistent_units<Unit::Pressure>{
  {System::MetreKilogramSecondKelvin, Unit::Pressure::Pascal},
  {System::MillimetreGramSecondKelvin, Unit::Pressure::Pascal},
  {System::FootPoundSecondRankine, Unit::Pressure::PoundPerSquareFoot},
  {System::InchPoundSecondRankine, Unit::Pressure::PoundPerSquareInch}
};

template <> constexpr const Unit::Pressure standard_unit<Unit::Pressure>{Unit::Pressure::Pascal};

template <> constexpr const Dimension::Set dimension<Unit::Pressure>{Dimension::Set{Dimension::Length{-1}, Dimension::Mass{1}, Dimension::Time{-2}}};

template <> const std::map<Unit::Pressure, std::map<Unit::Pressure, std::function<void(std::vector<double>&)>>> conversions<Unit::Pressure>{
  {Unit::Pressure::Pascal, {
    {Unit::Pressure::Pascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Pressure::Kilopascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::Pressure::Megapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000001;});}},
    {Unit::Pressure::Gigapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000000001;});}},
    {Unit::Pressure::Bar, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.00001;});}},
    {Unit::Pressure::Atmosphere, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 101325.0;});}},
    {Unit::Pressure::PoundPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.3048, 2) / (0.45359237 * 9.80665);});}},
    {Unit::Pressure::PoundPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 2) / (0.45359237 * 9.80665);});}}
  }},
  {Unit::Pressure::Kilopascal, {
    {Unit::Pressure::Pascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::Pressure::Kilopascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Pressure::Megapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::Pressure::Gigapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000001;});}},
    {Unit::Pressure::Bar, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.01;});}},
    {Unit::Pressure::Atmosphere, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 101.325;});}},
    {Unit::Pressure::PoundPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0 * std::pow(0.3048, 2) / (0.45359237 * 9.80665);});}},
    {Unit::Pressure::PoundPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0 * std::pow(0.0254, 2) / (0.45359237 * 9.80665);});}}
  }},
  {Unit::Pressure::Megapascal, {
    {Unit::Pressure::Pascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0;});}},
    {Unit::Pressure::Kilopascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::Pressure::Megapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Pressure::Gigapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::Pressure::Bar, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 10.0;});}},
    {Unit::Pressure::Atmosphere, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.101325;});}},
    {Unit::Pressure::PoundPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0 * std::pow(0.3048, 2) / (0.45359237 * 9.80665);});}},
    {Unit::Pressure::PoundPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0 * std::pow(0.0254, 2) / (0.45359237 * 9.80665);});}}
  }},
  {Unit::Pressure::Gigapascal, {
    {Unit::Pressure::Pascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000000.0;});}},
    {Unit::Pressure::Kilopascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000.0;});}},
    {Unit::Pressure::Megapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::Pressure::Gigapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},

    {Unit::Pressure::Bar, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 10000.0;});}},
    {Unit::Pressure::Atmosphere, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.000101325;});}},
    {Unit::Pressure::PoundPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000000.0 * std::pow(0.3048, 2) / (0.45359237 * 9.80665);});}},
    {Unit::Pressure::PoundPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000000000.0 * std::pow(0.0254, 2) / (0.45359237 * 9.80665);});}}
  }},
  {Unit::Pressure::Bar, {
    {Unit::Pressure::Pascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 100000.0;});}},
    {Unit::Pressure::Kilopascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 100.0;});}},
    {Unit::Pressure::Megapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.1;});}},
    {Unit::Pressure::Gigapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0001;});}},
    {Unit::Pressure::Bar, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Pressure::Atmosphere, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.01325;});}},
    {Unit::Pressure::PoundPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 100000.0 * std::pow(0.3048, 2) / (0.45359237 * 9.80665);});}},
    {Unit::Pressure::PoundPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 100000.0 * std::pow(0.0254, 2) / (0.45359237 * 9.80665);});}}
  }},
  {Unit::Pressure::Atmosphere, {
    {Unit::Pressure::Pascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 101325.0;});}},
    {Unit::Pressure::Kilopascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 101.325;});}},
    {Unit::Pressure::Megapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.101325;});}},
    {Unit::Pressure::Gigapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000101325;});}},
    {Unit::Pressure::Bar, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.01325;});}},
    {Unit::Pressure::Atmosphere, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Pressure::PoundPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 101325.0 * std::pow(0.3048, 2) / (0.45359237 * 9.80665);});}},
    {Unit::Pressure::PoundPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 101325.0 * std::pow(0.0254, 2) / (0.45359237 * 9.80665);});}}
  }},
  {Unit::Pressure::PoundPerSquareFoot, {
    {Unit::Pressure::Pascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / std::pow(0.3048, 2);});}},
    {Unit::Pressure::Kilopascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001 * 0.45359237 * 9.80665 / std::pow(0.3048, 2);});}},
    {Unit::Pressure::Megapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000001 * 0.45359237 * 9.80665 / std::pow(0.3048, 2);});}},
    {Unit::Pressure::Gigapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000000001 * 0.45359237 * 9.80665 / std::pow(0.3048, 2);});}},
    {Unit::Pressure::Bar, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.00001 * 0.45359237 * 9.80665 / std::pow(0.3048, 2);});}},
    {Unit::Pressure::Atmosphere, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / (std::pow(0.3048, 2) * 101325.0);});}},
    {Unit::Pressure::PoundPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Pressure::PoundPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12.0, 2);});}}
  }},
  {Unit::Pressure::PoundPerSquareInch, {
    {Unit::Pressure::Pascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / std::pow(0.0254, 2);});}},
    {Unit::Pressure::Kilopascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001 * 0.45359237 * 9.80665 / std::pow(0.0254, 2);});}},
    {Unit::Pressure::Megapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000001 * 0.45359237 * 9.80665 / std::pow(0.0254, 2);});}},
    {Unit::Pressure::Gigapascal, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.000000001 * 0.45359237 * 9.80665 / std::pow(0.0254, 2);});}},
    {Unit::Pressure::Bar, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.00001 * 0.45359237 * 9.80665 / std::pow(0.0254, 2);});}},
    {Unit::Pressure::Atmosphere, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / (std::pow(0.0254, 2) * 101325.0);});}},
    {Unit::Pressure::PoundPerSquareFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12.0, 2);});}},
    {Unit::Pressure::PoundPerSquareInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}
  }}
};

} // namespace PhQ
