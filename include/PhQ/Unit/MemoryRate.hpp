// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MEMORY_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MEMORY_RATE_HPP

#include "../Unit.hpp"

namespace PhQ {

namespace Unit {

// Time rate of computer memory units.
enum class MemoryRate : int8_t {
  BitPerSecond,
  BytePerSecond,
  KilobitPerSecond,
  KibibitPerSecond,
  KilobytePerSecond,
  KibibytePerSecond,
  MegabitPerSecond,
  MebibitPerSecond,
  MegabytePerSecond,
  MebibytePerSecond,
  GigabitPerSecond,
  GibibitPerSecond,
  GigabytePerSecond,
  GibibytePerSecond,
  TerabitPerSecond,
  TebibitPerSecond,
  TerabytePerSecond,
  TebibytePerSecond,
  PetabitPerSecond,
  PebibitPerSecond,
  PetabytePerSecond,
  PebibytePerSecond,
  BitPerMinute,
  BytePerMinute,
  KilobitPerMinute,
  KibibitPerMinute,
  KilobytePerMinute,
  KibibytePerMinute,
  MegabitPerMinute,
  MebibitPerMinute,
  MegabytePerMinute,
  MebibytePerMinute,
  GigabitPerMinute,
  GibibitPerMinute,
  GigabytePerMinute,
  GibibytePerMinute,
  TerabitPerMinute,
  TebibitPerMinute,
  TerabytePerMinute,
  TebibytePerMinute,
  PetabitPerMinute,
  PebibitPerMinute,
  PetabytePerMinute,
  PebibytePerMinute,
  BitPerHour,
  BytePerHour,
  KilobitPerHour,
  KibibitPerHour,
  KilobytePerHour,
  KibibytePerHour,
  MegabitPerHour,
  MebibitPerHour,
  MegabytePerHour,
  MebibytePerHour,
  GigabitPerHour,
  GibibitPerHour,
  GigabytePerHour,
  GibibytePerHour,
  TerabitPerHour,
  TebibitPerHour,
  TerabytePerHour,
  TebibytePerHour,
  PetabitPerHour,
  PebibitPerHour,
  PetabytePerHour,
  PebibytePerHour,
};

}  // namespace Unit

// Standard time rate of computer memory unit: bit per second.
template <>
inline constexpr const Unit::MemoryRate Standard<Unit::MemoryRate>{
    Unit::MemoryRate::BitPerSecond};

// Physical dimension set of time rate of computer memory units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::MemoryRate>{
    Dimensions{Dimension::Time{-1}}};

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::MemoryRate>
    ConsistentUnits<Unit::MemoryRate>{
        {UnitSystem::MetreKilogramSecondKelvin,  Unit::MemoryRate::BitPerSecond},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::MemoryRate::BitPerSecond                                        },
        {UnitSystem::FootPoundSecondRankine,     Unit::MemoryRate::BitPerSecond},
        {UnitSystem::InchPoundSecondRankine,     Unit::MemoryRate::BitPerSecond},
};

template <>
inline const std::map<Unit::MemoryRate, UnitSystem>
    RelatedUnitSystems<Unit::MemoryRate>{};

template <>
inline const std::map<Unit::MemoryRate, std::string_view> Abbreviations<
    Unit::MemoryRate>{
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
inline const std::unordered_map<std::string_view, Unit::MemoryRate> Spellings<
    Unit::MemoryRate>{
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
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>(
    double&) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>(
    double& value) noexcept {
  value *= 0.125;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KilobitPerSecond>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KibibitPerSecond>(
    double& value) noexcept {
  value /= 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KilobytePerSecond>(
    double& value) noexcept {
  value /= 8000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KibibytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MegabitPerSecond>(
    double& value) noexcept {
  value /= 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MebibitPerSecond>(
    double& value) noexcept {
  value /= 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MegabytePerSecond>(
    double& value) noexcept {
  value /= 8000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MebibytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GigabitPerSecond>(
    double& value) noexcept {
  value /= 1.0e9;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GibibitPerSecond>(
    double& value) noexcept {
  value /= 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GigabytePerSecond>(
    double& value) noexcept {
  value /= 8.0e9;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GibibytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TerabitPerSecond>(
    double& value) noexcept {
  value /= 1.0e12;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TebibitPerSecond>(
    double& value) noexcept {
  value /= 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TerabytePerSecond>(
    double& value) noexcept {
  value /= 8.0e12;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TebibytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PetabitPerSecond>(
    double& value) noexcept {
  value /= 1.0e15;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PebibitPerSecond>(
    double& value) noexcept {
  value /= 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PetabytePerSecond>(
    double& value) noexcept {
  value /= 8.0e15;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PebibytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::BitPerMinute>(
    double& value) noexcept {
  value *= 60.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::BytePerMinute>(
    double& value) noexcept {
  value *= 60.0 / 8.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KilobitPerMinute>(
    double& value) noexcept {
  value *= 60.0 / 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KibibitPerMinute>(
    double& value) noexcept {
  value *= 60.0 / 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KilobytePerMinute>(
    double& value) noexcept {
  value *= 60.0 / 8000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KibibytePerMinute>(
    double& value) noexcept {
  value *= 60.0 / (8.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MegabitPerMinute>(
    double& value) noexcept {
  value *= 60.0 / 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MebibitPerMinute>(
    double& value) noexcept {
  value *= 60.0 / (1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MegabytePerMinute>(
    double& value) noexcept {
  value *= 60.0 / 8000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MebibytePerMinute>(
    double& value) noexcept {
  value *= 60.0 / (8.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GigabitPerMinute>(
    double& value) noexcept {
  value *= 60.0 / 1.0e9;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GibibitPerMinute>(
    double& value) noexcept {
  value *= 60.0 / (1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GigabytePerMinute>(
    double& value) noexcept {
  value *= 60.0 / (8.0e9);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GibibytePerMinute>(
    double& value) noexcept {
  value *= 60.0 / (8.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TerabitPerMinute>(
    double& value) noexcept {
  value *= 60.0 / 1.0e12;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TebibitPerMinute>(
    double& value) noexcept {
  value *= 60.0 / (1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TerabytePerMinute>(
    double& value) noexcept {
  value *= 60.0 / 8.0e12;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TebibytePerMinute>(
    double& value) noexcept {
  value *= 60.0 / (8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PetabitPerMinute>(
    double& value) noexcept {
  value *= 60.0 / 1.0e15;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PebibitPerMinute>(
    double& value) noexcept {
  value *= 60.0 / (1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PetabytePerMinute>(
    double& value) noexcept {
  value *= 60.0 / 8.0e15;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PebibytePerMinute>(
    double& value) noexcept {
  value *= 60.0 / (8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::BitPerHour>(
    double& value) noexcept {
  value *= 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::BytePerHour>(
    double& value) noexcept {
  value *= 3600.0 / 8.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KilobitPerHour>(
    double& value) noexcept {
  value *= 3600.0 / 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KibibitPerHour>(
    double& value) noexcept {
  value *= 3600.0 / 1024.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KilobytePerHour>(
    double& value) noexcept {
  value *= 3600.0 / 8000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KibibytePerHour>(
    double& value) noexcept {
  value *= 3600.0 / (8.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MegabitPerHour>(
    double& value) noexcept {
  value *= 3600.0 / 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MebibitPerHour>(
    double& value) noexcept {
  value *= 3600.0 / (1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MegabytePerHour>(
    double& value) noexcept {
  value *= 3600.0 / 8000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MebibytePerHour>(
    double& value) noexcept {
  value *= 3600.0 / (8.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GigabitPerHour>(
    double& value) noexcept {
  value *= 3600.0 / 1.0e9;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GibibitPerHour>(
    double& value) noexcept {
  value *= 3600.0 / (1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GigabytePerHour>(
    double& value) noexcept {
  value *= 3600.0 / (8.0e9);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GibibytePerHour>(
    double& value) noexcept {
  value *= 3600.0 / (8.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TerabitPerHour>(
    double& value) noexcept {
  value *= 3600.0 / 1.0e12;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TebibitPerHour>(
    double& value) noexcept {
  value *= 3600.0 / (1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TerabytePerHour>(
    double& value) noexcept {
  value *= 3600.0 / 8.0e12;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TebibytePerHour>(
    double& value) noexcept {
  value *= 3600.0 / (8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PetabitPerHour>(
    double& value) noexcept {
  value *= 3600.0 / 1.0e15;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PebibitPerHour>(
    double& value) noexcept {
  value *= 3600.0 / (1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PetabytePerHour>(
    double& value) noexcept {
  value *= 3600.0 / 8.0e15;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PebibytePerHour>(
    double& value) noexcept {
  value *= 3600.0 / (8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>(
    double&) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>(
    double& value) noexcept {
  value *= 8.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KilobitPerSecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KibibitPerSecond>(
    double& value) noexcept {
  value *= 1024.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KilobytePerSecond>(
    double& value) noexcept {
  value *= 8000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KibibytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * 1024.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MegabitPerSecond>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MebibitPerSecond>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MegabytePerSecond>(
    double& value) noexcept {
  value *= 8000000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MebibytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GigabitPerSecond>(
    double& value) noexcept {
  value *= 1.0e9;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GibibitPerSecond>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GigabytePerSecond>(
    double& value) noexcept {
  value *= 8.0e9;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GibibytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TerabitPerSecond>(
    double& value) noexcept {
  value *= 1.0e12;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TebibitPerSecond>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TerabytePerSecond>(
    double& value) noexcept {
  value *= 8.0e12;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TebibytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PetabitPerSecond>(
    double& value) noexcept {
  value *= 1.0e15;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PebibitPerSecond>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PetabytePerSecond>(
    double& value) noexcept {
  value *= 8.0e15;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PebibytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::BitPerMinute>(
    double& value) noexcept {
  value /= 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::BytePerMinute>(
    double& value) noexcept {
  value *= 8.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KilobitPerMinute>(
    double& value) noexcept {
  value *= 1000.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KibibitPerMinute>(
    double& value) noexcept {
  value *= 1024.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KilobytePerMinute>(
    double& value) noexcept {
  value *= 8000.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KibibytePerMinute>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MegabitPerMinute>(
    double& value) noexcept {
  value *= 1000000.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MebibitPerMinute>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MegabytePerMinute>(
    double& value) noexcept {
  value *= 8000000.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MebibytePerMinute>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GigabitPerMinute>(
    double& value) noexcept {
  value *= 1.0e9 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GibibitPerMinute>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GigabytePerMinute>(
    double& value) noexcept {
  value *= 8.0e9 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GibibytePerMinute>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TerabitPerMinute>(
    double& value) noexcept {
  value *= 1.0e12 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TebibitPerMinute>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0 * 1024.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TerabytePerMinute>(
    double& value) noexcept {
  value *= 8.0e12 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TebibytePerMinute>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PetabitPerMinute>(
    double& value) noexcept {
  value *= 1.0e15 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PebibitPerMinute>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PetabytePerMinute>(
    double& value) noexcept {
  value *= 8.0e15 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PebibytePerMinute>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::BitPerHour>(
    double& value) noexcept {
  value /= 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::BytePerHour>(
    double& value) noexcept {
  value *= 8.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KilobitPerHour>(
    double& value) noexcept {
  value *= 1000.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KibibitPerHour>(
    double& value) noexcept {
  value *= 1024.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KilobytePerHour>(
    double& value) noexcept {
  value *= 8000.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KibibytePerHour>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MegabitPerHour>(
    double& value) noexcept {
  value *= 1000000.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MebibitPerHour>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MegabytePerHour>(
    double& value) noexcept {
  value *= 8000000.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MebibytePerHour>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GigabitPerHour>(
    double& value) noexcept {
  value *= 1.0e9 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GibibitPerHour>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GigabytePerHour>(
    double& value) noexcept {
  value *= 8.0e9 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GibibytePerHour>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TerabitPerHour>(
    double& value) noexcept {
  value *= 1.0e12 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TebibitPerHour>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0 * 1024.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TerabytePerHour>(
    double& value) noexcept {
  value *= 8.0e12 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TebibytePerHour>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PetabitPerHour>(
    double& value) noexcept {
  value *= 1.0e15 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PebibitPerHour>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PetabytePerHour>(
    double& value) noexcept {
  value *= 8.0e15 / 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PebibytePerHour>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 / 3600.0;
}

template <>
inline const std::map<
    Unit::MemoryRate,
    std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::MemoryRate>{
        {Unit::MemoryRate::BitPerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::BitPerSecond>     },
        {Unit::MemoryRate::BytePerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::BytePerSecond>    },
        {Unit::MemoryRate::KilobitPerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerSecond> },
        {Unit::MemoryRate::KibibitPerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerSecond> },
        {Unit::MemoryRate::KilobytePerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerSecond>},
        {Unit::MemoryRate::KibibytePerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerSecond>},
        {Unit::MemoryRate::MegabitPerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerSecond> },
        {Unit::MemoryRate::MebibitPerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerSecond> },
        {Unit::MemoryRate::MegabytePerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerSecond>},
        {Unit::MemoryRate::MebibytePerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerSecond>},
        {Unit::MemoryRate::GigabitPerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerSecond> },
        {Unit::MemoryRate::GibibitPerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerSecond> },
        {Unit::MemoryRate::GigabytePerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerSecond>},
        {Unit::MemoryRate::GibibytePerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerSecond>},
        {Unit::MemoryRate::TerabitPerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerSecond> },
        {Unit::MemoryRate::TebibitPerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerSecond> },
        {Unit::MemoryRate::TerabytePerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerSecond>},
        {Unit::MemoryRate::TebibytePerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerSecond>},
        {Unit::MemoryRate::PetabitPerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerSecond> },
        {Unit::MemoryRate::PebibitPerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerSecond> },
        {Unit::MemoryRate::PetabytePerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerSecond>},
        {Unit::MemoryRate::PebibytePerSecond,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerSecond>},
        {Unit::MemoryRate::BitPerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::BitPerMinute>     },
        {Unit::MemoryRate::BytePerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::BytePerMinute>    },
        {Unit::MemoryRate::KilobitPerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerMinute> },
        {Unit::MemoryRate::KibibitPerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerMinute> },
        {Unit::MemoryRate::KilobytePerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerMinute>},
        {Unit::MemoryRate::KibibytePerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerMinute>},
        {Unit::MemoryRate::MegabitPerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerMinute> },
        {Unit::MemoryRate::MebibitPerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerMinute> },
        {Unit::MemoryRate::MegabytePerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerMinute>},
        {Unit::MemoryRate::MebibytePerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerMinute>},
        {Unit::MemoryRate::GigabitPerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerMinute> },
        {Unit::MemoryRate::GibibitPerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerMinute> },
        {Unit::MemoryRate::GigabytePerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerMinute>},
        {Unit::MemoryRate::GibibytePerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerMinute>},
        {Unit::MemoryRate::TerabitPerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerMinute> },
        {Unit::MemoryRate::TebibitPerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerMinute> },
        {Unit::MemoryRate::TerabytePerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerMinute>},
        {Unit::MemoryRate::TebibytePerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerMinute>},
        {Unit::MemoryRate::PetabitPerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerMinute> },
        {Unit::MemoryRate::PebibitPerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerMinute> },
        {Unit::MemoryRate::PetabytePerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerMinute>},
        {Unit::MemoryRate::PebibytePerMinute,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerMinute>},
        {Unit::MemoryRate::BitPerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::BitPerHour>       },
        {Unit::MemoryRate::BytePerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::BytePerHour>      },
        {Unit::MemoryRate::KilobitPerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerHour>   },
        {Unit::MemoryRate::KibibitPerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerHour>   },
        {Unit::MemoryRate::KilobytePerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerHour>  },
        {Unit::MemoryRate::KibibytePerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerHour>  },
        {Unit::MemoryRate::MegabitPerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerHour>   },
        {Unit::MemoryRate::MebibitPerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerHour>   },
        {Unit::MemoryRate::MegabytePerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerHour>  },
        {Unit::MemoryRate::MebibytePerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerHour>  },
        {Unit::MemoryRate::GigabitPerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerHour>   },
        {Unit::MemoryRate::GibibitPerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerHour>   },
        {Unit::MemoryRate::GigabytePerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerHour>  },
        {Unit::MemoryRate::GibibytePerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerHour>  },
        {Unit::MemoryRate::TerabitPerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerHour>   },
        {Unit::MemoryRate::TebibitPerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerHour>   },
        {Unit::MemoryRate::TerabytePerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerHour>  },
        {Unit::MemoryRate::TebibytePerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerHour>  },
        {Unit::MemoryRate::PetabitPerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerHour>   },
        {Unit::MemoryRate::PebibitPerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerHour>   },
        {Unit::MemoryRate::PetabytePerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerHour>  },
        {Unit::MemoryRate::PebibytePerHour,
         ConversionsFromStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerHour>  },
};

template <>
inline const std::map<
    Unit::MemoryRate,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::MemoryRate>{
        {Unit::MemoryRate::BitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::BitPerSecond>                                      },
        {Unit::MemoryRate::BytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::BytePerSecond>                                     },
        {Unit::MemoryRate::KilobitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerSecond>                                  },
        {Unit::MemoryRate::KibibitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerSecond>                                  },
        {Unit::MemoryRate::KilobytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerSecond>                                 },
        {Unit::MemoryRate::KibibytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerSecond>                                 },
        {Unit::MemoryRate::MegabitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerSecond>                                  },
        {Unit::MemoryRate::MebibitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerSecond>                                  },
        {Unit::MemoryRate::MegabytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerSecond>                                 },
        {Unit::MemoryRate::MebibytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerSecond>                                 },
        {Unit::MemoryRate::GigabitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerSecond>                                  },
        {Unit::MemoryRate::GibibitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerSecond>                                  },
        {Unit::MemoryRate::GigabytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerSecond>                                 },
        {Unit::MemoryRate::GibibytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerSecond>                                 },
        {Unit::MemoryRate::TerabitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerSecond>                                  },
        {Unit::MemoryRate::TebibitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerSecond>                                  },
        {Unit::MemoryRate::TerabytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerSecond>                                 },
        {Unit::MemoryRate::TebibytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerSecond>                                 },
        {Unit::MemoryRate::PetabitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerSecond>                                  },
        {Unit::MemoryRate::PebibitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerSecond>                                  },
        {Unit::MemoryRate::PetabytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerSecond>                                 },
        {Unit::MemoryRate::PebibytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerSecond>                                 },
        {Unit::MemoryRate::BitPerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::BitPerMinute>                                      },
        {Unit::MemoryRate::BytePerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::BytePerMinute>                                     },
        {Unit::MemoryRate::KilobitPerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerMinute>                                  },
        {Unit::MemoryRate::KibibitPerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerMinute>                                  },
        {Unit::MemoryRate::KilobytePerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerMinute>                                 },
        {Unit::MemoryRate::KibibytePerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerMinute>                                 },
        {Unit::MemoryRate::MegabitPerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerMinute>                                  },
        {Unit::MemoryRate::MebibitPerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerMinute>                                  },
        {Unit::MemoryRate::MegabytePerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerMinute>                                 },
        {Unit::MemoryRate::MebibytePerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerMinute>                                 },
        {Unit::MemoryRate::GigabitPerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerMinute>                                  },
        {Unit::MemoryRate::GibibitPerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerMinute>                                  },
        {Unit::MemoryRate::GigabytePerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerMinute>                                 },
        {Unit::MemoryRate::GibibytePerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerMinute>                                 },
        {Unit::MemoryRate::TerabitPerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerMinute>                                  },
        {Unit::MemoryRate::TebibitPerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerMinute>                                  },
        {Unit::MemoryRate::TerabytePerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerMinute>                                 },
        {Unit::MemoryRate::TebibytePerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerMinute>                                 },
        {Unit::MemoryRate::PetabitPerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerMinute>                                  },
        {Unit::MemoryRate::PebibitPerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerMinute>                                  },
        {Unit::MemoryRate::PetabytePerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerMinute>                                 },
        {Unit::MemoryRate::PebibytePerMinute,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerMinute>                                 },
        {Unit::MemoryRate::BitPerHour,
         ConversionsToStandard<Unit::MemoryRate, Unit::MemoryRate::BitPerHour>},
        {Unit::MemoryRate::BytePerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::BytePerHour>                                       },
        {Unit::MemoryRate::KilobitPerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerHour>                                    },
        {Unit::MemoryRate::KibibitPerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerHour>                                    },
        {Unit::MemoryRate::KilobytePerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerHour>                                   },
        {Unit::MemoryRate::KibibytePerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerHour>                                   },
        {Unit::MemoryRate::MegabitPerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerHour>                                    },
        {Unit::MemoryRate::MebibitPerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerHour>                                    },
        {Unit::MemoryRate::MegabytePerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerHour>                                   },
        {Unit::MemoryRate::MebibytePerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerHour>                                   },
        {Unit::MemoryRate::GigabitPerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerHour>                                    },
        {Unit::MemoryRate::GibibitPerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerHour>                                    },
        {Unit::MemoryRate::GigabytePerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerHour>                                   },
        {Unit::MemoryRate::GibibytePerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerHour>                                   },
        {Unit::MemoryRate::TerabitPerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerHour>                                    },
        {Unit::MemoryRate::TebibitPerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerHour>                                    },
        {Unit::MemoryRate::TerabytePerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerHour>                                   },
        {Unit::MemoryRate::TebibytePerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerHour>                                   },
        {Unit::MemoryRate::PetabitPerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerHour>                                    },
        {Unit::MemoryRate::PebibitPerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerHour>                                    },
        {Unit::MemoryRate::PetabytePerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerHour>                                   },
        {Unit::MemoryRate::PebibytePerHour,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerHour>                                   },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MEMORY_RATE_HPP
