// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_UNIT_SYSTEM_HPP
#define PHQ_UNIT_SYSTEM_HPP

#include <cstdint>
#include <map>
#include <optional>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "Base.hpp"

namespace PhQ {

/// \brief Systems of units of measure. All units of measure in a unit system are standard units of
/// measure. When a physical quantity is expressed in terms of a standard unit of measure, its value
/// does not need to be converted when used in mathematical expressions with other physical
/// quantities expressed in standard units of measure.
enum class UnitSystem : int8_t {
  /// \brief Metre-kilogram-second-kelvin (m·kg·s·K) system
  MetreKilogramSecondKelvin,

  /// \brief Millimetre-gram-second-kelvin (mm·g·s·K) system
  MillimetreGramSecondKelvin,

  /// \brief Foot-pound-second-rankine (ft·lbf·s·°R) system
  FootPoundSecondRankine,

  /// \brief Inch-pound-second-rankine (in·lbf·s·°R) system
  InchPoundSecondRankine,
};

/// \brief Standard unit of measure of a given type. Standard units of measure of different types
/// can be combined with each other without the need for conversions. When a physical quantity is
/// expressed in terms of a standard unit of measure, its value does not need to be converted when
/// used in mathematical expressions with other physical quantities expressed in standard units of
/// measure. For example, the standard unit of time is the second and the standard unit of length is
/// the metre. Correspondingly, the standard unit of speed is the metre per second. Thus, when
/// forming a speed quantity from a length quantity and a time quantity, if all quantities are
/// expressed in these standard units, no unit conversions are needed.
template <typename Type>
inline constexpr const Type Standard;

/// \brief The standard unit system: the International System of Units (SI). It uses the following
/// standard units: second (s) for time, metre (m) for length, kilogram (kg) for mass, ampere (A)
/// for electric current, kelvin (K) for temperature, mole (mol) for substance amount, and candela
/// (cd) for luminous intensity.
template <>
inline constexpr const UnitSystem Standard<UnitSystem>{UnitSystem::MetreKilogramSecondKelvin};

namespace Internal {

// clang-format off

template <>
inline const std::map<UnitSystem, std::string_view> Abbreviations<UnitSystem>{
    {UnitSystem::MetreKilogramSecondKelvin,  "m·kg·s·K"   },
    {UnitSystem::MillimetreGramSecondKelvin, "mm·g·s·K"   },
    {UnitSystem::FootPoundSecondRankine,     "ft·lbf·s·°R"},
    {UnitSystem::InchPoundSecondRankine,     "in·lbf·s·°R"},
};

template <>
inline const std::unordered_map<std::string_view, UnitSystem> Spellings<UnitSystem>{
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

// clang-format on

/// \brief Map of unit systems to their corresponding units. This is an internal implementation
/// detail and is not intended to be used except by the PhQ::ConsistentUnit function.
template <typename Unit>
inline const std::map<UnitSystem, Unit> ConsistentUnits;

/// \brief Map of units to their corresponding unit systems. This is an internal implementation
/// detail and is not intended to be used except by the PhQ::RelatedUnitSystem function.
template <typename Unit>
inline const std::map<Unit, UnitSystem> RelatedUnitSystems;

}  // namespace Internal

/// \brief Returns the unit of a given type that corresponds to a given unit system. For example,
/// PhQ::ConsistentUnit<Force>(PhQ::UnitSystem::MetreKilogramSecondKelvin) returns
/// PhQ::Unit::Force::Newton.
template <typename Unit>
inline Unit ConsistentUnit(const UnitSystem& system) {
  return Internal::ConsistentUnits<Unit>.at(system);
}

/// \brief Returns the unit system, if any, that corresponds to a given unit, or std::nullptr
/// otherwise. For example, PhQ::RelatedUnitSystem(PhQ::Unit::Length::Millimetre) returns
/// PhQ::UnitSystem::MillimetreGramSecondKelvin.
template <typename Unit>
inline std::optional<UnitSystem> RelatedUnitSystem(const Unit& unit) {
  const typename std::map<Unit, UnitSystem>::const_iterator system{
      Internal::RelatedUnitSystems<Unit>.find(unit)};
  if (system != Internal::RelatedUnitSystems<Unit>.cend()) {
    return system->second;
  }
  return std::nullopt;
}

inline std::ostream& operator<<(std::ostream& stream, const UnitSystem unit_system) {
  stream << Abbreviation(unit_system);
  return stream;
}

}  // namespace PhQ

#endif  // PHQ_UNIT_SYSTEM_HPP
