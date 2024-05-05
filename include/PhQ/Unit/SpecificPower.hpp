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

#ifndef PHQ_UNIT_SPECIFIC_POWER_HPP
#define PHQ_UNIT_SPECIFIC_POWER_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

// Mass-specific power units.
enum class SpecificPower : int8_t {
  // Watt per kilogram (W/kg) specific power unit.
  WattPerKilogram,

  // Nanowatt per gram (nW/g) specific power unit.
  NanowattPerGram,

  // Foot-pound per slug per second (ft·lbf/slug/s) specific power unit.
  FootPoundPerSlugPerSecond,

  // Inch-pound per slinch per second (in·lbf/slinch/s) specific power unit.
  InchPoundPerSlinchPerSecond,
};

}  // namespace Unit

// Standard mass-specific power unit: watt per kilogram (W/kg).
template <>
inline constexpr const Unit::SpecificPower Standard<Unit::SpecificPower>{
    Unit::SpecificPower::WattPerKilogram};

// Physical dimension set of mass-specific power units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::SpecificPower>{
    Dimensions{Dimension::Time{-3}, Dimension::Length{2}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::SpecificPower unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::SpecificPower> ConsistentUnits<Unit::SpecificPower>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::SpecificPower::WattPerKilogram            },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::SpecificPower::NanowattPerGram            },
    {UnitSystem::FootPoundSecondRankine,     Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {UnitSystem::InchPoundSecondRankine,     Unit::SpecificPower::InchPoundPerSlinchPerSecond},
};

template <>
inline const std::map<Unit::SpecificPower, UnitSystem> RelatedUnitSystems<Unit::SpecificPower>{
    {Unit::SpecificPower::WattPerKilogram,             UnitSystem::MetreKilogramSecondKelvin },
    {Unit::SpecificPower::NanowattPerGram,             UnitSystem::MillimetreGramSecondKelvin},
    {Unit::SpecificPower::FootPoundPerSlugPerSecond,   UnitSystem::FootPoundSecondRankine    },
    {Unit::SpecificPower::InchPoundPerSlinchPerSecond, UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::SpecificPower, std::string_view> Abbreviations<Unit::SpecificPower>{
    {Unit::SpecificPower::WattPerKilogram,             "W/kg"           },
    {Unit::SpecificPower::NanowattPerGram,             "nW/g"           },
    {Unit::SpecificPower::FootPoundPerSlugPerSecond,   "ft·lbf/slug/s"  },
    {Unit::SpecificPower::InchPoundPerSlinchPerSecond, "in·lbf/slinch/s"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::SpecificPower> Spellings<
    Unit::SpecificPower>{
    {"W/kg",              Unit::SpecificPower::WattPerKilogram            },
    {"N·m/kg/s",          Unit::SpecificPower::WattPerKilogram            },
    {"N*m/kg/s",          Unit::SpecificPower::WattPerKilogram            },
    {"N·m/(kg·s)",        Unit::SpecificPower::WattPerKilogram            },
    {"N*m/(kg*s)",        Unit::SpecificPower::WattPerKilogram            },
    {"N·m/s/kg",          Unit::SpecificPower::WattPerKilogram            },
    {"N*m/s/kg",          Unit::SpecificPower::WattPerKilogram            },
    {"N·m/(s·kg)",        Unit::SpecificPower::WattPerKilogram            },
    {"N*m/(s*kg)",        Unit::SpecificPower::WattPerKilogram            },
    {"m·N/kg/s",          Unit::SpecificPower::WattPerKilogram            },
    {"m*N/kg/s",          Unit::SpecificPower::WattPerKilogram            },
    {"m·N/(kg·s)",        Unit::SpecificPower::WattPerKilogram            },
    {"m*N/(kg*s)",        Unit::SpecificPower::WattPerKilogram            },
    {"m·N/s/kg",          Unit::SpecificPower::WattPerKilogram            },
    {"m*N/s/kg",          Unit::SpecificPower::WattPerKilogram            },
    {"m·N/(s·kg)",        Unit::SpecificPower::WattPerKilogram            },
    {"m*N/(s*kg)",        Unit::SpecificPower::WattPerKilogram            },
    {"m^2/s^3",           Unit::SpecificPower::WattPerKilogram            },
    {"m2/s3",             Unit::SpecificPower::WattPerKilogram            },
    {"nW/g",              Unit::SpecificPower::NanowattPerGram            },
    {"μN·mm/g/s",         Unit::SpecificPower::NanowattPerGram            },
    {"μN*mm/g/s",         Unit::SpecificPower::NanowattPerGram            },
    {"μN·mm/(g·s)",       Unit::SpecificPower::NanowattPerGram            },
    {"μN*mm/(g*s)",       Unit::SpecificPower::NanowattPerGram            },
    {"uN·mm/g/s",         Unit::SpecificPower::NanowattPerGram            },
    {"uN*mm/g/s",         Unit::SpecificPower::NanowattPerGram            },
    {"uN·mm/(g·s)",       Unit::SpecificPower::NanowattPerGram            },
    {"uN*mm/(g*s)",       Unit::SpecificPower::NanowattPerGram            },
    {"μN·mm/s/g",         Unit::SpecificPower::NanowattPerGram            },
    {"μN*mm/s/g",         Unit::SpecificPower::NanowattPerGram            },
    {"μN·mm/(s·g)",       Unit::SpecificPower::NanowattPerGram            },
    {"μN*mm/(s*g)",       Unit::SpecificPower::NanowattPerGram            },
    {"uN·mm/s/g",         Unit::SpecificPower::NanowattPerGram            },
    {"uN*mm/s/g",         Unit::SpecificPower::NanowattPerGram            },
    {"uN·mm/(s·g)",       Unit::SpecificPower::NanowattPerGram            },
    {"uN*mm/(s*g)",       Unit::SpecificPower::NanowattPerGram            },
    {"mm·μN/g/s",         Unit::SpecificPower::NanowattPerGram            },
    {"mm*μN/g/s",         Unit::SpecificPower::NanowattPerGram            },
    {"mm·μN/(g·s)",       Unit::SpecificPower::NanowattPerGram            },
    {"mm*μN/(g*s)",       Unit::SpecificPower::NanowattPerGram            },
    {"mm·uN/g/s",         Unit::SpecificPower::NanowattPerGram            },
    {"mm*uN/g/s",         Unit::SpecificPower::NanowattPerGram            },
    {"mm·uN/(g·s)",       Unit::SpecificPower::NanowattPerGram            },
    {"mm*uN/(g*s)",       Unit::SpecificPower::NanowattPerGram            },
    {"mm·μN/s/g",         Unit::SpecificPower::NanowattPerGram            },
    {"mm*μN/s/g",         Unit::SpecificPower::NanowattPerGram            },
    {"mm·μN/(s·g)",       Unit::SpecificPower::NanowattPerGram            },
    {"mm*μN/(s*g)",       Unit::SpecificPower::NanowattPerGram            },
    {"mm·uN/s/g",         Unit::SpecificPower::NanowattPerGram            },
    {"mm*uN/s/g",         Unit::SpecificPower::NanowattPerGram            },
    {"mm·uN/(s·g)",       Unit::SpecificPower::NanowattPerGram            },
    {"mm*uN/(s*g)",       Unit::SpecificPower::NanowattPerGram            },
    {"mm^2/s^3",          Unit::SpecificPower::NanowattPerGram            },
    {"mm2/s3",            Unit::SpecificPower::NanowattPerGram            },
    {"ft·lbf/slug/s",     Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft*lbf/slug/s",     Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft·lbf/(slug·s)",   Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft*lbf/(slug*s)",   Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft·lbf/s/slug",     Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft*lbf/s/slug",     Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft·lbf/(s·slug)",   Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft*lbf/(s*slug)",   Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lbf·ft/slug/s",     Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lbf*ft/slug/s",     Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lbf·ft/(slug·s)",   Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lbf*ft/(slug*s)",   Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lbf·ft/s/slug",     Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lbf*ft/s/slug",     Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lbf·ft/(s·slug)",   Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lbf*ft/(s*slug)",   Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft·lb/slug/s",      Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft*lb/slug/s",      Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft·lb/(slug·s)",    Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft*lb/(slug*s)",    Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft·lb/s/slug",      Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft*lb/s/slug",      Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft·lb/(s·slug)",    Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft*lb/(s*slug)",    Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lb·ft/slug/s",      Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lb*ft/slug/s",      Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lb·ft/(slug·s)",    Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lb*ft/(slug*s)",    Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lb·ft/s/slug",      Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lb*ft/s/slug",      Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lb·ft/(s·slug)",    Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"lb*ft/(s*slug)",    Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft^2/s^3",          Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"ft2/s3",            Unit::SpecificPower::FootPoundPerSlugPerSecond  },
    {"in·lbf/slinch/s",   Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in*lbf/slinch/s",   Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in·lbf/(slinch·s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in*lbf/(slinch*s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in·lbf/s/slinch",   Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in*lbf/s/slinch",   Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in·lbf/(s·slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in*lbf/(s*slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lbf·in/slinch/s",   Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lbf*in/slinch/s",   Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lbf·in/(slinch·s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lbf*in/(slinch*s)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lbf·in/s/slinch",   Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lbf*in/s/slinch",   Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lbf·in/(s·slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lbf*in/(s*slinch)", Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in·lb/slinch/s",    Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in*lb/slinch/s",    Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in·lb/(slinch·s)",  Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in*lb/(slinch*s)",  Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in·lb/s/slinch",    Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in*lb/s/slinch",    Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in·lb/(s·slinch)",  Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in*lb/(s*slinch)",  Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lb·in/slinch/s",    Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lb*in/slinch/s",    Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lb·in/(slinch·s)",  Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lb*in/(slinch*s)",  Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lb·in/s/slinch",    Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lb*in/s/slinch",    Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lb·in/(s·slinch)",  Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"lb*in/(s*slinch)",  Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in^2/s^3",          Unit::SpecificPower::InchPoundPerSlinchPerSecond},
    {"in2/s3",            Unit::SpecificPower::InchPoundPerSlinchPerSecond},
};

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::WattPerKilogram>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::WattPerKilogram>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::NanowattPerGram>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::NanowattPerGram>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::FootPoundPerSlugPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::FootPoundPerSlugPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::InchPoundPerSlinchPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::InchPoundPerSlinchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L);
}

template <typename Number>
inline const std::map<Unit::SpecificPower,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::SpecificPower, Number>{
        {Unit::SpecificPower::WattPerKilogram,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::WattPerKilogram>::FromStandard<Number>            },
        {Unit::SpecificPower::NanowattPerGram,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::NanowattPerGram>::FromStandard<Number>            },
        {Unit::SpecificPower::FootPoundPerSlugPerSecond,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::FootPoundPerSlugPerSecond>::FromStandard<Number>  },
        {Unit::SpecificPower::InchPoundPerSlinchPerSecond,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::InchPoundPerSlinchPerSecond>::FromStandard<Number>},
};

template <typename Number>
inline const std::map<Unit::SpecificPower,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::SpecificPower, Number>{
        {Unit::SpecificPower::WattPerKilogram,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::WattPerKilogram>::ToStandard<Number>            },
        {Unit::SpecificPower::NanowattPerGram,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::NanowattPerGram>::ToStandard<Number>            },
        {Unit::SpecificPower::FootPoundPerSlugPerSecond,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::FootPoundPerSlugPerSecond>::ToStandard<Number>  },
        {Unit::SpecificPower::InchPoundPerSlinchPerSecond,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::InchPoundPerSlinchPerSecond>::ToStandard<Number>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_SPECIFIC_POWER_HPP
