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
  EXPECT_EQ(angle0 / angle0, 1.0);

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
  constexpr Angle angle0;
  const Angle angle1{90.0, Unit::Angle::Degree};
  constexpr Angle angle2{Angle::Create<Unit::Angle::Degree>(90.0)};
  const Value::Vector vector0{1.0, 0.0, 0.0};
  const Value::Vector vector1{0.0, 0.0, -1.0};
  EXPECT_DOUBLE_EQ(vector0.Angle(vector1).Value(), angle1.Value());
}

TEST(Angle, Copy) {
  const Angle reference{1.11, Unit::Angle::Radian};
  const Angle first{reference};
  EXPECT_EQ(first, reference);
  Angle second = Angle::Zero();
  second = reference;
  EXPECT_EQ(second, reference);
}

TEST(Angle, Dimensions) {
  EXPECT_EQ(Angle::Dimensions(), RelatedDimensions<Unit::Angle>);
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
  const std::unordered_set<Angle> unordered{
      angle0, angle1, angle2, angle3, angle4, angle5};
}

TEST(Angle, JSON) {
  EXPECT_EQ(Angle(1.11, Unit::Angle::Radian).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"rad\"}");
  EXPECT_EQ(Angle(-5.0, Unit::Angle::Degree).JSON(Unit::Angle::Degree),
            "{\"value\":-5.000000000000000,\"unit\":\"deg\"}");
}

TEST(Angle, Move) {
  const Angle reference{1.11, Unit::Angle::Radian};
  Angle first{1.11, Unit::Angle::Radian};
  Angle second{std::move(first)};
  EXPECT_EQ(second, reference);
  Angle third = Angle::Zero();
  third = std::move(second);
  EXPECT_EQ(third, reference);
}

TEST(Angle, Print) {
  EXPECT_EQ(Angle(1.11, Unit::Angle::Radian).Print(), "1.110000000000000 rad");
  EXPECT_EQ(Angle(-5.0, Unit::Angle::Degree).Print(Unit::Angle::Degree),
            "-5.000000000000000 deg");
}

TEST(Angle, SizeOf) {
  const Angle angle{1.11, Unit::Angle::Radian};
  EXPECT_EQ(sizeof(angle), sizeof(double));
}

TEST(Angle, Stream) {
  const Angle angle{1.11, Unit::Angle::Radian};
  std::ostringstream stream;
  stream << angle;
  EXPECT_EQ(stream.str(), angle.Print());
}

TEST(Angle, Unit) { EXPECT_EQ(Angle::Unit(), Standard<Unit::Angle>); }

TEST(Angle, XML) {
  EXPECT_EQ(Angle(1.11, Unit::Angle::Radian).XML(),
            "<value>1.110000000000000</value><unit>rad</unit>");
  EXPECT_EQ(Angle(-5.0, Unit::Angle::Degree).XML(Unit::Angle::Degree),
            "<value>-5.000000000000000</value><unit>deg</unit>");
}

TEST(Angle, YAML) {
  EXPECT_EQ(Angle(1.11, Unit::Angle::Radian).YAML(),
            "{value:1.110000000000000,unit:\"rad\"}");
  EXPECT_EQ(Angle(-5.0, Unit::Angle::Degree).YAML(Unit::Angle::Degree),
            "{value:-5.000000000000000,unit:\"deg\"}");
}

TEST(Angle, Zero) { EXPECT_EQ(Angle::Zero(), Angle(0.0, Unit::Angle::Radian)); }

}  // namespace

}  // namespace PhQ
