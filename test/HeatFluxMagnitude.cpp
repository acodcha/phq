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

#include "../include/PhQ/HeatFluxMagnitude.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/TemperatureGradientMagnitude.hpp"
#include "../include/PhQ/ThermalConductivityScalar.hpp"
#include "../include/PhQ/Unit/EnergyFlux.hpp"
#include "../include/PhQ/Unit/TemperatureGradient.hpp"
#include "../include/PhQ/Unit/ThermalConductivity.hpp"

namespace PhQ {

namespace {

TEST(HeatFluxMagnitude, ArithmeticOperatorAddition) {
  EXPECT_EQ(HeatFluxMagnitude(1.0, Unit::EnergyFlux::WattPerSquareMetre)
                + HeatFluxMagnitude(2.0, Unit::EnergyFlux::WattPerSquareMetre),
            HeatFluxMagnitude(3.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxMagnitude, ArithmeticOperatorDivision) {
  EXPECT_EQ(HeatFluxMagnitude(8.0, Unit::EnergyFlux::WattPerSquareMetre) / 2.0,
            HeatFluxMagnitude(4.0, Unit::EnergyFlux::WattPerSquareMetre));

  EXPECT_EQ(HeatFluxMagnitude(8.0, Unit::EnergyFlux::WattPerSquareMetre)
                / HeatFluxMagnitude(2.0, Unit::EnergyFlux::WattPerSquareMetre),
            4.0);
}

TEST(HeatFluxMagnitude, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(HeatFluxMagnitude(4.0, Unit::EnergyFlux::WattPerSquareMetre) * 2.0,
            HeatFluxMagnitude(8.0, Unit::EnergyFlux::WattPerSquareMetre));

  EXPECT_EQ(2.0 * HeatFluxMagnitude(4.0, Unit::EnergyFlux::WattPerSquareMetre),
            HeatFluxMagnitude(8.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxMagnitude, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(HeatFluxMagnitude(3.0, Unit::EnergyFlux::WattPerSquareMetre)
                - HeatFluxMagnitude(2.0, Unit::EnergyFlux::WattPerSquareMetre),
            HeatFluxMagnitude(1.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxMagnitude, AssignmentOperatorAddition) {
  HeatFluxMagnitude quantity{1.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity += HeatFluxMagnitude(2.0, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(quantity, HeatFluxMagnitude(3.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxMagnitude, AssignmentOperatorDivision) {
  HeatFluxMagnitude quantity{8.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity /= 2.0;
  EXPECT_EQ(quantity, HeatFluxMagnitude(4.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxMagnitude, AssignmentOperatorMultiplication) {
  HeatFluxMagnitude quantity{4.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity *= 2.0;
  EXPECT_EQ(quantity, HeatFluxMagnitude(8.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxMagnitude, AssignmentOperatorSubtraction) {
  HeatFluxMagnitude quantity{3.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity -= HeatFluxMagnitude(2.0, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(quantity, HeatFluxMagnitude(1.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxMagnitude, ComparisonOperators) {
  const HeatFluxMagnitude first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  const HeatFluxMagnitude second{2.22, Unit::EnergyFlux::WattPerSquareMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(HeatFluxMagnitude, CopyAssignmentOperator) {
  const HeatFluxMagnitude first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  HeatFluxMagnitude second = HeatFluxMagnitude::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(HeatFluxMagnitude, CopyConstructor) {
  const HeatFluxMagnitude first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  const HeatFluxMagnitude second{first};
  EXPECT_EQ(second, first);
}

TEST(HeatFluxMagnitude, Create) {
  constexpr HeatFluxMagnitude quantity =
      HeatFluxMagnitude::Create<Unit::EnergyFlux::WattPerSquareMetre>(1.11);
  EXPECT_EQ(quantity, HeatFluxMagnitude(1.11, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxMagnitude, DefaultConstructor) {
  EXPECT_NO_THROW(HeatFluxMagnitude{});
}

TEST(HeatFluxMagnitude, Dimensions) {
  EXPECT_EQ(HeatFluxMagnitude::Dimensions(), RelatedDimensions<Unit::EnergyFlux>);
}

TEST(HeatFluxMagnitude, Hash) {
  const HeatFluxMagnitude first{1.11, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const HeatFluxMagnitude second{1.110001, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const HeatFluxMagnitude third{-1.11, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const std::hash<HeatFluxMagnitude> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(HeatFluxMagnitude, JSON) {
  EXPECT_EQ(HeatFluxMagnitude(1.11, Unit::EnergyFlux::WattPerSquareMetre).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"W/m^2\"}");
  EXPECT_EQ(HeatFluxMagnitude(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .JSON(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "{\"value\":-2.220000000000000,\"unit\":\"nW/mm^2\"}");
}

TEST(HeatFluxMagnitude, MiscellaneousConstructor) {
  EXPECT_EQ(HeatFluxMagnitude(
                ThermalConductivityScalar(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
                TemperatureGradientMagnitude(4.0, Unit::TemperatureGradient::KelvinPerMetre)),
            HeatFluxMagnitude(-8.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxMagnitude, MoveAssignmentOperator) {
  HeatFluxMagnitude first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  HeatFluxMagnitude second = HeatFluxMagnitude::Zero();
  second = std::move(first);
  EXPECT_EQ(second, HeatFluxMagnitude(1.11, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxMagnitude, MoveConstructor) {
  HeatFluxMagnitude first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  const HeatFluxMagnitude second{std::move(first)};
  EXPECT_EQ(second, HeatFluxMagnitude(1.11, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxMagnitude, MutableValue) {
  HeatFluxMagnitude quantity{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(HeatFluxMagnitude, Print) {
  EXPECT_EQ(HeatFluxMagnitude(1.11, Unit::EnergyFlux::WattPerSquareMetre).Print(),
            "1.110000000000000 W/m^2");
  EXPECT_EQ(HeatFluxMagnitude(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Print(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "-2.220000000000000 nW/mm^2");
}

TEST(HeatFluxMagnitude, SetValue) {
  HeatFluxMagnitude quantity{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(HeatFluxMagnitude, SizeOf) {
  EXPECT_EQ(sizeof(HeatFluxMagnitude{}), sizeof(double));
}

TEST(HeatFluxMagnitude, StandardConstructor) {
  EXPECT_NO_THROW(HeatFluxMagnitude(1.11, Unit::EnergyFlux::NanowattPerSquareMillimetre));
}

TEST(HeatFluxMagnitude, StaticValue) {
  constexpr HeatFluxMagnitude quantity =
      HeatFluxMagnitude::Create<Unit::EnergyFlux::NanowattPerSquareMillimetre>(2.0);
  constexpr double value = quantity.StaticValue<Unit::EnergyFlux::NanowattPerSquareMillimetre>();
  EXPECT_EQ(value, 2.0);
}

TEST(HeatFluxMagnitude, Stream) {
  std::ostringstream stream;
  stream << HeatFluxMagnitude(1.11, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(stream.str(), HeatFluxMagnitude(1.11, Unit::EnergyFlux::WattPerSquareMetre).Print());
}

TEST(HeatFluxMagnitude, Unit) {
  EXPECT_EQ(HeatFluxMagnitude::Unit(), Standard<Unit::EnergyFlux>);
}

TEST(HeatFluxMagnitude, Value) {
  EXPECT_EQ(HeatFluxMagnitude(1.11, Unit::EnergyFlux::WattPerSquareMetre).Value(), 1.11);
  EXPECT_EQ(HeatFluxMagnitude(2.0, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Value(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            2.0);
}

TEST(HeatFluxMagnitude, XML) {
  EXPECT_EQ(HeatFluxMagnitude(1.11, Unit::EnergyFlux::WattPerSquareMetre).XML(),
            "<value>1.110000000000000</value><unit>W/m^2</unit>");
  EXPECT_EQ(HeatFluxMagnitude(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .XML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "<value>-2.220000000000000</value><unit>nW/mm^2</unit>");
}

TEST(HeatFluxMagnitude, YAML) {
  EXPECT_EQ(HeatFluxMagnitude(1.11, Unit::EnergyFlux::WattPerSquareMetre).YAML(),
            "{value:1.110000000000000,unit:\"W/m^2\"}");
  EXPECT_EQ(HeatFluxMagnitude(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .YAML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "{value:-2.220000000000000,unit:\"nW/mm^2\"}");
}

TEST(HeatFluxMagnitude, Zero) {
  EXPECT_EQ(
      HeatFluxMagnitude::Zero(), HeatFluxMagnitude(0.0, Unit::EnergyFlux::WattPerSquareMetre));
}

}  // namespace

}  // namespace PhQ
