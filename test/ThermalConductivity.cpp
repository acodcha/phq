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

#include "../include/PhQ/ThermalConductivity.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/SymmetricDyad.hpp"
#include "../include/PhQ/ThermalConductivityScalar.hpp"
#include "../include/PhQ/Unit/ThermalConductivity.hpp"

namespace PhQ {

namespace {

TEST(ThermalConductivity, ArithmeticOperatorAddition) {
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                + ThermalConductivity({2.0, -4.0, 6.0, -8.0, 10.0, -12.0},
                                      Unit::ThermalConductivity::WattPerMetrePerKelvin),
            ThermalConductivity({3.0, -6.0, 9.0, -12.0, 15.0, -18.0},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, ArithmeticOperatorDivision) {
  EXPECT_EQ(ThermalConductivity({2.0, -4.0, 6.0, -8.0, 10.0, -12.0},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin)
                / 2.0,
            ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                * 2.0,
            ThermalConductivity({2.0, -4.0, 6.0, -8.0, 10.0, -12.0},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin));

  EXPECT_EQ(2.0
                * ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                      Unit::ThermalConductivity::WattPerMetrePerKelvin),
            ThermalConductivity({2.0, -4.0, 6.0, -8.0, 10.0, -12.0},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ThermalConductivity({3.0, -6.0, 9.0, -12.0, 15.0, -18.0},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin)
                - ThermalConductivity({2.0, -4.0, 6.0, -8.0, 10.0, -12.0},
                                      Unit::ThermalConductivity::WattPerMetrePerKelvin),
            ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, AssignmentOperatorAddition) {
  ThermalConductivity quantity(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  quantity += ThermalConductivity(
      {2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(quantity, ThermalConductivity({3.0, -6.0, 9.0, -12.0, 15.0, -18.0},
                                          Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, AssignmentOperatorDivision) {
  ThermalConductivity quantity(
      {2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  quantity /= 2.0;
  EXPECT_EQ(quantity, ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                          Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, AssignmentOperatorMultiplication) {
  ThermalConductivity quantity(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  quantity *= 2.0;
  EXPECT_EQ(quantity, ThermalConductivity({2.0, -4.0, 6.0, -8.0, 10.0, -12.0},
                                          Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, AssignmentOperatorSubtraction) {
  ThermalConductivity quantity(
      {3.0, -6.0, 9.0, -12.0, 15.0, -18.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  quantity -= ThermalConductivity(
      {2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(quantity, ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                          Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, ComparisonOperators) {
  const ThermalConductivity first({1.11, -2.22, 3.33, -4.44, 5.55, -6.660001},
                                  Unit::ThermalConductivity::WattPerMetrePerKelvin);
  const ThermalConductivity second(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ThermalConductivity, CopyAssignmentOperator) {
  const ThermalConductivity first(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  ThermalConductivity second = ThermalConductivity::Zero();
  second = first;
  EXPECT_EQ(second, ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                        Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, CopyConstructor) {
  const ThermalConductivity first(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  const ThermalConductivity second{first};
  EXPECT_EQ(second, ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                        Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, Create) {
  constexpr ThermalConductivity first =
      ThermalConductivity::Create<Unit::ThermalConductivity::WattPerMetrePerKelvin>(
          1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  EXPECT_EQ(first, ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                       Unit::ThermalConductivity::WattPerMetrePerKelvin));

  constexpr ThermalConductivity second =
      ThermalConductivity::Create<Unit::ThermalConductivity::WattPerMetrePerKelvin>(
          std::array<double, 6>{1.11, -2.22, 3.33, -4.44, 5.55, -6.66});
  EXPECT_EQ(second, ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                        Unit::ThermalConductivity::WattPerMetrePerKelvin));

  constexpr ThermalConductivity third =
      ThermalConductivity::Create<Unit::ThermalConductivity::WattPerMetrePerKelvin>(
          SymmetricDyad{1.11, -2.22, 3.33, -4.44, 5.55, -6.66});
  EXPECT_EQ(third, ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                       Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, DefaultConstructor) {
  EXPECT_NO_THROW(ThermalConductivity{});
}

TEST(ThermalConductivity, Dimensions) {
  EXPECT_EQ(ThermalConductivity::Dimensions(), RelatedDimensions<Unit::ThermalConductivity>);
}

TEST(ThermalConductivity, Hash) {
  const ThermalConductivity first({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                  Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin);
  const ThermalConductivity second({1.11, -2.22, 3.33, -4.44, 5.55, -6.660001},
                                   Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin);
  const ThermalConductivity third({1.11, -2.22, 3.33, 4.44, 5.55, -6.66},
                                  Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin);
  const std::hash<ThermalConductivity> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ThermalConductivity, JSON) {
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .JSON(),
            "{\"value\":{\"xx\":1.000000000000000,\"xy\":-2.000000000000000,\"xz\":3."
            "000000000000000,\"yy\":-4.000000000000000,\"yz\":5.000000000000000,\"zz\":-6."
            "000000000000000},\"unit\":\"W/m/K\"}");
  EXPECT_EQ(ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
                .JSON(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
            "{\"value\":{\"xx\":1.000000000000000,\"xy\":-2.000000000000000,\"xz\":3."
            "000000000000000,\"yy\":-4.000000000000000,\"yz\":5.000000000000000,\"zz\":-6."
            "000000000000000},\"unit\":\"nW/mm/K\"}");
}

TEST(ThermalConductivity, MiscellaneousConstructors) {
  EXPECT_EQ(ThermalConductivity(
                ThermalConductivityScalar(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin)),
            ThermalConductivity(
                {2.0, 0.0, 0.0, 2.0, 0.0, 2.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, MoveAssignmentOperator) {
  ThermalConductivity first(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  ThermalConductivity second = ThermalConductivity::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                        Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, MoveConstructor) {
  ThermalConductivity first(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  const ThermalConductivity second{std::move(first)};
  EXPECT_EQ(second, ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                        Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, MutableValue) {
  ThermalConductivity quantity(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  SymmetricDyad& value = quantity.MutableValue();
  value = SymmetricDyad{-7.77, 8.88, -9.99, 10.10, -11.11, 12.12};
  EXPECT_EQ(quantity.Value(), SymmetricDyad(-7.77, 8.88, -9.99, 10.10, -11.11, 12.12));
}

TEST(ThermalConductivity, Print) {
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .Print(),
            "(1.000000000000000, -2.000000000000000, 3.000000000000000; -4.000000000000000, "
            "5.000000000000000; -6.000000000000000) W/m/K");
  EXPECT_EQ(ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
                .Print(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
            "(1.000000000000000, -2.000000000000000, 3.000000000000000; -4.000000000000000, "
            "5.000000000000000; -6.000000000000000) nW/mm/K");
}

TEST(ThermalConductivity, SetValue) {
  ThermalConductivity quantity(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  quantity.SetValue(SymmetricDyad(-7.77, 8.88, -9.99, 10.10, -11.11, 12.12));
  EXPECT_EQ(quantity.Value(), SymmetricDyad(-7.77, 8.88, -9.99, 10.10, -11.11, 12.12));
}

TEST(ThermalConductivity, SizeOf) {
  EXPECT_EQ(sizeof(ThermalConductivity{}), 6 * sizeof(double));
}

TEST(ThermalConductivity, StandardConstructor) {
  EXPECT_NO_THROW(ThermalConductivity(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66}, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, StaticValue) {
  constexpr ThermalConductivity quantity =
      ThermalConductivity::Create<Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>(
          1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  constexpr SymmetricDyad value =
      quantity.StaticValue<Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>();
  EXPECT_EQ(value, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(ThermalConductivity, Stream) {
  std::ostringstream stream;
  stream << ThermalConductivity(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(stream.str(), ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                              Unit::ThermalConductivity::WattPerMetrePerKelvin)
                              .Print());
}

TEST(ThermalConductivity, Value) {
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .Value(),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
                .Value(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(ThermalConductivity, XML) {
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .XML(),
            "<value><xx>1.000000000000000</xx><xy>-2.000000000000000</xy><xz>3.000000000000000</"
            "xz><yy>-4.000000000000000</yy><yz>5.000000000000000</yz><zz>-6.000000000000000</zz></"
            "value><unit>W/m/K</unit>");
  EXPECT_EQ(ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
                .XML(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
            "<value><xx>1.000000000000000</xx><xy>-2.000000000000000</xy><xz>3.000000000000000</"
            "xz><yy>-4.000000000000000</yy><yz>5.000000000000000</yz><zz>-6.000000000000000</zz></"
            "value><unit>nW/mm/K</unit>");
}

TEST(ThermalConductivity, XYZ) {
  EXPECT_EQ(ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .xx(),
            ThermalConductivityScalar(1.11, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .xy(),
            ThermalConductivityScalar(-2.22, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .xz(),
            ThermalConductivityScalar(3.33, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .yx(),
            ThermalConductivityScalar(-2.22, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .yy(),
            ThermalConductivityScalar(-4.44, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .yz(),
            ThermalConductivityScalar(5.55, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .zx(),
            ThermalConductivityScalar(3.33, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .zy(),
            ThermalConductivityScalar(5.55, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity({1.11, -2.22, 3.33, -4.44, 5.55, -6.66},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .zz(),
            ThermalConductivityScalar(-6.66, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, YAML) {
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .YAML(),
            "{value:{xx:1.000000000000000,xy:-2.000000000000000,xz:3.000000000000000,yy:-4."
            "000000000000000,yz:5.000000000000000,zz:-6.000000000000000},unit:\"W/m/K\"}");
  EXPECT_EQ(ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
                .YAML(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
            "{value:{xx:1.000000000000000,xy:-2.000000000000000,xz:3.000000000000000,yy:-4."
            "000000000000000,yz:5.000000000000000,zz:-6.000000000000000},unit:\"nW/mm/K\"}");
}

TEST(ThermalConductivity, Zero) {
  EXPECT_EQ(ThermalConductivity::Zero(),
            ThermalConductivity(
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

}  // namespace

}  // namespace PhQ
