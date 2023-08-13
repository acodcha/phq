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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPECIFIC_POWER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPECIFIC_POWER_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

// Mass-specific power units.
enum class SpecificPower : int_least8_t {
  WattPerKilogram,
  NanowattPerGram,
  FootPoundPerSlugPerSecond,
  InchPoundPerSlinchPerSecond,
};

}  // namespace Unit

// Standard mass-specific power unit: watt per kilogram.
template<>
inline constexpr const Unit::SpecificPower Standard<Unit::SpecificPower>{
    Unit::SpecificPower::WattPerKilogram};

// Physical dimension set of mass-specific power units.
template<>
inline constexpr const Dimension::Set Dimensions<Unit::SpecificPower>{
    Dimension::Set{
                   Dimension::Time{-3}, Dimension::Length{2}, Dimension::Mass{}}
};

namespace Internal {

template<> inline const std::map<UnitSystem, Unit::SpecificPower>
    ConsistentUnits<Unit::SpecificPower>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::SpecificPower::WattPerKilogram            },
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::SpecificPower::NanowattPerGram            },
        {UnitSystem::FootPoundSecondRankine,
         Unit::SpecificPower::FootPoundPerSlugPerSecond  },
        {UnitSystem::InchPoundSecondRankine,
         Unit::SpecificPower::InchPoundPerSlinchPerSecond},
};

template<> inline const std::map<Unit::SpecificPower, UnitSystem>
    RelatedUnitSystems<Unit::SpecificPower>{
        {Unit::SpecificPower::WattPerKilogram,
         UnitSystem::MetreKilogramSecondKelvin },
        {Unit::SpecificPower::NanowattPerGram,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::SpecificPower::FootPoundPerSlugPerSecond,
         UnitSystem::FootPoundSecondRankine    },
        {Unit::SpecificPower::InchPoundPerSlinchPerSecond,
         UnitSystem::InchPoundSecondRankine    },
};

template<> inline const std::map<Unit::SpecificPower, std::string_view>
    Abbreviations<Unit::SpecificPower>{
        {Unit::SpecificPower::WattPerKilogram,             "W/kg"            },
        {Unit::SpecificPower::NanowattPerGram,             "nW/g"            },
        {Unit::SpecificPower::FootPoundPerSlugPerSecond,   "ft·lbf/slug/s"  },
        {Unit::SpecificPower::InchPoundPerSlinchPerSecond, "in·lbf/slinch/s"},
};

template<>
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

template<> inline constexpr void
ConversionFromStandard<Unit::SpecificPower,
                       Unit::SpecificPower::WattPerKilogram>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionFromStandard<Unit::SpecificPower,
                       Unit::SpecificPower::NanowattPerGram>(
    double& value) noexcept {
  value *= 1000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::SpecificPower,
                       Unit::SpecificPower::FootPoundPerSlugPerSecond>(
    double& value) noexcept {
  value /= std::pow(0.3048, 2);
}

template<> inline constexpr void
ConversionFromStandard<Unit::SpecificPower,
                       Unit::SpecificPower::InchPoundPerSlinchPerSecond>(
    double& value) noexcept {
  value /= std::pow(0.0254, 2);
}

template<> inline constexpr void
ConversionToStandard<Unit::SpecificPower, Unit::SpecificPower::WattPerKilogram>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::SpecificPower, Unit::SpecificPower::NanowattPerGram>(
    double& value) noexcept {
  value *= 0.000001;
}

template<> inline constexpr void
ConversionToStandard<Unit::SpecificPower,
                     Unit::SpecificPower::FootPoundPerSlugPerSecond>(
    double& value) noexcept {
  value *= std::pow(0.3048, 2);
}

template<> inline constexpr void
ConversionToStandard<Unit::SpecificPower,
                     Unit::SpecificPower::InchPoundPerSlinchPerSecond>(
    double& value) noexcept {
  value *= std::pow(0.0254, 2);
}

template<> inline const std::map<
    Unit::SpecificPower,
    std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::SpecificPower>{
        {Unit::SpecificPower::WattPerKilogram,
         ConversionsFromStandard<Unit::SpecificPower,
         Unit::SpecificPower::WattPerKilogram>            },
        {Unit::SpecificPower::NanowattPerGram,
         ConversionsFromStandard<Unit::SpecificPower,
         Unit::SpecificPower::NanowattPerGram>            },
        {Unit::SpecificPower::FootPoundPerSlugPerSecond,
         ConversionsFromStandard<Unit::SpecificPower,
         Unit::SpecificPower::FootPoundPerSlugPerSecond>  },
        {Unit::SpecificPower::InchPoundPerSlinchPerSecond,
         ConversionsFromStandard<
             Unit::SpecificPower,
         Unit::SpecificPower::InchPoundPerSlinchPerSecond>},
};

template<> inline const std::map<
    Unit::SpecificPower,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::SpecificPower>{
        {Unit::SpecificPower::WattPerKilogram,
         ConversionsToStandard<Unit::SpecificPower,
         Unit::SpecificPower::WattPerKilogram>            },
        {Unit::SpecificPower::NanowattPerGram,
         ConversionsToStandard<Unit::SpecificPower,
         Unit::SpecificPower::NanowattPerGram>            },
        {Unit::SpecificPower::FootPoundPerSlugPerSecond,
         ConversionsToStandard<Unit::SpecificPower,
         Unit::SpecificPower::FootPoundPerSlugPerSecond>  },
        {Unit::SpecificPower::InchPoundPerSlinchPerSecond,
         ConversionsToStandard<Unit::SpecificPower,
         Unit::SpecificPower::InchPoundPerSlinchPerSecond>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPECIFIC_POWER_HPP
