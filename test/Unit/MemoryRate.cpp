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

constexpr std::array<MemoryRate, 22> Units = {
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

TEST(UnitMemoryRate, DimensionSet) {
  EXPECT_EQ(Dimensions<MemoryRate>, Dimension::Set(Dimension::Time{-1}));
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
}

TEST(UnitMemoryRate, StandardUnit) {
  EXPECT_EQ(StandardUnit<MemoryRate>, MemoryRate::BitPerSecond);
}

}  // namespace

}  // namespace PhQ::Unit
