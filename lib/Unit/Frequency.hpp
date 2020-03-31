#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Frequency : uint_least8_t {
  Hertz,
  Kilohertz,
  Megahertz,
  Gigahertz
};

} // namespace Unit

template <> const std::map<Unit::Frequency, std::string> abbreviations<Unit::Frequency>{
  {Unit::Frequency::Hertz, "Hz"},
  {Unit::Frequency::Kilohertz, "kHz"},
  {Unit::Frequency::Megahertz, "MHz"},
  {Unit::Frequency::Gigahertz, "GHz"}
};

template <> const std::unordered_map<std::string, Unit::Frequency> spellings<Unit::Frequency>{
  {"Hz", Unit::Frequency::Hertz},
  {"1/s", Unit::Frequency::Hertz},
  {"/s", Unit::Frequency::Hertz},
  {"kHz", Unit::Frequency::Kilohertz},
  {"MHz", Unit::Frequency::Megahertz},
  {"GHz", Unit::Frequency::Gigahertz}
};

template <> const std::map<System, Unit::Frequency> consistent_units<Unit::Frequency>{
  {System::MetreKilogramSecondKelvin, Unit::Frequency::Hertz},
  {System::MillimetreGramSecondKelvin, Unit::Frequency::Hertz},
  {System::FootPoundSecondRankine, Unit::Frequency::Hertz},
  {System::InchPoundSecondRankine, Unit::Frequency::Hertz}
};

template <> constexpr const Unit::Frequency standard_unit<Unit::Frequency>{Unit::Frequency::Hertz};

template <> constexpr const Dimension::Set dimension<Unit::Frequency>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{-1}}};

template <size_t size> const std::map<Unit::Frequency, std::map<Unit::Frequency, std::function<void(std::array<double, size>&)>>> conversions<Unit::Frequency, size>{
  {Unit::Frequency::Hertz, {
    {Unit::Frequency::Hertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Frequency::Kilohertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Frequency::Megahertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}},
    {Unit::Frequency::Gigahertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000000001;});}}}},
  {Unit::Frequency::Kilohertz, {
    {Unit::Frequency::Hertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Unit::Frequency::Kilohertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Frequency::Megahertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}},
    {Unit::Frequency::Gigahertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.000001;});}}}},
  {Unit::Frequency::Megahertz, {
    {Unit::Frequency::Hertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}},
    {Unit::Frequency::Kilohertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Unit::Frequency::Megahertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Frequency::Gigahertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.001;});}}}},
  {Unit::Frequency::Gigahertz, {
    {Unit::Frequency::Hertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000000.0;});}},
    {Unit::Frequency::Kilohertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000000.0;});}},
    {Unit::Frequency::Megahertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1000.0;});}},
    {Unit::Frequency::Gigahertz, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}}}
};

} // namespace PhQ
