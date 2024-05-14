// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
  const ScalarHeatFlux first{1.0, Unit::EnergyFlux::WattPerSquareMetre};
  const ScalarHeatFlux second{2.0, Unit::EnergyFlux::WattPerSquareMetre};
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
  const ScalarHeatFlux first{1.0, Unit::EnergyFlux::WattPerSquareMetre};
  ScalarHeatFlux second = ScalarHeatFlux<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ScalarHeatFlux, CopyConstructor) {
  const ScalarHeatFlux first{1.0, Unit::EnergyFlux::WattPerSquareMetre};
  const ScalarHeatFlux second{first};
  EXPECT_EQ(second, first);
}

TEST(ScalarHeatFlux, Create) {
  constexpr ScalarHeatFlux quantity =
      ScalarHeatFlux<>::Create<Unit::EnergyFlux::WattPerSquareMetre>(1.0);
  EXPECT_EQ(quantity, ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarHeatFlux<>{});
}

TEST(ScalarHeatFlux, Dimensions) {
  EXPECT_EQ(ScalarHeatFlux<>::Dimensions(), RelatedDimensions<Unit::EnergyFlux>);
}

TEST(ScalarHeatFlux, Hash) {
  const ScalarHeatFlux first{1.0, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const ScalarHeatFlux second{1.00001, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const ScalarHeatFlux third{-1.0, Unit::EnergyFlux::NanowattPerSquareMillimetre};
  const std::hash<ScalarHeatFlux<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarHeatFlux, JSON) {
  EXPECT_EQ(ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"W/m^2\"}");
  EXPECT_EQ(ScalarHeatFlux(1.0, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .JSON(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"nW/mm^2\"}");
}

TEST(ScalarHeatFlux, MiscellaneousConstructor) {
  EXPECT_EQ(ScalarHeatFlux(
                ScalarThermalConductivity(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
                ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre)),
            ScalarHeatFlux(-8.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, MoveAssignmentOperator) {
  ScalarHeatFlux first{1.0, Unit::EnergyFlux::WattPerSquareMetre};
  ScalarHeatFlux second = ScalarHeatFlux<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, MoveConstructor) {
  ScalarHeatFlux first{1.0, Unit::EnergyFlux::WattPerSquareMetre};
  const ScalarHeatFlux second{std::move(first)};
  EXPECT_EQ(second, ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(ScalarHeatFlux, MutableValue) {
  ScalarHeatFlux quantity{1.0, Unit::EnergyFlux::WattPerSquareMetre};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarHeatFlux, Print) {
  EXPECT_EQ(
      ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre).Print(), Print(1.0) + " W/m^2");
  EXPECT_EQ(ScalarHeatFlux(1.0, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Print(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            Print(1.0) + " nW/mm^2");
}

TEST(ScalarHeatFlux, SetValue) {
  ScalarHeatFlux quantity{1.0, Unit::EnergyFlux::WattPerSquareMetre};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarHeatFlux, SizeOf) {
  EXPECT_EQ(sizeof(ScalarHeatFlux<>{}), sizeof(double));
}

TEST(ScalarHeatFlux, StandardConstructor) {
  EXPECT_NO_THROW(ScalarHeatFlux(1.0, Unit::EnergyFlux::NanowattPerSquareMillimetre));
}

TEST(ScalarHeatFlux, StaticValue) {
  constexpr ScalarHeatFlux quantity =
      ScalarHeatFlux<>::Create<Unit::EnergyFlux::NanowattPerSquareMillimetre>(2.0);
  constexpr double value = quantity.StaticValue<Unit::EnergyFlux::NanowattPerSquareMillimetre>();
  EXPECT_EQ(value, 2.0);
}

TEST(ScalarHeatFlux, Stream) {
  std::ostringstream stream;
  stream << ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(stream.str(), ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre).Print());
}

TEST(ScalarHeatFlux, Unit) {
  EXPECT_EQ(ScalarHeatFlux<>::Unit(), Standard<Unit::EnergyFlux>);
}

TEST(ScalarHeatFlux, Value) {
  EXPECT_EQ(ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre).Value(), 1.0);
  EXPECT_EQ(ScalarHeatFlux(2.0, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Value(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            2.0);
}

TEST(ScalarHeatFlux, XML) {
  EXPECT_EQ(ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre).XML(),
            "<value>" + Print(1.0) + "</value><unit>W/m^2</unit>");
  EXPECT_EQ(ScalarHeatFlux(1.0, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .XML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "<value>" + Print(1.0) + "</value><unit>nW/mm^2</unit>");
}

TEST(ScalarHeatFlux, YAML) {
  EXPECT_EQ(ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre).YAML(),
            "{value:" + Print(1.0) + ",unit:\"W/m^2\"}");
  EXPECT_EQ(ScalarHeatFlux(1.0, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .YAML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "{value:" + Print(1.0) + ",unit:\"nW/mm^2\"}");
}

TEST(ScalarHeatFlux, Zero) {
  EXPECT_EQ(ScalarHeatFlux<>::Zero(), ScalarHeatFlux(0.0, Unit::EnergyFlux::WattPerSquareMetre));
}

}  // namespace

}  // namespace PhQ
