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

#include "../include/PhQ/ScalarAngularAcceleration.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/AngularSpeed.hpp"
#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/AngularAcceleration.hpp"
#include "../include/PhQ/Unit/AngularSpeed.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(ScalarAngularAcceleration, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                + ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            ScalarAngularAcceleration(3.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond) / 2.0,
            ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            4.0);

  EXPECT_EQ(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
            Frequency(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / Frequency(4.0, Unit::Frequency::Hertz),
            AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond) / Time(4.0, Unit::Time::Second),
            ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            Time(2.0, Unit::Time::Second));
}

TEST(ScalarAngularAcceleration, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond) * 2.0,
            ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(2.0 * ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond)
                * Frequency(2.0, Unit::Frequency::Hertz),
            ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz)
                * AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarAngularAcceleration(3.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                - ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, AssignmentOperatorAddition) {
  ScalarAngularAcceleration quantity{1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity += ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(
      quantity, ScalarAngularAcceleration(3.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, AssignmentOperatorDivision) {
  ScalarAngularAcceleration quantity{8.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity /= 2.0;
  EXPECT_EQ(
      quantity, ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, AssignmentOperatorMultiplication) {
  ScalarAngularAcceleration quantity{4.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity *= 2.0;
  EXPECT_EQ(
      quantity, ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, AssignmentOperatorSubtraction) {
  ScalarAngularAcceleration quantity{3.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity -= ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(
      quantity, ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, ComparisonOperators) {
  const ScalarAngularAcceleration first{0.1, Unit::AngularAcceleration::RadianPerSquareSecond};
  const ScalarAngularAcceleration second{0.2, Unit::AngularAcceleration::RadianPerSquareSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarAngularAcceleration, CopyAssignmentOperator) {
  const ScalarAngularAcceleration first{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  ScalarAngularAcceleration second = ScalarAngularAcceleration::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ScalarAngularAcceleration, CopyConstructor) {
  const ScalarAngularAcceleration first{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  const ScalarAngularAcceleration second{first};
  EXPECT_EQ(second, first);
}

TEST(ScalarAngularAcceleration, Create) {
  constexpr ScalarAngularAcceleration quantity =
      ScalarAngularAcceleration::Create<Unit::AngularAcceleration::RadianPerSquareSecond>(1.11);
  EXPECT_EQ(
      quantity, ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarAngularAcceleration{});
}

TEST(ScalarAngularAcceleration, Dimensions) {
  EXPECT_EQ(ScalarAngularAcceleration::Dimensions(), RelatedDimensions<Unit::AngularAcceleration>);
}

TEST(ScalarAngularAcceleration, Hash) {
  const ScalarAngularAcceleration first{10.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const ScalarAngularAcceleration second{
      10.000001, Unit::AngularAcceleration::DegreePerSquareSecond};
  const ScalarAngularAcceleration third{11.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const std::hash<ScalarAngularAcceleration> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarAngularAcceleration, JSON) {
  EXPECT_EQ(
      ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).JSON(),
      "{\"value\":1.110000000000000,\"unit\":\"rad/s^2\"}");
  EXPECT_EQ(ScalarAngularAcceleration(-2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .JSON(Unit::AngularAcceleration::DegreePerSquareSecond),
            "{\"value\":-2.220000000000000,\"unit\":\"deg/s^2\"}");
}

TEST(ScalarAngularAcceleration, MiscellaneousConstructors) {
  EXPECT_EQ(ScalarAngularAcceleration(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                                      Time(4.0, Unit::Time::Second)),
            ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(ScalarAngularAcceleration(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
                                      Frequency(2.0, Unit::Frequency::Hertz)),
            ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(
      AngularSpeed(ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                   Time(2.0, Unit::Time::Second)),
      AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(
      AngularSpeed(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                   Frequency(2.0, Unit::Frequency::Hertz)),
      AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(Time(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                 ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond)),
            Time(2.0, Unit::Time::Second));

  EXPECT_EQ(
      Frequency(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond)),
      Frequency(2.0, Unit::Frequency::Hertz));
}

TEST(ScalarAngularAcceleration, MoveAssignmentOperator) {
  ScalarAngularAcceleration first{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  ScalarAngularAcceleration second = ScalarAngularAcceleration::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, MoveConstructor) {
  ScalarAngularAcceleration first{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  const ScalarAngularAcceleration second{std::move(first)};
  EXPECT_EQ(
      second, ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, MutableValue) {
  ScalarAngularAcceleration quantity{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ScalarAngularAcceleration, Print) {
  EXPECT_EQ(
      ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).Print(),
      "1.110000000000000 rad/s^2");
  EXPECT_EQ(ScalarAngularAcceleration(-2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .Print(Unit::AngularAcceleration::DegreePerSquareSecond),
            "-2.220000000000000 deg/s^2");
}

TEST(ScalarAngularAcceleration, SetValue) {
  ScalarAngularAcceleration quantity{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ScalarAngularAcceleration, SizeOf) {
  EXPECT_EQ(sizeof(ScalarAngularAcceleration{}), sizeof(double));
}

TEST(ScalarAngularAcceleration, StandardConstructor) {
  EXPECT_NO_THROW(
      ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::DegreePerSquareSecond));
}

TEST(ScalarAngularAcceleration, StaticValue) {
  constexpr ScalarAngularAcceleration quantity =
      ScalarAngularAcceleration::Create<Unit::AngularAcceleration::DegreePerSquareSecond>(1.11);
  constexpr double value = quantity.StaticValue<Unit::AngularAcceleration::DegreePerSquareSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(ScalarAngularAcceleration, Stream) {
  std::ostringstream stream;
  stream << ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(
      stream.str(),
      ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).Print());
}

TEST(ScalarAngularAcceleration, Unit) {
  EXPECT_EQ(ScalarAngularAcceleration::Unit(), Standard<Unit::AngularAcceleration>);
}

TEST(ScalarAngularAcceleration, Value) {
  EXPECT_EQ(
      ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).Value(),
      1.11);
  EXPECT_EQ(ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::DegreePerSquareSecond)
                .Value(Unit::AngularAcceleration::DegreePerSquareSecond),
            1.11);
}

TEST(ScalarAngularAcceleration, XML) {
  EXPECT_EQ(ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).XML(),
            "<value>1.110000000000000</value><unit>rad/s^2</unit>");
  EXPECT_EQ(ScalarAngularAcceleration(-2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .XML(Unit::AngularAcceleration::DegreePerSquareSecond),
            "<value>-2.220000000000000</value><unit>deg/s^2</unit>");
}

TEST(ScalarAngularAcceleration, YAML) {
  EXPECT_EQ(
      ScalarAngularAcceleration(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).YAML(),
      "{value:1.110000000000000,unit:\"rad/s^2\"}");
  EXPECT_EQ(ScalarAngularAcceleration(-2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .YAML(Unit::AngularAcceleration::DegreePerSquareSecond),
            "{value:-2.220000000000000,unit:\"deg/s^2\"}");
}

TEST(ScalarAngularAcceleration, Zero) {
  EXPECT_EQ(ScalarAngularAcceleration::Zero(),
            ScalarAngularAcceleration(0.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

}  // namespace

}  // namespace PhQ
