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

#include "../../include/PhQ/Unit/MemoryRate.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<MemoryRate, 66> Units = {
    MemoryRate::BitPerSecond,      MemoryRate::BytePerSecond,
    MemoryRate::KilobitPerSecond,  MemoryRate::KibibitPerSecond,
    MemoryRate::KilobytePerSecond, MemoryRate::KibibytePerSecond,
    MemoryRate::MegabitPerSecond,  MemoryRate::MebibitPerSecond,
    MemoryRate::MegabytePerSecond, MemoryRate::MebibytePerSecond,
    MemoryRate::GigabitPerSecond,  MemoryRate::GibibitPerSecond,
    MemoryRate::GigabytePerSecond, MemoryRate::GibibytePerSecond,
    MemoryRate::TerabitPerSecond,  MemoryRate::TebibitPerSecond,
    MemoryRate::TerabytePerSecond, MemoryRate::TebibytePerSecond,
    MemoryRate::PetabitPerSecond,  MemoryRate::PebibitPerSecond,
    MemoryRate::PetabytePerSecond, MemoryRate::PebibytePerSecond,
    MemoryRate::BitPerMinute,      MemoryRate::BytePerMinute,
    MemoryRate::KilobitPerMinute,  MemoryRate::KibibitPerMinute,
    MemoryRate::KilobytePerMinute, MemoryRate::KibibytePerMinute,
    MemoryRate::MegabitPerMinute,  MemoryRate::MebibitPerMinute,
    MemoryRate::MegabytePerMinute, MemoryRate::MebibytePerMinute,
    MemoryRate::GigabitPerMinute,  MemoryRate::GibibitPerMinute,
    MemoryRate::GigabytePerMinute, MemoryRate::GibibytePerMinute,
    MemoryRate::TerabitPerMinute,  MemoryRate::TebibitPerMinute,
    MemoryRate::TerabytePerMinute, MemoryRate::TebibytePerMinute,
    MemoryRate::PetabitPerMinute,  MemoryRate::PebibitPerMinute,
    MemoryRate::PetabytePerMinute, MemoryRate::PebibytePerMinute,
    MemoryRate::BitPerHour,        MemoryRate::BytePerHour,
    MemoryRate::KilobitPerHour,    MemoryRate::KibibitPerHour,
    MemoryRate::KilobytePerHour,   MemoryRate::KibibytePerHour,
    MemoryRate::MegabitPerHour,    MemoryRate::MebibitPerHour,
    MemoryRate::MegabytePerHour,   MemoryRate::MebibytePerHour,
    MemoryRate::GigabitPerHour,    MemoryRate::GibibitPerHour,
    MemoryRate::GigabytePerHour,   MemoryRate::GibibytePerHour,
    MemoryRate::TerabitPerHour,    MemoryRate::TebibitPerHour,
    MemoryRate::TerabytePerHour,   MemoryRate::TebibytePerHour,
    MemoryRate::PetabitPerHour,    MemoryRate::PebibitPerHour,
    MemoryRate::PetabytePerHour,   MemoryRate::PebibytePerHour,
};

TEST(UnitMemoryRate, Abbreviation) {
  EXPECT_EQ(Abbreviation(MemoryRate::BitPerSecond), "b/s");
  EXPECT_EQ(Abbreviation(MemoryRate::BytePerSecond), "B/s");
  EXPECT_EQ(Abbreviation(MemoryRate::KilobitPerSecond), "kb/s");
  EXPECT_EQ(Abbreviation(MemoryRate::KibibitPerSecond), "kib/s");
  EXPECT_EQ(Abbreviation(MemoryRate::KilobytePerSecond), "kB/s");
  EXPECT_EQ(Abbreviation(MemoryRate::KibibytePerSecond), "kiB/s");
  EXPECT_EQ(Abbreviation(MemoryRate::MegabitPerSecond), "Mb/s");
  EXPECT_EQ(Abbreviation(MemoryRate::MebibitPerSecond), "Mib/s");
  EXPECT_EQ(Abbreviation(MemoryRate::MegabytePerSecond), "MB/s");
  EXPECT_EQ(Abbreviation(MemoryRate::MebibytePerSecond), "MiB/s");
  EXPECT_EQ(Abbreviation(MemoryRate::GigabitPerSecond), "Gb/s");
  EXPECT_EQ(Abbreviation(MemoryRate::GibibitPerSecond), "Gib/s");
  EXPECT_EQ(Abbreviation(MemoryRate::GigabytePerSecond), "GB/s");
  EXPECT_EQ(Abbreviation(MemoryRate::GibibytePerSecond), "GiB/s");
  EXPECT_EQ(Abbreviation(MemoryRate::TerabitPerSecond), "Tb/s");
  EXPECT_EQ(Abbreviation(MemoryRate::TebibitPerSecond), "Tib/s");
  EXPECT_EQ(Abbreviation(MemoryRate::TerabytePerSecond), "TB/s");
  EXPECT_EQ(Abbreviation(MemoryRate::TebibytePerSecond), "TiB/s");
  EXPECT_EQ(Abbreviation(MemoryRate::PetabitPerSecond), "Pb/s");
  EXPECT_EQ(Abbreviation(MemoryRate::PebibitPerSecond), "Pib/s");
  EXPECT_EQ(Abbreviation(MemoryRate::PetabytePerSecond), "PB/s");
  EXPECT_EQ(Abbreviation(MemoryRate::PebibytePerSecond), "PiB/s");
  EXPECT_EQ(Abbreviation(MemoryRate::BitPerMinute), "b/min");
  EXPECT_EQ(Abbreviation(MemoryRate::BytePerMinute), "B/min");
  EXPECT_EQ(Abbreviation(MemoryRate::KilobitPerMinute), "kb/min");
  EXPECT_EQ(Abbreviation(MemoryRate::KibibitPerMinute), "kib/min");
  EXPECT_EQ(Abbreviation(MemoryRate::KilobytePerMinute), "kB/min");
  EXPECT_EQ(Abbreviation(MemoryRate::KibibytePerMinute), "kiB/min");
  EXPECT_EQ(Abbreviation(MemoryRate::MegabitPerMinute), "Mb/min");
  EXPECT_EQ(Abbreviation(MemoryRate::MebibitPerMinute), "Mib/min");
  EXPECT_EQ(Abbreviation(MemoryRate::MegabytePerMinute), "MB/min");
  EXPECT_EQ(Abbreviation(MemoryRate::MebibytePerMinute), "MiB/min");
  EXPECT_EQ(Abbreviation(MemoryRate::GigabitPerMinute), "Gb/min");
  EXPECT_EQ(Abbreviation(MemoryRate::GibibitPerMinute), "Gib/min");
  EXPECT_EQ(Abbreviation(MemoryRate::GigabytePerMinute), "GB/min");
  EXPECT_EQ(Abbreviation(MemoryRate::GibibytePerMinute), "GiB/min");
  EXPECT_EQ(Abbreviation(MemoryRate::TerabitPerMinute), "Tb/min");
  EXPECT_EQ(Abbreviation(MemoryRate::TebibitPerMinute), "Tib/min");
  EXPECT_EQ(Abbreviation(MemoryRate::TerabytePerMinute), "TB/min");
  EXPECT_EQ(Abbreviation(MemoryRate::TebibytePerMinute), "TiB/min");
  EXPECT_EQ(Abbreviation(MemoryRate::PetabitPerMinute), "Pb/min");
  EXPECT_EQ(Abbreviation(MemoryRate::PebibitPerMinute), "Pib/min");
  EXPECT_EQ(Abbreviation(MemoryRate::PetabytePerMinute), "PB/min");
  EXPECT_EQ(Abbreviation(MemoryRate::PebibytePerMinute), "PiB/min");
  EXPECT_EQ(Abbreviation(MemoryRate::BitPerHour), "b/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::BytePerHour), "B/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::KilobitPerHour), "kb/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::KibibitPerHour), "kib/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::KilobytePerHour), "kB/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::KibibytePerHour), "kiB/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::MegabitPerHour), "Mb/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::MebibitPerHour), "Mib/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::MegabytePerHour), "MB/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::MebibytePerHour), "MiB/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::GigabitPerHour), "Gb/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::GibibitPerHour), "Gib/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::GigabytePerHour), "GB/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::GibibytePerHour), "GiB/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::TerabitPerHour), "Tb/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::TebibitPerHour), "Tib/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::TerabytePerHour), "TB/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::TebibytePerHour), "TiB/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::PetabitPerHour), "Pb/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::PebibitPerHour), "Pib/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::PetabytePerHour), "PB/hr");
  EXPECT_EQ(Abbreviation(MemoryRate::PebibytePerHour), "PiB/hr");
}

TEST(UnitMemoryRate, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<MemoryRate>(UnitSystem::MetreKilogramSecondKelvin),
            MemoryRate::BitPerSecond);
  EXPECT_EQ(ConsistentUnit<MemoryRate>(UnitSystem::MillimetreGramSecondKelvin),
            MemoryRate::BitPerSecond);
  EXPECT_EQ(ConsistentUnit<MemoryRate>(UnitSystem::FootPoundSecondRankine),
            MemoryRate::BitPerSecond);
  EXPECT_EQ(ConsistentUnit<MemoryRate>(UnitSystem::InchPoundSecondRankine),
            MemoryRate::BitPerSecond);
}

TEST(UnitMemoryRate, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::BitPerSecond),
      value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::BytePerSecond),
      value / 8.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::KilobitPerSecond),
                   value / 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::KibibitPerSecond),
                   value / 1024.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::KilobytePerSecond),
                   value / (8.0 * 1000.0));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::KibibytePerSecond),
                   value / (8.0 * 1024.0));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::MegabitPerSecond),
                   value / std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::MebibitPerSecond),
                   value / std::pow(1024.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::MegabytePerSecond),
                   value / (8.0 * std::pow(1000.0, 2)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::MebibytePerSecond),
                   value / (8.0 * std::pow(1024.0, 2)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::GigabitPerSecond),
                   value / std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::GibibitPerSecond),
                   value / std::pow(1024.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::GigabytePerSecond),
                   value / (8.0 * std::pow(1000.0, 3)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::GibibytePerSecond),
                   value / (8.0 * std::pow(1024.0, 3)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::TerabitPerSecond),
                   value / std::pow(1000.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::TebibitPerSecond),
                   value / std::pow(1024.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::TerabytePerSecond),
                   value / (8.0 * std::pow(1000.0, 4)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::TebibytePerSecond),
                   value / (8.0 * std::pow(1024.0, 4)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::PetabitPerSecond),
                   value / std::pow(1000.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::PebibitPerSecond),
                   value / std::pow(1024.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::PetabytePerSecond),
                   value / (8.0 * std::pow(1000.0, 5)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::PebibytePerSecond),
                   value / (8.0 * std::pow(1024.0, 5)));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::BitPerMinute),
      value * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::BytePerMinute),
      value * 60.0 / 8.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::KilobitPerMinute),
                   value * 60.0 / 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::KibibitPerMinute),
                   value * 60.0 / 1024.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::KilobytePerMinute),
                   value * 60.0 / (8.0 * 1000.0));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::KibibytePerMinute),
                   value * 60.0 / (8.0 * 1024.0));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::MegabitPerMinute),
                   value * 60.0 / std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::MebibitPerMinute),
                   value * 60.0 / std::pow(1024.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::MegabytePerMinute),
                   value * 60.0 / (8.0 * std::pow(1000.0, 2)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::MebibytePerMinute),
                   value * 60.0 / (8.0 * std::pow(1024.0, 2)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::GigabitPerMinute),
                   value * 60.0 / std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::GibibitPerMinute),
                   value * 60.0 / std::pow(1024.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::GigabytePerMinute),
                   value * 60.0 / (8.0 * std::pow(1000.0, 3)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::GibibytePerMinute),
                   value * 60.0 / (8.0 * std::pow(1024.0, 3)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::TerabitPerMinute),
                   value * 60.0 / std::pow(1000.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::TebibitPerMinute),
                   value * 60.0 / std::pow(1024.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::TerabytePerMinute),
                   value * 60.0 / (8.0 * std::pow(1000.0, 4)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::TebibytePerMinute),
                   value * 60.0 / (8.0 * std::pow(1024.0, 4)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::PetabitPerMinute),
                   value * 60.0 / std::pow(1000.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::PebibitPerMinute),
                   value * 60.0 / std::pow(1024.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::PetabytePerMinute),
                   value * 60.0 / (8.0 * std::pow(1000.0, 5)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::BitPerSecond,
                               MemoryRate::PebibytePerMinute),
                   value * 60.0 / (8.0 * std::pow(1024.0, 5)));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::BitPerHour),
      value * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::BytePerHour),
      value * 3600.0 / 8.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::KilobitPerHour),
      value * 3600.0 / 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::KibibitPerHour),
      value * 3600.0 / 1024.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::KilobytePerHour),
      value * 3600.0 / (8.0 * 1000.0));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::KibibytePerHour),
      value * 3600.0 / (8.0 * 1024.0));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::MegabitPerHour),
      value * 3600.0 / std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::MebibitPerHour),
      value * 3600.0 / std::pow(1024.0, 2));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::MegabytePerHour),
      value * 3600.0 / (8.0 * std::pow(1000.0, 2)));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::MebibytePerHour),
      value * 3600.0 / (8.0 * std::pow(1024.0, 2)));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::GigabitPerHour),
      value * 3600.0 / std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::GibibitPerHour),
      value * 3600.0 / std::pow(1024.0, 3));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::GigabytePerHour),
      value * 3600.0 / (8.0 * std::pow(1000.0, 3)));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::GibibytePerHour),
      value * 3600.0 / (8.0 * std::pow(1024.0, 3)));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::TerabitPerHour),
      value * 3600.0 / std::pow(1000.0, 4));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::TebibitPerHour),
      value * 3600.0 / std::pow(1024.0, 4));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::TerabytePerHour),
      value * 3600.0 / (8.0 * std::pow(1000.0, 4)));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::TebibytePerHour),
      value * 3600.0 / (8.0 * std::pow(1024.0, 4)));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::PetabitPerHour),
      value * 3600.0 / std::pow(1000.0, 5));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::PebibitPerHour),
      value * 3600.0 / std::pow(1024.0, 5));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::PetabytePerHour),
      value * 3600.0 / (8.0 * std::pow(1000.0, 5)));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::PebibytePerHour),
      value * 3600.0 / (8.0 * std::pow(1024.0, 5)));
}

TEST(UnitMemoryRate, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerSecond, MemoryRate::BitPerSecond),
      value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BytePerSecond, MemoryRate::BitPerSecond),
      value * 8.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::KilobitPerSecond,
                               MemoryRate::BitPerSecond),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::KibibitPerSecond,
                               MemoryRate::BitPerSecond),
                   value * 1024.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::KilobytePerSecond,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::KibibytePerSecond,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * 1024.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::MegabitPerSecond,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::MebibitPerSecond,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1024.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::MegabytePerSecond,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::MebibytePerSecond,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1024.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::GigabitPerSecond,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::GibibitPerSecond,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1024.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::GigabytePerSecond,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::GibibytePerSecond,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1024.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::TerabitPerSecond,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1000.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::TebibitPerSecond,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1024.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::TerabytePerSecond,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1000.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::TebibytePerSecond,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1024.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::PetabitPerSecond,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1000.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::PebibitPerSecond,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1024.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::PetabytePerSecond,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1000.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::PebibytePerSecond,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1024.0, 5));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerMinute, MemoryRate::BitPerSecond),
      value / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BytePerMinute, MemoryRate::BitPerSecond),
      value * 8.0 / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::KilobitPerMinute,
                               MemoryRate::BitPerSecond),
                   value * 1000.0 / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::KibibitPerMinute,
                               MemoryRate::BitPerSecond),
                   value * 1024.0 / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::KilobytePerMinute,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * 1000.0 / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::KibibytePerMinute,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * 1024.0 / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::MegabitPerMinute,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1000.0, 2) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::MebibitPerMinute,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1024.0, 2) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::MegabytePerMinute,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1000.0, 2) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::MebibytePerMinute,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1024.0, 2) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::GigabitPerMinute,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1000.0, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::GibibitPerMinute,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1024.0, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::GigabytePerMinute,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1000.0, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::GibibytePerMinute,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1024.0, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::TerabitPerMinute,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1000.0, 4) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::TebibitPerMinute,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1024.0, 4) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::TerabytePerMinute,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1000.0, 4) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::TebibytePerMinute,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1024.0, 4) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::PetabitPerMinute,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1000.0, 5) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::PebibitPerMinute,
                               MemoryRate::BitPerSecond),
                   value * std::pow(1024.0, 5) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::PetabytePerMinute,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1000.0, 5) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MemoryRate::PebibytePerMinute,
                               MemoryRate::BitPerSecond),
                   value * 8.0 * std::pow(1024.0, 5) / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BitPerHour, MemoryRate::BitPerSecond),
      value / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::BytePerHour, MemoryRate::BitPerSecond),
      value * 8.0 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::KilobitPerHour, MemoryRate::BitPerSecond),
      value * 1000.0 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::KibibitPerHour, MemoryRate::BitPerSecond),
      value * 1024.0 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::KilobytePerHour, MemoryRate::BitPerSecond),
      value * 8.0 * 1000.0 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::KibibytePerHour, MemoryRate::BitPerSecond),
      value * 8.0 * 1024.0 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::MegabitPerHour, MemoryRate::BitPerSecond),
      value * std::pow(1000.0, 2) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::MebibitPerHour, MemoryRate::BitPerSecond),
      value * std::pow(1024.0, 2) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::MegabytePerHour, MemoryRate::BitPerSecond),
      value * 8.0 * std::pow(1000.0, 2) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::MebibytePerHour, MemoryRate::BitPerSecond),
      value * 8.0 * std::pow(1024.0, 2) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::GigabitPerHour, MemoryRate::BitPerSecond),
      value * std::pow(1000.0, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::GibibitPerHour, MemoryRate::BitPerSecond),
      value * std::pow(1024.0, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::GigabytePerHour, MemoryRate::BitPerSecond),
      value * 8.0 * std::pow(1000.0, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::GibibytePerHour, MemoryRate::BitPerSecond),
      value * 8.0 * std::pow(1024.0, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::TerabitPerHour, MemoryRate::BitPerSecond),
      value * std::pow(1000.0, 4) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::TebibitPerHour, MemoryRate::BitPerSecond),
      value * std::pow(1024.0, 4) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::TerabytePerHour, MemoryRate::BitPerSecond),
      value * 8.0 * std::pow(1000.0, 4) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::TebibytePerHour, MemoryRate::BitPerSecond),
      value * 8.0 * std::pow(1024.0, 4) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::PetabitPerHour, MemoryRate::BitPerSecond),
      value * std::pow(1000.0, 5) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::PebibitPerHour, MemoryRate::BitPerSecond),
      value * std::pow(1024.0, 5) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::PetabytePerHour, MemoryRate::BitPerSecond),
      value * 8.0 * std::pow(1000.0, 5) / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MemoryRate::PebibytePerHour, MemoryRate::BitPerSecond),
      value * 8.0 * std::pow(1024.0, 5) / 3600.0);
}

TEST(UnitMemoryRate, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const MemoryRate old_unit : Units) {
    for (const MemoryRate new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitMemoryRate, Parse) {
  EXPECT_EQ(Parse<MemoryRate>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<MemoryRate>("b/s"), MemoryRate::BitPerSecond);
  EXPECT_EQ(Parse<MemoryRate>("B/s"), MemoryRate::BytePerSecond);
  EXPECT_EQ(Parse<MemoryRate>("kb/s"), MemoryRate::KilobitPerSecond);
  EXPECT_EQ(Parse<MemoryRate>("kib/s"), MemoryRate::KibibitPerSecond);
  EXPECT_EQ(Parse<MemoryRate>("kB/s"), MemoryRate::KilobytePerSecond);
  EXPECT_EQ(Parse<MemoryRate>("kiB/s"), MemoryRate::KibibytePerSecond);
  EXPECT_EQ(Parse<MemoryRate>("Mb/s"), MemoryRate::MegabitPerSecond);
  EXPECT_EQ(Parse<MemoryRate>("Mib/s"), MemoryRate::MebibitPerSecond);
  EXPECT_EQ(Parse<MemoryRate>("MB/s"), MemoryRate::MegabytePerSecond);
  EXPECT_EQ(Parse<MemoryRate>("MiB/s"), MemoryRate::MebibytePerSecond);
  EXPECT_EQ(Parse<MemoryRate>("Gb/s"), MemoryRate::GigabitPerSecond);
  EXPECT_EQ(Parse<MemoryRate>("Gib/s"), MemoryRate::GibibitPerSecond);
  EXPECT_EQ(Parse<MemoryRate>("GB/s"), MemoryRate::GigabytePerSecond);
  EXPECT_EQ(Parse<MemoryRate>("GiB/s"), MemoryRate::GibibytePerSecond);
  EXPECT_EQ(Parse<MemoryRate>("Tb/s"), MemoryRate::TerabitPerSecond);
  EXPECT_EQ(Parse<MemoryRate>("Tib/s"), MemoryRate::TebibitPerSecond);
  EXPECT_EQ(Parse<MemoryRate>("TB/s"), MemoryRate::TerabytePerSecond);
  EXPECT_EQ(Parse<MemoryRate>("TiB/s"), MemoryRate::TebibytePerSecond);
  EXPECT_EQ(Parse<MemoryRate>("Pb/s"), MemoryRate::PetabitPerSecond);
  EXPECT_EQ(Parse<MemoryRate>("Pib/s"), MemoryRate::PebibitPerSecond);
  EXPECT_EQ(Parse<MemoryRate>("PB/s"), MemoryRate::PetabytePerSecond);
  EXPECT_EQ(Parse<MemoryRate>("PiB/s"), MemoryRate::PebibytePerSecond);
  EXPECT_EQ(Parse<MemoryRate>("b/min"), MemoryRate::BitPerMinute);
  EXPECT_EQ(Parse<MemoryRate>("B/min"), MemoryRate::BytePerMinute);
  EXPECT_EQ(Parse<MemoryRate>("kb/min"), MemoryRate::KilobitPerMinute);
  EXPECT_EQ(Parse<MemoryRate>("kib/min"), MemoryRate::KibibitPerMinute);
  EXPECT_EQ(Parse<MemoryRate>("kB/min"), MemoryRate::KilobytePerMinute);
  EXPECT_EQ(Parse<MemoryRate>("kiB/min"), MemoryRate::KibibytePerMinute);
  EXPECT_EQ(Parse<MemoryRate>("Mb/min"), MemoryRate::MegabitPerMinute);
  EXPECT_EQ(Parse<MemoryRate>("Mib/min"), MemoryRate::MebibitPerMinute);
  EXPECT_EQ(Parse<MemoryRate>("MB/min"), MemoryRate::MegabytePerMinute);
  EXPECT_EQ(Parse<MemoryRate>("MiB/min"), MemoryRate::MebibytePerMinute);
  EXPECT_EQ(Parse<MemoryRate>("Gb/min"), MemoryRate::GigabitPerMinute);
  EXPECT_EQ(Parse<MemoryRate>("Gib/min"), MemoryRate::GibibitPerMinute);
  EXPECT_EQ(Parse<MemoryRate>("GB/min"), MemoryRate::GigabytePerMinute);
  EXPECT_EQ(Parse<MemoryRate>("GiB/min"), MemoryRate::GibibytePerMinute);
  EXPECT_EQ(Parse<MemoryRate>("Tb/min"), MemoryRate::TerabitPerMinute);
  EXPECT_EQ(Parse<MemoryRate>("Tib/min"), MemoryRate::TebibitPerMinute);
  EXPECT_EQ(Parse<MemoryRate>("TB/min"), MemoryRate::TerabytePerMinute);
  EXPECT_EQ(Parse<MemoryRate>("TiB/min"), MemoryRate::TebibytePerMinute);
  EXPECT_EQ(Parse<MemoryRate>("Pb/min"), MemoryRate::PetabitPerMinute);
  EXPECT_EQ(Parse<MemoryRate>("Pib/min"), MemoryRate::PebibitPerMinute);
  EXPECT_EQ(Parse<MemoryRate>("PB/min"), MemoryRate::PetabytePerMinute);
  EXPECT_EQ(Parse<MemoryRate>("PiB/min"), MemoryRate::PebibytePerMinute);
  EXPECT_EQ(Parse<MemoryRate>("b/hr"), MemoryRate::BitPerHour);
  EXPECT_EQ(Parse<MemoryRate>("B/hr"), MemoryRate::BytePerHour);
  EXPECT_EQ(Parse<MemoryRate>("kb/hr"), MemoryRate::KilobitPerHour);
  EXPECT_EQ(Parse<MemoryRate>("kib/hr"), MemoryRate::KibibitPerHour);
  EXPECT_EQ(Parse<MemoryRate>("kB/hr"), MemoryRate::KilobytePerHour);
  EXPECT_EQ(Parse<MemoryRate>("kiB/hr"), MemoryRate::KibibytePerHour);
  EXPECT_EQ(Parse<MemoryRate>("Mb/hr"), MemoryRate::MegabitPerHour);
  EXPECT_EQ(Parse<MemoryRate>("Mib/hr"), MemoryRate::MebibitPerHour);
  EXPECT_EQ(Parse<MemoryRate>("MB/hr"), MemoryRate::MegabytePerHour);
  EXPECT_EQ(Parse<MemoryRate>("MiB/hr"), MemoryRate::MebibytePerHour);
  EXPECT_EQ(Parse<MemoryRate>("Gb/hr"), MemoryRate::GigabitPerHour);
  EXPECT_EQ(Parse<MemoryRate>("Gib/hr"), MemoryRate::GibibitPerHour);
  EXPECT_EQ(Parse<MemoryRate>("GB/hr"), MemoryRate::GigabytePerHour);
  EXPECT_EQ(Parse<MemoryRate>("GiB/hr"), MemoryRate::GibibytePerHour);
  EXPECT_EQ(Parse<MemoryRate>("Tb/hr"), MemoryRate::TerabitPerHour);
  EXPECT_EQ(Parse<MemoryRate>("Tib/hr"), MemoryRate::TebibitPerHour);
  EXPECT_EQ(Parse<MemoryRate>("TB/hr"), MemoryRate::TerabytePerHour);
  EXPECT_EQ(Parse<MemoryRate>("TiB/hr"), MemoryRate::TebibytePerHour);
  EXPECT_EQ(Parse<MemoryRate>("Pb/hr"), MemoryRate::PetabitPerHour);
  EXPECT_EQ(Parse<MemoryRate>("Pib/hr"), MemoryRate::PebibitPerHour);
  EXPECT_EQ(Parse<MemoryRate>("PB/hr"), MemoryRate::PetabytePerHour);
  EXPECT_EQ(Parse<MemoryRate>("PiB/hr"), MemoryRate::PebibytePerHour);
}

TEST(UnitMemoryRate, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<MemoryRate>, Dimensions(Dimension::Time{-1}));
}

TEST(UnitMemoryRate, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::BitPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::BytePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KilobitPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KibibitPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KilobytePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KibibytePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MegabitPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MebibitPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MegabytePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MebibytePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GigabitPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GibibitPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GigabytePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GibibytePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TerabitPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TebibitPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TerabytePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TebibytePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PetabitPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PebibitPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PetabytePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PebibytePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::BitPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::BytePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KilobitPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KibibitPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KilobytePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KibibytePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MegabitPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MebibitPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MegabytePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MebibytePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GigabitPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GibibitPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GigabytePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GibibytePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TerabitPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TebibitPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TerabytePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TebibytePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PetabitPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PebibitPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PetabytePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PebibytePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::BitPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::BytePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KilobitPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KibibitPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KilobytePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::KibibytePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MegabitPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MebibitPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MegabytePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::MebibytePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GigabitPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GibibitPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GigabytePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::GibibytePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TerabitPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TebibitPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TerabytePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::TebibytePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PetabitPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PebibitPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PetabytePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MemoryRate::PebibytePerHour), std::nullopt);
}

TEST(UnitMemoryRate, Standard) {
  EXPECT_EQ(Standard<MemoryRate>, MemoryRate::BitPerSecond);
}

}  // namespace

}  // namespace PhQ::Unit
