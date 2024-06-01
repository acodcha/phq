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

#include "../include/PhQ/PlanarDisplacement.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/PlanarDirection.hpp"
#include "../include/PhQ/PlanarVector.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Length.hpp"

namespace PhQ {

namespace {

TEST(PlanarDisplacement, Angle) {
  EXPECT_EQ(PlanarDisplacement({0.0, -2.0}, Unit::Length::Metre)
                .Angle(PlanarDisplacement({3.0, 0.0}, Unit::Length::Metre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarDisplacement, ArithmeticOperatorAddition) {
  EXPECT_EQ(PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre)
                + PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre),
            PlanarDisplacement({3.0, -6.0}, Unit::Length::Metre));
}

TEST(PlanarDisplacement, ArithmeticOperatorDivision) {
  EXPECT_EQ(PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre) / 2.0,
            PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarDisplacement, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre) * 2.0,
            PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre));

  EXPECT_EQ(2.0 * PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre),
            PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre));
}

TEST(PlanarDisplacement, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PlanarDisplacement({3.0, -6.0}, Unit::Length::Metre)
                - PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre),
            PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarDisplacement, AssignmentOperatorAddition) {
  PlanarDisplacement displacement({1.0, -2.0}, Unit::Length::Metre);
  displacement += PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre);
  EXPECT_EQ(displacement, PlanarDisplacement({3.0, -6.0}, Unit::Length::Metre));
}

TEST(PlanarDisplacement, AssignmentOperatorDivision) {
  PlanarDisplacement displacement({2.0, -4.0}, Unit::Length::Metre);
  displacement /= 2.0;
  EXPECT_EQ(displacement, PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarDisplacement, AssignmentOperatorMultiplication) {
  PlanarDisplacement displacement({1.0, -2.0}, Unit::Length::Metre);
  displacement *= 2.0;
  EXPECT_EQ(displacement, PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre));
}

TEST(PlanarDisplacement, AssignmentOperatorSubtraction) {
  PlanarDisplacement displacement({3.0, -6.0}, Unit::Length::Metre);
  displacement -= PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre);
  EXPECT_EQ(displacement, PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarDisplacement, ComparisonOperators) {
  const PlanarDisplacement first({1.0, -2.000001}, Unit::Length::Metre);
  const PlanarDisplacement second({1.0, -2.0}, Unit::Length::Metre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PlanarDisplacement, Constructor) {
  EXPECT_NO_THROW(PlanarDisplacement({1.0, -2.0}, Unit::Length::Millimetre));
  EXPECT_EQ(PlanarDisplacement(Length(1.0, Unit::Length::Metre), Length(-2.0, Unit::Length::Metre)),
            PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
  EXPECT_EQ(PlanarDirection(PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre)),
            PlanarDirection(1.0, -2.0));
  EXPECT_EQ(Angle(PlanarDisplacement({0.0, -2.0}, Unit::Length::Metre),
                  PlanarDisplacement({3.0, 0.0}, Unit::Length::Metre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarDisplacement, CopyAssignmentOperator) {
  {
    const PlanarDisplacement<float> first({1.0F, -2.0F}, Unit::Length::Metre);
    PlanarDisplacement<double> second = PlanarDisplacement<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarDisplacement<double>({1.0, -2.0}, Unit::Length::Metre));
  }
  {
    const PlanarDisplacement<double> first({1.0, -2.0}, Unit::Length::Metre);
    PlanarDisplacement<double> second = PlanarDisplacement<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarDisplacement<double>({1.0, -2.0}, Unit::Length::Metre));
  }
  {
    const PlanarDisplacement<long double> first({1.0L, -2.0L}, Unit::Length::Metre);
    PlanarDisplacement<double> second = PlanarDisplacement<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarDisplacement<double>({1.0, -2.0}, Unit::Length::Metre));
  }
}

TEST(PlanarDisplacement, CopyConstructor) {
  {
    const PlanarDisplacement<float> first({1.0F, -2.0F}, Unit::Length::Metre);
    const PlanarDisplacement<double> second{first};
    EXPECT_EQ(second, PlanarDisplacement<double>({1.0, -2.0}, Unit::Length::Metre));
  }
  {
    const PlanarDisplacement<double> first({1.0, -2.0}, Unit::Length::Metre);
    const PlanarDisplacement<double> second{first};
    EXPECT_EQ(second, PlanarDisplacement<double>({1.0, -2.0}, Unit::Length::Metre));
  }
  {
    const PlanarDisplacement<long double> first({1.0L, -2.0L}, Unit::Length::Metre);
    const PlanarDisplacement<double> second{first};
    EXPECT_EQ(second, PlanarDisplacement<double>({1.0, -2.0}, Unit::Length::Metre));
  }
}

TEST(PlanarDisplacement, Create) {
  {
    constexpr PlanarDisplacement displacement =
        PlanarDisplacement<>::Create<Unit::Length::Metre>(1.0, -2.0);
    EXPECT_EQ(displacement, PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
  }
  {
    constexpr PlanarDisplacement displacement =
        PlanarDisplacement<>::Create<Unit::Length::Metre>(std::array<double, 2>{1.0, -2.0});
    EXPECT_EQ(displacement, PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
  }
  {
    constexpr PlanarDisplacement displacement =
        PlanarDisplacement<>::Create<Unit::Length::Metre>(PlanarVector{1.0, -2.0});
    EXPECT_EQ(displacement, PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
  }
}

TEST(PlanarDisplacement, DefaultConstructor) {
  EXPECT_NO_THROW(PlanarDisplacement<>{});
}

TEST(PlanarDisplacement, Dimensions) {
  EXPECT_EQ(PlanarDisplacement<>::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(PlanarDisplacement, Hash) {
  const PlanarDisplacement first({1.0, -2.000001}, Unit::Length::Millimetre);
  const PlanarDisplacement second({1.0, -2.0}, Unit::Length::Millimetre);
  const PlanarDisplacement third({1.0, 2.0}, Unit::Length::Millimetre);
  const std::hash<PlanarDisplacement<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PlanarDisplacement, JSON) {
  EXPECT_EQ(PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"m\"}");
  EXPECT_EQ(
      PlanarDisplacement({0.0, -2.0}, Unit::Length::Millimetre).JSON(Unit::Length::Millimetre),
      "{\"value\":{\"x\":" + Print(0.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"mm\"}");
}

TEST(PlanarDisplacement, Magnitude) {
  EXPECT_EQ(PlanarDisplacement({3.0, -4.0}, Unit::Length::Metre).Magnitude(),
            Length(5.0, Unit::Length::Metre));
}

TEST(PlanarDisplacement, MoveAssignmentOperator) {
  PlanarDisplacement first({1.0, -2.0}, Unit::Length::Metre);
  PlanarDisplacement second = PlanarDisplacement<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarDisplacement, MoveConstructor) {
  PlanarDisplacement first({1.0, -2.0}, Unit::Length::Metre);
  const PlanarDisplacement second{std::move(first)};
  EXPECT_EQ(second, PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarDisplacement, MutableValue) {
  PlanarDisplacement displacement({1.0, -2.0}, Unit::Length::Metre);
  PlanarVector<>& value = displacement.MutableValue();
  value = PlanarVector{-4.0, 5.0};
  EXPECT_EQ(displacement.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarDisplacement, PlanarDirection) {
  EXPECT_EQ(PlanarDisplacement({3.0, -4.0}, Unit::Length::Metre).PlanarDirection(),
            PlanarDirection(3.0, -4.0));
}

TEST(PlanarDisplacement, Print) {
  EXPECT_EQ(PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") m");
  EXPECT_EQ(
      PlanarDisplacement({0.0, -2.0}, Unit::Length::Millimetre).Print(Unit::Length::Millimetre),
      "(" + Print(0.0) + ", " + Print(-2.0) + ") mm");
}

TEST(PlanarDisplacement, SetValue) {
  PlanarDisplacement displacement({1.0, -2.0}, Unit::Length::Metre);
  displacement.SetValue({-4.0, 5.0});
  EXPECT_EQ(displacement.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarDisplacement, SizeOf) {
  EXPECT_EQ(sizeof(PlanarDisplacement<>{}), 2 * sizeof(double));
}

TEST(PlanarDisplacement, StaticValue) {
  constexpr PlanarDisplacement displacement =
      PlanarDisplacement<>::Create<Unit::Length::Millimetre>(1.0, -2.0);
  constexpr PlanarVector value = displacement.StaticValue<Unit::Length::Millimetre>();
  EXPECT_EQ(value, PlanarVector(1.0, -2.0));
}

TEST(PlanarDisplacement, Stream) {
  std::ostringstream stream;
  stream << PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre);
  EXPECT_EQ(stream.str(), PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre).Print());
}

TEST(PlanarDisplacement, Unit) {
  EXPECT_EQ(PlanarDisplacement<>::Unit(), Standard<Unit::Length>);
}

TEST(PlanarDisplacement, Value) {
  EXPECT_EQ(PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre).Value(), PlanarVector(1.0, -2.0));
  EXPECT_EQ(
      PlanarDisplacement({1.0, -2.0}, Unit::Length::Millimetre).Value(Unit::Length::Millimetre),
      PlanarVector(1.0, -2.0));
}

TEST(PlanarDisplacement, XML) {
  EXPECT_EQ(PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>m</unit>");
  EXPECT_EQ(PlanarDisplacement({0.0, -2.0}, Unit::Length::Millimetre).XML(Unit::Length::Millimetre),
            "<value><x>" + Print(0.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>mm</unit>");
}

TEST(PlanarDisplacement, XY) {
  EXPECT_EQ(
      PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre).x(), Length(1.0, Unit::Length::Metre));
  EXPECT_EQ(
      PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre).y(), Length(-2.0, Unit::Length::Metre));
}

TEST(PlanarDisplacement, YAML) {
  EXPECT_EQ(PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"m\"}");
  EXPECT_EQ(
      PlanarDisplacement({0.0, -2.0}, Unit::Length::Millimetre).YAML(Unit::Length::Millimetre),
      "{value:{x:0,y:" + Print(-2.0) + "},unit:\"mm\"}");
}

TEST(PlanarDisplacement, Zero) {
  EXPECT_EQ(PlanarDisplacement<>::Zero(), PlanarDisplacement({0.0, 0.0}, Unit::Length::Metre));
}

}  // namespace

}  // namespace PhQ
