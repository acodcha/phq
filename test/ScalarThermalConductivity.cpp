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

#include "../include/PhQ/ScalarThermalConductivity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/ThermalConductivity.hpp"

namespace PhQ {

namespace {

TEST(ScalarThermalConductivity, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                + ScalarThermalConductivity(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
            ScalarThermalConductivity(3.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ScalarThermalConductivity, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarThermalConductivity(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin) / 2.0,
            ScalarThermalConductivity(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ScalarThermalConductivity(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                / ScalarThermalConductivity(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
            4.0);
}

TEST(ScalarThermalConductivity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarThermalConductivity(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin) * 2.0,
            ScalarThermalConductivity(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(2.0 * ScalarThermalConductivity(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
            ScalarThermalConductivity(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ScalarThermalConductivity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarThermalConductivity(3.0, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                - ScalarThermalConductivity(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
            ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ScalarThermalConductivity, AssignmentOperatorAddition) {
  ScalarThermalConductivity quantity{1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  quantity += ScalarThermalConductivity(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(
      quantity, ScalarThermalConductivity(3.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ScalarThermalConductivity, AssignmentOperatorDivision) {
  ScalarThermalConductivity quantity{8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  quantity /= 2.0;
  EXPECT_EQ(
      quantity, ScalarThermalConductivity(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ScalarThermalConductivity, AssignmentOperatorMultiplication) {
  ScalarThermalConductivity quantity{4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  quantity *= 2.0;
  EXPECT_EQ(
      quantity, ScalarThermalConductivity(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ScalarThermalConductivity, AssignmentOperatorSubtraction) {
  ScalarThermalConductivity quantity{3.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  quantity -= ScalarThermalConductivity(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(
      quantity, ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ScalarThermalConductivity, ComparisonOperators) {
  const ScalarThermalConductivity first{0.1, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const ScalarThermalConductivity second{0.2, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarThermalConductivity, CopyAssignmentOperator) {
  const ScalarThermalConductivity first{1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  ScalarThermalConductivity second = ScalarThermalConductivity<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ScalarThermalConductivity, CopyConstructor) {
  const ScalarThermalConductivity first{1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const ScalarThermalConductivity second{first};
  EXPECT_EQ(second, first);
}

TEST(ScalarThermalConductivity, Create) {
  constexpr ScalarThermalConductivity quantity =
      ScalarThermalConductivity<>::Create<Unit::ThermalConductivity::WattPerMetrePerKelvin>(1.0);
  EXPECT_EQ(
      quantity, ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ScalarThermalConductivity, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarThermalConductivity<>{});
}

TEST(ScalarThermalConductivity, Dimensions) {
  EXPECT_EQ(
      ScalarThermalConductivity<>::Dimensions(), RelatedDimensions<Unit::ThermalConductivity>);
}

TEST(ScalarThermalConductivity, Hash) {
  const ScalarThermalConductivity first{1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const ScalarThermalConductivity second{1.00001, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const ScalarThermalConductivity third{-1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const std::hash<ScalarThermalConductivity<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarThermalConductivity, JSON) {
  EXPECT_EQ(ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"W/m/K\"}");
  EXPECT_EQ(
      ScalarThermalConductivity(1.0, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
          .JSON(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
      "{\"value\":" + Print(1.0) + ",\"unit\":\"nW/mm/K\"}");
}

TEST(ScalarThermalConductivity, MoveAssignmentOperator) {
  ScalarThermalConductivity first{1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  ScalarThermalConductivity second = ScalarThermalConductivity<>::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ScalarThermalConductivity, MoveConstructor) {
  ScalarThermalConductivity first{1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const ScalarThermalConductivity second{std::move(first)};
  EXPECT_EQ(
      second, ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ScalarThermalConductivity, MutableValue) {
  ScalarThermalConductivity quantity{1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarThermalConductivity, Print) {
  EXPECT_EQ(
      ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin).Print(),
      Print(1.0) + " W/m/K");
  EXPECT_EQ(
      ScalarThermalConductivity(1.0, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
          .Print(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
      Print(1.0) + " nW/mm/K");
}

TEST(ScalarThermalConductivity, SetValue) {
  ScalarThermalConductivity quantity{1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarThermalConductivity, SizeOf) {
  EXPECT_EQ(sizeof(ScalarThermalConductivity<>{}), sizeof(double));
}

TEST(ScalarThermalConductivity, StandardConstructor) {
  EXPECT_NO_THROW(
      ScalarThermalConductivity(1.0, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin));
}

TEST(ScalarThermalConductivity, StaticValue) {
  constexpr ScalarThermalConductivity quantity = ScalarThermalConductivity<>::Create<
      Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>(2.0);
  constexpr double value =
      quantity.StaticValue<Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>();
  EXPECT_EQ(value, 2.0);
}

TEST(ScalarThermalConductivity, Stream) {
  std::ostringstream stream;
  stream << ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(
      stream.str(),
      ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin).Print());
}

TEST(ScalarThermalConductivity, Unit) {
  EXPECT_EQ(ScalarThermalConductivity<>::Unit(), Standard<Unit::ThermalConductivity>);
}

TEST(ScalarThermalConductivity, Value) {
  EXPECT_EQ(
      ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin).Value(),
      1.0);
  EXPECT_EQ(
      ScalarThermalConductivity(2.0, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
          .Value(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
      2.0);
}

TEST(ScalarThermalConductivity, XML) {
  EXPECT_EQ(ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin).XML(),
            "<value>" + Print(1.0) + "</value><unit>W/m/K</unit>");
  EXPECT_EQ(
      ScalarThermalConductivity(1.0, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
          .XML(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
      "<value>" + Print(1.0) + "</value><unit>nW/mm/K</unit>");
}

TEST(ScalarThermalConductivity, YAML) {
  EXPECT_EQ(ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin).YAML(),
            "{value:" + Print(1.0) + ",unit:\"W/m/K\"}");
  EXPECT_EQ(
      ScalarThermalConductivity(1.0, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
          .YAML(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
      "{value:" + Print(1.0) + ",unit:\"nW/mm/K\"}");
}

TEST(ScalarThermalConductivity, Zero) {
  EXPECT_EQ(ScalarThermalConductivity<>::Zero(),
            ScalarThermalConductivity(0.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

}  // namespace

}  // namespace PhQ
