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

#include "../include/PhQ/VolumetricThermalExpansionCoefficient.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Strain.hpp"
#include "../include/PhQ/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/ThermalExpansion.hpp"
#include "Performance.hpp"

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
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(6.0, Unit::ThermalExpansion::PerKelvin)
                * TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            Strain(4.0, 0.0, 0.0, 4.0, 0.0, 4.0));
  EXPECT_EQ(TemperatureDifference(6.0, Unit::TemperatureDifference::Kelvin)
                * VolumetricThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin),
            Strain(4.0, 0.0, 0.0, 4.0, 0.0, 4.0));
}

TEST(VolumetricThermalExpansionCoefficient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(3.0, Unit::ThermalExpansion::PerKelvin)
                - VolumetricThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin),
            VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, AssignmentOperatorAddition) {
  VolumetricThermalExpansionCoefficient volumetric_thermal_expansion_coefficient{
      1.0, Unit::ThermalExpansion::PerKelvin};
  volumetric_thermal_expansion_coefficient +=
      VolumetricThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin);
  EXPECT_EQ(volumetric_thermal_expansion_coefficient,
            VolumetricThermalExpansionCoefficient(3.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, AssignmentOperatorDivision) {
  VolumetricThermalExpansionCoefficient volumetric_thermal_expansion_coefficient{
      8.0, Unit::ThermalExpansion::PerKelvin};
  volumetric_thermal_expansion_coefficient /= 2.0;
  EXPECT_EQ(volumetric_thermal_expansion_coefficient,
            VolumetricThermalExpansionCoefficient(4.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, AssignmentOperatorMultiplication) {
  VolumetricThermalExpansionCoefficient volumetric_thermal_expansion_coefficient{
      4.0, Unit::ThermalExpansion::PerKelvin};
  volumetric_thermal_expansion_coefficient *= 2.0;
  EXPECT_EQ(volumetric_thermal_expansion_coefficient,
            VolumetricThermalExpansionCoefficient(8.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, AssignmentOperatorSubtraction) {
  VolumetricThermalExpansionCoefficient volumetric_thermal_expansion_coefficient{
      3.0, Unit::ThermalExpansion::PerKelvin};
  volumetric_thermal_expansion_coefficient -=
      VolumetricThermalExpansionCoefficient(2.0, Unit::ThermalExpansion::PerKelvin);
  EXPECT_EQ(volumetric_thermal_expansion_coefficient,
            VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, ComparisonOperators) {
  const VolumetricThermalExpansionCoefficient first{1.0, Unit::ThermalExpansion::PerKelvin};
  const VolumetricThermalExpansionCoefficient second{2.0, Unit::ThermalExpansion::PerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(VolumetricThermalExpansionCoefficient, Constructor) {
  EXPECT_NO_THROW(VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine));
  EXPECT_EQ(Strain(VolumetricThermalExpansionCoefficient(6.0, Unit::ThermalExpansion::PerKelvin),
                   TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin)),
            Strain(4.0, 0.0, 0.0, 4.0, 0.0, 4.0));
}

TEST(VolumetricThermalExpansionCoefficient, CopyAssignmentOperator) {
  {
    const VolumetricThermalExpansionCoefficient<float> first(
        1.0F, Unit::ThermalExpansion::PerKelvin);
    VolumetricThermalExpansionCoefficient<double> second =
        VolumetricThermalExpansionCoefficient<double>::Zero();
    second = first;
    EXPECT_EQ(second, VolumetricThermalExpansionCoefficient<double>(
                          1.0, Unit::ThermalExpansion::PerKelvin));
  }
  {
    const VolumetricThermalExpansionCoefficient<double> first(
        1.0, Unit::ThermalExpansion::PerKelvin);
    VolumetricThermalExpansionCoefficient<double> second =
        VolumetricThermalExpansionCoefficient<double>::Zero();
    second = first;
    EXPECT_EQ(second, VolumetricThermalExpansionCoefficient<double>(
                          1.0, Unit::ThermalExpansion::PerKelvin));
  }
  {
    const VolumetricThermalExpansionCoefficient<long double> first(
        1.0L, Unit::ThermalExpansion::PerKelvin);
    VolumetricThermalExpansionCoefficient<double> second =
        VolumetricThermalExpansionCoefficient<double>::Zero();
    second = first;
    EXPECT_EQ(second, VolumetricThermalExpansionCoefficient<double>(
                          1.0, Unit::ThermalExpansion::PerKelvin));
  }
}

TEST(VolumetricThermalExpansionCoefficient, CopyConstructor) {
  {
    const VolumetricThermalExpansionCoefficient<float> first(
        1.0F, Unit::ThermalExpansion::PerKelvin);
    const VolumetricThermalExpansionCoefficient<double> second{first};
    EXPECT_EQ(second, VolumetricThermalExpansionCoefficient<double>(
                          1.0, Unit::ThermalExpansion::PerKelvin));
  }
  {
    const VolumetricThermalExpansionCoefficient<double> first(
        1.0, Unit::ThermalExpansion::PerKelvin);
    const VolumetricThermalExpansionCoefficient<double> second{first};
    EXPECT_EQ(second, VolumetricThermalExpansionCoefficient<double>(
                          1.0, Unit::ThermalExpansion::PerKelvin));
  }
  {
    const VolumetricThermalExpansionCoefficient<long double> first(
        1.0L, Unit::ThermalExpansion::PerKelvin);
    const VolumetricThermalExpansionCoefficient<double> second{first};
    EXPECT_EQ(second, VolumetricThermalExpansionCoefficient<double>(
                          1.0, Unit::ThermalExpansion::PerKelvin));
  }
}

TEST(VolumetricThermalExpansionCoefficient, Create) {
  constexpr VolumetricThermalExpansionCoefficient volumetric_thermal_expansion_coefficient =
      VolumetricThermalExpansionCoefficient<>::Create<Unit::ThermalExpansion::PerKelvin>(1.0);
  EXPECT_EQ(volumetric_thermal_expansion_coefficient,
            VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, DefaultConstructor) {
  EXPECT_NO_THROW(VolumetricThermalExpansionCoefficient<>{});
}

TEST(VolumetricThermalExpansionCoefficient, Dimensions) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient<>::Dimensions(),
            RelatedDimensions<Unit::ThermalExpansion>);
}

TEST(VolumetricThermalExpansionCoefficient, Hash) {
  const VolumetricThermalExpansionCoefficient first{1.0, Unit::ThermalExpansion::PerRankine};
  const VolumetricThermalExpansionCoefficient second{1.000001, Unit::ThermalExpansion::PerRankine};
  const VolumetricThermalExpansionCoefficient third{-1.0, Unit::ThermalExpansion::PerRankine};
  const std::hash<VolumetricThermalExpansionCoefficient<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(VolumetricThermalExpansionCoefficient, JSON) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"/K\"}");
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine)
                .JSON(Unit::ThermalExpansion::PerRankine),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"/°R\"}");
}

TEST(VolumetricThermalExpansionCoefficient, MoveAssignmentOperator) {
  VolumetricThermalExpansionCoefficient first{1.0, Unit::ThermalExpansion::PerKelvin};
  VolumetricThermalExpansionCoefficient second = VolumetricThermalExpansionCoefficient<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, MoveConstructor) {
  VolumetricThermalExpansionCoefficient first{1.0, Unit::ThermalExpansion::PerKelvin};
  const VolumetricThermalExpansionCoefficient second{std::move(first)};
  EXPECT_EQ(second, VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin));
}

TEST(VolumetricThermalExpansionCoefficient, MutableValue) {
  VolumetricThermalExpansionCoefficient volumetric_thermal_expansion_coefficient{
      1.0, Unit::ThermalExpansion::PerKelvin};
  double& value = volumetric_thermal_expansion_coefficient.MutableValue();
  value = 2.0;
  EXPECT_EQ(volumetric_thermal_expansion_coefficient.Value(), 2.0);
}

TEST(VolumetricThermalExpansionCoefficient, Performance) {
  VolumetricThermalExpansionCoefficient first{
      1.2345678901234567890, Unit::ThermalExpansion::PerKelvin};
  VolumetricThermalExpansionCoefficient second{
      1.2345678901234567890, Unit::ThermalExpansion::PerKelvin};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(VolumetricThermalExpansionCoefficient, Print) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).Print(),
            Print(1.0) + " /K");
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine)
                .Print(Unit::ThermalExpansion::PerRankine),
            Print(1.0) + " /°R");
}

TEST(VolumetricThermalExpansionCoefficient, SetValue) {
  VolumetricThermalExpansionCoefficient volumetric_thermal_expansion_coefficient{
      1.0, Unit::ThermalExpansion::PerKelvin};
  volumetric_thermal_expansion_coefficient.SetValue(2.0);
  EXPECT_EQ(volumetric_thermal_expansion_coefficient.Value(), 2.0);
}

TEST(VolumetricThermalExpansionCoefficient, SizeOf) {
  EXPECT_EQ(sizeof(VolumetricThermalExpansionCoefficient<>{}), sizeof(double));
}

TEST(VolumetricThermalExpansionCoefficient, StaticValue) {
  constexpr VolumetricThermalExpansionCoefficient volumetric_thermal_expansion_coefficient =
      VolumetricThermalExpansionCoefficient<>::Create<Unit::ThermalExpansion::PerRankine>(1.0);
  constexpr double value =
      volumetric_thermal_expansion_coefficient.StaticValue<Unit::ThermalExpansion::PerRankine>();
  EXPECT_EQ(value, 1.0);
}

TEST(VolumetricThermalExpansionCoefficient, Stream) {
  std::ostringstream stream;
  stream << VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin);
  EXPECT_EQ(stream.str(),
            VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).Print());
}

TEST(VolumetricThermalExpansionCoefficient, Unit) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient<>::Unit(), Standard<Unit::ThermalExpansion>);
}

TEST(VolumetricThermalExpansionCoefficient, Value) {
  EXPECT_EQ(
      VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).Value(), 1.0);
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine)
                .Value(Unit::ThermalExpansion::PerRankine),
            1.0);
}

TEST(VolumetricThermalExpansionCoefficient, XML) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).XML(),
            "<value>" + Print(1.0) + "</value><unit>/K</unit>");
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine)
                .XML(Unit::ThermalExpansion::PerRankine),
            "<value>" + Print(1.0) + "</value><unit>/°R</unit>");
}

TEST(VolumetricThermalExpansionCoefficient, YAML) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerKelvin).YAML(),
            "{value:" + Print(1.0) + ",unit:\"/K\"}");
  EXPECT_EQ(VolumetricThermalExpansionCoefficient(1.0, Unit::ThermalExpansion::PerRankine)
                .YAML(Unit::ThermalExpansion::PerRankine),
            "{value:" + Print(1.0) + ",unit:\"/°R\"}");
}

TEST(VolumetricThermalExpansionCoefficient, Zero) {
  EXPECT_EQ(VolumetricThermalExpansionCoefficient<>::Zero(),
            VolumetricThermalExpansionCoefficient(0.0, Unit::ThermalExpansion::PerKelvin));
}

}  // namespace

}  // namespace PhQ
