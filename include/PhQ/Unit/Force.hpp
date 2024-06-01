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

#ifndef PHQ_UNIT_FORCE_HPP
#define PHQ_UNIT_FORCE_HPP

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

/// \brief Force units.
enum class Force : int8_t {
  /// \brief Newton (N) force unit.
  Newton,

  /// \brief Kilonewton (kN) force unit.
  Kilonewton,

  /// \brief Meganewton (MN) force unit.
  Meganewton,

  /// \brief Giganewton (GN) force unit.
  Giganewton,

  /// \brief Millinewton (mN) force unit.
  Millinewton,

  /// \brief Micronewton (μN) force unit.
  Micronewton,

  /// \brief Nanonewton (nN) force unit.
  Nanonewton,

  /// \brief Dyne (dyn) force unit.
  Dyne,

  /// \brief Pound (lbf) force unit.
  Pound,
};

}  // namespace Unit

/// \brief Standard force unit: newton (N).
template <>
inline constexpr const Unit::Force Standard<Unit::Force>{Unit::Force::Newton};

/// \brief Physical dimension set of force units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Force>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Force unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Force> ConsistentUnits<Unit::Force>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Force::Newton     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Force::Micronewton},
    {UnitSystem::FootPoundSecondRankine,     Unit::Force::Pound      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Force::Pound      },
};

template <>
inline const std::map<Unit::Force, UnitSystem> RelatedUnitSystems<Unit::Force>{
    {Unit::Force::Newton,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Force::Micronewton, UnitSystem::MillimetreGramSecondKelvin},
};

template <>
inline const std::map<Unit::Force, std::string_view> Abbreviations<Unit::Force>{
    {Unit::Force::Newton,      "N"  },
    {Unit::Force::Kilonewton,  "kN" },
    {Unit::Force::Meganewton,  "MN" },
    {Unit::Force::Giganewton,  "GN" },
    {Unit::Force::Millinewton, "mN" },
    {Unit::Force::Micronewton, "μN" },
    {Unit::Force::Nanonewton,  "nN" },
    {Unit::Force::Dyne,        "dyn"},
    {Unit::Force::Pound,       "lbf"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Force> Spellings<Unit::Force>{
    {"N",        Unit::Force::Newton     },
    {"J/m",      Unit::Force::Newton     },
    {"kJ/km",    Unit::Force::Newton     },
    {"kg·m/s^2", Unit::Force::Newton     },
    {"kg*m/s^2", Unit::Force::Newton     },
    {"kg·m/s2",  Unit::Force::Newton     },
    {"kg*m/s2",  Unit::Force::Newton     },
    {"kN",       Unit::Force::Kilonewton },
    {"MN",       Unit::Force::Meganewton },
    {"GN",       Unit::Force::Giganewton },
    {"mN",       Unit::Force::Millinewton},
    {"μN",       Unit::Force::Micronewton},
    {"uN",       Unit::Force::Micronewton},
    {"nJ/mm",    Unit::Force::Micronewton},
    {"g·mm/s^2", Unit::Force::Micronewton},
    {"g*mm/s^2", Unit::Force::Micronewton},
    {"g·mm/s2",  Unit::Force::Micronewton},
    {"g*mm/s2",  Unit::Force::Micronewton},
    {"nN",       Unit::Force::Nanonewton },
    {"dyn",      Unit::Force::Dyne       },
    {"lbf",      Unit::Force::Pound      },
    {"lb",       Unit::Force::Pound      },
};

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Newton>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Newton>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Kilonewton>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Kilonewton>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Meganewton>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Meganewton>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Giganewton>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Giganewton>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Millinewton>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Millinewton>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Micronewton>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Micronewton>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Nanonewton>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Nanonewton>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Dyne>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(100000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Dyne>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.00001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Pound>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Force, Unit::Force::Pound>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.45359237L) * static_cast<NumericType>(9.80665L);
}

template <typename NumericType>
inline const std::map<Unit::Force, std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Force, NumericType>{
        {Unit::Force::Newton,
         Conversions<Unit::Force,                           Unit::Force::Newton>::FromStandard<NumericType>     },
        {Unit::Force::Kilonewton,
         Conversions<Unit::Force,                           Unit::Force::Kilonewton>::FromStandard<NumericType> },
        {Unit::Force::Meganewton,
         Conversions<Unit::Force,                           Unit::Force::Meganewton>::FromStandard<NumericType> },
        {Unit::Force::Giganewton,
         Conversions<Unit::Force,                           Unit::Force::Giganewton>::FromStandard<NumericType> },
        {Unit::Force::Millinewton,
         Conversions<Unit::Force,                           Unit::Force::Millinewton>::FromStandard<NumericType>},
        {Unit::Force::Micronewton,
         Conversions<Unit::Force,                           Unit::Force::Micronewton>::FromStandard<NumericType>},
        {Unit::Force::Nanonewton,
         Conversions<Unit::Force,                           Unit::Force::Nanonewton>::FromStandard<NumericType> },
        {Unit::Force::Dyne,        Conversions<Unit::Force, Unit::Force::Dyne>::FromStandard<NumericType>       },
        {Unit::Force::Pound,
         Conversions<Unit::Force,                           Unit::Force::Pound>::FromStandard<NumericType>      },
};

template <typename NumericType>
inline const std::map<Unit::Force,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Force, NumericType>{
        {Unit::Force::Newton,
         Conversions<Unit::Force,                           Unit::Force::Newton>::ToStandard<NumericType>     },
        {Unit::Force::Kilonewton,
         Conversions<Unit::Force,                           Unit::Force::Kilonewton>::ToStandard<NumericType> },
        {Unit::Force::Meganewton,
         Conversions<Unit::Force,                           Unit::Force::Meganewton>::ToStandard<NumericType> },
        {Unit::Force::Giganewton,
         Conversions<Unit::Force,                           Unit::Force::Giganewton>::ToStandard<NumericType> },
        {Unit::Force::Millinewton,
         Conversions<Unit::Force,                           Unit::Force::Millinewton>::ToStandard<NumericType>},
        {Unit::Force::Micronewton,
         Conversions<Unit::Force,                           Unit::Force::Micronewton>::ToStandard<NumericType>},
        {Unit::Force::Nanonewton,
         Conversions<Unit::Force,                           Unit::Force::Nanonewton>::ToStandard<NumericType> },
        {Unit::Force::Dyne,        Conversions<Unit::Force, Unit::Force::Dyne>::ToStandard<NumericType>       },
        {Unit::Force::Pound,       Conversions<Unit::Force, Unit::Force::Pound>::ToStandard<NumericType>      },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_FORCE_HPP
