#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Memory : uint_least8_t {
  Bit,
  Byte,
  Kilobyte,
  Megabyte,
  Gigabyte,
  Terabyte
};

} // namespace Unit

template <> const std::map<Unit::Memory, std::string> abbreviations<Unit::Memory>{
  {Unit::Memory::Bit, "b"},
  {Unit::Memory::Byte, "B"},
  {Unit::Memory::Kilobyte, "kB"},
  {Unit::Memory::Megabyte, "MB"},
  {Unit::Memory::Gigabyte, "GB"},
  {Unit::Memory::Terabyte, "TB"}
};

template <> const std::unordered_map<std::string, Unit::Memory> spellings<Unit::Memory>{
  {"b", Unit::Memory::Bit},
  {"bit", Unit::Memory::Bit},
  {"bits", Unit::Memory::Bit},
  {"B", Unit::Memory::Byte},
  {"byte", Unit::Memory::Byte},
  {"bytes", Unit::Memory::Byte},
  {"kB", Unit::Memory::Kilobyte},
  {"kilobyte", Unit::Memory::Kilobyte},
  {"kilobytes", Unit::Memory::Kilobyte},
  {"MB", Unit::Memory::Megabyte},
  {"megabyte", Unit::Memory::Megabyte},
  {"megabytes", Unit::Memory::Megabyte},
  {"GB", Unit::Memory::Gigabyte},
  {"gigabyte", Unit::Memory::Gigabyte},
  {"gigabytes", Unit::Memory::Gigabyte},
  {"TB", Unit::Memory::Terabyte},
  {"terabyte", Unit::Memory::Terabyte},
  {"terabytes", Unit::Memory::Terabyte}
};

template <> const std::map<System, Unit::Memory> consistent_units<Unit::Memory>{
  {System::MetreKilogramSecondKelvin, Unit::Memory::Byte},
  {System::MillimetreGramSecondKelvin, Unit::Memory::Byte},
  {System::FootPoundSecondRankine, Unit::Memory::Byte},
  {System::InchPoundSecondRankine, Unit::Memory::Byte}
};

template <> constexpr const Unit::Memory standard_unit<Unit::Memory>{Unit::Memory::Byte};

template <> constexpr const Dimension::Set dimension<Unit::Memory>{Dimension::Set{}};

template <size_t size> const std::map<Unit::Memory, std::map<Unit::Memory, std::function<void(std::array<double, size>&)>>> conversions<Unit::Memory, size>{
  {Unit::Memory::Bit, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.125;});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.125 / 1024.0;});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.125 / std::pow(1024.0, 2);});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.125 / std::pow(1024.0, 3);});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 0.125 / std::pow(1024.0, 4);});}}}},
  {Unit::Memory::Byte, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 8.0;});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1024.0;});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 2);});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 3);});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 4);});}}}},
  {Unit::Memory::Kilobyte, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 8.0 * 1024.0;});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1024.0;});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1024.0;});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 2);});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 3);});}}}},
  {Unit::Memory::Megabyte, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 8.0 * std::pow(1024.0, 2);});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 2);});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1024.0;});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1024.0;});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= std::pow(1024.0, 2);});}}}},
  {Unit::Memory::Gigabyte, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 8.0 * std::pow(1024.0, 3);});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 3);});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 2);});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1024.0;});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value /= 1024.0;});}}}},
  {Unit::Memory::Terabyte, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 8.0 * std::pow(1024.0, 4);});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 4);});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 3);});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= std::pow(1024.0, 2);});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{
      value *= 1024.0;});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}}}
};

} // namespace PhQ
