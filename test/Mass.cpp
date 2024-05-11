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

#include "../include/PhQ/Mass.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Mass.hpp"

namespace PhQ {

namespace {

TEST(Mass, ArithmeticOperatorAddition) {
  EXPECT_EQ(Mass(1.0, Unit::Mass::Kilogram) + Mass(2.0, Unit::Mass::Kilogram),
            Mass(3.0, Unit::Mass::Kilogram));
}

TEST(Mass, ArithmeticOperatorDivision) {
  EXPECT_EQ(Mass(8.0, Unit::Mass::Kilogram) / 2.0, Mass(4.0, Unit::Mass::Kilogram));
  EXPECT_EQ(Mass(8.0, Unit::Mass::Kilogram) / Mass(2.0, Unit::Mass::Kilogram), 4.0);
}

TEST(Mass, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Mass(4.0, Unit::Mass::Kilogram) * 2.0, Mass(8.0, Unit::Mass::Kilogram));
  EXPECT_EQ(2.0 * Mass(4.0, Unit::Mass::Kilogram), Mass(8.0, Unit::Mass::Kilogram));
}

TEST(Mass, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Mass(3.0, Unit::Mass::Kilogram) - Mass(2.0, Unit::Mass::Kilogram),
            Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, AssignmentOperatorAddition) {
  Mass mass{1.0, Unit::Mass::Kilogram};
  mass += Mass(2.0, Unit::Mass::Kilogram);
  EXPECT_EQ(mass, Mass(3.0, Unit::Mass::Kilogram));
}

TEST(Mass, AssignmentOperatorDivision) {
  Mass mass{8.0, Unit::Mass::Kilogram};
  mass /= 2.0;
  EXPECT_EQ(mass, Mass(4.0, Unit::Mass::Kilogram));
}

TEST(Mass, AssignmentOperatorMultiplication) {
  Mass mass{4.0, Unit::Mass::Kilogram};
  mass *= 2.0;
  EXPECT_EQ(mass, Mass(8.0, Unit::Mass::Kilogram));
}

TEST(Mass, AssignmentOperatorSubtraction) {
  Mass mass{3.0, Unit::Mass::Kilogram};
  mass -= Mass(2.0, Unit::Mass::Kilogram);
  EXPECT_EQ(mass, Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, ComparisonOperators) {
  const Mass first{1.0, Unit::Mass::Kilogram};
  const Mass second{2.0, Unit::Mass::Kilogram};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Mass, CopyAssignmentOperator) {
  const Mass first{1.0, Unit::Mass::Kilogram};
  Mass second = Mass<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Mass, CopyConstructor) {
  const Mass first{1.0, Unit::Mass::Kilogram};
  const Mass second{first};
  EXPECT_EQ(second, first);
}

TEST(Mass, Create) {
  constexpr Mass mass = Mass<>::Create<Unit::Mass::Kilogram>(1.0);
  EXPECT_EQ(mass, Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, DefaultConstructor) {
  EXPECT_NO_THROW(Mass{});
}

TEST(Mass, Dimensions) {
  EXPECT_EQ(Mass<>::Dimensions(), RelatedDimensions<Unit::Mass>);
}

TEST(Mass, Hash) {
  const Mass first{1.0, Unit::Mass::Gram};
  const Mass second{1.00001, Unit::Mass::Gram};
  const Mass third{-1.0, Unit::Mass::Gram};
  const std::hash<Mass<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Mass, JSON) {
  EXPECT_EQ(
      Mass(1.0, Unit::Mass::Kilogram).JSON(), "{\"value\":" + Print(1.0) + ",\"unit\":\"kg\"}");
  EXPECT_EQ(Mass(1.0, Unit::Mass::Gram).JSON(Unit::Mass::Gram),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"g\"}");
}

TEST(Mass, MoveAssignmentOperator) {
  Mass first{1.0, Unit::Mass::Kilogram};
  Mass second = Mass<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, MoveConstructor) {
  Mass first{1.0, Unit::Mass::Kilogram};
  const Mass second{std::move(first)};
  EXPECT_EQ(second, Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, MutableValue) {
  Mass mass{1.0, Unit::Mass::Kilogram};
  double& value = mass.MutableValue();
  value = 2.0;
  EXPECT_EQ(mass.Value(), 2.0);
}

TEST(Mass, Print) {
  EXPECT_EQ(Mass(1.0, Unit::Mass::Kilogram).Print(), Print(1.0) + " kg");
  EXPECT_EQ(Mass(1.0, Unit::Mass::Gram).Print(Unit::Mass::Gram), Print(1.0) + " g");
}

TEST(Mass, SetValue) {
  Mass mass{1.0, Unit::Mass::Kilogram};
  mass.SetValue(2.0);
  EXPECT_EQ(mass.Value(), 2.0);
}

TEST(Mass, SizeOf) {
  EXPECT_EQ(sizeof(Mass{}), sizeof(double));
}

TEST(Mass, StandardConstructor) {
  EXPECT_NO_THROW(Mass(1.0, Unit::Mass::Gram));
}

TEST(Mass, StaticValue) {
  constexpr Mass mass = Mass<>::Create<Unit::Mass::Gram>(1.0);
  constexpr double value = mass.StaticValue<Unit::Mass::Gram>();
  EXPECT_EQ(value, 1.0);
}

TEST(Mass, Stream) {
  std::ostringstream stream;
  stream << Mass(1.0, Unit::Mass::Kilogram);
  EXPECT_EQ(stream.str(), Mass(1.0, Unit::Mass::Kilogram).Print());
}

TEST(Mass, Unit) {
  EXPECT_EQ(Mass<>::Unit(), Standard<Unit::Mass>);
}

TEST(Mass, Value) {
  EXPECT_EQ(Mass(1.0, Unit::Mass::Kilogram).Value(), 1.0);
  EXPECT_EQ(Mass(1.0, Unit::Mass::Gram).Value(Unit::Mass::Gram), 1.0);
}

TEST(Mass, XML) {
  EXPECT_EQ(
      Mass(1.0, Unit::Mass::Kilogram).XML(), "<value>" + Print(1.0) + "</value><unit>kg</unit>");
  EXPECT_EQ(Mass(1.0, Unit::Mass::Gram).XML(Unit::Mass::Gram),
            "<value>" + Print(1.0) + "</value><unit>g</unit>");
}

TEST(Mass, YAML) {
  EXPECT_EQ(Mass(1.0, Unit::Mass::Kilogram).YAML(), "{value:" + Print(1.0) + ",unit:\"kg\"}");
  EXPECT_EQ(
      Mass(1.0, Unit::Mass::Gram).YAML(Unit::Mass::Gram), "{value:" + Print(1.0) + ",unit:\"g\"}");
}

TEST(Mass, Zero) {
  EXPECT_EQ(Mass<>::Zero(), Mass(0.0, Unit::Mass::Kilogram));
}

}  // namespace

}  // namespace PhQ
