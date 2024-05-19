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

#ifndef PHQ_UNIT_DYNAMIC_VISCOSITY_HPP
#define PHQ_UNIT_DYNAMIC_VISCOSITY_HPP

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

// Dynamic viscosity units.
enum class DynamicViscosity : int8_t {
  // Pascal-second (Pa·s) dynamic viscosity unit.
  PascalSecond,

  // Kilopascal-second (kPa·s) dynamic viscosity unit.
  KilopascalSecond,

  // Megapascal-second (MPa·s) dynamic viscosity unit.
  MegapascalSecond,

  // Gigapascal-second (GPa·s) dynamic viscosity unit.
  GigapascalSecond,

  // Poise (P) dynamic viscosity unit.
  Poise,

  // Pound-second per square foot (lbf·s/ft^2) dynamic viscosity unit.
  PoundSecondPerSquareFoot,

  // Pound-second per square inch (lbf·s/in^2) dynamic viscosity unit.
  PoundSecondPerSquareInch,
};

}  // namespace Unit

// Standard dynamic viscosity unit: pascal-second (Pa·s).
template <>
inline constexpr const Unit::DynamicViscosity Standard<Unit::DynamicViscosity>{
    Unit::DynamicViscosity::PascalSecond};

// Physical dimension set of dynamic viscosity units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::DynamicViscosity>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{-1}, Dimension::Mass{1},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::DynamicViscosity unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::DynamicViscosity> ConsistentUnits<Unit::DynamicViscosity>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::DynamicViscosity::PascalSecond            },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::DynamicViscosity::PascalSecond            },
    {UnitSystem::FootPoundSecondRankine,     Unit::DynamicViscosity::PoundSecondPerSquareFoot},
    {UnitSystem::InchPoundSecondRankine,     Unit::DynamicViscosity::PoundSecondPerSquareInch},
};

template <>
inline const std::map<Unit::DynamicViscosity, UnitSystem>
    RelatedUnitSystems<Unit::DynamicViscosity>{
        {Unit::DynamicViscosity::PoundSecondPerSquareFoot, UnitSystem::FootPoundSecondRankine},
        {Unit::DynamicViscosity::PoundSecondPerSquareInch, UnitSystem::InchPoundSecondRankine},
};

template <>
inline const std::map<Unit::DynamicViscosity, std::string_view>
    Abbreviations<Unit::DynamicViscosity>{
        {Unit::DynamicViscosity::PascalSecond,             "Pa·s"      },
        {Unit::DynamicViscosity::KilopascalSecond,         "kPa·s"     },
        {Unit::DynamicViscosity::MegapascalSecond,         "MPa·s"     },
        {Unit::DynamicViscosity::GigapascalSecond,         "GPa·s"     },
        {Unit::DynamicViscosity::Poise,                    "P"         },
        {Unit::DynamicViscosity::PoundSecondPerSquareFoot, "lbf·s/ft^2"},
        {Unit::DynamicViscosity::PoundSecondPerSquareInch, "lbf·s/in^2"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::DynamicViscosity> Spellings<
    Unit::DynamicViscosity>{
    {"Pa·s",       Unit::DynamicViscosity::PascalSecond            },
    {"Pa*s",       Unit::DynamicViscosity::PascalSecond            },
    {"N·s/m^2",    Unit::DynamicViscosity::PascalSecond            },
    {"N·s/m2",     Unit::DynamicViscosity::PascalSecond            },
    {"N*s/m^2",    Unit::DynamicViscosity::PascalSecond            },
    {"N*s/m2",     Unit::DynamicViscosity::PascalSecond            },
    {"kg/(m·s)",   Unit::DynamicViscosity::PascalSecond            },
    {"kg/(m*s)",   Unit::DynamicViscosity::PascalSecond            },
    {"kg/m/s",     Unit::DynamicViscosity::PascalSecond            },
    {"kPa·s",      Unit::DynamicViscosity::KilopascalSecond        },
    {"kPa*s",      Unit::DynamicViscosity::KilopascalSecond        },
    {"kN·s/m^2",   Unit::DynamicViscosity::KilopascalSecond        },
    {"kN·s/m2",    Unit::DynamicViscosity::KilopascalSecond        },
    {"kN*s/m^2",   Unit::DynamicViscosity::KilopascalSecond        },
    {"kN*s/m2",    Unit::DynamicViscosity::KilopascalSecond        },
    {"MPa·s",      Unit::DynamicViscosity::MegapascalSecond        },
    {"MPa*s",      Unit::DynamicViscosity::MegapascalSecond        },
    {"N·s/mm^2",   Unit::DynamicViscosity::MegapascalSecond        },
    {"N·s/mm^2",   Unit::DynamicViscosity::MegapascalSecond        },
    {"N*s/mm2",    Unit::DynamicViscosity::MegapascalSecond        },
    {"N*s/mm2",    Unit::DynamicViscosity::MegapascalSecond        },
    {"MN·s/m^2",   Unit::DynamicViscosity::MegapascalSecond        },
    {"MN·s/m2",    Unit::DynamicViscosity::MegapascalSecond        },
    {"MN*s/m^2",   Unit::DynamicViscosity::MegapascalSecond        },
    {"MN*s/m2",    Unit::DynamicViscosity::MegapascalSecond        },
    {"GPa·s",      Unit::DynamicViscosity::GigapascalSecond        },
    {"GPa*s",      Unit::DynamicViscosity::GigapascalSecond        },
    {"GN·s/m^2",   Unit::DynamicViscosity::GigapascalSecond        },
    {"GN·s/m2",    Unit::DynamicViscosity::GigapascalSecond        },
    {"GN*s/m^2",   Unit::DynamicViscosity::GigapascalSecond        },
    {"GN*s/m2",    Unit::DynamicViscosity::GigapascalSecond        },
    {"kN·s/mm^2",  Unit::DynamicViscosity::GigapascalSecond        },
    {"kN·s/mm2",   Unit::DynamicViscosity::GigapascalSecond        },
    {"kN*s/mm^2",  Unit::DynamicViscosity::GigapascalSecond        },
    {"kN*s/mm2",   Unit::DynamicViscosity::GigapascalSecond        },
    {"P",          Unit::DynamicViscosity::Poise                   },
    {"lbf·s/ft^2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
    {"lbf·s/ft2",  Unit::DynamicViscosity::PoundSecondPerSquareFoot},
    {"lbf*s/ft^2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
    {"lbf*s/ft2",  Unit::DynamicViscosity::PoundSecondPerSquareFoot},
    {"lb·s/ft^2",  Unit::DynamicViscosity::PoundSecondPerSquareFoot},
    {"lb·s/ft2",   Unit::DynamicViscosity::PoundSecondPerSquareFoot},
    {"lb*s/ft^2",  Unit::DynamicViscosity::PoundSecondPerSquareFoot},
    {"lb*s/ft2",   Unit::DynamicViscosity::PoundSecondPerSquareFoot},
    {"psf·s",      Unit::DynamicViscosity::PoundSecondPerSquareFoot},
    {"psf*s",      Unit::DynamicViscosity::PoundSecondPerSquareFoot},
    {"lbf·s/in^2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
    {"lbf·s/in2",  Unit::DynamicViscosity::PoundSecondPerSquareInch},
    {"lbf*s/in^2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
    {"lbf*s/in2",  Unit::DynamicViscosity::PoundSecondPerSquareInch},
    {"lb·s/in^2",  Unit::DynamicViscosity::PoundSecondPerSquareInch},
    {"lb·s/in2",   Unit::DynamicViscosity::PoundSecondPerSquareInch},
    {"lb*s/in^2",  Unit::DynamicViscosity::PoundSecondPerSquareInch},
    {"lb*s/in2",   Unit::DynamicViscosity::PoundSecondPerSquareInch},
    {"psi·s",      Unit::DynamicViscosity::PoundSecondPerSquareInch},
    {"psi*s",      Unit::DynamicViscosity::PoundSecondPerSquareInch},
};

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::PascalSecond>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::PascalSecond>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::KilopascalSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::KilopascalSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::MegapascalSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::MegapascalSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::GigapascalSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000000001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::GigapascalSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::Poise>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(10.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::Poise>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.1L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::PoundSecondPerSquareFoot>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::PoundSecondPerSquareFoot>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / (static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::PoundSecondPerSquareInch>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::DynamicViscosity, Unit::DynamicViscosity::PoundSecondPerSquareInch>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / (static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L));
}

template <typename Number>
inline const std::map<Unit::DynamicViscosity,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::DynamicViscosity, Number>{
        {Unit::DynamicViscosity::PascalSecond,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::PascalSecond>::FromStandard<Number>                             },
        {Unit::DynamicViscosity::KilopascalSecond,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::KilopascalSecond>::FromStandard<Number>                         },
        {Unit::DynamicViscosity::MegapascalSecond,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::MegapascalSecond>::FromStandard<Number>                         },
        {Unit::DynamicViscosity::GigapascalSecond,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::GigapascalSecond>::FromStandard<Number>                         },
        {Unit::DynamicViscosity::Poise,
         Conversions<Unit::DynamicViscosity, Unit::DynamicViscosity::Poise>::FromStandard<Number>},
        {Unit::DynamicViscosity::PoundSecondPerSquareFoot,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::PoundSecondPerSquareFoot>::FromStandard<Number>                 },
        {Unit::DynamicViscosity::PoundSecondPerSquareInch,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::PoundSecondPerSquareInch>::FromStandard<Number>                 },
};

template <typename Number>
inline const std::map<Unit::DynamicViscosity,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::DynamicViscosity, Number>{
        {Unit::DynamicViscosity::PascalSecond,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::PascalSecond>::ToStandard<Number>                             },
        {Unit::DynamicViscosity::KilopascalSecond,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::KilopascalSecond>::ToStandard<Number>                         },
        {Unit::DynamicViscosity::MegapascalSecond,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::MegapascalSecond>::ToStandard<Number>                         },
        {Unit::DynamicViscosity::GigapascalSecond,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::GigapascalSecond>::ToStandard<Number>                         },
        {Unit::DynamicViscosity::Poise,
         Conversions<Unit::DynamicViscosity, Unit::DynamicViscosity::Poise>::ToStandard<Number>},
        {Unit::DynamicViscosity::PoundSecondPerSquareFoot,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::PoundSecondPerSquareFoot>::ToStandard<Number>                 },
        {Unit::DynamicViscosity::PoundSecondPerSquareInch,
         Conversions<Unit::DynamicViscosity,
         Unit::DynamicViscosity::PoundSecondPerSquareInch>::ToStandard<Number>                 },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_DYNAMIC_VISCOSITY_HPP
