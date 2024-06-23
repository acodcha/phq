// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

/// \brief Angular speed units.
enum class AngularSpeed : int8_t {
  /// \brief Radian per second (rad/s) angular speed unit.
  RadianPerSecond,

  /// \brief Radian per minute (rad/min) angular speed unit.
  RadianPerMinute,

  /// \brief Radian per hour (rad/hr) angular speed unit.
  RadianPerHour,

  /// \brief Degree per second (deg/s) angular speed unit.
  DegreePerSecond,

  /// \brief Degree per minute (deg/min) angular speed unit.
  DegreePerMinute,

  /// \brief Degree per hour (deg/hr) angular speed unit.
  DegreePerHour,

  /// \brief Arcminute per second (arcmin/s) angular speed unit.
  ArcminutePerSecond,

  /// \brief Arcminute per minute (arcmin/min) angular speed unit.
  ArcminutePerMinute,

  /// \brief Arcminute per hour (arcmin/hr) angular speed unit.
  ArcminutePerHour,

  /// \brief Arcsecond per second (arcsec/s) angular speed unit.
  ArcsecondPerSecond,

  /// \brief Arcsecond per minute (arcsec/min) angular speed unit.
  ArcsecondPerMinute,

  /// \brief Arcsecond per hour (arcsec/hr) angular speed unit.
  ArcsecondPerHour,

  /// \brief Revolution per second (rev/s) angular speed unit.
  RevolutionPerSecond,

  /// \brief Revolution per minute (rev/min) angular speed unit.
  RevolutionPerMinute,

  /// \brief Revolution per hour (rev/hr) angular speed unit.
  RevolutionPerHour,
};

}  // namespace Unit

/// \brief Standard angular speed unit: radian per second (rad/s).
template <>
inline constexpr const Unit::AngularSpeed Standard<Unit::AngularSpeed>{
    Unit::AngularSpeed::RadianPerSecond};

/// \brief Physical dimension set of angular speed units.
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

// clang-format off

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

// clang-format on

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerSecond>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerSecond>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RadianPerHour>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(180.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(180.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(10800.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(10800.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(648000.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::AngularSpeed, Unit::AngularSpeed::DegreePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(648000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(10800.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(10800.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(648000.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(648000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(38880000.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcminutePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(38880000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(648000.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(648000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(38880000.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(38880000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(2332800000.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::ArcsecondPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(2332800000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.5L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(2.0L) * Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(30.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(30.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1800.0L) / Pi<NumericType>;
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::AngularSpeed, Unit::AngularSpeed::RevolutionPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= Pi<NumericType> / static_cast<NumericType>(1800.0L);
}

template <typename NumericType>
inline const std::map<Unit::AngularSpeed,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::AngularSpeed, NumericType>{
        {Unit::AngularSpeed::RadianPerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerSecond>::FromStandard<NumericType>    },
        {Unit::AngularSpeed::RadianPerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerMinute>::FromStandard<NumericType>    },
        {Unit::AngularSpeed::RadianPerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerHour>::FromStandard<NumericType>      },
        {Unit::AngularSpeed::DegreePerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerSecond>::FromStandard<NumericType>    },
        {Unit::AngularSpeed::DegreePerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerMinute>::FromStandard<NumericType>    },
        {Unit::AngularSpeed::DegreePerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerHour>::FromStandard<NumericType>      },
        {Unit::AngularSpeed::ArcminutePerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerSecond>::FromStandard<NumericType> },
        {Unit::AngularSpeed::ArcminutePerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerMinute>::FromStandard<NumericType> },
        {Unit::AngularSpeed::ArcminutePerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerHour>::FromStandard<NumericType>   },
        {Unit::AngularSpeed::ArcsecondPerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerSecond>::FromStandard<NumericType> },
        {Unit::AngularSpeed::ArcsecondPerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerMinute>::FromStandard<NumericType> },
        {Unit::AngularSpeed::ArcsecondPerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerHour>::FromStandard<NumericType>   },
        {Unit::AngularSpeed::RevolutionPerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerSecond>::FromStandard<NumericType>},
        {Unit::AngularSpeed::RevolutionPerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerMinute>::FromStandard<NumericType>},
        {Unit::AngularSpeed::RevolutionPerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerHour>::FromStandard<NumericType>  },
};

template <typename NumericType>
inline const std::map<Unit::AngularSpeed,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::AngularSpeed, NumericType>{
        {Unit::AngularSpeed::RadianPerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerSecond>::ToStandard<NumericType>    },
        {Unit::AngularSpeed::RadianPerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerMinute>::ToStandard<NumericType>    },
        {Unit::AngularSpeed::RadianPerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RadianPerHour>::ToStandard<NumericType>      },
        {Unit::AngularSpeed::DegreePerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerSecond>::ToStandard<NumericType>    },
        {Unit::AngularSpeed::DegreePerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerMinute>::ToStandard<NumericType>    },
        {Unit::AngularSpeed::DegreePerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::DegreePerHour>::ToStandard<NumericType>      },
        {Unit::AngularSpeed::ArcminutePerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerSecond>::ToStandard<NumericType> },
        {Unit::AngularSpeed::ArcminutePerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerMinute>::ToStandard<NumericType> },
        {Unit::AngularSpeed::ArcminutePerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcminutePerHour>::ToStandard<NumericType>   },
        {Unit::AngularSpeed::ArcsecondPerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerSecond>::ToStandard<NumericType> },
        {Unit::AngularSpeed::ArcsecondPerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerMinute>::ToStandard<NumericType> },
        {Unit::AngularSpeed::ArcsecondPerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::ArcsecondPerHour>::ToStandard<NumericType>   },
        {Unit::AngularSpeed::RevolutionPerSecond,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerSecond>::ToStandard<NumericType>},
        {Unit::AngularSpeed::RevolutionPerMinute,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerMinute>::ToStandard<NumericType>},
        {Unit::AngularSpeed::RevolutionPerHour,
         Conversions<Unit::AngularSpeed,
         Unit::AngularSpeed::RevolutionPerHour>::ToStandard<NumericType>  },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ANGULAR_SPEED_HPP
