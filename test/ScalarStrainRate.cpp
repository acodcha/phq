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

#include "../include/PhQ/ScalarStrainRate.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/ScalarStrain.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(ScalarStrainRate, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      ScalarStrainRate(1.0, Unit::Frequency::Hertz) + ScalarStrainRate(2.0, Unit::Frequency::Hertz),
      ScalarStrainRate(3.0, Unit::Frequency::Hertz));
}

TEST(ScalarStrainRate, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarStrainRate(8.0, Unit::Frequency::Hertz) / 2.0,
            ScalarStrainRate(4.0, Unit::Frequency::Hertz));
  EXPECT_EQ(
      ScalarStrainRate(8.0, Unit::Frequency::Hertz) / ScalarStrainRate(2.0, Unit::Frequency::Hertz),
      4.0);
  EXPECT_EQ(ScalarStrain(8.0) / Time(4.0, Unit::Time::Second),
            ScalarStrainRate(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(ScalarStrainRate(8.0, Unit::Frequency::Hertz) / Frequency(4.0, Unit::Frequency::Hertz),
            ScalarStrain(2.0));
}

TEST(ScalarStrainRate, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarStrainRate(4.0, Unit::Frequency::Hertz) * 2.0,
            ScalarStrainRate(8.0, Unit::Frequency::Hertz));
  EXPECT_EQ(2.0 * ScalarStrainRate(4.0, Unit::Frequency::Hertz),
            ScalarStrainRate(8.0, Unit::Frequency::Hertz));
  EXPECT_EQ(ScalarStrainRate(4.0, Unit::Frequency::Hertz) * Time(2.0, Unit::Time::Second),
            ScalarStrain(8.0));
  EXPECT_EQ(Time(4.0, Unit::Time::Second) * ScalarStrainRate(2.0, Unit::Frequency::Hertz),
            ScalarStrain(8.0));
  EXPECT_EQ(ScalarStrain(2.0) * Frequency(4.0, Unit::Frequency::Hertz),
            ScalarStrainRate(8.0, Unit::Frequency::Hertz));
  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * ScalarStrain(2.0),
            ScalarStrainRate(8.0, Unit::Frequency::Hertz));
}

TEST(ScalarStrainRate, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      ScalarStrainRate(3.0, Unit::Frequency::Hertz) - ScalarStrainRate(2.0, Unit::Frequency::Hertz),
      ScalarStrainRate(1.0, Unit::Frequency::Hertz));
}

TEST(ScalarStrainRate, AssignmentOperatorAddition) {
  ScalarStrainRate quantity{1.0, Unit::Frequency::Hertz};
  quantity += ScalarStrainRate(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, ScalarStrainRate(3.0, Unit::Frequency::Hertz));
}

TEST(ScalarStrainRate, AssignmentOperatorDivision) {
  ScalarStrainRate quantity{8.0, Unit::Frequency::Hertz};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ScalarStrainRate(4.0, Unit::Frequency::Hertz));
}

TEST(ScalarStrainRate, AssignmentOperatorMultiplication) {
  ScalarStrainRate quantity{4.0, Unit::Frequency::Hertz};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ScalarStrainRate(8.0, Unit::Frequency::Hertz));
}

TEST(ScalarStrainRate, AssignmentOperatorSubtraction) {
  ScalarStrainRate quantity{3.0, Unit::Frequency::Hertz};
  quantity -= ScalarStrainRate(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, ScalarStrainRate(1.0, Unit::Frequency::Hertz));
}

TEST(ScalarStrainRate, ComparisonOperators) {
  const ScalarStrainRate first{1.0, Unit::Frequency::Hertz};
  const ScalarStrainRate second{2.0, Unit::Frequency::Hertz};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarStrainRate, CopyAssignmentOperator) {
  const ScalarStrainRate first{1.0, Unit::Frequency::Hertz};
  ScalarStrainRate second = ScalarStrainRate<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ScalarStrainRate, CopyConstructor) {
  const ScalarStrainRate first{1.0, Unit::Frequency::Hertz};
  const ScalarStrainRate second{first};
  EXPECT_EQ(second, first);
}

TEST(ScalarStrainRate, Create) {
  constexpr ScalarStrainRate quantity = ScalarStrainRate<>::Create<Unit::Frequency::Hertz>(1.0);
  EXPECT_EQ(quantity, ScalarStrainRate(1.0, Unit::Frequency::Hertz));
}

TEST(ScalarStrainRate, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarStrainRate{});
}

TEST(ScalarStrainRate, Dimensions) {
  EXPECT_EQ(ScalarStrainRate<>::Dimensions(), RelatedDimensions<Unit::Frequency>);
}

TEST(ScalarStrainRate, Hash) {
  const ScalarStrainRate first{1.0, Unit::Frequency::Kilohertz};
  const ScalarStrainRate second{1.00001, Unit::Frequency::Kilohertz};
  const ScalarStrainRate third{-1.0, Unit::Frequency::Kilohertz};
  const std::hash<ScalarStrainRate<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(ScalarStrainRate, JSON) {
  EXPECT_EQ(ScalarStrainRate(1.0, Unit::Frequency::Hertz).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Hz\"}");
  EXPECT_EQ(ScalarStrainRate(1.0, Unit::Frequency::Kilohertz).JSON(Unit::Frequency::Kilohertz),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kHz\"}");
}

TEST(ScalarStrainRate, MiscellaneousConstructors) {
  EXPECT_EQ(ScalarStrainRate(ScalarStrain(8.0), Time(4.0, Unit::Time::Second)),
            ScalarStrainRate(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(ScalarStrainRate(ScalarStrain(4.0), Frequency(2.0, Unit::Frequency::Hertz)),
            ScalarStrainRate(8.0, Unit::Frequency::Hertz));
  EXPECT_EQ(
      ScalarStrain(ScalarStrainRate(4.0, Unit::Frequency::Hertz), Time(2.0, Unit::Time::Second)),
      ScalarStrain(8.0));
  EXPECT_EQ(ScalarStrain(ScalarStrainRate(8.0, Unit::Frequency::Hertz),
                         Frequency(4.0, Unit::Frequency::Hertz)),
            ScalarStrain(2.0));
}

TEST(ScalarStrainRate, MoveAssignmentOperator) {
  ScalarStrainRate first{1.0, Unit::Frequency::Hertz};
  ScalarStrainRate second = ScalarStrainRate<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarStrainRate(1.0, Unit::Frequency::Hertz));
}

TEST(ScalarStrainRate, MoveConstructor) {
  ScalarStrainRate first{1.0, Unit::Frequency::Hertz};
  const ScalarStrainRate second{std::move(first)};
  EXPECT_EQ(second, ScalarStrainRate(1.0, Unit::Frequency::Hertz));
}

TEST(ScalarStrainRate, MutableValue) {
  ScalarStrainRate quantity{1.0, Unit::Frequency::Hertz};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarStrainRate, Print) {
  EXPECT_EQ(ScalarStrainRate(1.0, Unit::Frequency::Hertz).Print(), Print(1.0) + " Hz");
  EXPECT_EQ(ScalarStrainRate(1.0, Unit::Frequency::Kilohertz).Print(Unit::Frequency::Kilohertz),
            Print(1.0) + " kHz");
}

TEST(ScalarStrainRate, SetValue) {
  ScalarStrainRate quantity{1.0, Unit::Frequency::Hertz};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarStrainRate, SizeOf) {
  EXPECT_EQ(sizeof(ScalarStrainRate{}), sizeof(double));
}

TEST(ScalarStrainRate, StandardConstructor) {
  EXPECT_NO_THROW(ScalarStrainRate(1.0, Unit::Frequency::Kilohertz));
}

TEST(ScalarStrainRate, StaticValue) {
  constexpr ScalarStrainRate quantity = ScalarStrainRate<>::Create<Unit::Frequency::Kilohertz>(1.0);
  constexpr double value = quantity.StaticValue<Unit::Frequency::Kilohertz>();
  EXPECT_EQ(value, 1.0);
}

TEST(ScalarStrainRate, Stream) {
  std::ostringstream stream;
  stream << ScalarStrainRate(1.0, Unit::Frequency::Hertz);
  EXPECT_EQ(stream.str(), ScalarStrainRate(1.0, Unit::Frequency::Hertz).Print());
}

TEST(ScalarStrainRate, Unit) {
  EXPECT_EQ(ScalarStrainRate<>::Unit(), Standard<Unit::Frequency>);
}

TEST(ScalarStrainRate, Value) {
  EXPECT_EQ(ScalarStrainRate(1.0, Unit::Frequency::Hertz).Value(), 1.0);
  EXPECT_EQ(
      ScalarStrainRate(1.0, Unit::Frequency::Kilohertz).Value(Unit::Frequency::Kilohertz), 1.0);
}

TEST(ScalarStrainRate, XML) {
  EXPECT_EQ(ScalarStrainRate(1.0, Unit::Frequency::Hertz).XML(),
            "<value>" + Print(1.0) + "</value><unit>Hz</unit>");
  EXPECT_EQ(ScalarStrainRate(1.0, Unit::Frequency::Kilohertz).XML(Unit::Frequency::Kilohertz),
            "<value>" + Print(1.0) + "</value><unit>kHz</unit>");
}

TEST(ScalarStrainRate, YAML) {
  EXPECT_EQ(ScalarStrainRate(1.0, Unit::Frequency::Hertz).YAML(),
            "{value:" + Print(1.0) + ",unit:\"Hz\"}");
  EXPECT_EQ(ScalarStrainRate(1.0, Unit::Frequency::Kilohertz).YAML(Unit::Frequency::Kilohertz),
            "{value:" + Print(1.0) + ",unit:\"kHz\"}");
}

TEST(ScalarStrainRate, Zero) {
  EXPECT_EQ(ScalarStrainRate<>::Zero(), ScalarStrainRate(0.0, Unit::Frequency::Hertz));
}

}  // namespace

}  // namespace PhQ
