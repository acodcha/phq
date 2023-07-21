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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ANGULAR_SPEED_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ANGULAR_SPEED_HPP

#include "../Base/Constants.hpp"
#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class AngularSpeed : int_least8_t {
  RadianPerSecond,
  RadianPerMinute,
  RadianPerHour,
  DegreePerSecond,
  DegreePerMinute,
  DegreePerHour,
  ArcminutePerSecond,
  ArcminutePerMinute,
  ArcminutePerHour,
  ArcsecondPerSecond,
  ArcsecondPerMinute,
  ArcsecondPerHour,
  RevolutionPerSecond,
  RevolutionPerMinute,
  RevolutionPerHour,
};

}  // namespace Unit

template<>
inline constexpr const Unit::AngularSpeed StandardUnit<Unit::AngularSpeed>{
    Unit::AngularSpeed::RadianPerSecond};

template<> inline constexpr const Dimension::Set Dimensions<Unit::AngularSpeed>{
    Dimension::Set{Dimension::Time{-1}}};

template<>
inline const std::map<UnitSystem, Unit::AngularSpeed> ConsistentUnits<
    Unit::AngularSpeed>{
    {UnitSystem::MetreKilogramSecondKelvin,
     Unit::AngularSpeed::RadianPerSecond                                        },
    {UnitSystem::MillimetreGramSecondKelvin,
     Unit::AngularSpeed::RadianPerSecond                                        },
    {UnitSystem::FootPoundSecondRankine,     Unit::AngularSpeed::RadianPerSecond},
    {UnitSystem::InchPoundSecondRankine,     Unit::AngularSpeed::RadianPerSecond},
};

template<> inline const std::map<Unit::AngularSpeed, UnitSystem>
    RelatedUnitSystems<Unit::AngularSpeed>{};

template<> inline const std::map<Unit::AngularSpeed, std::string_view>
    Abbreviations<Unit::AngularSpeed>{
        {Unit::AngularSpeed::RadianPerSecond,     "rad/s"     },
        {Unit::AngularSpeed::RadianPerMinute,     "rad/min"   },
        {Unit::AngularSpeed::RadianPerHour,       "rad/hr"    },
        {Unit::AngularSpeed::DegreePerSecond,     "deg/s"     },
        {Unit::AngularSpeed::DegreePerMinute,     "deg/min"   },
        {Unit::AngularSpeed::DegreePerHour,       "deg/hr"    },
        {Unit::AngularSpeed::ArcminutePerSecond,  "arcmin/s"  },
        {Unit::AngularSpeed::ArcminutePerMinute,  "arcmin/min"},
        {Unit::AngularSpeed::ArcminutePerHour,    "arcmin/hr" },
        {Unit::AngularSpeed::ArcsecondPerSecond,  "arcsec/s"  },
        {Unit::AngularSpeed::ArcsecondPerMinute,  "arcsec/min"},
        {Unit::AngularSpeed::ArcsecondPerHour,    "arcsec/hr" },
        {Unit::AngularSpeed::RevolutionPerSecond, "rev/s"     },
        {Unit::AngularSpeed::RevolutionPerMinute, "rev/min"   },
        {Unit::AngularSpeed::RevolutionPerHour,   "rev/hr"    },
};

template<> inline const std::unordered_map<std::string_view, Unit::AngularSpeed>
    Spellings<Unit::AngularSpeed>{
        {"rad/s",      Unit::AngularSpeed::RadianPerSecond    },
        {"rad/min",    Unit::AngularSpeed::RadianPerMinute    },
        {"rad/hr",     Unit::AngularSpeed::RadianPerHour      },
        {"°/s",        Unit::AngularSpeed::DegreePerSecond    },
        {"deg/s",      Unit::AngularSpeed::DegreePerSecond    },
        {"°/min",      Unit::AngularSpeed::DegreePerMinute    },
        {"deg/min",    Unit::AngularSpeed::DegreePerMinute    },
        {"°/hr",       Unit::AngularSpeed::DegreePerHour      },
        {"deg/hr",     Unit::AngularSpeed::DegreePerHour      },
        {"arcmin/s",   Unit::AngularSpeed::ArcminutePerSecond },
        {"arcmin/min", Unit::AngularSpeed::ArcminutePerMinute },
        {"arcmin/hr",  Unit::AngularSpeed::ArcminutePerHour   },
        {"arcsec/s",   Unit::AngularSpeed::ArcsecondPerSecond },
        {"arcsec/min", Unit::AngularSpeed::ArcsecondPerMinute },
        {"arcsec/hr",  Unit::AngularSpeed::ArcsecondPerHour   },
        {"rev/s",      Unit::AngularSpeed::RevolutionPerSecond},
        {"rev/min",    Unit::AngularSpeed::RevolutionPerMinute},
        {"rev/hr",     Unit::AngularSpeed::RevolutionPerHour  },
};

namespace Internal {

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerSecond>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerMinute>(
    double& value) noexcept {
  value *= 60.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerHour>(
    double& value) noexcept {
  value *= 3600.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerSecond>(
    double& value) noexcept {
  value *= 180.0 / Pi;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerMinute>(
    double& value) noexcept {
  value *= 10800.0 / Pi;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerHour>(
    double& value) noexcept {
  value *= 648000.0 / Pi;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed,
                       Unit::AngularSpeed::ArcminutePerSecond>(
    double& value) noexcept {
  value *= 10800.0 / Pi;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed,
                       Unit::AngularSpeed::ArcminutePerMinute>(
    double& value) noexcept {
  value *= 648000.0 / Pi;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerHour>(
    double& value) noexcept {
  value *= 38880000.0 / Pi;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed,
                       Unit::AngularSpeed::ArcsecondPerSecond>(
    double& value) noexcept {
  value *= 648000.0 / Pi;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed,
                       Unit::AngularSpeed::ArcsecondPerMinute>(
    double& value) noexcept {
  value *= 38880000.0 / Pi;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerHour>(
    double& value) noexcept {
  value *= 2332800000.0 / Pi;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed,
                       Unit::AngularSpeed::RevolutionPerSecond>(
    double& value) noexcept {
  value *= 0.5 / Pi;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed,
                       Unit::AngularSpeed::RevolutionPerMinute>(
    double& value) noexcept {
  value *= 30.0 / Pi;
}

template<> inline constexpr void
ConversionFromStandard<Unit::AngularSpeed,
                       Unit::AngularSpeed::RevolutionPerHour>(
    double& value) noexcept {
  value *= 1800.0 / Pi;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerSecond>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerMinute>(
    double& value) noexcept {
  value /= 60.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerHour>(
    double& value) noexcept {
  value /= 3600.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerSecond>(
    double& value) noexcept {
  value *= Pi / 180.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerMinute>(
    double& value) noexcept {
  value *= Pi / 10800.0;
  ;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerHour>(
    double& value) noexcept {
  value *= Pi / 648000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerSecond>(
    double& value) noexcept {
  value *= Pi / 10800.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerMinute>(
    double& value) noexcept {
  value *= Pi / 648000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerHour>(
    double& value) noexcept {
  value *= Pi / 38880000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerSecond>(
    double& value) noexcept {
  value *= Pi / 648000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerMinute>(
    double& value) noexcept {
  value *= Pi / 38880000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerHour>(
    double& value) noexcept {
  value *= Pi / 2332800000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed,
                     Unit::AngularSpeed::RevolutionPerSecond>(
    double& value) noexcept {
  value *= 2.0 * Pi;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed,
                     Unit::AngularSpeed::RevolutionPerMinute>(
    double& value) noexcept {
  value *= Pi / 30.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerHour>(
    double& value) noexcept {
  value *= Pi / 1800.0;
}

template<> inline const std::map<
    Unit::AngularSpeed,
    std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::AngularSpeed>{
        {Unit::AngularSpeed::RadianPerSecond,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerSecond>    },
        {Unit::AngularSpeed::RadianPerMinute,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerMinute>    },
        {Unit::AngularSpeed::RadianPerHour,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerHour>      },
        {Unit::AngularSpeed::DegreePerSecond,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerSecond>    },
        {Unit::AngularSpeed::DegreePerMinute,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerMinute>    },
        {Unit::AngularSpeed::DegreePerHour,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerHour>      },
        {Unit::AngularSpeed::ArcminutePerSecond,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerSecond> },
        {Unit::AngularSpeed::ArcminutePerMinute,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerMinute> },
        {Unit::AngularSpeed::ArcminutePerHour,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerHour>   },
        {Unit::AngularSpeed::ArcsecondPerSecond,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerSecond> },
        {Unit::AngularSpeed::ArcsecondPerMinute,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerMinute> },
        {Unit::AngularSpeed::ArcsecondPerHour,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerHour>   },
        {Unit::AngularSpeed::RevolutionPerSecond,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerSecond>},
        {Unit::AngularSpeed::RevolutionPerMinute,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerMinute>},
        {Unit::AngularSpeed::RevolutionPerHour,
         ConversionsFromStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerHour>  },
};

template<> inline const std::map<
    Unit::AngularSpeed,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::AngularSpeed>{
        {Unit::AngularSpeed::RadianPerSecond,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerSecond>    },
        {Unit::AngularSpeed::RadianPerMinute,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerMinute>    },
        {Unit::AngularSpeed::RadianPerHour,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerHour>      },
        {Unit::AngularSpeed::DegreePerSecond,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerSecond>    },
        {Unit::AngularSpeed::DegreePerMinute,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerMinute>    },
        {Unit::AngularSpeed::DegreePerHour,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerHour>      },
        {Unit::AngularSpeed::ArcminutePerSecond,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerSecond> },
        {Unit::AngularSpeed::ArcminutePerMinute,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerMinute> },
        {Unit::AngularSpeed::ArcminutePerHour,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerHour>   },
        {Unit::AngularSpeed::ArcsecondPerSecond,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerSecond> },
        {Unit::AngularSpeed::ArcsecondPerMinute,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerMinute> },
        {Unit::AngularSpeed::ArcsecondPerHour,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerHour>   },
        {Unit::AngularSpeed::RevolutionPerSecond,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerSecond>},
        {Unit::AngularSpeed::RevolutionPerMinute,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerMinute>},
        {Unit::AngularSpeed::RevolutionPerHour,
         ConversionsToStandard<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerHour>  },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ANGULAR_SPEED_HPP
