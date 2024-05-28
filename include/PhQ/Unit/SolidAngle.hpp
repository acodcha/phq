// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
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

#ifndef PHQ_UNIT_SOLID_ANGLE_HPP
#define PHQ_UNIT_SOLID_ANGLE_HPP

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

/// \brief Solid angle units. Measures the field of view of a portion of the surface of the unit
/// sphere viewed from the center of the unit sphere. Typically measured in steradians (sr), which
/// are square radians. The unit sphere has a total solid angle of 4π steradians.
enum class SolidAngle : int8_t {
  /// \brief Steradian (sr) solid angle unit, also known as square radian.
  Steradian,

  /// \brief Square degree (deg^2) solid angle unit.
  SquareDegree,

  /// \brief Square arcminute (arcmin^2) solid angle unit.
  SquareArcminute,

  /// \brief Square arcsecond (arcsec^2) solid angle unit.
  SquareArcsecond,
};

}  // namespace Unit

/// \brief Standard solid angle unit: steradian (sr).
template <>
inline constexpr const Unit::SolidAngle Standard<Unit::SolidAngle>{Unit::SolidAngle::Steradian};

/// \brief Physical dimension set of solid angle units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::SolidAngle>{Dimensionless};

inline std::ostream& operator<<(std::ostream& stream, const Unit::SolidAngle unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::SolidAngle> ConsistentUnits<Unit::SolidAngle>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::SolidAngle::Steradian},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::SolidAngle::Steradian},
    {UnitSystem::FootPoundSecondRankine,     Unit::SolidAngle::Steradian},
    {UnitSystem::InchPoundSecondRankine,     Unit::SolidAngle::Steradian},
};

template <>
inline const std::map<Unit::SolidAngle, UnitSystem> RelatedUnitSystems<Unit::SolidAngle>{};

template <>
inline const std::map<Unit::SolidAngle, std::string_view> Abbreviations<Unit::SolidAngle>{
    {Unit::SolidAngle::Steradian,       "sr"      },
    {Unit::SolidAngle::SquareDegree,    "deg^2"   },
    {Unit::SolidAngle::SquareArcminute, "arcmin^2"},
    {Unit::SolidAngle::SquareArcsecond, "arcsec^2"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::SolidAngle> Spellings<Unit::SolidAngle>{
    {"sr",           Unit::SolidAngle::Steradian      },
    {"rad^2",        Unit::SolidAngle::SquareDegree   },
    {"rad2",         Unit::SolidAngle::SquareDegree   },
    {"radian^2",     Unit::SolidAngle::SquareDegree   },
    {"radian2",      Unit::SolidAngle::SquareDegree   },
    {"radians^2",    Unit::SolidAngle::SquareDegree   },
    {"radians2",     Unit::SolidAngle::SquareDegree   },
    {"deg^2",        Unit::SolidAngle::SquareDegree   },
    {"deg2",         Unit::SolidAngle::SquareDegree   },
    {"degree^2",     Unit::SolidAngle::SquareDegree   },
    {"degree2",      Unit::SolidAngle::SquareDegree   },
    {"degrees^2",    Unit::SolidAngle::SquareDegree   },
    {"degrees2",     Unit::SolidAngle::SquareDegree   },
    {"°^2",          Unit::SolidAngle::SquareDegree   },
    {"°2",           Unit::SolidAngle::SquareDegree   },
    {"'^2",          Unit::SolidAngle::SquareArcminute},
    {"'2",           Unit::SolidAngle::SquareArcminute},
    {"am^2",         Unit::SolidAngle::SquareArcminute},
    {"am2",          Unit::SolidAngle::SquareArcminute},
    {"arcmin^2",     Unit::SolidAngle::SquareArcminute},
    {"arcmin2",      Unit::SolidAngle::SquareArcminute},
    {"arcminute^2",  Unit::SolidAngle::SquareArcminute},
    {"arcminute2",   Unit::SolidAngle::SquareArcminute},
    {"arcminutes^2", Unit::SolidAngle::SquareArcminute},
    {"arcminutes2",  Unit::SolidAngle::SquareArcminute},
    {"\"^2",         Unit::SolidAngle::SquareArcsecond},
    {"\"2",          Unit::SolidAngle::SquareArcsecond},
    {"as",           Unit::SolidAngle::SquareArcsecond},
    {"as^2",         Unit::SolidAngle::SquareArcsecond},
    {"arcs^2",       Unit::SolidAngle::SquareArcsecond},
    {"arcs2",        Unit::SolidAngle::SquareArcsecond},
    {"arcsec^2",     Unit::SolidAngle::SquareArcsecond},
    {"arcsec2",      Unit::SolidAngle::SquareArcsecond},
    {"arcsecond^2",  Unit::SolidAngle::SquareArcsecond},
    {"arcsecond2",   Unit::SolidAngle::SquareArcsecond},
    {"arcseconds^2", Unit::SolidAngle::SquareArcsecond},
    {"arcseconds2",  Unit::SolidAngle::SquareArcsecond},
};

template <>
template <typename Number>
inline constexpr void Conversion<Unit::SolidAngle, Unit::SolidAngle::Steradian>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::SolidAngle, Unit::SolidAngle::Steradian>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::SolidAngle, Unit::SolidAngle::SquareDegree>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(180.0L) * static_cast<Number>(180.0L) / (Pi<Number> * Pi<Number>);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::SolidAngle, Unit::SolidAngle::SquareDegree>::ToStandard(
    Number& value) noexcept {
  value *= Pi<Number> * Pi<Number> / (static_cast<Number>(180.0L) * static_cast<Number>(180.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::SolidAngle, Unit::SolidAngle::SquareArcminute>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(10800.0L) * static_cast<Number>(10800.0L) / (Pi<Number> * Pi<Number>);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::SolidAngle, Unit::SolidAngle::SquareArcminute>::ToStandard(
    Number& value) noexcept {
  value *=
      Pi<Number> * Pi<Number> / (static_cast<Number>(10800.0L) * static_cast<Number>(10800.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::SolidAngle, Unit::SolidAngle::SquareArcsecond>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(648000.0L) * static_cast<Number>(648000.0L) / (Pi<Number> * Pi<Number>);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::SolidAngle, Unit::SolidAngle::SquareArcsecond>::ToStandard(
    Number& value) noexcept {
  value *=
      Pi<Number> * Pi<Number> / (static_cast<Number>(648000.0L) * static_cast<Number>(648000.0L));
}

template <typename Number>
inline const std::map<Unit::SolidAngle, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::SolidAngle, Number>{
        {Unit::SolidAngle::Steradian,
         Conversions<Unit::SolidAngle, Unit::SolidAngle::Steradian>::FromStandard<Number>      },
        {Unit::SolidAngle::SquareDegree,
         Conversions<Unit::SolidAngle, Unit::SolidAngle::SquareDegree>::FromStandard<Number>   },
        {Unit::SolidAngle::SquareArcminute,
         Conversions<Unit::SolidAngle, Unit::SolidAngle::SquareArcminute>::FromStandard<Number>},
        {Unit::SolidAngle::SquareArcsecond,
         Conversions<Unit::SolidAngle, Unit::SolidAngle::SquareArcsecond>::FromStandard<Number>},
};

template <typename Number>
inline const std::map<Unit::SolidAngle,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::SolidAngle, Number>{
        {Unit::SolidAngle::Steradian,
         Conversions<Unit::SolidAngle, Unit::SolidAngle::Steradian>::ToStandard<Number>      },
        {Unit::SolidAngle::SquareDegree,
         Conversions<Unit::SolidAngle, Unit::SolidAngle::SquareDegree>::ToStandard<Number>   },
        {Unit::SolidAngle::SquareArcminute,
         Conversions<Unit::SolidAngle, Unit::SolidAngle::SquareArcminute>::ToStandard<Number>},
        {Unit::SolidAngle::SquareArcsecond,
         Conversions<Unit::SolidAngle, Unit::SolidAngle::SquareArcsecond>::ToStandard<Number>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_SOLID_ANGLE_HPP
