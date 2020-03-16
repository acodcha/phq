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

template <> constexpr const Temperature standard<Temperature>{Temperature::Kelvin};

template <> constexpr const Dimension::Set dimension<Temperature>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{}, Dimension::ElectricCurrent{}, Dimension::Temperature{1}}};

template <> const std::map<Temperature, std::string> abbreviations<Temperature>{
  {Temperature::Kelvin, "K"},
  {Temperature::Celsius, "°C"},
  {Temperature::Rankine, "°R"},
  {Temperature::Fahrenheit, "°F"}
};

template <> const std::unordered_map<std::string, Temperature> spellings<Temperature>{
  {"K", Temperature::Kelvin},
  {"°K", Temperature::Kelvin},
  {"degK", Temperature::Kelvin},
  {"deg K", Temperature::Kelvin},
  {"°C", Temperature::Celsius},
  {"C", Temperature::Celsius},
  {"degC", Temperature::Celsius},
  {"deg C", Temperature::Celsius},
  {"°R", Temperature::Rankine},
  {"R", Temperature::Rankine},
  {"degR", Temperature::Rankine},
  {"deg R", Temperature::Rankine},
  {"°F", Temperature::Fahrenheit},
  {"F", Temperature::Fahrenheit},
  {"degF", Temperature::Fahrenheit},
  {"deg F", Temperature::Fahrenheit}
};

template <size_t size> const std::map<Temperature, std::map<Temperature, std::function<void(std::array<double, size>&)>>> conversions<Temperature, size>{
  {Temperature::Kelvin, {
    {Temperature::Celsius, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value - 273.15;});}},
    {Temperature::Rankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value * 9.0 / 5.0;});}},
    {Temperature::Fahrenheit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value * 9.0 / 5.0) - 459.67;});}}}},
  {Temperature::Celsius, {
    {Temperature::Kelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value + 273.15;});}},
    {Temperature::Rankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value + 273.15) * 9.0 / 5.0;});}},
    {Temperature::Fahrenheit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value * 9.0 / 5.0) + 32.0;});}}}},
  {Temperature::Rankine, {
    {Temperature::Kelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value * 5.0 / 9.0;});}},
    {Temperature::Celsius, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value - 491.67) * 5.0 / 9.0;});}},
    {Temperature::Fahrenheit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value - 459.67;});}}}},
  {Temperature::Fahrenheit, {
    {Temperature::Kelvin, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value + 459.67) * 5.0 / 9.0;});}},
    {Temperature::Celsius, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = (value - 32.0) * 5.0 / 9.0;});}},
    {Temperature::Rankine, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value = value + 459.67;});}}}}
};

} // namespace Unit

template <> const std::map<System, Unit::Temperature> consistent_units<Unit::Temperature>{
  {System::MetreKilogramSecondKelvin, Unit::Temperature::Kelvin},
  {System::CentimetreGramSecondKelvin, Unit::Temperature::Kelvin},
  {System::MillimetreGramSecondKelvin, Unit::Temperature::Kelvin},
  {System::FootPoundSecondRankine, Unit::Temperature::Rankine},
  {System::InchPoundSecondRankine, Unit::Temperature::Rankine}
};

} // namespace PhQ
