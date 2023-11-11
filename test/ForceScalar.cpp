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

#include "../include/PhQ/ForceScalar.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Force.hpp"

namespace PhQ {

namespace {

TEST(ForceScalar, ArithmeticOperatorAddition) {
  EXPECT_EQ(ForceScalar(1.0, Unit::Force::Newton) + ForceScalar(2.0, Unit::Force::Newton),
            ForceScalar(3.0, Unit::Force::Newton));
}

TEST(ForceScalar, ArithmeticOperatorDivision) {
  EXPECT_EQ(ForceScalar(8.0, Unit::Force::Newton) / 2.0, ForceScalar(4.0, Unit::Force::Newton));

  EXPECT_EQ(ForceScalar(8.0, Unit::Force::Newton) / ForceScalar(2.0, Unit::Force::Newton), 4.0);
}

TEST(ForceScalar, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ForceScalar(4.0, Unit::Force::Newton) * 2.0, ForceScalar(8.0, Unit::Force::Newton));

  EXPECT_EQ(2.0 * ForceScalar(4.0, Unit::Force::Newton), ForceScalar(8.0, Unit::Force::Newton));
}

TEST(ForceScalar, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ForceScalar(3.0, Unit::Force::Newton) - ForceScalar(2.0, Unit::Force::Newton),
            ForceScalar(1.0, Unit::Force::Newton));
}

TEST(ForceScalar, AssignmentOperatorAddition) {
  ForceScalar quantity{1.0, Unit::Force::Newton};
  quantity += ForceScalar(2.0, Unit::Force::Newton);
  EXPECT_EQ(quantity, ForceScalar(3.0, Unit::Force::Newton));
}

TEST(ForceScalar, AssignmentOperatorDivision) {
  ForceScalar quantity{8.0, Unit::Force::Newton};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ForceScalar(4.0, Unit::Force::Newton));
}

TEST(ForceScalar, AssignmentOperatorMultiplication) {
  ForceScalar quantity{4.0, Unit::Force::Newton};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ForceScalar(8.0, Unit::Force::Newton));
}

TEST(ForceScalar, AssignmentOperatorSubtraction) {
  ForceScalar quantity{3.0, Unit::Force::Newton};
  quantity -= ForceScalar(2.0, Unit::Force::Newton);
  EXPECT_EQ(quantity, ForceScalar(1.0, Unit::Force::Newton));
}

TEST(ForceScalar, ComparisonOperators) {
  const ForceScalar first{1.11, Unit::Force::Newton};
  const ForceScalar second{2.22, Unit::Force::Newton};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ForceScalar, CopyAssignmentOperator) {
  const ForceScalar first{1.11, Unit::Force::Newton};
  ForceScalar second = ForceScalar::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ForceScalar, CopyConstructor) {
  const ForceScalar first{1.11, Unit::Force::Newton};
  const ForceScalar second{first};
  EXPECT_EQ(second, first);
}

TEST(ForceScalar, Create) {
  constexpr ForceScalar quantity = ForceScalar::Create<Unit::Force::Newton>(1.11);
  EXPECT_EQ(quantity, ForceScalar(1.11, Unit::Force::Newton));
}

TEST(ForceScalar, DefaultConstructor) {
  EXPECT_NO_THROW(ForceScalar{});
}

TEST(ForceScalar, Dimensions) {
  EXPECT_EQ(ForceScalar::Dimensions(), RelatedDimensions<Unit::Force>);
}

TEST(ForceScalar, Hash) {
  const ForceScalar first{1.11, Unit::Force::Micronewton};
  const ForceScalar second{1.110001, Unit::Force::Micronewton};
  const ForceScalar third{-1.11, Unit::Force::Micronewton};
  const std::hash<ForceScalar> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ForceScalar, JSON) {
  EXPECT_EQ(ForceScalar(1.11, Unit::Force::Newton).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"N\"}");
  EXPECT_EQ(ForceScalar(-2.22, Unit::Force::Micronewton).JSON(Unit::Force::Micronewton),
            "{\"value\":-2.220000000000000,\"unit\":\"μN\"}");
}

TEST(ForceScalar, MoveAssignmentOperator) {
  ForceScalar first{1.11, Unit::Force::Newton};
  ForceScalar second = ForceScalar::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ForceScalar(1.11, Unit::Force::Newton));
}

TEST(ForceScalar, MoveConstructor) {
  ForceScalar first{1.11, Unit::Force::Newton};
  const ForceScalar second{std::move(first)};
  EXPECT_EQ(second, ForceScalar(1.11, Unit::Force::Newton));
}

TEST(ForceScalar, MutableValue) {
  ForceScalar quantity{1.11, Unit::Force::Newton};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ForceScalar, Print) {
  EXPECT_EQ(ForceScalar(1.11, Unit::Force::Newton).Print(), "1.110000000000000 N");
  EXPECT_EQ(ForceScalar(-2.22, Unit::Force::Micronewton).Print(Unit::Force::Micronewton),
            "-2.220000000000000 μN");
}

TEST(ForceScalar, SetValue) {
  ForceScalar quantity{1.11, Unit::Force::Newton};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ForceScalar, SizeOf) {
  EXPECT_EQ(sizeof(ForceScalar{}), sizeof(double));
}

TEST(ForceScalar, StandardConstructor) {
  EXPECT_NO_THROW(ForceScalar(1.11, Unit::Force::Micronewton));
}

TEST(ForceScalar, StaticValue) {
  constexpr ForceScalar quantity = ForceScalar::Create<Unit::Force::Micronewton>(2.0);
  constexpr double value = quantity.StaticValue<Unit::Force::Micronewton>();
  EXPECT_EQ(value, 2.0);
}

TEST(ForceScalar, Stream) {
  std::ostringstream stream;
  stream << ForceScalar(1.11, Unit::Force::Newton);
  EXPECT_EQ(stream.str(), ForceScalar(1.11, Unit::Force::Newton).Print());
}

TEST(ForceScalar, Unit) {
  EXPECT_EQ(ForceScalar::Unit(), Standard<Unit::Force>);
}

TEST(ForceScalar, Value) {
  EXPECT_EQ(ForceScalar(1.11, Unit::Force::Newton).Value(), 1.11);
  EXPECT_EQ(ForceScalar(2.0, Unit::Force::Micronewton).Value(Unit::Force::Micronewton), 2.0);
}

TEST(ForceScalar, XML) {
  EXPECT_EQ(ForceScalar(1.11, Unit::Force::Newton).XML(),
            "<value>1.110000000000000</value><unit>N</unit>");
  EXPECT_EQ(ForceScalar(-2.22, Unit::Force::Micronewton).XML(Unit::Force::Micronewton),
            "<value>-2.220000000000000</value><unit>μN</unit>");
}

TEST(ForceScalar, YAML) {
  EXPECT_EQ(ForceScalar(1.11, Unit::Force::Newton).YAML(), "{value:1.110000000000000,unit:\"N\"}");
  EXPECT_EQ(ForceScalar(-2.22, Unit::Force::Micronewton).YAML(Unit::Force::Micronewton),
            "{value:-2.220000000000000,unit:\"μN\"}");
}

TEST(ForceScalar, Zero) {
  EXPECT_EQ(ForceScalar::Zero(), ForceScalar(0.0, Unit::Force::Newton));
}

}  // namespace

}  // namespace PhQ
