// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base/String.hpp"
#include "Base/Type.hpp"

namespace PhQ {

enum class System : uint_least8_t {
  MetreKilogramSecondKelvin,
  MillimetreGramSecondKelvin,
  FootPoundSecondRankine,
  InchPoundSecondRankine,
};

const System standard_system{System::MetreKilogramSecondKelvin};

template <> const std::map<System, std::string> abbreviations<System>{
  {System::MetreKilogramSecondKelvin, "m·kg·s·K"},
  {System::MillimetreGramSecondKelvin, "mm·g·s·K"},
  {System::FootPoundSecondRankine, "ft·lbf·s·°R"},
  {System::InchPoundSecondRankine, "in·lbf·s·°R"}
};

template <> const std::unordered_map<std::string, System> spellings<System>{
  {"m·kg·s·K", System::MetreKilogramSecondKelvin},
  {"m-kg-s-K", System::MetreKilogramSecondKelvin},
  {"m kg s K", System::MetreKilogramSecondKelvin},
  {"m, kg, s, K", System::MetreKilogramSecondKelvin},
  {"m·kg·s", System::MetreKilogramSecondKelvin},
  {"m-kg-s", System::MetreKilogramSecondKelvin},
  {"m kg s", System::MetreKilogramSecondKelvin},
  {"m, kg, s", System::MetreKilogramSecondKelvin},
  {"m·kg", System::MetreKilogramSecondKelvin},
  {"m-kg", System::MetreKilogramSecondKelvin},
  {"m kg", System::MetreKilogramSecondKelvin},
  {"m, kg", System::MetreKilogramSecondKelvin},
  {"m", System::MetreKilogramSecondKelvin},
  {"kg", System::MetreKilogramSecondKelvin},
  {"mm·g·s·K", System::MillimetreGramSecondKelvin},
  {"mm-g-s-K", System::MillimetreGramSecondKelvin},
  {"mm g s K", System::MillimetreGramSecondKelvin},
  {"mm, g, s, K", System::MillimetreGramSecondKelvin},
  {"mm·g·s", System::MillimetreGramSecondKelvin},
  {"mm-g-s", System::MillimetreGramSecondKelvin},
  {"mm g s", System::MillimetreGramSecondKelvin},
  {"mm, g, s", System::MillimetreGramSecondKelvin},
  {"mm·g", System::MillimetreGramSecondKelvin},
  {"mm-g", System::MillimetreGramSecondKelvin},
  {"mm g", System::MillimetreGramSecondKelvin},
  {"mm, g", System::MillimetreGramSecondKelvin},
  {"mm", System::MillimetreGramSecondKelvin},
  {"ft·lbf·s·°R", System::FootPoundSecondRankine},
  {"ft-lbf-s-°R", System::FootPoundSecondRankine},
  {"ft lbf s °R", System::FootPoundSecondRankine},
  {"ft, lbf, s, °R", System::FootPoundSecondRankine},
  {"ft·lb·s·°R", System::FootPoundSecondRankine},
  {"ft-lb-s-°R", System::FootPoundSecondRankine},
  {"ft lb s °R", System::FootPoundSecondRankine},
  {"ft, lb, s, °R", System::FootPoundSecondRankine},
  {"ft·lbf·s·R", System::FootPoundSecondRankine},
  {"ft-lbf-s-R", System::FootPoundSecondRankine},
  {"ft lbf s R", System::FootPoundSecondRankine},
  {"ft, lbf, s, R", System::FootPoundSecondRankine},
  {"ft·lb·s·R", System::FootPoundSecondRankine},
  {"ft-lb-s-R", System::FootPoundSecondRankine},
  {"ft lb s R", System::FootPoundSecondRankine},
  {"ft, lb, s, R", System::FootPoundSecondRankine},
  {"ft·lbf·s", System::FootPoundSecondRankine},
  {"ft-lbf-s", System::FootPoundSecondRankine},
  {"ft lbf s", System::FootPoundSecondRankine},
  {"ft, lbf, s", System::FootPoundSecondRankine},
  {"ft·lb·s", System::FootPoundSecondRankine},
  {"ft-lb-s", System::FootPoundSecondRankine},
  {"ft lb s", System::FootPoundSecondRankine},
  {"ft, lb, s", System::FootPoundSecondRankine},
  {"ft·lbf", System::FootPoundSecondRankine},
  {"ft-lbf", System::FootPoundSecondRankine},
  {"ft lbf", System::FootPoundSecondRankine},
  {"ft, lbf", System::FootPoundSecondRankine},
  {"ft·lb", System::FootPoundSecondRankine},
  {"ft-lb", System::FootPoundSecondRankine},
  {"ft lb", System::FootPoundSecondRankine},
  {"ft, lb", System::FootPoundSecondRankine},
  {"ft", System::FootPoundSecondRankine},
  {"in·lbf·s·°R", System::InchPoundSecondRankine},
  {"in-lbf-s-°R", System::InchPoundSecondRankine},
  {"in lbf s °R", System::InchPoundSecondRankine},
  {"in, lbf, s, °R", System::InchPoundSecondRankine},
  {"in·lb·s·°R", System::InchPoundSecondRankine},
  {"in-lb-s-°R", System::InchPoundSecondRankine},
  {"in lb s °R", System::InchPoundSecondRankine},
  {"in, lb, s, °R", System::InchPoundSecondRankine},
  {"in·lbf·s·R", System::InchPoundSecondRankine},
  {"in-lbf-s-R", System::InchPoundSecondRankine},
  {"in lbf s R", System::InchPoundSecondRankine},
  {"in, lbf, s, R", System::InchPoundSecondRankine},
  {"in·lb·s·R", System::InchPoundSecondRankine},
  {"in-lb-s-R", System::InchPoundSecondRankine},
  {"in lb s R", System::InchPoundSecondRankine},
  {"in, lb, s, R", System::InchPoundSecondRankine},
  {"in·lbf·s", System::InchPoundSecondRankine},
  {"in-lbf-s", System::InchPoundSecondRankine},
  {"in lbf s", System::InchPoundSecondRankine},
  {"in, lbf, s", System::InchPoundSecondRankine},
  {"in·lb·s", System::InchPoundSecondRankine},
  {"in-lb-s", System::InchPoundSecondRankine},
  {"in lb s", System::InchPoundSecondRankine},
  {"in, lb, s", System::InchPoundSecondRankine},
  {"in·lbf", System::InchPoundSecondRankine},
  {"in-lbf", System::InchPoundSecondRankine},
  {"in lbf", System::InchPoundSecondRankine},
  {"in, lbf", System::InchPoundSecondRankine},
  {"in·lb", System::InchPoundSecondRankine},
  {"in-lb", System::InchPoundSecondRankine},
  {"in lb", System::InchPoundSecondRankine},
  {"in, lb", System::InchPoundSecondRankine},
  {"in", System::InchPoundSecondRankine},
};

template <typename Unit> const std::map<System, Unit> consistent_units;

/// \brief Obtain a unit of a given type from a unit system.
/// \details For example, PhQ::unit<Force>(PhQ::System::MetreKilogramSecondKelvin) returns PhQ::Unit::Force::Newton.
template <typename Unit> constexpr Unit unit(const System& system) noexcept {
  return consistent_units<Unit>.at(system);
}

template <typename Unit> const std::map<Unit, System> related_systems;

/// \brief Obtain a unit system, if one exists, from a unit.
/// \details For example, PhQ::system(PhQ::Unit::Length::Millimetre) returns PhQ::System::MillimetreGramSecondKelvin.
template <typename Unit> std::optional<System> system(const Unit& unit) noexcept {
  const typename std::map<Unit, System>::const_iterator system{related_systems<Unit>.find(unit)};
  if (system != related_systems<Unit>.cend()) {
    return {system->second};
  } else {
    return {};
  }
}

} // namespace PhQ
