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

#ifndef PHQ_UNIT_ENERGY_FLUX_HPP
#define PHQ_UNIT_ENERGY_FLUX_HPP

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

/// \brief Energy flux units.
enum class EnergyFlux : int8_t {
  /// \brief Watt per square metre (W/m^2) energy flux unit.
  WattPerSquareMetre,

  /// \brief Nanowatt per square millimetre (nW/mm^2) energy flux unit.
  NanowattPerSquareMillimetre,

  /// \brief Foot-pound per square foot per second (ft·lbf/ft^2/s) energy flux unit.
  FootPoundPerSquareFootPerSecond,

  /// \brief Inch-pound per square inch per second (in·lbf/in^2/s) energy flux unit.
  InchPoundPerSquareInchPerSecond,
};

}  // namespace Unit

/// \brief Standard energy flux unit: watt per square metre (W/m^2).
template <>
inline constexpr const Unit::EnergyFlux Standard<Unit::EnergyFlux>{
    Unit::EnergyFlux::WattPerSquareMetre};

/// \brief Physical dimension set of energy flux units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::EnergyFlux>{
    Dimensions{Dimension::Time{-3}, Dimension::Length{0}, Dimension::Mass{1},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::EnergyFlux unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::EnergyFlux> ConsistentUnits<Unit::EnergyFlux>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::EnergyFlux::WattPerSquareMetre             },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {UnitSystem::FootPoundSecondRankine,     Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {UnitSystem::InchPoundSecondRankine,     Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
};

template <>
inline const std::map<Unit::EnergyFlux, UnitSystem> RelatedUnitSystems<Unit::EnergyFlux>{
    {Unit::EnergyFlux::WattPerSquareMetre,              UnitSystem::MetreKilogramSecondKelvin },
    {Unit::EnergyFlux::NanowattPerSquareMillimetre,     UnitSystem::MillimetreGramSecondKelvin},
    {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, UnitSystem::FootPoundSecondRankine    },
    {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, UnitSystem::InchPoundSecondRankine    },
};

// clang-format off

template <>
inline const std::map<Unit::EnergyFlux, std::string_view> Abbreviations<Unit::EnergyFlux>{
    {Unit::EnergyFlux::WattPerSquareMetre,              "W/m^2"        },
    {Unit::EnergyFlux::NanowattPerSquareMillimetre,     "nW/mm^2"      },
    {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond, "ft·lbf/ft^2/s"},
    {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond, "in·lbf/in^2/s"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::EnergyFlux> Spellings<Unit::EnergyFlux>{
    {"W/m^2",           Unit::EnergyFlux::WattPerSquareMetre             },
    {"W/m2",            Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m^2·s)",       Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m^2*s)",       Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m2·s)",        Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/(m2*s)",        Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/m^2/s",         Unit::EnergyFlux::WattPerSquareMetre             },
    {"J/m2/s",          Unit::EnergyFlux::WattPerSquareMetre             },
    {"N/(m·s)",         Unit::EnergyFlux::WattPerSquareMetre             },
    {"N/(m*s)",         Unit::EnergyFlux::WattPerSquareMetre             },
    {"N/m/s",           Unit::EnergyFlux::WattPerSquareMetre             },
    {"kg/s^3",          Unit::EnergyFlux::WattPerSquareMetre             },
    {"kg/s3",           Unit::EnergyFlux::WattPerSquareMetre             },
    {"nW/mm^2",         Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nW/mm2",          Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm^2·s)",     Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm^2*s)",     Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm2·s)",      Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/(mm2*s)",      Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/mm^2/s",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"nJ/mm2/s",        Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"μN/(mm·s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"μN/(mm*s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"μN/mm/s",         Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"uN/(mm·s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"uN/(mm*s)",       Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"uN/mm/s",         Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"g/s^3",           Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"g/s3",            Unit::EnergyFlux::NanowattPerSquareMillimetre    },
    {"ft·lbf/(ft^2·s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft·lbf/(ft2·s)",  Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/(ft^2*s)", Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/(ft2*s)",  Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft·lbf/ft^2/s",   Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft·lbf/ft2/s",    Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/ft^2/s",   Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"ft*lbf/ft2/s",    Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"lbf/(ft·s)",      Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"lbf/(ft*s)",      Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"lbf/ft/s",        Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"slug/s^3",        Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"slug/s3",         Unit::EnergyFlux::FootPoundPerSquareFootPerSecond},
    {"in·lbf/(in^2·s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in·lbf/(in2·s)",  Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/(in^2*s)", Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/(in2*s)",  Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in·lbf/in^2/s",   Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in·lbf/in2/s",    Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/in^2/s",   Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"in*lbf/in2/s",    Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"lbf/(in·s)",      Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"lbf/(in*s)",      Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"lbf/in/s",        Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"slinch/s^3",      Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
    {"slinch/s3",       Unit::EnergyFlux::InchPoundPerSquareInchPerSecond},
};

// clang-format on

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::WattPerSquareMetre>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::WattPerSquareMetre>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::NanowattPerSquareMillimetre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::NanowattPerSquareMillimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L)
           / (static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L)
           / static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L)
           / (static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::EnergyFlux, Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L)
           / static_cast<NumericType>(0.0254L);
}

template <typename NumericType>
inline const std::map<Unit::EnergyFlux,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::EnergyFlux, NumericType>{
        {Unit::EnergyFlux::WattPerSquareMetre,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::WattPerSquareMetre>::FromStandard<NumericType>             },
        {Unit::EnergyFlux::NanowattPerSquareMillimetre,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::NanowattPerSquareMillimetre>::FromStandard<NumericType>    },
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>::FromStandard<NumericType>},
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>::FromStandard<NumericType>},
};

template <typename NumericType>
inline const std::map<Unit::EnergyFlux,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::EnergyFlux, NumericType>{
        {Unit::EnergyFlux::WattPerSquareMetre,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::WattPerSquareMetre>::ToStandard<NumericType>             },
        {Unit::EnergyFlux::NanowattPerSquareMillimetre,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::NanowattPerSquareMillimetre>::ToStandard<NumericType>    },
        {Unit::EnergyFlux::FootPoundPerSquareFootPerSecond,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::FootPoundPerSquareFootPerSecond>::ToStandard<NumericType>},
        {Unit::EnergyFlux::InchPoundPerSquareInchPerSecond,
         Conversions<Unit::EnergyFlux,
         Unit::EnergyFlux::InchPoundPerSquareInchPerSecond>::ToStandard<NumericType>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ENERGY_FLUX_HPP
