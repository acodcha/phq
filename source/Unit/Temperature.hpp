#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Temperature : uint_least8_t {
  Kelvin,
  Celsius,
  Rankine,
  Fahrenheit
};

} // namespace Unit

template <> const std::map<System, Unit::Temperature> consistent_units<Unit::Temperature>{
  {System::MetreKilogramSecondKelvin, Unit::Temperature::Kelvin},
  {System::CentimetreGramSecondKelvin, Unit::Temperature::Kelvin},
  {System::MillimetreGramSecondKelvin, Unit::Temperature::Kelvin},
  {System::FootPoundSecondRankine, Unit::Temperature::Rankine},
  {System::InchPoundSecondRankine, Unit::Temperature::Rankine}
};

template <> constexpr const Unit::Temperature standard_unit<Unit::Temperature>{Unit::Temperature::Kelvin};

template <> constexpr const Dimension::Set dimension<Unit::Temperature>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{}, Dimension::ElectricCurrent{}, Dimension::Temperature{1}}};

template <> const std::map<Unit::Temperature, std::string> abbreviations<Unit::Temperature>{
  {Unit::Temperature::Kelvin, "K"},
  {Unit::Temperature::Celsius, "°C"},
  {Unit::Temperature::Rankine, "°R"},
  {Unit::Temperature::Fahrenheit, "°F"}
};

template <> const std::unordered_map<std::string, Unit::Temperature> spellings<Unit::Temperature>{
  {"K", Unit::Temperature::Kelvin},
  {"°K", Unit::Temperature::Kelvin},
  {"degK", Unit::Temperature::Kelvin},
  {"deg K", Unit::Temperature::Kelvin},
  {"°C", Unit::Temperature::Celsius},
  {"C", Unit::Temperature::Celsius},
  {"degC", Unit::Temperature::Celsius},
  {"deg C", Unit::Temperature::Celsius},
  {"°R", Unit::Temperature::Rankine},
  {"R", Unit::Temperature::Rankine},
  {"degR", Unit::Temperature::Rankine},
  {"deg R", Unit::Temperature::Rankine},
  {"°F", Unit::Temperature::Fahrenheit},
  {"F", Unit::Temperature::Fahrenheit},
  {"degF", Unit::Temperature::Fahrenheit},
  {"deg F", Unit::Temperature::Fahrenheit}
};

template <size_t size> const std::map<Unit::Temperature, std::map<Unit::Temperature, std::function<void(std::array<double, size>&)>>> conversions<Unit::Temperature, size>{
  {Unit::Temperature::Kelvin, {
    {Unit::Temperature::Celsius, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value - 273.15;});}},
    {Unit::Temperature::Rankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value * 9.0 / 5.0;});}},
    {Unit::Temperature::Fahrenheit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value * 9.0 / 5.0) - 459.67;});}}}},
  {Unit::Temperature::Celsius, {
    {Unit::Temperature::Kelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value + 273.15;});}},
    {Unit::Temperature::Rankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value + 273.15) * 9.0 / 5.0;});}},
    {Unit::Temperature::Fahrenheit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value * 9.0 / 5.0) + 32.0;});}}}},
  {Unit::Temperature::Rankine, {
    {Unit::Temperature::Kelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value * 5.0 / 9.0;});}},
    {Unit::Temperature::Celsius, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value - 491.67) * 5.0 / 9.0;});}},
    {Unit::Temperature::Fahrenheit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value - 459.67;});}}}},
  {Unit::Temperature::Fahrenheit, {
    {Unit::Temperature::Kelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value + 459.67) * 5.0 / 9.0;});}},
    {Unit::Temperature::Celsius, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value - 32.0) * 5.0 / 9.0;});}},
    {Unit::Temperature::Rankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value + 459.67;});}}}}
};

} // namespace PhQ
