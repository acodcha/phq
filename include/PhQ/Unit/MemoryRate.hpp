// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

// Computer memory rate unit. Can represent the time rate of change of memory or
// a memory transfer speed.
enum class MemoryRate : int8_t {
  // Bit per second (b/s) memory rate unit.
  BitPerSecond,

  // Byte per second (B/s) memory rate unit.
  BytePerSecond,

  // Kilobit per second (kb/s) memory rate unit.
  KilobitPerSecond,

  // Kibibit per second (kib/s) memory rate unit.
  KibibitPerSecond,

  // Kilobyte per second (kB/s) memory rate unit.
  KilobytePerSecond,

  // Kibibyte per second (kiB/s) memory rate unit.
  KibibytePerSecond,

  // Megabit per second (Mb/s) memory rate unit.
  MegabitPerSecond,

  // Mebibit per second (Mib/s) memory rate unit.
  MebibitPerSecond,

  // Megabyte per second (MB/s) memory rate unit.
  MegabytePerSecond,

  // Mebibyte per second (MiB/s) memory rate unit.
  MebibytePerSecond,

  // Gigabit per second (Gb/s) memory rate unit.
  GigabitPerSecond,

  // Gibibit per second (Gib/s) memory rate unit.
  GibibitPerSecond,

  // Gigabyte per second (GB/s) memory rate unit.
  GigabytePerSecond,

  // Gibibyte per second (GiB/s) memory rate unit.
  GibibytePerSecond,

  // Terabit per second (Tb/s) memory rate unit.
  TerabitPerSecond,

  // Tebibit per second (Tib/s) memory rate unit.
  TebibitPerSecond,

  // Terabyte per second (TB/s) memory rate unit.
  TerabytePerSecond,

  // Tebibyte per second (TiB/s) memory rate unit.
  TebibytePerSecond,

  // Petabit per second (Pb/s) memory rate unit.
  PetabitPerSecond,

  // Pebibit per second (Pib/s) memory rate unit.
  PebibitPerSecond,

  // Petabyte per second (PB/s) memory rate unit.
  PetabytePerSecond,

  // Pebibyte per second (PiB/s) memory rate unit.
  PebibytePerSecond,

  // Bit per minute (b/min) memory rate unit.
  BitPerMinute,

  // Byte per minute (B/min) memory rate unit.
  BytePerMinute,

  // Kilobit per minute (kb/min) memory rate unit.
  KilobitPerMinute,

  // Kibibit per minute (kib/min) memory rate unit.
  KibibitPerMinute,

  // Kilobyte per minute (kB/min) memory rate unit.
  KilobytePerMinute,

  // Kibibyte per minute (kiB/min) memory rate unit.
  KibibytePerMinute,

  // Megabit per minute (Mb/min) memory rate unit.
  MegabitPerMinute,

  // Mebibit per minute (Mib/min) memory rate unit.
  MebibitPerMinute,

  // Megabyte per minute (MB/min) memory rate unit.
  MegabytePerMinute,

  // Mebibyte per minute (MiB/min) memory rate unit.
  MebibytePerMinute,

  // Gigabit per minute (Gb/min) memory rate unit.
  GigabitPerMinute,

  // Gibibit per minute (Gib/min) memory rate unit.
  GibibitPerMinute,

  // Gigabyte per minute (GB/min) memory rate unit.
  GigabytePerMinute,

  // Gibibyte per minute (GiB/min) memory rate unit.
  GibibytePerMinute,

  // Terabit per minute (Tb/min) memory rate unit.
  TerabitPerMinute,

  // Tebibit per minute (Tib/min) memory rate unit.
  TebibitPerMinute,

  // Terabyte per minute (TB/min) memory rate unit.
  TerabytePerMinute,

  // Tebibyte per minute (TiB/min) memory rate unit.
  TebibytePerMinute,

  // Petabit per minute (Pb/min) memory rate unit.
  PetabitPerMinute,

  // Pebibit per minute (Pib/min) memory rate unit.
  PebibitPerMinute,

  // Petabyte per minute (PB/min) memory rate unit.
  PetabytePerMinute,

  // Pebibyte per minute (PiB/min) memory rate unit.
  PebibytePerMinute,

  // Bit per hour (b/hr) memory rate unit.
  BitPerHour,

  // Byte per hour (B/hr) memory rate unit.
  BytePerHour,

  // Kilobit per hour (kb/hr) memory rate unit.
  KilobitPerHour,

  // Kibibit per hour (kib/hr) memory rate unit.
  KibibitPerHour,

  // Kilobyte per hour (kB/hr) memory rate unit.
  KilobytePerHour,

  // Kibibyte per hour (kiB/hr) memory rate unit.
  KibibytePerHour,

  // Megabit per hour (Mb/hr) memory rate unit.
  MegabitPerHour,

  // Mebibit per hour (Mib/hr) memory rate unit.
  MebibitPerHour,

  // Megabyte per hour (MB/hr) memory rate unit.
  MegabytePerHour,

  // Mebibyte per hour (MiB/hr) memory rate unit.
  MebibytePerHour,

  // Gigabit per hour (Gb/hr) memory rate unit.
  GigabitPerHour,

  // Gibibit per hour (Gib/hr) memory rate unit.
  GibibitPerHour,

  // Gigabyte per hour (GB/hr) memory rate unit.
  GigabytePerHour,

  // Gibibyte per hour (GiB/hr) memory rate unit.
  GibibytePerHour,

  // Terabit per hour (Tb/hr) memory rate unit.
  TerabitPerHour,

  // Tebibit per hour (Tib/hr) memory rate unit.
  TebibitPerHour,

  // Terabyte per hour (TB/hr) memory rate unit.
  TerabytePerHour,

  // Tebibyte per hour (TiB/hr) memory rate unit.
  TebibytePerHour,

  // Petabit per hour (Pb/hr) memory rate unit.
  PetabitPerHour,

  // Pebibit per hour (Pib/hr) memory rate unit.
  PebibitPerHour,

  // Petabyte per hour (PB/hr) memory rate unit.
  PetabytePerHour,

  // Pebibyte per hour (PiB/hr) memory rate unit.
  PebibytePerHour,
};

}  // namespace Unit

// Standard computer memory rate unit: bit per second (b/s).
template <>
inline constexpr const Unit::MemoryRate Standard<Unit::MemoryRate>{Unit::MemoryRate::BitPerSecond};

// Physical dimension set of computer memory rate units.
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
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.125L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(8000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(8000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8000000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerSecond>::FromStandard(
    Number& value) noexcept {
  value /=
      (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerSecond>::FromStandard(
    Number& value) noexcept {
  value /=
      (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerSecond>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(8.0E9L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
            * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-12L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E12L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
            * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(8.0E12L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E12L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
            * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E15L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerSecond>::FromStandard(
    Number& value) noexcept {
  value /=
      (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
       * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerSecond>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
      * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(8.0E15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E15L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
            * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
            * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerSecond>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
      * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(8.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1024.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(8000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8000.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerMinute>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(60.0L) / (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(8000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8000000.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerMinute>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(60.0L)
      / (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L)
           / (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
              * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / (static_cast<Number>(8.0E9L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E9L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L)
           / (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L)
              * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(1.0E12L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E12L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L)
           / (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
              * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerMinute>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
      * static_cast<Number>(1024.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(8.0E12L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E12L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerMinute>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(60.0L)
      / (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
         * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerMinute>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
      * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(1.0E15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E15L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerMinute>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(60.0L)
      / (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
         * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerMinute>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
      * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(8.0E15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E15L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L)
           / (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L)
              * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
              * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BitPerHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(8.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::BytePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobitPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibitPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1024.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(8000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KilobytePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8000.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerHour>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(3600.0L) / (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::KibibytePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabitPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerHour>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(3600.0L) / (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibitPerHour>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(8000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MegabytePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8000000.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerHour>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(3600.0L)
      / (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::MebibytePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabitPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L)
           / (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
              * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibitPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / (static_cast<Number>(8.0E9L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GigabytePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E9L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L)
           / (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L)
              * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::GibibytePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1.0E12L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabitPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E12L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L)
           / (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
              * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibitPerHour>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
      * static_cast<Number>(1024.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(8.0E12L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TerabytePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E12L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerHour>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(3600.0L)
      / (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
         * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::TebibytePerHour>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
      * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1.0E15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabitPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E15L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerHour>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(3600.0L)
      / (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
         * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibitPerHour>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
      * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(8.0E15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PetabytePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E15L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L)
           / (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L)
              * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
              * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MemoryRate, Unit::MemoryRate::PebibytePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) / static_cast<Number>(3600.0L);
}

template <typename Number>
inline const std::map<Unit::MemoryRate, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::MemoryRate, Number>{
        {Unit::MemoryRate::BitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>::FromStandard<Number>     },
        {Unit::MemoryRate::BytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>::FromStandard<Number>    },
        {Unit::MemoryRate::KilobitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobitPerSecond>::FromStandard<Number> },
        {Unit::MemoryRate::KibibitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibitPerSecond>::FromStandard<Number> },
        {Unit::MemoryRate::KilobytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobytePerSecond>::FromStandard<Number>},
        {Unit::MemoryRate::KibibytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibytePerSecond>::FromStandard<Number>},
        {Unit::MemoryRate::MegabitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabitPerSecond>::FromStandard<Number> },
        {Unit::MemoryRate::MebibitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibitPerSecond>::FromStandard<Number> },
        {Unit::MemoryRate::MegabytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabytePerSecond>::FromStandard<Number>},
        {Unit::MemoryRate::MebibytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibytePerSecond>::FromStandard<Number>},
        {Unit::MemoryRate::GigabitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabitPerSecond>::FromStandard<Number> },
        {Unit::MemoryRate::GibibitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibitPerSecond>::FromStandard<Number> },
        {Unit::MemoryRate::GigabytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabytePerSecond>::FromStandard<Number>},
        {Unit::MemoryRate::GibibytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibytePerSecond>::FromStandard<Number>},
        {Unit::MemoryRate::TerabitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabitPerSecond>::FromStandard<Number> },
        {Unit::MemoryRate::TebibitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibitPerSecond>::FromStandard<Number> },
        {Unit::MemoryRate::TerabytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabytePerSecond>::FromStandard<Number>},
        {Unit::MemoryRate::TebibytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibytePerSecond>::FromStandard<Number>},
        {Unit::MemoryRate::PetabitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabitPerSecond>::FromStandard<Number> },
        {Unit::MemoryRate::PebibitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibitPerSecond>::FromStandard<Number> },
        {Unit::MemoryRate::PetabytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabytePerSecond>::FromStandard<Number>},
        {Unit::MemoryRate::PebibytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibytePerSecond>::FromStandard<Number>},
        {Unit::MemoryRate::BitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerMinute>::FromStandard<Number>     },
        {Unit::MemoryRate::BytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerMinute>::FromStandard<Number>    },
        {Unit::MemoryRate::KilobitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobitPerMinute>::FromStandard<Number> },
        {Unit::MemoryRate::KibibitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibitPerMinute>::FromStandard<Number> },
        {Unit::MemoryRate::KilobytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobytePerMinute>::FromStandard<Number>},
        {Unit::MemoryRate::KibibytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibytePerMinute>::FromStandard<Number>},
        {Unit::MemoryRate::MegabitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabitPerMinute>::FromStandard<Number> },
        {Unit::MemoryRate::MebibitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibitPerMinute>::FromStandard<Number> },
        {Unit::MemoryRate::MegabytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabytePerMinute>::FromStandard<Number>},
        {Unit::MemoryRate::MebibytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibytePerMinute>::FromStandard<Number>},
        {Unit::MemoryRate::GigabitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabitPerMinute>::FromStandard<Number> },
        {Unit::MemoryRate::GibibitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibitPerMinute>::FromStandard<Number> },
        {Unit::MemoryRate::GigabytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabytePerMinute>::FromStandard<Number>},
        {Unit::MemoryRate::GibibytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibytePerMinute>::FromStandard<Number>},
        {Unit::MemoryRate::TerabitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabitPerMinute>::FromStandard<Number> },
        {Unit::MemoryRate::TebibitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibitPerMinute>::FromStandard<Number> },
        {Unit::MemoryRate::TerabytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabytePerMinute>::FromStandard<Number>},
        {Unit::MemoryRate::TebibytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibytePerMinute>::FromStandard<Number>},
        {Unit::MemoryRate::PetabitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabitPerMinute>::FromStandard<Number> },
        {Unit::MemoryRate::PebibitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibitPerMinute>::FromStandard<Number> },
        {Unit::MemoryRate::PetabytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabytePerMinute>::FromStandard<Number>},
        {Unit::MemoryRate::PebibytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibytePerMinute>::FromStandard<Number>},
        {Unit::MemoryRate::BitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerHour>::FromStandard<Number>       },
        {Unit::MemoryRate::BytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerHour>::FromStandard<Number>      },
        {Unit::MemoryRate::KilobitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobitPerHour>::FromStandard<Number>   },
        {Unit::MemoryRate::KibibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibitPerHour>::FromStandard<Number>   },
        {Unit::MemoryRate::KilobytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobytePerHour>::FromStandard<Number>  },
        {Unit::MemoryRate::KibibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibytePerHour>::FromStandard<Number>  },
        {Unit::MemoryRate::MegabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabitPerHour>::FromStandard<Number>   },
        {Unit::MemoryRate::MebibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibitPerHour>::FromStandard<Number>   },
        {Unit::MemoryRate::MegabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabytePerHour>::FromStandard<Number>  },
        {Unit::MemoryRate::MebibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibytePerHour>::FromStandard<Number>  },
        {Unit::MemoryRate::GigabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabitPerHour>::FromStandard<Number>   },
        {Unit::MemoryRate::GibibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibitPerHour>::FromStandard<Number>   },
        {Unit::MemoryRate::GigabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabytePerHour>::FromStandard<Number>  },
        {Unit::MemoryRate::GibibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibytePerHour>::FromStandard<Number>  },
        {Unit::MemoryRate::TerabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabitPerHour>::FromStandard<Number>   },
        {Unit::MemoryRate::TebibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibitPerHour>::FromStandard<Number>   },
        {Unit::MemoryRate::TerabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabytePerHour>::FromStandard<Number>  },
        {Unit::MemoryRate::TebibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibytePerHour>::FromStandard<Number>  },
        {Unit::MemoryRate::PetabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabitPerHour>::FromStandard<Number>   },
        {Unit::MemoryRate::PebibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibitPerHour>::FromStandard<Number>   },
        {Unit::MemoryRate::PetabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabytePerHour>::FromStandard<Number>  },
        {Unit::MemoryRate::PebibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibytePerHour>::FromStandard<Number>  },
};

template <typename Number>
inline const std::map<Unit::MemoryRate,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::MemoryRate, Number>{
        {Unit::MemoryRate::BitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>::ToStandard<Number>     },
        {Unit::MemoryRate::BytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>::ToStandard<Number>    },
        {Unit::MemoryRate::KilobitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobitPerSecond>::ToStandard<Number> },
        {Unit::MemoryRate::KibibitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibitPerSecond>::ToStandard<Number> },
        {Unit::MemoryRate::KilobytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobytePerSecond>::ToStandard<Number>},
        {Unit::MemoryRate::KibibytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibytePerSecond>::ToStandard<Number>},
        {Unit::MemoryRate::MegabitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabitPerSecond>::ToStandard<Number> },
        {Unit::MemoryRate::MebibitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibitPerSecond>::ToStandard<Number> },
        {Unit::MemoryRate::MegabytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabytePerSecond>::ToStandard<Number>},
        {Unit::MemoryRate::MebibytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibytePerSecond>::ToStandard<Number>},
        {Unit::MemoryRate::GigabitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabitPerSecond>::ToStandard<Number> },
        {Unit::MemoryRate::GibibitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibitPerSecond>::ToStandard<Number> },
        {Unit::MemoryRate::GigabytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabytePerSecond>::ToStandard<Number>},
        {Unit::MemoryRate::GibibytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibytePerSecond>::ToStandard<Number>},
        {Unit::MemoryRate::TerabitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabitPerSecond>::ToStandard<Number> },
        {Unit::MemoryRate::TebibitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibitPerSecond>::ToStandard<Number> },
        {Unit::MemoryRate::TerabytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabytePerSecond>::ToStandard<Number>},
        {Unit::MemoryRate::TebibytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibytePerSecond>::ToStandard<Number>},
        {Unit::MemoryRate::PetabitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabitPerSecond>::ToStandard<Number> },
        {Unit::MemoryRate::PebibitPerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibitPerSecond>::ToStandard<Number> },
        {Unit::MemoryRate::PetabytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabytePerSecond>::ToStandard<Number>},
        {Unit::MemoryRate::PebibytePerSecond,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibytePerSecond>::ToStandard<Number>},
        {Unit::MemoryRate::BitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerMinute>::ToStandard<Number>     },
        {Unit::MemoryRate::BytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerMinute>::ToStandard<Number>    },
        {Unit::MemoryRate::KilobitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobitPerMinute>::ToStandard<Number> },
        {Unit::MemoryRate::KibibitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibitPerMinute>::ToStandard<Number> },
        {Unit::MemoryRate::KilobytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobytePerMinute>::ToStandard<Number>},
        {Unit::MemoryRate::KibibytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibytePerMinute>::ToStandard<Number>},
        {Unit::MemoryRate::MegabitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabitPerMinute>::ToStandard<Number> },
        {Unit::MemoryRate::MebibitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibitPerMinute>::ToStandard<Number> },
        {Unit::MemoryRate::MegabytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabytePerMinute>::ToStandard<Number>},
        {Unit::MemoryRate::MebibytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibytePerMinute>::ToStandard<Number>},
        {Unit::MemoryRate::GigabitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabitPerMinute>::ToStandard<Number> },
        {Unit::MemoryRate::GibibitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibitPerMinute>::ToStandard<Number> },
        {Unit::MemoryRate::GigabytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabytePerMinute>::ToStandard<Number>},
        {Unit::MemoryRate::GibibytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibytePerMinute>::ToStandard<Number>},
        {Unit::MemoryRate::TerabitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabitPerMinute>::ToStandard<Number> },
        {Unit::MemoryRate::TebibitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibitPerMinute>::ToStandard<Number> },
        {Unit::MemoryRate::TerabytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabytePerMinute>::ToStandard<Number>},
        {Unit::MemoryRate::TebibytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibytePerMinute>::ToStandard<Number>},
        {Unit::MemoryRate::PetabitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabitPerMinute>::ToStandard<Number> },
        {Unit::MemoryRate::PebibitPerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibitPerMinute>::ToStandard<Number> },
        {Unit::MemoryRate::PetabytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabytePerMinute>::ToStandard<Number>},
        {Unit::MemoryRate::PebibytePerMinute,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibytePerMinute>::ToStandard<Number>},
        {Unit::MemoryRate::BitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BitPerHour>::ToStandard<Number>       },
        {Unit::MemoryRate::BytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::BytePerHour>::ToStandard<Number>      },
        {Unit::MemoryRate::KilobitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobitPerHour>::ToStandard<Number>   },
        {Unit::MemoryRate::KibibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibitPerHour>::ToStandard<Number>   },
        {Unit::MemoryRate::KilobytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KilobytePerHour>::ToStandard<Number>  },
        {Unit::MemoryRate::KibibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::KibibytePerHour>::ToStandard<Number>  },
        {Unit::MemoryRate::MegabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabitPerHour>::ToStandard<Number>   },
        {Unit::MemoryRate::MebibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibitPerHour>::ToStandard<Number>   },
        {Unit::MemoryRate::MegabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MegabytePerHour>::ToStandard<Number>  },
        {Unit::MemoryRate::MebibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::MebibytePerHour>::ToStandard<Number>  },
        {Unit::MemoryRate::GigabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabitPerHour>::ToStandard<Number>   },
        {Unit::MemoryRate::GibibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibitPerHour>::ToStandard<Number>   },
        {Unit::MemoryRate::GigabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GigabytePerHour>::ToStandard<Number>  },
        {Unit::MemoryRate::GibibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::GibibytePerHour>::ToStandard<Number>  },
        {Unit::MemoryRate::TerabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabitPerHour>::ToStandard<Number>   },
        {Unit::MemoryRate::TebibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibitPerHour>::ToStandard<Number>   },
        {Unit::MemoryRate::TerabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TerabytePerHour>::ToStandard<Number>  },
        {Unit::MemoryRate::TebibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::TebibytePerHour>::ToStandard<Number>  },
        {Unit::MemoryRate::PetabitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabitPerHour>::ToStandard<Number>   },
        {Unit::MemoryRate::PebibitPerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibitPerHour>::ToStandard<Number>   },
        {Unit::MemoryRate::PetabytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PetabytePerHour>::ToStandard<Number>  },
        {Unit::MemoryRate::PebibytePerHour,
         Conversions<Unit::MemoryRate, Unit::MemoryRate::PebibytePerHour>::ToStandard<Number>  },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_MEMORY_RATE_HPP
