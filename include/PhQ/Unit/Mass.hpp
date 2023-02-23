// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Mass : int_least8_t {
  Kilogram,
  Gram,
  Slug,
  Slinch,
  Pound
};

} // namespace Unit

template <> const std::map<Unit::Mass, std::string> abbreviations<Unit::Mass>{
  {Unit::Mass::Kilogram, "kg"},
  {Unit::Mass::Gram, "g"},
  {Unit::Mass::Slug, "slug"},
  {Unit::Mass::Slinch, "slinch"},
  {Unit::Mass::Pound, "lbm"}
};

template <> const std::unordered_map<std::string, Unit::Mass> spellings<Unit::Mass>{
  {"kg", Unit::Mass::Kilogram},
  {"g", Unit::Mass::Gram},
  {"slug", Unit::Mass::Slug},
  {"slinch", Unit::Mass::Slinch},
  {"lbm", Unit::Mass::Pound},
  {"lb", Unit::Mass::Pound}
};

template <> const std::map<System, Unit::Mass> consistent_units<Unit::Mass>{
  {System::MetreKilogramSecondKelvin, Unit::Mass::Kilogram},
  {System::MillimetreGramSecondKelvin, Unit::Mass::Gram},
  {System::FootPoundSecondRankine, Unit::Mass::Slug},
  {System::InchPoundSecondRankine, Unit::Mass::Slinch}
};

template <> constexpr const Unit::Mass standard_unit<Unit::Mass>{Unit::Mass::Kilogram};

template <> constexpr const Dimension::Set dimension<Unit::Mass>{Dimension::Set{Dimension::Length{0}, Dimension::Mass{1}}};

template <> const std::map<Unit::Mass, std::map<Unit::Mass, std::function<void(std::vector<double>&)>>> conversions<Unit::Mass>{
  {Unit::Mass::Kilogram, {
    {Unit::Mass::Kilogram, [](std::vector<double>& values)->void{}},
    {Unit::Mass::Gram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 1000.0;});}},
    {Unit::Mass::Slug, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.3048 / (0.45359237 * 9.80665);});}},
    {Unit::Mass::Slinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0254 / (0.45359237 * 9.80665);});}},
    {Unit::Mass::Pound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 0.45359237;});}}
  }},
  {Unit::Mass::Gram, {
    {Unit::Mass::Kilogram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.001;});}},
    {Unit::Mass::Gram, [](std::vector<double>& values)->void{}},
    {Unit::Mass::Slug, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0003048 / (0.45359237 * 9.80665);});}},
    {Unit::Mass::Slinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0000254 / (0.45359237 * 9.80665);});}},
    {Unit::Mass::Pound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 453.59237;});}}
  }},
  {Unit::Mass::Slug, {
    {Unit::Mass::Kilogram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / 0.3048;});}},
    {Unit::Mass::Gram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 453.59237 * 9.80665 / 0.3048;});}},
    {Unit::Mass::Slug, [](std::vector<double>& values)->void{}},
    {Unit::Mass::Slinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value /= 12.0;});}},
    {Unit::Mass::Pound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 9.80665 / 0.3048;});}}
  }},
  {Unit::Mass::Slinch, {
    {Unit::Mass::Kilogram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237 * 9.80665 / 0.0254;});}},
    {Unit::Mass::Gram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 453.59237 * 9.80665 / 0.0254;});}},
    {Unit::Mass::Slug, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 12.0;});}},
    {Unit::Mass::Slinch, [](std::vector<double>& values)->void{}},
    {Unit::Mass::Pound, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 9.80665 / 0.0254;});}}
  }},
  {Unit::Mass::Pound, {
    {Unit::Mass::Kilogram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.45359237;});}},
    {Unit::Mass::Gram, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 453.59237;});}},
    {Unit::Mass::Slug, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.3048 / 9.80665;});}},
    {Unit::Mass::Slinch, [](std::vector<double>& values)->void{std::for_each(values.begin(), values.end(), [](double& value)->void{value *= 0.0254 / 9.80665;});}},
    {Unit::Mass::Slinch, [](std::vector<double>& values)->void{}}
  }}
};

} // namespace PhQ
