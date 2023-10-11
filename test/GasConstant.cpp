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

#include "../include/PhQ/GasConstant.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(GasConstant, ArithmeticOperatorAddition) {
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin)
                + GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin),
            GasConstant(3.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(
      GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin)
          + IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
      IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin)
                + GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin),
            IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, ArithmeticOperatorDivision) {
  EXPECT_EQ(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin) / 2.0,
            GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin),
            4.0);
}

TEST(GasConstant, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin) * 2.0,
            GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(2.0 * GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin),
            GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(GasConstant(3.0, Unit::HeatCapacity::JoulePerKelvin)
                - GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin),
            GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(
      IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin)
          - IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
      GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin)
                - GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin),
            IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, AssignmentOperatorAddition) {
  GasConstant quantity{1.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity += GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(quantity, GasConstant(3.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, AssignmentOperatorDivision) {
  GasConstant quantity{8.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity /= 2.0;
  EXPECT_EQ(quantity, GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, AssignmentOperatorMultiplication) {
  GasConstant quantity{4.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity *= 2.0;
  EXPECT_EQ(quantity, GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, AssignmentOperatorSubtraction) {
  GasConstant quantity{3.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity -= GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(quantity, GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, ComparisonOperators) {
  const GasConstant first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  const GasConstant second{2.22, Unit::HeatCapacity::JoulePerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(GasConstant, CopyAssignmentOperator) {
  const GasConstant first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  GasConstant second = GasConstant::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(GasConstant, CopyConstructor) {
  const GasConstant first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  const GasConstant second{first};
  EXPECT_EQ(second, first);
}

TEST(GasConstant, Create) {
  constexpr GasConstant quantity =
      GasConstant::Create<Unit::HeatCapacity::JoulePerKelvin>(1.11);
  EXPECT_EQ(quantity, GasConstant(1.11, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, DefaultConstructor) {
  EXPECT_NO_THROW(GasConstant{});
}

TEST(GasConstant, Dimensions) {
  EXPECT_EQ(GasConstant::Dimensions(), RelatedDimensions<Unit::HeatCapacity>);
}

TEST(GasConstant, Hash) {
  const GasConstant first{1.11, Unit::HeatCapacity::NanojoulePerKelvin};
  const GasConstant second{1.110001, Unit::HeatCapacity::NanojoulePerKelvin};
  const GasConstant third{-1.11, Unit::HeatCapacity::NanojoulePerKelvin};
  const std::hash<GasConstant> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(GasConstant, JSON) {
  EXPECT_EQ(GasConstant(1.11, Unit::HeatCapacity::JoulePerKelvin).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"J/K\"}");
  EXPECT_EQ(GasConstant(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .JSON(Unit::HeatCapacity::NanojoulePerKelvin),
            "{\"value\":-2.220000000000000,\"unit\":\"nJ/K\"}");
}

TEST(GasConstant, MiscellaneousConstructors) {
  EXPECT_EQ(GasConstant(
                IsobaricHeatCapacity(6.0, Unit::HeatCapacity::JoulePerKelvin),
                IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin)),
            GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(GasConstant(
                HeatCapacityRatio(2.0),
                IsobaricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin)),
            GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(GasConstant(
                HeatCapacityRatio(2.0),
                IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin)),
            GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(HeatCapacityRatio(
                IsobaricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin),
                GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin)),
            HeatCapacityRatio(2.0));

  EXPECT_EQ(HeatCapacityRatio(
                GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin),
                IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin)),
            HeatCapacityRatio(3.0));

  EXPECT_EQ(IsochoricHeatCapacity(
                IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin),
                GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin)),
            IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(IsochoricHeatCapacity(
                GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin),
                HeatCapacityRatio(2.0)),
            IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(IsobaricHeatCapacity(
                IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
                GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin)),
            IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(IsobaricHeatCapacity(
                HeatCapacityRatio(2.0),
                GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin)),
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, MoveAssignmentOperator) {
  GasConstant first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  GasConstant second = GasConstant::Zero();
  second = std::move(first);
  EXPECT_EQ(second, GasConstant(1.11, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, MoveConstructor) {
  GasConstant first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  GasConstant second{std::move(first)};
  EXPECT_EQ(second, GasConstant(1.11, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, MutableValue) {
  GasConstant quantity{1.11, Unit::HeatCapacity::JoulePerKelvin};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(GasConstant, Print) {
  EXPECT_EQ(GasConstant(1.11, Unit::HeatCapacity::JoulePerKelvin).Print(),
            "1.110000000000000 J/K");
  EXPECT_EQ(GasConstant(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .Print(Unit::HeatCapacity::NanojoulePerKelvin),
            "-2.220000000000000 nJ/K");
}

TEST(GasConstant, SetValue) {
  GasConstant quantity{1.11, Unit::HeatCapacity::JoulePerKelvin};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(GasConstant, SizeOf) {
  EXPECT_EQ(sizeof(GasConstant{}), sizeof(double));
}

TEST(GasConstant, StandardConstructor) {
  EXPECT_NO_THROW(GasConstant(1.11, Unit::HeatCapacity::NanojoulePerKelvin));
}

TEST(GasConstant, StaticValue) {
  constexpr GasConstant quantity =
      GasConstant::Create<Unit::HeatCapacity::NanojoulePerKelvin>(1.11);
  constexpr double value =
      quantity.StaticValue<Unit::HeatCapacity::NanojoulePerKelvin>();
  EXPECT_EQ(value, 1.11);
}

TEST(GasConstant, Stream) {
  std::ostringstream stream;
  stream << GasConstant(1.11, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(stream.str(),
            GasConstant(1.11, Unit::HeatCapacity::JoulePerKelvin).Print());
}

TEST(GasConstant, Unit) {
  EXPECT_EQ(GasConstant::Unit(), Standard<Unit::HeatCapacity>);
}

TEST(GasConstant, Value) {
  EXPECT_EQ(
      GasConstant(1.11, Unit::HeatCapacity::JoulePerKelvin).Value(), 1.11);
  EXPECT_EQ(GasConstant(1.11, Unit::HeatCapacity::NanojoulePerKelvin)
                .Value(Unit::HeatCapacity::NanojoulePerKelvin),
            1.11);
}

TEST(GasConstant, XML) {
  EXPECT_EQ(GasConstant(1.11, Unit::HeatCapacity::JoulePerKelvin).XML(),
            "<value>1.110000000000000</value><unit>J/K</unit>");
  EXPECT_EQ(GasConstant(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .XML(Unit::HeatCapacity::NanojoulePerKelvin),
            "<value>-2.220000000000000</value><unit>nJ/K</unit>");
}

TEST(GasConstant, YAML) {
  EXPECT_EQ(GasConstant(1.11, Unit::HeatCapacity::JoulePerKelvin).YAML(),
            "{value:1.110000000000000,unit:\"J/K\"}");
  EXPECT_EQ(GasConstant(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .YAML(Unit::HeatCapacity::NanojoulePerKelvin),
            "{value:-2.220000000000000,unit:\"nJ/K\"}");
}

TEST(GasConstant, Zero) {
  EXPECT_EQ(GasConstant::Zero(),
            GasConstant(0.0, Unit::HeatCapacity::JoulePerKelvin));
}

}  // namespace

}  // namespace PhQ
