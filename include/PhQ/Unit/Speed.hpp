// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
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
#include "../Dimension/ElectricCurrent.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/LuminousIntensity.hpp"
#include "../Dimension/Mass.hpp"
#include "../Dimension/SubstanceAmount.hpp"
#include "../Dimension/Temperature.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

/// \brief Speed units.
enum class Speed : int8_t {
  /// \brief Nautical mile per second (nmi/s) speed unit.
  NauticalMilePerSecond,

  /// \brief Nautical mile per minute (nmi/min) speed unit.
  NauticalMilePerMinute,

  /// \brief Knot (kn) speed unit, also known as nautical mile per hour.
  Knot,

  /// \brief Mile per second (mi/s) speed unit.
  MilePerSecond,

  /// \brief Mile per minute (mi/min) speed unit.
  MilePerMinute,

  /// \brief Mile per hour (mi/hr) speed unit.
  MilePerHour,

  /// \brief Kilometre per second (km/s) speed unit.
  KilometrePerSecond,

  /// \brief Kilometre per minute (km/min) speed unit.
  KilometrePerMinute,

  /// \brief Kilometre per hour (km/hr) speed unit.
  KilometrePerHour,

  /// \brief Metre per second (m/s) speed unit.
  MetrePerSecond,

  /// \brief Metre per minute (m/min) speed unit.
  MetrePerMinute,

  /// \brief Metre per hour (m/hr) speed unit.
  MetrePerHour,

  /// \brief Yard per second (yd/s) speed unit.
  YardPerSecond,

  /// \brief Yard per minute (yd/min) speed unit.
  YardPerMinute,

  /// \brief Yard per hour (yd/hr) speed unit.
  YardPerHour,

  /// \brief Foot per second (ft/s) speed unit.
  FootPerSecond,

  /// \brief Foot per minute (ft/min) speed unit.
  FootPerMinute,

  /// \brief Foot per hour (ft/hr) speed unit.
  FootPerHour,

  /// \brief Decimetre per second (dm/s) speed unit.
  DecimetrePerSecond,

  /// \brief Decimetre per minute (dm/min) speed unit.
  DecimetrePerMinute,

  /// \brief Decimetre per hour (dm/hr) speed unit.
  DecimetrePerHour,

  /// \brief Inch per second (in/s) speed unit.
  InchPerSecond,

  /// \brief Inch per minute (in/min) speed unit.
  InchPerMinute,

  /// \brief Inch per hour (in/hr) speed unit.
  InchPerHour,

  /// \brief Centimetre per second (cm/s) speed unit.
  CentimetrePerSecond,

  /// \brief Centimetre per minute (cm/min) speed unit.
  CentimetrePerMinute,

  /// \brief Centimetre per hour (cm/hr) speed unit.
  CentimetrePerHour,

  /// \brief Millimetre per second (mm/s) speed unit.
  MillimetrePerSecond,

  /// \brief Millimetre per minute (mm/min) speed unit.
  MillimetrePerMinute,

  /// \brief Millimetre per hour (mm/hr) speed unit.
  MillimetrePerHour,

  /// \brief Milliinch per second (mil/s) speed unit.
  MilliinchPerSecond,

  /// \brief Milliinch per minute (mil/min) speed unit.
  MilliinchPerMinute,

  /// \brief Milliinch per hour (mil/hr) speed unit.
  MilliinchPerHour,

  /// \brief Micrometre per second (μm/s) speed unit.
  MicrometrePerSecond,

  /// \brief Micrometre per minute (μm/min) speed unit.
  MicrometrePerMinute,

  /// \brief Micrometre per hour (μm/hr) speed unit.
  MicrometrePerHour,

  /// \brief Microinch per second (μin/s) speed unit.
  MicroinchPerSecond,

  /// \brief Microinch per minute (μin/min) speed unit.
  MicroinchPerMinute,

  /// \brief Microinch per hour (μin/hr) speed unit.
  MicroinchPerHour,
};

}  // namespace Unit

/// \brief Standard speed unit: metre per second (m/s).
template <>
inline constexpr const Unit::Speed Standard<Unit::Speed>{Unit::Speed::MetrePerSecond};

/// \brief Physical dimension set of speed units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Speed>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{1}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
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
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::NauticalMilePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::NauticalMilePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::NauticalMilePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::NauticalMilePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::Knot>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::Knot>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.06L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3.6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::KilometrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerSecond>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerSecond>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MetrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::YardPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::FootPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(10.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.1L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(36000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::DecimetrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(36000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::InchPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(100.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.01L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(6000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(6000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(360000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::CentimetrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(360000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MillimetrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MilliinchPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicrometrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Speed, Unit::Speed::MicroinchPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L) / static_cast<NumericType>(3600.0L);
}

template <typename NumericType>
inline const std::map<Unit::Speed, std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Speed, NumericType>{
        {Unit::Speed::NauticalMilePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::NauticalMilePerSecond>::FromStandard<NumericType>},
        {Unit::Speed::NauticalMilePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::NauticalMilePerMinute>::FromStandard<NumericType>},
        {Unit::Speed::Knot,                  Conversions<Unit::Speed, Unit::Speed::Knot>::FromStandard<NumericType>                 },
        {Unit::Speed::MilePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerSecond>::FromStandard<NumericType>        },
        {Unit::Speed::MilePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerMinute>::FromStandard<NumericType>        },
        {Unit::Speed::MilePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerHour>::FromStandard<NumericType>          },
        {Unit::Speed::KilometrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerSecond>::FromStandard<NumericType>   },
        {Unit::Speed::KilometrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerMinute>::FromStandard<NumericType>   },
        {Unit::Speed::KilometrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerHour>::FromStandard<NumericType>     },
        {Unit::Speed::MetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerSecond>::FromStandard<NumericType>       },
        {Unit::Speed::MetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerMinute>::FromStandard<NumericType>       },
        {Unit::Speed::MetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerHour>::FromStandard<NumericType>         },
        {Unit::Speed::YardPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerSecond>::FromStandard<NumericType>        },
        {Unit::Speed::YardPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerMinute>::FromStandard<NumericType>        },
        {Unit::Speed::YardPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerHour>::FromStandard<NumericType>          },
        {Unit::Speed::FootPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerSecond>::FromStandard<NumericType>        },
        {Unit::Speed::FootPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerMinute>::FromStandard<NumericType>        },
        {Unit::Speed::FootPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerHour>::FromStandard<NumericType>          },
        {Unit::Speed::DecimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerSecond>::FromStandard<NumericType>   },
        {Unit::Speed::DecimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerMinute>::FromStandard<NumericType>   },
        {Unit::Speed::DecimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerHour>::FromStandard<NumericType>     },
        {Unit::Speed::InchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerSecond>::FromStandard<NumericType>        },
        {Unit::Speed::InchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerMinute>::FromStandard<NumericType>        },
        {Unit::Speed::InchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerHour>::FromStandard<NumericType>          },
        {Unit::Speed::CentimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerSecond>::FromStandard<NumericType>  },
        {Unit::Speed::CentimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerMinute>::FromStandard<NumericType>  },
        {Unit::Speed::CentimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerHour>::FromStandard<NumericType>    },
        {Unit::Speed::MillimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerSecond>::FromStandard<NumericType>  },
        {Unit::Speed::MillimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerMinute>::FromStandard<NumericType>  },
        {Unit::Speed::MillimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerHour>::FromStandard<NumericType>    },
        {Unit::Speed::MilliinchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerSecond>::FromStandard<NumericType>   },
        {Unit::Speed::MilliinchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerMinute>::FromStandard<NumericType>   },
        {Unit::Speed::MilliinchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerHour>::FromStandard<NumericType>     },
        {Unit::Speed::MicrometrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerSecond>::FromStandard<NumericType>  },
        {Unit::Speed::MicrometrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerMinute>::FromStandard<NumericType>  },
        {Unit::Speed::MicrometrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerHour>::FromStandard<NumericType>    },
        {Unit::Speed::MicroinchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerSecond>::FromStandard<NumericType>   },
        {Unit::Speed::MicroinchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerMinute>::FromStandard<NumericType>   },
        {Unit::Speed::MicroinchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerHour>::FromStandard<NumericType>     },
};

template <typename NumericType>
inline const std::map<Unit::Speed,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Speed, NumericType>{
        {Unit::Speed::NauticalMilePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::NauticalMilePerSecond>::ToStandard<NumericType>},
        {Unit::Speed::NauticalMilePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::NauticalMilePerMinute>::ToStandard<NumericType>},
        {Unit::Speed::Knot,                  Conversions<Unit::Speed, Unit::Speed::Knot>::ToStandard<NumericType>                 },
        {Unit::Speed::MilePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerSecond>::ToStandard<NumericType>        },
        {Unit::Speed::MilePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerMinute>::ToStandard<NumericType>        },
        {Unit::Speed::MilePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MilePerHour>::ToStandard<NumericType>          },
        {Unit::Speed::KilometrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerSecond>::ToStandard<NumericType>   },
        {Unit::Speed::KilometrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerMinute>::ToStandard<NumericType>   },
        {Unit::Speed::KilometrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::KilometrePerHour>::ToStandard<NumericType>     },
        {Unit::Speed::MetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerSecond>::ToStandard<NumericType>       },
        {Unit::Speed::MetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerMinute>::ToStandard<NumericType>       },
        {Unit::Speed::MetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MetrePerHour>::ToStandard<NumericType>         },
        {Unit::Speed::YardPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerSecond>::ToStandard<NumericType>        },
        {Unit::Speed::YardPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerMinute>::ToStandard<NumericType>        },
        {Unit::Speed::YardPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::YardPerHour>::ToStandard<NumericType>          },
        {Unit::Speed::FootPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerSecond>::ToStandard<NumericType>        },
        {Unit::Speed::FootPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerMinute>::ToStandard<NumericType>        },
        {Unit::Speed::FootPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::FootPerHour>::ToStandard<NumericType>          },
        {Unit::Speed::DecimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerSecond>::ToStandard<NumericType>   },
        {Unit::Speed::DecimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerMinute>::ToStandard<NumericType>   },
        {Unit::Speed::DecimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::DecimetrePerHour>::ToStandard<NumericType>     },
        {Unit::Speed::InchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerSecond>::ToStandard<NumericType>        },
        {Unit::Speed::InchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerMinute>::ToStandard<NumericType>        },
        {Unit::Speed::InchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::InchPerHour>::ToStandard<NumericType>          },
        {Unit::Speed::CentimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerSecond>::ToStandard<NumericType>  },
        {Unit::Speed::CentimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerMinute>::ToStandard<NumericType>  },
        {Unit::Speed::CentimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::CentimetrePerHour>::ToStandard<NumericType>    },
        {Unit::Speed::MillimetrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerSecond>::ToStandard<NumericType>  },
        {Unit::Speed::MillimetrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerMinute>::ToStandard<NumericType>  },
        {Unit::Speed::MillimetrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MillimetrePerHour>::ToStandard<NumericType>    },
        {Unit::Speed::MilliinchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerSecond>::ToStandard<NumericType>   },
        {Unit::Speed::MilliinchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerMinute>::ToStandard<NumericType>   },
        {Unit::Speed::MilliinchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MilliinchPerHour>::ToStandard<NumericType>     },
        {Unit::Speed::MicrometrePerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerSecond>::ToStandard<NumericType>  },
        {Unit::Speed::MicrometrePerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerMinute>::ToStandard<NumericType>  },
        {Unit::Speed::MicrometrePerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MicrometrePerHour>::ToStandard<NumericType>    },
        {Unit::Speed::MicroinchPerSecond,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerSecond>::ToStandard<NumericType>   },
        {Unit::Speed::MicroinchPerMinute,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerMinute>::ToStandard<NumericType>   },
        {Unit::Speed::MicroinchPerHour,
         Conversions<Unit::Speed,                                     Unit::Speed::MicroinchPerHour>::ToStandard<NumericType>     },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_SPEED_HPP
