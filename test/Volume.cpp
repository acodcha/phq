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

#include "../include/PhQ/Volume.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Volume, Accessor) {
  const Volume volume{0.1, Unit::Volume::CubicMetre};
  EXPECT_DOUBLE_EQ(volume.Value(), 0.1);
  EXPECT_DOUBLE_EQ(
      volume.Value(Unit::Volume::CubicMillimetre), 0.1 * 1000000000.0);
}

TEST(Volume, Arithmetic) {
  const Length length{2.0, Unit::Length::Metre};
  const Area area{0.5, Unit::Area::SquareMetre};
  const Volume volume0{1.0, Unit::Volume::CubicMetre};
  EXPECT_EQ(volume0 + volume0, Volume(2.0, Unit::Volume::CubicMetre));
  EXPECT_EQ(volume0 - volume0, Volume(0.0, Unit::Volume::CubicMetre));
  EXPECT_EQ(volume0 * 2.0, Volume(2.0, Unit::Volume::CubicMetre));
  EXPECT_EQ(2.0 * volume0, Volume(2.0, Unit::Volume::CubicMetre));
  EXPECT_EQ(length * area, volume0);
  EXPECT_EQ(area * length, volume0);
  EXPECT_EQ(volume0 / 2.0, Volume(0.5, Unit::Volume::CubicMetre));
  EXPECT_EQ(volume0 / length, area);
  EXPECT_EQ(volume0 / area, length);
  EXPECT_EQ(volume0 / volume0, 1.0);

  Volume volume1{1.0, Unit::Volume::CubicMetre};
  volume1 += Volume{1.0, Unit::Volume::CubicMetre};
  EXPECT_EQ(volume1, Volume(2.0, Unit::Volume::CubicMetre));

  Volume volume2{2.0, Unit::Volume::CubicMetre};
  volume2 -= Volume{1.0, Unit::Volume::CubicMetre};
  EXPECT_EQ(volume2, Volume(1.0, Unit::Volume::CubicMetre));

  Volume volume3{1.0, Unit::Volume::CubicMetre};
  volume3 *= 2.0;
  EXPECT_EQ(volume3, Volume(2.0, Unit::Volume::CubicMetre));

  Volume volume4{2.0, Unit::Volume::CubicMetre};
  volume4 /= 2.0;
  EXPECT_EQ(volume4, Volume(1.0, Unit::Volume::CubicMetre));
}

TEST(Volume, Comparison) {
  const Volume volume0{0.1, Unit::Volume::CubicMetre};
  const Volume volume1{0.2, Unit::Volume::CubicMetre};
  EXPECT_EQ(volume0, volume0);
  EXPECT_NE(volume0, volume1);
  EXPECT_LT(volume0, volume1);
  EXPECT_GT(volume1, volume0);
  EXPECT_LE(volume0, volume0);
  EXPECT_LE(volume0, volume1);
  EXPECT_GE(volume0, volume0);
  EXPECT_GE(volume1, volume0);
}

TEST(Volume, Constructor) {
  constexpr Volume volume0;
  const Volume volume1{100.0, Unit::Volume::CubicMillimetre};
  constexpr Volume volume2{
      Volume::Create<Unit::Volume::CubicMillimetre>(100.0)};
}

TEST(Volume, Copy) {
  const Volume reference{1.11, Unit::Volume::CubicMetre};
  const Volume first{reference};
  EXPECT_EQ(first, reference);
  Volume second = Volume::Zero();
  second = reference;
  EXPECT_EQ(second, reference);
}

TEST(Volume, Dimensions) {
  EXPECT_EQ(Volume::Dimensions(), RelatedDimensions<Unit::Volume>);
}

TEST(Volume, Hash) {
  const Volume volume0{10.0, Unit::Volume::CubicMetre};
  const Volume volume1{10.000001, Unit::Volume::CubicMetre};
  const Volume volume2{11.0, Unit::Volume::CubicMetre};
  const Volume volume3{-10.0, Unit::Volume::CubicMetre};
  const Volume volume4{20000.0, Unit::Volume::CubicMetre};
  const Volume volume5{-123.456, Unit::Volume::CubicMetre};
  const std::hash<Volume> hasher;
  EXPECT_NE(hasher(volume0), hasher(volume1));
  EXPECT_NE(hasher(volume0), hasher(volume2));
  EXPECT_NE(hasher(volume0), hasher(volume3));
  EXPECT_NE(hasher(volume0), hasher(volume4));
  EXPECT_NE(hasher(volume0), hasher(volume5));
  const std::unordered_set<Volume> unordered{
      volume0, volume1, volume2, volume3, volume4, volume5};
}

TEST(Volume, JSON) {
  EXPECT_EQ(Volume(1.11, Unit::Volume::CubicMetre).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"m^3\"}");
  EXPECT_EQ(Volume(-5.0, Unit::Volume::CubicMillimetre)
                .JSON(Unit::Volume::CubicMillimetre),
            "{\"value\":-5.000000000000000,\"unit\":\"mm^3\"}");
}

TEST(Volume, Move) {
  const Volume reference{1.11, Unit::Volume::CubicMetre};
  Volume first{1.11, Unit::Volume::CubicMetre};
  Volume second{std::move(first)};
  EXPECT_EQ(second, reference);
  Volume third = Volume::Zero();
  third = std::move(second);
  EXPECT_EQ(third, reference);
}

TEST(Volume, Print) {
  EXPECT_EQ(
      Volume(1.11, Unit::Volume::CubicMetre).Print(), "1.110000000000000 m^3");
  EXPECT_EQ(Volume(-5.0, Unit::Volume::CubicMillimetre)
                .Print(Unit::Volume::CubicMillimetre),
            "-5.000000000000000 mm^3");
}

TEST(Volume, SizeOf) {
  const Volume volume{1.11, Unit::Volume::CubicMetre};
  EXPECT_EQ(sizeof(volume), sizeof(double));
}

TEST(Volume, Stream) {
  const Volume volume{1.11, Unit::Volume::CubicMetre};
  std::ostringstream stream;
  stream << volume;
  EXPECT_EQ(stream.str(), volume.Print());
}

TEST(Volume, Unit) { EXPECT_EQ(Volume::Unit(), Standard<Unit::Volume>); }

TEST(Volume, XML) {
  EXPECT_EQ(Volume(1.11, Unit::Volume::CubicMetre).XML(),
            "<value>1.110000000000000</value><unit>m^3</unit>");
  EXPECT_EQ(Volume(-5.0, Unit::Volume::CubicMillimetre)
                .XML(Unit::Volume::CubicMillimetre),
            "<value>-5.000000000000000</value><unit>mm^3</unit>");
}

TEST(Volume, YAML) {
  EXPECT_EQ(Volume(1.11, Unit::Volume::CubicMetre).YAML(),
            "{value:1.110000000000000,unit:\"m^3\"}");
  EXPECT_EQ(Volume(-5.0, Unit::Volume::CubicMillimetre)
                .YAML(Unit::Volume::CubicMillimetre),
            "{value:-5.000000000000000,unit:\"mm^3\"}");
}

TEST(Volume, Zero) {
  EXPECT_EQ(Volume::Zero(), Volume(0.0, Unit::Volume::CubicMetre));
}

}  // namespace

}  // namespace PhQ
