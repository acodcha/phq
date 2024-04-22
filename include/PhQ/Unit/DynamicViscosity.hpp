// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DYNAMIC_VISCOSITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DYNAMIC_VISCOSITY_HPP

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
    Dimensions{Dimension::Time{-1}, Dimension::Length{-1}, Dimension::Mass{1}}
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
inline constexpr void
ConversionFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::PascalSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::PascalSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::KilopascalSecond>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::KilopascalSecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::MegapascalSecond>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::MegapascalSecond>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::GigapascalSecond>(
    double& value) noexcept {
  value *= 0.000000001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::GigapascalSecond>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::Poise>(
    double& value) noexcept {
  value *= 10.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::Poise>(
    double& value) noexcept {
  value *= 0.1;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::PoundSecondPerSquareFoot>(
    double& value) noexcept {
  value *= 0.3048 * 0.3048 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::PoundSecondPerSquareFoot>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / (0.3048 * 0.3048);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::PoundSecondPerSquareInch>(
    double& value) noexcept {
  value *= 0.0254 * 0.0254 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::PoundSecondPerSquareInch>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 / (0.0254 * 0.0254);
}

template <>
inline const std::map<Unit::DynamicViscosity,
                      std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::DynamicViscosity>{
        {Unit::DynamicViscosity::PascalSecond,
         ConversionsFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::PascalSecond>    },
        {Unit::DynamicViscosity::KilopascalSecond,
         ConversionsFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::KilopascalSecond>},
        {Unit::DynamicViscosity::MegapascalSecond,
         ConversionsFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::MegapascalSecond>},
        {Unit::DynamicViscosity::GigapascalSecond,
         ConversionsFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::GigapascalSecond>},
        {Unit::DynamicViscosity::Poise,
         ConversionsFromStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::Poise>           },
        {Unit::DynamicViscosity::PoundSecondPerSquareFoot,
         ConversionsFromStandard<Unit::DynamicViscosity,
         Unit::DynamicViscosity::PoundSecondPerSquareFoot>                                        },
        {Unit::DynamicViscosity::PoundSecondPerSquareInch,
         ConversionsFromStandard<Unit::DynamicViscosity,
         Unit::DynamicViscosity::PoundSecondPerSquareInch>                                        },
};

template <>
inline const std::map<Unit::DynamicViscosity,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::DynamicViscosity>{
        {Unit::DynamicViscosity::PascalSecond,
         ConversionsToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::PascalSecond>    },
        {Unit::DynamicViscosity::KilopascalSecond,
         ConversionsToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::KilopascalSecond>},
        {Unit::DynamicViscosity::MegapascalSecond,
         ConversionsToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::MegapascalSecond>},
        {Unit::DynamicViscosity::GigapascalSecond,
         ConversionsToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::GigapascalSecond>},
        {Unit::DynamicViscosity::Poise,
         ConversionsToStandard<Unit::DynamicViscosity, Unit::DynamicViscosity::Poise>           },
        {Unit::DynamicViscosity::PoundSecondPerSquareFoot,
         ConversionsToStandard<Unit::DynamicViscosity,
         Unit::DynamicViscosity::PoundSecondPerSquareFoot>                                      },
        {Unit::DynamicViscosity::PoundSecondPerSquareInch,
         ConversionsToStandard<Unit::DynamicViscosity,
         Unit::DynamicViscosity::PoundSecondPerSquareInch>                                      },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DYNAMIC_VISCOSITY_HPP
