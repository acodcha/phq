// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#include <functional>
#include <gtest/gtest.h>
#include <sstream>

#include "../include/PhQ/Position.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

// Since PhQ::DimensionalVector is an abstract base class, tests use PhQ::Position, which is one of
// its derived classes.

TEST(DimensionalVector, Dimensions) {
  EXPECT_EQ(Position::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(DimensionalVector, Hash) {
  const Position first({1.0, -2.0, 3.0}, Unit::Length::Millimetre);
  const Position second({1.0, -2.0, 3.000001}, Unit::Length::Millimetre);
  const Position third({1.0, 2.0, 3.0}, Unit::Length::Millimetre);
  const std::hash<Position> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionalVector, JSON) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"m\"}");
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Millimetre).JSON(Unit::Length::Millimetre),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"mm\"}");
}

TEST(DimensionalVector, MutableValue) {
  Position position({1.0, -2.0, 3.0}, Unit::Length::Metre);
  Vector<>& value = position.MutableValue();
  value = Vector{-4.0, 5.0, -6.0};
  EXPECT_EQ(position.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(DimensionalVector, Print) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") m");
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Millimetre).Print(Unit::Length::Millimetre),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") mm");
}

TEST(DimensionalVector, SetValue) {
  Position position({1.0, -2.0, 3.0}, Unit::Length::Metre);
  position.SetValue({-4.0, 5.0, -6.0});
  EXPECT_EQ(position.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(DimensionalVector, SizeOf) {
  EXPECT_EQ(sizeof(Position{}), 3 * sizeof(double));
}

TEST(DimensionalVector, StaticValue) {
  constexpr Position position = Position::Create<Unit::Length::Millimetre>(1.0, -2.0, 3.0);
  constexpr Vector value = position.StaticValue<Unit::Length::Millimetre>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(DimensionalVector, Stream) {
  std::ostringstream stream;
  stream << Position({1.0, -2.0, 3.0}, Unit::Length::Metre);
  EXPECT_EQ(stream.str(), Position({1.0, -2.0, 3.0}, Unit::Length::Metre).Print());
}

TEST(DimensionalVector, Unit) {
  EXPECT_EQ(Position::Unit(), Standard<Unit::Length>);
}

TEST(DimensionalVector, Value) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).Value(), Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Millimetre).Value(Unit::Length::Millimetre),
            Vector(1.0, -2.0, 3.0));
}

TEST(DimensionalVector, XML) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>m</unit>");
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Millimetre).XML(Unit::Length::Millimetre),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>mm</unit>");
}

TEST(DimensionalVector, YAML) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"m\"}");
  EXPECT_EQ(
      Position({1.0, -2.0, 3.0}, Unit::Length::Millimetre).YAML(Unit::Length::Millimetre),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"mm\"}");
}

}  // namespace

}  // namespace PhQ
