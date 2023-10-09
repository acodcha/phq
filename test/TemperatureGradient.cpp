// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#include "../include/PhQ/TemperatureGradient.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(TemperatureGradient, Angle) {
  EXPECT_EQ(
      TemperatureGradient(
          {0.0, -2.22, 0.0}, Unit::TemperatureGradient::KelvinPerMetre)
          .Angle(TemperatureGradient(
              {0.0, 0.0, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)),
      Angle(90.0, Unit::Angle::Degree));
}

TEST(TemperatureGradient, ArithmeticAddition) {
  EXPECT_EQ(
      TemperatureGradient(
          {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)
          + TemperatureGradient(
              {2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre),
      TemperatureGradient(
          {3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre));

  TemperatureGradient quantity(
      {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  quantity += TemperatureGradient(
      {2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(quantity,
            TemperatureGradient(
                {3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, ArithmeticDivision) {
  EXPECT_EQ(TemperatureGradient(
                {2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre)
                / 2.0,
            TemperatureGradient(
                {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));

  TemperatureGradient quantity(
      {2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre);
  quantity /= 2.0;
  EXPECT_EQ(quantity,
            TemperatureGradient(
                {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, ArithmeticMultiplication) {
  EXPECT_EQ(TemperatureGradient(
                {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)
                * 2.0,
            TemperatureGradient(
                {2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(
      2.0
          * TemperatureGradient(
              {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre),
      TemperatureGradient(
          {2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(Direction(2.0, -3.0, 6.0)
                * TemperatureGradientMagnitude(
                    7.0, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradient(
                {2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(TemperatureGradientMagnitude(
                7.0, Unit::TemperatureGradient::KelvinPerMetre)
                * Direction(2.0, -3.0, 6.0),
            TemperatureGradient(
                {2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));

  TemperatureGradient quantity(
      {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  quantity *= 2.0;
  EXPECT_EQ(quantity,
            TemperatureGradient(
                {2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, ArithmeticSubtraction) {
  EXPECT_EQ(
      TemperatureGradient(
          {3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre)
          - TemperatureGradient(
              {2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre),
      TemperatureGradient(
          {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));

  TemperatureGradient quantity(
      {3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre);
  quantity -= TemperatureGradient(
      {2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(quantity,
            TemperatureGradient(
                {1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, Comparisons) {
  const TemperatureGradient first(
      {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  const TemperatureGradient second(
      {1.11, -2.22, 3.330001}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(TemperatureGradient, CopyAssignment) {
  const TemperatureGradient first(
      {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  TemperatureGradient second = TemperatureGradient::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(TemperatureGradient, CopyConstructor) {
  const TemperatureGradient first(
      {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  const TemperatureGradient second{first};
  EXPECT_EQ(second, first);
}

TEST(TemperatureGradient, Create) {
  constexpr TemperatureGradient quantity =
      TemperatureGradient::Create<Unit::TemperatureGradient::KelvinPerMetre>(
          {1.11, -2.22, 3.33});
  EXPECT_EQ(quantity,
            TemperatureGradient({1.11, -2.22, 3.33},
                                Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, DefaultConstructor) {
  EXPECT_NO_THROW(TemperatureGradient{});
}

TEST(TemperatureGradient, Dimensions) {
  EXPECT_EQ(TemperatureGradient::Dimensions(),
            RelatedDimensions<Unit::TemperatureGradient>);
}

TEST(TemperatureGradient, Hash) {
  const TemperatureGradient first(
      {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMillimetre);
  const TemperatureGradient second(
      {1.11, -2.22, 3.330001}, Unit::TemperatureGradient::KelvinPerMillimetre);
  const TemperatureGradient third(
      {1.11, 2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMillimetre);
  const std::hash<TemperatureGradient> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(TemperatureGradient, JSON) {
  EXPECT_EQ(TemperatureGradient(
                {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)
                .JSON(),
            "{\"value\":{\"x\":1.110000000000000,\"y\":-2.220000000000000,"
            "\"z\":3.330000000000000},\"unit\":\"K/m\"}");
  EXPECT_EQ(TemperatureGradient({0.0, -2.22, 0.0},
                                Unit::TemperatureGradient::KelvinPerMillimetre)
                .JSON(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{\"value\":{\"x\":0,\"y\":-2.220000000000000,\"z\":0},\"unit\":"
            "\"K/mm\"}");
}

TEST(TemperatureGradient, Magnitude) {
  EXPECT_EQ(TemperatureGradient(
                {2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre)
                .Magnitude(),
            TemperatureGradientMagnitude(
                7.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, MiscellaneousConstructors) {
  EXPECT_EQ(
      Direction(TemperatureGradient(
          {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)),
      Direction(1.11, -2.22, 3.33));

  EXPECT_EQ(
      Angle(TemperatureGradient(
                {0.0, -2.22, 0.0}, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradient(
                {0.0, 0.0, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)),
      Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(TemperatureGradientMagnitude(TemperatureGradient(
                {2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre)),
            TemperatureGradientMagnitude(
                7.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, MoveAssignment) {
  TemperatureGradient first(
      {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  TemperatureGradient second = TemperatureGradient::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, TemperatureGradient({1.11, -2.22, 3.33},
                                  Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, MoveConstructor) {
  TemperatureGradient first(
      {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  TemperatureGradient second{std::move(first)};
  EXPECT_EQ(
      second, TemperatureGradient({1.11, -2.22, 3.33},
                                  Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, MutableValue) {
  TemperatureGradient quantity(
      {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  Value::Vector& value = quantity.MutableValue();
  value = Value::Vector{-4.44, 5.55, -6.66};
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(TemperatureGradient, Print) {
  EXPECT_EQ(TemperatureGradient(
                {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)
                .Print(),
            "(1.110000000000000, -2.220000000000000, 3.330000000000000) K/m");
  EXPECT_EQ(TemperatureGradient({0.0, -2.22, 0.0},
                                Unit::TemperatureGradient::KelvinPerMillimetre)
                .Print(Unit::TemperatureGradient::KelvinPerMillimetre),
            "(0, -2.220000000000000, 0) K/mm");
}

TEST(TemperatureGradient, SetValue) {
  TemperatureGradient quantity(
      {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  quantity.SetValue({-4.44, 5.55, -6.66});
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(TemperatureGradient, SizeOf) {
  EXPECT_EQ(sizeof(TemperatureGradient{}), 3 * sizeof(double));
}

TEST(TemperatureGradient, StandardConstructor) {
  EXPECT_NO_THROW(TemperatureGradient(
      {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMillimetre));
}

TEST(TemperatureGradient, StaticValue) {
  constexpr TemperatureGradient quantity = TemperatureGradient::Create<
      Unit::TemperatureGradient::KelvinPerMillimetre>({1.11, -2.22, 3.33});
  constexpr Value::Vector value =
      quantity.StaticValue<Unit::TemperatureGradient::KelvinPerMillimetre>();
  EXPECT_EQ(value, Value::Vector(1.11, -2.22, 3.33));
}

TEST(TemperatureGradient, Stream) {
  std::ostringstream stream;
  stream << TemperatureGradient(
      {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(stream.str(),
            TemperatureGradient(
                {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)
                .Print());
}

TEST(TemperatureGradient, Unit) {
  EXPECT_EQ(TemperatureGradient::Unit(), Standard<Unit::TemperatureGradient>);
}

TEST(TemperatureGradient, Value) {
  EXPECT_EQ(TemperatureGradient(
                {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)
                .Value(),
            Value::Vector(1.11, -2.22, 3.33));
  EXPECT_EQ(TemperatureGradient({1.11, -2.22, 3.33},
                                Unit::TemperatureGradient::KelvinPerMillimetre)
                .Value(Unit::TemperatureGradient::KelvinPerMillimetre),
            Value::Vector(1.11, -2.22, 3.33));
}

TEST(TemperatureGradient, XML) {
  EXPECT_EQ(TemperatureGradient(
                {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)
                .XML(),
            "<value><x>1.110000000000000</x><y>-2.220000000000000</"
            "y><z>3.330000000000000</z></value><unit>K/m</unit>");
  EXPECT_EQ(TemperatureGradient({0.0, -2.22, 0.0},
                                Unit::TemperatureGradient::KelvinPerMillimetre)
                .XML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "<value><x>0</x><y>-2.220000000000000</y><z>0</z></value><unit>K/"
            "mm</unit>");
}

TEST(TemperatureGradient, YAML) {
  EXPECT_EQ(TemperatureGradient(
                {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)
                .YAML(),
            "{value:{x:1.110000000000000,y:-2.220000000000000,z:3."
            "330000000000000},unit:\"K/m\"}");
  EXPECT_EQ(TemperatureGradient({0.0, -2.22, 0.0},
                                Unit::TemperatureGradient::KelvinPerMillimetre)
                .YAML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{value:{x:0,y:-2.220000000000000,z:0},unit:\"K/mm\"}");
}

TEST(TemperatureGradient, Zero) {
  EXPECT_EQ(TemperatureGradient::Zero(),
            TemperatureGradient(
                {0.0, 0.0, 0.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

}  // namespace

}  // namespace PhQ
