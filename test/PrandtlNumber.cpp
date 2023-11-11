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

#include "../include/PhQ/PrandtlNumber.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimensions.hpp"
#include "../include/PhQ/DynamicViscosity.hpp"
#include "../include/PhQ/KinematicViscosity.hpp"
#include "../include/PhQ/SpecificIsobaricHeatCapacity.hpp"
#include "../include/PhQ/ThermalConductivityScalar.hpp"
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
  PrandtlNumber quantity{1.0};
  quantity += PrandtlNumber(2.0);
  EXPECT_EQ(quantity, PrandtlNumber(3.0));
}

TEST(PrandtlNumber, AssignmentOperatorDivision) {
  PrandtlNumber quantity{8.0};
  quantity /= 2.0;
  EXPECT_EQ(quantity, PrandtlNumber(4.0));
}

TEST(PrandtlNumber, AssignmentOperatorMultiplication) {
  PrandtlNumber quantity{4.0};
  quantity *= 2.0;
  EXPECT_EQ(quantity, PrandtlNumber(8.0));
}

TEST(PrandtlNumber, AssignmentOperatorSubtraction) {
  PrandtlNumber quantity{3.0};
  quantity -= PrandtlNumber(2.0);
  EXPECT_EQ(quantity, PrandtlNumber(1.0));
}

TEST(PrandtlNumber, ComparisonOperators) {
  const PrandtlNumber first{1.11};
  const PrandtlNumber second{2.22};
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
  const PrandtlNumber first{1.11};
  PrandtlNumber second = PrandtlNumber::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(PrandtlNumber, CopyConstructor) {
  const PrandtlNumber first{1.11};
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
  const PrandtlNumber first{1.11};
  const PrandtlNumber second{1.110001};
  const PrandtlNumber third{-1.11};
  const std::hash<PrandtlNumber> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PrandtlNumber, JSON) {
  EXPECT_EQ(PrandtlNumber(1.11).JSON(), "1.110000000000000");
}

TEST(PrandtlNumber, MiscellaneousConstructors) {
  EXPECT_EQ(PrandtlNumber(KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond),
                          ThermalDiffusivity(4.0, Unit::Diffusivity::SquareMetrePerSecond)),
            PrandtlNumber(2.0));

  EXPECT_EQ(
      PrandtlNumber(
          SpecificIsobaricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
          ThermalConductivityScalar(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin)),
      PrandtlNumber(16.0));

  EXPECT_EQ(ThermalDiffusivity(KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond),
                               PrandtlNumber(4.0)),
            ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond));

  EXPECT_EQ(
      ThermalConductivityScalar(
          SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond), PrandtlNumber(2.0)),
      ThermalConductivityScalar(16.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));

  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(
          PrandtlNumber(8.0),
          ThermalConductivityScalar(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
          DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond)),
      SpecificIsobaricHeatCapacity(16.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(
      DynamicViscosity(
          PrandtlNumber(8.0),
          ThermalConductivityScalar(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
          SpecificIsobaricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      DynamicViscosity(16.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(KinematicViscosity(PrandtlNumber(4.0),
                               ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond)),
            KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(PrandtlNumber, MiscellaneousMethods) {
  EXPECT_EQ(
      PrandtlNumber(8.0).DynamicViscosity(
          ThermalConductivityScalar(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
          SpecificIsobaricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      DynamicViscosity(16.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(PrandtlNumber(4.0).KinematicViscosity(
                ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond)),
            KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond));

  EXPECT_EQ(
      PrandtlNumber(8.0).SpecificIsobaricHeatCapacity(
          ThermalConductivityScalar(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
          DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond)),
      SpecificIsobaricHeatCapacity(16.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(
      PrandtlNumber(2.0).ThermalConductivityScalar(
          SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond)),
      ThermalConductivityScalar(16.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));

  EXPECT_EQ(PrandtlNumber(4.0).ThermalDiffusivity(
                KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond)),
            ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(PrandtlNumber, MoveAssignmentOperator) {
  PrandtlNumber first{1.11};
  PrandtlNumber second = PrandtlNumber::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PrandtlNumber(1.11));
}

TEST(PrandtlNumber, MoveConstructor) {
  PrandtlNumber first{1.11};
  const PrandtlNumber second{std::move(first)};
  EXPECT_EQ(second, PrandtlNumber(1.11));
}

TEST(PrandtlNumber, MutableValue) {
  PrandtlNumber quantity{1.11};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(PrandtlNumber, Print) {
  EXPECT_EQ(PrandtlNumber(1.11).Print(), "1.110000000000000");
}

TEST(PrandtlNumber, SetValue) {
  PrandtlNumber quantity{1.11};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(PrandtlNumber, SizeOf) {
  EXPECT_EQ(sizeof(PrandtlNumber{}), sizeof(double));
}

TEST(PrandtlNumber, StandardConstructor) {
  EXPECT_NO_THROW(PrandtlNumber(1.11));
}

TEST(PrandtlNumber, Stream) {
  std::ostringstream stream;
  stream << PrandtlNumber(1.11);
  EXPECT_EQ(stream.str(), PrandtlNumber(1.11).Print());
}

TEST(PrandtlNumber, Value) {
  EXPECT_EQ(PrandtlNumber(1.11).Value(), 1.11);
}

TEST(PrandtlNumber, XML) {
  EXPECT_EQ(PrandtlNumber(1.11).XML(), "1.110000000000000");
}

TEST(PrandtlNumber, YAML) {
  EXPECT_EQ(PrandtlNumber(1.11).YAML(), "1.110000000000000");
}

TEST(PrandtlNumber, Zero) {
  EXPECT_EQ(PrandtlNumber::Zero(), PrandtlNumber(0.0));
}

}  // namespace

}  // namespace PhQ
