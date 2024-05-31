// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
#include "../Dimension/ElectricCurrent.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/LuminousIntensity.hpp"
#include "../Dimension/Mass.hpp"
#include "../Dimension/SubstanceAmount.hpp"
#include "../Dimension/Temperature.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

/// \brief Mass-specific power units.
enum class SpecificPower : int8_t {
  /// \brief Watt per kilogram (W/kg) specific power unit.
  WattPerKilogram,

  /// \brief Nanowatt per gram (nW/g) specific power unit.
  NanowattPerGram,

  /// \brief Foot-pound per slug per second (ft·lbf/slug/s) specific power unit.
  FootPoundPerSlugPerSecond,

  /// \brief Inch-pound per slinch per second (in·lbf/slinch/s) specific power unit.
  InchPoundPerSlinchPerSecond,
};

}  // namespace Unit

/// \brief Standard mass-specific power unit: watt per kilogram (W/kg).
template <>
inline constexpr const Unit::SpecificPower Standard<Unit::SpecificPower>{
    Unit::SpecificPower::WattPerKilogram};

/// \brief Physical dimension set of mass-specific power units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::SpecificPower>{
    Dimensions{Dimension::Time{-3}, Dimension::Length{2}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
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
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::WattPerKilogram>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::WattPerKilogram>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::NanowattPerGram>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::NanowattPerGram>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::FootPoundPerSlugPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::FootPoundPerSlugPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::InchPoundPerSlinchPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificPower, Unit::SpecificPower::InchPoundPerSlinchPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L);
}

template <typename NumericType>
inline const std::map<Unit::SpecificPower,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::SpecificPower, NumericType>{
        {Unit::SpecificPower::WattPerKilogram,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::WattPerKilogram>::FromStandard<NumericType>            },
        {Unit::SpecificPower::NanowattPerGram,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::NanowattPerGram>::FromStandard<NumericType>            },
        {Unit::SpecificPower::FootPoundPerSlugPerSecond,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::FootPoundPerSlugPerSecond>::FromStandard<NumericType>  },
        {Unit::SpecificPower::InchPoundPerSlinchPerSecond,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::InchPoundPerSlinchPerSecond>::FromStandard<NumericType>},
};

template <typename NumericType>
inline const std::map<Unit::SpecificPower,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::SpecificPower, NumericType>{
        {Unit::SpecificPower::WattPerKilogram,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::WattPerKilogram>::ToStandard<NumericType>            },
        {Unit::SpecificPower::NanowattPerGram,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::NanowattPerGram>::ToStandard<NumericType>            },
        {Unit::SpecificPower::FootPoundPerSlugPerSecond,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::FootPoundPerSlugPerSecond>::ToStandard<NumericType>  },
        {Unit::SpecificPower::InchPoundPerSlinchPerSecond,
         Conversions<Unit::SpecificPower,
         Unit::SpecificPower::InchPoundPerSlinchPerSecond>::ToStandard<NumericType>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_SPECIFIC_POWER_HPP
