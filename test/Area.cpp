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

#include "../include/PhQ/Area.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/Unit/Area.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(Area, ArithmeticOperatorAddition) {
  EXPECT_EQ(Area(1.0, Unit::Area::SquareMetre) + Area(2.0, Unit::Area::SquareMetre),
            Area(3.0, Unit::Area::SquareMetre));
}

TEST(Area, ArithmeticOperatorDivision) {
  EXPECT_EQ(Area(8.0, Unit::Area::SquareMetre) / 2.0, Area(4.0, Unit::Area::SquareMetre));

  EXPECT_EQ(Area(8.0, Unit::Area::SquareMetre) / Area(2.0, Unit::Area::SquareMetre), 4.0);

  EXPECT_EQ(Area(8.0, Unit::Area::SquareMetre) / Length(4.0, Unit::Length::Metre),
            Length(2.0, Unit::Length::Metre));
}

TEST(Area, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Area(4.0, Unit::Area::SquareMetre) * 2.0, Area(8.0, Unit::Area::SquareMetre));

  EXPECT_EQ(2.0 * Area(4.0, Unit::Area::SquareMetre), Area(8.0, Unit::Area::SquareMetre));

  EXPECT_EQ(Length(4.0, Unit::Length::Metre) * Length(2.0, Unit::Length::Metre),
            Area(8.0, Unit::Area::SquareMetre));
}

TEST(Area, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Area(3.0, Unit::Area::SquareMetre) - Area(2.0, Unit::Area::SquareMetre),
            Area(1.0, Unit::Area::SquareMetre));
}

TEST(Area, AssignmentOperatorAddition) {
  Area area{1.0, Unit::Area::SquareMetre};
  area += Area(2.0, Unit::Area::SquareMetre);
  EXPECT_EQ(area, Area(3.0, Unit::Area::SquareMetre));
}

TEST(Area, AssignmentOperatorDivision) {
  Area area{8.0, Unit::Area::SquareMetre};
  area /= 2.0;
  EXPECT_EQ(area, Area(4.0, Unit::Area::SquareMetre));
}

TEST(Area, AssignmentOperatorMultiplication) {
  Area area{4.0, Unit::Area::SquareMetre};
  area *= 2.0;
  EXPECT_EQ(area, Area(8.0, Unit::Area::SquareMetre));
}

TEST(Area, AssignmentOperatorSubtraction) {
  Area area{3.0, Unit::Area::SquareMetre};
  area -= Area(2.0, Unit::Area::SquareMetre);
  EXPECT_EQ(area, Area(1.0, Unit::Area::SquareMetre));
}

TEST(Area, ComparisonOperators) {
  const Area first{1.0, Unit::Area::SquareMetre};
  const Area second{2.0, Unit::Area::SquareMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Area, Constructor) {
  EXPECT_NO_THROW(Area(1.0, Unit::Area::SquareMillimetre));
}

TEST(Area, CopyAssignmentOperator) {
  {
    const Area<float> first(1.0F, Unit::Area::SquareMetre);
    Area<double> second = Area<double>::Zero();
    second = first;
    EXPECT_EQ(second, Area<double>(1.0, Unit::Area::SquareMetre));
  }
  {
    const Area<double> first(1.0, Unit::Area::SquareMetre);
    Area<double> second = Area<double>::Zero();
    second = first;
    EXPECT_EQ(second, Area<double>(1.0, Unit::Area::SquareMetre));
  }
  {
    const Area<long double> first(1.0L, Unit::Area::SquareMetre);
    Area<double> second = Area<double>::Zero();
    second = first;
    EXPECT_EQ(second, Area<double>(1.0, Unit::Area::SquareMetre));
  }
}

TEST(Area, CopyConstructor) {
  {
    const Area<float> first(1.0F, Unit::Area::SquareMetre);
    const Area<double> second{first};
    EXPECT_EQ(second, Area<double>(1.0, Unit::Area::SquareMetre));
  }
  {
    const Area<double> first(1.0, Unit::Area::SquareMetre);
    const Area<double> second{first};
    EXPECT_EQ(second, Area<double>(1.0, Unit::Area::SquareMetre));
  }
  {
    const Area<long double> first(1.0L, Unit::Area::SquareMetre);
    const Area<double> second{first};
    EXPECT_EQ(second, Area<double>(1.0, Unit::Area::SquareMetre));
  }
}

TEST(Area, Create) {
  constexpr Area area = Area<>::Create<Unit::Area::SquareMetre>(1.0);
  EXPECT_EQ(area, Area(1.0, Unit::Area::SquareMetre));
}

TEST(Area, DefaultConstructor) {
  EXPECT_NO_THROW(Area<>{});
}

TEST(Area, Dimensions) {
  EXPECT_EQ(Area<>::Dimensions(), RelatedDimensions<Unit::Area>);
}

TEST(Area, Hash) {
  const Area first{1.0, Unit::Area::SquareMetre};
  const Area second{1.000001, Unit::Area::SquareMetre};
  const Area third{-1.0, Unit::Area::SquareMetre};
  const std::hash<Area<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Area, JSON) {
  EXPECT_EQ(
      Area(1.0, Unit::Area::SquareMetre).JSON(), "{\"value\":" + Print(1.0) + ",\"unit\":\"m^2\"}");
  EXPECT_EQ(Area(1.0, Unit::Area::SquareMillimetre).JSON(Unit::Area::SquareMillimetre),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"mm^2\"}");
}

TEST(Area, MoveAssignmentOperator) {
  Area first{1.0, Unit::Area::SquareMetre};
  Area second = Area<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Area(1.0, Unit::Area::SquareMetre));
}

TEST(Area, MoveConstructor) {
  Area first{1.0, Unit::Area::SquareMetre};
  const Area second{std::move(first)};
  EXPECT_EQ(second, Area(1.0, Unit::Area::SquareMetre));
}

TEST(Area, MutableValue) {
  Area area{1.0, Unit::Area::SquareMetre};
  double& value = area.MutableValue();
  value = 2.0;
  EXPECT_EQ(area.Value(), 2.0);
}

TEST(Area, Performance) {
  Area first{1.2345678901234567890, Unit::Area::SquareMetre};
  Area second{1.2345678901234567890, Unit::Area::SquareMetre};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(Area, Print) {
  EXPECT_EQ(Area(1.0, Unit::Area::SquareMetre).Print(), Print(1.0) + " m^2");
  EXPECT_EQ(Area(1.0, Unit::Area::SquareMillimetre).Print(Unit::Area::SquareMillimetre),
            Print(1.0) + " mm^2");
}

TEST(Area, SetValue) {
  Area area{1.0, Unit::Area::SquareMetre};
  area.SetValue(2.0);
  EXPECT_EQ(area.Value(), 2.0);
}

TEST(Area, SizeOf) {
  EXPECT_EQ(sizeof(Area<>{}), sizeof(double));
}

TEST(Area, StaticValue) {
  constexpr Area area = Area<>::Create<Unit::Area::SquareMetre>(1.0);
  constexpr double value = area.StaticValue<Unit::Area::SquareMetre>();
  EXPECT_EQ(value, 1.0);
}

TEST(Area, Stream) {
  std::ostringstream stream;
  stream << Area(1.0, Unit::Area::SquareMetre);
  EXPECT_EQ(stream.str(), Area(1.0, Unit::Area::SquareMetre).Print());
}

TEST(Area, Unit) {
  EXPECT_EQ(Area<>::Unit(), Standard<Unit::Area>);
}

TEST(Area, Value) {
  EXPECT_EQ(Area(1.0, Unit::Area::SquareMetre).Value(), 1.0);
  EXPECT_EQ(Area(1.0, Unit::Area::SquareMillimetre).Value(Unit::Area::SquareMillimetre), 1.0);
}

TEST(Area, XML) {
  EXPECT_EQ(Area(1.0, Unit::Area::SquareMetre).XML(),
            "<value>" + Print(1.0) + "</value><unit>m^2</unit>");
  EXPECT_EQ(Area(1.0, Unit::Area::SquareMillimetre).XML(Unit::Area::SquareMillimetre),
            "<value>" + Print(1.0) + "</value><unit>mm^2</unit>");
}

TEST(Area, YAML) {
  EXPECT_EQ(Area(1.0, Unit::Area::SquareMetre).YAML(), "{value:" + Print(1.0) + ",unit:\"m^2\"}");
  EXPECT_EQ(Area(1.0, Unit::Area::SquareMillimetre).YAML(Unit::Area::SquareMillimetre),
            "{value:" + Print(1.0) + ",unit:\"mm^2\"}");
}

TEST(Area, Zero) {
  EXPECT_EQ(Area<>::Zero(), Area(0.0, Unit::Area::SquareMetre));
}

}  // namespace

}  // namespace PhQ
