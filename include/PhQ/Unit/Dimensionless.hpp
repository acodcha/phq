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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DIMENSIONLESS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DIMENSIONLESS_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Dimensionless : int_least8_t {
  Dimensionless,
};

}  // namespace Unit

template<>
inline constexpr const Unit::Dimensionless StandardUnit<Unit::Dimensionless>{
    Unit::Dimensionless::Dimensionless};

template<>
inline constexpr const Dimension::Set Dimensions<Unit::Dimensionless>{
    Dimension::Set{}};

namespace Internal {

template<>
inline const std::map<UnitSystem, Unit::Dimensionless> ConsistentUnits<
    Unit::Dimensionless>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Dimensionless::Dimensionless},
    {UnitSystem::MillimetreGramSecondKelvin,
     Unit::Dimensionless::Dimensionless                                        },
    {UnitSystem::FootPoundSecondRankine,     Unit::Dimensionless::Dimensionless},
    {UnitSystem::InchPoundSecondRankine,     Unit::Dimensionless::Dimensionless},
};

template<> inline const std::map<Unit::Dimensionless, UnitSystem>
    RelatedUnitSystems<Unit::Dimensionless>{};

template<> inline const std::map<Unit::Dimensionless, std::string_view>
    Abbreviations<Unit::Dimensionless>{
        {Unit::Dimensionless::Dimensionless, ""},
};

template<>
inline const std::unordered_map<std::string_view, Unit::Dimensionless>
    Spellings<Unit::Dimensionless>{
        {"", Unit::Dimensionless::Dimensionless},
};

template<> inline constexpr void
ConversionFromStandard<Unit::Dimensionless, Unit::Dimensionless::Dimensionless>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::Dimensionless, Unit::Dimensionless::Dimensionless>(
    double& value) noexcept {}

template<> inline const std::map<
    Unit::Dimensionless,
    std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Dimensionless>{
        {Unit::Dimensionless::Dimensionless,
         ConversionsFromStandard<Unit::Dimensionless,
         Unit::Dimensionless::Dimensionless>},
};

template<> inline const std::map<
    Unit::Dimensionless,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Dimensionless>{
        {Unit::Dimensionless::Dimensionless,
         ConversionsToStandard<Unit::Dimensionless,
         Unit::Dimensionless::Dimensionless>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DIMENSIONLESS_HPP
