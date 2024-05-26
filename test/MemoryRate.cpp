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

#include "../include/PhQ/MemoryRate.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Memory.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Memory.hpp"
#include "../include/PhQ/Unit/MemoryRate.hpp"
#include "../include/PhQ/Unit/Time.hpp"

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
  EXPECT_EQ(
      MemoryRate(8.0, Unit::MemoryRate::BitPerSecond) / Frequency(4.0, Unit::Frequency::Hertz),
      Memory(2.0, Unit::Memory::Bit));
  EXPECT_EQ(MemoryRate(8.0, Unit::MemoryRate::BitPerSecond) / Memory(4.0, Unit::Memory::Bit),
            Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(Memory(8.0, Unit::Memory::Bit) / Time(4.0, Unit::Time::Second),
            MemoryRate(2.0, Unit::MemoryRate::BitPerSecond));
  EXPECT_EQ(Memory(8.0, Unit::Memory::Bit) / MemoryRate(4.0, Unit::MemoryRate::BitPerSecond),
            Time(2.0, Unit::Time::Second));
}

TEST(MemoryRate, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(MemoryRate(4.0, Unit::MemoryRate::BitPerSecond) * 2.0,
            MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));
  EXPECT_EQ(2.0 * MemoryRate(4.0, Unit::MemoryRate::BitPerSecond),
            MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));
  EXPECT_EQ(MemoryRate(4.0, Unit::MemoryRate::BitPerSecond) * Time(2.0, Unit::Time::Second),
            Memory(8.0, Unit::Memory::Bit));
  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * Memory(2.0, Unit::Memory::Bit),
            MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));
  EXPECT_EQ(Memory(4.0, Unit::Memory::Bit) * Frequency(2.0, Unit::Frequency::Hertz),
            MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(MemoryRate(3.0, Unit::MemoryRate::BitPerSecond)
                - MemoryRate(2.0, Unit::MemoryRate::BitPerSecond),
            MemoryRate(1.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, AssignmentOperatorAddition) {
  MemoryRate memory_rate{1.0, Unit::MemoryRate::BitPerSecond};
  memory_rate += MemoryRate(2.0, Unit::MemoryRate::BitPerSecond);
  EXPECT_EQ(memory_rate, MemoryRate(3.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, AssignmentOperatorDivision) {
  MemoryRate memory_rate{8.0, Unit::MemoryRate::BitPerSecond};
  memory_rate /= 2.0;
  EXPECT_EQ(memory_rate, MemoryRate(4.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, AssignmentOperatorMultiplication) {
  MemoryRate memory_rate{4.0, Unit::MemoryRate::BitPerSecond};
  memory_rate *= 2.0;
  EXPECT_EQ(memory_rate, MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, AssignmentOperatorSubtraction) {
  MemoryRate memory_rate{3.0, Unit::MemoryRate::BitPerSecond};
  memory_rate -= MemoryRate(2.0, Unit::MemoryRate::BitPerSecond);
  EXPECT_EQ(memory_rate, MemoryRate(1.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, ComparisonOperators) {
  const MemoryRate first{1.0, Unit::MemoryRate::BitPerSecond};
  const MemoryRate second{2.0, Unit::MemoryRate::BitPerSecond};
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
  {
    const MemoryRate<float> first(1.0F, Unit::MemoryRate::BitPerSecond);
    MemoryRate<double> second = MemoryRate<double>::Zero();
    second = first;
    EXPECT_EQ(second, MemoryRate<double>(1.0, Unit::MemoryRate::BitPerSecond));
  }
  {
    const MemoryRate<double> first(1.0, Unit::MemoryRate::BitPerSecond);
    MemoryRate<double> second = MemoryRate<double>::Zero();
    second = first;
    EXPECT_EQ(second, MemoryRate<double>(1.0, Unit::MemoryRate::BitPerSecond));
  }
  {
    const MemoryRate<long double> first(1.0L, Unit::MemoryRate::BitPerSecond);
    MemoryRate<double> second = MemoryRate<double>::Zero();
    second = first;
    EXPECT_EQ(second, MemoryRate<double>(1.0, Unit::MemoryRate::BitPerSecond));
  }
}

TEST(MemoryRate, CopyConstructor) {
  {
    const MemoryRate<float> first(1.0F, Unit::MemoryRate::BitPerSecond);
    const MemoryRate<double> second{first};
    EXPECT_EQ(second, MemoryRate<double>(1.0, Unit::MemoryRate::BitPerSecond));
  }
  {
    const MemoryRate<double> first(1.0, Unit::MemoryRate::BitPerSecond);
    const MemoryRate<double> second{first};
    EXPECT_EQ(second, MemoryRate<double>(1.0, Unit::MemoryRate::BitPerSecond));
  }
  {
    const MemoryRate<long double> first(1.0L, Unit::MemoryRate::BitPerSecond);
    const MemoryRate<double> second{first};
    EXPECT_EQ(second, MemoryRate<double>(1.0, Unit::MemoryRate::BitPerSecond));
  }
}

TEST(MemoryRate, Create) {
  constexpr MemoryRate memory_rate = MemoryRate<>::Create<Unit::MemoryRate::BitPerSecond>(1.0);
  EXPECT_EQ(memory_rate, MemoryRate(1.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, DefaultConstructor) {
  EXPECT_NO_THROW(MemoryRate<>{});
}

TEST(MemoryRate, Dimensions) {
  EXPECT_EQ(MemoryRate<>::Dimensions(), RelatedDimensions<Unit::MemoryRate>);
}

TEST(MemoryRate, Hash) {
  const MemoryRate first{1.0, Unit::MemoryRate::BytePerSecond};
  const MemoryRate second{1.00001, Unit::MemoryRate::BytePerSecond};
  const MemoryRate third{-1.0, Unit::MemoryRate::BytePerSecond};
  const std::hash<MemoryRate<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(MemoryRate, JSON) {
  EXPECT_EQ(MemoryRate(1.0, Unit::MemoryRate::BitPerSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"b/s\"}");
  EXPECT_EQ(MemoryRate(1.0, Unit::MemoryRate::BytePerSecond).JSON(Unit::MemoryRate::BytePerSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"B/s\"}");
}

TEST(MemoryRate, MiscellaneousConstructors) {
  EXPECT_EQ(MemoryRate(Memory(8.0, Unit::Memory::Bit), Time(4.0, Unit::Time::Second)),
            MemoryRate(2.0, Unit::MemoryRate::BitPerSecond));
  EXPECT_EQ(MemoryRate(Memory(4.0, Unit::Memory::Bit), Frequency(2.0, Unit::Frequency::Hertz)),
            MemoryRate(8.0, Unit::MemoryRate::BitPerSecond));
  EXPECT_EQ(
      Frequency(MemoryRate(8.0, Unit::MemoryRate::BitPerSecond), Memory(4.0, Unit::Memory::Bit)),
      Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(Memory(MemoryRate(4.0, Unit::MemoryRate::BitPerSecond), Time(2.0, Unit::Time::Second)),
            Memory(8.0, Unit::Memory::Bit));
  EXPECT_EQ(Memory(MemoryRate(8.0, Unit::MemoryRate::BitPerSecond),
                   Frequency(4.0, Unit::Frequency::Hertz)),
            Memory(2.0, Unit::Memory::Bit));
}

TEST(MemoryRate, MoveAssignmentOperator) {
  MemoryRate first{1.0, Unit::MemoryRate::BitPerSecond};
  MemoryRate second = MemoryRate<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, MemoryRate(1.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, MoveConstructor) {
  MemoryRate first{1.0, Unit::MemoryRate::BitPerSecond};
  const MemoryRate second{std::move(first)};
  EXPECT_EQ(second, MemoryRate(1.0, Unit::MemoryRate::BitPerSecond));
}

TEST(MemoryRate, MutableValue) {
  MemoryRate memory_rate{1.0, Unit::MemoryRate::BitPerSecond};
  double& value = memory_rate.MutableValue();
  value = 2.0;
  EXPECT_EQ(memory_rate.Value(), 2.0);
}

TEST(MemoryRate, Print) {
  EXPECT_EQ(MemoryRate(1.0, Unit::MemoryRate::BitPerSecond).Print(), Print(1.0) + " b/s");
  EXPECT_EQ(MemoryRate(1.0, Unit::MemoryRate::BytePerSecond).Print(Unit::MemoryRate::BytePerSecond),
            Print(1.0) + " B/s");
}

TEST(MemoryRate, SetValue) {
  MemoryRate memory_rate{1.0, Unit::MemoryRate::BitPerSecond};
  memory_rate.SetValue(2.0);
  EXPECT_EQ(memory_rate.Value(), 2.0);
}

TEST(MemoryRate, SizeOf) {
  EXPECT_EQ(sizeof(MemoryRate<>{}), sizeof(double));
}

TEST(MemoryRate, StandardConstructor) {
  EXPECT_NO_THROW(MemoryRate(1.0, Unit::MemoryRate::BytePerSecond));
}

TEST(MemoryRate, StaticValue) {
  constexpr MemoryRate memory_rate = MemoryRate<>::Create<Unit::MemoryRate::BytePerSecond>(1.0);
  constexpr double value = memory_rate.StaticValue<Unit::MemoryRate::BytePerSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(MemoryRate, Stream) {
  std::ostringstream stream;
  stream << MemoryRate(1.0, Unit::MemoryRate::BitPerSecond);
  EXPECT_EQ(stream.str(), MemoryRate(1.0, Unit::MemoryRate::BitPerSecond).Print());
}

TEST(MemoryRate, Unit) {
  EXPECT_EQ(MemoryRate<>::Unit(), Standard<Unit::MemoryRate>);
}

TEST(MemoryRate, Value) {
  EXPECT_EQ(MemoryRate(1.0, Unit::MemoryRate::BitPerSecond).Value(), 1.0);
  EXPECT_EQ(
      MemoryRate(1.0, Unit::MemoryRate::BytePerSecond).Value(Unit::MemoryRate::BytePerSecond), 1.0);
}

TEST(MemoryRate, XML) {
  EXPECT_EQ(MemoryRate(1.0, Unit::MemoryRate::BitPerSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>b/s</unit>");
  EXPECT_EQ(MemoryRate(1.0, Unit::MemoryRate::BytePerSecond).XML(Unit::MemoryRate::BytePerSecond),
            "<value>" + Print(1.0) + "</value><unit>B/s</unit>");
}

TEST(MemoryRate, YAML) {
  EXPECT_EQ(MemoryRate(1.0, Unit::MemoryRate::BitPerSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"b/s\"}");
  EXPECT_EQ(MemoryRate(1.0, Unit::MemoryRate::BytePerSecond).YAML(Unit::MemoryRate::BytePerSecond),
            "{value:" + Print(1.0) + ",unit:\"B/s\"}");
}

TEST(MemoryRate, Zero) {
  EXPECT_EQ(MemoryRate<>::Zero(), MemoryRate(0.0, Unit::MemoryRate::BitPerSecond));
}

}  // namespace

}  // namespace PhQ
