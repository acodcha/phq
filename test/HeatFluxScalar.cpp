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

#include "../include/PhQ/HeatFluxScalar.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/TemperatureGradientScalar.hpp"
#include "../include/PhQ/ThermalConductivityScalar.hpp"
#include "../include/PhQ/Unit/EnergyFlux.hpp"
#include "../include/PhQ/Unit/TemperatureGradient.hpp"
#include "../include/PhQ/Unit/ThermalConductivity.hpp"

namespace PhQ {

namespace {

TEST(HeatFluxScalar, ArithmeticOperatorAddition) {
  EXPECT_EQ(HeatFluxScalar(1.0, Unit::EnergyFlux::WattPerSquareMetre)
                + HeatFluxScalar(2.0, Unit::EnergyFlux::WattPerSquareMetre),
            HeatFluxScalar(3.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxScalar, ArithmeticOperatorDivision) {
  EXPECT_EQ(HeatFluxScalar(8.0, Unit::EnergyFlux::WattPerSquareMetre) / 2.0,
            HeatFluxScalar(4.0, Unit::EnergyFlux::WattPerSquareMetre));

  EXPECT_EQ(HeatFluxScalar(8.0, Unit::EnergyFlux::WattPerSquareMetre)
                / HeatFluxScalar(2.0, Unit::EnergyFlux::WattPerSquareMetre),
            4.0);
}

TEST(HeatFluxScalar, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(HeatFluxScalar(4.0, Unit::EnergyFlux::WattPerSquareMetre) * 2.0,
            HeatFluxScalar(8.0, Unit::EnergyFlux::WattPerSquareMetre));

  EXPECT_EQ(2.0 * HeatFluxScalar(4.0, Unit::EnergyFlux::WattPerSquareMetre),
            HeatFluxScalar(8.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxScalar, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(HeatFluxScalar(3.0, Unit::EnergyFlux::WattPerSquareMetre)
                - HeatFluxScalar(2.0, Unit::EnergyFlux::WattPerSquareMetre),
            HeatFluxScalar(1.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxScalar, AssignmentOperatorAddition) {
  HeatFluxScalar quantity{1.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity += HeatFluxScalar(2.0, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(quantity, HeatFluxScalar(3.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxScalar, AssignmentOperatorDivision) {
  HeatFluxScalar quantity{8.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity /= 2.0;
  EXPECT_EQ(quantity, HeatFluxScalar(4.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxScalar, AssignmentOperatorMultiplication) {
  HeatFluxScalar quantity{4.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity *= 2.0;
  EXPECT_EQ(quantity, HeatFluxScalar(8.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxScalar, AssignmentOperatorSubtraction) {
  HeatFluxScalar quantity{3.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity -= HeatFluxScalar(2.0, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(quantity, HeatFluxScalar(1.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxScalar, ComparisonOperators) {
  const HeatFluxScalar first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  const HeatFluxScalar second{2.22, Unit::EnergyFlux::WattPerSquareMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(HeatFluxScalar, CopyAssignmentOperator) {
  const HeatFluxScalar first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  HeatFluxScalar second = HeatFluxScalar::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(HeatFluxScalar, CopyConstructor) {
  const HeatFluxScalar first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  const HeatFluxScalar second{first};
  EXPECT_EQ(second, first);
}

TEST(HeatFluxScalar, Create) {
  constexpr HeatFluxScalar quantity =
      HeatFluxScalar::Create<Unit::EnergyFlux::WattPerSquareMetre>(1.11);
  EXPECT_EQ(quantity, HeatFluxScalar(1.11, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxScalar, DefaultConstructor) {
  EXPECT_NO_THROW(HeatFluxScalar{});
}

TEST(HeatFluxScalar, Dimensions) {
  EXPECT_EQ(HeatFluxScalar::Dimensions(), RelatedDimensions<Unit::EnergyFlux>);
}

TEST(HeatFluxScalar, Hash) {
  const HeatFluxScalar first{1.11, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const HeatFluxScalar second{1.110001, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const HeatFluxScalar third{-1.11, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const std::hash<HeatFluxScalar> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(HeatFluxScalar, JSON) {
  EXPECT_EQ(HeatFluxScalar(1.11, Unit::EnergyFlux::WattPerSquareMetre).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"W/m^2\"}");
  EXPECT_EQ(HeatFluxScalar(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .JSON(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "{\"value\":-2.220000000000000,\"unit\":\"nW/mm^2\"}");
}

TEST(HeatFluxScalar, MiscellaneousConstructor) {
  EXPECT_EQ(HeatFluxScalar(
                ThermalConductivityScalar(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
                TemperatureGradientScalar(4.0, Unit::TemperatureGradient::KelvinPerMetre)),
            HeatFluxScalar(-8.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxScalar, MoveAssignmentOperator) {
  HeatFluxScalar first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  HeatFluxScalar second = HeatFluxScalar::Zero();
  second = std::move(first);
  EXPECT_EQ(second, HeatFluxScalar(1.11, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxScalar, MoveConstructor) {
  HeatFluxScalar first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  const HeatFluxScalar second{std::move(first)};
  EXPECT_EQ(second, HeatFluxScalar(1.11, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFluxScalar, MutableValue) {
  HeatFluxScalar quantity{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(HeatFluxScalar, Print) {
  EXPECT_EQ(HeatFluxScalar(1.11, Unit::EnergyFlux::WattPerSquareMetre).Print(),
            "1.110000000000000 W/m^2");
  EXPECT_EQ(HeatFluxScalar(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Print(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "-2.220000000000000 nW/mm^2");
}

TEST(HeatFluxScalar, SetValue) {
  HeatFluxScalar quantity{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(HeatFluxScalar, SizeOf) {
  EXPECT_EQ(sizeof(HeatFluxScalar{}), sizeof(double));
}

TEST(HeatFluxScalar, StandardConstructor) {
  EXPECT_NO_THROW(HeatFluxScalar(1.11, Unit::EnergyFlux::NanowattPerSquareMillimetre));
}

TEST(HeatFluxScalar, StaticValue) {
  constexpr HeatFluxScalar quantity =
      HeatFluxScalar::Create<Unit::EnergyFlux::NanowattPerSquareMillimetre>(2.0);
  constexpr double value = quantity.StaticValue<Unit::EnergyFlux::NanowattPerSquareMillimetre>();
  EXPECT_EQ(value, 2.0);
}

TEST(HeatFluxScalar, Stream) {
  std::ostringstream stream;
  stream << HeatFluxScalar(1.11, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(stream.str(), HeatFluxScalar(1.11, Unit::EnergyFlux::WattPerSquareMetre).Print());
}

TEST(HeatFluxScalar, Unit) {
  EXPECT_EQ(HeatFluxScalar::Unit(), Standard<Unit::EnergyFlux>);
}

TEST(HeatFluxScalar, Value) {
  EXPECT_EQ(HeatFluxScalar(1.11, Unit::EnergyFlux::WattPerSquareMetre).Value(), 1.11);
  EXPECT_EQ(HeatFluxScalar(2.0, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Value(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            2.0);
}

TEST(HeatFluxScalar, XML) {
  EXPECT_EQ(HeatFluxScalar(1.11, Unit::EnergyFlux::WattPerSquareMetre).XML(),
            "<value>1.110000000000000</value><unit>W/m^2</unit>");
  EXPECT_EQ(HeatFluxScalar(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .XML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "<value>-2.220000000000000</value><unit>nW/mm^2</unit>");
}

TEST(HeatFluxScalar, YAML) {
  EXPECT_EQ(HeatFluxScalar(1.11, Unit::EnergyFlux::WattPerSquareMetre).YAML(),
            "{value:1.110000000000000,unit:\"W/m^2\"}");
  EXPECT_EQ(HeatFluxScalar(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .YAML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "{value:-2.220000000000000,unit:\"nW/mm^2\"}");
}

TEST(HeatFluxScalar, Zero) {
  EXPECT_EQ(HeatFluxScalar::Zero(), HeatFluxScalar(0.0, Unit::EnergyFlux::WattPerSquareMetre));
}

}  // namespace

}  // namespace PhQ
