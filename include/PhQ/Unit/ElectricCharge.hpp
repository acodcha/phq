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

#ifndef PHQ_UNIT_ELECTRIC_CHARGE_HPP
#define PHQ_UNIT_ELECTRIC_CHARGE_HPP

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

/// \brief Electric charge units.
enum class ElectricCharge : int8_t {
  /// \brief Coulomb (C) electric charge unit.
  Coulomb,

  /// \brief Kilocoulomb (kC) electric charge unit.
  Kilocoulomb,

  /// \brief Megacoulomb (MC) electric charge unit.
  Megacoulomb,

  /// \brief Gigacoulomb (GC) electric charge unit.
  Gigacoulomb,

  /// \brief Teracoulomb (TC) electric charge unit.
  Teracoulomb,

  /// \brief Millicoulomb (mC) electric charge unit.
  Millicoulomb,

  /// \brief Microcoulomb (μC) electric charge unit.
  Microcoulomb,

  /// \brief Nanocoulomb (nC) electric charge unit.
  Nanocoulomb,

  /// \brief Elementary charge (e) electric charge unit.
  ElementaryCharge,

  /// \brief Ampere-minute (A·min) electric charge unit.
  AmpereMinute,

  /// \brief Ampere-hour (A·hr) electric charge unit.
  AmpereHour,

  /// \brief Kiloampere-minute (kA·min) electric charge unit.
  KiloampereMinute,

  /// \brief Kiloampere-hour (kA·hr) electric charge unit.
  KiloampereHour,

  /// \brief Megaampere-minute (MA·min) electric charge unit.
  MegaampereMinute,

  /// \brief Megaampere-hour (MA·hr) electric charge unit.
  MegaampereHour,

  /// \brief Gigaampere-minute (GA·min) electric charge unit.
  GigaampereMinute,

  /// \brief Gigaampere-hour (GA·hr) electric charge unit.
  GigaampereHour,

  /// \brief Teraampere-minute (TA·min) electric charge unit.
  TeraampereMinute,

  /// \brief Teraampere-hour (TA·hr) electric charge unit.
  TeraampereHour,

  /// \brief Milliampere-minute (mA·min) electric charge unit.
  MilliampereMinute,

  /// \brief Milliampere-hour (mA·hr) electric charge unit.
  MilliampereHour,

  /// \brief Microampere-minute (μA·min) electric charge unit.
  MicroampereMinute,

  /// \brief Microampere-hour (μA·hr) electric charge unit.
  MicroampereHour,

  /// \brief Nanoampere-minute (μA·min) electric charge unit.
  NanoampereMinute,

  /// \brief Nanoampere-hour (μA·hr) electric charge unit.
  NanoampereHour,
};

}  // namespace Unit

/// \brief Standard electric charge unit: coulomb (C).
template <>
inline constexpr const Unit::ElectricCharge Standard<Unit::ElectricCharge>{
    Unit::ElectricCharge::Coulomb};

/// \brief Physical dimension set of electric charge units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::ElectricCharge>{
    Dimensions{Dimension::Time{1}, Dimension::Length{0}, Dimension::Mass{0},
               Dimension::ElectricCurrent{1}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::ElectricCharge unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::ElectricCharge> ConsistentUnits<Unit::ElectricCharge>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::ElectricCharge::Coulomb},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::ElectricCharge::Coulomb},
    {UnitSystem::FootPoundSecondRankine,     Unit::ElectricCharge::Coulomb},
    {UnitSystem::InchPoundSecondRankine,     Unit::ElectricCharge::Coulomb},
};

template <>
inline const std::map<Unit::ElectricCharge, UnitSystem> RelatedUnitSystems<Unit::ElectricCharge>{};

// clang-format off

template <>
inline const std::map<Unit::ElectricCharge, std::string_view> Abbreviations<Unit::ElectricCharge>{
    {Unit::ElectricCharge::Coulomb,           "C"     },
    {Unit::ElectricCharge::Kilocoulomb,       "kC"    },
    {Unit::ElectricCharge::Megacoulomb,       "MC"    },
    {Unit::ElectricCharge::Gigacoulomb,       "GC"    },
    {Unit::ElectricCharge::Teracoulomb,       "TC"    },
    {Unit::ElectricCharge::Millicoulomb,      "mC"    },
    {Unit::ElectricCharge::Microcoulomb,      "μC"    },
    {Unit::ElectricCharge::Nanocoulomb,       "nC"    },
    {Unit::ElectricCharge::ElementaryCharge,  "e"     },
    {Unit::ElectricCharge::AmpereMinute,      "A·min" },
    {Unit::ElectricCharge::AmpereHour,        "A·hr"  },
    {Unit::ElectricCharge::KiloampereMinute,  "kA·min"},
    {Unit::ElectricCharge::KiloampereHour,    "kA·hr" },
    {Unit::ElectricCharge::MegaampereMinute,  "MA·min"},
    {Unit::ElectricCharge::MegaampereHour,    "MA·hr" },
    {Unit::ElectricCharge::GigaampereMinute,  "GA·min"},
    {Unit::ElectricCharge::GigaampereHour,    "GA·hr" },
    {Unit::ElectricCharge::TeraampereMinute,  "TA·min"},
    {Unit::ElectricCharge::TeraampereHour,    "TA·hr" },
    {Unit::ElectricCharge::MilliampereMinute, "mA·min"},
    {Unit::ElectricCharge::MilliampereHour,   "mA·hr" },
    {Unit::ElectricCharge::MicroampereMinute, "μA·min"},
    {Unit::ElectricCharge::MicroampereHour,   "μA·hr" },
    {Unit::ElectricCharge::NanoampereMinute,  "nA·min"},
    {Unit::ElectricCharge::NanoampereHour,    "nA·hr" },
};

template <>
inline const std::unordered_map<std::string_view, Unit::ElectricCharge> Spellings<
    Unit::ElectricCharge>{
    {"C",      Unit::ElectricCharge::Coulomb          },
    {"kC",     Unit::ElectricCharge::Kilocoulomb      },
    {"MC",     Unit::ElectricCharge::Megacoulomb      },
    {"GC",     Unit::ElectricCharge::Gigacoulomb      },
    {"TC",     Unit::ElectricCharge::Teracoulomb      },
    {"mC",     Unit::ElectricCharge::Millicoulomb     },
    {"μC",     Unit::ElectricCharge::Microcoulomb     },
    {"uC",     Unit::ElectricCharge::Microcoulomb     },
    {"nC",     Unit::ElectricCharge::Nanocoulomb      },
    {"e",      Unit::ElectricCharge::ElementaryCharge },
    {"A·min",  Unit::ElectricCharge::AmpereMinute     },
    {"A*min",  Unit::ElectricCharge::AmpereMinute     },
    {"A·hr",   Unit::ElectricCharge::AmpereHour       },
    {"A*hr",   Unit::ElectricCharge::AmpereHour       },
    {"kA·min", Unit::ElectricCharge::KiloampereMinute },
    {"kA*min", Unit::ElectricCharge::KiloampereMinute },
    {"kA·hr",  Unit::ElectricCharge::KiloampereHour   },
    {"kA*hr",  Unit::ElectricCharge::KiloampereHour   },
    {"MA·min", Unit::ElectricCharge::MegaampereMinute },
    {"MA*min", Unit::ElectricCharge::MegaampereMinute },
    {"MA·hr",  Unit::ElectricCharge::MegaampereHour   },
    {"MA*hr",  Unit::ElectricCharge::MegaampereHour   },
    {"GA·min", Unit::ElectricCharge::GigaampereMinute },
    {"GA*min", Unit::ElectricCharge::GigaampereMinute },
    {"GA·hr",  Unit::ElectricCharge::GigaampereHour   },
    {"GA*hr",  Unit::ElectricCharge::GigaampereHour   },
    {"TA·min", Unit::ElectricCharge::TeraampereMinute },
    {"TA*min", Unit::ElectricCharge::TeraampereMinute },
    {"TA·hr",  Unit::ElectricCharge::TeraampereHour   },
    {"TA*hr",  Unit::ElectricCharge::TeraampereHour   },
    {"mA·min", Unit::ElectricCharge::MilliampereMinute},
    {"mA*min", Unit::ElectricCharge::MilliampereMinute},
    {"mA·hr",  Unit::ElectricCharge::MilliampereHour  },
    {"mA*hr",  Unit::ElectricCharge::MilliampereHour  },
    {"μA·min", Unit::ElectricCharge::MicroampereMinute},
    {"μA*min", Unit::ElectricCharge::MicroampereMinute},
    {"uA·min", Unit::ElectricCharge::MicroampereMinute},
    {"uA*min", Unit::ElectricCharge::MicroampereMinute},
    {"μA·hr",  Unit::ElectricCharge::MicroampereHour  },
    {"μA*hr",  Unit::ElectricCharge::MicroampereHour  },
    {"uA·hr",  Unit::ElectricCharge::MicroampereHour  },
    {"uA*hr",  Unit::ElectricCharge::MicroampereHour  },
    {"nA·min", Unit::ElectricCharge::NanoampereMinute },
    {"nA*min", Unit::ElectricCharge::NanoampereMinute },
    {"nA·hr",  Unit::ElectricCharge::NanoampereHour   },
    {"nA*hr",  Unit::ElectricCharge::NanoampereHour   },
};

// clang-format on

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Coulomb>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Coulomb>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Kilocoulomb>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Kilocoulomb>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Megacoulomb>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Megacoulomb>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Gigacoulomb>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Gigacoulomb>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Teracoulomb>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-12L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Teracoulomb>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Millicoulomb>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Millicoulomb>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Microcoulomb>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Microcoulomb>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Nanocoulomb>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Nanocoulomb>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::ElementaryCharge>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.602176634E-19L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::ElementaryCharge>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.602176634E-19L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::AmpereMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::AmpereMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::AmpereHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::AmpereHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::KiloampereMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::KiloampereMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::KiloampereHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::KiloampereHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MegaampereMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MegaampereMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MegaampereHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MegaampereHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::GigaampereMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::GigaampereMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::GigaampereHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::GigaampereHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::TeraampereMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60000000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::TeraampereMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60000000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::TeraampereHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600000000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::TeraampereHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600000000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MilliampereMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.06L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MilliampereMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.06L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MilliampereHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3.6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MilliampereHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3.6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MicroampereMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(6.0E-5L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MicroampereMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(6.0E-5L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MicroampereHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3.6E-3L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MicroampereHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3.6E-3L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::NanoampereMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(6.0E-8L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::NanoampereMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(6.0E-8L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::NanoampereHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3.6E-6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::NanoampereHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3.6E-6L);
}

template <typename NumericType>
inline const std::map<Unit::ElectricCharge,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::ElectricCharge, NumericType>{
        {Unit::ElectricCharge::Coulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Coulomb>::FromStandard<NumericType>          },
        {Unit::ElectricCharge::Kilocoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Kilocoulomb>::FromStandard<NumericType>      },
        {Unit::ElectricCharge::Megacoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Megacoulomb>::FromStandard<NumericType>      },
        {Unit::ElectricCharge::Gigacoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Gigacoulomb>::FromStandard<NumericType>      },
        {Unit::ElectricCharge::Teracoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Teracoulomb>::FromStandard<NumericType>      },
        {Unit::ElectricCharge::Millicoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Millicoulomb>::FromStandard<NumericType>     },
        {Unit::ElectricCharge::Microcoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Microcoulomb>::FromStandard<NumericType>     },
        {Unit::ElectricCharge::Nanocoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Nanocoulomb>::FromStandard<NumericType>      },
        {Unit::ElectricCharge::ElementaryCharge,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::ElementaryCharge>::FromStandard<NumericType> },
        {Unit::ElectricCharge::AmpereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::AmpereMinute>::FromStandard<NumericType>     },
        {Unit::ElectricCharge::AmpereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::AmpereHour>::FromStandard<NumericType>       },
        {Unit::ElectricCharge::KiloampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::KiloampereMinute>::FromStandard<NumericType> },
        {Unit::ElectricCharge::KiloampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::KiloampereHour>::FromStandard<NumericType>   },
        {Unit::ElectricCharge::MegaampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MegaampereMinute>::FromStandard<NumericType> },
        {Unit::ElectricCharge::MegaampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MegaampereHour>::FromStandard<NumericType>   },
        {Unit::ElectricCharge::GigaampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::GigaampereMinute>::FromStandard<NumericType> },
        {Unit::ElectricCharge::GigaampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::GigaampereHour>::FromStandard<NumericType>   },
        {Unit::ElectricCharge::TeraampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::TeraampereMinute>::FromStandard<NumericType> },
        {Unit::ElectricCharge::TeraampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::TeraampereHour>::FromStandard<NumericType>   },
        {Unit::ElectricCharge::MilliampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MilliampereMinute>::FromStandard<NumericType>},
        {Unit::ElectricCharge::MilliampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MilliampereHour>::FromStandard<NumericType>  },
        {Unit::ElectricCharge::MicroampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MicroampereMinute>::FromStandard<NumericType>},
        {Unit::ElectricCharge::MicroampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MicroampereHour>::FromStandard<NumericType>  },
        {Unit::ElectricCharge::NanoampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::NanoampereMinute>::FromStandard<NumericType> },
        {Unit::ElectricCharge::NanoampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::NanoampereHour>::FromStandard<NumericType>   },
};

template <typename NumericType>
inline const std::map<Unit::ElectricCharge,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::ElectricCharge, NumericType>{
        {Unit::ElectricCharge::Coulomb,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::Coulomb>::ToStandard<NumericType>},
        {Unit::ElectricCharge::Kilocoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Kilocoulomb>::ToStandard<NumericType>                              },
        {Unit::ElectricCharge::Megacoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Megacoulomb>::ToStandard<NumericType>                              },
        {Unit::ElectricCharge::Gigacoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Gigacoulomb>::ToStandard<NumericType>                              },
        {Unit::ElectricCharge::Teracoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Teracoulomb>::ToStandard<NumericType>                              },
        {Unit::ElectricCharge::Millicoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Millicoulomb>::ToStandard<NumericType>                             },
        {Unit::ElectricCharge::Microcoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Microcoulomb>::ToStandard<NumericType>                             },
        {Unit::ElectricCharge::Nanocoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Nanocoulomb>::ToStandard<NumericType>                              },
        {Unit::ElectricCharge::ElementaryCharge,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::ElementaryCharge>::ToStandard<NumericType>                         },
        {Unit::ElectricCharge::AmpereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::AmpereMinute>::ToStandard<NumericType>                             },
        {Unit::ElectricCharge::AmpereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::AmpereHour>::ToStandard<NumericType>                               },
        {Unit::ElectricCharge::KiloampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::KiloampereMinute>::ToStandard<NumericType>                         },
        {Unit::ElectricCharge::KiloampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::KiloampereHour>::ToStandard<NumericType>                           },
        {Unit::ElectricCharge::MegaampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MegaampereMinute>::ToStandard<NumericType>                         },
        {Unit::ElectricCharge::MegaampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MegaampereHour>::ToStandard<NumericType>                           },
        {Unit::ElectricCharge::GigaampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::GigaampereMinute>::ToStandard<NumericType>                         },
        {Unit::ElectricCharge::GigaampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::GigaampereHour>::ToStandard<NumericType>                           },
        {Unit::ElectricCharge::TeraampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::TeraampereMinute>::ToStandard<NumericType>                         },
        {Unit::ElectricCharge::TeraampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::TeraampereHour>::ToStandard<NumericType>                           },
        {Unit::ElectricCharge::MilliampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MilliampereMinute>::ToStandard<NumericType>                        },
        {Unit::ElectricCharge::MilliampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MilliampereHour>::ToStandard<NumericType>                          },
        {Unit::ElectricCharge::MicroampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MicroampereMinute>::ToStandard<NumericType>                        },
        {Unit::ElectricCharge::MicroampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MicroampereHour>::ToStandard<NumericType>                          },
        {Unit::ElectricCharge::NanoampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::NanoampereMinute>::ToStandard<NumericType>                         },
        {Unit::ElectricCharge::NanoampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::NanoampereHour>::ToStandard<NumericType>                           },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ELECTRIC_CHARGE_HPP
