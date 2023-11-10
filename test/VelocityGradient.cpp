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

#include "../include/PhQ/VelocityGradient.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/StrainRate.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Value/Dyad.hpp"

namespace PhQ {

namespace {

TEST(VelocityGradient, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          + VelocityGradient(
              {2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0}, Unit::Frequency::Hertz),
      VelocityGradient(
          {3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0}, Unit::Frequency::Hertz));
}

TEST(VelocityGradient, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      VelocityGradient(
          {2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0}, Unit::Frequency::Hertz)
          / 2.0,
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz));
}

TEST(VelocityGradient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          * 2.0,
      VelocityGradient(
          {2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0}, Unit::Frequency::Hertz));

  EXPECT_EQ(2.0
                * VelocityGradient(
                    {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz),
            VelocityGradient(
                {2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0}, Unit::Frequency::Hertz));
}

TEST(VelocityGradient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      VelocityGradient(
          {3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0}, Unit::Frequency::Hertz)
          - VelocityGradient(
              {2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0}, Unit::Frequency::Hertz),
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz));
}

TEST(VelocityGradient, AssignmentOperatorAddition) {
  VelocityGradient quantity(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz);
  quantity += VelocityGradient(
      {2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0}, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, VelocityGradient({3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0},
                                       Unit::Frequency::Hertz));
}

TEST(VelocityGradient, AssignmentOperatorDivision) {
  VelocityGradient quantity(
      {2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0}, Unit::Frequency::Hertz);
  quantity /= 2.0;
  EXPECT_EQ(quantity, VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0},
                                       Unit::Frequency::Hertz));
}

TEST(VelocityGradient, AssignmentOperatorMultiplication) {
  VelocityGradient quantity(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz);
  quantity *= 2.0;
  EXPECT_EQ(quantity, VelocityGradient({2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0},
                                       Unit::Frequency::Hertz));
}

TEST(VelocityGradient, AssignmentOperatorSubtraction) {
  VelocityGradient quantity(
      {3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0}, Unit::Frequency::Hertz);
  quantity -= VelocityGradient(
      {2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0}, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0},
                                       Unit::Frequency::Hertz));
}

TEST(VelocityGradient, ComparisonOperators) {
  const VelocityGradient first(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}, Unit::Frequency::Hertz);
  const VelocityGradient second(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.990001}, Unit::Frequency::Hertz);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(VelocityGradient, CopyAssignmentOperator) {
  const VelocityGradient first(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}, Unit::Frequency::Hertz);
  VelocityGradient second = VelocityGradient::Zero();
  second = first;
  EXPECT_EQ(second, VelocityGradient({1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99},
                                     Unit::Frequency::Hertz));
}

TEST(VelocityGradient, CopyConstructor) {
  const VelocityGradient first(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}, Unit::Frequency::Hertz);
  const VelocityGradient second{first};
  EXPECT_EQ(second, VelocityGradient({1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99},
                                     Unit::Frequency::Hertz));
}

TEST(VelocityGradient, Create) {
  constexpr VelocityGradient first = VelocityGradient::Create<Unit::Frequency::Hertz>(
      1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  EXPECT_EQ(first, VelocityGradient({1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99},
                                    Unit::Frequency::Hertz));

  constexpr VelocityGradient second = VelocityGradient::Create<Unit::Frequency::Hertz>(
      std::array<double, 9>{1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99});
  EXPECT_EQ(second, VelocityGradient({1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99},
                                     Unit::Frequency::Hertz));

  constexpr VelocityGradient third = VelocityGradient::Create<Unit::Frequency::Hertz>(
      Value::Dyad{1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99});
  EXPECT_EQ(third, VelocityGradient({1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99},
                                    Unit::Frequency::Hertz));
}

TEST(VelocityGradient, DefaultConstructor) {
  EXPECT_NO_THROW(VelocityGradient{});
}

TEST(VelocityGradient, Dimensions) {
  EXPECT_EQ(VelocityGradient::Dimensions(), RelatedDimensions<Unit::Frequency>);
}

TEST(VelocityGradient, Hash) {
  const VelocityGradient first(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}, Unit::Frequency::Kilohertz);
  const VelocityGradient second(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.990001}, Unit::Frequency::Kilohertz);
  const VelocityGradient third(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, 8.88, 9.99}, Unit::Frequency::Kilohertz);
  const std::hash<VelocityGradient> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(VelocityGradient, JSON) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .JSON(),
      "{\"value\":{\"xx\":1.000000000000000,\"xy\":-2.000000000000000,\"xz\":3.000000000000000,"
      "\"yx\":-4.000000000000000,\"yy\":5.000000000000000,\"yz\":-6.000000000000000,\"zx\":7."
      "000000000000000,\"zy\":-8.000000000000000,\"zz\":9.000000000000000},\"unit\":\"Hz\"}");
  EXPECT_EQ(
      VelocityGradient(
          {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Kilohertz)
          .JSON(Unit::Frequency::Kilohertz),
      "{\"value\":{\"xx\":1.000000000000000,\"xy\":-2.000000000000000,\"xz\":3.000000000000000,"
      "\"yx\":-4.000000000000000,\"yy\":5.000000000000000,\"yz\":-6.000000000000000,\"zx\":7."
      "000000000000000,\"zy\":-8.000000000000000,\"zz\":9.000000000000000},\"unit\":\"kHz\"}");
}

TEST(VelocityGradient, MiscellaneousConstructors) {
  EXPECT_EQ(StrainRate(VelocityGradient(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)),
            StrainRate({1.0, -3.0, 5.0, 5.0, -7.0, 9.0}, Unit::Frequency::Hertz));
}

TEST(VelocityGradient, MiscellaneousMethods) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .StrainRate(),
      StrainRate({1.0, -3.0, 5.0, 5.0, -7.0, 9.0}, Unit::Frequency::Hertz));
}

TEST(VelocityGradient, MoveAssignmentOperator) {
  VelocityGradient first(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}, Unit::Frequency::Hertz);
  VelocityGradient second = VelocityGradient::Zero();
  second = std::move(first);
  EXPECT_EQ(second, VelocityGradient({1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99},
                                     Unit::Frequency::Hertz));
}

TEST(VelocityGradient, MoveConstructor) {
  VelocityGradient first(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}, Unit::Frequency::Hertz);
  const VelocityGradient second{std::move(first)};
  EXPECT_EQ(second, VelocityGradient({1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99},
                                     Unit::Frequency::Hertz));
}

TEST(VelocityGradient, MutableValue) {
  VelocityGradient quantity(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}, Unit::Frequency::Hertz);
  Value::Dyad& value = quantity.MutableValue();
  value = Value::Dyad{-10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18};
  EXPECT_EQ(quantity.Value(),
            Value::Dyad(-10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
}

TEST(VelocityGradient, Print) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .Print(),
      "(1.000000000000000, -2.000000000000000, 3.000000000000000; -4.000000000000000, "
      "5.000000000000000, -6.000000000000000; 7.000000000000000, -8.000000000000000, "
      "9.000000000000000) Hz");
  EXPECT_EQ(VelocityGradient(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Kilohertz)
                .Print(Unit::Frequency::Kilohertz),
            "(1.000000000000000, -2.000000000000000, 3.000000000000000; -4.000000000000000, "
            "5.000000000000000, -6.000000000000000; 7.000000000000000, -8.000000000000000, "
            "9.000000000000000) kHz");
}

TEST(VelocityGradient, SetValue) {
  VelocityGradient quantity(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}, Unit::Frequency::Hertz);
  quantity.SetValue(
      Value::Dyad(-10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
  EXPECT_EQ(quantity.Value(),
            Value::Dyad(-10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
}

TEST(VelocityGradient, SizeOf) {
  EXPECT_EQ(sizeof(VelocityGradient{}), 9 * sizeof(double));
}

TEST(VelocityGradient, StandardConstructor) {
  EXPECT_NO_THROW(VelocityGradient(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}, Unit::Frequency::Hertz));
}

TEST(VelocityGradient, StaticValue) {
  constexpr VelocityGradient quantity = VelocityGradient::Create<Unit::Frequency::Kilohertz>(
      1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  constexpr Value::Dyad value = quantity.StaticValue<Unit::Frequency::Kilohertz>();
  EXPECT_EQ(value, Value::Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(VelocityGradient, Stream) {
  std::ostringstream stream;
  stream << VelocityGradient(
      {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}, Unit::Frequency::Hertz);
  EXPECT_EQ(stream.str(),
            VelocityGradient(
                {1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}, Unit::Frequency::Hertz)
                .Print());
}

TEST(VelocityGradient, Value) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .Value(),
      Value::Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  EXPECT_EQ(VelocityGradient(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Kilohertz)
                .Value(Unit::Frequency::Kilohertz),
            Value::Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(VelocityGradient, XML) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .XML(),
      "<value><xx>1.000000000000000</xx><xy>-2.000000000000000</xy><xz>3.000000000000000</"
      "xz><yx>-4.000000000000000</yx><yy>5.000000000000000</yy><yz>-6.000000000000000</"
      "yz><zx>7.000000000000000</zx><zy>-8.000000000000000</zy><zz>9.000000000000000</zz></"
      "value><unit>Hz</unit>");
  EXPECT_EQ(VelocityGradient(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Kilohertz)
                .XML(Unit::Frequency::Kilohertz),
            "<value><xx>1.000000000000000</xx><xy>-2.000000000000000</xy><xz>3.000000000000000</"
            "xz><yx>-4.000000000000000</yx><yy>5.000000000000000</yy><yz>-6.000000000000000</"
            "yz><zx>7.000000000000000</zx><zy>-8.000000000000000</zy><zz>9.000000000000000</zz></"
            "value><unit>kHz</unit>");
}

TEST(VelocityGradient, YAML) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .YAML(),
      "{value:{xx:1.000000000000000,xy:-2.000000000000000,xz:3.000000000000000,yx:-4."
      "000000000000000,yy:5.000000000000000,yz:-6.000000000000000,zx:7.000000000000000,zy:-8."
      "000000000000000,zz:9.000000000000000},unit:\"Hz\"}");
  EXPECT_EQ(VelocityGradient(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Kilohertz)
                .YAML(Unit::Frequency::Kilohertz),
            "{value:{xx:1.000000000000000,xy:-2.000000000000000,xz:3.000000000000000,yx:-4."
            "000000000000000,yy:5.000000000000000,yz:-6.000000000000000,zx:7.000000000000000,zy:-8."
            "000000000000000,zz:9.000000000000000},unit:\"kHz\"}");
}

TEST(VelocityGradient, Zero) {
  EXPECT_EQ(
      VelocityGradient::Zero(),
      VelocityGradient({0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, Unit::Frequency::Hertz));
}

}  // namespace

}  // namespace PhQ
