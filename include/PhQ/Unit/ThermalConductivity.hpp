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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_CONDUCTIVITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_CONDUCTIVITY_HPP

#include "../Unit.hpp"

namespace PhQ {

namespace Unit {

// Thermal conductivity units.
enum class ThermalConductivity : int8_t {
  // Watt per metre per kelvin (W/m/K) thermal conductivity unit.
  WattPerMetrePerKelvin,

  // Nanowatt per millimetre per kelvin (nW/mm/K) thermal conductivity unit.
  NanowattPerMillimetrePerKelvin,

  // Pound per second per degree Rankine (lbf/s/°R) thermal conductivity unit.
  PoundPerSecondPerRankine,
};

}  // namespace Unit

// Standard thermal conductivity unit: watt per metre per kelvin (W/m/K).
template <>
inline constexpr const Unit::ThermalConductivity
    Standard<Unit::ThermalConductivity>{
        Unit::ThermalConductivity::WattPerMetrePerKelvin};

// Physical dimension set of thermal conductivity units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::ThermalConductivity>{
    Dimensions{Dimension::Time{-3}, Dimension::Length{1}, Dimension::Mass{1},
               Dimension::ElectricCurrent{}, Dimension::Temperature{-1}}
};

inline std::ostream& operator<<(
    std::ostream& stream, const Unit::ThermalConductivity unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::ThermalConductivity>
    ConsistentUnits<Unit::ThermalConductivity>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {UnitSystem::FootPoundSecondRankine,
         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {UnitSystem::InchPoundSecondRankine,
         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
};

template <>
inline const std::map<Unit::ThermalConductivity, UnitSystem>
    RelatedUnitSystems<Unit::ThermalConductivity>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin,
         UnitSystem::MetreKilogramSecondKelvin },
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin,
         UnitSystem::MillimetreGramSecondKelvin},
};

template <>
inline const std::map<Unit::ThermalConductivity, std::string_view>
    Abbreviations<Unit::ThermalConductivity>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin,          "W/m/K"   },
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin, "nW/mm/K" },
        {Unit::ThermalConductivity::PoundPerSecondPerRankine,       "lbf/s/°R"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::ThermalConductivity>
    Spellings<Unit::ThermalConductivity>{
        {"W/m/K",           Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/m/°K",          Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/m/degK",        Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/m/°C",          Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/m/degC",        Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/m/C",           Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m·K)",         Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m·°K)",        Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m·degK)",      Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m·°C)",        Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m·degC)",      Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m·C)",         Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m*K)",         Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m*°K)",        Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m*degK)",      Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m*°C)",        Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m*degC)",      Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"W/(m*C)",         Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/s^3/K",      Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/s^3/°K",     Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/s^3/degK",   Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/s^3/C",      Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/s^3/°C",     Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/s^3/degC",   Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/s^3/K",      Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/s^3/°K",     Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/s^3/degK",   Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/s^3/C",      Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/s^3/°C",     Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/s^3/degC",   Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/(s^3·K)",    Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/(s^3·°K)",   Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/(s^3·degK)", Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/(s^3·C)",    Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/(s^3·°C)",   Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg·m/(s^3·degC)", Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/(s^3*K)",    Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/(s^3*°K)",   Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/(s^3*degK)", Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/(s^3*C)",    Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/(s^3*°C)",   Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"kg*m/(s^3*degC)", Unit::ThermalConductivity::WattPerMetrePerKelvin         },
        {"nW/mm/K",         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/mm/°K",        Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/mm/degK",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/mm/°C",         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/mm/degC",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/mm/C",           Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
        {"nW/(mm·K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/(mm·°K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/(mm·degK)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/(mm·°C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/(mm·degC)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/(mm·C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/(mm*K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/(mm*°K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/(mm*degK)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/(mm*°C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/(mm*degC)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"nW/(mm*C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/s^3/K",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/s^3/°K",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/s^3/degK",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/s^3/C",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/s^3/°C",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/s^3/degC",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/s^3/K",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/s^3/°K",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/s^3/degK",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/s^3/C",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/s^3/°C",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/s^3/degC",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/(s^3·K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/(s^3·°K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/(s^3·degK)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/(s^3·C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/(s^3·°C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g·mm/(s^3·degC)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/(s^3*K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/(s^3*°K)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/(s^3*degK)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/(s^3*C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/(s^3*°C)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"g*mm/(s^3*degC)",
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                     },
        {"lbf/s/°R",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/s/R",           Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/s/degR",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/s/°F",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/s/F",           Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/s/degF",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s·°R)",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s·R)",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s·degR)",     Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s·°F)",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s·F)",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s·degF)",     Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s*°R)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s*R)",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s*degR)",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s*°F)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s*F)",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lbf/(s*degF)",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/s/°R",          Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/s/R",            Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/s/degR",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/s/°F",          Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/s/F",            Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/s/degF",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s·°R)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s·R)",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s·degR)",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s·°F)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s·F)",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s·degF)",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s*°R)",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s*R)",          Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s*degR)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s*°F)",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s*F)",          Unit::ThermalConductivity::PoundPerSecondPerRankine      },
        {"lb/(s*degF)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
};

template <>
inline constexpr void
ConversionFromStandard<Unit::ThermalConductivity,
                       Unit::ThermalConductivity::WattPerMetrePerKelvin>(
    double&) noexcept {}

template <>
inline constexpr void ConversionFromStandard<
    Unit::ThermalConductivity,
    Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::ThermalConductivity,
                       Unit::ThermalConductivity::PoundPerSecondPerRankine>(
    double& value) noexcept {
  value /= 0.45359237 * 9.80665 * 1.8;
}

template <>
inline constexpr void
ConversionToStandard<Unit::ThermalConductivity,
                     Unit::ThermalConductivity::WattPerMetrePerKelvin>(
    double&) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::ThermalConductivity,
                     Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::ThermalConductivity,
                     Unit::ThermalConductivity::PoundPerSecondPerRankine>(
    double& value) noexcept {
  value *= 0.45359237 * 9.80665 * 1.8;
}

template <>
inline const std::map<
    Unit::ThermalConductivity,
    std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::ThermalConductivity>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin,
         ConversionsFromStandard<
             Unit::ThermalConductivity,
         Unit::ThermalConductivity::WattPerMetrePerKelvin>         },
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin,
         ConversionsFromStandard<
             Unit::ThermalConductivity,
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>},
        {Unit::ThermalConductivity::PoundPerSecondPerRankine,
         ConversionsFromStandard<
             Unit::ThermalConductivity,
         Unit::ThermalConductivity::PoundPerSecondPerRankine>      },
};

template <>
inline const std::map<
    Unit::ThermalConductivity,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::ThermalConductivity>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin,
         ConversionsToStandard<
             Unit::ThermalConductivity,
         Unit::ThermalConductivity::WattPerMetrePerKelvin>         },
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin,
         ConversionsToStandard<
             Unit::ThermalConductivity,
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>},
        {Unit::ThermalConductivity::PoundPerSecondPerRankine,
         ConversionsToStandard<
             Unit::ThermalConductivity,
         Unit::ThermalConductivity::PoundPerSecondPerRankine>      },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_THERMAL_CONDUCTIVITY_HPP
