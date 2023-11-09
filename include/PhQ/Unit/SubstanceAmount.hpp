// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SUBSTANCE_AMOUNT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SUBSTANCE_AMOUNT_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimension/ElectricCurrent.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/Mass.hpp"
#include "../Dimension/SubstanceAmount.hpp"
#include "../Dimension/Temperature.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

// Amount of substance units.
enum class SubstanceAmount : int8_t {
  // Mole (mol) substance amount unit.
  Mole,

  // Kilomole (kmol) substance amount unit.
  Kilomole,

  // Megamole (Mmol) substance amount unit.
  Megamole,

  // Gigamole (Gmol) substance amount unit.
  Gigamole,

  // Particles (particles) substance amount unit.
  Particles,
};

}  // namespace Unit

// Standard amount of substance unit: mole (mol).
template <>
inline constexpr const Unit::SubstanceAmount Standard<Unit::SubstanceAmount>{
    Unit::SubstanceAmount::Mole};

// Physical dimension set of amount of substance units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::SubstanceAmount>{
    Dimensions{Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::SubstanceAmount unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::SubstanceAmount> ConsistentUnits<Unit::SubstanceAmount>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::SubstanceAmount::Mole},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::SubstanceAmount::Mole},
    {UnitSystem::FootPoundSecondRankine,     Unit::SubstanceAmount::Mole},
    {UnitSystem::InchPoundSecondRankine,     Unit::SubstanceAmount::Mole},
};

template <>
inline const std::map<Unit::SubstanceAmount, UnitSystem>
    RelatedUnitSystems<Unit::SubstanceAmount>{};

template <>
inline const std::map<Unit::SubstanceAmount, std::string_view> Abbreviations<Unit::SubstanceAmount>{
    {Unit::SubstanceAmount::Mole,      "mol"      },
    {Unit::SubstanceAmount::Kilomole,  "kmol"     },
    {Unit::SubstanceAmount::Megamole,  "Mmol"     },
    {Unit::SubstanceAmount::Gigamole,  "Gmol"     },
    {Unit::SubstanceAmount::Particles, "particles"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::SubstanceAmount>
    Spellings<Unit::SubstanceAmount>{
        {"mol",       Unit::SubstanceAmount::Mole     },
        {"kmol",      Unit::SubstanceAmount::Kilomole },
        {"Mmol",      Unit::SubstanceAmount::Megamole },
        {"Gmol",      Unit::SubstanceAmount::Gigamole },
        {"particles", Unit::SubstanceAmount::Particles},
};

template <>
inline constexpr void
ConversionFromStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Mole>(double&) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Kilomole>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Megamole>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Gigamole>(
    double& value) noexcept {
  value *= 0.000000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Particles>(
    double& value) noexcept {
  value *= 6.02214076e23;
}

template <>
inline constexpr void
ConversionToStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Mole>(double&) noexcept {}

template <>
inline constexpr void ConversionToStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Kilomole>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Megamole>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Gigamole>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Particles>(
    double& value) noexcept {
  value /= 6.02214076e23;
}

template <>
inline const std::map<Unit::SubstanceAmount,
                      std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::SubstanceAmount>{
        {Unit::SubstanceAmount::Mole,
         ConversionsFromStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Mole>     },
        {Unit::SubstanceAmount::Kilomole,
         ConversionsFromStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Kilomole> },
        {Unit::SubstanceAmount::Megamole,
         ConversionsFromStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Megamole> },
        {Unit::SubstanceAmount::Gigamole,
         ConversionsFromStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Gigamole> },
        {Unit::SubstanceAmount::Particles,
         ConversionsFromStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Particles>},
};

template <>
inline const std::map<Unit::SubstanceAmount,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::SubstanceAmount>{
        {Unit::SubstanceAmount::Mole,
         ConversionsToStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Mole>     },
        {Unit::SubstanceAmount::Kilomole,
         ConversionsToStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Kilomole> },
        {Unit::SubstanceAmount::Megamole,
         ConversionsToStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Megamole> },
        {Unit::SubstanceAmount::Gigamole,
         ConversionsToStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Gigamole> },
        {Unit::SubstanceAmount::Particles,
         ConversionsToStandard<Unit::SubstanceAmount, Unit::SubstanceAmount::Particles>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SUBSTANCE_AMOUNT_HPP
