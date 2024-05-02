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
#include "../include/PhQ/StaticPressure.hpp"
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
  EXPECT_EQ(Direction(2.0, -3.0, 6.0) * StaticPressure(7.0, Unit::Pressure::Pascal),
            Traction({-2.0, 3.0, -6.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(StaticPressure(7.0, Unit::Pressure::Pascal) * Direction(2.0, -3.0, 6.0),
            Traction({-2.0, 3.0, -6.0}, Unit::Pressure::Pascal));
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

TEST(Traction, CopyAssignmentOperator) {
  const Traction first({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  Traction second = Traction::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Traction, CopyConstructor) {
  const Traction first({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  const Traction second{first};
  EXPECT_EQ(second, first);
}

TEST(Traction, Create) {
  {
    constexpr Traction traction = Traction::Create<Unit::Pressure::Pascal>(1.0, -2.0, 3.0);
    EXPECT_EQ(traction, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
  {
    constexpr Traction traction =
        Traction::Create<Unit::Pressure::Pascal>(std::array<double, 3>{1.0, -2.0, 3.0});
    EXPECT_EQ(traction, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
  {
    constexpr Traction traction = Traction::Create<Unit::Pressure::Pascal>(Vector{1.0, -2.0, 3.0});
    EXPECT_EQ(traction, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
  }
}

TEST(Traction, DefaultConstructor) {
  EXPECT_NO_THROW(Traction{});
}

TEST(Traction, Dimensions) {
  EXPECT_EQ(Traction::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(Traction, Direction) {
  EXPECT_EQ(
      Traction({2.0, -3.0, 6.0}, Unit::Pressure::Pascal).Direction(), Direction(2.0, -3.0, 6.0));
}

TEST(Traction, Hash) {
  const Traction first({1.0, -2.0, 3.0}, Unit::Pressure::Kilopascal);
  const Traction second({1.0, -2.0, 3.000001}, Unit::Pressure::Kilopascal);
  const Traction third({1.0, 2.0, 3.0}, Unit::Pressure::Kilopascal);
  const std::hash<Traction> hash;
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
            StaticPressure(-7.0, Unit::Pressure::Pascal));
}

TEST(Traction, MiscellaneousConstructors) {
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
}

TEST(Traction, MoveAssignmentOperator) {
  Traction first({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  Traction second = Traction::Zero();
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
  EXPECT_EQ(sizeof(Traction{}), 3 * sizeof(double));
}

TEST(Traction, StandardConstructor) {
  EXPECT_NO_THROW(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Kilopascal));
}

TEST(Traction, StaticValue) {
  constexpr Traction traction = Traction::Create<Unit::Pressure::Kilopascal>(1.0, -2.0, 3.0);
  constexpr Vector value = traction.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(Traction, Stream) {
  std::ostringstream stream;
  stream << Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).Print());
}

TEST(Traction, Unit) {
  EXPECT_EQ(Traction::Unit(), Standard<Unit::Pressure>);
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
            StaticPressure(1.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).y(),
            StaticPressure(-2.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal).z(),
            StaticPressure(3.0, Unit::Pressure::Pascal));
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
  EXPECT_EQ(Traction::Zero(), Traction({0.0, 0.0, 0.0}, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
