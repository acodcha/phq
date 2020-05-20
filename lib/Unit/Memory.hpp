// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Memory : uint_least8_t {
  Bit,
  Kilobit,
  Megabit,
  Gigabit,
  Terabit,
  Byte,
  Kilobyte,
  Megabyte,
  Gigabyte,
  Terabyte
};

} // namespace Unit

template <> const std::map<Unit::Memory, std::string> abbreviations<Unit::Memory>{
  {Unit::Memory::Bit, "b"},
  {Unit::Memory::Kilobit, "kb"},
  {Unit::Memory::Megabit, "Mb"},
  {Unit::Memory::Gigabit, "Gb"},
  {Unit::Memory::Terabit, "Tb"},
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
  {"kb", Unit::Memory::Kilobit},
  {"kilobit", Unit::Memory::Kilobit},
  {"kilobits", Unit::Memory::Kilobit},
  {"Mb", Unit::Memory::Megabit},
  {"megabit", Unit::Memory::Megabit},
  {"megabits", Unit::Memory::Megabit},
  {"Gb", Unit::Memory::Gigabit},
  {"gigabit", Unit::Memory::Gigabit},
  {"gigabits", Unit::Memory::Gigabit},
  {"Tb", Unit::Memory::Terabit},
  {"terabit", Unit::Memory::Terabit},
  {"terabits", Unit::Memory::Terabit},
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
    {Unit::Memory::Kilobit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::Memory::Megabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}},
    {Unit::Memory::Gigabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 3);});}},
    {Unit::Memory::Terabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 4);});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125;});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / 1024.0;});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 2);});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 3);});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 4);});}}
  }},
  {Unit::Memory::Kilobit, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::Memory::Kilobit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Megabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::Memory::Gigabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}},
    {Unit::Memory::Terabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 3);});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * 1024.0;});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125;});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / 1024.0;});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 2);});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 3);});}}
  }},
  {Unit::Memory::Megabit, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::Memory::Kilobit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::Memory::Megabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Gigabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::Memory::Terabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 2);});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * 1024.0;});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125;});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / 1024.0;});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 2);});}}
  }},
  {Unit::Memory::Gigabit, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 3);});}},
    {Unit::Memory::Kilobit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::Memory::Megabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::Memory::Gigabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Terabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 3);});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 2);});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * 1024.0;});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125;});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / 1024.0;});}}
  }},
  {Unit::Memory::Terabit, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 4);});}},
    {Unit::Memory::Kilobit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 3);});}},
    {Unit::Memory::Megabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::Memory::Gigabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::Memory::Terabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 4);});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 3);});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 2);});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * 1024.0;});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125;});}}
  }},
  {Unit::Memory::Byte, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0;});}},
    {Unit::Memory::Kilobit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / 1024.0;});}},
    {Unit::Memory::Megabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 2);});}},
    {Unit::Memory::Gigabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 3);});}},
    {Unit::Memory::Terabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 4);});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 3);});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 4);});}}
  }},
  {Unit::Memory::Kilobyte, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * 1024.0;});}},
    {Unit::Memory::Kilobit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0;});}},
    {Unit::Memory::Megabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / 1024.0;});}},
    {Unit::Memory::Gigabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 2);});}},
    {Unit::Memory::Terabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 3);});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 3);});}}
  }},
  {Unit::Memory::Megabyte, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 2);});}},
    {Unit::Memory::Kilobit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * 1024.0;});}},
    {Unit::Memory::Megabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0;});}},
    {Unit::Memory::Gigabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / 1024.0;});}},
    {Unit::Memory::Terabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 2);});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}}
  }},
  {Unit::Memory::Gigabyte, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 3);});}},
    {Unit::Memory::Kilobit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 2);});}},
    {Unit::Memory::Megabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * 1024.0;});}},
    {Unit::Memory::Gigabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0;});}},
    {Unit::Memory::Terabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / 1024.0;});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 3);});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}}
  }},
  {Unit::Memory::Terabyte, {
    {Unit::Memory::Bit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 4);});}},
    {Unit::Memory::Kilobit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 3);});}},
    {Unit::Memory::Megabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 2);});}},
    {Unit::Memory::Gigabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * 1024.0;});}},
    {Unit::Memory::Terabit, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0;});}},
    {Unit::Memory::Byte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 4);});}},
    {Unit::Memory::Kilobyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 3);});}},
    {Unit::Memory::Megabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::Memory::Gigabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::Memory::Terabyte, [](std::array<double, size>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}
  }}
};

} // namespace PhQ
