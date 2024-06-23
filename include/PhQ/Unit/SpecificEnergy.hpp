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

/// \brief Mass-specific energy units.
enum class SpecificEnergy : int8_t {
  /// \brief Joule per kilogram (J/kg) specific energy unit.
  JoulePerKilogram,

  /// \brief Nanojoule per gram (nJ/g) specific energy unit.
  NanojoulePerGram,

  /// \brief Foot-pound per slug (ft·lbf/slug) specific energy unit.
  FootPoundPerSlug,

  /// \brief Inch-pound per slinch (in·lbf/slinch) specific energy unit.
  InchPoundPerSlinch,
};

}  // namespace Unit

/// \brief Standard mass-specific energy unit: joule per kilogram (J/kg).
template <>
inline constexpr const Unit::SpecificEnergy Standard<Unit::SpecificEnergy>{
    Unit::SpecificEnergy::JoulePerKilogram};

/// \brief Physical dimension set of mass-specific energy units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::SpecificEnergy>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
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

// clang-format off

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

// clang-format on

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificEnergy, Unit::SpecificEnergy::JoulePerKilogram>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificEnergy, Unit::SpecificEnergy::JoulePerKilogram>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificEnergy, Unit::SpecificEnergy::NanojoulePerGram>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificEnergy, Unit::SpecificEnergy::NanojoulePerGram>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificEnergy, Unit::SpecificEnergy::FootPoundPerSlug>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificEnergy, Unit::SpecificEnergy::FootPoundPerSlug>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificEnergy, Unit::SpecificEnergy::InchPoundPerSlinch>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::SpecificEnergy, Unit::SpecificEnergy::InchPoundPerSlinch>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L);
}

template <typename NumericType>
inline const std::map<Unit::SpecificEnergy,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::SpecificEnergy, NumericType>{
        {Unit::SpecificEnergy::JoulePerKilogram,
         Conversions<Unit::SpecificEnergy,
         Unit::SpecificEnergy::JoulePerKilogram>::FromStandard<NumericType>  },
        {Unit::SpecificEnergy::NanojoulePerGram,
         Conversions<Unit::SpecificEnergy,
         Unit::SpecificEnergy::NanojoulePerGram>::FromStandard<NumericType>  },
        {Unit::SpecificEnergy::FootPoundPerSlug,
         Conversions<Unit::SpecificEnergy,
         Unit::SpecificEnergy::FootPoundPerSlug>::FromStandard<NumericType>  },
        {Unit::SpecificEnergy::InchPoundPerSlinch,
         Conversions<Unit::SpecificEnergy,
         Unit::SpecificEnergy::InchPoundPerSlinch>::FromStandard<NumericType>},
};

template <typename NumericType>
inline const std::map<Unit::SpecificEnergy,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::SpecificEnergy, NumericType>{
        {Unit::SpecificEnergy::JoulePerKilogram,
         Conversions<Unit::SpecificEnergy,
         Unit::SpecificEnergy::JoulePerKilogram>::ToStandard<NumericType>  },
        {Unit::SpecificEnergy::NanojoulePerGram,
         Conversions<Unit::SpecificEnergy,
         Unit::SpecificEnergy::NanojoulePerGram>::ToStandard<NumericType>  },
        {Unit::SpecificEnergy::FootPoundPerSlug,
         Conversions<Unit::SpecificEnergy,
         Unit::SpecificEnergy::FootPoundPerSlug>::ToStandard<NumericType>  },
        {Unit::SpecificEnergy::InchPoundPerSlinch,
         Conversions<Unit::SpecificEnergy,
         Unit::SpecificEnergy::InchPoundPerSlinch>::ToStandard<NumericType>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_SPECIFIC_ENERGY_HPP
