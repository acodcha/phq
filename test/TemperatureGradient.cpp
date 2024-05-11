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

#include "../include/PhQ/TemperatureGradient.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Direction.hpp"
#include "../include/PhQ/ScalarTemperatureGradient.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/TemperatureGradient.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(TemperatureGradient, Angle) {
  EXPECT_EQ(
      TemperatureGradient({0.0, -2.0, 0.0}, Unit::TemperatureGradient::KelvinPerMetre)
          .Angle(TemperatureGradient({0.0, 0.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)),
      Angle(90.0, Unit::Angle::Degree));
}

TEST(TemperatureGradient, ArithmeticOperatorAddition) {
  EXPECT_EQ(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)
                + TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradient({3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, ArithmeticOperatorDivision) {
  EXPECT_EQ(TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre) / 2.0,
            TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre) * 2.0,
            TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(2.0 * TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(Direction(2.0, -3.0, 6.0)
                * ScalarTemperatureGradient(7.0, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradient({2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(ScalarTemperatureGradient(7.0, Unit::TemperatureGradient::KelvinPerMetre)
                * Direction(2.0, -3.0, 6.0),
            TemperatureGradient({2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(TemperatureGradient({3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre)
                - TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, AssignmentOperatorAddition) {
  TemperatureGradient temperature_gradient(
      {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  temperature_gradient +=
      TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(temperature_gradient,
            TemperatureGradient({3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, AssignmentOperatorDivision) {
  TemperatureGradient temperature_gradient(
      {2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre);
  temperature_gradient /= 2.0;
  EXPECT_EQ(temperature_gradient,
            TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, AssignmentOperatorMultiplication) {
  TemperatureGradient temperature_gradient(
      {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  temperature_gradient *= 2.0;
  EXPECT_EQ(temperature_gradient,
            TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, AssignmentOperatorSubtraction) {
  TemperatureGradient temperature_gradient(
      {3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre);
  temperature_gradient -=
      TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(temperature_gradient,
            TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, ComparisonOperators) {
  const TemperatureGradient first({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  const TemperatureGradient second({1.0, -2.0, 3.00001}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(TemperatureGradient, CopyAssignmentOperator) {
  const TemperatureGradient first({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  TemperatureGradient second = TemperatureGradient<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(TemperatureGradient, CopyConstructor) {
  const TemperatureGradient first({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  const TemperatureGradient second{first};
  EXPECT_EQ(second, first);
}

TEST(TemperatureGradient, Create) {
  constexpr TemperatureGradient first =
      TemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMetre>(1.0, -2.0, 3.0);
  EXPECT_EQ(
      first, TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));

  constexpr TemperatureGradient second =
      TemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMetre>(
          std::array<double, 3>{1.0, -2.0, 3.0});
  EXPECT_EQ(
      second, TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));

  constexpr TemperatureGradient third =
      TemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMetre>(
          Vector{1.0, -2.0, 3.0});
  EXPECT_EQ(
      third, TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, DefaultConstructor) {
  EXPECT_NO_THROW(TemperatureGradient{});
}

TEST(TemperatureGradient, Dimensions) {
  EXPECT_EQ(TemperatureGradient<>::Dimensions(), RelatedDimensions<Unit::TemperatureGradient>);
}

TEST(TemperatureGradient, Direction) {
  EXPECT_EQ(
      TemperatureGradient({2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre).Direction(),
      Direction(2.0, -3.0, 6.0));
}

TEST(TemperatureGradient, Hash) {
  const TemperatureGradient first({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMillimetre);
  const TemperatureGradient second(
      {1.0, -2.0, 3.00001}, Unit::TemperatureGradient::KelvinPerMillimetre);
  const TemperatureGradient third({1.0, 2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMillimetre);
  const std::hash<TemperatureGradient<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(TemperatureGradient, JSON) {
  EXPECT_EQ(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"K/m\"}");
  EXPECT_EQ(TemperatureGradient({0.0, -2.0, 0.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .JSON(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{\"value\":{\"x\":0,\"y\":" + Print(-2.0) + ",\"z\":0},\"unit\":\"K/mm\"}");
}

TEST(TemperatureGradient, Magnitude) {
  EXPECT_EQ(
      TemperatureGradient({2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre).Magnitude(),
      ScalarTemperatureGradient(7.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, MiscellaneousConstructors) {
  EXPECT_EQ(
      Direction(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)),
      Direction(1.0, -2.0, 3.0));
  EXPECT_EQ(Angle(TemperatureGradient({0.0, -2.0, 0.0}, Unit::TemperatureGradient::KelvinPerMetre),
                  TemperatureGradient({0.0, 0.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(TemperatureGradient, MoveAssignmentOperator) {
  TemperatureGradient first({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  TemperatureGradient second = TemperatureGradient<>::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, MoveConstructor) {
  TemperatureGradient first({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  const TemperatureGradient second{std::move(first)};
  EXPECT_EQ(
      second, TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, MutableValue) {
  TemperatureGradient temperature_gradient(
      {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  Vector<>& value = temperature_gradient.MutableValue();
  value = Vector{-4.0, 5.0, -6.0};
  EXPECT_EQ(temperature_gradient.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(TemperatureGradient, Print) {
  EXPECT_EQ(
      TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre).Print(),
      "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") K/m");
  EXPECT_EQ(TemperatureGradient({0.0, -2.0, 0.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Print(Unit::TemperatureGradient::KelvinPerMillimetre),
            "(0, " + Print(-2.0) + ", 0) K/mm");
}

TEST(TemperatureGradient, SetValue) {
  TemperatureGradient temperature_gradient(
      {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  temperature_gradient.SetValue({-4.0, 5.0, -6.0});
  EXPECT_EQ(temperature_gradient.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(TemperatureGradient, SizeOf) {
  EXPECT_EQ(sizeof(TemperatureGradient{}), 3 * sizeof(double));
}

TEST(TemperatureGradient, StandardConstructor) {
  EXPECT_NO_THROW(
      TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMillimetre));
}

TEST(TemperatureGradient, StaticValue) {
  constexpr TemperatureGradient temperature_gradient =
      TemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMillimetre>(1.0, -2.0, 3.0);
  constexpr Vector value =
      temperature_gradient.StaticValue<Unit::TemperatureGradient::KelvinPerMillimetre>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(TemperatureGradient, Stream) {
  std::ostringstream stream;
  stream << TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(
      stream.str(),
      TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre).Print());
}

TEST(TemperatureGradient, Unit) {
  EXPECT_EQ(TemperatureGradient<>::Unit(), Standard<Unit::TemperatureGradient>);
}

TEST(TemperatureGradient, Value) {
  EXPECT_EQ(
      TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre).Value(),
      Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Value(Unit::TemperatureGradient::KelvinPerMillimetre),
            Vector(1.0, -2.0, 3.0));
}

TEST(TemperatureGradient, XML) {
  EXPECT_EQ(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>K/m</unit>");
  EXPECT_EQ(TemperatureGradient({0.0, -2.0, 0.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .XML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "<value><x>0</x><y>" + Print(-2.0) + "</y><z>0</z></value><unit>K/mm</unit>");
}

TEST(TemperatureGradient, XYZ) {
  EXPECT_EQ(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre).x(),
            ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre).y(),
            ScalarTemperatureGradient(-2.0, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre).z(),
            ScalarTemperatureGradient(3.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, YAML) {
  EXPECT_EQ(
      TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre).YAML(),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"K/m\"}");
  EXPECT_EQ(TemperatureGradient({0.0, -2.0, 0.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .YAML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{value:{x:0,y:" + Print(-2.0) + ",z:0},unit:\"K/mm\"}");
}

TEST(TemperatureGradient, Zero) {
  EXPECT_EQ(TemperatureGradient<>::Zero(),
            TemperatureGradient({0.0, 0.0, 0.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

}  // namespace

}  // namespace PhQ
