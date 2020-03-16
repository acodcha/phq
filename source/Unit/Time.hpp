#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Time : uint_least8_t {
  Second,
  Minute,
  Hour
};

template <> constexpr const Time standard<Time>{Time::Second};

template <> constexpr const Dimension::Set dimension<Time>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{1}}};

template <> const std::map<Time, std::string> abbreviations<Time>{
  {Time::Second, "s"},
  {Time::Minute, "min"},
  {Time::Hour, "hr"}
};

template <> const std::unordered_map<std::string, Time> spellings<Time>{
  {"s", Time::Second},
  {"sec", Time::Second},
  {"secs", Time::Second},
  {"min", Time::Minute},
  {"mins", Time::Minute},
  {"hr", Time::Hour},
  {"hrs", Time::Hour},
};

template <size_t size> const std::map<Time, std::map<Time, std::function<void(std::array<double, size>&)>>> conversions<Time, size>{
  {Time::Second, {
    {Time::Minute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 60.0;});}},
    {Time::Hour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 3600.0;});}}}},
  {Time::Minute, {
    {Time::Second, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 60.0;});}},
    {Time::Hour, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 60.0;});}}}},
  {Time::Hour, {
    {Time::Second, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 3600.0;});}},
    {Time::Minute, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 60.0;});}}}}
};

} // namespace Unit

template <> const std::map<System, Unit::Time> consistent_units<Unit::Time>{
  {System::MetreKilogramSecondKelvin, Unit::Time::Second},
  {System::CentimetreGramSecondKelvin, Unit::Time::Second},
  {System::MillimetreGramSecondKelvin, Unit::Time::Second},
  {System::FootPoundSecondRankine, Unit::Time::Second},
  {System::InchPoundSecondRankine, Unit::Time::Second}
};

} // namespace PhQ
