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

#include "../include/PhQ/Memory.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Memory, ArithmeticOperatorAddition) {
  EXPECT_EQ(Memory(1.0, Unit::Memory::Bit) + Memory(2.0, Unit::Memory::Bit),
            Memory(3.0, Unit::Memory::Bit));
}

TEST(Memory, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      Memory(8.0, Unit::Memory::Bit) / 2.0, Memory(4.0, Unit::Memory::Bit));

  EXPECT_EQ(
      Memory(8.0, Unit::Memory::Bit) / Memory(2.0, Unit::Memory::Bit), 4.0);
}

TEST(Memory, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      Memory(4.0, Unit::Memory::Bit) * 2.0, Memory(8.0, Unit::Memory::Bit));

  EXPECT_EQ(
      2.0 * Memory(4.0, Unit::Memory::Bit), Memory(8.0, Unit::Memory::Bit));
}

TEST(Memory, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Memory(3.0, Unit::Memory::Bit) - Memory(2.0, Unit::Memory::Bit),
            Memory(1.0, Unit::Memory::Bit));
}

TEST(Memory, AssignmentOperatorAddition) {
  Memory quantity{1.0, Unit::Memory::Bit};
  quantity += Memory(2.0, Unit::Memory::Bit);
  EXPECT_EQ(quantity, Memory(3.0, Unit::Memory::Bit));
}

TEST(Memory, AssignmentOperatorDivision) {
  Memory quantity{8.0, Unit::Memory::Bit};
  quantity /= 2.0;
  EXPECT_EQ(quantity, Memory(4.0, Unit::Memory::Bit));
}

TEST(Memory, AssignmentOperatorMultiplication) {
  Memory quantity{4.0, Unit::Memory::Bit};
  quantity *= 2.0;
  EXPECT_EQ(quantity, Memory(8.0, Unit::Memory::Bit));
}

TEST(Memory, AssignmentOperatorSubtraction) {
  Memory quantity{3.0, Unit::Memory::Bit};
  quantity -= Memory(2.0, Unit::Memory::Bit);
  EXPECT_EQ(quantity, Memory(1.0, Unit::Memory::Bit));
}

TEST(Memory, ComparisonOperators) {
  const Memory first{1.11, Unit::Memory::Bit};
  const Memory second{2.22, Unit::Memory::Bit};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Memory, CopyAssignmentOperator) {
  const Memory first{1.11, Unit::Memory::Bit};
  Memory second = Memory::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Memory, CopyConstructor) {
  const Memory first{1.11, Unit::Memory::Bit};
  const Memory second{first};
  EXPECT_EQ(second, first);
}

TEST(Memory, Create) {
  constexpr Memory quantity = Memory::Create<Unit::Memory::Bit>(1.11);
  EXPECT_EQ(quantity, Memory(1.11, Unit::Memory::Bit));
}

TEST(Memory, DefaultConstructor) {
  EXPECT_NO_THROW(Memory{});
}

TEST(Memory, Dimensions) {
  EXPECT_EQ(Memory::Dimensions(), RelatedDimensions<Unit::Memory>);
}

TEST(Memory, Hash) {
  const Memory first{1.11, Unit::Memory::Byte};
  const Memory second{1.110001, Unit::Memory::Byte};
  const Memory third{-1.11, Unit::Memory::Byte};
  const std::hash<Memory> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(Memory, JSON) {
  EXPECT_EQ(Memory(1.11, Unit::Memory::Bit).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"b\"}");
  EXPECT_EQ(Memory(-2.22, Unit::Memory::Byte).JSON(Unit::Memory::Byte),
            "{\"value\":-2.220000000000000,\"unit\":\"B\"}");
}

TEST(Memory, MoveAssignmentOperator) {
  Memory first{1.11, Unit::Memory::Bit};
  Memory second = Memory::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Memory(1.11, Unit::Memory::Bit));
}

TEST(Memory, MoveConstructor) {
  Memory first{1.11, Unit::Memory::Bit};
  Memory second{std::move(first)};
  EXPECT_EQ(second, Memory(1.11, Unit::Memory::Bit));
}

TEST(Memory, MutableValue) {
  Memory quantity{1.11, Unit::Memory::Bit};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Memory, Print) {
  EXPECT_EQ(Memory(1.11, Unit::Memory::Bit).Print(), "1.110000000000000 b");
  EXPECT_EQ(Memory(-2.22, Unit::Memory::Byte).Print(Unit::Memory::Byte),
            "-2.220000000000000 B");
}

TEST(Memory, SetValue) {
  Memory quantity{1.11, Unit::Memory::Bit};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Memory, SizeOf) {
  EXPECT_EQ(sizeof(Memory{}), sizeof(double));
}

TEST(Memory, StandardConstructor) {
  EXPECT_NO_THROW(Memory(1.11, Unit::Memory::Byte));
}

TEST(Memory, StaticValue) {
  constexpr Memory quantity = Memory::Create<Unit::Memory::Byte>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Memory::Byte>();
  EXPECT_EQ(value, 1.11);
}

TEST(Memory, Stream) {
  std::ostringstream stream;
  stream << Memory(1.11, Unit::Memory::Bit);
  EXPECT_EQ(stream.str(), Memory(1.11, Unit::Memory::Bit).Print());
}

TEST(Memory, Unit) {
  EXPECT_EQ(Memory::Unit(), Standard<Unit::Memory>);
}

TEST(Memory, Value) {
  EXPECT_EQ(Memory(1.11, Unit::Memory::Bit).Value(), 1.11);
  EXPECT_EQ(Memory(1.11, Unit::Memory::Byte).Value(Unit::Memory::Byte), 1.11);
}

TEST(Memory, XML) {
  EXPECT_EQ(Memory(1.11, Unit::Memory::Bit).XML(),
            "<value>1.110000000000000</value><unit>b</unit>");
  EXPECT_EQ(Memory(-2.22, Unit::Memory::Byte).XML(Unit::Memory::Byte),
            "<value>-2.220000000000000</value><unit>B</unit>");
}

TEST(Memory, YAML) {
  EXPECT_EQ(Memory(1.11, Unit::Memory::Bit).YAML(),
            "{value:1.110000000000000,unit:\"b\"}");
  EXPECT_EQ(Memory(-2.22, Unit::Memory::Byte).YAML(Unit::Memory::Byte),
            "{value:-2.220000000000000,unit:\"B\"}");
}

TEST(Memory, Zero) {
  EXPECT_EQ(Memory::Zero(), Memory(0.0, Unit::Memory::Bit));
}

}  // namespace

}  // namespace PhQ
