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

#include "../include/PhQ/DynamicPressure.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/MassDensity.hpp"
#include "../include/PhQ/Speed.hpp"
#include "../include/PhQ/Unit/MassDensity.hpp"
#include "../include/PhQ/Unit/Pressure.hpp"
#include "../include/PhQ/Unit/Speed.hpp"

namespace PhQ {

namespace {

TEST(DynamicPressure, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      DynamicPressure(1.0, Unit::Pressure::Pascal) + DynamicPressure(2.0, Unit::Pressure::Pascal),
      DynamicPressure(3.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, ArithmeticOperatorDivision) {
  EXPECT_EQ(DynamicPressure(8.0, Unit::Pressure::Pascal) / 2.0,
            DynamicPressure(4.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      DynamicPressure(8.0, Unit::Pressure::Pascal) / DynamicPressure(2.0, Unit::Pressure::Pascal),
      4.0);
}

TEST(DynamicPressure, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(DynamicPressure(4.0, Unit::Pressure::Pascal) * 2.0,
            DynamicPressure(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(2.0 * DynamicPressure(4.0, Unit::Pressure::Pascal),
            DynamicPressure(8.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      DynamicPressure(3.0, Unit::Pressure::Pascal) - DynamicPressure(2.0, Unit::Pressure::Pascal),
      DynamicPressure(1.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, AssignmentOperatorAddition) {
  DynamicPressure dynamic_pressure{1.0, Unit::Pressure::Pascal};
  dynamic_pressure += DynamicPressure(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(dynamic_pressure, DynamicPressure(3.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, AssignmentOperatorDivision) {
  DynamicPressure dynamic_pressure{8.0, Unit::Pressure::Pascal};
  dynamic_pressure /= 2.0;
  EXPECT_EQ(dynamic_pressure, DynamicPressure(4.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, AssignmentOperatorMultiplication) {
  DynamicPressure dynamic_pressure{4.0, Unit::Pressure::Pascal};
  dynamic_pressure *= 2.0;
  EXPECT_EQ(dynamic_pressure, DynamicPressure(8.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, AssignmentOperatorSubtraction) {
  DynamicPressure dynamic_pressure{3.0, Unit::Pressure::Pascal};
  dynamic_pressure -= DynamicPressure(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(dynamic_pressure, DynamicPressure(1.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, ComparisonOperators) {
  const DynamicPressure first{1.0, Unit::Pressure::Pascal};
  const DynamicPressure second{2.0, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(DynamicPressure, Constructor) {
  EXPECT_NO_THROW(DynamicPressure(1.0, Unit::Pressure::Kilopascal));
  EXPECT_EQ(DynamicPressure(MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                            Speed(4.0, Unit::Speed::MetrePerSecond)),
            DynamicPressure(16.0, Unit::Pressure::Pascal));
  EXPECT_EQ(MassDensity(DynamicPressure(16.0, Unit::Pressure::Pascal),
                        Speed(4.0, Unit::Speed::MetrePerSecond)),
            MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre));
  EXPECT_EQ(Speed(DynamicPressure(16.0, Unit::Pressure::Pascal),
                  MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre)),
            Speed(4.0, Unit::Speed::MetrePerSecond));
}

TEST(DynamicPressure, CopyAssignmentOperator) {
  {
    const DynamicPressure<float> first(1.0F, Unit::Pressure::Pascal);
    DynamicPressure<double> second = DynamicPressure<double>::Zero();
    second = first;
    EXPECT_EQ(second, DynamicPressure<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const DynamicPressure<double> first(1.0, Unit::Pressure::Pascal);
    DynamicPressure<double> second = DynamicPressure<double>::Zero();
    second = first;
    EXPECT_EQ(second, DynamicPressure<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const DynamicPressure<long double> first(1.0L, Unit::Pressure::Pascal);
    DynamicPressure<double> second = DynamicPressure<double>::Zero();
    second = first;
    EXPECT_EQ(second, DynamicPressure<double>(1.0, Unit::Pressure::Pascal));
  }
}

TEST(DynamicPressure, CopyConstructor) {
  {
    const DynamicPressure<float> first(1.0F, Unit::Pressure::Pascal);
    const DynamicPressure<double> second{first};
    EXPECT_EQ(second, DynamicPressure<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const DynamicPressure<double> first(1.0, Unit::Pressure::Pascal);
    const DynamicPressure<double> second{first};
    EXPECT_EQ(second, DynamicPressure<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const DynamicPressure<long double> first(1.0L, Unit::Pressure::Pascal);
    const DynamicPressure<double> second{first};
    EXPECT_EQ(second, DynamicPressure<double>(1.0, Unit::Pressure::Pascal));
  }
}

TEST(DynamicPressure, Create) {
  constexpr DynamicPressure dynamic_pressure =
      DynamicPressure<>::Create<Unit::Pressure::Pascal>(1.0);
  EXPECT_EQ(dynamic_pressure, DynamicPressure(1.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, DefaultConstructor) {
  EXPECT_NO_THROW(DynamicPressure<>{});
}

TEST(DynamicPressure, Dimensions) {
  EXPECT_EQ(DynamicPressure<>::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(DynamicPressure, Hash) {
  const DynamicPressure first{1.0, Unit::Pressure::Kilopascal};
  const DynamicPressure second{1.000001, Unit::Pressure::Kilopascal};
  const DynamicPressure third{-1.0, Unit::Pressure::Kilopascal};
  const std::hash<DynamicPressure<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DynamicPressure, JSON) {
  EXPECT_EQ(DynamicPressure(1.0, Unit::Pressure::Pascal).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Pa\"}");
  EXPECT_EQ(DynamicPressure(1.0, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kPa\"}");
}

TEST(DynamicPressure, MoveAssignmentOperator) {
  DynamicPressure first{1.0, Unit::Pressure::Pascal};
  DynamicPressure second = DynamicPressure<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, DynamicPressure(1.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, MoveConstructor) {
  DynamicPressure first{1.0, Unit::Pressure::Pascal};
  const DynamicPressure second{std::move(first)};
  EXPECT_EQ(second, DynamicPressure(1.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, MutableValue) {
  DynamicPressure dynamic_pressure{1.0, Unit::Pressure::Pascal};
  double& value = dynamic_pressure.MutableValue();
  value = 2.0;
  EXPECT_EQ(dynamic_pressure.Value(), 2.0);
}

TEST(DynamicPressure, Print) {
  EXPECT_EQ(DynamicPressure(1.0, Unit::Pressure::Pascal).Print(), Print(1.0) + " Pa");
  EXPECT_EQ(DynamicPressure(1.0, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
            Print(1.0) + " kPa");
}

TEST(DynamicPressure, SetValue) {
  DynamicPressure dynamic_pressure{1.0, Unit::Pressure::Pascal};
  dynamic_pressure.SetValue(2.0);
  EXPECT_EQ(dynamic_pressure.Value(), 2.0);
}

TEST(DynamicPressure, SizeOf) {
  EXPECT_EQ(sizeof(DynamicPressure<>{}), sizeof(double));
}

TEST(DynamicPressure, StaticValue) {
  constexpr DynamicPressure dynamic_pressure =
      DynamicPressure<>::Create<Unit::Pressure::Kilopascal>(1.0);
  constexpr double value = dynamic_pressure.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.0);
}

TEST(DynamicPressure, Stream) {
  std::ostringstream stream;
  stream << DynamicPressure(1.0, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), DynamicPressure(1.0, Unit::Pressure::Pascal).Print());
}

TEST(DynamicPressure, Unit) {
  EXPECT_EQ(DynamicPressure<>::Unit(), Standard<Unit::Pressure>);
}

TEST(DynamicPressure, Value) {
  EXPECT_EQ(DynamicPressure(1.0, Unit::Pressure::Pascal).Value(), 1.0);
  EXPECT_EQ(
      DynamicPressure(1.0, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal), 1.0);
}

TEST(DynamicPressure, XML) {
  EXPECT_EQ(DynamicPressure(1.0, Unit::Pressure::Pascal).XML(),
            "<value>" + Print(1.0) + "</value><unit>Pa</unit>");
  EXPECT_EQ(DynamicPressure(1.0, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value>" + Print(1.0) + "</value><unit>kPa</unit>");
}

TEST(DynamicPressure, YAML) {
  EXPECT_EQ(DynamicPressure(1.0, Unit::Pressure::Pascal).YAML(),
            "{value:" + Print(1.0) + ",unit:\"Pa\"}");
  EXPECT_EQ(DynamicPressure(1.0, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
            "{value:" + Print(1.0) + ",unit:\"kPa\"}");
}

TEST(DynamicPressure, Zero) {
  EXPECT_EQ(DynamicPressure<>::Zero(), DynamicPressure(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
