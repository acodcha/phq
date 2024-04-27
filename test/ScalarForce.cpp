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

#include "../include/PhQ/ScalarForce.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Force.hpp"

namespace PhQ {

namespace {

TEST(ScalarForce, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarForce(1.0, Unit::Force::Newton) + ScalarForce(2.0, Unit::Force::Newton),
            ScalarForce(3.0, Unit::Force::Newton));
}

TEST(ScalarForce, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarForce(8.0, Unit::Force::Newton) / 2.0, ScalarForce(4.0, Unit::Force::Newton));

  EXPECT_EQ(ScalarForce(8.0, Unit::Force::Newton) / ScalarForce(2.0, Unit::Force::Newton), 4.0);
}

TEST(ScalarForce, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarForce(4.0, Unit::Force::Newton) * 2.0, ScalarForce(8.0, Unit::Force::Newton));

  EXPECT_EQ(2.0 * ScalarForce(4.0, Unit::Force::Newton), ScalarForce(8.0, Unit::Force::Newton));
}

TEST(ScalarForce, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarForce(3.0, Unit::Force::Newton) - ScalarForce(2.0, Unit::Force::Newton),
            ScalarForce(1.0, Unit::Force::Newton));
}

TEST(ScalarForce, AssignmentOperatorAddition) {
  ScalarForce quantity{1.0, Unit::Force::Newton};
  quantity += ScalarForce(2.0, Unit::Force::Newton);
  EXPECT_EQ(quantity, ScalarForce(3.0, Unit::Force::Newton));
}

TEST(ScalarForce, AssignmentOperatorDivision) {
  ScalarForce quantity{8.0, Unit::Force::Newton};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ScalarForce(4.0, Unit::Force::Newton));
}

TEST(ScalarForce, AssignmentOperatorMultiplication) {
  ScalarForce quantity{4.0, Unit::Force::Newton};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ScalarForce(8.0, Unit::Force::Newton));
}

TEST(ScalarForce, AssignmentOperatorSubtraction) {
  ScalarForce quantity{3.0, Unit::Force::Newton};
  quantity -= ScalarForce(2.0, Unit::Force::Newton);
  EXPECT_EQ(quantity, ScalarForce(1.0, Unit::Force::Newton));
}

TEST(ScalarForce, ComparisonOperators) {
  const ScalarForce first{1.11, Unit::Force::Newton};
  const ScalarForce second{2.22, Unit::Force::Newton};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarForce, CopyAssignmentOperator) {
  const ScalarForce first{1.11, Unit::Force::Newton};
  ScalarForce second = ScalarForce::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ScalarForce, CopyConstructor) {
  const ScalarForce first{1.11, Unit::Force::Newton};
  const ScalarForce second{first};
  EXPECT_EQ(second, first);
}

TEST(ScalarForce, Create) {
  constexpr ScalarForce quantity = ScalarForce::Create<Unit::Force::Newton>(1.11);
  EXPECT_EQ(quantity, ScalarForce(1.11, Unit::Force::Newton));
}

TEST(ScalarForce, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarForce{});
}

TEST(ScalarForce, Dimensions) {
  EXPECT_EQ(ScalarForce::Dimensions(), RelatedDimensions<Unit::Force>);
}

TEST(ScalarForce, Hash) {
  const ScalarForce first{1.11, Unit::Force::Micronewton};
  const ScalarForce second{1.110001, Unit::Force::Micronewton};
  const ScalarForce third{-1.11, Unit::Force::Micronewton};
  const std::hash<ScalarForce> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarForce, JSON) {
  EXPECT_EQ(ScalarForce(1.11, Unit::Force::Newton).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"N\"}");
  EXPECT_EQ(ScalarForce(-2.22, Unit::Force::Micronewton).JSON(Unit::Force::Micronewton),
            "{\"value\":-2.220000000000000,\"unit\":\"μN\"}");
}

TEST(ScalarForce, MoveAssignmentOperator) {
  ScalarForce first{1.11, Unit::Force::Newton};
  ScalarForce second = ScalarForce::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarForce(1.11, Unit::Force::Newton));
}

TEST(ScalarForce, MoveConstructor) {
  ScalarForce first{1.11, Unit::Force::Newton};
  const ScalarForce second{std::move(first)};
  EXPECT_EQ(second, ScalarForce(1.11, Unit::Force::Newton));
}

TEST(ScalarForce, MutableValue) {
  ScalarForce quantity{1.11, Unit::Force::Newton};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ScalarForce, Print) {
  EXPECT_EQ(ScalarForce(1.11, Unit::Force::Newton).Print(), "1.110000000000000 N");
  EXPECT_EQ(ScalarForce(-2.22, Unit::Force::Micronewton).Print(Unit::Force::Micronewton),
            "-2.220000000000000 μN");
}

TEST(ScalarForce, SetValue) {
  ScalarForce quantity{1.11, Unit::Force::Newton};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ScalarForce, SizeOf) {
  EXPECT_EQ(sizeof(ScalarForce{}), sizeof(double));
}

TEST(ScalarForce, StandardConstructor) {
  EXPECT_NO_THROW(ScalarForce(1.11, Unit::Force::Micronewton));
}

TEST(ScalarForce, StaticValue) {
  constexpr ScalarForce quantity = ScalarForce::Create<Unit::Force::Micronewton>(2.0);
  constexpr double value = quantity.StaticValue<Unit::Force::Micronewton>();
  EXPECT_EQ(value, 2.0);
}

TEST(ScalarForce, Stream) {
  std::ostringstream stream;
  stream << ScalarForce(1.11, Unit::Force::Newton);
  EXPECT_EQ(stream.str(), ScalarForce(1.11, Unit::Force::Newton).Print());
}

TEST(ScalarForce, Unit) {
  EXPECT_EQ(ScalarForce::Unit(), Standard<Unit::Force>);
}

TEST(ScalarForce, Value) {
  EXPECT_EQ(ScalarForce(1.11, Unit::Force::Newton).Value(), 1.11);
  EXPECT_EQ(ScalarForce(2.0, Unit::Force::Micronewton).Value(Unit::Force::Micronewton), 2.0);
}

TEST(ScalarForce, XML) {
  EXPECT_EQ(ScalarForce(1.11, Unit::Force::Newton).XML(),
            "<value>1.110000000000000</value><unit>N</unit>");
  EXPECT_EQ(ScalarForce(-2.22, Unit::Force::Micronewton).XML(Unit::Force::Micronewton),
            "<value>-2.220000000000000</value><unit>μN</unit>");
}

TEST(ScalarForce, YAML) {
  EXPECT_EQ(ScalarForce(1.11, Unit::Force::Newton).YAML(), "{value:1.110000000000000,unit:\"N\"}");
  EXPECT_EQ(ScalarForce(-2.22, Unit::Force::Micronewton).YAML(Unit::Force::Micronewton),
            "{value:-2.220000000000000,unit:\"μN\"}");
}

TEST(ScalarForce, Zero) {
  EXPECT_EQ(ScalarForce::Zero(), ScalarForce(0.0, Unit::Force::Newton));
}

}  // namespace

}  // namespace PhQ
