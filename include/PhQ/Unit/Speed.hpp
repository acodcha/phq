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

#ifndef PHQ_UNIT_SPEED_HPP
#define PHQ_UNIT_SPEED_HPP

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

// Speed units.
enum class Speed : int8_t {
  // Nautical mile per second (nmi/s) speed unit.
  NauticalMilePerSecond,

  // Nautical mile per minute (nmi/min) speed unit.
  NauticalMilePerMinute,

  // Knot (kn) speed unit, also known as nautical mile per hour.
  Knot,

  // Mile per second (mi/s) speed unit.
  MilePerSecond,

  // Mile per minute (mi/min) speed unit.
  MilePerMinute,

  // Mile per hour (mi/hr) speed unit.
  MilePerHour,

  // Kilometre per second (km/s) speed unit.
  KilometrePerSecond,

  // Kilometre per minute (km/min) speed unit.
  KilometrePerMinute,

  // Kilometre per hour (km/hr) speed unit.
  KilometrePerHour,

  // Metre per second (m/s) speed unit.
  MetrePerSecond,

  // Metre per minute (m/min) speed unit.
  MetrePerMinute,

  // Metre per hour (m/hr) speed unit.
  MetrePerHour,

  // Yard per second (yd/s) speed unit.
  YardPerSecond,

  // Yard per minute (yd/min) speed unit.
  YardPerMinute,

  // Yard per hour (yd/hr) speed unit.
  YardPerHour,

  // Foot per second (ft/s) speed unit.
  FootPerSecond,

  // Foot per minute (ft/min) speed unit.
  FootPerMinute,

  // Foot per hour (ft/hr) speed unit.
  FootPerHour,

  // Decimetre per second (dm/s) speed unit.
  DecimetrePerSecond,

  // Decimetre per minute (dm/min) speed unit.
  DecimetrePerMinute,

  // Decimetre per hour (dm/hr) speed unit.
  DecimetrePerHour,

  // Inch per second (in/s) speed unit.
  InchPerSecond,

  // Inch per minute (in/min) speed unit.
  InchPerMinute,

  // Inch per hour (in/hr) speed unit.
  InchPerHour,

  // Centimetre per second (cm/s) speed unit.
  CentimetrePerSecond,

  // Centimetre per minute (cm/min) speed unit.
  CentimetrePerMinute,

  // Centimetre per hour (cm/hr) speed unit.
  CentimetrePerHour,

  // Millimetre per second (mm/s) speed unit.
  MillimetrePerSecond,

  // Millimetre per minute (mm/min) speed unit.
  MillimetrePerMinute,

  // Millimetre per hour (mm/hr) speed unit.
  MillimetrePerHour,

  // Milliinch per second (mil/s) speed unit.
  MilliinchPerSecond,

  // Milliinch per minute (mil/min) speed unit.
  MilliinchPerMinute,

  // Milliinch per hour (mil/hr) speed unit.
  MilliinchPerHour,

  // Micrometre per second (μm/s) speed unit.
  MicrometrePerSecond,

  // Micrometre per minute (μm/min) speed unit.
  MicrometrePerMinute,

  // Micrometre per hour (μm/hr) speed unit.
  MicrometrePerHour,

  // Microinch per second (μin/s) speed unit.
  MicroinchPerSecond,

  // Microinch per minute (μin/min) speed unit.
  MicroinchPerMinute,

  // Microinch per hour (μin/hr) speed unit.
  MicroinchPerHour,
};

}  // namespace Unit

// Standard speed unit: metre per second (m/s).
template <>
inline constexpr const Unit::Speed Standard<Unit::Speed>{Unit::Speed::MetrePerSecond};

// Physical dimension set of speed units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Speed>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Speed unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Speed> ConsistentUnits<Unit::Speed>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Speed::MetrePerSecond     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Speed::MillimetrePerSecond},
    {UnitSystem::FootPoundSecondRankine,     Unit::Speed::FootPerSecond      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Speed::InchPerSecond      },
};

template <>
inline const std::map<Unit::Speed, UnitSystem> RelatedUnitSystems<Unit::Speed>{
    {Unit::Speed::MetrePerSecond,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Speed::MillimetrePerSecond, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Speed::FootPerSecond,       UnitSystem::FootPoundSecondRankine    },
    {Unit::Speed::InchPerSecond,       UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::Speed, std::string_view> Abbreviations<Unit::Speed>{
    {Unit::Speed::NauticalMilePerSecond, "nmi/s"  },
    {Unit::Speed::NauticalMilePerMinute, "nmi/min"},
    {Unit::Speed::Knot,                  "kn"     },
    {Unit::Speed::MilePerSecond,         "mi/s"   },
    {Unit::Speed::MilePerMinute,         "mi/min" },
    {Unit::Speed::MilePerHour,           "mi/hr"  },
    {Unit::Speed::KilometrePerSecond,    "km/s"   },
    {Unit::Speed::KilometrePerMinute,    "km/min" },
    {Unit::Speed::KilometrePerHour,      "km/hr"  },
    {Unit::Speed::MetrePerSecond,        "m/s"    },
    {Unit::Speed::MetrePerMinute,        "m/min"  },
    {Unit::Speed::MetrePerHour,          "m/hr"   },
    {Unit::Speed::YardPerSecond,         "yd/s"   },
    {Unit::Speed::YardPerMinute,         "yd/min" },
    {Unit::Speed::YardPerHour,           "yd/hr"  },
    {Unit::Speed::FootPerSecond,         "ft/s"   },
    {Unit::Speed::FootPerMinute,         "ft/min" },
    {Unit::Speed::FootPerHour,           "ft/hr"  },
    {Unit::Speed::DecimetrePerSecond,    "dm/s"   },
    {Unit::Speed::DecimetrePerMinute,    "dm/min" },
    {Unit::Speed::DecimetrePerHour,      "dm/hr"  },
    {Unit::Speed::InchPerSecond,         "in/s"   },
    {Unit::Speed::InchPerMinute,         "in/min" },
    {Unit::Speed::InchPerHour,           "in/hr"  },
    {Unit::Speed::CentimetrePerSecond,   "cm/s"   },
    {Unit::Speed::CentimetrePerMinute,   "cm/min" },
    {Unit::Speed::CentimetrePerHour,     "cm/hr"  },
    {Unit::Speed::MillimetrePerSecond,   "mm/s"   },
    {Unit::Speed::MillimetrePerMinute,   "mm/min" },
    {Unit::Speed::MillimetrePerHour,     "mm/hr"  },
    {Unit::Speed::MilliinchPerSecond,    "mil/s"  },
    {Unit::Speed::MilliinchPerMinute,    "mil/min"},
    {Unit::Speed::MilliinchPerHour,      "mil/hr" },
    {Unit::Speed::MicrometrePerSecond,   "μm/s"   },
    {Unit::Speed::MicrometrePerMinute,   "μm/min" },
    {Unit::Speed::MicrometrePerHour,     "μm/hr"  },
    {Unit::Speed::MicroinchPerSecond,    "μin/s"  },
    {Unit::Speed::MicroinchPerMinute,    "μin/min"},
    {Unit::Speed::MicroinchPerHour,      "μin/hr" },
};

template <>
inline const std::unordered_map<std::string_view, Unit::Speed> Spellings<Unit::Speed>{
    {"nmi/s",         Unit::Speed::NauticalMilePerSecond},
    {"nmi/min",       Unit::Speed::NauticalMilePerMinute},
    {"kn",            Unit::Speed::Knot                 },
    {"knot",          Unit::Speed::Knot                 },
    {"knots",         Unit::Speed::Knot                 },
    {"nmi/hr",        Unit::Speed::Knot                 },
    {"mi/s",          Unit::Speed::MilePerSecond        },
    {"mi/min",        Unit::Speed::MilePerMinute        },
    {"mi/hr",         Unit::Speed::MilePerHour          },
    {"km/s",          Unit::Speed::KilometrePerSecond   },
    {"km/min",        Unit::Speed::KilometrePerMinute   },
    {"km/hr",         Unit::Speed::KilometrePerHour     },
    {"m/s",           Unit::Speed::MetrePerSecond       },
    {"m/min",         Unit::Speed::MetrePerMinute       },
    {"m/hr",          Unit::Speed::MetrePerHour         },
    {"yd/s",          Unit::Speed::YardPerSecond        },
    {"yd/min",        Unit::Speed::YardPerMinute        },
    {"yd/hr",         Unit::Speed::YardPerHour          },
    {"ft/s",          Unit::Speed::FootPerSecond        },
    {"ft/min",        Unit::Speed::FootPerMinute        },
    {"ft/hr",         Unit::Speed::FootPerHour          },
    {"dm/s",          Unit::Speed::DecimetrePerSecond   },
    {"dm/min",        Unit::Speed::DecimetrePerMinute   },
    {"dm/hr",         Unit::Speed::DecimetrePerHour     },
    {"in/s",          Unit::Speed::InchPerSecond        },
    {"in/min",        Unit::Speed::InchPerMinute        },
    {"in/hr",         Unit::Speed::InchPerHour          },
    {"cm/s",          Unit::Speed::CentimetrePerSecond  },
    {"cm/min",        Unit::Speed::CentimetrePerMinute  },
    {"cm/hr",         Unit::Speed::CentimetrePerHour    },
    {"mm/s",          Unit::Speed::MillimetrePerSecond  },
    {"mm/min",        Unit::Speed::MillimetrePerMinute  },
    {"mm/hr",         Unit::Speed::MillimetrePerHour    },
    {"milin/s",       Unit::Speed::MilliinchPerSecond   },
    {"milin/min",     Unit::Speed::MilliinchPerMinute   },
    {"milin/hr",      Unit::Speed::MilliinchPerHour     },
    {"milliinch/s",   Unit::Speed::MilliinchPerSecond   },
    {"milliinch/min", Unit::Speed::MilliinchPerMinute   },
    {"milliinch/hr",  Unit::Speed::MilliinchPerHour     },
    {"mil/s",         Unit::Speed::MilliinchPerSecond   },
    {"mil/min",       Unit::Speed::MilliinchPerMinute   },
    {"mil/hr",        Unit::Speed::MilliinchPerHour     },
    {"thou/s",        Unit::Speed::MilliinchPerSecond   },
    {"thou/min",      Unit::Speed::MilliinchPerMinute   },
    {"thou/hr",       Unit::Speed::MilliinchPerHour     },
    {"μm/s",          Unit::Speed::MicrometrePerSecond  },
    {"μm/min",        Unit::Speed::MicrometrePerMinute  },
    {"μm/hr",         Unit::Speed::MicrometrePerHour    },
    {"um/s",          Unit::Speed::MicrometrePerSecond  },
    {"um/min",        Unit::Speed::MicrometrePerMinute  },
    {"um/hr",         Unit::Speed::MicrometrePerHour    },
    {"μin/s",         Unit::Speed::MicroinchPerSecond   },
    {"μin/min",       Unit::Speed::MicroinchPerMinute   },
    {"μin/hr",        Unit::Speed::MicroinchPerHour     },
    {"uin/s",         Unit::Speed::MicroinchPerSecond   },
    {"uin/min",       Unit::Speed::MicroinchPerMinute   },
    {"uin/hr",        Unit::Speed::MicroinchPerHour     },
};

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::NauticalMilePerSecond>(
    double& value) noexcept {
  value /= 1852.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::NauticalMilePerSecond>(
    double& value) noexcept {
  value *= 1852.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::NauticalMilePerMinute>(
    double& value) noexcept {
  value *= 60.0 / 1852.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::NauticalMilePerMinute>(
    double& value) noexcept {
  value *= 1852.0 / 60.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::Knot>(
    double& value) noexcept {
  value *= 3600.0 / 1852.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::Knot>(double& value) noexcept {
  value *= 1852.0 / 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MilePerSecond>(
    double& value) noexcept {
  value /= 1609.344;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MilePerSecond>(
    double& value) noexcept {
  value *= 1609.344;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MilePerMinute>(
    double& value) noexcept {
  value *= 60.0 / 1609.344;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MilePerMinute>(
    double& value) noexcept {
  value *= 1609.344 / 60.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MilePerHour>(
    double& value) noexcept {
  value *= 3600.0 / 1609.344;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MilePerHour>(
    double& value) noexcept {
  value *= 1609.344 / 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::KilometrePerSecond>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::KilometrePerSecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::KilometrePerMinute>(
    double& value) noexcept {
  value *= 0.06;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::KilometrePerMinute>(
    double& value) noexcept {
  value *= 1000.0 / 60.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::KilometrePerHour>(
    double& value) noexcept {
  value *= 3.6;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::KilometrePerHour>(
    double& value) noexcept {
  value *= 1000.0 / 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MetrePerSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MetrePerSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MetrePerMinute>(
    double& value) noexcept {
  value *= 60.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MetrePerMinute>(
    double& value) noexcept {
  value /= 60.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MetrePerHour>(
    double& value) noexcept {
  value *= 3600.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MetrePerHour>(
    double& value) noexcept {
  value /= 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::YardPerSecond>(
    double& value) noexcept {
  value /= 0.9144;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::YardPerSecond>(
    double& value) noexcept {
  value *= 0.9144;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::YardPerMinute>(
    double& value) noexcept {
  value *= 60.0 / 0.9144;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::YardPerMinute>(
    double& value) noexcept {
  value *= 0.9144 / 60.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::YardPerHour>(
    double& value) noexcept {
  value *= 3600.0 / 0.9144;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::YardPerHour>(
    double& value) noexcept {
  value *= 0.9144 / 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::FootPerSecond>(
    double& value) noexcept {
  value /= 0.3048;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::FootPerSecond>(
    double& value) noexcept {
  value *= 0.3048;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::FootPerMinute>(
    double& value) noexcept {
  value *= 60.0 / 0.3048;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::FootPerMinute>(
    double& value) noexcept {
  value *= 0.3048 / 60.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::FootPerHour>(
    double& value) noexcept {
  value *= 3600.0 / 0.3048;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::FootPerHour>(
    double& value) noexcept {
  value *= 0.3048 / 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::DecimetrePerSecond>(
    double& value) noexcept {
  value *= 10.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::DecimetrePerSecond>(
    double& value) noexcept {
  value *= 0.1;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::DecimetrePerMinute>(
    double& value) noexcept {
  value *= 600.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::DecimetrePerMinute>(
    double& value) noexcept {
  value /= 600.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::DecimetrePerHour>(
    double& value) noexcept {
  value *= 36000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::DecimetrePerHour>(
    double& value) noexcept {
  value /= 36000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::InchPerSecond>(
    double& value) noexcept {
  value /= 0.0254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::InchPerSecond>(
    double& value) noexcept {
  value *= 0.0254;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::InchPerMinute>(
    double& value) noexcept {
  value *= 60.0 / 0.0254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::InchPerMinute>(
    double& value) noexcept {
  value *= 0.0254 / 60.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::InchPerHour>(
    double& value) noexcept {
  value *= 3600.0 / 0.0254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::InchPerHour>(
    double& value) noexcept {
  value *= 0.0254 / 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::CentimetrePerSecond>(
    double& value) noexcept {
  value *= 100.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::CentimetrePerSecond>(
    double& value) noexcept {
  value *= 0.01;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::CentimetrePerMinute>(
    double& value) noexcept {
  value *= 6000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::CentimetrePerMinute>(
    double& value) noexcept {
  value /= 6000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::CentimetrePerHour>(
    double& value) noexcept {
  value *= 360000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::CentimetrePerHour>(
    double& value) noexcept {
  value /= 360000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MillimetrePerSecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MillimetrePerSecond>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MillimetrePerMinute>(
    double& value) noexcept {
  value *= 60000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MillimetrePerMinute>(
    double& value) noexcept {
  value /= 60000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MillimetrePerHour>(
    double& value) noexcept {
  value *= 3600000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MillimetrePerHour>(
    double& value) noexcept {
  value /= 3600000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MilliinchPerSecond>(
    double& value) noexcept {
  value /= 0.0000254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MilliinchPerSecond>(
    double& value) noexcept {
  value *= 0.0000254;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MilliinchPerMinute>(
    double& value) noexcept {
  value *= 60.0 / 0.0000254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MilliinchPerMinute>(
    double& value) noexcept {
  value *= 0.0000254 / 60.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MilliinchPerHour>(
    double& value) noexcept {
  value *= 3600.0 / 0.0000254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MilliinchPerHour>(
    double& value) noexcept {
  value *= 0.0000254 / 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MicrometrePerSecond>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MicrometrePerSecond>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MicrometrePerMinute>(
    double& value) noexcept {
  value *= 60000000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MicrometrePerMinute>(
    double& value) noexcept {
  value /= 60000000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MicrometrePerHour>(
    double& value) noexcept {
  value *= 3600000000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MicrometrePerHour>(
    double& value) noexcept {
  value /= 3600000000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MicroinchPerSecond>(
    double& value) noexcept {
  value /= 0.0000000254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MicroinchPerSecond>(
    double& value) noexcept {
  value *= 0.0000000254;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MicroinchPerMinute>(
    double& value) noexcept {
  value *= 60.0 / 0.0000000254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MicroinchPerMinute>(
    double& value) noexcept {
  value *= 0.0000000254 / 60.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Speed, Unit::Speed::MicroinchPerHour>(
    double& value) noexcept {
  value *= 3600.0 / 0.0000000254;
}

template <>
inline constexpr void ConversionToStandard<Unit::Speed, Unit::Speed::MicroinchPerHour>(
    double& value) noexcept {
  value *= 0.0000000254 / 3600.0;
}

template <>
inline const std::map<Unit::Speed, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Speed, double>{
        {Unit::Speed::NauticalMilePerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::NauticalMilePerSecond, double>},
        {Unit::Speed::NauticalMilePerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::NauticalMilePerMinute, double>},
        {Unit::Speed::Knot,                  ConversionsFromStandard<Unit::Speed, Unit::Speed::Knot,                  double>},
        {Unit::Speed::MilePerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MilePerSecond,         double>},
        {Unit::Speed::MilePerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MilePerMinute,         double>},
        {Unit::Speed::MilePerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MilePerHour,           double>},
        {Unit::Speed::KilometrePerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::KilometrePerSecond,    double>},
        {Unit::Speed::KilometrePerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::KilometrePerMinute,    double>},
        {Unit::Speed::KilometrePerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::KilometrePerHour,      double>},
        {Unit::Speed::MetrePerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MetrePerSecond,        double>},
        {Unit::Speed::MetrePerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MetrePerMinute,        double>},
        {Unit::Speed::MetrePerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MetrePerHour,          double>},
        {Unit::Speed::YardPerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::YardPerSecond,         double>},
        {Unit::Speed::YardPerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::YardPerMinute,         double>},
        {Unit::Speed::YardPerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::YardPerHour,           double>},
        {Unit::Speed::FootPerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::FootPerSecond,         double>},
        {Unit::Speed::FootPerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::FootPerMinute,         double>},
        {Unit::Speed::FootPerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::FootPerHour,           double>},
        {Unit::Speed::DecimetrePerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::DecimetrePerSecond,    double>},
        {Unit::Speed::DecimetrePerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::DecimetrePerMinute,    double>},
        {Unit::Speed::DecimetrePerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::DecimetrePerHour,      double>},
        {Unit::Speed::InchPerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::InchPerSecond,         double>},
        {Unit::Speed::InchPerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::InchPerMinute,         double>},
        {Unit::Speed::InchPerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::InchPerHour,           double>},
        {Unit::Speed::CentimetrePerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::CentimetrePerSecond,   double>},
        {Unit::Speed::CentimetrePerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::CentimetrePerMinute,   double>},
        {Unit::Speed::CentimetrePerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::CentimetrePerHour,     double>},
        {Unit::Speed::MillimetrePerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MillimetrePerSecond,   double>},
        {Unit::Speed::MillimetrePerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MillimetrePerMinute,   double>},
        {Unit::Speed::MillimetrePerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MillimetrePerHour,     double>},
        {Unit::Speed::MilliinchPerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MilliinchPerSecond,    double>},
        {Unit::Speed::MilliinchPerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MilliinchPerMinute,    double>},
        {Unit::Speed::MilliinchPerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MilliinchPerHour,      double>},
        {Unit::Speed::MicrometrePerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MicrometrePerSecond,   double>},
        {Unit::Speed::MicrometrePerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MicrometrePerMinute,   double>},
        {Unit::Speed::MicrometrePerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MicrometrePerHour,     double>},
        {Unit::Speed::MicroinchPerSecond,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MicroinchPerSecond,    double>},
        {Unit::Speed::MicroinchPerMinute,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MicroinchPerMinute,    double>},
        {Unit::Speed::MicroinchPerHour,
         ConversionsFromStandard<Unit::Speed,                                     Unit::Speed::MicroinchPerHour,      double>},
};

template <>
inline const std::map<Unit::Speed,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Speed, double>{
        {Unit::Speed::NauticalMilePerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::NauticalMilePerSecond, double>},
        {Unit::Speed::NauticalMilePerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::NauticalMilePerMinute, double>},
        {Unit::Speed::Knot,                  ConversionsToStandard<Unit::Speed, Unit::Speed::Knot,                  double>},
        {Unit::Speed::MilePerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MilePerSecond,         double>},
        {Unit::Speed::MilePerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MilePerMinute,         double>},
        {Unit::Speed::MilePerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MilePerHour,           double>},
        {Unit::Speed::KilometrePerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::KilometrePerSecond,    double>},
        {Unit::Speed::KilometrePerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::KilometrePerMinute,    double>},
        {Unit::Speed::KilometrePerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::KilometrePerHour,      double>},
        {Unit::Speed::MetrePerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MetrePerSecond,        double>},
        {Unit::Speed::MetrePerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MetrePerMinute,        double>},
        {Unit::Speed::MetrePerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MetrePerHour,          double>},
        {Unit::Speed::YardPerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::YardPerSecond,         double>},
        {Unit::Speed::YardPerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::YardPerMinute,         double>},
        {Unit::Speed::YardPerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::YardPerHour,           double>},
        {Unit::Speed::FootPerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::FootPerSecond,         double>},
        {Unit::Speed::FootPerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::FootPerMinute,         double>},
        {Unit::Speed::FootPerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::FootPerHour,           double>},
        {Unit::Speed::DecimetrePerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::DecimetrePerSecond,    double>},
        {Unit::Speed::DecimetrePerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::DecimetrePerMinute,    double>},
        {Unit::Speed::DecimetrePerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::DecimetrePerHour,      double>},
        {Unit::Speed::InchPerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::InchPerSecond,         double>},
        {Unit::Speed::InchPerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::InchPerMinute,         double>},
        {Unit::Speed::InchPerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::InchPerHour,           double>},
        {Unit::Speed::CentimetrePerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::CentimetrePerSecond,   double>},
        {Unit::Speed::CentimetrePerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::CentimetrePerMinute,   double>},
        {Unit::Speed::CentimetrePerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::CentimetrePerHour,     double>},
        {Unit::Speed::MillimetrePerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MillimetrePerSecond,   double>},
        {Unit::Speed::MillimetrePerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MillimetrePerMinute,   double>},
        {Unit::Speed::MillimetrePerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MillimetrePerHour,     double>},
        {Unit::Speed::MilliinchPerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MilliinchPerSecond,    double>},
        {Unit::Speed::MilliinchPerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MilliinchPerMinute,    double>},
        {Unit::Speed::MilliinchPerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MilliinchPerHour,      double>},
        {Unit::Speed::MicrometrePerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MicrometrePerSecond,   double>},
        {Unit::Speed::MicrometrePerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MicrometrePerMinute,   double>},
        {Unit::Speed::MicrometrePerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MicrometrePerHour,     double>},
        {Unit::Speed::MicroinchPerSecond,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MicroinchPerSecond,    double>},
        {Unit::Speed::MicroinchPerMinute,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MicroinchPerMinute,    double>},
        {Unit::Speed::MicroinchPerHour,
         ConversionsToStandard<Unit::Speed,                                     Unit::Speed::MicroinchPerHour,      double>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_SPEED_HPP
