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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPECIFIC_ENERGY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPECIFIC_ENERGY_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class SpecificEnergy : int_least8_t {
  JoulePerKilogram,
  NanojoulePerGram,
  FootPoundPerSlug,
  InchPoundPerSlinch,
};

}  // namespace Unit

template <>
inline constexpr const Unit::SpecificEnergy StandardUnit<Unit::SpecificEnergy>{
    Unit::SpecificEnergy::JoulePerKilogram};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::SpecificEnergy>{
    Dimension::Set{Dimension::Time{-2}, Dimension::Length{2}}};

template <>
inline const std::map<UnitSystem, Unit::SpecificEnergy>
    ConsistentUnits<Unit::SpecificEnergy>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::SpecificEnergy::JoulePerKilogram},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::SpecificEnergy::NanojoulePerGram},
        {UnitSystem::FootPoundSecondRankine,
         Unit::SpecificEnergy::FootPoundPerSlug},
        {UnitSystem::InchPoundSecondRankine,
         Unit::SpecificEnergy::InchPoundPerSlinch},
    };

template <>
inline const std::map<Unit::SpecificEnergy, UnitSystem>
    RelatedUnitSystems<Unit::SpecificEnergy>{
        {Unit::SpecificEnergy::JoulePerKilogram,
         UnitSystem::MetreKilogramSecondKelvin},
        {Unit::SpecificEnergy::NanojoulePerGram,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::SpecificEnergy::FootPoundPerSlug,
         UnitSystem::FootPoundSecondRankine},
        {Unit::SpecificEnergy::InchPoundPerSlinch,
         UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::SpecificEnergy, std::string_view>
    Abbreviations<Unit::SpecificEnergy>{
        {Unit::SpecificEnergy::JoulePerKilogram, "J/kg"},
        {Unit::SpecificEnergy::NanojoulePerGram, "nJ/g"},
        {Unit::SpecificEnergy::FootPoundPerSlug, "ft·lbf/slug"},
        {Unit::SpecificEnergy::InchPoundPerSlinch, "in·lbf/slinch"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::SpecificEnergy>
    Spellings<Unit::SpecificEnergy>{
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
        {"in2/s2", Unit::SpecificEnergy::InchPoundPerSlinch},
    };

template <>
inline const std::map<
    Unit::SpecificEnergy,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::SpecificEnergy>{
        {Unit::SpecificEnergy::JoulePerKilogram,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::SpecificEnergy::NanojoulePerGram,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::SpecificEnergy::FootPoundPerSlug,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.3048, 2);
           }
         }},
        {Unit::SpecificEnergy::InchPoundPerSlinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0254, 2);
           }
         }},
    };

template <>
inline const std::map<
    Unit::SpecificEnergy,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::SpecificEnergy>{
        {Unit::SpecificEnergy::JoulePerKilogram,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::SpecificEnergy::NanojoulePerGram,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::SpecificEnergy::FootPoundPerSlug,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.3048, 2);
           }
         }},
        {Unit::SpecificEnergy::InchPoundPerSlinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0254, 2);
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPECIFIC_ENERGY_HPP
