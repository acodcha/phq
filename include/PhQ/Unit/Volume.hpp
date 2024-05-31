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

#ifndef PHQ_UNIT_VOLUME_HPP
#define PHQ_UNIT_VOLUME_HPP

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

/// \brief Volume units.
enum class Volume : int8_t {
  /// \brief Cubic nautical mile (nmi^3) volume unit.
  CubicNauticalMile,

  /// \brief Cubic mile (mi^3) volume unit.
  CubicMile,

  /// \brief Cubic kilometre (km^3) volume unit.
  CubicKilometre,

  /// \brief Cubic metre (m^3) volume unit.
  CubicMetre,

  /// \brief Cubic yard (yd^3) volume unit.
  CubicYard,

  /// \brief Cubic foot (ft^3) volume unit.
  CubicFoot,

  /// \brief Cubic decimetre (dm^3) volume unit.
  CubicDecimetre,

  /// \brief Litre (L) volume unit.
  Litre,

  /// \brief Cubic inch (in^3) volume unit.
  CubicInch,

  /// \brief Cubic centimetre (cm^3) volume unit.
  CubicCentimetre,

  /// \brief Millilitre (mL) volume unit.
  Millilitre,

  /// \brief Cubic millimetre (mm^3) volume unit.
  CubicMillimetre,

  /// \brief Cubic milliinch (mil^3) volume unit.
  CubicMilliinch,

  /// \brief Cubic micrometre (μm^3) volume unit.
  CubicMicrometre,

  /// \brief Cubic microinch (μin^3) volume unit.
  CubicMicroinch,
};

}  // namespace Unit

/// \brief Standard volume unit: cubic metre (m^3).
template <>
inline constexpr const Unit::Volume Standard<Unit::Volume>{Unit::Volume::CubicMetre};

/// \brief Physical dimension set of volume units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Volume>{
    Dimensions{Dimension::Time{0}, Dimension::Length{3}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Volume unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Volume> ConsistentUnits<Unit::Volume>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Volume::CubicMetre     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Volume::CubicMillimetre},
    {UnitSystem::FootPoundSecondRankine,     Unit::Volume::CubicFoot      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Volume::CubicInch      },
};

template <>
inline const std::map<Unit::Volume, UnitSystem> RelatedUnitSystems<Unit::Volume>{
    {Unit::Volume::CubicMetre,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Volume::CubicMillimetre, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Volume::CubicFoot,       UnitSystem::FootPoundSecondRankine    },
    {Unit::Volume::CubicInch,       UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::Volume, std::string_view> Abbreviations<Unit::Volume>{
    {Unit::Volume::CubicNauticalMile, "nmi^3"},
    {Unit::Volume::CubicMile,         "mi^3" },
    {Unit::Volume::CubicKilometre,    "km^3" },
    {Unit::Volume::CubicMetre,        "m^3"  },
    {Unit::Volume::CubicYard,         "yd^3" },
    {Unit::Volume::CubicFoot,         "ft^3" },
    {Unit::Volume::CubicDecimetre,    "dm^3" },
    {Unit::Volume::Litre,             "L"    },
    {Unit::Volume::CubicInch,         "in^3" },
    {Unit::Volume::CubicCentimetre,   "cm^3" },
    {Unit::Volume::Millilitre,        "mL"   },
    {Unit::Volume::CubicMillimetre,   "mm^3" },
    {Unit::Volume::CubicMilliinch,    "mil^3"},
    {Unit::Volume::CubicMicrometre,   "μm^3" },
    {Unit::Volume::CubicMicroinch,    "μin^3"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Volume> Spellings<Unit::Volume>{
    {"nmi^3",       Unit::Volume::CubicNauticalMile},
    {"nmi3",        Unit::Volume::CubicNauticalMile},
    {"mi^3",        Unit::Volume::CubicMile        },
    {"mi3",         Unit::Volume::CubicMile        },
    {"km^3",        Unit::Volume::CubicKilometre   },
    {"km3",         Unit::Volume::CubicKilometre   },
    {"m^3",         Unit::Volume::CubicMetre       },
    {"m3",          Unit::Volume::CubicMetre       },
    {"yd^3",        Unit::Volume::CubicYard        },
    {"yd3",         Unit::Volume::CubicYard        },
    {"ft^3",        Unit::Volume::CubicFoot        },
    {"ft3",         Unit::Volume::CubicFoot        },
    {"dm^3",        Unit::Volume::CubicDecimetre   },
    {"dm3",         Unit::Volume::CubicDecimetre   },
    {"L",           Unit::Volume::Litre            },
    {"in^3",        Unit::Volume::CubicInch        },
    {"in3",         Unit::Volume::CubicInch        },
    {"cm^3",        Unit::Volume::CubicCentimetre  },
    {"cm3",         Unit::Volume::CubicCentimetre  },
    {"mL",          Unit::Volume::Millilitre       },
    {"mm^3",        Unit::Volume::CubicMillimetre  },
    {"mm3",         Unit::Volume::CubicMillimetre  },
    {"millinch^3",  Unit::Volume::CubicMilliinch   },
    {"millinch3",   Unit::Volume::CubicMilliinch   },
    {"milliinch^3", Unit::Volume::CubicMilliinch   },
    {"milliinch3",  Unit::Volume::CubicMilliinch   },
    {"mil^3",       Unit::Volume::CubicMilliinch   },
    {"mil3",        Unit::Volume::CubicMilliinch   },
    {"thou^3",      Unit::Volume::CubicMilliinch   },
    {"thou3",       Unit::Volume::CubicMilliinch   },
    {"μm^3",        Unit::Volume::CubicMicrometre  },
    {"μm3",         Unit::Volume::CubicMicrometre  },
    {"um^3",        Unit::Volume::CubicMicrometre  },
    {"um3",         Unit::Volume::CubicMicrometre  },
    {"μin^3",       Unit::Volume::CubicMicroinch   },
    {"μin3",        Unit::Volume::CubicMicroinch   },
    {"uin^3",       Unit::Volume::CubicMicroinch   },
    {"uin3",        Unit::Volume::CubicMicroinch   },
};

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicNauticalMile>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L)
           * static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicNauticalMile>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L)
           * static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMile>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L)
           * static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMile>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L)
           * static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicKilometre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicKilometre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMetre>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMetre>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicYard>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L)
           * static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicYard>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L)
           * static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicFoot>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L)
           * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicFoot>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L)
           * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicDecimetre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicDecimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::Litre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::Litre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicInch>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L)
           * static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicInch>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L)
           * static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicCentimetre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicCentimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::Millilitre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::Millilitre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMillimetre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMillimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMilliinch>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L)
           * static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMilliinch>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L)
           * static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMicrometre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E18L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMicrometre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-18L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMicroinch>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L)
           * static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Volume, Unit::Volume::CubicMicroinch>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L)
           * static_cast<NumericType>(0.0000000254L);
}

template <typename NumericType>
inline const std::map<Unit::Volume, std::function<void(NumericType* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Volume, NumericType>{
        {Unit::Volume::CubicNauticalMile,
         Conversions<Unit::Volume, Unit::Volume::CubicNauticalMile>::FromStandard<NumericType>},
        {Unit::Volume::CubicMile,
         Conversions<Unit::Volume, Unit::Volume::CubicMile>::FromStandard<NumericType>        },
        {Unit::Volume::CubicKilometre,
         Conversions<Unit::Volume, Unit::Volume::CubicKilometre>::FromStandard<NumericType>   },
        {Unit::Volume::CubicMetre,
         Conversions<Unit::Volume, Unit::Volume::CubicMetre>::FromStandard<NumericType>       },
        {Unit::Volume::CubicYard,
         Conversions<Unit::Volume, Unit::Volume::CubicYard>::FromStandard<NumericType>        },
        {Unit::Volume::CubicFoot,
         Conversions<Unit::Volume, Unit::Volume::CubicFoot>::FromStandard<NumericType>        },
        {Unit::Volume::CubicDecimetre,
         Conversions<Unit::Volume, Unit::Volume::CubicDecimetre>::FromStandard<NumericType>   },
        {Unit::Volume::Litre,
         Conversions<Unit::Volume, Unit::Volume::Litre>::FromStandard<NumericType>            },
        {Unit::Volume::CubicInch,
         Conversions<Unit::Volume, Unit::Volume::CubicInch>::FromStandard<NumericType>        },
        {Unit::Volume::CubicCentimetre,
         Conversions<Unit::Volume, Unit::Volume::CubicCentimetre>::FromStandard<NumericType>  },
        {Unit::Volume::Millilitre,
         Conversions<Unit::Volume, Unit::Volume::Millilitre>::FromStandard<NumericType>       },
        {Unit::Volume::CubicMillimetre,
         Conversions<Unit::Volume, Unit::Volume::CubicMillimetre>::FromStandard<NumericType>  },
        {Unit::Volume::CubicMilliinch,
         Conversions<Unit::Volume, Unit::Volume::CubicMilliinch>::FromStandard<NumericType>   },
        {Unit::Volume::CubicMicrometre,
         Conversions<Unit::Volume, Unit::Volume::CubicMicrometre>::FromStandard<NumericType>  },
        {Unit::Volume::CubicMicroinch,
         Conversions<Unit::Volume, Unit::Volume::CubicMicroinch>::FromStandard<NumericType>   },
};

template <typename NumericType>
inline const std::map<Unit::Volume,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Volume, NumericType>{
        {Unit::Volume::CubicNauticalMile,
         Conversions<Unit::Volume, Unit::Volume::CubicNauticalMile>::ToStandard<NumericType>},
        {Unit::Volume::CubicMile,
         Conversions<Unit::Volume, Unit::Volume::CubicMile>::ToStandard<NumericType>        },
        {Unit::Volume::CubicKilometre,
         Conversions<Unit::Volume, Unit::Volume::CubicKilometre>::ToStandard<NumericType>   },
        {Unit::Volume::CubicMetre,
         Conversions<Unit::Volume, Unit::Volume::CubicMetre>::ToStandard<NumericType>       },
        {Unit::Volume::CubicYard,
         Conversions<Unit::Volume, Unit::Volume::CubicYard>::ToStandard<NumericType>        },
        {Unit::Volume::CubicFoot,
         Conversions<Unit::Volume, Unit::Volume::CubicFoot>::ToStandard<NumericType>        },
        {Unit::Volume::CubicDecimetre,
         Conversions<Unit::Volume, Unit::Volume::CubicDecimetre>::ToStandard<NumericType>   },
        {Unit::Volume::Litre,
         Conversions<Unit::Volume, Unit::Volume::Litre>::ToStandard<NumericType>            },
        {Unit::Volume::CubicInch,
         Conversions<Unit::Volume, Unit::Volume::CubicInch>::ToStandard<NumericType>        },
        {Unit::Volume::CubicCentimetre,
         Conversions<Unit::Volume, Unit::Volume::CubicCentimetre>::ToStandard<NumericType>  },
        {Unit::Volume::Millilitre,
         Conversions<Unit::Volume, Unit::Volume::Millilitre>::ToStandard<NumericType>       },
        {Unit::Volume::CubicMillimetre,
         Conversions<Unit::Volume, Unit::Volume::CubicMillimetre>::ToStandard<NumericType>  },
        {Unit::Volume::CubicMilliinch,
         Conversions<Unit::Volume, Unit::Volume::CubicMilliinch>::ToStandard<NumericType>   },
        {Unit::Volume::CubicMicrometre,
         Conversions<Unit::Volume, Unit::Volume::CubicMicrometre>::ToStandard<NumericType>  },
        {Unit::Volume::CubicMicroinch,
         Conversions<Unit::Volume, Unit::Volume::CubicMicroinch>::ToStandard<NumericType>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_VOLUME_HPP
