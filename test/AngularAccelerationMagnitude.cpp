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

#include "../include/PhQ/AngularAccelerationMagnitude.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(AngularAccelerationMagnitude, ArithmeticOperatorAddition) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                1.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                + AngularAccelerationMagnitude(
                    2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            AngularAccelerationMagnitude(
                3.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationMagnitude, ArithmeticOperatorDivision) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / 2.0,
            AngularAccelerationMagnitude(
                4.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(AngularAccelerationMagnitude(
                8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / AngularAccelerationMagnitude(
                    2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            4.0);

  EXPECT_EQ(AngularAccelerationMagnitude(
                8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
            Frequency(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(AngularAccelerationMagnitude(
                8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / Frequency(4.0, Unit::Frequency::Hertz),
            AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / Time(4.0, Unit::Time::Second),
            AngularAccelerationMagnitude(
                2.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / AngularAccelerationMagnitude(
                    4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            Time(2.0, Unit::Time::Second));
}

TEST(AngularAccelerationMagnitude, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                4.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                * 2.0,
            AngularAccelerationMagnitude(
                8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(2.0
                * AngularAccelerationMagnitude(
                    4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            AngularAccelerationMagnitude(
                8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond)
                * Frequency(2.0, Unit::Frequency::Hertz),
            AngularAccelerationMagnitude(
                8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz)
                * AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            AngularAccelerationMagnitude(
                8.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationMagnitude, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                3.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                - AngularAccelerationMagnitude(
                    2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            AngularAccelerationMagnitude(
                1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationMagnitude, AssignmentOperatorAddition) {
  AngularAccelerationMagnitude quantity{
      1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity += AngularAccelerationMagnitude(
      2.0, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(quantity,
            AngularAccelerationMagnitude(
                3.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationMagnitude, AssignmentOperatorDivision) {
  AngularAccelerationMagnitude quantity{
      8.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity /= 2.0;
  EXPECT_EQ(quantity,
            AngularAccelerationMagnitude(
                4.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationMagnitude, AssignmentOperatorMultiplication) {
  AngularAccelerationMagnitude quantity{
      4.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity *= 2.0;
  EXPECT_EQ(quantity,
            AngularAccelerationMagnitude(
                8.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationMagnitude, AssignmentOperatorSubtraction) {
  AngularAccelerationMagnitude quantity{
      3.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity -= AngularAccelerationMagnitude(
      2.0, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(quantity,
            AngularAccelerationMagnitude(
                1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationMagnitude, ComparisonOperators) {
  const AngularAccelerationMagnitude first{
      0.1, Unit::AngularAcceleration::RadianPerSquareSecond};
  const AngularAccelerationMagnitude second{
      0.2, Unit::AngularAcceleration::RadianPerSquareSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(AngularAccelerationMagnitude, CopyAssignmentOperator) {
  const AngularAccelerationMagnitude first{
      1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  AngularAccelerationMagnitude second = AngularAccelerationMagnitude::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(AngularAccelerationMagnitude, CopyConstructor) {
  const AngularAccelerationMagnitude first{
      1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  const AngularAccelerationMagnitude second{first};
  EXPECT_EQ(second, first);
}

TEST(AngularAccelerationMagnitude, Create) {
  constexpr AngularAccelerationMagnitude quantity =
      AngularAccelerationMagnitude::Create<
          Unit::AngularAcceleration::RadianPerSquareSecond>(1.11);
  EXPECT_EQ(quantity,
            AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationMagnitude, DefaultConstructor) {
  EXPECT_NO_THROW(AngularAccelerationMagnitude{});
}

TEST(AngularAccelerationMagnitude, Dimensions) {
  EXPECT_EQ(AngularAccelerationMagnitude::Dimensions(),
            RelatedDimensions<Unit::AngularAcceleration>);
}

TEST(AngularAccelerationMagnitude, Hash) {
  const AngularAccelerationMagnitude first{
      10.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const AngularAccelerationMagnitude second{
      10.000001, Unit::AngularAcceleration::DegreePerSquareSecond};
  const AngularAccelerationMagnitude third{
      11.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const std::hash<AngularAccelerationMagnitude> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(AngularAccelerationMagnitude, JSON) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::RadianPerSquareSecond)
                .JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"rad/s^2\"}");
  EXPECT_EQ(AngularAccelerationMagnitude(
                -2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .JSON(Unit::AngularAcceleration::DegreePerSquareSecond),
            "{\"value\":-2.220000000000000,\"unit\":\"deg/s^2\"}");
}

TEST(AngularAccelerationMagnitude, MiscellaneousConstructors) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                Time(4.0, Unit::Time::Second)),
            AngularAccelerationMagnitude(
                2.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(AngularAccelerationMagnitude(
                AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
                Frequency(2.0, Unit::Frequency::Hertz)),
            AngularAccelerationMagnitude(
                8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(
      AngularSpeed(AngularAccelerationMagnitude(
                       4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                   Time(2.0, Unit::Time::Second)),
      AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(
      AngularSpeed(AngularAccelerationMagnitude(
                       8.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                   Frequency(2.0, Unit::Frequency::Hertz)),
      AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(Time(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                 AngularAccelerationMagnitude(
                     4.0, Unit::AngularAcceleration::RadianPerSquareSecond)),
            Time(2.0, Unit::Time::Second));

  EXPECT_EQ(
      Frequency(AngularAccelerationMagnitude(
                    8.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond)),
      Frequency(2.0, Unit::Frequency::Hertz));
}

TEST(AngularAccelerationMagnitude, MoveAssignmentOperator) {
  AngularAccelerationMagnitude first{
      1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  AngularAccelerationMagnitude second = AngularAccelerationMagnitude::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, AngularAccelerationMagnitude(
                  1.11, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationMagnitude, MoveConstructor) {
  AngularAccelerationMagnitude first{
      1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  AngularAccelerationMagnitude second{std::move(first)};
  EXPECT_EQ(
      second, AngularAccelerationMagnitude(
                  1.11, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationMagnitude, MutableValue) {
  AngularAccelerationMagnitude quantity{
      1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(AngularAccelerationMagnitude, Print) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::RadianPerSquareSecond)
                .Print(),
            "1.110000000000000 rad/s^2");
  EXPECT_EQ(AngularAccelerationMagnitude(
                -2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .Print(Unit::AngularAcceleration::DegreePerSquareSecond),
            "-2.220000000000000 deg/s^2");
}

TEST(AngularAccelerationMagnitude, SetValue) {
  AngularAccelerationMagnitude quantity{
      1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(AngularAccelerationMagnitude, SizeOf) {
  EXPECT_EQ(sizeof(AngularAccelerationMagnitude{}), sizeof(double));
}

TEST(AngularAccelerationMagnitude, StandardConstructor) {
  EXPECT_NO_THROW(AngularAccelerationMagnitude(
      1.11, Unit::AngularAcceleration::DegreePerSquareSecond));
}

TEST(AngularAccelerationMagnitude, StaticValue) {
  constexpr AngularAccelerationMagnitude quantity =
      AngularAccelerationMagnitude::Create<
          Unit::AngularAcceleration::DegreePerSquareSecond>(1.11);
  constexpr double value =
      quantity.StaticValue<Unit::AngularAcceleration::DegreePerSquareSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(AngularAccelerationMagnitude, Stream) {
  std::ostringstream stream;
  stream << AngularAccelerationMagnitude(
      1.11, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(stream.str(),
            AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::RadianPerSquareSecond)
                .Print());
}

TEST(AngularAccelerationMagnitude, Unit) {
  EXPECT_EQ(AngularAccelerationMagnitude::Unit(),
            Standard<Unit::AngularAcceleration>);
}

TEST(AngularAccelerationMagnitude, Value) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::RadianPerSquareSecond)
                .Value(),
            1.11);
  EXPECT_EQ(AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::DegreePerSquareSecond)
                .Value(Unit::AngularAcceleration::DegreePerSquareSecond),
            1.11);
}

TEST(AngularAccelerationMagnitude, XML) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::RadianPerSquareSecond)
                .XML(),
            "<value>1.110000000000000</value><unit>rad/s^2</unit>");
  EXPECT_EQ(AngularAccelerationMagnitude(
                -2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .XML(Unit::AngularAcceleration::DegreePerSquareSecond),
            "<value>-2.220000000000000</value><unit>deg/s^2</unit>");
}

TEST(AngularAccelerationMagnitude, YAML) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::RadianPerSquareSecond)
                .YAML(),
            "{value:1.110000000000000,unit:\"rad/s^2\"}");
  EXPECT_EQ(AngularAccelerationMagnitude(
                -2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .YAML(Unit::AngularAcceleration::DegreePerSquareSecond),
            "{value:-2.220000000000000,unit:\"deg/s^2\"}");
}

TEST(AngularAccelerationMagnitude, Zero) {
  EXPECT_EQ(AngularAccelerationMagnitude::Zero(),
            AngularAccelerationMagnitude(
                0.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

}  // namespace

}  // namespace PhQ
