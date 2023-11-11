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

#include "../include/PhQ/TemperatureGradient.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/TemperatureGradientScalar.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/TemperatureGradient.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(TemperatureGradient, Angle) {
  EXPECT_EQ(
      TemperatureGradient({0.0, -2.22, 0.0}, Unit::TemperatureGradient::KelvinPerMetre)
          .Angle(TemperatureGradient({0.0, 0.0, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)),
      Angle(90.0, Unit::Angle::Degree));
}

TEST(TemperatureGradient, ArithmeticOperatorAddition) {
  EXPECT_EQ(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)
                + TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradient({3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, ArithmeticOperatorDivision) {
  EXPECT_EQ(TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre) / 2.0,
            TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre) * 2.0,
            TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(2.0 * TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(Direction(2.0, -3.0, 6.0)
                * TemperatureGradientScalar(7.0, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradient({2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(TemperatureGradientScalar(7.0, Unit::TemperatureGradient::KelvinPerMetre)
                * Direction(2.0, -3.0, 6.0),
            TemperatureGradient({2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(TemperatureGradient({3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre)
                - TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, AssignmentOperatorAddition) {
  TemperatureGradient quantity({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  quantity += TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(
      quantity, TemperatureGradient({3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, AssignmentOperatorDivision) {
  TemperatureGradient quantity({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre);
  quantity /= 2.0;
  EXPECT_EQ(
      quantity, TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, AssignmentOperatorMultiplication) {
  TemperatureGradient quantity({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre);
  quantity *= 2.0;
  EXPECT_EQ(
      quantity, TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, AssignmentOperatorSubtraction) {
  TemperatureGradient quantity({3.0, -6.0, 9.0}, Unit::TemperatureGradient::KelvinPerMetre);
  quantity -= TemperatureGradient({2.0, -4.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(
      quantity, TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, ComparisonOperators) {
  const TemperatureGradient first({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
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

TEST(TemperatureGradient, CopyAssignmentOperator) {
  const TemperatureGradient first({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  TemperatureGradient second = TemperatureGradient::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(TemperatureGradient, CopyConstructor) {
  const TemperatureGradient first({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  const TemperatureGradient second{first};
  EXPECT_EQ(second, first);
}

TEST(TemperatureGradient, Create) {
  constexpr TemperatureGradient first =
      TemperatureGradient::Create<Unit::TemperatureGradient::KelvinPerMetre>(1.11, -2.22, 3.33);
  EXPECT_EQ(
      first, TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre));

  constexpr TemperatureGradient second =
      TemperatureGradient::Create<Unit::TemperatureGradient::KelvinPerMetre>(
          std::array<double, 3>{1.11, -2.22, 3.33});
  EXPECT_EQ(
      second, TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre));

  constexpr TemperatureGradient third =
      TemperatureGradient::Create<Unit::TemperatureGradient::KelvinPerMetre>(
          Vector{1.11, -2.22, 3.33});
  EXPECT_EQ(
      third, TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, DefaultConstructor) {
  EXPECT_NO_THROW(TemperatureGradient{});
}

TEST(TemperatureGradient, Dimensions) {
  EXPECT_EQ(TemperatureGradient::Dimensions(), RelatedDimensions<Unit::TemperatureGradient>);
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
  EXPECT_EQ(
      TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre).JSON(),
      "{\"value\":{\"x\":1.110000000000000,\"y\":-2.220000000000000,\"z\":3.330000000000000},"
      "\"unit\":\"K/m\"}");
  EXPECT_EQ(TemperatureGradient({0.0, -2.22, 0.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .JSON(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{\"value\":{\"x\":0,\"y\":-2.220000000000000,\"z\":0},\"unit\":\"K/mm\"}");
}

TEST(TemperatureGradient, Magnitude) {
  EXPECT_EQ(
      TemperatureGradient({2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre).Magnitude(),
      TemperatureGradientScalar(7.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(TemperatureGradient(
                {1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)),
            Direction(1.11, -2.22, 3.33));

  EXPECT_EQ(Angle(TemperatureGradient({0.0, -2.22, 0.0}, Unit::TemperatureGradient::KelvinPerMetre),
                  TemperatureGradient({0.0, 0.0, 3.33}, Unit::TemperatureGradient::KelvinPerMetre)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(TemperatureGradientScalar(
                TemperatureGradient({2.0, -3.0, 6.0}, Unit::TemperatureGradient::KelvinPerMetre)),
            TemperatureGradientScalar(7.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, MoveAssignmentOperator) {
  TemperatureGradient first({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  TemperatureGradient second = TemperatureGradient::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, MoveConstructor) {
  TemperatureGradient first({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  const TemperatureGradient second{std::move(first)};
  EXPECT_EQ(
      second, TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradient, MutableValue) {
  TemperatureGradient quantity({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  Vector& value = quantity.MutableValue();
  value = Vector{-4.44, 5.55, -6.66};
  EXPECT_EQ(quantity.Value(), Vector(-4.44, 5.55, -6.66));
}

TEST(TemperatureGradient, Print) {
  EXPECT_EQ(
      TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre).Print(),
      "(1.110000000000000, -2.220000000000000, 3.330000000000000) K/m");
  EXPECT_EQ(TemperatureGradient({0.0, -2.22, 0.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Print(Unit::TemperatureGradient::KelvinPerMillimetre),
            "(0, -2.220000000000000, 0) K/mm");
}

TEST(TemperatureGradient, SetValue) {
  TemperatureGradient quantity({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  quantity.SetValue({-4.44, 5.55, -6.66});
  EXPECT_EQ(quantity.Value(), Vector(-4.44, 5.55, -6.66));
}

TEST(TemperatureGradient, SizeOf) {
  EXPECT_EQ(sizeof(TemperatureGradient{}), 3 * sizeof(double));
}

TEST(TemperatureGradient, StandardConstructor) {
  EXPECT_NO_THROW(
      TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMillimetre));
}

TEST(TemperatureGradient, StaticValue) {
  constexpr TemperatureGradient quantity =
      TemperatureGradient::Create<Unit::TemperatureGradient::KelvinPerMillimetre>(
          1.11, -2.22, 3.33);
  constexpr Vector value = quantity.StaticValue<Unit::TemperatureGradient::KelvinPerMillimetre>();
  EXPECT_EQ(value, Vector(1.11, -2.22, 3.33));
}

TEST(TemperatureGradient, Stream) {
  std::ostringstream stream;
  stream << TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(
      stream.str(),
      TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre).Print());
}

TEST(TemperatureGradient, Unit) {
  EXPECT_EQ(TemperatureGradient::Unit(), Standard<Unit::TemperatureGradient>);
}

TEST(TemperatureGradient, Value) {
  EXPECT_EQ(
      TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre).Value(),
      Vector(1.11, -2.22, 3.33));
  EXPECT_EQ(TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Value(Unit::TemperatureGradient::KelvinPerMillimetre),
            Vector(1.11, -2.22, 3.33));
}

TEST(TemperatureGradient, XML) {
  EXPECT_EQ(
      TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre).XML(),
      "<value><x>1.110000000000000</x><y>-2.220000000000000</y><z>3.330000000000000</z></"
      "value><unit>K/m</unit>");
  EXPECT_EQ(TemperatureGradient({0.0, -2.22, 0.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .XML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "<value><x>0</x><y>-2.220000000000000</y><z>0</z></value><unit>K/mm</unit>");
}

TEST(TemperatureGradient, YAML) {
  EXPECT_EQ(
      TemperatureGradient({1.11, -2.22, 3.33}, Unit::TemperatureGradient::KelvinPerMetre).YAML(),
      "{value:{x:1.110000000000000,y:-2.220000000000000,z:3.330000000000000},unit:\"K/m\"}");
  EXPECT_EQ(TemperatureGradient({0.0, -2.22, 0.0}, Unit::TemperatureGradient::KelvinPerMillimetre)
                .YAML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{value:{x:0,y:-2.220000000000000,z:0},unit:\"K/mm\"}");
}

TEST(TemperatureGradient, Zero) {
  EXPECT_EQ(TemperatureGradient::Zero(),
            TemperatureGradient({0.0, 0.0, 0.0}, Unit::TemperatureGradient::KelvinPerMetre));
}

}  // namespace

}  // namespace PhQ
