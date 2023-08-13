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

#include "../../include/PhQ/Unit/Memory.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<Memory, 22> Units = {
    Memory::Bit,      Memory::Byte,     Memory::Kilobit, Memory::Kibibit,
    Memory::Kilobyte, Memory::Kibibyte, Memory::Megabit, Memory::Mebibit,
    Memory::Megabyte, Memory::Mebibyte, Memory::Gigabit, Memory::Gibibit,
    Memory::Gigabyte, Memory::Gibibyte, Memory::Terabit, Memory::Tebibit,
    Memory::Terabyte, Memory::Tebibyte, Memory::Petabit, Memory::Pebibit,
    Memory::Petabyte, Memory::Pebibyte,
};

TEST(UnitMemory, Abbreviation) {
  EXPECT_EQ(Abbreviation(Memory::Bit), "b");
  EXPECT_EQ(Abbreviation(Memory::Byte), "B");
  EXPECT_EQ(Abbreviation(Memory::Kilobit), "kb");
  EXPECT_EQ(Abbreviation(Memory::Kibibit), "kib");
  EXPECT_EQ(Abbreviation(Memory::Kilobyte), "kB");
  EXPECT_EQ(Abbreviation(Memory::Kibibyte), "kiB");
  EXPECT_EQ(Abbreviation(Memory::Megabit), "Mb");
  EXPECT_EQ(Abbreviation(Memory::Mebibit), "Mib");
  EXPECT_EQ(Abbreviation(Memory::Megabyte), "MB");
  EXPECT_EQ(Abbreviation(Memory::Mebibyte), "MiB");
  EXPECT_EQ(Abbreviation(Memory::Gigabit), "Gb");
  EXPECT_EQ(Abbreviation(Memory::Gibibit), "Gib");
  EXPECT_EQ(Abbreviation(Memory::Gigabyte), "GB");
  EXPECT_EQ(Abbreviation(Memory::Gibibyte), "GiB");
  EXPECT_EQ(Abbreviation(Memory::Terabit), "Tb");
  EXPECT_EQ(Abbreviation(Memory::Tebibit), "Tib");
  EXPECT_EQ(Abbreviation(Memory::Terabyte), "TB");
  EXPECT_EQ(Abbreviation(Memory::Tebibyte), "TiB");
  EXPECT_EQ(Abbreviation(Memory::Petabit), "Pb");
  EXPECT_EQ(Abbreviation(Memory::Pebibit), "Pib");
  EXPECT_EQ(Abbreviation(Memory::Petabyte), "PB");
  EXPECT_EQ(Abbreviation(Memory::Pebibyte), "PiB");
}

TEST(UnitMemory, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Memory>(UnitSystem::MetreKilogramSecondKelvin),
            Memory::Bit);
  EXPECT_EQ(ConsistentUnit<Memory>(UnitSystem::MillimetreGramSecondKelvin),
            Memory::Bit);
  EXPECT_EQ(
      ConsistentUnit<Memory>(UnitSystem::FootPoundSecondRankine), Memory::Bit);
  EXPECT_EQ(
      ConsistentUnit<Memory>(UnitSystem::InchPoundSecondRankine), Memory::Bit);
}

TEST(UnitMemory, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Bit), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Byte), value / 8.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Memory::Bit, Memory::Kilobit), value / 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Memory::Bit, Memory::Kibibit), value / 1024.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Kilobyte),
                   value / (8.0 * 1000.0));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Kibibyte),
                   value / (8.0 * 1024.0));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Megabit),
                   value / std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Mebibit),
                   value / std::pow(1024.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Megabyte),
                   value / (8.0 * std::pow(1000.0, 2)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Mebibyte),
                   value / (8.0 * std::pow(1024.0, 2)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Gigabit),
                   value / std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Gibibit),
                   value / std::pow(1024.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Gigabyte),
                   value / (8.0 * std::pow(1000.0, 3)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Gibibyte),
                   value / (8.0 * std::pow(1024.0, 3)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Terabit),
                   value / std::pow(1000.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Tebibit),
                   value / std::pow(1024.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Terabyte),
                   value / (8.0 * std::pow(1000.0, 4)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Tebibyte),
                   value / (8.0 * std::pow(1024.0, 4)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Petabit),
                   value / std::pow(1000.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Pebibit),
                   value / std::pow(1024.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Petabyte),
                   value / (8.0 * std::pow(1000.0, 5)));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Pebibyte),
                   value / (8.0 * std::pow(1024.0, 5)));
}

TEST(UnitMemory, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Bit, Memory::Bit), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Byte, Memory::Bit), value * 8.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Memory::Kilobit, Memory::Bit), value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Memory::Kibibit, Memory::Bit), value * 1024.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Memory::Kilobyte, Memory::Bit), value * 8.0 * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Memory::Kibibyte, Memory::Bit), value * 8.0 * 1024.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Megabit, Memory::Bit),
                   value * std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Mebibit, Memory::Bit),
                   value * std::pow(1024.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Megabyte, Memory::Bit),
                   value * 8.0 * std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Mebibyte, Memory::Bit),
                   value * 8.0 * std::pow(1024.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Gigabit, Memory::Bit),
                   value * std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Gibibit, Memory::Bit),
                   value * std::pow(1024.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Gigabyte, Memory::Bit),
                   value * 8.0 * std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Gibibyte, Memory::Bit),
                   value * 8.0 * std::pow(1024.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Terabit, Memory::Bit),
                   value * std::pow(1000.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Tebibit, Memory::Bit),
                   value * std::pow(1024.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Terabyte, Memory::Bit),
                   value * 8.0 * std::pow(1000.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Tebibyte, Memory::Bit),
                   value * 8.0 * std::pow(1024.0, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Petabit, Memory::Bit),
                   value * std::pow(1000.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Pebibit, Memory::Bit),
                   value * std::pow(1024.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Petabyte, Memory::Bit),
                   value * 8.0 * std::pow(1000.0, 5));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Memory::Pebibyte, Memory::Bit),
                   value * 8.0 * std::pow(1024.0, 5));
}

TEST(UnitMemory, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Memory old_unit : Units) {
    for (const Memory new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitMemory, DimensionSet) {
  EXPECT_EQ(Dimensions<Memory>, Dimension::Set());
}

TEST(UnitMemory, Parse) {
  EXPECT_EQ(Parse<Memory>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Memory>("b"), Memory::Bit);
  EXPECT_EQ(Parse<Memory>("B"), Memory::Byte);
  EXPECT_EQ(Parse<Memory>("kb"), Memory::Kilobit);
  EXPECT_EQ(Parse<Memory>("kib"), Memory::Kibibit);
  EXPECT_EQ(Parse<Memory>("kB"), Memory::Kilobyte);
  EXPECT_EQ(Parse<Memory>("kiB"), Memory::Kibibyte);
  EXPECT_EQ(Parse<Memory>("Mb"), Memory::Megabit);
  EXPECT_EQ(Parse<Memory>("Mib"), Memory::Mebibit);
  EXPECT_EQ(Parse<Memory>("MB"), Memory::Megabyte);
  EXPECT_EQ(Parse<Memory>("MiB"), Memory::Mebibyte);
  EXPECT_EQ(Parse<Memory>("Gb"), Memory::Gigabit);
  EXPECT_EQ(Parse<Memory>("Gib"), Memory::Gibibit);
  EXPECT_EQ(Parse<Memory>("GB"), Memory::Gigabyte);
  EXPECT_EQ(Parse<Memory>("GiB"), Memory::Gibibyte);
  EXPECT_EQ(Parse<Memory>("Tb"), Memory::Terabit);
  EXPECT_EQ(Parse<Memory>("Tib"), Memory::Tebibit);
  EXPECT_EQ(Parse<Memory>("TB"), Memory::Terabyte);
  EXPECT_EQ(Parse<Memory>("TiB"), Memory::Tebibyte);
  EXPECT_EQ(Parse<Memory>("Pb"), Memory::Petabit);
  EXPECT_EQ(Parse<Memory>("Pib"), Memory::Pebibit);
  EXPECT_EQ(Parse<Memory>("PB"), Memory::Petabyte);
  EXPECT_EQ(Parse<Memory>("PiB"), Memory::Pebibyte);
}

TEST(UnitMemory, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Memory::Bit), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Byte), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Kilobit), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Kibibit), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Kilobyte), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Kibibyte), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Megabit), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Mebibit), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Megabyte), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Mebibyte), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Gigabit), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Gibibit), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Gigabyte), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Gibibyte), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Terabit), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Tebibit), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Terabyte), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Tebibyte), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Petabit), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Pebibit), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Petabyte), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Memory::Pebibyte), std::nullopt);
}

TEST(UnitMemory, Standard) { EXPECT_EQ(Standard<Memory>, Memory::Bit); }

}  // namespace

}  // namespace PhQ::Unit
