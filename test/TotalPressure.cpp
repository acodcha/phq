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

#include "../include/PhQ/TotalPressure.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/DynamicPressure.hpp"
#include "../include/PhQ/StaticPressure.hpp"
#include "../include/PhQ/Unit/Pressure.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(TotalPressure, ArithmeticOperatorAddition) {
  EXPECT_EQ(TotalPressure(1.0, Unit::Pressure::Pascal) + TotalPressure(2.0, Unit::Pressure::Pascal),
            TotalPressure(3.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      StaticPressure(2.0, Unit::Pressure::Pascal) + DynamicPressure(1.0, Unit::Pressure::Pascal),
      TotalPressure(3.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      DynamicPressure(1.0, Unit::Pressure::Pascal) + StaticPressure(2.0, Unit::Pressure::Pascal),
      TotalPressure(3.0, Unit::Pressure::Pascal));
}

TEST(TotalPressure, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      TotalPressure(8.0, Unit::Pressure::Pascal) / 2.0, TotalPressure(4.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      TotalPressure(8.0, Unit::Pressure::Pascal) / TotalPressure(2.0, Unit::Pressure::Pascal), 4.0);
}

TEST(TotalPressure, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      TotalPressure(4.0, Unit::Pressure::Pascal) * 2.0, TotalPressure(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      2.0 * TotalPressure(4.0, Unit::Pressure::Pascal), TotalPressure(8.0, Unit::Pressure::Pascal));
}

TEST(TotalPressure, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(TotalPressure(3.0, Unit::Pressure::Pascal) - TotalPressure(2.0, Unit::Pressure::Pascal),
            TotalPressure(1.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      TotalPressure(3.0, Unit::Pressure::Pascal) - StaticPressure(2.0, Unit::Pressure::Pascal),
      DynamicPressure(1.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      TotalPressure(3.0, Unit::Pressure::Pascal) - DynamicPressure(1.0, Unit::Pressure::Pascal),
      StaticPressure(2.0, Unit::Pressure::Pascal));
}

TEST(TotalPressure, AssignmentOperatorAddition) {
  TotalPressure total_pressure{1.0, Unit::Pressure::Pascal};
  total_pressure += TotalPressure(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(total_pressure, TotalPressure(3.0, Unit::Pressure::Pascal));
}

TEST(TotalPressure, AssignmentOperatorDivision) {
  TotalPressure total_pressure{8.0, Unit::Pressure::Pascal};
  total_pressure /= 2.0;
  EXPECT_EQ(total_pressure, TotalPressure(4.0, Unit::Pressure::Pascal));
}

TEST(TotalPressure, AssignmentOperatorMultiplication) {
  TotalPressure total_pressure{4.0, Unit::Pressure::Pascal};
  total_pressure *= 2.0;
  EXPECT_EQ(total_pressure, TotalPressure(8.0, Unit::Pressure::Pascal));
}

TEST(TotalPressure, AssignmentOperatorSubtraction) {
  TotalPressure total_pressure{3.0, Unit::Pressure::Pascal};
  total_pressure -= TotalPressure(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(total_pressure, TotalPressure(1.0, Unit::Pressure::Pascal));
}

TEST(TotalPressure, ComparisonOperators) {
  const TotalPressure first{1.0, Unit::Pressure::Pascal};
  const TotalPressure second{2.0, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(TotalPressure, Constructor) {
  EXPECT_NO_THROW(TotalPressure(1.0, Unit::Pressure::Kilopascal));
  EXPECT_EQ(TotalPressure(StaticPressure(2.0, Unit::Pressure::Pascal),
                          DynamicPressure(1.0, Unit::Pressure::Pascal)),
            TotalPressure(3.0, Unit::Pressure::Pascal));
  EXPECT_EQ(StaticPressure(TotalPressure(3.0, Unit::Pressure::Pascal),
                           DynamicPressure(1.0, Unit::Pressure::Pascal)),
            StaticPressure(2.0, Unit::Pressure::Pascal));
  EXPECT_EQ(DynamicPressure(TotalPressure(3.0, Unit::Pressure::Pascal),
                            StaticPressure(2.0, Unit::Pressure::Pascal)),
            DynamicPressure(1.0, Unit::Pressure::Pascal));
}

TEST(TotalPressure, CopyAssignmentOperator) {
  {
    const TotalPressure<float> first(1.0F, Unit::Pressure::Pascal);
    TotalPressure<double> second = TotalPressure<double>::Zero();
    second = first;
    EXPECT_EQ(second, TotalPressure<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const TotalPressure<double> first(1.0, Unit::Pressure::Pascal);
    TotalPressure<double> second = TotalPressure<double>::Zero();
    second = first;
    EXPECT_EQ(second, TotalPressure<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const TotalPressure<long double> first(1.0L, Unit::Pressure::Pascal);
    TotalPressure<double> second = TotalPressure<double>::Zero();
    second = first;
    EXPECT_EQ(second, TotalPressure<double>(1.0, Unit::Pressure::Pascal));
  }
}

TEST(TotalPressure, CopyConstructor) {
  {
    const TotalPressure<float> first(1.0F, Unit::Pressure::Pascal);
    const TotalPressure<double> second{first};
    EXPECT_EQ(second, TotalPressure<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const TotalPressure<double> first(1.0, Unit::Pressure::Pascal);
    const TotalPressure<double> second{first};
    EXPECT_EQ(second, TotalPressure<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const TotalPressure<long double> first(1.0L, Unit::Pressure::Pascal);
    const TotalPressure<double> second{first};
    EXPECT_EQ(second, TotalPressure<double>(1.0, Unit::Pressure::Pascal));
  }
}

TEST(TotalPressure, Create) {
  constexpr TotalPressure total_pressure = TotalPressure<>::Create<Unit::Pressure::Pascal>(1.0);
  EXPECT_EQ(total_pressure, TotalPressure(1.0, Unit::Pressure::Pascal));
}

TEST(TotalPressure, DefaultConstructor) {
  EXPECT_NO_THROW(TotalPressure<>{});
}

TEST(TotalPressure, Dimensions) {
  EXPECT_EQ(TotalPressure<>::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(TotalPressure, Hash) {
  const TotalPressure first{1.0, Unit::Pressure::Kilopascal};
  const TotalPressure second{1.000001, Unit::Pressure::Kilopascal};
  const TotalPressure third{-1.0, Unit::Pressure::Kilopascal};
  const std::hash<TotalPressure<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(TotalPressure, JSON) {
  EXPECT_EQ(TotalPressure(1.0, Unit::Pressure::Pascal).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Pa\"}");
  EXPECT_EQ(TotalPressure(1.0, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kPa\"}");
}

TEST(TotalPressure, MoveAssignmentOperator) {
  TotalPressure first{1.0, Unit::Pressure::Pascal};
  TotalPressure second = TotalPressure<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, TotalPressure(1.0, Unit::Pressure::Pascal));
}

TEST(TotalPressure, MoveConstructor) {
  TotalPressure first{1.0, Unit::Pressure::Pascal};
  const TotalPressure second{std::move(first)};
  EXPECT_EQ(second, TotalPressure(1.0, Unit::Pressure::Pascal));
}

TEST(TotalPressure, MutableValue) {
  TotalPressure total_pressure{1.0, Unit::Pressure::Pascal};
  double& value = total_pressure.MutableValue();
  value = 2.0;
  EXPECT_EQ(total_pressure.Value(), 2.0);
}

TEST(TotalPressure, Performance) {
  TotalPressure first{1.2345678901234567890, Unit::Pressure::Pascal};
  TotalPressure second{1.2345678901234567890, Unit::Pressure::Pascal};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(TotalPressure, Print) {
  EXPECT_EQ(TotalPressure(1.0, Unit::Pressure::Pascal).Print(), Print(1.0) + " Pa");
  EXPECT_EQ(TotalPressure(1.0, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
            Print(1.0) + " kPa");
}

TEST(TotalPressure, SetValue) {
  TotalPressure total_pressure{1.0, Unit::Pressure::Pascal};
  total_pressure.SetValue(2.0);
  EXPECT_EQ(total_pressure.Value(), 2.0);
}

TEST(TotalPressure, SizeOf) {
  EXPECT_EQ(sizeof(TotalPressure<>{}), sizeof(double));
}

TEST(TotalPressure, StaticValue) {
  constexpr TotalPressure total_pressure = TotalPressure<>::Create<Unit::Pressure::Kilopascal>(1.0);
  constexpr double value = total_pressure.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.0);
}

TEST(TotalPressure, Stream) {
  std::ostringstream stream;
  stream << TotalPressure(1.0, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), TotalPressure(1.0, Unit::Pressure::Pascal).Print());
}

TEST(TotalPressure, Unit) {
  EXPECT_EQ(TotalPressure<>::Unit(), Standard<Unit::Pressure>);
}

TEST(TotalPressure, Value) {
  EXPECT_EQ(TotalPressure(1.0, Unit::Pressure::Pascal).Value(), 1.0);
  EXPECT_EQ(TotalPressure(1.0, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal), 1.0);
}

TEST(TotalPressure, XML) {
  EXPECT_EQ(TotalPressure(1.0, Unit::Pressure::Pascal).XML(),
            "<value>" + Print(1.0) + "</value><unit>Pa</unit>");
  EXPECT_EQ(TotalPressure(1.0, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value>" + Print(1.0) + "</value><unit>kPa</unit>");
}

TEST(TotalPressure, YAML) {
  EXPECT_EQ(
      TotalPressure(1.0, Unit::Pressure::Pascal).YAML(), "{value:" + Print(1.0) + ",unit:\"Pa\"}");
  EXPECT_EQ(TotalPressure(1.0, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
            "{value:" + Print(1.0) + ",unit:\"kPa\"}");
}

TEST(TotalPressure, Zero) {
  EXPECT_EQ(TotalPressure<>::Zero(), TotalPressure(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
