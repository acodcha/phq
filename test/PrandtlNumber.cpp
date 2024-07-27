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

#include "../include/PhQ/PrandtlNumber.hpp"

#include <cmath>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimensions.hpp"
#include "../include/PhQ/DynamicViscosity.hpp"
#include "../include/PhQ/KinematicViscosity.hpp"
#include "../include/PhQ/ScalarThermalConductivity.hpp"
#include "../include/PhQ/SpecificIsobaricHeatCapacity.hpp"
#include "../include/PhQ/ThermalDiffusivity.hpp"
#include "../include/PhQ/Unit/Diffusivity.hpp"
#include "../include/PhQ/Unit/DynamicViscosity.hpp"
#include "../include/PhQ/Unit/SpecificHeatCapacity.hpp"
#include "../include/PhQ/Unit/ThermalConductivity.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(PrandtlNumber, ArithmeticOperatorAddition) {
  EXPECT_EQ(PrandtlNumber(1.0) + PrandtlNumber(2.0), PrandtlNumber(3.0));
}

TEST(PrandtlNumber, ArithmeticOperatorDivision) {
  EXPECT_EQ(PrandtlNumber(8.0) / 2.0, PrandtlNumber(4.0));
  EXPECT_EQ(PrandtlNumber(8.0) / PrandtlNumber(2.0), 4.0);
}

TEST(PrandtlNumber, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PrandtlNumber(4.0) * 2.0, PrandtlNumber(8.0));
  EXPECT_EQ(2.0 * PrandtlNumber(4.0), PrandtlNumber(8.0));
}

TEST(PrandtlNumber, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PrandtlNumber(3.0) - PrandtlNumber(2.0), PrandtlNumber(1.0));
}

TEST(PrandtlNumber, AssignmentOperatorAddition) {
  PrandtlNumber prandtl_number{1.0};
  prandtl_number += PrandtlNumber(2.0);
  EXPECT_EQ(prandtl_number, PrandtlNumber(3.0));
}

TEST(PrandtlNumber, AssignmentOperatorDivision) {
  PrandtlNumber prandtl_number{8.0};
  prandtl_number /= 2.0;
  EXPECT_EQ(prandtl_number, PrandtlNumber(4.0));
}

TEST(PrandtlNumber, AssignmentOperatorMultiplication) {
  PrandtlNumber prandtl_number{4.0};
  prandtl_number *= 2.0;
  EXPECT_EQ(prandtl_number, PrandtlNumber(8.0));
}

TEST(PrandtlNumber, AssignmentOperatorSubtraction) {
  PrandtlNumber prandtl_number{3.0};
  prandtl_number -= PrandtlNumber(2.0);
  EXPECT_EQ(prandtl_number, PrandtlNumber(1.0));
}

TEST(PrandtlNumber, ComparisonOperators) {
  const PrandtlNumber first{1.0};
  const PrandtlNumber second{2.0};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PrandtlNumber, Constructor) {
  EXPECT_NO_THROW(PrandtlNumber(1.0));
  EXPECT_EQ(PrandtlNumber(KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond),
                          ThermalDiffusivity(4.0, Unit::Diffusivity::SquareMetrePerSecond)),
            PrandtlNumber(2.0));
  EXPECT_EQ(
      PrandtlNumber(
          SpecificIsobaricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
          ScalarThermalConductivity(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin)),
      PrandtlNumber(16.0));
  EXPECT_EQ(ThermalDiffusivity(KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond),
                               PrandtlNumber(4.0)),
            ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond));
  EXPECT_EQ(
      ScalarThermalConductivity(
          SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond), PrandtlNumber(2.0)),
      ScalarThermalConductivity(16.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(
          PrandtlNumber(8.0),
          ScalarThermalConductivity(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
          DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond)),
      SpecificIsobaricHeatCapacity(16.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      DynamicViscosity(
          PrandtlNumber(8.0),
          ScalarThermalConductivity(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
          SpecificIsobaricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      DynamicViscosity(16.0, Unit::DynamicViscosity::PascalSecond));
  EXPECT_EQ(KinematicViscosity(PrandtlNumber(4.0),
                               ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond)),
            KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(PrandtlNumber, CopyAssignmentOperator) {
  {
    const PrandtlNumber<float> first(1.0F);
    PrandtlNumber<double> second = PrandtlNumber<double>::Zero();
    second = first;
    EXPECT_EQ(second, PrandtlNumber<double>(1.0));
  }
  {
    const PrandtlNumber<double> first(1.0);
    PrandtlNumber<double> second = PrandtlNumber<double>::Zero();
    second = first;
    EXPECT_EQ(second, PrandtlNumber<double>(1.0));
  }
  {
    const PrandtlNumber<long double> first(1.0L);
    PrandtlNumber<double> second = PrandtlNumber<double>::Zero();
    second = first;
    EXPECT_EQ(second, PrandtlNumber<double>(1.0));
  }
}

TEST(PrandtlNumber, CopyConstructor) {
  {
    const PrandtlNumber<float> first(1.0F);
    const PrandtlNumber<double> second{first};
    EXPECT_EQ(second, PrandtlNumber<double>(1.0));
  }
  {
    const PrandtlNumber<double> first(1.0);
    const PrandtlNumber<double> second{first};
    EXPECT_EQ(second, PrandtlNumber<double>(1.0));
  }
  {
    const PrandtlNumber<long double> first(1.0L);
    const PrandtlNumber<double> second{first};
    EXPECT_EQ(second, PrandtlNumber<double>(1.0));
  }
}

TEST(PrandtlNumber, DefaultConstructor) {
  EXPECT_NO_THROW(PrandtlNumber<>{});
}

TEST(PrandtlNumber, Dimensions) {
  EXPECT_EQ(PrandtlNumber<>::Dimensions(), Dimensionless);
}

TEST(PrandtlNumber, Hash) {
  const PrandtlNumber first{1.0};
  const PrandtlNumber second{1.000001};
  const PrandtlNumber third{-1.0};
  const std::hash<PrandtlNumber<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PrandtlNumber, JSON) {
  EXPECT_EQ(PrandtlNumber(1.0).JSON(), Print(1.0));
}

TEST(PrandtlNumber, Mathematics) {
  EXPECT_EQ(std::abs(PrandtlNumber(-1.0)), std::abs(-1.0));
  EXPECT_EQ(std::cbrt(PrandtlNumber(-8.0)), std::cbrt(-8.0));
  EXPECT_EQ(std::exp(PrandtlNumber(2.0)), std::exp(2.0));
  EXPECT_EQ(std::log(PrandtlNumber(2.0)), std::log(2.0));
  EXPECT_EQ(std::log2(PrandtlNumber(8.0)), std::log2(8.0));
  EXPECT_EQ(std::log10(PrandtlNumber(100.0)), std::log10(100.0));
  EXPECT_EQ(std::pow(PrandtlNumber(4.0), 3), std::pow(4.0, 3));
  EXPECT_EQ(std::pow(PrandtlNumber(4.0), 3L), std::pow(4.0, 3L));
  EXPECT_EQ(std::pow(PrandtlNumber(4.0), 3LL), std::pow(4.0, 3LL));
  EXPECT_EQ(std::pow(PrandtlNumber(4.0), 3.0F), std::pow(4.0, 3.0F));
  EXPECT_EQ(std::pow(PrandtlNumber(4.0), 3.0), std::pow(4.0, 3.0));
  EXPECT_EQ(std::pow(PrandtlNumber(4.0), 3.0L), std::pow(4.0, 3.0L));
  EXPECT_EQ(std::sqrt(PrandtlNumber(9.0)), std::sqrt(9.0));
}

TEST(PrandtlNumber, MiscellaneousMethods) {
  EXPECT_EQ(
      PrandtlNumber(8.0).DynamicViscosity(
          ScalarThermalConductivity(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
          SpecificIsobaricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      DynamicViscosity(16.0, Unit::DynamicViscosity::PascalSecond));
  EXPECT_EQ(PrandtlNumber(4.0).KinematicViscosity(
                ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond)),
            KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond));
  EXPECT_EQ(
      PrandtlNumber(8.0).SpecificIsobaricHeatCapacity(
          ScalarThermalConductivity(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
          DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond)),
      SpecificIsobaricHeatCapacity(16.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      PrandtlNumber(2.0).ScalarThermalConductivity(
          SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond)),
      ScalarThermalConductivity(16.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(PrandtlNumber(4.0).ThermalDiffusivity(
                KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond)),
            ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(PrandtlNumber, MoveAssignmentOperator) {
  PrandtlNumber first{1.0};
  PrandtlNumber second = PrandtlNumber<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PrandtlNumber(1.0));
}

TEST(PrandtlNumber, MoveConstructor) {
  PrandtlNumber first{1.0};
  const PrandtlNumber second{std::move(first)};
  EXPECT_EQ(second, PrandtlNumber(1.0));
}

TEST(PrandtlNumber, MutableValue) {
  PrandtlNumber prandtl_number{1.0};
  double& value = prandtl_number.MutableValue();
  value = 2.0;
  EXPECT_EQ(prandtl_number.Value(), 2.0);
}

TEST(PrandtlNumber, Performance) {
  PrandtlNumber first{1.2345678901234567890};
  PrandtlNumber second{1.2345678901234567890};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(PrandtlNumber, Print) {
  EXPECT_EQ(PrandtlNumber(1.0).Print(), Print(1.0));
}

TEST(PrandtlNumber, SetValue) {
  PrandtlNumber prandtl_number{1.0};
  prandtl_number.SetValue(2.0);
  EXPECT_EQ(prandtl_number.Value(), 2.0);
}

TEST(PrandtlNumber, SizeOf) {
  EXPECT_EQ(sizeof(PrandtlNumber<>{}), sizeof(double));
}

TEST(PrandtlNumber, Stream) {
  std::ostringstream stream;
  stream << PrandtlNumber(1.0);
  EXPECT_EQ(stream.str(), PrandtlNumber(1.0).Print());
}

TEST(PrandtlNumber, Value) {
  EXPECT_EQ(PrandtlNumber(1.0).Value(), 1.0);
}

TEST(PrandtlNumber, XML) {
  EXPECT_EQ(PrandtlNumber(1.0).XML(), Print(1.0));
}

TEST(PrandtlNumber, YAML) {
  EXPECT_EQ(PrandtlNumber(1.0).YAML(), Print(1.0));
}

TEST(PrandtlNumber, Zero) {
  EXPECT_EQ(PrandtlNumber<>::Zero(), PrandtlNumber(0.0));
}

}  // namespace

}  // namespace PhQ
