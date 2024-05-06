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

#ifndef PHQ_UNIT_MASS_HPP
#define PHQ_UNIT_MASS_HPP

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

// Mass units.
enum class Mass : int8_t {
  // Kilogram (kg) mass unit.
  Kilogram,

  // Gram (g) mass unit.
  Gram,

  // Slug (slug) mass unit.
  Slug,

  // Slinch (slinch) mass unit.
  Slinch,

  // Pound (lbm) mass unit.
  Pound,
};

}  // namespace Unit

// Standard mass unit: kilogram (kg).
template <>
inline constexpr const Unit::Mass Standard<Unit::Mass>{Unit::Mass::Kilogram};

// Physical dimension set of mass units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Mass>{
    Dimensions{Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Mass unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Mass> ConsistentUnits<Unit::Mass>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Mass::Kilogram},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Mass::Gram    },
    {UnitSystem::FootPoundSecondRankine,     Unit::Mass::Slug    },
    {UnitSystem::InchPoundSecondRankine,     Unit::Mass::Slinch  },
};

template <>
inline const std::map<Unit::Mass, UnitSystem> RelatedUnitSystems<Unit::Mass>{
    {Unit::Mass::Kilogram, UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Mass::Gram,     UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Mass::Slug,     UnitSystem::FootPoundSecondRankine    },
    {Unit::Mass::Slinch,   UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::Mass, std::string_view> Abbreviations<Unit::Mass>{
    {Unit::Mass::Kilogram, "kg"    },
    {Unit::Mass::Gram,     "g"     },
    {Unit::Mass::Slug,     "slug"  },
    {Unit::Mass::Slinch,   "slinch"},
    {Unit::Mass::Pound,    "lbm"   },
};

template <>
inline const std::unordered_map<std::string_view, Unit::Mass> Spellings<Unit::Mass>{
    {"kg",     Unit::Mass::Kilogram},
    {"g",      Unit::Mass::Gram    },
    {"slug",   Unit::Mass::Slug    },
    {"slinch", Unit::Mass::Slinch  },
    {"lbm",    Unit::Mass::Pound   },
    {"lb",     Unit::Mass::Pound   },
};

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Mass, Unit::Mass::Kilogram>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Mass, Unit::Mass::Kilogram>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Mass, Unit::Mass::Gram>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Mass, Unit::Mass::Gram>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Mass, Unit::Mass::Slug>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Mass, Unit::Mass::Slug>::ToStandard(Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Mass, Unit::Mass::Slinch>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Mass, Unit::Mass::Slinch>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Mass, Unit::Mass::Pound>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.45359237L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Mass, Unit::Mass::Pound>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L);
}

template <typename Number>
inline const std::map<Unit::Mass, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Mass, Number>{
        {Unit::Mass::Kilogram, Conversions<Unit::Mass, Unit::Mass::Kilogram>::FromStandard<Number>},
        {Unit::Mass::Gram,     Conversions<Unit::Mass, Unit::Mass::Gram>::FromStandard<Number>    },
        {Unit::Mass::Slug,     Conversions<Unit::Mass, Unit::Mass::Slug>::FromStandard<Number>    },
        {Unit::Mass::Slinch,   Conversions<Unit::Mass, Unit::Mass::Slinch>::FromStandard<Number>  },
        {Unit::Mass::Pound,    Conversions<Unit::Mass, Unit::Mass::Pound>::FromStandard<Number>   },
};

template <typename Number>
inline const std::map<Unit::Mass, std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Mass, Number>{
        {Unit::Mass::Kilogram, Conversions<Unit::Mass, Unit::Mass::Kilogram>::ToStandard<Number>},
        {Unit::Mass::Gram,     Conversions<Unit::Mass, Unit::Mass::Gram>::ToStandard<Number>    },
        {Unit::Mass::Slug,     Conversions<Unit::Mass, Unit::Mass::Slug>::ToStandard<Number>    },
        {Unit::Mass::Slinch,   Conversions<Unit::Mass, Unit::Mass::Slinch>::ToStandard<Number>  },
        {Unit::Mass::Pound,    Conversions<Unit::Mass, Unit::Mass::Pound>::ToStandard<Number>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_MASS_HPP
