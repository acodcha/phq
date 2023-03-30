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

#include <unordered_set>

namespace PhQ {

namespace {

TEST(AngularAccelerationMagnitude, Accessor) {
  const AngularAccelerationMagnitude acceleration{
      0.1, Unit::AngularAcceleration::RadianPerSquareSecond};
  EXPECT_DOUBLE_EQ(acceleration.Value(), 0.1);
  EXPECT_DOUBLE_EQ(
      acceleration.Value(Unit::AngularAcceleration::DegreePerSquareSecond),
      0.1 * 180.0 / Pi);
}

TEST(AngularAccelerationMagnitude, Arithmetic) {
  const AngularSpeed speed{0.5, Unit::AngularSpeed::RadianPerSecond};
  const Time time{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  const AngularAccelerationMagnitude acceleration0{
      1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  EXPECT_EQ(acceleration0 + acceleration0,
            AngularAccelerationMagnitude(
                2.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  EXPECT_EQ(acceleration0 - acceleration0,
            AngularAccelerationMagnitude(
                0.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  EXPECT_EQ(acceleration0 * 2.0,
            AngularAccelerationMagnitude(
                2.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  EXPECT_EQ(2.0 * acceleration0,
            AngularAccelerationMagnitude(
                2.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  EXPECT_EQ(speed * frequency, acceleration0);
  EXPECT_EQ(frequency * speed, acceleration0);
  EXPECT_EQ(acceleration0 / 2.0,
            AngularAccelerationMagnitude(
                0.5, Unit::AngularAcceleration::RadianPerSquareSecond));
  EXPECT_EQ(acceleration0 / speed, frequency);
  EXPECT_EQ(acceleration0 / frequency, speed);
  EXPECT_EQ(speed / time, acceleration0);
  EXPECT_EQ(speed / acceleration0, time);

  AngularAccelerationMagnitude acceleration1{
      1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  acceleration1 += AngularAccelerationMagnitude{
      1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  EXPECT_EQ(acceleration1,
            AngularAccelerationMagnitude(
                2.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  AngularAccelerationMagnitude acceleration2{
      2.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  acceleration2 -= AngularAccelerationMagnitude{
      1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  EXPECT_EQ(acceleration2,
            AngularAccelerationMagnitude(
                1.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  AngularAccelerationMagnitude acceleration3{
      1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  acceleration3 *= 2.0;
  EXPECT_EQ(acceleration3,
            AngularAccelerationMagnitude(
                2.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  AngularAccelerationMagnitude acceleration4{
      2.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  acceleration4 /= 2.0;
  EXPECT_EQ(acceleration4,
            AngularAccelerationMagnitude(
                1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(AngularAccelerationMagnitude, Comparison) {
  const AngularAccelerationMagnitude acceleration0{
      0.1, Unit::AngularAcceleration::RadianPerSquareSecond};
  const AngularAccelerationMagnitude acceleration1{
      0.2, Unit::AngularAcceleration::RadianPerSquareSecond};
  EXPECT_EQ(acceleration0, acceleration0);
  EXPECT_NE(acceleration0, acceleration1);
  EXPECT_LT(acceleration0, acceleration1);
  EXPECT_GT(acceleration1, acceleration0);
  EXPECT_LE(acceleration0, acceleration0);
  EXPECT_LE(acceleration0, acceleration1);
  EXPECT_GE(acceleration0, acceleration0);
  EXPECT_GE(acceleration1, acceleration0);
}

TEST(AngularAccelerationMagnitude, Constructor) {
  const AngularSpeed speed{8.0, Unit::AngularSpeed::RadianPerSecond};
  const Time time{2.0, Unit::Time::Second};
  const Frequency frequency{0.5, Unit::Frequency::Hertz};
  constexpr AngularAccelerationMagnitude acceleration0;
  const AngularAccelerationMagnitude acceleration1{
      90.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const AngularAccelerationMagnitude acceleration2{
      4.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  constexpr AngularAccelerationMagnitude acceleration3{
      AngularAccelerationMagnitude::Create<
          Unit::AngularAcceleration::DegreePerSquareSecond>(90.0)};
  EXPECT_EQ(AngularAccelerationMagnitude(speed, time), acceleration2);
  EXPECT_EQ(AngularAccelerationMagnitude(speed, frequency), acceleration2);
  EXPECT_EQ(AngularSpeed(acceleration2, time), speed);
  EXPECT_EQ(AngularSpeed(acceleration2, frequency), speed);
  EXPECT_EQ(Time(acceleration2, speed), time);
  EXPECT_EQ(Frequency(acceleration2, speed), frequency);
}

TEST(AngularAccelerationMagnitude, Hash) {
  const AngularAccelerationMagnitude acceleration0{
      10.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const AngularAccelerationMagnitude acceleration1{
      10.000001, Unit::AngularAcceleration::DegreePerSquareSecond};
  const AngularAccelerationMagnitude acceleration2{
      11.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const AngularAccelerationMagnitude acceleration3{
      -10.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const AngularAccelerationMagnitude acceleration4{
      20000.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const AngularAccelerationMagnitude acceleration5{
      -123.456, Unit::AngularAcceleration::DegreePerSquareSecond};
  const std::hash<AngularAccelerationMagnitude> hasher;
  EXPECT_NE(hasher(acceleration0), hasher(acceleration1));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration2));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration3));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration4));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration5));
  const std::unordered_set<AngularAccelerationMagnitude> unordered{
      acceleration0, acceleration1, acceleration2,
      acceleration3, acceleration4, acceleration5};
}

TEST(AngularAccelerationMagnitude, JSON) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::RadianPerSquareSecond)
                .JSON(),
            "{\"value\":1.110000,\"unit\":\"rad/s^2\"}");
  EXPECT_EQ(AngularAccelerationMagnitude(
                -5.0, Unit::AngularAcceleration::DegreePerSquareSecond)
                .JSON(Unit::AngularAcceleration::DegreePerSquareSecond),
            "{\"value\":-5.000000,\"unit\":\"deg/s^2\"}");
}

TEST(AngularAccelerationMagnitude, Print) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::RadianPerSquareSecond)
                .Print(),
            "1.110000 rad/s^2");
  EXPECT_EQ(AngularAccelerationMagnitude(
                -5.0, Unit::AngularAcceleration::DegreePerSquareSecond)
                .Print(Unit::AngularAcceleration::DegreePerSquareSecond),
            "-5.000000 deg/s^2");
}

TEST(AngularAccelerationMagnitude, Stream) {
  const AngularAccelerationMagnitude acceleration{
      1.11, Unit::AngularAcceleration::RadianPerSquareSecond};
  std::ostringstream stream;
  stream << acceleration;
  EXPECT_EQ(stream.str(), acceleration.Print());
}

TEST(AngularAccelerationMagnitude, XML) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::RadianPerSquareSecond)
                .XML(),
            "<value>1.110000</value><unit>rad/s^2</unit>");
  EXPECT_EQ(AngularAccelerationMagnitude(
                -5.0, Unit::AngularAcceleration::DegreePerSquareSecond)
                .XML(Unit::AngularAcceleration::DegreePerSquareSecond),
            "<value>-5.000000</value><unit>deg/s^2</unit>");
}

TEST(AngularAccelerationMagnitude, YAML) {
  EXPECT_EQ(AngularAccelerationMagnitude(
                1.11, Unit::AngularAcceleration::RadianPerSquareSecond)
                .YAML(),
            "{value:1.110000,unit:\"rad/s^2\"}");
  EXPECT_EQ(AngularAccelerationMagnitude(
                -5.0, Unit::AngularAcceleration::DegreePerSquareSecond)
                .YAML(Unit::AngularAcceleration::DegreePerSquareSecond),
            "{value:-5.000000,unit:\"deg/s^2\"}");
}

}  // namespace

}  // namespace PhQ
