// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_PRESSURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_PRESSURE_HPP

#include "../Unit.hpp"

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
inline constexpr const Unit::Pressure Standard<Unit::Pressure>{
    Unit::Pressure::Pascal};

// Physical dimension set of pressure units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Pressure>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{-1}, Dimension::Mass{1}}
};

inline std::ostream& operator<<(
    std::ostream& stream, const Unit::Pressure unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Pressure> ConsistentUnits<
    Unit::Pressure>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Pressure::Pascal            },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Pressure::Pascal            },
    {UnitSystem::FootPoundSecondRankine,     Unit::Pressure::PoundPerSquareFoot},
    {UnitSystem::InchPoundSecondRankine,     Unit::Pressure::PoundPerSquareInch},
};

template <>
inline const std::map<Unit::Pressure, UnitSystem> RelatedUnitSystems<
    Unit::Pressure>{
    {Unit::Pressure::PoundPerSquareFoot, UnitSystem::FootPoundSecondRankine},
    {Unit::Pressure::PoundPerSquareInch, UnitSystem::InchPoundSecondRankine},
};

template <>
inline const std::map<Unit::Pressure, std::string_view>
    Abbreviations<Unit::Pressure>{
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
inline const std::unordered_map<std::string_view, Unit::Pressure>
    Spellings<Unit::Pressure>{
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
inline constexpr void
ConversionFromStandard<Unit::Pressure, Unit::Pressure::Pascal>(
    double&) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::Pressure, Unit::Pressure::Kilopascal>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Pressure, Unit::Pressure::Megapascal>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Pressure, Unit::Pressure::Gigapascal>(
    double& value) noexcept {
  value *= 0.000000001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Pressure, Unit::Pressure::Bar>(
    double& value) noexcept {
  value *= 0.00001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Pressure, Unit::Pressure::Atmosphere>(
    double& value) noexcept {
  value /= 101325.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Pressure, Unit::Pressure::PoundPerSquareFoot>(
    double& value) noexcept {
  value *= 0.3048 * 0.3048 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Pressure, Unit::Pressure::PoundPerSquareInch>(
    double& value) noexcept {
  value *= 0.0254 * 0.0254 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionToStandard<Unit::Pressure, Unit::Pressure::Pascal>(double&) noexcept {
}

template <>
inline constexpr void
ConversionToStandard<Unit::Pressure, Unit::Pressure::Kilopascal>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Pressure, Unit::Pressure::Megapascal>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Pressure, Unit::Pressure::Gigapascal>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Pressure, Unit::Pressure::Bar>(
    double& value) noexcept {
  value *= 100000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Pressure, Unit::Pressure::Atmosphere>(
    double& value) noexcept {
  value *= 101325.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Pressure, Unit::Pressure::PoundPerSquareFoot>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / (0.3048 * 0.3048);
}

template <>
inline constexpr void
ConversionToStandard<Unit::Pressure, Unit::Pressure::PoundPerSquareInch>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / (0.0254 * 0.0254);
}

template <>
inline const std::map<
    Unit::Pressure, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Pressure>{
        {Unit::Pressure::Pascal,
         ConversionsFromStandard<Unit::Pressure, Unit::Pressure::Pascal>    },
        {Unit::Pressure::Kilopascal,
         ConversionsFromStandard<Unit::Pressure, Unit::Pressure::Kilopascal>},
        {Unit::Pressure::Megapascal,
         ConversionsFromStandard<Unit::Pressure, Unit::Pressure::Megapascal>},
        {Unit::Pressure::Gigapascal,
         ConversionsFromStandard<Unit::Pressure, Unit::Pressure::Gigapascal>},
        {Unit::Pressure::Bar,
         ConversionsFromStandard<Unit::Pressure, Unit::Pressure::Bar>       },
        {Unit::Pressure::Atmosphere,
         ConversionsFromStandard<Unit::Pressure, Unit::Pressure::Atmosphere>},
        {Unit::Pressure::PoundPerSquareFoot,
         ConversionsFromStandard<Unit::Pressure,
         Unit::Pressure::PoundPerSquareFoot>                                },
        {Unit::Pressure::PoundPerSquareInch,
         ConversionsFromStandard<Unit::Pressure,
         Unit::Pressure::PoundPerSquareInch>                                },
};

template <>
inline const std::map<
    Unit::Pressure,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Pressure>{
        {Unit::Pressure::Pascal,
         ConversionsToStandard<Unit::Pressure, Unit::Pressure::Pascal>    },
        {Unit::Pressure::Kilopascal,
         ConversionsToStandard<Unit::Pressure, Unit::Pressure::Kilopascal>},
        {Unit::Pressure::Megapascal,
         ConversionsToStandard<Unit::Pressure, Unit::Pressure::Megapascal>},
        {Unit::Pressure::Gigapascal,
         ConversionsToStandard<Unit::Pressure, Unit::Pressure::Gigapascal>},
        {Unit::Pressure::Bar,
         ConversionsToStandard<Unit::Pressure, Unit::Pressure::Bar>       },
        {Unit::Pressure::Atmosphere,
         ConversionsToStandard<Unit::Pressure, Unit::Pressure::Atmosphere>},
        {Unit::Pressure::PoundPerSquareFoot,
         ConversionsToStandard<Unit::Pressure,
         Unit::Pressure::PoundPerSquareFoot>                              },
        {Unit::Pressure::PoundPerSquareInch,
         ConversionsToStandard<Unit::Pressure,
         Unit::Pressure::PoundPerSquareInch>                              },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_PRESSURE_HPP
