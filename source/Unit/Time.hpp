#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Time : uint_least8_t {
  Second,
  Minute,
  Hour
};

} // namespace Unit

template <> const std::map<System, Unit::Time> consistent_units<Unit::Time>{
  {System::MetreKilogramSecondKelvin, Unit::Time::Second},
  {System::CentimetreGramSecondKelvin, Unit::Time::Second},
  {System::MillimetreGramSecondKelvin, Unit::Time::Second},
  {System::FootPoundSecondRankine, Unit::Time::Second},
  {System::InchPoundSecondRankine, Unit::Time::Second}
};

template <> constexpr const Unit::Time standard_unit<Unit::Time>{Unit::Time::Second};

template <> constexpr const Dimension::Set dimension<Unit::Time>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{1}}};

template <> const std::map<Unit::Time, std::string> abbreviations<Unit::Time>{
  {Unit::Time::Second, "s"},
  {Unit::Time::Minute, "min"},
  {Unit::Time::Hour, "hr"}
};

template <> const std::unordered_map<std::string, Unit::Time> spellings<Unit::Time>{
  {"s", Unit::Time::Second},
  {"sec", Unit::Time::Second},
  {"secs", Unit::Time::Second},
  {"min", Unit::Time::Minute},
  {"mins", Unit::Time::Minute},
  {"hr", Unit::Time::Hour},
  {"hrs", Unit::Time::Hour},
};

template <size_t size> const std::map<Unit::Time, std::map<Unit::Time, std::function<void(std::array<double, size>&)>>> conversions<Unit::Time, size>{
  {Unit::Time::Second, {
    {Unit::Time::Minute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 60.0;});}},
    {Unit::Time::Hour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 3600.0;});}}}},
  {Unit::Time::Minute, {
    {Unit::Time::Second, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 60.0;});}},
    {Unit::Time::Hour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 60.0;});}}}},
  {Unit::Time::Hour, {
    {Unit::Time::Second, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 3600.0;});}},
    {Unit::Time::Minute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 60.0;});}}}}
};

} // namespace PhQ
