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

#include "../include/PhQ/TemperatureGradientScalar.hpp"

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

TEST(TemperatureGradientScalar, ArithmeticOperatorAddition) {
  EXPECT_EQ(TemperatureGradientScalar(1.0, Unit::TemperatureGradient::KelvinPerMetre)
                + TemperatureGradientScalar(2.0, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradientScalar(3.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientScalar, ArithmeticOperatorDivision) {
  EXPECT_EQ(TemperatureGradientScalar(8.0, Unit::TemperatureGradient::KelvinPerMetre) / 2.0,
            TemperatureGradientScalar(4.0, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(TemperatureGradientScalar(8.0, Unit::TemperatureGradient::KelvinPerMetre)
                / TemperatureGradientScalar(2.0, Unit::TemperatureGradient::KelvinPerMetre),
            4.0);

  EXPECT_EQ(TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin)
                / Length(4.0, Unit::Length::Metre),
            TemperatureGradientScalar(2.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientScalar, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(TemperatureGradientScalar(4.0, Unit::TemperatureGradient::KelvinPerMetre) * 2.0,
            TemperatureGradientScalar(8.0, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(2.0 * TemperatureGradientScalar(4.0, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradientScalar(8.0, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(TemperatureGradientScalar(4.0, Unit::TemperatureGradient::KelvinPerMetre)
                * Length(2.0, Unit::Length::Metre),
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureGradientScalar, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(TemperatureGradientScalar(3.0, Unit::TemperatureGradient::KelvinPerMetre)
                - TemperatureGradientScalar(2.0, Unit::TemperatureGradient::KelvinPerMetre),
            TemperatureGradientScalar(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientScalar, AssignmentOperatorAddition) {
  TemperatureGradientScalar quantity{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity += TemperatureGradientScalar(2.0, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(quantity, TemperatureGradientScalar(3.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientScalar, AssignmentOperatorDivision) {
  TemperatureGradientScalar quantity{8.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity /= 2.0;
  EXPECT_EQ(quantity, TemperatureGradientScalar(4.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientScalar, AssignmentOperatorMultiplication) {
  TemperatureGradientScalar quantity{4.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity *= 2.0;
  EXPECT_EQ(quantity, TemperatureGradientScalar(8.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientScalar, AssignmentOperatorSubtraction) {
  TemperatureGradientScalar quantity{3.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity -= TemperatureGradientScalar(2.0, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(quantity, TemperatureGradientScalar(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientScalar, ComparisonOperators) {
  const TemperatureGradientScalar first{0.1, Unit::TemperatureGradient::KelvinPerMetre};
  const TemperatureGradientScalar second{0.2, Unit::TemperatureGradient::KelvinPerMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(TemperatureGradientScalar, CopyAssignmentOperator) {
  const TemperatureGradientScalar first{1.11, Unit::TemperatureGradient::KelvinPerMetre};
  TemperatureGradientScalar second = TemperatureGradientScalar::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(TemperatureGradientScalar, CopyConstructor) {
  const TemperatureGradientScalar first{1.11, Unit::TemperatureGradient::KelvinPerMetre};
  const TemperatureGradientScalar second{first};
  EXPECT_EQ(second, first);
}

TEST(TemperatureGradientScalar, Create) {
  constexpr TemperatureGradientScalar quantity =
      TemperatureGradientScalar::Create<Unit::TemperatureGradient::KelvinPerMetre>(1.11);
  EXPECT_EQ(quantity, TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientScalar, DefaultConstructor) {
  EXPECT_NO_THROW(TemperatureGradientScalar{});
}

TEST(TemperatureGradientScalar, Dimensions) {
  EXPECT_EQ(TemperatureGradientScalar::Dimensions(), RelatedDimensions<Unit::TemperatureGradient>);
}

TEST(TemperatureGradientScalar, Hash) {
  const TemperatureGradientScalar first{1.11, Unit::TemperatureGradient::KelvinPerMetre};
  const TemperatureGradientScalar second{1.110001, Unit::TemperatureGradient::KelvinPerMetre};
  const TemperatureGradientScalar third{-1.11, Unit::TemperatureGradient::KelvinPerMetre};
  const std::hash<TemperatureGradientScalar> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(TemperatureGradientScalar, JSON) {
  EXPECT_EQ(TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMetre).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"K/m\"}");
  EXPECT_EQ(TemperatureGradientScalar(-2.22, Unit::TemperatureGradient::KelvinPerMillimetre)
                .JSON(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{\"value\":-2.220000000000000,\"unit\":\"K/mm\"}");
}

TEST(TemperatureGradientScalar, MiscellaneousConstructors) {
  EXPECT_EQ(
      TemperatureGradientScalar(TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin),
                                Length(4.0, Unit::Length::Metre)),
      TemperatureGradientScalar(2.0, Unit::TemperatureGradient::KelvinPerMetre));

  EXPECT_EQ(TemperatureDifference(
                TemperatureGradientScalar(4.0, Unit::TemperatureGradient::KelvinPerMetre),
                Length(2.0, Unit::Length::Metre)),
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureGradientScalar, MoveAssignmentOperator) {
  TemperatureGradientScalar first{1.11, Unit::TemperatureGradient::KelvinPerMetre};
  TemperatureGradientScalar second = TemperatureGradientScalar::Zero();
  second = std::move(first);
  EXPECT_EQ(second, TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientScalar, MoveConstructor) {
  TemperatureGradientScalar first{1.11, Unit::TemperatureGradient::KelvinPerMetre};
  const TemperatureGradientScalar second{std::move(first)};
  EXPECT_EQ(second, TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(TemperatureGradientScalar, MutableValue) {
  TemperatureGradientScalar quantity{1.11, Unit::TemperatureGradient::KelvinPerMetre};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(TemperatureGradientScalar, Print) {
  EXPECT_EQ(TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMetre).Print(),
            "1.110000000000000 K/m");
  EXPECT_EQ(TemperatureGradientScalar(-2.22, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Print(Unit::TemperatureGradient::KelvinPerMillimetre),
            "-2.220000000000000 K/mm");
}

TEST(TemperatureGradientScalar, SetValue) {
  TemperatureGradientScalar quantity{1.11, Unit::TemperatureGradient::KelvinPerMetre};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(TemperatureGradientScalar, SizeOf) {
  EXPECT_EQ(sizeof(TemperatureGradientScalar{}), sizeof(double));
}

TEST(TemperatureGradientScalar, StandardConstructor) {
  EXPECT_NO_THROW(TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMillimetre));
}

TEST(TemperatureGradientScalar, StaticValue) {
  constexpr TemperatureGradientScalar quantity =
      TemperatureGradientScalar::Create<Unit::TemperatureGradient::KelvinPerMillimetre>(1.11);
  constexpr double value = quantity.StaticValue<Unit::TemperatureGradient::KelvinPerMillimetre>();
  EXPECT_EQ(value, 1.11);
}

TEST(TemperatureGradientScalar, Stream) {
  std::ostringstream stream;
  stream << TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(stream.str(),
            TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMetre).Print());
}

TEST(TemperatureGradientScalar, Unit) {
  EXPECT_EQ(TemperatureGradientScalar::Unit(), Standard<Unit::TemperatureGradient>);
}

TEST(TemperatureGradientScalar, Value) {
  EXPECT_EQ(
      TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMetre).Value(), 1.11);
  EXPECT_EQ(TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Value(Unit::TemperatureGradient::KelvinPerMillimetre),
            1.11);
}

TEST(TemperatureGradientScalar, XML) {
  EXPECT_EQ(TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMetre).XML(),
            "<value>1.110000000000000</value><unit>K/m</unit>");
  EXPECT_EQ(TemperatureGradientScalar(-2.22, Unit::TemperatureGradient::KelvinPerMillimetre)
                .XML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "<value>-2.220000000000000</value><unit>K/mm</unit>");
}

TEST(TemperatureGradientScalar, YAML) {
  EXPECT_EQ(TemperatureGradientScalar(1.11, Unit::TemperatureGradient::KelvinPerMetre).YAML(),
            "{value:1.110000000000000,unit:\"K/m\"}");
  EXPECT_EQ(TemperatureGradientScalar(-2.22, Unit::TemperatureGradient::KelvinPerMillimetre)
                .YAML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{value:-2.220000000000000,unit:\"K/mm\"}");
}

TEST(TemperatureGradientScalar, Zero) {
  EXPECT_EQ(TemperatureGradientScalar::Zero(),
            TemperatureGradientScalar(0.0, Unit::TemperatureGradient::KelvinPerMetre));
}

}  // namespace

}  // namespace PhQ
