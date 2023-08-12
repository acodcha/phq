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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Volume : int_least8_t {
  CubicMile,
  CubicKilometre,
  CubicMetre,
  CubicYard,
  CubicFoot,
  CubicDecimetre,
  Litre,
  CubicInch,
  CubicCentimetre,
  Millilitre,
  CubicMillimetre,
  CubicMilliinch,
  CubicMicrometre,
  CubicMicroinch,
};

}  // namespace Unit

template<> inline constexpr const Unit::Volume StandardUnit<Unit::Volume>{
    Unit::Volume::CubicMetre};

template<> inline constexpr const Dimension::Set Dimensions<Unit::Volume>{
    Dimension::Set{Dimension::Time{}, Dimension::Length{3}}
};

namespace Internal {

template<>
inline const std::map<UnitSystem, Unit::Volume> ConsistentUnits<Unit::Volume>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Volume::CubicMetre     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Volume::CubicMillimetre},
    {UnitSystem::FootPoundSecondRankine,     Unit::Volume::CubicFoot      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Volume::CubicInch      },
};

template<>
inline const std::map<Unit::Volume, UnitSystem> RelatedUnitSystems<Unit::Volume>{
    {Unit::Volume::CubicMetre,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Volume::CubicMillimetre, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Volume::CubicFoot,       UnitSystem::FootPoundSecondRankine    },
    {Unit::Volume::CubicInch,       UnitSystem::InchPoundSecondRankine    },
};

template<> inline const std::map<Unit::Volume, std::string_view>
    Abbreviations<Unit::Volume>{
        {Unit::Volume::CubicMile,       "mi^3" },
        {Unit::Volume::CubicKilometre,  "km^3" },
        {Unit::Volume::CubicMetre,      "m^3"  },
        {Unit::Volume::CubicYard,       "yd^3" },
        {Unit::Volume::CubicFoot,       "ft^3" },
        {Unit::Volume::CubicDecimetre,  "dm^3" },
        {Unit::Volume::Litre,           "L"    },
        {Unit::Volume::CubicInch,       "in^3" },
        {Unit::Volume::CubicCentimetre, "cm^3" },
        {Unit::Volume::Millilitre,      "mL"   },
        {Unit::Volume::CubicMillimetre, "mm^3" },
        {Unit::Volume::CubicMilliinch,  "mil^3"},
        {Unit::Volume::CubicMicrometre, "μm^3" },
        {Unit::Volume::CubicMicroinch,  "μin^3"},
};

template<> inline const std::unordered_map<std::string_view, Unit::Volume>
    Spellings<Unit::Volume>{
        {"mi^3",        Unit::Volume::CubicMile      },
        {"mi3",         Unit::Volume::CubicMile      },
        {"km^3",        Unit::Volume::CubicKilometre },
        {"km3",         Unit::Volume::CubicKilometre },
        {"m^3",         Unit::Volume::CubicMetre     },
        {"m3",          Unit::Volume::CubicMetre     },
        {"yd^3",        Unit::Volume::CubicYard      },
        {"yd3",         Unit::Volume::CubicYard      },
        {"ft^3",        Unit::Volume::CubicFoot      },
        {"ft3",         Unit::Volume::CubicFoot      },
        {"dm^3",        Unit::Volume::CubicDecimetre },
        {"dm3",         Unit::Volume::CubicDecimetre },
        {"L",           Unit::Volume::Litre          },
        {"in^3",        Unit::Volume::CubicInch      },
        {"in3",         Unit::Volume::CubicInch      },
        {"cm^3",        Unit::Volume::CubicCentimetre},
        {"cm3",         Unit::Volume::CubicCentimetre},
        {"mL",          Unit::Volume::Millilitre     },
        {"mm^3",        Unit::Volume::CubicMillimetre},
        {"mm3",         Unit::Volume::CubicMillimetre},
        {"millinch^3",  Unit::Volume::CubicMilliinch },
        {"millinch3",   Unit::Volume::CubicMilliinch },
        {"milliinch^3", Unit::Volume::CubicMilliinch },
        {"milliinch3",  Unit::Volume::CubicMilliinch },
        {"mil^3",       Unit::Volume::CubicMilliinch },
        {"mil3",        Unit::Volume::CubicMilliinch },
        {"thou^3",      Unit::Volume::CubicMilliinch },
        {"thou3",       Unit::Volume::CubicMilliinch },
        {"μm^3",        Unit::Volume::CubicMicrometre},
        {"μm3",         Unit::Volume::CubicMicrometre},
        {"um^3",        Unit::Volume::CubicMicrometre},
        {"um3",         Unit::Volume::CubicMicrometre},
        {"μin^3",       Unit::Volume::CubicMicroinch },
        {"μin3",        Unit::Volume::CubicMicroinch },
        {"uin^3",       Unit::Volume::CubicMicroinch },
        {"uin3",        Unit::Volume::CubicMicroinch },
};

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMile>(
    double& value) noexcept {
  value /= std::pow(1609.344, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicKilometre>(
    double& value) noexcept {
  value *= std::pow(0.001, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMetre>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicYard>(
    double& value) noexcept {
  value /= std::pow(0.9144, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicFoot>(
    double& value) noexcept {
  value /= std::pow(0.3048, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicDecimetre>(
    double& value) noexcept {
  value *= std::pow(10.0, 3);
}

template<>
inline constexpr void ConversionFromStandard<Unit::Volume, Unit::Volume::Litre>(
    double& value) noexcept {
  value *= std::pow(10.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicInch>(
    double& value) noexcept {
  value /= std::pow(0.0254, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicCentimetre>(
    double& value) noexcept {
  value *= std::pow(100.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::Millilitre>(
    double& value) noexcept {
  value *= std::pow(100.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMillimetre>(
    double& value) noexcept {
  value *= std::pow(1000.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMilliinch>(
    double& value) noexcept {
  value /= std::pow(0.0000254, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMicrometre>(
    double& value) noexcept {
  value *= std::pow(1000000.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::Volume, Unit::Volume::CubicMicroinch>(
    double& value) noexcept {
  value /= std::pow(0.0000000254, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicMile>(
    double& value) noexcept {
  value *= std::pow(1609.344, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicKilometre>(
    double& value) noexcept {
  value *= std::pow(1000.0, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicMetre>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicYard>(
    double& value) noexcept {
  value *= std::pow(0.9144, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicFoot>(
    double& value) noexcept {
  value *= std::pow(0.3048, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicDecimetre>(
    double& value) noexcept {
  value *= std::pow(0.1, 3);
}

template<>
inline constexpr void ConversionToStandard<Unit::Volume, Unit::Volume::Litre>(
    double& value) noexcept {
  value *= std::pow(0.1, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicInch>(
    double& value) noexcept {
  value *= std::pow(0.0254, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicCentimetre>(
    double& value) noexcept {
  value *= std::pow(0.01, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::Millilitre>(
    double& value) noexcept {
  value *= std::pow(0.01, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicMillimetre>(
    double& value) noexcept {
  value *= std::pow(0.001, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicMilliinch>(
    double& value) noexcept {
  value *= std::pow(0.0000254, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicMicrometre>(
    double& value) noexcept {
  value *= std::pow(0.000001, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::Volume, Unit::Volume::CubicMicroinch>(
    double& value) noexcept {
  value *= std::pow(0.0000000254, 3);
}

template<> inline const std::map<
    Unit::Volume, std::function<void(double* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Volume>{
        {Unit::Volume::CubicMile,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicMile>      },
        {Unit::Volume::CubicKilometre,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicKilometre> },
        {Unit::Volume::CubicMetre,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicMetre>     },
        {Unit::Volume::CubicYard,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicYard>      },
        {Unit::Volume::CubicFoot,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicFoot>      },
        {Unit::Volume::CubicDecimetre,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicDecimetre> },
        {Unit::Volume::Litre,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::Litre>          },
        {Unit::Volume::CubicInch,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicInch>      },
        {Unit::Volume::CubicCentimetre,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicCentimetre>},
        {Unit::Volume::Millilitre,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::Millilitre>     },
        {Unit::Volume::CubicMillimetre,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicMillimetre>},
        {Unit::Volume::CubicMilliinch,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicMilliinch> },
        {Unit::Volume::CubicMicrometre,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicMicrometre>},
        {Unit::Volume::CubicMicroinch,
         ConversionsFromStandard<Unit::Volume, Unit::Volume::CubicMicroinch> },
};

template<> inline const std::map<
    Unit::Volume, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Volume>{
        {Unit::Volume::CubicMile,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicMile>      },
        {Unit::Volume::CubicKilometre,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicKilometre> },
        {Unit::Volume::CubicMetre,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicMetre>     },
        {Unit::Volume::CubicYard,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicYard>      },
        {Unit::Volume::CubicFoot,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicFoot>      },
        {Unit::Volume::CubicDecimetre,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicDecimetre> },
        {Unit::Volume::Litre,
         ConversionsToStandard<Unit::Volume, Unit::Volume::Litre>          },
        {Unit::Volume::CubicInch,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicInch>      },
        {Unit::Volume::CubicCentimetre,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicCentimetre>},
        {Unit::Volume::Millilitre,
         ConversionsToStandard<Unit::Volume, Unit::Volume::Millilitre>     },
        {Unit::Volume::CubicMillimetre,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicMillimetre>},
        {Unit::Volume::CubicMilliinch,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicMilliinch> },
        {Unit::Volume::CubicMicrometre,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicMicrometre>},
        {Unit::Volume::CubicMicroinch,
         ConversionsToStandard<Unit::Volume, Unit::Volume::CubicMicroinch> },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_HPP
