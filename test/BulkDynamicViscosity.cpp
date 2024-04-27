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

#include "../include/PhQ/BulkDynamicViscosity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/DynamicViscosity.hpp"

namespace PhQ {

namespace {

TEST(BulkDynamicViscosity, ArithmeticOperatorAddition) {
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)
                + BulkDynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            BulkDynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, ArithmeticOperatorDivision) {
  EXPECT_EQ(BulkDynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond) / 2.0,
            BulkDynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(BulkDynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond)
                / BulkDynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            4.0);
}

TEST(BulkDynamicViscosity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(BulkDynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond) * 2.0,
            BulkDynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(2.0 * BulkDynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond),
            BulkDynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(BulkDynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond)
                - BulkDynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, AssignmentOperatorAddition) {
  BulkDynamicViscosity quantity{1.0, Unit::DynamicViscosity::PascalSecond};
  quantity += BulkDynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond);
  EXPECT_EQ(quantity, BulkDynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, AssignmentOperatorDivision) {
  BulkDynamicViscosity quantity{8.0, Unit::DynamicViscosity::PascalSecond};
  quantity /= 2.0;
  EXPECT_EQ(quantity, BulkDynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, AssignmentOperatorMultiplication) {
  BulkDynamicViscosity quantity{4.0, Unit::DynamicViscosity::PascalSecond};
  quantity *= 2.0;
  EXPECT_EQ(quantity, BulkDynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, AssignmentOperatorSubtraction) {
  BulkDynamicViscosity quantity{3.0, Unit::DynamicViscosity::PascalSecond};
  quantity -= BulkDynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond);
  EXPECT_EQ(quantity, BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, ComparisonOperators) {
  const BulkDynamicViscosity first{1.11, Unit::DynamicViscosity::PascalSecond};
  const BulkDynamicViscosity second{2.22, Unit::DynamicViscosity::PascalSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(BulkDynamicViscosity, CopyAssignmentOperator) {
  const BulkDynamicViscosity first{1.11, Unit::DynamicViscosity::PascalSecond};
  BulkDynamicViscosity second = BulkDynamicViscosity::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(BulkDynamicViscosity, CopyConstructor) {
  const BulkDynamicViscosity first{1.11, Unit::DynamicViscosity::PascalSecond};
  const BulkDynamicViscosity second{first};
  EXPECT_EQ(second, first);
}

TEST(BulkDynamicViscosity, Create) {
  constexpr BulkDynamicViscosity quantity =
      BulkDynamicViscosity::Create<Unit::DynamicViscosity::PascalSecond>(1.11);
  EXPECT_EQ(quantity, BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, DefaultConstructor) {
  EXPECT_NO_THROW(BulkDynamicViscosity{});
}

TEST(BulkDynamicViscosity, Dimensions) {
  EXPECT_EQ(BulkDynamicViscosity::Dimensions(), RelatedDimensions<Unit::DynamicViscosity>);
}

TEST(BulkDynamicViscosity, Hash) {
  const BulkDynamicViscosity first{1.11, Unit::DynamicViscosity::KilopascalSecond};
  const BulkDynamicViscosity second{1.110001, Unit::DynamicViscosity::KilopascalSecond};
  const BulkDynamicViscosity third{-1.11, Unit::DynamicViscosity::KilopascalSecond};
  const std::hash<BulkDynamicViscosity> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(BulkDynamicViscosity, JSON) {
  EXPECT_EQ(BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Pa·s\"}");
  EXPECT_EQ(BulkDynamicViscosity(-2.22, Unit::DynamicViscosity::KilopascalSecond)
                .JSON(Unit::DynamicViscosity::KilopascalSecond),
            "{\"value\":-2.220000000000000,\"unit\":\"kPa·s\"}");
}

TEST(BulkDynamicViscosity, MoveAssignmentOperator) {
  BulkDynamicViscosity first{1.11, Unit::DynamicViscosity::PascalSecond};
  BulkDynamicViscosity second = BulkDynamicViscosity::Zero();
  second = std::move(first);
  EXPECT_EQ(second, BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, MoveConstructor) {
  BulkDynamicViscosity first{1.11, Unit::DynamicViscosity::PascalSecond};
  const BulkDynamicViscosity second{std::move(first)};
  EXPECT_EQ(second, BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, MutableValue) {
  BulkDynamicViscosity quantity{1.11, Unit::DynamicViscosity::PascalSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(BulkDynamicViscosity, Print) {
  EXPECT_EQ(BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).Print(),
            "1.110000000000000 Pa·s");
  EXPECT_EQ(BulkDynamicViscosity(-2.22, Unit::DynamicViscosity::KilopascalSecond)
                .Print(Unit::DynamicViscosity::KilopascalSecond),
            "-2.220000000000000 kPa·s");
}

TEST(BulkDynamicViscosity, SetValue) {
  BulkDynamicViscosity quantity{1.11, Unit::DynamicViscosity::PascalSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(BulkDynamicViscosity, SizeOf) {
  EXPECT_EQ(sizeof(BulkDynamicViscosity{}), sizeof(double));
}

TEST(BulkDynamicViscosity, StandardConstructor) {
  EXPECT_NO_THROW(BulkDynamicViscosity(1.11, Unit::DynamicViscosity::KilopascalSecond));
}

TEST(BulkDynamicViscosity, StaticValue) {
  constexpr BulkDynamicViscosity quantity =
      BulkDynamicViscosity::Create<Unit::DynamicViscosity::KilopascalSecond>(1.11);
  constexpr double value = quantity.StaticValue<Unit::DynamicViscosity::KilopascalSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(BulkDynamicViscosity, Stream) {
  std::ostringstream stream;
  stream << BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond);
  EXPECT_EQ(stream.str(), BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).Print());
}

TEST(BulkDynamicViscosity, Unit) {
  EXPECT_EQ(BulkDynamicViscosity::Unit(), Standard<Unit::DynamicViscosity>);
}

TEST(BulkDynamicViscosity, Value) {
  EXPECT_EQ(BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).Value(), 1.11);
  EXPECT_EQ(BulkDynamicViscosity(1.11, Unit::DynamicViscosity::KilopascalSecond)
                .Value(Unit::DynamicViscosity::KilopascalSecond),
            1.11);
}

TEST(BulkDynamicViscosity, XML) {
  EXPECT_EQ(BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).XML(),
            "<value>1.110000000000000</value><unit>Pa·s</unit>");
  EXPECT_EQ(BulkDynamicViscosity(-2.22, Unit::DynamicViscosity::KilopascalSecond)
                .XML(Unit::DynamicViscosity::KilopascalSecond),
            "<value>-2.220000000000000</value><unit>kPa·s</unit>");
}

TEST(BulkDynamicViscosity, YAML) {
  EXPECT_EQ(BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).YAML(),
            "{value:1.110000000000000,unit:\"Pa·s\"}");
  EXPECT_EQ(BulkDynamicViscosity(-2.22, Unit::DynamicViscosity::KilopascalSecond)
                .YAML(Unit::DynamicViscosity::KilopascalSecond),
            "{value:-2.220000000000000,unit:\"kPa·s\"}");
}

TEST(BulkDynamicViscosity, Zero) {
  EXPECT_EQ(BulkDynamicViscosity::Zero(),
            BulkDynamicViscosity(0.0, Unit::DynamicViscosity::PascalSecond));
}

}  // namespace

}  // namespace PhQ
