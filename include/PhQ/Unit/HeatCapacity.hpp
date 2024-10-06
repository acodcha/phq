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

#ifndef PHQ_UNIT_HEAT_CAPACITY_HPP
#define PHQ_UNIT_HEAT_CAPACITY_HPP

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

/// \brief Heat capacity units.
enum class HeatCapacity : int8_t {
  /// \brief Joule per kelvin (J/K) heat capacity unit.
  JoulePerKelvin,

  /// \brief Nanojoule per kelvin (nJ/K) heat capacity unit.
  NanojoulePerKelvin,

  /// \brief Foot-pound per degree Rankine (ft·lbf/°R) heat capacity unit.
  FootPoundPerRankine,

  /// \brief Inch-pound per degree Rankine (in·lbf/°R) heat capacity unit.
  InchPoundPerRankine,
};

}  // namespace Unit

/// \brief Standard heat capacity unit: joule per kelvin (J/K).
template <>
inline constexpr const Unit::
    HeatCapacity Standard<Unit::HeatCapacity>{Unit::HeatCapacity::JoulePerKelvin};

/// \brief Physical dimension set of heat capacity units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::HeatCapacity>{
  Dimensions{Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1},
             Dimension::ElectricCurrent{0}, Dimension::Temperature{-1},
             Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::HeatCapacity unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::HeatCapacity> ConsistentUnits<Unit::HeatCapacity>{
  {UnitSystem::MetreKilogramSecondKelvin,  Unit::HeatCapacity::JoulePerKelvin     },
  {UnitSystem::MillimetreGramSecondKelvin, Unit::HeatCapacity::NanojoulePerKelvin },
  {UnitSystem::FootPoundSecondRankine,     Unit::HeatCapacity::FootPoundPerRankine},
  {UnitSystem::InchPoundSecondRankine,     Unit::HeatCapacity::InchPoundPerRankine},
};

template <>
inline const std::map<Unit::HeatCapacity, UnitSystem> RelatedUnitSystems<Unit::HeatCapacity>{
  {Unit::HeatCapacity::JoulePerKelvin,      UnitSystem::MetreKilogramSecondKelvin },
  {Unit::HeatCapacity::NanojoulePerKelvin,  UnitSystem::MillimetreGramSecondKelvin},
  {Unit::HeatCapacity::FootPoundPerRankine, UnitSystem::FootPoundSecondRankine    },
  {Unit::HeatCapacity::InchPoundPerRankine, UnitSystem::InchPoundSecondRankine    },
};

// clang-format off

template <>
inline const std::map<Unit::HeatCapacity, std::string_view> Abbreviations<Unit::HeatCapacity>{
    {Unit::HeatCapacity::JoulePerKelvin,      "J/K"      },
    {Unit::HeatCapacity::NanojoulePerKelvin,  "nJ/K"     },
    {Unit::HeatCapacity::FootPoundPerRankine, "ft·lbf/°R"},
    {Unit::HeatCapacity::InchPoundPerRankine, "in·lbf/°R"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::HeatCapacity> Spellings<Unit::HeatCapacity>{
    {"J/K",            Unit::HeatCapacity::JoulePerKelvin     },
    {"N·m/K",          Unit::HeatCapacity::JoulePerKelvin     },
    {"N*m/K",          Unit::HeatCapacity::JoulePerKelvin     },
    {"kg·m^2/s^2/K",   Unit::HeatCapacity::JoulePerKelvin     },
    {"kg*m^2/s^2/K",   Unit::HeatCapacity::JoulePerKelvin     },
    {"kg·m2/s2/K",     Unit::HeatCapacity::JoulePerKelvin     },
    {"kg*m2/s2/K",     Unit::HeatCapacity::JoulePerKelvin     },
    {"kg·m^2/(s^2·K)", Unit::HeatCapacity::JoulePerKelvin     },
    {"kg*m^2/(s^2*K)", Unit::HeatCapacity::JoulePerKelvin     },
    {"kg·m2/(s2·K)",   Unit::HeatCapacity::JoulePerKelvin     },
    {"kg*m2/(s2*K)",   Unit::HeatCapacity::JoulePerKelvin     },
    {"nJ/K",           Unit::HeatCapacity::NanojoulePerKelvin },
    {"μN·mm/K",        Unit::HeatCapacity::NanojoulePerKelvin },
    {"μN*mm/K",        Unit::HeatCapacity::NanojoulePerKelvin },
    {"uN·mm/K",        Unit::HeatCapacity::NanojoulePerKelvin },
    {"uN*mm/K",        Unit::HeatCapacity::NanojoulePerKelvin },
    {"g·mm^2/s^2/K",   Unit::HeatCapacity::NanojoulePerKelvin },
    {"g*mm^2/s^2/K",   Unit::HeatCapacity::NanojoulePerKelvin },
    {"g·mm2/s2/K",     Unit::HeatCapacity::NanojoulePerKelvin },
    {"g*mm2/s2/K",     Unit::HeatCapacity::NanojoulePerKelvin },
    {"g·mm^2/(s^2·K)", Unit::HeatCapacity::NanojoulePerKelvin },
    {"g*mm^2/(s^2*K)", Unit::HeatCapacity::NanojoulePerKelvin },
    {"g·mm2/(s2·K)",   Unit::HeatCapacity::NanojoulePerKelvin },
    {"g*mm2/(s2*K)",   Unit::HeatCapacity::NanojoulePerKelvin },
    {"ft·lbf/°R",      Unit::HeatCapacity::FootPoundPerRankine},
    {"ft·lbf/R",       Unit::HeatCapacity::FootPoundPerRankine},
    {"ft*lbf/°R",      Unit::HeatCapacity::FootPoundPerRankine},
    {"ft*lbf/R",       Unit::HeatCapacity::FootPoundPerRankine},
    {"ft·lb/°R",       Unit::HeatCapacity::FootPoundPerRankine},
    {"ft·lb/R",        Unit::HeatCapacity::FootPoundPerRankine},
    {"ft*lb/°R",       Unit::HeatCapacity::FootPoundPerRankine},
    {"ft*lb/R",        Unit::HeatCapacity::FootPoundPerRankine},
    {"in·lbf/°R",      Unit::HeatCapacity::InchPoundPerRankine},
    {"in·lbf/R",       Unit::HeatCapacity::InchPoundPerRankine},
    {"in*lbf/°R",      Unit::HeatCapacity::InchPoundPerRankine},
    {"in*lbf/R",       Unit::HeatCapacity::InchPoundPerRankine},
    {"in·lb/°R",       Unit::HeatCapacity::InchPoundPerRankine},
    {"in·lb/R",        Unit::HeatCapacity::InchPoundPerRankine},
    {"in*lb/°R",       Unit::HeatCapacity::InchPoundPerRankine},
    {"in*lb/R",        Unit::HeatCapacity::InchPoundPerRankine},
};

// clang-format on

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::HeatCapacity, Unit::HeatCapacity::JoulePerKelvin>::
    FromStandard(NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::HeatCapacity, Unit::HeatCapacity::JoulePerKelvin>::
    ToStandard(NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::HeatCapacity, Unit::HeatCapacity::NanojoulePerKelvin>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::HeatCapacity, Unit::HeatCapacity::NanojoulePerKelvin>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::HeatCapacity, Unit::HeatCapacity::FootPoundPerRankine>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.45359237L)
           * static_cast<NumericType>(9.80665L) * static_cast<NumericType>(1.8L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::HeatCapacity, Unit::HeatCapacity::FootPoundPerRankine>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.45359237L)
           * static_cast<NumericType>(9.80665L) * static_cast<NumericType>(1.8L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::HeatCapacity, Unit::HeatCapacity::InchPoundPerRankine>::
    FromStandard(NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.45359237L)
           * static_cast<NumericType>(9.80665L) * static_cast<NumericType>(1.8L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::HeatCapacity, Unit::HeatCapacity::InchPoundPerRankine>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.45359237L)
           * static_cast<NumericType>(9.80665L) * static_cast<NumericType>(1.8L);
}

template <typename NumericType>
inline const std::
    map<Unit::HeatCapacity, std::function<void(NumericType* values, const std::size_t size)>>
        MapOfConversionsFromStandard<Unit::HeatCapacity, NumericType>{
          {Unit::HeatCapacity::JoulePerKelvin,
           Conversions<Unit::HeatCapacity, Unit::HeatCapacity::JoulePerKelvin>::
               FromStandard<NumericType>},
          {Unit::HeatCapacity::NanojoulePerKelvin,
           Conversions<Unit::HeatCapacity, Unit::HeatCapacity::NanojoulePerKelvin>::
               FromStandard<NumericType>},
          {Unit::HeatCapacity::FootPoundPerRankine,
           Conversions<Unit::HeatCapacity, Unit::HeatCapacity::FootPoundPerRankine>::
               FromStandard<NumericType>},
          {Unit::HeatCapacity::InchPoundPerRankine,
           Conversions<Unit::HeatCapacity, Unit::HeatCapacity::InchPoundPerRankine>::
               FromStandard<NumericType>},
};

template <typename NumericType>
inline const std::
    map<Unit::HeatCapacity, std::function<void(NumericType* const values, const std::size_t size)>>
        MapOfConversionsToStandard<Unit::HeatCapacity, NumericType>{
          {Unit::HeatCapacity::JoulePerKelvin,
           Conversions<Unit::HeatCapacity, Unit::HeatCapacity::JoulePerKelvin>::
               ToStandard<NumericType>},
          {Unit::HeatCapacity::NanojoulePerKelvin,
           Conversions<Unit::HeatCapacity, Unit::HeatCapacity::NanojoulePerKelvin>::
               ToStandard<NumericType>},
          {Unit::HeatCapacity::FootPoundPerRankine,
           Conversions<Unit::HeatCapacity, Unit::HeatCapacity::FootPoundPerRankine>::
               ToStandard<NumericType>},
          {Unit::HeatCapacity::InchPoundPerRankine,
           Conversions<Unit::HeatCapacity, Unit::HeatCapacity::InchPoundPerRankine>::
               ToStandard<NumericType>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_HEAT_CAPACITY_HPP
