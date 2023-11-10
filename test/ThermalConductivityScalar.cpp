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

#include "../include/PhQ/ThermalConductivityScalar.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/ThermalConductivity.hpp"

namespace PhQ {

namespace {

TEST(ThermalConductivityScalar, ArithmeticOperatorAddition) {
  EXPECT_EQ(ThermalConductivityScalar(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                + ThermalConductivityScalar(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
            ThermalConductivityScalar(3.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivityScalar, ArithmeticOperatorDivision) {
  EXPECT_EQ(ThermalConductivityScalar(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin) / 2.0,
            ThermalConductivityScalar(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));

  EXPECT_EQ(ThermalConductivityScalar(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                / ThermalConductivityScalar(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
            4.0);
}

TEST(ThermalConductivityScalar, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ThermalConductivityScalar(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin) * 2.0,
            ThermalConductivityScalar(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));

  EXPECT_EQ(2.0 * ThermalConductivityScalar(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
            ThermalConductivityScalar(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivityScalar, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ThermalConductivityScalar(3.0, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                - ThermalConductivityScalar(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
            ThermalConductivityScalar(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivityScalar, AssignmentOperatorAddition) {
  ThermalConductivityScalar quantity{1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  quantity += ThermalConductivityScalar(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(
      quantity, ThermalConductivityScalar(3.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivityScalar, AssignmentOperatorDivision) {
  ThermalConductivityScalar quantity{8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  quantity /= 2.0;
  EXPECT_EQ(
      quantity, ThermalConductivityScalar(4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivityScalar, AssignmentOperatorMultiplication) {
  ThermalConductivityScalar quantity{4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  quantity *= 2.0;
  EXPECT_EQ(
      quantity, ThermalConductivityScalar(8.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivityScalar, AssignmentOperatorSubtraction) {
  ThermalConductivityScalar quantity{3.0, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  quantity -= ThermalConductivityScalar(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(
      quantity, ThermalConductivityScalar(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivityScalar, ComparisonOperators) {
  const ThermalConductivityScalar first{0.1, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const ThermalConductivityScalar second{0.2, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ThermalConductivityScalar, CopyAssignmentOperator) {
  const ThermalConductivityScalar first{1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  ThermalConductivityScalar second = ThermalConductivityScalar::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ThermalConductivityScalar, CopyConstructor) {
  const ThermalConductivityScalar first{1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const ThermalConductivityScalar second{first};
  EXPECT_EQ(second, first);
}

TEST(ThermalConductivityScalar, Create) {
  constexpr ThermalConductivityScalar quantity =
      ThermalConductivityScalar::Create<Unit::ThermalConductivity::WattPerMetrePerKelvin>(1.11);
  EXPECT_EQ(
      quantity, ThermalConductivityScalar(1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivityScalar, DefaultConstructor) {
  EXPECT_NO_THROW(ThermalConductivityScalar{});
}

TEST(ThermalConductivityScalar, Dimensions) {
  EXPECT_EQ(ThermalConductivityScalar::Dimensions(), RelatedDimensions<Unit::ThermalConductivity>);
}

TEST(ThermalConductivityScalar, Hash) {
  const ThermalConductivityScalar first{1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const ThermalConductivityScalar second{
      1.110001, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const ThermalConductivityScalar third{-1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const std::hash<ThermalConductivityScalar> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ThermalConductivityScalar, JSON) {
  EXPECT_EQ(
      ThermalConductivityScalar(1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin).JSON(),
      "{\"value\":1.110000000000000,\"unit\":\"W/m/K\"}");
  EXPECT_EQ(
      ThermalConductivityScalar(-2.22, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
          .JSON(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
      "{\"value\":-2.220000000000000,\"unit\":\"nW/mm/K\"}");
}

TEST(ThermalConductivityScalar, MoveAssignmentOperator) {
  ThermalConductivityScalar first{1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  ThermalConductivityScalar second = ThermalConductivityScalar::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, ThermalConductivityScalar(1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivityScalar, MoveConstructor) {
  ThermalConductivityScalar first{1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  const ThermalConductivityScalar second{std::move(first)};
  EXPECT_EQ(
      second, ThermalConductivityScalar(1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivityScalar, MutableValue) {
  ThermalConductivityScalar quantity{1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ThermalConductivityScalar, Print) {
  EXPECT_EQ(
      ThermalConductivityScalar(1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin).Print(),
      "1.110000000000000 W/m/K");
  EXPECT_EQ(
      ThermalConductivityScalar(-2.22, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
          .Print(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
      "-2.220000000000000 nW/mm/K");
}

TEST(ThermalConductivityScalar, SetValue) {
  ThermalConductivityScalar quantity{1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ThermalConductivityScalar, SizeOf) {
  EXPECT_EQ(sizeof(ThermalConductivityScalar{}), sizeof(double));
}

TEST(ThermalConductivityScalar, StandardConstructor) {
  EXPECT_NO_THROW(
      ThermalConductivityScalar(1.11, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin));
}

TEST(ThermalConductivityScalar, StaticValue) {
  constexpr ThermalConductivityScalar quantity =
      ThermalConductivityScalar::Create<Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>(
          2.0);
  constexpr double value =
      quantity.StaticValue<Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>();
  EXPECT_EQ(value, 2.0);
}

TEST(ThermalConductivityScalar, Stream) {
  std::ostringstream stream;
  stream << ThermalConductivityScalar(1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(
      stream.str(),
      ThermalConductivityScalar(1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin).Print());
}

TEST(ThermalConductivityScalar, Unit) {
  EXPECT_EQ(ThermalConductivityScalar::Unit(), Standard<Unit::ThermalConductivity>);
}

TEST(ThermalConductivityScalar, Value) {
  EXPECT_EQ(
      ThermalConductivityScalar(1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin).Value(),
      1.11);
  EXPECT_EQ(
      ThermalConductivityScalar(2.0, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
          .Value(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
      2.0);
}

TEST(ThermalConductivityScalar, XML) {
  EXPECT_EQ(ThermalConductivityScalar(1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin).XML(),
            "<value>1.110000000000000</value><unit>W/m/K</unit>");
  EXPECT_EQ(
      ThermalConductivityScalar(-2.22, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
          .XML(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
      "<value>-2.220000000000000</value><unit>nW/mm/K</unit>");
}

TEST(ThermalConductivityScalar, YAML) {
  EXPECT_EQ(
      ThermalConductivityScalar(1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin).YAML(),
      "{value:1.110000000000000,unit:\"W/m/K\"}");
  EXPECT_EQ(
      ThermalConductivityScalar(-2.22, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
          .YAML(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
      "{value:-2.220000000000000,unit:\"nW/mm/K\"}");
}

TEST(ThermalConductivityScalar, Zero) {
  EXPECT_EQ(ThermalConductivityScalar::Zero(),
            ThermalConductivityScalar(0.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

}  // namespace

}  // namespace PhQ
