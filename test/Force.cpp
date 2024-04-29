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

#include "../include/PhQ/Force.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Direction.hpp"
#include "../include/PhQ/ScalarForce.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Force.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(Force, Angle) {
  EXPECT_EQ(Force({0.0, -2.0, 0.0}, Unit::Force::Newton)
                .Angle(Force({0.0, 0.0, 3.0}, Unit::Force::Newton)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Force, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      Force({1.0, -2.0, 3.0}, Unit::Force::Newton) + Force({2.0, -4.0, 6.0}, Unit::Force::Newton),
      Force({3.0, -6.0, 9.0}, Unit::Force::Newton));
}

TEST(Force, ArithmeticOperatorDivision) {
  EXPECT_EQ(Force({2.0, -4.0, 6.0}, Unit::Force::Newton) / 2.0,
            Force({1.0, -2.0, 3.0}, Unit::Force::Newton));
}

TEST(Force, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Force({1.0, -2.0, 3.0}, Unit::Force::Newton) * 2.0,
            Force({2.0, -4.0, 6.0}, Unit::Force::Newton));
  EXPECT_EQ(2.0 * Force({1.0, -2.0, 3.0}, Unit::Force::Newton),
            Force({2.0, -4.0, 6.0}, Unit::Force::Newton));
  EXPECT_EQ(Direction(2.0, -3.0, 6.0) * ScalarForce(7.0, Unit::Force::Newton),
            Force({2.0, -3.0, 6.0}, Unit::Force::Newton));
  EXPECT_EQ(ScalarForce(7.0, Unit::Force::Newton) * Direction(2.0, -3.0, 6.0),
            Force({2.0, -3.0, 6.0}, Unit::Force::Newton));
}

TEST(Force, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      Force({3.0, -6.0, 9.0}, Unit::Force::Newton) - Force({2.0, -4.0, 6.0}, Unit::Force::Newton),
      Force({1.0, -2.0, 3.0}, Unit::Force::Newton));
}

TEST(Force, AssignmentOperatorAddition) {
  Force force({1.0, -2.0, 3.0}, Unit::Force::Newton);
  force += Force({2.0, -4.0, 6.0}, Unit::Force::Newton);
  EXPECT_EQ(force, Force({3.0, -6.0, 9.0}, Unit::Force::Newton));
}

TEST(Force, AssignmentOperatorDivision) {
  Force force({2.0, -4.0, 6.0}, Unit::Force::Newton);
  force /= 2.0;
  EXPECT_EQ(force, Force({1.0, -2.0, 3.0}, Unit::Force::Newton));
}

TEST(Force, AssignmentOperatorMultiplication) {
  Force force({1.0, -2.0, 3.0}, Unit::Force::Newton);
  force *= 2.0;
  EXPECT_EQ(force, Force({2.0, -4.0, 6.0}, Unit::Force::Newton));
}

TEST(Force, AssignmentOperatorSubtraction) {
  Force force({3.0, -6.0, 9.0}, Unit::Force::Newton);
  force -= Force({2.0, -4.0, 6.0}, Unit::Force::Newton);
  EXPECT_EQ(force, Force({1.0, -2.0, 3.0}, Unit::Force::Newton));
}

TEST(Force, ComparisonOperators) {
  const Force first({1.0, -2.0, 3.0}, Unit::Force::Newton);
  const Force second({1.0, -2.0, 3.000001}, Unit::Force::Newton);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Force, CopyAssignmentOperator) {
  const Force first({1.0, -2.0, 3.0}, Unit::Force::Newton);
  Force second = Force::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Force, CopyConstructor) {
  const Force first({1.0, -2.0, 3.0}, Unit::Force::Newton);
  const Force second{first};
  EXPECT_EQ(second, first);
}

TEST(Force, Create) {
  {
    constexpr Force force = Force::Create<Unit::Force::Newton>(1.0, -2.0, 3.0);
    EXPECT_EQ(force, Force({1.0, -2.0, 3.0}, Unit::Force::Newton));
  }
  {
    constexpr Force force =
        Force::Create<Unit::Force::Newton>(std::array<double, 3>{1.0, -2.0, 3.0});
    EXPECT_EQ(force, Force({1.0, -2.0, 3.0}, Unit::Force::Newton));
  }
  {
    constexpr Force force = Force::Create<Unit::Force::Newton>(Vector{1.0, -2.0, 3.0});
    EXPECT_EQ(force, Force({1.0, -2.0, 3.0}, Unit::Force::Newton));
  }
}

TEST(Force, DefaultConstructor) {
  EXPECT_NO_THROW(Force{});
}

TEST(Force, Dimensions) {
  EXPECT_EQ(Force::Dimensions(), RelatedDimensions<Unit::Force>);
}

TEST(Force, Direction) {
  EXPECT_EQ(Force({2.0, -3.0, 6.0}, Unit::Force::Newton).Direction(), Direction(2.0, -3.0, 6.0));
}

TEST(Force, Hash) {
  const Force first({1.0, -2.0, 3.0}, Unit::Force::Pound);
  const Force second({1.0, -2.0, 3.000001}, Unit::Force::Pound);
  const Force third({1.0, 2.0, 3.0}, Unit::Force::Pound);
  const std::hash<Force> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Force, JSON) {
  EXPECT_EQ(Force({1.0, -2.0, 3.0}, Unit::Force::Newton).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"N\"}");
  EXPECT_EQ(Force({0.0, -2.0, 0.0}, Unit::Force::Pound).JSON(Unit::Force::Pound),
            "{\"value\":{\"x\":0,\"y\":" + Print(-2.0) + ",\"z\":0},\"unit\":\"lbf\"}");
}

TEST(Force, Magnitude) {
  EXPECT_EQ(Force({2.0, -3.0, 6.0}, Unit::Force::Newton).Magnitude(),
            ScalarForce(7.0, Unit::Force::Newton));
}

TEST(Force, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(Force({1.0, -2.0, 3.0}, Unit::Force::Newton)), Direction(1.0, -2.0, 3.0));

  EXPECT_EQ(Angle(Force({0.0, -2.0, 0.0}, Unit::Force::Newton),
                  Force({0.0, 0.0, 3.0}, Unit::Force::Newton)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Force, MoveAssignmentOperator) {
  Force first({1.0, -2.0, 3.0}, Unit::Force::Newton);
  Force second = Force::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Force({1.0, -2.0, 3.0}, Unit::Force::Newton));
}

TEST(Force, MoveConstructor) {
  Force first({1.0, -2.0, 3.0}, Unit::Force::Newton);
  const Force second{std::move(first)};
  EXPECT_EQ(second, Force({1.0, -2.0, 3.0}, Unit::Force::Newton));
}

TEST(Force, MutableValue) {
  Force force({1.0, -2.0, 3.0}, Unit::Force::Newton);
  Vector& value = force.MutableValue();
  value = Vector{-4.0, 5.0, -6.0};
  EXPECT_EQ(force.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(Force, Print) {
  EXPECT_EQ(Force({1.0, -2.0, 3.0}, Unit::Force::Newton).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") N");
  EXPECT_EQ(Force({0.0, -2.0, 0.0}, Unit::Force::Pound).Print(Unit::Force::Pound),
            "(" + Print(0.0) + ", " + Print(-2.0) + ", " + Print(0.0) + ") lbf");
}

TEST(Force, SetValue) {
  Force force({1.0, -2.0, 3.0}, Unit::Force::Newton);
  force.SetValue({-4.0, 5.0, -6.0});
  EXPECT_EQ(force.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(Force, SizeOf) {
  EXPECT_EQ(sizeof(Force{}), 3 * sizeof(double));
}

TEST(Force, StandardConstructor) {
  EXPECT_NO_THROW(Force({1.0, -2.0, 3.0}, Unit::Force::Pound));
}

TEST(Force, StaticValue) {
  constexpr Force force = Force::Create<Unit::Force::Pound>(1.0, -2.0, 3.0);
  constexpr Vector value = force.StaticValue<Unit::Force::Pound>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(Force, Stream) {
  std::ostringstream stream;
  stream << Force({1.0, -2.0, 3.0}, Unit::Force::Newton);
  EXPECT_EQ(stream.str(), Force({1.0, -2.0, 3.0}, Unit::Force::Newton).Print());
}

TEST(Force, Unit) {
  EXPECT_EQ(Force::Unit(), Standard<Unit::Force>);
}

TEST(Force, Value) {
  EXPECT_EQ(Force({1.0, -2.0, 3.0}, Unit::Force::Newton).Value(), Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(Force({1.0, -2.0, 3.0}, Unit::Force::Pound).Value(Unit::Force::Pound),
            Vector(1.0, -2.0, 3.0));
}

TEST(Force, XML) {
  EXPECT_EQ(Force({1.0, -2.0, 3.0}, Unit::Force::Newton).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>N</unit>");
  EXPECT_EQ(Force({0.0, -2.0, 0.0}, Unit::Force::Pound).XML(Unit::Force::Pound),
            "<value><x>0</x><y>" + Print(-2.0) + "</y><z>0</z></value><unit>lbf</unit>");
}

TEST(Force, XYZ) {
  EXPECT_EQ(
      Force({1.0, -2.0, 3.0}, Unit::Force::Newton).x(), ScalarForce(1.0, Unit::Force::Newton));
  EXPECT_EQ(
      Force({1.0, -2.0, 3.0}, Unit::Force::Newton).y(), ScalarForce(-2.0, Unit::Force::Newton));
  EXPECT_EQ(
      Force({1.0, -2.0, 3.0}, Unit::Force::Newton).z(), ScalarForce(3.0, Unit::Force::Newton));
}

TEST(Force, YAML) {
  EXPECT_EQ(Force({1.0, -2.0, 3.0}, Unit::Force::Newton).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"N\"}");
  EXPECT_EQ(Force({0.0, -2.0, 0.0}, Unit::Force::Pound).YAML(Unit::Force::Pound),
            "{value:{x:0,y:" + Print(-2.0) + ",z:0},unit:\"lbf\"}");
}

TEST(Force, Zero) {
  EXPECT_EQ(Force::Zero(), Force({0.0, 0.0, 0.0}, Unit::Force::Newton));
}

}  // namespace

}  // namespace PhQ
