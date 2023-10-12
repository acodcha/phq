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

#include "../include/PhQ/MemoryRate.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(MemoryRate, ArithmeticOperatorAddition) {
  EXPECT_EQ(MemoryRate(1.0, Unit::MemoryRate::BitPerSecond)
                + MemoryRate(2.0, Unit::MemoryRate::BitPerSecond),
            MemoryRate(3.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, ArithmeticOperatorDivision) {
  EXPECT_EQ(MemoryRate(8.0, Unit::MemoryRate::BitPerSecond) / 2.0,
            MemoryRate(4.0, Unit::MemoryRate::BitPerSecond));

  EXPECT_EQ(MemoryRate(8.0, Unit::MemoryRate::BitPerSecond)
                / MemoryRate(2.0, Unit::MemoryRate::BitPerSecond),
            4.0);

  EXPECT_EQ(MemoryRate(8.0, Unit::MemoryRate::BitPerSecond)
                / Frequency(4.0, Unit::Frequency::Hertz),
            Memory(2.0, Unit::Memory::Bit));

  EXPECT_EQ(MemoryRate(8.0, Unit::MemoryRate::BitPerSecond)
                / Memory(4.0, Unit::Memory::Bit),
            Frequency(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(Memory(8.0, Unit::Memory::Bit) / Time(4.0, Unit::Time::Second),
            MemoryRate(2.0, Unit::MemoryRate::BitPerSecond));

  EXPECT_EQ(Memory(8.0, Unit::Memory::Bit)
                / MemoryRate(4.0, Unit::MemoryRate::BitPerSecond),
            Time(2.0, Unit::Time::Second));
}

TEST(MemoryRate, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(MemoryRate(4.0, Unit::MemoryRate::BitPerSecond) * 2.0,
            MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));

  EXPECT_EQ(2.0 * MemoryRate(4.0, Unit::MemoryRate::BitPerSecond),
            MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));

  EXPECT_EQ(MemoryRate(4.0, Unit::MemoryRate::BitPerSecond)
                * Time(2.0, Unit::Time::Second),
            Memory(8.0, Unit::Memory::Bit));

  EXPECT_EQ(
      Frequency(4.0, Unit::Frequency::Hertz) * Memory(2.0, Unit::Memory::Bit),
      MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));

  EXPECT_EQ(
      Memory(4.0, Unit::Memory::Bit) * Frequency(2.0, Unit::Frequency::Hertz),
      MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(MemoryRate(3.0, Unit::MemoryRate::BitPerSecond)
                - MemoryRate(2.0, Unit::MemoryRate::BitPerSecond),
            MemoryRate(1.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, AssignmentOperatorAddition) {
  MemoryRate quantity{1.0, Unit::MemoryRate::BitPerSecond};
  quantity += MemoryRate(2.0, Unit::MemoryRate::BitPerSecond);
  EXPECT_EQ(quantity, MemoryRate(3.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, AssignmentOperatorDivision) {
  MemoryRate quantity{8.0, Unit::MemoryRate::BitPerSecond};
  quantity /= 2.0;
  EXPECT_EQ(quantity, MemoryRate(4.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, AssignmentOperatorMultiplication) {
  MemoryRate quantity{4.0, Unit::MemoryRate::BitPerSecond};
  quantity *= 2.0;
  EXPECT_EQ(quantity, MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, AssignmentOperatorSubtraction) {
  MemoryRate quantity{3.0, Unit::MemoryRate::BitPerSecond};
  quantity -= MemoryRate(2.0, Unit::MemoryRate::BitPerSecond);
  EXPECT_EQ(quantity, MemoryRate(1.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, ComparisonOperators) {
  const MemoryRate first{1.11, Unit::MemoryRate::BitPerSecond};
  const MemoryRate second{2.22, Unit::MemoryRate::BitPerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(MemoryRate, CopyAssignmentOperator) {
  const MemoryRate first{1.11, Unit::MemoryRate::BitPerSecond};
  MemoryRate second = MemoryRate::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(MemoryRate, CopyConstructor) {
  const MemoryRate first{1.11, Unit::MemoryRate::BitPerSecond};
  const MemoryRate second{first};
  EXPECT_EQ(second, first);
}

TEST(MemoryRate, Create) {
  constexpr MemoryRate quantity =
      MemoryRate::Create<Unit::MemoryRate::BitPerSecond>(1.11);
  EXPECT_EQ(quantity, MemoryRate(1.11, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, DefaultConstructor) {
  EXPECT_NO_THROW(MemoryRate{});
}

TEST(MemoryRate, Dimensions) {
  EXPECT_EQ(MemoryRate::Dimensions(), RelatedDimensions<Unit::MemoryRate>);
}

TEST(MemoryRate, Hash) {
  const MemoryRate first{1.11, Unit::MemoryRate::BytePerSecond};
  const MemoryRate second{1.110001, Unit::MemoryRate::BytePerSecond};
  const MemoryRate third{-1.11, Unit::MemoryRate::BytePerSecond};
  const std::hash<MemoryRate> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(MemoryRate, JSON) {
  EXPECT_EQ(MemoryRate(1.11, Unit::MemoryRate::BitPerSecond).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"b/s\"}");
  EXPECT_EQ(MemoryRate(-2.22, Unit::MemoryRate::BytePerSecond)
                .JSON(Unit::MemoryRate::BytePerSecond),
            "{\"value\":-2.220000000000000,\"unit\":\"B/s\"}");
}

TEST(MemoryRate, MiscellaneousConstructors) {
  EXPECT_EQ(
      MemoryRate(Memory(8.0, Unit::Memory::Bit), Time(4.0, Unit::Time::Second)),
      MemoryRate(2.0, Unit::MemoryRate::BitPerSecond));

  EXPECT_EQ(MemoryRate(Memory(4.0, Unit::Memory::Bit),
                       Frequency(2.0, Unit::Frequency::Hertz)),
            MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));

  EXPECT_EQ(Frequency(MemoryRate(8.0, Unit::MemoryRate::BitPerSecond),
                      Memory(4.0, Unit::Memory::Bit)),
            Frequency(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(Memory(MemoryRate(4.0, Unit::MemoryRate::BitPerSecond),
                   Time(2.0, Unit::Time::Second)),
            Memory(8.0, Unit::Memory::Bit));

  EXPECT_EQ(Memory(MemoryRate(8.0, Unit::MemoryRate::BitPerSecond),
                   Frequency(4.0, Unit::Frequency::Hertz)),
            Memory(2.0, Unit::Memory::Bit));
}

TEST(MemoryRate, MoveAssignmentOperator) {
  MemoryRate first{1.11, Unit::MemoryRate::BitPerSecond};
  MemoryRate second = MemoryRate::Zero();
  second = std::move(first);
  EXPECT_EQ(second, MemoryRate(1.11, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, MoveConstructor) {
  MemoryRate first{1.11, Unit::MemoryRate::BitPerSecond};
  MemoryRate second{std::move(first)};
  EXPECT_EQ(second, MemoryRate(1.11, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, MutableValue) {
  MemoryRate quantity{1.11, Unit::MemoryRate::BitPerSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(MemoryRate, Print) {
  EXPECT_EQ(MemoryRate(1.11, Unit::MemoryRate::BitPerSecond).Print(),
            "1.110000000000000 b/s");
  EXPECT_EQ(MemoryRate(-2.22, Unit::MemoryRate::BytePerSecond)
                .Print(Unit::MemoryRate::BytePerSecond),
            "-2.220000000000000 B/s");
}

TEST(MemoryRate, SetValue) {
  MemoryRate quantity{1.11, Unit::MemoryRate::BitPerSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(MemoryRate, SizeOf) {
  EXPECT_EQ(sizeof(MemoryRate{}), sizeof(double));
}

TEST(MemoryRate, StandardConstructor) {
  EXPECT_NO_THROW(MemoryRate(1.11, Unit::MemoryRate::BytePerSecond));
}

TEST(MemoryRate, StaticValue) {
  constexpr MemoryRate quantity =
      MemoryRate::Create<Unit::MemoryRate::BytePerSecond>(1.11);
  constexpr double value =
      quantity.StaticValue<Unit::MemoryRate::BytePerSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(MemoryRate, Stream) {
  std::ostringstream stream;
  stream << MemoryRate(1.11, Unit::MemoryRate::BitPerSecond);
  EXPECT_EQ(
      stream.str(), MemoryRate(1.11, Unit::MemoryRate::BitPerSecond).Print());
}

TEST(MemoryRate, Unit) {
  EXPECT_EQ(MemoryRate::Unit(), Standard<Unit::MemoryRate>);
}

TEST(MemoryRate, Value) {
  EXPECT_EQ(MemoryRate(1.11, Unit::MemoryRate::BitPerSecond).Value(), 1.11);
  EXPECT_EQ(MemoryRate(1.11, Unit::MemoryRate::BytePerSecond)
                .Value(Unit::MemoryRate::BytePerSecond),
            1.11);
}

TEST(MemoryRate, XML) {
  EXPECT_EQ(MemoryRate(1.11, Unit::MemoryRate::BitPerSecond).XML(),
            "<value>1.110000000000000</value><unit>b/s</unit>");
  EXPECT_EQ(MemoryRate(-2.22, Unit::MemoryRate::BytePerSecond)
                .XML(Unit::MemoryRate::BytePerSecond),
            "<value>-2.220000000000000</value><unit>B/s</unit>");
}

TEST(MemoryRate, YAML) {
  EXPECT_EQ(MemoryRate(1.11, Unit::MemoryRate::BitPerSecond).YAML(),
            "{value:1.110000000000000,unit:\"b/s\"}");
  EXPECT_EQ(MemoryRate(-2.22, Unit::MemoryRate::BytePerSecond)
                .YAML(Unit::MemoryRate::BytePerSecond),
            "{value:-2.220000000000000,unit:\"B/s\"}");
}

TEST(MemoryRate, Zero) {
  EXPECT_EQ(
      MemoryRate::Zero(), MemoryRate(0.0, Unit::MemoryRate::BitPerSecond));
}

}  // namespace

}  // namespace PhQ
