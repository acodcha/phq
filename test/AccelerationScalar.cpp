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

#include "../include/PhQ/AccelerationScalar.hpp"

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

TEST(AccelerationScalar, ArithmeticOperatorAddition) {
  EXPECT_EQ(AccelerationScalar(1.0, Unit::Acceleration::MetrePerSquareSecond)
                + AccelerationScalar(2.0, Unit::Acceleration::MetrePerSquareSecond),
            AccelerationScalar(3.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationScalar, ArithmeticOperatorDivision) {
  EXPECT_EQ(AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond) / 2.0,
            AccelerationScalar(4.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / AccelerationScalar(2.0, Unit::Acceleration::MetrePerSquareSecond),
            4.0);

  EXPECT_EQ(AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            Speed(4.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / Speed(2.0, Unit::Speed::MetrePerSecond),
            Frequency(4.0, Unit::Frequency::Hertz));

  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond) / Time(2.0, Unit::Time::Second),
            AccelerationScalar(4.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond)
                / AccelerationScalar(2.0, Unit::Acceleration::MetrePerSquareSecond),
            Time(4.0, Unit::Time::Second));
}

TEST(AccelerationScalar, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(AccelerationScalar(4.0, Unit::Acceleration::MetrePerSquareSecond) * 2.0,
            AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(2.0 * AccelerationScalar(4.0, Unit::Acceleration::MetrePerSquareSecond),
            AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(AccelerationScalar(2.0, Unit::Acceleration::MetrePerSquareSecond)
                * Time(4.0, Unit::Time::Second),
            Speed(8.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Time(2.0, Unit::Time::Second)
                * AccelerationScalar(4.0, Unit::Acceleration::MetrePerSquareSecond),
            Speed(8.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Speed(2.0, Unit::Speed::MetrePerSecond) * Frequency(4.0, Unit::Frequency::Hertz),
            AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(Frequency(2.0, Unit::Frequency::Hertz) * Speed(4.0, Unit::Speed::MetrePerSecond),
            AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationScalar, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(AccelerationScalar(3.0, Unit::Acceleration::MetrePerSquareSecond)
                - AccelerationScalar(2.0, Unit::Acceleration::MetrePerSquareSecond),
            AccelerationScalar(1.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationScalar, AssignmentOperatorAddition) {
  AccelerationScalar quantity{1.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity += AccelerationScalar(2.0, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(quantity, AccelerationScalar(3.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationScalar, AssignmentOperatorDivision) {
  AccelerationScalar quantity{8.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity /= 2.0;
  EXPECT_EQ(quantity, AccelerationScalar(4.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationScalar, AssignmentOperatorMultiplication) {
  AccelerationScalar quantity{4.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity *= 2.0;
  EXPECT_EQ(quantity, AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationScalar, AssignmentOperatorSubtraction) {
  AccelerationScalar quantity{3.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity -= AccelerationScalar(2.0, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(quantity, AccelerationScalar(1.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationScalar, ComparisonOperators) {
  const AccelerationScalar first{0.1, Unit::Acceleration::MetrePerSquareSecond};
  const AccelerationScalar second{0.2, Unit::Acceleration::MetrePerSquareSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(AccelerationScalar, CopyAssignmentOperator) {
  const AccelerationScalar first{1.11, Unit::Acceleration::MetrePerSquareSecond};
  AccelerationScalar second = AccelerationScalar::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(AccelerationScalar, CopyConstructor) {
  const AccelerationScalar first{1.11, Unit::Acceleration::MetrePerSquareSecond};
  const AccelerationScalar second{first};
  EXPECT_EQ(second, first);
}

TEST(Angle, Create) {
  constexpr AccelerationScalar quantity =
      AccelerationScalar::Create<Unit::Acceleration::MetrePerSquareSecond>(1.11);
  EXPECT_EQ(quantity, AccelerationScalar(1.11, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationScalar, DefaultConstructor) {
  EXPECT_NO_THROW(AccelerationScalar{});
}

TEST(AccelerationScalar, Dimensions) {
  EXPECT_EQ(AccelerationScalar::Dimensions(), RelatedDimensions<Unit::Acceleration>);
}

TEST(AccelerationScalar, Hash) {
  const AccelerationScalar first{1.11, Unit::Acceleration::FootPerSquareSecond};
  const AccelerationScalar second{1.110001, Unit::Acceleration::FootPerSquareSecond};
  const AccelerationScalar third{-1.11, Unit::Acceleration::FootPerSquareSecond};
  const std::hash<AccelerationScalar> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(AccelerationScalar, JSON) {
  EXPECT_EQ(AccelerationScalar(1.11, Unit::Acceleration::MetrePerSquareSecond).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"m/s^2\"}");
  EXPECT_EQ(AccelerationScalar(-2.22, Unit::Acceleration::FootPerSquareSecond)
                .JSON(Unit::Acceleration::FootPerSquareSecond),
            "{\"value\":-2.220000000000000,\"unit\":\"ft/s^2\"}");
}

TEST(AccelerationScalar, MiscellaneousConstructors) {
  EXPECT_EQ(
      AccelerationScalar(Speed(8.0, Unit::Speed::MetrePerSecond), Time(2.0, Unit::Time::Second)),
      AccelerationScalar(4.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(AccelerationScalar(
                Speed(4.0, Unit::Speed::MetrePerSecond), Frequency(2.0, Unit::Frequency::Hertz)),
            AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(Speed(AccelerationScalar(4.0, Unit::Acceleration::MetrePerSquareSecond),
                  Time(2.0, Unit::Time::Second)),
            Speed(8.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Speed(AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond),
                  Frequency(2.0, Unit::Frequency::Hertz)),
            Speed(4.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Time(Speed(8.0, Unit::Speed::MetrePerSecond),
                 AccelerationScalar(2.0, Unit::Acceleration::MetrePerSquareSecond)),
            Time(4.0, Unit::Time::Second));

  EXPECT_EQ(Frequency(AccelerationScalar(8.0, Unit::Acceleration::MetrePerSquareSecond),
                      Speed(2.0, Unit::Speed::MetrePerSecond)),
            Frequency(4.0, Unit::Frequency::Hertz));
}

TEST(AccelerationScalar, MoveAssignmentOperator) {
  AccelerationScalar first{1.11, Unit::Acceleration::MetrePerSquareSecond};
  AccelerationScalar second = AccelerationScalar::Zero();
  second = std::move(first);
  EXPECT_EQ(second, AccelerationScalar(1.11, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationScalar, MoveConstructor) {
  AccelerationScalar first{1.11, Unit::Acceleration::MetrePerSquareSecond};
  const AccelerationScalar second{std::move(first)};
  EXPECT_EQ(second, AccelerationScalar(1.11, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationScalar, MutableValue) {
  AccelerationScalar quantity{1.11, Unit::Acceleration::MetrePerSquareSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(AccelerationScalar, Print) {
  EXPECT_EQ(AccelerationScalar(1.11, Unit::Acceleration::MetrePerSquareSecond).Print(),
            "1.110000000000000 m/s^2");
  EXPECT_EQ(AccelerationScalar(-2.22, Unit::Acceleration::FootPerSquareSecond)
                .Print(Unit::Acceleration::FootPerSquareSecond),
            "-2.220000000000000 ft/s^2");
}

TEST(AccelerationScalar, SetValue) {
  AccelerationScalar quantity{1.11, Unit::Acceleration::MetrePerSquareSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(AccelerationScalar, SizeOf) {
  EXPECT_EQ(sizeof(AccelerationScalar{}), sizeof(double));
}

TEST(AccelerationScalar, StandardConstructor) {
  EXPECT_NO_THROW(AccelerationScalar(1.11, Unit::Acceleration::FootPerSquareSecond));
}

TEST(AccelerationScalar, StaticValue) {
  constexpr AccelerationScalar quantity =
      AccelerationScalar::Create<Unit::Acceleration::FootPerSquareSecond>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Acceleration::FootPerSquareSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(AccelerationScalar, Stream) {
  std::ostringstream stream;
  stream << AccelerationScalar(1.11, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(
      stream.str(), AccelerationScalar(1.11, Unit::Acceleration::MetrePerSquareSecond).Print());
}

TEST(AccelerationScalar, Unit) {
  EXPECT_EQ(AccelerationScalar::Unit(), Standard<Unit::Acceleration>);
}

TEST(AccelerationScalar, Value) {
  EXPECT_EQ(AccelerationScalar(1.11, Unit::Acceleration::MetrePerSquareSecond).Value(), 1.11);
  EXPECT_EQ(AccelerationScalar(1.11, Unit::Acceleration::FootPerSquareSecond)
                .Value(Unit::Acceleration::FootPerSquareSecond),
            1.11);
}

TEST(AccelerationScalar, XML) {
  EXPECT_EQ(AccelerationScalar(1.11, Unit::Acceleration::MetrePerSquareSecond).XML(),
            "<value>1.110000000000000</value><unit>m/s^2</unit>");
  EXPECT_EQ(AccelerationScalar(-2.22, Unit::Acceleration::FootPerSquareSecond)
                .XML(Unit::Acceleration::FootPerSquareSecond),
            "<value>-2.220000000000000</value><unit>ft/s^2</unit>");
}

TEST(AccelerationScalar, YAML) {
  EXPECT_EQ(AccelerationScalar(1.11, Unit::Acceleration::MetrePerSquareSecond).YAML(),
            "{value:1.110000000000000,unit:\"m/s^2\"}");
  EXPECT_EQ(AccelerationScalar(-2.22, Unit::Acceleration::FootPerSquareSecond)
                .YAML(Unit::Acceleration::FootPerSquareSecond),
            "{value:-2.220000000000000,unit:\"ft/s^2\"}");
}

TEST(AccelerationScalar, Zero) {
  EXPECT_EQ(AccelerationScalar::Zero(),
            AccelerationScalar(0.0, Unit::Acceleration::MetrePerSquareSecond));
}

}  // namespace

}  // namespace PhQ
