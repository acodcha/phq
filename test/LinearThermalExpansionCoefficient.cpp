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

#include "../include/PhQ/LinearThermalExpansionCoefficient.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/ScalarStrain.hpp"
#include "../include/PhQ/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/ThermalExpansion.hpp"

namespace PhQ {

namespace {

TEST(LinearThermalExpansionCoefficient, ArithmeticOperatorAddition) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin)
                + LinearThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin),
            LinearThermalExpansionCoefficient(3.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, ArithmeticOperatorDivision) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(8.0, Unit::ThermalExpansion::PerKelvin) / 2.0,
            LinearThermalExpansionCoefficient(4.0, Unit::ThermalExpansion::PerKelvin));
  EXPECT_EQ(LinearThermalExpansionCoefficient(8.0, Unit::ThermalExpansion::PerKelvin)
                / LinearThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin),
            4.0);
}

TEST(LinearThermalExpansionCoefficient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(4.0, Unit::ThermalExpansion::PerKelvin) * 2.0,
            LinearThermalExpansionCoefficient(8.0, Unit::ThermalExpansion::PerKelvin));
  EXPECT_EQ(2.0 * LinearThermalExpansionCoefficient(4.0, Unit::ThermalExpansion::PerKelvin),
            LinearThermalExpansionCoefficient(8.0, Unit::ThermalExpansion::PerKelvin));
  EXPECT_EQ(LinearThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin)
                * TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin),
            ScalarStrain(8.0));
  EXPECT_EQ(TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin)
                * LinearThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin),
            ScalarStrain(8.0));
}

TEST(LinearThermalExpansionCoefficient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(3.0, Unit::ThermalExpansion::PerKelvin)
                - LinearThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin),
            LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, AssignmentOperatorAddition) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
      1.0, Unit::ThermalExpansion::PerKelvin};
  linear_thermal_expansion_coefficient +=
      LinearThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin);
  EXPECT_EQ(linear_thermal_expansion_coefficient,
            LinearThermalExpansionCoefficient(3.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, AssignmentOperatorDivision) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
      8.0, Unit::ThermalExpansion::PerKelvin};
  linear_thermal_expansion_coefficient /= 2.0;
  EXPECT_EQ(linear_thermal_expansion_coefficient,
            LinearThermalExpansionCoefficient(4.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, AssignmentOperatorMultiplication) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
      4.0, Unit::ThermalExpansion::PerKelvin};
  linear_thermal_expansion_coefficient *= 2.0;
  EXPECT_EQ(linear_thermal_expansion_coefficient,
            LinearThermalExpansionCoefficient(8.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, AssignmentOperatorSubtraction) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
      3.0, Unit::ThermalExpansion::PerKelvin};
  linear_thermal_expansion_coefficient -=
      LinearThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin);
  EXPECT_EQ(linear_thermal_expansion_coefficient,
            LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, ComparisonOperators) {
  const LinearThermalExpansionCoefficient first{0.1, Unit::ThermalExpansion::PerKelvin};
  const LinearThermalExpansionCoefficient second{0.2, Unit::ThermalExpansion::PerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(LinearThermalExpansionCoefficient, CopyAssignmentOperator) {
  const LinearThermalExpansionCoefficient first{1.0, Unit::ThermalExpansion::PerKelvin};
  LinearThermalExpansionCoefficient second = LinearThermalExpansionCoefficient<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(LinearThermalExpansionCoefficient, CopyConstructor) {
  const LinearThermalExpansionCoefficient first{1.0, Unit::ThermalExpansion::PerKelvin};
  const LinearThermalExpansionCoefficient second{first};
  EXPECT_EQ(second, first);
}

TEST(LinearThermalExpansionCoefficient, Create) {
  constexpr LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient =
      LinearThermalExpansionCoefficient<>::Create<Unit::ThermalExpansion::PerKelvin>(1.0);
  EXPECT_EQ(linear_thermal_expansion_coefficient,
            LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, DefaultConstructor) {
  EXPECT_NO_THROW(LinearThermalExpansionCoefficient<>{});
}

TEST(LinearThermalExpansionCoefficient, Dimensions) {
  EXPECT_EQ(
      LinearThermalExpansionCoefficient<>::Dimensions(), RelatedDimensions<Unit::ThermalExpansion>);
}

TEST(LinearThermalExpansionCoefficient, Hash) {
  const LinearThermalExpansionCoefficient first{1.0, Unit::ThermalExpansion::PerRankine};
  const LinearThermalExpansionCoefficient second{1.00001, Unit::ThermalExpansion::PerRankine};
  const LinearThermalExpansionCoefficient third{-1.0, Unit::ThermalExpansion::PerRankine};
  const std::hash<LinearThermalExpansionCoefficient<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(LinearThermalExpansionCoefficient, JSON) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"/K\"}");
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine)
                .JSON(Unit::ThermalExpansion::PerRankine),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"/°R\"}");
}

TEST(LinearThermalExpansionCoefficient, MiscellaneousConstructors) {
  EXPECT_EQ(ScalarStrain(LinearThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin),
                         TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin)),
            ScalarStrain(8.0));
}

TEST(LinearThermalExpansionCoefficient, MoveAssignmentOperator) {
  LinearThermalExpansionCoefficient first{1.0, Unit::ThermalExpansion::PerKelvin};
  LinearThermalExpansionCoefficient second = LinearThermalExpansionCoefficient<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, MoveConstructor) {
  LinearThermalExpansionCoefficient first{1.0, Unit::ThermalExpansion::PerKelvin};
  const LinearThermalExpansionCoefficient second{std::move(first)};
  EXPECT_EQ(second, LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, MutableValue) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
      1.0, Unit::ThermalExpansion::PerKelvin};
  double& value = linear_thermal_expansion_coefficient.MutableValue();
  value = 2.0;
  EXPECT_EQ(linear_thermal_expansion_coefficient.Value(), 2.0);
}

TEST(LinearThermalExpansionCoefficient, Print) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).Print(),
            Print(1.0) + " /K");
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine)
                .Print(Unit::ThermalExpansion::PerRankine),
            Print(1.0) + " /°R");
}

TEST(LinearThermalExpansionCoefficient, SetValue) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
      1.0, Unit::ThermalExpansion::PerKelvin};
  linear_thermal_expansion_coefficient.SetValue(2.0);
  EXPECT_EQ(linear_thermal_expansion_coefficient.Value(), 2.0);
}

TEST(LinearThermalExpansionCoefficient, SizeOf) {
  EXPECT_EQ(sizeof(LinearThermalExpansionCoefficient<>{}), sizeof(double));
}

TEST(LinearThermalExpansionCoefficient, StandardConstructor) {
  EXPECT_NO_THROW(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine));
}

TEST(LinearThermalExpansionCoefficient, StaticValue) {
  constexpr LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient =
      LinearThermalExpansionCoefficient<>::Create<Unit::ThermalExpansion::PerRankine>(1.0);
  constexpr double value =
      linear_thermal_expansion_coefficient.StaticValue<Unit::ThermalExpansion::PerRankine>();
  EXPECT_EQ(value, 1.0);
}

TEST(LinearThermalExpansionCoefficient, Stream) {
  std::ostringstream stream;
  stream << LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin);
  EXPECT_EQ(stream.str(),
            LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).Print());
}

TEST(LinearThermalExpansionCoefficient, Unit) {
  EXPECT_EQ(LinearThermalExpansionCoefficient<>::Unit(), Standard<Unit::ThermalExpansion>);
}

TEST(LinearThermalExpansionCoefficient, Value) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).Value(), 1.0);
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine)
                .Value(Unit::ThermalExpansion::PerRankine),
            1.0);
}

TEST(LinearThermalExpansionCoefficient, XML) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).XML(),
            "<value>" + Print(1.0) + "</value><unit>/K</unit>");
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine)
                .XML(Unit::ThermalExpansion::PerRankine),
            "<value>" + Print(1.0) + "</value><unit>/°R</unit>");
}

TEST(LinearThermalExpansionCoefficient, YAML) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).YAML(),
            "{value:" + Print(1.0) + ",unit:\"/K\"}");
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine)
                .YAML(Unit::ThermalExpansion::PerRankine),
            "{value:" + Print(1.0) + ",unit:\"/°R\"}");
}

TEST(LinearThermalExpansionCoefficient, Zero) {
  EXPECT_EQ(LinearThermalExpansionCoefficient<>::Zero(),
            LinearThermalExpansionCoefficient(0.0, Unit::ThermalExpansion::PerKelvin));
}

}  // namespace

}  // namespace PhQ
