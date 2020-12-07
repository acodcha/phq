// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class SpecificEnergy : uint_least8_t {
  JoulePerKilogram,
  NanojoulePerGram,
  FootPoundPerSlug,
  InchPoundPerSlinch
};

} // namespace Unit

template <> const std::map<Unit::SpecificEnergy, std::string> abbreviations<Unit::SpecificEnergy>{
  {Unit::SpecificEnergy::JoulePerKilogram, "J/kg"},
  {Unit::SpecificEnergy::NanojoulePerGram, "nJ/g"},
  {Unit::SpecificEnergy::FootPoundPerSlug, "ft·lbf/slug"},
  {Unit::SpecificEnergy::InchPoundPerSlinch, "in·lbf/slinch"}
};

template <> const std::unordered_map<std::string, Unit::SpecificEnergy> spellings<Unit::SpecificEnergy>{
  {"J/kg", Unit::SpecificEnergy::JoulePerKilogram},
  {"N·m/kg", Unit::SpecificEnergy::JoulePerKilogram},
  {"N*m/kg", Unit::SpecificEnergy::JoulePerKilogram},
  {"m·N/kg", Unit::SpecificEnergy::JoulePerKilogram},
  {"m*N/kg", Unit::SpecificEnergy::JoulePerKilogram},
  {"m^2/s^2", Unit::SpecificEnergy::JoulePerKilogram},
  {"m2/s2", Unit::SpecificEnergy::JoulePerKilogram},
  {"nJ/g", Unit::SpecificEnergy::NanojoulePerGram},
  {"μN·mm/g", Unit::SpecificEnergy::NanojoulePerGram},
  {"μN*mm/g", Unit::SpecificEnergy::NanojoulePerGram},
  {"uN·mm/g", Unit::SpecificEnergy::NanojoulePerGram},
  {"uN*mm/g", Unit::SpecificEnergy::NanojoulePerGram},
  {"mm·μN/g", Unit::SpecificEnergy::NanojoulePerGram},
  {"mm*μN/g", Unit::SpecificEnergy::NanojoulePerGram},
  {"mm·uN/g", Unit::SpecificEnergy::NanojoulePerGram},
  {"mm*uN/g", Unit::SpecificEnergy::NanojoulePerGram},
  {"mm^2/s^2", Unit::SpecificEnergy::NanojoulePerGram},
  {"mm2/s2", Unit::SpecificEnergy::NanojoulePerGram},
  {"ft·lbf/slug", Unit::SpecificEnergy::FootPoundPerSlug},
  {"ft*lbf/slug", Unit::SpecificEnergy::FootPoundPerSlug},
  {"lbf·ft/slug", Unit::SpecificEnergy::FootPoundPerSlug},
  {"lbf*ft/slug", Unit::SpecificEnergy::FootPoundPerSlug},
  {"ft·lb/slug", Unit::SpecificEnergy::FootPoundPerSlug},
  {"ft*lb/slug", Unit::SpecificEnergy::FootPoundPerSlug},
  {"lb·ft/slug", Unit::SpecificEnergy::FootPoundPerSlug},
  {"lb*ft/slug", Unit::SpecificEnergy::FootPoundPerSlug},
  {"ft^2/s^2", Unit::SpecificEnergy::FootPoundPerSlug},
  {"ft2/s2", Unit::SpecificEnergy::FootPoundPerSlug},
  {"in·lbf/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
  {"in*lbf/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
  {"lbf·in/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
  {"lbf*in/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
  {"in·lb/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
  {"in*lb/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
  {"lb·in/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
  {"lb*in/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
  {"in^2/s^2", Unit::SpecificEnergy::InchPoundPerSlinch},
  {"in2/s2", Unit::SpecificEnergy::InchPoundPerSlinch}
};

template <> const std::map<System, Unit::SpecificEnergy> consistent_units<Unit::SpecificEnergy>{
  {System::MetreKilogramSecondKelvin, Unit::SpecificEnergy::JoulePerKilogram},
  {System::MillimetreGramSecondKelvin, Unit::SpecificEnergy::NanojoulePerGram},
  {System::FootPoundSecondRankine, Unit::SpecificEnergy::FootPoundPerSlug},
  {System::InchPoundSecondRankine, Unit::SpecificEnergy::InchPoundPerSlinch}
};

template <> const std::map<Unit::SpecificEnergy, System> related_systems<Unit::SpecificEnergy>{
  {Unit::SpecificEnergy::JoulePerKilogram, System::MetreKilogramSecondKelvin},
  {Unit::SpecificEnergy::NanojoulePerGram, System::MillimetreGramSecondKelvin},
  {Unit::SpecificEnergy::FootPoundPerSlug, System::FootPoundSecondRankine},
  {Unit::SpecificEnergy::InchPoundPerSlinch, System::InchPoundSecondRankine},
};

template <> constexpr const Unit::SpecificEnergy standard_unit<Unit::SpecificEnergy>{Unit::SpecificEnergy::JoulePerKilogram};

template <> constexpr const Dimension::Set dimension<Unit::SpecificEnergy>{Dimension::Set{Dimension::Length{2}, Dimension::Mass{}, Dimension::Time{-2}}};

template <> const std::map<Unit::SpecificEnergy, std::map<Unit::SpecificEnergy, std::function<void(std::vector<double>&)>>> conversions<Unit::SpecificEnergy>{
  {Unit::SpecificEnergy::JoulePerKilogram, {
    {Unit::SpecificEnergy::JoulePerKilogram, [](std::vector<double>& values)->void{}},
    {Unit::SpecificEnergy::NanojoulePerGram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(1000.0, 2);});}},
    {Unit::SpecificEnergy::FootPoundPerSlug, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.3048, 2);});}},
    {Unit::SpecificEnergy::InchPoundPerSlinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(0.0254, 2);});}}
  }},
  {Unit::SpecificEnergy::NanojoulePerGram, {
    {Unit::SpecificEnergy::JoulePerKilogram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.001, 2);});}},
    {Unit::SpecificEnergy::NanojoulePerGram, [](std::vector<double>& values)->void{}},
    {Unit::SpecificEnergy::FootPoundPerSlug, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(304.8, 2);});}},
    {Unit::SpecificEnergy::InchPoundPerSlinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(25.4, 2);});}}
  }},
  {Unit::SpecificEnergy::FootPoundPerSlug, {
    {Unit::SpecificEnergy::JoulePerKilogram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.3048, 2);});}},
    {Unit::SpecificEnergy::NanojoulePerGram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(304.8, 2);});}},
    {Unit::SpecificEnergy::FootPoundPerSlug, [](std::vector<double>& values)->void{}},
    {Unit::SpecificEnergy::InchPoundPerSlinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(12.0, 2);});}}
  }},
  {Unit::SpecificEnergy::InchPoundPerSlinch, {
    {Unit::SpecificEnergy::JoulePerKilogram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(0.0254, 2);});}},
    {Unit::SpecificEnergy::NanojoulePerGram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= std::pow(25.4, 2);});}},
    {Unit::SpecificEnergy::FootPoundPerSlug, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= std::pow(12.0, 2);});}},
    {Unit::SpecificEnergy::InchPoundPerSlinch, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
