// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
inline constexpr const Unit::ElectricCurrent Standard<Unit::ElectricCurrent>{
    Unit::ElectricCurrent::Ampere};

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

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Ampere>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Ampere>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Kiloampere>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Kiloampere>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Megaampere>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Megaampere>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Gigaampere>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Gigaampere>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Teraampere>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-12L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Teraampere>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E12L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Milliampere>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Milliampere>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Microampere>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Microampere>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Nanoampere>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::Nanoampere>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.602176634E-19L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.602176634E-19L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(1.602176634E-19L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.602176634E-19L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1.602176634E-19L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCurrent, Unit::ElectricCurrent::ElementaryChargePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.602176634E-19L) / static_cast<Number>(3600.0L);
}

template <typename Number>
inline const std::map<Unit::ElectricCurrent,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::ElectricCurrent, Number>{
        {Unit::ElectricCurrent::Ampere,
         Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Ampere>::FromStandard<Number>},
        {Unit::ElectricCurrent::Kiloampere,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::Kiloampere>::FromStandard<Number>                               },
        {Unit::ElectricCurrent::Megaampere,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::Megaampere>::FromStandard<Number>                               },
        {Unit::ElectricCurrent::Gigaampere,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::Gigaampere>::FromStandard<Number>                               },
        {Unit::ElectricCurrent::Teraampere,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::Teraampere>::FromStandard<Number>                               },
        {Unit::ElectricCurrent::Milliampere,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::Milliampere>::FromStandard<Number>                              },
        {Unit::ElectricCurrent::Microampere,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::Microampere>::FromStandard<Number>                              },
        {Unit::ElectricCurrent::Nanoampere,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::Nanoampere>::FromStandard<Number>                               },
        {Unit::ElectricCurrent::ElementaryChargePerSecond,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::ElementaryChargePerSecond>::FromStandard<Number>                },
        {Unit::ElectricCurrent::ElementaryChargePerMinute,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::ElementaryChargePerMinute>::FromStandard<Number>                },
        {Unit::ElectricCurrent::ElementaryChargePerHour,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::ElementaryChargePerHour>::FromStandard<Number>                  },
};

template <typename Number>
inline const std::map<Unit::ElectricCurrent,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::ElectricCurrent, Number>{
        {Unit::ElectricCurrent::Ampere,
         Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Ampere>::ToStandard<Number>    },
        {Unit::ElectricCurrent::Kiloampere,
         Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Kiloampere>::ToStandard<Number>},
        {Unit::ElectricCurrent::Megaampere,
         Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Megaampere>::ToStandard<Number>},
        {Unit::ElectricCurrent::Gigaampere,
         Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Gigaampere>::ToStandard<Number>},
        {Unit::ElectricCurrent::Teraampere,
         Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Teraampere>::ToStandard<Number>},
        {Unit::ElectricCurrent::Milliampere,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::Milliampere>::ToStandard<Number>                                  },
        {Unit::ElectricCurrent::Microampere,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::Microampere>::ToStandard<Number>                                  },
        {Unit::ElectricCurrent::Nanoampere,
         Conversions<Unit::ElectricCurrent, Unit::ElectricCurrent::Nanoampere>::ToStandard<Number>},
        {Unit::ElectricCurrent::ElementaryChargePerSecond,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::ElementaryChargePerSecond>::ToStandard<Number>                    },
        {Unit::ElectricCurrent::ElementaryChargePerMinute,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::ElementaryChargePerMinute>::ToStandard<Number>                    },
        {Unit::ElectricCurrent::ElementaryChargePerHour,
         Conversions<Unit::ElectricCurrent,
         Unit::ElectricCurrent::ElementaryChargePerHour>::ToStandard<Number>                      },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ELECTRIC_CURRENT_HPP
