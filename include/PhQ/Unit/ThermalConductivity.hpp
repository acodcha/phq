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

#ifndef PHQ_UNIT_THERMAL_CONDUCTIVITY_HPP
#define PHQ_UNIT_THERMAL_CONDUCTIVITY_HPP

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

/// \brief Thermal conductivity units.
enum class ThermalConductivity : int8_t {
  /// \brief Watt per metre per kelvin (W/m/K) thermal conductivity unit.
  WattPerMetrePerKelvin,

  /// \brief Nanowatt per millimetre per kelvin (nW/mm/K) thermal conductivity unit.
  NanowattPerMillimetrePerKelvin,

  /// \brief Pound per second per degree Rankine (lbf/s/°R) thermal conductivity unit.
  PoundPerSecondPerRankine,
};

}  // namespace Unit

/// \brief Standard thermal conductivity unit: watt per metre per kelvin (W/m/K).
template <>
inline constexpr const Unit::ThermalConductivity Standard<Unit::ThermalConductivity>{
    Unit::ThermalConductivity::WattPerMetrePerKelvin};

/// \brief Physical dimension set of thermal conductivity units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::ThermalConductivity>{
    Dimensions{Dimension::Time{-3}, Dimension::Length{1}, Dimension::Mass{1},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{-1},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::ThermalConductivity unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::ThermalConductivity>
    ConsistentUnits<Unit::ThermalConductivity>{
        {UnitSystem::MetreKilogramSecondKelvin,  Unit::ThermalConductivity::WattPerMetrePerKelvin   },
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin                                  },
        {UnitSystem::FootPoundSecondRankine,     Unit::ThermalConductivity::PoundPerSecondPerRankine},
        {UnitSystem::InchPoundSecondRankine,     Unit::ThermalConductivity::PoundPerSecondPerRankine},
};

template <>
inline const std::map<Unit::ThermalConductivity, UnitSystem>
    RelatedUnitSystems<Unit::ThermalConductivity>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin,          UnitSystem::MetreKilogramSecondKelvin},
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin,
         UnitSystem::MillimetreGramSecondKelvin                                                          },
};

template <>
inline const std::map<Unit::ThermalConductivity, std::string_view>
    Abbreviations<Unit::ThermalConductivity>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin,          "W/m/K"   },
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin, "nW/mm/K" },
        {Unit::ThermalConductivity::PoundPerSecondPerRankine,       "lbf/s/°R"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::ThermalConductivity> Spellings<
    Unit::ThermalConductivity>{
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
    {"nW/mm/degK",      Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/mm/°C",        Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/mm/degC",      Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/mm/C",         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm·K)",       Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm·°K)",      Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm·degK)",    Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm·°C)",      Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm·degC)",    Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm·C)",       Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm*K)",       Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm*°K)",      Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm*degK)",    Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm*°C)",      Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm*degC)",    Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"nW/(mm*C)",       Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/s^3/K",      Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/s^3/°K",     Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/s^3/degK",   Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/s^3/C",      Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/s^3/°C",     Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/s^3/degC",   Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/s^3/K",      Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/s^3/°K",     Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/s^3/degK",   Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/s^3/C",      Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/s^3/°C",     Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/s^3/degC",   Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/(s^3·K)",    Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/(s^3·°K)",   Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/(s^3·degK)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/(s^3·C)",    Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/(s^3·°C)",   Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g·mm/(s^3·degC)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/(s^3*K)",    Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/(s^3*°K)",   Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/(s^3*degK)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/(s^3*C)",    Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/(s^3*°C)",   Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"g*mm/(s^3*degC)", Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin},
    {"lbf/s/°R",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/s/R",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/s/degR",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/s/°F",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/s/F",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/s/degF",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s·°R)",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s·R)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s·degR)",    Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s·°F)",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s·F)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s·degF)",    Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s*°R)",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s*R)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s*degR)",    Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s*°F)",      Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s*F)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lbf/(s*degF)",    Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/s/°R",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/s/R",          Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/s/degR",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/s/°F",         Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/s/F",          Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/s/degF",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s·°R)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s·R)",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s·degR)",     Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s·°F)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s·F)",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s·degF)",     Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s*°R)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s*R)",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s*degR)",     Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s*°F)",       Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s*F)",        Unit::ThermalConductivity::PoundPerSecondPerRankine      },
    {"lb/(s*degF)",     Unit::ThermalConductivity::PoundPerSecondPerRankine      },
};

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ThermalConductivity, Unit::ThermalConductivity::WattPerMetrePerKelvin>::
    FromStandard(NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ThermalConductivity, Unit::ThermalConductivity::WattPerMetrePerKelvin>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ThermalConductivity, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ThermalConductivity, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ThermalConductivity, Unit::ThermalConductivity::PoundPerSecondPerRankine>::
    FromStandard(NumericType& value) noexcept {
  value /= (static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L)
            * static_cast<NumericType>(1.8L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ThermalConductivity, Unit::ThermalConductivity::PoundPerSecondPerRankine>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L)
           * static_cast<NumericType>(1.8L);
}

template <typename NumericType>
inline const std::map<Unit::ThermalConductivity,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::ThermalConductivity, NumericType>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin,
         Conversions<Unit::ThermalConductivity,
         Unit::ThermalConductivity::WattPerMetrePerKelvin>::FromStandard<NumericType>         },
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin,
         Conversions<
             Unit::ThermalConductivity,
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>::FromStandard<NumericType>},
        {Unit::ThermalConductivity::PoundPerSecondPerRankine,
         Conversions<
             Unit::ThermalConductivity,
         Unit::ThermalConductivity::PoundPerSecondPerRankine>::FromStandard<NumericType>      },
};

template <typename NumericType>
inline const std::map<Unit::ThermalConductivity,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::ThermalConductivity, NumericType>{
        {Unit::ThermalConductivity::WattPerMetrePerKelvin,
         Conversions<Unit::ThermalConductivity,
         Unit::ThermalConductivity::WattPerMetrePerKelvin>::ToStandard<NumericType>         },
        {Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin,
         Conversions<
             Unit::ThermalConductivity,
         Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>::ToStandard<NumericType>},
        {Unit::ThermalConductivity::PoundPerSecondPerRankine,
         Conversions<Unit::ThermalConductivity,
         Unit::ThermalConductivity::PoundPerSecondPerRankine>::ToStandard<NumericType>      },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_THERMAL_CONDUCTIVITY_HPP
