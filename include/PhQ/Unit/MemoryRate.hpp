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

#ifndef PHQ_UNIT_MEMORY_RATE_HPP
#define PHQ_UNIT_MEMORY_RATE_HPP

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

/// \brief Computer memory rate unit. Can represent the time rate of change of memory or a memory
/// transfer speed.
enum class MemoryRate : int8_t {
  /// \brief Bit per second (b/s) memory rate unit.
  BitPerSecond,

  /// \brief Byte per second (B/s) memory rate unit.
  BytePerSecond,

  /// \brief Kilobit per second (kb/s) memory rate unit.
  KilobitPerSecond,

  /// \brief Kibibit per second (kib/s) memory rate unit.
  KibibitPerSecond,

  /// \brief Kilobyte per second (kB/s) memory rate unit.
  KilobytePerSecond,

  /// \brief Kibibyte per second (kiB/s) memory rate unit.
  KibibytePerSecond,

  /// \brief Megabit per second (Mb/s) memory rate unit.
  MegabitPerSecond,

  /// \brief Mebibit per second (Mib/s) memory rate unit.
  MebibitPerSecond,

  /// \brief Megabyte per second (MB/s) memory rate unit.
  MegabytePerSecond,

  /// \brief Mebibyte per second (MiB/s) memory rate unit.
  MebibytePerSecond,

  /// \brief Gigabit per second (Gb/s) memory rate unit.
  GigabitPerSecond,

  /// \brief Gibibit per second (Gib/s) memory rate unit.
  GibibitPerSecond,

  /// \brief Gigabyte per second (GB/s) memory rate unit.
  GigabytePerSecond,

  /// \brief Gibibyte per second (GiB/s) memory rate unit.
  GibibytePerSecond,

  /// \brief Terabit per second (Tb/s) memory rate unit.
  TerabitPerSecond,

  /// \brief Tebibit per second (Tib/s) memory rate unit.
  TebibitPerSecond,

  /// \brief Terabyte per second (TB/s) memory rate unit.
  TerabytePerSecond,

  /// \brief Tebibyte per second (TiB/s) memory rate unit.
  TebibytePerSecond,

  /// \brief Petabit per second (Pb/s) memory rate unit.
  PetabitPerSecond,

  /// \brief Pebibit per second (Pib/s) memory rate unit.
  PebibitPerSecond,

  /// \brief Petabyte per second (PB/s) memory rate unit.
  PetabytePerSecond,

  /// \brief Pebibyte per second (PiB/s) memory rate unit.
  PebibytePerSecond,

  /// \brief Bit per minute (b/min) memory rate unit.
  BitPerMinute,

  /// \brief Byte per minute (B/min) memory rate unit.
  BytePerMinute,

  /// \brief Kilobit per minute (kb/min) memory rate unit.
  KilobitPerMinute,

  /// \brief Kibibit per minute (kib/min) memory rate unit.
  KibibitPerMinute,

  /// \brief Kilobyte per minute (kB/min) memory rate unit.
  KilobytePerMinute,

  /// \brief Kibibyte per minute (kiB/min) memory rate unit.
  KibibytePerMinute,

  /// \brief Megabit per minute (Mb/min) memory rate unit.
  MegabitPerMinute,

  /// \brief Mebibit per minute (Mib/min) memory rate unit.
  MebibitPerMinute,

  /// \brief Megabyte per minute (MB/min) memory rate unit.
  MegabytePerMinute,

  /// \brief Mebibyte per minute (MiB/min) memory rate unit.
  MebibytePerMinute,

  /// \brief Gigabit per minute (Gb/min) memory rate unit.
  GigabitPerMinute,

  /// \brief Gibibit per minute (Gib/min) memory rate unit.
  GibibitPerMinute,

  /// \brief Gigabyte per minute (GB/min) memory rate unit.
  GigabytePerMinute,

  /// \brief Gibibyte per minute (GiB/min) memory rate unit.
  GibibytePerMinute,

  /// \brief Terabit per minute (Tb/min) memory rate unit.
  TerabitPerMinute,

  /// \brief Tebibit per minute (Tib/min) memory rate unit.
  TebibitPerMinute,

  /// \brief Terabyte per minute (TB/min) memory rate unit.
  TerabytePerMinute,

  /// \brief Tebibyte per minute (TiB/min) memory rate unit.
  TebibytePerMinute,

  /// \brief Petabit per minute (Pb/min) memory rate unit.
  PetabitPerMinute,

  /// \brief Pebibit per minute (Pib/min) memory rate unit.
  PebibitPerMinute,

  /// \brief Petabyte per minute (PB/min) memory rate unit.
  PetabytePerMinute,

  /// \brief Pebibyte per minute (PiB/min) memory rate unit.
  PebibytePerMinute,

  /// \brief Bit per hour (b/hr) memory rate unit.
  BitPerHour,

  /// \brief Byte per hour (B/hr) memory rate unit.
  BytePerHour,

  /// \brief Kilobit per hour (kb/hr) memory rate unit.
  KilobitPerHour,

  /// \brief Kibibit per hour (kib/hr) memory rate unit.
  KibibitPerHour,

  /// \brief Kilobyte per hour (kB/hr) memory rate unit.
  KilobytePerHour,

  /// \brief Kibibyte per hour (kiB/hr) memory rate unit.
  KibibytePerHour,

  /// \brief Megabit per hour (Mb/hr) memory rate unit.
  MegabitPerHour,

  /// \brief Mebibit per hour (Mib/hr) memory rate unit.
  MebibitPerHour,

  /// \brief Megabyte per hour (MB/hr) memory rate unit.
  MegabytePerHour,

  /// \brief Mebibyte per hour (MiB/hr) memory rate unit.
  MebibytePerHour,

  /// \brief Gigabit per hour (Gb/hr) memory rate unit.
  GigabitPerHour,

  /// \brief Gibibit per hour (Gib/hr) memory rate unit.
  GibibitPerHour,

  /// \brief Gigabyte per hour (GB/hr) memory rate unit.
  GigabytePerHour,

  /// \brief Gibibyte per hour (GiB/hr) memory rate unit.
  GibibytePerHour,

  /// \brief Terabit per hour (Tb/hr) memory rate unit.
  TerabitPerHour,

  /// \brief Tebibit per hour (Tib/hr) memory rate unit.
  TebibitPerHour,

  /// \brief Terabyte per hour (TB/hr) memory rate unit.
  TerabytePerHour,

  /// \brief Tebibyte per hour (TiB/hr) memory rate unit.
  TebibytePerHour,

  /// \brief Petabit per hour (Pb/hr) memory rate unit.
  PetabitPerHour,

  /// \brief Pebibit per hour (Pib/hr) memory rate unit.
  PebibitPerHour,

  /// \brief Petabyte per hour (PB/hr) memory rate unit.
  PetabytePerHour,

  /// \brief Pebibyte per hour (PiB/hr) memory rate unit.
  PebibytePerHour,
};

}  // namespace Unit

/// \brief Standard computer memory rate unit: bit per second (b/s).
template <>
inline constexpr const Unit::MemoryRate Standard<Unit::MemoryRate>{Unit::MemoryRate::BitPerSecond};

/// \brief Physical dimension set of computer memory rate units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::MemoryRate>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{0}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::MemoryRate unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::MemoryRate> ConsistentUnits<Unit::MemoryRate>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::MemoryRate::BitPerSecond},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::MemoryRate::BitPerSecond},
    {UnitSystem::FootPoundSecondRankine,     Unit::MemoryRate::BitPerSecond},
    {UnitSystem::InchPoundSecondRankine,     Unit::MemoryRate::BitPerSecond},
};

template <>
inline const std::map<Unit::MemoryRate, UnitSystem> RelatedUnitSystems<Unit::MemoryRate>{};

template <>
inline const std::map<Unit::MemoryRate, std::string_view> Abbreviations<Unit::MemoryRate>{
    {Unit::MemoryRate::BitPerSecond,      "b/s"    },
    {Unit::MemoryRate::BytePerSecond,     "B/s"    },
    {Unit::MemoryRate::KilobitPerSecond,  "kb/s"   },
    {Unit::MemoryRate::KibibitPerSecond,  "kib/s"  },
    {Unit::MemoryRate::KilobytePerSecond, "kB/s"   },
    {Unit::MemoryRate::KibibytePerSecond, "kiB/s"  },
    {Unit::MemoryRate::MegabitPerSecond,  "Mb/s"   },
    {Unit::MemoryRate::MebibitPerSecond,  "Mib/s"  },
    {Unit::MemoryRate::MegabytePerSecond, "MB/s"   },
    {Unit::MemoryRate::MebibytePerSecond, "MiB/s"  },
    {Unit::MemoryRate::GigabitPerSecond,  "Gb/s"   },
    {Unit::MemoryRate::GibibitPerSecond,  "Gib/s"  },
    {Unit::MemoryRate::GigabytePerSecond, "GB/s"   },
    {Unit::MemoryRate::GibibytePerSecond, "GiB/s"  },
    {Unit::MemoryRate::TerabitPerSecond,  "Tb/s"   },
    {Unit::MemoryRate::TebibitPerSecond,  "Tib/s"  },
    {Unit::MemoryRate::TerabytePerSecond, "TB/s"   },
    {Unit::MemoryRate::TebibytePerSecond, "TiB/s"  },
    {Unit::MemoryRate::PetabitPerSecond,  "Pb/s"   },
    {Unit::MemoryRate::PebibitPerSecond,  "Pib/s"  },
    {Unit::MemoryRate::PetabytePerSecond, "PB/s"   },
    {Unit::MemoryRate::PebibytePerSecond, "PiB/s"  },
    {Unit::MemoryRate::BitPerMinute,      "b/min"  },
    {Unit::MemoryRate::BytePerMinute,     "B/min"  },
    {Unit::MemoryRate::KilobitPerMinute,  "kb/min" },
    {Unit::MemoryRate::KibibitPerMinute,  "kib/min"},
    {Unit::MemoryRate::KilobytePerMinute, "kB/min" },
    {Unit::MemoryRate::KibibytePerMinute, "kiB/min"},
    {Unit::MemoryRate::MegabitPerMinute,  "Mb/min" },
    {Unit::MemoryRate::MebibitPerMinute,  "Mib/min"},
    {Unit::MemoryRate::MegabytePerMinute, "MB/min" },
    {Unit::MemoryRate::MebibytePerMinute, "MiB/min"},
    {Unit::MemoryRate::GigabitPerMinute,  "Gb/min" },
    {Unit::MemoryRate::GibibitPerMinute,  "Gib/min"},
    {Unit::MemoryRate::GigabytePerMinute, "GB/min" },
    {Unit::MemoryRate::GibibytePerMinute, "GiB/min"},
    {Unit::MemoryRate::TerabitPerMinute,  "Tb/min" },
    {Unit::MemoryRate::TebibitPerMinute,  "Tib/min"},
    {Unit::MemoryRate::TerabytePerMinute, "TB/min" },
    {Unit::MemoryRate::TebibytePerMinute, "TiB/min"},
    {Unit::MemoryRate::PetabitPerMinute,  "Pb/min" },
    {Unit::MemoryRate::PebibitPerMinute,  "Pib/min"},
    {Unit::MemoryRate::PetabytePerMinute, "PB/min" },
    {Unit::MemoryRate::PebibytePerMinute, "PiB/min"},
    {Unit::MemoryRate::BitPerHour,        "b/hr"   },
    {Unit::MemoryRate::BytePerHour,       "B/hr"   },
    {Unit::MemoryRate::KilobitPerHour,    "kb/hr"  },
    {Unit::MemoryRate::KibibitPerHour,    "kib/hr" },
    {Unit::MemoryRate::KilobytePerHour,   "kB/hr"  },
    {Unit::MemoryRate::KibibytePerHour,   "kiB/hr" },
    {Unit::MemoryRate::MegabitPerHour,    "Mb/hr"  },
    {Unit::MemoryRate::MebibitPerHour,    "Mib/hr" },
    {Unit::MemoryRate::MegabytePerHour,   "MB/hr"  },
    {Unit::MemoryRate::MebibytePerHour,   "MiB/hr" },
    {Unit::MemoryRate::GigabitPerHour,    "Gb/hr"  },
    {Unit::MemoryRate::GibibitPerHour,    "Gib/hr" },
    {Unit::MemoryRate::GigabytePerHour,   "GB/hr"  },
    {Unit::MemoryRate::GibibytePerHour,   "GiB/hr" },
    {Unit::MemoryRate::TerabitPerHour,    "Tb/hr"  },
    {Unit::MemoryRate::TebibitPerHour,    "Tib/hr" },
    {Unit::MemoryRate::TerabytePerHour,   "TB/hr"  },
    {Unit::MemoryRate::TebibytePerHour,   "TiB/hr" },
    {Unit::MemoryRate::PetabitPerHour,    "Pb/hr"  },
    {Unit::MemoryRate::PebibitPerHour,    "Pib/hr" },
    {Unit::MemoryRate::PetabytePerHour,   "PB/hr"  },
    {Unit::MemoryRate::PebibytePerHour,   "PiB/hr" },
};

template <>
inline const std::unordered_map<std::string_view, Unit::MemoryRate> Spellings<Unit::MemoryRate>{
    {"b/s",     Unit::MemoryRate::BitPerSecond     },
    {"B/s",     Unit::MemoryRate::BytePerSecond    },
    {"kb/s",    Unit::MemoryRate::KilobitPerSecond },
    {"kB/s",    Unit::MemoryRate::KilobytePerSecond},
    {"kib/s",   Unit::MemoryRate::KibibitPerSecond },
    {"kiB/s",   Unit::MemoryRate::KibibytePerSecond},
    {"Mb/s",    Unit::MemoryRate::MegabitPerSecond },
    {"MB/s",    Unit::MemoryRate::MegabytePerSecond},
    {"Mib/s",   Unit::MemoryRate::MebibitPerSecond },
    {"MiB/s",   Unit::MemoryRate::MebibytePerSecond},
    {"Gb/s",    Unit::MemoryRate::GigabitPerSecond },
    {"GB/s",    Unit::MemoryRate::GigabytePerSecond},
    {"Gib/s",   Unit::MemoryRate::GibibitPerSecond },
    {"GiB/s",   Unit::MemoryRate::GibibytePerSecond},
    {"Tb/s",    Unit::MemoryRate::TerabitPerSecond },
    {"TB/s",    Unit::MemoryRate::TerabytePerSecond},
    {"Tib/s",   Unit::MemoryRate::TebibitPerSecond },
    {"TiB/s",   Unit::MemoryRate::TebibytePerSecond},
    {"Pb/s",    Unit::MemoryRate::PetabitPerSecond },
    {"PB/s",    Unit::MemoryRate::PetabytePerSecond},
    {"Pib/s",   Unit::MemoryRate::PebibitPerSecond },
    {"PiB/s",   Unit::MemoryRate::PebibytePerSecond},
    {"b/min",   Unit::MemoryRate::BitPerMinute     },
    {"B/min",   Unit::MemoryRate::BytePerMinute    },
    {"kb/min",  Unit::MemoryRate::KilobitPerMinute },
    {"kB/min",  Unit::MemoryRate::KilobytePerMinute},
    {"kib/min", Unit::MemoryRate::KibibitPerMinute },
    {"kiB/min", Unit::MemoryRate::KibibytePerMinute},
    {"Mb/min",  Unit::MemoryRate::MegabitPerMinute },
    {"MB/min",  Unit::MemoryRate::MegabytePerMinute},
    {"Mib/min", Unit::MemoryRate::MebibitPerMinute },
    {"MiB/min", Unit::MemoryRate::MebibytePerMinute},
    {"Gb/min",  Unit::MemoryRate::GigabitPerMinute },
    {"GB/min",  Unit::MemoryRate::GigabytePerMinute},
    {"Gib/min", Unit::MemoryRate::GibibitPerMinute },
    {"GiB/min", Unit::MemoryRate::GibibytePerMinute},
    {"Tb/min",  Unit::MemoryRate::TerabitPerMinute },
    {"TB/min",  Unit::MemoryRate::TerabytePerMinute},
    {"Tib/min", Unit::MemoryRate::TebibitPerMinute },
    {"TiB/min", Unit::MemoryRate::TebibytePerMinute},
    {"Pb/min",  Unit::MemoryRate::PetabitPerMinute },
    {"PB/min",  Unit::MemoryRate::PetabytePerMinute},
    {"Pib/min", Unit::MemoryRate::PebibitPerMinute },
    {"PiB/min", Unit::MemoryRate::PebibytePerMinute},
    {"b/hr",    Unit::MemoryRate::BitPerHour       },
    {"B/hr",    Unit::MemoryRate::BytePerHour      },
    {"kb/hr",   Unit::MemoryRate::KilobitPerHour   },
    {"kB/hr",   Unit::MemoryRate::KilobytePerHour  },
    {"kib/hr",  Unit::MemoryRate::KibibitPerHour   },
    {"kiB/hr",  Unit::MemoryRate::KibibytePerHour  },
    {"Mb/hr",   Unit::MemoryRate::MegabitPerHour   },
    {"MB/hr",   Unit::MemoryRate::MegabytePerHour  },
    {"Mib/hr",  Unit::MemoryRate::MebibitPerHour   },
    {"MiB/hr",  Unit::MemoryRate::MebibytePerHour  },
    {"Gb/hr",   Unit::MemoryRate::GigabitPerHour   },
    {"GB/hr",   Unit::MemoryRate::GigabytePerHour  },
    {"Gib/hr",  Unit::MemoryRate::GibibitPerHour   },
    {"GiB/hr",  Unit::MemoryRate::GibibytePerHour  },
    {"Tb/hr",   Unit::MemoryRate::TerabitPerHour   },
    {"TB/hr",   Unit::MemoryRate::TerabytePerHour  },
    {"Tib/hr",  Unit::MemoryRate::TebibitPerHour   },
    {"TiB/hr",  Unit::MemoryRate::TebibytePerHour  },
    {"Pb/hr",   Unit::MemoryRate::PetabitPerHour   },
    {"PB/hr",   Unit::MemoryRate::PetabytePerHour  },
    {"Pib/hr",  Unit::MemoryRate::PebibitPerHour   },
    {"PiB/hr",  Unit::MemoryRate::PebibytePerHour  },
};

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.125L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(8000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(8000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(8.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(8.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-15L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E15L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(8.0E15L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E15L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(8.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(8000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8000.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(8000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8000000.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / (static_cast<NumericType>(8.0E9L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E9L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(1.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E12L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(8.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E12L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(1.0E15L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E15L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(8.0E15L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E15L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerHour>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(8.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(8000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8000.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(8000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8000000.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / (static_cast<NumericType>(8.0E9L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E9L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E12L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(8.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E12L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1.0E15L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E15L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(8.0E15L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E15L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
              * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           / static_cast<NumericType>(3600.0L);
}

template <typename NumericType>
inline const std::map<Unit::MemoryRate,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::MemoryRate, NumericType>{
        {Unit::MemoryRate::BitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>::FromStandard<NumericType> },
        {Unit::MemoryRate::BytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>::FromStandard<NumericType>},
        {Unit::MemoryRate::KilobitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerSecond>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::KibibitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerSecond>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::KilobytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerSecond>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::KibibytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerSecond>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::MegabitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerSecond>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::MebibitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerSecond>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::MegabytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerSecond>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::MebibytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerSecond>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::GigabitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerSecond>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::GibibitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerSecond>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::GigabytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerSecond>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::GibibytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerSecond>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::TerabitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerSecond>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::TebibitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerSecond>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::TerabytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerSecond>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::TebibytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerSecond>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::PetabitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerSecond>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::PebibitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerSecond>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::PetabytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerSecond>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::PebibytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerSecond>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::BitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerMinute>::FromStandard<NumericType> },
        {Unit::MemoryRate::BytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerMinute>::FromStandard<NumericType>},
        {Unit::MemoryRate::KilobitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerMinute>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::KibibitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerMinute>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::KilobytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerMinute>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::KibibytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerMinute>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::MegabitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerMinute>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::MebibitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerMinute>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::MegabytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerMinute>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::MebibytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerMinute>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::GigabitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerMinute>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::GibibitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerMinute>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::GigabytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerMinute>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::GibibytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerMinute>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::TerabitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerMinute>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::TebibitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerMinute>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::TerabytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerMinute>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::TebibytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerMinute>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::PetabitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerMinute>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::PebibitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerMinute>::FromStandard<NumericType>                           },
        {Unit::MemoryRate::PetabytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerMinute>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::PebibytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerMinute>::FromStandard<NumericType>                          },
        {Unit::MemoryRate::BitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerHour>::FromStandard<NumericType>   },
        {Unit::MemoryRate::BytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerHour>::FromStandard<NumericType>  },
        {Unit::MemoryRate::KilobitPerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerHour>::FromStandard<NumericType>                             },
        {Unit::MemoryRate::KibibitPerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerHour>::FromStandard<NumericType>                             },
        {Unit::MemoryRate::KilobytePerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerHour>::FromStandard<NumericType>                            },
        {Unit::MemoryRate::KibibytePerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerHour>::FromStandard<NumericType>                            },
        {Unit::MemoryRate::MegabitPerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerHour>::FromStandard<NumericType>                             },
        {Unit::MemoryRate::MebibitPerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerHour>::FromStandard<NumericType>                             },
        {Unit::MemoryRate::MegabytePerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerHour>::FromStandard<NumericType>                            },
        {Unit::MemoryRate::MebibytePerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerHour>::FromStandard<NumericType>                            },
        {Unit::MemoryRate::GigabitPerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerHour>::FromStandard<NumericType>                             },
        {Unit::MemoryRate::GibibitPerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerHour>::FromStandard<NumericType>                             },
        {Unit::MemoryRate::GigabytePerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerHour>::FromStandard<NumericType>                            },
        {Unit::MemoryRate::GibibytePerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerHour>::FromStandard<NumericType>                            },
        {Unit::MemoryRate::TerabitPerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerHour>::FromStandard<NumericType>                             },
        {Unit::MemoryRate::TebibitPerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerHour>::FromStandard<NumericType>                             },
        {Unit::MemoryRate::TerabytePerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerHour>::FromStandard<NumericType>                            },
        {Unit::MemoryRate::TebibytePerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerHour>::FromStandard<NumericType>                            },
        {Unit::MemoryRate::PetabitPerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerHour>::FromStandard<NumericType>                             },
        {Unit::MemoryRate::PebibitPerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerHour>::FromStandard<NumericType>                             },
        {Unit::MemoryRate::PetabytePerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerHour>::FromStandard<NumericType>                            },
        {Unit::MemoryRate::PebibytePerHour,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerHour>::FromStandard<NumericType>                            },
};

template <typename NumericType>
inline const std::map<Unit::MemoryRate,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::MemoryRate, NumericType>{
        {Unit::MemoryRate::BitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>::ToStandard<NumericType>   },
        {Unit::MemoryRate::BytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>::ToStandard<NumericType>  },
        {Unit::MemoryRate::KilobitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerSecond>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::KibibitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerSecond>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::KilobytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerSecond>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::KibibytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerSecond>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::MegabitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerSecond>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::MebibitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerSecond>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::MegabytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerSecond>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::MebibytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerSecond>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::GigabitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerSecond>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::GibibitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerSecond>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::GigabytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerSecond>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::GibibytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerSecond>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::TerabitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerSecond>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::TebibitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerSecond>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::TerabytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerSecond>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::TebibytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerSecond>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::PetabitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerSecond>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::PebibitPerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerSecond>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::PetabytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerSecond>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::PebibytePerSecond,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerSecond>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::BitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerMinute>::ToStandard<NumericType>   },
        {Unit::MemoryRate::BytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerMinute>::ToStandard<NumericType>  },
        {Unit::MemoryRate::KilobitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerMinute>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::KibibitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerMinute>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::KilobytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerMinute>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::KibibytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerMinute>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::MegabitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerMinute>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::MebibitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerMinute>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::MegabytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerMinute>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::MebibytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerMinute>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::GigabitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerMinute>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::GibibitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerMinute>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::GigabytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerMinute>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::GibibytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerMinute>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::TerabitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerMinute>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::TebibitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerMinute>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::TerabytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerMinute>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::TebibytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerMinute>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::PetabitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerMinute>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::PebibitPerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerMinute>::ToStandard<NumericType>                             },
        {Unit::MemoryRate::PetabytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerMinute>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::PebibytePerMinute,
         Conversions<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerMinute>::ToStandard<NumericType>                            },
        {Unit::MemoryRate::BitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerHour>::ToStandard<NumericType>     },
        {Unit::MemoryRate::BytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerHour>::ToStandard<NumericType>    },
        {Unit::MemoryRate::KilobitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobitPerHour>::ToStandard<NumericType> },
        {Unit::MemoryRate::KibibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibitPerHour>::ToStandard<NumericType> },
        {Unit::MemoryRate::KilobytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobytePerHour>::ToStandard<NumericType>},
        {Unit::MemoryRate::KibibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibytePerHour>::ToStandard<NumericType>},
        {Unit::MemoryRate::MegabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabitPerHour>::ToStandard<NumericType> },
        {Unit::MemoryRate::MebibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibitPerHour>::ToStandard<NumericType> },
        {Unit::MemoryRate::MegabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabytePerHour>::ToStandard<NumericType>},
        {Unit::MemoryRate::MebibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibytePerHour>::ToStandard<NumericType>},
        {Unit::MemoryRate::GigabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabitPerHour>::ToStandard<NumericType> },
        {Unit::MemoryRate::GibibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibitPerHour>::ToStandard<NumericType> },
        {Unit::MemoryRate::GigabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabytePerHour>::ToStandard<NumericType>},
        {Unit::MemoryRate::GibibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibytePerHour>::ToStandard<NumericType>},
        {Unit::MemoryRate::TerabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabitPerHour>::ToStandard<NumericType> },
        {Unit::MemoryRate::TebibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibitPerHour>::ToStandard<NumericType> },
        {Unit::MemoryRate::TerabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabytePerHour>::ToStandard<NumericType>},
        {Unit::MemoryRate::TebibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibytePerHour>::ToStandard<NumericType>},
        {Unit::MemoryRate::PetabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabitPerHour>::ToStandard<NumericType> },
        {Unit::MemoryRate::PebibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibitPerHour>::ToStandard<NumericType> },
        {Unit::MemoryRate::PetabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabytePerHour>::ToStandard<NumericType>},
        {Unit::MemoryRate::PebibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibytePerHour>::ToStandard<NumericType>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_MEMORY_RATE_HPP
