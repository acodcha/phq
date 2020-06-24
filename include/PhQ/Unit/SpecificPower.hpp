// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class SpecificPower : uint_least8_t {
  WattPerKilogram,
  NanowattPerGram,
  FootPoundPerSlugPerSecond,
  InchPoundPerSlinchPerSecond
};

} // namespace Unit

template <> const std::map<Unit::SpecificPower, std::string> abbreviations<Unit::SpecificPower>{
  {Unit::SpecificPower::WattPerKilogram, "W/kg"},
  {Unit::SpecificPower::NanowattPerGram, "nW/g"},
  {Unit::SpecificPower::FootPoundPerSlugPerSecond, "ft·lbf/slug/s"},
  {Unit::SpecificPower::InchPoundPerSlinchPerSecond, "in·lbf/slinch/s"}
};

template <> const std::unordered_map<std::string, Unit::SpecificPower> spellings<Unit::SpecificPower>{
  {"W/kg", Unit::SpecificPower::WattPerKilogram},
  {"N·m/kg/s", Unit::SpecificPower::WattPerKilogram},
  {"N*m/kg/s", Unit::SpecificPower::WattPerKilogram},
  {"N·m/(kg·s)", Unit::SpecificPower::WattPerKilogram},
  {"N*m/(kg*s)", Unit::SpecificPower::WattPerKilogram},
  {"N·m/s/kg", Unit::SpecificPower::WattPerKilogram},
  {"N*m/s/kg", Unit::SpecificPower::WattPerKilogram},
  {"N·m/(s·kg)", Unit::SpecificPower::WattPerKilogram},
  {"N*m/(s*kg)", Unit::SpecificPower::WattPerKilogram},
  {"m·N/kg/s", Unit::SpecificPower::WattPerKilogram},
  {"m*N/kg/s", Unit::SpecificPower::WattPerKilogram},
  {"m·N/(kg·s)", Unit::SpecificPower::WattPerKilogram},
  {"m*N/(kg*s)", Unit::SpecificPower::WattPerKilogram},
  {"m·N/s/kg", Unit::SpecificPower::WattPerKilogram},
  {"m*N/s/kg", Unit::SpecificPower::WattPerKilogram},
  {"m·N/(s·kg)", Unit::SpecificPower::WattPerKilogram},
  {"m*N/(s*kg)", Unit::SpecificPower::WattPerKilogram},
  {"m^2/s^3", Unit::SpecificPower::WattPerKilogram},
  {"m2/s3", Unit::SpecificPower::WattPerKilogram},
  {"nW/g", Unit::SpecificPower::NanowattPerGram},
  {"μN·mm/g/s", Unit::SpecificPower::NanowattPerGram},
  {"μN*mm/g/s", Unit::SpecificPower::NanowattPerGram},
  {"μN·mm/(g·s)", Unit::SpecificPower::NanowattPerGram},
  {"μN*mm/(g*s)", Unit::SpecificPower::NanowattPerGram},
  {"uN·mm/g/s", Unit::SpecificPower::NanowattPerGram},
  {"uN*mm/g/s", Unit::SpecificPower::NanowattPerGram},
  {"uN·mm/(g·s)", Unit::SpecificPower::NanowattPerGram},
  {"uN*mm/(g*s)", Unit::SpecificPower::NanowattPerGram},
  {"μN·mm/s/g", Unit::SpecificPower::NanowattPerGram},
  {"μN*mm/s/g", Unit::SpecificPower::NanowattPerGram},
  {"μN·mm/(s·g)", Unit::SpecificPower::NanowattPerGram},
  {"μN*mm/(s*g)", Unit::SpecificPower::NanowattPerGram},
  {"uN·mm/s/g", Unit::SpecificPower::NanowattPerGram},
  {"uN*mm/s/g", Unit::SpecificPower::NanowattPerGram},
  {"uN·mm/(s·g)", Unit::SpecificPower::NanowattPerGram},
  {"uN*mm/(s*g)", Unit::SpecificPower::NanowattPerGram},
  {"mm·μN/g/s", Unit::SpecificPower::NanowattPerGram},
  {"mm*μN/g/s", Unit::SpecificPower::NanowattPerGram},
  {"mm·μN/(g·s)", Unit::SpecificPower::NanowattPerGram},
  {"mm*μN/(g*s)", Unit::SpecificPower::NanowattPerGram},
  {"mm·uN/g/s", Unit::SpecificPower::NanowattPerGram},
  {"mm*uN/g/s", Unit::SpecificPower::NanowattPerGram},
  {"mm·uN/(g·s)", Unit::SpecificPower::NanowattPerGram},
  {"mm*uN/(g*s)", Unit::SpecificPower::NanowattPerGram},
  {"mm·μN/s/g", Unit::SpecificPower::NanowattPerGram},
  {"mm*μN/s/g", Unit::SpecificPower::NanowattPerGram},
  {"mm·μN/(s·g)", Unit::SpecificPower::NanowattPerGram},
  {"mm*μN/(s*g)", Unit::SpecificPower::NanowattPerGram},
  {"mm·uN/s/g", Unit::SpecificPower::NanowattPerGram},
  {"mm*uN/s/g", Unit::SpecificPower::NanowattPerGram},
  {"mm·uN/(s·g)", Unit::SpecificPower::NanowattPerGram},
  {"mm*uN/(s*g)", Unit::SpecificPower::NanowattPerGram},
  {"mm^2/s^3", Unit::SpecificPower::NanowattPerGram},
  {"mm2/s3", Unit::SpecificPower::NanowattPerGram},
  {"ft·lbf/slug/s", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft*lbf/slug/s", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft·lbf/(slug·s)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft*lbf/(slug*s)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft·lbf/s/slug", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft*lbf/s/slug", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft·lbf/(s·slug)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft*lbf/(s*slug)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lbf·ft/slug/s", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lbf*ft/slug/s", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lbf·ft/(slug·s)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lbf*ft/(slug*s)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lbf·ft/s/slug", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lbf*ft/s/slug", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lbf·ft/(s·slug)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lbf*ft/(s*slug)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft·lb/slug/s", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft*lb/slug/s", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft·lb/(slug·s)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft*lb/(slug*s)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft·lb/s/slug", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft*lb/s/slug", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft·lb/(s·slug)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft*lb/(s*slug)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lb·ft/slug/s", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lb*ft/slug/s", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lb·ft/(slug·s)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lb*ft/(slug*s)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lb·ft/s/slug", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lb*ft/s/slug", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lb·ft/(s·slug)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"lb*ft/(s*slug)", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft^2/s^3", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"ft2/s3", Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {"in·lbf/slinch/s", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in*lbf/slinch/s", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in·lbf/(slinch·s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in*lbf/(slinch*s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in·lbf/s/slinch", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in*lbf/s/slinch", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in·lbf/(s·slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in*lbf/(s*slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lbf·in/slinch/s", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lbf*in/slinch/s", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lbf·in/(slinch·s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lbf*in/(slinch*s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lbf·in/s/slinch", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lbf*in/s/slinch", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lbf·in/(s·slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lbf*in/(s*slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in·lb/slinch/s", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in*lb/slinch/s", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in·lb/(slinch·s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in*lb/(slinch*s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in·lb/s/slinch", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in*lb/s/slinch", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in·lb/(s·slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in*lb/(s*slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lb·in/slinch/s", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lb*in/slinch/s", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lb·in/(slinch·s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lb*in/(slinch*s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lb·in/s/slinch", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lb*in/s/slinch", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lb·in/(s·slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"lb*in/(s*slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in^2/s^3", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
  {"in2/s3", Unit::SpecificPower::InchPoundPerSlinchPerSecond}
};

template <> const std::map<System, Unit::SpecificPower> consistent_units<Unit::SpecificPower>{
  {System::MetreKilogramSecondKelvin, Unit::SpecificPower::WattPerKilogram},
  {System::MillimetreGramSecondKelvin, Unit::SpecificPower::NanowattPerGram},
  {System::FootPoundSecondRankine, Unit::SpecificPower::FootPoundPerSlugPerSecond},
  {System::InchPoundSecondRankine, Unit::SpecificPower::InchPoundPerSlinchPerSecond}
};

template <> const std::map<Unit::SpecificPower, System> related_systems<Unit::SpecificPower>{
  {Unit::SpecificPower::WattPerKilogram, System::MetreKilogramSecondKelvin},
  {Unit::SpecificPower::NanowattPerGram, System::MillimetreGramSecondKelvin},
  {Unit::SpecificPower::FootPoundPerSlugPerSecond, System::FootPoundSecondRankine},
  {Unit::SpecificPower::InchPoundPerSlinchPerSecond, System::InchPoundSecondRankine},
};

template <> constexpr const Unit::SpecificPower standard_unit<Unit::SpecificPower>{Unit::SpecificPower::WattPerKilogram};

template <> constexpr const Dimension::Set dimension<Unit::SpecificPower>{Dimension::Set{Dimension::Length{2}, Dimension::Mass{}, Dimension::Time{-3}}};

template <> const std::map<Unit::SpecificPower, std::map<Unit::SpecificPower, std::function<void(std::vector<double>&)>>> conversions<Unit::SpecificPower>{
  {Unit::SpecificPower::WattPerKilogram, {
    {Unit::SpecificPower::WattPerKilogram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::SpecificPower::NanowattPerGram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 2);});}},
    {Unit::SpecificPower::FootPoundPerSlugPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.3048, 2);});}},
    {Unit::SpecificPower::InchPoundPerSlinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0254, 2);});}}
  }},
  {Unit::SpecificPower::NanowattPerGram, {
    {Unit::SpecificPower::WattPerKilogram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 2);});}},
    {Unit::SpecificPower::NanowattPerGram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::SpecificPower::FootPoundPerSlugPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(304.8, 2);});}},
    {Unit::SpecificPower::InchPoundPerSlinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(25.4, 2);});}}
  }},
  {Unit::SpecificPower::FootPoundPerSlugPerSecond, {
    {Unit::SpecificPower::WattPerKilogram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.3048, 2);});}},
    {Unit::SpecificPower::NanowattPerGram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(304.8, 2);});}},
    {Unit::SpecificPower::FootPoundPerSlugPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}},
    {Unit::SpecificPower::InchPoundPerSlinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12.0, 2);});}}
  }},
  {Unit::SpecificPower::InchPoundPerSlinchPerSecond, {
    {Unit::SpecificPower::WattPerKilogram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 2);});}},
    {Unit::SpecificPower::NanowattPerGram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(25.4, 2);});}},
    {Unit::SpecificPower::FootPoundPerSlugPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12.0, 2);});}},
    {Unit::SpecificPower::InchPoundPerSlinchPerSecond, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{});}}
  }}
};

} // namespace PhQ
