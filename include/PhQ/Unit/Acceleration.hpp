// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1852.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Acceleration, Unit::Acceleration::KnotPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(12960000.0L) / static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Acceleration, Unit::Acceleration::KnotPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1852.0L) / static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(12960000.0L) / static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) / static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3.6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(12960.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L) / static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareSecond>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareSecond>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.9144L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(12960000.0L) / static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.9144L) / static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(12960000.0L) / static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) / static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(10.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.1L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(36000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.1L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(129600000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.1L) / static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(12960000.0L) / static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) / static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(100.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.01L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(360000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.01L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1296000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.01L) / static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(12960000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L) / static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(12960000.0L) / static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L) / static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(12960000000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L) / static_cast<Number>(12960000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(12960000.0L) / static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L) / static_cast<Number>(12960000.0L);
}

template <typename Number>
inline const std::map<Unit::Acceleration,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Acceleration, Number>{
        {Unit::Acceleration::NauticalMilePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::NauticalMilePerSquareSecond>::FromStandard<Number>                },
        {Unit::Acceleration::NauticalMilePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::NauticalMilePerSquareMinute>::FromStandard<Number>                },
        {Unit::Acceleration::KnotPerHour,
         Conversions<Unit::Acceleration, Unit::Acceleration::KnotPerHour>::FromStandard<Number>},
        {Unit::Acceleration::MilePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareSecond>::FromStandard<Number>                        },
        {Unit::Acceleration::MilePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareMinute>::FromStandard<Number>                        },
        {Unit::Acceleration::MilePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareHour>::FromStandard<Number>                          },
        {Unit::Acceleration::KilometrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareSecond>::FromStandard<Number>                   },
        {Unit::Acceleration::KilometrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareMinute>::FromStandard<Number>                   },
        {Unit::Acceleration::KilometrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareHour>::FromStandard<Number>                     },
        {Unit::Acceleration::MetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareSecond>::FromStandard<Number>                       },
        {Unit::Acceleration::MetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareMinute>::FromStandard<Number>                       },
        {Unit::Acceleration::MetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareHour>::FromStandard<Number>                         },
        {Unit::Acceleration::YardPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareSecond>::FromStandard<Number>                        },
        {Unit::Acceleration::YardPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareMinute>::FromStandard<Number>                        },
        {Unit::Acceleration::YardPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareHour>::FromStandard<Number>                          },
        {Unit::Acceleration::FootPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareSecond>::FromStandard<Number>                        },
        {Unit::Acceleration::FootPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareMinute>::FromStandard<Number>                        },
        {Unit::Acceleration::FootPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareHour>::FromStandard<Number>                          },
        {Unit::Acceleration::DecimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareSecond>::FromStandard<Number>                   },
        {Unit::Acceleration::DecimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareMinute>::FromStandard<Number>                   },
        {Unit::Acceleration::DecimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareHour>::FromStandard<Number>                     },
        {Unit::Acceleration::InchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareSecond>::FromStandard<Number>                        },
        {Unit::Acceleration::InchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareMinute>::FromStandard<Number>                        },
        {Unit::Acceleration::InchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareHour>::FromStandard<Number>                          },
        {Unit::Acceleration::CentimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareSecond>::FromStandard<Number>                  },
        {Unit::Acceleration::CentimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareMinute>::FromStandard<Number>                  },
        {Unit::Acceleration::CentimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareHour>::FromStandard<Number>                    },
        {Unit::Acceleration::MillimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareSecond>::FromStandard<Number>                  },
        {Unit::Acceleration::MillimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareMinute>::FromStandard<Number>                  },
        {Unit::Acceleration::MillimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareHour>::FromStandard<Number>                    },
        {Unit::Acceleration::MilliinchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareSecond>::FromStandard<Number>                   },
        {Unit::Acceleration::MilliinchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareMinute>::FromStandard<Number>                   },
        {Unit::Acceleration::MilliinchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareHour>::FromStandard<Number>                     },
        {Unit::Acceleration::MicrometrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareSecond>::FromStandard<Number>                  },
        {Unit::Acceleration::MicrometrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareMinute>::FromStandard<Number>                  },
        {Unit::Acceleration::MicrometrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareHour>::FromStandard<Number>                    },
        {Unit::Acceleration::MicroinchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareSecond>::FromStandard<Number>                   },
        {Unit::Acceleration::MicroinchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareMinute>::FromStandard<Number>                   },
        {Unit::Acceleration::MicroinchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareHour>::FromStandard<Number>                     },
};

template <typename Number>
inline const std::map<Unit::Acceleration,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Acceleration, Number>{
        {Unit::Acceleration::NauticalMilePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::NauticalMilePerSquareSecond>::ToStandard<Number>                },
        {Unit::Acceleration::NauticalMilePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::NauticalMilePerSquareMinute>::ToStandard<Number>                },
        {Unit::Acceleration::KnotPerHour,
         Conversions<Unit::Acceleration, Unit::Acceleration::KnotPerHour>::ToStandard<Number>},
        {Unit::Acceleration::MilePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareSecond>::ToStandard<Number>                        },
        {Unit::Acceleration::MilePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareMinute>::ToStandard<Number>                        },
        {Unit::Acceleration::MilePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareHour>::ToStandard<Number>                          },
        {Unit::Acceleration::KilometrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareSecond>::ToStandard<Number>                   },
        {Unit::Acceleration::KilometrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareMinute>::ToStandard<Number>                   },
        {Unit::Acceleration::KilometrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareHour>::ToStandard<Number>                     },
        {Unit::Acceleration::MetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareSecond>::ToStandard<Number>                       },
        {Unit::Acceleration::MetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareMinute>::ToStandard<Number>                       },
        {Unit::Acceleration::MetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareHour>::ToStandard<Number>                         },
        {Unit::Acceleration::YardPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareSecond>::ToStandard<Number>                        },
        {Unit::Acceleration::YardPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareMinute>::ToStandard<Number>                        },
        {Unit::Acceleration::YardPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareHour>::ToStandard<Number>                          },
        {Unit::Acceleration::FootPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareSecond>::ToStandard<Number>                        },
        {Unit::Acceleration::FootPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareMinute>::ToStandard<Number>                        },
        {Unit::Acceleration::FootPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareHour>::ToStandard<Number>                          },
        {Unit::Acceleration::DecimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareSecond>::ToStandard<Number>                   },
        {Unit::Acceleration::DecimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareMinute>::ToStandard<Number>                   },
        {Unit::Acceleration::DecimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareHour>::ToStandard<Number>                     },
        {Unit::Acceleration::InchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareSecond>::ToStandard<Number>                        },
        {Unit::Acceleration::InchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareMinute>::ToStandard<Number>                        },
        {Unit::Acceleration::InchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareHour>::ToStandard<Number>                          },
        {Unit::Acceleration::CentimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareSecond>::ToStandard<Number>                  },
        {Unit::Acceleration::CentimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareMinute>::ToStandard<Number>                  },
        {Unit::Acceleration::CentimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareHour>::ToStandard<Number>                    },
        {Unit::Acceleration::MillimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareSecond>::ToStandard<Number>                  },
        {Unit::Acceleration::MillimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareMinute>::ToStandard<Number>                  },
        {Unit::Acceleration::MillimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareHour>::ToStandard<Number>                    },
        {Unit::Acceleration::MilliinchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareSecond>::ToStandard<Number>                   },
        {Unit::Acceleration::MilliinchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareMinute>::ToStandard<Number>                   },
        {Unit::Acceleration::MilliinchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareHour>::ToStandard<Number>                     },
        {Unit::Acceleration::MicrometrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareSecond>::ToStandard<Number>                  },
        {Unit::Acceleration::MicrometrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareMinute>::ToStandard<Number>                  },
        {Unit::Acceleration::MicrometrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareHour>::ToStandard<Number>                    },
        {Unit::Acceleration::MicroinchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareSecond>::ToStandard<Number>                   },
        {Unit::Acceleration::MicroinchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareMinute>::ToStandard<Number>                   },
        {Unit::Acceleration::MicroinchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareHour>::ToStandard<Number>                     },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ACCELERATION_HPP
