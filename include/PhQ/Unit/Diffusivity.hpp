// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Diffusivity : uint_least8_t {
  SquareMilePerSecond,
  SquareKilometrePerSecond,
  SquareYardPerSecond,
  SquareMetrePerSecond,
  SquareFootPerSecond,
  SquareDecimetrePerSecond,
  SquareInchPerSecond,
  SquareCentimetrePerSecond,
  SquareMillimetrePerSecond,
  SquareMilliinchPerSecond,
  SquareMicrometrePerSecond,
  SquareMicroinchPerSecond
};

} // namespace Unit

template <> const std::map<Unit::Diffusivity, std::string> abbreviations<Unit::Diffusivity>{
  {Unit::Diffusivity::SquareMilePerSecond, "mi^2/s"},
  {Unit::Diffusivity::SquareKilometrePerSecond, "km^2/s"},
  {Unit::Diffusivity::SquareYardPerSecond, "yd^2/s"},
  {Unit::Diffusivity::SquareMetrePerSecond, "m^2/s"},
  {Unit::Diffusivity::SquareFootPerSecond, "ft^2/s"},
  {Unit::Diffusivity::SquareDecimetrePerSecond, "dm^2/s"},
  {Unit::Diffusivity::SquareInchPerSecond, "in^2/s"},
  {Unit::Diffusivity::SquareCentimetrePerSecond, "cm^2/s"},
  {Unit::Diffusivity::SquareMillimetrePerSecond, "mm^2/s"},
  {Unit::Diffusivity::SquareMilliinchPerSecond, "thou^2/s"},
  {Unit::Diffusivity::SquareMicrometrePerSecond, "μm^2/s"},
  {Unit::Diffusivity::SquareMicroinchPerSecond, "μin^2/s"}
};

template <> const std::unordered_map<std::string, Unit::Diffusivity> spellings<Unit::Diffusivity>{
  {"mi^2/s", Unit::Diffusivity::SquareMilePerSecond},
  {"mi^2/sec", Unit::Diffusivity::SquareMilePerSecond},
  {"mi2/s", Unit::Diffusivity::SquareMilePerSecond},
  {"mi2/sec", Unit::Diffusivity::SquareMilePerSecond},
  {"km^2/s", Unit::Diffusivity::SquareKilometrePerSecond},
  {"km^2/sec", Unit::Diffusivity::SquareKilometrePerSecond},
  {"km2/s", Unit::Diffusivity::SquareKilometrePerSecond},
  {"km2/sec", Unit::Diffusivity::SquareKilometrePerSecond},
  {"yd^2/s", Unit::Diffusivity::SquareYardPerSecond},
  {"yd^2/sec", Unit::Diffusivity::SquareYardPerSecond},
  {"yd2/s", Unit::Diffusivity::SquareYardPerSecond},
  {"yd2/sec", Unit::Diffusivity::SquareYardPerSecond},
  {"m^2/s", Unit::Diffusivity::SquareMetrePerSecond},
  {"m^2/sec", Unit::Diffusivity::SquareMetrePerSecond},
  {"m2/s", Unit::Diffusivity::SquareMetrePerSecond},
  {"m2/sec", Unit::Diffusivity::SquareMetrePerSecond},
  {"ft^2/s", Unit::Diffusivity::SquareFootPerSecond},
  {"ft^2/sec", Unit::Diffusivity::SquareFootPerSecond},
  {"ft2/s", Unit::Diffusivity::SquareFootPerSecond},
  {"ft2/sec", Unit::Diffusivity::SquareFootPerSecond},
  {"dm^2/s", Unit::Diffusivity::SquareDecimetrePerSecond},
  {"dm^2/sec", Unit::Diffusivity::SquareDecimetrePerSecond},
  {"dm2/s", Unit::Diffusivity::SquareDecimetrePerSecond},
  {"dm2/sec", Unit::Diffusivity::SquareDecimetrePerSecond},
  {"in^2/s", Unit::Diffusivity::SquareInchPerSecond},
  {"in^2/sec", Unit::Diffusivity::SquareInchPerSecond},
  {"in2/s", Unit::Diffusivity::SquareInchPerSecond},
  {"in2/sec", Unit::Diffusivity::SquareInchPerSecond},
  {"cm^2/s", Unit::Diffusivity::SquareCentimetrePerSecond},
  {"cm^2/sec", Unit::Diffusivity::SquareCentimetrePerSecond},
  {"cm2/s", Unit::Diffusivity::SquareCentimetrePerSecond},
  {"cm2/sec", Unit::Diffusivity::SquareCentimetrePerSecond},
  {"mm^2/s", Unit::Diffusivity::SquareMillimetrePerSecond},
  {"mm^2/sec", Unit::Diffusivity::SquareMillimetrePerSecond},
  {"mm2/s", Unit::Diffusivity::SquareMillimetrePerSecond},
  {"mm2/sec", Unit::Diffusivity::SquareMillimetrePerSecond},
  {"thou^2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"thou^2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"thou2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"thou2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"mil^2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"mil^2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"mil2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"mil2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"millinch^2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"millinch^2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"millinch2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"millinch2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"milliinch^2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"milliinch^2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"milliinch2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"milliinch2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
  {"μm^2/s", Unit::Diffusivity::SquareMicrometrePerSecond},
  {"μm^2/sec", Unit::Diffusivity::SquareMicrometrePerSecond},
  {"μm2/s", Unit::Diffusivity::SquareMicrometrePerSecond},
  {"μm2/sec", Unit::Diffusivity::SquareMicrometrePerSecond},
  {"um^2/s", Unit::Diffusivity::SquareMicrometrePerSecond},
  {"um^2/sec", Unit::Diffusivity::SquareMicrometrePerSecond},
  {"um2/s", Unit::Diffusivity::SquareMicrometrePerSecond},
  {"um2/sec", Unit::Diffusivity::SquareMicrometrePerSecond},
  {"μin^2/s", Unit::Diffusivity::SquareMicroinchPerSecond},
  {"μin^2/sec", Unit::Diffusivity::SquareMicroinchPerSecond},
  {"μin2/s", Unit::Diffusivity::SquareMicroinchPerSecond},
  {"μin2/sec", Unit::Diffusivity::SquareMicroinchPerSecond},
  {"uin^2/s", Unit::Diffusivity::SquareMicroinchPerSecond},
  {"uin^2/sec", Unit::Diffusivity::SquareMicroinchPerSecond},
  {"uin2/s", Unit::Diffusivity::SquareMicroinchPerSecond},
  {"uin2/sec", Unit::Diffusivity::SquareMicroinchPerSecond}
};

template <> const std::map<System, Unit::Diffusivity> consistent_units<Unit::Diffusivity>{
  {System::MetreKilogramSecondKelvin, Unit::Diffusivity::SquareMetrePerSecond},
  {System::MillimetreGramSecondKelvin, Unit::Diffusivity::SquareMillimetrePerSecond},
  {System::FootPoundSecondRankine, Unit::Diffusivity::SquareFootPerSecond},
  {System::InchPoundSecondRankine, Unit::Diffusivity::SquareInchPerSecond}
};

template <> const std::map<Unit::Diffusivity, System> related_systems<Unit::Diffusivity>{
  {Unit::Diffusivity::SquareMetrePerSecond, System::MetreKilogramSecondKelvin},
  {Unit::Diffusivity::SquareMillimetrePerSecond, System::MillimetreGramSecondKelvin},
  {Unit::Diffusivity::SquareFootPerSecond, System::FootPoundSecondRankine},
  {Unit::Diffusivity::SquareInchPerSecond, System::InchPoundSecondRankine},
};

template <> constexpr const Unit::Diffusivity standard_unit<Unit::Diffusivity>{Unit::Diffusivity::SquareMetrePerSecond};

template <> constexpr const Dimension::Set dimension<Unit::Diffusivity>{Dimension::Set{Dimension::Length{2}, Dimension::Mass{}, Dimension::Time{-1}}};

template <> const std::map<Unit::Diffusivity, std::map<Unit::Diffusivity, std::function<void(std::vector<double>&)>>> conversions<Unit::Diffusivity>{
  {Unit::Diffusivity::SquareMilePerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1.609344, 2);});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1760.0, 2);});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1609.344, 2);});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(5280.0, 2);});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(16093.44, 2);});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(63360.0, 2);});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(160934.4, 2);});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1609344.0, 2);});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(63360000.0, 2);});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1609344000.0, 2);});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(63360000000.0, 2);});}}
  }},
  {Unit::Diffusivity::SquareKilometrePerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1.609344, 2);});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0009144, 2);});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 2);});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0003048, 2);});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10000.0, 2);});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000254, 2);});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100000.0, 2);});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000000.0, 2);});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000000254, 2);});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000000000.0, 2);});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000000000254, 2);});}}
  }},
  {Unit::Diffusivity::SquareYardPerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1760.0, 2);});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0009144, 2);});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.9144, 2);});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(3.0, 2);});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(9.144, 2);});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(36.0, 2);});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(91.44, 2);});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(914.4, 2);});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(36000.0, 2);});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(914400.0, 2);});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(36000000.0, 2);});}}
  }},
  {Unit::Diffusivity::SquareMetrePerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1609.344, 2);});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 2);});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.9144, 2);});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.3048, 2);});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10.0, 2);});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0254, 2);});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100.0, 2);});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 2);});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000254, 2);});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000000.0, 2);});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000000254, 2);});}}
  }},
  {Unit::Diffusivity::SquareFootPerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(5280.0, 2);});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0003048, 2);});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(3.0, 2);});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.3048, 2);});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(3.048, 2);});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12.0, 2);});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(30.48, 2);});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(304.8, 2);});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12000.0, 2);});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(304800.0, 2);});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12000000.0, 2);});}}
  }},
  {Unit::Diffusivity::SquareDecimetrePerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(16093.44, 2);});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0001, 2);});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(9.144, 2);});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.1, 2);});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(3.048, 2);});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.254, 2);});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10.0, 2);});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100.0, 2);});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.000254, 2);});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100000.0, 2);});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.000000254, 2);});}}
  }},
  {Unit::Diffusivity::SquareInchPerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(63360.0, 2);});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000254, 2);});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(36.0, 2);});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 2);});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12.0, 2);});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.254, 2);});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(2.54, 2);});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(25.4, 2);});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 2);});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(25400.0, 2);});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000000.0, 2);});}}
  }},
  {Unit::Diffusivity::SquareCentimetrePerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(160934.4, 2);});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00001, 2);});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(91.44, 2);});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.01, 2);});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(30.48, 2);});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.1, 2);});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(2.54, 2);});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10.0, 2);});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.00254, 2);});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10000.0, 2);});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.00000254, 2);});}}
  }},
  {Unit::Diffusivity::SquareMillimetrePerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1609344.0, 2);});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000001, 2);});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(914.4, 2);});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 2);});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(304.8, 2);});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.01, 2);});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(25.4, 2);});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.1, 2);});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0254, 2);});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 2);});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000254, 2);});}}
  }},
  {Unit::Diffusivity::SquareMilliinchPerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(63360000.0, 2);});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000000254, 2);});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(36000.0, 2);});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000254, 2);});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12000.0, 2);});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000254, 2);});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 2);});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00254, 2);});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 2);});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(25.4, 2);});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 2);});}}
  }},
  {Unit::Diffusivity::SquareMicrometrePerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1609344000.0, 2);});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000000001, 2);});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(914400.0, 2);});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000001, 2);});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(304800.0, 2);});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00001, 2);});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(25400.0, 2);});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0001, 2);});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 2);});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(25.4, 2);});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0254, 2);});}}
  }},
  {Unit::Diffusivity::SquareMicroinchPerSecond, {
    {Unit::Diffusivity::SquareMilePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(63360000000.0, 2);});}},
    {Unit::Diffusivity::SquareKilometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000000000254, 2);});}},
    {Unit::Diffusivity::SquareYardPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(36000000.0, 2);});}},
    {Unit::Diffusivity::SquareMetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000000254, 2);});}},
    {Unit::Diffusivity::SquareFootPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12000000.0, 2);});}},
    {Unit::Diffusivity::SquareDecimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000000254, 2);});}},
    {Unit::Diffusivity::SquareInchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000001, 2);});}},
    {Unit::Diffusivity::SquareCentimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00000254, 2);});}},
    {Unit::Diffusivity::SquareMillimetrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000254, 2);});}},
    {Unit::Diffusivity::SquareMilliinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 2);});}},
    {Unit::Diffusivity::SquareMicrometrePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 2);});}},
    {Unit::Diffusivity::SquareMicroinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}
  }}
};

} // namespace PhQ
