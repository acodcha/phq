// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/LinearThermalExpansionCoefficient.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/ScalarStrain.hpp"
#include "../include/PhQ/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/ReciprocalTemperature.hpp"
#include "../include/PhQ/Unit/TemperatureDifference.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(LinearThermalExpansionCoefficient, ArithmeticOperatorAddition) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin)
                + LinearThermalExpansionCoefficient(2.0, Unit::ReciprocalTemperature::PerKelvin),
            LinearThermalExpansionCoefficient(3.0, Unit::ReciprocalTemperature::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, ArithmeticOperatorDivision) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(8.0, Unit::ReciprocalTemperature::PerKelvin) / 2.0,
            LinearThermalExpansionCoefficient(4.0, Unit::ReciprocalTemperature::PerKelvin));
  EXPECT_EQ(LinearThermalExpansionCoefficient(8.0, Unit::ReciprocalTemperature::PerKelvin)
                / LinearThermalExpansionCoefficient(2.0, Unit::ReciprocalTemperature::PerKelvin),
            4.0);
}

TEST(LinearThermalExpansionCoefficient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(4.0, Unit::ReciprocalTemperature::PerKelvin) * 2.0,
            LinearThermalExpansionCoefficient(8.0, Unit::ReciprocalTemperature::PerKelvin));
  EXPECT_EQ(2.0 * LinearThermalExpansionCoefficient(4.0, Unit::ReciprocalTemperature::PerKelvin),
            LinearThermalExpansionCoefficient(8.0, Unit::ReciprocalTemperature::PerKelvin));
  EXPECT_EQ(LinearThermalExpansionCoefficient(2.0, Unit::ReciprocalTemperature::PerKelvin)
                * TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin),
            ScalarStrain(8.0));
  EXPECT_EQ(TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin)
                * LinearThermalExpansionCoefficient(2.0, Unit::ReciprocalTemperature::PerKelvin),
            ScalarStrain(8.0));
}

TEST(LinearThermalExpansionCoefficient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(3.0, Unit::ReciprocalTemperature::PerKelvin)
                - LinearThermalExpansionCoefficient(2.0, Unit::ReciprocalTemperature::PerKelvin),
            LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, AssignmentOperatorAddition) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
    1.0, Unit::ReciprocalTemperature::PerKelvin};
  linear_thermal_expansion_coefficient +=
      LinearThermalExpansionCoefficient(2.0, Unit::ReciprocalTemperature::PerKelvin);
  EXPECT_EQ(linear_thermal_expansion_coefficient,
            LinearThermalExpansionCoefficient(3.0, Unit::ReciprocalTemperature::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, AssignmentOperatorDivision) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
    8.0, Unit::ReciprocalTemperature::PerKelvin};
  linear_thermal_expansion_coefficient /= 2.0;
  EXPECT_EQ(linear_thermal_expansion_coefficient,
            LinearThermalExpansionCoefficient(4.0, Unit::ReciprocalTemperature::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, AssignmentOperatorMultiplication) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
    4.0, Unit::ReciprocalTemperature::PerKelvin};
  linear_thermal_expansion_coefficient *= 2.0;
  EXPECT_EQ(linear_thermal_expansion_coefficient,
            LinearThermalExpansionCoefficient(8.0, Unit::ReciprocalTemperature::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, AssignmentOperatorSubtraction) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
    3.0, Unit::ReciprocalTemperature::PerKelvin};
  linear_thermal_expansion_coefficient -=
      LinearThermalExpansionCoefficient(2.0, Unit::ReciprocalTemperature::PerKelvin);
  EXPECT_EQ(linear_thermal_expansion_coefficient,
            LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, ComparisonOperators) {
  const LinearThermalExpansionCoefficient first{0.1, Unit::ReciprocalTemperature::PerKelvin};
  const LinearThermalExpansionCoefficient second{0.2, Unit::ReciprocalTemperature::PerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(LinearThermalExpansionCoefficient, Constructor) {
  EXPECT_NO_THROW(LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerRankine));
  EXPECT_EQ(
      ScalarStrain(LinearThermalExpansionCoefficient(2.0, Unit::ReciprocalTemperature::PerKelvin),
                   TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin)),
      ScalarStrain(8.0));
}

TEST(LinearThermalExpansionCoefficient, CopyAssignmentOperator) {
  {
    const LinearThermalExpansionCoefficient<float> first(
        1.0F, Unit::ReciprocalTemperature::PerKelvin);
    LinearThermalExpansionCoefficient<double> second =
        LinearThermalExpansionCoefficient<double>::Zero();
    second = first;
    EXPECT_EQ(second, LinearThermalExpansionCoefficient<double>(
                          1.0, Unit::ReciprocalTemperature::PerKelvin));
  }
  {
    const LinearThermalExpansionCoefficient<double> first(
        1.0, Unit::ReciprocalTemperature::PerKelvin);
    LinearThermalExpansionCoefficient<double> second =
        LinearThermalExpansionCoefficient<double>::Zero();
    second = first;
    EXPECT_EQ(second, LinearThermalExpansionCoefficient<double>(
                          1.0, Unit::ReciprocalTemperature::PerKelvin));
  }
  {
    const LinearThermalExpansionCoefficient<long double> first(
        1.0L, Unit::ReciprocalTemperature::PerKelvin);
    LinearThermalExpansionCoefficient<double> second =
        LinearThermalExpansionCoefficient<double>::Zero();
    second = first;
    EXPECT_EQ(second, LinearThermalExpansionCoefficient<double>(
                          1.0, Unit::ReciprocalTemperature::PerKelvin));
  }
}

TEST(LinearThermalExpansionCoefficient, CopyConstructor) {
  {
    const LinearThermalExpansionCoefficient<float> first(
        1.0F, Unit::ReciprocalTemperature::PerKelvin);
    const LinearThermalExpansionCoefficient<double> second{first};
    EXPECT_EQ(second, LinearThermalExpansionCoefficient<double>(
                          1.0, Unit::ReciprocalTemperature::PerKelvin));
  }
  {
    const LinearThermalExpansionCoefficient<double> first(
        1.0, Unit::ReciprocalTemperature::PerKelvin);
    const LinearThermalExpansionCoefficient<double> second{first};
    EXPECT_EQ(second, LinearThermalExpansionCoefficient<double>(
                          1.0, Unit::ReciprocalTemperature::PerKelvin));
  }
  {
    const LinearThermalExpansionCoefficient<long double> first(
        1.0L, Unit::ReciprocalTemperature::PerKelvin);
    const LinearThermalExpansionCoefficient<double> second{first};
    EXPECT_EQ(second, LinearThermalExpansionCoefficient<double>(
                          1.0, Unit::ReciprocalTemperature::PerKelvin));
  }
}

TEST(LinearThermalExpansionCoefficient, Create) {
  constexpr LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient =
      LinearThermalExpansionCoefficient<>::Create<Unit::ReciprocalTemperature::PerKelvin>(1.0);
  EXPECT_EQ(linear_thermal_expansion_coefficient,
            LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, DefaultConstructor) {
  EXPECT_NO_THROW(LinearThermalExpansionCoefficient<>{});
}

TEST(LinearThermalExpansionCoefficient, Dimensions) {
  EXPECT_EQ(LinearThermalExpansionCoefficient<>::Dimensions(),
            RelatedDimensions<Unit::ReciprocalTemperature>);
}

TEST(LinearThermalExpansionCoefficient, Hash) {
  const LinearThermalExpansionCoefficient first{1.0, Unit::ReciprocalTemperature::PerRankine};
  const LinearThermalExpansionCoefficient second{1.00001, Unit::ReciprocalTemperature::PerRankine};
  const LinearThermalExpansionCoefficient third{-1.0, Unit::ReciprocalTemperature::PerRankine};
  const std::hash<LinearThermalExpansionCoefficient<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(LinearThermalExpansionCoefficient, JSON) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"/K\"}");
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerRankine)
                .JSON(Unit::ReciprocalTemperature::PerRankine),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"/°R\"}");
}

TEST(LinearThermalExpansionCoefficient, MoveAssignmentOperator) {
  LinearThermalExpansionCoefficient first{1.0, Unit::ReciprocalTemperature::PerKelvin};
  LinearThermalExpansionCoefficient second = LinearThermalExpansionCoefficient<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, MoveConstructor) {
  LinearThermalExpansionCoefficient first{1.0, Unit::ReciprocalTemperature::PerKelvin};
  const LinearThermalExpansionCoefficient second{std::move(first)};
  EXPECT_EQ(second, LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin));
}

TEST(LinearThermalExpansionCoefficient, MutableValue) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
    1.0, Unit::ReciprocalTemperature::PerKelvin};
  double& value = linear_thermal_expansion_coefficient.MutableValue();
  value = 2.0;
  EXPECT_EQ(linear_thermal_expansion_coefficient.Value(), 2.0);
}

TEST(LinearThermalExpansionCoefficient, Performance) {
  LinearThermalExpansionCoefficient first{
    1.2345678901234567890, Unit::ReciprocalTemperature::PerKelvin};
  LinearThermalExpansionCoefficient second{
    1.2345678901234567890, Unit::ReciprocalTemperature::PerKelvin};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(LinearThermalExpansionCoefficient, Print) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin).Print(),
            Print(1.0) + " /K");
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerRankine)
                .Print(Unit::ReciprocalTemperature::PerRankine),
            Print(1.0) + " /°R");
}

TEST(LinearThermalExpansionCoefficient, SetValue) {
  LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient{
    1.0, Unit::ReciprocalTemperature::PerKelvin};
  linear_thermal_expansion_coefficient.SetValue(2.0);
  EXPECT_EQ(linear_thermal_expansion_coefficient.Value(), 2.0);
}

TEST(LinearThermalExpansionCoefficient, SizeOf) {
  EXPECT_EQ(sizeof(LinearThermalExpansionCoefficient<>{}), sizeof(double));
}

TEST(LinearThermalExpansionCoefficient, StaticValue) {
  constexpr LinearThermalExpansionCoefficient linear_thermal_expansion_coefficient =
      LinearThermalExpansionCoefficient<>::Create<Unit::ReciprocalTemperature::PerRankine>(1.0);
  constexpr double value =
      linear_thermal_expansion_coefficient.StaticValue<Unit::ReciprocalTemperature::PerRankine>();
  EXPECT_EQ(value, 1.0);
}

TEST(LinearThermalExpansionCoefficient, Stream) {
  std::ostringstream stream;
  stream << LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin);
  EXPECT_EQ(stream.str(),
            LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin).Print());
}

TEST(LinearThermalExpansionCoefficient, Unit) {
  EXPECT_EQ(LinearThermalExpansionCoefficient<>::Unit(), Standard<Unit::ReciprocalTemperature>);
}

TEST(LinearThermalExpansionCoefficient, Value) {
  EXPECT_EQ(
      LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin).Value(), 1.0);
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerRankine)
                .Value(Unit::ReciprocalTemperature::PerRankine),
            1.0);
}

TEST(LinearThermalExpansionCoefficient, XML) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin).XML(),
            "<value>" + Print(1.0) + "</value><unit>/K</unit>");
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerRankine)
                .XML(Unit::ReciprocalTemperature::PerRankine),
            "<value>" + Print(1.0) + "</value><unit>/°R</unit>");
}

TEST(LinearThermalExpansionCoefficient, YAML) {
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerKelvin).YAML(),
            "{value:" + Print(1.0) + ",unit:\"/K\"}");
  EXPECT_EQ(LinearThermalExpansionCoefficient(1.0, Unit::ReciprocalTemperature::PerRankine)
                .YAML(Unit::ReciprocalTemperature::PerRankine),
            "{value:" + Print(1.0) + ",unit:\"/°R\"}");
}

TEST(LinearThermalExpansionCoefficient, Zero) {
  EXPECT_EQ(LinearThermalExpansionCoefficient<>::Zero(),
            LinearThermalExpansionCoefficient(0.0, Unit::ReciprocalTemperature::PerKelvin));
}

}  // namespace

}  // namespace PhQ
