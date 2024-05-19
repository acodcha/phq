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

#ifndef PHQ_UNIT_ANGULAR_SPEED_HPP
#define PHQ_UNIT_ANGULAR_SPEED_HPP

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

// Angular speed units.
enum class AngularSpeed : int8_t {
  // Radian per second (rad/s) angular speed unit.
  RadianPerSecond,

  // Radian per minute (rad/min) angular speed unit.
  RadianPerMinute,

  // Radian per hour (rad/hr) angular speed unit.
  RadianPerHour,

  // Degree per second (deg/s) angular speed unit.
  DegreePerSecond,

  // Degree per minute (deg/min) angular speed unit.
  DegreePerMinute,

  // Degree per hour (deg/hr) angular speed unit.
  DegreePerHour,

  // Arcminute per second (arcmin/s) angular speed unit.
  ArcminutePerSecond,

  // Arcminute per minute (arcmin/min) angular speed unit.
  ArcminutePerMinute,

  // Arcminute per hour (arcmin/hr) angular speed unit.
  ArcminutePerHour,

  // Arcsecond per second (arcsec/s) angular speed unit.
  ArcsecondPerSecond,

  // Arcsecond per minute (arcsec/min) angular speed unit.
  ArcsecondPerMinute,

  // Arcsecond per hour (arcsec/hr) angular speed unit.
  ArcsecondPerHour,

  // Revolution per second (rev/s) angular speed unit.
  RevolutionPerSecond,

  // Revolution per minute (rev/min) angular speed unit.
  RevolutionPerMinute,

  // Revolution per hour (rev/hr) angular speed unit.
  RevolutionPerHour,
};

}  // namespace Unit

// Standard angular speed unit: radian per second (rad/s).
template <>
inline constexpr const Unit::AngularSpeed Standard<Unit::AngularSpeed>{
    Unit::AngularSpeed::RadianPerSecond};

// Physical dimension set of angular speed units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::AngularSpeed>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{0}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::AngularSpeed unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::AngularSpeed> ConsistentUnits<Unit::AngularSpeed>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::AngularSpeed::RadianPerSecond},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::AngularSpeed::RadianPerSecond},
    {UnitSystem::FootPoundSecondRankine,     Unit::AngularSpeed::RadianPerSecond},
    {UnitSystem::InchPoundSecondRankine,     Unit::AngularSpeed::RadianPerSecond},
};

template <>
inline const std::map<Unit::AngularSpeed, UnitSystem> RelatedUnitSystems<Unit::AngularSpeed>{};

template <>
inline const std::map<Unit::AngularSpeed, std::string_view> Abbreviations<Unit::AngularSpeed>{
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

template <>
inline const std::unordered_map<std::string_view, Unit::AngularSpeed> Spellings<Unit::AngularSpeed>{
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

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerSecond>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerSecond>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(180.0L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(180.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(10800.0L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(10800.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(648000.0L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerHour>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(648000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(10800.0L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(10800.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(648000.0L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(648000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(38880000.0L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerHour>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(38880000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(648000.0L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(648000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(38880000.0L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(38880000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(2332800000.0L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerHour>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(2332800000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.5L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(2.0L) * Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(30.0L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(30.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1800.0L) / Pi<Number>;
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerHour>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> / static_cast<Number>(1800.0L);
}

template <typename Number>
inline const std::map<Unit::AngularSpeed,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::AngularSpeed, Number>{
        {Unit::AngularSpeed::RadianPerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerSecond>::FromStandard<Number>                              },
        {Unit::AngularSpeed::RadianPerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerMinute>::FromStandard<Number>                              },
        {Unit::AngularSpeed::RadianPerHour,
         Conversions<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerHour>::FromStandard<Number>},
        {Unit::AngularSpeed::DegreePerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerSecond>::FromStandard<Number>                              },
        {Unit::AngularSpeed::DegreePerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerMinute>::FromStandard<Number>                              },
        {Unit::AngularSpeed::DegreePerHour,
         Conversions<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerHour>::FromStandard<Number>},
        {Unit::AngularSpeed::ArcminutePerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerSecond>::FromStandard<Number>                           },
        {Unit::AngularSpeed::ArcminutePerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerMinute>::FromStandard<Number>                           },
        {Unit::AngularSpeed::ArcminutePerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerHour>::FromStandard<Number>                             },
        {Unit::AngularSpeed::ArcsecondPerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerSecond>::FromStandard<Number>                           },
        {Unit::AngularSpeed::ArcsecondPerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerMinute>::FromStandard<Number>                           },
        {Unit::AngularSpeed::ArcsecondPerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerHour>::FromStandard<Number>                             },
        {Unit::AngularSpeed::RevolutionPerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerSecond>::FromStandard<Number>                          },
        {Unit::AngularSpeed::RevolutionPerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerMinute>::FromStandard<Number>                          },
        {Unit::AngularSpeed::RevolutionPerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerHour>::FromStandard<Number>                            },
};

template <typename Number>
inline const std::map<Unit::AngularSpeed,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::AngularSpeed, Number>{
        {Unit::AngularSpeed::RadianPerSecond,
         Conversions<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerSecond>::ToStandard<Number> },
        {Unit::AngularSpeed::RadianPerMinute,
         Conversions<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerMinute>::ToStandard<Number> },
        {Unit::AngularSpeed::RadianPerHour,
         Conversions<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerHour>::ToStandard<Number>   },
        {Unit::AngularSpeed::DegreePerSecond,
         Conversions<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerSecond>::ToStandard<Number> },
        {Unit::AngularSpeed::DegreePerMinute,
         Conversions<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerMinute>::ToStandard<Number> },
        {Unit::AngularSpeed::DegreePerHour,
         Conversions<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerHour>::ToStandard<Number>   },
        {Unit::AngularSpeed::ArcminutePerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerSecond>::ToStandard<Number>                              },
        {Unit::AngularSpeed::ArcminutePerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerMinute>::ToStandard<Number>                              },
        {Unit::AngularSpeed::ArcminutePerHour,
         Conversions<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerHour>::ToStandard<Number>},
        {Unit::AngularSpeed::ArcsecondPerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerSecond>::ToStandard<Number>                              },
        {Unit::AngularSpeed::ArcsecondPerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerMinute>::ToStandard<Number>                              },
        {Unit::AngularSpeed::ArcsecondPerHour,
         Conversions<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerHour>::ToStandard<Number>},
        {Unit::AngularSpeed::RevolutionPerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerSecond>::ToStandard<Number>                             },
        {Unit::AngularSpeed::RevolutionPerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerMinute>::ToStandard<Number>                             },
        {Unit::AngularSpeed::RevolutionPerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerHour>::ToStandard<Number>                               },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ANGULAR_SPEED_HPP
