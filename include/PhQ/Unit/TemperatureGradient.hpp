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

/// \brief Temperature gradient units.
enum class TemperatureGradient : int8_t {
  /// \brief Kelvin per metre (K/m) temperature gradient unit.
  KelvinPerMetre,

  /// \brief Kelvin per millimetre (K/mm) temperature gradient unit.
  KelvinPerMillimetre,

  /// \brief Degree Celsius per metre (°C/m) temperature gradient unit.
  CelsiusPerMetre,

  /// \brief Degree Celsius per millimetre (°C/mm) temperature gradient unit.
  CelsiusPerMillimetre,

  /// \brief Degree Rankine per foot (°R/ft) temperature gradient unit.
  RankinePerFoot,

  /// \brief Degree Rankine per inch (°R/in) temperature gradient unit.
  RankinePerInch,

  /// \brief Degree Fahrenheit per foot (°F/ft) temperature gradient unit.
  FahrenheitPerFoot,

  /// \brief Degree Fahrenheit per inch (°F/in) temperature gradient unit.
  FahrenheitPerInch,
};

}  // namespace Unit

/// \brief Standard temperature gradient unit: kelvin per metre (K/m).
template <>
inline constexpr const Unit::TemperatureGradient Standard<Unit::TemperatureGradient>{
    Unit::TemperatureGradient::KelvinPerMetre};

/// \brief Physical dimension set of temperature gradient units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::TemperatureGradient>{
    Dimensions{Dimension::Time{0}, Dimension::Length{-1}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{1},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
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

// clang-format off

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

// clang-format on

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::KelvinPerMetre>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::KelvinPerMetre>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::KelvinPerMillimetre>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::KelvinPerMillimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::CelsiusPerMetre>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::CelsiusPerMetre>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::CelsiusPerMillimetre>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::CelsiusPerMillimetre>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::RankinePerFoot>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.8L) * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::RankinePerFoot>::ToStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1.8L) * static_cast<NumericType>(0.3048L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::RankinePerInch>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.8L) * static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::RankinePerInch>::ToStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1.8L) * static_cast<NumericType>(0.0254L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::FahrenheitPerFoot>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.8L) * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::FahrenheitPerFoot>::ToStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1.8L) * static_cast<NumericType>(0.3048L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::FahrenheitPerInch>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.8L) * static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::TemperatureGradient, Unit::TemperatureGradient::FahrenheitPerInch>::ToStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1.8L) * static_cast<NumericType>(0.0254L));
}

template <typename NumericType>
inline const std::map<Unit::TemperatureGradient,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::TemperatureGradient, NumericType>{
        {Unit::TemperatureGradient::KelvinPerMetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMetre>::FromStandard<NumericType>      },
        {Unit::TemperatureGradient::KelvinPerMillimetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMillimetre>::FromStandard<NumericType> },
        {Unit::TemperatureGradient::CelsiusPerMetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMetre>::FromStandard<NumericType>     },
        {Unit::TemperatureGradient::CelsiusPerMillimetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMillimetre>::FromStandard<NumericType>},
        {Unit::TemperatureGradient::RankinePerFoot,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerFoot>::FromStandard<NumericType>      },
        {Unit::TemperatureGradient::RankinePerInch,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerInch>::FromStandard<NumericType>      },
        {Unit::TemperatureGradient::FahrenheitPerFoot,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerFoot>::FromStandard<NumericType>   },
        {Unit::TemperatureGradient::FahrenheitPerInch,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerInch>::FromStandard<NumericType>   },
};

template <typename NumericType>
inline const std::map<Unit::TemperatureGradient,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::TemperatureGradient, NumericType>{
        {Unit::TemperatureGradient::KelvinPerMetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMetre>::ToStandard<NumericType>      },
        {Unit::TemperatureGradient::KelvinPerMillimetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::KelvinPerMillimetre>::ToStandard<NumericType> },
        {Unit::TemperatureGradient::CelsiusPerMetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMetre>::ToStandard<NumericType>     },
        {Unit::TemperatureGradient::CelsiusPerMillimetre,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::CelsiusPerMillimetre>::ToStandard<NumericType>},
        {Unit::TemperatureGradient::RankinePerFoot,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerFoot>::ToStandard<NumericType>      },
        {Unit::TemperatureGradient::RankinePerInch,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::RankinePerInch>::ToStandard<NumericType>      },
        {Unit::TemperatureGradient::FahrenheitPerFoot,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerFoot>::ToStandard<NumericType>   },
        {Unit::TemperatureGradient::FahrenheitPerInch,
         Conversions<Unit::TemperatureGradient,
         Unit::TemperatureGradient::FahrenheitPerInch>::ToStandard<NumericType>   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_TEMPERATURE_GRADIENT_HPP
