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

#include "../include/PhQ/StrainRateScalar.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/StrainScalar.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(StrainRateScalar, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      StrainRateScalar(1.0, Unit::Frequency::Hertz) + StrainRateScalar(2.0, Unit::Frequency::Hertz),
      StrainRateScalar(3.0, Unit::Frequency::Hertz));
}

TEST(StrainRateScalar, ArithmeticOperatorDivision) {
  EXPECT_EQ(StrainRateScalar(8.0, Unit::Frequency::Hertz) / 2.0,
            StrainRateScalar(4.0, Unit::Frequency::Hertz));

  EXPECT_EQ(
      StrainRateScalar(8.0, Unit::Frequency::Hertz) / StrainRateScalar(2.0, Unit::Frequency::Hertz),
      4.0);

  EXPECT_EQ(StrainScalar(8.0) / Time(4.0, Unit::Time::Second),
            StrainRateScalar(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(StrainRateScalar(8.0, Unit::Frequency::Hertz) / Frequency(4.0, Unit::Frequency::Hertz),
            StrainScalar(2.0));
}

TEST(StrainRateScalar, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(StrainRateScalar(4.0, Unit::Frequency::Hertz) * 2.0,
            StrainRateScalar(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(2.0 * StrainRateScalar(4.0, Unit::Frequency::Hertz),
            StrainRateScalar(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(StrainRateScalar(4.0, Unit::Frequency::Hertz) * Time(2.0, Unit::Time::Second),
            StrainScalar(8.0));

  EXPECT_EQ(Time(4.0, Unit::Time::Second) * StrainRateScalar(2.0, Unit::Frequency::Hertz),
            StrainScalar(8.0));

  EXPECT_EQ(StrainScalar(2.0) * Frequency(4.0, Unit::Frequency::Hertz),
            StrainRateScalar(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * StrainScalar(2.0),
            StrainRateScalar(8.0, Unit::Frequency::Hertz));
}

TEST(StrainRateScalar, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      StrainRateScalar(3.0, Unit::Frequency::Hertz) - StrainRateScalar(2.0, Unit::Frequency::Hertz),
      StrainRateScalar(1.0, Unit::Frequency::Hertz));
}

TEST(StrainRateScalar, AssignmentOperatorAddition) {
  StrainRateScalar quantity{1.0, Unit::Frequency::Hertz};
  quantity += StrainRateScalar(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, StrainRateScalar(3.0, Unit::Frequency::Hertz));
}

TEST(StrainRateScalar, AssignmentOperatorDivision) {
  StrainRateScalar quantity{8.0, Unit::Frequency::Hertz};
  quantity /= 2.0;
  EXPECT_EQ(quantity, StrainRateScalar(4.0, Unit::Frequency::Hertz));
}

TEST(StrainRateScalar, AssignmentOperatorMultiplication) {
  StrainRateScalar quantity{4.0, Unit::Frequency::Hertz};
  quantity *= 2.0;
  EXPECT_EQ(quantity, StrainRateScalar(8.0, Unit::Frequency::Hertz));
}

TEST(StrainRateScalar, AssignmentOperatorSubtraction) {
  StrainRateScalar quantity{3.0, Unit::Frequency::Hertz};
  quantity -= StrainRateScalar(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, StrainRateScalar(1.0, Unit::Frequency::Hertz));
}

TEST(StrainRateScalar, ComparisonOperators) {
  const StrainRateScalar first{1.11, Unit::Frequency::Hertz};
  const StrainRateScalar second{2.22, Unit::Frequency::Hertz};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(StrainRateScalar, CopyAssignmentOperator) {
  const StrainRateScalar first{1.11, Unit::Frequency::Hertz};
  StrainRateScalar second = StrainRateScalar::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(StrainRateScalar, CopyConstructor) {
  const StrainRateScalar first{1.11, Unit::Frequency::Hertz};
  const StrainRateScalar second{first};
  EXPECT_EQ(second, first);
}

TEST(StrainRateScalar, Create) {
  constexpr StrainRateScalar quantity = StrainRateScalar::Create<Unit::Frequency::Hertz>(1.11);
  EXPECT_EQ(quantity, StrainRateScalar(1.11, Unit::Frequency::Hertz));
}

TEST(StrainRateScalar, DefaultConstructor) {
  EXPECT_NO_THROW(StrainRateScalar{});
}

TEST(StrainRateScalar, Dimensions) {
  EXPECT_EQ(StrainRateScalar::Dimensions(), RelatedDimensions<Unit::Frequency>);
}

TEST(StrainRateScalar, Hash) {
  const StrainRateScalar first{1.11, Unit::Frequency::Kilohertz};
  const StrainRateScalar second{1.110001, Unit::Frequency::Kilohertz};
  const StrainRateScalar third{-1.11, Unit::Frequency::Kilohertz};
  const std::hash<StrainRateScalar> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(StrainRateScalar, JSON) {
  EXPECT_EQ(StrainRateScalar(1.11, Unit::Frequency::Hertz).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Hz\"}");
  EXPECT_EQ(StrainRateScalar(-2.22, Unit::Frequency::Kilohertz).JSON(Unit::Frequency::Kilohertz),
            "{\"value\":-2.220000000000000,\"unit\":\"kHz\"}");
}

TEST(StrainRateScalar, MiscellaneousConstructors) {
  EXPECT_EQ(StrainRateScalar(StrainScalar(8.0), Time(4.0, Unit::Time::Second)),
            StrainRateScalar(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(StrainRateScalar(StrainScalar(4.0), Frequency(2.0, Unit::Frequency::Hertz)),
            StrainRateScalar(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(
      StrainScalar(StrainRateScalar(4.0, Unit::Frequency::Hertz), Time(2.0, Unit::Time::Second)),
      StrainScalar(8.0));

  EXPECT_EQ(StrainScalar(StrainRateScalar(8.0, Unit::Frequency::Hertz),
                         Frequency(4.0, Unit::Frequency::Hertz)),
            StrainScalar(2.0));
}

TEST(StrainRateScalar, MoveAssignmentOperator) {
  StrainRateScalar first{1.11, Unit::Frequency::Hertz};
  StrainRateScalar second = StrainRateScalar::Zero();
  second = std::move(first);
  EXPECT_EQ(second, StrainRateScalar(1.11, Unit::Frequency::Hertz));
}

TEST(StrainRateScalar, MoveConstructor) {
  StrainRateScalar first{1.11, Unit::Frequency::Hertz};
  const StrainRateScalar second{std::move(first)};
  EXPECT_EQ(second, StrainRateScalar(1.11, Unit::Frequency::Hertz));
}

TEST(StrainRateScalar, MutableValue) {
  StrainRateScalar quantity{1.11, Unit::Frequency::Hertz};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(StrainRateScalar, Print) {
  EXPECT_EQ(StrainRateScalar(1.11, Unit::Frequency::Hertz).Print(), "1.110000000000000 Hz");
  EXPECT_EQ(StrainRateScalar(-2.22, Unit::Frequency::Kilohertz).Print(Unit::Frequency::Kilohertz),
            "-2.220000000000000 kHz");
}

TEST(StrainRateScalar, SetValue) {
  StrainRateScalar quantity{1.11, Unit::Frequency::Hertz};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(StrainRateScalar, SizeOf) {
  EXPECT_EQ(sizeof(StrainRateScalar{}), sizeof(double));
}

TEST(StrainRateScalar, StandardConstructor) {
  EXPECT_NO_THROW(StrainRateScalar(1.11, Unit::Frequency::Kilohertz));
}

TEST(StrainRateScalar, StaticValue) {
  constexpr StrainRateScalar quantity = StrainRateScalar::Create<Unit::Frequency::Kilohertz>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Frequency::Kilohertz>();
  EXPECT_EQ(value, 1.11);
}

TEST(StrainRateScalar, Stream) {
  std::ostringstream stream;
  stream << StrainRateScalar(1.11, Unit::Frequency::Hertz);
  EXPECT_EQ(stream.str(), StrainRateScalar(1.11, Unit::Frequency::Hertz).Print());
}

TEST(StrainRateScalar, Unit) {
  EXPECT_EQ(StrainRateScalar::Unit(), Standard<Unit::Frequency>);
}

TEST(StrainRateScalar, Value) {
  EXPECT_EQ(StrainRateScalar(1.11, Unit::Frequency::Hertz).Value(), 1.11);
  EXPECT_EQ(
      StrainRateScalar(1.11, Unit::Frequency::Kilohertz).Value(Unit::Frequency::Kilohertz), 1.11);
}

TEST(StrainRateScalar, XML) {
  EXPECT_EQ(StrainRateScalar(1.11, Unit::Frequency::Hertz).XML(),
            "<value>1.110000000000000</value><unit>Hz</unit>");
  EXPECT_EQ(StrainRateScalar(-2.22, Unit::Frequency::Kilohertz).XML(Unit::Frequency::Kilohertz),
            "<value>-2.220000000000000</value><unit>kHz</unit>");
}

TEST(StrainRateScalar, YAML) {
  EXPECT_EQ(StrainRateScalar(1.11, Unit::Frequency::Hertz).YAML(),
            "{value:1.110000000000000,unit:\"Hz\"}");
  EXPECT_EQ(StrainRateScalar(-2.22, Unit::Frequency::Kilohertz).YAML(Unit::Frequency::Kilohertz),
            "{value:-2.220000000000000,unit:\"kHz\"}");
}

TEST(StrainRateScalar, Zero) {
  EXPECT_EQ(StrainRateScalar::Zero(), StrainRateScalar(0.0, Unit::Frequency::Hertz));
}

}  // namespace

}  // namespace PhQ
