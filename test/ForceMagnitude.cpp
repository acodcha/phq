// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#include "../include/PhQ/ForceMagnitude.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Force.hpp"

namespace PhQ {

namespace {

TEST(ForceMagnitude, ArithmeticOperatorAddition) {
  EXPECT_EQ(ForceMagnitude(1.0, Unit::Force::Newton) + ForceMagnitude(2.0, Unit::Force::Newton),
            ForceMagnitude(3.0, Unit::Force::Newton));
}

TEST(ForceMagnitude, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      ForceMagnitude(8.0, Unit::Force::Newton) / 2.0, ForceMagnitude(4.0, Unit::Force::Newton));

  EXPECT_EQ(
      ForceMagnitude(8.0, Unit::Force::Newton) / ForceMagnitude(2.0, Unit::Force::Newton), 4.0);
}

TEST(ForceMagnitude, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      ForceMagnitude(4.0, Unit::Force::Newton) * 2.0, ForceMagnitude(8.0, Unit::Force::Newton));

  EXPECT_EQ(
      2.0 * ForceMagnitude(4.0, Unit::Force::Newton), ForceMagnitude(8.0, Unit::Force::Newton));
}

TEST(ForceMagnitude, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ForceMagnitude(3.0, Unit::Force::Newton) - ForceMagnitude(2.0, Unit::Force::Newton),
            ForceMagnitude(1.0, Unit::Force::Newton));
}

TEST(ForceMagnitude, AssignmentOperatorAddition) {
  ForceMagnitude quantity{1.0, Unit::Force::Newton};
  quantity += ForceMagnitude(2.0, Unit::Force::Newton);
  EXPECT_EQ(quantity, ForceMagnitude(3.0, Unit::Force::Newton));
}

TEST(ForceMagnitude, AssignmentOperatorDivision) {
  ForceMagnitude quantity{8.0, Unit::Force::Newton};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ForceMagnitude(4.0, Unit::Force::Newton));
}

TEST(ForceMagnitude, AssignmentOperatorMultiplication) {
  ForceMagnitude quantity{4.0, Unit::Force::Newton};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ForceMagnitude(8.0, Unit::Force::Newton));
}

TEST(ForceMagnitude, AssignmentOperatorSubtraction) {
  ForceMagnitude quantity{3.0, Unit::Force::Newton};
  quantity -= ForceMagnitude(2.0, Unit::Force::Newton);
  EXPECT_EQ(quantity, ForceMagnitude(1.0, Unit::Force::Newton));
}

TEST(ForceMagnitude, ComparisonOperators) {
  const ForceMagnitude first{1.11, Unit::Force::Newton};
  const ForceMagnitude second{2.22, Unit::Force::Newton};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ForceMagnitude, CopyAssignmentOperator) {
  const ForceMagnitude first{1.11, Unit::Force::Newton};
  ForceMagnitude second = ForceMagnitude::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ForceMagnitude, CopyConstructor) {
  const ForceMagnitude first{1.11, Unit::Force::Newton};
  const ForceMagnitude second{first};
  EXPECT_EQ(second, first);
}

TEST(ForceMagnitude, Create) {
  constexpr ForceMagnitude quantity = ForceMagnitude::Create<Unit::Force::Newton>(1.11);
  EXPECT_EQ(quantity, ForceMagnitude(1.11, Unit::Force::Newton));
}

TEST(ForceMagnitude, DefaultConstructor) {
  EXPECT_NO_THROW(ForceMagnitude{});
}

TEST(ForceMagnitude, Dimensions) {
  EXPECT_EQ(ForceMagnitude::Dimensions(), RelatedDimensions<Unit::Force>);
}

TEST(ForceMagnitude, Hash) {
  const ForceMagnitude first{1.11, Unit::Force::Micronewton};
  const ForceMagnitude second{1.110001, Unit::Force::Micronewton};
  const ForceMagnitude third{-1.11, Unit::Force::Micronewton};
  const std::hash<ForceMagnitude> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ForceMagnitude, JSON) {
  EXPECT_EQ(ForceMagnitude(1.11, Unit::Force::Newton).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"N\"}");
  EXPECT_EQ(ForceMagnitude(-2.22, Unit::Force::Micronewton).JSON(Unit::Force::Micronewton),
            "{\"value\":-2.220000000000000,\"unit\":\"μN\"}");
}

TEST(ForceMagnitude, MoveAssignmentOperator) {
  ForceMagnitude first{1.11, Unit::Force::Newton};
  ForceMagnitude second = ForceMagnitude::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ForceMagnitude(1.11, Unit::Force::Newton));
}

TEST(ForceMagnitude, MoveConstructor) {
  ForceMagnitude first{1.11, Unit::Force::Newton};
  const ForceMagnitude second{std::move(first)};
  EXPECT_EQ(second, ForceMagnitude(1.11, Unit::Force::Newton));
}

TEST(ForceMagnitude, MutableValue) {
  ForceMagnitude quantity{1.11, Unit::Force::Newton};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ForceMagnitude, Print) {
  EXPECT_EQ(ForceMagnitude(1.11, Unit::Force::Newton).Print(), "1.110000000000000 N");
  EXPECT_EQ(ForceMagnitude(-2.22, Unit::Force::Micronewton).Print(Unit::Force::Micronewton),
            "-2.220000000000000 μN");
}

TEST(ForceMagnitude, SetValue) {
  ForceMagnitude quantity{1.11, Unit::Force::Newton};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ForceMagnitude, SizeOf) {
  EXPECT_EQ(sizeof(ForceMagnitude{}), sizeof(double));
}

TEST(ForceMagnitude, StandardConstructor) {
  EXPECT_NO_THROW(ForceMagnitude(1.11, Unit::Force::Micronewton));
}

TEST(ForceMagnitude, StaticValue) {
  constexpr ForceMagnitude quantity = ForceMagnitude::Create<Unit::Force::Micronewton>(2.0);
  constexpr double value = quantity.StaticValue<Unit::Force::Micronewton>();
  EXPECT_EQ(value, 2.0);
}

TEST(ForceMagnitude, Stream) {
  std::ostringstream stream;
  stream << ForceMagnitude(1.11, Unit::Force::Newton);
  EXPECT_EQ(stream.str(), ForceMagnitude(1.11, Unit::Force::Newton).Print());
}

TEST(ForceMagnitude, Unit) {
  EXPECT_EQ(ForceMagnitude::Unit(), Standard<Unit::Force>);
}

TEST(ForceMagnitude, Value) {
  EXPECT_EQ(ForceMagnitude(1.11, Unit::Force::Newton).Value(), 1.11);
  EXPECT_EQ(ForceMagnitude(2.0, Unit::Force::Micronewton).Value(Unit::Force::Micronewton), 2.0);
}

TEST(ForceMagnitude, XML) {
  EXPECT_EQ(ForceMagnitude(1.11, Unit::Force::Newton).XML(),
            "<value>1.110000000000000</value><unit>N</unit>");
  EXPECT_EQ(ForceMagnitude(-2.22, Unit::Force::Micronewton).XML(Unit::Force::Micronewton),
            "<value>-2.220000000000000</value><unit>μN</unit>");
}

TEST(ForceMagnitude, YAML) {
  EXPECT_EQ(
      ForceMagnitude(1.11, Unit::Force::Newton).YAML(), "{value:1.110000000000000,unit:\"N\"}");
  EXPECT_EQ(ForceMagnitude(-2.22, Unit::Force::Micronewton).YAML(Unit::Force::Micronewton),
            "{value:-2.220000000000000,unit:\"μN\"}");
}

TEST(ForceMagnitude, Zero) {
  EXPECT_EQ(ForceMagnitude::Zero(), ForceMagnitude(0.0, Unit::Force::Newton));
}

}  // namespace

}  // namespace PhQ
