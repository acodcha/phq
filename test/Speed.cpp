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

#include "../include/PhQ/Speed.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Speed, Accessor) {
  const Speed speed{0.1, Unit::Speed::MetrePerSecond};
  EXPECT_DOUBLE_EQ(speed.Value(), 0.1);
  EXPECT_DOUBLE_EQ(speed.Value(Unit::Speed::FootPerSecond), 0.1 / 0.3048);
}

TEST(Speed, Arithmetic) {
  const Time time{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  const Length length{0.5, Unit::Length::Metre};
  const Speed speed0{1.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(speed0 + speed0, Speed(2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(speed0 - speed0, Speed(0.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(speed0 * 2.0, Speed(2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(2.0 * speed0, Speed(2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(speed0 * time, Length(0.5, Unit::Length::Metre));
  EXPECT_EQ(length * frequency, speed0);
  EXPECT_EQ(frequency * length, speed0);
  EXPECT_EQ(speed0 / 2.0, Speed(0.5, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(speed0 / frequency, Length(0.5, Unit::Length::Metre));
  EXPECT_EQ(length / speed0, time);
  EXPECT_EQ(length / time, speed0);

  Speed speed1{1.0, Unit::Speed::MetrePerSecond};
  speed1 += Speed{1.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(speed1, Speed(2.0, Unit::Speed::MetrePerSecond));

  Speed speed2{2.0, Unit::Speed::MetrePerSecond};
  speed2 -= Speed{1.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(speed2, Speed(1.0, Unit::Speed::MetrePerSecond));

  Speed speed3{1.0, Unit::Speed::MetrePerSecond};
  speed3 *= 2.0;
  EXPECT_EQ(speed3, Speed(2.0, Unit::Speed::MetrePerSecond));

  Speed speed4{2.0, Unit::Speed::MetrePerSecond};
  speed4 /= 2.0;
  EXPECT_EQ(speed4, Speed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, Comparison) {
  const Speed speed0{0.1, Unit::Speed::MetrePerSecond};
  const Speed speed1{0.2, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(speed0, speed0);
  EXPECT_NE(speed0, speed1);
  EXPECT_LT(speed0, speed1);
  EXPECT_GT(speed1, speed0);
  EXPECT_LE(speed0, speed0);
  EXPECT_LE(speed0, speed1);
  EXPECT_GE(speed0, speed0);
  EXPECT_GE(speed1, speed0);
}

TEST(Speed, Constructor) {
  const Time time{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  const Length length{2.0, Unit::Length::Metre};
  constexpr Speed speed0;
  const Speed speed1{4.0, Unit::Speed::MetrePerSecond};
  constexpr Speed speed2{Speed::Create<Unit::Speed::MetrePerSecond>(4.0)};
  EXPECT_EQ(Speed(length, time), speed1);
  EXPECT_EQ(Speed(length, frequency), speed1);
  EXPECT_EQ(Length(speed1, time), length);
  EXPECT_EQ(Length(speed1, frequency), length);
  EXPECT_EQ(Time(speed1, length), time);
  EXPECT_EQ(Frequency(speed1, length), frequency);
}

TEST(Speed, Hash) {
  const Speed speed0{10.0, Unit::Speed::FootPerSecond};
  const Speed speed1{10.000001, Unit::Speed::FootPerSecond};
  const Speed speed2{11.0, Unit::Speed::FootPerSecond};
  const Speed speed3{-10.0, Unit::Speed::FootPerSecond};
  const Speed speed4{20000.0, Unit::Speed::FootPerSecond};
  const Speed speed5{-123.456, Unit::Speed::FootPerSecond};
  const std::hash<Speed> hasher;
  EXPECT_NE(hasher(speed0), hasher(speed1));
  EXPECT_NE(hasher(speed0), hasher(speed2));
  EXPECT_NE(hasher(speed0), hasher(speed3));
  EXPECT_NE(hasher(speed0), hasher(speed4));
  EXPECT_NE(hasher(speed0), hasher(speed5));
  const std::unordered_set<Speed> unordered{speed0, speed1, speed2,
                                            speed3, speed4, speed5};
}

TEST(Speed, Json) {
  EXPECT_EQ(Speed(1.11, Unit::Speed::MetrePerSecond).Json(),
            "{\"value\":1.110000,\"unit\":\"m/s\"}");
  EXPECT_EQ(
      Speed(-5.0, Unit::Speed::FootPerSecond).Json(Unit::Speed::FootPerSecond),
      "{\"value\":-5.000000,\"unit\":\"ft/s\"}");
}

TEST(Speed, Print) {
  EXPECT_EQ(Speed(1.11, Unit::Speed::MetrePerSecond).Print(), "1.110000 m/s");
  EXPECT_EQ(
      Speed(-5.0, Unit::Speed::FootPerSecond).Print(Unit::Speed::FootPerSecond),
      "-5.000000 ft/s");
}

TEST(Speed, Stream) {
  const Speed speed{1.11, Unit::Speed::MetrePerSecond};
  std::ostringstream stream;
  stream << speed;
  EXPECT_EQ(stream.str(), speed.Print());
}

TEST(Speed, Xml) {
  EXPECT_EQ(Speed(1.11, Unit::Speed::MetrePerSecond).Xml(),
            "<value>1.110000</value><unit>m/s</unit>");
  EXPECT_EQ(
      Speed(-5.0, Unit::Speed::FootPerSecond).Xml(Unit::Speed::FootPerSecond),
      "<value>-5.000000</value><unit>ft/s</unit>");
}

TEST(Speed, Yaml) {
  EXPECT_EQ(Speed(1.11, Unit::Speed::MetrePerSecond).Yaml(),
            "{value:1.110000,unit:\"m/s\"}");
  EXPECT_EQ(
      Speed(-5.0, Unit::Speed::FootPerSecond).Yaml(Unit::Speed::FootPerSecond),
      "{value:-5.000000,unit:\"ft/s\"}");
}

}  // namespace

}  // namespace PhQ
