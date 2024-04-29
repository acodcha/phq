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

#include "../include/PhQ/PrandtlNumber.hpp"

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

TEST(PrandtlNumber, CopyAssignmentOperator) {
  const PrandtlNumber first{1.0};
  PrandtlNumber second = PrandtlNumber::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(PrandtlNumber, CopyConstructor) {
  const PrandtlNumber first{1.0};
  const PrandtlNumber second{first};
  EXPECT_EQ(second, first);
}

TEST(PrandtlNumber, DefaultConstructor) {
  EXPECT_NO_THROW(PrandtlNumber{});
}

TEST(PrandtlNumber, Dimensions) {
  EXPECT_EQ(PrandtlNumber::Dimensions(), Dimensionless);
}

TEST(PrandtlNumber, Hash) {
  const PrandtlNumber first{1.0};
  const PrandtlNumber second{1.000001};
  const PrandtlNumber third{-1.0};
  const std::hash<PrandtlNumber> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PrandtlNumber, JSON) {
  EXPECT_EQ(PrandtlNumber(1.0).JSON(), Print(1.0));
}

TEST(PrandtlNumber, MiscellaneousConstructors) {
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
  PrandtlNumber second = PrandtlNumber::Zero();
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

TEST(PrandtlNumber, Print) {
  EXPECT_EQ(PrandtlNumber(1.0).Print(), Print(1.0));
}

TEST(PrandtlNumber, SetValue) {
  PrandtlNumber prandtl_number{1.0};
  prandtl_number.SetValue(2.0);
  EXPECT_EQ(prandtl_number.Value(), 2.0);
}

TEST(PrandtlNumber, SizeOf) {
  EXPECT_EQ(sizeof(PrandtlNumber{}), sizeof(double));
}

TEST(PrandtlNumber, StandardConstructor) {
  EXPECT_NO_THROW(PrandtlNumber(1.0));
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
  EXPECT_EQ(PrandtlNumber::Zero(), PrandtlNumber(0.0));
}

}  // namespace

}  // namespace PhQ
