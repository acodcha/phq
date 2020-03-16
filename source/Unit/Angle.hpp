#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Angle : uint_least8_t {
  Radian,
  Degree,
  Arcminute,
  Arcsecond
};

template <> constexpr const Dimension::Set dimension<Angle>{Dimension::Set{}};

template <> const std::map<Angle, std::string> abbreviations<Angle>{
  {Angle::Radian, "rad"},
  {Angle::Degree, "deg"},
  {Angle::Arcminute, "'"},
  {Angle::Arcsecond, "\""}
};

template <> const std::unordered_map<std::string, Angle> spellings<Angle>{
  {"rad", Angle::Radian},
  {"rads", Angle::Radian},
  {"deg", Angle::Degree},
  {"degs", Angle::Degree},
  {"°", Angle::Degree},
  {"'", Angle::Arcminute},
  {"am", Angle::Arcminute},
  {"arcmin", Angle::Arcminute},
  {"\"", Angle::Arcsecond},
  {"as", Angle::Arcsecond},
  {"arcsec", Angle::Arcsecond}
};

template <size_t size> const std::map<Angle, std::map<Angle, std::function<void(std::array<double, size>&)>>> conversions<Angle, size>{
  {Angle::Radian, {
    {Angle::Degree, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 180.0 / M_PI;});}},
    {Angle::Arcminute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10800.0 / M_PI;});}},
    {Angle::Arcsecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 648000.0 / M_PI;});}}}},
  {Angle::Degree, {
    {Angle::Radian, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= M_PI / 180.0;});}},
    {Angle::Arcminute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 60.0;});}},
    {Angle::Arcsecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 3600.0;});}}}},
  {Angle::Arcminute, {
    {Angle::Radian, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= M_PI / 10800.0;});}},
    {Angle::Degree, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 60.0;});}},
    {Angle::Arcsecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 60.0;});}}}},
  {Angle::Arcsecond, {
    {Angle::Radian, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= M_PI / 648000.0;});}},
    {Angle::Degree, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 3600.0;});}},
    {Angle::Arcminute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 60.0;});}}}}
};

} // namespace Unit

template <> const std::map<System, Unit::Angle> consistent_units<Unit::Angle>{
  {System::MetreKilogramSecondKelvin, Unit::Angle::Radian},
  {System::CentimetreGramSecondKelvin, Unit::Angle::Radian},
  {System::MillimetreGramSecondKelvin, Unit::Angle::Radian},
  {System::FootPoundSecondRankine, Unit::Angle::Radian},
  {System::InchPoundSecondRankine, Unit::Angle::Radian}
};

} // namespace PhQ
