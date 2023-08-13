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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_RATE_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

// Time rate of volume units.
enum class VolumeRate : int_least8_t {
  CubicMilePerSecond,
  CubicKilometrePerSecond,
  CubicMetrePerSecond,
  CubicYardPerSecond,
  CubicFootPerSecond,
  CubicDecimetrePerSecond,
  LitrePerSecond,
  CubicInchPerSecond,
  CubicCentimetrePerSecond,
  MillilitrePerSecond,
  CubicMillimetrePerSecond,
  CubicMilliinchPerSecond,
  CubicMicrometrePerSecond,
  CubicMicroinchPerSecond,
};

}  // namespace Unit

// Standard time-rate of volume unit: cubic metre per second.
template<>
inline constexpr const Unit::VolumeRate StandardUnit<Unit::VolumeRate>{
    Unit::VolumeRate::CubicMetrePerSecond};

// Physical dimension set of time-rate of volume units.
template<> inline constexpr const Dimension::Set Dimensions<Unit::VolumeRate>{
    Dimension::Set{Dimension::Time{-1}, Dimension::Length{3}}
};

namespace Internal {

template<> inline const std::map<UnitSystem, Unit::VolumeRate> ConsistentUnits<
    Unit::VolumeRate>{
    {UnitSystem::MetreKilogramSecondKelvin,
     Unit::VolumeRate::CubicMetrePerSecond                                       },
    {UnitSystem::MillimetreGramSecondKelvin,
     Unit::VolumeRate::CubicMillimetrePerSecond                                  },
    {UnitSystem::FootPoundSecondRankine,     Unit::VolumeRate::CubicFootPerSecond},
    {UnitSystem::InchPoundSecondRankine,     Unit::VolumeRate::CubicInchPerSecond},
};

template<>
inline const std::map<Unit::VolumeRate, UnitSystem> RelatedUnitSystems<
    Unit::VolumeRate>{
    {Unit::VolumeRate::CubicMetrePerSecond,
     UnitSystem::MetreKilogramSecondKelvin                                         },
    {Unit::VolumeRate::CubicMillimetrePerSecond,
     UnitSystem::MillimetreGramSecondKelvin                                        },
    {Unit::VolumeRate::CubicFootPerSecond,       UnitSystem::FootPoundSecondRankine},
    {Unit::VolumeRate::CubicInchPerSecond,       UnitSystem::InchPoundSecondRankine},
};

template<> inline const std::map<Unit::VolumeRate, std::string_view>
    Abbreviations<Unit::VolumeRate>{
        {Unit::VolumeRate::CubicMilePerSecond,       "mi^3/s" },
        {Unit::VolumeRate::CubicKilometrePerSecond,  "km^3/s" },
        {Unit::VolumeRate::CubicMetrePerSecond,      "m^3/s"  },
        {Unit::VolumeRate::CubicYardPerSecond,       "yd^3/s" },
        {Unit::VolumeRate::CubicFootPerSecond,       "ft^3/s" },
        {Unit::VolumeRate::CubicDecimetrePerSecond,  "dm^3/s" },
        {Unit::VolumeRate::LitrePerSecond,           "L/s"    },
        {Unit::VolumeRate::CubicInchPerSecond,       "in^3/s" },
        {Unit::VolumeRate::CubicCentimetrePerSecond, "cm^3/s" },
        {Unit::VolumeRate::MillilitrePerSecond,      "mL/s"   },
        {Unit::VolumeRate::CubicMillimetrePerSecond, "mm^3/s" },
        {Unit::VolumeRate::CubicMilliinchPerSecond,  "mil^3/s"},
        {Unit::VolumeRate::CubicMicrometrePerSecond, "μm^3/s" },
        {Unit::VolumeRate::CubicMicroinchPerSecond,  "μin^3/s"},
};

template<> inline const std::unordered_map<std::string_view, Unit::VolumeRate>
    Spellings<Unit::VolumeRate>{
        {"mi^3/s",        Unit::VolumeRate::CubicMilePerSecond      },
        {"mi3/s",         Unit::VolumeRate::CubicMilePerSecond      },
        {"km^3/s",        Unit::VolumeRate::CubicKilometrePerSecond },
        {"km3/s",         Unit::VolumeRate::CubicKilometrePerSecond },
        {"m^3/s",         Unit::VolumeRate::CubicMetrePerSecond     },
        {"m3/s",          Unit::VolumeRate::CubicMetrePerSecond     },
        {"yd^3/s",        Unit::VolumeRate::CubicYardPerSecond      },
        {"yd3/s",         Unit::VolumeRate::CubicYardPerSecond      },
        {"ft^3/s",        Unit::VolumeRate::CubicFootPerSecond      },
        {"ft3/s",         Unit::VolumeRate::CubicFootPerSecond      },
        {"dm^3/s",        Unit::VolumeRate::CubicDecimetrePerSecond },
        {"dm3/s",         Unit::VolumeRate::CubicDecimetrePerSecond },
        {"L/s",           Unit::VolumeRate::LitrePerSecond          },
        {"in^3/s",        Unit::VolumeRate::CubicInchPerSecond      },
        {"in3/s",         Unit::VolumeRate::CubicInchPerSecond      },
        {"cm^3/s",        Unit::VolumeRate::CubicCentimetrePerSecond},
        {"cm3/s",         Unit::VolumeRate::CubicCentimetrePerSecond},
        {"mL/s",          Unit::VolumeRate::MillilitrePerSecond     },
        {"mm^3/s",        Unit::VolumeRate::CubicMillimetrePerSecond},
        {"mm3/s",         Unit::VolumeRate::CubicMillimetrePerSecond},
        {"millinch^3/s",  Unit::VolumeRate::CubicMilliinchPerSecond },
        {"millinch3/s",   Unit::VolumeRate::CubicMilliinchPerSecond },
        {"milliinch^3/s", Unit::VolumeRate::CubicMilliinchPerSecond },
        {"milliinch3/s",  Unit::VolumeRate::CubicMilliinchPerSecond },
        {"mil^3/s",       Unit::VolumeRate::CubicMilliinchPerSecond },
        {"mil3/s",        Unit::VolumeRate::CubicMilliinchPerSecond },
        {"thou^3/s",      Unit::VolumeRate::CubicMilliinchPerSecond },
        {"thou3/s",       Unit::VolumeRate::CubicMilliinchPerSecond },
        {"μm^3/s",        Unit::VolumeRate::CubicMicrometrePerSecond},
        {"μm3/s",         Unit::VolumeRate::CubicMicrometrePerSecond},
        {"um^3/s",        Unit::VolumeRate::CubicMicrometrePerSecond},
        {"um3/s",         Unit::VolumeRate::CubicMicrometrePerSecond},
        {"μin^3/s",       Unit::VolumeRate::CubicMicroinchPerSecond },
        {"μin3/s",        Unit::VolumeRate::CubicMicroinchPerSecond },
        {"uin^3/s",       Unit::VolumeRate::CubicMicroinchPerSecond },
        {"uin3/s",        Unit::VolumeRate::CubicMicroinchPerSecond },
};

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>(
    double& value) noexcept {
  value /= std::pow(1609.344, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate,
                       Unit::VolumeRate::CubicKilometrePerSecond>(
    double& value) noexcept {
  value *= std::pow(0.001, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerSecond>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>(
    double& value) noexcept {
  value /= std::pow(0.9144, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>(
    double& value) noexcept {
  value /= std::pow(0.3048, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate,
                       Unit::VolumeRate::CubicDecimetrePerSecond>(
    double& value) noexcept {
  value *= std::pow(10.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>(
    double& value) noexcept {
  value *= std::pow(10.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>(
    double& value) noexcept {
  value /= std::pow(0.0254, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate,
                       Unit::VolumeRate::CubicCentimetrePerSecond>(
    double& value) noexcept {
  value *= std::pow(100.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerSecond>(
    double& value) noexcept {
  value *= std::pow(100.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate,
                       Unit::VolumeRate::CubicMillimetrePerSecond>(
    double& value) noexcept {
  value *= std::pow(1000.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate,
                       Unit::VolumeRate::CubicMilliinchPerSecond>(
    double& value) noexcept {
  value /= std::pow(0.0000254, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate,
                       Unit::VolumeRate::CubicMicrometrePerSecond>(
    double& value) noexcept {
  value *= std::pow(1000000.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::VolumeRate,
                       Unit::VolumeRate::CubicMicroinchPerSecond>(
    double& value) noexcept {
  value /= std::pow(0.0000000254, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>(
    double& value) noexcept {
  value *= std::pow(1609.344, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate,
                     Unit::VolumeRate::CubicKilometrePerSecond>(
    double& value) noexcept {
  value *= std::pow(1000.0, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerSecond>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>(
    double& value) noexcept {
  value *= std::pow(0.9144, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>(
    double& value) noexcept {
  value *= std::pow(0.3048, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate,
                     Unit::VolumeRate::CubicDecimetrePerSecond>(
    double& value) noexcept {
  value *= std::pow(0.1, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>(
    double& value) noexcept {
  value *= std::pow(0.1, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>(
    double& value) noexcept {
  value *= std::pow(0.0254, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate,
                     Unit::VolumeRate::CubicCentimetrePerSecond>(
    double& value) noexcept {
  value *= std::pow(0.01, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerSecond>(
    double& value) noexcept {
  value *= std::pow(0.01, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate,
                     Unit::VolumeRate::CubicMillimetrePerSecond>(
    double& value) noexcept {
  value *= std::pow(0.001, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate,
                     Unit::VolumeRate::CubicMilliinchPerSecond>(
    double& value) noexcept {
  value *= std::pow(0.0000254, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate,
                     Unit::VolumeRate::CubicMicrometrePerSecond>(
    double& value) noexcept {
  value *= std::pow(0.000001, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::VolumeRate,
                     Unit::VolumeRate::CubicMicroinchPerSecond>(
    double& value) noexcept {
  value *= std::pow(0.0000000254, 3);
}

template<>
inline const std::map<Unit::VolumeRate,
                      std::function<void(double* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::VolumeRate>{
        {Unit::VolumeRate::CubicMilePerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilePerSecond>      },
        {Unit::VolumeRate::CubicKilometrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerSecond> },
        {Unit::VolumeRate::CubicMetrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMetrePerSecond>     },
        {Unit::VolumeRate::CubicYardPerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicYardPerSecond>      },
        {Unit::VolumeRate::CubicFootPerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicFootPerSecond>      },
        {Unit::VolumeRate::CubicDecimetrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerSecond> },
        {Unit::VolumeRate::LitrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::LitrePerSecond>          },
        {Unit::VolumeRate::CubicInchPerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicInchPerSecond>      },
        {Unit::VolumeRate::CubicCentimetrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerSecond>},
        {Unit::VolumeRate::MillilitrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::MillilitrePerSecond>     },
        {Unit::VolumeRate::CubicMillimetrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerSecond>},
        {Unit::VolumeRate::CubicMilliinchPerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerSecond> },
        {Unit::VolumeRate::CubicMicrometrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerSecond>},
        {Unit::VolumeRate::CubicMicroinchPerSecond,
         ConversionsFromStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerSecond> },
};

template<> inline const std::map<
    Unit::VolumeRate,
    std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::VolumeRate>{
        {Unit::VolumeRate::CubicMilePerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilePerSecond>      },
        {Unit::VolumeRate::CubicKilometrePerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerSecond> },
        {Unit::VolumeRate::CubicMetrePerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMetrePerSecond>     },
        {Unit::VolumeRate::CubicYardPerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicYardPerSecond>      },
        {Unit::VolumeRate::CubicFootPerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicFootPerSecond>      },
        {Unit::VolumeRate::CubicDecimetrePerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerSecond> },
        {Unit::VolumeRate::LitrePerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::LitrePerSecond>          },
        {Unit::VolumeRate::CubicInchPerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicInchPerSecond>      },
        {Unit::VolumeRate::CubicCentimetrePerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerSecond>},
        {Unit::VolumeRate::MillilitrePerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::MillilitrePerSecond>     },
        {Unit::VolumeRate::CubicMillimetrePerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerSecond>},
        {Unit::VolumeRate::CubicMilliinchPerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerSecond> },
        {Unit::VolumeRate::CubicMicrometrePerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerSecond>},
        {Unit::VolumeRate::CubicMicroinchPerSecond,
         ConversionsToStandard<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerSecond> },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_RATE_HPP
