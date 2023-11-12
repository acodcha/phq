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

#include "../include/PhQ/VelocityGradientScalar.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/DisplacementGradientScalar.hpp"
#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(VelocityGradientScalar, ArithmeticOperatorAddition) {
  EXPECT_EQ(VelocityGradientScalar(1.0, Unit::Frequency::Hertz)
                + VelocityGradientScalar(2.0, Unit::Frequency::Hertz),
            VelocityGradientScalar(3.0, Unit::Frequency::Hertz));
}

TEST(VelocityGradientScalar, ArithmeticOperatorDivision) {
  EXPECT_EQ(VelocityGradientScalar(8.0, Unit::Frequency::Hertz) / 2.0,
            VelocityGradientScalar(4.0, Unit::Frequency::Hertz));

  EXPECT_EQ(VelocityGradientScalar(8.0, Unit::Frequency::Hertz)
                / VelocityGradientScalar(2.0, Unit::Frequency::Hertz),
            4.0);

  EXPECT_EQ(DisplacementGradientScalar(8.0) / Time(4.0, Unit::Time::Second),
            VelocityGradientScalar(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(
      VelocityGradientScalar(8.0, Unit::Frequency::Hertz) / Frequency(4.0, Unit::Frequency::Hertz),
      DisplacementGradientScalar(2.0));
}

TEST(VelocityGradientScalar, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(VelocityGradientScalar(4.0, Unit::Frequency::Hertz) * 2.0,
            VelocityGradientScalar(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(2.0 * VelocityGradientScalar(4.0, Unit::Frequency::Hertz),
            VelocityGradientScalar(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(VelocityGradientScalar(4.0, Unit::Frequency::Hertz) * Time(2.0, Unit::Time::Second),
            DisplacementGradientScalar(8.0));

  EXPECT_EQ(Time(4.0, Unit::Time::Second) * VelocityGradientScalar(2.0, Unit::Frequency::Hertz),
            DisplacementGradientScalar(8.0));

  EXPECT_EQ(DisplacementGradientScalar(4.0) * Frequency(2.0, Unit::Frequency::Hertz),
            VelocityGradientScalar(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * DisplacementGradientScalar(2.0),
            VelocityGradientScalar(8.0, Unit::Frequency::Hertz));
}

TEST(VelocityGradientScalar, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(VelocityGradientScalar(3.0, Unit::Frequency::Hertz)
                - VelocityGradientScalar(2.0, Unit::Frequency::Hertz),
            VelocityGradientScalar(1.0, Unit::Frequency::Hertz));
}

TEST(VelocityGradientScalar, AssignmentOperatorAddition) {
  VelocityGradientScalar quantity{1.0, Unit::Frequency::Hertz};
  quantity += VelocityGradientScalar(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, VelocityGradientScalar(3.0, Unit::Frequency::Hertz));
}

TEST(VelocityGradientScalar, AssignmentOperatorDivision) {
  VelocityGradientScalar quantity{8.0, Unit::Frequency::Hertz};
  quantity /= 2.0;
  EXPECT_EQ(quantity, VelocityGradientScalar(4.0, Unit::Frequency::Hertz));
}

TEST(VelocityGradientScalar, AssignmentOperatorMultiplication) {
  VelocityGradientScalar quantity{4.0, Unit::Frequency::Hertz};
  quantity *= 2.0;
  EXPECT_EQ(quantity, VelocityGradientScalar(8.0, Unit::Frequency::Hertz));
}

TEST(VelocityGradientScalar, AssignmentOperatorSubtraction) {
  VelocityGradientScalar quantity{3.0, Unit::Frequency::Hertz};
  quantity -= VelocityGradientScalar(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, VelocityGradientScalar(1.0, Unit::Frequency::Hertz));
}

TEST(VelocityGradientScalar, ComparisonOperators) {
  const VelocityGradientScalar first{1.11, Unit::Frequency::Hertz};
  const VelocityGradientScalar second{2.22, Unit::Frequency::Hertz};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(VelocityGradientScalar, CopyAssignmentOperator) {
  const VelocityGradientScalar first{1.11, Unit::Frequency::Hertz};
  VelocityGradientScalar second = VelocityGradientScalar::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(VelocityGradientScalar, CopyConstructor) {
  const VelocityGradientScalar first{1.11, Unit::Frequency::Hertz};
  const VelocityGradientScalar second{first};
  EXPECT_EQ(second, first);
}

TEST(VelocityGradientScalar, Create) {
  constexpr VelocityGradientScalar quantity =
      VelocityGradientScalar::Create<Unit::Frequency::Hertz>(1.11);
  EXPECT_EQ(quantity, VelocityGradientScalar(1.11, Unit::Frequency::Hertz));
}

TEST(VelocityGradientScalar, DefaultConstructor) {
  EXPECT_NO_THROW(VelocityGradientScalar{});
}

TEST(VelocityGradientScalar, Dimensions) {
  EXPECT_EQ(VelocityGradientScalar::Dimensions(), RelatedDimensions<Unit::Frequency>);
}

TEST(VelocityGradientScalar, Hash) {
  const VelocityGradientScalar first{1.11, Unit::Frequency::Kilohertz};
  const VelocityGradientScalar second{1.110001, Unit::Frequency::Kilohertz};
  const VelocityGradientScalar third{-1.11, Unit::Frequency::Kilohertz};
  const std::hash<VelocityGradientScalar> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(VelocityGradientScalar, JSON) {
  EXPECT_EQ(VelocityGradientScalar(1.11, Unit::Frequency::Hertz).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Hz\"}");
  EXPECT_EQ(
      VelocityGradientScalar(-2.22, Unit::Frequency::Kilohertz).JSON(Unit::Frequency::Kilohertz),
      "{\"value\":-2.220000000000000,\"unit\":\"kHz\"}");
}

TEST(VelocityGradientScalar, MiscellaneousConstructors) {
  EXPECT_EQ(VelocityGradientScalar(DisplacementGradientScalar(8.0), Time(4.0, Unit::Time::Second)),
            VelocityGradientScalar(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(VelocityGradientScalar(
                DisplacementGradientScalar(4.0), Frequency(2.0, Unit::Frequency::Hertz)),
            VelocityGradientScalar(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(DisplacementGradientScalar(
                VelocityGradientScalar(4.0, Unit::Frequency::Hertz), Time(2.0, Unit::Time::Second)),
            DisplacementGradientScalar(8.0));

  EXPECT_EQ(DisplacementGradientScalar(VelocityGradientScalar(8.0, Unit::Frequency::Hertz),
                                       Frequency(4.0, Unit::Frequency::Hertz)),
            DisplacementGradientScalar(2.0));
}

TEST(VelocityGradientScalar, MoveAssignmentOperator) {
  VelocityGradientScalar first{1.11, Unit::Frequency::Hertz};
  VelocityGradientScalar second = VelocityGradientScalar::Zero();
  second = std::move(first);
  EXPECT_EQ(second, VelocityGradientScalar(1.11, Unit::Frequency::Hertz));
}

TEST(VelocityGradientScalar, MoveConstructor) {
  VelocityGradientScalar first{1.11, Unit::Frequency::Hertz};
  const VelocityGradientScalar second{std::move(first)};
  EXPECT_EQ(second, VelocityGradientScalar(1.11, Unit::Frequency::Hertz));
}

TEST(VelocityGradientScalar, MutableValue) {
  VelocityGradientScalar quantity{1.11, Unit::Frequency::Hertz};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(VelocityGradientScalar, Print) {
  EXPECT_EQ(VelocityGradientScalar(1.11, Unit::Frequency::Hertz).Print(), "1.110000000000000 Hz");
  EXPECT_EQ(
      VelocityGradientScalar(-2.22, Unit::Frequency::Kilohertz).Print(Unit::Frequency::Kilohertz),
      "-2.220000000000000 kHz");
}

TEST(VelocityGradientScalar, SetValue) {
  VelocityGradientScalar quantity{1.11, Unit::Frequency::Hertz};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(VelocityGradientScalar, SizeOf) {
  EXPECT_EQ(sizeof(VelocityGradientScalar{}), sizeof(double));
}

TEST(VelocityGradientScalar, StandardConstructor) {
  EXPECT_NO_THROW(VelocityGradientScalar(1.11, Unit::Frequency::Kilohertz));
}

TEST(VelocityGradientScalar, StaticValue) {
  constexpr VelocityGradientScalar quantity =
      VelocityGradientScalar::Create<Unit::Frequency::Kilohertz>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Frequency::Kilohertz>();
  EXPECT_EQ(value, 1.11);
}

TEST(VelocityGradientScalar, Stream) {
  std::ostringstream stream;
  stream << VelocityGradientScalar(1.11, Unit::Frequency::Hertz);
  EXPECT_EQ(stream.str(), VelocityGradientScalar(1.11, Unit::Frequency::Hertz).Print());
}

TEST(VelocityGradientScalar, Unit) {
  EXPECT_EQ(VelocityGradientScalar::Unit(), Standard<Unit::Frequency>);
}

TEST(VelocityGradientScalar, Value) {
  EXPECT_EQ(VelocityGradientScalar(1.11, Unit::Frequency::Hertz).Value(), 1.11);
  EXPECT_EQ(
      VelocityGradientScalar(1.11, Unit::Frequency::Kilohertz).Value(Unit::Frequency::Kilohertz),
      1.11);
}

TEST(VelocityGradientScalar, XML) {
  EXPECT_EQ(VelocityGradientScalar(1.11, Unit::Frequency::Hertz).XML(),
            "<value>1.110000000000000</value><unit>Hz</unit>");
  EXPECT_EQ(
      VelocityGradientScalar(-2.22, Unit::Frequency::Kilohertz).XML(Unit::Frequency::Kilohertz),
      "<value>-2.220000000000000</value><unit>kHz</unit>");
}

TEST(VelocityGradientScalar, YAML) {
  EXPECT_EQ(VelocityGradientScalar(1.11, Unit::Frequency::Hertz).YAML(),
            "{value:1.110000000000000,unit:\"Hz\"}");
  EXPECT_EQ(
      VelocityGradientScalar(-2.22, Unit::Frequency::Kilohertz).YAML(Unit::Frequency::Kilohertz),
      "{value:-2.220000000000000,unit:\"kHz\"}");
}

TEST(VelocityGradientScalar, Zero) {
  EXPECT_EQ(VelocityGradientScalar::Zero(), VelocityGradientScalar(0.0, Unit::Frequency::Hertz));
}

}  // namespace

}  // namespace PhQ
