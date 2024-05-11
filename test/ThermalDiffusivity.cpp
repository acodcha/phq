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

#include "../include/PhQ/ThermalDiffusivity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/MassDensity.hpp"
#include "../include/PhQ/ScalarThermalConductivity.hpp"
#include "../include/PhQ/SpecificIsobaricHeatCapacity.hpp"
#include "../include/PhQ/Unit/Diffusivity.hpp"
#include "../include/PhQ/Unit/MassDensity.hpp"
#include "../include/PhQ/Unit/SpecificHeatCapacity.hpp"
#include "../include/PhQ/Unit/ThermalConductivity.hpp"

namespace PhQ {

namespace {

TEST(ThermalDiffusivity, ArithmeticOperatorAddition) {
  EXPECT_EQ(ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond)
                + ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond),
            ThermalDiffusivity(3.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(ThermalDiffusivity, ArithmeticOperatorDivision) {
  EXPECT_EQ(ThermalDiffusivity(8.0, Unit::Diffusivity::SquareMetrePerSecond) / 2.0,
            ThermalDiffusivity(4.0, Unit::Diffusivity::SquareMetrePerSecond));
  EXPECT_EQ(ThermalDiffusivity(8.0, Unit::Diffusivity::SquareMetrePerSecond)
                / ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond),
            4.0);
}

TEST(ThermalDiffusivity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ThermalDiffusivity(4.0, Unit::Diffusivity::SquareMetrePerSecond) * 2.0,
            ThermalDiffusivity(8.0, Unit::Diffusivity::SquareMetrePerSecond));
  EXPECT_EQ(2.0 * ThermalDiffusivity(4.0, Unit::Diffusivity::SquareMetrePerSecond),
            ThermalDiffusivity(8.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(ThermalDiffusivity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ThermalDiffusivity(3.0, Unit::Diffusivity::SquareMetrePerSecond)
                - ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond),
            ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(ThermalDiffusivity, AssignmentOperatorAddition) {
  ThermalDiffusivity thermal_diffusivity{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  thermal_diffusivity += ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond);
  EXPECT_EQ(thermal_diffusivity, ThermalDiffusivity(3.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(ThermalDiffusivity, AssignmentOperatorDivision) {
  ThermalDiffusivity thermal_diffusivity{8.0, Unit::Diffusivity::SquareMetrePerSecond};
  thermal_diffusivity /= 2.0;
  EXPECT_EQ(thermal_diffusivity, ThermalDiffusivity(4.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(ThermalDiffusivity, AssignmentOperatorMultiplication) {
  ThermalDiffusivity thermal_diffusivity{4.0, Unit::Diffusivity::SquareMetrePerSecond};
  thermal_diffusivity *= 2.0;
  EXPECT_EQ(thermal_diffusivity, ThermalDiffusivity(8.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(ThermalDiffusivity, AssignmentOperatorSubtraction) {
  ThermalDiffusivity thermal_diffusivity{3.0, Unit::Diffusivity::SquareMetrePerSecond};
  thermal_diffusivity -= ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond);
  EXPECT_EQ(thermal_diffusivity, ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(ThermalDiffusivity, ComparisonOperators) {
  const ThermalDiffusivity first{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  const ThermalDiffusivity second{2.0, Unit::Diffusivity::SquareMetrePerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ThermalDiffusivity, CopyAssignmentOperator) {
  const ThermalDiffusivity first{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  ThermalDiffusivity second = ThermalDiffusivity<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ThermalDiffusivity, CopyConstructor) {
  const ThermalDiffusivity first{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  const ThermalDiffusivity second{first};
  EXPECT_EQ(second, first);
}

TEST(ThermalDiffusivity, Create) {
  constexpr ThermalDiffusivity thermal_diffusivity =
      ThermalDiffusivity<>::Create<Unit::Diffusivity::SquareMetrePerSecond>(1.0);
  EXPECT_EQ(thermal_diffusivity, ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(ThermalDiffusivity, DefaultConstructor) {
  EXPECT_NO_THROW(ThermalDiffusivity{});
}

TEST(ThermalDiffusivity, Dimensions) {
  EXPECT_EQ(ThermalDiffusivity<>::Dimensions(), RelatedDimensions<Unit::Diffusivity>);
}

TEST(ThermalDiffusivity, Hash) {
  const ThermalDiffusivity first{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  const ThermalDiffusivity second{1.000001, Unit::Diffusivity::SquareMetrePerSecond};
  const ThermalDiffusivity third{-1.0, Unit::Diffusivity::SquareMetrePerSecond};
  const std::hash<ThermalDiffusivity<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ThermalDiffusivity, JSON) {
  EXPECT_EQ(ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"m^2/s\"}");
  EXPECT_EQ(ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMillimetrePerSecond)
                .JSON(Unit::Diffusivity::SquareMillimetrePerSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"mm^2/s\"}");
}

TEST(ThermalDiffusivity, MiscellaneousConstructors) {
  EXPECT_EQ(
      ThermalDiffusivity(
          ScalarThermalConductivity(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
          MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
          SpecificIsobaricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond));
  EXPECT_EQ(
      ScalarThermalConductivity(
          MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
          SpecificIsobaricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          ThermalDiffusivity(8.0, Unit::Diffusivity::SquareMetrePerSecond)),
      ScalarThermalConductivity(64.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(
      MassDensity(
          ScalarThermalConductivity(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
          ThermalDiffusivity(4.0, Unit::Diffusivity::SquareMetrePerSecond),
          SpecificIsobaricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre));
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(
          ScalarThermalConductivity(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
          MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
          ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMetrePerSecond)),
      SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(ThermalDiffusivity, MoveAssignmentOperator) {
  ThermalDiffusivity first{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  ThermalDiffusivity second = ThermalDiffusivity<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(ThermalDiffusivity, MoveConstructor) {
  ThermalDiffusivity first{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  const ThermalDiffusivity second{std::move(first)};
  EXPECT_EQ(second, ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(ThermalDiffusivity, MutableValue) {
  ThermalDiffusivity thermal_diffusivity{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  double& value = thermal_diffusivity.MutableValue();
  value = 2.0;
  EXPECT_EQ(thermal_diffusivity.Value(), 2.0);
}

TEST(ThermalDiffusivity, Print) {
  EXPECT_EQ(ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond).Print(),
            Print(1.0) + " m^2/s");
  EXPECT_EQ(ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMillimetrePerSecond)
                .Print(Unit::Diffusivity::SquareMillimetrePerSecond),
            Print(1.0) + " mm^2/s");
}

TEST(ThermalDiffusivity, SetValue) {
  ThermalDiffusivity thermal_diffusivity{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  thermal_diffusivity.SetValue(2.0);
  EXPECT_EQ(thermal_diffusivity.Value(), 2.0);
}

TEST(ThermalDiffusivity, SizeOf) {
  EXPECT_EQ(sizeof(ThermalDiffusivity{}), sizeof(double));
}

TEST(ThermalDiffusivity, StandardConstructor) {
  EXPECT_NO_THROW(ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMillimetrePerSecond));
}

TEST(ThermalDiffusivity, StaticValue) {
  constexpr ThermalDiffusivity thermal_diffusivity =
      ThermalDiffusivity<>::Create<Unit::Diffusivity::SquareMillimetrePerSecond>(2.0);
  constexpr double value =
      thermal_diffusivity.StaticValue<Unit::Diffusivity::SquareMillimetrePerSecond>();
  EXPECT_EQ(value, 2.0);
}

TEST(ThermalDiffusivity, Stream) {
  std::ostringstream stream;
  stream << ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond);
  EXPECT_EQ(stream.str(), ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond).Print());
}

TEST(ThermalDiffusivity, Unit) {
  EXPECT_EQ(ThermalDiffusivity<>::Unit(), Standard<Unit::Diffusivity>);
}

TEST(ThermalDiffusivity, Value) {
  EXPECT_EQ(ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond).Value(), 1.0);
  EXPECT_EQ(ThermalDiffusivity(2.0, Unit::Diffusivity::SquareMillimetrePerSecond)
                .Value(Unit::Diffusivity::SquareMillimetrePerSecond),
            2.0);
}

TEST(ThermalDiffusivity, XML) {
  EXPECT_EQ(ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>m^2/s</unit>");
  EXPECT_EQ(ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMillimetrePerSecond)
                .XML(Unit::Diffusivity::SquareMillimetrePerSecond),
            "<value>" + Print(1.0) + "</value><unit>mm^2/s</unit>");
}

TEST(ThermalDiffusivity, YAML) {
  EXPECT_EQ(ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMetrePerSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"m^2/s\"}");
  EXPECT_EQ(ThermalDiffusivity(1.0, Unit::Diffusivity::SquareMillimetrePerSecond)
                .YAML(Unit::Diffusivity::SquareMillimetrePerSecond),
            "{value:" + Print(1.0) + ",unit:\"mm^2/s\"}");
}

TEST(ThermalDiffusivity, Zero) {
  EXPECT_EQ(ThermalDiffusivity<>::Zero(),
            ThermalDiffusivity(0.0, Unit::Diffusivity::SquareMetrePerSecond));
}

}  // namespace

}  // namespace PhQ
