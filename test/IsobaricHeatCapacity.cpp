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

#include "../include/PhQ/IsobaricHeatCapacity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/HeatCapacityRatio.hpp"
#include "../include/PhQ/IsochoricHeatCapacity.hpp"
#include "../include/PhQ/Unit/HeatCapacity.hpp"

namespace PhQ {

namespace {

TEST(IsobaricHeatCapacity, ArithmeticOperatorAddition) {
  EXPECT_EQ(IsobaricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin)
                + IsobaricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
            IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsobaricHeatCapacity, ArithmeticOperatorDivision) {
  EXPECT_EQ(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin) / 2.0,
            IsobaricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / IsobaricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
            4.0);

  EXPECT_EQ(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin) / HeatCapacityRatio(2.0),
            IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin),
            HeatCapacityRatio(2.0));
}

TEST(IsobaricHeatCapacity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(IsobaricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin) * 2.0,
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(2.0 * IsobaricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin),
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(HeatCapacityRatio(2.0) * IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin),
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin) * HeatCapacityRatio(2.0),
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsobaricHeatCapacity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin)
                - IsobaricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
            IsobaricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsobaricHeatCapacity, AssignmentOperatorAddition) {
  IsobaricHeatCapacity quantity{1.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity += IsobaricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(quantity, IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsobaricHeatCapacity, AssignmentOperatorDivision) {
  IsobaricHeatCapacity quantity{8.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity /= 2.0;
  EXPECT_EQ(quantity, IsobaricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsobaricHeatCapacity, AssignmentOperatorMultiplication) {
  IsobaricHeatCapacity quantity{4.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity *= 2.0;
  EXPECT_EQ(quantity, IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsobaricHeatCapacity, AssignmentOperatorSubtraction) {
  IsobaricHeatCapacity quantity{3.0, Unit::HeatCapacity::JoulePerKelvin};
  quantity -= IsobaricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(quantity, IsobaricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsobaricHeatCapacity, ComparisonOperators) {
  const IsobaricHeatCapacity first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  const IsobaricHeatCapacity second{2.22, Unit::HeatCapacity::JoulePerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(IsobaricHeatCapacity, CopyAssignmentOperator) {
  const IsobaricHeatCapacity first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  IsobaricHeatCapacity second = IsobaricHeatCapacity::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(IsobaricHeatCapacity, CopyConstructor) {
  const IsobaricHeatCapacity first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  const IsobaricHeatCapacity second{first};
  EXPECT_EQ(second, first);
}

TEST(IsobaricHeatCapacity, Create) {
  constexpr IsobaricHeatCapacity quantity =
      IsobaricHeatCapacity::Create<Unit::HeatCapacity::JoulePerKelvin>(1.11);
  EXPECT_EQ(quantity, IsobaricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsobaricHeatCapacity, DefaultConstructor) {
  EXPECT_NO_THROW(IsobaricHeatCapacity{});
}

TEST(IsobaricHeatCapacity, Dimensions) {
  EXPECT_EQ(IsobaricHeatCapacity::Dimensions(), RelatedDimensions<Unit::HeatCapacity>);
}

TEST(IsobaricHeatCapacity, Hash) {
  const IsobaricHeatCapacity first{1.11, Unit::HeatCapacity::NanojoulePerKelvin};
  const IsobaricHeatCapacity second{1.110001, Unit::HeatCapacity::NanojoulePerKelvin};
  const IsobaricHeatCapacity third{-1.11, Unit::HeatCapacity::NanojoulePerKelvin};
  const std::hash<IsobaricHeatCapacity> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(IsobaricHeatCapacity, JSON) {
  EXPECT_EQ(IsobaricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"J/K\"}");
  EXPECT_EQ(IsobaricHeatCapacity(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .JSON(Unit::HeatCapacity::NanojoulePerKelvin),
            "{\"value\":-2.220000000000000,\"unit\":\"nJ/K\"}");
}

TEST(IsobaricHeatCapacity, MiscellaneousConstructors) {
  EXPECT_EQ(IsobaricHeatCapacity(HeatCapacityRatio(2.0),
                                 IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin)),
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(HeatCapacityRatio(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin),
                              IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin)),
            HeatCapacityRatio(2.0));

  EXPECT_EQ(IsochoricHeatCapacity(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin),
                                  HeatCapacityRatio(2.0)),
            IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsobaricHeatCapacity, MoveAssignmentOperator) {
  IsobaricHeatCapacity first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  IsobaricHeatCapacity second = IsobaricHeatCapacity::Zero();
  second = std::move(first);
  EXPECT_EQ(second, IsobaricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsobaricHeatCapacity, MoveConstructor) {
  IsobaricHeatCapacity first{1.11, Unit::HeatCapacity::JoulePerKelvin};
  const IsobaricHeatCapacity second{std::move(first)};
  EXPECT_EQ(second, IsobaricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsobaricHeatCapacity, MutableValue) {
  IsobaricHeatCapacity quantity{1.11, Unit::HeatCapacity::JoulePerKelvin};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(IsobaricHeatCapacity, Print) {
  EXPECT_EQ(IsobaricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).Print(),
            "1.110000000000000 J/K");
  EXPECT_EQ(IsobaricHeatCapacity(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .Print(Unit::HeatCapacity::NanojoulePerKelvin),
            "-2.220000000000000 nJ/K");
}

TEST(IsobaricHeatCapacity, SetValue) {
  IsobaricHeatCapacity quantity{1.11, Unit::HeatCapacity::JoulePerKelvin};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(IsobaricHeatCapacity, SizeOf) {
  EXPECT_EQ(sizeof(IsobaricHeatCapacity{}), sizeof(double));
}

TEST(IsobaricHeatCapacity, StandardConstructor) {
  EXPECT_NO_THROW(IsobaricHeatCapacity(1.11, Unit::HeatCapacity::NanojoulePerKelvin));
}

TEST(IsobaricHeatCapacity, StaticValue) {
  constexpr IsobaricHeatCapacity quantity =
      IsobaricHeatCapacity::Create<Unit::HeatCapacity::NanojoulePerKelvin>(2.0);
  constexpr double value = quantity.StaticValue<Unit::HeatCapacity::NanojoulePerKelvin>();
  EXPECT_EQ(value, 2.0);
}

TEST(IsobaricHeatCapacity, Stream) {
  std::ostringstream stream;
  stream << IsobaricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(stream.str(), IsobaricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).Print());
}

TEST(IsobaricHeatCapacity, Unit) {
  EXPECT_EQ(IsobaricHeatCapacity::Unit(), Standard<Unit::HeatCapacity>);
}

TEST(IsobaricHeatCapacity, Value) {
  EXPECT_EQ(IsobaricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).Value(), 1.11);
  EXPECT_EQ(IsobaricHeatCapacity(2.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .Value(Unit::HeatCapacity::NanojoulePerKelvin),
            2.0);
}

TEST(IsobaricHeatCapacity, XML) {
  EXPECT_EQ(IsobaricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).XML(),
            "<value>1.110000000000000</value><unit>J/K</unit>");
  EXPECT_EQ(IsobaricHeatCapacity(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .XML(Unit::HeatCapacity::NanojoulePerKelvin),
            "<value>-2.220000000000000</value><unit>nJ/K</unit>");
}

TEST(IsobaricHeatCapacity, YAML) {
  EXPECT_EQ(IsobaricHeatCapacity(1.11, Unit::HeatCapacity::JoulePerKelvin).YAML(),
            "{value:1.110000000000000,unit:\"J/K\"}");
  EXPECT_EQ(IsobaricHeatCapacity(-2.22, Unit::HeatCapacity::NanojoulePerKelvin)
                .YAML(Unit::HeatCapacity::NanojoulePerKelvin),
            "{value:-2.220000000000000,unit:\"nJ/K\"}");
}

TEST(IsobaricHeatCapacity, Zero) {
  EXPECT_EQ(
      IsobaricHeatCapacity::Zero(), IsobaricHeatCapacity(0.0, Unit::HeatCapacity::JoulePerKelvin));
}

}  // namespace

}  // namespace PhQ
