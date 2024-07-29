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

/// \brief Diffusivity units.
enum class Diffusivity : int8_t {
  /// \brief Square metre per second (m^2/s) diffusivity unit.
  SquareMetrePerSecond,

  /// \brief Square nautical mile per second (nmi^2/s) diffusivity unit.
  SquareNauticalMilePerSecond,

  /// \brief Square mile per second (mi^2/s) diffusivity unit.
  SquareMilePerSecond,

  /// \brief Square kilometre per second (km^2/s) diffusivity unit.
  SquareKilometrePerSecond,

  /// \brief Hectare per second (ha/s) diffusivity unit.
  HectarePerSecond,

  /// \brief Acre per second (ac/s) diffusivity unit.
  AcrePerSecond,

  /// \brief Square yard per second (yd^2/s) diffusivity unit.
  SquareYardPerSecond,

  /// \brief Square foot per second (ft^2/s) diffusivity unit.
  SquareFootPerSecond,

  /// \brief Square decimetre per second (dm^2/s) diffusivity unit.
  SquareDecimetrePerSecond,

  /// \brief Square inch per second (in^2/s) diffusivity unit.
  SquareInchPerSecond,

  /// \brief Square centimetre per second (cm^2/s) diffusivity unit.
  SquareCentimetrePerSecond,

  /// \brief Square millimetre per second (mm^2/s) diffusivity unit.
  SquareMillimetrePerSecond,

  /// \brief Square milliinch per second (mil^2/s) diffusivity unit.
  SquareMilliinchPerSecond,

  /// \brief Square micrometre per second (μm^2/s) diffusivity unit.
  SquareMicrometrePerSecond,

  /// \brief Square microinch per second (μin^2/s) diffusivity unit.
  SquareMicroinchPerSecond,
};

}  // namespace Unit

/// \brief Standard diffusivity unit: square metre per second (m^2/s).
template <>
inline constexpr const Unit::Diffusivity Standard<Unit::Diffusivity>{
    Unit::Diffusivity::SquareMetrePerSecond};

/// \brief Physical dimension set of diffusivity units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Diffusivity>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{2}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
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

// clang-format off

template <>
inline const std::map<Unit::Diffusivity, std::string_view> Abbreviations<Unit::Diffusivity>{
    {Unit::Diffusivity::SquareMetrePerSecond,        "m^2/s"  },
    {Unit::Diffusivity::SquareNauticalMilePerSecond, "nmi^2/s"},
    {Unit::Diffusivity::SquareMilePerSecond,         "mi^2/s" },
    {Unit::Diffusivity::SquareKilometrePerSecond,    "km^2/s" },
    {Unit::Diffusivity::HectarePerSecond,            "ha/s"   },
    {Unit::Diffusivity::AcrePerSecond,               "ac/s"   },
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
    {"m^2/s",         Unit::Diffusivity::SquareMetrePerSecond       },
    {"m2/s",          Unit::Diffusivity::SquareMetrePerSecond       },
    {"nmi^2/s",       Unit::Diffusivity::SquareNauticalMilePerSecond},
    {"nmi2/s",        Unit::Diffusivity::SquareNauticalMilePerSecond},
    {"mi^2/s",        Unit::Diffusivity::SquareMilePerSecond        },
    {"mi2/s",         Unit::Diffusivity::SquareMilePerSecond        },
    {"km^2/s",        Unit::Diffusivity::SquareKilometrePerSecond   },
    {"km2/s",         Unit::Diffusivity::SquareKilometrePerSecond   },
    {"ha/s",          Unit::Diffusivity::HectarePerSecond           },
    {"ac/s",          Unit::Diffusivity::AcrePerSecond              },
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

// clang-format on

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMetrePerSecond>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMetrePerSecond>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareNauticalMilePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareNauticalMilePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMilePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMilePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareKilometrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareKilometrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::HectarePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::HectarePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(10000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Diffusivity, Unit::Diffusivity::AcrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(640.0L)
           / (static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Diffusivity, Unit::Diffusivity::AcrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L)
           / static_cast<NumericType>(640.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareYardPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareYardPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareFootPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareFootPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareDecimetrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(100.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareDecimetrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.01L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareInchPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareInchPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareCentimetrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(10000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareCentimetrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMillimetrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMillimetrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMilliinchPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMilliinchPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMicrometrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMicrometrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000000000001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMicroinchPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Diffusivity, Unit::Diffusivity::SquareMicroinchPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L);
}

template <typename NumericType>
inline const std::map<Unit::Diffusivity,
                      std::function<void(NumericType* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Diffusivity, NumericType>{
        {Unit::Diffusivity::SquareMetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMetrePerSecond>::FromStandard<NumericType>       },
        {Unit::Diffusivity::SquareNauticalMilePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareNauticalMilePerSecond>::FromStandard<NumericType>},
        {Unit::Diffusivity::SquareMilePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMilePerSecond>::FromStandard<NumericType>        },
        {Unit::Diffusivity::SquareKilometrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareKilometrePerSecond>::FromStandard<NumericType>   },
        {Unit::Diffusivity::HectarePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::HectarePerSecond>::FromStandard<NumericType>           },
        {Unit::Diffusivity::AcrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::AcrePerSecond>::FromStandard<NumericType>              },
        {Unit::Diffusivity::SquareYardPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareYardPerSecond>::FromStandard<NumericType>        },
        {Unit::Diffusivity::SquareFootPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareFootPerSecond>::FromStandard<NumericType>        },
        {Unit::Diffusivity::SquareDecimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareDecimetrePerSecond>::FromStandard<NumericType>   },
        {Unit::Diffusivity::SquareInchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareInchPerSecond>::FromStandard<NumericType>        },
        {Unit::Diffusivity::SquareCentimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareCentimetrePerSecond>::FromStandard<NumericType>  },
        {Unit::Diffusivity::SquareMillimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMillimetrePerSecond>::FromStandard<NumericType>  },
        {Unit::Diffusivity::SquareMilliinchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMilliinchPerSecond>::FromStandard<NumericType>   },
        {Unit::Diffusivity::SquareMicrometrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMicrometrePerSecond>::FromStandard<NumericType>  },
        {Unit::Diffusivity::SquareMicroinchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMicroinchPerSecond>::FromStandard<NumericType>   },
};

template <typename NumericType>
inline const std::map<Unit::Diffusivity,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Diffusivity, NumericType>{
        {Unit::Diffusivity::SquareMetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMetrePerSecond>::ToStandard<NumericType>                        },
        {Unit::Diffusivity::SquareNauticalMilePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareNauticalMilePerSecond>::ToStandard<NumericType>                 },
        {Unit::Diffusivity::SquareMilePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMilePerSecond>::ToStandard<NumericType>                         },
        {Unit::Diffusivity::SquareKilometrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareKilometrePerSecond>::ToStandard<NumericType>                    },
        {Unit::Diffusivity::HectarePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::HectarePerSecond>::ToStandard<NumericType>                            },
        {Unit::Diffusivity::AcrePerSecond,
         Conversions<Unit::Diffusivity, Unit::Diffusivity::AcrePerSecond>::ToStandard<NumericType>},
        {Unit::Diffusivity::SquareYardPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareYardPerSecond>::ToStandard<NumericType>                         },
        {Unit::Diffusivity::SquareFootPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareFootPerSecond>::ToStandard<NumericType>                         },
        {Unit::Diffusivity::SquareDecimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareDecimetrePerSecond>::ToStandard<NumericType>                    },
        {Unit::Diffusivity::SquareInchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareInchPerSecond>::ToStandard<NumericType>                         },
        {Unit::Diffusivity::SquareCentimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareCentimetrePerSecond>::ToStandard<NumericType>                   },
        {Unit::Diffusivity::SquareMillimetrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMillimetrePerSecond>::ToStandard<NumericType>                   },
        {Unit::Diffusivity::SquareMilliinchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMilliinchPerSecond>::ToStandard<NumericType>                    },
        {Unit::Diffusivity::SquareMicrometrePerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMicrometrePerSecond>::ToStandard<NumericType>                   },
        {Unit::Diffusivity::SquareMicroinchPerSecond,
         Conversions<Unit::Diffusivity,
         Unit::Diffusivity::SquareMicroinchPerSecond>::ToStandard<NumericType>                    },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_DIFFUSIVITY_HPP
