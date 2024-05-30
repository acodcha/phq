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

TEST(UnitMemory, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<Memory>(Memory::Bit, Memory::Bit, value, value);
  Internal::TestConvertAndConvertCopy<Memory>(Memory::Bit, Memory::Byte, value, value / 8.0L);
  Internal::TestConvertAndConvertCopy<Memory>(Memory::Bit, Memory::Kilobit, value, value / 1000.0L);
  Internal::TestConvertAndConvertCopy<Memory>(Memory::Bit, Memory::Kibibit, value, value / 1024.0L);
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Kilobyte, value, value / (8.0L * 1000.0L));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Kibibyte, value, value / (8.0L * 1024.0L));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Megabit, value, value / std::pow(1000.0L, 2));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Mebibit, value, value / std::pow(1024.0L, 2));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Megabyte, value, value / (8.0L * std::pow(1000.0L, 2)));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Mebibyte, value, value / (8.0L * std::pow(1024.0L, 2)));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Gigabit, value, value / std::pow(1000.0L, 3));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Gibibit, value, value / std::pow(1024.0L, 3));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Gigabyte, value, value / (8.0L * std::pow(1000.0L, 3)));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Gibibyte, value, value / (8.0L * std::pow(1024.0L, 3)));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Terabit, value, value / std::pow(1000.0L, 4));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Tebibit, value, value / std::pow(1024.0L, 4));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Terabyte, value, value / (8.0L * std::pow(1000.0L, 4)));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Tebibyte, value, value / (8.0L * std::pow(1024.0L, 4)));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Petabit, value, value / std::pow(1000.0L, 5));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Pebibit, value, value / std::pow(1024.0L, 5));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Petabyte, value, value / (8.0L * std::pow(1000.0L, 5)));
  Internal::TestConvertAndConvertCopy<Memory>(
      Memory::Bit, Memory::Pebibyte, value, value / (8.0L * std::pow(1024.0L, 5)));
}

TEST(UnitMemory, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Memory>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Memory>("b"), Memory::Bit);
  EXPECT_EQ(ParseEnumeration<Memory>("B"), Memory::Byte);
  EXPECT_EQ(ParseEnumeration<Memory>("kb"), Memory::Kilobit);
  EXPECT_EQ(ParseEnumeration<Memory>("kib"), Memory::Kibibit);
  EXPECT_EQ(ParseEnumeration<Memory>("kB"), Memory::Kilobyte);
  EXPECT_EQ(ParseEnumeration<Memory>("kiB"), Memory::Kibibyte);
  EXPECT_EQ(ParseEnumeration<Memory>("Mb"), Memory::Megabit);
  EXPECT_EQ(ParseEnumeration<Memory>("Mib"), Memory::Mebibit);
  EXPECT_EQ(ParseEnumeration<Memory>("MB"), Memory::Megabyte);
  EXPECT_EQ(ParseEnumeration<Memory>("MiB"), Memory::Mebibyte);
  EXPECT_EQ(ParseEnumeration<Memory>("Gb"), Memory::Gigabit);
  EXPECT_EQ(ParseEnumeration<Memory>("Gib"), Memory::Gibibit);
  EXPECT_EQ(ParseEnumeration<Memory>("GB"), Memory::Gigabyte);
  EXPECT_EQ(ParseEnumeration<Memory>("GiB"), Memory::Gibibyte);
  EXPECT_EQ(ParseEnumeration<Memory>("Tb"), Memory::Terabit);
  EXPECT_EQ(ParseEnumeration<Memory>("Tib"), Memory::Tebibit);
  EXPECT_EQ(ParseEnumeration<Memory>("TB"), Memory::Terabyte);
  EXPECT_EQ(ParseEnumeration<Memory>("TiB"), Memory::Tebibyte);
  EXPECT_EQ(ParseEnumeration<Memory>("Pb"), Memory::Petabit);
  EXPECT_EQ(ParseEnumeration<Memory>("Pib"), Memory::Pebibit);
  EXPECT_EQ(ParseEnumeration<Memory>("PB"), Memory::Petabyte);
  EXPECT_EQ(ParseEnumeration<Memory>("PiB"), Memory::Pebibyte);
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

TEST(UnitMemory, StaticConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestStaticConvertCopy<Memory, Memory::Bit, Memory::Kilobyte>(
      value, value / (8.0L * 1000.0L));
}

TEST(UnitMemory, Stream) {
  std::ostringstream stream;
  stream << Memory::Bit;
  EXPECT_EQ(stream.str(), Abbreviation(Memory::Bit));
}

}  // namespace

}  // namespace PhQ::Unit
