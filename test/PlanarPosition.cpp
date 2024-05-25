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

#include "../include/PhQ/PlanarPosition.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/PlanarDirection.hpp"
#include "../include/PhQ/PlanarDisplacement.hpp"
#include "../include/PhQ/PlanarVector.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Length.hpp"

namespace PhQ {

namespace {

TEST(PlanarPosition, Angle) {
  EXPECT_EQ(PlanarPosition({0.0, -2.0}, Unit::Length::Metre)
                .Angle(PlanarPosition({3.0, 0.0}, Unit::Length::Metre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarPosition, ArithmeticOperatorAddition) {
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Metre)
                + PlanarPosition({2.0, -4.0}, Unit::Length::Metre),
            PlanarPosition({3.0, -6.0}, Unit::Length::Metre));
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Metre)
                + PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre),
            PlanarPosition({3.0, -6.0}, Unit::Length::Metre));
  EXPECT_EQ(PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre)
                + PlanarPosition({2.0, -4.0}, Unit::Length::Metre),
            PlanarPosition({3.0, -6.0}, Unit::Length::Metre));
}

TEST(PlanarPosition, ArithmeticOperatorDivision) {
  EXPECT_EQ(PlanarPosition({2.0, -4.0}, Unit::Length::Metre) / 2.0,
            PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarPosition, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Metre) * 2.0,
            PlanarPosition({2.0, -4.0}, Unit::Length::Metre));
  EXPECT_EQ(2.0 * PlanarPosition({1.0, -2.0}, Unit::Length::Metre),
            PlanarPosition({2.0, -4.0}, Unit::Length::Metre));
  EXPECT_EQ(PlanarDirection(3.0, -4.0) * Length(5.0, Unit::Length::Metre),
            PlanarPosition({3.0, -4.0}, Unit::Length::Metre));
  EXPECT_EQ(Length(5.0, Unit::Length::Metre) * PlanarDirection(3.0, -4.0),
            PlanarPosition({3.0, -4.0}, Unit::Length::Metre));
}

TEST(PlanarPosition, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PlanarPosition({3.0, -6.0}, Unit::Length::Metre)
                - PlanarPosition({2.0, -4.0}, Unit::Length::Metre),
            PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
  EXPECT_EQ(PlanarPosition({3.0, -6.0}, Unit::Length::Metre)
                - PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre),
            PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
  EXPECT_EQ(PlanarDisplacement({3.0, -6.0}, Unit::Length::Metre)
                - PlanarPosition({2.0, -4.0}, Unit::Length::Metre),
            PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarPosition, AssignmentOperatorAddition) {
  {
    PlanarPosition position({1.0, -2.0}, Unit::Length::Metre);
    position += PlanarPosition({2.0, -4.0}, Unit::Length::Metre);
    EXPECT_EQ(position, PlanarPosition({3.0, -6.0}, Unit::Length::Metre));
  }
  {
    PlanarPosition position({1.0, -2.0}, Unit::Length::Metre);
    position += PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre);
    EXPECT_EQ(position, PlanarPosition({3.0, -6.0}, Unit::Length::Metre));
  }
}

TEST(PlanarPosition, AssignmentOperatorDivision) {
  PlanarPosition position({2.0, -4.0}, Unit::Length::Metre);
  position /= 2.0;
  EXPECT_EQ(position, PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarPosition, AssignmentOperatorMultiplication) {
  PlanarPosition position({1.0, -2.0}, Unit::Length::Metre);
  position *= 2.0;
  EXPECT_EQ(position, PlanarPosition({2.0, -4.0}, Unit::Length::Metre));
}

TEST(PlanarPosition, AssignmentOperatorSubtraction) {
  {
    PlanarPosition position({3.0, -6.0}, Unit::Length::Metre);
    position -= PlanarPosition({2.0, -4.0}, Unit::Length::Metre);
    EXPECT_EQ(position, PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
  }
  {
    PlanarPosition position({3.0, -6.0}, Unit::Length::Metre);
    position -= PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre);
    EXPECT_EQ(position, PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
  }
}

TEST(PlanarPosition, ComparisonOperators) {
  const PlanarPosition first({1.0, -2.000001}, Unit::Length::Metre);
  const PlanarPosition second({1.0, -2.0}, Unit::Length::Metre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PlanarPosition, CopyAssignmentOperator) {
  const PlanarPosition first({1.0, -2.0}, Unit::Length::Metre);
  PlanarPosition second = PlanarPosition<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(PlanarPosition, CopyConstructor) {
  const PlanarPosition first({1.0, -2.0}, Unit::Length::Metre);
  const PlanarPosition second{first};
  EXPECT_EQ(second, first);
}

TEST(PlanarPosition, Create) {
  {
    constexpr PlanarPosition position = PlanarPosition<>::Create<Unit::Length::Metre>(1.0, -2.0);
    EXPECT_EQ(position, PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
  }
  {
    constexpr PlanarPosition position =
        PlanarPosition<>::Create<Unit::Length::Metre>(std::array<double, 2>{1.0, -2.0});
    EXPECT_EQ(position, PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
  }
  {
    constexpr PlanarPosition position =
        PlanarPosition<>::Create<Unit::Length::Metre>(PlanarVector{1.0, -2.0});
    EXPECT_EQ(position, PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
  }
}

TEST(PlanarPosition, DefaultConstructor) {
  EXPECT_NO_THROW(PlanarPosition<>{});
}

TEST(PlanarPosition, Dimensions) {
  EXPECT_EQ(PlanarPosition<>::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(PlanarPosition, Hash) {
  const PlanarPosition first({1.0, -2.000001}, Unit::Length::Millimetre);
  const PlanarPosition second({1.0, -2.0}, Unit::Length::Millimetre);
  const PlanarPosition third({1.0, 2.0}, Unit::Length::Millimetre);
  const std::hash<PlanarPosition<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PlanarPosition, JSON) {
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Metre).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"m\"}");
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Millimetre).JSON(Unit::Length::Millimetre),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"mm\"}");
}

TEST(PlanarPosition, Magnitude) {
  EXPECT_EQ(PlanarPosition({3.0, -4.0}, Unit::Length::Metre).Magnitude(),
            Length(5.0, Unit::Length::Metre));
}

TEST(PlanarPosition, MiscellaneousConstructors) {
  EXPECT_EQ(PlanarDirection(PlanarPosition({1.0, -2.0}, Unit::Length::Metre)),
            PlanarDirection(1.0, -2.0));
  EXPECT_EQ(Angle(PlanarPosition({0.0, -2.0}, Unit::Length::Metre),
                  PlanarPosition({3.0, 0.0}, Unit::Length::Metre)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(PlanarDisplacement(PlanarPosition({1.0, -2.0}, Unit::Length::Metre)),
            PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarPosition, MoveAssignmentOperator) {
  PlanarPosition first({1.0, -2.0}, Unit::Length::Metre);
  PlanarPosition second = PlanarPosition<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarPosition, MoveConstructor) {
  PlanarPosition first({1.0, -2.0}, Unit::Length::Metre);
  const PlanarPosition second{std::move(first)};
  EXPECT_EQ(second, PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarPosition, MutableValue) {
  PlanarPosition position({1.0, -2.0}, Unit::Length::Metre);
  PlanarVector<>& value = position.MutableValue();
  value = PlanarVector{-4.0, 5.0};
  EXPECT_EQ(position.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarPosition, PlanarDirection) {
  EXPECT_EQ(PlanarPosition({3.0, -4.0}, Unit::Length::Metre).PlanarDirection(),
            PlanarDirection(3.0, -4.0));
}

TEST(PlanarPosition, Print) {
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Metre).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") m");
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Millimetre).Print(Unit::Length::Millimetre),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") mm");
}

TEST(PlanarPosition, SetValue) {
  PlanarPosition position({1.0, -2.0}, Unit::Length::Metre);
  position.SetValue({-4.0, 5.0});
  EXPECT_EQ(position.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarPosition, SizeOf) {
  EXPECT_EQ(sizeof(PlanarPosition<>{}), 2 * sizeof(double));
}

TEST(PlanarPosition, StandardConstructor) {
  EXPECT_NO_THROW(PlanarPosition({1.0, -2.0}, Unit::Length::Millimetre));
}

TEST(PlanarPosition, StaticValue) {
  constexpr PlanarPosition position = PlanarPosition<>::Create<Unit::Length::Millimetre>(1.0, -2.0);
  constexpr PlanarVector value = position.StaticValue<Unit::Length::Millimetre>();
  EXPECT_EQ(value, PlanarVector(1.0, -2.0));
}

TEST(PlanarPosition, Stream) {
  std::ostringstream stream;
  stream << PlanarPosition({1.0, -2.0}, Unit::Length::Metre);
  EXPECT_EQ(stream.str(), PlanarPosition({1.0, -2.0}, Unit::Length::Metre).Print());
}

TEST(PlanarPosition, Unit) {
  EXPECT_EQ(PlanarPosition<>::Unit(), Standard<Unit::Length>);
}

TEST(PlanarPosition, Value) {
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Metre).Value(), PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Millimetre).Value(Unit::Length::Millimetre),
            PlanarVector(1.0, -2.0));
}

TEST(PlanarPosition, XML) {
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Metre).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>m</unit>");
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Millimetre).XML(Unit::Length::Millimetre),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>mm</unit>");
}

TEST(PlanarPosition, XY) {
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Metre).x(), Length(1.0, Unit::Length::Metre));
  EXPECT_EQ(
      PlanarPosition({1.0, -2.0}, Unit::Length::Metre).y(), Length(-2.0, Unit::Length::Metre));
}

TEST(PlanarPosition, YAML) {
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Metre).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"m\"}");
  EXPECT_EQ(PlanarPosition({1.0, -2.0}, Unit::Length::Millimetre).YAML(Unit::Length::Millimetre),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"mm\"}");
}

TEST(PlanarPosition, Zero) {
  EXPECT_EQ(PlanarPosition<>::Zero(), PlanarPosition({0.0, 0.0}, Unit::Length::Metre));
}

}  // namespace

}  // namespace PhQ
