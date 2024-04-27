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

#include "../include/PhQ/IsochoricHeatCapacity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/HeatCapacity.hpp"

namespace PhQ {

namespace {

TEST(IsochoricHeatCapacity, ArithmeticOperatorAddition) {
  EXPECT_EQ(IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin)
                + IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
            IsochoricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, ArithmeticOperatorDivision) {
  EXPECT_EQ(IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin) / 2.0,
            IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
            4.0);
}

TEST(IsochoricHeatCapacity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin) * 2.0,
            IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(2.0 * IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin),
            IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(IsochoricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin)
                - IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
            IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, AssignmentOperatorAddition) {
  IsochoricHeatCapacity quantity{1.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity += IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(quantity, IsochoricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, AssignmentOperatorDivision) {
  IsochoricHeatCapacity quantity{8.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity /= 2.0;
  EXPECT_EQ(quantity, IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, AssignmentOperatorMultiplication) {
  IsochoricHeatCapacity quantity{4.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity *= 2.0;
  EXPECT_EQ(quantity, IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, AssignmentOperatorSubtraction) {
  IsochoricHeatCapacity quantity{3.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity -= IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(quantity, IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, ComparisonOperators) {
  const IsochoricHeatCapacity first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  const IsochoricHeatCapacity second{2.22, Unit::HeatCapacity::JoulePerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(IsochoricHeatCapacity, CopyAssignmentOperator) {
  const IsochoricHeatCapacity first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  IsochoricHeatCapacity second = IsochoricHeatCapacity::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(IsochoricHeatCapacity, CopyConstructor) {
  const IsochoricHeatCapacity first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  const IsochoricHeatCapacity second{first};
  EXPECT_EQ(second, first);
}

TEST(IsochoricHeatCapacity, Create) {
  constexpr IsochoricHeatCapacity quantity =
      IsochoricHeatCapacity::Create<Unit::HeatCapacity::JoulePerKelvin>(1.11);
  EXPECT_EQ(quantity, IsochoricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, DefaultConstructor) {
  EXPECT_NO_THROW(IsochoricHeatCapacity{});
}

TEST(IsochoricHeatCapacity, Dimensions) {
  EXPECT_EQ(IsochoricHeatCapacity::Dimensions(), RelatedDimensions<Unit::HeatCapacity>);
}

TEST(IsochoricHeatCapacity, Hash) {
  const IsochoricHeatCapacity first{1.11, Unit::HeatCapacity::NanojoulePerKelvin};
  const IsochoricHeatCapacity second{1.110001, Unit::HeatCapacity::NanojoulePerKelvin};
  const IsochoricHeatCapacity third{-1.11, Unit::HeatCapacity::NanojoulePerKelvin};
  const std::hash<IsochoricHeatCapacity> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(IsochoricHeatCapacity, JSON) {
  EXPECT_EQ(IsochoricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"J/K\"}");
  EXPECT_EQ(IsochoricHeatCapacity(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .JSON(Unit::HeatCapacity::NanojoulePerKelvin),
            "{\"value\":-2.220000000000000,\"unit\":\"nJ/K\"}");
}

TEST(IsochoricHeatCapacity, MoveAssignmentOperator) {
  IsochoricHeatCapacity first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  IsochoricHeatCapacity second = IsochoricHeatCapacity::Zero();
  second = std::move(first);
  EXPECT_EQ(second, IsochoricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, MoveConstructor) {
  IsochoricHeatCapacity first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  const IsochoricHeatCapacity second{std::move(first)};
  EXPECT_EQ(second, IsochoricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, MutableValue) {
  IsochoricHeatCapacity quantity{1.11, Unit::HeatCapacity::JoulePerKelvin};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(IsochoricHeatCapacity, Print) {
  EXPECT_EQ(IsochoricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).Print(),
            "1.110000000000000 J/K");
  EXPECT_EQ(IsochoricHeatCapacity(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .Print(Unit::HeatCapacity::NanojoulePerKelvin),
            "-2.220000000000000 nJ/K");
}

TEST(IsochoricHeatCapacity, SetValue) {
  IsochoricHeatCapacity quantity{1.11, Unit::HeatCapacity::JoulePerKelvin};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(IsochoricHeatCapacity, SizeOf) {
  EXPECT_EQ(sizeof(IsochoricHeatCapacity{}), sizeof(double));
}

TEST(IsochoricHeatCapacity, StandardConstructor) {
  EXPECT_NO_THROW(IsochoricHeatCapacity(1.11, Unit::HeatCapacity::NanojoulePerKelvin));
}

TEST(IsochoricHeatCapacity, StaticValue) {
  constexpr IsochoricHeatCapacity quantity =
      IsochoricHeatCapacity::Create<Unit::HeatCapacity::NanojoulePerKelvin>(2.0);
  constexpr double value = quantity.StaticValue<Unit::HeatCapacity::NanojoulePerKelvin>();
  EXPECT_EQ(value, 2.0);
}

TEST(IsochoricHeatCapacity, Stream) {
  std::ostringstream stream;
  stream << IsochoricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(stream.str(), IsochoricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).Print());
}

TEST(IsochoricHeatCapacity, Unit) {
  EXPECT_EQ(IsochoricHeatCapacity::Unit(), Standard<Unit::HeatCapacity>);
}

TEST(IsochoricHeatCapacity, Value) {
  EXPECT_EQ(IsochoricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).Value(), 1.11);
  EXPECT_EQ(IsochoricHeatCapacity(2.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .Value(Unit::HeatCapacity::NanojoulePerKelvin),
            2.0);
}

TEST(IsochoricHeatCapacity, XML) {
  EXPECT_EQ(IsochoricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).XML(),
            "<value>1.110000000000000</value><unit>J/K</unit>");
  EXPECT_EQ(IsochoricHeatCapacity(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .XML(Unit::HeatCapacity::NanojoulePerKelvin),
            "<value>-2.220000000000000</value><unit>nJ/K</unit>");
}

TEST(IsochoricHeatCapacity, YAML) {
  EXPECT_EQ(IsochoricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).YAML(),
            "{value:1.110000000000000,unit:\"J/K\"}");
  EXPECT_EQ(IsochoricHeatCapacity(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .YAML(Unit::HeatCapacity::NanojoulePerKelvin),
            "{value:-2.220000000000000,unit:\"nJ/K\"}");
}

TEST(IsochoricHeatCapacity, Zero) {
  EXPECT_EQ(IsochoricHeatCapacity::Zero(),
            IsochoricHeatCapacity(0.0, Unit::HeatCapacity::JoulePerKelvin));
}

}  // namespace

}  // namespace PhQ
