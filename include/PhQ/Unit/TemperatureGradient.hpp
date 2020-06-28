// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class TemperatureGradient : uint_least8_t {
  KelvinPerMetre,
  KelvinPerMillimetre,
  CelsiusPerMetre,
  CelsiusPerMillimetre,
  RankinePerFoot,
  RankinePerInch,
  FahrenheitPerFoot,
  FahrenheitPerInch
};

} // namespace Unit

template <> const std::map<Unit::TemperatureGradient, std::string> abbreviations<Unit::TemperatureGradient>{
  {Unit::TemperatureGradient::KelvinPerMetre, "K/m"},
  {Unit::TemperatureGradient::CelsiusPerMetre, "°C/m"},
  {Unit::TemperatureGradient::KelvinPerMillimetre, "K/mm"},
  {Unit::TemperatureGradient::CelsiusPerMillimetre, "°C/mm"},
  {Unit::TemperatureGradient::RankinePerFoot, "°R/ft"},
  {Unit::TemperatureGradient::FahrenheitPerFoot, "°F/ft"},
  {Unit::TemperatureGradient::RankinePerInch, "°R/in"},
  {Unit::TemperatureGradient::FahrenheitPerInch, "°F/in"}
};

template <> const std::unordered_map<std::string, Unit::TemperatureGradient> spellings<Unit::TemperatureGradient>{
  {"K/m", Unit::TemperatureGradient::KelvinPerMetre},
  {"°K/m", Unit::TemperatureGradient::KelvinPerMetre},
  {"degK/m", Unit::TemperatureGradient::KelvinPerMetre},
  {"°C/m", Unit::TemperatureGradient::CelsiusPerMetre},
  {"C/m", Unit::TemperatureGradient::CelsiusPerMetre},
  {"degC/m", Unit::TemperatureGradient::CelsiusPerMetre},
  {"K/mm", Unit::TemperatureGradient::KelvinPerMillimetre},
  {"°K/mm", Unit::TemperatureGradient::KelvinPerMillimetre},
  {"degK/mm", Unit::TemperatureGradient::KelvinPerMillimetre},
  {"°C/mm", Unit::TemperatureGradient::CelsiusPerMillimetre},
  {"C/mm", Unit::TemperatureGradient::CelsiusPerMillimetre},
  {"degC/mm", Unit::TemperatureGradient::CelsiusPerMillimetre},
  {"°R/ft", Unit::TemperatureGradient::RankinePerFoot},
  {"R/ft", Unit::TemperatureGradient::RankinePerFoot},
  {"degR/ft", Unit::TemperatureGradient::RankinePerFoot},
  {"°F/ft", Unit::TemperatureGradient::FahrenheitPerFoot},
  {"F/ft", Unit::TemperatureGradient::FahrenheitPerFoot},
  {"degF/ft", Unit::TemperatureGradient::FahrenheitPerFoot},
  {"°R/in", Unit::TemperatureGradient::RankinePerInch},
  {"R/in", Unit::TemperatureGradient::RankinePerInch},
  {"degR/in", Unit::TemperatureGradient::RankinePerInch},
  {"°F/in", Unit::TemperatureGradient::FahrenheitPerInch},
  {"F/in", Unit::TemperatureGradient::FahrenheitPerInch},
  {"degF/in", Unit::TemperatureGradient::FahrenheitPerInch}
};

template <> const std::map<System, Unit::TemperatureGradient> consistent_units<Unit::TemperatureGradient>{
  {System::MetreKilogramSecondKelvin, Unit::TemperatureGradient::KelvinPerMetre},
  {System::MillimetreGramSecondKelvin, Unit::TemperatureGradient::KelvinPerMillimetre},
  {System::FootPoundSecondRankine, Unit::TemperatureGradient::RankinePerFoot},
  {System::InchPoundSecondRankine, Unit::TemperatureGradient::RankinePerInch}
};

template <> constexpr const Unit::TemperatureGradient standard_unit<Unit::TemperatureGradient>{Unit::TemperatureGradient::KelvinPerMetre};

template <> constexpr const Dimension::Set dimension<Unit::TemperatureGradient>{Dimension::Set{Dimension::Length{-1}, Dimension::Mass{}, Dimension::Time{}, Dimension::ElectricCurrent{}, Dimension::Temperature{1}}};

template <> const std::map<Unit::TemperatureGradient, std::map<Unit::TemperatureGradient, std::function<void(std::vector<double>&)>>> conversions<Unit::TemperatureGradient>{
  {Unit::TemperatureGradient::KelvinPerMetre, {
    {Unit::TemperatureGradient::KelvinPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::CelsiusPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::KelvinPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::TemperatureGradient::CelsiusPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::TemperatureGradient::RankinePerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 0.3048;});}},
    {Unit::TemperatureGradient::FahrenheitPerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 0.3048;});}},
    {Unit::TemperatureGradient::RankinePerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 0.0254;});}},
    {Unit::TemperatureGradient::FahrenheitPerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 0.0254;});}}
  }},
  {Unit::TemperatureGradient::CelsiusPerMetre, {
    {Unit::TemperatureGradient::KelvinPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::CelsiusPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::KelvinPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::TemperatureGradient::CelsiusPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::TemperatureGradient::RankinePerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 0.3048;});}},
    {Unit::TemperatureGradient::FahrenheitPerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 0.3048;});}},
    {Unit::TemperatureGradient::RankinePerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 0.0254;});}},
    {Unit::TemperatureGradient::FahrenheitPerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 0.0254;});}}
  }},
  {Unit::TemperatureGradient::KelvinPerMillimetre, {
    {Unit::TemperatureGradient::KelvinPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::TemperatureGradient::CelsiusPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::TemperatureGradient::KelvinPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::CelsiusPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::RankinePerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 304.8;});}},
    {Unit::TemperatureGradient::FahrenheitPerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 304.8;});}},
    {Unit::TemperatureGradient::RankinePerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 25.4;});}},
    {Unit::TemperatureGradient::FahrenheitPerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 25.4;});}}
  }},
  {Unit::TemperatureGradient::CelsiusPerMillimetre, {
    {Unit::TemperatureGradient::KelvinPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::TemperatureGradient::CelsiusPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::TemperatureGradient::KelvinPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::CelsiusPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::RankinePerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 304.8;});}},
    {Unit::TemperatureGradient::FahrenheitPerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 304.8;});}},
    {Unit::TemperatureGradient::RankinePerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 25.4;});}},
    {Unit::TemperatureGradient::FahrenheitPerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1.8 * 25.4;});}}
  }},
  {Unit::TemperatureGradient::RankinePerFoot, {
    {Unit::TemperatureGradient::KelvinPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 0.3048;});}},
    {Unit::TemperatureGradient::CelsiusPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 0.3048;});}},
    {Unit::TemperatureGradient::KelvinPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 304.8;});}},
    {Unit::TemperatureGradient::CelsiusPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 304.8;});}},
    {Unit::TemperatureGradient::RankinePerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::FahrenheitPerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::RankinePerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12.0;});}},
    {Unit::TemperatureGradient::FahrenheitPerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12.0;});}}
  }},
  {Unit::TemperatureGradient::FahrenheitPerFoot, {
    {Unit::TemperatureGradient::KelvinPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 0.3048;});}},
    {Unit::TemperatureGradient::CelsiusPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 0.3048;});}},
    {Unit::TemperatureGradient::KelvinPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 304.8;});}},
    {Unit::TemperatureGradient::CelsiusPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 304.8;});}},
    {Unit::TemperatureGradient::RankinePerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::FahrenheitPerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::RankinePerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12.0;});}},
    {Unit::TemperatureGradient::FahrenheitPerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12.0;});}}
  }},
  {Unit::TemperatureGradient::RankinePerInch, {
    {Unit::TemperatureGradient::KelvinPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 0.0254;});}},
    {Unit::TemperatureGradient::CelsiusPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 0.0254;});}},
    {Unit::TemperatureGradient::KelvinPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 25.4;});}},
    {Unit::TemperatureGradient::CelsiusPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 25.4;});}},
    {Unit::TemperatureGradient::RankinePerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::FahrenheitPerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::RankinePerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12.0;});}},
    {Unit::TemperatureGradient::FahrenheitPerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12.0;});}}
  }},
  {Unit::TemperatureGradient::FahrenheitPerInch, {
    {Unit::TemperatureGradient::KelvinPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 0.0254;});}},
    {Unit::TemperatureGradient::CelsiusPerMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 0.0254;});}},
    {Unit::TemperatureGradient::KelvinPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 25.4;});}},
    {Unit::TemperatureGradient::CelsiusPerMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1.8 * 25.4;});}},
    {Unit::TemperatureGradient::RankinePerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::FahrenheitPerFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::TemperatureGradient::RankinePerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12.0;});}},
    {Unit::TemperatureGradient::FahrenheitPerInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12.0;});}}
  }}
};

} // namespace PhQ
