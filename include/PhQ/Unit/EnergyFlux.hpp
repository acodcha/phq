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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_FLUX_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_FLUX_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class EnergyFlux : int_least8_t {
  WattPerSquareMetre,
  NanowattPerSquareMillimetre,
  FootPoundPerSquareFootPerSecond,
  InchPoundPerSquareInchPerSecond,
};

}  // namespace Unit

template <>
inline constexpr const Unit::EnergyFlux StandardUnit<Unit::EnergyFlux>{
    Unit::EnergyFlux::WattPerSquareMetre};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::EnergyFlux>{
    Dimension::Set{Dimension::Time{-3}, Dimension::Length{0},
                   Dimension::Mass{1}}};

template <>
inline const std::map<UnitSystem, Unit::EnergyFlux>
    ConsistentUnits<Unit::EnergyFlux>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::EnergyFlux::WattPerSquareMetre},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {UnitSystem::FootPoundSecondRankine,
         Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {UnitSystem::InchPoundSecondRankine,
         Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    };

template <>
inline const std::map<Unit::EnergyFlux, UnitSystem>
    RelatedUnitSystems<Unit::EnergyFlux>{
        {Unit::EnergyFlux::WattPerSquareMetre,
         UnitSystem::MetreKilogramSecondKelvin},
        {Unit::EnergyFlux::NanowattPerSquareMillimetre,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond,
         UnitSystem::FootPoundSecondRankine},
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond,
         UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::EnergyFlux, std::string_view>
    Abbreviations<Unit::EnergyFlux>{
        {Unit::EnergyFlux::WattPerSquareMetre, "W/m^2"},
        {Unit::EnergyFlux::NanowattPerSquareMillimetre, "nW/mm^2"},
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, "ft·lbf/ft^2/s"},
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, "in·lbf/in^2/s"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::EnergyFlux>
    Spellings<Unit::EnergyFlux>{
        {"W/m^2", Unit::EnergyFlux::WattPerSquareMetre},
        {"W/m2", Unit::EnergyFlux::WattPerSquareMetre},
        {"J/(m^2·s)", Unit::EnergyFlux::WattPerSquareMetre},
        {"J/(m^2*s)", Unit::EnergyFlux::WattPerSquareMetre},
        {"J/(m2·s)", Unit::EnergyFlux::WattPerSquareMetre},
        {"J/(m2*s)", Unit::EnergyFlux::WattPerSquareMetre},
        {"J/m^2/s", Unit::EnergyFlux::WattPerSquareMetre},
        {"J/m2/s", Unit::EnergyFlux::WattPerSquareMetre},
        {"N/(m·s)", Unit::EnergyFlux::WattPerSquareMetre},
        {"N/(m*s)", Unit::EnergyFlux::WattPerSquareMetre},
        {"N/m/s", Unit::EnergyFlux::WattPerSquareMetre},
        {"kg/s^3", Unit::EnergyFlux::WattPerSquareMetre},
        {"kg/s3", Unit::EnergyFlux::WattPerSquareMetre},
        {"nW/mm^2", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"nW/mm2", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"nJ/(mm^2·s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"nJ/(mm^2*s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"nJ/(mm2·s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"nJ/(mm2*s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"nJ/mm^2/s", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"nJ/mm2/s", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"μN/(mm·s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"μN/(mm*s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"μN/mm/s", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"uN/(mm·s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"uN/(mm*s)", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"uN/mm/s", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"g/s^3", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"g/s3", Unit::EnergyFlux::NanowattPerSquareMillimetre},
        {"ft·lbf/(ft^2·s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"ft·lbf/(ft2·s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"ft*lbf/(ft^2*s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"ft*lbf/(ft2*s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"ft·lbf/ft^2/s", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"ft·lbf/ft2/s", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"ft*lbf/ft^2/s", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"ft*lbf/ft2/s", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"lbf/(ft·s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"lbf/(ft*s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"lbf/ft/s", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"slug/s^3", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"slug/s3", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {"in·lbf/(in^2·s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"in·lbf/(in2·s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"in*lbf/(in^2*s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"in*lbf/(in2*s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"in·lbf/in^2/s", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"in·lbf/in2/s", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"in*lbf/in^2/s", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"in*lbf/in2/s", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"lbf/(in·s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"lbf/(in*s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"lbf/in/s", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"slinch/s^3", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
        {"slinch/s3", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    };

template <>
inline const std::map<
    Unit::EnergyFlux,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::EnergyFlux>{
        {Unit::EnergyFlux::WattPerSquareMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::EnergyFlux::NanowattPerSquareMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.3048 / (0.45359237 * 9.80665);
           }
         }},
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0254 / (0.45359237 * 9.80665);
           }
         }},
    };

template <>
inline const std::map<
    Unit::EnergyFlux,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::EnergyFlux>{
        {Unit::EnergyFlux::WattPerSquareMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::EnergyFlux::NanowattPerSquareMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / 0.3048;
           }
         }},
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / 0.0254;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_FLUX_HPP
