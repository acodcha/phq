// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#include "../include/PhQ/SolidAngle.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/SolidAngle.hpp"

namespace PhQ {

namespace {

TEST(SolidAngle, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      SolidAngle(1.0, Unit::SolidAngle::Steradian) + SolidAngle(2.0, Unit::SolidAngle::Steradian),
      SolidAngle(3.0, Unit::SolidAngle::Steradian));
}

TEST(SolidAngle, ArithmeticOperatorDivision) {
  EXPECT_EQ(SolidAngle(8.0, Unit::SolidAngle::Steradian) / 2.0,
            SolidAngle(4.0, Unit::SolidAngle::Steradian));
  EXPECT_EQ(
      SolidAngle(8.0, Unit::SolidAngle::Steradian) / SolidAngle(2.0, Unit::SolidAngle::Steradian),
      4.0);
}

TEST(SolidAngle, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SolidAngle(4.0, Unit::SolidAngle::Steradian) * 2.0,
            SolidAngle(8.0, Unit::SolidAngle::Steradian));
  EXPECT_EQ(2.0 * SolidAngle(4.0, Unit::SolidAngle::Steradian),
            SolidAngle(8.0, Unit::SolidAngle::Steradian));
}

TEST(SolidAngle, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      SolidAngle(3.0, Unit::SolidAngle::Steradian) - SolidAngle(2.0, Unit::SolidAngle::Steradian),
      SolidAngle(1.0, Unit::SolidAngle::Steradian));
}

TEST(SolidAngle, AssignmentOperatorAddition) {
  SolidAngle solid_angle{1.0, Unit::SolidAngle::Steradian};
  solid_angle += SolidAngle(2.0, Unit::SolidAngle::Steradian);
  EXPECT_EQ(solid_angle, SolidAngle(3.0, Unit::SolidAngle::Steradian));
}

TEST(SolidAngle, AssignmentOperatorDivision) {
  SolidAngle solid_angle{8.0, Unit::SolidAngle::Steradian};
  solid_angle /= 2.0;
  EXPECT_EQ(solid_angle, SolidAngle(4.0, Unit::SolidAngle::Steradian));
}

TEST(SolidAngle, AssignmentOperatorMultiplication) {
  SolidAngle solid_angle{4.0, Unit::SolidAngle::Steradian};
  solid_angle *= 2.0;
  EXPECT_EQ(solid_angle, SolidAngle(8.0, Unit::SolidAngle::Steradian));
}

TEST(SolidAngle, AssignmentOperatorSubtraction) {
  SolidAngle solid_angle{3.0, Unit::SolidAngle::Steradian};
  solid_angle -= SolidAngle(2.0, Unit::SolidAngle::Steradian);
  EXPECT_EQ(solid_angle, SolidAngle(1.0, Unit::SolidAngle::Steradian));
}

TEST(SolidAngle, ComparisonOperators) {
  const SolidAngle first{1.0, Unit::SolidAngle::Steradian};
  const SolidAngle second{2.0, Unit::SolidAngle::Steradian};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(SolidAngle, Constructor) {
  EXPECT_NO_THROW(SolidAngle(1.0, Unit::SolidAngle::SquareDegree));
}

TEST(SolidAngle, CopyAssignmentOperator) {
  {
    const SolidAngle<float> first(1.0F, Unit::SolidAngle::Steradian);
    SolidAngle<double> second = SolidAngle<double>::Zero();
    second = first;
    EXPECT_EQ(second, SolidAngle<double>(1.0, Unit::SolidAngle::Steradian));
  }
  {
    const SolidAngle<double> first(1.0, Unit::SolidAngle::Steradian);
    SolidAngle<double> second = SolidAngle<double>::Zero();
    second = first;
    EXPECT_EQ(second, SolidAngle<double>(1.0, Unit::SolidAngle::Steradian));
  }
  {
    const SolidAngle<long double> first(1.0L, Unit::SolidAngle::Steradian);
    SolidAngle<double> second = SolidAngle<double>::Zero();
    second = first;
    EXPECT_EQ(second, SolidAngle<double>(1.0, Unit::SolidAngle::Steradian));
  }
}

TEST(SolidAngle, CopyConstructor) {
  {
    const SolidAngle<float> first(1.0F, Unit::SolidAngle::Steradian);
    const SolidAngle<double> second{first};
    EXPECT_EQ(second, SolidAngle<double>(1.0, Unit::SolidAngle::Steradian));
  }
  {
    const SolidAngle<double> first(1.0, Unit::SolidAngle::Steradian);
    const SolidAngle<double> second{first};
    EXPECT_EQ(second, SolidAngle<double>(1.0, Unit::SolidAngle::Steradian));
  }
  {
    const SolidAngle<long double> first(1.0L, Unit::SolidAngle::Steradian);
    const SolidAngle<double> second{first};
    EXPECT_EQ(second, SolidAngle<double>(1.0, Unit::SolidAngle::Steradian));
  }
}

TEST(SolidAngle, Create) {
  constexpr SolidAngle solid_angle = SolidAngle<>::Create<Unit::SolidAngle::Steradian>(1.0);
  EXPECT_EQ(solid_angle, SolidAngle(1.0, Unit::SolidAngle::Steradian));
}

TEST(SolidAngle, DefaultConstructor) {
  EXPECT_NO_THROW(SolidAngle<>{});
}

TEST(SolidAngle, Dimensions) {
  EXPECT_EQ(SolidAngle<>::Dimensions(), RelatedDimensions<Unit::SolidAngle>);
}

TEST(SolidAngle, Hash) {
  const SolidAngle first{1.0, Unit::SolidAngle::SquareDegree};
  const SolidAngle second{1.000001, Unit::SolidAngle::SquareDegree};
  const SolidAngle third{-1.0, Unit::SolidAngle::SquareDegree};
  const std::hash<SolidAngle<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(SolidAngle, JSON) {
  EXPECT_EQ(SolidAngle(1.0, Unit::SolidAngle::Steradian).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"sr\"}");
  EXPECT_EQ(SolidAngle(1.0, Unit::SolidAngle::SquareDegree).JSON(Unit::SolidAngle::SquareDegree),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"deg^2\"}");
}

TEST(SolidAngle, MoveAssignmentOperator) {
  SolidAngle first{1.0, Unit::SolidAngle::Steradian};
  SolidAngle second = SolidAngle<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, SolidAngle(1.0, Unit::SolidAngle::Steradian));
}

TEST(SolidAngle, MoveConstructor) {
  SolidAngle first{1.0, Unit::SolidAngle::Steradian};
  const SolidAngle second{std::move(first)};
  EXPECT_EQ(second, SolidAngle(1.0, Unit::SolidAngle::Steradian));
}

TEST(SolidAngle, MutableValue) {
  SolidAngle solid_angle{1.0, Unit::SolidAngle::Steradian};
  double& value = solid_angle.MutableValue();
  value = 2.0;
  EXPECT_EQ(solid_angle.Value(), 2.0);
}

TEST(SolidAngle, Print) {
  EXPECT_EQ(SolidAngle(1.0, Unit::SolidAngle::Steradian).Print(), Print(1.0) + " sr");
  EXPECT_EQ(SolidAngle(1.0, Unit::SolidAngle::SquareDegree).Print(Unit::SolidAngle::SquareDegree),
            Print(1.0) + " deg^2");
}

TEST(SolidAngle, SetValue) {
  SolidAngle solid_angle{1.0, Unit::SolidAngle::Steradian};
  solid_angle.SetValue(2.0);
  EXPECT_EQ(solid_angle.Value(), 2.0);
}

TEST(SolidAngle, SizeOf) {
  EXPECT_EQ(sizeof(SolidAngle<>{}), sizeof(double));
}

TEST(SolidAngle, StaticValue) {
  constexpr SolidAngle solid_angle = SolidAngle<>::Create<Unit::SolidAngle::SquareDegree>(1.0);
  constexpr double value = solid_angle.StaticValue<Unit::SolidAngle::SquareDegree>();
  EXPECT_EQ(value, 1.0);
}

TEST(SolidAngle, Stream) {
  std::ostringstream stream;
  stream << SolidAngle(1.0, Unit::SolidAngle::Steradian);
  EXPECT_EQ(stream.str(), SolidAngle(1.0, Unit::SolidAngle::Steradian).Print());
}

TEST(SolidAngle, Unit) {
  EXPECT_EQ(SolidAngle<>::Unit(), Standard<Unit::SolidAngle>);
}

TEST(SolidAngle, Value) {
  EXPECT_EQ(SolidAngle(1.0, Unit::SolidAngle::Steradian).Value(), 1.0);
  EXPECT_EQ(
      SolidAngle(1.0, Unit::SolidAngle::SquareDegree).Value(Unit::SolidAngle::SquareDegree), 1.0);
}

TEST(SolidAngle, XML) {
  EXPECT_EQ(SolidAngle(1.0, Unit::SolidAngle::Steradian).XML(),
            "<value>" + Print(1.0) + "</value><unit>sr</unit>");
  EXPECT_EQ(SolidAngle(1.0, Unit::SolidAngle::SquareDegree).XML(Unit::SolidAngle::SquareDegree),
            "<value>" + Print(1.0) + "</value><unit>deg^2</unit>");
}

TEST(SolidAngle, YAML) {
  EXPECT_EQ(SolidAngle(1.0, Unit::SolidAngle::Steradian).YAML(),
            "{value:" + Print(1.0) + ",unit:\"sr\"}");
  EXPECT_EQ(SolidAngle(1.0, Unit::SolidAngle::SquareDegree).YAML(Unit::SolidAngle::SquareDegree),
            "{value:" + Print(1.0) + ",unit:\"deg^2\"}");
}

TEST(SolidAngle, Zero) {
  EXPECT_EQ(SolidAngle<>::Zero(), SolidAngle(0.0, Unit::SolidAngle::Steradian));
}

}  // namespace

}  // namespace PhQ
