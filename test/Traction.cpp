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

#include "../include/PhQ/Traction.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Area.hpp"
#include "../include/PhQ/Direction.hpp"
#include "../include/PhQ/Force.hpp"
#include "../include/PhQ/ScalarTraction.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Area.hpp"
#include "../include/PhQ/Unit/Force.hpp"
#include "../include/PhQ/Unit/Pressure.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(Traction, Angle) {
  EXPECT_EQ(Traction({0.0, -2.0, 0.0}, Unit::Pressure::Pascal)
                .Angle(Traction({0.0, 0.0, 3.0}, Unit::Pressure::Pascal)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Traction, ArithmeticOperatorAddition) {
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal)
                + Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal),
            Traction({3.0, -6.0, 9.0}, Unit::Pressure::Pascal));
}

TEST(Traction, ArithmeticOperatorDivision) {
  EXPECT_EQ(Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal) / 2.0,
            Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(Force({2.0, -4.0, 6.0}, Unit::Force::Newton) / Area(2.0, Unit::Area::SquareMetre),
            Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
}

TEST(Traction, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal) * 2.0,
            Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(2.0 * Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal),
            Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(Direction(2.0, -3.0, 6.0) * ScalarTraction(7.0, Unit::Pressure::Pascal),
            Traction({2.0, -3.0, 6.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(ScalarTraction(7.0, Unit::Pressure::Pascal) * Direction(2.0, -3.0, 6.0),
            Traction({2.0, -3.0, 6.0}, Unit::Pressure::Pascal));
}

TEST(Traction, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Traction({3.0, -6.0, 9.0}, Unit::Pressure::Pascal)
                - Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal),
            Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
}

TEST(Traction, AssignmentOperatorAddition) {
  Traction traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  traction += Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(traction, Traction({3.0, -6.0, 9.0}, Unit::Pressure::Pascal));
}

TEST(Traction, AssignmentOperatorDivision) {
  Traction traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal);
  traction /= 2.0;
  EXPECT_EQ(traction, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
}

TEST(Traction, AssignmentOperatorMultiplication) {
  Traction traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  traction *= 2.0;
  EXPECT_EQ(traction, Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal));
}

TEST(Traction, AssignmentOperatorSubtraction) {
  Traction traction({3.0, -6.0, 9.0}, Unit::Pressure::Pascal);
  traction -= Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(traction, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
}

TEST(Traction, ComparisonOperators) {
  const Traction first({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  const Traction second({1.0, -2.0, 3.000001}, Unit::Pressure::Pascal);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Traction, Constructor) {
  EXPECT_NO_THROW(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Kilopascal));
  EXPECT_EQ(Traction(ScalarTraction(1.0, Unit::Pressure::Pascal),
                     ScalarTraction(-2.0, Unit::Pressure::Pascal),
                     ScalarTraction(3.0, Unit::Pressure::Pascal)),
            Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(
      Direction(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal)), Direction(1.0, -2.0, 3.0));
  EXPECT_EQ(Angle(Traction({0.0, -2.0, 0.0}, Unit::Pressure::Pascal),
                  Traction({0.0, 0.0, 3.0}, Unit::Pressure::Pascal)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(
      Traction(Force({2.0, -4.0, 6.0}, Unit::Force::Newton), Area(2.0, Unit::Area::SquareMetre)),
      Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(
      Force(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal), Area(2.0, Unit::Area::SquareMetre)),
      Force({2.0, -4.0, 6.0}, Unit::Force::Newton));
  EXPECT_EQ(PlanarTraction(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal)),
            PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(Traction(PlanarTraction({1.0, -2.0}, Unit::Pressure::Pascal)),
            Traction({1.0, -2.0, 0.0}, Unit::Pressure::Pascal));
}

TEST(Traction, CopyAssignmentOperator) {
  {
    const Traction<float> first({1.0F, -2.0F, 3.0F}, Unit::Pressure::Pascal);
    Traction<double> second = Traction<double>::Zero();
    second = first;
    EXPECT_EQ(second, Traction<double>({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
  {
    const Traction<double> first({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
    Traction<double> second = Traction<double>::Zero();
    second = first;
    EXPECT_EQ(second, Traction<double>({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
  {
    const Traction<long double> first({1.0L, -2.0L, 3.0L}, Unit::Pressure::Pascal);
    Traction<double> second = Traction<double>::Zero();
    second = first;
    EXPECT_EQ(second, Traction<double>({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
}

TEST(Traction, CopyConstructor) {
  {
    const Traction<float> first({1.0F, -2.0F, 3.0F}, Unit::Pressure::Pascal);
    const Traction<double> second{first};
    EXPECT_EQ(second, Traction<double>({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
  {
    const Traction<double> first({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
    const Traction<double> second{first};
    EXPECT_EQ(second, Traction<double>({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
  {
    const Traction<long double> first({1.0L, -2.0L, 3.0L}, Unit::Pressure::Pascal);
    const Traction<double> second{first};
    EXPECT_EQ(second, Traction<double>({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
}

TEST(Traction, Create) {
  {
    constexpr Traction traction = Traction<>::Create<Unit::Pressure::Pascal>(1.0, -2.0, 3.0);
    EXPECT_EQ(traction, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
  {
    constexpr Traction traction =
        Traction<>::Create<Unit::Pressure::Pascal>(std::array<double, 3>{1.0, -2.0, 3.0});
    EXPECT_EQ(traction, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
  {
    constexpr Traction traction =
        Traction<>::Create<Unit::Pressure::Pascal>(Vector{1.0, -2.0, 3.0});
    EXPECT_EQ(traction, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
}

TEST(Traction, DefaultConstructor) {
  EXPECT_NO_THROW(Traction<>{});
}

TEST(Traction, Dimensions) {
  EXPECT_EQ(Traction<>::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(Traction, Direction) {
  EXPECT_EQ(
      Traction({2.0, -3.0, 6.0}, Unit::Pressure::Pascal).Direction(), Direction(2.0, -3.0, 6.0));
}

TEST(Traction, Hash) {
  const Traction first({1.0, -2.0, 3.0}, Unit::Pressure::Kilopascal);
  const Traction second({1.0, -2.0, 3.000001}, Unit::Pressure::Kilopascal);
  const Traction third({1.0, 2.0, 3.0}, Unit::Pressure::Kilopascal);
  const std::hash<Traction<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Traction, JSON) {
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"Pa\"}");
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"kPa\"}");
}

TEST(Traction, Magnitude) {
  EXPECT_EQ(Traction({2.0, -3.0, 6.0}, Unit::Pressure::Pascal).Magnitude(),
            ScalarTraction(7.0, Unit::Pressure::Pascal));
}

TEST(Traction, MoveAssignmentOperator) {
  Traction first({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  Traction second = Traction<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
}

TEST(Traction, MoveConstructor) {
  Traction first({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  const Traction second{std::move(first)};
  EXPECT_EQ(second, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
}

TEST(Traction, MutableValue) {
  Traction traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  Vector<>& value = traction.MutableValue();
  value = Vector{-4.0, 5.0, -6.0};
  EXPECT_EQ(traction.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(Traction, Print) {
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") Pa");
  EXPECT_EQ(
      Traction({1.0, -2.0, 3.0}, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
      "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") kPa");
}

TEST(Traction, SetValue) {
  Traction traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  traction.SetValue({-4.0, 5.0, -6.0});
  EXPECT_EQ(traction.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(Traction, SizeOf) {
  EXPECT_EQ(sizeof(Traction<>{}), 3 * sizeof(double));
}

TEST(Traction, StaticValue) {
  constexpr Traction traction = Traction<>::Create<Unit::Pressure::Kilopascal>(1.0, -2.0, 3.0);
  constexpr Vector value = traction.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(Traction, Stream) {
  std::ostringstream stream;
  stream << Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).Print());
}

TEST(Traction, Unit) {
  EXPECT_EQ(Traction<>::Unit(), Standard<Unit::Pressure>);
}

TEST(Traction, Value) {
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).Value(), Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(
      Traction({1.0, -2.0, 3.0}, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal),
      Vector(1.0, -2.0, 3.0));
}

TEST(Traction, XML) {
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>Pa</unit>");
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>kPa</unit>");
}

TEST(Traction, XYZ) {
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).x(),
            ScalarTraction(1.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).y(),
            ScalarTraction(-2.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).z(),
            ScalarTraction(3.0, Unit::Pressure::Pascal));
}

TEST(Traction, YAML) {
  EXPECT_EQ(
      Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).YAML(),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"Pa\"}");
  EXPECT_EQ(
      Traction({1.0, -2.0, 3.0}, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"kPa\"}");
}

TEST(Traction, Zero) {
  EXPECT_EQ(Traction<>::Zero(), Traction({0.0, 0.0, 0.0}, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
