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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_RATE_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class MassRate : int_least8_t {
  KilogramPerSecond,
  GramPerSecond,
  SlugPerSecond,
  SlinchPerSecond,
  PoundPerSecond,
};

}  // namespace Unit

template<> inline constexpr const Unit::MassRate StandardUnit<Unit::MassRate>{
    Unit::MassRate::KilogramPerSecond};

template<> inline constexpr const Dimension::Set Dimensions<Unit::MassRate>{
    Dimension::Set{
                   Dimension::Time{-1}, Dimension::Length{0}, Dimension::Mass{1}}
};

namespace Internal {

template<> inline const std::map<UnitSystem, Unit::MassRate>
    ConsistentUnits<Unit::MassRate>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::MassRate::KilogramPerSecond                                      },
        {UnitSystem::MillimetreGramSecondKelvin, Unit::MassRate::GramPerSecond  },
        {UnitSystem::FootPoundSecondRankine,     Unit::MassRate::SlugPerSecond  },
        {UnitSystem::InchPoundSecondRankine,     Unit::MassRate::SlinchPerSecond},
};

template<> inline const std::map<Unit::MassRate, UnitSystem>
    RelatedUnitSystems<Unit::MassRate>{
        {Unit::MassRate::KilogramPerSecond,
         UnitSystem::MetreKilogramSecondKelvin                                    },
        {Unit::MassRate::GramPerSecond,     UnitSystem::MillimetreGramSecondKelvin},
        {Unit::MassRate::SlugPerSecond,     UnitSystem::FootPoundSecondRankine    },
        {Unit::MassRate::SlinchPerSecond,   UnitSystem::InchPoundSecondRankine    },
};

template<> inline const std::map<Unit::MassRate, std::string_view>
    Abbreviations<Unit::MassRate>{
        {Unit::MassRate::KilogramPerSecond, "kg/s"    },
        {Unit::MassRate::GramPerSecond,     "g/s"     },
        {Unit::MassRate::SlugPerSecond,     "slug/s"  },
        {Unit::MassRate::SlinchPerSecond,   "slinch/s"},
        {Unit::MassRate::PoundPerSecond,    "lbm/s"   },
};

template<> inline const std::unordered_map<std::string_view, Unit::MassRate>
    Spellings<Unit::MassRate>{
        {"kg/s",     Unit::MassRate::KilogramPerSecond},
        {"g/s",      Unit::MassRate::GramPerSecond    },
        {"slug/s",   Unit::MassRate::SlugPerSecond    },
        {"slinch/s", Unit::MassRate::SlinchPerSecond  },
        {"lbm/s",    Unit::MassRate::PoundPerSecond   },
        {"lb/s",     Unit::MassRate::PoundPerSecond   },
};

template<> inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::KilogramPerSecond>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::GramPerSecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::SlugPerSecond>(
    double& value) noexcept {
  value *= 0.3048 / (0.45359237 * 9.80665);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::SlinchPerSecond>(
    double& value) noexcept {
  value *= 0.0254 / (0.45359237 * 9.80665);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::PoundPerSecond>(
    double& value) noexcept {
  value /= 0.45359237;
}

template<> inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::KilogramPerSecond>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::GramPerSecond>(
    double& value) noexcept {
  value *= 0.001;
}

template<> inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::SlugPerSecond>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / 0.3048;
}

template<> inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::SlinchPerSecond>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / 0.0254;
}

template<> inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::PoundPerSecond>(
    double& value) noexcept {
  value *= 0.45359237;
}

template<> inline const std::map<
    Unit::MassRate, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::MassRate>{
        {Unit::MassRate::KilogramPerSecond,
         ConversionsFromStandard<Unit::MassRate,
         Unit::MassRate::KilogramPerSecond>                                    },
        {Unit::MassRate::GramPerSecond,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::GramPerSecond>},
        {Unit::MassRate::SlugPerSecond,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::SlugPerSecond>},
        {Unit::MassRate::SlinchPerSecond,
         ConversionsFromStandard<Unit::MassRate,
         Unit::MassRate::SlinchPerSecond>                                      },
        {Unit::MassRate::PoundPerSecond,
         ConversionsFromStandard<Unit::MassRate,
         Unit::MassRate::PoundPerSecond>                                       },
};

template<> inline const std::map<
    Unit::MassRate,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::MassRate>{
        {Unit::MassRate::KilogramPerSecond,
         ConversionsToStandard<Unit::MassRate,
         Unit::MassRate::KilogramPerSecond>                                    },
        {Unit::MassRate::GramPerSecond,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::GramPerSecond>  },
        {Unit::MassRate::SlugPerSecond,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::SlugPerSecond>  },
        {Unit::MassRate::SlinchPerSecond,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::SlinchPerSecond>},
        {Unit::MassRate::PoundPerSecond,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::PoundPerSecond> },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_RATE_HPP
