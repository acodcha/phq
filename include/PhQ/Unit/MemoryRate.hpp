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

template <>
inline constexpr const Unit::MemoryRate StandardUnit<Unit::MemoryRate>{
    Unit::MemoryRate::BitPerSecond};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::MemoryRate>{
    Dimension::Set{Dimension::Time{-1}}};

template <>
inline const std::map<UnitSystem, Unit::MemoryRate>
    ConsistentUnits<Unit::MemoryRate>{
        {UnitSystem::MetreKilogramSecondKelvin, Unit::MemoryRate::BitPerSecond},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::MemoryRate::BitPerSecond},
        {UnitSystem::FootPoundSecondRankine, Unit::MemoryRate::BitPerSecond},
        {UnitSystem::InchPoundSecondRankine, Unit::MemoryRate::BitPerSecond},
    };

template <>
inline const std::map<Unit::MemoryRate, UnitSystem>
    RelatedUnitSystems<Unit::MemoryRate>{};

template <>
inline const std::map<Unit::MemoryRate, std::string_view>
    Abbreviations<Unit::MemoryRate>{
        {Unit::MemoryRate::BitPerSecond, "b/s"},
        {Unit::MemoryRate::BytePerSecond, "B/s"},
        {Unit::MemoryRate::KilobitPerSecond, "kb/s"},
        {Unit::MemoryRate::KibibitPerSecond, "kib/s"},
        {Unit::MemoryRate::KilobytePerSecond, "kB/s"},
        {Unit::MemoryRate::KibibytePerSecond, "kiB/s"},
        {Unit::MemoryRate::MegabitPerSecond, "Mb/s"},
        {Unit::MemoryRate::MebibitPerSecond, "Mib/s"},
        {Unit::MemoryRate::MegabytePerSecond, "MB/s"},
        {Unit::MemoryRate::MebibytePerSecond, "MiB/s"},
        {Unit::MemoryRate::GigabitPerSecond, "Gb/s"},
        {Unit::MemoryRate::GibibitPerSecond, "Gib/s"},
        {Unit::MemoryRate::GigabytePerSecond, "GB/s"},
        {Unit::MemoryRate::GibibytePerSecond, "GiB/s"},
        {Unit::MemoryRate::TerabitPerSecond, "Tb/s"},
        {Unit::MemoryRate::TebibitPerSecond, "Tib/s"},
        {Unit::MemoryRate::TerabytePerSecond, "TB/s"},
        {Unit::MemoryRate::TebibytePerSecond, "TiB/s"},
        {Unit::MemoryRate::PetabitPerSecond, "Pb/s"},
        {Unit::MemoryRate::PebibitPerSecond, "Pib/s"},
        {Unit::MemoryRate::PetabytePerSecond, "PB/s"},
        {Unit::MemoryRate::PebibytePerSecond, "PiB/s"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::MemoryRate>
    Spellings<Unit::MemoryRate>{
        {"b/s", Unit::MemoryRate::BitPerSecond},
        {"B/s", Unit::MemoryRate::BytePerSecond},
        {"kb/s", Unit::MemoryRate::KilobitPerSecond},
        {"kB/s", Unit::MemoryRate::KilobytePerSecond},
        {"kib/s", Unit::MemoryRate::KibibitPerSecond},
        {"kiB/s", Unit::MemoryRate::KibibytePerSecond},
        {"Mb/s", Unit::MemoryRate::MegabitPerSecond},
        {"MB/s", Unit::MemoryRate::MegabytePerSecond},
        {"Mib/s", Unit::MemoryRate::MebibitPerSecond},
        {"MiB/s", Unit::MemoryRate::MebibytePerSecond},
        {"Gb/s", Unit::MemoryRate::GigabitPerSecond},
        {"GB/s", Unit::MemoryRate::GigabytePerSecond},
        {"Gib/s", Unit::MemoryRate::GibibitPerSecond},
        {"GiB/s", Unit::MemoryRate::GibibytePerSecond},
        {"Tb/s", Unit::MemoryRate::TerabitPerSecond},
        {"TB/s", Unit::MemoryRate::TerabytePerSecond},
        {"Tib/s", Unit::MemoryRate::TebibitPerSecond},
        {"TiB/s", Unit::MemoryRate::TebibytePerSecond},
        {"Pb/s", Unit::MemoryRate::PetabitPerSecond},
        {"PB/s", Unit::MemoryRate::PetabytePerSecond},
        {"Pib/s", Unit::MemoryRate::PebibitPerSecond},
        {"PiB/s", Unit::MemoryRate::PebibytePerSecond},
    };

template <>
inline const std::map<
    Unit::MemoryRate,
    std::function<void(double* const values, const std::size_t size)>>
    Internal::MapOfConversionsFromStandard<Unit::MemoryRate>{
        {Unit::MemoryRate::BitPerSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::MemoryRate::BytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0;
           }
         }},
        {Unit::MemoryRate::KilobitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1000.0;
           }
         }},
        {Unit::MemoryRate::KibibitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1024.0;
           }
         }},
        {Unit::MemoryRate::KilobytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * 1000.0;
           }
         }},
        {Unit::MemoryRate::KibibytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * 1024.0;
           }
         }},
        {Unit::MemoryRate::MegabitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1000.0, 2);
           }
         }},
        {Unit::MemoryRate::MebibitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1024.0, 2);
           }
         }},
        {Unit::MemoryRate::MegabytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1000.0, 2);
           }
         }},
        {Unit::MemoryRate::MebibytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1024.0, 2);
           }
         }},
        {Unit::MemoryRate::GigabitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1000.0, 3);
           }
         }},
        {Unit::MemoryRate::GibibitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1024.0, 3);
           }
         }},
        {Unit::MemoryRate::GigabytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1000.0, 3);
           }
         }},
        {Unit::MemoryRate::GibibytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1024.0, 3);
           }
         }},
        {Unit::MemoryRate::TerabitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1000.0, 4);
           }
         }},
        {Unit::MemoryRate::TebibitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1024.0, 4);
           }
         }},
        {Unit::MemoryRate::TerabytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1000.0, 4);
           }
         }},
        {Unit::MemoryRate::TebibytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1024.0, 4);
           }
         }},
        {Unit::MemoryRate::PetabitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1000.0, 5);
           }
         }},
        {Unit::MemoryRate::PebibitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1024.0, 5);
           }
         }},
        {Unit::MemoryRate::PetabytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1000.0, 5);
           }
         }},
        {Unit::MemoryRate::PebibytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1024.0, 5);
           }
         }},
    };

template <>
inline const std::map<
    Unit::MemoryRate,
    std::function<void(double* const values, const std::size_t size)>>
    Internal::MapOfConversionsToStandard<Unit::MemoryRate>{
        {Unit::MemoryRate::BitPerSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::MemoryRate::BytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0;
           }
         }},
        {Unit::MemoryRate::KilobitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::MemoryRate::KibibitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1024.0;
           }
         }},
        {Unit::MemoryRate::KilobytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * 1000.0;
           }
         }},
        {Unit::MemoryRate::KibibytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * 1024.0;
           }
         }},
        {Unit::MemoryRate::MegabitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 2);
           }
         }},
        {Unit::MemoryRate::MebibitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1024.0, 2);
           }
         }},
        {Unit::MemoryRate::MegabytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1000.0, 2);
           }
         }},
        {Unit::MemoryRate::MebibytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1024.0, 2);
           }
         }},
        {Unit::MemoryRate::GigabitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 3);
           }
         }},
        {Unit::MemoryRate::GibibitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1024.0, 3);
           }
         }},
        {Unit::MemoryRate::GigabytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1000.0, 3);
           }
         }},
        {Unit::MemoryRate::GibibytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1024.0, 3);
           }
         }},
        {Unit::MemoryRate::TerabitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 4);
           }
         }},
        {Unit::MemoryRate::TebibitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1024.0, 4);
           }
         }},
        {Unit::MemoryRate::TerabytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1000.0, 4);
           }
         }},
        {Unit::MemoryRate::TebibytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1024.0, 4);
           }
         }},
        {Unit::MemoryRate::PetabitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 5);
           }
         }},
        {Unit::MemoryRate::PebibitPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1024.0, 5);
           }
         }},
        {Unit::MemoryRate::PetabytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1000.0, 5);
           }
         }},
        {Unit::MemoryRate::PebibytePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1024.0, 5);
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MEMORY_RATE_HPP
