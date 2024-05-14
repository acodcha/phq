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
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::NauticalMilePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::NauticalMilePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::NauticalMilePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::NauticalMilePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1852.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::Knot>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::Knot>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1852.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.06L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3.6L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerSecond>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerSecond>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.9144L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.9144L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(10.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.1L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(36000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(36000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(100.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.01L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(6000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(6000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(360000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(360000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L) / static_cast<Number>(3600.0L);
}

template <typename Number>
inline const std::map<Unit::Speed, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Speed, Number>{
        {Unit::Speed::NauticalMilePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::NauticalMilePerSecond>::FromStandard<Number>},
        {Unit::Speed::NauticalMilePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::NauticalMilePerMinute>::FromStandard<Number>},
        {Unit::Speed::Knot,                  Conversions<Unit::Speed, Unit::Speed::Knot>::FromStandard<Number>                 },
        {Unit::Speed::MilePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerSecond>::FromStandard<Number>        },
        {Unit::Speed::MilePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerMinute>::FromStandard<Number>        },
        {Unit::Speed::MilePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerHour>::FromStandard<Number>          },
        {Unit::Speed::KilometrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerSecond>::FromStandard<Number>   },
        {Unit::Speed::KilometrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerMinute>::FromStandard<Number>   },
        {Unit::Speed::KilometrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerHour>::FromStandard<Number>     },
        {Unit::Speed::MetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerSecond>::FromStandard<Number>       },
        {Unit::Speed::MetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerMinute>::FromStandard<Number>       },
        {Unit::Speed::MetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerHour>::FromStandard<Number>         },
        {Unit::Speed::YardPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerSecond>::FromStandard<Number>        },
        {Unit::Speed::YardPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerMinute>::FromStandard<Number>        },
        {Unit::Speed::YardPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerHour>::FromStandard<Number>          },
        {Unit::Speed::FootPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerSecond>::FromStandard<Number>        },
        {Unit::Speed::FootPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerMinute>::FromStandard<Number>        },
        {Unit::Speed::FootPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerHour>::FromStandard<Number>          },
        {Unit::Speed::DecimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerSecond>::FromStandard<Number>   },
        {Unit::Speed::DecimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerMinute>::FromStandard<Number>   },
        {Unit::Speed::DecimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerHour>::FromStandard<Number>     },
        {Unit::Speed::InchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerSecond>::FromStandard<Number>        },
        {Unit::Speed::InchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerMinute>::FromStandard<Number>        },
        {Unit::Speed::InchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerHour>::FromStandard<Number>          },
        {Unit::Speed::CentimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerSecond>::FromStandard<Number>  },
        {Unit::Speed::CentimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerMinute>::FromStandard<Number>  },
        {Unit::Speed::CentimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerHour>::FromStandard<Number>    },
        {Unit::Speed::MillimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerSecond>::FromStandard<Number>  },
        {Unit::Speed::MillimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerMinute>::FromStandard<Number>  },
        {Unit::Speed::MillimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerHour>::FromStandard<Number>    },
        {Unit::Speed::MilliinchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerSecond>::FromStandard<Number>   },
        {Unit::Speed::MilliinchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerMinute>::FromStandard<Number>   },
        {Unit::Speed::MilliinchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerHour>::FromStandard<Number>     },
        {Unit::Speed::MicrometrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerSecond>::FromStandard<Number>  },
        {Unit::Speed::MicrometrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerMinute>::FromStandard<Number>  },
        {Unit::Speed::MicrometrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerHour>::FromStandard<Number>    },
        {Unit::Speed::MicroinchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerSecond>::FromStandard<Number>   },
        {Unit::Speed::MicroinchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerMinute>::FromStandard<Number>   },
        {Unit::Speed::MicroinchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerHour>::FromStandard<Number>     },
};

template <typename Number>
inline const std::map<Unit::Speed,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Speed, Number>{
        {Unit::Speed::NauticalMilePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::NauticalMilePerSecond>::ToStandard<Number>},
        {Unit::Speed::NauticalMilePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::NauticalMilePerMinute>::ToStandard<Number>},
        {Unit::Speed::Knot,                  Conversions<Unit::Speed, Unit::Speed::Knot>::ToStandard<Number>                 },
        {Unit::Speed::MilePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerSecond>::ToStandard<Number>        },
        {Unit::Speed::MilePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerMinute>::ToStandard<Number>        },
        {Unit::Speed::MilePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerHour>::ToStandard<Number>          },
        {Unit::Speed::KilometrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerSecond>::ToStandard<Number>   },
        {Unit::Speed::KilometrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerMinute>::ToStandard<Number>   },
        {Unit::Speed::KilometrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerHour>::ToStandard<Number>     },
        {Unit::Speed::MetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerSecond>::ToStandard<Number>       },
        {Unit::Speed::MetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerMinute>::ToStandard<Number>       },
        {Unit::Speed::MetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerHour>::ToStandard<Number>         },
        {Unit::Speed::YardPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerSecond>::ToStandard<Number>        },
        {Unit::Speed::YardPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerMinute>::ToStandard<Number>        },
        {Unit::Speed::YardPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerHour>::ToStandard<Number>          },
        {Unit::Speed::FootPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerSecond>::ToStandard<Number>        },
        {Unit::Speed::FootPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerMinute>::ToStandard<Number>        },
        {Unit::Speed::FootPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerHour>::ToStandard<Number>          },
        {Unit::Speed::DecimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerSecond>::ToStandard<Number>   },
        {Unit::Speed::DecimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerMinute>::ToStandard<Number>   },
        {Unit::Speed::DecimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerHour>::ToStandard<Number>     },
        {Unit::Speed::InchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerSecond>::ToStandard<Number>        },
        {Unit::Speed::InchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerMinute>::ToStandard<Number>        },
        {Unit::Speed::InchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerHour>::ToStandard<Number>          },
        {Unit::Speed::CentimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerSecond>::ToStandard<Number>  },
        {Unit::Speed::CentimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerMinute>::ToStandard<Number>  },
        {Unit::Speed::CentimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerHour>::ToStandard<Number>    },
        {Unit::Speed::MillimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerSecond>::ToStandard<Number>  },
        {Unit::Speed::MillimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerMinute>::ToStandard<Number>  },
        {Unit::Speed::MillimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerHour>::ToStandard<Number>    },
        {Unit::Speed::MilliinchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerSecond>::ToStandard<Number>   },
        {Unit::Speed::MilliinchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerMinute>::ToStandard<Number>   },
        {Unit::Speed::MilliinchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerHour>::ToStandard<Number>     },
        {Unit::Speed::MicrometrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerSecond>::ToStandard<Number>  },
        {Unit::Speed::MicrometrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerMinute>::ToStandard<Number>  },
        {Unit::Speed::MicrometrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerHour>::ToStandard<Number>    },
        {Unit::Speed::MicroinchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerSecond>::ToStandard<Number>   },
        {Unit::Speed::MicroinchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerMinute>::ToStandard<Number>   },
        {Unit::Speed::MicroinchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerHour>::ToStandard<Number>     },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_SPEED_HPP
