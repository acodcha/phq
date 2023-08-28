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

#include "../include/PhQ/Displacement.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Displacement, Accessor) {
  const Displacement displacement{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_DOUBLE_EQ(displacement.Value().x(), 1.0);
  EXPECT_DOUBLE_EQ(displacement.Value().y(), 2.0);
  EXPECT_DOUBLE_EQ(displacement.Value().z(), 4.0);
  EXPECT_DOUBLE_EQ(
      displacement.Value(Unit::Length::Millimetre).x(), 1.0 * 1000.0);
  EXPECT_DOUBLE_EQ(
      displacement.Value(Unit::Length::Millimetre).y(), 2.0 * 1000.0);
  EXPECT_DOUBLE_EQ(
      displacement.Value(Unit::Length::Millimetre).z(), 4.0 * 1000.0);
}

TEST(Displacement, AngleAndMagnitude) {
  const Displacement displacement0{
      {0.0, 2.0, 0.0},
      Unit::Length::Metre
  };
  const Displacement displacement1{
      {0.0, 0.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_DOUBLE_EQ(
      displacement0.Angle(displacement1).Value(Unit::Angle::Degree), 90.0);
  EXPECT_DOUBLE_EQ(displacement0.Magnitude().Value(), 2.0);
}

TEST(Displacement, Arithmetic) {
  const Length length{2.0, Unit::Length::Metre};
  const Direction direction{0.0, -1.0, 0.0};
  const Displacement displacement0{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_EQ(displacement0 + displacement0,
            Displacement({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(displacement0 - displacement0,
            Displacement({0.0, 0.0, 0.0}, Unit::Length::Metre));
  EXPECT_EQ(
      displacement0 * 2.0, Displacement({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(
      2.0 * displacement0, Displacement({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(
      displacement0 / 2.0, Displacement({0.5, 1.0, 2.0}, Unit::Length::Metre));

  Displacement displacement1{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  displacement1 += Displacement{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_EQ(displacement1, Displacement({2.0, 4.0, 8.0}, Unit::Length::Metre));

  Displacement displacement2{
      {2.0, 4.0, 8.0},
      Unit::Length::Metre
  };
  displacement2 -= Displacement{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_EQ(displacement2, Displacement({1.0, 2.0, 4.0}, Unit::Length::Metre));

  Displacement displacement3{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  displacement3 *= 2.0;
  EXPECT_EQ(displacement3, Displacement({2.0, 4.0, 8.0}, Unit::Length::Metre));

  Displacement displacement4{
      {2.0, 4.0, 8.0},
      Unit::Length::Metre
  };
  displacement4 /= 2.0;
  EXPECT_EQ(displacement4, Displacement({1.0, 2.0, 4.0}, Unit::Length::Metre));
}

TEST(Displacement, Comparison) {
  const Displacement displacement0{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  const Displacement displacement1{
      {1.0, 2.0, 8.0},
      Unit::Length::Metre
  };
  EXPECT_EQ(displacement0, displacement0);
  EXPECT_NE(displacement0, displacement1);
  EXPECT_LT(displacement0, displacement1);
  EXPECT_GT(displacement1, displacement0);
  EXPECT_LE(displacement0, displacement0);
  EXPECT_LE(displacement0, displacement1);
  EXPECT_GE(displacement0, displacement0);
  EXPECT_GE(displacement1, displacement0);
}

TEST(Displacement, Constructor) {
  constexpr Displacement displacement0;
  const Displacement displacement1{
      {1.0, 2.0, 4.0},
      Unit::Length::Millimetre
  };
  const Displacement displacement2{
      {-1.0, -2.0, -4.0},
      Unit::Length::Millimetre
  };
  constexpr Displacement displacement3{
      Displacement::Create<Unit::Length::Millimetre>({-1.0, -2.0, -4.0})};
  const Direction direction{displacement1};
  const Angle angle{displacement1, displacement2};
  const Length length{displacement1};
}

TEST(Displacement, Hash) {
  const Displacement displacement0{
      {1.0, 2.0, 4.0},
      Unit::Length::Millimetre
  };
  const Displacement displacement1{
      {1.0, 2.000001, 4.0},
      Unit::Length::Millimetre
  };
  const Displacement displacement2{
      {1.0, 2.0, 5.0},
      Unit::Length::Millimetre
  };
  const Displacement displacement3{
      {1.0, 2.0, -4.0},
      Unit::Length::Millimetre
  };
  const Displacement displacement4{
      {1000000.0, 2000000.0, 4000000.0},
      Unit::Length::Millimetre
  };
  const Displacement displacement5{
      {-1.0, -2.0, -4.0},
      Unit::Length::Millimetre
  };
  const std::hash<Displacement> hasher;
  EXPECT_NE(hasher(displacement0), hasher(displacement1));
  EXPECT_NE(hasher(displacement0), hasher(displacement2));
  EXPECT_NE(hasher(displacement0), hasher(displacement3));
  EXPECT_NE(hasher(displacement0), hasher(displacement4));
  EXPECT_NE(hasher(displacement0), hasher(displacement5));
  const std::unordered_set<Displacement> unordered{
      displacement0, displacement1, displacement2,
      displacement3, displacement4, displacement5};
}

TEST(Displacement, JSON) {
  EXPECT_EQ(Displacement({1.11, 2.22, 4.44}, Unit::Length::Metre).JSON(),
            "{\"value\":{\"x\":1.110000000000000,\"y\":2.220000000000000,\"z\":"
            "4.440000000000000},\"unit\":\"m\"}");
  EXPECT_EQ(Displacement({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .JSON(Unit::Length::Millimetre),
            "{\"value\":{\"x\":0,\"y\":-5.000000000000000,\"z\":0},\"unit\":"
            "\"mm\"}");
}

TEST(Displacement, Print) {
  EXPECT_EQ(Displacement({1.11, 2.22, 4.44}, Unit::Length::Metre).Print(),
            "(1.110000000000000, 2.220000000000000, 4.440000000000000) m");
  EXPECT_EQ(Displacement({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .Print(Unit::Length::Millimetre),
            "(0, -5.000000000000000, 0) mm");
}

TEST(Displacement, SizeOf) {
  const Displacement displacement{
      {1.11, 2.22, 4.44},
      Unit::Length::Metre
  };
  EXPECT_EQ(sizeof(displacement), 3 * sizeof(double));
}

TEST(Displacement, Stream) {
  const Displacement displacement{
      {1.11, 2.22, 4.44},
      Unit::Length::Metre
  };
  std::ostringstream stream;
  stream << displacement;
  EXPECT_EQ(stream.str(), displacement.Print());
}

TEST(Displacement, XML) {
  EXPECT_EQ(Displacement({1.11, 2.22, 4.44}, Unit::Length::Metre).XML(),
            "<value><x>1.110000000000000</x><y>2.220000000000000</"
            "y><z>4.440000000000000</z></value><unit>m</unit>");
  EXPECT_EQ(Displacement({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .XML(Unit::Length::Millimetre),
            "<value><x>0</x><y>-5.000000000000000</y><z>0</z></value><unit>mm</"
            "unit>");
}

TEST(Displacement, YAML) {
  EXPECT_EQ(Displacement({1.11, 2.22, 4.44}, Unit::Length::Metre).YAML(),
            "{value:{x:1.110000000000000,y:2.220000000000000,z:4."
            "440000000000000},unit:\"m\"}");
  EXPECT_EQ(Displacement({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .YAML(Unit::Length::Millimetre),
            "{value:{x:0,y:-5.000000000000000,z:0},unit:\"mm\"}");
}

TEST(Displacement, Zero) {
  EXPECT_EQ(
      Displacement::Zero(), Displacement({0.0, 0.0, 0.0}, Unit::Length::Metre));
}

}  // namespace

}  // namespace PhQ
