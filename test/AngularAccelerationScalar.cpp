// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#include "../include/PhQ/AngularAccelerationScalar.hpp"

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

TEST(AngularAccelerationScalar, ArithmeticOperatorAddition) {
  EXPECT_EQ(AngularAccelerationScalar(1.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                + AngularAccelerationScalar(2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            AngularAccelerationScalar(3.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationScalar, ArithmeticOperatorDivision) {
  EXPECT_EQ(AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond) / 2.0,
            AngularAccelerationScalar(4.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / AngularAccelerationScalar(2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            4.0);

  EXPECT_EQ(AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
            Frequency(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / Frequency(4.0, Unit::Frequency::Hertz),
            AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond) / Time(4.0, Unit::Time::Second),
            AngularAccelerationScalar(2.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / AngularAccelerationScalar(4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            Time(2.0, Unit::Time::Second));
}

TEST(AngularAccelerationScalar, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(AngularAccelerationScalar(4.0, Unit::AngularAcceleration::RadianPerSquareSecond) * 2.0,
            AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(2.0 * AngularAccelerationScalar(4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond)
                * Frequency(2.0, Unit::Frequency::Hertz),
            AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz)
                * AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationScalar, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(AngularAccelerationScalar(3.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                - AngularAccelerationScalar(2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            AngularAccelerationScalar(1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationScalar, AssignmentOperatorAddition) {
  AngularAccelerationScalar quantity{1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity += AngularAccelerationScalar(2.0, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(
      quantity, AngularAccelerationScalar(3.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationScalar, AssignmentOperatorDivision) {
  AngularAccelerationScalar quantity{8.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity /= 2.0;
  EXPECT_EQ(
      quantity, AngularAccelerationScalar(4.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationScalar, AssignmentOperatorMultiplication) {
  AngularAccelerationScalar quantity{4.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity *= 2.0;
  EXPECT_EQ(
      quantity, AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationScalar, AssignmentOperatorSubtraction) {
  AngularAccelerationScalar quantity{3.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity -= AngularAccelerationScalar(2.0, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(
      quantity, AngularAccelerationScalar(1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationScalar, ComparisonOperators) {
  const AngularAccelerationScalar first{0.1, Unit::AngularAcceleration::RadianPerSquareSecond};
  const AngularAccelerationScalar second{0.2, Unit::AngularAcceleration::RadianPerSquareSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(AngularAccelerationScalar, CopyAssignmentOperator) {
  const AngularAccelerationScalar first{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  AngularAccelerationScalar second = AngularAccelerationScalar::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(AngularAccelerationScalar, CopyConstructor) {
  const AngularAccelerationScalar first{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  const AngularAccelerationScalar second{first};
  EXPECT_EQ(second, first);
}

TEST(AngularAccelerationScalar, Create) {
  constexpr AngularAccelerationScalar quantity =
      AngularAccelerationScalar::Create<Unit::AngularAcceleration::RadianPerSquareSecond>(1.11);
  EXPECT_EQ(
      quantity, AngularAccelerationScalar(1.11, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationScalar, DefaultConstructor) {
  EXPECT_NO_THROW(AngularAccelerationScalar{});
}

TEST(AngularAccelerationScalar, Dimensions) {
  EXPECT_EQ(AngularAccelerationScalar::Dimensions(), RelatedDimensions<Unit::AngularAcceleration>);
}

TEST(AngularAccelerationScalar, Hash) {
  const AngularAccelerationScalar first{10.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const AngularAccelerationScalar second{
      10.000001, Unit::AngularAcceleration::DegreePerSquareSecond};
  const AngularAccelerationScalar third{11.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const std::hash<AngularAccelerationScalar> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(AngularAccelerationScalar, JSON) {
  EXPECT_EQ(
      AngularAccelerationScalar(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).JSON(),
      "{\"value\":1.110000000000000,\"unit\":\"rad/s^2\"}");
  EXPECT_EQ(AngularAccelerationScalar(-2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .JSON(Unit::AngularAcceleration::DegreePerSquareSecond),
            "{\"value\":-2.220000000000000,\"unit\":\"deg/s^2\"}");
}

TEST(AngularAccelerationScalar, MiscellaneousConstructors) {
  EXPECT_EQ(AngularAccelerationScalar(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                                      Time(4.0, Unit::Time::Second)),
            AngularAccelerationScalar(2.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(AngularAccelerationScalar(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
                                      Frequency(2.0, Unit::Frequency::Hertz)),
            AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(
      AngularSpeed(AngularAccelerationScalar(4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                   Time(2.0, Unit::Time::Second)),
      AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(
      AngularSpeed(AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                   Frequency(2.0, Unit::Frequency::Hertz)),
      AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(Time(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                 AngularAccelerationScalar(4.0, Unit::AngularAcceleration::RadianPerSquareSecond)),
            Time(2.0, Unit::Time::Second));

  EXPECT_EQ(
      Frequency(AngularAccelerationScalar(8.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond)),
      Frequency(2.0, Unit::Frequency::Hertz));
}

TEST(AngularAccelerationScalar, MoveAssignmentOperator) {
  AngularAccelerationScalar first{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  AngularAccelerationScalar second = AngularAccelerationScalar::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, AngularAccelerationScalar(1.11, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationScalar, MoveConstructor) {
  AngularAccelerationScalar first{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  const AngularAccelerationScalar second{std::move(first)};
  EXPECT_EQ(
      second, AngularAccelerationScalar(1.11, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationScalar, MutableValue) {
  AngularAccelerationScalar quantity{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(AngularAccelerationScalar, Print) {
  EXPECT_EQ(
      AngularAccelerationScalar(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).Print(),
      "1.110000000000000 rad/s^2");
  EXPECT_EQ(AngularAccelerationScalar(-2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .Print(Unit::AngularAcceleration::DegreePerSquareSecond),
            "-2.220000000000000 deg/s^2");
}

TEST(AngularAccelerationScalar, SetValue) {
  AngularAccelerationScalar quantity{1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(AngularAccelerationScalar, SizeOf) {
  EXPECT_EQ(sizeof(AngularAccelerationScalar{}), sizeof(double));
}

TEST(AngularAccelerationScalar, StandardConstructor) {
  EXPECT_NO_THROW(
      AngularAccelerationScalar(1.11, Unit::AngularAcceleration::DegreePerSquareSecond));
}

TEST(AngularAccelerationScalar, StaticValue) {
  constexpr AngularAccelerationScalar quantity =
      AngularAccelerationScalar::Create<Unit::AngularAcceleration::DegreePerSquareSecond>(1.11);
  constexpr double value = quantity.StaticValue<Unit::AngularAcceleration::DegreePerSquareSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(AngularAccelerationScalar, Stream) {
  std::ostringstream stream;
  stream << AngularAccelerationScalar(1.11, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(
      stream.str(),
      AngularAccelerationScalar(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).Print());
}

TEST(AngularAccelerationScalar, Unit) {
  EXPECT_EQ(AngularAccelerationScalar::Unit(), Standard<Unit::AngularAcceleration>);
}

TEST(AngularAccelerationScalar, Value) {
  EXPECT_EQ(
      AngularAccelerationScalar(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).Value(),
      1.11);
  EXPECT_EQ(AngularAccelerationScalar(1.11, Unit::AngularAcceleration::DegreePerSquareSecond)
                .Value(Unit::AngularAcceleration::DegreePerSquareSecond),
            1.11);
}

TEST(AngularAccelerationScalar, XML) {
  EXPECT_EQ(AngularAccelerationScalar(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).XML(),
            "<value>1.110000000000000</value><unit>rad/s^2</unit>");
  EXPECT_EQ(AngularAccelerationScalar(-2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .XML(Unit::AngularAcceleration::DegreePerSquareSecond),
            "<value>-2.220000000000000</value><unit>deg/s^2</unit>");
}

TEST(AngularAccelerationScalar, YAML) {
  EXPECT_EQ(
      AngularAccelerationScalar(1.11, Unit::AngularAcceleration::RadianPerSquareSecond).YAML(),
      "{value:1.110000000000000,unit:\"rad/s^2\"}");
  EXPECT_EQ(AngularAccelerationScalar(-2.22, Unit::AngularAcceleration::DegreePerSquareSecond)
                .YAML(Unit::AngularAcceleration::DegreePerSquareSecond),
            "{value:-2.220000000000000,unit:\"deg/s^2\"}");
}

TEST(AngularAccelerationScalar, Zero) {
  EXPECT_EQ(AngularAccelerationScalar::Zero(),
            AngularAccelerationScalar(0.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

}  // namespace

}  // namespace PhQ
