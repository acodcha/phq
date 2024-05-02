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

#ifndef PHQ_UNIT_ACCELERATION_HPP
#define PHQ_UNIT_ACCELERATION_HPP

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

// Acceleration units.
enum class Acceleration : int8_t {
  // Nautical mile per square second (nmi/s^2) acceleration unit.
  NauticalMilePerSquareSecond,

  // Nautical mile per square minute (nmi/min^2) acceleration unit.
  NauticalMilePerSquareMinute,

  // Knot per hour (kn/hr) acceleration unit, also known as nautical mile per square hour.
  KnotPerHour,

  // Mile per square second (mi/s^2) acceleration unit.
  MilePerSquareSecond,

  // Mile per square minute (mi/min^2) acceleration unit.
  MilePerSquareMinute,

  // Mile per square hour (mi/hr^2) acceleration unit.
  MilePerSquareHour,

  // Kilometre per square second (km/s^2) acceleration unit.
  KilometrePerSquareSecond,

  // Kilometre per square minute (km/min^2) acceleration unit.
  KilometrePerSquareMinute,

  // Kilometre per square hour (km/hr^2) acceleration unit.
  KilometrePerSquareHour,

  // Metre per square second (m/s^2) acceleration unit.
  MetrePerSquareSecond,

  // Metre per square minute (m/min^2) acceleration unit.
  MetrePerSquareMinute,

  // Metre per square hour (m/hr^2) acceleration unit.
  MetrePerSquareHour,

  // Yard per square second (yd/s^2) acceleration unit.
  YardPerSquareSecond,

  // Yard per square minute (yd/min^2) acceleration unit.
  YardPerSquareMinute,

  // Yard per square hour (yd/hr^2) acceleration unit.
  YardPerSquareHour,

  // Foot per square second (ft/s^2) acceleration unit.
  FootPerSquareSecond,

  // Foot per square minute (ft/min^2) acceleration unit.
  FootPerSquareMinute,

  // Foot per square hour (ft/hr^2) acceleration unit.
  FootPerSquareHour,

  // Decimetre per square second (dm/s^2) acceleration unit.
  DecimetrePerSquareSecond,

  // Decimetre per square minute (dm/min^2) acceleration unit.
  DecimetrePerSquareMinute,

  // Decimetre per square hour (dm/hr^2) acceleration unit.
  DecimetrePerSquareHour,

  // Inch per square second (in/s^2) acceleration unit.
  InchPerSquareSecond,

  // Inch per square minute (in/min^2) acceleration unit.
  InchPerSquareMinute,

  // Inch per square hour (in/hr^2) acceleration unit.
  InchPerSquareHour,

  // Centimetre per square second (cm/s^2) acceleration unit.
  CentimetrePerSquareSecond,

  // Centimetre per square minute (cm/min^2) acceleration unit.
  CentimetrePerSquareMinute,

  // Centimetre per square hour (cm/hr^2) acceleration unit.
  CentimetrePerSquareHour,

  // Millimetre per square second (mm/s^2) acceleration unit.
  MillimetrePerSquareSecond,

  // Millimetre per square minute (mm/min^2) acceleration unit.
  MillimetrePerSquareMinute,

  // Millimetre per square hour (mm/hr^2) acceleration unit.
  MillimetrePerSquareHour,

  // Milliinch per square second (mil/s^2) acceleration unit.
  MilliinchPerSquareSecond,

  // Milliinch per square minute (mil/min^2) acceleration unit.
  MilliinchPerSquareMinute,

  // Milliinch per square hour (mil/hr^2) acceleration unit.
  MilliinchPerSquareHour,

  // Micrometre per square second (μm/s^2) acceleration unit.
  MicrometrePerSquareSecond,

  // Micrometre per square minute (μm/min^2) acceleration unit.
  MicrometrePerSquareMinute,

  // Micrometre per square hour (μm/hr^2) acceleration unit.
  MicrometrePerSquareHour,

  // Microinch per square second (μin/s^2) acceleration unit.
  MicroinchPerSquareSecond,

  // Microinch per square minute (μin/min^2) acceleration unit.
  MicroinchPerSquareMinute,

  // Microinch per square hour (μin/hr^2) acceleration unit.
  MicroinchPerSquareHour,
};

}  // namespace Unit

// Standard acceleration unit: metre per square second (m/s^2).
template <>
inline constexpr const Unit::Acceleration Standard<Unit::Acceleration>{
    Unit::Acceleration::MetrePerSquareSecond};

// Physical dimension set of acceleration units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Acceleration>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Acceleration unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Acceleration> ConsistentUnits<Unit::Acceleration>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Acceleration::MetrePerSquareSecond     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Acceleration::MillimetrePerSquareSecond},
    {UnitSystem::FootPoundSecondRankine,     Unit::Acceleration::FootPerSquareSecond      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Acceleration::InchPerSquareSecond      },
};

template <>
inline const std::map<Unit::Acceleration, UnitSystem> RelatedUnitSystems<Unit::Acceleration>{
    {Unit::Acceleration::MetrePerSquareSecond,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Acceleration::MillimetrePerSquareSecond, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Acceleration::FootPerSquareSecond,       UnitSystem::FootPoundSecondRankine    },
    {Unit::Acceleration::InchPerSquareSecond,       UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::Acceleration, std::string_view> Abbreviations<Unit::Acceleration>{
    {Unit::Acceleration::NauticalMilePerSquareSecond, "nmi/s^2"  },
    {Unit::Acceleration::NauticalMilePerSquareMinute, "nmi/min^2"},
    {Unit::Acceleration::KnotPerHour,                 "kn/hr"    },
    {Unit::Acceleration::MilePerSquareSecond,         "mi/s^2"   },
    {Unit::Acceleration::MilePerSquareMinute,         "mi/min^2" },
    {Unit::Acceleration::MilePerSquareHour,           "mi/hr^2"  },
    {Unit::Acceleration::KilometrePerSquareSecond,    "km/s^2"   },
    {Unit::Acceleration::KilometrePerSquareMinute,    "km/min^2" },
    {Unit::Acceleration::KilometrePerSquareHour,      "km/hr^2"  },
    {Unit::Acceleration::YardPerSquareSecond,         "yd/s^2"   },
    {Unit::Acceleration::YardPerSquareMinute,         "yd/min^2" },
    {Unit::Acceleration::YardPerSquareHour,           "yd/hr^2"  },
    {Unit::Acceleration::MetrePerSquareSecond,        "m/s^2"    },
    {Unit::Acceleration::MetrePerSquareMinute,        "m/min^2"  },
    {Unit::Acceleration::MetrePerSquareHour,          "m/hr^2"   },
    {Unit::Acceleration::FootPerSquareSecond,         "ft/s^2"   },
    {Unit::Acceleration::FootPerSquareMinute,         "ft/min^2" },
    {Unit::Acceleration::FootPerSquareHour,           "ft/hr^2"  },
    {Unit::Acceleration::DecimetrePerSquareSecond,    "dm/s^2"   },
    {Unit::Acceleration::DecimetrePerSquareMinute,    "dm/min^2" },
    {Unit::Acceleration::DecimetrePerSquareHour,      "dm/hr^2"  },
    {Unit::Acceleration::InchPerSquareSecond,         "in/s^2"   },
    {Unit::Acceleration::InchPerSquareMinute,         "in/min^2" },
    {Unit::Acceleration::InchPerSquareHour,           "in/hr^2"  },
    {Unit::Acceleration::CentimetrePerSquareSecond,   "cm/s^2"   },
    {Unit::Acceleration::CentimetrePerSquareMinute,   "cm/min^2" },
    {Unit::Acceleration::CentimetrePerSquareHour,     "cm/hr^2"  },
    {Unit::Acceleration::MillimetrePerSquareSecond,   "mm/s^2"   },
    {Unit::Acceleration::MillimetrePerSquareMinute,   "mm/min^2" },
    {Unit::Acceleration::MillimetrePerSquareHour,     "mm/hr^2"  },
    {Unit::Acceleration::MilliinchPerSquareSecond,    "mil/s^2"  },
    {Unit::Acceleration::MilliinchPerSquareMinute,    "mil/min^2"},
    {Unit::Acceleration::MilliinchPerSquareHour,      "mil/hr^2" },
    {Unit::Acceleration::MicrometrePerSquareSecond,   "μm/s^2"   },
    {Unit::Acceleration::MicrometrePerSquareMinute,   "μm/min^2" },
    {Unit::Acceleration::MicrometrePerSquareHour,     "μm/hr^2"  },
    {Unit::Acceleration::MicroinchPerSquareSecond,    "μin/s^2"  },
    {Unit::Acceleration::MicroinchPerSquareMinute,    "μin/min^2"},
    {Unit::Acceleration::MicroinchPerSquareHour,      "μin/hr^2" },
};

template <>
inline const std::unordered_map<std::string_view, Unit::Acceleration> Spellings<Unit::Acceleration>{
    {"nmi/s^2",           Unit::Acceleration::NauticalMilePerSquareSecond},
    {"nmi/s2",            Unit::Acceleration::NauticalMilePerSquareSecond},
    {"nmi/s/s",           Unit::Acceleration::NauticalMilePerSquareSecond},
    {"nmi/min^2",         Unit::Acceleration::NauticalMilePerSquareMinute},
    {"nmi/min2",          Unit::Acceleration::NauticalMilePerSquareMinute},
    {"nmi/min/min",       Unit::Acceleration::NauticalMilePerSquareMinute},
    {"kn/hr",             Unit::Acceleration::KnotPerHour                },
    {"nmi/hr^2",          Unit::Acceleration::KnotPerHour                },
    {"nmi/hr2",           Unit::Acceleration::KnotPerHour                },
    {"nmi/hr/hr",         Unit::Acceleration::KnotPerHour                },
    {"mi/s^2",            Unit::Acceleration::MilePerSquareSecond        },
    {"mi/s2",             Unit::Acceleration::MilePerSquareSecond        },
    {"mi/s/s",            Unit::Acceleration::MilePerSquareSecond        },
    {"mi/min^2",          Unit::Acceleration::MilePerSquareMinute        },
    {"mi/min2",           Unit::Acceleration::MilePerSquareMinute        },
    {"mi/min/min",        Unit::Acceleration::MilePerSquareMinute        },
    {"mi/hr^2",           Unit::Acceleration::MilePerSquareHour          },
    {"mi/hr2",            Unit::Acceleration::MilePerSquareHour          },
    {"mi/hr/hr",          Unit::Acceleration::MilePerSquareHour          },
    {"km/s^2",            Unit::Acceleration::KilometrePerSquareSecond   },
    {"km/s2",             Unit::Acceleration::KilometrePerSquareSecond   },
    {"km/s/s",            Unit::Acceleration::KilometrePerSquareSecond   },
    {"km/min^2",          Unit::Acceleration::KilometrePerSquareMinute   },
    {"km/min2",           Unit::Acceleration::KilometrePerSquareMinute   },
    {"km/min/min",        Unit::Acceleration::KilometrePerSquareMinute   },
    {"km/hr^2",           Unit::Acceleration::KilometrePerSquareHour     },
    {"km/hr2",            Unit::Acceleration::KilometrePerSquareHour     },
    {"km/hr/hr",          Unit::Acceleration::KilometrePerSquareHour     },
    {"yd/s^2",            Unit::Acceleration::YardPerSquareSecond        },
    {"yd/s2",             Unit::Acceleration::YardPerSquareSecond        },
    {"yd/s/s",            Unit::Acceleration::YardPerSquareSecond        },
    {"yd/min^2",          Unit::Acceleration::YardPerSquareMinute        },
    {"yd/min2",           Unit::Acceleration::YardPerSquareMinute        },
    {"yd/min/min",        Unit::Acceleration::YardPerSquareMinute        },
    {"yd/hr^2",           Unit::Acceleration::YardPerSquareHour          },
    {"yd/hr2",            Unit::Acceleration::YardPerSquareHour          },
    {"yd/hr/hr",          Unit::Acceleration::YardPerSquareHour          },
    {"m/s^2",             Unit::Acceleration::MetrePerSquareSecond       },
    {"m/s2",              Unit::Acceleration::MetrePerSquareSecond       },
    {"m/s/s",             Unit::Acceleration::MetrePerSquareSecond       },
    {"m/min^2",           Unit::Acceleration::MetrePerSquareMinute       },
    {"m/min2",            Unit::Acceleration::MetrePerSquareMinute       },
    {"m/min/min",         Unit::Acceleration::MetrePerSquareMinute       },
    {"m/hr^2",            Unit::Acceleration::MetrePerSquareHour         },
    {"m/hr2",             Unit::Acceleration::MetrePerSquareHour         },
    {"m/hr/hr",           Unit::Acceleration::MetrePerSquareHour         },
    {"ft/s^2",            Unit::Acceleration::FootPerSquareSecond        },
    {"ft/s2",             Unit::Acceleration::FootPerSquareSecond        },
    {"ft/s/s",            Unit::Acceleration::FootPerSquareSecond        },
    {"ft/min^2",          Unit::Acceleration::FootPerSquareMinute        },
    {"ft/min2",           Unit::Acceleration::FootPerSquareMinute        },
    {"ft/min/min",        Unit::Acceleration::FootPerSquareMinute        },
    {"ft/hr^2",           Unit::Acceleration::FootPerSquareHour          },
    {"ft/hr2",            Unit::Acceleration::FootPerSquareHour          },
    {"ft/hr/hr",          Unit::Acceleration::FootPerSquareHour          },
    {"dm/s^2",            Unit::Acceleration::DecimetrePerSquareSecond   },
    {"dm/s2",             Unit::Acceleration::DecimetrePerSquareSecond   },
    {"dm/s/s",            Unit::Acceleration::DecimetrePerSquareSecond   },
    {"dm/min^2",          Unit::Acceleration::DecimetrePerSquareMinute   },
    {"dm/min2",           Unit::Acceleration::DecimetrePerSquareMinute   },
    {"dm/min/min",        Unit::Acceleration::DecimetrePerSquareMinute   },
    {"dm/hr^2",           Unit::Acceleration::DecimetrePerSquareHour     },
    {"dm/hr2",            Unit::Acceleration::DecimetrePerSquareHour     },
    {"dm/hr/hr",          Unit::Acceleration::DecimetrePerSquareHour     },
    {"in/s^2",            Unit::Acceleration::InchPerSquareSecond        },
    {"in/s2",             Unit::Acceleration::InchPerSquareSecond        },
    {"in/s/s",            Unit::Acceleration::InchPerSquareSecond        },
    {"in/min^2",          Unit::Acceleration::InchPerSquareMinute        },
    {"in/min2",           Unit::Acceleration::InchPerSquareMinute        },
    {"in/min/min",        Unit::Acceleration::InchPerSquareMinute        },
    {"in/hr^2",           Unit::Acceleration::InchPerSquareHour          },
    {"in/hr2",            Unit::Acceleration::InchPerSquareHour          },
    {"in/hr/hr",          Unit::Acceleration::InchPerSquareHour          },
    {"cm/s^2",            Unit::Acceleration::CentimetrePerSquareSecond  },
    {"cm/s2",             Unit::Acceleration::CentimetrePerSquareSecond  },
    {"cm/s/s",            Unit::Acceleration::CentimetrePerSquareSecond  },
    {"cm/min^2",          Unit::Acceleration::CentimetrePerSquareMinute  },
    {"cm/min2",           Unit::Acceleration::CentimetrePerSquareMinute  },
    {"cm/min/min",        Unit::Acceleration::CentimetrePerSquareMinute  },
    {"cm/hr^2",           Unit::Acceleration::CentimetrePerSquareHour    },
    {"cm/hr2",            Unit::Acceleration::CentimetrePerSquareHour    },
    {"cm/hr/hr",          Unit::Acceleration::CentimetrePerSquareHour    },
    {"mm/s^2",            Unit::Acceleration::MillimetrePerSquareSecond  },
    {"mm/s2",             Unit::Acceleration::MillimetrePerSquareSecond  },
    {"mm/s/s",            Unit::Acceleration::MillimetrePerSquareSecond  },
    {"mm/min^2",          Unit::Acceleration::MillimetrePerSquareMinute  },
    {"mm/min2",           Unit::Acceleration::MillimetrePerSquareMinute  },
    {"mm/min/min",        Unit::Acceleration::MillimetrePerSquareMinute  },
    {"mm/hr^2",           Unit::Acceleration::MillimetrePerSquareHour    },
    {"mm/hr2",            Unit::Acceleration::MillimetrePerSquareHour    },
    {"mm/hr/hr",          Unit::Acceleration::MillimetrePerSquareHour    },
    {"milin/s^2",         Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milin/s2",          Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milin/s/s",         Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milliinch/s^2",     Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milliinch/s2",      Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milliinch/s/s",     Unit::Acceleration::MilliinchPerSquareSecond   },
    {"mil/s^2",           Unit::Acceleration::MilliinchPerSquareSecond   },
    {"mil/s2",            Unit::Acceleration::MilliinchPerSquareSecond   },
    {"mil/s/s",           Unit::Acceleration::MilliinchPerSquareSecond   },
    {"thou/s^2",          Unit::Acceleration::MilliinchPerSquareSecond   },
    {"thou/s2",           Unit::Acceleration::MilliinchPerSquareSecond   },
    {"thou/s/s",          Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milin/min^2",       Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milin/min2",        Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milin/min/min",     Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milliinch/min^2",   Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milliinch/min2",    Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milliinch/min/min", Unit::Acceleration::MilliinchPerSquareMinute   },
    {"mil/min^2",         Unit::Acceleration::MilliinchPerSquareMinute   },
    {"mil/min2",          Unit::Acceleration::MilliinchPerSquareMinute   },
    {"mil/min/min",       Unit::Acceleration::MilliinchPerSquareMinute   },
    {"thou/min^2",        Unit::Acceleration::MilliinchPerSquareMinute   },
    {"thou/min2",         Unit::Acceleration::MilliinchPerSquareMinute   },
    {"thou/min/min",      Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milin/hr^2",        Unit::Acceleration::MilliinchPerSquareHour     },
    {"milin/hr2",         Unit::Acceleration::MilliinchPerSquareHour     },
    {"milin/hr/hr",       Unit::Acceleration::MilliinchPerSquareHour     },
    {"milliinch/hr^2",    Unit::Acceleration::MilliinchPerSquareHour     },
    {"milliinch/hr2",     Unit::Acceleration::MilliinchPerSquareHour     },
    {"milliinch/hr/hr",   Unit::Acceleration::MilliinchPerSquareHour     },
    {"mil/hr^2",          Unit::Acceleration::MilliinchPerSquareHour     },
    {"mil/hr2",           Unit::Acceleration::MilliinchPerSquareHour     },
    {"mil/hr/hr",         Unit::Acceleration::MilliinchPerSquareHour     },
    {"thou/hr^2",         Unit::Acceleration::MilliinchPerSquareHour     },
    {"thou/hr2",          Unit::Acceleration::MilliinchPerSquareHour     },
    {"thou/hr/hr",        Unit::Acceleration::MilliinchPerSquareHour     },
    {"μm/s^2",            Unit::Acceleration::MicrometrePerSquareSecond  },
    {"μm/s2",             Unit::Acceleration::MicrometrePerSquareSecond  },
    {"μm/s/s",            Unit::Acceleration::MicrometrePerSquareSecond  },
    {"um/s^2",            Unit::Acceleration::MicrometrePerSquareSecond  },
    {"um/s2",             Unit::Acceleration::MicrometrePerSquareSecond  },
    {"um/s/s",            Unit::Acceleration::MicrometrePerSquareSecond  },
    {"μm/min^2",          Unit::Acceleration::MicrometrePerSquareMinute  },
    {"μm/min2",           Unit::Acceleration::MicrometrePerSquareMinute  },
    {"μm/min/min",        Unit::Acceleration::MicrometrePerSquareMinute  },
    {"um/min^2",          Unit::Acceleration::MicrometrePerSquareMinute  },
    {"um/min2",           Unit::Acceleration::MicrometrePerSquareMinute  },
    {"um/min/min",        Unit::Acceleration::MicrometrePerSquareMinute  },
    {"μm/hr^2",           Unit::Acceleration::MicrometrePerSquareHour    },
    {"μm/hr2",            Unit::Acceleration::MicrometrePerSquareHour    },
    {"μm/hr/hr",          Unit::Acceleration::MicrometrePerSquareHour    },
    {"um/hr^2",           Unit::Acceleration::MicrometrePerSquareHour    },
    {"um/hr2",            Unit::Acceleration::MicrometrePerSquareHour    },
    {"um/hr/hr",          Unit::Acceleration::MicrometrePerSquareHour    },
    {"μin/s^2",           Unit::Acceleration::MicroinchPerSquareSecond   },
    {"μin/s2",            Unit::Acceleration::MicroinchPerSquareSecond   },
    {"μin/s/s",           Unit::Acceleration::MicroinchPerSquareSecond   },
    {"uin/s^2",           Unit::Acceleration::MicroinchPerSquareSecond   },
    {"uin/s2",            Unit::Acceleration::MicroinchPerSquareSecond   },
    {"uin/s/s",           Unit::Acceleration::MicroinchPerSquareSecond   },
    {"μin/min^2",         Unit::Acceleration::MicroinchPerSquareMinute   },
    {"μin/min2",          Unit::Acceleration::MicroinchPerSquareMinute   },
    {"μin/min/min",       Unit::Acceleration::MicroinchPerSquareMinute   },
    {"uin/min^2",         Unit::Acceleration::MicroinchPerSquareMinute   },
    {"uin/min2",          Unit::Acceleration::MicroinchPerSquareMinute   },
    {"uin/min/min",       Unit::Acceleration::MicroinchPerSquareMinute   },
    {"μin/hr^2",          Unit::Acceleration::MicroinchPerSquareHour     },
    {"μin/hr2",           Unit::Acceleration::MicroinchPerSquareHour     },
    {"μin/hr/hr",         Unit::Acceleration::MicroinchPerSquareHour     },
    {"uin/hr^2",          Unit::Acceleration::MicroinchPerSquareHour     },
    {"uin/hr2",           Unit::Acceleration::MicroinchPerSquareHour     },
    {"uin/hr/hr",         Unit::Acceleration::MicroinchPerSquareHour     },
};

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareSecond>(
    double& value) noexcept {
  value /= 1852.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareSecond>(
    double& value) noexcept {
  value *= 1852.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareMinute>(
    double& value) noexcept {
  value *= 3600.0 / 1852.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareMinute>(
    double& value) noexcept {
  value *= 1852.0 / 3600.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::KnotPerHour>(
    double& value) noexcept {
  value *= 12960000.0 / 1852.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Acceleration, Unit::Acceleration::KnotPerHour>(
    double& value) noexcept {
  value *= 1852.0 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareSecond>(
    double& value) noexcept {
  value /= 1609.344;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareSecond>(
    double& value) noexcept {
  value *= 1609.344;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareMinute>(
    double& value) noexcept {
  value *= 3600.0 / 1609.344;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareMinute>(
    double& value) noexcept {
  value *= 1609.344 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareHour>(
    double& value) noexcept {
  value *= 12960000.0 / 1609.344;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareHour>(
    double& value) noexcept {
  value *= 1609.344 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareSecond>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareSecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareMinute>(
    double& value) noexcept {
  value *= 3.6;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareMinute>(
    double& value) noexcept {
  value *= 1000.0 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareHour>(
    double& value) noexcept {
  value *= 12960.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareHour>(
    double& value) noexcept {
  value *= 1000.0 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareMinute>(
    double& value) noexcept {
  value *= 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareMinute>(
    double& value) noexcept {
  value /= 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareHour>(
    double& value) noexcept {
  value *= 12960000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareHour>(
    double& value) noexcept {
  value /= 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareSecond>(
    double& value) noexcept {
  value /= 0.9144;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareSecond>(
    double& value) noexcept {
  value *= 0.9144;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareMinute>(
    double& value) noexcept {
  value *= 3600.0 / 0.9144;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareMinute>(
    double& value) noexcept {
  value *= 0.9144 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareHour>(
    double& value) noexcept {
  value *= 12960000.0 / 0.9144;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareHour>(
    double& value) noexcept {
  value *= 0.9144 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareSecond>(
    double& value) noexcept {
  value /= 0.3048;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareSecond>(
    double& value) noexcept {
  value *= 0.3048;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareMinute>(
    double& value) noexcept {
  value *= 3600.0 / 0.3048;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareMinute>(
    double& value) noexcept {
  value *= 0.3048 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareHour>(
    double& value) noexcept {
  value *= 12960000.0 / 0.3048;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareHour>(
    double& value) noexcept {
  value *= 0.3048 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareSecond>(
    double& value) noexcept {
  value *= 10.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareSecond>(
    double& value) noexcept {
  value *= 0.1;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareMinute>(
    double& value) noexcept {
  value *= 36000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareMinute>(
    double& value) noexcept {
  value *= 0.1 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareHour>(
    double& value) noexcept {
  value *= 129600000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareHour>(
    double& value) noexcept {
  value *= 0.1 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareSecond>(
    double& value) noexcept {
  value /= 0.0254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareSecond>(
    double& value) noexcept {
  value *= 0.0254;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareMinute>(
    double& value) noexcept {
  value *= 3600.0 / 0.0254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareMinute>(
    double& value) noexcept {
  value *= 0.0254 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareHour>(
    double& value) noexcept {
  value *= 12960000.0 / 0.0254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareHour>(
    double& value) noexcept {
  value *= 0.0254 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareSecond>(
    double& value) noexcept {
  value *= 100.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareSecond>(
    double& value) noexcept {
  value *= 0.01;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareMinute>(
    double& value) noexcept {
  value *= 360000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareMinute>(
    double& value) noexcept {
  value *= 0.01 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareHour>(
    double& value) noexcept {
  value *= 1296000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareHour>(
    double& value) noexcept {
  value *= 0.01 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareSecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareSecond>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareMinute>(
    double& value) noexcept {
  value *= 3600000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareMinute>(
    double& value) noexcept {
  value *= 0.001 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareHour>(
    double& value) noexcept {
  value *= 12960000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareHour>(
    double& value) noexcept {
  value *= 0.001 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareSecond>(
    double& value) noexcept {
  value /= 0.0000254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareSecond>(
    double& value) noexcept {
  value *= 0.0000254;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareMinute>(
    double& value) noexcept {
  value *= 3600.0 / 0.0000254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareMinute>(
    double& value) noexcept {
  value *= 0.0000254 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareHour>(
    double& value) noexcept {
  value *= 12960000.0 / 0.0000254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareHour>(
    double& value) noexcept {
  value *= 0.0000254 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareSecond>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareSecond>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareMinute>(
    double& value) noexcept {
  value *= 3600000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareMinute>(
    double& value) noexcept {
  value *= 0.000001 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareHour>(
    double& value) noexcept {
  value *= 12960000000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareHour>(
    double& value) noexcept {
  value *= 0.000001 / 12960000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareSecond>(
    double& value) noexcept {
  value /= 0.0000000254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareSecond>(
    double& value) noexcept {
  value *= 0.0000000254;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareMinute>(
    double& value) noexcept {
  value *= 3600.0 / 0.0000000254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareMinute>(
    double& value) noexcept {
  value *= 0.0000000254 / 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareHour>(
    double& value) noexcept {
  value *= 12960000.0 / 0.0000000254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareHour>(
    double& value) noexcept {
  value *= 0.0000000254 / 12960000.0;
}

template <>
inline const std::map<Unit::Acceleration,
                      std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Acceleration, double>{
        {Unit::Acceleration::NauticalMilePerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration,
         Unit::Acceleration::NauticalMilePerSquareSecond,                                           double>},
        {Unit::Acceleration::NauticalMilePerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration,
         Unit::Acceleration::NauticalMilePerSquareMinute,                                           double>},
        {Unit::Acceleration::KnotPerHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::KnotPerHour,               double>},
        {Unit::Acceleration::MilePerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MilePerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MilePerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::KilometrePerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::KilometrePerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::KilometrePerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::MetrePerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MetrePerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MetrePerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::YardPerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::YardPerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::YardPerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::FootPerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::FootPerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::FootPerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::DecimetrePerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::DecimetrePerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::DecimetrePerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::InchPerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::InchPerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::InchPerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::CentimetrePerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::CentimetrePerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::CentimetrePerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::MillimetrePerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MillimetrePerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MillimetrePerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::MilliinchPerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MilliinchPerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MilliinchPerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::MicrometrePerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MicrometrePerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MicrometrePerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::MicroinchPerSquareSecond,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MicroinchPerSquareMinute,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MicroinchPerSquareHour,
         ConversionsFromStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareHour,
         double>                                                                                           },
};

template <>
inline const std::map<Unit::Acceleration,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Acceleration, double>{
        {Unit::Acceleration::NauticalMilePerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::NauticalMilePerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::KnotPerHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::KnotPerHour,                 double>},
        {Unit::Acceleration::MilePerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MilePerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MilePerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MilePerSquareHour,           double>},
        {Unit::Acceleration::KilometrePerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::KilometrePerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::KilometrePerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::MetrePerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MetrePerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MetrePerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MetrePerSquareHour,          double>},
        {Unit::Acceleration::YardPerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::YardPerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::YardPerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::YardPerSquareHour,           double>},
        {Unit::Acceleration::FootPerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::FootPerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::FootPerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::FootPerSquareHour,           double>},
        {Unit::Acceleration::DecimetrePerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::DecimetrePerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::DecimetrePerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::InchPerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::InchPerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::InchPerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::InchPerSquareHour,           double>},
        {Unit::Acceleration::CentimetrePerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::CentimetrePerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::CentimetrePerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::MillimetrePerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MillimetrePerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MillimetrePerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::MilliinchPerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MilliinchPerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MilliinchPerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::MicrometrePerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MicrometrePerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MicrometrePerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareHour,
         double>                                                                                           },
        {Unit::Acceleration::MicroinchPerSquareSecond,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareSecond,
         double>                                                                                           },
        {Unit::Acceleration::MicroinchPerSquareMinute,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareMinute,
         double>                                                                                           },
        {Unit::Acceleration::MicroinchPerSquareHour,
         ConversionsToStandard<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareHour,
         double>                                                                                           },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ACCELERATION_HPP
