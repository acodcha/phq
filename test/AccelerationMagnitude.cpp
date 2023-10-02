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

#include "../include/PhQ/AccelerationMagnitude.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(AccelerationMagnitude, ArithmeticAddition) {
  EXPECT_EQ(
      AccelerationMagnitude(1.0, Unit::Acceleration::MetrePerSquareSecond)
          + AccelerationMagnitude(
              2.0, Unit::Acceleration::MetrePerSquareSecond),
      AccelerationMagnitude(3.0, Unit::Acceleration::MetrePerSquareSecond));

  AccelerationMagnitude quantity{1.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity +=
      AccelerationMagnitude(2.0, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(quantity, AccelerationMagnitude(
                          3.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationMagnitude, ArithmeticDivision) {
  EXPECT_EQ(
      AccelerationMagnitude(8.0, Unit::Acceleration::MetrePerSquareSecond)
          / 2.0,
      AccelerationMagnitude(4.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(AccelerationMagnitude(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / AccelerationMagnitude(
                    2.0, Unit::Acceleration::MetrePerSquareSecond),
            4.0);

  EXPECT_EQ(AccelerationMagnitude(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            Speed(4.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(AccelerationMagnitude(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / Speed(2.0, Unit::Speed::MetrePerSecond),
            Frequency(4.0, Unit::Frequency::Hertz));

  EXPECT_EQ(
      Speed(8.0, Unit::Speed::MetrePerSecond) / Time(2.0, Unit::Time::Second),
      AccelerationMagnitude(4.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond)
                / AccelerationMagnitude(
                    2.0, Unit::Acceleration::MetrePerSquareSecond),
            Time(4.0, Unit::Time::Second));

  AccelerationMagnitude quantity{8.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity /= 2.0;
  EXPECT_EQ(quantity, AccelerationMagnitude(
                          4.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationMagnitude, ArithmeticMultiplication) {
  EXPECT_EQ(
      AccelerationMagnitude(4.0, Unit::Acceleration::MetrePerSquareSecond)
          * 2.0,
      AccelerationMagnitude(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(
      2.0
          * AccelerationMagnitude(
              4.0, Unit::Acceleration::MetrePerSquareSecond),
      AccelerationMagnitude(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(AccelerationMagnitude(2.0, Unit::Acceleration::MetrePerSquareSecond)
                * Time(4.0, Unit::Time::Second),
            Speed(8.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Time(2.0, Unit::Time::Second)
                * AccelerationMagnitude(
                    4.0, Unit::Acceleration::MetrePerSquareSecond),
            Speed(8.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(
      Speed(2.0, Unit::Speed::MetrePerSecond)
          * Frequency(4.0, Unit::Frequency::Hertz),
      AccelerationMagnitude(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(
      Frequency(2.0, Unit::Frequency::Hertz)
          * Speed(4.0, Unit::Speed::MetrePerSecond),
      AccelerationMagnitude(8.0, Unit::Acceleration::MetrePerSquareSecond));

  AccelerationMagnitude quantity{4.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity *= 2.0;
  EXPECT_EQ(quantity, AccelerationMagnitude(
                          8.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationMagnitude, ArithmeticSubtraction) {
  EXPECT_EQ(
      AccelerationMagnitude(3.0, Unit::Acceleration::MetrePerSquareSecond)
          - AccelerationMagnitude(
              2.0, Unit::Acceleration::MetrePerSquareSecond),
      AccelerationMagnitude(1.0, Unit::Acceleration::MetrePerSquareSecond));

  AccelerationMagnitude quantity{3.0, Unit::Acceleration::MetrePerSquareSecond};
  quantity -=
      AccelerationMagnitude(2.0, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(quantity, AccelerationMagnitude(
                          1.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationMagnitude, Comparisons) {
  const AccelerationMagnitude first{
      0.1, Unit::Acceleration::MetrePerSquareSecond};
  const AccelerationMagnitude second{
      0.2, Unit::Acceleration::MetrePerSquareSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(AccelerationMagnitude, CopyAssignment) {
  const AccelerationMagnitude first{
      1.11, Unit::Acceleration::MetrePerSquareSecond};
  AccelerationMagnitude second = AccelerationMagnitude::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(AccelerationMagnitude, CopyConstructor) {
  const AccelerationMagnitude first{
      1.11, Unit::Acceleration::MetrePerSquareSecond};
  const AccelerationMagnitude second{first};
  EXPECT_EQ(second, first);
}

TEST(Angle, Create) {
  constexpr AccelerationMagnitude quantity =
      AccelerationMagnitude::Create<Unit::Acceleration::MetrePerSquareSecond>(
          1.11);
  EXPECT_EQ(quantity, AccelerationMagnitude(
                          1.11, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(AccelerationMagnitude, DefaultConstructor) {
  EXPECT_NO_THROW(AccelerationMagnitude{});
}

TEST(AccelerationMagnitude, Dimensions) {
  EXPECT_EQ(AccelerationMagnitude::Dimensions(),
            RelatedDimensions<Unit::Acceleration>);
}

TEST(AccelerationMagnitude, Hash) {
  const AccelerationMagnitude first{
      1.11, Unit::Acceleration::FootPerSquareSecond};
  const AccelerationMagnitude second{
      1.110001, Unit::Acceleration::FootPerSquareSecond};
  const AccelerationMagnitude third{
      -1.11, Unit::Acceleration::FootPerSquareSecond};
  const std::hash<AccelerationMagnitude> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(AccelerationMagnitude, JSON) {
  EXPECT_EQ(
      AccelerationMagnitude(1.11, Unit::Acceleration::MetrePerSquareSecond)
          .JSON(),
      "{\"value\":1.110000000000000,\"unit\":\"m/s^2\"}");
  EXPECT_EQ(
      AccelerationMagnitude(-2.22, Unit::Acceleration::FootPerSquareSecond)
          .JSON(Unit::Acceleration::FootPerSquareSecond),
      "{\"value\":-2.220000000000000,\"unit\":\"ft/s^2\"}");
}

TEST(AccelerationMagnitude, MiscellaneousConstructors) {
  EXPECT_EQ(
      AccelerationMagnitude(Speed(8.0, Unit::Speed::MetrePerSecond),
                            Time(2.0, Unit::Time::Second)),
      AccelerationMagnitude(4.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(
      AccelerationMagnitude(Speed(4.0, Unit::Speed::MetrePerSecond),
                            Frequency(2.0, Unit::Frequency::Hertz)),
      AccelerationMagnitude(8.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(Speed(AccelerationMagnitude(
                      4.0, Unit::Acceleration::MetrePerSquareSecond),
                  Time(2.0, Unit::Time::Second)),
            Speed(8.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Speed(AccelerationMagnitude(
                      8.0, Unit::Acceleration::MetrePerSquareSecond),
                  Frequency(2.0, Unit::Frequency::Hertz)),
            Speed(4.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(
      Time(AccelerationMagnitude(2.0, Unit::Acceleration::MetrePerSquareSecond),
           Speed(8.0, Unit::Speed::MetrePerSecond)),
      Time(4.0, Unit::Time::Second));

  EXPECT_EQ(Frequency(AccelerationMagnitude(
                          8.0, Unit::Acceleration::MetrePerSquareSecond),
                      Speed(2.0, Unit::Speed::MetrePerSecond)),
            Frequency(4.0, Unit::Frequency::Hertz));
}

TEST(AccelerationMagnitude, MoveAssignment) {
  const AccelerationMagnitude first{
      1.11, Unit::Acceleration::MetrePerSquareSecond};
  AccelerationMagnitude second{1.11, Unit::Acceleration::MetrePerSquareSecond};
  AccelerationMagnitude third = AccelerationMagnitude::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(AccelerationMagnitude, MoveConstructor) {
  const AccelerationMagnitude first{
      1.11, Unit::Acceleration::MetrePerSquareSecond};
  AccelerationMagnitude second{1.11, Unit::Acceleration::MetrePerSquareSecond};
  AccelerationMagnitude third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(AccelerationMagnitude, MutableValue) {
  AccelerationMagnitude quantity{
      1.11, Unit::Acceleration::MetrePerSquareSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(value, 2.22);
}

TEST(AccelerationMagnitude, Print) {
  EXPECT_EQ(
      AccelerationMagnitude(1.11, Unit::Acceleration::MetrePerSquareSecond)
          .Print(),
      "1.110000000000000 m/s^2");
  EXPECT_EQ(
      AccelerationMagnitude(-2.22, Unit::Acceleration::FootPerSquareSecond)
          .Print(Unit::Acceleration::FootPerSquareSecond),
      "-2.220000000000000 ft/s^2");
}

TEST(AccelerationMagnitude, SetValue) {
  AccelerationMagnitude quantity{
      1.11, Unit::Acceleration::MetrePerSquareSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(AccelerationMagnitude, SizeOf) {
  EXPECT_EQ(sizeof(AccelerationMagnitude{}), sizeof(double));
}

TEST(AccelerationMagnitude, StandardConstructor) {
  EXPECT_NO_THROW(
      AccelerationMagnitude(1.11, Unit::Acceleration::FootPerSquareSecond));
}

TEST(AccelerationMagnitude, StaticValue) {
  constexpr AccelerationMagnitude quantity =
      AccelerationMagnitude::Create<Unit::Acceleration::FootPerSquareSecond>(
          1.11);
  constexpr double value =
      quantity.StaticValue<Unit::Acceleration::FootPerSquareSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(AccelerationMagnitude, Stream) {
  const AccelerationMagnitude quantity{
      1.11, Unit::Acceleration::MetrePerSquareSecond};
  std::ostringstream stream;
  stream << quantity;
  EXPECT_EQ(stream.str(), quantity.Print());
}

TEST(AccelerationMagnitude, Unit) {
  EXPECT_EQ(AccelerationMagnitude::Unit(), Standard<Unit::Acceleration>);
}

TEST(AccelerationMagnitude, Value) {
  EXPECT_EQ(
      AccelerationMagnitude(1.11, Unit::Acceleration::MetrePerSquareSecond)
          .Value(),
      1.11);
  EXPECT_EQ(AccelerationMagnitude(1.11, Unit::Acceleration::FootPerSquareSecond)
                .Value(Unit::Acceleration::FootPerSquareSecond),
            1.11);
}

TEST(AccelerationMagnitude, XML) {
  EXPECT_EQ(
      AccelerationMagnitude(1.11, Unit::Acceleration::MetrePerSquareSecond)
          .XML(),
      "<value>1.110000000000000</value><unit>m/s^2</unit>");
  EXPECT_EQ(
      AccelerationMagnitude(-2.22, Unit::Acceleration::FootPerSquareSecond)
          .XML(Unit::Acceleration::FootPerSquareSecond),
      "<value>-2.220000000000000</value><unit>ft/s^2</unit>");
}

TEST(AccelerationMagnitude, YAML) {
  EXPECT_EQ(
      AccelerationMagnitude(1.11, Unit::Acceleration::MetrePerSquareSecond)
          .YAML(),
      "{value:1.110000000000000,unit:\"m/s^2\"}");
  EXPECT_EQ(
      AccelerationMagnitude(-2.22, Unit::Acceleration::FootPerSquareSecond)
          .YAML(Unit::Acceleration::FootPerSquareSecond),
      "{value:-2.220000000000000,unit:\"ft/s^2\"}");
}

TEST(AccelerationMagnitude, Zero) {
  EXPECT_EQ(
      AccelerationMagnitude::Zero(),
      AccelerationMagnitude(0.0, Unit::Acceleration::MetrePerSquareSecond));
}

}  // namespace

}  // namespace PhQ
