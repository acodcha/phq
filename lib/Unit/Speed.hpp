#pragma once

#include "Length.hpp"
#include "Time.hpp"

namespace PhQ {

namespace Unit {

enum class Speed : uint_least8_t {
  MilePerSecond,
  KilometrePerSecond,
  YardPerSecond,
  MetrePerSecond,
  FootPerSecond,
  DecimetrePerSecond,
  InchPerSecond,
  CentimetrePerSecond,
  MillimetrePerSecond,
  MilliinchPerSecond,
  MicrometrePerSecond,
  MicroinchPerSecond
};

} // namespace Unit

template <> const std::map<Unit::Speed, std::string> abbreviations<Unit::Speed>{
  {Unit::Speed::MilePerSecond, "mi/s"},
  {Unit::Speed::KilometrePerSecond, "km/s"},
  {Unit::Speed::YardPerSecond, "yd/s"},
  {Unit::Speed::MetrePerSecond, "m/s"},
  {Unit::Speed::FootPerSecond, "ft/s"},
  {Unit::Speed::DecimetrePerSecond, "dm/s"},
  {Unit::Speed::InchPerSecond, "in/s"},
  {Unit::Speed::CentimetrePerSecond, "cm/s"},
  {Unit::Speed::MillimetrePerSecond, "mm/s"},
  {Unit::Speed::MilliinchPerSecond, "thou/s"},
  {Unit::Speed::MicrometrePerSecond, "μm/s"},
  {Unit::Speed::MicroinchPerSecond, "μin/s"}
};

template <> const std::unordered_map<std::string, Unit::Speed> spellings<Unit::Speed>{
  {"mi/s", Unit::Speed::MilePerSecond},
  {"mi/sec", Unit::Speed::MilePerSecond},
  {"km/s", Unit::Speed::KilometrePerSecond},
  {"km/sec", Unit::Speed::KilometrePerSecond},
  {"yd/s", Unit::Speed::YardPerSecond},
  {"yd/sec", Unit::Speed::YardPerSecond},
  {"m/s", Unit::Speed::MetrePerSecond},
  {"m/sec", Unit::Speed::MetrePerSecond},
  {"ft/s", Unit::Speed::FootPerSecond},
  {"ft/sec", Unit::Speed::FootPerSecond},
  {"dm/s", Unit::Speed::DecimetrePerSecond},
  {"dm/sec", Unit::Speed::DecimetrePerSecond},
  {"in/s", Unit::Speed::InchPerSecond},
  {"in/sec", Unit::Speed::InchPerSecond},
  {"cm/s", Unit::Speed::CentimetrePerSecond},
  {"cm/sec", Unit::Speed::CentimetrePerSecond},
  {"mm/s", Unit::Speed::MillimetrePerSecond},
  {"mm/sec", Unit::Speed::MillimetrePerSecond},
  {"milin/s", Unit::Speed::MilliinchPerSecond},
  {"milin/sec", Unit::Speed::MilliinchPerSecond},
  {"milliinch/s", Unit::Speed::MilliinchPerSecond},
  {"milliinch/sec", Unit::Speed::MilliinchPerSecond},
  {"thou/s", Unit::Speed::MilliinchPerSecond},
  {"thou/sec", Unit::Speed::MilliinchPerSecond},
  {"mil/s", Unit::Speed::MilliinchPerSecond},
  {"mil/sec", Unit::Speed::MilliinchPerSecond},
  {"μm/s", Unit::Speed::MicrometrePerSecond},
  {"μm/sec", Unit::Speed::MicrometrePerSecond},
  {"um/s", Unit::Speed::MicrometrePerSecond},
  {"um/sec", Unit::Speed::MicrometrePerSecond},
  {"μin/s", Unit::Speed::MicroinchPerSecond},
  {"μin/sec", Unit::Speed::MicroinchPerSecond},
  {"uin/s", Unit::Speed::MicroinchPerSecond},
  {"uin/sec", Unit::Speed::MicroinchPerSecond},
};

template <> const std::map<System, Unit::Speed> consistent_units<Unit::Speed>{
  {System::MetreKilogramSecondKelvin, Unit::Speed::MetrePerSecond},
  {System::MillimetreGramSecondKelvin, Unit::Speed::MillimetrePerSecond},
  {System::FootPoundSecondRankine, Unit::Speed::FootPerSecond},
  {System::InchPoundSecondRankine, Unit::Speed::InchPerSecond}
};

template <> const std::map<Unit::Speed, System> related_systems<Unit::Speed>{
  {Unit::Speed::MetrePerSecond, System::MetreKilogramSecondKelvin},
  {Unit::Speed::MillimetrePerSecond, System::MillimetreGramSecondKelvin},
  {Unit::Speed::FootPerSecond, System::FootPoundSecondRankine},
  {Unit::Speed::InchPerSecond, System::InchPoundSecondRankine},
};

template <> constexpr const Unit::Speed standard_unit<Unit::Speed>{Unit::Speed::MetrePerSecond};

template <> constexpr const Dimension::Set dimension<Unit::Speed>{Dimension::Set{Dimension::Length{1}, Dimension::Mass{}, Dimension::Time{-1}}};

template <> const std::map<Unit::Speed, Unit::Length> related_units<Unit::Speed, Unit::Length> {
  {Unit::Speed::MetrePerSecond, Unit::Length::Metre},
  {Unit::Speed::DecimetrePerSecond, Unit::Length::Decimetre},
  {Unit::Speed::CentimetrePerSecond, Unit::Length::Centimetre},
  {Unit::Speed::MillimetrePerSecond, Unit::Length::Millimetre},
  {Unit::Speed::MicrometrePerSecond, Unit::Length::Micrometre},
  {Unit::Speed::KilometrePerSecond, Unit::Length::Kilometre},
  {Unit::Speed::MilePerSecond, Unit::Length::Mile},
  {Unit::Speed::YardPerSecond, Unit::Length::Yard},
  {Unit::Speed::FootPerSecond, Unit::Length::Foot},
  {Unit::Speed::InchPerSecond, Unit::Length::Inch},
  {Unit::Speed::MilliinchPerSecond, Unit::Length::Milliinch}
};

template <> const std::map<Unit::Speed, Unit::Time> related_units<Unit::Speed, Unit::Time> {
  {Unit::Speed::MetrePerSecond, Unit::Time::Second},
  {Unit::Speed::DecimetrePerSecond, Unit::Time::Second},
  {Unit::Speed::CentimetrePerSecond, Unit::Time::Second},
  {Unit::Speed::MillimetrePerSecond, Unit::Time::Second},
  {Unit::Speed::MicrometrePerSecond, Unit::Time::Second},
  {Unit::Speed::KilometrePerSecond, Unit::Time::Second},
  {Unit::Speed::MilePerSecond, Unit::Time::Second},
  {Unit::Speed::YardPerSecond, Unit::Time::Second},
  {Unit::Speed::FootPerSecond, Unit::Time::Second},
  {Unit::Speed::InchPerSecond, Unit::Time::Second},
  {Unit::Speed::MilliinchPerSecond, Unit::Time::Second}
};

template <size_t size> const std::map<Unit::Speed, std::map<Unit::Speed, std::function<void(std::array<double, size>&)>>> conversions<Unit::Speed, size>{
  {Unit::Speed::MilePerSecond, {
    {Unit::Speed::KilometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1.609344;});}},
    {Unit::Speed::YardPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1760.0;});}},
    {Unit::Speed::MetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1609.344;});}},
    {Unit::Speed::FootPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 5280.0;});}},
    {Unit::Speed::DecimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 16093.44;});}},
    {Unit::Speed::InchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 63360.0;});}},
    {Unit::Speed::CentimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 160934.4;});}},
    {Unit::Speed::MillimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1609344.0;});}},
    {Unit::Speed::MilliinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 63360000.0;});}},
    {Unit::Speed::MicrometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1609344000.0;});}},
    {Unit::Speed::MicroinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 63360000000.0;});}}}},
  {Unit::Speed::KilometrePerSecond, {
    {Unit::Speed::MilePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1.609344;});}},
    {Unit::Speed::YardPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0009144;});}},
    {Unit::Speed::MetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Unit::Speed::FootPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0003048;});}},
    {Unit::Speed::DecimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10000.0;});}},
    {Unit::Speed::InchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000254;});}},
    {Unit::Speed::CentimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100000.0;});}},
    {Unit::Speed::MillimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}},
    {Unit::Speed::MilliinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000000254;});}},
    {Unit::Speed::MicrometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000000.0;});}},
    {Unit::Speed::MicroinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000000000254;});}}}},
  {Unit::Speed::YardPerSecond, {
    {Unit::Speed::MilePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1760.0;});}},
    {Unit::Speed::KilometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0009144;});}},
    {Unit::Speed::MetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.9144;});}},
    {Unit::Speed::FootPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 3.0;});}},
    {Unit::Speed::DecimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 9.144;});}},
    {Unit::Speed::InchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 36.0;});}},
    {Unit::Speed::CentimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 91.44;});}},
    {Unit::Speed::MillimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 914.4;});}},
    {Unit::Speed::MilliinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 36000.0;});}},
    {Unit::Speed::MicrometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 914400.0;});}},
    {Unit::Speed::MicroinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 36000000.0;});}}}},
  {Unit::Speed::MetrePerSecond, {
    {Unit::Speed::MilePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1609.344;});}},
    {Unit::Speed::KilometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Speed::YardPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.9144;});}},
    {Unit::Speed::FootPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.3048;});}},
    {Unit::Speed::DecimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10.0;});}},
    {Unit::Speed::InchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0254;});}},
    {Unit::Speed::CentimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100.0;});}},
    {Unit::Speed::MillimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Unit::Speed::MilliinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000254;});}},
    {Unit::Speed::MicrometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}},
    {Unit::Speed::MicroinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000000254;});}}}},
  {Unit::Speed::FootPerSecond, {
    {Unit::Speed::MilePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 5280.0;});}},
    {Unit::Speed::KilometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0003048;});}},
    {Unit::Speed::YardPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 3.0;});}},
    {Unit::Speed::MetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.3048;});}},
    {Unit::Speed::DecimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 3.048;});}},
    {Unit::Speed::InchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 12.0;});}},
    {Unit::Speed::CentimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 30.48;});}},
    {Unit::Speed::MillimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 304.8;});}},
    {Unit::Speed::MilliinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 12000.0;});}},
    {Unit::Speed::MicrometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 304800.0;});}},
    {Unit::Speed::MicroinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 12000000.0;});}}}},
  {Unit::Speed::DecimetrePerSecond, {
    {Unit::Speed::MilePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 16093.44;});}},
    {Unit::Speed::KilometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0001;});}},
    {Unit::Speed::YardPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 9.144;});}},
    {Unit::Speed::MetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.1;});}},
    {Unit::Speed::FootPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 3.048;});}},
    {Unit::Speed::InchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.254;});}},
    {Unit::Speed::CentimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10.0;});}},
    {Unit::Speed::MillimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100.0;});}},
    {Unit::Speed::MilliinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.000254;});}},
    {Unit::Speed::MicrometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 100000.0;});}},
    {Unit::Speed::MicroinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.000000254;});}}}},
  {Unit::Speed::InchPerSecond, {
    {Unit::Speed::MilePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 63360.0;});}},
    {Unit::Speed::KilometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000254;});}},
    {Unit::Speed::YardPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 36.0;});}},
    {Unit::Speed::MetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0254;});}},
    {Unit::Speed::FootPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 12.0;});}},
    {Unit::Speed::DecimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.254;});}},
    {Unit::Speed::CentimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 2.54;});}},
    {Unit::Speed::MillimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 25.4;});}},
    {Unit::Speed::MilliinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Unit::Speed::MicrometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 25400.0;});}},
    {Unit::Speed::MicroinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}}}},
  {Unit::Speed::CentimetrePerSecond, {
    {Unit::Speed::MilePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 160934.4;});}},
    {Unit::Speed::KilometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00001;});}},
    {Unit::Speed::YardPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 91.44;});}},
    {Unit::Speed::MetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.01;});}},
    {Unit::Speed::FootPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 30.48;});}},
    {Unit::Speed::DecimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.1;});}},
    {Unit::Speed::InchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 2.54;});}},
    {Unit::Speed::MillimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10.0;});}},
    {Unit::Speed::MilliinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.00254;});}},
    {Unit::Speed::MicrometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 10000.0;});}},
    {Unit::Speed::MicroinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.00000254;});}}}},
  {Unit::Speed::MillimetrePerSecond, {
    {Unit::Speed::MilePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1609344.0;});}},
    {Unit::Speed::KilometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}},
    {Unit::Speed::YardPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 914.4;});}},
    {Unit::Speed::MetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Speed::FootPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 304.8;});}},
    {Unit::Speed::DecimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.01;});}},
    {Unit::Speed::InchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 25.4;});}},
    {Unit::Speed::CentimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.1;});}},
    {Unit::Speed::MilliinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0254;});}},
    {Unit::Speed::MicrometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Unit::Speed::MicroinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0000254;});}}}},
  {Unit::Speed::MilliinchPerSecond, {
    {Unit::Speed::MilePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 63360000.0;});}},
    {Unit::Speed::KilometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000000254;});}},
    {Unit::Speed::YardPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 36000.0;});}},
    {Unit::Speed::MetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000254;});}},
    {Unit::Speed::FootPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 12000.0;});}},
    {Unit::Speed::DecimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000254;});}},
    {Unit::Speed::InchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Speed::CentimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00254;});}},
    {Unit::Speed::MillimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0254;});}},
    {Unit::Speed::MicrometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 25.4;});}},
    {Unit::Speed::MicroinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}}}},
  {Unit::Speed::MicrometrePerSecond, {
    {Unit::Speed::MilePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1609344000.0;});}},
    {Unit::Speed::KilometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000000001;});}},
    {Unit::Speed::YardPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 914400.0;});}},
    {Unit::Speed::MetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}},
    {Unit::Speed::FootPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 304800.0;});}},
    {Unit::Speed::DecimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00001;});}},
    {Unit::Speed::InchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 25400.0;});}},
    {Unit::Speed::CentimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0001;});}},
    {Unit::Speed::MillimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Speed::MilliinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 25.4;});}},
    {Unit::Speed::MicroinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.0254;});}}}},
  {Unit::Speed::MicroinchPerSecond, {
    {Unit::Speed::MilePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 63360000000.0;});}},
    {Unit::Speed::KilometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000000000254;});}},
    {Unit::Speed::YardPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 36000000.0;});}},
    {Unit::Speed::MetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000000254;});}},
    {Unit::Speed::FootPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 12000000.0;});}},
    {Unit::Speed::DecimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000000254;});}},
    {Unit::Speed::InchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}},
    {Unit::Speed::CentimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.00000254;});}},
    {Unit::Speed::MillimetrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0000254;});}},
    {Unit::Speed::MilliinchPerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Speed::MicrometrePerSecond, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.0254;});}}}}
};

} // namespace PhQ
