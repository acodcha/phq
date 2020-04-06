// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Length : uint_least8_t {
  Mile,
  Kilometre,
  Yard,
  Metre,
  Foot,
  Decimetre,
  Inch,
  Centimetre,
  Millimetre,
  Milliinch,
  Micrometre,
  Microinch
};

} // namespace Unit

template <> const std::map<Unit::Length, std::string> abbreviations<Unit::Length>{
  {Unit::Length::Mile, "mi"},
  {Unit::Length::Kilometre, "km"},
  {Unit::Length::Yard, "yd"},
  {Unit::Length::Metre, "m"},
  {Unit::Length::Foot, "ft"},
  {Unit::Length::Decimetre, "dm"},
  {Unit::Length::Inch, "in"},
  {Unit::Length::Centimetre, "cm"},
  {Unit::Length::Millimetre, "mm"},
  {Unit::Length::Milliinch, "thou"},
  {Unit::Length::Micrometre, "μm"},
  {Unit::Length::Microinch, "μin"}
};

template <> const std::unordered_map<std::string, Unit::Length> spellings<Unit::Length>{
  {"mi", Unit::Length::Mile},
  {"mile", Unit::Length::Mile},
  {"miles", Unit::Length::Mile},
  {"km", Unit::Length::Kilometre},
  {"kilometer", Unit::Length::Kilometre},
  {"kilometers", Unit::Length::Kilometre},
  {"kilometre", Unit::Length::Kilometre},
  {"kilometres", Unit::Length::Kilometre},
  {"yd", Unit::Length::Yard},
  {"yard", Unit::Length::Yard},
  {"yards", Unit::Length::Yard},
  {"m", Unit::Length::Metre},
  {"meter", Unit::Length::Metre},
  {"meters", Unit::Length::Metre},
  {"metre", Unit::Length::Metre},
  {"metres", Unit::Length::Metre},
  {"ft", Unit::Length::Foot},
  {"foot", Unit::Length::Foot},
  {"feet", Unit::Length::Foot},
  {"dm", Unit::Length::Decimetre},
  {"decimeter", Unit::Length::Decimetre},
  {"decimeters", Unit::Length::Decimetre},
  {"decimetre", Unit::Length::Decimetre},
  {"decimetres", Unit::Length::Decimetre},
  {"in", Unit::Length::Inch},
  {"inch", Unit::Length::Inch},
  {"inches", Unit::Length::Inch},
  {"cm", Unit::Length::Centimetre},
  {"centimeter", Unit::Length::Centimetre},
  {"centimeters", Unit::Length::Centimetre},
  {"centimetre", Unit::Length::Centimetre},
  {"centimetres", Unit::Length::Centimetre},
  {"mm", Unit::Length::Millimetre},
  {"millimeter", Unit::Length::Millimetre},
  {"millimeters", Unit::Length::Millimetre},
  {"millimetre", Unit::Length::Millimetre},
  {"millimetres", Unit::Length::Millimetre},
  {"milin", Unit::Length::Milliinch},
  {"milliinch", Unit::Length::Milliinch},
  {"milliinches", Unit::Length::Milliinch},
  {"thou", Unit::Length::Milliinch},
  {"thous", Unit::Length::Milliinch},
  {"thousandth", Unit::Length::Milliinch},
  {"thousandths", Unit::Length::Milliinch},
  {"mil", Unit::Length::Milliinch},
  {"mils", Unit::Length::Milliinch},
  {"μm", Unit::Length::Micrometre},
  {"um", Unit::Length::Micrometre},
  {"micrometer", Unit::Length::Micrometre},
  {"micrometers", Unit::Length::Micrometre},
  {"Micrometre", Unit::Length::Micrometre},
  {"Micrometres", Unit::Length::Micrometre},
  {"micron", Unit::Length::Micrometre},
  {"microns", Unit::Length::Micrometre},
  {"μin", Unit::Length::Microinch},
  {"uin", Unit::Length::Microinch},
  {"microinch", Unit::Length::Microinch},
  {"microinches", Unit::Length::Microinch}
};

template <> const std::map<System, Unit::Length> consistent_units<Unit::Length>{
  {System::MetreKilogramSecondKelvin, Unit::Length::Metre},
  {System::MillimetreGramSecondKelvin, Unit::Length::Millimetre},
  {System::FootPoundSecondRankine, Unit::Length::Foot},
  {System::InchPoundSecondRankine, Unit::Length::Inch}
};

template <> const std::map<Unit::Length, System> related_systems<Unit::Length>{
  {Unit::Length::Metre, System::MetreKilogramSecondKelvin},
  {Unit::Length::Millimetre, System::MillimetreGramSecondKelvin},
  {Unit::Length::Foot, System::FootPoundSecondRankine},
  {Unit::Length::Inch, System::InchPoundSecondRankine},
};

template <> constexpr const Unit::Length standard_unit<Unit::Length>{Unit::Length::Metre};

template <> constexpr const Dimension::Set dimension<Unit::Length>{Dimension::Set{Dimension::Length{1}}};

template <size_t size> const std::map<Unit::Length, std::map<Unit::Length, std::function<void(std::array<double, size>&)>>> conversions<Unit::Length, size>{
  {Unit::Length::Mile, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1.609344;});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1760.0;});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1609.344;});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 5280.0;});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 16093.44;});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 63360.0;});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 160934.4;});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1609344.0;});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 63360000.0;});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1609344000.0;});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 63360000000.0;});}}}},
  {Unit::Length::Kilometre, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1.609344;});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0009144;});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0003048;});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10000.0;});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000254;});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100000.0;});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000000254;});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000000.0;});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000000000254;});}}}},
  {Unit::Length::Yard, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1760.0;});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0009144;});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.9144;});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 3.0;});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 9.144;});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 36.0;});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 91.44;});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 914.4;});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 36000.0;});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 914400.0;});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 36000000.0;});}}}},
  {Unit::Length::Metre, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1609.344;});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.9144;});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.3048;});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10.0;});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0254;});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100.0;});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000254;});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000000254;});}}}},
  {Unit::Length::Foot, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 5280.0;});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0003048;});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 3.0;});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.3048;});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 3.048;});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 12.0;});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 30.48;});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 304.8;});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 12000.0;});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 304800.0;});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 12000000.0;});}}}},
  {Unit::Length::Decimetre, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 16093.44;});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0001;});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 9.144;});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.1;});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 3.048;});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.254;});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10.0;});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100.0;});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.000254;});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100000.0;});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.000000254;});}}}},
  {Unit::Length::Inch, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 63360.0;});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000254;});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 36.0;});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0254;});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 12.0;});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.254;});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 2.54;});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 25.4;});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 25400.0;});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}}}},
  {Unit::Length::Centimetre, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 160934.4;});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00001;});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 91.44;});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.01;});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 30.48;});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.1;});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 2.54;});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10.0;});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.00254;});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10000.0;});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.00000254;});}}}},
  {Unit::Length::Millimetre, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1609344.0;});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 914.4;});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 304.8;});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.01;});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 25.4;});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.1;});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0254;});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000254;});}}}},
  {Unit::Length::Milliinch, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 63360000.0;});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000000254;});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 36000.0;});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000254;});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 12000.0;});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000254;});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00254;});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0254;});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 25.4;});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}}}},
  {Unit::Length::Micrometre, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1609344000.0;});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000000001;});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 914400.0;});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 304800.0;});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00001;});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 25400.0;});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0001;});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 25.4;});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0254;});}}}},
  {Unit::Length::Microinch, {
    {Unit::Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 63360000000.0;});}},
    {Unit::Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000000000254;});}},
    {Unit::Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 36000000.0;});}},
    {Unit::Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000000254;});}},
    {Unit::Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 12000000.0;});}},
    {Unit::Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000000254;});}},
    {Unit::Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}},
    {Unit::Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00000254;});}},
    {Unit::Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000254;});}},
    {Unit::Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0254;});}},
    {Unit::Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}}}
};

} // namespace PhQ
