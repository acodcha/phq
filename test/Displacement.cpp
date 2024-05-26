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

#include "../include/PhQ/Displacement.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Direction.hpp"
#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/PlanarDisplacement.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(Displacement, Angle) {
  EXPECT_EQ(Displacement({0.0, -2.0, 0.0}, Unit::Length::Metre)
                .Angle(Displacement({0.0, 0.0, 3.0}, Unit::Length::Metre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Displacement, ArithmeticOperatorAddition) {
  EXPECT_EQ(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre)
                + Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre),
            Displacement({3.0, -6.0, 9.0}, Unit::Length::Metre));
}

TEST(Displacement, ArithmeticOperatorDivision) {
  EXPECT_EQ(Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre) / 2.0,
            Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Displacement, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre) * 2.0,
            Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));

  EXPECT_EQ(2.0 * Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre),
            Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));
}

TEST(Displacement, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Displacement({3.0, -6.0, 9.0}, Unit::Length::Metre)
                - Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre),
            Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Displacement, AssignmentOperatorAddition) {
  Displacement displacement({1.0, -2.0, 3.0}, Unit::Length::Metre);
  displacement += Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre);
  EXPECT_EQ(displacement, Displacement({3.0, -6.0, 9.0}, Unit::Length::Metre));
}

TEST(Displacement, AssignmentOperatorDivision) {
  Displacement displacement({2.0, -4.0, 6.0}, Unit::Length::Metre);
  displacement /= 2.0;
  EXPECT_EQ(displacement, Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Displacement, AssignmentOperatorMultiplication) {
  Displacement displacement({1.0, -2.0, 3.0}, Unit::Length::Metre);
  displacement *= 2.0;
  EXPECT_EQ(displacement, Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));
}

TEST(Displacement, AssignmentOperatorSubtraction) {
  Displacement displacement({3.0, -6.0, 9.0}, Unit::Length::Metre);
  displacement -= Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre);
  EXPECT_EQ(displacement, Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Displacement, ComparisonOperators) {
  const Displacement first({1.0, -2.0, 3.0}, Unit::Length::Metre);
  const Displacement second({1.0, -2.0, 3.000001}, Unit::Length::Metre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Displacement, CopyAssignmentOperator) {
  {
    const Displacement<float> first({1.0F, -2.0F, 3.0F}, Unit::Length::Metre);
    Displacement<double> second = Displacement<double>::Zero();
    second = first;
    EXPECT_EQ(second, Displacement<double>({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
  {
    const Displacement<double> first({1.0, -2.0, 3.0}, Unit::Length::Metre);
    Displacement<double> second = Displacement<double>::Zero();
    second = first;
    EXPECT_EQ(second, Displacement<double>({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
  {
    const Displacement<long double> first({1.0L, -2.0L, 3.0L}, Unit::Length::Metre);
    Displacement<double> second = Displacement<double>::Zero();
    second = first;
    EXPECT_EQ(second, Displacement<double>({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
}

TEST(Displacement, CopyConstructor) {
  {
    const Displacement<float> first({1.0F, -2.0F, 3.0F}, Unit::Length::Metre);
    const Displacement<double> second{first};
    EXPECT_EQ(second, Displacement<double>({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
  {
    const Displacement<double> first({1.0, -2.0, 3.0}, Unit::Length::Metre);
    const Displacement<double> second{first};
    EXPECT_EQ(second, Displacement<double>({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
  {
    const Displacement<long double> first({1.0L, -2.0L, 3.0L}, Unit::Length::Metre);
    const Displacement<double> second{first};
    EXPECT_EQ(second, Displacement<double>({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
}

TEST(Displacement, Create) {
  {
    constexpr Displacement displacement =
        Displacement<>::Create<Unit::Length::Metre>(1.0, -2.0, 3.0);
    EXPECT_EQ(displacement, Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
  {
    constexpr Displacement displacement =
        Displacement<>::Create<Unit::Length::Metre>(std::array<double, 3>{1.0, -2.0, 3.0});
    EXPECT_EQ(displacement, Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
  {
    constexpr Displacement displacement =
        Displacement<>::Create<Unit::Length::Metre>(Vector{1.0, -2.0, 3.0});
    EXPECT_EQ(displacement, Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
}

TEST(Displacement, DefaultConstructor) {
  EXPECT_NO_THROW(Displacement<>{});
}

TEST(Displacement, Dimensions) {
  EXPECT_EQ(Displacement<>::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(Displacement, Direction) {
  EXPECT_EQ(
      Displacement({2.0, -3.0, 6.0}, Unit::Length::Metre).Direction(), Direction(2.0, -3.0, 6.0));
}

TEST(Displacement, Hash) {
  const Displacement first({1.0, -2.0, 3.0}, Unit::Length::Millimetre);
  const Displacement second({1.0, -2.0, 3.000001}, Unit::Length::Millimetre);
  const Displacement third({1.0, 2.0, 3.0}, Unit::Length::Millimetre);
  const std::hash<Displacement<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Displacement, JSON) {
  EXPECT_EQ(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"m\"}");
  EXPECT_EQ(Displacement({0.0, -2.0, 0.0}, Unit::Length::Millimetre).JSON(Unit::Length::Millimetre),
            "{\"value\":{\"x\":" + Print(0.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(0.0)
                + "},\"unit\":\"mm\"}");
}

TEST(Displacement, Magnitude) {
  EXPECT_EQ(Displacement({2.0, -3.0, 6.0}, Unit::Length::Metre).Magnitude(),
            Length(7.0, Unit::Length::Metre));
}

TEST(Displacement, MiscellaneousConstructors) {
  EXPECT_EQ(
      Direction(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre)), Direction(1.0, -2.0, 3.0));
  EXPECT_EQ(Angle(Displacement({0.0, -2.0, 0.0}, Unit::Length::Metre),
                  Displacement({0.0, 0.0, 3.0}, Unit::Length::Metre)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(PlanarDisplacement(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre)),
            PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
  EXPECT_EQ(Displacement(PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre)),
            Displacement({1.0, -2.0, 0.0}, Unit::Length::Metre));
}

TEST(Displacement, MoveAssignmentOperator) {
  Displacement first({1.0, -2.0, 3.0}, Unit::Length::Metre);
  Displacement second = Displacement<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Displacement, MoveConstructor) {
  Displacement first({1.0, -2.0, 3.0}, Unit::Length::Metre);
  const Displacement second{std::move(first)};
  EXPECT_EQ(second, Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Displacement, MutableValue) {
  Displacement displacement({1.0, -2.0, 3.0}, Unit::Length::Metre);
  Vector<>& value = displacement.MutableValue();
  value = Vector{-4.0, 5.0, -6.0};
  EXPECT_EQ(displacement.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(Displacement, Print) {
  EXPECT_EQ(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") m");
  EXPECT_EQ(
      Displacement({0.0, -2.0, 0.0}, Unit::Length::Millimetre).Print(Unit::Length::Millimetre),
      "(" + Print(0.0) + ", " + Print(-2.0) + ", " + Print(0.0) + ") mm");
}

TEST(Displacement, SetValue) {
  Displacement displacement({1.0, -2.0, 3.0}, Unit::Length::Metre);
  displacement.SetValue({-4.0, 5.0, -6.0});
  EXPECT_EQ(displacement.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(Displacement, SizeOf) {
  EXPECT_EQ(sizeof(Displacement<>{}), 3 * sizeof(double));
}

TEST(Displacement, StandardConstructor) {
  EXPECT_NO_THROW(Displacement({1.0, -2.0, 3.0}, Unit::Length::Millimetre));
}

TEST(Displacement, StaticValue) {
  constexpr Displacement displacement =
      Displacement<>::Create<Unit::Length::Millimetre>(1.0, -2.0, 3.0);
  constexpr Vector value = displacement.StaticValue<Unit::Length::Millimetre>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(Displacement, Stream) {
  std::ostringstream stream;
  stream << Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre);
  EXPECT_EQ(stream.str(), Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre).Print());
}

TEST(Displacement, Unit) {
  EXPECT_EQ(Displacement<>::Unit(), Standard<Unit::Length>);
}

TEST(Displacement, Value) {
  EXPECT_EQ(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre).Value(), Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(
      Displacement({1.0, -2.0, 3.0}, Unit::Length::Millimetre).Value(Unit::Length::Millimetre),
      Vector(1.0, -2.0, 3.0));
}

TEST(Displacement, XML) {
  EXPECT_EQ(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>m</unit>");
  EXPECT_EQ(Displacement({0.0, -2.0, 0.0}, Unit::Length::Millimetre).XML(Unit::Length::Millimetre),
            "<value><x>" + Print(0.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(0.0)
                + "</z></value><unit>mm</unit>");
}

TEST(Displacement, XYZ) {
  EXPECT_EQ(
      Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre).x(), Length(1.0, Unit::Length::Metre));
  EXPECT_EQ(
      Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre).y(), Length(-2.0, Unit::Length::Metre));
  EXPECT_EQ(
      Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre).z(), Length(3.0, Unit::Length::Metre));
}

TEST(Displacement, YAML) {
  EXPECT_EQ(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"m\"}");
  EXPECT_EQ(Displacement({0.0, -2.0, 0.0}, Unit::Length::Millimetre).YAML(Unit::Length::Millimetre),
            "{value:{x:0,y:" + Print(-2.0) + ",z:0},unit:\"mm\"}");
}

TEST(Displacement, Zero) {
  EXPECT_EQ(Displacement<>::Zero(), Displacement({0.0, 0.0, 0.0}, Unit::Length::Metre));
}

}  // namespace

}  // namespace PhQ
