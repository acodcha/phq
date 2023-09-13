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

#include "../include/PhQ/Area.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Area, Accessor) {
  const Area area{0.1, Unit::Area::SquareMetre};
  EXPECT_DOUBLE_EQ(area.Value(), 0.1);
  EXPECT_DOUBLE_EQ(area.Value(Unit::Area::SquareMillimetre), 0.1 * 1000000.0);
}

TEST(Area, Arithmetic) {
  const Length length{2.0, Unit::Length::Metre};
  const Area area0{1.0, Unit::Area::SquareMetre};
  EXPECT_EQ(area0 + area0, Area(2.0, Unit::Area::SquareMetre));
  EXPECT_EQ(area0 - area0, Area(0.0, Unit::Area::SquareMetre));
  EXPECT_EQ(area0 * 2.0, Area(2.0, Unit::Area::SquareMetre));
  EXPECT_EQ(2.0 * area0, Area(2.0, Unit::Area::SquareMetre));
  EXPECT_EQ(length * length, Area(4.0, Unit::Area::SquareMetre));
  EXPECT_EQ(area0 / 2.0, Area(0.5, Unit::Area::SquareMetre));
  EXPECT_EQ(area0 / length, Length(0.5, Unit::Length::Metre));
  EXPECT_EQ(area0 / area0, 1.0);

  Area area1{1.0, Unit::Area::SquareMetre};
  area1 += Area{1.0, Unit::Area::SquareMetre};
  EXPECT_EQ(area1, Area(2.0, Unit::Area::SquareMetre));

  Area area2{2.0, Unit::Area::SquareMetre};
  area2 -= Area{1.0, Unit::Area::SquareMetre};
  EXPECT_EQ(area2, Area(1.0, Unit::Area::SquareMetre));

  Area area3{1.0, Unit::Area::SquareMetre};
  area3 *= 2.0;
  EXPECT_EQ(area3, Area(2.0, Unit::Area::SquareMetre));

  Area area4{2.0, Unit::Area::SquareMetre};
  area4 /= 2.0;
  EXPECT_EQ(area4, Area(1.0, Unit::Area::SquareMetre));
}

TEST(Area, Comparison) {
  const Area area0{0.1, Unit::Area::SquareMetre};
  const Area area1{0.2, Unit::Area::SquareMetre};
  EXPECT_EQ(area0, area0);
  EXPECT_NE(area0, area1);
  EXPECT_LT(area0, area1);
  EXPECT_GT(area1, area0);
  EXPECT_LE(area0, area0);
  EXPECT_LE(area0, area1);
  EXPECT_GE(area0, area0);
  EXPECT_GE(area1, area0);
}

TEST(Area, Constructor) {
  constexpr Area area0;
  const Area area1{100.0, Unit::Area::SquareMillimetre};
  constexpr Area area2{Area::Create<Unit::Area::SquareMillimetre>(90.0)};
}

TEST(Area, Copy) {
  const Area reference{1.11, Unit::Area::SquareMetre};
  const Area first{reference};
  EXPECT_EQ(first, reference);
  Area second = Area::Zero();
  second = reference;
  EXPECT_EQ(second, reference);
}

TEST(Area, Dimensions) {
  EXPECT_EQ(Area::Dimensions(), RelatedDimensions<Unit::Area>);
}

TEST(Area, Hash) {
  const Area area0{10.0, Unit::Area::SquareMillimetre};
  const Area area1{10.000001, Unit::Area::SquareMillimetre};
  const Area area2{11.0, Unit::Area::SquareMillimetre};
  const Area area3{-10.0, Unit::Area::SquareMillimetre};
  const Area area4{20000.0, Unit::Area::SquareMillimetre};
  const Area area5{-123.456, Unit::Area::SquareMillimetre};
  const std::hash<Area> hasher;
  EXPECT_NE(hasher(area0), hasher(area1));
  EXPECT_NE(hasher(area0), hasher(area2));
  EXPECT_NE(hasher(area0), hasher(area3));
  EXPECT_NE(hasher(area0), hasher(area4));
  EXPECT_NE(hasher(area0), hasher(area5));
  const std::unordered_set<Area> unordered{
      area0, area1, area2, area3, area4, area5};
}

TEST(Area, JSON) {
  EXPECT_EQ(Area(1.11, Unit::Area::SquareMetre).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"m^2\"}");
  EXPECT_EQ(Area(-5.0, Unit::Area::SquareMillimetre)
                .JSON(Unit::Area::SquareMillimetre),
            "{\"value\":-5.000000000000000,\"unit\":\"mm^2\"}");
}

TEST(Area, Move) {
  const Area reference{1.11, Unit::Area::SquareMetre};
  Area first{1.11, Unit::Area::SquareMetre};
  Area second{std::move(first)};
  EXPECT_EQ(second, reference);
  Area third = Area::Zero();
  third = std::move(second);
  EXPECT_EQ(third, reference);
}

TEST(Area, Print) {
  EXPECT_EQ(
      Area(1.11, Unit::Area::SquareMetre).Print(), "1.110000000000000 m^2");
  EXPECT_EQ(Area(-5.0, Unit::Area::SquareMillimetre)
                .Print(Unit::Area::SquareMillimetre),
            "-5.000000000000000 mm^2");
}

TEST(Area, SizeOf) {
  const Area area{1.11, Unit::Area::SquareMetre};
  EXPECT_EQ(sizeof(area), sizeof(double));
}

TEST(Area, Stream) {
  const Area area{1.11, Unit::Area::SquareMetre};
  std::ostringstream stream;
  stream << area;
  EXPECT_EQ(stream.str(), area.Print());
}

TEST(Area, Unit) {
  EXPECT_EQ(Area::Unit(), Standard<Unit::Area>);
}

TEST(Area, XML) {
  EXPECT_EQ(Area(1.11, Unit::Area::SquareMetre).XML(),
            "<value>1.110000000000000</value><unit>m^2</unit>");
  EXPECT_EQ(Area(-5.0, Unit::Area::SquareMillimetre)
                .XML(Unit::Area::SquareMillimetre),
            "<value>-5.000000000000000</value><unit>mm^2</unit>");
}

TEST(Area, YAML) {
  EXPECT_EQ(Area(1.11, Unit::Area::SquareMetre).YAML(),
            "{value:1.110000000000000,unit:\"m^2\"}");
  EXPECT_EQ(Area(-5.0, Unit::Area::SquareMillimetre)
                .YAML(Unit::Area::SquareMillimetre),
            "{value:-5.000000000000000,unit:\"mm^2\"}");
}

TEST(Area, Zero) {
  EXPECT_EQ(Area::Zero(), Area(0.0, Unit::Area::SquareMetre));
}

}  // namespace

}  // namespace PhQ
