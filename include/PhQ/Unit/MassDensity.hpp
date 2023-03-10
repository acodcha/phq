// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_DENSITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_DENSITY_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class MassDensity : int_least8_t {
  KilogramPerCubicMetre,
  GramPerCubicMillimetre,
  SlugPerCubicFoot,
  SlinchPerCubicInch,
  PoundPerCubicFoot,
  PoundPerCubicInch,
};

}  // namespace Unit

template <>
inline constexpr const Unit::MassDensity StandardUnit<Unit::MassDensity>{
    Unit::MassDensity::KilogramPerCubicMetre};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::MassDensity>{
    Dimension::Set{Dimension::Time{}, Dimension::Length{-3},
                   Dimension::Mass{1}}};

template <>
inline const std::map<UnitSystem, Unit::MassDensity>
    ConsistentUnits<Unit::MassDensity>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::MassDensity::KilogramPerCubicMetre},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::MassDensity::GramPerCubicMillimetre},
        {UnitSystem::FootPoundSecondRankine,
         Unit::MassDensity::SlugPerCubicFoot},
        {UnitSystem::InchPoundSecondRankine,
         Unit::MassDensity::SlinchPerCubicInch},
    };

template <>
inline const std::map<Unit::MassDensity, UnitSystem>
    RelatedUnitSystems<Unit::MassDensity>{
        {Unit::MassDensity::KilogramPerCubicMetre,
         UnitSystem::MetreKilogramSecondKelvin},
        {Unit::MassDensity::GramPerCubicMillimetre,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::MassDensity::SlugPerCubicFoot,
         UnitSystem::FootPoundSecondRankine},
        {Unit::MassDensity::SlinchPerCubicInch,
         UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::MassDensity, std::string_view>
    Abbreviations<Unit::MassDensity>{
        {Unit::MassDensity::KilogramPerCubicMetre, "kg/m^3"},
        {Unit::MassDensity::GramPerCubicMillimetre, "g/mm^3"},
        {Unit::MassDensity::SlugPerCubicFoot, "slug/ft^3"},
        {Unit::MassDensity::SlinchPerCubicInch, "slinch/in^3"},
        {Unit::MassDensity::PoundPerCubicFoot, "lbm/ft^3"},
        {Unit::MassDensity::PoundPerCubicInch, "lbm/in^3"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::MassDensity>
    Spellings<Unit::MassDensity>{
        {"kg/m^3", Unit::MassDensity::KilogramPerCubicMetre},
        {"kg/m3", Unit::MassDensity::KilogramPerCubicMetre},
        {"kg/m/m/m", Unit::MassDensity::KilogramPerCubicMetre},
        {"g/mm^3", Unit::MassDensity::GramPerCubicMillimetre},
        {"g/mm3", Unit::MassDensity::GramPerCubicMillimetre},
        {"g/mm/mm/mm", Unit::MassDensity::GramPerCubicMillimetre},
        {"slug/ft^3", Unit::MassDensity::SlugPerCubicFoot},
        {"slug/ft3", Unit::MassDensity::SlugPerCubicFoot},
        {"slug/ft/ft/ft", Unit::MassDensity::SlugPerCubicFoot},
        {"slinch/in^3", Unit::MassDensity::SlinchPerCubicInch},
        {"slinch/in3", Unit::MassDensity::SlinchPerCubicInch},
        {"slinch/in/in/in", Unit::MassDensity::SlinchPerCubicInch},
        {"lbm/ft^3", Unit::MassDensity::PoundPerCubicFoot},
        {"lbm/ft3", Unit::MassDensity::PoundPerCubicFoot},
        {"lbm/ft/ft/ft", Unit::MassDensity::PoundPerCubicFoot},
        {"lb/ft^3", Unit::MassDensity::PoundPerCubicFoot},
        {"lb/ft3", Unit::MassDensity::PoundPerCubicFoot},
        {"lb/ft/ft/ft", Unit::MassDensity::PoundPerCubicFoot},
        {"lbm/in^3", Unit::MassDensity::PoundPerCubicInch},
        {"lbm/in3", Unit::MassDensity::PoundPerCubicInch},
        {"lbm/in/in/in", Unit::MassDensity::PoundPerCubicInch},
        {"lb/in^3", Unit::MassDensity::PoundPerCubicInch},
        {"lb/in3", Unit::MassDensity::PoundPerCubicInch},
        {"lb/in/in/in", Unit::MassDensity::PoundPerCubicInch},
    };

template <>
inline const std::map<
    Unit::MassDensity,
    std::function<void(double* const values, const std::size_t size)>>
    Internal::MapOfConversionsFromStandard<Unit::MassDensity>{
        {Unit::MassDensity::KilogramPerCubicMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::MassDensity::GramPerCubicMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::MassDensity::SlugPerCubicFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.3048, 4) / (0.45359237 * 9.80665);
           }
         }},
        {Unit::MassDensity::SlinchPerCubicInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0254, 4) / (0.45359237 * 9.80665);
           }
         }},
        {Unit::MassDensity::PoundPerCubicFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.3048, 3) / 0.45359237;
           }
         }},
        {Unit::MassDensity::PoundPerCubicInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0254, 3) / 0.45359237;
           }
         }},
    };

template <>
inline const std::map<
    Unit::MassDensity,
    std::function<void(double* const values, const std::size_t size)>>
    Internal::MapOfConversionsToStandard<Unit::MassDensity>{
        {Unit::MassDensity::KilogramPerCubicMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::MassDensity::GramPerCubicMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::MassDensity::SlugPerCubicFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / std::pow(0.3048, 4);
           }
         }},
        {Unit::MassDensity::SlinchPerCubicInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / std::pow(0.0254, 4);
           }
         }},
        {Unit::MassDensity::PoundPerCubicFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 / std::pow(0.3048, 3);
           }
         }},
        {Unit::MassDensity::PoundPerCubicInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 / std::pow(0.0254, 3);
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_DENSITY_HPP
