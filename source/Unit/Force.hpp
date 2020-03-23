#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Force : uint_least8_t {
  Newton,
  Micronewton,
  Pound
};

} // namespace Unit

template <> const std::map<System, Unit::Force> consistent_units<Unit::Force>{
  {System::MetreKilogramSecondKelvin, Unit::Force::Newton},
  {System::MillimetreGramSecondKelvin, Unit::Force::Micronewton},
  {System::FootPoundSecondRankine, Unit::Force::Pound},
  {System::InchPoundSecondRankine, Unit::Force::Pound}
};

template <> constexpr const Unit::Force standard_unit<Unit::Force>{Unit::Force::Newton};

template <> constexpr const Dimension::Set dimension<Unit::Force>{Dimension::Set{Dimension::Length{1}, Dimension::Mass{1}, Dimension::Time{-2}}};

template <> const std::map<Unit::Force, std::string> abbreviations<Unit::Force>{
  {Unit::Force::Newton, "N"},
  {Unit::Force::Micronewton, "μN"},
  {Unit::Force::Pound, "lbf"}
};

template <> const std::unordered_map<std::string, Unit::Force> spellings<Unit::Force>{
  {"N", Unit::Force::Newton},
  {"kg*m/s^2", Unit::Force::Newton},
  {"kg*m/s2", Unit::Force::Newton},
  {"μN", Unit::Force::Micronewton},
  {"uN", Unit::Force::Micronewton},
  {"g*mm/s^2", Unit::Force::Micronewton},
  {"g*mm/s2", Unit::Force::Micronewton},
  {"lbf", Unit::Force::Pound},
  {"lb", Unit::Force::Pound}
};

template <size_t size> const std::map<Unit::Force, std::map<Unit::Force, std::function<void(std::array<double, size>&)>>> conversions<Unit::Force, size>{
  {Unit::Force::Newton, {
    {Unit::Force::Micronewton, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}},
    {Unit::Force::Pound, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 0.45359237 * 9.80665;});}}}},
  {Unit::Force::Micronewton, {
    {Unit::Force::Newton, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}},
    {Unit::Force::Pound, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 453592.37 * 9.80665;});}}}},
  {Unit::Force::Pound, {
    {Unit::Force::Newton, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.45359237 * 9.80665;});}},
    {Unit::Force::Micronewton, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 453592.37 * 9.80665;});}}}}
};

} // namespace PhQ
