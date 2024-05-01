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

#include "../include/PhQ/VectorArea.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Area.hpp"
#include "../include/PhQ/Direction.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Area.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(VectorArea, Angle) {
  EXPECT_EQ(VectorArea({0.0, -2.0, 0.0}, Unit::Area::SquareMetre)
                .Angle(VectorArea({0.0, 0.0, 3.0}, Unit::Area::SquareMetre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(VectorArea, ArithmeticOperatorAddition) {
  EXPECT_EQ(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre)
                + VectorArea({2.0, -4.0, 6.0}, Unit::Area::SquareMetre),
            VectorArea({3.0, -6.0, 9.0}, Unit::Area::SquareMetre));
}

TEST(VectorArea, ArithmeticOperatorDivision) {
  EXPECT_EQ(VectorArea({2.0, -4.0, 6.0}, Unit::Area::SquareMetre) / 2.0,
            VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
}

TEST(VectorArea, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre) * 2.0,
            VectorArea({2.0, -4.0, 6.0}, Unit::Area::SquareMetre));
  EXPECT_EQ(2.0 * VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre),
            VectorArea({2.0, -4.0, 6.0}, Unit::Area::SquareMetre));
  EXPECT_EQ(Direction(2.0, -3.0, 6.0) * Area(7.0, Unit::Area::SquareMetre),
            VectorArea({2.0, -3.0, 6.0}, Unit::Area::SquareMetre));
  EXPECT_EQ(Area(7.0, Unit::Area::SquareMetre) * Direction(2.0, -3.0, 6.0),
            VectorArea({2.0, -3.0, 6.0}, Unit::Area::SquareMetre));
}

TEST(VectorArea, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(VectorArea({3.0, -6.0, 9.0}, Unit::Area::SquareMetre)
                - VectorArea({2.0, -4.0, 6.0}, Unit::Area::SquareMetre),
            VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
}

TEST(VectorArea, AssignmentOperatorAddition) {
  VectorArea vector_area({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  vector_area += VectorArea({2.0, -4.0, 6.0}, Unit::Area::SquareMetre);
  EXPECT_EQ(vector_area, VectorArea({3.0, -6.0, 9.0}, Unit::Area::SquareMetre));
}

TEST(VectorArea, AssignmentOperatorDivision) {
  VectorArea vector_area({2.0, -4.0, 6.0}, Unit::Area::SquareMetre);
  vector_area /= 2.0;
  EXPECT_EQ(vector_area, VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
}

TEST(VectorArea, AssignmentOperatorMultiplication) {
  VectorArea vector_area({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  vector_area *= 2.0;
  EXPECT_EQ(vector_area, VectorArea({2.0, -4.0, 6.0}, Unit::Area::SquareMetre));
}

TEST(VectorArea, AssignmentOperatorSubtraction) {
  VectorArea vector_area({3.0, -6.0, 9.0}, Unit::Area::SquareMetre);
  vector_area -= VectorArea({2.0, -4.0, 6.0}, Unit::Area::SquareMetre);
  EXPECT_EQ(vector_area, VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
}

TEST(VectorArea, ComparisonOperators) {
  const VectorArea first({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  const VectorArea second({1.0, -2.0, 3.000001}, Unit::Area::SquareMetre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(VectorArea, CopyAssignmentOperator) {
  const VectorArea first({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  VectorArea second = VectorArea::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(VectorArea, CopyConstructor) {
  const VectorArea first({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  const VectorArea second{first};
  EXPECT_EQ(second, first);
}

TEST(VectorArea, Create) {
  {
    constexpr VectorArea vector_area = VectorArea::Create<Unit::Area::SquareMetre>(1.0, -2.0, 3.0);
    EXPECT_EQ(vector_area, VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
  }
  {
    constexpr VectorArea vector_area =
        VectorArea::Create<Unit::Area::SquareMetre>(std::array<double, 3>{1.0, -2.0, 3.0});
    EXPECT_EQ(vector_area, VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
  }
  {
    constexpr VectorArea vector_area =
        VectorArea::Create<Unit::Area::SquareMetre>(Vector{1.0, -2.0, 3.0});
    EXPECT_EQ(vector_area, VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
  }
}

TEST(VectorArea, DefaultConstructor) {
  EXPECT_NO_THROW(VectorArea{});
}

TEST(VectorArea, Dimensions) {
  EXPECT_EQ(VectorArea::Dimensions(), RelatedDimensions<Unit::Area>);
}

TEST(VectorArea, Direction) {
  EXPECT_EQ(
      VectorArea({2.0, -3.0, 6.0}, Unit::Area::SquareMetre).Direction(), Direction(2.0, -3.0, 6.0));
}

TEST(VectorArea, Hash) {
  const VectorArea first({1.0, -2.0, 3.0}, Unit::Area::SquareMillimetre);
  const VectorArea second({1.0, -2.0, 3.000001}, Unit::Area::SquareMillimetre);
  const VectorArea third({1.0, 2.0, 3.0}, Unit::Area::SquareMillimetre);
  const std::hash<VectorArea> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(VectorArea, JSON) {
  EXPECT_EQ(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"m^2\"}");
  EXPECT_EQ(
      VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMillimetre).JSON(Unit::Area::SquareMillimetre),
      "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
          + "},\"unit\":\"mm^2\"}");
}

TEST(VectorArea, Magnitude) {
  EXPECT_EQ(VectorArea({2.0, -3.0, 6.0}, Unit::Area::SquareMetre).Magnitude(),
            Area(7.0, Unit::Area::SquareMetre));
}

TEST(VectorArea, MiscellaneousConstructors) {
  EXPECT_EQ(
      Direction(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre)), Direction(1.0, -2.0, 3.0));
  EXPECT_EQ(Angle(VectorArea({0.0, -2.0, 0.0}, Unit::Area::SquareMetre),
                  VectorArea({0.0, 0.0, 3.0}, Unit::Area::SquareMetre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(VectorArea, MoveAssignmentOperator) {
  VectorArea first({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  VectorArea second = VectorArea::Zero();
  second = std::move(first);
  EXPECT_EQ(second, VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
}

TEST(VectorArea, MoveConstructor) {
  VectorArea first({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  const VectorArea second{std::move(first)};
  EXPECT_EQ(second, VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
}

TEST(VectorArea, MutableValue) {
  VectorArea vector_area({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  Vector& value = vector_area.MutableValue();
  value = Vector{-4.0, 5.0, -6.0};
  EXPECT_EQ(vector_area.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(VectorArea, Print) {
  EXPECT_EQ(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") m^2");
  EXPECT_EQ(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMillimetre)
                .Print(Unit::Area::SquareMillimetre),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") mm^2");
}

TEST(VectorArea, SetValue) {
  VectorArea vector_area({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  vector_area.SetValue({-4.0, 5.0, -6.0});
  EXPECT_EQ(vector_area.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(VectorArea, SizeOf) {
  EXPECT_EQ(sizeof(VectorArea{}), 3 * sizeof(double));
}

TEST(VectorArea, StandardConstructor) {
  EXPECT_NO_THROW(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMillimetre));
}

TEST(VectorArea, StaticValue) {
  constexpr VectorArea vector_area =
      VectorArea::Create<Unit::Area::SquareMillimetre>(1.0, -2.0, 3.0);
  constexpr Vector value = vector_area.StaticValue<Unit::Area::SquareMillimetre>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(VectorArea, Stream) {
  std::ostringstream stream;
  stream << VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  EXPECT_EQ(stream.str(), VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre).Print());
}

TEST(VectorArea, Unit) {
  EXPECT_EQ(VectorArea::Unit(), Standard<Unit::Area>);
}

TEST(VectorArea, Value) {
  EXPECT_EQ(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre).Value(), Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMillimetre)
                .Value(Unit::Area::SquareMillimetre),
            Vector(1.0, -2.0, 3.0));
}

TEST(VectorArea, XML) {
  EXPECT_EQ(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>m^2</unit>");
  EXPECT_EQ(
      VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMillimetre).XML(Unit::Area::SquareMillimetre),
      "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
          + "</z></value><unit>mm^2</unit>");
}

TEST(VectorArea, XYZ) {
  EXPECT_EQ(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre).x(),
            Area(1.0, Unit::Area::SquareMetre));
  EXPECT_EQ(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre).y(),
            Area(-2.0, Unit::Area::SquareMetre));
  EXPECT_EQ(VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre).z(),
            Area(3.0, Unit::Area::SquareMetre));
}

TEST(VectorArea, YAML) {
  EXPECT_EQ(
      VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMetre).YAML(),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"m^2\"}");
  EXPECT_EQ(
      VectorArea({1.0, -2.0, 3.0}, Unit::Area::SquareMillimetre).YAML(Unit::Area::SquareMillimetre),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"mm^2\"}");
}

TEST(VectorArea, Zero) {
  EXPECT_EQ(VectorArea::Zero(), VectorArea({0.0, 0.0, 0.0}, Unit::Area::SquareMetre));
}

}  // namespace

}  // namespace PhQ