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

#include "../include/PhQ/PlanarTraction.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Area.hpp"
#include "../include/PhQ/PlanarDirection.hpp"
#include "../include/PhQ/PlanarForce.hpp"
#include "../include/PhQ/PlanarVector.hpp"
#include "../include/PhQ/ScalarTraction.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Area.hpp"
#include "../include/PhQ/Unit/Force.hpp"
#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

TEST(PlanarTraction, Angle) {
  EXPECT_EQ(PlanarTraction({0.0, -2.0}, Unit::Pressure::Pascal)
                .Angle(PlanarTraction({3.0, 0.0}, Unit::Pressure::Pascal)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarTraction, ArithmeticOperatorAddition) {
  EXPECT_EQ(PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal)
                + PlanarTraction({2.0, -4.0}, Unit::Pressure::Pascal),
            PlanarTraction({3.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, ArithmeticOperatorDivision) {
  EXPECT_EQ(PlanarTraction({2.0, -4.0}, Unit::Pressure::Pascal) / 2.0,
            PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(PlanarForce({2.0, -4.0}, Unit::Force::Newton) / Area(2.0, Unit::Area::SquareMetre),
            PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal) * 2.0,
            PlanarTraction({2.0, -4.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(2.0 * PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal),
            PlanarTraction({2.0, -4.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(PlanarDirection(3.0, -4.0) * ScalarTraction(5.0, Unit::Pressure::Pascal),
            PlanarTraction({3.0, -4.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(ScalarTraction(5.0, Unit::Pressure::Pascal) * PlanarDirection(3.0, -4.0),
            PlanarTraction({3.0, -4.0}, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PlanarTraction({3.0, -6.0}, Unit::Pressure::Pascal)
                - PlanarTraction({2.0, -4.0}, Unit::Pressure::Pascal),
            PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, AssignmentOperatorAddition) {
  PlanarTraction traction({1.0, -2.0}, Unit::Pressure::Pascal);
  traction += PlanarTraction({2.0, -4.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(traction, PlanarTraction({3.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, AssignmentOperatorDivision) {
  PlanarTraction traction({2.0, -4.0}, Unit::Pressure::Pascal);
  traction /= 2.0;
  EXPECT_EQ(traction, PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, AssignmentOperatorMultiplication) {
  PlanarTraction traction({1.0, -2.0}, Unit::Pressure::Pascal);
  traction *= 2.0;
  EXPECT_EQ(traction, PlanarTraction({2.0, -4.0}, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, AssignmentOperatorSubtraction) {
  PlanarTraction traction({3.0, -6.0}, Unit::Pressure::Pascal);
  traction -= PlanarTraction({2.0, -4.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(traction, PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, ComparisonOperators) {
  const PlanarTraction first({1.0, -2.000001}, Unit::Pressure::Pascal);
  const PlanarTraction second({1.0, -2.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PlanarTraction, Constructor) {
  EXPECT_NO_THROW(PlanarTraction({1.0, -2.0}, Unit::Pressure::Kilopascal));
  EXPECT_EQ(PlanarTraction(ScalarTraction(1.0, Unit::Pressure::Pascal),
                           ScalarTraction(-2.0, Unit::Pressure::Pascal)),
            PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(PlanarDirection(PlanarTraction({3.0, -4.0}, Unit::Pressure::Pascal)),
            PlanarDirection(3.0, -4.0));
  EXPECT_EQ(Angle(PlanarTraction({0.0, -2.0}, Unit::Pressure::Pascal),
                  PlanarTraction({3.0, 0.0}, Unit::Pressure::Pascal)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(PlanarTraction(
                PlanarForce({2.0, -4.0}, Unit::Force::Newton), Area(2.0, Unit::Area::SquareMetre)),
            PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(PlanarForce(PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal),
                        Area(2.0, Unit::Area::SquareMetre)),
            PlanarForce({2.0, -4.0}, Unit::Force::Newton));
}

TEST(PlanarTraction, CopyAssignmentOperator) {
  {
    const PlanarTraction<float> first({1.0F, -2.0F}, Unit::Pressure::Pascal);
    PlanarTraction<double> second = PlanarTraction<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarTraction<double>({1.0, -2.0}, Unit::Pressure::Pascal));
  }
  {
    const PlanarTraction<double> first({1.0, -2.0}, Unit::Pressure::Pascal);
    PlanarTraction<double> second = PlanarTraction<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarTraction<double>({1.0, -2.0}, Unit::Pressure::Pascal));
  }
  {
    const PlanarTraction<long double> first({1.0L, -2.0L}, Unit::Pressure::Pascal);
    PlanarTraction<double> second = PlanarTraction<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarTraction<double>({1.0, -2.0}, Unit::Pressure::Pascal));
  }
}

TEST(PlanarTraction, CopyConstructor) {
  {
    const PlanarTraction<float> first({1.0F, -2.0F}, Unit::Pressure::Pascal);
    const PlanarTraction<double> second{first};
    EXPECT_EQ(second, PlanarTraction<double>({1.0, -2.0}, Unit::Pressure::Pascal));
  }
  {
    const PlanarTraction<double> first({1.0, -2.0}, Unit::Pressure::Pascal);
    const PlanarTraction<double> second{first};
    EXPECT_EQ(second, PlanarTraction<double>({1.0, -2.0}, Unit::Pressure::Pascal));
  }
  {
    const PlanarTraction<long double> first({1.0L, -2.0L}, Unit::Pressure::Pascal);
    const PlanarTraction<double> second{first};
    EXPECT_EQ(second, PlanarTraction<double>({1.0, -2.0}, Unit::Pressure::Pascal));
  }
}

TEST(PlanarTraction, Create) {
  {
    constexpr PlanarTraction traction = PlanarTraction<>::Create<Unit::Pressure::Pascal>(1.0, -2.0);
    EXPECT_EQ(traction, PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
  }
  {
    constexpr PlanarTraction traction =
        PlanarTraction<>::Create<Unit::Pressure::Pascal>(std::array<double, 2>{1.0, -2.0});
    EXPECT_EQ(traction, PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
  }
  {
    constexpr PlanarTraction traction =
        PlanarTraction<>::Create<Unit::Pressure::Pascal>(PlanarVector{1.0, -2.0});
    EXPECT_EQ(traction, PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
  }
}

TEST(PlanarTraction, DefaultConstructor) {
  EXPECT_NO_THROW(PlanarTraction<>{});
}

TEST(PlanarTraction, Dimensions) {
  EXPECT_EQ(PlanarTraction<>::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(PlanarTraction, Hash) {
  const PlanarTraction first({1.0, -2.000001}, Unit::Pressure::Kilopascal);
  const PlanarTraction second({1.0, -2.0}, Unit::Pressure::Kilopascal);
  const PlanarTraction third({1.0, 2.0}, Unit::Pressure::Kilopascal);
  const std::hash<PlanarTraction<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PlanarTraction, JSON) {
  EXPECT_EQ(PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"Pa\"}");
  EXPECT_EQ(
      PlanarTraction({1.0, -2.0}, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
      "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"kPa\"}");
}

TEST(PlanarTraction, Magnitude) {
  EXPECT_EQ(PlanarTraction({3.0, -4.0}, Unit::Pressure::Pascal).Magnitude(),
            ScalarTraction(5.0, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, MoveAssignmentOperator) {
  PlanarTraction first({1.0, -2.0}, Unit::Pressure::Pascal);
  PlanarTraction second = PlanarTraction<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, MoveConstructor) {
  PlanarTraction first({1.0, -2.0}, Unit::Pressure::Pascal);
  const PlanarTraction second{std::move(first)};
  EXPECT_EQ(second, PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, MutableValue) {
  PlanarTraction traction({1.0, -2.0}, Unit::Pressure::Pascal);
  PlanarVector<>& value = traction.MutableValue();
  value = PlanarVector{-4.0, 5.0};
  EXPECT_EQ(traction.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarTraction, PlanarDirection) {
  EXPECT_EQ(PlanarTraction({3.0, -4.0}, Unit::Pressure::Pascal).PlanarDirection(),
            PlanarDirection(3.0, -4.0));
}

TEST(PlanarTraction, Print) {
  EXPECT_EQ(PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") Pa");
  EXPECT_EQ(
      PlanarTraction({1.0, -2.0}, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
      "(" + Print(1.0) + ", " + Print(-2.0) + ") kPa");
}

TEST(PlanarTraction, SetValue) {
  PlanarTraction traction({1.0, -2.0}, Unit::Pressure::Pascal);
  traction.SetValue({-4.0, 5.0});
  EXPECT_EQ(traction.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarTraction, SizeOf) {
  EXPECT_EQ(sizeof(PlanarTraction<>{}), 2 * sizeof(double));
}

TEST(PlanarTraction, StaticValue) {
  constexpr PlanarTraction traction =
      PlanarTraction<>::Create<Unit::Pressure::Kilopascal>(1.0, -2.0);
  constexpr PlanarVector value = traction.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, PlanarVector(1.0, -2.0));
}

TEST(PlanarTraction, Stream) {
  std::ostringstream stream;
  stream << PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal).Print());
}

TEST(PlanarTraction, Unit) {
  EXPECT_EQ(PlanarTraction<>::Unit(), Standard<Unit::Pressure>);
}

TEST(PlanarTraction, Value) {
  EXPECT_EQ(PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal).Value(), PlanarVector(1.0, -2.0));
  EXPECT_EQ(
      PlanarTraction({1.0, -2.0}, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal),
      PlanarVector(1.0, -2.0));
}

TEST(PlanarTraction, XML) {
  EXPECT_EQ(PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>Pa</unit>");
  EXPECT_EQ(PlanarTraction({1.0, -2.0}, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>kPa</unit>");
}

TEST(PlanarTraction, XY) {
  EXPECT_EQ(PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal).x(),
            ScalarTraction(1.0, Unit::Pressure::Pascal));
  EXPECT_EQ(PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal).y(),
            ScalarTraction(-2.0, Unit::Pressure::Pascal));
}

TEST(PlanarTraction, YAML) {
  EXPECT_EQ(PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"Pa\"}");
  EXPECT_EQ(
      PlanarTraction({1.0, -2.0}, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"kPa\"}");
}

TEST(PlanarTraction, Zero) {
  EXPECT_EQ(PlanarTraction<>::Zero(), PlanarTraction({0.0, 0.0}, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
