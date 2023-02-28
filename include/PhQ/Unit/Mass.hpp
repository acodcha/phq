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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Mass : int_least8_t {
  Kilogram,
  Gram,
  Slug,
  Slinch,
  Pound,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Mass StandardUnit<Unit::Mass>{
    Unit::Mass::Kilogram};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Mass>{Dimension::Set{
    Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{1}}};

template <>
inline const std::map<UnitSystem, Unit::Mass> ConsistentUnits<Unit::Mass>{
    {UnitSystem::MetreKilogramSecondKelvin, Unit::Mass::Kilogram},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Mass::Gram},
    {UnitSystem::FootPoundSecondRankine, Unit::Mass::Slug},
    {UnitSystem::InchPoundSecondRankine, Unit::Mass::Slinch},
};

template <>
inline const std::map<Unit::Mass, UnitSystem> RelatedUnitSystems<Unit::Mass>{
    {Unit::Mass::Kilogram, UnitSystem::MetreKilogramSecondKelvin},
    {Unit::Mass::Gram, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Mass::Slug, UnitSystem::FootPoundSecondRankine},
    {Unit::Mass::Slinch, UnitSystem::InchPoundSecondRankine},
};

template <>
inline const std::map<Unit::Mass, std::string_view> Abbreviations<Unit::Mass>{
    {Unit::Mass::Kilogram, "kg"}, {Unit::Mass::Gram, "g"},
    {Unit::Mass::Slug, "slug"},   {Unit::Mass::Slinch, "slinch"},
    {Unit::Mass::Pound, "lbm"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Mass>
    Spellings<Unit::Mass>{
        {"kg", Unit::Mass::Kilogram}, {"g", Unit::Mass::Gram},
        {"slug", Unit::Mass::Slug},   {"slinch", Unit::Mass::Slinch},
        {"lbm", Unit::Mass::Pound},   {"lb", Unit::Mass::Pound},
    };

template <>
inline const std::map<Unit::Mass, std::function<void(double* const values,
                                                     const std::size_t size)>>
    ConversionsFromStandard<Unit::Mass>{
        {Unit::Mass::Kilogram,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Mass::Gram,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Mass::Slug,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.3048 / (0.45359237 * 9.80665);
           }
         }},
        {Unit::Mass::Slinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0254 / (0.45359237 * 9.80665);
           }
         }},
        {Unit::Mass::Pound,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.45359237;
           }
         }},
    };

template <>
inline const std::map<Unit::Mass, std::function<void(double* const values,
                                                     const std::size_t size)>>
    ConversionsToStandard<Unit::Mass>{
        {Unit::Mass::Kilogram,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Mass::Gram,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Mass::Slug,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / 0.3048;
           }
         }},
        {Unit::Mass::Slinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / 0.0254;
           }
         }},
        {Unit::Mass::Pound,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_HPP
