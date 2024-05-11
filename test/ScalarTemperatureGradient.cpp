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

#include "../include/PhQ/ScalarTemperatureGradient.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "../include/PhQ/Unit/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/TemperatureGradient.hpp"

namespace PhQ {

namespace {

TEST(ScalarTemperatureGradient, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre)
                + ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre),
            ScalarTemperatureGradient(3.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarTemperatureGradient(8.0, Unit::TemperatureGradient::KelvinPerMetre) / 2.0,
            ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(ScalarTemperatureGradient(8.0, Unit::TemperatureGradient::KelvinPerMetre)
                / ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre),
            4.0);
  EXPECT_EQ(TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin)
                / Length(4.0, Unit::Length::Metre),
            ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre) * 2.0,
            ScalarTemperatureGradient(8.0, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(2.0 * ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre),
            ScalarTemperatureGradient(8.0, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre)
                * Length(2.0, Unit::Length::Metre),
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(ScalarTemperatureGradient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarTemperatureGradient(3.0, Unit::TemperatureGradient::KelvinPerMetre)
                - ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre),
            ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, AssignmentOperatorAddition) {
  ScalarTemperatureGradient quantity{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity += ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(quantity, ScalarTemperatureGradient(3.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, AssignmentOperatorDivision) {
  ScalarTemperatureGradient quantity{8.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, AssignmentOperatorMultiplication) {
  ScalarTemperatureGradient quantity{4.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ScalarTemperatureGradient(8.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, AssignmentOperatorSubtraction) {
  ScalarTemperatureGradient quantity{3.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity -= ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(quantity, ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, ComparisonOperators) {
  const ScalarTemperatureGradient first{0.1, Unit::TemperatureGradient::KelvinPerMetre};
  const ScalarTemperatureGradient second{0.2, Unit::TemperatureGradient::KelvinPerMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarTemperatureGradient, CopyAssignmentOperator) {
  const ScalarTemperatureGradient first{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  ScalarTemperatureGradient second = ScalarTemperatureGradient<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ScalarTemperatureGradient, CopyConstructor) {
  const ScalarTemperatureGradient first{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  const ScalarTemperatureGradient second{first};
  EXPECT_EQ(second, first);
}

TEST(ScalarTemperatureGradient, Create) {
  constexpr ScalarTemperatureGradient quantity =
      ScalarTemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMetre>(1.0);
  EXPECT_EQ(quantity, ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarTemperatureGradient{});
}

TEST(ScalarTemperatureGradient, Dimensions) {
  EXPECT_EQ(
      ScalarTemperatureGradient<>::Dimensions(), RelatedDimensions<Unit::TemperatureGradient>);
}

TEST(ScalarTemperatureGradient, Hash) {
  const ScalarTemperatureGradient first{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  const ScalarTemperatureGradient second{1.00001, Unit::TemperatureGradient::KelvinPerMetre};
  const ScalarTemperatureGradient third{-1.0, Unit::TemperatureGradient::KelvinPerMetre};
  const std::hash<ScalarTemperatureGradient<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarTemperatureGradient, JSON) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"K/m\"}");
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre)
                .JSON(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"K/mm\"}");
}

TEST(ScalarTemperatureGradient, MiscellaneousConstructors) {
  EXPECT_EQ(
      ScalarTemperatureGradient(TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin),
                                Length(4.0, Unit::Length::Metre)),
      ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(TemperatureDifference(
                ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre),
                Length(2.0, Unit::Length::Metre)),
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(ScalarTemperatureGradient, MoveAssignmentOperator) {
  ScalarTemperatureGradient first{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  ScalarTemperatureGradient second = ScalarTemperatureGradient<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, MoveConstructor) {
  ScalarTemperatureGradient first{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  const ScalarTemperatureGradient second{std::move(first)};
  EXPECT_EQ(second, ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, MutableValue) {
  ScalarTemperatureGradient quantity{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarTemperatureGradient, Print) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).Print(),
            Print(1.0) + " K/m");
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Print(Unit::TemperatureGradient::KelvinPerMillimetre),
            Print(1.0) + " K/mm");
}

TEST(ScalarTemperatureGradient, SetValue) {
  ScalarTemperatureGradient quantity{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarTemperatureGradient, SizeOf) {
  EXPECT_EQ(sizeof(ScalarTemperatureGradient{}), sizeof(double));
}

TEST(ScalarTemperatureGradient, StandardConstructor) {
  EXPECT_NO_THROW(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre));
}

TEST(ScalarTemperatureGradient, StaticValue) {
  constexpr ScalarTemperatureGradient quantity =
      ScalarTemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMillimetre>(1.0);
  constexpr double value = quantity.StaticValue<Unit::TemperatureGradient::KelvinPerMillimetre>();
  EXPECT_EQ(value, 1.0);
}

TEST(ScalarTemperatureGradient, Stream) {
  std::ostringstream stream;
  stream << ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(stream.str(),
            ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).Print());
}

TEST(ScalarTemperatureGradient, Unit) {
  EXPECT_EQ(ScalarTemperatureGradient<>::Unit(), Standard<Unit::TemperatureGradient>);
}

TEST(ScalarTemperatureGradient, Value) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).Value(), 1.0);
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Value(Unit::TemperatureGradient::KelvinPerMillimetre),
            1.0);
}

TEST(ScalarTemperatureGradient, XML) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).XML(),
            "<value>" + Print(1.0) + "</value><unit>K/m</unit>");
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre)
                .XML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "<value>" + Print(1.0) + "</value><unit>K/mm</unit>");
}

TEST(ScalarTemperatureGradient, YAML) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).YAML(),
            "{value:" + Print(1.0) + ",unit:\"K/m\"}");
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre)
                .YAML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{value:" + Print(1.0) + ",unit:\"K/mm\"}");
}

TEST(ScalarTemperatureGradient, Zero) {
  EXPECT_EQ(ScalarTemperatureGradient<>::Zero(),
            ScalarTemperatureGradient(0.0, Unit::TemperatureGradient::KelvinPerMetre));
}

}  // namespace

}  // namespace PhQ
