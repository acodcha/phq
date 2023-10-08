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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_GRADIENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_GRADIENT_HPP

#include "../Unit.hpp"

namespace PhQ {

namespace Unit {

// Temperature gradient units.
enum class TemperatureGradient : int8_t {
  // Kelvin per metre (K/m) temperature gradient unit.
  KelvinPerMetre,

  // Kelvin per millimetre (K/mm) temperature gradient unit.
  KelvinPerMillimetre,

  // Degree Celsius per metre (°C/m) temperature gradient unit.
  CelsiusPerMetre,

  // Degree Celsius per millimetre (°C/mm) temperature gradient unit.
  CelsiusPerMillimetre,

  // Degree Rankine per foot (°R/ft) temperature gradient unit.
  RankinePerFoot,

  // Degree Rankine per inch (°R/in) temperature gradient unit.
  RankinePerInch,

  // Degree Fahrenheit per foot (°F/ft) temperature gradient unit.
  FahrenheitPerFoot,

  // Degree Fahrenheit per inch (°F/in) temperature gradient unit.
  FahrenheitPerInch,
};

}  // namespace Unit

// Standard temperature gradient unit: kelvin per metre (K/m).
template <>
inline constexpr const Unit::TemperatureGradient
    Standard<Unit::TemperatureGradient>{
        Unit::TemperatureGradient::KelvinPerMetre};

// Physical dimension set of temperature gradient units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::TemperatureGradient>{
    Dimensions{Dimension::Time{}, Dimension::Length{-1}, Dimension::Mass{},
               Dimension::ElectricCurrent{}, Dimension::Temperature{1}}
};

inline std::ostream& operator<<(
    std::ostream& stream, const Unit::TemperatureGradient unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::TemperatureGradient>
    ConsistentUnits<Unit::TemperatureGradient>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::TemperatureGradient::KelvinPerMetre     },
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::TemperatureGradient::KelvinPerMillimetre},
        {UnitSystem::FootPoundSecondRankine,
         Unit::TemperatureGradient::RankinePerFoot     },
        {UnitSystem::InchPoundSecondRankine,
         Unit::TemperatureGradient::RankinePerInch     },
};

template <>
inline const std::map<Unit::TemperatureGradient, UnitSystem>
    RelatedUnitSystems<Unit::TemperatureGradient>{
        {Unit::TemperatureGradient::KelvinPerMetre,
         UnitSystem::MetreKilogramSecondKelvin },
        {Unit::TemperatureGradient::KelvinPerMillimetre,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::TemperatureGradient::RankinePerFoot,
         UnitSystem::FootPoundSecondRankine    },
        {Unit::TemperatureGradient::RankinePerInch,
         UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::TemperatureGradient, std::string_view>
    Abbreviations<Unit::TemperatureGradient>{
        {Unit::TemperatureGradient::KelvinPerMetre,       "K/m"  },
        {Unit::TemperatureGradient::CelsiusPerMetre,      "°C/m" },
        {Unit::TemperatureGradient::KelvinPerMillimetre,  "K/mm" },
        {Unit::TemperatureGradient::CelsiusPerMillimetre, "°C/mm"},
        {Unit::TemperatureGradient::RankinePerFoot,       "°R/ft"},
        {Unit::TemperatureGradient::FahrenheitPerFoot,    "°F/ft"},
        {Unit::TemperatureGradient::RankinePerInch,       "°R/in"},
        {Unit::TemperatureGradient::FahrenheitPerInch,    "°F/in"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::TemperatureGradient>
    Spellings<Unit::TemperatureGradient>{
        {"K/m",     Unit::TemperatureGradient::KelvinPerMetre      },
        {"°K/m",    Unit::TemperatureGradient::KelvinPerMetre      },
        {"degK/m",  Unit::TemperatureGradient::KelvinPerMetre      },
        {"°C/m",    Unit::TemperatureGradient::CelsiusPerMetre     },
        {"C/m",     Unit::TemperatureGradient::CelsiusPerMetre     },
        {"degC/m",  Unit::TemperatureGradient::CelsiusPerMetre     },
        {"K/mm",    Unit::TemperatureGradient::KelvinPerMillimetre },
        {"°K/mm",   Unit::TemperatureGradient::KelvinPerMillimetre },
        {"degK/mm", Unit::TemperatureGradient::KelvinPerMillimetre },
        {"°C/mm",   Unit::TemperatureGradient::CelsiusPerMillimetre},
        {"C/mm",    Unit::TemperatureGradient::CelsiusPerMillimetre},
        {"degC/mm", Unit::TemperatureGradient::CelsiusPerMillimetre},
        {"°R/ft",   Unit::TemperatureGradient::RankinePerFoot      },
        {"R/ft",    Unit::TemperatureGradient::RankinePerFoot      },
        {"degR/ft", Unit::TemperatureGradient::RankinePerFoot      },
        {"°F/ft",   Unit::TemperatureGradient::FahrenheitPerFoot   },
        {"F/ft",    Unit::TemperatureGradient::FahrenheitPerFoot   },
        {"degF/ft", Unit::TemperatureGradient::FahrenheitPerFoot   },
        {"°R/in",   Unit::TemperatureGradient::RankinePerInch      },
        {"R/in",    Unit::TemperatureGradient::RankinePerInch      },
        {"degR/in", Unit::TemperatureGradient::RankinePerInch      },
        {"°F/in",   Unit::TemperatureGradient::FahrenheitPerInch   },
        {"F/in",    Unit::TemperatureGradient::FahrenheitPerInch   },
        {"degF/in", Unit::TemperatureGradient::FahrenheitPerInch   },
};

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureGradient,
                       Unit::TemperatureGradient::KelvinPerMetre>(
    double&) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureGradient,
                       Unit::TemperatureGradient::KelvinPerMillimetre>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureGradient,
                       Unit::TemperatureGradient::CelsiusPerMetre>(
    double&) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureGradient,
                       Unit::TemperatureGradient::CelsiusPerMillimetre>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureGradient,
                       Unit::TemperatureGradient::RankinePerFoot>(
    double& value) noexcept {
  value *= 1.8 * 0.3048;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureGradient,
                       Unit::TemperatureGradient::RankinePerInch>(
    double& value) noexcept {
  value *= 1.8 * 0.0254;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureGradient,
                       Unit::TemperatureGradient::FahrenheitPerFoot>(
    double& value) noexcept {
  value *= 1.8 * 0.3048;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::TemperatureGradient,
                       Unit::TemperatureGradient::FahrenheitPerInch>(
    double& value) noexcept {
  value *= 1.8 * 0.0254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureGradient,
                     Unit::TemperatureGradient::KelvinPerMetre>(
    double&) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureGradient,
                     Unit::TemperatureGradient::KelvinPerMillimetre>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureGradient,
                     Unit::TemperatureGradient::CelsiusPerMetre>(
    double&) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureGradient,
                     Unit::TemperatureGradient::CelsiusPerMillimetre>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureGradient,
                     Unit::TemperatureGradient::RankinePerFoot>(
    double& value) noexcept {
  value /= 1.8 * 0.3048;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureGradient,
                     Unit::TemperatureGradient::RankinePerInch>(
    double& value) noexcept {
  value /= 1.8 * 0.0254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureGradient,
                     Unit::TemperatureGradient::FahrenheitPerFoot>(
    double& value) noexcept {
  value /= 1.8 * 0.3048;
}

template <>
inline constexpr void
ConversionToStandard<Unit::TemperatureGradient,
                     Unit::TemperatureGradient::FahrenheitPerInch>(
    double& value) noexcept {
  value /= 1.8 * 0.0254;
}

template <>
inline const std::map<
    Unit::TemperatureGradient,
    std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::TemperatureGradient>{
        {Unit::TemperatureGradient::KelvinPerMetre,
         ConversionsFromStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMetre>      },
        {Unit::TemperatureGradient::KelvinPerMillimetre,
         ConversionsFromStandard<
             Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMillimetre> },
        {Unit::TemperatureGradient::CelsiusPerMetre,
         ConversionsFromStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMetre>     },
        {Unit::TemperatureGradient::CelsiusPerMillimetre,
         ConversionsFromStandard<
             Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMillimetre>},
        {Unit::TemperatureGradient::RankinePerFoot,
         ConversionsFromStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerFoot>      },
        {Unit::TemperatureGradient::RankinePerInch,
         ConversionsFromStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerInch>      },
        {Unit::TemperatureGradient::FahrenheitPerFoot,
         ConversionsFromStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerFoot>   },
        {Unit::TemperatureGradient::FahrenheitPerInch,
         ConversionsFromStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerInch>   },
};

template <>
inline const std::map<
    Unit::TemperatureGradient,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::TemperatureGradient>{
        {Unit::TemperatureGradient::KelvinPerMetre,
         ConversionsToStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMetre>      },
        {Unit::TemperatureGradient::KelvinPerMillimetre,
         ConversionsToStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMillimetre> },
        {Unit::TemperatureGradient::CelsiusPerMetre,
         ConversionsToStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMetre>     },
        {Unit::TemperatureGradient::CelsiusPerMillimetre,
         ConversionsToStandard<
             Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMillimetre>},
        {Unit::TemperatureGradient::RankinePerFoot,
         ConversionsToStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerFoot>      },
        {Unit::TemperatureGradient::RankinePerInch,
         ConversionsToStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerInch>      },
        {Unit::TemperatureGradient::FahrenheitPerFoot,
         ConversionsToStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerFoot>   },
        {Unit::TemperatureGradient::FahrenheitPerInch,
         ConversionsToStandard<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerInch>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_GRADIENT_HPP
