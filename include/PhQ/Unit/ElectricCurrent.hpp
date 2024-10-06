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

#ifndef PHQ_UNIT_ELECTRIC_CURRENT_HPP
#define PHQ_UNIT_ELECTRIC_CURRENT_HPP

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

/// \brief Electric current units.
enum class ElectricCurrent : int8_t {
  /// \brief Ampere (A) electric current unit.
  Ampere,

  /// \brief Kiloampere (kA) electric current unit.
  Kiloampere,

  /// \brief Megaampere (MA) electric current unit.
  Megaampere,

  /// \brief Gigaampere (GA) electric current unit.
  Gigaampere,

  /// \brief Teraampere (TA) electric current unit.
  Teraampere,

  /// \brief Milliampere (mA) electric current unit.
  Milliampere,

  /// \brief Microampere (μA) electric current unit.
  Microampere,

  /// \brief Nanoampere (nA) electric current unit.
  Nanoampere,

  /// \brief Elementary charge per second (e/s) electric current unit.
  ElementaryChargePerSecond,

  /// \brief Elementary charge per minute (e/min) electric current unit.
  ElementaryChargePerMinute,

  /// \brief Elementary charge per hour (e/hr) electric current unit.
  ElementaryChargePerHour,
};

}  // namespace Unit

/// \brief Standard electric current unit: ampere (A).
template <>
inline constexpr const Unit::
    ElectricCurrent Standard<Unit::ElectricCurrent>{Unit::ElectricCurrent::Ampere};

/// \brief Physical dimension set of electric current units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::ElectricCurrent>{
  Dimensions{Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
             Dimension::ElectricCurrent{1}, Dimension::Temperature{0},
             Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::ElectricCurrent unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::ElectricCurrent> ConsistentUnits<Unit::ElectricCurrent>{
  {UnitSystem::MetreKilogramSecondKelvin,  Unit::ElectricCurrent::Ampere},
  {UnitSystem::MillimetreGramSecondKelvin, Unit::ElectricCurrent::Ampere},
  {UnitSystem::FootPoundSecondRankine,     Unit::ElectricCurrent::Ampere},
  {UnitSystem::InchPoundSecondRankine,     Unit::ElectricCurrent::Ampere},
};

template <>
inline const std::map<Unit::ElectricCurrent, UnitSystem>
    RelatedUnitSystems<Unit::ElectricCurrent>{};

// clang-format off

template <>
inline const std::map<Unit::ElectricCurrent, std::string_view> Abbreviations<Unit::ElectricCurrent>{
    {Unit::ElectricCurrent::Ampere,                    "A"    },
    {Unit::ElectricCurrent::Kiloampere,                "kA"   },
    {Unit::ElectricCurrent::Megaampere,                "MA"   },
    {Unit::ElectricCurrent::Gigaampere,                "GA"   },
    {Unit::ElectricCurrent::Teraampere,                "TA"   },
    {Unit::ElectricCurrent::Milliampere,               "mA"   },
    {Unit::ElectricCurrent::Microampere,               "μA"   },
    {Unit::ElectricCurrent::Nanoampere,                "nA"   },
    {Unit::ElectricCurrent::ElementaryChargePerSecond, "e/s"  },
    {Unit::ElectricCurrent::ElementaryChargePerMinute, "e/min"},
    {Unit::ElectricCurrent::ElementaryChargePerHour,   "e/hr" },
};

template <>
inline const std::unordered_map<std::string_view, Unit::ElectricCurrent>
    Spellings<Unit::ElectricCurrent>{
        {"A",     Unit::ElectricCurrent::Ampere                   },
        {"kA",    Unit::ElectricCurrent::Kiloampere               },
        {"MA",    Unit::ElectricCurrent::Megaampere               },
        {"GA",    Unit::ElectricCurrent::Gigaampere               },
        {"TA",    Unit::ElectricCurrent::Teraampere               },
        {"mA",    Unit::ElectricCurrent::Milliampere              },
        {"μA",    Unit::ElectricCurrent::Microampere              },
        {"uA",    Unit::ElectricCurrent::Microampere              },
        {"nA",    Unit::ElectricCurrent::Nanoampere               },
        {"e/s",   Unit::ElectricCurrent::ElementaryChargePerSecond},
        {"e/min", Unit::ElectricCurrent::ElementaryChargePerMinute},
        {"e/hr",  Unit::ElectricCurrent::ElementaryChargePerHour  },
};

// clang-format on

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Ampere>::
    FromStandard(NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Ampere>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Kiloampere>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Kiloampere>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Megaampere>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Megaampere>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Gigaampere>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Gigaampere>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Teraampere>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Teraampere>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Milliampere>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Milliampere>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Microampere>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Microampere>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Nanoampere>::
    FromStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Nanoampere>::
    ToStandard(NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.602176634E-19L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.602176634E-19L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(1.602176634E-19L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.602176634E-19L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1.602176634E-19L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.602176634E-19L) / static_cast<NumericType>(3600.0L);
}

template <typename NumericType>
inline const std::
    map<Unit::ElectricCurrent, std::function<void(NumericType* values, const std::size_t size)>>
        MapOfConversionsFromStandard<Unit::ElectricCurrent, NumericType>{
          {Unit::ElectricCurrent::Ampere,
           Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Ampere>::
               FromStandard<NumericType>},
          {Unit::ElectricCurrent::Kiloampere,
           Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Kiloampere>::
               FromStandard<NumericType>},
          {Unit::ElectricCurrent::Megaampere,
           Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Megaampere>::
               FromStandard<NumericType>},
          {Unit::ElectricCurrent::Gigaampere,
           Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Gigaampere>::
               FromStandard<NumericType>},
          {Unit::ElectricCurrent::Teraampere,
           Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Teraampere>::
               FromStandard<NumericType>},
          {Unit::ElectricCurrent::Milliampere,
           Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Milliampere>::
               FromStandard<NumericType>},
          {Unit::ElectricCurrent::Microampere,
           Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Microampere>::
               FromStandard<NumericType>},
          {Unit::ElectricCurrent::Nanoampere,
           Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Nanoampere>::
               FromStandard<NumericType>},
          {Unit::ElectricCurrent::ElementaryChargePerSecond,
           Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerSecond>::
               FromStandard<NumericType>},
          {Unit::ElectricCurrent::ElementaryChargePerMinute,
           Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerMinute>::
               FromStandard<NumericType>},
          {Unit::ElectricCurrent::ElementaryChargePerHour,
           Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerHour>::
               FromStandard<NumericType>},
};

template <typename NumericType>
inline const std::map<Unit::ElectricCurrent,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::ElectricCurrent, NumericType>{
      {Unit::ElectricCurrent::Ampere,
       Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Ampere>::ToStandard<NumericType>},
      {Unit::ElectricCurrent::Kiloampere,
       Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Kiloampere>::
           ToStandard<NumericType>                      },
      {Unit::ElectricCurrent::Megaampere,
       Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Megaampere>::
           ToStandard<NumericType>                      },
      {Unit::ElectricCurrent::Gigaampere,
       Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Gigaampere>::
           ToStandard<NumericType>                      },
      {Unit::ElectricCurrent::Teraampere,
       Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Teraampere>::
           ToStandard<NumericType>                      },
      {Unit::ElectricCurrent::Milliampere,
       Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Milliampere>::
           ToStandard<NumericType>                      },
      {Unit::ElectricCurrent::Microampere,
       Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Microampere>::
           ToStandard<NumericType>                      },
      {Unit::ElectricCurrent::Nanoampere,
       Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Nanoampere>::
           ToStandard<NumericType>                      },
      {Unit::ElectricCurrent::ElementaryChargePerSecond,
       Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerSecond>::
           ToStandard<NumericType>                      },
      {Unit::ElectricCurrent::ElementaryChargePerMinute,
       Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerMinute>::
           ToStandard<NumericType>                      },
      {Unit::ElectricCurrent::ElementaryChargePerHour,
       Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerHour>::
           ToStandard<NumericType>                      },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ELECTRIC_CURRENT_HPP
