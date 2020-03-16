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

template <> constexpr const Length standard<Length>{Length::Metre};

template <> constexpr const Dimension::Set dimension<Length>{Dimension::Set{Dimension::Length{1}}};

template <> const std::map<Length, std::string> abbreviations<Length>{
  {Length::Mile, "mi"},
  {Length::Kilometre, "km"},
  {Length::Yard, "yd"},
  {Length::Metre, "m"},
  {Length::Foot, "ft"},
  {Length::Decimetre, "dm"},
  {Length::Inch, "in"},
  {Length::Centimetre, "cm"},
  {Length::Millimetre, "mm"},
  {Length::Milliinch, "thou"},
  {Length::Micrometre, "μm"},
  {Length::Microinch, "μin"}
};

template <> const std::unordered_map<std::string, Length> spellings<Length>{
  {"mi", Length::Mile},
  {"mile", Length::Mile},
  {"miles", Length::Mile},
  {"km", Length::Kilometre},
  {"kilometer", Length::Kilometre},
  {"kilometers", Length::Kilometre},
  {"kilometre", Length::Kilometre},
  {"kilometres", Length::Kilometre},
  {"yd", Length::Yard},
  {"yard", Length::Yard},
  {"yards", Length::Yard},
  {"m", Length::Metre},
  {"meter", Length::Metre},
  {"meters", Length::Metre},
  {"metre", Length::Metre},
  {"metres", Length::Metre},
  {"ft", Length::Foot},
  {"foot", Length::Foot},
  {"feet", Length::Foot},
  {"dm", Length::Decimetre},
  {"decimeter", Length::Decimetre},
  {"decimeters", Length::Decimetre},
  {"decimetre", Length::Decimetre},
  {"decimetres", Length::Decimetre},
  {"in", Length::Inch},
  {"inch", Length::Inch},
  {"inches", Length::Inch},
  {"cm", Length::Centimetre},
  {"centimeter", Length::Centimetre},
  {"centimeters", Length::Centimetre},
  {"centimetre", Length::Centimetre},
  {"centimetres", Length::Centimetre},
  {"mm", Length::Millimetre},
  {"millimeter", Length::Millimetre},
  {"millimeters", Length::Millimetre},
  {"millimetre", Length::Millimetre},
  {"millimetres", Length::Millimetre},
  {"milin", Length::Milliinch},
  {"milliinch", Length::Milliinch},
  {"milliinches", Length::Milliinch},
  {"thou", Length::Milliinch},
  {"thous", Length::Milliinch},
  {"thousandth", Length::Milliinch},
  {"thousandths", Length::Milliinch},
  {"mil", Length::Milliinch},
  {"mils", Length::Milliinch},
  {"μm", Length::Micrometre},
  {"um", Length::Micrometre},
  {"micrometer", Length::Micrometre},
  {"micrometers", Length::Micrometre},
  {"Micrometre", Length::Micrometre},
  {"Micrometres", Length::Micrometre},
  {"micron", Length::Micrometre},
  {"microns", Length::Micrometre},
  {"μin", Length::Microinch},
  {"uin", Length::Microinch},
  {"microinch", Length::Microinch},
  {"microinches", Length::Microinch}
};

template <size_t size> const std::map<Length, std::map<Length, std::function<void(std::array<double, size>&)>>> conversions<Length, size>{
  {Length::Mile, {
    {Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1.609344;});}},
    {Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1760.0;});}},
    {Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1609.344;});}},
    {Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 5280.0;});}},
    {Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 16093.44;});}},
    {Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 63360.0;});}},
    {Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 160934.4;});}},
    {Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1609344.0;});}},
    {Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 63360000.0;});}},
    {Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1609344000.0;});}},
    {Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 63360000000.0;});}}}},
  {Length::Kilometre, {
    {Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1.609344;});}},
    {Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0009144;});}},
    {Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0003048;});}},
    {Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10000.0;});}},
    {Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000254;});}},
    {Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100000.0;});}},
    {Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}},
    {Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000000254;});}},
    {Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000000.0;});}},
    {Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000000000254;});}}}},
  {Length::Yard, {
    {Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1760.0;});}},
    {Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0009144;});}},
    {Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.9144;});}},
    {Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 3.0;});}},
    {Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 9.144;});}},
    {Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 36.0;});}},
    {Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 91.44;});}},
    {Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 914.4;});}},
    {Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 36000.0;});}},
    {Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 914400.0;});}},
    {Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 36000000.0;});}}}},
  {Length::Metre, {
    {Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1609.344;});}},
    {Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.9144;});}},
    {Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.3048;});}},
    {Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10.0;});}},
    {Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0254;});}},
    {Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100.0;});}},
    {Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000254;});}},
    {Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}},
    {Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000000254;});}}}},
  {Length::Foot, {
    {Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 5280.0;});}},
    {Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0003048;});}},
    {Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 3.0;});}},
    {Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.3048;});}},
    {Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 3.048;});}},
    {Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 12.0;});}},
    {Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 30.48;});}},
    {Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 304.8;});}},
    {Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 12000.0;});}},
    {Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 304800.0;});}},
    {Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 12000000.0;});}}}},
  {Length::Decimetre, {
    {Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 16093.44;});}},
    {Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0001;});}},
    {Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 9.144;});}},
    {Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.1;});}},
    {Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 3.048;});}},
    {Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.254;});}},
    {Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10.0;});}},
    {Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100.0;});}},
    {Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.000254;});}},
    {Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100000.0;});}},
    {Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.000000254;});}}}},
  {Length::Inch, {
    {Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 63360.0;});}},
    {Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000254;});}},
    {Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 36.0;});}},
    {Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0254;});}},
    {Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 12.0;});}},
    {Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.254;});}},
    {Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 2.54;});}},
    {Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 25.4;});}},
    {Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 25400.0;});}},
    {Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}}}},
  {Length::Centimetre, {
    {Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 160934.4;});}},
    {Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00001;});}},
    {Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 91.44;});}},
    {Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.01;});}},
    {Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 30.48;});}},
    {Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.1;});}},
    {Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 2.54;});}},
    {Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10.0;});}},
    {Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.00254;});}},
    {Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10000.0;});}},
    {Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.00000254;});}}}},
  {Length::Millimetre, {
    {Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1609344.0;});}},
    {Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}},
    {Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 914.4;});}},
    {Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 304.8;});}},
    {Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.01;});}},
    {Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 25.4;});}},
    {Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.1;});}},
    {Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0254;});}},
    {Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000254;});}}}},
  {Length::Milliinch, {
    {Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 63360000.0;});}},
    {Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000000254;});}},
    {Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 36000.0;});}},
    {Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000254;});}},
    {Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 12000.0;});}},
    {Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000254;});}},
    {Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00254;});}},
    {Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0254;});}},
    {Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 25.4;});}},
    {Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}}}},
  {Length::Micrometre, {
    {Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1609344000.0;});}},
    {Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000000001;});}},
    {Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 914400.0;});}},
    {Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}},
    {Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 304800.0;});}},
    {Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00001;});}},
    {Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 25400.0;});}},
    {Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0001;});}},
    {Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 25.4;});}},
    {Length::Microinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0254;});}}}},
  {Length::Microinch, {
    {Length::Mile, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 63360000000.0;});}},
    {Length::Kilometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000000000254;});}},
    {Length::Yard, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 36000000.0;});}},
    {Length::Metre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000000254;});}},
    {Length::Foot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 12000000.0;});}},
    {Length::Decimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000000254;});}},
    {Length::Inch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}},
    {Length::Centimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00000254;});}},
    {Length::Millimetre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000254;});}},
    {Length::Milliinch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Length::Micrometre, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0254;});}}}}
};

} // namespace Unit

template <> const std::map<System, Unit::Length> consistent_units<Unit::Length>{
  {System::MetreKilogramSecondKelvin, Unit::Length::Metre},
  {System::CentimetreGramSecondKelvin, Unit::Length::Centimetre},
  {System::MillimetreGramSecondKelvin, Unit::Length::Millimetre},
  {System::FootPoundSecondRankine, Unit::Length::Foot},
  {System::InchPoundSecondRankine, Unit::Length::Inch}
};

template <> const std::map<Unit::Length, System> related_systems<Unit::Length>{
  {Unit::Length::Metre, System::MetreKilogramSecondKelvin},
  {Unit::Length::Centimetre, System::CentimetreGramSecondKelvin},
  {Unit::Length::Millimetre, System::MillimetreGramSecondKelvin},
  {Unit::Length::Foot, System::FootPoundSecondRankine},
  {Unit::Length::Inch, System::InchPoundSecondRankine},
};

} // namespace PhQ
