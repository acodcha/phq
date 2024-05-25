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

#include "../include/PhQ/PlanarAcceleration.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/PlanarDirection.hpp"
#include "../include/PhQ/PlanarVector.hpp"
#include "../include/PhQ/PlanarVelocity.hpp"
#include "../include/PhQ/ScalarAcceleration.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Acceleration.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Speed.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(PlanarAcceleration, Angle) {
  EXPECT_EQ(PlanarAcceleration({0.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond)
                .Angle(PlanarAcceleration({3.0, 0.0}, Unit::Acceleration::MetrePerSquareSecond)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarAcceleration, ArithmeticOperatorAddition) {
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond)
                + PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond),
            PlanarAcceleration({3.0, -6.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, ArithmeticOperatorDivision) {
  EXPECT_EQ(PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond) / 2.0,
            PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(
      PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond) / Time(2.0, Unit::Time::Second),
      PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond) * 2.0,
            PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(2.0 * PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond),
            PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(PlanarDirection(3.0, -4.0)
                * ScalarAcceleration(5.0, Unit::Acceleration::MetrePerSquareSecond),
            PlanarAcceleration({3.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(ScalarAcceleration(5.0, Unit::Acceleration::MetrePerSquareSecond)
                * PlanarDirection(3.0, -4.0),
            PlanarAcceleration({3.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond)
                * Time(2.0, Unit::Time::Second),
            PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Time(2.0, Unit::Time::Second)
                * PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond),
            PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond)
                * Frequency(2.0, Unit::Frequency::Hertz),
            PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(Frequency(2.0, Unit::Frequency::Hertz)
                * PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond),
            PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PlanarAcceleration({3.0, -6.0}, Unit::Acceleration::MetrePerSquareSecond)
                - PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond),
            PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, AssignmentOperatorAddition) {
  PlanarAcceleration acceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond);
  acceleration += PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(
      acceleration, PlanarAcceleration({3.0, -6.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, AssignmentOperatorDivision) {
  PlanarAcceleration acceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond);
  acceleration /= 2.0;
  EXPECT_EQ(
      acceleration, PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, AssignmentOperatorMultiplication) {
  PlanarAcceleration acceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond);
  acceleration *= 2.0;
  EXPECT_EQ(
      acceleration, PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, AssignmentOperatorSubtraction) {
  PlanarAcceleration acceleration({3.0, -6.0}, Unit::Acceleration::MetrePerSquareSecond);
  acceleration -= PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(
      acceleration, PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, ComparisonOperators) {
  const PlanarAcceleration first({1.0, -2.0000010}, Unit::Acceleration::MetrePerSquareSecond);
  const PlanarAcceleration second({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PlanarAcceleration, CopyAssignmentOperator) {
  const PlanarAcceleration first({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond);
  PlanarAcceleration second = PlanarAcceleration<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(PlanarAcceleration, CopyConstructor) {
  const PlanarAcceleration first({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond);
  const PlanarAcceleration second{first};
  EXPECT_EQ(second, first);
}

TEST(PlanarAcceleration, Create) {
  {
    constexpr PlanarAcceleration acceleration =
        PlanarAcceleration<>::Create<Unit::Acceleration::MetrePerSquareSecond>(1.0, -2.0);
    EXPECT_EQ(
        acceleration, PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond));
  }
  {
    constexpr PlanarAcceleration acceleration =
        PlanarAcceleration<>::Create<Unit::Acceleration::MetrePerSquareSecond>(
            std::array<double, 2>{1.0, -2.0});
    EXPECT_EQ(
        acceleration, PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond));
  }
  {
    constexpr PlanarAcceleration acceleration =
        PlanarAcceleration<>::Create<Unit::Acceleration::MetrePerSquareSecond>(
            PlanarVector{1.0, -2.0});
    EXPECT_EQ(
        acceleration, PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond));
  }
}

TEST(PlanarAcceleration, DefaultConstructor) {
  EXPECT_NO_THROW(PlanarAcceleration<>{});
}

TEST(PlanarAcceleration, Dimensions) {
  EXPECT_EQ(PlanarAcceleration<>::Dimensions(), RelatedDimensions<Unit::Acceleration>);
}

TEST(PlanarAcceleration, Hash) {
  const PlanarAcceleration first({1.0, -2.000001}, Unit::Acceleration::MillimetrePerSquareSecond);
  const PlanarAcceleration second({1.0, -2.0}, Unit::Acceleration::MillimetrePerSquareSecond);
  const PlanarAcceleration third({1.0, 2.0}, Unit::Acceleration::MillimetrePerSquareSecond);
  const std::hash<PlanarAcceleration<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PlanarAcceleration, JSON) {
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"m/s^2\"}");
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MillimetrePerSquareSecond)
                .JSON(Unit::Acceleration::MillimetrePerSquareSecond),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"mm/s^2\"}");
}

TEST(PlanarAcceleration, Magnitude) {
  EXPECT_EQ(PlanarAcceleration({3.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond).Magnitude(),
            ScalarAcceleration(5.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, MiscellaneousConstructors) {
  EXPECT_EQ(
      PlanarDirection(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond)),
      PlanarDirection(1.0, -2.0));

  EXPECT_EQ(Angle(PlanarAcceleration({0.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond),
                  PlanarAcceleration({3.0, 0.0}, Unit::Acceleration::MetrePerSquareSecond)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(
      PlanarVelocity(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond),
                     Time(2.0, Unit::Time::Second)),
      PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(
      PlanarVelocity(PlanarAcceleration({2.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond),
                     Frequency(2.0, Unit::Frequency::Hertz)),
      PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond));
}

TEST(PlanarAcceleration, MoveAssignmentOperator) {
  PlanarAcceleration first({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond);
  PlanarAcceleration second = PlanarAcceleration<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, MoveConstructor) {
  PlanarAcceleration first({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond);
  const PlanarAcceleration second{std::move(first)};
  EXPECT_EQ(second, PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, MutableValue) {
  PlanarAcceleration acceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond);
  PlanarVector<>& value = acceleration.MutableValue();
  value = PlanarVector{-4.0, 5.0};
  EXPECT_EQ(acceleration.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarAcceleration, PlanarDirection) {
  EXPECT_EQ(
      PlanarAcceleration({3.0, -4.0}, Unit::Acceleration::MetrePerSquareSecond).PlanarDirection(),
      PlanarDirection(3.0, -4.0));
}

TEST(PlanarAcceleration, Print) {
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") m/s^2");
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MillimetrePerSquareSecond)
                .Print(Unit::Acceleration::MillimetrePerSquareSecond),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") mm/s^2");
}

TEST(PlanarAcceleration, SetValue) {
  PlanarAcceleration acceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond);
  acceleration.SetValue({-4.0, 5.0});
  EXPECT_EQ(acceleration.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarAcceleration, SizeOf) {
  EXPECT_EQ(sizeof(PlanarAcceleration<>{}), 2 * sizeof(double));
}

TEST(PlanarAcceleration, StandardConstructor) {
  EXPECT_NO_THROW(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MillimetrePerSquareSecond));
}

TEST(PlanarAcceleration, StaticValue) {
  constexpr PlanarAcceleration acceleration =
      PlanarAcceleration<>::Create<Unit::Acceleration::MillimetrePerSquareSecond>(1.0, -2.0);
  constexpr PlanarVector value =
      acceleration.StaticValue<Unit::Acceleration::MillimetrePerSquareSecond>();
  EXPECT_EQ(value, PlanarVector(1.0, -2.0));
}

TEST(PlanarAcceleration, Stream) {
  std::ostringstream stream;
  stream << PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MillimetrePerSquareSecond);
  EXPECT_EQ(stream.str(),
            PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MillimetrePerSquareSecond).Print());
}

TEST(PlanarAcceleration, Unit) {
  EXPECT_EQ(PlanarAcceleration<>::Unit(), Standard<Unit::Acceleration>);
}

TEST(PlanarAcceleration, Value) {
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond).Value(),
            PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MillimetrePerSquareSecond)
                .Value(Unit::Acceleration::MillimetrePerSquareSecond),
            PlanarVector(1.0, -2.0));
}

TEST(PlanarAcceleration, XML) {
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>m/s^2</unit>");
  EXPECT_EQ(
      PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MillimetrePerSquareSecond)
          .XML(Unit::Acceleration::MillimetrePerSquareSecond),
      "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>mm/s^2</unit>");
}

TEST(PlanarAcceleration, XY) {
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond).x(),
            ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond).y(),
            ScalarAcceleration(-2.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(PlanarAcceleration, YAML) {
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MetrePerSquareSecond).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"m/s^2\"}");
  EXPECT_EQ(PlanarAcceleration({1.0, -2.0}, Unit::Acceleration::MillimetrePerSquareSecond)
                .YAML(Unit::Acceleration::MillimetrePerSquareSecond),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"mm/s^2\"}");
}

TEST(PlanarAcceleration, Zero) {
  EXPECT_EQ(PlanarAcceleration<>::Zero(),
            PlanarAcceleration({0.0, 0.0}, Unit::Acceleration::MetrePerSquareSecond));
}

}  // namespace

}  // namespace PhQ
