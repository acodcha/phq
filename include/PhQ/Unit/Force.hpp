// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#ifndef PHQ_UNIT_FORCE_HPP
#define PHQ_UNIT_FORCE_HPP

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
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Newton>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Newton>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Kilonewton>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Kilonewton>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Meganewton>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Meganewton>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Giganewton>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Giganewton>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Millinewton>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Millinewton>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Micronewton>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Micronewton>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Nanonewton>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Nanonewton>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Dyne>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(100000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Dyne>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.00001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Pound>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Force, Unit::Force::Pound>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L);
}

template <typename Number>
inline const std::map<Unit::Force, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Force, Number>{
        {Unit::Force::Newton,      Conversions<Unit::Force, Unit::Force::Newton>::FromStandard<Number>     },
        {Unit::Force::Kilonewton,
         Conversions<Unit::Force,                           Unit::Force::Kilonewton>::FromStandard<Number> },
        {Unit::Force::Meganewton,
         Conversions<Unit::Force,                           Unit::Force::Meganewton>::FromStandard<Number> },
        {Unit::Force::Giganewton,
         Conversions<Unit::Force,                           Unit::Force::Giganewton>::FromStandard<Number> },
        {Unit::Force::Millinewton,
         Conversions<Unit::Force,                           Unit::Force::Millinewton>::FromStandard<Number>},
        {Unit::Force::Micronewton,
         Conversions<Unit::Force,                           Unit::Force::Micronewton>::FromStandard<Number>},
        {Unit::Force::Nanonewton,
         Conversions<Unit::Force,                           Unit::Force::Nanonewton>::FromStandard<Number> },
        {Unit::Force::Dyne,        Conversions<Unit::Force, Unit::Force::Dyne>::FromStandard<Number>       },
        {Unit::Force::Pound,       Conversions<Unit::Force, Unit::Force::Pound>::FromStandard<Number>      },
};

template <typename Number>
inline const std::map<Unit::Force,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Force, Number>{
        {Unit::Force::Newton,      Conversions<Unit::Force, Unit::Force::Newton>::ToStandard<Number>     },
        {Unit::Force::Kilonewton,
         Conversions<Unit::Force,                           Unit::Force::Kilonewton>::ToStandard<Number> },
        {Unit::Force::Meganewton,
         Conversions<Unit::Force,                           Unit::Force::Meganewton>::ToStandard<Number> },
        {Unit::Force::Giganewton,
         Conversions<Unit::Force,                           Unit::Force::Giganewton>::ToStandard<Number> },
        {Unit::Force::Millinewton,
         Conversions<Unit::Force,                           Unit::Force::Millinewton>::ToStandard<Number>},
        {Unit::Force::Micronewton,
         Conversions<Unit::Force,                           Unit::Force::Micronewton>::ToStandard<Number>},
        {Unit::Force::Nanonewton,
         Conversions<Unit::Force,                           Unit::Force::Nanonewton>::ToStandard<Number> },
        {Unit::Force::Dyne,        Conversions<Unit::Force, Unit::Force::Dyne>::ToStandard<Number>       },
        {Unit::Force::Pound,       Conversions<Unit::Force, Unit::Force::Pound>::ToStandard<Number>      },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_FORCE_HPP
