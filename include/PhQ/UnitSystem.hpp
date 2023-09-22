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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SYSTEM_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SYSTEM_HPP

#include "Base.hpp"

namespace PhQ {

// Systems of units of measure. All units of measure in a unit system are
// standard units of measure. When a physical quantity is expressed in terms of
// a standard unit of measure, its value does not need to be converted when used
// in mathematical expressions with other physical quantities expressed in
// standard units of measure.
enum class UnitSystem : int8_t {
  // Metre-kilogram-second-kelvin (m·kg·s·K) system
  MetreKilogramSecondKelvin,

  // Millimetre-gram-second-kelvin (mm·g·s·K) system
  MillimetreGramSecondKelvin,

  // Foot-pound-second-rankine (ft·lbf·s·°R) system
  FootPoundSecondRankine,

  // Inch-pound-second-rankine (in·lbf·s·°R) system
  InchPoundSecondRankine,
};

// Standard unit of measure of a given type. Standard units of measure of
// different types can be combined with each other without the need for
// conversions. When a physical quantity is expressed in terms of a standard
// unit of measure, its value does not need to be converted when used in
// mathematical expressions with other physical quantities expressed in standard
// units of measure.
//
// For example, the standard unit of time is the second and the standard unit of
// length is the metre. Correspondingly, the standard unit of speed is the metre
// per second. Thus, when forming a speed quantity from a length quantity and a
// time quantity, if all quantities are expressed in these standard units, no
// unit conversions are needed.
template <typename Type>
inline constexpr const Type Standard;

// The standard unit system: the International System of Units (SI). It uses the
// following standard units: second for time, metre for length, kilogram for
// mass, ampere for electric current, kelvin for temperature, mole for substance
// amount, and candela for luminous intensity.
template <>
inline constexpr const UnitSystem Standard<UnitSystem>{
    UnitSystem::MetreKilogramSecondKelvin};

namespace Internal {

template <>
inline const std::map<UnitSystem, std::string_view> Abbreviations<UnitSystem>{
    {UnitSystem::MetreKilogramSecondKelvin,  "m·kg·s·K"   },
    {UnitSystem::MillimetreGramSecondKelvin, "mm·g·s·K"   },
    {UnitSystem::FootPoundSecondRankine,     "ft·lbf·s·°R"},
    {UnitSystem::InchPoundSecondRankine,     "in·lbf·s·°R"},
};

template <>
inline const std::unordered_map<std::string_view, UnitSystem> Spellings<
    UnitSystem>{
    {"m·kg·s·K",       UnitSystem::MetreKilogramSecondKelvin },
    {"m-kg-s-K",       UnitSystem::MetreKilogramSecondKelvin },
    {"m*kg*s*K",       UnitSystem::MetreKilogramSecondKelvin },
    {"m kg s K",       UnitSystem::MetreKilogramSecondKelvin },
    {"m, kg, s, K",    UnitSystem::MetreKilogramSecondKelvin },
    {"m·kg·s",         UnitSystem::MetreKilogramSecondKelvin },
    {"m-kg-s",         UnitSystem::MetreKilogramSecondKelvin },
    {"m*kg*s",         UnitSystem::MetreKilogramSecondKelvin },
    {"m kg s",         UnitSystem::MetreKilogramSecondKelvin },
    {"m, kg, s",       UnitSystem::MetreKilogramSecondKelvin },
    {"m·kg",           UnitSystem::MetreKilogramSecondKelvin },
    {"m-kg",           UnitSystem::MetreKilogramSecondKelvin },
    {"m*kg",           UnitSystem::MetreKilogramSecondKelvin },
    {"m kg",           UnitSystem::MetreKilogramSecondKelvin },
    {"m, kg",          UnitSystem::MetreKilogramSecondKelvin },
    {"m",              UnitSystem::MetreKilogramSecondKelvin },
    {"kg",             UnitSystem::MetreKilogramSecondKelvin },
    {"mm·g·s·K",       UnitSystem::MillimetreGramSecondKelvin},
    {"mm-g-s-K",       UnitSystem::MillimetreGramSecondKelvin},
    {"mm*g*s*K",       UnitSystem::MillimetreGramSecondKelvin},
    {"mm g s K",       UnitSystem::MillimetreGramSecondKelvin},
    {"mm, g, s, K",    UnitSystem::MillimetreGramSecondKelvin},
    {"mm·g·s",         UnitSystem::MillimetreGramSecondKelvin},
    {"mm-g-s",         UnitSystem::MillimetreGramSecondKelvin},
    {"mm*g*s",         UnitSystem::MillimetreGramSecondKelvin},
    {"mm g s",         UnitSystem::MillimetreGramSecondKelvin},
    {"mm, g, s",       UnitSystem::MillimetreGramSecondKelvin},
    {"mm·g",           UnitSystem::MillimetreGramSecondKelvin},
    {"mm-g",           UnitSystem::MillimetreGramSecondKelvin},
    {"mm*g",           UnitSystem::MillimetreGramSecondKelvin},
    {"mm g",           UnitSystem::MillimetreGramSecondKelvin},
    {"mm, g",          UnitSystem::MillimetreGramSecondKelvin},
    {"mm",             UnitSystem::MillimetreGramSecondKelvin},
    {"g",              UnitSystem::MillimetreGramSecondKelvin},
    {"ft·lbf·s·°R",    UnitSystem::FootPoundSecondRankine    },
    {"ft-lbf-s-°R",    UnitSystem::FootPoundSecondRankine    },
    {"ft*lbf*s*°R",    UnitSystem::FootPoundSecondRankine    },
    {"ft lbf s °R",    UnitSystem::FootPoundSecondRankine    },
    {"ft, lbf, s, °R", UnitSystem::FootPoundSecondRankine    },
    {"ft·lb·s·°R",     UnitSystem::FootPoundSecondRankine    },
    {"ft-lb-s-°R",     UnitSystem::FootPoundSecondRankine    },
    {"ft*lb*s*°R",     UnitSystem::FootPoundSecondRankine    },
    {"ft lb s °R",     UnitSystem::FootPoundSecondRankine    },
    {"ft, lb, s, °R",  UnitSystem::FootPoundSecondRankine    },
    {"ft·lbf·s·R",     UnitSystem::FootPoundSecondRankine    },
    {"ft-lbf-s-R",     UnitSystem::FootPoundSecondRankine    },
    {"ft*lbf*s*R",     UnitSystem::FootPoundSecondRankine    },
    {"ft lbf s R",     UnitSystem::FootPoundSecondRankine    },
    {"ft, lbf, s, R",  UnitSystem::FootPoundSecondRankine    },
    {"ft·lb·s·R",      UnitSystem::FootPoundSecondRankine    },
    {"ft-lb-s-R",      UnitSystem::FootPoundSecondRankine    },
    {"ft*lb*s*R",      UnitSystem::FootPoundSecondRankine    },
    {"ft lb s R",      UnitSystem::FootPoundSecondRankine    },
    {"ft, lb, s, R",   UnitSystem::FootPoundSecondRankine    },
    {"ft·lbf·s",       UnitSystem::FootPoundSecondRankine    },
    {"ft-lbf-s",       UnitSystem::FootPoundSecondRankine    },
    {"ft*lbf*s",       UnitSystem::FootPoundSecondRankine    },
    {"ft lbf s",       UnitSystem::FootPoundSecondRankine    },
    {"ft, lbf, s",     UnitSystem::FootPoundSecondRankine    },
    {"ft·lb·s",        UnitSystem::FootPoundSecondRankine    },
    {"ft-lb-s",        UnitSystem::FootPoundSecondRankine    },
    {"ft*lb*s",        UnitSystem::FootPoundSecondRankine    },
    {"ft lb s",        UnitSystem::FootPoundSecondRankine    },
    {"ft, lb, s",      UnitSystem::FootPoundSecondRankine    },
    {"ft·lbf",         UnitSystem::FootPoundSecondRankine    },
    {"ft-lbf",         UnitSystem::FootPoundSecondRankine    },
    {"ft*lbf",         UnitSystem::FootPoundSecondRankine    },
    {"ft lbf",         UnitSystem::FootPoundSecondRankine    },
    {"ft, lbf",        UnitSystem::FootPoundSecondRankine    },
    {"ft·lb",          UnitSystem::FootPoundSecondRankine    },
    {"ft-lb",          UnitSystem::FootPoundSecondRankine    },
    {"ft*lb",          UnitSystem::FootPoundSecondRankine    },
    {"ft lb",          UnitSystem::FootPoundSecondRankine    },
    {"ft, lb",         UnitSystem::FootPoundSecondRankine    },
    {"ft",             UnitSystem::FootPoundSecondRankine    },
    {"in·lbf·s·°R",    UnitSystem::InchPoundSecondRankine    },
    {"in-lbf-s-°R",    UnitSystem::InchPoundSecondRankine    },
    {"in*lbf*s*°R",    UnitSystem::InchPoundSecondRankine    },
    {"in lbf s °R",    UnitSystem::InchPoundSecondRankine    },
    {"in, lbf, s, °R", UnitSystem::InchPoundSecondRankine    },
    {"in·lb·s·°R",     UnitSystem::InchPoundSecondRankine    },
    {"in-lb-s-°R",     UnitSystem::InchPoundSecondRankine    },
    {"in*lb*s*°R",     UnitSystem::InchPoundSecondRankine    },
    {"in lb s °R",     UnitSystem::InchPoundSecondRankine    },
    {"in, lb, s, °R",  UnitSystem::InchPoundSecondRankine    },
    {"in·lbf·s·R",     UnitSystem::InchPoundSecondRankine    },
    {"in-lbf-s-R",     UnitSystem::InchPoundSecondRankine    },
    {"in*lbf*s*R",     UnitSystem::InchPoundSecondRankine    },
    {"in lbf s R",     UnitSystem::InchPoundSecondRankine    },
    {"in, lbf, s, R",  UnitSystem::InchPoundSecondRankine    },
    {"in·lb·s·R",      UnitSystem::InchPoundSecondRankine    },
    {"in-lb-s-R",      UnitSystem::InchPoundSecondRankine    },
    {"in*lb*s*R",      UnitSystem::InchPoundSecondRankine    },
    {"in lb s R",      UnitSystem::InchPoundSecondRankine    },
    {"in, lb, s, R",   UnitSystem::InchPoundSecondRankine    },
    {"in·lbf·s",       UnitSystem::InchPoundSecondRankine    },
    {"in-lbf-s",       UnitSystem::InchPoundSecondRankine    },
    {"in*lbf*s",       UnitSystem::InchPoundSecondRankine    },
    {"in lbf s",       UnitSystem::InchPoundSecondRankine    },
    {"in, lbf, s",     UnitSystem::InchPoundSecondRankine    },
    {"in·lb·s",        UnitSystem::InchPoundSecondRankine    },
    {"in-lb-s",        UnitSystem::InchPoundSecondRankine    },
    {"in*lb*s",        UnitSystem::InchPoundSecondRankine    },
    {"in lb s",        UnitSystem::InchPoundSecondRankine    },
    {"in, lb, s",      UnitSystem::InchPoundSecondRankine    },
    {"in·lbf",         UnitSystem::InchPoundSecondRankine    },
    {"in-lbf",         UnitSystem::InchPoundSecondRankine    },
    {"in*lbf",         UnitSystem::InchPoundSecondRankine    },
    {"in lbf",         UnitSystem::InchPoundSecondRankine    },
    {"in, lbf",        UnitSystem::InchPoundSecondRankine    },
    {"in·lb",          UnitSystem::InchPoundSecondRankine    },
    {"in-lb",          UnitSystem::InchPoundSecondRankine    },
    {"in*lb",          UnitSystem::InchPoundSecondRankine    },
    {"in lb",          UnitSystem::InchPoundSecondRankine    },
    {"in, lb",         UnitSystem::InchPoundSecondRankine    },
    {"in",             UnitSystem::InchPoundSecondRankine    },
};

// Map of unit systems to their corresponding units. This is an internal
// implementation detail and is not intended to be used except by the
// PhQ::ConsistentUnit function.
template <typename Unit>
inline const std::map<UnitSystem, Unit> ConsistentUnits;

// Map of units to their corresponding unit systems. This is an internal
// implementation detail and is not intended to be used except by the
// PhQ::RelatedUnitSystem function.
template <typename Unit>
inline const std::map<Unit, UnitSystem> RelatedUnitSystems;

}  // namespace Internal

// Returns the unit of a given type that corresponds to a given unit system. For
// example,
// PhQ::ConsistentUnit<Force>(PhQ::UnitSystem::MetreKilogramSecondKelvin)
// returns PhQ::Unit::Force::Newton.
template <typename Unit>
inline Unit ConsistentUnit(const UnitSystem& system) {
  return Internal::ConsistentUnits<Unit>.at(system);
}

// Returns the unit system, if any, that corresponds to a given unit, or
// std::nullptr otherwise. For example,
// PhQ::RelatedUnitSystem(PhQ::Unit::Length::Millimetre) returns
// PhQ::UnitSystem::MillimetreGramSecondKelvin.
template <typename Unit>
inline std::optional<UnitSystem> RelatedUnitSystem(const Unit& unit) {
  const typename std::map<Unit, UnitSystem>::const_iterator system{
      Internal::RelatedUnitSystems<Unit>.find(unit)};
  if (system != Internal::RelatedUnitSystems<Unit>.cend()) {
    return system->second;
  } else {
    return std::nullopt;
  }
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SYSTEM_HPP
