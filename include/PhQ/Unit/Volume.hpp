// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Volume : int_least8_t {
  CubicMile,
  CubicKilometre,
  CubicYard,
  CubicMetre,
  CubicFoot,
  CubicDecimetre,
  Litre,
  CubicInch,
  CubicCentimetre,
  Millilitre,
  CubicMillimetre,
  CubicMilliinch,
  CubicMicrometre,
  CubicMicroinch
};

} // namespace Unit

template <> const std::map<Unit::Volume, std::string> abbreviations<Unit::Volume>{
  {Unit::Volume::CubicMile, "mi^3"},
  {Unit::Volume::CubicKilometre, "km^3"},
  {Unit::Volume::CubicYard, "yd^3"},
  {Unit::Volume::CubicMetre, "m^3"},
  {Unit::Volume::CubicFoot, "ft^3"},
  {Unit::Volume::CubicDecimetre, "dm^3"},
  {Unit::Volume::Litre, "L"},
  {Unit::Volume::CubicInch, "in^3"},
  {Unit::Volume::CubicCentimetre, "cm^3"},
  {Unit::Volume::Millilitre, "mL"},
  {Unit::Volume::CubicMillimetre, "mm^3"},
  {Unit::Volume::CubicMilliinch, "thou^3"},
  {Unit::Volume::CubicMicrometre, "μm^3"},
  {Unit::Volume::CubicMicroinch, "μin^3"}
};

template <> const std::unordered_map<std::string, Unit::Volume> spellings<Unit::Volume>{
  {"mi^3", Unit::Volume::CubicMile},
  {"mi3", Unit::Volume::CubicMile},
  {"km^3", Unit::Volume::CubicKilometre},
  {"km3", Unit::Volume::CubicKilometre},
  {"yd^3", Unit::Volume::CubicYard},
  {"yd3", Unit::Volume::CubicYard},
  {"m^3", Unit::Volume::CubicMetre},
  {"m3", Unit::Volume::CubicMetre},
  {"ft^3", Unit::Volume::CubicFoot},
  {"ft3", Unit::Volume::CubicFoot},
  {"dm^3", Unit::Volume::CubicDecimetre},
  {"dm3", Unit::Volume::CubicDecimetre},
  {"L", Unit::Volume::Litre},
  {"in^3", Unit::Volume::CubicInch},
  {"in3", Unit::Volume::CubicInch},
  {"cm^3", Unit::Volume::CubicCentimetre},
  {"cm3", Unit::Volume::CubicCentimetre},
  {"mL", Unit::Volume::Millilitre},
  {"mm^3", Unit::Volume::CubicMillimetre},
  {"mm3", Unit::Volume::CubicMillimetre},
  {"thou^3", Unit::Volume::CubicMilliinch},
  {"thou3", Unit::Volume::CubicMilliinch},
  {"mil^3", Unit::Volume::CubicMilliinch},
  {"mil3", Unit::Volume::CubicMilliinch},
  {"millinch^3", Unit::Volume::CubicMilliinch},
  {"millinch3", Unit::Volume::CubicMilliinch},
  {"milliinch^3", Unit::Volume::CubicMilliinch},
  {"milliinch3", Unit::Volume::CubicMilliinch},
  {"μm^3", Unit::Volume::CubicMicrometre},
  {"μm3", Unit::Volume::CubicMicrometre},
  {"um^3", Unit::Volume::CubicMicrometre},
  {"um3", Unit::Volume::CubicMicrometre},
  {"μin^3", Unit::Volume::CubicMicroinch},
  {"μin3", Unit::Volume::CubicMicroinch},
  {"uin^3", Unit::Volume::CubicMicroinch},
  {"uin3", Unit::Volume::CubicMicroinch}
};

template <> const std::map<System, Unit::Volume> consistent_units<Unit::Volume>{
  {System::MetreKilogramSecondKelvin, Unit::Volume::CubicMetre},
  {System::MillimetreGramSecondKelvin, Unit::Volume::CubicMillimetre},
  {System::FootPoundSecondRankine, Unit::Volume::CubicFoot},
  {System::InchPoundSecondRankine, Unit::Volume::CubicInch}
};

template <> const std::map<Unit::Volume, System> related_systems<Unit::Volume>{
  {Unit::Volume::CubicMetre, System::MetreKilogramSecondKelvin},
  {Unit::Volume::CubicMillimetre, System::MillimetreGramSecondKelvin},
  {Unit::Volume::CubicFoot, System::FootPoundSecondRankine},
  {Unit::Volume::CubicInch, System::InchPoundSecondRankine},
};

template <> constexpr const Unit::Volume standard_unit<Unit::Volume>{Unit::Volume::CubicMetre};

template <> constexpr const Dimension::Set dimension<Unit::Volume>{Dimension::Set{Dimension::Length{3}}};

template <> const std::map<Unit::Volume, std::map<Unit::Volume, std::function<void(std::vector<double>&)>>> conversions<Unit::Volume>{
  {Unit::Volume::CubicMile, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1.609344, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1760.0, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1609.344, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(5280.0, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(16093.44, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(16093.44, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(63360.0, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(160934.4, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(160934.4, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1609344.0, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(63360000.0, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1609344000.0, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(63360000000.0, 3);});}}
  }},
  {Unit::Volume::CubicKilometre, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1.609344, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0009144, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0003048, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10000.0, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10000.0, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000254, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100000.0, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100000.0, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000000.0, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000000254, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000000000.0, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000000000254, 3);});}}
  }},
  {Unit::Volume::CubicYard, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1760.0, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0009144, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.9144, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(3.0, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(9.144, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(9.144, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(36.0, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(91.44, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(91.44, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(914.4, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(36000.0, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(914400.0, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(36000000.0, 3);});}}
  }},
  {Unit::Volume::CubicMetre, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1609.344, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.9144, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.3048, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10.0, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10.0, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0254, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100.0, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100.0, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000254, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000000.0, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000000254, 3);});}}
  }},
  {Unit::Volume::CubicFoot, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(5280.0, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0003048, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(3.0, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.3048, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(3.048, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(3.048, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12.0, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(30.48, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(30.48, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(304.8, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12000.0, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(304800.0, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12000000.0, 3);});}}
  }},
  {Unit::Volume::CubicDecimetre, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(16093.44, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0001, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(9.144, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.1, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(3.048, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.254, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10.0, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10.0, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100.0, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.000254, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100000.0, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.000000254, 3);});}}
  }},
  {Unit::Volume::Litre, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(16093.44, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0001, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(9.144, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.1, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(3.048, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.254, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10.0, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10.0, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100.0, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.000254, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(100000.0, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.000000254, 3);});}}
  }},
  {Unit::Volume::CubicInch, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(63360.0, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000254, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(36.0, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12.0, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.254, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.254, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(2.54, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(2.54, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(25.4, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(25400.0, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000000.0, 3);});}}
  }},
  {Unit::Volume::CubicCentimetre, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(160934.4, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00001, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(91.44, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.01, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(30.48, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.1, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.1, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(2.54, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10.0, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.00254, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10000.0, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.00000254, 3);});}}
  }},
  {Unit::Volume::Millilitre, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(160934.4, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00001, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(91.44, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.01, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(30.48, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.1, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.1, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(2.54, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10.0, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.00254, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(10000.0, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.00000254, 3);});}}
  }},
  {Unit::Volume::CubicMillimetre, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1609344.0, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000001, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(914.4, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(304.8, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.01, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.01, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(25.4, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.1, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.1, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0254, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0000254, 3);});}}
  }},
  {Unit::Volume::CubicMilliinch, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(63360000.0, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000000254, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(36000.0, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000254, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12000.0, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000254, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000254, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00254, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00254, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(25.4, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 3);});}}
  }},
  {Unit::Volume::CubicMicrometre, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1609344000.0, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000000001, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(914400.0, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000001, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(304800.0, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00001, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00001, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(25400.0, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0001, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0001, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(25.4, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0254, 3);});}}
  }},
  {Unit::Volume::CubicMicroinch, {
    {Unit::Volume::CubicMile, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(63360000000.0, 3);});}},
    {Unit::Volume::CubicKilometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000000000254, 3);});}},
    {Unit::Volume::CubicYard, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(36000000.0, 3);});}},
    {Unit::Volume::CubicMetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000000254, 3);});}},
    {Unit::Volume::CubicFoot, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12000000.0, 3);});}},
    {Unit::Volume::CubicDecimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000000254, 3);});}},
    {Unit::Volume::Litre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000000254, 3);});}},
    {Unit::Volume::CubicInch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.000001, 3);});}},
    {Unit::Volume::CubicCentimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00000254, 3);});}},
    {Unit::Volume::Millilitre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.00000254, 3);});}},
    {Unit::Volume::CubicMillimetre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0000254, 3);});}},
    {Unit::Volume::CubicMilliinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 3);});}},
    {Unit::Volume::CubicMicrometre, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 3);});}},
    {Unit::Volume::CubicMicroinch, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
