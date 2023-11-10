// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_RATE_HPP

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

// Volume rate units. Can represent a time rate of change of a volume or a
// volume flow rate.
enum class VolumeRate : int8_t {
  // Cubic mile per second (mi^3/s) volume rate unit.
  CubicMilePerSecond,

  // Cubic kilometre per second (km^3/s) volume rate unit.
  CubicKilometrePerSecond,

  // Cubic metre per second (m^3/s) volume rate unit.
  CubicMetrePerSecond,

  // Cubic yard per second (yd^3/s) volume rate unit.
  CubicYardPerSecond,

  // Cubic foot per second (ft^3/s) volume rate unit.
  CubicFootPerSecond,

  // Cubic decimetre per second (dm^3/s) volume rate unit.
  CubicDecimetrePerSecond,

  // Litre per second (L/s) volume rate unit.
  LitrePerSecond,

  // Cubic inch per second (in^3/s) volume rate unit.
  CubicInchPerSecond,

  // Cubic centimetre per second (cm^3/s) volume rate unit.
  CubicCentimetrePerSecond,

  // Millilitre per second (mL/s) volume rate unit.
  MillilitrePerSecond,

  // Cubic millimetre per second (mm^3/s) volume rate unit.
  CubicMillimetrePerSecond,

  // Cubic milliinch per second (mil^3/s) volume rate unit.
  CubicMilliinchPerSecond,

  // Cubic micrometre per second (μm^3/s) volume rate unit.
  CubicMicrometrePerSecond,

  // Cubic microinch per second (μin^3/s) volume rate unit.
  CubicMicroinchPerSecond,

  // Cubic mile per minute (mi^3/min) volume rate unit.
  CubicMilePerMinute,

  // Cubic kilometre per minute (km^3/min) volume rate unit.
  CubicKilometrePerMinute,

  // Cubic metre per minute (m^3/min) volume rate unit.
  CubicMetrePerMinute,

  // Cubic yard per minute (yd^3/min) volume rate unit.
  CubicYardPerMinute,

  // Cubic foot per minute (ft^3/min) volume rate unit.
  CubicFootPerMinute,

  // Cubic decimetre per minute (dm^3/min) volume rate unit.
  CubicDecimetrePerMinute,

  // Litre per minute (L/min) volume rate unit.
  LitrePerMinute,

  // Cubic inch per minute (in^3/min) volume rate unit.
  CubicInchPerMinute,

  // Cubic centimetre per minute (cm^3/min) volume rate unit.
  CubicCentimetrePerMinute,

  // Millilitre per minute (mL/min) volume rate unit.
  MillilitrePerMinute,

  // Cubic millimetre per minute (mm^3/min) volume rate unit.
  CubicMillimetrePerMinute,

  // Cubic milliinch per minute (mil^3/min) volume rate unit.
  CubicMilliinchPerMinute,

  // Cubic micrometre per minute (μm^3/min) volume rate unit.
  CubicMicrometrePerMinute,

  // Cubic microinch per minute (μin^3/min) volume rate unit.
  CubicMicroinchPerMinute,

  // Cubic mile per hour (mi^3/hr) volume rate unit.
  CubicMilePerHour,

  // Cubic kilometre per hour (km^3/hr) volume rate unit.
  CubicKilometrePerHour,

  // Cubic metre per hour (m^3/hr) volume rate unit.
  CubicMetrePerHour,

  // Cubic yard per hour (yd^3/hr) volume rate unit.
  CubicYardPerHour,

  // Cubic foot per hour (ft^3/hr) volume rate unit.
  CubicFootPerHour,

  // Cubic decimetre per hour (dm^3/hr) volume rate unit.
  CubicDecimetrePerHour,

  // Litre per hour (L/hr) volume rate unit.
  LitrePerHour,

  // Cubic inch per hour (in^3/hr) volume rate unit.
  CubicInchPerHour,

  // Cubic centimetre per hour (cm^3/hr) volume rate unit.
  CubicCentimetrePerHour,

  // Millilitre per hour (mL/hr) volume rate unit.
  MillilitrePerHour,

  // Cubic millimetre per hour (mm^3/hr) volume rate unit.
  CubicMillimetrePerHour,

  // Cubic milliinch per hour (mil^3/hr) volume rate unit.
  CubicMilliinchPerHour,

  // Cubic micrometre per hour (μm^3/hr) volume rate unit.
  CubicMicrometrePerHour,

  // Cubic microinch per hour (μin^3/hr) volume rate unit.
  CubicMicroinchPerHour,
};

}  // namespace Unit

// Standard time-rate of volume unit: cubic metre per second (m^3/s).
template <>
inline constexpr const Unit::VolumeRate Standard<Unit::VolumeRate>{
    Unit::VolumeRate::CubicMetrePerSecond};

// Physical dimension set of time-rate of volume units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::VolumeRate>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{3}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::VolumeRate unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::VolumeRate> ConsistentUnits<Unit::VolumeRate>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::VolumeRate::CubicMetrePerSecond     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::VolumeRate::CubicMillimetrePerSecond},
    {UnitSystem::FootPoundSecondRankine,     Unit::VolumeRate::CubicFootPerSecond      },
    {UnitSystem::InchPoundSecondRankine,     Unit::VolumeRate::CubicInchPerSecond      },
};

template <>
inline const std::map<Unit::VolumeRate, UnitSystem> RelatedUnitSystems<Unit::VolumeRate>{
    {Unit::VolumeRate::CubicMetrePerSecond,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::VolumeRate::CubicMillimetrePerSecond, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::VolumeRate::CubicFootPerSecond,       UnitSystem::FootPoundSecondRankine    },
    {Unit::VolumeRate::CubicInchPerSecond,       UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::VolumeRate, std::string_view> Abbreviations<Unit::VolumeRate>{
    {Unit::VolumeRate::CubicMilePerSecond,       "mi^3/s"   },
    {Unit::VolumeRate::CubicKilometrePerSecond,  "km^3/s"   },
    {Unit::VolumeRate::CubicMetrePerSecond,      "m^3/s"    },
    {Unit::VolumeRate::CubicYardPerSecond,       "yd^3/s"   },
    {Unit::VolumeRate::CubicFootPerSecond,       "ft^3/s"   },
    {Unit::VolumeRate::CubicDecimetrePerSecond,  "dm^3/s"   },
    {Unit::VolumeRate::LitrePerSecond,           "L/s"      },
    {Unit::VolumeRate::CubicInchPerSecond,       "in^3/s"   },
    {Unit::VolumeRate::CubicCentimetrePerSecond, "cm^3/s"   },
    {Unit::VolumeRate::MillilitrePerSecond,      "mL/s"     },
    {Unit::VolumeRate::CubicMillimetrePerSecond, "mm^3/s"   },
    {Unit::VolumeRate::CubicMilliinchPerSecond,  "mil^3/s"  },
    {Unit::VolumeRate::CubicMicrometrePerSecond, "μm^3/s"   },
    {Unit::VolumeRate::CubicMicroinchPerSecond,  "μin^3/s"  },
    {Unit::VolumeRate::CubicMilePerMinute,       "mi^3/min" },
    {Unit::VolumeRate::CubicKilometrePerMinute,  "km^3/min" },
    {Unit::VolumeRate::CubicMetrePerMinute,      "m^3/min"  },
    {Unit::VolumeRate::CubicYardPerMinute,       "yd^3/min" },
    {Unit::VolumeRate::CubicFootPerMinute,       "ft^3/min" },
    {Unit::VolumeRate::CubicDecimetrePerMinute,  "dm^3/min" },
    {Unit::VolumeRate::LitrePerMinute,           "L/min"    },
    {Unit::VolumeRate::CubicInchPerMinute,       "in^3/min" },
    {Unit::VolumeRate::CubicCentimetrePerMinute, "cm^3/min" },
    {Unit::VolumeRate::MillilitrePerMinute,      "mL/min"   },
    {Unit::VolumeRate::CubicMillimetrePerMinute, "mm^3/min" },
    {Unit::VolumeRate::CubicMilliinchPerMinute,  "mil^3/min"},
    {Unit::VolumeRate::CubicMicrometrePerMinute, "μm^3/min" },
    {Unit::VolumeRate::CubicMicroinchPerMinute,  "μin^3/min"},
    {Unit::VolumeRate::CubicMilePerHour,         "mi^3/hr"  },
    {Unit::VolumeRate::CubicKilometrePerHour,    "km^3/hr"  },
    {Unit::VolumeRate::CubicMetrePerHour,        "m^3/hr"   },
    {Unit::VolumeRate::CubicYardPerHour,         "yd^3/hr"  },
    {Unit::VolumeRate::CubicFootPerHour,         "ft^3/hr"  },
    {Unit::VolumeRate::CubicDecimetrePerHour,    "dm^3/hr"  },
    {Unit::VolumeRate::LitrePerHour,             "L/hr"     },
    {Unit::VolumeRate::CubicInchPerHour,         "in^3/hr"  },
    {Unit::VolumeRate::CubicCentimetrePerHour,   "cm^3/hr"  },
    {Unit::VolumeRate::MillilitrePerHour,        "mL/hr"    },
    {Unit::VolumeRate::CubicMillimetrePerHour,   "mm^3/hr"  },
    {Unit::VolumeRate::CubicMilliinchPerHour,    "mil^3/hr" },
    {Unit::VolumeRate::CubicMicrometrePerHour,   "μm^3/hr"  },
    {Unit::VolumeRate::CubicMicroinchPerHour,    "μin^3/hr" },
};

template <>
inline const std::unordered_map<std::string_view, Unit::VolumeRate> Spellings<Unit::VolumeRate>{
    {"mi^3/s",          Unit::VolumeRate::CubicMilePerSecond      },
    {"mi3/s",           Unit::VolumeRate::CubicMilePerSecond      },
    {"km^3/s",          Unit::VolumeRate::CubicKilometrePerSecond },
    {"km3/s",           Unit::VolumeRate::CubicKilometrePerSecond },
    {"m^3/s",           Unit::VolumeRate::CubicMetrePerSecond     },
    {"m3/s",            Unit::VolumeRate::CubicMetrePerSecond     },
    {"yd^3/s",          Unit::VolumeRate::CubicYardPerSecond      },
    {"yd3/s",           Unit::VolumeRate::CubicYardPerSecond      },
    {"ft^3/s",          Unit::VolumeRate::CubicFootPerSecond      },
    {"ft3/s",           Unit::VolumeRate::CubicFootPerSecond      },
    {"dm^3/s",          Unit::VolumeRate::CubicDecimetrePerSecond },
    {"dm3/s",           Unit::VolumeRate::CubicDecimetrePerSecond },
    {"L/s",             Unit::VolumeRate::LitrePerSecond          },
    {"in^3/s",          Unit::VolumeRate::CubicInchPerSecond      },
    {"in3/s",           Unit::VolumeRate::CubicInchPerSecond      },
    {"cm^3/s",          Unit::VolumeRate::CubicCentimetrePerSecond},
    {"cm3/s",           Unit::VolumeRate::CubicCentimetrePerSecond},
    {"mL/s",            Unit::VolumeRate::MillilitrePerSecond     },
    {"mm^3/s",          Unit::VolumeRate::CubicMillimetrePerSecond},
    {"mm3/s",           Unit::VolumeRate::CubicMillimetrePerSecond},
    {"millinch^3/s",    Unit::VolumeRate::CubicMilliinchPerSecond },
    {"millinch3/s",     Unit::VolumeRate::CubicMilliinchPerSecond },
    {"milliinch^3/s",   Unit::VolumeRate::CubicMilliinchPerSecond },
    {"milliinch3/s",    Unit::VolumeRate::CubicMilliinchPerSecond },
    {"mil^3/s",         Unit::VolumeRate::CubicMilliinchPerSecond },
    {"mil3/s",          Unit::VolumeRate::CubicMilliinchPerSecond },
    {"thou^3/s",        Unit::VolumeRate::CubicMilliinchPerSecond },
    {"thou3/s",         Unit::VolumeRate::CubicMilliinchPerSecond },
    {"μm^3/s",          Unit::VolumeRate::CubicMicrometrePerSecond},
    {"μm3/s",           Unit::VolumeRate::CubicMicrometrePerSecond},
    {"um^3/s",          Unit::VolumeRate::CubicMicrometrePerSecond},
    {"um3/s",           Unit::VolumeRate::CubicMicrometrePerSecond},
    {"μin^3/s",         Unit::VolumeRate::CubicMicroinchPerSecond },
    {"μin3/s",          Unit::VolumeRate::CubicMicroinchPerSecond },
    {"uin^3/s",         Unit::VolumeRate::CubicMicroinchPerSecond },
    {"uin3/s",          Unit::VolumeRate::CubicMicroinchPerSecond },
    {"mi^3/min",        Unit::VolumeRate::CubicMilePerMinute      },
    {"mi3/min",         Unit::VolumeRate::CubicMilePerMinute      },
    {"km^3/min",        Unit::VolumeRate::CubicKilometrePerMinute },
    {"km3/min",         Unit::VolumeRate::CubicKilometrePerMinute },
    {"m^3/min",         Unit::VolumeRate::CubicMetrePerMinute     },
    {"m3/min",          Unit::VolumeRate::CubicMetrePerMinute     },
    {"yd^3/min",        Unit::VolumeRate::CubicYardPerMinute      },
    {"yd3/min",         Unit::VolumeRate::CubicYardPerMinute      },
    {"ft^3/min",        Unit::VolumeRate::CubicFootPerMinute      },
    {"ft3/min",         Unit::VolumeRate::CubicFootPerMinute      },
    {"dm^3/min",        Unit::VolumeRate::CubicDecimetrePerMinute },
    {"dm3/min",         Unit::VolumeRate::CubicDecimetrePerMinute },
    {"L/min",           Unit::VolumeRate::LitrePerMinute          },
    {"in^3/min",        Unit::VolumeRate::CubicInchPerMinute      },
    {"in3/min",         Unit::VolumeRate::CubicInchPerMinute      },
    {"cm^3/min",        Unit::VolumeRate::CubicCentimetrePerMinute},
    {"cm3/min",         Unit::VolumeRate::CubicCentimetrePerMinute},
    {"mL/min",          Unit::VolumeRate::MillilitrePerMinute     },
    {"mm^3/min",        Unit::VolumeRate::CubicMillimetrePerMinute},
    {"mm3/min",         Unit::VolumeRate::CubicMillimetrePerMinute},
    {"millinch^3/min",  Unit::VolumeRate::CubicMilliinchPerMinute },
    {"millinch3/min",   Unit::VolumeRate::CubicMilliinchPerMinute },
    {"milliinch^3/min", Unit::VolumeRate::CubicMilliinchPerMinute },
    {"milliinch3/min",  Unit::VolumeRate::CubicMilliinchPerMinute },
    {"mil^3/min",       Unit::VolumeRate::CubicMilliinchPerMinute },
    {"mil3/min",        Unit::VolumeRate::CubicMilliinchPerMinute },
    {"thou^3/min",      Unit::VolumeRate::CubicMilliinchPerMinute },
    {"thou3/min",       Unit::VolumeRate::CubicMilliinchPerMinute },
    {"μm^3/min",        Unit::VolumeRate::CubicMicrometrePerMinute},
    {"μm3/min",         Unit::VolumeRate::CubicMicrometrePerMinute},
    {"um^3/min",        Unit::VolumeRate::CubicMicrometrePerMinute},
    {"um3/min",         Unit::VolumeRate::CubicMicrometrePerMinute},
    {"μin^3/min",       Unit::VolumeRate::CubicMicroinchPerMinute },
    {"μin3/min",        Unit::VolumeRate::CubicMicroinchPerMinute },
    {"uin^3/min",       Unit::VolumeRate::CubicMicroinchPerMinute },
    {"uin3/min",        Unit::VolumeRate::CubicMicroinchPerMinute },
    {"mi^3/hr",         Unit::VolumeRate::CubicMilePerHour        },
    {"mi3/hr",          Unit::VolumeRate::CubicMilePerHour        },
    {"km^3/hr",         Unit::VolumeRate::CubicKilometrePerHour   },
    {"km3/hr",          Unit::VolumeRate::CubicKilometrePerHour   },
    {"m^3/hr",          Unit::VolumeRate::CubicMetrePerHour       },
    {"m3/hr",           Unit::VolumeRate::CubicMetrePerHour       },
    {"yd^3/hr",         Unit::VolumeRate::CubicYardPerHour        },
    {"yd3/hr",          Unit::VolumeRate::CubicYardPerHour        },
    {"ft^3/hr",         Unit::VolumeRate::CubicFootPerHour        },
    {"ft3/hr",          Unit::VolumeRate::CubicFootPerHour        },
    {"dm^3/hr",         Unit::VolumeRate::CubicDecimetrePerHour   },
    {"dm3/hr",          Unit::VolumeRate::CubicDecimetrePerHour   },
    {"L/hr",            Unit::VolumeRate::LitrePerHour            },
    {"in^3/hr",         Unit::VolumeRate::CubicInchPerHour        },
    {"in3/hr",          Unit::VolumeRate::CubicInchPerHour        },
    {"cm^3/hr",         Unit::VolumeRate::CubicCentimetrePerHour  },
    {"cm3/hr",          Unit::VolumeRate::CubicCentimetrePerHour  },
    {"mL/hr",           Unit::VolumeRate::MillilitrePerHour       },
    {"mm^3/hr",         Unit::VolumeRate::CubicMillimetrePerHour  },
    {"mm3/hr",          Unit::VolumeRate::CubicMillimetrePerHour  },
    {"millinch^3/hr",   Unit::VolumeRate::CubicMilliinchPerHour   },
    {"millinch3/hr",    Unit::VolumeRate::CubicMilliinchPerHour   },
    {"milliinch^3/hr",  Unit::VolumeRate::CubicMilliinchPerHour   },
    {"milliinch3/hr",   Unit::VolumeRate::CubicMilliinchPerHour   },
    {"mil^3/hr",        Unit::VolumeRate::CubicMilliinchPerHour   },
    {"mil3/hr",         Unit::VolumeRate::CubicMilliinchPerHour   },
    {"thou^3/hr",       Unit::VolumeRate::CubicMilliinchPerHour   },
    {"thou3/hr",        Unit::VolumeRate::CubicMilliinchPerHour   },
    {"μm^3/hr",         Unit::VolumeRate::CubicMicrometrePerHour  },
    {"μm3/hr",          Unit::VolumeRate::CubicMicrometrePerHour  },
    {"um^3/hr",         Unit::VolumeRate::CubicMicrometrePerHour  },
    {"um3/hr",          Unit::VolumeRate::CubicMicrometrePerHour  },
    {"μin^3/hr",        Unit::VolumeRate::CubicMicroinchPerHour   },
    {"μin3/hr",         Unit::VolumeRate::CubicMicroinchPerHour   },
    {"uin^3/hr",        Unit::VolumeRate::CubicMicroinchPerHour   },
    {"uin3/hr",         Unit::VolumeRate::CubicMicroinchPerHour   },
};

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>(
    double& value) noexcept {
  value /= 1609.344 * 1609.344 * 1609.344;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerSecond>(
    double& value) noexcept {
  value *= 0.000000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>(
    double& value) noexcept {
  value /= 0.9144 * 0.9144 * 0.9144;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>(
    double& value) noexcept {
  value /= 0.3048 * 0.3048 * 0.3048;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerSecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>(double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>(
    double& value) noexcept {
  value /= 0.0254 * 0.0254 * 0.0254;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerSecond>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerSecond>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerSecond>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerSecond>(
    double& value) noexcept {
  value /= 0.0000254 * 0.0000254 * 0.0000254;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerSecond>(
    double& value) noexcept {
  value *= 1.0e18;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerSecond>(
    double& value) noexcept {
  value /= 0.0000000254 * 0.0000000254 * 0.0000000254;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerMinute>(
    double& value) noexcept {
  value *= 60.0 / (1609.344 * 1609.344 * 1609.344);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerMinute>(
    double& value) noexcept {
  value *= 60.0 * 0.000000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerMinute>(
    double& value) noexcept {
  value *= 60.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerMinute>(
    double& value) noexcept {
  value *= 60.0 / (0.9144 * 0.9144 * 0.9144);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerMinute>(
    double& value) noexcept {
  value *= 60.0 / (0.3048 * 0.3048 * 0.3048);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerMinute>(
    double& value) noexcept {
  value *= 60.0 * 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerMinute>(double& value) noexcept {
  value *= 60.0 * 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerMinute>(
    double& value) noexcept {
  value *= 60.0 / (0.0254 * 0.0254 * 0.0254);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerMinute>(
    double& value) noexcept {
  value *= 60.0 * 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerMinute>(
    double& value) noexcept {
  value *= 60.0 * 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerMinute>(
    double& value) noexcept {
  value *= 60.0 * 1000000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerMinute>(
    double& value) noexcept {
  value *= 60.0 / (0.0000254 * 0.0000254 * 0.0000254);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerMinute>(
    double& value) noexcept {
  value *= 60.0 * 1.0e18;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerMinute>(
    double& value) noexcept {
  value *= 60.0 / (0.0000000254 * 0.0000000254 * 0.0000000254);
}

template <>
inline constexpr void ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerHour>(
    double& value) noexcept {
  value *= 3600.0 / (1609.344 * 1609.344 * 1609.344);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerHour>(
    double& value) noexcept {
  value *= 3600.0 * 0.000000001;
}

template <>
inline constexpr void ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerHour>(
    double& value) noexcept {
  value *= 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerHour>(
    double& value) noexcept {
  value *= 3600.0 / (0.9144 * 0.9144 * 0.9144);
}

template <>
inline constexpr void ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerHour>(
    double& value) noexcept {
  value *= 3600.0 / (0.3048 * 0.3048 * 0.3048);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerHour>(
    double& value) noexcept {
  value *= 3600.0 * 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>(double& value) noexcept {
  value *= 3600.0 * 1000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerHour>(
    double& value) noexcept {
  value *= 3600.0 / (0.0254 * 0.0254 * 0.0254);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerHour>(
    double& value) noexcept {
  value *= 3600.0 * 1000000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerHour>(
    double& value) noexcept {
  value *= 3600.0 * 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerHour>(
    double& value) noexcept {
  value *= 3600.0 * 1000000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerHour>(
    double& value) noexcept {
  value *= 3600.0 / (0.0000254 * 0.0000254 * 0.0000254);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerHour>(
    double& value) noexcept {
  value *= 3600.0 * 1.0e18;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerHour>(
    double& value) noexcept {
  value *= 3600.0 / (0.0000000254 * 0.0000000254 * 0.0000000254);
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>(
    double& value) noexcept {
  value *= 1609.344 * 1609.344 * 1609.344;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerSecond>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>(
    double& value) noexcept {
  value *= 0.9144 * 0.9144 * 0.9144;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>(
    double& value) noexcept {
  value *= 0.3048 * 0.3048 * 0.3048;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerSecond>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>(double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>(
    double& value) noexcept {
  value *= 0.0254 * 0.0254 * 0.0254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerSecond>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerSecond>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerSecond>(
    double& value) noexcept {
  value *= 0.000000001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerSecond>(
    double& value) noexcept {
  value *= 0.0000254 * 0.0000254 * 0.0000254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerSecond>(
    double& value) noexcept {
  value *= 1.0e-18;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerSecond>(
    double& value) noexcept {
  value *= 0.0000000254 * 0.0000000254 * 0.0000000254;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerMinute>(
    double& value) noexcept {
  value *= 1609.344 * 1609.344 * 1609.344 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerMinute>(
    double& value) noexcept {
  value *= 1000000000.0 / 60.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerMinute>(
    double& value) noexcept {
  value /= 60.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerMinute>(
    double& value) noexcept {
  value *= 0.9144 * 0.9144 * 0.9144 / 60.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerMinute>(
    double& value) noexcept {
  value *= 0.3048 * 0.3048 * 0.3048 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerMinute>(
    double& value) noexcept {
  value *= 0.001 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerMinute>(double& value) noexcept {
  value *= 0.001 / 60.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerMinute>(
    double& value) noexcept {
  value *= 0.0254 * 0.0254 * 0.0254 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerMinute>(
    double& value) noexcept {
  value *= 0.000001 / 60.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerMinute>(
    double& value) noexcept {
  value *= 0.000001 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerMinute>(
    double& value) noexcept {
  value *= 0.000000001 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerMinute>(
    double& value) noexcept {
  value *= 0.0000254 * 0.0000254 * 0.0000254 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerMinute>(
    double& value) noexcept {
  value *= 1.0e-18 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerMinute>(
    double& value) noexcept {
  value *= 0.0000000254 * 0.0000000254 * 0.0000000254 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerHour>(double& value) noexcept {
  value *= 1609.344 * 1609.344 * 1609.344 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerHour>(
    double& value) noexcept {
  value *= 1000000000.0 / 3600.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerHour>(
    double& value) noexcept {
  value /= 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerHour>(double& value) noexcept {
  value *= 0.9144 * 0.9144 * 0.9144 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerHour>(double& value) noexcept {
  value *= 0.3048 * 0.3048 * 0.3048 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerHour>(
    double& value) noexcept {
  value *= 0.001 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>(double& value) noexcept {
  value *= 0.001 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerHour>(double& value) noexcept {
  value *= 0.0254 * 0.0254 * 0.0254 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerHour>(
    double& value) noexcept {
  value *= 0.000001 / 3600.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerHour>(
    double& value) noexcept {
  value *= 0.000001 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerHour>(
    double& value) noexcept {
  value *= 0.000000001 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerHour>(
    double& value) noexcept {
  value *= 0.0000254 * 0.0000254 * 0.0000254 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerHour>(
    double& value) noexcept {
  value *= 1.0e-18 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerHour>(
    double& value) noexcept {
  value *= 0.0000000254 * 0.0000000254 * 0.0000000254 / 3600.0;
}

template <>
inline const std::map<Unit::VolumeRate, std::function<void(double* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::VolumeRate>{
        {Unit::VolumeRate::CubicMilePerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>      },
        {Unit::VolumeRate::CubicKilometrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerSecond> },
        {Unit::VolumeRate::CubicMetrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerSecond>     },
        {Unit::VolumeRate::CubicYardPerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>      },
        {Unit::VolumeRate::CubicFootPerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>      },
        {Unit::VolumeRate::CubicDecimetrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerSecond> },
        {Unit::VolumeRate::LitrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>          },
        {Unit::VolumeRate::CubicInchPerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>      },
        {Unit::VolumeRate::CubicCentimetrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerSecond>},
        {Unit::VolumeRate::MillilitrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerSecond>     },
        {Unit::VolumeRate::CubicMillimetrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerSecond>},
        {Unit::VolumeRate::CubicMilliinchPerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerSecond> },
        {Unit::VolumeRate::CubicMicrometrePerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerSecond>},
        {Unit::VolumeRate::CubicMicroinchPerSecond,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerSecond> },
        {Unit::VolumeRate::CubicMilePerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerMinute>      },
        {Unit::VolumeRate::CubicKilometrePerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerMinute> },
        {Unit::VolumeRate::CubicMetrePerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerMinute>     },
        {Unit::VolumeRate::CubicYardPerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerMinute>      },
        {Unit::VolumeRate::CubicFootPerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerMinute>      },
        {Unit::VolumeRate::CubicDecimetrePerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerMinute> },
        {Unit::VolumeRate::LitrePerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerMinute>          },
        {Unit::VolumeRate::CubicInchPerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerMinute>      },
        {Unit::VolumeRate::CubicCentimetrePerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerMinute>},
        {Unit::VolumeRate::MillilitrePerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerMinute>     },
        {Unit::VolumeRate::CubicMillimetrePerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerMinute>},
        {Unit::VolumeRate::CubicMilliinchPerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerMinute> },
        {Unit::VolumeRate::CubicMicrometrePerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerMinute>},
        {Unit::VolumeRate::CubicMicroinchPerMinute,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerMinute> },
        {Unit::VolumeRate::CubicMilePerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerHour>        },
        {Unit::VolumeRate::CubicKilometrePerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerHour>   },
        {Unit::VolumeRate::CubicMetrePerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerHour>       },
        {Unit::VolumeRate::CubicYardPerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerHour>        },
        {Unit::VolumeRate::CubicFootPerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerHour>        },
        {Unit::VolumeRate::CubicDecimetrePerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerHour>   },
        {Unit::VolumeRate::LitrePerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>            },
        {Unit::VolumeRate::CubicInchPerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerHour>        },
        {Unit::VolumeRate::CubicCentimetrePerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerHour>  },
        {Unit::VolumeRate::MillilitrePerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerHour>       },
        {Unit::VolumeRate::CubicMillimetrePerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerHour>  },
        {Unit::VolumeRate::CubicMilliinchPerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerHour>   },
        {Unit::VolumeRate::CubicMicrometrePerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerHour>  },
        {Unit::VolumeRate::CubicMicroinchPerHour,
         ConversionsFromStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerHour>   },
};

template <>
inline const std::map<Unit::VolumeRate, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::VolumeRate>{
        {Unit::VolumeRate::CubicMilePerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>      },
        {Unit::VolumeRate::CubicKilometrePerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerSecond> },
        {Unit::VolumeRate::CubicMetrePerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerSecond>     },
        {Unit::VolumeRate::CubicYardPerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>      },
        {Unit::VolumeRate::CubicFootPerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>      },
        {Unit::VolumeRate::CubicDecimetrePerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerSecond> },
        {Unit::VolumeRate::LitrePerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>          },
        {Unit::VolumeRate::CubicInchPerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>      },
        {Unit::VolumeRate::CubicCentimetrePerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerSecond>},
        {Unit::VolumeRate::MillilitrePerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerSecond>     },
        {Unit::VolumeRate::CubicMillimetrePerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerSecond>},
        {Unit::VolumeRate::CubicMilliinchPerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerSecond> },
        {Unit::VolumeRate::CubicMicrometrePerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerSecond>},
        {Unit::VolumeRate::CubicMicroinchPerSecond,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerSecond> },
        {Unit::VolumeRate::CubicMilePerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerMinute>      },
        {Unit::VolumeRate::CubicKilometrePerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerMinute> },
        {Unit::VolumeRate::CubicMetrePerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerMinute>     },
        {Unit::VolumeRate::CubicYardPerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerMinute>      },
        {Unit::VolumeRate::CubicFootPerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerMinute>      },
        {Unit::VolumeRate::CubicDecimetrePerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerMinute> },
        {Unit::VolumeRate::LitrePerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerMinute>          },
        {Unit::VolumeRate::CubicInchPerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerMinute>      },
        {Unit::VolumeRate::CubicCentimetrePerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerMinute>},
        {Unit::VolumeRate::MillilitrePerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerMinute>     },
        {Unit::VolumeRate::CubicMillimetrePerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerMinute>},
        {Unit::VolumeRate::CubicMilliinchPerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerMinute> },
        {Unit::VolumeRate::CubicMicrometrePerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerMinute>},
        {Unit::VolumeRate::CubicMicroinchPerMinute,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerMinute> },
        {Unit::VolumeRate::CubicMilePerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerHour>        },
        {Unit::VolumeRate::CubicKilometrePerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerHour>   },
        {Unit::VolumeRate::CubicMetrePerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerHour>       },
        {Unit::VolumeRate::CubicYardPerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerHour>        },
        {Unit::VolumeRate::CubicFootPerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerHour>        },
        {Unit::VolumeRate::CubicDecimetrePerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerHour>   },
        {Unit::VolumeRate::LitrePerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>            },
        {Unit::VolumeRate::CubicInchPerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerHour>        },
        {Unit::VolumeRate::CubicCentimetrePerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerHour>  },
        {Unit::VolumeRate::MillilitrePerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerHour>       },
        {Unit::VolumeRate::CubicMillimetrePerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerHour>  },
        {Unit::VolumeRate::CubicMilliinchPerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerHour>   },
        {Unit::VolumeRate::CubicMicrometrePerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerHour>  },
        {Unit::VolumeRate::CubicMicroinchPerHour,
         ConversionsToStandard<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerHour>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_RATE_HPP
