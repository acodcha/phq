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

#ifndef PHQ_UNIT_DIFFUSIVITY_HPP
#define PHQ_UNIT_DIFFUSIVITY_HPP

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

// Diffusivity units.
enum class Diffusivity : int8_t {
  // Square nautical mile per second (nmi^2/s) diffusivity unit.
  SquareNauticalMilePerSecond,

  // Square mile per second (mi^2/s) diffusivity unit.
  SquareMilePerSecond,

  // Square kilometre per second (km^2/s) diffusivity unit.
  SquareKilometrePerSecond,

  // Hectare per second (ha/s) diffusivity unit.
  HectarePerSecond,

  // Acre per second (ac/s) diffusivity unit.
  AcrePerSecond,

  // Square metre per second (m^2/s) diffusivity unit.
  SquareMetrePerSecond,

  // Square yard per second (yd^2/s) diffusivity unit.
  SquareYardPerSecond,

  // Square foot per second (ft^2/s) diffusivity unit.
  SquareFootPerSecond,

  // Square decimetre per second (dm^2/s) diffusivity unit.
  SquareDecimetrePerSecond,

  // Square inch per second (in^2/s) diffusivity unit.
  SquareInchPerSecond,

  // Square centimetre per second (cm^2/s) diffusivity unit.
  SquareCentimetrePerSecond,

  // Square millimetre per second (mm^2/s) diffusivity unit.
  SquareMillimetrePerSecond,

  // Square milliinch per second (mil^2/s) diffusivity unit.
  SquareMilliinchPerSecond,

  // Square micrometre per second (μm^2/s) diffusivity unit.
  SquareMicrometrePerSecond,

  // Square microinch per second (μin^2/s) diffusivity unit.
  SquareMicroinchPerSecond,
};

}  // namespace Unit

// Standard diffusivity unit: square metre per second (m^2/s).
template <>
inline constexpr const Unit::Diffusivity Standard<Unit::Diffusivity>{
    Unit::Diffusivity::SquareMetrePerSecond};

// Physical dimension set of diffusivity units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Diffusivity>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{2}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Diffusivity unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Diffusivity> ConsistentUnits<Unit::Diffusivity>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Diffusivity::SquareMetrePerSecond     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Diffusivity::SquareMillimetrePerSecond},
    {UnitSystem::FootPoundSecondRankine,     Unit::Diffusivity::SquareFootPerSecond      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Diffusivity::SquareInchPerSecond      },
};

template <>
inline const std::map<Unit::Diffusivity, UnitSystem> RelatedUnitSystems<Unit::Diffusivity>{
    {Unit::Diffusivity::SquareMetrePerSecond,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Diffusivity::SquareMillimetrePerSecond, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Diffusivity::SquareFootPerSecond,       UnitSystem::FootPoundSecondRankine    },
    {Unit::Diffusivity::SquareInchPerSecond,       UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::Diffusivity, std::string_view> Abbreviations<Unit::Diffusivity>{
    {Unit::Diffusivity::SquareNauticalMilePerSecond, "nmi^2/s"},
    {Unit::Diffusivity::SquareMilePerSecond,         "mi^2/s" },
    {Unit::Diffusivity::SquareKilometrePerSecond,    "km^2/s" },
    {Unit::Diffusivity::HectarePerSecond,            "ha/s"   },
    {Unit::Diffusivity::AcrePerSecond,               "ac/s"   },
    {Unit::Diffusivity::SquareMetrePerSecond,        "m^2/s"  },
    {Unit::Diffusivity::SquareYardPerSecond,         "yd^2/s" },
    {Unit::Diffusivity::SquareFootPerSecond,         "ft^2/s" },
    {Unit::Diffusivity::SquareDecimetrePerSecond,    "dm^2/s" },
    {Unit::Diffusivity::SquareInchPerSecond,         "in^2/s" },
    {Unit::Diffusivity::SquareCentimetrePerSecond,   "cm^2/s" },
    {Unit::Diffusivity::SquareMillimetrePerSecond,   "mm^2/s" },
    {Unit::Diffusivity::SquareMilliinchPerSecond,    "mil^2/s"},
    {Unit::Diffusivity::SquareMicrometrePerSecond,   "μm^2/s" },
    {Unit::Diffusivity::SquareMicroinchPerSecond,    "μin^2/s"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Diffusivity> Spellings<Unit::Diffusivity>{
    {"nmi^2/s",       Unit::Diffusivity::SquareNauticalMilePerSecond},
    {"nmi2/s",        Unit::Diffusivity::SquareNauticalMilePerSecond},
    {"mi^2/s",        Unit::Diffusivity::SquareMilePerSecond        },
    {"mi2/s",         Unit::Diffusivity::SquareMilePerSecond        },
    {"km^2/s",        Unit::Diffusivity::SquareKilometrePerSecond   },
    {"km2/s",         Unit::Diffusivity::SquareKilometrePerSecond   },
    {"ha/s",          Unit::Diffusivity::HectarePerSecond           },
    {"ac/s",          Unit::Diffusivity::AcrePerSecond              },
    {"m^2/s",         Unit::Diffusivity::SquareMetrePerSecond       },
    {"m2/s",          Unit::Diffusivity::SquareMetrePerSecond       },
    {"yd^2/s",        Unit::Diffusivity::SquareYardPerSecond        },
    {"yd2/s",         Unit::Diffusivity::SquareYardPerSecond        },
    {"ft^2/s",        Unit::Diffusivity::SquareFootPerSecond        },
    {"ft2/s",         Unit::Diffusivity::SquareFootPerSecond        },
    {"dm^2/s",        Unit::Diffusivity::SquareDecimetrePerSecond   },
    {"dm2/s",         Unit::Diffusivity::SquareDecimetrePerSecond   },
    {"in^2/s",        Unit::Diffusivity::SquareInchPerSecond        },
    {"in2/s",         Unit::Diffusivity::SquareInchPerSecond        },
    {"cm^2/s",        Unit::Diffusivity::SquareCentimetrePerSecond  },
    {"cm2/s",         Unit::Diffusivity::SquareCentimetrePerSecond  },
    {"mm^2/s",        Unit::Diffusivity::SquareMillimetrePerSecond  },
    {"mm2/s",         Unit::Diffusivity::SquareMillimetrePerSecond  },
    {"millinch^2/s",  Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"millinch2/s",   Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"milliinch^2/s", Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"milliinch2/s",  Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"mil^2/s",       Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"mil2/s",        Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"thou^2/s",      Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"thou2/s",       Unit::Diffusivity::SquareMilliinchPerSecond   },
    {"μm^2/s",        Unit::Diffusivity::SquareMicrometrePerSecond  },
    {"μm2/s",         Unit::Diffusivity::SquareMicrometrePerSecond  },
    {"um^2/s",        Unit::Diffusivity::SquareMicrometrePerSecond  },
    {"um2/s",         Unit::Diffusivity::SquareMicrometrePerSecond  },
    {"μin^2/s",       Unit::Diffusivity::SquareMicroinchPerSecond   },
    {"μin2/s",        Unit::Diffusivity::SquareMicroinchPerSecond   },
    {"uin^2/s",       Unit::Diffusivity::SquareMicroinchPerSecond   },
    {"uin2/s",        Unit::Diffusivity::SquareMicroinchPerSecond   },
};

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareNauticalMilePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareNauticalMilePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMilePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMilePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareKilometrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareKilometrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::HectarePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::HectarePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(10000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Diffusivity, Unit::Diffusivity::AcrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(640.0L)
           / (static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Diffusivity, Unit::Diffusivity::AcrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L) / static_cast<Number>(640.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMetrePerSecond>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMetrePerSecond>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareYardPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareYardPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareFootPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareFootPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareDecimetrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(100.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareDecimetrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.01L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareInchPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareInchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareCentimetrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(10000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareCentimetrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMillimetrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMillimetrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMilliinchPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0000254L) * static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMilliinchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L) * static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMicrometrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMicrometrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000000000001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMicroinchPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.0000000254L) * static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMicroinchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L) * static_cast<Number>(0.0000000254L);
}

template <typename Number>
inline const std::map<Unit::Diffusivity, std::function<void(Number* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Diffusivity, Number>{
        {Unit::Diffusivity::SquareNauticalMilePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareNauticalMilePerSecond>::FromStandard<Number>                    },
        {Unit::Diffusivity::SquareMilePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMilePerSecond>::FromStandard<Number>                            },
        {Unit::Diffusivity::SquareKilometrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareKilometrePerSecond>::FromStandard<Number>                       },
        {Unit::Diffusivity::HectarePerSecond,
         Conversions<Unit::Diffusivity, Unit::Diffusivity::HectarePerSecond>::FromStandard<Number>},
        {Unit::Diffusivity::AcrePerSecond,
         Conversions<Unit::Diffusivity, Unit::Diffusivity::AcrePerSecond>::FromStandard<Number>   },
        {Unit::Diffusivity::SquareMetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMetrePerSecond>::FromStandard<Number>                           },
        {Unit::Diffusivity::SquareYardPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareYardPerSecond>::FromStandard<Number>                            },
        {Unit::Diffusivity::SquareFootPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareFootPerSecond>::FromStandard<Number>                            },
        {Unit::Diffusivity::SquareDecimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareDecimetrePerSecond>::FromStandard<Number>                       },
        {Unit::Diffusivity::SquareInchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareInchPerSecond>::FromStandard<Number>                            },
        {Unit::Diffusivity::SquareCentimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareCentimetrePerSecond>::FromStandard<Number>                      },
        {Unit::Diffusivity::SquareMillimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMillimetrePerSecond>::FromStandard<Number>                      },
        {Unit::Diffusivity::SquareMilliinchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMilliinchPerSecond>::FromStandard<Number>                       },
        {Unit::Diffusivity::SquareMicrometrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMicrometrePerSecond>::FromStandard<Number>                      },
        {Unit::Diffusivity::SquareMicroinchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMicroinchPerSecond>::FromStandard<Number>                       },
};

template <typename Number>
inline const std::map<Unit::Diffusivity,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Diffusivity, Number>{
        {Unit::Diffusivity::SquareNauticalMilePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareNauticalMilePerSecond>::ToStandard<Number>                    },
        {Unit::Diffusivity::SquareMilePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMilePerSecond>::ToStandard<Number>                            },
        {Unit::Diffusivity::SquareKilometrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareKilometrePerSecond>::ToStandard<Number>                       },
        {Unit::Diffusivity::HectarePerSecond,
         Conversions<Unit::Diffusivity, Unit::Diffusivity::HectarePerSecond>::ToStandard<Number>},
        {Unit::Diffusivity::AcrePerSecond,
         Conversions<Unit::Diffusivity, Unit::Diffusivity::AcrePerSecond>::ToStandard<Number>   },
        {Unit::Diffusivity::SquareMetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMetrePerSecond>::ToStandard<Number>                           },
        {Unit::Diffusivity::SquareYardPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareYardPerSecond>::ToStandard<Number>                            },
        {Unit::Diffusivity::SquareFootPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareFootPerSecond>::ToStandard<Number>                            },
        {Unit::Diffusivity::SquareDecimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareDecimetrePerSecond>::ToStandard<Number>                       },
        {Unit::Diffusivity::SquareInchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareInchPerSecond>::ToStandard<Number>                            },
        {Unit::Diffusivity::SquareCentimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareCentimetrePerSecond>::ToStandard<Number>                      },
        {Unit::Diffusivity::SquareMillimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMillimetrePerSecond>::ToStandard<Number>                      },
        {Unit::Diffusivity::SquareMilliinchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMilliinchPerSecond>::ToStandard<Number>                       },
        {Unit::Diffusivity::SquareMicrometrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMicrometrePerSecond>::ToStandard<Number>                      },
        {Unit::Diffusivity::SquareMicroinchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMicroinchPerSecond>::ToStandard<Number>                       },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_DIFFUSIVITY_HPP
