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
#include "Performance.hpp"

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

TEST(TemperatureGradient, Constructor) {
  EXPECT_NO_THROW(
      TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMillimetre));
  EXPECT_EQ(TemperatureGradient(
                ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre),
                ScalarTemperatureGradient(-2.0, Unit::TemperatureGradient::KelvinPerMetre),
                ScalarTemperatureGradient(3.0, Unit::TemperatureGradient::KelvinPerMetre)),
            TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(
      Direction(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)),
      Direction(1.0, -2.0, 3.0));
  EXPECT_EQ(Angle(TemperatureGradient({0.0, -2.0, 0.0}, Unit::TemperatureGradient::KelvinPerMetre),
                  TemperatureGradient({0.0, 0.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(PlanarTemperatureGradient(
                TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)),
            PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(TemperatureGradient(
                PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre)),
            TemperatureGradient({1.0, -2.0, 0.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, CopyAssignmentOperator) {
  {
    const TemperatureGradient<float> first(
        {1.0F, -2.0F, 3.0F}, Unit::TemperatureGradient::KelvinPerMetre);
    TemperatureGradient<double> second = TemperatureGradient<double>::Zero();
    second = first;
    EXPECT_EQ(second, TemperatureGradient<double>(
                          {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const TemperatureGradient<double> first(
        {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
    TemperatureGradient<double> second = TemperatureGradient<double>::Zero();
    second = first;
    EXPECT_EQ(second, TemperatureGradient<double>(
                          {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const TemperatureGradient<long double> first(
        {1.0L, -2.0L, 3.0L}, Unit::TemperatureGradient::KelvinPerMetre);
    TemperatureGradient<double> second = TemperatureGradient<double>::Zero();
    second = first;
    EXPECT_EQ(second, TemperatureGradient<double>(
                          {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
}

TEST(TemperatureGradient, CopyConstructor) {
  {
    const TemperatureGradient<float> first(
        {1.0F, -2.0F, 3.0F}, Unit::TemperatureGradient::KelvinPerMetre);
    const TemperatureGradient<double> second{first};
    EXPECT_EQ(second, TemperatureGradient<double>(
                          {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const TemperatureGradient<double> first(
        {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
    const TemperatureGradient<double> second{first};
    EXPECT_EQ(second, TemperatureGradient<double>(
                          {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const TemperatureGradient<long double> first(
        {1.0L, -2.0L, 3.0L}, Unit::TemperatureGradient::KelvinPerMetre);
    const TemperatureGradient<double> second{first};
    EXPECT_EQ(second, TemperatureGradient<double>(
                          {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
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
  EXPECT_NO_THROW(TemperatureGradient<>{});
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

TEST(TemperatureGradient, Performance) {
  TemperatureGradient temperature_gradient_1{
      {1.2345678901234567890, 2.3456789012345678901, 3.4567890123456789012},
      Unit::TemperatureGradient::KelvinPerMetre
  };
  TemperatureGradient temperature_gradient_2{
      {1.2345678901234567890, 2.3456789012345678901, 3.4567890123456789012},
      Unit::TemperatureGradient::KelvinPerMetre
  };
  std::array<double, 3> reference1{
      1.2345678901234567890, 2.3456789012345678901, 3.4567890123456789012};
  std::array<double, 3> reference2{
      1.2345678901234567890, 2.3456789012345678901, 3.4567890123456789012};
  Internal::TestVectorPerformance(
      temperature_gradient_1, temperature_gradient_2, reference1, reference2);
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
  EXPECT_EQ(sizeof(TemperatureGradient<>{}), 3 * sizeof(double));
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
