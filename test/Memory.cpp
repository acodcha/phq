// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/Memory.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Memory.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(Memory, ArithmeticOperatorAddition) {
  EXPECT_EQ(Memory(1.0, Unit::Memory::Bit) + Memory(2.0, Unit::Memory::Bit),
            Memory(3.0, Unit::Memory::Bit));
}

TEST(Memory, ArithmeticOperatorDivision) {
  EXPECT_EQ(Memory(8.0, Unit::Memory::Bit) / 2.0, Memory(4.0, Unit::Memory::Bit));
  EXPECT_EQ(Memory(8.0, Unit::Memory::Bit) / Memory(2.0, Unit::Memory::Bit), 4.0);
}

TEST(Memory, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Memory(4.0, Unit::Memory::Bit) * 2.0, Memory(8.0, Unit::Memory::Bit));
  EXPECT_EQ(2.0 * Memory(4.0, Unit::Memory::Bit), Memory(8.0, Unit::Memory::Bit));
}

TEST(Memory, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Memory(3.0, Unit::Memory::Bit) - Memory(2.0, Unit::Memory::Bit),
            Memory(1.0, Unit::Memory::Bit));
}

TEST(Memory, AssignmentOperatorAddition) {
  Memory memory{1.0, Unit::Memory::Bit};
  memory += Memory(2.0, Unit::Memory::Bit);
  EXPECT_EQ(memory, Memory(3.0, Unit::Memory::Bit));
}

TEST(Memory, AssignmentOperatorDivision) {
  Memory memory{8.0, Unit::Memory::Bit};
  memory /= 2.0;
  EXPECT_EQ(memory, Memory(4.0, Unit::Memory::Bit));
}

TEST(Memory, AssignmentOperatorMultiplication) {
  Memory memory{4.0, Unit::Memory::Bit};
  memory *= 2.0;
  EXPECT_EQ(memory, Memory(8.0, Unit::Memory::Bit));
}

TEST(Memory, AssignmentOperatorSubtraction) {
  Memory memory{3.0, Unit::Memory::Bit};
  memory -= Memory(2.0, Unit::Memory::Bit);
  EXPECT_EQ(memory, Memory(1.0, Unit::Memory::Bit));
}

TEST(Memory, ComparisonOperators) {
  const Memory first{1.0, Unit::Memory::Bit};
  const Memory second{2.0, Unit::Memory::Bit};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Memory, Constructor) {
  EXPECT_NO_THROW(Memory(1.0, Unit::Memory::Byte));
}

TEST(Memory, CopyAssignmentOperator) {
  {
    const Memory<float> first(1.0F, Unit::Memory::Bit);
    Memory<double> second = Memory<double>::Zero();
    second = first;
    EXPECT_EQ(second, Memory<double>(1.0, Unit::Memory::Bit));
  }
  {
    const Memory<double> first(1.0, Unit::Memory::Bit);
    Memory<double> second = Memory<double>::Zero();
    second = first;
    EXPECT_EQ(second, Memory<double>(1.0, Unit::Memory::Bit));
  }
  {
    const Memory<long double> first(1.0L, Unit::Memory::Bit);
    Memory<double> second = Memory<double>::Zero();
    second = first;
    EXPECT_EQ(second, Memory<double>(1.0, Unit::Memory::Bit));
  }
}

TEST(Memory, CopyConstructor) {
  {
    const Memory<float> first(1.0F, Unit::Memory::Bit);
    const Memory<double> second{first};
    EXPECT_EQ(second, Memory<double>(1.0, Unit::Memory::Bit));
  }
  {
    const Memory<double> first(1.0, Unit::Memory::Bit);
    const Memory<double> second{first};
    EXPECT_EQ(second, Memory<double>(1.0, Unit::Memory::Bit));
  }
  {
    const Memory<long double> first(1.0L, Unit::Memory::Bit);
    const Memory<double> second{first};
    EXPECT_EQ(second, Memory<double>(1.0, Unit::Memory::Bit));
  }
}

TEST(Memory, Create) {
  constexpr Memory memory = Memory<>::Create<Unit::Memory::Bit>(1.0);
  EXPECT_EQ(memory, Memory(1.0, Unit::Memory::Bit));
}

TEST(Memory, DefaultConstructor) {
  EXPECT_NO_THROW(Memory<>{});
}

TEST(Memory, Dimensions) {
  EXPECT_EQ(Memory<>::Dimensions(), RelatedDimensions<Unit::Memory>);
}

TEST(Memory, Hash) {
  const Memory first{1.0, Unit::Memory::Byte};
  const Memory second{1.00001, Unit::Memory::Byte};
  const Memory third{-1.0, Unit::Memory::Byte};
  const std::hash<Memory<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(Memory, JSON) {
  EXPECT_EQ(Memory(1.0, Unit::Memory::Bit).JSON(), "{\"value\":" + Print(1.0) + ",\"unit\":\"b\"}");
  EXPECT_EQ(Memory(1.0, Unit::Memory::Byte).JSON(Unit::Memory::Byte),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"B\"}");
}

TEST(Memory, MoveAssignmentOperator) {
  Memory first{1.0, Unit::Memory::Bit};
  Memory second = Memory<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Memory(1.0, Unit::Memory::Bit));
}

TEST(Memory, MoveConstructor) {
  Memory first{1.0, Unit::Memory::Bit};
  const Memory second{std::move(first)};
  EXPECT_EQ(second, Memory(1.0, Unit::Memory::Bit));
}

TEST(Memory, MutableValue) {
  Memory memory{1.0, Unit::Memory::Bit};
  double& value = memory.MutableValue();
  value = 2.0;
  EXPECT_EQ(memory.Value(), 2.0);
}

TEST(Memory, Performance) {
  Memory first{1.2345678901234567890, Unit::Memory::Bit};
  Memory second{1.2345678901234567890, Unit::Memory::Bit};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(Memory, Print) {
  EXPECT_EQ(Memory(1.0, Unit::Memory::Bit).Print(), Print(1.0) + " b");
  EXPECT_EQ(Memory(1.0, Unit::Memory::Byte).Print(Unit::Memory::Byte), Print(1.0) + " B");
}

TEST(Memory, SetValue) {
  Memory memory{1.0, Unit::Memory::Bit};
  memory.SetValue(2.0);
  EXPECT_EQ(memory.Value(), 2.0);
}

TEST(Memory, SizeOf) {
  EXPECT_EQ(sizeof(Memory<>{}), sizeof(double));
}

TEST(Memory, StaticValue) {
  constexpr Memory memory = Memory<>::Create<Unit::Memory::Byte>(1.0);
  constexpr double value = memory.StaticValue<Unit::Memory::Byte>();
  EXPECT_EQ(value, 1.0);
}

TEST(Memory, Stream) {
  std::ostringstream stream;
  stream << Memory(1.0, Unit::Memory::Bit);
  EXPECT_EQ(stream.str(), Memory(1.0, Unit::Memory::Bit).Print());
}

TEST(Memory, Unit) {
  EXPECT_EQ(Memory<>::Unit(), Standard<Unit::Memory>);
}

TEST(Memory, Value) {
  EXPECT_EQ(Memory(1.0, Unit::Memory::Bit).Value(), 1.0);
  EXPECT_EQ(Memory(1.0, Unit::Memory::Byte).Value(Unit::Memory::Byte), 1.0);
}

TEST(Memory, XML) {
  EXPECT_EQ(
      Memory(1.0, Unit::Memory::Bit).XML(), "<value>" + Print(1.0) + "</value><unit>b</unit>");
  EXPECT_EQ(Memory(1.0, Unit::Memory::Byte).XML(Unit::Memory::Byte),
            "<value>" + Print(1.0) + "</value><unit>B</unit>");
}

TEST(Memory, YAML) {
  EXPECT_EQ(Memory(1.0, Unit::Memory::Bit).YAML(), "{value:" + Print(1.0) + ",unit:\"b\"}");
  EXPECT_EQ(Memory(1.0, Unit::Memory::Byte).YAML(Unit::Memory::Byte),
            "{value:" + Print(1.0) + ",unit:\"B\"}");
}

TEST(Memory, Zero) {
  EXPECT_EQ(Memory<>::Zero(), Memory(0.0, Unit::Memory::Bit));
}

}  // namespace

}  // namespace PhQ
