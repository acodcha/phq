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

#include "../include/PhQ/PlanarForce.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/PlanarDirection.hpp"
#include "../include/PhQ/PlanarVector.hpp"
#include "../include/PhQ/ScalarForce.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Force.hpp"

namespace PhQ {

namespace {

TEST(PlanarForce, Angle) {
  EXPECT_EQ(PlanarForce({0.0, -2.0}, Unit::Force::Newton)
                .Angle(PlanarForce({3.0, 0.0}, Unit::Force::Newton)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarForce, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      PlanarForce({1.0, -2.0}, Unit::Force::Newton) + PlanarForce({2.0, -4.0}, Unit::Force::Newton),
      PlanarForce({3.0, -6.0}, Unit::Force::Newton));
}

TEST(PlanarForce, ArithmeticOperatorDivision) {
  EXPECT_EQ(PlanarForce({2.0, -4.0}, Unit::Force::Newton) / 2.0,
            PlanarForce({1.0, -2.0}, Unit::Force::Newton));
}

TEST(PlanarForce, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PlanarForce({1.0, -2.0}, Unit::Force::Newton) * 2.0,
            PlanarForce({2.0, -4.0}, Unit::Force::Newton));
  EXPECT_EQ(2.0 * PlanarForce({1.0, -2.0}, Unit::Force::Newton),
            PlanarForce({2.0, -4.0}, Unit::Force::Newton));
  EXPECT_EQ(PlanarDirection(3.0, -4.0) * ScalarForce(5.0, Unit::Force::Newton),
            PlanarForce({3.0, -4.0}, Unit::Force::Newton));
  EXPECT_EQ(ScalarForce(5.0, Unit::Force::Newton) * PlanarDirection(3.0, -4.0),
            PlanarForce({3.0, -4.0}, Unit::Force::Newton));
}

TEST(PlanarForce, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      PlanarForce({3.0, -6.0}, Unit::Force::Newton) - PlanarForce({2.0, -4.0}, Unit::Force::Newton),
      PlanarForce({1.0, -2.0}, Unit::Force::Newton));
}

TEST(PlanarForce, AssignmentOperatorAddition) {
  PlanarForce force({1.0, -2.0}, Unit::Force::Newton);
  force += PlanarForce({2.0, -4.0}, Unit::Force::Newton);
  EXPECT_EQ(force, PlanarForce({3.0, -6.0}, Unit::Force::Newton));
}

TEST(PlanarForce, AssignmentOperatorDivision) {
  PlanarForce force({2.0, -4.0}, Unit::Force::Newton);
  force /= 2.0;
  EXPECT_EQ(force, PlanarForce({1.0, -2.0}, Unit::Force::Newton));
}

TEST(PlanarForce, AssignmentOperatorMultiplication) {
  PlanarForce force({1.0, -2.0}, Unit::Force::Newton);
  force *= 2.0;
  EXPECT_EQ(force, PlanarForce({2.0, -4.0}, Unit::Force::Newton));
}

TEST(PlanarForce, AssignmentOperatorSubtraction) {
  PlanarForce force({3.0, -6.0}, Unit::Force::Newton);
  force -= PlanarForce({2.0, -4.0}, Unit::Force::Newton);
  EXPECT_EQ(force, PlanarForce({1.0, -2.0}, Unit::Force::Newton));
}

TEST(PlanarForce, ComparisonOperators) {
  const PlanarForce first({1.0, -2.000001}, Unit::Force::Newton);
  const PlanarForce second({1.0, -2.0}, Unit::Force::Newton);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PlanarForce, Constructor) {
  EXPECT_NO_THROW(PlanarForce({1.0, -2.0}, Unit::Force::Pound));
  EXPECT_EQ(
      PlanarForce(ScalarForce(1.0, Unit::Force::Newton), ScalarForce(-2.0, Unit::Force::Newton)),
      PlanarForce({1.0, -2.0}, Unit::Force::Newton));
  EXPECT_EQ(
      PlanarDirection(PlanarForce({1.0, -2.0}, Unit::Force::Newton)), PlanarDirection(1.0, -2.0));
  EXPECT_EQ(Angle(PlanarForce({0.0, -2.0}, Unit::Force::Newton),
                  PlanarForce({3.0, 0.0}, Unit::Force::Newton)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarForce, CopyAssignmentOperator) {
  {
    const PlanarForce<float> first({1.0F, -2.0F}, Unit::Force::Newton);
    PlanarForce<double> second = PlanarForce<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarForce<double>({1.0, -2.0}, Unit::Force::Newton));
  }
  {
    const PlanarForce<double> first({1.0, -2.0}, Unit::Force::Newton);
    PlanarForce<double> second = PlanarForce<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarForce<double>({1.0, -2.0}, Unit::Force::Newton));
  }
  {
    const PlanarForce<long double> first({1.0L, -2.0L}, Unit::Force::Newton);
    PlanarForce<double> second = PlanarForce<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarForce<double>({1.0, -2.0}, Unit::Force::Newton));
  }
}

TEST(PlanarForce, CopyConstructor) {
  {
    const PlanarForce<float> first({1.0F, -2.0F}, Unit::Force::Newton);
    const PlanarForce<double> second{first};
    EXPECT_EQ(second, PlanarForce<double>({1.0, -2.0}, Unit::Force::Newton));
  }
  {
    const PlanarForce<double> first({1.0, -2.0}, Unit::Force::Newton);
    const PlanarForce<double> second{first};
    EXPECT_EQ(second, PlanarForce<double>({1.0, -2.0}, Unit::Force::Newton));
  }
  {
    const PlanarForce<long double> first({1.0L, -2.0L}, Unit::Force::Newton);
    const PlanarForce<double> second{first};
    EXPECT_EQ(second, PlanarForce<double>({1.0, -2.0}, Unit::Force::Newton));
  }
}

TEST(PlanarForce, Create) {
  {
    constexpr PlanarForce force = PlanarForce<>::Create<Unit::Force::Newton>(1.0, -2.0);
    EXPECT_EQ(force, PlanarForce({1.0, -2.0}, Unit::Force::Newton));
  }
  {
    constexpr PlanarForce force =
        PlanarForce<>::Create<Unit::Force::Newton>(std::array<double, 2>{1.0, -2.0});
    EXPECT_EQ(force, PlanarForce({1.0, -2.0}, Unit::Force::Newton));
  }
  {
    constexpr PlanarForce force =
        PlanarForce<>::Create<Unit::Force::Newton>(PlanarVector{1.0, -2.0});
    EXPECT_EQ(force, PlanarForce({1.0, -2.0}, Unit::Force::Newton));
  }
}

TEST(PlanarForce, DefaultConstructor) {
  EXPECT_NO_THROW(PlanarForce<>{});
}

TEST(PlanarForce, Dimensions) {
  EXPECT_EQ(PlanarForce<>::Dimensions(), RelatedDimensions<Unit::Force>);
}

TEST(PlanarForce, Hash) {
  const PlanarForce first({1.0, -2.000001}, Unit::Force::Pound);
  const PlanarForce second({1.0, -2.0}, Unit::Force::Pound);
  const PlanarForce third({1.0, 2.0}, Unit::Force::Pound);
  const std::hash<PlanarForce<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PlanarForce, JSON) {
  EXPECT_EQ(PlanarForce({1.0, -2.0}, Unit::Force::Newton).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"N\"}");
  EXPECT_EQ(PlanarForce({0.0, -2.0}, Unit::Force::Pound).JSON(Unit::Force::Pound),
            "{\"value\":{\"x\":" + Print(0.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"lbf\"}");
}

TEST(PlanarForce, Magnitude) {
  EXPECT_EQ(PlanarForce({3.0, -4.0}, Unit::Force::Newton).Magnitude(),
            ScalarForce(5.0, Unit::Force::Newton));
}

TEST(PlanarForce, MoveAssignmentOperator) {
  PlanarForce first({1.0, -2.0}, Unit::Force::Newton);
  PlanarForce second = PlanarForce<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PlanarForce({1.0, -2.0}, Unit::Force::Newton));
}

TEST(PlanarForce, MoveConstructor) {
  PlanarForce first({1.0, -2.0}, Unit::Force::Newton);
  const PlanarForce second{std::move(first)};
  EXPECT_EQ(second, PlanarForce({1.0, -2.0}, Unit::Force::Newton));
}

TEST(PlanarForce, MutableValue) {
  PlanarForce force({1.0, -2.0}, Unit::Force::Newton);
  PlanarVector<>& value = force.MutableValue();
  value = PlanarVector{-4.0, 5.0};
  EXPECT_EQ(force.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarForce, PlanarDirection) {
  EXPECT_EQ(
      PlanarForce({3.0, -4.0}, Unit::Force::Newton).PlanarDirection(), PlanarDirection(3.0, -4.0));
}

TEST(PlanarForce, Print) {
  EXPECT_EQ(PlanarForce({1.0, -2.0}, Unit::Force::Newton).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") N");
  EXPECT_EQ(PlanarForce({0.0, -2.0}, Unit::Force::Pound).Print(Unit::Force::Pound),
            "(" + Print(0.0) + ", " + Print(-2.0) + ") lbf");
}

TEST(PlanarForce, SetValue) {
  PlanarForce force({1.0, -2.0}, Unit::Force::Newton);
  force.SetValue({-4.0, 5.0});
  EXPECT_EQ(force.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarForce, SizeOf) {
  EXPECT_EQ(sizeof(PlanarForce<>{}), 2 * sizeof(double));
}

TEST(PlanarForce, StaticValue) {
  constexpr PlanarForce force = PlanarForce<>::Create<Unit::Force::Pound>(1.0, -2.0);
  constexpr PlanarVector value = force.StaticValue<Unit::Force::Pound>();
  EXPECT_EQ(value, PlanarVector(1.0, -2.0));
}

TEST(PlanarForce, Stream) {
  std::ostringstream stream;
  stream << PlanarForce({1.0, -2.0}, Unit::Force::Newton);
  EXPECT_EQ(stream.str(), PlanarForce({1.0, -2.0}, Unit::Force::Newton).Print());
}

TEST(PlanarForce, Unit) {
  EXPECT_EQ(PlanarForce<>::Unit(), Standard<Unit::Force>);
}

TEST(PlanarForce, Value) {
  EXPECT_EQ(PlanarForce({1.0, -2.0}, Unit::Force::Newton).Value(), PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarForce({1.0, -2.0}, Unit::Force::Pound).Value(Unit::Force::Pound),
            PlanarVector(1.0, -2.0));
}

TEST(PlanarForce, XML) {
  EXPECT_EQ(PlanarForce({1.0, -2.0}, Unit::Force::Newton).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>N</unit>");
  EXPECT_EQ(PlanarForce({0.0, -2.0}, Unit::Force::Pound).XML(Unit::Force::Pound),
            "<value><x>" + Print(0.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>lbf</unit>");
}

TEST(PlanarForce, XY) {
  EXPECT_EQ(
      PlanarForce({1.0, -2.0}, Unit::Force::Newton).x(), ScalarForce(1.0, Unit::Force::Newton));
  EXPECT_EQ(
      PlanarForce({1.0, -2.0}, Unit::Force::Newton).y(), ScalarForce(-2.0, Unit::Force::Newton));
}

TEST(PlanarForce, YAML) {
  EXPECT_EQ(PlanarForce({1.0, -2.0}, Unit::Force::Newton).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"N\"}");
  EXPECT_EQ(PlanarForce({0.0, -2.0}, Unit::Force::Pound).YAML(Unit::Force::Pound),
            "{value:{x:" + Print(0.0) + ",y:" + Print(-2.0) + "},unit:\"lbf\"}");
}

TEST(PlanarForce, Zero) {
  EXPECT_EQ(PlanarForce<>::Zero(), PlanarForce({0.0, 0.0}, Unit::Force::Newton));
}

}  // namespace

}  // namespace PhQ
