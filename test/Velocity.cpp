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

#include "../include/PhQ/Velocity.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Velocity, Accessor) {
  const Velocity velocity{{1.0, 2.0, 4.0}, Unit::Speed::MetrePerSecond};
  EXPECT_DOUBLE_EQ(velocity.Value().x(), 1.0);
  EXPECT_DOUBLE_EQ(velocity.Value().y(), 2.0);
  EXPECT_DOUBLE_EQ(velocity.Value().z(), 4.0);
  EXPECT_DOUBLE_EQ(velocity.Value(Unit::Speed::FootPerSecond).x(),
                   1.0 / 0.3048);
  EXPECT_DOUBLE_EQ(velocity.Value(Unit::Speed::FootPerSecond).y(),
                   2.0 / 0.3048);
  EXPECT_DOUBLE_EQ(velocity.Value(Unit::Speed::FootPerSecond).z(),
                   4.0 / 0.3048);
}

TEST(Velocity, AngleAndMagnitude) {
  const Velocity velocity0{{0.0, 2.0, 0.0}, Unit::Speed::MetrePerSecond};
  const Velocity velocity1{{0.0, 0.0, 4.0}, Unit::Speed::MetrePerSecond};
  EXPECT_DOUBLE_EQ(velocity0.Angle(velocity1).Value(Unit::Angle::Degree), 90.0);
  EXPECT_DOUBLE_EQ(velocity0.Magnitude().Value(), 2.0);
}

TEST(Velocity, Arithmetic) {
  const Speed speed{2.0, Unit::Speed::MetrePerSecond};
  const Direction direction{0.0, -1.0, 0.0};
  const Time time{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  const Displacement displacement{{0.5, 1.0, 2.0}, Unit::Length::Metre};
  const Velocity velocity0{{0.0, 0.0, 0.0}, Unit::Speed::MetrePerSecond};
  const Velocity velocity1{{1.0, 2.0, 4.0}, Unit::Speed::MetrePerSecond};
  const Velocity velocity2{{2.0, 4.0, 8.0}, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(velocity1 + velocity1, velocity2);
  EXPECT_EQ(velocity1 - velocity1, velocity0);
  EXPECT_EQ(velocity1 * 2.0, velocity2);
  EXPECT_EQ(2.0 * velocity1, velocity2);
  EXPECT_EQ(direction * speed,
            Velocity({0.0, -2.0, 0.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(speed * direction,
            Velocity({0.0, -2.0, 0.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(velocity1 * time, displacement);
  EXPECT_EQ(time * velocity1, displacement);
  EXPECT_EQ(velocity2 / 2.0, velocity1);
  EXPECT_EQ(velocity1 / frequency, displacement);

  Velocity velocity3{velocity1};
  velocity3 += velocity1;
  EXPECT_EQ(velocity3, velocity2);

  Velocity velocity4{velocity1};
  velocity4 -= velocity1;
  EXPECT_EQ(velocity4, velocity0);

  Velocity velocity5{velocity1};
  velocity5 *= 2.0;
  EXPECT_EQ(velocity5, velocity2);

  Velocity velocity6{velocity2};
  velocity6 /= 2.0;
  EXPECT_EQ(velocity6, velocity1);
}

TEST(Velocity, Comparison) {
  const Velocity velocity0{{1.0, 2.0, 4.0}, Unit::Speed::MetrePerSecond};
  const Velocity velocity1{{1.0, 2.0, -4.0}, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(velocity0, velocity0);
  EXPECT_NE(velocity0, velocity1);
}

TEST(Velocity, Constructor) {
  constexpr Velocity velocity0;
  const Velocity velocity1{{1.0, 2.0, 4.0}, Unit::Speed::FootPerSecond};
  const Velocity velocity2{{-1.0, -2.0, -4.0}, Unit::Speed::FootPerSecond};
  constexpr Velocity velocity3{
      Velocity::Create<Unit::Speed::FootPerSecond>({-1.0, -2.0, -4.0})};
  const Direction direction{velocity1};
  const Angle angle{velocity1, velocity2};
  const Speed speed{velocity1};
  const Time time{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  const Displacement displacement0{velocity1, time};
  const Displacement displacement1{velocity1, frequency};
}

TEST(Velocity, Hash) {
  const Velocity velocity0{{1.0, 2.0, 4.0}, Unit::Speed::FootPerSecond};
  const Velocity velocity1{{1.0, 2.000001, 4.0}, Unit::Speed::FootPerSecond};
  const Velocity velocity2{{1.0, 2.0, 5.0}, Unit::Speed::FootPerSecond};
  const Velocity velocity3{{1.0, 2.0, -4.0}, Unit::Speed::FootPerSecond};
  const Velocity velocity4{{1000000.0, 2000000.0, 4000000.0},
                           Unit::Speed::FootPerSecond};
  const Velocity velocity5{{-1.0, -2.0, -4.0}, Unit::Speed::FootPerSecond};
  const std::hash<Velocity> hasher;
  EXPECT_NE(hasher(velocity0), hasher(velocity1));
  EXPECT_NE(hasher(velocity0), hasher(velocity2));
  EXPECT_NE(hasher(velocity0), hasher(velocity3));
  EXPECT_NE(hasher(velocity0), hasher(velocity4));
  EXPECT_NE(hasher(velocity0), hasher(velocity5));
  const std::unordered_set<Velocity> unordered{velocity0, velocity1, velocity2,
                                               velocity3, velocity4, velocity5};
}

TEST(Velocity, Json) {
  EXPECT_EQ(Velocity({1.11, 2.22, 4.44}, Unit::Speed::MetrePerSecond).Json(),
            "{\"value\":{\"x\":1.110000,\"y\":2.220000,\"z\":4.440000},"
            "\"unit\":\"m/s\"}");
  EXPECT_EQ(Velocity({0.0, -5.0, 0.0}, Unit::Speed::FootPerSecond)
                .Json(Unit::Speed::FootPerSecond),
            "{\"value\":{\"x\":0,\"y\":-5.000000,\"z\":0},\"unit\":\"ft/s\"}");
}

TEST(Velocity, Print) {
  EXPECT_EQ(Velocity({1.11, 2.22, 4.44}, Unit::Speed::MetrePerSecond).Print(),
            "(1.110000, 2.220000, 4.440000) m/s");
  EXPECT_EQ(Velocity({0.0, -5.0, 0.0}, Unit::Speed::FootPerSecond)
                .Print(Unit::Speed::FootPerSecond),
            "(0, -5.000000, 0) ft/s");
}

TEST(Velocity, Stream) {
  const Velocity velocity{{1.11, 2.22, 4.44}, Unit::Speed::MetrePerSecond};
  std::ostringstream stream;
  stream << velocity;
  EXPECT_EQ(stream.str(), velocity.Print());
}

TEST(Velocity, Xml) {
  EXPECT_EQ(Velocity({1.11, 2.22, 4.44}, Unit::Speed::MetrePerSecond).Xml(),
            "<value><x>1.110000</x><y>2.220000</y><z>4.440000</z></"
            "value><unit>m/s</unit>");
  EXPECT_EQ(Velocity({0.0, -5.0, 0.0}, Unit::Speed::FootPerSecond)
                .Xml(Unit::Speed::FootPerSecond),
            "<value><x>0</x><y>-5.000000</y><z>0</z></value><unit>ft/s</unit>");
}

TEST(Velocity, Yaml) {
  EXPECT_EQ(Velocity({1.11, 2.22, 4.44}, Unit::Speed::MetrePerSecond).Yaml(),
            "{value:{x:1.110000,y:2.220000,z:4.440000},unit:\"m/s\"}");
  EXPECT_EQ(Velocity({0.0, -5.0, 0.0}, Unit::Speed::FootPerSecond)
                .Yaml(Unit::Speed::FootPerSecond),
            "{value:{x:0,y:-5.000000,z:0},unit:\"ft/s\"}");
}

}  // namespace

}  // namespace PhQ
