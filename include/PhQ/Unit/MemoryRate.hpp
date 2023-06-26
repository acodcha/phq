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

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class MemoryRate : int_least8_t {
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
};

}  // namespace Unit

template<>
inline constexpr const Unit::MemoryRate StandardUnit<Unit::MemoryRate>{
    Unit::MemoryRate::BitPerSecond};

template<> inline constexpr const Dimension::Set Dimensions<Unit::MemoryRate>{
    Dimension::Set{Dimension::Time{-1}}};

template<> inline const std::map<UnitSystem, Unit::MemoryRate>
    ConsistentUnits<Unit::MemoryRate>{
        {UnitSystem::MetreKilogramSecondKelvin,  Unit::MemoryRate::BitPerSecond},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::MemoryRate::BitPerSecond                                        },
        {UnitSystem::FootPoundSecondRankine,     Unit::MemoryRate::BitPerSecond},
        {UnitSystem::InchPoundSecondRankine,     Unit::MemoryRate::BitPerSecond},
};

template<> inline const std::map<Unit::MemoryRate, UnitSystem>
    RelatedUnitSystems<Unit::MemoryRate>{};

template<> inline const std::map<Unit::MemoryRate, std::string_view>
    Abbreviations<Unit::MemoryRate>{
        {Unit::MemoryRate::BitPerSecond,      "b/s"  },
        {Unit::MemoryRate::BytePerSecond,     "B/s"  },
        {Unit::MemoryRate::KilobitPerSecond,  "kb/s" },
        {Unit::MemoryRate::KibibitPerSecond,  "kib/s"},
        {Unit::MemoryRate::KilobytePerSecond, "kB/s" },
        {Unit::MemoryRate::KibibytePerSecond, "kiB/s"},
        {Unit::MemoryRate::MegabitPerSecond,  "Mb/s" },
        {Unit::MemoryRate::MebibitPerSecond,  "Mib/s"},
        {Unit::MemoryRate::MegabytePerSecond, "MB/s" },
        {Unit::MemoryRate::MebibytePerSecond, "MiB/s"},
        {Unit::MemoryRate::GigabitPerSecond,  "Gb/s" },
        {Unit::MemoryRate::GibibitPerSecond,  "Gib/s"},
        {Unit::MemoryRate::GigabytePerSecond, "GB/s" },
        {Unit::MemoryRate::GibibytePerSecond, "GiB/s"},
        {Unit::MemoryRate::TerabitPerSecond,  "Tb/s" },
        {Unit::MemoryRate::TebibitPerSecond,  "Tib/s"},
        {Unit::MemoryRate::TerabytePerSecond, "TB/s" },
        {Unit::MemoryRate::TebibytePerSecond, "TiB/s"},
        {Unit::MemoryRate::PetabitPerSecond,  "Pb/s" },
        {Unit::MemoryRate::PebibitPerSecond,  "Pib/s"},
        {Unit::MemoryRate::PetabytePerSecond, "PB/s" },
        {Unit::MemoryRate::PebibytePerSecond, "PiB/s"},
};

template<> inline const std::unordered_map<std::string_view, Unit::MemoryRate>
    Spellings<Unit::MemoryRate>{
        {"b/s",   Unit::MemoryRate::BitPerSecond     },
        {"B/s",   Unit::MemoryRate::BytePerSecond    },
        {"kb/s",  Unit::MemoryRate::KilobitPerSecond },
        {"kB/s",  Unit::MemoryRate::KilobytePerSecond},
        {"kib/s", Unit::MemoryRate::KibibitPerSecond },
        {"kiB/s", Unit::MemoryRate::KibibytePerSecond},
        {"Mb/s",  Unit::MemoryRate::MegabitPerSecond },
        {"MB/s",  Unit::MemoryRate::MegabytePerSecond},
        {"Mib/s", Unit::MemoryRate::MebibitPerSecond },
        {"MiB/s", Unit::MemoryRate::MebibytePerSecond},
        {"Gb/s",  Unit::MemoryRate::GigabitPerSecond },
        {"GB/s",  Unit::MemoryRate::GigabytePerSecond},
        {"Gib/s", Unit::MemoryRate::GibibitPerSecond },
        {"GiB/s", Unit::MemoryRate::GibibytePerSecond},
        {"Tb/s",  Unit::MemoryRate::TerabitPerSecond },
        {"TB/s",  Unit::MemoryRate::TerabytePerSecond},
        {"Tib/s", Unit::MemoryRate::TebibitPerSecond },
        {"TiB/s", Unit::MemoryRate::TebibytePerSecond},
        {"Pb/s",  Unit::MemoryRate::PetabitPerSecond },
        {"PB/s",  Unit::MemoryRate::PetabytePerSecond},
        {"Pib/s", Unit::MemoryRate::PebibitPerSecond },
        {"PiB/s", Unit::MemoryRate::PebibytePerSecond},
};

namespace Internal {

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>(
    double& value) noexcept {
  value /= 8.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KilobitPerSecond>(
    double& value) noexcept {
  value /= 1000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KibibitPerSecond>(
    double& value) noexcept {
  value /= 1024.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KilobytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * 1000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::KibibytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * 1024.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MegabitPerSecond>(
    double& value) noexcept {
  value /= std::pow(1000.0, 2);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MebibitPerSecond>(
    double& value) noexcept {
  value /= std::pow(1024.0, 2);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MegabytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * std::pow(1000.0, 2);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::MebibytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * std::pow(1024.0, 2);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GigabitPerSecond>(
    double& value) noexcept {
  value /= std::pow(1000.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GibibitPerSecond>(
    double& value) noexcept {
  value /= std::pow(1024.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GigabytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * std::pow(1000.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::GibibytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * std::pow(1024.0, 3);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TerabitPerSecond>(
    double& value) noexcept {
  value /= std::pow(1000.0, 4);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TebibitPerSecond>(
    double& value) noexcept {
  value /= std::pow(1024.0, 4);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TerabytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * std::pow(1000.0, 4);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::TebibytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * std::pow(1024.0, 4);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PetabitPerSecond>(
    double& value) noexcept {
  value /= std::pow(1000.0, 5);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PebibitPerSecond>(
    double& value) noexcept {
  value /= std::pow(1024.0, 5);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PetabytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * std::pow(1000.0, 5);
}

template<> inline constexpr void
ConversionFromStandard<Unit::MemoryRate, Unit::MemoryRate::PebibytePerSecond>(
    double& value) noexcept {
  value /= 8.0 * std::pow(1024.0, 5);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::BitPerSecond>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::BytePerSecond>(
    double& value) noexcept {
  value *= 8.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KilobitPerSecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KibibitPerSecond>(
    double& value) noexcept {
  value *= 1024.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KilobytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * 1000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::KibibytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * 1024.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MegabitPerSecond>(
    double& value) noexcept {
  value *= std::pow(1000.0, 2);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MebibitPerSecond>(
    double& value) noexcept {
  value *= std::pow(1024.0, 2);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MegabytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * std::pow(1000.0, 2);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::MebibytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * std::pow(1024.0, 2);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GigabitPerSecond>(
    double& value) noexcept {
  value *= std::pow(1000.0, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GibibitPerSecond>(
    double& value) noexcept {
  value *= std::pow(1024.0, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GigabytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * std::pow(1000.0, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::GibibytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * std::pow(1024.0, 3);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TerabitPerSecond>(
    double& value) noexcept {
  value *= std::pow(1000.0, 4);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TebibitPerSecond>(
    double& value) noexcept {
  value *= std::pow(1024.0, 4);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TerabytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * std::pow(1000.0, 4);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::TebibytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * std::pow(1024.0, 4);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PetabitPerSecond>(
    double& value) noexcept {
  value *= std::pow(1000.0, 5);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PebibitPerSecond>(
    double& value) noexcept {
  value *= std::pow(1024.0, 5);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PetabytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * std::pow(1000.0, 5);
}

template<> inline constexpr void
ConversionToStandard<Unit::MemoryRate, Unit::MemoryRate::PebibytePerSecond>(
    double& value) noexcept {
  value *= 8.0 * std::pow(1024.0, 5);
}

template<> inline const std::map<
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
};

template<> inline const std::map<
    Unit::MemoryRate,
    std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::MemoryRate>{
        {Unit::MemoryRate::BitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::BitPerSecond>     },
        {Unit::MemoryRate::BytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::BytePerSecond>    },
        {Unit::MemoryRate::KilobitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobitPerSecond> },
        {Unit::MemoryRate::KibibitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibitPerSecond> },
        {Unit::MemoryRate::KilobytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KilobytePerSecond>},
        {Unit::MemoryRate::KibibytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::KibibytePerSecond>},
        {Unit::MemoryRate::MegabitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabitPerSecond> },
        {Unit::MemoryRate::MebibitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibitPerSecond> },
        {Unit::MemoryRate::MegabytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MegabytePerSecond>},
        {Unit::MemoryRate::MebibytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::MebibytePerSecond>},
        {Unit::MemoryRate::GigabitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabitPerSecond> },
        {Unit::MemoryRate::GibibitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibitPerSecond> },
        {Unit::MemoryRate::GigabytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GigabytePerSecond>},
        {Unit::MemoryRate::GibibytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::GibibytePerSecond>},
        {Unit::MemoryRate::TerabitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabitPerSecond> },
        {Unit::MemoryRate::TebibitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibitPerSecond> },
        {Unit::MemoryRate::TerabytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TerabytePerSecond>},
        {Unit::MemoryRate::TebibytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::TebibytePerSecond>},
        {Unit::MemoryRate::PetabitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabitPerSecond> },
        {Unit::MemoryRate::PebibitPerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibitPerSecond> },
        {Unit::MemoryRate::PetabytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PetabytePerSecond>},
        {Unit::MemoryRate::PebibytePerSecond,
         ConversionsToStandard<Unit::MemoryRate,
         Unit::MemoryRate::PebibytePerSecond>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MEMORY_RATE_HPP
