#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Pressure : uint_least8_t {
  Pascal,
  PoundPerSquareFoot,
  PoundPerSquareInch
};

} // namespace Unit

template <> const std::map<Unit::Pressure, std::string> abbreviations<Unit::Pressure>{
  {Unit::Pressure::Pascal, "Pa"},
  {Unit::Pressure::PoundPerSquareFoot, "lbf/ft^2"},
  {Unit::Pressure::PoundPerSquareInch, "lbf/in^2"}
};

template <> const std::unordered_map<std::string, Unit::Pressure> spellings<Unit::Pressure>{
  {"Pa", Unit::Pressure::Pascal},
  {"N/m^2", Unit::Pressure::Pascal},
  {"N/m2", Unit::Pressure::Pascal},
  {"kg/(m*s)", Unit::Pressure::Pascal},
  {"kg/m/s", Unit::Pressure::Pascal},
  {"lbf/ft^2", Unit::Pressure::PoundPerSquareFoot},
  {"lbf/ft2", Unit::Pressure::PoundPerSquareFoot},
  {"lb/ft^2", Unit::Pressure::PoundPerSquareFoot},
  {"lb/ft2", Unit::Pressure::PoundPerSquareFoot},
  {"psf", Unit::Pressure::PoundPerSquareFoot},
  {"lbf/in^2", Unit::Pressure::PoundPerSquareInch},
  {"lbf/in2", Unit::Pressure::PoundPerSquareInch},
  {"lb/in^2", Unit::Pressure::PoundPerSquareInch},
  {"lb/in2", Unit::Pressure::PoundPerSquareInch},
  {"psi", Unit::Pressure::PoundPerSquareInch}
};

template <> const std::map<System, Unit::Pressure> consistent_units<Unit::Pressure>{
  {System::MetreKilogramSecondKelvin, Unit::Pressure::Pascal},
  {System::MillimetreGramSecondKelvin, Unit::Pressure::Pascal},
  {System::FootPoundSecondRankine, Unit::Pressure::PoundPerSquareFoot},
  {System::InchPoundSecondRankine, Unit::Pressure::PoundPerSquareInch}
};

template <> constexpr const Unit::Pressure standard_unit<Unit::Pressure>{Unit::Pressure::Pascal};

template <> constexpr const Dimension::Set dimension<Unit::Pressure>{Dimension::Set{Dimension::Length{-1}, Dimension::Mass{1}, Dimension::Time{-2}}};

template <size_t size> const std::map<Unit::Pressure, std::map<Unit::Pressure, std::function<void(std::array<double, size>&)>>> conversions<Unit::Pressure, size>{
  {Unit::Pressure::Pascal, {
    {Unit::Pressure::PoundPerSquareFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(0.3048, 2) / (0.45359237 * 9.80665);});}},
    {Unit::Pressure::PoundPerSquareInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(0.0254, 2) / (0.45359237 * 9.80665);});}}}},
  {Unit::Pressure::PoundPerSquareFoot, {
    {Unit::Pressure::Pascal, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= (0.45359237 * 9.80665) / std::pow(0.3048, 2);});}},
    {Unit::Pressure::PoundPerSquareInch, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(12.0, 2);});}}}},
  {Unit::Pressure::PoundPerSquareInch, {
    {Unit::Pressure::Pascal, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= (0.45359237 * 9.80665) / std::pow(0.0254, 2);});}},
    {Unit::Pressure::PoundPerSquareFoot, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(12.0, 2);});}}}}
};

} // namespace PhQ
