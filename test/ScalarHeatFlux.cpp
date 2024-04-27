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

#include "../include/PhQ/ScalarHeatFlux.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/ScalarTemperatureGradient.hpp"
#include "../include/PhQ/ScalarThermalConductivity.hpp"
#include "../include/PhQ/Unit/EnergyFlux.hpp"
#include "../include/PhQ/Unit/TemperatureGradient.hpp"
#include "../include/PhQ/Unit/ThermalConductivity.hpp"

namespace PhQ {

namespace {

TEST(ScalarHeatFlux, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre)
                + ScalarHeatFlux(2.0, Unit::EnergyFlux::WattPerSquareMetre),
            ScalarHeatFlux(3.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarHeatFlux(8.0, Unit::EnergyFlux::WattPerSquareMetre) / 2.0,
            ScalarHeatFlux(4.0, Unit::EnergyFlux::WattPerSquareMetre));

  EXPECT_EQ(ScalarHeatFlux(8.0, Unit::EnergyFlux::WattPerSquareMetre)
                / ScalarHeatFlux(2.0, Unit::EnergyFlux::WattPerSquareMetre),
            4.0);
}

TEST(ScalarHeatFlux, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarHeatFlux(4.0, Unit::EnergyFlux::WattPerSquareMetre) * 2.0,
            ScalarHeatFlux(8.0, Unit::EnergyFlux::WattPerSquareMetre));

  EXPECT_EQ(2.0 * ScalarHeatFlux(4.0, Unit::EnergyFlux::WattPerSquareMetre),
            ScalarHeatFlux(8.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarHeatFlux(3.0, Unit::EnergyFlux::WattPerSquareMetre)
                - ScalarHeatFlux(2.0, Unit::EnergyFlux::WattPerSquareMetre),
            ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, AssignmentOperatorAddition) {
  ScalarHeatFlux quantity{1.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity += ScalarHeatFlux(2.0, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(quantity, ScalarHeatFlux(3.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, AssignmentOperatorDivision) {
  ScalarHeatFlux quantity{8.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ScalarHeatFlux(4.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, AssignmentOperatorMultiplication) {
  ScalarHeatFlux quantity{4.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ScalarHeatFlux(8.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, AssignmentOperatorSubtraction) {
  ScalarHeatFlux quantity{3.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity -= ScalarHeatFlux(2.0, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(quantity, ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, ComparisonOperators) {
  const ScalarHeatFlux first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  const ScalarHeatFlux second{2.22, Unit::EnergyFlux::WattPerSquareMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarHeatFlux, CopyAssignmentOperator) {
  const ScalarHeatFlux first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  ScalarHeatFlux second = ScalarHeatFlux::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ScalarHeatFlux, CopyConstructor) {
  const ScalarHeatFlux first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  const ScalarHeatFlux second{first};
  EXPECT_EQ(second, first);
}

TEST(ScalarHeatFlux, Create) {
  constexpr ScalarHeatFlux quantity =
      ScalarHeatFlux::Create<Unit::EnergyFlux::WattPerSquareMetre>(1.11);
  EXPECT_EQ(quantity, ScalarHeatFlux(1.11, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarHeatFlux{});
}

TEST(ScalarHeatFlux, Dimensions) {
  EXPECT_EQ(ScalarHeatFlux::Dimensions(), RelatedDimensions<Unit::EnergyFlux>);
}

TEST(ScalarHeatFlux, Hash) {
  const ScalarHeatFlux first{1.11, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const ScalarHeatFlux second{1.110001, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const ScalarHeatFlux third{-1.11, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const std::hash<ScalarHeatFlux> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarHeatFlux, JSON) {
  EXPECT_EQ(ScalarHeatFlux(1.11, Unit::EnergyFlux::WattPerSquareMetre).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"W/m^2\"}");
  EXPECT_EQ(ScalarHeatFlux(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .JSON(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "{\"value\":-2.220000000000000,\"unit\":\"nW/mm^2\"}");
}

TEST(ScalarHeatFlux, MiscellaneousConstructor) {
  EXPECT_EQ(ScalarHeatFlux(
                ScalarThermalConductivity(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
                ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre)),
            ScalarHeatFlux(-8.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, MoveAssignmentOperator) {
  ScalarHeatFlux first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  ScalarHeatFlux second = ScalarHeatFlux::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarHeatFlux(1.11, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, MoveConstructor) {
  ScalarHeatFlux first{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  const ScalarHeatFlux second{std::move(first)};
  EXPECT_EQ(second, ScalarHeatFlux(1.11, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, MutableValue) {
  ScalarHeatFlux quantity{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ScalarHeatFlux, Print) {
  EXPECT_EQ(ScalarHeatFlux(1.11, Unit::EnergyFlux::WattPerSquareMetre).Print(),
            "1.110000000000000 W/m^2");
  EXPECT_EQ(ScalarHeatFlux(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Print(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "-2.220000000000000 nW/mm^2");
}

TEST(ScalarHeatFlux, SetValue) {
  ScalarHeatFlux quantity{1.11, Unit::EnergyFlux::WattPerSquareMetre};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ScalarHeatFlux, SizeOf) {
  EXPECT_EQ(sizeof(ScalarHeatFlux{}), sizeof(double));
}

TEST(ScalarHeatFlux, StandardConstructor) {
  EXPECT_NO_THROW(ScalarHeatFlux(1.11, Unit::EnergyFlux::NanowattPerSquareMillimetre));
}

TEST(ScalarHeatFlux, StaticValue) {
  constexpr ScalarHeatFlux quantity =
      ScalarHeatFlux::Create<Unit::EnergyFlux::NanowattPerSquareMillimetre>(2.0);
  constexpr double value = quantity.StaticValue<Unit::EnergyFlux::NanowattPerSquareMillimetre>();
  EXPECT_EQ(value, 2.0);
}

TEST(ScalarHeatFlux, Stream) {
  std::ostringstream stream;
  stream << ScalarHeatFlux(1.11, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(stream.str(), ScalarHeatFlux(1.11, Unit::EnergyFlux::WattPerSquareMetre).Print());
}

TEST(ScalarHeatFlux, Unit) {
  EXPECT_EQ(ScalarHeatFlux::Unit(), Standard<Unit::EnergyFlux>);
}

TEST(ScalarHeatFlux, Value) {
  EXPECT_EQ(ScalarHeatFlux(1.11, Unit::EnergyFlux::WattPerSquareMetre).Value(), 1.11);
  EXPECT_EQ(ScalarHeatFlux(2.0, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Value(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            2.0);
}

TEST(ScalarHeatFlux, XML) {
  EXPECT_EQ(ScalarHeatFlux(1.11, Unit::EnergyFlux::WattPerSquareMetre).XML(),
            "<value>1.110000000000000</value><unit>W/m^2</unit>");
  EXPECT_EQ(ScalarHeatFlux(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .XML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "<value>-2.220000000000000</value><unit>nW/mm^2</unit>");
}

TEST(ScalarHeatFlux, YAML) {
  EXPECT_EQ(ScalarHeatFlux(1.11, Unit::EnergyFlux::WattPerSquareMetre).YAML(),
            "{value:1.110000000000000,unit:\"W/m^2\"}");
  EXPECT_EQ(ScalarHeatFlux(-2.22, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .YAML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "{value:-2.220000000000000,unit:\"nW/mm^2\"}");
}

TEST(ScalarHeatFlux, Zero) {
  EXPECT_EQ(ScalarHeatFlux::Zero(), ScalarHeatFlux(0.0, Unit::EnergyFlux::WattPerSquareMetre));
}

}  // namespace

}  // namespace PhQ
