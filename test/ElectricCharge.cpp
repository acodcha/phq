// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/ElectricCharge.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/ElectricCharge.hpp"

namespace PhQ {

namespace {

TEST(ElectricCharge, ArithmeticOperatorAddition) {
  EXPECT_EQ(ElectricCharge(1.0, Unit::ElectricCharge::Coulomb)
                + ElectricCharge(2.0, Unit::ElectricCharge::Coulomb),
            ElectricCharge(3.0, Unit::ElectricCharge::Coulomb));
}

TEST(ElectricCharge, ArithmeticOperatorDivision) {
  EXPECT_EQ(ElectricCharge(8.0, Unit::ElectricCharge::Coulomb) / 2.0,
            ElectricCharge(4.0, Unit::ElectricCharge::Coulomb));
  EXPECT_EQ(ElectricCharge(8.0, Unit::ElectricCharge::Coulomb)
                / ElectricCharge(2.0, Unit::ElectricCharge::Coulomb),
            4.0);
}

TEST(ElectricCharge, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ElectricCharge(4.0, Unit::ElectricCharge::Coulomb) * 2.0,
            ElectricCharge(8.0, Unit::ElectricCharge::Coulomb));
  EXPECT_EQ(2.0 * ElectricCharge(4.0, Unit::ElectricCharge::Coulomb),
            ElectricCharge(8.0, Unit::ElectricCharge::Coulomb));
}

TEST(ElectricCharge, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ElectricCharge(3.0, Unit::ElectricCharge::Coulomb)
                - ElectricCharge(2.0, Unit::ElectricCharge::Coulomb),
            ElectricCharge(1.0, Unit::ElectricCharge::Coulomb));
}

TEST(ElectricCharge, AssignmentOperatorAddition) {
  ElectricCharge electric_charge{1.0, Unit::ElectricCharge::Coulomb};
  electric_charge += ElectricCharge(2.0, Unit::ElectricCharge::Coulomb);
  EXPECT_EQ(electric_charge, ElectricCharge(3.0, Unit::ElectricCharge::Coulomb));
}

TEST(ElectricCharge, AssignmentOperatorDivision) {
  ElectricCharge electric_charge{8.0, Unit::ElectricCharge::Coulomb};
  electric_charge /= 2.0;
  EXPECT_EQ(electric_charge, ElectricCharge(4.0, Unit::ElectricCharge::Coulomb));
}

TEST(ElectricCharge, AssignmentOperatorMultiplication) {
  ElectricCharge electric_charge{4.0, Unit::ElectricCharge::Coulomb};
  electric_charge *= 2.0;
  EXPECT_EQ(electric_charge, ElectricCharge(8.0, Unit::ElectricCharge::Coulomb));
}

TEST(ElectricCharge, AssignmentOperatorSubtraction) {
  ElectricCharge electric_charge{3.0, Unit::ElectricCharge::Coulomb};
  electric_charge -= ElectricCharge(2.0, Unit::ElectricCharge::Coulomb);
  EXPECT_EQ(electric_charge, ElectricCharge(1.0, Unit::ElectricCharge::Coulomb));
}

TEST(ElectricCharge, ComparisonOperators) {
  const ElectricCharge first{1.0, Unit::ElectricCharge::Coulomb};
  const ElectricCharge second{2.0, Unit::ElectricCharge::Coulomb};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ElectricCharge, Constructor) {
  EXPECT_NO_THROW(ElectricCharge(1.0, Unit::ElectricCharge::Kilocoulomb));
}

TEST(ElectricCharge, CopyAssignmentOperator) {
  {
    const ElectricCharge<float> first(1.0F, Unit::ElectricCharge::Coulomb);
    ElectricCharge<double> second = ElectricCharge<double>::Zero();
    second = first;
    EXPECT_EQ(second, ElectricCharge<double>(1.0, Unit::ElectricCharge::Coulomb));
  }
  {
    const ElectricCharge<double> first(1.0, Unit::ElectricCharge::Coulomb);
    ElectricCharge<double> second = ElectricCharge<double>::Zero();
    second = first;
    EXPECT_EQ(second, ElectricCharge<double>(1.0, Unit::ElectricCharge::Coulomb));
  }
  {
    const ElectricCharge<long double> first(1.0L, Unit::ElectricCharge::Coulomb);
    ElectricCharge<double> second = ElectricCharge<double>::Zero();
    second = first;
    EXPECT_EQ(second, ElectricCharge<double>(1.0, Unit::ElectricCharge::Coulomb));
  }
}

TEST(ElectricCharge, CopyConstructor) {
  {
    const ElectricCharge<float> first(1.0F, Unit::ElectricCharge::Coulomb);
    const ElectricCharge<double> second{first};
    EXPECT_EQ(second, ElectricCharge<double>(1.0, Unit::ElectricCharge::Coulomb));
  }
  {
    const ElectricCharge<double> first(1.0, Unit::ElectricCharge::Coulomb);
    const ElectricCharge<double> second{first};
    EXPECT_EQ(second, ElectricCharge<double>(1.0, Unit::ElectricCharge::Coulomb));
  }
  {
    const ElectricCharge<long double> first(1.0L, Unit::ElectricCharge::Coulomb);
    const ElectricCharge<double> second{first};
    EXPECT_EQ(second, ElectricCharge<double>(1.0, Unit::ElectricCharge::Coulomb));
  }
}

TEST(ElectricCharge, Create) {
  constexpr ElectricCharge electric_charge =
      ElectricCharge<>::Create<Unit::ElectricCharge::Coulomb>(1.0);
  EXPECT_EQ(electric_charge, ElectricCharge(1.0, Unit::ElectricCharge::Coulomb));
}

TEST(ElectricCharge, DefaultConstructor) {
  EXPECT_NO_THROW(ElectricCharge<>{});
}

TEST(ElectricCharge, Dimensions) {
  EXPECT_EQ(ElectricCharge<>::Dimensions(), RelatedDimensions<Unit::ElectricCharge>);
}

TEST(ElectricCharge, Hash) {
  const ElectricCharge first{1.0, Unit::ElectricCharge::Kilocoulomb};
  const ElectricCharge second{1.000001, Unit::ElectricCharge::Kilocoulomb};
  const ElectricCharge third{-1.0, Unit::ElectricCharge::Kilocoulomb};
  const std::hash<ElectricCharge<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ElectricCharge, JSON) {
  EXPECT_EQ(ElectricCharge(1.0, Unit::ElectricCharge::Coulomb).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"C\"}");
  EXPECT_EQ(ElectricCharge(1.0, Unit::ElectricCharge::Kilocoulomb)
                .JSON(Unit::ElectricCharge::Kilocoulomb),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kC\"}");
}

TEST(ElectricCharge, MoveAssignmentOperator) {
  ElectricCharge first{1.0, Unit::ElectricCharge::Coulomb};
  ElectricCharge second = ElectricCharge<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ElectricCharge(1.0, Unit::ElectricCharge::Coulomb));
}

TEST(ElectricCharge, MoveConstructor) {
  ElectricCharge first{1.0, Unit::ElectricCharge::Coulomb};
  ElectricCharge second{std::move(first)};
  EXPECT_EQ(second, ElectricCharge(1.0, Unit::ElectricCharge::Coulomb));
}

TEST(ElectricCharge, MutableValue) {
  ElectricCharge electric_charge{1.0, Unit::ElectricCharge::Coulomb};
  double& value = electric_charge.MutableValue();
  value = 2.0;
  EXPECT_EQ(electric_charge.Value(), 2.0);
}

TEST(ElectricCharge, Print) {
  EXPECT_EQ(ElectricCharge(1.0, Unit::ElectricCharge::Coulomb).Print(), Print(1.0) + " C");
  EXPECT_EQ(ElectricCharge(1.0, Unit::ElectricCharge::Kilocoulomb)
                .Print(Unit::ElectricCharge::Kilocoulomb),
            Print(1.0) + " kC");
}

TEST(ElectricCharge, SetValue) {
  ElectricCharge electric_charge{1.0, Unit::ElectricCharge::Coulomb};
  electric_charge.SetValue(2.0);
  EXPECT_EQ(electric_charge.Value(), 2.0);
}

TEST(ElectricCharge, SizeOf) {
  EXPECT_EQ(sizeof(ElectricCharge<>{}), sizeof(double));
}

TEST(ElectricCharge, StaticValue) {
  constexpr ElectricCharge electric_charge =
      ElectricCharge<>::Create<Unit::ElectricCharge::Kilocoulomb>(1.0);
  constexpr double value = electric_charge.StaticValue<Unit::ElectricCharge::Kilocoulomb>();
  EXPECT_EQ(value, 1.0);
}

TEST(ElectricCharge, Stream) {
  std::ostringstream stream;
  stream << ElectricCharge(1.0, Unit::ElectricCharge::Coulomb);
  EXPECT_EQ(stream.str(), ElectricCharge(1.0, Unit::ElectricCharge::Coulomb).Print());
}

TEST(ElectricCharge, Unit) {
  EXPECT_EQ(ElectricCharge<>::Unit(), Standard<Unit::ElectricCharge>);
}

TEST(ElectricCharge, Value) {
  EXPECT_EQ(ElectricCharge(1.0, Unit::ElectricCharge::Coulomb).Value(), 1.0);
  EXPECT_EQ(ElectricCharge(1.0, Unit::ElectricCharge::Kilocoulomb)
                .Value(Unit::ElectricCharge::Kilocoulomb),
            1.0);
}

TEST(ElectricCharge, XML) {
  EXPECT_EQ(ElectricCharge(1.0, Unit::ElectricCharge::Coulomb).XML(),
            "<value>" + Print(1.0) + "</value><unit>C</unit>");
  EXPECT_EQ(
      ElectricCharge(1.0, Unit::ElectricCharge::Kilocoulomb).XML(Unit::ElectricCharge::Kilocoulomb),
      "<value>" + Print(1.0) + "</value><unit>kC</unit>");
}

TEST(ElectricCharge, YAML) {
  EXPECT_EQ(ElectricCharge(1.0, Unit::ElectricCharge::Coulomb).YAML(),
            "{value:" + Print(1.0) + ",unit:\"C\"}");
  EXPECT_EQ(ElectricCharge(1.0, Unit::ElectricCharge::Kilocoulomb)
                .YAML(Unit::ElectricCharge::Kilocoulomb),
            "{value:" + Print(1.0) + ",unit:\"kC\"}");
}

TEST(ElectricCharge, Zero) {
  EXPECT_EQ(ElectricCharge<>::Zero(), ElectricCharge(0.0, Unit::ElectricCharge::Coulomb));
}

}  // namespace

}  // namespace PhQ
