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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_FLUX_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_FLUX_HPP

#include "../Unit.hpp"

namespace PhQ {

namespace Unit {

// Energy flux units.
enum class EnergyFlux : int8_t {
  WattPerSquareMetre,
  NanowattPerSquareMillimetre,
  FootPoundPerSquareFootPerSecond,
  InchPoundPerSquareInchPerSecond,
};

}  // namespace Unit

// Standard energy flux unit: watt per square metre.
template <>
inline constexpr const Unit::EnergyFlux Standard<Unit::EnergyFlux>{
    Unit::EnergyFlux::WattPerSquareMetre};

// Physical dimension set of energy flux units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::EnergyFlux>{
    Dimensions{Dimension::Time{-3}, Dimension::Length{0}, Dimension::Mass{1}}
};

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::EnergyFlux>
    ConsistentUnits<Unit::EnergyFlux>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::EnergyFlux::WattPerSquareMetre             },
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::EnergyFlux::NanowattPerSquareMillimetre    },
        {UnitSystem::FootPoundSecondRankine,
         Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
        {UnitSystem::InchPoundSecondRankine,
         Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
};

template <>
inline const std::map<Unit::EnergyFlux, UnitSystem>
    RelatedUnitSystems<Unit::EnergyFlux>{
        {Unit::EnergyFlux::WattPerSquareMetre,
         UnitSystem::MetreKilogramSecondKelvin },
        {Unit::EnergyFlux::NanowattPerSquareMillimetre,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond,
         UnitSystem::FootPoundSecondRankine    },
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond,
         UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::EnergyFlux, std::string_view>
    Abbreviations<Unit::EnergyFlux>{
        {Unit::EnergyFlux::WattPerSquareMetre,              "W/m^2"        },
        {Unit::EnergyFlux::NanowattPerSquareMillimetre,     "nW/mm^2"      },
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, "ft·lbf/ft^2/s"},
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, "in·lbf/in^2/s"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::EnergyFlux> Spellings<
    Unit::EnergyFlux>{
    {"W/m^2",           Unit::EnergyFlux::WattPerSquareMetre             },
    {"W/m2",            Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m^2·s)",       Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m^2*s)",       Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m2·s)",        Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m2*s)",        Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/m^2/s",         Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/m2/s",          Unit::EnergyFlux::WattPerSquareMetre             },
    {"N/(m·s)",         Unit::EnergyFlux::WattPerSquareMetre             },
    {"N/(m*s)",         Unit::EnergyFlux::WattPerSquareMetre             },
    {"N/m/s",           Unit::EnergyFlux::WattPerSquareMetre             },
    {"kg/s^3",          Unit::EnergyFlux::WattPerSquareMetre             },
    {"kg/s3",           Unit::EnergyFlux::WattPerSquareMetre             },
    {"nW/mm^2",         Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nW/mm2",          Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm^2·s)",     Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm^2*s)",     Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm2·s)",      Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm2*s)",      Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/mm^2/s",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/mm2/s",        Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"μN/(mm·s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"μN/(mm*s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"μN/mm/s",         Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"uN/(mm·s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"uN/(mm*s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"uN/mm/s",         Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"g/s^3",           Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"g/s3",            Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"ft·lbf/(ft^2·s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft·lbf/(ft2·s)",  Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/(ft^2*s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/(ft2*s)",  Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft·lbf/ft^2/s",   Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft·lbf/ft2/s",    Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/ft^2/s",   Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/ft2/s",    Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"lbf/(ft·s)",      Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"lbf/(ft*s)",      Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"lbf/ft/s",        Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"slug/s^3",        Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"slug/s3",         Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"in·lbf/(in^2·s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in·lbf/(in2·s)",  Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/(in^2*s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/(in2*s)",  Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in·lbf/in^2/s",   Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in·lbf/in2/s",    Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/in^2/s",   Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/in2/s",    Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"lbf/(in·s)",      Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"lbf/(in*s)",      Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"lbf/in/s",        Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"slinch/s^3",      Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"slinch/s3",       Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
};

template <>
inline constexpr void
ConversionFromStandard<Unit::EnergyFlux, Unit::EnergyFlux::WattPerSquareMetre>(
    double& value) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::EnergyFlux,
                       Unit::EnergyFlux::NanowattPerSquareMillimetre>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::EnergyFlux,
                       Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>(
    double& value) noexcept {
  value *= 0.3048 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::EnergyFlux,
                       Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>(
    double& value) noexcept {
  value *= 0.0254 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionToStandard<Unit::EnergyFlux, Unit::EnergyFlux::WattPerSquareMetre>(
    double& value) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::EnergyFlux,
                     Unit::EnergyFlux::NanowattPerSquareMillimetre>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::EnergyFlux,
                     Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / 0.3048;
}

template <>
inline constexpr void
ConversionToStandard<Unit::EnergyFlux,
                     Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / 0.0254;
}

template <>
inline const std::map<
    Unit::EnergyFlux,
    std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::EnergyFlux>{
        {Unit::EnergyFlux::WattPerSquareMetre,
         ConversionsFromStandard<Unit::EnergyFlux,
         Unit::EnergyFlux::WattPerSquareMetre>                                                   },
        {Unit::EnergyFlux::NanowattPerSquareMillimetre,
         ConversionsFromStandard<
             Unit::EnergyFlux,                     Unit::EnergyFlux::NanowattPerSquareMillimetre>},
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond,
         ConversionsFromStandard<
             Unit::EnergyFlux,
         Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>                                      },
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond,
         ConversionsFromStandard<
             Unit::EnergyFlux,
         Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>                                      },
};

template <>
inline const std::map<
    Unit::EnergyFlux,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::EnergyFlux>{
        {Unit::EnergyFlux::WattPerSquareMetre,
         ConversionsToStandard<Unit::EnergyFlux,
         Unit::EnergyFlux::WattPerSquareMetre>             },
        {Unit::EnergyFlux::NanowattPerSquareMillimetre,
         ConversionsToStandard<Unit::EnergyFlux,
         Unit::EnergyFlux::NanowattPerSquareMillimetre>    },
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond,
         ConversionsToStandard<
             Unit::EnergyFlux,
         Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>},
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond,
         ConversionsToStandard<
             Unit::EnergyFlux,
         Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_FLUX_HPP
