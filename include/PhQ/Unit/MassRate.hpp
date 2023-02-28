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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_RATE_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class MassRate : int_least8_t {
  KilogramPerSecond,
  GramPerSecond,
  SlugPerSecond,
  SlinchPerSecond,
  PoundPerSecond,
};

}  // namespace Unit

template <>
inline constexpr const Unit::MassRate StandardUnit<Unit::MassRate>{
    Unit::MassRate::KilogramPerSecond};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::MassRate>{Dimension::Set{
    Dimension::Time{-1}, Dimension::Length{0}, Dimension::Mass{1}}};

template <>
inline const std::map<UnitSystem, Unit::MassRate>
    ConsistentUnits<Unit::MassRate>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::MassRate::KilogramPerSecond},
        {UnitSystem::MillimetreGramSecondKelvin, Unit::MassRate::GramPerSecond},
        {UnitSystem::FootPoundSecondRankine, Unit::MassRate::SlugPerSecond},
        {UnitSystem::InchPoundSecondRankine, Unit::MassRate::SlinchPerSecond},
    };

template <>
inline const std::map<Unit::MassRate, UnitSystem>
    RelatedUnitSystems<Unit::MassRate>{
        {Unit::MassRate::KilogramPerSecond,
         UnitSystem::MetreKilogramSecondKelvin},
        {Unit::MassRate::GramPerSecond, UnitSystem::MillimetreGramSecondKelvin},
        {Unit::MassRate::SlugPerSecond, UnitSystem::FootPoundSecondRankine},
        {Unit::MassRate::SlinchPerSecond, UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::MassRate, std::string_view>
    Abbreviations<Unit::MassRate>{
        {Unit::MassRate::KilogramPerSecond, "kg/s"},
        {Unit::MassRate::GramPerSecond, "g/s"},
        {Unit::MassRate::SlugPerSecond, "slug/s"},
        {Unit::MassRate::SlinchPerSecond, "slinch/s"},
        {Unit::MassRate::PoundPerSecond, "lbm/s"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::MassRate>
    Spellings<Unit::MassRate>{
        {"kg/s", Unit::MassRate::KilogramPerSecond},
        {"kg/sec", Unit::MassRate::KilogramPerSecond},
        {"g/s", Unit::MassRate::GramPerSecond},
        {"g/sec", Unit::MassRate::GramPerSecond},
        {"slug/s", Unit::MassRate::SlugPerSecond},
        {"slug/sec", Unit::MassRate::SlugPerSecond},
        {"slinch/s", Unit::MassRate::SlinchPerSecond},
        {"slinch/sec", Unit::MassRate::SlinchPerSecond},
        {"lbm/s", Unit::MassRate::PoundPerSecond},
        {"lbm/sec", Unit::MassRate::PoundPerSecond},
        {"lb/s", Unit::MassRate::PoundPerSecond},
        {"lb/sec", Unit::MassRate::PoundPerSecond},
    };

template <>
inline const std::map<
    Unit::MassRate,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::MassRate>{
        {Unit::MassRate::KilogramPerSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::MassRate::GramPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::MassRate::SlugPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.3048 / (0.45359237 * 9.80665);
           }
         }},
        {Unit::MassRate::SlinchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0254 / (0.45359237 * 9.80665);
           }
         }},
        {Unit::MassRate::PoundPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.45359237;
           }
         }},
    };

template <>
inline const std::map<
    Unit::MassRate,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::MassRate>{
        {Unit::MassRate::KilogramPerSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::MassRate::GramPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::MassRate::SlugPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / 0.3048;
           }
         }},
        {Unit::MassRate::SlinchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / 0.0254;
           }
         }},
        {Unit::MassRate::PoundPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_RATE_HPP
