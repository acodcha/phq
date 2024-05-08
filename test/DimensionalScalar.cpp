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

#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/Unit/Length.hpp"

namespace PhQ {

namespace {

// Since PhQ::DimensionalScalar is an abstract base class, tests use PhQ::Length, which is one of
// its derived classes.

TEST(DimensionalScalar, Dimensions) {
  EXPECT_EQ(Length::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(DimensionalScalar, Hash) {
  const Length first{1.0, Unit::Length::Millimetre};
  const Length second{1.00001, Unit::Length::Millimetre};
  const Length third{-1.0, Unit::Length::Millimetre};
  const std::hash<Length> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionalScalar, JSON) {
  EXPECT_EQ(
      Length(1.0, Unit::Length::Metre).JSON(), "{\"value\":" + Print(1.0) + ",\"unit\":\"m\"}");
  EXPECT_EQ(Length(1.0, Unit::Length::Millimetre).JSON(Unit::Length::Millimetre),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"mm\"}");
}

TEST(DimensionalScalar, MutableValue) {
  Length length{1.0, Unit::Length::Metre};
  double& value = length.MutableValue();
  value = 2.0;
  EXPECT_EQ(length.Value(), 2.0);
}

TEST(DimensionalScalar, Print) {
  EXPECT_EQ(Length(1.0, Unit::Length::Metre).Print(), Print(1.0) + " m");
  EXPECT_EQ(
      Length(1.0, Unit::Length::Millimetre).Print(Unit::Length::Millimetre), Print(1.0) + " mm");
}

TEST(DimensionalScalar, SetValue) {
  Length length{1.0, Unit::Length::Metre};
  length.SetValue(2.0);
  EXPECT_EQ(length.Value(), 2.0);
}

TEST(DimensionalScalar, SizeOf) {
  EXPECT_EQ(sizeof(Length{}), sizeof(double));
}

TEST(DimensionalScalar, StaticValue) {
  constexpr Length length = Length::Create<Unit::Length::Metre>(1.0);
  constexpr double value = length.StaticValue<Unit::Length::Metre>();
  EXPECT_EQ(value, 1.0);
}

TEST(DimensionalScalar, Stream) {
  std::ostringstream stream;
  stream << Length{1.0, Unit::Length::Metre};
  EXPECT_EQ(stream.str(), Length(1.0, Unit::Length::Metre).Print());
}

TEST(DimensionalScalar, Unit) {
  EXPECT_EQ(Length::Unit(), Standard<Unit::Length>);
}

TEST(DimensionalScalar, Value) {
  EXPECT_EQ(Length(1.0, Unit::Length::Metre).Value(), 1.0);
  EXPECT_EQ(Length(1.0, Unit::Length::Millimetre).Value(Unit::Length::Millimetre), 1.0);
}

TEST(DimensionalScalar, XML) {
  EXPECT_EQ(
      Length(1.0, Unit::Length::Metre).XML(), "<value>" + Print(1.0) + "</value><unit>m</unit>");
  EXPECT_EQ(Length(1.0, Unit::Length::Millimetre).XML(Unit::Length::Millimetre),
            "<value>" + Print(1.0) + "</value><unit>mm</unit>");
}

TEST(DimensionalScalar, YAML) {
  EXPECT_EQ(Length(1.0, Unit::Length::Metre).YAML(), "{value:" + Print(1.0) + ",unit:\"m\"}");
  EXPECT_EQ(Length(1.0, Unit::Length::Millimetre).YAML(Unit::Length::Millimetre),
            "{value:" + Print(1.0) + ",unit:\"mm\"}");
}

}  // namespace

}  // namespace PhQ
