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

#include "../include/PhQ/ScalarVelocityGradient.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/ScalarDisplacementGradient.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(ScalarVelocityGradient, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarVelocityGradient(1.0, Unit::Frequency::Hertz)
                + ScalarVelocityGradient(2.0, Unit::Frequency::Hertz),
            ScalarVelocityGradient(3.0, Unit::Frequency::Hertz));
}

TEST(ScalarVelocityGradient, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarVelocityGradient(8.0, Unit::Frequency::Hertz) / 2.0,
            ScalarVelocityGradient(4.0, Unit::Frequency::Hertz));

  EXPECT_EQ(ScalarVelocityGradient(8.0, Unit::Frequency::Hertz)
                / ScalarVelocityGradient(2.0, Unit::Frequency::Hertz),
            4.0);

  EXPECT_EQ(ScalarDisplacementGradient(8.0) / Time(4.0, Unit::Time::Second),
            ScalarVelocityGradient(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(
      ScalarVelocityGradient(8.0, Unit::Frequency::Hertz) / Frequency(4.0, Unit::Frequency::Hertz),
      ScalarDisplacementGradient(2.0));
}

TEST(ScalarVelocityGradient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarVelocityGradient(4.0, Unit::Frequency::Hertz) * 2.0,
            ScalarVelocityGradient(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(2.0 * ScalarVelocityGradient(4.0, Unit::Frequency::Hertz),
            ScalarVelocityGradient(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(ScalarVelocityGradient(4.0, Unit::Frequency::Hertz) * Time(2.0, Unit::Time::Second),
            ScalarDisplacementGradient(8.0));

  EXPECT_EQ(Time(4.0, Unit::Time::Second) * ScalarVelocityGradient(2.0, Unit::Frequency::Hertz),
            ScalarDisplacementGradient(8.0));

  EXPECT_EQ(ScalarDisplacementGradient(4.0) * Frequency(2.0, Unit::Frequency::Hertz),
            ScalarVelocityGradient(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * ScalarDisplacementGradient(2.0),
            ScalarVelocityGradient(8.0, Unit::Frequency::Hertz));
}

TEST(ScalarVelocityGradient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarVelocityGradient(3.0, Unit::Frequency::Hertz)
                - ScalarVelocityGradient(2.0, Unit::Frequency::Hertz),
            ScalarVelocityGradient(1.0, Unit::Frequency::Hertz));
}

TEST(ScalarVelocityGradient, AssignmentOperatorAddition) {
  ScalarVelocityGradient quantity{1.0, Unit::Frequency::Hertz};
  quantity += ScalarVelocityGradient(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, ScalarVelocityGradient(3.0, Unit::Frequency::Hertz));
}

TEST(ScalarVelocityGradient, AssignmentOperatorDivision) {
  ScalarVelocityGradient quantity{8.0, Unit::Frequency::Hertz};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ScalarVelocityGradient(4.0, Unit::Frequency::Hertz));
}

TEST(ScalarVelocityGradient, AssignmentOperatorMultiplication) {
  ScalarVelocityGradient quantity{4.0, Unit::Frequency::Hertz};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ScalarVelocityGradient(8.0, Unit::Frequency::Hertz));
}

TEST(ScalarVelocityGradient, AssignmentOperatorSubtraction) {
  ScalarVelocityGradient quantity{3.0, Unit::Frequency::Hertz};
  quantity -= ScalarVelocityGradient(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, ScalarVelocityGradient(1.0, Unit::Frequency::Hertz));
}

TEST(ScalarVelocityGradient, ComparisonOperators) {
  const ScalarVelocityGradient first{1.11, Unit::Frequency::Hertz};
  const ScalarVelocityGradient second{2.22, Unit::Frequency::Hertz};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarVelocityGradient, CopyAssignmentOperator) {
  const ScalarVelocityGradient first{1.11, Unit::Frequency::Hertz};
  ScalarVelocityGradient second = ScalarVelocityGradient::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ScalarVelocityGradient, CopyConstructor) {
  const ScalarVelocityGradient first{1.11, Unit::Frequency::Hertz};
  const ScalarVelocityGradient second{first};
  EXPECT_EQ(second, first);
}

TEST(ScalarVelocityGradient, Create) {
  constexpr ScalarVelocityGradient quantity =
      ScalarVelocityGradient::Create<Unit::Frequency::Hertz>(1.11);
  EXPECT_EQ(quantity, ScalarVelocityGradient(1.11, Unit::Frequency::Hertz));
}

TEST(ScalarVelocityGradient, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarVelocityGradient{});
}

TEST(ScalarVelocityGradient, Dimensions) {
  EXPECT_EQ(ScalarVelocityGradient::Dimensions(), RelatedDimensions<Unit::Frequency>);
}

TEST(ScalarVelocityGradient, Hash) {
  const ScalarVelocityGradient first{1.11, Unit::Frequency::Kilohertz};
  const ScalarVelocityGradient second{1.110001, Unit::Frequency::Kilohertz};
  const ScalarVelocityGradient third{-1.11, Unit::Frequency::Kilohertz};
  const std::hash<ScalarVelocityGradient> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(ScalarVelocityGradient, JSON) {
  EXPECT_EQ(ScalarVelocityGradient(1.11, Unit::Frequency::Hertz).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Hz\"}");
  EXPECT_EQ(
      ScalarVelocityGradient(-2.22, Unit::Frequency::Kilohertz).JSON(Unit::Frequency::Kilohertz),
      "{\"value\":-2.220000000000000,\"unit\":\"kHz\"}");
}

TEST(ScalarVelocityGradient, MiscellaneousConstructors) {
  EXPECT_EQ(ScalarVelocityGradient(ScalarDisplacementGradient(8.0), Time(4.0, Unit::Time::Second)),
            ScalarVelocityGradient(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(ScalarVelocityGradient(
                ScalarDisplacementGradient(4.0), Frequency(2.0, Unit::Frequency::Hertz)),
            ScalarVelocityGradient(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(ScalarDisplacementGradient(
                ScalarVelocityGradient(4.0, Unit::Frequency::Hertz), Time(2.0, Unit::Time::Second)),
            ScalarDisplacementGradient(8.0));

  EXPECT_EQ(ScalarDisplacementGradient(ScalarVelocityGradient(8.0, Unit::Frequency::Hertz),
                                       Frequency(4.0, Unit::Frequency::Hertz)),
            ScalarDisplacementGradient(2.0));
}

TEST(ScalarVelocityGradient, MoveAssignmentOperator) {
  ScalarVelocityGradient first{1.11, Unit::Frequency::Hertz};
  ScalarVelocityGradient second = ScalarVelocityGradient::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarVelocityGradient(1.11, Unit::Frequency::Hertz));
}

TEST(ScalarVelocityGradient, MoveConstructor) {
  ScalarVelocityGradient first{1.11, Unit::Frequency::Hertz};
  const ScalarVelocityGradient second{std::move(first)};
  EXPECT_EQ(second, ScalarVelocityGradient(1.11, Unit::Frequency::Hertz));
}

TEST(ScalarVelocityGradient, MutableValue) {
  ScalarVelocityGradient quantity{1.11, Unit::Frequency::Hertz};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ScalarVelocityGradient, Print) {
  EXPECT_EQ(ScalarVelocityGradient(1.11, Unit::Frequency::Hertz).Print(), "1.110000000000000 Hz");
  EXPECT_EQ(
      ScalarVelocityGradient(-2.22, Unit::Frequency::Kilohertz).Print(Unit::Frequency::Kilohertz),
      "-2.220000000000000 kHz");
}

TEST(ScalarVelocityGradient, SetValue) {
  ScalarVelocityGradient quantity{1.11, Unit::Frequency::Hertz};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ScalarVelocityGradient, SizeOf) {
  EXPECT_EQ(sizeof(ScalarVelocityGradient{}), sizeof(double));
}

TEST(ScalarVelocityGradient, StandardConstructor) {
  EXPECT_NO_THROW(ScalarVelocityGradient(1.11, Unit::Frequency::Kilohertz));
}

TEST(ScalarVelocityGradient, StaticValue) {
  constexpr ScalarVelocityGradient quantity =
      ScalarVelocityGradient::Create<Unit::Frequency::Kilohertz>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Frequency::Kilohertz>();
  EXPECT_EQ(value, 1.11);
}

TEST(ScalarVelocityGradient, Stream) {
  std::ostringstream stream;
  stream << ScalarVelocityGradient(1.11, Unit::Frequency::Hertz);
  EXPECT_EQ(stream.str(), ScalarVelocityGradient(1.11, Unit::Frequency::Hertz).Print());
}

TEST(ScalarVelocityGradient, Unit) {
  EXPECT_EQ(ScalarVelocityGradient::Unit(), Standard<Unit::Frequency>);
}

TEST(ScalarVelocityGradient, Value) {
  EXPECT_EQ(ScalarVelocityGradient(1.11, Unit::Frequency::Hertz).Value(), 1.11);
  EXPECT_EQ(
      ScalarVelocityGradient(1.11, Unit::Frequency::Kilohertz).Value(Unit::Frequency::Kilohertz),
      1.11);
}

TEST(ScalarVelocityGradient, XML) {
  EXPECT_EQ(ScalarVelocityGradient(1.11, Unit::Frequency::Hertz).XML(),
            "<value>1.110000000000000</value><unit>Hz</unit>");
  EXPECT_EQ(
      ScalarVelocityGradient(-2.22, Unit::Frequency::Kilohertz).XML(Unit::Frequency::Kilohertz),
      "<value>-2.220000000000000</value><unit>kHz</unit>");
}

TEST(ScalarVelocityGradient, YAML) {
  EXPECT_EQ(ScalarVelocityGradient(1.11, Unit::Frequency::Hertz).YAML(),
            "{value:1.110000000000000,unit:\"Hz\"}");
  EXPECT_EQ(
      ScalarVelocityGradient(-2.22, Unit::Frequency::Kilohertz).YAML(Unit::Frequency::Kilohertz),
      "{value:-2.220000000000000,unit:\"kHz\"}");
}

TEST(ScalarVelocityGradient, Zero) {
  EXPECT_EQ(ScalarVelocityGradient::Zero(), ScalarVelocityGradient(0.0, Unit::Frequency::Hertz));
}

}  // namespace

}  // namespace PhQ
