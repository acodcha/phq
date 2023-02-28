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

#include "../include/PhQ/AngularSpeed.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(AngularSpeed, Accessor) {
  const AngularSpeed angle{0.1, Unit::AngularSpeed::RadianPerSecond};
  EXPECT_DOUBLE_EQ(angle.Value(), 0.1);
  EXPECT_DOUBLE_EQ(angle.Value(Unit::AngularSpeed::DegreePerSecond),
                   0.1 * 180.0 / Pi);
}

TEST(AngularSpeed, Arithmetic) {
  const Angle angle{0.5, Unit::Angle::Radian};
  const Duration duration{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  const AngularSpeed angular_speed_0{1.0, Unit::AngularSpeed::RadianPerSecond};
  EXPECT_EQ(angular_speed_0 + angular_speed_0,
            AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(angular_speed_0 - angular_speed_0,
            AngularSpeed(0.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(angular_speed_0 * 2.0,
            AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(2.0 * angular_speed_0,
            AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(angle * frequency, angular_speed_0);
  EXPECT_EQ(frequency * angle, angular_speed_0);
  EXPECT_EQ(angular_speed_0 / 2.0,
            AngularSpeed(0.5, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(angular_speed_0 / angle, frequency);
  EXPECT_EQ(angular_speed_0 / frequency, angle);
  EXPECT_EQ(angle / duration, angular_speed_0);
  EXPECT_EQ(angle / angular_speed_0, duration);

  AngularSpeed angular_speed_1{1.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed_1 += AngularSpeed{1.0, Unit::AngularSpeed::RadianPerSecond};
  EXPECT_EQ(angular_speed_1,
            AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond));

  AngularSpeed angular_speed_2{2.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed_2 -= AngularSpeed{1.0, Unit::AngularSpeed::RadianPerSecond};
  EXPECT_EQ(angular_speed_2,
            AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));

  AngularSpeed angular_speed_3{1.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed_3 *= 2.0;
  EXPECT_EQ(angular_speed_3,
            AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond));

  AngularSpeed angular_speed_4{2.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed_4 /= 2.0;
  EXPECT_EQ(angular_speed_4,
            AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, Comparison) {
  const AngularSpeed angular_speed_0{0.1, Unit::AngularSpeed::RadianPerSecond};
  const AngularSpeed angular_speed_1{0.2, Unit::AngularSpeed::RadianPerSecond};
  EXPECT_EQ(angular_speed_0, angular_speed_0);
  EXPECT_NE(angular_speed_0, angular_speed_1);
  EXPECT_LT(angular_speed_0, angular_speed_1);
  EXPECT_GT(angular_speed_1, angular_speed_0);
  EXPECT_LE(angular_speed_0, angular_speed_0);
  EXPECT_LE(angular_speed_0, angular_speed_1);
  EXPECT_GE(angular_speed_0, angular_speed_0);
  EXPECT_GE(angular_speed_1, angular_speed_0);
}

TEST(AngularSpeed, Constructor) {
  const Angle angle{8.0, Unit::Angle::Radian};
  const Duration duration{2.0, Unit::Time::Second};
  const Frequency frequency{0.5, Unit::Frequency::Hertz};
  const AngularSpeed angular_speed_0;
  const AngularSpeed angular_speed_1{90.0, Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed angular_speed_2{4.0, Unit::AngularSpeed::RadianPerSecond};
  EXPECT_EQ(AngularSpeed(angle, duration), angular_speed_2);
  EXPECT_EQ(AngularSpeed(angle, frequency), angular_speed_2);
  EXPECT_EQ(Angle(angular_speed_2, duration), angle);
  EXPECT_EQ(Angle(angular_speed_2, frequency), angle);
  EXPECT_EQ(Duration(angular_speed_2, angle), duration);
  EXPECT_EQ(Frequency(angular_speed_2, angle), frequency);
}

TEST(AngularSpeed, Hash) {
  const AngularSpeed angular_speed_0{10.0, Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed angular_speed_1{10.000001,
                                     Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed angular_speed_2{11.0, Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed angular_speed_3{-10.0,
                                     Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed angular_speed_4{20000.0,
                                     Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed angular_speed_5{-123.456,
                                     Unit::AngularSpeed::DegreePerSecond};
  const std::hash<AngularSpeed> hasher;
  EXPECT_NE(hasher(angular_speed_0), hasher(angular_speed_1));
  EXPECT_NE(hasher(angular_speed_0), hasher(angular_speed_2));
  EXPECT_NE(hasher(angular_speed_0), hasher(angular_speed_3));
  EXPECT_NE(hasher(angular_speed_0), hasher(angular_speed_4));
  EXPECT_NE(hasher(angular_speed_0), hasher(angular_speed_5));
  const std::unordered_set<AngularSpeed> unordered{
      angular_speed_0, angular_speed_1, angular_speed_2,
      angular_speed_3, angular_speed_4, angular_speed_5};
}

TEST(AngularSpeed, Json) {
  EXPECT_EQ(AngularSpeed(1.11, Unit::AngularSpeed::RadianPerSecond).Json(),
            "{\"value\":1.110000,\"unit\":\"rad/s\"}");
  EXPECT_EQ(AngularSpeed(-5.0, Unit::AngularSpeed::DegreePerSecond)
                .Json(Unit::AngularSpeed::DegreePerSecond),
            "{\"value\":-5.000000,\"unit\":\"deg/s\"}");
}

TEST(AngularSpeed, Print) {
  EXPECT_EQ(AngularSpeed(1.11, Unit::AngularSpeed::RadianPerSecond).Print(),
            "1.110000 rad/s");
  EXPECT_EQ(AngularSpeed(-5.0, Unit::AngularSpeed::DegreePerSecond)
                .Print(Unit::AngularSpeed::DegreePerSecond),
            "-5.000000 deg/s");
}

TEST(AngularSpeed, Stream) {
  const AngularSpeed angle{1.11, Unit::AngularSpeed::RadianPerSecond};
  std::ostringstream stream;
  stream << angle;
  EXPECT_EQ(stream.str(), angle.Print());
}

TEST(AngularSpeed, Xml) {
  EXPECT_EQ(AngularSpeed(1.11, Unit::AngularSpeed::RadianPerSecond).Xml(),
            "<value>1.110000</value><unit>rad/s</unit>");
  EXPECT_EQ(AngularSpeed(-5.0, Unit::AngularSpeed::DegreePerSecond)
                .Xml(Unit::AngularSpeed::DegreePerSecond),
            "<value>-5.000000</value><unit>deg/s</unit>");
}

TEST(AngularSpeed, Yaml) {
  EXPECT_EQ(AngularSpeed(1.11, Unit::AngularSpeed::RadianPerSecond).Yaml(),
            "{value:1.110000,unit:\"rad/s\"}");
  EXPECT_EQ(AngularSpeed(-5.0, Unit::AngularSpeed::DegreePerSecond)
                .Yaml(Unit::AngularSpeed::DegreePerSecond),
            "{value:-5.000000,unit:\"deg/s\"}");
}

}  // namespace

}  // namespace PhQ
