// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
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

#include "../include/PhQ/ThermalConductivity.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/ScalarThermalConductivity.hpp"
#include "../include/PhQ/SymmetricDyad.hpp"
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
  ThermalConductivity thermal_conductivity(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  thermal_conductivity += ThermalConductivity(
      {2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(thermal_conductivity,
            ThermalConductivity({3.0, -6.0, 9.0, -12.0, 15.0, -18.0},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, AssignmentOperatorDivision) {
  ThermalConductivity thermal_conductivity(
      {2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  thermal_conductivity /= 2.0;
  EXPECT_EQ(thermal_conductivity,
            ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, AssignmentOperatorMultiplication) {
  ThermalConductivity thermal_conductivity(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  thermal_conductivity *= 2.0;
  EXPECT_EQ(thermal_conductivity,
            ThermalConductivity({2.0, -4.0, 6.0, -8.0, 10.0, -12.0},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, AssignmentOperatorSubtraction) {
  ThermalConductivity thermal_conductivity(
      {3.0, -6.0, 9.0, -12.0, 15.0, -18.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  thermal_conductivity -= ThermalConductivity(
      {2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(thermal_conductivity,
            ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, ComparisonOperators) {
  const ThermalConductivity first(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.000001}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  const ThermalConductivity second(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ThermalConductivity, Constructor) {
  EXPECT_NO_THROW(ThermalConductivity(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity(
                ScalarThermalConductivity(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin)),
            ThermalConductivity(
                {2.0, 0.0, 0.0, 2.0, 0.0, 2.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, CopyAssignmentOperator) {
  {
    const ThermalConductivity<float> first(
        {1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
    ThermalConductivity<double> second = ThermalConductivity<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, ThermalConductivity<double>({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                            Unit::ThermalConductivity::WattPerMetrePerKelvin));
  }
  {
    const ThermalConductivity<double> first(
        {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
    ThermalConductivity<double> second = ThermalConductivity<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, ThermalConductivity<double>({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                            Unit::ThermalConductivity::WattPerMetrePerKelvin));
  }
  {
    const ThermalConductivity<long double> first(
        {1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
    ThermalConductivity<double> second = ThermalConductivity<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, ThermalConductivity<double>({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                            Unit::ThermalConductivity::WattPerMetrePerKelvin));
  }
}

TEST(ThermalConductivity, CopyConstructor) {
  {
    const ThermalConductivity<float> first(
        {1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
    const ThermalConductivity<double> second{first};
    EXPECT_EQ(
        second, ThermalConductivity<double>({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                            Unit::ThermalConductivity::WattPerMetrePerKelvin));
  }
  {
    const ThermalConductivity<double> first(
        {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
    const ThermalConductivity<double> second{first};
    EXPECT_EQ(
        second, ThermalConductivity<double>({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                            Unit::ThermalConductivity::WattPerMetrePerKelvin));
  }
  {
    const ThermalConductivity<long double> first(
        {1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
    const ThermalConductivity<double> second{first};
    EXPECT_EQ(
        second, ThermalConductivity<double>({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                            Unit::ThermalConductivity::WattPerMetrePerKelvin));
  }
}

TEST(ThermalConductivity, Create) {
  {
    constexpr ThermalConductivity thermal_conductivity =
        ThermalConductivity<>::Create<Unit::ThermalConductivity::WattPerMetrePerKelvin>(
            1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    EXPECT_EQ(thermal_conductivity,
              ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                  Unit::ThermalConductivity::WattPerMetrePerKelvin));
  }
  {
    constexpr ThermalConductivity thermal_conductivity =
        ThermalConductivity<>::Create<Unit::ThermalConductivity::WattPerMetrePerKelvin>(
            std::array<double, 6>{1.0, -2.0, 3.0, -4.0, 5.0, -6.0});
    EXPECT_EQ(thermal_conductivity,
              ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                  Unit::ThermalConductivity::WattPerMetrePerKelvin));
  }
  {
    constexpr ThermalConductivity thermal_conductivity =
        ThermalConductivity<>::Create<Unit::ThermalConductivity::WattPerMetrePerKelvin>(
            SymmetricDyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0});
    EXPECT_EQ(thermal_conductivity,
              ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                  Unit::ThermalConductivity::WattPerMetrePerKelvin));
  }
}

TEST(ThermalConductivity, DefaultConstructor) {
  EXPECT_NO_THROW(ThermalConductivity<>{});
}

TEST(ThermalConductivity, Dimensions) {
  EXPECT_EQ(ThermalConductivity<>::Dimensions(), RelatedDimensions<Unit::ThermalConductivity>);
}

TEST(ThermalConductivity, Hash) {
  const ThermalConductivity first(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin);
  const ThermalConductivity second({1.0, -2.0, 3.0, -4.0, 5.0, -6.000001},
                                   Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin);
  const ThermalConductivity third(
      {1.0, -2.0, 3.0, 4.0, 5.0, -6.0}, Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin);
  const std::hash<ThermalConductivity<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ThermalConductivity, JSON) {
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .JSON(),
            "{\"value\":{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
                + ",\"yy\":" + Print(-4.0) + ",\"yz\":" + Print(5.0) + ",\"zz\":" + Print(-6.0)
                + "},\"unit\":\"W/m/K\"}");
  EXPECT_EQ(ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
                .JSON(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
            "{\"value\":{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
                + ",\"yy\":" + Print(-4.0) + ",\"yz\":" + Print(5.0) + ",\"zz\":" + Print(-6.0)
                + "},\"unit\":\"nW/mm/K\"}");
}

TEST(ThermalConductivity, MoveAssignmentOperator) {
  ThermalConductivity first(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  ThermalConductivity second = ThermalConductivity<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                        Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, MoveConstructor) {
  ThermalConductivity first(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  const ThermalConductivity second{std::move(first)};
  EXPECT_EQ(second, ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                        Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, MutableValue) {
  ThermalConductivity thermal_conductivity(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  SymmetricDyad<>& value = thermal_conductivity.MutableValue();
  value = SymmetricDyad{-7.0, 8.0, -9.0, 10.0, -11.0, 12.0};
  EXPECT_EQ(thermal_conductivity.Value(), SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
}

TEST(ThermalConductivity, Print) {
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + "; " + Print(-6.0) + ") W/m/K");
  EXPECT_EQ(ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
                .Print(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + "; " + Print(-6.0) + ") nW/mm/K");
}

TEST(ThermalConductivity, SetValue) {
  ThermalConductivity thermal_conductivity(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  thermal_conductivity.SetValue(SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  EXPECT_EQ(thermal_conductivity.Value(), SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
}

TEST(ThermalConductivity, SizeOf) {
  EXPECT_EQ(sizeof(ThermalConductivity<>{}), 6 * sizeof(double));
}

TEST(ThermalConductivity, StaticValue) {
  constexpr ThermalConductivity thermal_conductivity =
      ThermalConductivity<>::Create<Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>(
          1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  constexpr SymmetricDyad value =
      thermal_conductivity.StaticValue<Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin>();
  EXPECT_EQ(value, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(ThermalConductivity, Stream) {
  std::ostringstream stream;
  stream << ThermalConductivity(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(stream.str(), ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
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
            "<value><xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0)
                + "</xz><yy>" + Print(-4.0) + "</yy><yz>" + Print(5.0) + "</yz><zz>" + Print(-6.0)
                + "</zz></value><unit>W/m/K</unit>");
  EXPECT_EQ(ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
                .XML(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
            "<value><xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0)
                + "</xz><yy>" + Print(-4.0) + "</yy><yz>" + Print(5.0) + "</yz><zz>" + Print(-6.0)
                + "</zz></value><unit>nW/mm/K</unit>");
}

TEST(ThermalConductivity, XYZ) {
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .xx(),
            ScalarThermalConductivity(1.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .xy(),
            ScalarThermalConductivity(-2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .xz(),
            ScalarThermalConductivity(3.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .yx(),
            ScalarThermalConductivity(-2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .yy(),
            ScalarThermalConductivity(-4.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .yz(),
            ScalarThermalConductivity(5.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .zx(),
            ScalarThermalConductivity(3.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .zy(),
            ScalarThermalConductivity(5.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .zz(),
            ScalarThermalConductivity(-6.0, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

TEST(ThermalConductivity, YAML) {
  EXPECT_EQ(ThermalConductivity(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin)
                .YAML(),
            "{value:{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yy:"
                + Print(-4.0) + ",yz:" + Print(5.0) + ",zz:" + Print(-6.0) + "},unit:\"W/m/K\"}");
  EXPECT_EQ(ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin)
                .YAML(Unit::ThermalConductivity::NanowattPerMillimetrePerKelvin),
            "{value:{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yy:"
                + Print(-4.0) + ",yz:" + Print(5.0) + ",zz:" + Print(-6.0) + "},unit:\"nW/mm/K\"}");
}

TEST(ThermalConductivity, Zero) {
  EXPECT_EQ(ThermalConductivity<>::Zero(),
            ThermalConductivity(
                {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, Unit::ThermalConductivity::WattPerMetrePerKelvin));
}

}  // namespace

}  // namespace PhQ
