// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class MemoryRate : uint_least8_t {
  BitPerSecond,
  KilobitPerSecond,
  MegabitPerSecond,
  GigabitPerSecond,
  TerabitPerSecond,
  BytePerSecond,
  KilobytePerSecond,
  MegabytePerSecond,
  GigabytePerSecond,
  TerabytePerSecond
};

} // namespace Unit

template <> const std::map<Unit::MemoryRate, std::string> abbreviations<Unit::MemoryRate>{
  {Unit::MemoryRate::BitPerSecond, "b/s"},
  {Unit::MemoryRate::KilobitPerSecond, "kb/s"},
  {Unit::MemoryRate::MegabitPerSecond, "Mb/s"},
  {Unit::MemoryRate::GigabitPerSecond, "Gb/s"},
  {Unit::MemoryRate::TerabitPerSecond, "Tb/s"},
  {Unit::MemoryRate::BytePerSecond, "B/s"},
  {Unit::MemoryRate::KilobytePerSecond, "kB/s"},
  {Unit::MemoryRate::MegabytePerSecond, "MB/s"},
  {Unit::MemoryRate::GigabytePerSecond, "GB/s"},
  {Unit::MemoryRate::TerabytePerSecond, "TB/s"}
};

template <> const std::unordered_map<std::string, Unit::MemoryRate> spellings<Unit::MemoryRate>{
  {"b/s", Unit::MemoryRate::BitPerSecond},
  {"kb/s", Unit::MemoryRate::KilobitPerSecond},
  {"Mb/s", Unit::MemoryRate::MegabitPerSecond},
  {"Gb/s", Unit::MemoryRate::GigabitPerSecond},
  {"Tb/s", Unit::MemoryRate::TerabitPerSecond},
  {"B/s", Unit::MemoryRate::BytePerSecond},
  {"kB/s", Unit::MemoryRate::KilobytePerSecond},
  {"MB/s", Unit::MemoryRate::MegabytePerSecond},
  {"GB/s", Unit::MemoryRate::GigabytePerSecond},
  {"TB/s", Unit::MemoryRate::TerabytePerSecond}
};

template <> const std::map<System, Unit::MemoryRate> consistent_units<Unit::MemoryRate>{
  {System::MetreKilogramSecondKelvin, Unit::MemoryRate::BytePerSecond},
  {System::MillimetreGramSecondKelvin, Unit::MemoryRate::BytePerSecond},
  {System::FootPoundSecondRankine, Unit::MemoryRate::BytePerSecond},
  {System::InchPoundSecondRankine, Unit::MemoryRate::BytePerSecond}
};

template <> constexpr const Unit::MemoryRate standard_unit<Unit::MemoryRate>{Unit::MemoryRate::BytePerSecond};

template <> constexpr const Dimension::Set dimension<Unit::MemoryRate>{Dimension::Set{Dimension::Length{}, Dimension::Mass{}, Dimension::Time{-1}}};

template <> const std::map<Unit::MemoryRate, std::map<Unit::MemoryRate, std::function<void(std::vector<double>&)>>> conversions<Unit::MemoryRate>{
  {Unit::MemoryRate::BitPerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::KilobitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::MemoryRate::MegabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::GigabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::TerabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 4);});}},
    {Unit::MemoryRate::BytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125;});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / 1024.0;});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 4);});}}
  }},
  {Unit::MemoryRate::KilobitPerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::MemoryRate::KilobitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::MegabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::MemoryRate::GigabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::TerabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::BytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * 1024.0;});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125;});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / 1024.0;});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 3);});}}
  }},
  {Unit::MemoryRate::MegabitPerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::KilobitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::MemoryRate::MegabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::GigabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::MemoryRate::TerabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::BytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * 1024.0;});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125;});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / 1024.0;});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / std::pow(1024.0, 2);});}}
  }},
  {Unit::MemoryRate::GigabitPerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::KilobitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::MegabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::MemoryRate::GigabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::TerabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::MemoryRate::BytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * 1024.0;});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125;});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 / 1024.0;});}}
  }},
  {Unit::MemoryRate::TerabitPerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 4);});}},
    {Unit::MemoryRate::KilobitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::MegabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::GigabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::MemoryRate::TerabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::BytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 4);});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125 * 1024.0;});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.125;});}}
  }},
  {Unit::MemoryRate::BytePerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0;});}},
    {Unit::MemoryRate::KilobitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / 1024.0;});}},
    {Unit::MemoryRate::MegabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::GigabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::TerabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 4);});}},
    {Unit::MemoryRate::BytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 4);});}}
  }},
  {Unit::MemoryRate::KilobytePerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * 1024.0;});}},
    {Unit::MemoryRate::KilobitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0;});}},
    {Unit::MemoryRate::MegabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / 1024.0;});}},
    {Unit::MemoryRate::GigabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::TerabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::BytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 3);});}}
  }},
  {Unit::MemoryRate::MegabytePerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::KilobitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * 1024.0;});}},
    {Unit::MemoryRate::MegabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0;});}},
    {Unit::MemoryRate::GigabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / 1024.0;});}},
    {Unit::MemoryRate::TerabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::BytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(1024.0, 2);});}}
  }},
  {Unit::MemoryRate::GigabytePerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::KilobitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::MegabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * 1024.0;});}},
    {Unit::MemoryRate::GigabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0;});}},
    {Unit::MemoryRate::TerabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 / 1024.0;});}},
    {Unit::MemoryRate::BytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 1024.0;});}}
  }},
  {Unit::MemoryRate::TerabytePerSecond, {
    {Unit::MemoryRate::BitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 4);});}},
    {Unit::MemoryRate::KilobitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::MegabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::GigabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0 * 1024.0;});}},
    {Unit::MemoryRate::TerabitPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 8.0;});}},
    {Unit::MemoryRate::BytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 4);});}},
    {Unit::MemoryRate::KilobytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 3);});}},
    {Unit::MemoryRate::MegabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1024.0, 2);});}},
    {Unit::MemoryRate::GigabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1024.0;});}},
    {Unit::MemoryRate::TerabytePerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}
  }}
};

} // namespace PhQ
