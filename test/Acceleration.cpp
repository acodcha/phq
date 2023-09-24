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

#include "../include/PhQ/Acceleration.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Acceleration, Accessor) {
  const Acceleration acceleration{
      {1.0, 2.0, 4.0},
      Unit::Acceleration::MetrePerSquareSecond
  };
  EXPECT_DOUBLE_EQ(acceleration.Value().x(), 1.0);
  EXPECT_DOUBLE_EQ(acceleration.Value().y(), 2.0);
  EXPECT_DOUBLE_EQ(acceleration.Value().z(), 4.0);
  EXPECT_DOUBLE_EQ(
      acceleration.Value(Unit::Acceleration::FootPerSquareSecond).x(),
      1.0 / 0.3048);
  EXPECT_DOUBLE_EQ(
      acceleration.Value(Unit::Acceleration::FootPerSquareSecond).y(),
      2.0 / 0.3048);
  EXPECT_DOUBLE_EQ(
      acceleration.Value(Unit::Acceleration::FootPerSquareSecond).z(),
      4.0 / 0.3048);
}

TEST(Acceleration, AngleAndMagnitude) {
  const Acceleration acceleration0{
      {0.0, 2.0, 0.0},
      Unit::Acceleration::MetrePerSquareSecond
  };
  const Acceleration acceleration1{
      {0.0, 0.0, 4.0},
      Unit::Acceleration::MetrePerSquareSecond
  };
  EXPECT_DOUBLE_EQ(
      acceleration0.Angle(acceleration1).Value(Unit::Angle::Degree), 90.0);
  EXPECT_DOUBLE_EQ(acceleration0.Magnitude().Value(), 2.0);
}

TEST(Acceleration, Arithmetic) {
  const AccelerationMagnitude magnitude{
      2.0, Unit::Acceleration::MetrePerSquareSecond};
  const Direction direction{0.0, -1.0, 0.0};
  const Time time{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  const Velocity velocity{
      {0.5, 1.0, 2.0},
      Unit::Speed::MetrePerSecond
  };
  const Acceleration acceleration0{
      {0.0, 0.0, 0.0},
      Unit::Acceleration::MetrePerSquareSecond
  };
  const Acceleration acceleration1{
      {1.0, 2.0, 4.0},
      Unit::Acceleration::MetrePerSquareSecond
  };
  const Acceleration acceleration2{
      {2.0, 4.0, 8.0},
      Unit::Acceleration::MetrePerSquareSecond
  };
  EXPECT_EQ(acceleration1 + acceleration1, acceleration2);
  EXPECT_EQ(acceleration1 - acceleration1, acceleration0);
  EXPECT_EQ(acceleration1 * 2.0, acceleration2);
  EXPECT_EQ(2.0 * acceleration1, acceleration2);
  EXPECT_EQ(
      direction * magnitude,
      Acceleration({0.0, -2.0, 0.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(
      magnitude * direction,
      Acceleration({0.0, -2.0, 0.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(acceleration1 * time, velocity);
  EXPECT_EQ(time * acceleration1, velocity);
  EXPECT_EQ(velocity * frequency, acceleration1);
  EXPECT_EQ(acceleration2 / 2.0, acceleration1);
  EXPECT_EQ(acceleration1 / frequency, velocity);
  EXPECT_EQ(velocity / time, acceleration1);

  Acceleration acceleration3{acceleration1};
  acceleration3 += acceleration1;
  EXPECT_EQ(acceleration3, acceleration2);

  Acceleration acceleration4{acceleration1};
  acceleration4 -= acceleration1;
  EXPECT_EQ(acceleration4, acceleration0);

  Acceleration acceleration5{acceleration1};
  acceleration5 *= 2.0;
  EXPECT_EQ(acceleration5, acceleration2);

  Acceleration acceleration6{acceleration2};
  acceleration6 /= 2.0;
  EXPECT_EQ(acceleration6, acceleration1);
}

TEST(Acceleration, Comparison) {
  const Acceleration acceleration0{
      {1.0, 2.0, 4.0},
      Unit::Acceleration::MetrePerSquareSecond
  };
  const Acceleration acceleration1{
      {1.0, 2.0, 8.0},
      Unit::Acceleration::MetrePerSquareSecond
  };
  EXPECT_EQ(acceleration0, acceleration0);
  EXPECT_NE(acceleration0, acceleration1);
  EXPECT_LT(acceleration0, acceleration1);
  EXPECT_GT(acceleration1, acceleration0);
  EXPECT_LE(acceleration0, acceleration0);
  EXPECT_LE(acceleration0, acceleration1);
  EXPECT_GE(acceleration0, acceleration0);
  EXPECT_GE(acceleration1, acceleration0);
}

TEST(Acceleration, Constructor) {
  constexpr Acceleration acceleration0{};
  const Acceleration acceleration1{
      {1.0, 2.0, 4.0},
      Unit::Acceleration::FootPerSquareSecond
  };
  const Acceleration acceleration2{
      {-1.0, -2.0, -4.0},
      Unit::Acceleration::FootPerSquareSecond
  };
  constexpr Acceleration acceleration3{
      Acceleration::Create<Unit::Acceleration::FootPerSquareSecond>(
          {-1.0, -2.0, -4.0})};
  const Direction direction{acceleration1};
  const Angle angle{acceleration1, acceleration2};
  const AccelerationMagnitude magnitude{acceleration1};
  const Time time{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  const Velocity velocity0{acceleration1, time};
  const Velocity velocity1{acceleration1, frequency};
}

TEST(Acceleration, Copy) {
  const Acceleration reference{
      {1.11, 2.22, 3.33},
      Unit::Acceleration::MetrePerSquareSecond
  };
  const Acceleration first{reference};
  EXPECT_EQ(first, reference);
  Acceleration second = Acceleration::Zero();
  second = reference;
  EXPECT_EQ(second, reference);
}

TEST(Acceleration, Dimensions) {
  EXPECT_EQ(Acceleration::Dimensions(), RelatedDimensions<Unit::Acceleration>);
}

TEST(Acceleration, Hash) {
  const Acceleration acceleration0{
      {1.0, 2.0, 4.0},
      Unit::Acceleration::FootPerSquareSecond
  };
  const Acceleration acceleration1{
      {1.0, 2.000001, 4.0},
      Unit::Acceleration::FootPerSquareSecond
  };
  const Acceleration acceleration2{
      {1.0, 2.0, 5.0},
      Unit::Acceleration::FootPerSquareSecond
  };
  const Acceleration acceleration3{
      {1.0, 2.0, -4.0},
      Unit::Acceleration::FootPerSquareSecond
  };
  const Acceleration acceleration4{
      {1000000.0, 2000000.0, 4000000.0},
      Unit::Acceleration::FootPerSquareSecond
  };
  const Acceleration acceleration5{
      {-1.0, -2.0, -4.0},
      Unit::Acceleration::FootPerSquareSecond
  };
  const std::hash<Acceleration> hasher;
  EXPECT_NE(hasher(acceleration0), hasher(acceleration1));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration2));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration3));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration4));
  EXPECT_NE(hasher(acceleration0), hasher(acceleration5));
  const std::unordered_set<Acceleration> unordered{
      acceleration0, acceleration1, acceleration2,
      acceleration3, acceleration4, acceleration5};
}

TEST(Acceleration, JSON) {
  EXPECT_EQ(
      Acceleration({1.11, 2.22, 4.44}, Unit::Acceleration::MetrePerSquareSecond)
          .JSON(),
      "{\"value\":{\"x\":1.110000000000000,\"y\":2.220000000000000,\"z\":4."
      "440000000000000},\"unit\":\"m/s^2\"}");
  EXPECT_EQ(
      Acceleration({0.0, -5.5, 0.0}, Unit::Acceleration::FootPerSquareSecond)
          .JSON(Unit::Acceleration::FootPerSquareSecond),
      "{\"value\":{\"x\":0,\"y\":-5.500000000000000,\"z\":0},\"unit\":\"ft/"
      "s^2\"}");
}

TEST(Acceleration, Move) {
  const Acceleration reference{
      {1.11, 2.22, 4.44},
      Unit::Acceleration::MetrePerSquareSecond
  };
  Acceleration first{
      {1.11, 2.22, 4.44},
      Unit::Acceleration::MetrePerSquareSecond
  };
  Acceleration second{std::move(first)};
  EXPECT_EQ(second, reference);
  Acceleration third = Acceleration::Zero();
  third = std::move(second);
  EXPECT_EQ(third, reference);
}

TEST(Acceleration, Print) {
  EXPECT_EQ(
      Acceleration({1.11, 2.22, 4.44}, Unit::Acceleration::MetrePerSquareSecond)
          .Print(),
      "(1.110000000000000, 2.220000000000000, 4.440000000000000) m/s^2");
  EXPECT_EQ(
      Acceleration({0.0, -5.5, 0.0}, Unit::Acceleration::FootPerSquareSecond)
          .Print(Unit::Acceleration::FootPerSquareSecond),
      "(0, -5.500000000000000, 0) ft/s^2");
}

TEST(Acceleration, SizeOf) {
  const Acceleration acceleration{
      {1.11, 2.22, 4.44},
      Unit::Acceleration::MetrePerSquareSecond
  };
  EXPECT_EQ(sizeof(acceleration), 3 * sizeof(double));
}

TEST(Acceleration, Stream) {
  const Acceleration acceleration{
      {1.11, 2.22, 4.44},
      Unit::Acceleration::MetrePerSquareSecond
  };
  std::ostringstream stream;
  stream << acceleration;
  EXPECT_EQ(stream.str(), acceleration.Print());
}

TEST(Acceleration, Unit) {
  EXPECT_EQ(Acceleration::Unit(), Standard<Unit::Acceleration>);
}

TEST(Acceleration, XML) {
  EXPECT_EQ(
      Acceleration({1.11, 2.22, 4.44}, Unit::Acceleration::MetrePerSquareSecond)
          .XML(),
      "<value><x>1.110000000000000</x><y>2.220000000000000</"
      "y><z>4.440000000000000</z></value><unit>m/s^2</unit>");
  EXPECT_EQ(
      Acceleration({0.0, -5.5, 0.0}, Unit::Acceleration::FootPerSquareSecond)
          .XML(Unit::Acceleration::FootPerSquareSecond),
      "<value><x>0</x><y>-5.500000000000000</y><z>0</z></value><unit>ft/s^2</"
      "unit>");
}

TEST(Acceleration, YAML) {
  EXPECT_EQ(
      Acceleration({1.11, 2.22, 4.44}, Unit::Acceleration::MetrePerSquareSecond)
          .YAML(),
      "{value:{x:1.110000000000000,y:2.220000000000000,z:4.440000000000000},"
      "unit:\"m/s^2\"}");
  EXPECT_EQ(
      Acceleration({0.0, -5.5, 0.0}, Unit::Acceleration::FootPerSquareSecond)
          .YAML(Unit::Acceleration::FootPerSquareSecond),
      "{value:{x:0,y:-5.500000000000000,z:0},unit:\"ft/s^2\"}");
}

TEST(Acceleration, Zero) {
  EXPECT_EQ(
      Acceleration::Zero(),
      Acceleration({0.0, 0.0, 0.0}, Unit::Acceleration::MetrePerSquareSecond));
}

}  // namespace

}  // namespace PhQ
