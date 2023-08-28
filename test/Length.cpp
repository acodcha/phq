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

#include "../include/PhQ/Length.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Length, Accessor) {
  const Length length{0.1, Unit::Length::Metre};
  EXPECT_DOUBLE_EQ(length.Value(), 0.1);
  EXPECT_DOUBLE_EQ(length.Value(Unit::Length::Millimetre), 0.1 * 1000.0);
}

TEST(Length, Arithmetic) {
  const Length length0{1.0, Unit::Length::Metre};
  EXPECT_EQ(length0 + length0, Length(2.0, Unit::Length::Metre));
  EXPECT_EQ(length0 - length0, Length(0.0, Unit::Length::Metre));
  EXPECT_EQ(length0 * 2.0, Length(2.0, Unit::Length::Metre));
  EXPECT_EQ(2.0 * length0, Length(2.0, Unit::Length::Metre));
  EXPECT_EQ(length0 / 2.0, Length(0.5, Unit::Length::Metre));
  EXPECT_EQ(length0 / length0, 1.0);

  Length length1{1.0, Unit::Length::Metre};
  length1 += Length{1.0, Unit::Length::Metre};
  EXPECT_EQ(length1, Length(2.0, Unit::Length::Metre));

  Length length2{2.0, Unit::Length::Metre};
  length2 -= Length{1.0, Unit::Length::Metre};
  EXPECT_EQ(length2, Length(1.0, Unit::Length::Metre));

  Length length3{1.0, Unit::Length::Metre};
  length3 *= 2.0;
  EXPECT_EQ(length3, Length(2.0, Unit::Length::Metre));

  Length length4{2.0, Unit::Length::Metre};
  length4 /= 2.0;
  EXPECT_EQ(length4, Length(1.0, Unit::Length::Metre));
}

TEST(Length, Comparison) {
  const Length length0{0.1, Unit::Length::Metre};
  const Length length1{0.2, Unit::Length::Metre};
  EXPECT_EQ(length0, length0);
  EXPECT_NE(length0, length1);
  EXPECT_LT(length0, length1);
  EXPECT_GT(length1, length0);
  EXPECT_LE(length0, length0);
  EXPECT_LE(length0, length1);
  EXPECT_GE(length0, length0);
  EXPECT_GE(length1, length0);
}

TEST(Length, Constructor) {
  constexpr Length length0;
  const Length length1{100.0, Unit::Length::Millimetre};
  constexpr Length length2{Length::Create<Unit::Length::Millimetre>(100.0)};
}

TEST(Length, Copy) {
  const Length reference{1.11, Unit::Length::Metre};
  const Length first{reference};
  EXPECT_EQ(first, reference);
  Length second = Length::Zero();
  second = reference;
  EXPECT_EQ(second, reference);
}

TEST(Length, Dimensions) {
  EXPECT_EQ(Length::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(Length, Hash) {
  const Length length0{10.0, Unit::Length::Millimetre};
  const Length length1{10.000001, Unit::Length::Millimetre};
  const Length length2{11.0, Unit::Length::Millimetre};
  const Length length3{-10.0, Unit::Length::Millimetre};
  const Length length4{20000.0, Unit::Length::Millimetre};
  const Length length5{-123.456, Unit::Length::Millimetre};
  const std::hash<Length> hasher;
  EXPECT_NE(hasher(length0), hasher(length1));
  EXPECT_NE(hasher(length0), hasher(length2));
  EXPECT_NE(hasher(length0), hasher(length3));
  EXPECT_NE(hasher(length0), hasher(length4));
  EXPECT_NE(hasher(length0), hasher(length5));
  const std::unordered_set<Length> unordered{
      length0, length1, length2, length3, length4, length5};
}

TEST(Length, JSON) {
  EXPECT_EQ(Length(1.11, Unit::Length::Metre).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"m\"}");
  EXPECT_EQ(
      Length(-5.0, Unit::Length::Millimetre).JSON(Unit::Length::Millimetre),
      "{\"value\":-5.000000000000000,\"unit\":\"mm\"}");
}

TEST(Length, Move) {
  const Length reference{1.11, Unit::Length::Metre};
  Length first{1.11, Unit::Length::Metre};
  Length second{std::move(first)};
  EXPECT_EQ(second, reference);
  Length third = Length::Zero();
  third = std::move(second);
  EXPECT_EQ(third, reference);
}

TEST(Length, Print) {
  EXPECT_EQ(Length(1.11, Unit::Length::Metre).Print(), "1.110000000000000 m");
  EXPECT_EQ(
      Length(-5.0, Unit::Length::Millimetre).Print(Unit::Length::Millimetre),
      "-5.000000000000000 mm");
}

TEST(Length, SizeOf) {
  const Length length{1.11, Unit::Length::Metre};
  EXPECT_EQ(sizeof(length), sizeof(double));
}

TEST(Length, Stream) {
  const Length length{1.11, Unit::Length::Metre};
  std::ostringstream stream;
  stream << length;
  EXPECT_EQ(stream.str(), length.Print());
}

TEST(Length, Unit) { EXPECT_EQ(Length::Unit(), Standard<Unit::Length>); }

TEST(Length, XML) {
  EXPECT_EQ(Length(1.11, Unit::Length::Metre).XML(),
            "<value>1.110000000000000</value><unit>m</unit>");
  EXPECT_EQ(
      Length(-5.0, Unit::Length::Millimetre).XML(Unit::Length::Millimetre),
      "<value>-5.000000000000000</value><unit>mm</unit>");
}

TEST(Length, YAML) {
  EXPECT_EQ(Length(1.11, Unit::Length::Metre).YAML(),
            "{value:1.110000000000000,unit:\"m\"}");
  EXPECT_EQ(
      Length(-5.0, Unit::Length::Millimetre).YAML(Unit::Length::Millimetre),
      "{value:-5.000000000000000,unit:\"mm\"}");
}

TEST(Length, Zero) {
  EXPECT_EQ(Length::Zero(), Length(0.0, Unit::Length::Metre));
}

}  // namespace

}  // namespace PhQ
