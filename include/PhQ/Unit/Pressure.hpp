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

#ifndef PHQ_UNIT_PRESSURE_HPP
#define PHQ_UNIT_PRESSURE_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/Mass.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

// Pressure units.
enum class Pressure : int8_t {
  // Pascal (Pa) pressure unit.
  Pascal,

  // Kilopascal (kPa) pressure unit.
  Kilopascal,

  // Megapascal (MPa) pressure unit.
  Megapascal,

  // Gigapascal (GPa) pressure unit.
  Gigapascal,

  // Bar (bar) pressure unit.
  Bar,

  // Atmosphere (atm) pressure unit.
  Atmosphere,

  // Pound per square foot (lbf/ft^2) pressure unit.
  PoundPerSquareFoot,

  // Pound per square inch (lbf/in^2) pressure unit.
  PoundPerSquareInch,
};

}  // namespace Unit

// Standard pressure unit: pascal (Pa).
template <>
inline constexpr const Unit::Pressure Standard<Unit::Pressure>{Unit::Pressure::Pascal};

// Physical dimension set of pressure units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Pressure>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{-1}, Dimension::Mass{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Pressure unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Pressure> ConsistentUnits<Unit::Pressure>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Pressure::Pascal            },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Pressure::Pascal            },
    {UnitSystem::FootPoundSecondRankine,     Unit::Pressure::PoundPerSquareFoot},
    {UnitSystem::InchPoundSecondRankine,     Unit::Pressure::PoundPerSquareInch},
};

template <>
inline const std::map<Unit::Pressure, UnitSystem> RelatedUnitSystems<Unit::Pressure>{
    {Unit::Pressure::PoundPerSquareFoot, UnitSystem::FootPoundSecondRankine},
    {Unit::Pressure::PoundPerSquareInch, UnitSystem::InchPoundSecondRankine},
};

template <>
inline const std::map<Unit::Pressure, std::string_view> Abbreviations<Unit::Pressure>{
    {Unit::Pressure::Pascal,             "Pa"      },
    {Unit::Pressure::Kilopascal,         "kPa"     },
    {Unit::Pressure::Megapascal,         "MPa"     },
    {Unit::Pressure::Gigapascal,         "GPa"     },
    {Unit::Pressure::Bar,                "bar"     },
    {Unit::Pressure::Atmosphere,         "atm"     },
    {Unit::Pressure::PoundPerSquareFoot, "lbf/ft^2"},
    {Unit::Pressure::PoundPerSquareInch, "lbf/in^2"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Pressure> Spellings<Unit::Pressure>{
    {"Pa",         Unit::Pressure::Pascal            },
    {"N/m^2",      Unit::Pressure::Pascal            },
    {"N/m2",       Unit::Pressure::Pascal            },
    {"kg/(m·s^2)", Unit::Pressure::Pascal            },
    {"kg/(m·s2)",  Unit::Pressure::Pascal            },
    {"kg/(m*s^2)", Unit::Pressure::Pascal            },
    {"kg/(m*s2)",  Unit::Pressure::Pascal            },
    {"kg/m/s^2",   Unit::Pressure::Pascal            },
    {"kg/m/s2",    Unit::Pressure::Pascal            },
    {"kPa",        Unit::Pressure::Kilopascal        },
    {"kN/m^2",     Unit::Pressure::Kilopascal        },
    {"kN/m2",      Unit::Pressure::Kilopascal        },
    {"MPa",        Unit::Pressure::Megapascal        },
    {"N/mm^2",     Unit::Pressure::Megapascal        },
    {"N/mm2",      Unit::Pressure::Megapascal        },
    {"MN/m^2",     Unit::Pressure::Megapascal        },
    {"MN/m2",      Unit::Pressure::Megapascal        },
    {"GPa",        Unit::Pressure::Gigapascal        },
    {"GN/m^2",     Unit::Pressure::Gigapascal        },
    {"GN/m2",      Unit::Pressure::Gigapascal        },
    {"kN/mm^2",    Unit::Pressure::Gigapascal        },
    {"kN/mm2",     Unit::Pressure::Gigapascal        },
    {"bar",        Unit::Pressure::Bar               },
    {"atm",        Unit::Pressure::Atmosphere        },
    {"atmosphere", Unit::Pressure::Atmosphere        },
    {"lbf/ft^2",   Unit::Pressure::PoundPerSquareFoot},
    {"lbf/ft2",    Unit::Pressure::PoundPerSquareFoot},
    {"lb/ft^2",    Unit::Pressure::PoundPerSquareFoot},
    {"lb/ft2",     Unit::Pressure::PoundPerSquareFoot},
    {"psf",        Unit::Pressure::PoundPerSquareFoot},
    {"lbf/in^2",   Unit::Pressure::PoundPerSquareInch},
    {"lbf/in2",    Unit::Pressure::PoundPerSquareInch},
    {"lb/in^2",    Unit::Pressure::PoundPerSquareInch},
    {"lb/in2",     Unit::Pressure::PoundPerSquareInch},
    {"psi",        Unit::Pressure::PoundPerSquareInch},
};

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Pascal>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Pascal>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Kilopascal>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Kilopascal>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Megapascal>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Megapascal>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Gigapascal>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Gigapascal>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Bar>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.00001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Bar>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(100000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Atmosphere>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(101325.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::Atmosphere>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(101325.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::PoundPerSquareFoot>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::PoundPerSquareFoot>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / (static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::PoundPerSquareInch>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Pressure, Unit::Pressure::PoundPerSquareInch>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / (static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L));
}

template <typename Number>
inline const std::map<Unit::Pressure, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Pressure, Number>{
        {Unit::Pressure::Pascal,
         Conversions<Unit::Pressure, Unit::Pressure::Pascal>::FromStandard<Number>            },
        {Unit::Pressure::Kilopascal,
         Conversions<Unit::Pressure, Unit::Pressure::Kilopascal>::FromStandard<Number>        },
        {Unit::Pressure::Megapascal,
         Conversions<Unit::Pressure, Unit::Pressure::Megapascal>::FromStandard<Number>        },
        {Unit::Pressure::Gigapascal,
         Conversions<Unit::Pressure, Unit::Pressure::Gigapascal>::FromStandard<Number>        },
        {Unit::Pressure::Bar,
         Conversions<Unit::Pressure, Unit::Pressure::Bar>::FromStandard<Number>               },
        {Unit::Pressure::Atmosphere,
         Conversions<Unit::Pressure, Unit::Pressure::Atmosphere>::FromStandard<Number>        },
        {Unit::Pressure::PoundPerSquareFoot,
         Conversions<Unit::Pressure, Unit::Pressure::PoundPerSquareFoot>::FromStandard<Number>},
        {Unit::Pressure::PoundPerSquareInch,
         Conversions<Unit::Pressure, Unit::Pressure::PoundPerSquareInch>::FromStandard<Number>},
};

template <typename Number>
inline const std::map<Unit::Pressure,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Pressure, Number>{
        {Unit::Pressure::Pascal,
         Conversions<Unit::Pressure,                                     Unit::Pressure::Pascal>::ToStandard<Number>            },
        {Unit::Pressure::Kilopascal,
         Conversions<Unit::Pressure,                                     Unit::Pressure::Kilopascal>::ToStandard<Number>        },
        {Unit::Pressure::Megapascal,
         Conversions<Unit::Pressure,                                     Unit::Pressure::Megapascal>::ToStandard<Number>        },
        {Unit::Pressure::Gigapascal,
         Conversions<Unit::Pressure,                                     Unit::Pressure::Gigapascal>::ToStandard<Number>        },
        {Unit::Pressure::Bar,                Conversions<Unit::Pressure, Unit::Pressure::Bar>::ToStandard<Number>               },
        {Unit::Pressure::Atmosphere,
         Conversions<Unit::Pressure,                                     Unit::Pressure::Atmosphere>::ToStandard<Number>        },
        {Unit::Pressure::PoundPerSquareFoot,
         Conversions<Unit::Pressure,                                     Unit::Pressure::PoundPerSquareFoot>::ToStandard<Number>},
        {Unit::Pressure::PoundPerSquareInch,
         Conversions<Unit::Pressure,                                     Unit::Pressure::PoundPerSquareInch>::ToStandard<Number>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_PRESSURE_HPP
