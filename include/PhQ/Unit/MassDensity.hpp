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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_DENSITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_DENSITY_HPP

#include "../Unit.hpp"

namespace PhQ {

namespace Unit {

// Mass density units.
enum class MassDensity : int_least8_t {
  KilogramPerCubicMetre,
  GramPerCubicMillimetre,
  SlugPerCubicFoot,
  SlinchPerCubicInch,
  PoundPerCubicFoot,
  PoundPerCubicInch,
};

}  // namespace Unit

// Standard mass density unit: kilogram per cubic metre.
template<> inline constexpr const Unit::MassDensity Standard<Unit::MassDensity>{
    Unit::MassDensity::KilogramPerCubicMetre};

// Physical dimension set of mass density units.
template<>
inline constexpr const Dimensions RelatedDimensions<Unit::MassDensity>{
    Dimensions{Dimension::Time{}, Dimension::Length{-3}, Dimension::Mass{1}}
};

namespace Internal {

template<> inline const std::map<UnitSystem, Unit::MassDensity> ConsistentUnits<
    Unit::MassDensity>{
    {UnitSystem::MetreKilogramSecondKelvin,
     Unit::MassDensity::KilogramPerCubicMetre                                     },
    {UnitSystem::MillimetreGramSecondKelvin,
     Unit::MassDensity::GramPerCubicMillimetre                                    },
    {UnitSystem::FootPoundSecondRankine,     Unit::MassDensity::SlugPerCubicFoot  },
    {UnitSystem::InchPoundSecondRankine,     Unit::MassDensity::SlinchPerCubicInch},
};

template<>
inline const std::map<Unit::MassDensity, UnitSystem> RelatedUnitSystems<
    Unit::MassDensity>{
    {Unit::MassDensity::KilogramPerCubicMetre,
     UnitSystem::MetreKilogramSecondKelvin                                        },
    {Unit::MassDensity::GramPerCubicMillimetre,
     UnitSystem::MillimetreGramSecondKelvin                                       },
    {Unit::MassDensity::SlugPerCubicFoot,       UnitSystem::FootPoundSecondRankine},
    {Unit::MassDensity::SlinchPerCubicInch,     UnitSystem::InchPoundSecondRankine},
};

template<> inline const std::map<Unit::MassDensity, std::string_view>
    Abbreviations<Unit::MassDensity>{
        {Unit::MassDensity::KilogramPerCubicMetre,  "kg/m^3"     },
        {Unit::MassDensity::GramPerCubicMillimetre, "g/mm^3"     },
        {Unit::MassDensity::SlugPerCubicFoot,       "slug/ft^3"  },
        {Unit::MassDensity::SlinchPerCubicInch,     "slinch/in^3"},
        {Unit::MassDensity::PoundPerCubicFoot,      "lbm/ft^3"   },
        {Unit::MassDensity::PoundPerCubicInch,      "lbm/in^3"   },
};

template<> inline const std::unordered_map<std::string_view, Unit::MassDensity>
    Spellings<Unit::MassDensity>{
        {"kg/m^3",          Unit::MassDensity::KilogramPerCubicMetre },
        {"kg/m3",           Unit::MassDensity::KilogramPerCubicMetre },
        {"kg/m/m/m",        Unit::MassDensity::KilogramPerCubicMetre },
        {"g/mm^3",          Unit::MassDensity::GramPerCubicMillimetre},
        {"g/mm3",           Unit::MassDensity::GramPerCubicMillimetre},
        {"g/mm/mm/mm",      Unit::MassDensity::GramPerCubicMillimetre},
        {"slug/ft^3",       Unit::MassDensity::SlugPerCubicFoot      },
        {"slug/ft3",        Unit::MassDensity::SlugPerCubicFoot      },
        {"slug/ft/ft/ft",   Unit::MassDensity::SlugPerCubicFoot      },
        {"slinch/in^3",     Unit::MassDensity::SlinchPerCubicInch    },
        {"slinch/in3",      Unit::MassDensity::SlinchPerCubicInch    },
        {"slinch/in/in/in", Unit::MassDensity::SlinchPerCubicInch    },
        {"lbm/ft^3",        Unit::MassDensity::PoundPerCubicFoot     },
        {"lbm/ft3",         Unit::MassDensity::PoundPerCubicFoot     },
        {"lbm/ft/ft/ft",    Unit::MassDensity::PoundPerCubicFoot     },
        {"lb/ft^3",         Unit::MassDensity::PoundPerCubicFoot     },
        {"lb/ft3",          Unit::MassDensity::PoundPerCubicFoot     },
        {"lb/ft/ft/ft",     Unit::MassDensity::PoundPerCubicFoot     },
        {"lbm/in^3",        Unit::MassDensity::PoundPerCubicInch     },
        {"lbm/in3",         Unit::MassDensity::PoundPerCubicInch     },
        {"lbm/in/in/in",    Unit::MassDensity::PoundPerCubicInch     },
        {"lb/in^3",         Unit::MassDensity::PoundPerCubicInch     },
        {"lb/in3",          Unit::MassDensity::PoundPerCubicInch     },
        {"lb/in/in/in",     Unit::MassDensity::PoundPerCubicInch     },
};

template<> inline constexpr void
ConversionFromStandard<Unit::MassDensity,
                       Unit::MassDensity::KilogramPerCubicMetre>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionFromStandard<Unit::MassDensity,
                       Unit::MassDensity::GramPerCubicMillimetre>(
    double& value) noexcept {
  value *= 0.000001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::MassDensity, Unit::MassDensity::SlugPerCubicFoot>(
    double& value) noexcept {
  value *= std::pow(0.3048, 4) / (0.45359237 * 9.80665);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MassDensity, Unit::MassDensity::SlinchPerCubicInch>(
    double& value) noexcept {
  value *= std::pow(0.0254, 4) / (0.45359237 * 9.80665);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MassDensity, Unit::MassDensity::PoundPerCubicFoot>(
    double& value) noexcept {
  value *= std::pow(0.3048, 3) / 0.45359237;
}

template<> inline constexpr void
ConversionFromStandard<Unit::MassDensity, Unit::MassDensity::PoundPerCubicInch>(
    double& value) noexcept {
  value *= std::pow(0.0254, 3) / 0.45359237;
}

template<> inline constexpr void
ConversionToStandard<Unit::MassDensity,
                     Unit::MassDensity::KilogramPerCubicMetre>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::MassDensity,
                     Unit::MassDensity::GramPerCubicMillimetre>(
    double& value) noexcept {
  value *= 1000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::MassDensity, Unit::MassDensity::SlugPerCubicFoot>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / std::pow(0.3048, 4);
}

template<> inline constexpr void
ConversionToStandard<Unit::MassDensity, Unit::MassDensity::SlinchPerCubicInch>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / std::pow(0.0254, 4);
}

template<> inline constexpr void
ConversionToStandard<Unit::MassDensity, Unit::MassDensity::PoundPerCubicFoot>(
    double& value) noexcept {
  value *= 0.45359237 / std::pow(0.3048, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::MassDensity, Unit::MassDensity::PoundPerCubicInch>(
    double& value) noexcept {
  value *= 0.45359237 / std::pow(0.0254, 3);
}

template<> inline const std::map<
    Unit::MassDensity,
    std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::MassDensity>{
        {Unit::MassDensity::KilogramPerCubicMetre,
         ConversionsFromStandard<Unit::MassDensity,
         Unit::MassDensity::KilogramPerCubicMetre> },
        {Unit::MassDensity::GramPerCubicMillimetre,
         ConversionsFromStandard<Unit::MassDensity,
         Unit::MassDensity::GramPerCubicMillimetre>},
        {Unit::MassDensity::SlugPerCubicFoot,
         ConversionsFromStandard<Unit::MassDensity,
         Unit::MassDensity::SlugPerCubicFoot>      },
        {Unit::MassDensity::SlinchPerCubicInch,
         ConversionsFromStandard<Unit::MassDensity,
         Unit::MassDensity::SlinchPerCubicInch>    },
        {Unit::MassDensity::PoundPerCubicFoot,
         ConversionsFromStandard<Unit::MassDensity,
         Unit::MassDensity::PoundPerCubicFoot>     },
        {Unit::MassDensity::PoundPerCubicInch,
         ConversionsFromStandard<Unit::MassDensity,
         Unit::MassDensity::PoundPerCubicInch>     },
};

template<> inline const std::map<
    Unit::MassDensity,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::MassDensity>{
        {Unit::MassDensity::KilogramPerCubicMetre,
         ConversionsToStandard<Unit::MassDensity,
         Unit::MassDensity::KilogramPerCubicMetre> },
        {Unit::MassDensity::GramPerCubicMillimetre,
         ConversionsToStandard<Unit::MassDensity,
         Unit::MassDensity::GramPerCubicMillimetre>},
        {Unit::MassDensity::SlugPerCubicFoot,
         ConversionsToStandard<Unit::MassDensity,
         Unit::MassDensity::SlugPerCubicFoot>      },
        {Unit::MassDensity::SlinchPerCubicInch,
         ConversionsToStandard<Unit::MassDensity,
         Unit::MassDensity::SlinchPerCubicInch>    },
        {Unit::MassDensity::PoundPerCubicFoot,
         ConversionsToStandard<Unit::MassDensity,
         Unit::MassDensity::PoundPerCubicFoot>     },
        {Unit::MassDensity::PoundPerCubicInch,
         ConversionsToStandard<Unit::MassDensity,
         Unit::MassDensity::PoundPerCubicInch>     },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_DENSITY_HPP
