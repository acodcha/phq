// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#include "../include/PhQ/TemperatureGradientMagnitude.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(TemperatureGradientMagnitude, ArithmeticOperatorAddition) {
  EXPECT_EQ(TemperatureGradientMagnitude(
                1.0, Unit::TemperatureGradient::KelvinPerMetre)
                + TemperatureGradientMagnitude(
                    2.0, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradientMagnitude(
                3.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientMagnitude, ArithmeticOperatorDivision) {
  EXPECT_EQ(TemperatureGradientMagnitude(
                8.0, Unit::TemperatureGradient::KelvinPerMetre)
                / 2.0,
            TemperatureGradientMagnitude(
                4.0, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(TemperatureGradientMagnitude(
                8.0, Unit::TemperatureGradient::KelvinPerMetre)
                / TemperatureGradientMagnitude(
                    2.0, Unit::TemperatureGradient::KelvinPerMetre),
            4.0);

  EXPECT_EQ(TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin)
                / Length(4.0, Unit::Length::Metre),
            TemperatureGradientMagnitude(
                2.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientMagnitude, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(TemperatureGradientMagnitude(
                4.0, Unit::TemperatureGradient::KelvinPerMetre)
                * 2.0,
            TemperatureGradientMagnitude(
                8.0, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(2.0
                * TemperatureGradientMagnitude(
                    4.0, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradientMagnitude(
                8.0, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(TemperatureGradientMagnitude(
                4.0, Unit::TemperatureGradient::KelvinPerMetre)
                * Length(2.0, Unit::Length::Metre),
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureGradientMagnitude, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(TemperatureGradientMagnitude(
                3.0, Unit::TemperatureGradient::KelvinPerMetre)
                - TemperatureGradientMagnitude(
                    2.0, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradientMagnitude(
                1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientMagnitude, AssignmentOperatorAddition) {
  TemperatureGradientMagnitude quantity{
      1.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity += TemperatureGradientMagnitude(
      2.0, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(quantity, TemperatureGradientMagnitude(
                          3.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientMagnitude, AssignmentOperatorDivision) {
  TemperatureGradientMagnitude quantity{
      8.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity /= 2.0;
  EXPECT_EQ(quantity, TemperatureGradientMagnitude(
                          4.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientMagnitude, AssignmentOperatorMultiplication) {
  TemperatureGradientMagnitude quantity{
      4.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity *= 2.0;
  EXPECT_EQ(quantity, TemperatureGradientMagnitude(
                          8.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientMagnitude, AssignmentOperatorSubtraction) {
  TemperatureGradientMagnitude quantity{
      3.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity -= TemperatureGradientMagnitude(
      2.0, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(quantity, TemperatureGradientMagnitude(
                          1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientMagnitude, ComparisonOperators) {
  const TemperatureGradientMagnitude first{
      0.1, Unit::TemperatureGradient::KelvinPerMetre};
  const TemperatureGradientMagnitude second{
      0.2, Unit::TemperatureGradient::KelvinPerMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(TemperatureGradientMagnitude, CopyAssignmentOperator) {
  const TemperatureGradientMagnitude first{
      1.11, Unit::TemperatureGradient::KelvinPerMetre};
  TemperatureGradientMagnitude second = TemperatureGradientMagnitude::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(TemperatureGradientMagnitude, CopyConstructor) {
  const TemperatureGradientMagnitude first{
      1.11, Unit::TemperatureGradient::KelvinPerMetre};
  const TemperatureGradientMagnitude second{first};
  EXPECT_EQ(second, first);
}

TEST(TemperatureGradientMagnitude, Create) {
  constexpr TemperatureGradientMagnitude quantity =
      TemperatureGradientMagnitude::Create<
          Unit::TemperatureGradient::KelvinPerMetre>(1.11);
  EXPECT_EQ(quantity, TemperatureGradientMagnitude(
                          1.11, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientMagnitude, DefaultConstructor) {
  EXPECT_NO_THROW(TemperatureGradientMagnitude{});
}

TEST(TemperatureGradientMagnitude, Dimensions) {
  EXPECT_EQ(TemperatureGradientMagnitude::Dimensions(),
            RelatedDimensions<Unit::TemperatureGradient>);
}

TEST(TemperatureGradientMagnitude, Hash) {
  const TemperatureGradientMagnitude first{
      1.11, Unit::TemperatureGradient::KelvinPerMetre};
  const TemperatureGradientMagnitude second{
      1.110001, Unit::TemperatureGradient::KelvinPerMetre};
  const TemperatureGradientMagnitude third{
      -1.11, Unit::TemperatureGradient::KelvinPerMetre};
  const std::hash<TemperatureGradientMagnitude> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(TemperatureGradientMagnitude, JSON) {
  EXPECT_EQ(TemperatureGradientMagnitude(
                1.11, Unit::TemperatureGradient::KelvinPerMetre)
                .JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"K/m\"}");
  EXPECT_EQ(TemperatureGradientMagnitude(
                -2.22, Unit::TemperatureGradient::KelvinPerMillimetre)
                .JSON(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{\"value\":-2.220000000000000,\"unit\":\"K/mm\"}");
}

TEST(TemperatureGradientMagnitude, MiscellaneousConstructors) {
  EXPECT_EQ(TemperatureGradientMagnitude(
                TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin),
                Length(4.0, Unit::Length::Metre)),
            TemperatureGradientMagnitude(
                2.0, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(
      TemperatureDifference(TemperatureGradientMagnitude(
                                4.0, Unit::TemperatureGradient::KelvinPerMetre),
                            Length(2.0, Unit::Length::Metre)),
      TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureGradientMagnitude, MoveAssignmentOperator) {
  TemperatureGradientMagnitude first{
      1.11, Unit::TemperatureGradient::KelvinPerMetre};
  TemperatureGradientMagnitude second = TemperatureGradientMagnitude::Zero();
  second = std::move(first);
  EXPECT_EQ(second, TemperatureGradientMagnitude(
                        1.11, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientMagnitude, MoveConstructor) {
  TemperatureGradientMagnitude first{
      1.11, Unit::TemperatureGradient::KelvinPerMetre};
  TemperatureGradientMagnitude second{std::move(first)};
  EXPECT_EQ(second, TemperatureGradientMagnitude(
                        1.11, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientMagnitude, MutableValue) {
  TemperatureGradientMagnitude quantity{
      1.11, Unit::TemperatureGradient::KelvinPerMetre};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(TemperatureGradientMagnitude, Print) {
  EXPECT_EQ(TemperatureGradientMagnitude(
                1.11, Unit::TemperatureGradient::KelvinPerMetre)
                .Print(),
            "1.110000000000000 K/m");
  EXPECT_EQ(TemperatureGradientMagnitude(
                -2.22, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Print(Unit::TemperatureGradient::KelvinPerMillimetre),
            "-2.220000000000000 K/mm");
}

TEST(TemperatureGradientMagnitude, SetValue) {
  TemperatureGradientMagnitude quantity{
      1.11, Unit::TemperatureGradient::KelvinPerMetre};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(TemperatureGradientMagnitude, SizeOf) {
  EXPECT_EQ(sizeof(TemperatureGradientMagnitude{}), sizeof(double));
}

TEST(TemperatureGradientMagnitude, StandardConstructor) {
  EXPECT_NO_THROW(TemperatureGradientMagnitude(
      1.11, Unit::TemperatureGradient::KelvinPerMillimetre));
}

TEST(TemperatureGradientMagnitude, StaticValue) {
  constexpr TemperatureGradientMagnitude quantity =
      TemperatureGradientMagnitude::Create<
          Unit::TemperatureGradient::KelvinPerMillimetre>(1.11);
  constexpr double value =
      quantity.StaticValue<Unit::TemperatureGradient::KelvinPerMillimetre>();
  EXPECT_EQ(value, 1.11);
}

TEST(TemperatureGradientMagnitude, Stream) {
  std::ostringstream stream;
  stream << TemperatureGradientMagnitude(
      1.11, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(stream.str(), TemperatureGradientMagnitude(
                              1.11, Unit::TemperatureGradient::KelvinPerMetre)
                              .Print());
}

TEST(TemperatureGradientMagnitude, Unit) {
  EXPECT_EQ(TemperatureGradientMagnitude::Unit(),
            Standard<Unit::TemperatureGradient>);
}

TEST(TemperatureGradientMagnitude, Value) {
  EXPECT_EQ(TemperatureGradientMagnitude(
                1.11, Unit::TemperatureGradient::KelvinPerMetre)
                .Value(),
            1.11);
  EXPECT_EQ(TemperatureGradientMagnitude(
                1.11, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Value(Unit::TemperatureGradient::KelvinPerMillimetre),
            1.11);
}

TEST(TemperatureGradientMagnitude, XML) {
  EXPECT_EQ(TemperatureGradientMagnitude(
                1.11, Unit::TemperatureGradient::KelvinPerMetre)
                .XML(),
            "<value>1.110000000000000</value><unit>K/m</unit>");
  EXPECT_EQ(TemperatureGradientMagnitude(
                -2.22, Unit::TemperatureGradient::KelvinPerMillimetre)
                .XML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "<value>-2.220000000000000</value><unit>K/mm</unit>");
}

TEST(TemperatureGradientMagnitude, YAML) {
  EXPECT_EQ(TemperatureGradientMagnitude(
                1.11, Unit::TemperatureGradient::KelvinPerMetre)
                .YAML(),
            "{value:1.110000000000000,unit:\"K/m\"}");
  EXPECT_EQ(TemperatureGradientMagnitude(
                -2.22, Unit::TemperatureGradient::KelvinPerMillimetre)
                .YAML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{value:-2.220000000000000,unit:\"K/mm\"}");
}

TEST(TemperatureGradientMagnitude, Zero) {
  EXPECT_EQ(TemperatureGradientMagnitude::Zero(),
            TemperatureGradientMagnitude(
                0.0, Unit::TemperatureGradient::KelvinPerMetre));
}

}  // namespace

}  // namespace PhQ
