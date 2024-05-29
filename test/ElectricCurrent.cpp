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

#include "../include/PhQ/ElectricCurrent.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/ElectricCharge.hpp"
#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/ElectricCurrent.hpp"

namespace PhQ {

namespace {

TEST(ElectricCurrent, ArithmeticOperatorAddition) {
  EXPECT_EQ(ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere)
                + ElectricCurrent(2.0, Unit::ElectricCurrent::Ampere),
            ElectricCurrent(3.0, Unit::ElectricCurrent::Ampere));
}

TEST(ElectricCurrent, ArithmeticOperatorDivision) {
  EXPECT_EQ(ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere) / 2.0,
            ElectricCurrent(4.0, Unit::ElectricCurrent::Ampere));
  EXPECT_EQ(ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere)
                / ElectricCurrent(2.0, Unit::ElectricCurrent::Ampere),
            4.0);
  EXPECT_EQ(
      ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere) / Frequency(4.0, Unit::Frequency::Hertz),
      ElectricCharge(2.0, Unit::ElectricCharge::Coulomb));
  EXPECT_EQ(ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere)
                / ElectricCharge(4.0, Unit::ElectricCharge::Coulomb),
            Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(ElectricCharge(8.0, Unit::ElectricCharge::Coulomb) / Time(4.0, Unit::Time::Second),
            ElectricCurrent(2.0, Unit::ElectricCurrent::Ampere));
  EXPECT_EQ(ElectricCharge(8.0, Unit::ElectricCharge::Coulomb)
                / ElectricCurrent(4.0, Unit::ElectricCurrent::Ampere),
            Time(2.0, Unit::Time::Second));
}

TEST(ElectricCurrent, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ElectricCurrent(4.0, Unit::ElectricCurrent::Ampere) * 2.0,
            ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere));
  EXPECT_EQ(2.0 * ElectricCurrent(4.0, Unit::ElectricCurrent::Ampere),
            ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere));
  EXPECT_EQ(ElectricCurrent(4.0, Unit::ElectricCurrent::Ampere) * Time(2.0, Unit::Time::Second),
            ElectricCharge(8.0, Unit::ElectricCharge::Coulomb));
  EXPECT_EQ(Time(4.0, Unit::Time::Second) * ElectricCurrent(2.0, Unit::ElectricCurrent::Ampere),
            ElectricCharge(8.0, Unit::ElectricCharge::Coulomb));
  EXPECT_EQ(
      Frequency(4.0, Unit::Frequency::Hertz) * ElectricCharge(2.0, Unit::ElectricCharge::Coulomb),
      ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere));
  EXPECT_EQ(
      ElectricCharge(4.0, Unit::ElectricCharge::Coulomb) * Frequency(2.0, Unit::Frequency::Hertz),
      ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere));
}

TEST(ElectricCurrent, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ElectricCurrent(3.0, Unit::ElectricCurrent::Ampere)
                - ElectricCurrent(2.0, Unit::ElectricCurrent::Ampere),
            ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere));
}

TEST(ElectricCurrent, AssignmentOperatorAddition) {
  ElectricCurrent electric_current{1.0, Unit::ElectricCurrent::Ampere};
  electric_current += ElectricCurrent(2.0, Unit::ElectricCurrent::Ampere);
  EXPECT_EQ(electric_current, ElectricCurrent(3.0, Unit::ElectricCurrent::Ampere));
}

TEST(ElectricCurrent, AssignmentOperatorDivision) {
  ElectricCurrent electric_current{8.0, Unit::ElectricCurrent::Ampere};
  electric_current /= 2.0;
  EXPECT_EQ(electric_current, ElectricCurrent(4.0, Unit::ElectricCurrent::Ampere));
}

TEST(ElectricCurrent, AssignmentOperatorMultiplication) {
  ElectricCurrent electric_current{4.0, Unit::ElectricCurrent::Ampere};
  electric_current *= 2.0;
  EXPECT_EQ(electric_current, ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere));
}

TEST(ElectricCurrent, AssignmentOperatorSubtraction) {
  ElectricCurrent electric_current{3.0, Unit::ElectricCurrent::Ampere};
  electric_current -= ElectricCurrent(2.0, Unit::ElectricCurrent::Ampere);
  EXPECT_EQ(electric_current, ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere));
}

TEST(ElectricCurrent, ComparisonOperators) {
  const ElectricCurrent first{1.0, Unit::ElectricCurrent::Ampere};
  const ElectricCurrent second{2.0, Unit::ElectricCurrent::Ampere};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ElectricCurrent, Constructor) {
  EXPECT_NO_THROW(ElectricCurrent(1.0, Unit::ElectricCurrent::Kiloampere));
  EXPECT_EQ(ElectricCurrent(
                ElectricCharge(8.0, Unit::ElectricCharge::Coulomb), Time(4.0, Unit::Time::Second)),
            ElectricCurrent(2.0, Unit::ElectricCurrent::Ampere));
  EXPECT_EQ(ElectricCurrent(ElectricCharge(4.0, Unit::ElectricCharge::Coulomb),
                            Frequency(2.0, Unit::Frequency::Hertz)),
            ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere));
  EXPECT_EQ(Time(ElectricCharge(8.0, Unit::ElectricCharge::Coulomb),
                 ElectricCurrent(4.0, Unit::ElectricCurrent::Ampere)),
            Time(2.0, Unit::Time::Second));
  EXPECT_EQ(Frequency(ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere),
                      ElectricCharge(4.0, Unit::ElectricCharge::Coulomb)),
            Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(ElectricCharge(
                ElectricCurrent(4.0, Unit::ElectricCurrent::Ampere), Time(2.0, Unit::Time::Second)),
            ElectricCharge(8.0, Unit::ElectricCharge::Coulomb));
  EXPECT_EQ(ElectricCharge(ElectricCurrent(8.0, Unit::ElectricCurrent::Ampere),
                           Frequency(4.0, Unit::Frequency::Hertz)),
            ElectricCharge(2.0, Unit::ElectricCharge::Coulomb));
}

TEST(ElectricCurrent, CopyAssignmentOperator) {
  {
    const ElectricCurrent<float> first(1.0F, Unit::ElectricCurrent::Ampere);
    ElectricCurrent<double> second = ElectricCurrent<double>::Zero();
    second = first;
    EXPECT_EQ(second, ElectricCurrent<double>(1.0, Unit::ElectricCurrent::Ampere));
  }
  {
    const ElectricCurrent<double> first(1.0, Unit::ElectricCurrent::Ampere);
    ElectricCurrent<double> second = ElectricCurrent<double>::Zero();
    second = first;
    EXPECT_EQ(second, ElectricCurrent<double>(1.0, Unit::ElectricCurrent::Ampere));
  }
  {
    const ElectricCurrent<long double> first(1.0L, Unit::ElectricCurrent::Ampere);
    ElectricCurrent<double> second = ElectricCurrent<double>::Zero();
    second = first;
    EXPECT_EQ(second, ElectricCurrent<double>(1.0, Unit::ElectricCurrent::Ampere));
  }
}

TEST(ElectricCurrent, CopyConstructor) {
  {
    const ElectricCurrent<float> first(1.0F, Unit::ElectricCurrent::Ampere);
    const ElectricCurrent<double> second{first};
    EXPECT_EQ(second, ElectricCurrent<double>(1.0, Unit::ElectricCurrent::Ampere));
  }
  {
    const ElectricCurrent<double> first(1.0, Unit::ElectricCurrent::Ampere);
    const ElectricCurrent<double> second{first};
    EXPECT_EQ(second, ElectricCurrent<double>(1.0, Unit::ElectricCurrent::Ampere));
  }
  {
    const ElectricCurrent<long double> first(1.0L, Unit::ElectricCurrent::Ampere);
    const ElectricCurrent<double> second{first};
    EXPECT_EQ(second, ElectricCurrent<double>(1.0, Unit::ElectricCurrent::Ampere));
  }
}

TEST(ElectricCurrent, Create) {
  constexpr ElectricCurrent electric_current =
      ElectricCurrent<>::Create<Unit::ElectricCurrent::Ampere>(1.0);
  EXPECT_EQ(electric_current, ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere));
}

TEST(ElectricCurrent, DefaultConstructor) {
  EXPECT_NO_THROW(ElectricCurrent<>{});
}

TEST(ElectricCurrent, Dimensions) {
  EXPECT_EQ(ElectricCurrent<>::Dimensions(), RelatedDimensions<Unit::ElectricCurrent>);
}

TEST(ElectricCurrent, Hash) {
  const ElectricCurrent first{1.0, Unit::ElectricCurrent::Kiloampere};
  const ElectricCurrent second{1.000001, Unit::ElectricCurrent::Kiloampere};
  const ElectricCurrent third{-1.0, Unit::ElectricCurrent::Kiloampere};
  const std::hash<ElectricCurrent<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ElectricCurrent, JSON) {
  EXPECT_EQ(ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"A\"}");
  EXPECT_EQ(ElectricCurrent(1.0, Unit::ElectricCurrent::Kiloampere)
                .JSON(Unit::ElectricCurrent::Kiloampere),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kA\"}");
}

TEST(ElectricCurrent, MoveAssignmentOperator) {
  ElectricCurrent first{1.0, Unit::ElectricCurrent::Ampere};
  ElectricCurrent second = ElectricCurrent<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere));
}

TEST(ElectricCurrent, MoveConstructor) {
  ElectricCurrent first{1.0, Unit::ElectricCurrent::Ampere};
  ElectricCurrent second{std::move(first)};
  EXPECT_EQ(second, ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere));
}

TEST(ElectricCurrent, MutableValue) {
  ElectricCurrent electric_current{1.0, Unit::ElectricCurrent::Ampere};
  double& value = electric_current.MutableValue();
  value = 2.0;
  EXPECT_EQ(electric_current.Value(), 2.0);
}

TEST(ElectricCurrent, Print) {
  EXPECT_EQ(ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere).Print(), Print(1.0) + " A");
  EXPECT_EQ(ElectricCurrent(1.0, Unit::ElectricCurrent::Kiloampere)
                .Print(Unit::ElectricCurrent::Kiloampere),
            Print(1.0) + " kA");
}

TEST(ElectricCurrent, SetValue) {
  ElectricCurrent electric_current{1.0, Unit::ElectricCurrent::Ampere};
  electric_current.SetValue(2.0);
  EXPECT_EQ(electric_current.Value(), 2.0);
}

TEST(ElectricCurrent, SizeOf) {
  EXPECT_EQ(sizeof(ElectricCurrent<>{}), sizeof(double));
}

TEST(ElectricCurrent, StaticValue) {
  constexpr ElectricCurrent electric_current =
      ElectricCurrent<>::Create<Unit::ElectricCurrent::Kiloampere>(1.0);
  constexpr double value = electric_current.StaticValue<Unit::ElectricCurrent::Kiloampere>();
  EXPECT_EQ(value, 1.0);
}

TEST(ElectricCurrent, Stream) {
  std::ostringstream stream;
  stream << ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere);
  EXPECT_EQ(stream.str(), ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere).Print());
}

TEST(ElectricCurrent, Unit) {
  EXPECT_EQ(ElectricCurrent<>::Unit(), Standard<Unit::ElectricCurrent>);
}

TEST(ElectricCurrent, Value) {
  EXPECT_EQ(ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere).Value(), 1.0);
  EXPECT_EQ(ElectricCurrent(1.0, Unit::ElectricCurrent::Kiloampere)
                .Value(Unit::ElectricCurrent::Kiloampere),
            1.0);
}

TEST(ElectricCurrent, XML) {
  EXPECT_EQ(ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere).XML(),
            "<value>" + Print(1.0) + "</value><unit>A</unit>");
  EXPECT_EQ(ElectricCurrent(1.0, Unit::ElectricCurrent::Kiloampere)
                .XML(Unit::ElectricCurrent::Kiloampere),
            "<value>" + Print(1.0) + "</value><unit>kA</unit>");
}

TEST(ElectricCurrent, YAML) {
  EXPECT_EQ(ElectricCurrent(1.0, Unit::ElectricCurrent::Ampere).YAML(),
            "{value:" + Print(1.0) + ",unit:\"A\"}");
  EXPECT_EQ(ElectricCurrent(1.0, Unit::ElectricCurrent::Kiloampere)
                .YAML(Unit::ElectricCurrent::Kiloampere),
            "{value:" + Print(1.0) + ",unit:\"kA\"}");
}

TEST(ElectricCurrent, Zero) {
  EXPECT_EQ(ElectricCurrent<>::Zero(), ElectricCurrent(0.0, Unit::ElectricCurrent::Ampere));
}

}  // namespace

}  // namespace PhQ
