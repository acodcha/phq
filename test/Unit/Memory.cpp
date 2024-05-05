// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#include "../../include/PhQ/Unit/Memory.hpp"

#include <array>
#include <cmath>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Memory, 22> Units = {
    Memory::Bit,      Memory::Byte,     Memory::Kilobit,  Memory::Kibibit,  Memory::Kilobyte,
    Memory::Kibibyte, Memory::Megabit,  Memory::Mebibit,  Memory::Megabyte, Memory::Mebibyte,
    Memory::Gigabit,  Memory::Gibibit,  Memory::Gigabyte, Memory::Gibibyte, Memory::Terabit,
    Memory::Tebibit,  Memory::Terabyte, Memory::Tebibyte, Memory::Petabit,  Memory::Pebibit,
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
  EXPECT_EQ(ConsistentUnit<Memory>(UnitSystem::MetreKilogramSecondKelvin), Memory::Bit);
  EXPECT_EQ(ConsistentUnit<Memory>(UnitSystem::MillimetreGramSecondKelvin), Memory::Bit);
  EXPECT_EQ(ConsistentUnit<Memory>(UnitSystem::FootPoundSecondRankine), Memory::Bit);
  EXPECT_EQ(ConsistentUnit<Memory>(UnitSystem::InchPoundSecondRankine), Memory::Bit);
}

TEST(UnitMemory, ConversionReciprocity) {
  constexpr long double original_value{1.234567890123456789L};
  for (const Memory original_unit : Units) {
    for (const Memory intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitMemory, ConvertFromStandard) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConversions<Memory, Memory::Bit, Memory::Bit>(value, value);
  Internal::TestConversions<Memory, Memory::Bit, Memory::Byte>(value, value / 8.0L);
  Internal::TestConversions<Memory, Memory::Bit, Memory::Kilobit>(value, value / 1000.0L);
  Internal::TestConversions<Memory, Memory::Bit, Memory::Kibibit>(value, value / 1024.0L);
  Internal::TestConversions<Memory, Memory::Bit, Memory::Kilobyte>(value, value / (8.0L * 1000.0L));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Kibibyte>(value, value / (8.0L * 1024.0L));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Megabit>(
      value, value / std::pow(1000.0L, 2));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Mebibit>(
      value, value / std::pow(1024.0L, 2));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Megabyte>(
      value, value / (8.0L * std::pow(1000.0L, 2)));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Mebibyte>(
      value, value / (8.0L * std::pow(1024.0L, 2)));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Gigabit>(
      value, value / std::pow(1000.0L, 3));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Gibibit>(
      value, value / std::pow(1024.0L, 3));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Gigabyte>(
      value, value / (8.0L * std::pow(1000.0L, 3)));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Gibibyte>(
      value, value / (8.0L * std::pow(1024.0L, 3)));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Terabit>(
      value, value / std::pow(1000.0L, 4));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Tebibit>(
      value, value / std::pow(1024.0L, 4));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Terabyte>(
      value, value / (8.0L * std::pow(1000.0L, 4)));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Tebibyte>(
      value, value / (8.0L * std::pow(1024.0L, 4)));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Petabit>(
      value, value / std::pow(1000.0L, 5));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Pebibit>(
      value, value / std::pow(1024.0L, 5));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Petabyte>(
      value, value / (8.0L * std::pow(1000.0L, 5)));
  Internal::TestConversions<Memory, Memory::Bit, Memory::Pebibyte>(
      value, value / (8.0L * std::pow(1024.0L, 5)));
}

TEST(UnitMemory, ConvertToStandard) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConversions<Memory, Memory::Bit, Memory::Bit>(value, value);
  Internal::TestConversions<Memory, Memory::Byte, Memory::Bit>(value, value * 8.0L);
  Internal::TestConversions<Memory, Memory::Kilobit, Memory::Bit>(value, value * 1000.0L);
  Internal::TestConversions<Memory, Memory::Kibibit, Memory::Bit>(value, value * 1024.0L);
  Internal::TestConversions<Memory, Memory::Kilobyte, Memory::Bit>(value, value * 8.0L * 1000.0L);
  Internal::TestConversions<Memory, Memory::Kibibyte, Memory::Bit>(value, value * 8.0L * 1024.0L);
  Internal::TestConversions<Memory, Memory::Megabit, Memory::Bit>(
      value, value * std::pow(1000.0L, 2));
  Internal::TestConversions<Memory, Memory::Mebibit, Memory::Bit>(
      value, value * std::pow(1024.0L, 2));
  Internal::TestConversions<Memory, Memory::Megabyte, Memory::Bit>(
      value, value * 8.0L * std::pow(1000.0L, 2));
  Internal::TestConversions<Memory, Memory::Mebibyte, Memory::Bit>(
      value, value * 8.0L * std::pow(1024.0L, 2));
  Internal::TestConversions<Memory, Memory::Gigabit, Memory::Bit>(
      value, value * std::pow(1000.0L, 3));
  Internal::TestConversions<Memory, Memory::Gibibit, Memory::Bit>(
      value, value * std::pow(1024.0L, 3));
  Internal::TestConversions<Memory, Memory::Gigabyte, Memory::Bit>(
      value, value * 8.0L * std::pow(1000.0L, 3));
  Internal::TestConversions<Memory, Memory::Gibibyte, Memory::Bit>(
      value, value * 8.0L * std::pow(1024.0L, 3));
  Internal::TestConversions<Memory, Memory::Terabit, Memory::Bit>(
      value, value * std::pow(1000.0L, 4));
  Internal::TestConversions<Memory, Memory::Tebibit, Memory::Bit>(
      value, value * std::pow(1024.0L, 4));
  Internal::TestConversions<Memory, Memory::Terabyte, Memory::Bit>(
      value, value * 8.0L * std::pow(1000.0L, 4));
  Internal::TestConversions<Memory, Memory::Tebibyte, Memory::Bit>(
      value, value * 8.0L * std::pow(1024.0L, 4));
  Internal::TestConversions<Memory, Memory::Petabit, Memory::Bit>(
      value, value * std::pow(1000.0L, 5));
  Internal::TestConversions<Memory, Memory::Pebibit, Memory::Bit>(
      value, value * std::pow(1024.0L, 5));
  Internal::TestConversions<Memory, Memory::Petabyte, Memory::Bit>(
      value, value * 8.0L * std::pow(1000.0L, 5));
  Internal::TestConversions<Memory, Memory::Pebibyte, Memory::Bit>(
      value, value * 8.0L * std::pow(1024.0L, 5));
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

TEST(UnitMemory, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Memory>, Dimensionless);
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

TEST(UnitMemory, Standard) {
  EXPECT_EQ(Standard<Memory>, Memory::Bit);
}

TEST(UnitMemory, Stream) {
  std::ostringstream stream;
  stream << Memory::Bit;
  EXPECT_EQ(stream.str(), Abbreviation(Memory::Bit));
}

}  // namespace

}  // namespace PhQ::Unit
