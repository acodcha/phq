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

/// \brief Standard electric charge unit: radian (C).
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

template <>
template <typename Number>
inline constexpr void Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Coulomb>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Coulomb>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Kilocoulomb>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Kilocoulomb>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Megacoulomb>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Megacoulomb>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Gigacoulomb>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Gigacoulomb>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Teracoulomb>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-12L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Teracoulomb>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E12L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Millicoulomb>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Millicoulomb>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Microcoulomb>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Microcoulomb>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Nanocoulomb>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::Nanocoulomb>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::ElementaryCharge>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.602176634E-19L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::ElementaryCharge>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.602176634E-19L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::AmpereMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::AmpereMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::AmpereHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::AmpereHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::KiloampereMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::KiloampereMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::KiloampereHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::KiloampereHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MegaampereMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MegaampereMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MegaampereHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MegaampereHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::GigaampereMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60000000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::GigaampereMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60000000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::GigaampereHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600000000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::GigaampereHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::TeraampereMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60000000000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::TeraampereMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60000000000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::TeraampereHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600000000000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::TeraampereHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000000000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MilliampereMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.06L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MilliampereMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.06L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MilliampereHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3.6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MilliampereHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3.6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MicroampereMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(6.0E-5L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MicroampereMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(6.0E-5L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MicroampereHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3.6E-3L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::MicroampereHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3.6E-3L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::NanoampereMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(6.0E-8L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::NanoampereMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(6.0E-8L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::NanoampereHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3.6E-6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::ElectricCharge, Unit::ElectricCharge::NanoampereHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3.6E-6L);
}

template <typename Number>
inline const std::map<Unit::ElectricCharge,
                      std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::ElectricCharge, Number>{
        {Unit::ElectricCharge::Coulomb,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::Coulomb>::FromStandard<Number>   },
        {Unit::ElectricCharge::Kilocoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Kilocoulomb>::FromStandard<Number>                                 },
        {Unit::ElectricCharge::Megacoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Megacoulomb>::FromStandard<Number>                                 },
        {Unit::ElectricCharge::Gigacoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Gigacoulomb>::FromStandard<Number>                                 },
        {Unit::ElectricCharge::Teracoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Teracoulomb>::FromStandard<Number>                                 },
        {Unit::ElectricCharge::Millicoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Millicoulomb>::FromStandard<Number>                                },
        {Unit::ElectricCharge::Microcoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Microcoulomb>::FromStandard<Number>                                },
        {Unit::ElectricCharge::Nanocoulomb,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::Nanocoulomb>::FromStandard<Number>                                 },
        {Unit::ElectricCharge::ElementaryCharge,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::ElementaryCharge>::FromStandard<Number>                            },
        {Unit::ElectricCharge::AmpereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::AmpereMinute>::FromStandard<Number>                                },
        {Unit::ElectricCharge::AmpereHour,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::AmpereHour>::FromStandard<Number>},
        {Unit::ElectricCharge::KiloampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::KiloampereMinute>::FromStandard<Number>                            },
        {Unit::ElectricCharge::KiloampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::KiloampereHour>::FromStandard<Number>                              },
        {Unit::ElectricCharge::MegaampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MegaampereMinute>::FromStandard<Number>                            },
        {Unit::ElectricCharge::MegaampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MegaampereHour>::FromStandard<Number>                              },
        {Unit::ElectricCharge::GigaampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::GigaampereMinute>::FromStandard<Number>                            },
        {Unit::ElectricCharge::GigaampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::GigaampereHour>::FromStandard<Number>                              },
        {Unit::ElectricCharge::TeraampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::TeraampereMinute>::FromStandard<Number>                            },
        {Unit::ElectricCharge::TeraampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::TeraampereHour>::FromStandard<Number>                              },
        {Unit::ElectricCharge::MilliampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MilliampereMinute>::FromStandard<Number>                           },
        {Unit::ElectricCharge::MilliampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MilliampereHour>::FromStandard<Number>                             },
        {Unit::ElectricCharge::MicroampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MicroampereMinute>::FromStandard<Number>                           },
        {Unit::ElectricCharge::MicroampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MicroampereHour>::FromStandard<Number>                             },
        {Unit::ElectricCharge::NanoampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::NanoampereMinute>::FromStandard<Number>                            },
        {Unit::ElectricCharge::NanoampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::NanoampereHour>::FromStandard<Number>                              },
};

template <typename Number>
inline const std::map<Unit::ElectricCharge,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::ElectricCharge, Number>{
        {Unit::ElectricCharge::Coulomb,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::Coulomb>::ToStandard<Number>     },
        {Unit::ElectricCharge::Kilocoulomb,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::Kilocoulomb>::ToStandard<Number> },
        {Unit::ElectricCharge::Megacoulomb,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::Megacoulomb>::ToStandard<Number> },
        {Unit::ElectricCharge::Gigacoulomb,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::Gigacoulomb>::ToStandard<Number> },
        {Unit::ElectricCharge::Teracoulomb,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::Teracoulomb>::ToStandard<Number> },
        {Unit::ElectricCharge::Millicoulomb,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::Millicoulomb>::ToStandard<Number>},
        {Unit::ElectricCharge::Microcoulomb,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::Microcoulomb>::ToStandard<Number>},
        {Unit::ElectricCharge::Nanocoulomb,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::Nanocoulomb>::ToStandard<Number> },
        {Unit::ElectricCharge::ElementaryCharge,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::ElementaryCharge>::ToStandard<Number>                              },
        {Unit::ElectricCharge::AmpereMinute,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::AmpereMinute>::ToStandard<Number>},
        {Unit::ElectricCharge::AmpereHour,
         Conversions<Unit::ElectricCharge, Unit::ElectricCharge::AmpereHour>::ToStandard<Number>  },
        {Unit::ElectricCharge::KiloampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::KiloampereMinute>::ToStandard<Number>                              },
        {Unit::ElectricCharge::KiloampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::KiloampereHour>::ToStandard<Number>                                },
        {Unit::ElectricCharge::MegaampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MegaampereMinute>::ToStandard<Number>                              },
        {Unit::ElectricCharge::MegaampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MegaampereHour>::ToStandard<Number>                                },
        {Unit::ElectricCharge::GigaampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::GigaampereMinute>::ToStandard<Number>                              },
        {Unit::ElectricCharge::GigaampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::GigaampereHour>::ToStandard<Number>                                },
        {Unit::ElectricCharge::TeraampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::TeraampereMinute>::ToStandard<Number>                              },
        {Unit::ElectricCharge::TeraampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::TeraampereHour>::ToStandard<Number>                                },
        {Unit::ElectricCharge::MilliampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MilliampereMinute>::ToStandard<Number>                             },
        {Unit::ElectricCharge::MilliampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MilliampereHour>::ToStandard<Number>                               },
        {Unit::ElectricCharge::MicroampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MicroampereMinute>::ToStandard<Number>                             },
        {Unit::ElectricCharge::MicroampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::MicroampereHour>::ToStandard<Number>                               },
        {Unit::ElectricCharge::NanoampereMinute,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::NanoampereMinute>::ToStandard<Number>                              },
        {Unit::ElectricCharge::NanoampereHour,
         Conversions<Unit::ElectricCharge,
         Unit::ElectricCharge::NanoampereHour>::ToStandard<Number>                                },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ELECTRIC_CHARGE_HPP
