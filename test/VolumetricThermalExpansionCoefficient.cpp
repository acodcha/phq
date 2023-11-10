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

#include "../include/PhQ/VolumetricThermalExpansionCoefficient.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/ThermalExpansion.hpp"

namespace PhQ {

namespace {

TEST(VolumetricThermalExpansionCoefficient, ArithmeticOperatorAddition) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin)
                + VolumetricThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin),
            VolumetricThermalExpansionCoefficient(3.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, ArithmeticOperatorDivision) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(8.0, Unit::ThermalExpansion::PerKelvin) / 2.0,
            VolumetricThermalExpansionCoefficient(4.0, Unit::ThermalExpansion::PerKelvin));

  EXPECT_EQ(VolumetricThermalExpansionCoefficient(8.0, Unit::ThermalExpansion::PerKelvin)
                / VolumetricThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin),
            4.0);
}

TEST(VolumetricThermalExpansionCoefficient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(4.0, Unit::ThermalExpansion::PerKelvin) * 2.0,
            VolumetricThermalExpansionCoefficient(8.0, Unit::ThermalExpansion::PerKelvin));

  EXPECT_EQ(2.0 * VolumetricThermalExpansionCoefficient(4.0, Unit::ThermalExpansion::PerKelvin),
            VolumetricThermalExpansionCoefficient(8.0, Unit::ThermalExpansion::PerKelvin));

  EXPECT_EQ(VolumetricThermalExpansionCoefficient(4.0, Unit::ThermalExpansion::PerKelvin)
                * TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            8.0);
}

TEST(VolumetricThermalExpansionCoefficient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(3.0, Unit::ThermalExpansion::PerKelvin)
                - VolumetricThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin),
            VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, AssignmentOperatorAddition) {
  VolumetricThermalExpansionCoefficient quantity{1.0, Unit::ThermalExpansion::PerKelvin};
  quantity += VolumetricThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin);
  EXPECT_EQ(
      quantity, VolumetricThermalExpansionCoefficient(3.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, AssignmentOperatorDivision) {
  VolumetricThermalExpansionCoefficient quantity{8.0, Unit::ThermalExpansion::PerKelvin};
  quantity /= 2.0;
  EXPECT_EQ(
      quantity, VolumetricThermalExpansionCoefficient(4.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, AssignmentOperatorMultiplication) {
  VolumetricThermalExpansionCoefficient quantity{4.0, Unit::ThermalExpansion::PerKelvin};
  quantity *= 2.0;
  EXPECT_EQ(
      quantity, VolumetricThermalExpansionCoefficient(8.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, AssignmentOperatorSubtraction) {
  VolumetricThermalExpansionCoefficient quantity{3.0, Unit::ThermalExpansion::PerKelvin};
  quantity -= VolumetricThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin);
  EXPECT_EQ(
      quantity, VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, ComparisonOperators) {
  const VolumetricThermalExpansionCoefficient first{1.11, Unit::ThermalExpansion::PerKelvin};
  const VolumetricThermalExpansionCoefficient second{2.22, Unit::ThermalExpansion::PerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(VolumetricThermalExpansionCoefficient, CopyAssignmentOperator) {
  const VolumetricThermalExpansionCoefficient first{1.11, Unit::ThermalExpansion::PerKelvin};
  VolumetricThermalExpansionCoefficient second = VolumetricThermalExpansionCoefficient::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(VolumetricThermalExpansionCoefficient, CopyConstructor) {
  const VolumetricThermalExpansionCoefficient first{1.11, Unit::ThermalExpansion::PerKelvin};
  const VolumetricThermalExpansionCoefficient second{first};
  EXPECT_EQ(second, first);
}

TEST(VolumetricThermalExpansionCoefficient, Create) {
  constexpr VolumetricThermalExpansionCoefficient quantity =
      VolumetricThermalExpansionCoefficient::Create<Unit::ThermalExpansion::PerKelvin>(1.11);
  EXPECT_EQ(
      quantity, VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, DefaultConstructor) {
  EXPECT_NO_THROW(VolumetricThermalExpansionCoefficient{});
}

TEST(VolumetricThermalExpansionCoefficient, Dimensions) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient::Dimensions(),
            RelatedDimensions<Unit::ThermalExpansion>);
}

TEST(VolumetricThermalExpansionCoefficient, Hash) {
  const VolumetricThermalExpansionCoefficient first{1.11, Unit::ThermalExpansion::PerRankine};
  const VolumetricThermalExpansionCoefficient second{1.110001, Unit::ThermalExpansion::PerRankine};
  const VolumetricThermalExpansionCoefficient third{-1.11, Unit::ThermalExpansion::PerRankine};
  const std::hash<VolumetricThermalExpansionCoefficient> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(VolumetricThermalExpansionCoefficient, JSON) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerKelvin).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"/K\"}");
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(-2.22, Unit::ThermalExpansion::PerRankine)
                .JSON(Unit::ThermalExpansion::PerRankine),
            "{\"value\":-2.220000000000000,\"unit\":\"/°R\"}");
}

TEST(VolumetricThermalExpansionCoefficient, MoveAssignmentOperator) {
  VolumetricThermalExpansionCoefficient first{1.11, Unit::ThermalExpansion::PerKelvin};
  VolumetricThermalExpansionCoefficient second = VolumetricThermalExpansionCoefficient::Zero();
  second = std::move(first);
  EXPECT_EQ(second, VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, MoveConstructor) {
  VolumetricThermalExpansionCoefficient first{1.11, Unit::ThermalExpansion::PerKelvin};
  const VolumetricThermalExpansionCoefficient second{std::move(first)};
  EXPECT_EQ(second, VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, MutableValue) {
  VolumetricThermalExpansionCoefficient quantity{1.11, Unit::ThermalExpansion::PerKelvin};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(VolumetricThermalExpansionCoefficient, Print) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerKelvin).Print(),
            "1.110000000000000 /K");
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(-2.22, Unit::ThermalExpansion::PerRankine)
                .Print(Unit::ThermalExpansion::PerRankine),
            "-2.220000000000000 /°R");
}

TEST(VolumetricThermalExpansionCoefficient, SetValue) {
  VolumetricThermalExpansionCoefficient quantity{1.11, Unit::ThermalExpansion::PerKelvin};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(VolumetricThermalExpansionCoefficient, SizeOf) {
  EXPECT_EQ(sizeof(VolumetricThermalExpansionCoefficient{}), sizeof(double));
}

TEST(VolumetricThermalExpansionCoefficient, StandardConstructor) {
  EXPECT_NO_THROW(VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerRankine));
}

TEST(VolumetricThermalExpansionCoefficient, StaticValue) {
  constexpr VolumetricThermalExpansionCoefficient quantity =
      VolumetricThermalExpansionCoefficient::Create<Unit::ThermalExpansion::PerRankine>(1.11);
  constexpr double value = quantity.StaticValue<Unit::ThermalExpansion::PerRankine>();
  EXPECT_EQ(value, 1.11);
}

TEST(VolumetricThermalExpansionCoefficient, Stream) {
  std::ostringstream stream;
  stream << VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerKelvin);
  EXPECT_EQ(stream.str(),
            VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerKelvin).Print());
}

TEST(VolumetricThermalExpansionCoefficient, Unit) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient::Unit(), Standard<Unit::ThermalExpansion>);
}

TEST(VolumetricThermalExpansionCoefficient, Value) {
  EXPECT_EQ(
      VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerKelvin).Value(), 1.11);
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerRankine)
                .Value(Unit::ThermalExpansion::PerRankine),
            1.11);
}

TEST(VolumetricThermalExpansionCoefficient, XML) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerKelvin).XML(),
            "<value>1.110000000000000</value><unit>/K</unit>");
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(-2.22, Unit::ThermalExpansion::PerRankine)
                .XML(Unit::ThermalExpansion::PerRankine),
            "<value>-2.220000000000000</value><unit>/°R</unit>");
}

TEST(VolumetricThermalExpansionCoefficient, YAML) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.11, Unit::ThermalExpansion::PerKelvin).YAML(),
            "{value:1.110000000000000,unit:\"/K\"}");
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(-2.22, Unit::ThermalExpansion::PerRankine)
                .YAML(Unit::ThermalExpansion::PerRankine),
            "{value:-2.220000000000000,unit:\"/°R\"}");
}

TEST(VolumetricThermalExpansionCoefficient, Zero) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient::Zero(),
            VolumetricThermalExpansionCoefficient(0.0, Unit::ThermalExpansion::PerKelvin));
}

}  // namespace

}  // namespace PhQ
