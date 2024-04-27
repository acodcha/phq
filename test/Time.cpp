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

#include "../include/PhQ/Time.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(Time, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      Time(1.0, Unit::Time::Second) + Time(2.0, Unit::Time::Second), Time(3.0, Unit::Time::Second));
}

TEST(Time, ArithmeticOperatorDivision) {
  EXPECT_EQ(Time(8.0, Unit::Time::Second) / 2.0, Time(4.0, Unit::Time::Second));

  EXPECT_EQ(Time(8.0, Unit::Time::Second) / Time(2.0, Unit::Time::Second), 4.0);
}

TEST(Time, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Time(4.0, Unit::Time::Second) * 2.0, Time(8.0, Unit::Time::Second));

  EXPECT_EQ(2.0 * Time(4.0, Unit::Time::Second), Time(8.0, Unit::Time::Second));
}

TEST(Time, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      Time(3.0, Unit::Time::Second) - Time(2.0, Unit::Time::Second), Time(1.0, Unit::Time::Second));
}

TEST(Time, AssignmentOperatorAddition) {
  Time quantity{1.0, Unit::Time::Second};
  quantity += Time(2.0, Unit::Time::Second);
  EXPECT_EQ(quantity, Time(3.0, Unit::Time::Second));
}

TEST(Time, AssignmentOperatorDivision) {
  Time quantity{8.0, Unit::Time::Second};
  quantity /= 2.0;
  EXPECT_EQ(quantity, Time(4.0, Unit::Time::Second));
}

TEST(Time, AssignmentOperatorMultiplication) {
  Time quantity{4.0, Unit::Time::Second};
  quantity *= 2.0;
  EXPECT_EQ(quantity, Time(8.0, Unit::Time::Second));
}

TEST(Time, AssignmentOperatorSubtraction) {
  Time quantity{3.0, Unit::Time::Second};
  quantity -= Time(2.0, Unit::Time::Second);
  EXPECT_EQ(quantity, Time(1.0, Unit::Time::Second));
}

TEST(Time, ComparisonOperators) {
  const Time first{0.1, Unit::Time::Second};
  const Time second{0.2, Unit::Time::Second};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Time, CopyAssignmentOperator) {
  const Time first{1.11, Unit::Time::Second};
  Time second = Time::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Time, CopyConstructor) {
  const Time first{1.11, Unit::Time::Second};
  const Time second{first};
  EXPECT_EQ(second, first);
}

TEST(Time, Create) {
  constexpr Time quantity = Time::Create<Unit::Time::Second>(1.11);
  EXPECT_EQ(quantity, Time(1.11, Unit::Time::Second));
}

TEST(Time, DefaultConstructor) {
  EXPECT_NO_THROW(Time{});
}

TEST(Time, Dimensions) {
  EXPECT_EQ(Time::Dimensions(), RelatedDimensions<Unit::Time>);
}

TEST(Time, Hash) {
  const Time first{1.11, Unit::Time::Second};
  const Time second{1.110001, Unit::Time::Second};
  const Time third{-1.11, Unit::Time::Second};
  const std::hash<Time> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Time, JSON) {
  EXPECT_EQ(Time(1.11, Unit::Time::Second).JSON(), "{\"value\":1.110000000000000,\"unit\":\"s\"}");
  EXPECT_EQ(Time(-2.22, Unit::Time::Minute).JSON(Unit::Time::Minute),
            "{\"value\":-2.220000000000000,\"unit\":\"min\"}");
}

TEST(Time, MoveAssignmentOperator) {
  Time first{1.11, Unit::Time::Second};
  Time second = Time::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Time(1.11, Unit::Time::Second));
}

TEST(Time, MoveConstructor) {
  Time first{1.11, Unit::Time::Second};
  const Time second{std::move(first)};
  EXPECT_EQ(second, Time(1.11, Unit::Time::Second));
}

TEST(Time, MutableValue) {
  Time quantity{1.11, Unit::Time::Second};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Time, Print) {
  EXPECT_EQ(Time(1.11, Unit::Time::Second).Print(), "1.110000000000000 s");
  EXPECT_EQ(Time(-2.22, Unit::Time::Minute).Print(Unit::Time::Minute), "-2.220000000000000 min");
}

TEST(Time, SetValue) {
  Time quantity{1.11, Unit::Time::Second};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Time, SizeOf) {
  EXPECT_EQ(sizeof(Time{}), sizeof(double));
}

TEST(Time, StandardConstructor) {
  EXPECT_NO_THROW(Time(1.11, Unit::Time::Minute));
}

TEST(Time, StaticValue) {
  constexpr Time quantity = Time::Create<Unit::Time::Minute>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Time::Minute>();
  EXPECT_EQ(value, 1.11);
}

TEST(Time, Stream) {
  std::ostringstream stream;
  stream << Time(1.11, Unit::Time::Second);
  EXPECT_EQ(stream.str(), Time(1.11, Unit::Time::Second).Print());
}

TEST(Time, Unit) {
  EXPECT_EQ(Time::Unit(), Standard<Unit::Time>);
}

TEST(Time, Value) {
  EXPECT_EQ(Time(1.11, Unit::Time::Second).Value(), 1.11);
  EXPECT_EQ(Time(1.11, Unit::Time::Minute).Value(Unit::Time::Minute), 1.11);
}

TEST(Time, XML) {
  EXPECT_EQ(Time(1.11, Unit::Time::Second).XML(), "<value>1.110000000000000</value><unit>s</unit>");
  EXPECT_EQ(Time(-2.22, Unit::Time::Minute).XML(Unit::Time::Minute),
            "<value>-2.220000000000000</value><unit>min</unit>");
}

TEST(Time, YAML) {
  EXPECT_EQ(Time(1.11, Unit::Time::Second).YAML(), "{value:1.110000000000000,unit:\"s\"}");
  EXPECT_EQ(Time(-2.22, Unit::Time::Minute).YAML(Unit::Time::Minute),
            "{value:-2.220000000000000,unit:\"min\"}");
}

TEST(Time, Zero) {
  EXPECT_EQ(Time::Zero(), Time(0.0, Unit::Time::Second));
}

}  // namespace

}  // namespace PhQ
