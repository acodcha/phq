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

#include "../include/PhQ/PlanarTemperatureGradient.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/PlanarDirection.hpp"
#include "../include/PhQ/PlanarVector.hpp"
#include "../include/PhQ/ScalarTemperatureGradient.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/TemperatureGradient.hpp"

namespace PhQ {

namespace {

TEST(PlanarTemperatureGradient, Angle) {
  EXPECT_EQ(
      PlanarTemperatureGradient({0.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre)
          .Angle(PlanarTemperatureGradient({3.0, 0.0}, Unit::TemperatureGradient::KelvinPerMetre)),
      Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarTemperatureGradient, ArithmeticOperatorAddition) {
  EXPECT_EQ(PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre)
                + PlanarTemperatureGradient({2.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre),
            PlanarTemperatureGradient({3.0, -6.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, ArithmeticOperatorDivision) {
  EXPECT_EQ(PlanarTemperatureGradient({2.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre) / 2.0,
            PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre) * 2.0,
            PlanarTemperatureGradient({2.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(2.0 * PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre),
            PlanarTemperatureGradient({2.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(PlanarDirection(3.0, -4.0)
                * ScalarTemperatureGradient(5.0, Unit::TemperatureGradient::KelvinPerMetre),
            PlanarTemperatureGradient({3.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(ScalarTemperatureGradient(5.0, Unit::TemperatureGradient::KelvinPerMetre)
                * PlanarDirection(3.0, -4.0),
            PlanarTemperatureGradient({3.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PlanarTemperatureGradient({3.0, -6.0}, Unit::TemperatureGradient::KelvinPerMetre)
                - PlanarTemperatureGradient({2.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre),
            PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, AssignmentOperatorAddition) {
  PlanarTemperatureGradient temperature_gradient(
      {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre);
  temperature_gradient +=
      PlanarTemperatureGradient({2.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(temperature_gradient,
            PlanarTemperatureGradient({3.0, -6.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, AssignmentOperatorDivision) {
  PlanarTemperatureGradient temperature_gradient(
      {2.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre);
  temperature_gradient /= 2.0;
  EXPECT_EQ(temperature_gradient,
            PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, AssignmentOperatorMultiplication) {
  PlanarTemperatureGradient temperature_gradient(
      {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre);
  temperature_gradient *= 2.0;
  EXPECT_EQ(temperature_gradient,
            PlanarTemperatureGradient({2.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, AssignmentOperatorSubtraction) {
  PlanarTemperatureGradient temperature_gradient(
      {3.0, -6.0}, Unit::TemperatureGradient::KelvinPerMetre);
  temperature_gradient -=
      PlanarTemperatureGradient({2.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(temperature_gradient,
            PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, ComparisonOperators) {
  const PlanarTemperatureGradient first({1.0, -2.00001}, Unit::TemperatureGradient::KelvinPerMetre);
  const PlanarTemperatureGradient second({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PlanarTemperatureGradient, Constructor) {
  EXPECT_NO_THROW(
      PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMillimetre));
  EXPECT_EQ(PlanarTemperatureGradient(
                ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre),
                ScalarTemperatureGradient(-2.0, Unit::TemperatureGradient::KelvinPerMetre)),
            PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(PlanarDirection(
                PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre)),
            PlanarDirection(1.0, -2.0));
  EXPECT_EQ(Angle(PlanarTemperatureGradient({0.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre),
                  PlanarTemperatureGradient({3.0, 0.0}, Unit::TemperatureGradient::KelvinPerMetre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarTemperatureGradient, CopyAssignmentOperator) {
  {
    const PlanarTemperatureGradient<float> first(
        {1.0F, -2.0F}, Unit::TemperatureGradient::KelvinPerMetre);
    PlanarTemperatureGradient<double> second = PlanarTemperatureGradient<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarTemperatureGradient<double>(
                          {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const PlanarTemperatureGradient<double> first(
        {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre);
    PlanarTemperatureGradient<double> second = PlanarTemperatureGradient<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarTemperatureGradient<double>(
                          {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const PlanarTemperatureGradient<long double> first(
        {1.0L, -2.0L}, Unit::TemperatureGradient::KelvinPerMetre);
    PlanarTemperatureGradient<double> second = PlanarTemperatureGradient<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarTemperatureGradient<double>(
                          {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
}

TEST(PlanarTemperatureGradient, CopyConstructor) {
  {
    const PlanarTemperatureGradient<float> first(
        {1.0F, -2.0F}, Unit::TemperatureGradient::KelvinPerMetre);
    const PlanarTemperatureGradient<double> second{first};
    EXPECT_EQ(second, PlanarTemperatureGradient<double>(
                          {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const PlanarTemperatureGradient<double> first(
        {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre);
    const PlanarTemperatureGradient<double> second{first};
    EXPECT_EQ(second, PlanarTemperatureGradient<double>(
                          {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const PlanarTemperatureGradient<long double> first(
        {1.0L, -2.0L}, Unit::TemperatureGradient::KelvinPerMetre);
    const PlanarTemperatureGradient<double> second{first};
    EXPECT_EQ(second, PlanarTemperatureGradient<double>(
                          {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
  }
}

TEST(PlanarTemperatureGradient, Create) {
  constexpr PlanarTemperatureGradient first =
      PlanarTemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMetre>(1.0, -2.0);
  EXPECT_EQ(
      first, PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));

  constexpr PlanarTemperatureGradient second =
      PlanarTemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMetre>(
          std::array<double, 2>{1.0, -2.0});
  EXPECT_EQ(
      second, PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));

  constexpr PlanarTemperatureGradient third =
      PlanarTemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMetre>(
          PlanarVector{1.0, -2.0});
  EXPECT_EQ(
      third, PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, DefaultConstructor) {
  EXPECT_NO_THROW(PlanarTemperatureGradient<>{});
}

TEST(PlanarTemperatureGradient, Dimensions) {
  EXPECT_EQ(
      PlanarTemperatureGradient<>::Dimensions(), RelatedDimensions<Unit::TemperatureGradient>);
}

TEST(PlanarTemperatureGradient, Hash) {
  const PlanarTemperatureGradient first(
      {1.0, -2.00001}, Unit::TemperatureGradient::KelvinPerMillimetre);
  const PlanarTemperatureGradient second(
      {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMillimetre);
  const PlanarTemperatureGradient third({1.0, 2.0}, Unit::TemperatureGradient::KelvinPerMillimetre);
  const std::hash<PlanarTemperatureGradient<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PlanarTemperatureGradient, JSON) {
  EXPECT_EQ(
      PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre).JSON(),
      "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"K/m\"}");
  EXPECT_EQ(PlanarTemperatureGradient({0.0, -2.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .JSON(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{\"value\":{\"x\":" + Print(0.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"K/mm\"}");
}

TEST(PlanarTemperatureGradient, Magnitude) {
  EXPECT_EQ(
      PlanarTemperatureGradient({3.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre).Magnitude(),
      ScalarTemperatureGradient(5.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, MoveAssignmentOperator) {
  PlanarTemperatureGradient first({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre);
  PlanarTemperatureGradient second = PlanarTemperatureGradient<>::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, MoveConstructor) {
  PlanarTemperatureGradient first({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre);
  const PlanarTemperatureGradient second{std::move(first)};
  EXPECT_EQ(
      second, PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, MutableValue) {
  PlanarTemperatureGradient temperature_gradient(
      {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre);
  PlanarVector<>& value = temperature_gradient.MutableValue();
  value = PlanarVector{-4.0, 5.0};
  EXPECT_EQ(temperature_gradient.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarTemperatureGradient, PlanarDirection) {
  EXPECT_EQ(PlanarTemperatureGradient({3.0, -4.0}, Unit::TemperatureGradient::KelvinPerMetre)
                .PlanarDirection(),
            PlanarDirection(3.0, -4.0));
}

TEST(PlanarTemperatureGradient, Print) {
  EXPECT_EQ(
      PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre).Print(),
      "(" + Print(1.0) + ", " + Print(-2.0) + ") K/m");
  EXPECT_EQ(PlanarTemperatureGradient({0.0, -2.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Print(Unit::TemperatureGradient::KelvinPerMillimetre),
            "(" + Print(0.0) + ", " + Print(-2.0) + ") K/mm");
}

TEST(PlanarTemperatureGradient, SetValue) {
  PlanarTemperatureGradient temperature_gradient(
      {1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre);
  temperature_gradient.SetValue({-4.0, 5.0});
  EXPECT_EQ(temperature_gradient.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarTemperatureGradient, SizeOf) {
  EXPECT_EQ(sizeof(PlanarTemperatureGradient<>{}), 2 * sizeof(double));
}

TEST(PlanarTemperatureGradient, StaticValue) {
  constexpr PlanarTemperatureGradient temperature_gradient =
      PlanarTemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMillimetre>(
          1.0, -2.0);
  constexpr PlanarVector value =
      temperature_gradient.StaticValue<Unit::TemperatureGradient::KelvinPerMillimetre>();
  EXPECT_EQ(value, PlanarVector(1.0, -2.0));
}

TEST(PlanarTemperatureGradient, Stream) {
  std::ostringstream stream;
  stream << PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(
      stream.str(),
      PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre).Print());
}

TEST(PlanarTemperatureGradient, Unit) {
  EXPECT_EQ(PlanarTemperatureGradient<>::Unit(), Standard<Unit::TemperatureGradient>);
}

TEST(PlanarTemperatureGradient, Value) {
  EXPECT_EQ(
      PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre).Value(),
      PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Value(Unit::TemperatureGradient::KelvinPerMillimetre),
            PlanarVector(1.0, -2.0));
}

TEST(PlanarTemperatureGradient, XML) {
  EXPECT_EQ(PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>K/m</unit>");
  EXPECT_EQ(PlanarTemperatureGradient({0.0, -2.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .XML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "<value><x>" + Print(0.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>K/mm</unit>");
}

TEST(PlanarTemperatureGradient, XY) {
  EXPECT_EQ(PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre).x(),
            ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre).y(),
            ScalarTemperatureGradient(-2.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(PlanarTemperatureGradient, YAML) {
  EXPECT_EQ(
      PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre).YAML(),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"K/m\"}");
  EXPECT_EQ(PlanarTemperatureGradient({0.0, -2.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .YAML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{value:{x:" + Print(0.0) + ",y:" + Print(-2.0) + "},unit:\"K/mm\"}");
}

TEST(PlanarTemperatureGradient, Zero) {
  EXPECT_EQ(PlanarTemperatureGradient<>::Zero(),
            PlanarTemperatureGradient({0.0, 0.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

}  // namespace

}  // namespace PhQ
