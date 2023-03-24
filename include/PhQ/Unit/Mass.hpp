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

namespace Internal {

template <>
inline constexpr void ConversionFromStandard<Unit::Mass, Unit::Mass::Kilogram>(
    double& value) noexcept {}

template <>
inline constexpr void ConversionFromStandard<Unit::Mass, Unit::Mass::Gram>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Mass, Unit::Mass::Slug>(
    double& value) noexcept {
  value *= 0.3048 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void ConversionFromStandard<Unit::Mass, Unit::Mass::Slinch>(
    double& value) noexcept {
  value *= 0.0254 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void ConversionFromStandard<Unit::Mass, Unit::Mass::Pound>(
    double& value) noexcept {
  value /= 0.45359237;
}

template <>
inline constexpr void ConversionToStandard<Unit::Mass, Unit::Mass::Kilogram>(
    double& value) noexcept {}

template <>
inline constexpr void ConversionToStandard<Unit::Mass, Unit::Mass::Gram>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void ConversionToStandard<Unit::Mass, Unit::Mass::Slug>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / 0.3048;
}

template <>
inline constexpr void ConversionToStandard<Unit::Mass, Unit::Mass::Slinch>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / 0.0254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Mass, Unit::Mass::Pound>(
    double& value) noexcept {
  value *= 0.45359237;
}

template <>
inline const std::map<
    Unit::Mass, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Mass>{
        {Unit::Mass::Kilogram,
         ConversionsFromStandard<Unit::Mass, Unit::Mass::Kilogram>},
        {Unit::Mass::Gram,
         ConversionsFromStandard<Unit::Mass, Unit::Mass::Gram>},
        {Unit::Mass::Slug,
         ConversionsFromStandard<Unit::Mass, Unit::Mass::Slug>},
        {Unit::Mass::Slinch,
         ConversionsFromStandard<Unit::Mass, Unit::Mass::Slinch>},
        {Unit::Mass::Pound,
         ConversionsFromStandard<Unit::Mass, Unit::Mass::Pound>},
    };

template <>
inline const std::map<Unit::Mass, std::function<void(double* const values,
                                                     const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Mass>{
        {Unit::Mass::Kilogram,
         ConversionsToStandard<Unit::Mass, Unit::Mass::Kilogram>},
        {Unit::Mass::Gram, ConversionsToStandard<Unit::Mass, Unit::Mass::Gram>},
        {Unit::Mass::Slug, ConversionsToStandard<Unit::Mass, Unit::Mass::Slug>},
        {Unit::Mass::Slinch,
         ConversionsToStandard<Unit::Mass, Unit::Mass::Slinch>},
        {Unit::Mass::Pound,
         ConversionsToStandard<Unit::Mass, Unit::Mass::Pound>},
    };

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_HPP
