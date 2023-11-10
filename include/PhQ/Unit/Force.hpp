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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FORCE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FORCE_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/Mass.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

// Force units.
enum class Force : int8_t {
  // Newton (N) force unit.
  Newton,

  // Kilonewton (kN) force unit.
  Kilonewton,

  // Meganewton (MN) force unit.
  Meganewton,

  // Giganewton (GN) force unit.
  Giganewton,

  // Millinewton (mN) force unit.
  Millinewton,

  // Micronewton (μN) force unit.
  Micronewton,

  // Nanonewton (nN) force unit.
  Nanonewton,

  // Dyne (dyn) force unit.
  Dyne,

  // Pound (lbf) force unit.
  Pound,
};

}  // namespace Unit

// Standard force unit: newton (N).
template <>
inline constexpr const Unit::Force Standard<Unit::Force>{Unit::Force::Newton};

// Physical dimension set of force units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Force>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Force unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Force> ConsistentUnits<Unit::Force>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Force::Newton     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Force::Micronewton},
    {UnitSystem::FootPoundSecondRankine,     Unit::Force::Pound      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Force::Pound      },
};

template <>
inline const std::map<Unit::Force, UnitSystem> RelatedUnitSystems<Unit::Force>{
    {Unit::Force::Newton,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Force::Micronewton, UnitSystem::MillimetreGramSecondKelvin},
};

template <>
inline const std::map<Unit::Force, std::string_view> Abbreviations<Unit::Force>{
    {Unit::Force::Newton,      "N"  },
    {Unit::Force::Kilonewton,  "kN" },
    {Unit::Force::Meganewton,  "MN" },
    {Unit::Force::Giganewton,  "GN" },
    {Unit::Force::Millinewton, "mN" },
    {Unit::Force::Micronewton, "μN" },
    {Unit::Force::Nanonewton,  "nN" },
    {Unit::Force::Dyne,        "dyn"},
    {Unit::Force::Pound,       "lbf"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Force> Spellings<Unit::Force>{
    {"N",        Unit::Force::Newton     },
    {"J/m",      Unit::Force::Newton     },
    {"kJ/km",    Unit::Force::Newton     },
    {"kg·m/s^2", Unit::Force::Newton     },
    {"kg*m/s^2", Unit::Force::Newton     },
    {"kg·m/s2",  Unit::Force::Newton     },
    {"kg*m/s2",  Unit::Force::Newton     },
    {"kN",       Unit::Force::Kilonewton },
    {"MN",       Unit::Force::Meganewton },
    {"GN",       Unit::Force::Giganewton },
    {"mN",       Unit::Force::Millinewton},
    {"μN",       Unit::Force::Micronewton},
    {"uN",       Unit::Force::Micronewton},
    {"nJ/mm",    Unit::Force::Micronewton},
    {"g·mm/s^2", Unit::Force::Micronewton},
    {"g*mm/s^2", Unit::Force::Micronewton},
    {"g·mm/s2",  Unit::Force::Micronewton},
    {"g*mm/s2",  Unit::Force::Micronewton},
    {"nN",       Unit::Force::Nanonewton },
    {"dyn",      Unit::Force::Dyne       },
    {"lbf",      Unit::Force::Pound      },
    {"lb",       Unit::Force::Pound      },
};

template <>
inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Newton>(double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Kilonewton>(double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Meganewton>(double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Giganewton>(double& value) noexcept {
  value *= 0.000000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Millinewton>(double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Micronewton>(double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Nanonewton>(double& value) noexcept {
  value *= 1000000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Dyne>(double& value) noexcept {
  value *= 100000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Force, Unit::Force::Pound>(double& value) noexcept {
  value /= 0.45359237 * 9.80665;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Newton>(double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Kilonewton>(double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Meganewton>(double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Giganewton>(double& value) noexcept {
  value *= 1000000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Millinewton>(double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Micronewton>(double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Nanonewton>(double& value) noexcept {
  value *= 0.000000001;
}

template <>
inline constexpr void ConversionToStandard<Unit::Force, Unit::Force::Dyne>(double& value) noexcept {
  value *= 0.00001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Force, Unit::Force::Pound>(double& value) noexcept {
  value *= 0.45359237 * 9.80665;
}

template <>
inline const std::map<Unit::Force, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Force>{
        {Unit::Force::Newton,      ConversionsFromStandard<Unit::Force, Unit::Force::Newton>     },
        {Unit::Force::Kilonewton,  ConversionsFromStandard<Unit::Force, Unit::Force::Kilonewton> },
        {Unit::Force::Meganewton,  ConversionsFromStandard<Unit::Force, Unit::Force::Meganewton> },
        {Unit::Force::Giganewton,  ConversionsFromStandard<Unit::Force, Unit::Force::Giganewton> },
        {Unit::Force::Millinewton, ConversionsFromStandard<Unit::Force, Unit::Force::Millinewton>},
        {Unit::Force::Micronewton, ConversionsFromStandard<Unit::Force, Unit::Force::Micronewton>},
        {Unit::Force::Nanonewton,  ConversionsFromStandard<Unit::Force, Unit::Force::Nanonewton> },
        {Unit::Force::Dyne,        ConversionsFromStandard<Unit::Force, Unit::Force::Dyne>       },
        {Unit::Force::Pound,       ConversionsFromStandard<Unit::Force, Unit::Force::Pound>      },
};

template <>
inline const std::map<Unit::Force,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Force>{
        {Unit::Force::Newton,      ConversionsToStandard<Unit::Force, Unit::Force::Newton>     },
        {Unit::Force::Kilonewton,  ConversionsToStandard<Unit::Force, Unit::Force::Kilonewton> },
        {Unit::Force::Meganewton,  ConversionsToStandard<Unit::Force, Unit::Force::Meganewton> },
        {Unit::Force::Giganewton,  ConversionsToStandard<Unit::Force, Unit::Force::Giganewton> },
        {Unit::Force::Millinewton, ConversionsToStandard<Unit::Force, Unit::Force::Millinewton>},
        {Unit::Force::Micronewton, ConversionsToStandard<Unit::Force, Unit::Force::Micronewton>},
        {Unit::Force::Nanonewton,  ConversionsToStandard<Unit::Force, Unit::Force::Nanonewton> },
        {Unit::Force::Dyne,        ConversionsToStandard<Unit::Force, Unit::Force::Dyne>       },
        {Unit::Force::Pound,       ConversionsToStandard<Unit::Force, Unit::Force::Pound>      },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FORCE_HPP
