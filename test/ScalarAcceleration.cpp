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

#include "../include/PhQ/ScalarAcceleration.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Speed.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Acceleration.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Speed.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(ScalarAcceleration, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond)
                + ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond),
            ScalarAcceleration(3.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond) / 2.0,
            ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond),
            4.0);

  EXPECT_EQ(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            Speed(4.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / Speed(2.0, Unit::Speed::MetrePerSecond),
            Frequency(4.0, Unit::Frequency::Hertz));

  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond) / Time(2.0, Unit::Time::Second),
            ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond)
                / ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond),
            Time(4.0, Unit::Time::Second));
}

TEST(ScalarAcceleration, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond) * 2.0,
            ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(2.0 * ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond),
            ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond)
                * Time(4.0, Unit::Time::Second),
            Speed(8.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Time(2.0, Unit::Time::Second)
                * ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond),
            Speed(8.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Speed(2.0, Unit::Speed::MetrePerSecond) * Frequency(4.0, Unit::Frequency::Hertz),
            ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(Frequency(2.0, Unit::Frequency::Hertz) * Speed(4.0, Unit::Speed::MetrePerSecond),
            ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarAcceleration(3.0, Unit::Acceleration::MetrePerSquareSecond)
                - ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond),
            ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, AssignmentOperatorAddition) {
  ScalarAcceleration quantity{1.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity += ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(quantity, ScalarAcceleration(3.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, AssignmentOperatorDivision) {
  ScalarAcceleration quantity{8.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, AssignmentOperatorMultiplication) {
  ScalarAcceleration quantity{4.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, AssignmentOperatorSubtraction) {
  ScalarAcceleration quantity{3.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity -= ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(quantity, ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, ComparisonOperators) {
  const ScalarAcceleration first{0.1, Unit::Acceleration::MetrePerSquareSecond};
  const ScalarAcceleration second{0.2, Unit::Acceleration::MetrePerSquareSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarAcceleration, CopyAssignmentOperator) {
  const ScalarAcceleration first{1.11, Unit::Acceleration::MetrePerSquareSecond};
  ScalarAcceleration second = ScalarAcceleration::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ScalarAcceleration, CopyConstructor) {
  const ScalarAcceleration first{1.11, Unit::Acceleration::MetrePerSquareSecond};
  const ScalarAcceleration second{first};
  EXPECT_EQ(second, first);
}

TEST(Angle, Create) {
  constexpr ScalarAcceleration quantity =
      ScalarAcceleration::Create<Unit::Acceleration::MetrePerSquareSecond>(1.11);
  EXPECT_EQ(quantity, ScalarAcceleration(1.11, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarAcceleration{});
}

TEST(ScalarAcceleration, Dimensions) {
  EXPECT_EQ(ScalarAcceleration::Dimensions(), RelatedDimensions<Unit::Acceleration>);
}

TEST(ScalarAcceleration, Hash) {
  const ScalarAcceleration first{1.11, Unit::Acceleration::FootPerSquareSecond};
  const ScalarAcceleration second{1.110001, Unit::Acceleration::FootPerSquareSecond};
  const ScalarAcceleration third{-1.11, Unit::Acceleration::FootPerSquareSecond};
  const std::hash<ScalarAcceleration> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarAcceleration, JSON) {
  EXPECT_EQ(ScalarAcceleration(1.11, Unit::Acceleration::MetrePerSquareSecond).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"m/s^2\"}");
  EXPECT_EQ(ScalarAcceleration(-2.22, Unit::Acceleration::FootPerSquareSecond)
                .JSON(Unit::Acceleration::FootPerSquareSecond),
            "{\"value\":-2.220000000000000,\"unit\":\"ft/s^2\"}");
}

TEST(ScalarAcceleration, MiscellaneousConstructors) {
  EXPECT_EQ(
      ScalarAcceleration(Speed(8.0, Unit::Speed::MetrePerSecond), Time(2.0, Unit::Time::Second)),
      ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(ScalarAcceleration(
                Speed(4.0, Unit::Speed::MetrePerSecond), Frequency(2.0, Unit::Frequency::Hertz)),
            ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(Speed(ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond),
                  Time(2.0, Unit::Time::Second)),
            Speed(8.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Speed(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond),
                  Frequency(2.0, Unit::Frequency::Hertz)),
            Speed(4.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Time(Speed(8.0, Unit::Speed::MetrePerSecond),
                 ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond)),
            Time(4.0, Unit::Time::Second));

  EXPECT_EQ(Frequency(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond),
                      Speed(2.0, Unit::Speed::MetrePerSecond)),
            Frequency(4.0, Unit::Frequency::Hertz));
}

TEST(ScalarAcceleration, MoveAssignmentOperator) {
  ScalarAcceleration first{1.11, Unit::Acceleration::MetrePerSquareSecond};
  ScalarAcceleration second = ScalarAcceleration::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarAcceleration(1.11, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, MoveConstructor) {
  ScalarAcceleration first{1.11, Unit::Acceleration::MetrePerSquareSecond};
  const ScalarAcceleration second{std::move(first)};
  EXPECT_EQ(second, ScalarAcceleration(1.11, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, MutableValue) {
  ScalarAcceleration quantity{1.11, Unit::Acceleration::MetrePerSquareSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ScalarAcceleration, Print) {
  EXPECT_EQ(ScalarAcceleration(1.11, Unit::Acceleration::MetrePerSquareSecond).Print(),
            "1.110000000000000 m/s^2");
  EXPECT_EQ(ScalarAcceleration(-2.22, Unit::Acceleration::FootPerSquareSecond)
                .Print(Unit::Acceleration::FootPerSquareSecond),
            "-2.220000000000000 ft/s^2");
}

TEST(ScalarAcceleration, SetValue) {
  ScalarAcceleration quantity{1.11, Unit::Acceleration::MetrePerSquareSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ScalarAcceleration, SizeOf) {
  EXPECT_EQ(sizeof(ScalarAcceleration{}), sizeof(double));
}

TEST(ScalarAcceleration, StandardConstructor) {
  EXPECT_NO_THROW(ScalarAcceleration(1.11, Unit::Acceleration::FootPerSquareSecond));
}

TEST(ScalarAcceleration, StaticValue) {
  constexpr ScalarAcceleration quantity =
      ScalarAcceleration::Create<Unit::Acceleration::FootPerSquareSecond>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Acceleration::FootPerSquareSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(ScalarAcceleration, Stream) {
  std::ostringstream stream;
  stream << ScalarAcceleration(1.11, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(
      stream.str(), ScalarAcceleration(1.11, Unit::Acceleration::MetrePerSquareSecond).Print());
}

TEST(ScalarAcceleration, Unit) {
  EXPECT_EQ(ScalarAcceleration::Unit(), Standard<Unit::Acceleration>);
}

TEST(ScalarAcceleration, Value) {
  EXPECT_EQ(ScalarAcceleration(1.11, Unit::Acceleration::MetrePerSquareSecond).Value(), 1.11);
  EXPECT_EQ(ScalarAcceleration(1.11, Unit::Acceleration::FootPerSquareSecond)
                .Value(Unit::Acceleration::FootPerSquareSecond),
            1.11);
}

TEST(ScalarAcceleration, XML) {
  EXPECT_EQ(ScalarAcceleration(1.11, Unit::Acceleration::MetrePerSquareSecond).XML(),
            "<value>1.110000000000000</value><unit>m/s^2</unit>");
  EXPECT_EQ(ScalarAcceleration(-2.22, Unit::Acceleration::FootPerSquareSecond)
                .XML(Unit::Acceleration::FootPerSquareSecond),
            "<value>-2.220000000000000</value><unit>ft/s^2</unit>");
}

TEST(ScalarAcceleration, YAML) {
  EXPECT_EQ(ScalarAcceleration(1.11, Unit::Acceleration::MetrePerSquareSecond).YAML(),
            "{value:1.110000000000000,unit:\"m/s^2\"}");
  EXPECT_EQ(ScalarAcceleration(-2.22, Unit::Acceleration::FootPerSquareSecond)
                .YAML(Unit::Acceleration::FootPerSquareSecond),
            "{value:-2.220000000000000,unit:\"ft/s^2\"}");
}

TEST(ScalarAcceleration, Zero) {
  EXPECT_EQ(ScalarAcceleration::Zero(),
            ScalarAcceleration(0.0, Unit::Acceleration::MetrePerSquareSecond));
}

}  // namespace

}  // namespace PhQ
