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

#ifndef PHQ_UNIT_SPECIFIC_ENERGY_HPP
#define PHQ_UNIT_SPECIFIC_ENERGY_HPP

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

// Mass-specific energy units.
enum class SpecificEnergy : int8_t {
  // Joule per kilogram (J/kg) specific energy unit.
  JoulePerKilogram,

  // Nanojoule per gram (nJ/g) specific energy unit.
  NanojoulePerGram,

  // Foot-pound per slug (ft·lbf/slug) specific energy unit.
  FootPoundPerSlug,

  // Inch-pound per slinch (in·lbf/slinch) specific energy unit.
  InchPoundPerSlinch,
};

}  // namespace Unit

// Standard mass-specific energy unit: joule per kilogram (J/kg).
template <>
inline constexpr const Unit::SpecificEnergy Standard<Unit::SpecificEnergy>{
    Unit::SpecificEnergy::JoulePerKilogram};

// Physical dimension set of mass-specific energy units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::SpecificEnergy>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{2}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::SpecificEnergy unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::SpecificEnergy> ConsistentUnits<Unit::SpecificEnergy>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::SpecificEnergy::JoulePerKilogram  },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::SpecificEnergy::NanojoulePerGram  },
    {UnitSystem::FootPoundSecondRankine,     Unit::SpecificEnergy::FootPoundPerSlug  },
    {UnitSystem::InchPoundSecondRankine,     Unit::SpecificEnergy::InchPoundPerSlinch},
};

template <>
inline const std::map<Unit::SpecificEnergy, UnitSystem> RelatedUnitSystems<Unit::SpecificEnergy>{
    {Unit::SpecificEnergy::JoulePerKilogram,   UnitSystem::MetreKilogramSecondKelvin },
    {Unit::SpecificEnergy::NanojoulePerGram,   UnitSystem::MillimetreGramSecondKelvin},
    {Unit::SpecificEnergy::FootPoundPerSlug,   UnitSystem::FootPoundSecondRankine    },
    {Unit::SpecificEnergy::InchPoundPerSlinch, UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::SpecificEnergy, std::string_view> Abbreviations<Unit::SpecificEnergy>{
    {Unit::SpecificEnergy::JoulePerKilogram,   "J/kg"         },
    {Unit::SpecificEnergy::NanojoulePerGram,   "nJ/g"         },
    {Unit::SpecificEnergy::FootPoundPerSlug,   "ft·lbf/slug"  },
    {Unit::SpecificEnergy::InchPoundPerSlinch, "in·lbf/slinch"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::SpecificEnergy> Spellings<
    Unit::SpecificEnergy>{
    {"J/kg",          Unit::SpecificEnergy::JoulePerKilogram  },
    {"N·m/kg",        Unit::SpecificEnergy::JoulePerKilogram  },
    {"N*m/kg",        Unit::SpecificEnergy::JoulePerKilogram  },
    {"m·N/kg",        Unit::SpecificEnergy::JoulePerKilogram  },
    {"m*N/kg",        Unit::SpecificEnergy::JoulePerKilogram  },
    {"m^2/s^2",       Unit::SpecificEnergy::JoulePerKilogram  },
    {"m2/s2",         Unit::SpecificEnergy::JoulePerKilogram  },
    {"nJ/g",          Unit::SpecificEnergy::NanojoulePerGram  },
    {"μN·mm/g",       Unit::SpecificEnergy::NanojoulePerGram  },
    {"μN*mm/g",       Unit::SpecificEnergy::NanojoulePerGram  },
    {"uN·mm/g",       Unit::SpecificEnergy::NanojoulePerGram  },
    {"uN*mm/g",       Unit::SpecificEnergy::NanojoulePerGram  },
    {"mm·μN/g",       Unit::SpecificEnergy::NanojoulePerGram  },
    {"mm*μN/g",       Unit::SpecificEnergy::NanojoulePerGram  },
    {"mm·uN/g",       Unit::SpecificEnergy::NanojoulePerGram  },
    {"mm*uN/g",       Unit::SpecificEnergy::NanojoulePerGram  },
    {"mm^2/s^2",      Unit::SpecificEnergy::NanojoulePerGram  },
    {"mm2/s2",        Unit::SpecificEnergy::NanojoulePerGram  },
    {"ft·lbf/slug",   Unit::SpecificEnergy::FootPoundPerSlug  },
    {"ft*lbf/slug",   Unit::SpecificEnergy::FootPoundPerSlug  },
    {"lbf·ft/slug",   Unit::SpecificEnergy::FootPoundPerSlug  },
    {"lbf*ft/slug",   Unit::SpecificEnergy::FootPoundPerSlug  },
    {"ft·lb/slug",    Unit::SpecificEnergy::FootPoundPerSlug  },
    {"ft*lb/slug",    Unit::SpecificEnergy::FootPoundPerSlug  },
    {"lb·ft/slug",    Unit::SpecificEnergy::FootPoundPerSlug  },
    {"lb*ft/slug",    Unit::SpecificEnergy::FootPoundPerSlug  },
    {"ft^2/s^2",      Unit::SpecificEnergy::FootPoundPerSlug  },
    {"ft2/s2",        Unit::SpecificEnergy::FootPoundPerSlug  },
    {"in·lbf/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
    {"in*lbf/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
    {"lbf·in/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
    {"lbf*in/slinch", Unit::SpecificEnergy::InchPoundPerSlinch},
    {"in·lb/slinch",  Unit::SpecificEnergy::InchPoundPerSlinch},
    {"in*lb/slinch",  Unit::SpecificEnergy::InchPoundPerSlinch},
    {"lb·in/slinch",  Unit::SpecificEnergy::InchPoundPerSlinch},
    {"lb*in/slinch",  Unit::SpecificEnergy::InchPoundPerSlinch},
    {"in^2/s^2",      Unit::SpecificEnergy::InchPoundPerSlinch},
    {"in2/s2",        Unit::SpecificEnergy::InchPoundPerSlinch},
};

template <>
inline constexpr void
ConversionFromStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::JoulePerKilogram>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::JoulePerKilogram>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::NanojoulePerGram>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::NanojoulePerGram>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::FootPoundPerSlug>(
    double& value) noexcept {
  value /= (0.3048 * 0.3048);
}

template <>
inline constexpr void
ConversionToStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::FootPoundPerSlug>(
    double& value) noexcept {
  value *= 0.3048 * 0.3048;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::InchPoundPerSlinch>(
    double& value) noexcept {
  value /= (0.0254 * 0.0254);
}

template <>
inline constexpr void
ConversionToStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::InchPoundPerSlinch>(
    double& value) noexcept {
  value *= 0.0254 * 0.0254;
}

template <>
inline const std::map<Unit::SpecificEnergy,
                      std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::SpecificEnergy, double>{
        {Unit::SpecificEnergy::JoulePerKilogram,
         ConversionsFromStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::JoulePerKilogram,
         double>},
        {Unit::SpecificEnergy::NanojoulePerGram,
         ConversionsFromStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::NanojoulePerGram,
         double>},
        {Unit::SpecificEnergy::FootPoundPerSlug,
         ConversionsFromStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::FootPoundPerSlug,
         double>},
        {Unit::SpecificEnergy::InchPoundPerSlinch,
         ConversionsFromStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::InchPoundPerSlinch,
         double>},
};

template <>
inline const std::map<Unit::SpecificEnergy,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::SpecificEnergy, double>{
        {Unit::SpecificEnergy::JoulePerKilogram,
         ConversionsToStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::JoulePerKilogram,
         double>},
        {Unit::SpecificEnergy::NanojoulePerGram,
         ConversionsToStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::NanojoulePerGram,
         double>},
        {Unit::SpecificEnergy::FootPoundPerSlug,
         ConversionsToStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::FootPoundPerSlug,
         double>},
        {Unit::SpecificEnergy::InchPoundPerSlinch,
         ConversionsToStandard<Unit::SpecificEnergy, Unit::SpecificEnergy::InchPoundPerSlinch,
         double>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_SPECIFIC_ENERGY_HPP
