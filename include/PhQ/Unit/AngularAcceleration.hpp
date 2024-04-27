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

#ifndef PHQ_UNIT_ANGULAR_ACCELERATION_HPP
#define PHQ_UNIT_ANGULAR_ACCELERATION_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

// Angular acceleration units.
enum class AngularAcceleration : int8_t {
  // Radian per square second (rad/s^2) angular acceleration unit.
  RadianPerSquareSecond,

  // Radian per square minute (rad/min^2) angular acceleration unit.
  RadianPerSquareMinute,

  // Radian per square hour (rad/hr^2) angular acceleration unit.
  RadianPerSquareHour,

  // Degree per square second (deg/s^2) angular acceleration unit.
  DegreePerSquareSecond,

  // Degree per square minute (deg/min^2) angular acceleration unit.
  DegreePerSquareMinute,

  // Degree per square hour (deg/hr^2) angular acceleration unit.
  DegreePerSquareHour,

  // Arcminute per square second (arcmin/s^2) angular acceleration unit.
  ArcminutePerSquareSecond,

  // Arcminute per square minute (arcmin/min^2) angular acceleration unit.
  ArcminutePerSquareMinute,

  // Arcminute per square hour (arcmin/hr^2) angular acceleration unit.
  ArcminutePerSquareHour,

  // Arcsecond per square second (arcsec/s^2) angular acceleration unit.
  ArcsecondPerSquareSecond,

  // Arcsecond per square minute (arcsec/min^2) angular acceleration unit.
  ArcsecondPerSquareMinute,

  // Arcsecond per square hour (arcsec/hr^2) angular acceleration unit.
  ArcsecondPerSquareHour,

  // Revolution per square second (rev/s^2) angular acceleration unit.
  RevolutionPerSquareSecond,

  // Revolution per square minute (rev/min^2) angular acceleration unit.
  RevolutionPerSquareMinute,

  // Revolution per square hour (rev/hr^2) angular acceleration unit.
  RevolutionPerSquareHour,
};

}  // namespace Unit

// Standard angular acceleration unit: radian per square second (rad/s^2).
template <>
inline constexpr const Unit::AngularAcceleration Standard<Unit::AngularAcceleration>{
    Unit::AngularAcceleration::RadianPerSquareSecond};

// Physical dimension set of angular acceleration units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::AngularAcceleration>{
    Dimensions{Dimension::Time{-2}}};

inline std::ostream& operator<<(std::ostream& stream, const Unit::AngularAcceleration unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::AngularAcceleration>
    ConsistentUnits<Unit::AngularAcceleration>{
        {UnitSystem::MetreKilogramSecondKelvin,  Unit::AngularAcceleration::RadianPerSquareSecond},
        {UnitSystem::MillimetreGramSecondKelvin, Unit::AngularAcceleration::RadianPerSquareSecond},
        {UnitSystem::FootPoundSecondRankine,     Unit::AngularAcceleration::RadianPerSquareSecond},
        {UnitSystem::InchPoundSecondRankine,     Unit::AngularAcceleration::RadianPerSquareSecond},
};

template <>
inline const std::map<Unit::AngularAcceleration, UnitSystem>
    RelatedUnitSystems<Unit::AngularAcceleration>{};

template <>
inline const std::map<Unit::AngularAcceleration, std::string_view>
    Abbreviations<Unit::AngularAcceleration>{
        {Unit::AngularAcceleration::RadianPerSquareSecond,     "rad/s^2"     },
        {Unit::AngularAcceleration::RadianPerSquareMinute,     "rad/min^2"   },
        {Unit::AngularAcceleration::RadianPerSquareHour,       "rad/hr^2"    },
        {Unit::AngularAcceleration::DegreePerSquareSecond,     "deg/s^2"     },
        {Unit::AngularAcceleration::DegreePerSquareMinute,     "deg/min^2"   },
        {Unit::AngularAcceleration::DegreePerSquareHour,       "deg/hr^2"    },
        {Unit::AngularAcceleration::ArcminutePerSquareSecond,  "arcmin/s^2"  },
        {Unit::AngularAcceleration::ArcminutePerSquareMinute,  "arcmin/min^2"},
        {Unit::AngularAcceleration::ArcminutePerSquareHour,    "arcmin/hr^2" },
        {Unit::AngularAcceleration::ArcsecondPerSquareSecond,  "arcsec/s^2"  },
        {Unit::AngularAcceleration::ArcsecondPerSquareMinute,  "arcsec/min^2"},
        {Unit::AngularAcceleration::ArcsecondPerSquareHour,    "arcsec/hr^2" },
        {Unit::AngularAcceleration::RevolutionPerSquareSecond, "rev/s^2"     },
        {Unit::AngularAcceleration::RevolutionPerSquareMinute, "rev/min^2"   },
        {Unit::AngularAcceleration::RevolutionPerSquareHour,   "rev/hr^2"    },
};

template <>
inline const std::unordered_map<std::string_view, Unit::AngularAcceleration> Spellings<
    Unit::AngularAcceleration>{
    {"rad/s^2",        Unit::AngularAcceleration::RadianPerSquareSecond    },
    {"rad/s2",         Unit::AngularAcceleration::RadianPerSquareSecond    },
    {"rad/s/s",        Unit::AngularAcceleration::RadianPerSquareSecond    },
    {"rad/min^2",      Unit::AngularAcceleration::RadianPerSquareMinute    },
    {"rad/min2",       Unit::AngularAcceleration::RadianPerSquareMinute    },
    {"rad/min/min",    Unit::AngularAcceleration::RadianPerSquareMinute    },
    {"rad/hr^2",       Unit::AngularAcceleration::RadianPerSquareHour      },
    {"rad/hr2",        Unit::AngularAcceleration::RadianPerSquareHour      },
    {"rad/hr/hr",      Unit::AngularAcceleration::RadianPerSquareHour      },
    {"°/s^2",          Unit::AngularAcceleration::DegreePerSquareSecond    },
    {"°/s2",           Unit::AngularAcceleration::DegreePerSquareSecond    },
    {"°/s/s",          Unit::AngularAcceleration::DegreePerSquareSecond    },
    {"deg/s^2",        Unit::AngularAcceleration::DegreePerSquareSecond    },
    {"deg/s2",         Unit::AngularAcceleration::DegreePerSquareSecond    },
    {"deg/s/s",        Unit::AngularAcceleration::DegreePerSquareSecond    },
    {"°/min^2",        Unit::AngularAcceleration::DegreePerSquareMinute    },
    {"°/min2",         Unit::AngularAcceleration::DegreePerSquareMinute    },
    {"°/min/min",      Unit::AngularAcceleration::DegreePerSquareMinute    },
    {"deg/min^2",      Unit::AngularAcceleration::DegreePerSquareMinute    },
    {"deg/min2",       Unit::AngularAcceleration::DegreePerSquareMinute    },
    {"deg/min/min",    Unit::AngularAcceleration::DegreePerSquareMinute    },
    {"°/hr^2",         Unit::AngularAcceleration::DegreePerSquareHour      },
    {"°/hr2",          Unit::AngularAcceleration::DegreePerSquareHour      },
    {"°/hr/hr",        Unit::AngularAcceleration::DegreePerSquareHour      },
    {"deg/hr^2",       Unit::AngularAcceleration::DegreePerSquareHour      },
    {"deg/hr2",        Unit::AngularAcceleration::DegreePerSquareHour      },
    {"deg/hr/hr",      Unit::AngularAcceleration::DegreePerSquareHour      },
    {"arcmin/s^2",     Unit::AngularAcceleration::ArcminutePerSquareSecond },
    {"arcmin/s2",      Unit::AngularAcceleration::ArcminutePerSquareSecond },
    {"arcmin/s/s",     Unit::AngularAcceleration::ArcminutePerSquareSecond },
    {"arcmin/min^2",   Unit::AngularAcceleration::ArcminutePerSquareMinute },
    {"arcmin/min2",    Unit::AngularAcceleration::ArcminutePerSquareMinute },
    {"arcmin/min/min", Unit::AngularAcceleration::ArcminutePerSquareMinute },
    {"arcmin/hr^2",    Unit::AngularAcceleration::ArcminutePerSquareHour   },
    {"arcmin/hr2",     Unit::AngularAcceleration::ArcminutePerSquareHour   },
    {"arcmin/hr/hr",   Unit::AngularAcceleration::ArcminutePerSquareHour   },
    {"arcsec/s^2",     Unit::AngularAcceleration::ArcsecondPerSquareSecond },
    {"arcsec/s2",      Unit::AngularAcceleration::ArcsecondPerSquareSecond },
    {"arcsec/s/s",     Unit::AngularAcceleration::ArcsecondPerSquareSecond },
    {"arcsec/min^2",   Unit::AngularAcceleration::ArcsecondPerSquareMinute },
    {"arcsec/min2",    Unit::AngularAcceleration::ArcsecondPerSquareMinute },
    {"arcsec/min/min", Unit::AngularAcceleration::ArcsecondPerSquareMinute },
    {"arcsec/hr^2",    Unit::AngularAcceleration::ArcsecondPerSquareHour   },
    {"arcsec/hr2",     Unit::AngularAcceleration::ArcsecondPerSquareHour   },
    {"arcsec/hr/hr",   Unit::AngularAcceleration::ArcsecondPerSquareHour   },
    {"rev/s^2",        Unit::AngularAcceleration::RevolutionPerSquareSecond},
    {"rev/s2",         Unit::AngularAcceleration::RevolutionPerSquareSecond},
    {"rev/s/s",        Unit::AngularAcceleration::RevolutionPerSquareSecond},
    {"rev/min^2",      Unit::AngularAcceleration::RevolutionPerSquareMinute},
    {"rev/min2",       Unit::AngularAcceleration::RevolutionPerSquareMinute},
    {"rev/min/min",    Unit::AngularAcceleration::RevolutionPerSquareMinute},
    {"rev/hr^2",       Unit::AngularAcceleration::RevolutionPerSquareHour  },
    {"rev/hr2",        Unit::AngularAcceleration::RevolutionPerSquareHour  },
    {"rev/hr/hr",      Unit::AngularAcceleration::RevolutionPerSquareHour  },
};

template <>
inline constexpr void
ConversionFromStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::RadianPerSquareSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::RadianPerSquareSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::RadianPerSquareMinute>(
    double& value) noexcept {
  value *= 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::RadianPerSquareMinute>(
    double& value) noexcept {
  value *= 1.0 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::RadianPerSquareHour>(
    double& value) noexcept {
  value *= 12960000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::RadianPerSquareHour>(
    double& value) noexcept {
  value *= 1.0 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::DegreePerSquareSecond>(
    double& value) noexcept {
  value *= 180.0 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::DegreePerSquareSecond>(
    double& value) noexcept {
  value *= Pi / 180.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::DegreePerSquareMinute>(
    double& value) noexcept {
  value *= 648000.0 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::DegreePerSquareMinute>(
    double& value) noexcept {
  value *= Pi / 648000.0;
  ;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::DegreePerSquareHour>(
    double& value) noexcept {
  value *= 2332800000.0 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::DegreePerSquareHour>(
    double& value) noexcept {
  value *= Pi / 2332800000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::AngularAcceleration,
                                             Unit::AngularAcceleration::ArcminutePerSquareSecond>(
    double& value) noexcept {
  value *= 10800.0 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration,
                     Unit::AngularAcceleration::ArcminutePerSquareSecond>(double& value) noexcept {
  value *= Pi / 10800.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::AngularAcceleration,
                                             Unit::AngularAcceleration::ArcminutePerSquareMinute>(
    double& value) noexcept {
  value *= 38880000.0 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration,
                     Unit::AngularAcceleration::ArcminutePerSquareMinute>(double& value) noexcept {
  value *= Pi / 38880000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::AngularAcceleration,
                       Unit::AngularAcceleration::ArcminutePerSquareHour>(double& value) noexcept {
  value *= 139968000000.0 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::ArcminutePerSquareHour>(
    double& value) noexcept {
  value *= Pi / 139968000000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::AngularAcceleration,
                                             Unit::AngularAcceleration::ArcsecondPerSquareSecond>(
    double& value) noexcept {
  value *= 648000.0 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration,
                     Unit::AngularAcceleration::ArcsecondPerSquareSecond>(double& value) noexcept {
  value *= Pi / 648000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::AngularAcceleration,
                                             Unit::AngularAcceleration::ArcsecondPerSquareMinute>(
    double& value) noexcept {
  value *= 2332800000.0 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration,
                     Unit::AngularAcceleration::ArcsecondPerSquareMinute>(double& value) noexcept {
  value *= Pi / 2332800000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::AngularAcceleration,
                       Unit::AngularAcceleration::ArcsecondPerSquareHour>(double& value) noexcept {
  value *= 8398080000000.0 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::ArcsecondPerSquareHour>(
    double& value) noexcept {
  value *= Pi / 8398080000000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::AngularAcceleration,
                                             Unit::AngularAcceleration::RevolutionPerSquareSecond>(
    double& value) noexcept {
  value *= 0.5 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration,
                     Unit::AngularAcceleration::RevolutionPerSquareSecond>(double& value) noexcept {
  value *= 2.0 * Pi;
}

template <>
inline constexpr void ConversionFromStandard<Unit::AngularAcceleration,
                                             Unit::AngularAcceleration::RevolutionPerSquareMinute>(
    double& value) noexcept {
  value *= 1800.0 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration,
                     Unit::AngularAcceleration::RevolutionPerSquareMinute>(double& value) noexcept {
  value *= Pi / 1800.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::AngularAcceleration,
                       Unit::AngularAcceleration::RevolutionPerSquareHour>(double& value) noexcept {
  value *= 6480000.0 / Pi;
}

template <>
inline constexpr void
ConversionToStandard<Unit::AngularAcceleration, Unit::AngularAcceleration::RevolutionPerSquareHour>(
    double& value) noexcept {
  value *= Pi / 6480000.0;
}

template <>
inline const std::map<Unit::AngularAcceleration,
                      std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::AngularAcceleration>{
        {Unit::AngularAcceleration::RadianPerSquareSecond,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RadianPerSquareSecond>    },
        {Unit::AngularAcceleration::RadianPerSquareMinute,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RadianPerSquareMinute>    },
        {Unit::AngularAcceleration::RadianPerSquareHour,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RadianPerSquareHour>      },
        {Unit::AngularAcceleration::DegreePerSquareSecond,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::DegreePerSquareSecond>    },
        {Unit::AngularAcceleration::DegreePerSquareMinute,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::DegreePerSquareMinute>    },
        {Unit::AngularAcceleration::DegreePerSquareHour,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::DegreePerSquareHour>      },
        {Unit::AngularAcceleration::ArcminutePerSquareSecond,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcminutePerSquareSecond> },
        {Unit::AngularAcceleration::ArcminutePerSquareMinute,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcminutePerSquareMinute> },
        {Unit::AngularAcceleration::ArcminutePerSquareHour,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcminutePerSquareHour>   },
        {Unit::AngularAcceleration::ArcsecondPerSquareSecond,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcsecondPerSquareSecond> },
        {Unit::AngularAcceleration::ArcsecondPerSquareMinute,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcsecondPerSquareMinute> },
        {Unit::AngularAcceleration::ArcsecondPerSquareHour,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcsecondPerSquareHour>   },
        {Unit::AngularAcceleration::RevolutionPerSquareSecond,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RevolutionPerSquareSecond>},
        {Unit::AngularAcceleration::RevolutionPerSquareMinute,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RevolutionPerSquareMinute>},
        {Unit::AngularAcceleration::RevolutionPerSquareHour,
         ConversionsFromStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RevolutionPerSquareHour>  },
};

template <>
inline const std::map<Unit::AngularAcceleration,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::AngularAcceleration>{
        {Unit::AngularAcceleration::RadianPerSquareSecond,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RadianPerSquareSecond>    },
        {Unit::AngularAcceleration::RadianPerSquareMinute,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RadianPerSquareMinute>    },
        {Unit::AngularAcceleration::RadianPerSquareHour,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RadianPerSquareHour>      },
        {Unit::AngularAcceleration::DegreePerSquareSecond,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::DegreePerSquareSecond>    },
        {Unit::AngularAcceleration::DegreePerSquareMinute,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::DegreePerSquareMinute>    },
        {Unit::AngularAcceleration::DegreePerSquareHour,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::DegreePerSquareHour>      },
        {Unit::AngularAcceleration::ArcminutePerSquareSecond,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcminutePerSquareSecond> },
        {Unit::AngularAcceleration::ArcminutePerSquareMinute,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcminutePerSquareMinute> },
        {Unit::AngularAcceleration::ArcminutePerSquareHour,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcminutePerSquareHour>   },
        {Unit::AngularAcceleration::ArcsecondPerSquareSecond,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcsecondPerSquareSecond> },
        {Unit::AngularAcceleration::ArcsecondPerSquareMinute,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcsecondPerSquareMinute> },
        {Unit::AngularAcceleration::ArcsecondPerSquareHour,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::ArcsecondPerSquareHour>   },
        {Unit::AngularAcceleration::RevolutionPerSquareSecond,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RevolutionPerSquareSecond>},
        {Unit::AngularAcceleration::RevolutionPerSquareMinute,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RevolutionPerSquareMinute>},
        {Unit::AngularAcceleration::RevolutionPerSquareHour,
         ConversionsToStandard<Unit::AngularAcceleration,
         Unit::AngularAcceleration::RevolutionPerSquareHour>  },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ANGULAR_ACCELERATION_HPP
