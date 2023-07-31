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

#include <unordered_set>

namespace PhQ {

namespace {

TEST(AccelerationMagnitude, Accessor) {
  const AccelerationMagnitude acceleration{
      0.1, Unit::Acceleration::MetrePerSquareSecond};
  EXPECT_DOUBLE_EQ(acceleration.Value(), 0.1);
  EXPECT_DOUBLE_EQ(acceleration.Value(Unit::Acceleration::FootPerSquareSecond),
                   0.1 / 0.3048);
}

TEST(AccelerationMagnitude, Arithmetic) {
  const Time time0p5{0.5, Unit::Time::Second};
  const Frequency frequency2{2.0, Unit::Frequency::Hertz};
  const Speed speed2{2.0, Unit::Speed::MetrePerSecond};
  const AccelerationMagnitude acceleration0{
      0.0, Unit::Acceleration::MetrePerSquareSecond};
  const AccelerationMagnitude acceleration4{
      4.0, Unit::Acceleration::MetrePerSquareSecond};
  const AccelerationMagnitude acceleration8{
      8.0, Unit::Acceleration::MetrePerSquareSecond};
  EXPECT_EQ(acceleration4 + acceleration4, acceleration8);
  EXPECT_EQ(acceleration4 - acceleration4, acceleration0);
  EXPECT_EQ(acceleration4 * 2.0, acceleration8);
  EXPECT_EQ(2.0 * acceleration4, acceleration8);
  EXPECT_EQ(acceleration4 * time0p5, speed2);
  EXPECT_EQ(speed2 * frequency2, acceleration4);
  EXPECT_EQ(frequency2 * speed2, acceleration4);
  EXPECT_EQ(acceleration8 / 2.0, acceleration4);
  EXPECT_EQ(acceleration4 / frequency2, speed2);
  EXPECT_EQ(speed2 / acceleration4, time0p5);
  EXPECT_EQ(speed2 / time0p5, acceleration4);
  EXPECT_EQ(acceleration4 / acceleration4, 1.0);

  AccelerationMagnitude a{acceleration4};
  a += acceleration4;
  EXPECT_EQ(a, acceleration8);

  AccelerationMagnitude b{acceleration4};
  b -= acceleration4;
  EXPECT_EQ(b, acceleration0);

  AccelerationMagnitude c{acceleration4};
  c *= 2.0;
  EXPECT_EQ(c, acceleration8);

  AccelerationMagnitude d{acceleration8};
  d /= 2.0;
  EXPECT_EQ(d, acceleration4);
}

TEST(AccelerationMagnitude, Comparison) {
  const AccelerationMagnitude acceleration0{
      0.1, Unit::Acceleration::MetrePerSquareSecond};
  const AccelerationMagnitude acceleration1{
      0.2, Unit::Acceleration::MetrePerSquareSecond};
  EXPECT_EQ(acceleration0, acceleration0);
  EXPECT_NE(acceleration0, acceleration1);
  EXPECT_LT(acceleration0, acceleration1);
  EXPECT_GT(acceleration1, acceleration0);
  EXPECT_LE(acceleration0, acceleration0);
  EXPECT_LE(acceleration0, acceleration1);
  EXPECT_GE(acceleration0, acceleration0);
  EXPECT_GE(acceleration1, acceleration0);
}

TEST(AccelerationMagnitude, Constructor) {
  const Time time{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  const Speed speed{2.0, Unit::Speed::MetrePerSecond};
  constexpr AccelerationMagnitude acceleration0;
  const AccelerationMagnitude acceleration1{
      4.0, Unit::Acceleration::MetrePerSquareSecond};
  constexpr AccelerationMagnitude acceleration2{
      AccelerationMagnitude::Create<Unit::Acceleration::MetrePerSquareSecond>(
          4.0)};
  EXPECT_EQ(AccelerationMagnitude(speed, time), acceleration1);
  EXPECT_EQ(AccelerationMagnitude(speed, frequency), acceleration1);
  EXPECT_EQ(Speed(acceleration1, time), speed);
  EXPECT_EQ(Speed(acceleration1, frequency), speed);
  EXPECT_EQ(Time(acceleration1, speed), time);
  EXPECT_EQ(Frequency(acceleration1, speed), frequency);
}

TEST(AccelerationMagnitude, Hash) {
  const AccelerationMagnitude acceleration0{
      10.0, Unit::Acceleration::FootPerSquareSecond};
  const AccelerationMagnitude acceleration1{
      10.000001, Unit::Acceleration::FootPerSquareSecond};
  const AccelerationMagnitude acceleration2{
      11.0, Unit::Acceleration::FootPerSquareSecond};
  const AccelerationMagnitude acceleration3{
      -10.0, Unit::Acceleration::FootPerSquareSecond};
  const AccelerationMagnitude acceleration4{
      20000.0, Unit::Acceleration::FootPerSquareSecond};
  const AccelerationMagnitude acceleration5{
      -123.456, Unit::Acceleration::FootPerSquareSecond};
  const std::hash<AccelerationMagnitude> hasher;
  EXPECT_NE(hasher(acceleration0), hasher(acceleration1));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration2));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration3));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration4));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration5));
  const std::unordered_set<AccelerationMagnitude> unordered{
      acceleration0, acceleration1, acceleration2,
      acceleration3, acceleration4, acceleration5};
}

TEST(AccelerationMagnitude, JSON) {
  EXPECT_EQ(
      AccelerationMagnitude(1.11, Unit::Acceleration::MetrePerSquareSecond)
          .JSON(),
      "{\"value\":1.110000,\"unit\":\"m/s^2\"}");
  EXPECT_EQ(AccelerationMagnitude(-5.0, Unit::Acceleration::FootPerSquareSecond)
                .JSON(Unit::Acceleration::FootPerSquareSecond),
            "{\"value\":-5.000000,\"unit\":\"ft/s^2\"}");
}

TEST(AccelerationMagnitude, Print) {
  EXPECT_EQ(
      AccelerationMagnitude(1.11, Unit::Acceleration::MetrePerSquareSecond)
          .Print(),
      "1.110000 m/s^2");
  EXPECT_EQ(AccelerationMagnitude(-5.0, Unit::Acceleration::FootPerSquareSecond)
                .Print(Unit::Acceleration::FootPerSquareSecond),
            "-5.000000 ft/s^2");
}

TEST(AccelerationMagnitude, Stream) {
  const AccelerationMagnitude acceleration{
      1.11, Unit::Acceleration::MetrePerSquareSecond};
  std::ostringstream stream;
  stream << acceleration;
  EXPECT_EQ(stream.str(), acceleration.Print());
}

TEST(AccelerationMagnitude, XML) {
  EXPECT_EQ(
      AccelerationMagnitude(1.11, Unit::Acceleration::MetrePerSquareSecond)
          .XML(),
      "<value>1.110000</value><unit>m/s^2</unit>");
  EXPECT_EQ(AccelerationMagnitude(-5.0, Unit::Acceleration::FootPerSquareSecond)
                .XML(Unit::Acceleration::FootPerSquareSecond),
            "<value>-5.000000</value><unit>ft/s^2</unit>");
}

TEST(AccelerationMagnitude, YAML) {
  EXPECT_EQ(
      AccelerationMagnitude(1.11, Unit::Acceleration::MetrePerSquareSecond)
          .YAML(),
      "{value:1.110000,unit:\"m/s^2\"}");
  EXPECT_EQ(AccelerationMagnitude(-5.0, Unit::Acceleration::FootPerSquareSecond)
                .YAML(Unit::Acceleration::FootPerSquareSecond),
            "{value:-5.000000,unit:\"ft/s^2\"}");
}

TEST(AccelerationMagnitude, Zero) {
  EXPECT_EQ(
      AccelerationMagnitude::Zero(),
      AccelerationMagnitude(0.0, Unit::Acceleration::MetrePerSquareSecond));
}

}  // namespace

}  // namespace PhQ
