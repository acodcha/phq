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

#ifndef PHQ_UNIT_POWER_HPP
#define PHQ_UNIT_POWER_HPP

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

/// \brief Power units.
enum class Power : int8_t {
  /// \brief Watt (W) power unit.
  Watt,

  /// \brief Milliwatt (mW) power unit.
  Milliwatt,

  /// \brief Microwatt (μW) power unit.
  Microwatt,

  /// \brief Nanowatt (nW) power unit.
  Nanowatt,

  /// \brief Kilowatt (kW) power unit.
  Kilowatt,

  /// \brief Megawatt (MW) power unit.
  Megawatt,

  /// \brief Gigawatt (GW) power unit.
  Gigawatt,

  /// \brief Foot-pound per second (ft·lbf/s) power unit.
  FootPoundPerSecond,

  /// \brief Inch-pound per second (in·lbf/s) power unit.
  InchPoundPerSecond,
};

}  // namespace Unit

/// \brief Standard power unit: watt (W).
template <>
inline constexpr const Unit::Power Standard<Unit::Power>{Unit::Power::Watt};

/// \brief Physical dimension set of power units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Power>{
  Dimensions{Dimension::Time{-3}, Dimension::Length{2}, Dimension::Mass{1},
             Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
             Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Power unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Power> ConsistentUnits<Unit::Power>{
  {UnitSystem::MetreKilogramSecondKelvin,  Unit::Power::Watt              },
  {UnitSystem::MillimetreGramSecondKelvin, Unit::Power::Nanowatt          },
  {UnitSystem::FootPoundSecondRankine,     Unit::Power::FootPoundPerSecond},
  {UnitSystem::InchPoundSecondRankine,     Unit::Power::InchPoundPerSecond},
};

template <>
inline const std::map<Unit::Power, UnitSystem> RelatedUnitSystems<Unit::Power>{
  {Unit::Power::Watt,               UnitSystem::MetreKilogramSecondKelvin },
  {Unit::Power::Nanowatt,           UnitSystem::MillimetreGramSecondKelvin},
  {Unit::Power::FootPoundPerSecond, UnitSystem::FootPoundSecondRankine    },
  {Unit::Power::InchPoundPerSecond, UnitSystem::InchPoundSecondRankine    },
};

// clang-format off

template <>
inline const std::map<Unit::Power, std::string_view> Abbreviations<Unit::Power>{
    {Unit::Power::Watt,               "W"       },
    {Unit::Power::Milliwatt,          "mW"      },
    {Unit::Power::Microwatt,          "μW"      },
    {Unit::Power::Nanowatt,           "nW"      },
    {Unit::Power::Kilowatt,           "kW"      },
    {Unit::Power::Megawatt,           "MW"      },
    {Unit::Power::Gigawatt,           "GW"      },
    {Unit::Power::FootPoundPerSecond, "ft·lbf/s"},
    {Unit::Power::InchPoundPerSecond, "in·lbf/s"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Power> Spellings<Unit::Power>{
    {"W",          Unit::Power::Watt              },
    {"J/s",        Unit::Power::Watt              },
    {"N·m/s",      Unit::Power::Watt              },
    {"N*m/s",      Unit::Power::Watt              },
    {"kg·m^2/s^3", Unit::Power::Watt              },
    {"kg*m^2/s^3", Unit::Power::Watt              },
    {"kg·m2/s3",   Unit::Power::Watt              },
    {"kg*m2/s3",   Unit::Power::Watt              },
    {"mW",         Unit::Power::Milliwatt         },
    {"mJ/s",       Unit::Power::Milliwatt         },
    {"μW",         Unit::Power::Microwatt         },
    {"μJ/s",       Unit::Power::Microwatt         },
    {"uW",         Unit::Power::Microwatt         },
    {"uJ/s",       Unit::Power::Microwatt         },
    {"nW",         Unit::Power::Nanowatt          },
    {"nJ/s",       Unit::Power::Nanowatt          },
    {"μN·mm/s",    Unit::Power::Nanowatt          },
    {"μN*mm/s",    Unit::Power::Nanowatt          },
    {"uN·mm/s",    Unit::Power::Nanowatt          },
    {"uN*mm/s",    Unit::Power::Nanowatt          },
    {"g·mm^2/s^3", Unit::Power::Nanowatt          },
    {"g*mm^2/s^3", Unit::Power::Nanowatt          },
    {"g·mm2/s3",   Unit::Power::Nanowatt          },
    {"g*mm2/s3",   Unit::Power::Nanowatt          },
    {"kW",         Unit::Power::Kilowatt          },
    {"kJ/s",       Unit::Power::Kilowatt          },
    {"MW",         Unit::Power::Megawatt          },
    {"MJ/s",       Unit::Power::Megawatt          },
    {"GW",         Unit::Power::Gigawatt          },
    {"GJ/s",       Unit::Power::Gigawatt          },
    {"ft·lbf/s",   Unit::Power::FootPoundPerSecond},
    {"ft*lbf/s",   Unit::Power::FootPoundPerSecond},
    {"ft·lb/s",    Unit::Power::FootPoundPerSecond},
    {"ft*lb/s",    Unit::Power::FootPoundPerSecond},
    {"in·lbf/s",   Unit::Power::InchPoundPerSecond},
    {"in*lbf/s",   Unit::Power::InchPoundPerSecond},
    {"in·lb/s",    Unit::Power::InchPoundPerSecond},
    {"in*lb/s",    Unit::Power::InchPoundPerSecond},
};

// clang-format on

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Watt>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Watt>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Milliwatt>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Milliwatt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Microwatt>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Microwatt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Nanowatt>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Nanowatt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Kilowatt>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Kilowatt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Megawatt>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Megawatt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Gigawatt>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::Gigawatt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::FootPoundPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.45359237L)
            * static_cast<NumericType>(9.80665L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::FootPoundPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.45359237L)
           * static_cast<NumericType>(9.80665L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::InchPoundPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.45359237L)
            * static_cast<NumericType>(9.80665L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Power, Unit::Power::InchPoundPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.45359237L)
           * static_cast<NumericType>(9.80665L);
}

template <typename NumericType>
inline const std::map<Unit::Power, std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Power, NumericType>{
      {Unit::Power::Watt,               Conversions<Unit::Power, Unit::Power::Watt>::FromStandard<NumericType>              },
      {Unit::Power::Milliwatt,
       Conversions<Unit::Power,                                  Unit::Power::Milliwatt>::FromStandard<NumericType>         },
      {Unit::Power::Microwatt,
       Conversions<Unit::Power,                                  Unit::Power::Microwatt>::FromStandard<NumericType>         },
      {Unit::Power::Nanowatt,
       Conversions<Unit::Power,                                  Unit::Power::Nanowatt>::FromStandard<NumericType>          },
      {Unit::Power::Kilowatt,
       Conversions<Unit::Power,                                  Unit::Power::Kilowatt>::FromStandard<NumericType>          },
      {Unit::Power::Megawatt,
       Conversions<Unit::Power,                                  Unit::Power::Megawatt>::FromStandard<NumericType>          },
      {Unit::Power::Gigawatt,
       Conversions<Unit::Power,                                  Unit::Power::Gigawatt>::FromStandard<NumericType>          },
      {Unit::Power::FootPoundPerSecond,
       Conversions<Unit::Power,                                  Unit::Power::FootPoundPerSecond>::FromStandard<NumericType>},
      {Unit::Power::InchPoundPerSecond,
       Conversions<Unit::Power,                                  Unit::Power::InchPoundPerSecond>::FromStandard<NumericType>},
};

template <typename NumericType>
inline const std::
    map<Unit::Power, std::function<void(NumericType* const values, const std::size_t size)>>
        MapOfConversionsToStandard<Unit::Power, NumericType>{
          {Unit::Power::Watt,               Conversions<Unit::Power, Unit::Power::Watt>::ToStandard<NumericType>              },
          {Unit::Power::Milliwatt,
           Conversions<Unit::Power,                                  Unit::Power::Milliwatt>::ToStandard<NumericType>         },
          {Unit::Power::Microwatt,
           Conversions<Unit::Power,                                  Unit::Power::Microwatt>::ToStandard<NumericType>         },
          {Unit::Power::Nanowatt,
           Conversions<Unit::Power,                                  Unit::Power::Nanowatt>::ToStandard<NumericType>          },
          {Unit::Power::Kilowatt,
           Conversions<Unit::Power,                                  Unit::Power::Kilowatt>::ToStandard<NumericType>          },
          {Unit::Power::Megawatt,
           Conversions<Unit::Power,                                  Unit::Power::Megawatt>::ToStandard<NumericType>          },
          {Unit::Power::Gigawatt,
           Conversions<Unit::Power,                                  Unit::Power::Gigawatt>::ToStandard<NumericType>          },
          {Unit::Power::FootPoundPerSecond,
           Conversions<Unit::Power,                                  Unit::Power::FootPoundPerSecond>::ToStandard<NumericType>},
          {Unit::Power::InchPoundPerSecond,
           Conversions<Unit::Power,                                  Unit::Power::InchPoundPerSecond>::ToStandard<NumericType>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_POWER_HPP
