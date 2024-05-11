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

#include "../include/PhQ/Area.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/Unit/Area.hpp"
#include "../include/PhQ/Unit/Length.hpp"

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

TEST(Area, CopyAssignmentOperator) {
  const Area first{1.0, Unit::Area::SquareMetre};
  Area second = Area<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Area, CopyConstructor) {
  const Area first{1.0, Unit::Area::SquareMetre};
  const Area second{first};
  EXPECT_EQ(second, first);
}

TEST(Area, Create) {
  constexpr Area area = Area<>::Create<Unit::Area::SquareMetre>(1.0);
  EXPECT_EQ(area, Area(1.0, Unit::Area::SquareMetre));
}

TEST(Area, DefaultConstructor) {
  EXPECT_NO_THROW(Area{});
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
  EXPECT_EQ(sizeof(Area{}), sizeof(double));
}

TEST(Area, StandardConstructor) {
  EXPECT_NO_THROW(Area(1.0, Unit::Area::SquareMillimetre));
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
