// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNITSYSTEM_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNITSYSTEM_HPP

#include "Base/Enumeration.hpp"

namespace PhQ {

enum class UnitSystem : int_least8_t {
  MetreKilogramSecondKelvin,
  MillimetreGramSecondKelvin,
  FootPoundSecondRankine,
  InchPoundSecondRankine,
};

const UnitSystem StandardUnitSystem{UnitSystem::MetreKilogramSecondKelvin};

template <> const std::map<UnitSystem, std::string> Abbreviations<UnitSystem>{
    {UnitSystem::MetreKilogramSecondKelvin, "m·kg·s·K"},
    {UnitSystem::MillimetreGramSecondKelvin, "mm·g·s·K"},
    {UnitSystem::FootPoundSecondRankine, "ft·lbf·s·°R"},
    {UnitSystem::InchPoundSecondRankine, "in·lbf·s·°R"}};

template <> const std::unordered_map<std::string, UnitSystem> Spellings<UnitSystem>{
    {"m·kg·s·K", UnitSystem::MetreKilogramSecondKelvin},
    {"m-kg-s-K", UnitSystem::MetreKilogramSecondKelvin},
    {"m*kg*s*K", UnitSystem::MetreKilogramSecondKelvin},
    {"m kg s K", UnitSystem::MetreKilogramSecondKelvin},
    {"m, kg, s, K", UnitSystem::MetreKilogramSecondKelvin},
    {"m·kg·s", UnitSystem::MetreKilogramSecondKelvin},
    {"m-kg-s", UnitSystem::MetreKilogramSecondKelvin},
    {"m*kg*s", UnitSystem::MetreKilogramSecondKelvin},
    {"m kg s", UnitSystem::MetreKilogramSecondKelvin},
    {"m, kg, s", UnitSystem::MetreKilogramSecondKelvin},
    {"m·kg", UnitSystem::MetreKilogramSecondKelvin},
    {"m-kg", UnitSystem::MetreKilogramSecondKelvin},
    {"m*kg", UnitSystem::MetreKilogramSecondKelvin},
    {"m kg", UnitSystem::MetreKilogramSecondKelvin},
    {"m, kg", UnitSystem::MetreKilogramSecondKelvin},
    {"m", UnitSystem::MetreKilogramSecondKelvin},
    {"kg", UnitSystem::MetreKilogramSecondKelvin},
    {"mm·g·s·K", UnitSystem::MillimetreGramSecondKelvin},
    {"mm-g-s-K", UnitSystem::MillimetreGramSecondKelvin},
    {"mm*g*s*K", UnitSystem::MillimetreGramSecondKelvin},
    {"mm g s K", UnitSystem::MillimetreGramSecondKelvin},
    {"mm, g, s, K", UnitSystem::MillimetreGramSecondKelvin},
    {"mm·g·s", UnitSystem::MillimetreGramSecondKelvin},
    {"mm-g-s", UnitSystem::MillimetreGramSecondKelvin},
    {"mm*g*s", UnitSystem::MillimetreGramSecondKelvin},
    {"mm g s", UnitSystem::MillimetreGramSecondKelvin},
    {"mm, g, s", UnitSystem::MillimetreGramSecondKelvin},
    {"mm·g", UnitSystem::MillimetreGramSecondKelvin},
    {"mm-g", UnitSystem::MillimetreGramSecondKelvin},
    {"mm*g", UnitSystem::MillimetreGramSecondKelvin},
    {"mm g", UnitSystem::MillimetreGramSecondKelvin},
    {"mm, g", UnitSystem::MillimetreGramSecondKelvin},
    {"mm", UnitSystem::MillimetreGramSecondKelvin},
    {"g", UnitSystem::MillimetreGramSecondKelvin},
    {"ft·lbf·s·°R", UnitSystem::FootPoundSecondRankine},
    {"ft-lbf-s-°R", UnitSystem::FootPoundSecondRankine},
    {"ft*lbf*s*°R", UnitSystem::FootPoundSecondRankine},
    {"ft lbf s °R", UnitSystem::FootPoundSecondRankine},
    {"ft, lbf, s, °R", UnitSystem::FootPoundSecondRankine},
    {"ft·lb·s·°R", UnitSystem::FootPoundSecondRankine},
    {"ft-lb-s-°R", UnitSystem::FootPoundSecondRankine},
    {"ft*lb*s*°R", UnitSystem::FootPoundSecondRankine},
    {"ft lb s °R", UnitSystem::FootPoundSecondRankine},
    {"ft, lb, s, °R", UnitSystem::FootPoundSecondRankine},
    {"ft·lbf·s·R", UnitSystem::FootPoundSecondRankine},
    {"ft-lbf-s-R", UnitSystem::FootPoundSecondRankine},
    {"ft*lbf*s*R", UnitSystem::FootPoundSecondRankine},
    {"ft lbf s R", UnitSystem::FootPoundSecondRankine},
    {"ft, lbf, s, R", UnitSystem::FootPoundSecondRankine},
    {"ft·lb·s·R", UnitSystem::FootPoundSecondRankine},
    {"ft-lb-s-R", UnitSystem::FootPoundSecondRankine},
    {"ft*lb*s*R", UnitSystem::FootPoundSecondRankine},
    {"ft lb s R", UnitSystem::FootPoundSecondRankine},
    {"ft, lb, s, R", UnitSystem::FootPoundSecondRankine},
    {"ft·lbf·s", UnitSystem::FootPoundSecondRankine},
    {"ft-lbf-s", UnitSystem::FootPoundSecondRankine},
    {"ft*lbf*s", UnitSystem::FootPoundSecondRankine},
    {"ft lbf s", UnitSystem::FootPoundSecondRankine},
    {"ft, lbf, s", UnitSystem::FootPoundSecondRankine},
    {"ft·lb·s", UnitSystem::FootPoundSecondRankine},
    {"ft-lb-s", UnitSystem::FootPoundSecondRankine},
    {"ft*lb*s", UnitSystem::FootPoundSecondRankine},
    {"ft lb s", UnitSystem::FootPoundSecondRankine},
    {"ft, lb, s", UnitSystem::FootPoundSecondRankine},
    {"ft·lbf", UnitSystem::FootPoundSecondRankine},
    {"ft-lbf", UnitSystem::FootPoundSecondRankine},
    {"ft*lbf", UnitSystem::FootPoundSecondRankine},
    {"ft lbf", UnitSystem::FootPoundSecondRankine},
    {"ft, lbf", UnitSystem::FootPoundSecondRankine},
    {"ft·lb", UnitSystem::FootPoundSecondRankine},
    {"ft-lb", UnitSystem::FootPoundSecondRankine},
    {"ft*lb", UnitSystem::FootPoundSecondRankine},
    {"ft lb", UnitSystem::FootPoundSecondRankine},
    {"ft, lb", UnitSystem::FootPoundSecondRankine},
    {"ft", UnitSystem::FootPoundSecondRankine},
    {"in·lbf·s·°R", UnitSystem::InchPoundSecondRankine},
    {"in-lbf-s-°R", UnitSystem::InchPoundSecondRankine},
    {"in*lbf*s*°R", UnitSystem::InchPoundSecondRankine},
    {"in lbf s °R", UnitSystem::InchPoundSecondRankine},
    {"in, lbf, s, °R", UnitSystem::InchPoundSecondRankine},
    {"in·lb·s·°R", UnitSystem::InchPoundSecondRankine},
    {"in-lb-s-°R", UnitSystem::InchPoundSecondRankine},
    {"in*lb*s*°R", UnitSystem::InchPoundSecondRankine},
    {"in lb s °R", UnitSystem::InchPoundSecondRankine},
    {"in, lb, s, °R", UnitSystem::InchPoundSecondRankine},
    {"in·lbf·s·R", UnitSystem::InchPoundSecondRankine},
    {"in-lbf-s-R", UnitSystem::InchPoundSecondRankine},
    {"in*lbf*s*R", UnitSystem::InchPoundSecondRankine},
    {"in lbf s R", UnitSystem::InchPoundSecondRankine},
    {"in, lbf, s, R", UnitSystem::InchPoundSecondRankine},
    {"in·lb·s·R", UnitSystem::InchPoundSecondRankine},
    {"in-lb-s-R", UnitSystem::InchPoundSecondRankine},
    {"in*lb*s*R", UnitSystem::InchPoundSecondRankine},
    {"in lb s R", UnitSystem::InchPoundSecondRankine},
    {"in, lb, s, R", UnitSystem::InchPoundSecondRankine},
    {"in·lbf·s", UnitSystem::InchPoundSecondRankine},
    {"in-lbf-s", UnitSystem::InchPoundSecondRankine},
    {"in*lbf*s", UnitSystem::InchPoundSecondRankine},
    {"in lbf s", UnitSystem::InchPoundSecondRankine},
    {"in, lbf, s", UnitSystem::InchPoundSecondRankine},
    {"in·lb·s", UnitSystem::InchPoundSecondRankine},
    {"in-lb-s", UnitSystem::InchPoundSecondRankine},
    {"in*lb*s", UnitSystem::InchPoundSecondRankine},
    {"in lb s", UnitSystem::InchPoundSecondRankine},
    {"in, lb, s", UnitSystem::InchPoundSecondRankine},
    {"in·lbf", UnitSystem::InchPoundSecondRankine},
    {"in-lbf", UnitSystem::InchPoundSecondRankine},
    {"in*lbf", UnitSystem::InchPoundSecondRankine},
    {"in lbf", UnitSystem::InchPoundSecondRankine},
    {"in, lbf", UnitSystem::InchPoundSecondRankine},
    {"in·lb", UnitSystem::InchPoundSecondRankine},
    {"in-lb", UnitSystem::InchPoundSecondRankine},
    {"in*lb", UnitSystem::InchPoundSecondRankine},
    {"in lb", UnitSystem::InchPoundSecondRankine},
    {"in, lb", UnitSystem::InchPoundSecondRankine},
    {"in", UnitSystem::InchPoundSecondRankine},
};

template <typename Unit> const std::map<UnitSystem, Unit> ConsistentUnits;

/// \brief Obtain a unit of a given type from a unit system.
/// \details For example, PhQ::unit<Force>(PhQ::UnitSystem::MetreKilogramSecondKelvin) returns PhQ::Unit::Force::Newton.
template <typename Unit> constexpr Unit unit(const UnitSystem& system) noexcept {
  return ConsistentUnits<Unit>.at(system);
}

template <typename Unit> const std::map<Unit, UnitSystem> RelatedUnitSystems;

/// \brief Obtain a unit system, if one exists, from a unit.
/// \details For example, PhQ::unit_system(PhQ::Unit::Length::Millimetre) returns PhQ::UnitSystem::MillimetreGramSecondKelvin.
template <typename Unit> std::optional<UnitSystem> unit_system(const Unit& unit) noexcept {
  const typename std::map<Unit, UnitSystem>::const_iterator system{RelatedUnitSystems<Unit>.find(unit)};
  if (system != RelatedUnitSystems<Unit>.cend()) {
    return system->second;
  } else {
    return std::nullopt;
  }
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNITSYSTEM_HPP
