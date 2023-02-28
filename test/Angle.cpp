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

#include "../include/PhQ/Angle.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Angle, Accessor) {
  const Angle angle{0.1, Unit::Angle::Radian};
  EXPECT_DOUBLE_EQ(angle.Value(), 0.1);
  EXPECT_DOUBLE_EQ(angle.Value(Unit::Angle::Degree), 0.1 * 180.0 / Pi);
}

TEST(Angle, Arithmetic) {
  const Angle angle0{1.0, Unit::Angle::Radian};
  EXPECT_EQ(angle0 + angle0, Angle(2.0, Unit::Angle::Radian));
  EXPECT_EQ(angle0 - angle0, Angle(0.0, Unit::Angle::Radian));
  EXPECT_EQ(angle0 * 2.0, Angle(2.0, Unit::Angle::Radian));
  EXPECT_EQ(2.0 * angle0, Angle(2.0, Unit::Angle::Radian));
  EXPECT_EQ(angle0 / 2.0, Angle(0.5, Unit::Angle::Radian));

  Angle angle1{1.0, Unit::Angle::Radian};
  angle1 += Angle{1.0, Unit::Angle::Radian};
  EXPECT_EQ(angle1, Angle(2.0, Unit::Angle::Radian));

  Angle angle2{2.0, Unit::Angle::Radian};
  angle2 -= Angle{1.0, Unit::Angle::Radian};
  EXPECT_EQ(angle2, Angle(1.0, Unit::Angle::Radian));

  Angle angle3{1.0, Unit::Angle::Radian};
  angle3 *= 2.0;
  EXPECT_EQ(angle3, Angle(2.0, Unit::Angle::Radian));

  Angle angle4{2.0, Unit::Angle::Radian};
  angle4 /= 2.0;
  EXPECT_EQ(angle4, Angle(1.0, Unit::Angle::Radian));
}

TEST(Angle, Comparison) {
  const Angle angle0{0.1, Unit::Angle::Radian};
  const Angle angle1{0.2, Unit::Angle::Radian};
  EXPECT_EQ(angle0, angle0);
  EXPECT_NE(angle0, angle1);
  EXPECT_LT(angle0, angle1);
  EXPECT_GT(angle1, angle0);
  EXPECT_LE(angle0, angle0);
  EXPECT_LE(angle0, angle1);
  EXPECT_GE(angle0, angle0);
  EXPECT_GE(angle1, angle0);
}

TEST(Angle, Constructor) {
  const Angle angle0;
  const Angle angle1{90.0, Unit::Angle::Degree};
}

TEST(Angle, Hash) {
  const Angle angle0{10.0, Unit::Angle::Degree};
  const Angle angle1{10.000001, Unit::Angle::Degree};
  const Angle angle2{11.0, Unit::Angle::Degree};
  const Angle angle3{-10.0, Unit::Angle::Degree};
  const Angle angle4{20000.0, Unit::Angle::Degree};
  const Angle angle5{-123.456, Unit::Angle::Degree};
  const std::hash<Angle> hasher;
  EXPECT_NE(hasher(angle0), hasher(angle1));
  EXPECT_NE(hasher(angle0), hasher(angle2));
  EXPECT_NE(hasher(angle0), hasher(angle3));
  EXPECT_NE(hasher(angle0), hasher(angle4));
  EXPECT_NE(hasher(angle0), hasher(angle5));
  const std::unordered_set<Angle> unordered{angle0, angle1, angle2,
                                            angle3, angle4, angle5};
}

TEST(Angle, Json) {
  EXPECT_EQ(Angle(1.11, Unit::Angle::Radian).Json(),
            "{\"value\":1.110000,\"unit\":\"rad\"}");
  EXPECT_EQ(Angle(-5.0, Unit::Angle::Degree).Json(Unit::Angle::Degree),
            "{\"value\":-5.000000,\"unit\":\"deg\"}");
}

TEST(Angle, Print) {
  EXPECT_EQ(Angle(1.11, Unit::Angle::Radian).Print(), "1.110000 rad");
  EXPECT_EQ(Angle(-5.0, Unit::Angle::Degree).Print(Unit::Angle::Degree),
            "-5.000000 deg");
}

TEST(Angle, Stream) {
  const Angle angle{1.11, Unit::Angle::Radian};
  std::ostringstream stream;
  stream << angle;
  EXPECT_EQ(stream.str(), angle.Print());
}

TEST(Angle, Xml) {
  EXPECT_EQ(Angle(1.11, Unit::Angle::Radian).Xml(),
            "<value>1.110000</value><unit>rad</unit>");
  EXPECT_EQ(Angle(-5.0, Unit::Angle::Degree).Xml(Unit::Angle::Degree),
            "<value>-5.000000</value><unit>deg</unit>");
}

TEST(Angle, Yaml) {
  EXPECT_EQ(Angle(1.11, Unit::Angle::Radian).Yaml(),
            "{value:1.110000,unit:\"rad\"}");
  EXPECT_EQ(Angle(-5.0, Unit::Angle::Degree).Yaml(Unit::Angle::Degree),
            "{value:-5.000000,unit:\"deg\"}");
}

}  // namespace

}  // namespace PhQ
