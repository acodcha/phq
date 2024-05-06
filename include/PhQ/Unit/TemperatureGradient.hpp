// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#ifndef PHQ_UNIT_TEMPERATURE_GRADIENT_HPP
#define PHQ_UNIT_TEMPERATURE_GRADIENT_HPP

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
#include "../Dimension/Mass.hpp"
#include "../Dimension/Temperature.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

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
inline constexpr const Unit::TemperatureGradient Standard<Unit::TemperatureGradient>{
    Unit::TemperatureGradient::KelvinPerMetre};

// Physical dimension set of temperature gradient units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::TemperatureGradient>{
    Dimensions{Dimension::Time{}, Dimension::Length{-1}, Dimension::Mass{},
               Dimension::ElectricCurrent{}, Dimension::Temperature{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::TemperatureGradient unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::TemperatureGradient>
    ConsistentUnits<Unit::TemperatureGradient>{
        {UnitSystem::MetreKilogramSecondKelvin,  Unit::TemperatureGradient::KelvinPerMetre     },
        {UnitSystem::MillimetreGramSecondKelvin, Unit::TemperatureGradient::KelvinPerMillimetre},
        {UnitSystem::FootPoundSecondRankine,     Unit::TemperatureGradient::RankinePerFoot     },
        {UnitSystem::InchPoundSecondRankine,     Unit::TemperatureGradient::RankinePerInch     },
};

template <>
inline const std::map<Unit::TemperatureGradient, UnitSystem>
    RelatedUnitSystems<Unit::TemperatureGradient>{
        {Unit::TemperatureGradient::KelvinPerMetre,      UnitSystem::MetreKilogramSecondKelvin },
        {Unit::TemperatureGradient::KelvinPerMillimetre, UnitSystem::MillimetreGramSecondKelvin},
        {Unit::TemperatureGradient::RankinePerFoot,      UnitSystem::FootPoundSecondRankine    },
        {Unit::TemperatureGradient::RankinePerInch,      UnitSystem::InchPoundSecondRankine    },
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
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::KelvinPerMetre>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::KelvinPerMetre>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::KelvinPerMillimetre>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::KelvinPerMillimetre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::CelsiusPerMetre>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::CelsiusPerMetre>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient,
           Unit::TemperatureGradient::CelsiusPerMillimetre>::FromStandard(Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::CelsiusPerMillimetre>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::RankinePerFoot>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.8L) * static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::RankinePerFoot>::ToStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(1.8L) * static_cast<Number>(0.3048L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::RankinePerInch>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.8L) * static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::RankinePerInch>::ToStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(1.8L) * static_cast<Number>(0.0254L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::FahrenheitPerFoot>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.8L) * static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::FahrenheitPerFoot>::ToStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(1.8L) * static_cast<Number>(0.3048L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::FahrenheitPerInch>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.8L) * static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::FahrenheitPerInch>::ToStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(1.8L) * static_cast<Number>(0.0254L));
}

template <typename Number>
inline const std::map<Unit::TemperatureGradient,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::TemperatureGradient, Number>{
        {Unit::TemperatureGradient::KelvinPerMetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMetre>::FromStandard<Number>      },
        {Unit::TemperatureGradient::KelvinPerMillimetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMillimetre>::FromStandard<Number> },
        {Unit::TemperatureGradient::CelsiusPerMetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMetre>::FromStandard<Number>     },
        {Unit::TemperatureGradient::CelsiusPerMillimetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMillimetre>::FromStandard<Number>},
        {Unit::TemperatureGradient::RankinePerFoot,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerFoot>::FromStandard<Number>      },
        {Unit::TemperatureGradient::RankinePerInch,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerInch>::FromStandard<Number>      },
        {Unit::TemperatureGradient::FahrenheitPerFoot,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerFoot>::FromStandard<Number>   },
        {Unit::TemperatureGradient::FahrenheitPerInch,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerInch>::FromStandard<Number>   },
};

template <typename Number>
inline const std::map<Unit::TemperatureGradient,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::TemperatureGradient, Number>{
        {Unit::TemperatureGradient::KelvinPerMetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMetre>::ToStandard<Number>      },
        {Unit::TemperatureGradient::KelvinPerMillimetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMillimetre>::ToStandard<Number> },
        {Unit::TemperatureGradient::CelsiusPerMetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMetre>::ToStandard<Number>     },
        {Unit::TemperatureGradient::CelsiusPerMillimetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMillimetre>::ToStandard<Number>},
        {Unit::TemperatureGradient::RankinePerFoot,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerFoot>::ToStandard<Number>      },
        {Unit::TemperatureGradient::RankinePerInch,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerInch>::ToStandard<Number>      },
        {Unit::TemperatureGradient::FahrenheitPerFoot,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerFoot>::ToStandard<Number>   },
        {Unit::TemperatureGradient::FahrenheitPerInch,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerInch>::ToStandard<Number>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_TEMPERATURE_GRADIENT_HPP
