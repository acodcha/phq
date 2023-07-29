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

#include "../include/PhQ/AreaVector.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(AreaVector, Accessor) {
  const AreaVector area{
      {1.0, 2.0, 4.0},
      Unit::Area::SquareMetre
  };
  EXPECT_DOUBLE_EQ(area.Value().x(), 1.0);
  EXPECT_DOUBLE_EQ(area.Value().y(), 2.0);
  EXPECT_DOUBLE_EQ(area.Value().z(), 4.0);
  EXPECT_DOUBLE_EQ(
      area.Value(Unit::Area::SquareFoot).x(), 1.0 / (0.3048 * 0.3048));
  EXPECT_DOUBLE_EQ(
      area.Value(Unit::Area::SquareFoot).y(), 2.0 / (0.3048 * 0.3048));
  EXPECT_DOUBLE_EQ(
      area.Value(Unit::Area::SquareFoot).z(), 4.0 / (0.3048 * 0.3048));
}

TEST(AreaVector, AngleAndMagnitude) {
  const AreaVector area0{
      {0.0, 2.0, 0.0},
      Unit::Area::SquareMetre
  };
  const AreaVector area1{
      {0.0, 0.0, 4.0},
      Unit::Area::SquareMetre
  };
  EXPECT_DOUBLE_EQ(area0.Angle(area1).Value(Unit::Angle::Degree), 90.0);
  EXPECT_DOUBLE_EQ(area0.Magnitude().Value(), 2.0);
}

TEST(AreaVector, Arithmetic) {
  const Area magnitude{2.0, Unit::Area::SquareMetre};
  const Direction direction{0.0, -1.0, 0.0};
  const AreaVector area0{
      {0.0, 0.0, 0.0},
      Unit::Area::SquareMetre
  };
  const AreaVector area1{
      {1.0, 2.0, 4.0},
      Unit::Area::SquareMetre
  };
  const AreaVector area2{
      {2.0, 4.0, 8.0},
      Unit::Area::SquareMetre
  };
  EXPECT_EQ(area1 + area1, area2);
  EXPECT_EQ(area1 - area1, area0);
  EXPECT_EQ(area1 * 2.0, area2);
  EXPECT_EQ(2.0 * area1, area2);
  EXPECT_EQ(direction * magnitude,
            AreaVector({0.0, -2.0, 0.0}, Unit::Area::SquareMetre));
  EXPECT_EQ(magnitude * direction,
            AreaVector({0.0, -2.0, 0.0}, Unit::Area::SquareMetre));
  EXPECT_EQ(area2 / 2.0, area1);

  AreaVector area3{area1};
  area3 += area1;
  EXPECT_EQ(area3, area2);

  AreaVector area4{area1};
  area4 -= area1;
  EXPECT_EQ(area4, area0);

  AreaVector area5{area1};
  area5 *= 2.0;
  EXPECT_EQ(area5, area2);

  AreaVector area6{area2};
  area6 /= 2.0;
  EXPECT_EQ(area6, area1);
}

TEST(AreaVector, Comparison) {
  const AreaVector area0{
      {1.0, 2.0, 4.0},
      Unit::Area::SquareMetre
  };
  const AreaVector area1{
      {1.0, 2.0, 8.0},
      Unit::Area::SquareMetre
  };
  EXPECT_EQ(area0, area0);
  EXPECT_NE(area0, area1);
  EXPECT_LT(area0, area1);
  EXPECT_GT(area1, area0);
  EXPECT_LE(area0, area0);
  EXPECT_LE(area0, area1);
  EXPECT_GE(area0, area0);
  EXPECT_GE(area1, area0);
}

TEST(AreaVector, Constructor) {
  constexpr AreaVector area0;
  const AreaVector area1{
      {1.0, 2.0, 4.0},
      Unit::Area::SquareFoot
  };
  const AreaVector area2{
      {-1.0, -2.0, -4.0},
      Unit::Area::SquareFoot
  };
  constexpr AreaVector area3{
      AreaVector::Create<Unit::Area::SquareFoot>({-1.0, -2.0, -4.0})};
  const Direction direction{area1};
  const Angle angle{area1, area2};
  const Area magnitude{area1};
}

TEST(AreaVector, Hash) {
  const AreaVector area0{
      {1.0, 2.0, 4.0},
      Unit::Area::SquareFoot
  };
  const AreaVector area1{
      {1.0, 2.000001, 4.0},
      Unit::Area::SquareFoot
  };
  const AreaVector area2{
      {1.0, 2.0, 5.0},
      Unit::Area::SquareFoot
  };
  const AreaVector area3{
      {1.0, 2.0, -4.0},
      Unit::Area::SquareFoot
  };
  const AreaVector area4{
      {1000000.0, 2000000.0, 4000000.0},
      Unit::Area::SquareFoot
  };
  const AreaVector area5{
      {-1.0, -2.0, -4.0},
      Unit::Area::SquareFoot
  };
  const std::hash<AreaVector> hasher;
  EXPECT_NE(hasher(area0), hasher(area1));
  EXPECT_NE(hasher(area0), hasher(area2));
  EXPECT_NE(hasher(area0), hasher(area3));
  EXPECT_NE(hasher(area0), hasher(area4));
  EXPECT_NE(hasher(area0), hasher(area5));
  const std::unordered_set<AreaVector> unordered{
      area0, area1, area2, area3, area4, area5};
}

TEST(AreaVector, JSON) {
  EXPECT_EQ(AreaVector({1.11, 2.22, 4.44}, Unit::Area::SquareMetre).JSON(),
            "{\"value\":{\"x\":1.110000,\"y\":2.220000,\"z\":4.440000},"
            "\"unit\":\"m^2\"}");
  EXPECT_EQ(AreaVector({0.0, -5.0, 0.0}, Unit::Area::SquareFoot)
                .JSON(Unit::Area::SquareFoot),
            "{\"value\":{\"x\":0,\"y\":-5.000000,\"z\":0},\"unit\":\"ft^2\"}");
}

TEST(AreaVector, Print) {
  EXPECT_EQ(AreaVector({1.11, 2.22, 4.44}, Unit::Area::SquareMetre).Print(),
            "(1.110000, 2.220000, 4.440000) m^2");
  EXPECT_EQ(AreaVector({0.0, -5.0, 0.0}, Unit::Area::SquareFoot)
                .Print(Unit::Area::SquareFoot),
            "(0, -5.000000, 0) ft^2");
}

TEST(AreaVector, Stream) {
  const AreaVector area{
      {1.11, 2.22, 4.44},
      Unit::Area::SquareMetre
  };
  std::ostringstream stream;
  stream << area;
  EXPECT_EQ(stream.str(), area.Print());
}

TEST(AreaVector, XML) {
  EXPECT_EQ(AreaVector({1.11, 2.22, 4.44}, Unit::Area::SquareMetre).XML(),
            "<value><x>1.110000</x><y>2.220000</y><z>4.440000</z></"
            "value><unit>m^2</unit>");
  EXPECT_EQ(AreaVector({0.0, -5.0, 0.0}, Unit::Area::SquareFoot)
                .XML(Unit::Area::SquareFoot),
            "<value><x>0</x><y>-5.000000</y><z>0</z></value><unit>ft^2</unit>");
}

TEST(AreaVector, YAML) {
  EXPECT_EQ(AreaVector({1.11, 2.22, 4.44}, Unit::Area::SquareMetre).YAML(),
            "{value:{x:1.110000,y:2.220000,z:4.440000},unit:\"m^2\"}");
  EXPECT_EQ(AreaVector({0.0, -5.0, 0.0}, Unit::Area::SquareFoot)
                .YAML(Unit::Area::SquareFoot),
            "{value:{x:0,y:-5.000000,z:0},unit:\"ft^2\"}");
}

TEST(AreaVector, Zero) {
  EXPECT_EQ(
      AreaVector::Zero(), AreaVector({0.0, 0.0, 0.0}, Unit::Area::SquareMetre));
}

}  // namespace

}  // namespace PhQ
