// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#include "../include/PhQ/BulkDynamicViscosity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/DynamicViscosity.hpp"

namespace PhQ {

namespace {

TEST(BulkDynamicViscosity, ArithmeticOperatorAddition) {
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)
                + BulkDynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            BulkDynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, ArithmeticOperatorDivision) {
  EXPECT_EQ(BulkDynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond) / 2.0,
            BulkDynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(BulkDynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond)
                / BulkDynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            4.0);
}

TEST(BulkDynamicViscosity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(BulkDynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond) * 2.0,
            BulkDynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(2.0 * BulkDynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond),
            BulkDynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(BulkDynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond)
                - BulkDynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, AssignmentOperatorAddition) {
  BulkDynamicViscosity bulk_dynamic_viscosity{1.0, Unit::DynamicViscosity::PascalSecond};
  bulk_dynamic_viscosity += BulkDynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond);
  EXPECT_EQ(
      bulk_dynamic_viscosity, BulkDynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, AssignmentOperatorDivision) {
  BulkDynamicViscosity bulk_dynamic_viscosity{8.0, Unit::DynamicViscosity::PascalSecond};
  bulk_dynamic_viscosity /= 2.0;
  EXPECT_EQ(
      bulk_dynamic_viscosity, BulkDynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, AssignmentOperatorMultiplication) {
  BulkDynamicViscosity bulk_dynamic_viscosity{4.0, Unit::DynamicViscosity::PascalSecond};
  bulk_dynamic_viscosity *= 2.0;
  EXPECT_EQ(
      bulk_dynamic_viscosity, BulkDynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, AssignmentOperatorSubtraction) {
  BulkDynamicViscosity bulk_dynamic_viscosity{3.0, Unit::DynamicViscosity::PascalSecond};
  bulk_dynamic_viscosity -= BulkDynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond);
  EXPECT_EQ(
      bulk_dynamic_viscosity, BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, ComparisonOperators) {
  const BulkDynamicViscosity first{1.0, Unit::DynamicViscosity::PascalSecond};
  const BulkDynamicViscosity second{2.0, Unit::DynamicViscosity::PascalSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(BulkDynamicViscosity, Constructor) {
  EXPECT_NO_THROW(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond));
}

TEST(BulkDynamicViscosity, CopyAssignmentOperator) {
  {
    const BulkDynamicViscosity<float> first(1.0F, Unit::DynamicViscosity::PascalSecond);
    BulkDynamicViscosity<double> second = BulkDynamicViscosity<double>::Zero();
    second = first;
    EXPECT_EQ(second, BulkDynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
  {
    const BulkDynamicViscosity<double> first(1.0, Unit::DynamicViscosity::PascalSecond);
    BulkDynamicViscosity<double> second = BulkDynamicViscosity<double>::Zero();
    second = first;
    EXPECT_EQ(second, BulkDynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
  {
    const BulkDynamicViscosity<long double> first(1.0L, Unit::DynamicViscosity::PascalSecond);
    BulkDynamicViscosity<double> second = BulkDynamicViscosity<double>::Zero();
    second = first;
    EXPECT_EQ(second, BulkDynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
}

TEST(BulkDynamicViscosity, CopyConstructor) {
  {
    const BulkDynamicViscosity<float> first(1.0F, Unit::DynamicViscosity::PascalSecond);
    const BulkDynamicViscosity<double> second{first};
    EXPECT_EQ(second, BulkDynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
  {
    const BulkDynamicViscosity<double> first(1.0, Unit::DynamicViscosity::PascalSecond);
    const BulkDynamicViscosity<double> second{first};
    EXPECT_EQ(second, BulkDynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
  {
    const BulkDynamicViscosity<long double> first(1.0L, Unit::DynamicViscosity::PascalSecond);
    const BulkDynamicViscosity<double> second{first};
    EXPECT_EQ(second, BulkDynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
}

TEST(BulkDynamicViscosity, Create) {
  constexpr BulkDynamicViscosity bulk_dynamic_viscosity =
      BulkDynamicViscosity<>::Create<Unit::DynamicViscosity::PascalSecond>(1.0);
  EXPECT_EQ(
      bulk_dynamic_viscosity, BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, DefaultConstructor) {
  EXPECT_NO_THROW(BulkDynamicViscosity<>{});
}

TEST(BulkDynamicViscosity, Dimensions) {
  EXPECT_EQ(BulkDynamicViscosity<>::Dimensions(), RelatedDimensions<Unit::DynamicViscosity>);
}

TEST(BulkDynamicViscosity, Hash) {
  const BulkDynamicViscosity first{1.0, Unit::DynamicViscosity::KilopascalSecond};
  const BulkDynamicViscosity second{1.000001, Unit::DynamicViscosity::KilopascalSecond};
  const BulkDynamicViscosity third{-1.0, Unit::DynamicViscosity::KilopascalSecond};
  const std::hash<BulkDynamicViscosity<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(BulkDynamicViscosity, JSON) {
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Pa·s\"}");
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond)
                .JSON(Unit::DynamicViscosity::KilopascalSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kPa·s\"}");
}

TEST(BulkDynamicViscosity, MoveAssignmentOperator) {
  BulkDynamicViscosity first{1.0, Unit::DynamicViscosity::PascalSecond};
  BulkDynamicViscosity second = BulkDynamicViscosity<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, MoveConstructor) {
  BulkDynamicViscosity first{1.0, Unit::DynamicViscosity::PascalSecond};
  const BulkDynamicViscosity second{std::move(first)};
  EXPECT_EQ(second, BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(BulkDynamicViscosity, MutableValue) {
  BulkDynamicViscosity bulk_dynamic_viscosity{1.0, Unit::DynamicViscosity::PascalSecond};
  double& value = bulk_dynamic_viscosity.MutableValue();
  value = 2.0;
  EXPECT_EQ(bulk_dynamic_viscosity.Value(), 2.0);
}

TEST(BulkDynamicViscosity, Print) {
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).Print(),
            Print(1.0) + " Pa·s");
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond)
                .Print(Unit::DynamicViscosity::KilopascalSecond),
            Print(1.0) + " kPa·s");
}

TEST(BulkDynamicViscosity, SetValue) {
  BulkDynamicViscosity bulk_dynamic_viscosity{1.0, Unit::DynamicViscosity::PascalSecond};
  bulk_dynamic_viscosity.SetValue(2.0);
  EXPECT_EQ(bulk_dynamic_viscosity.Value(), 2.0);
}

TEST(BulkDynamicViscosity, SizeOf) {
  EXPECT_EQ(sizeof(BulkDynamicViscosity<>{}), sizeof(double));
}

TEST(BulkDynamicViscosity, StaticValue) {
  constexpr BulkDynamicViscosity bulk_dynamic_viscosity =
      BulkDynamicViscosity<>::Create<Unit::DynamicViscosity::KilopascalSecond>(1.0);
  constexpr double value =
      bulk_dynamic_viscosity.StaticValue<Unit::DynamicViscosity::KilopascalSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(BulkDynamicViscosity, Stream) {
  std::ostringstream stream;
  stream << BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond);
  EXPECT_EQ(stream.str(), BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).Print());
}

TEST(BulkDynamicViscosity, Unit) {
  EXPECT_EQ(BulkDynamicViscosity<>::Unit(), Standard<Unit::DynamicViscosity>);
}

TEST(BulkDynamicViscosity, Value) {
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).Value(), 1.0);
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond)
                .Value(Unit::DynamicViscosity::KilopascalSecond),
            1.0);
}

TEST(BulkDynamicViscosity, XML) {
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>Pa·s</unit>");
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond)
                .XML(Unit::DynamicViscosity::KilopascalSecond),
            "<value>" + Print(1.0) + "</value><unit>kPa·s</unit>");
}

TEST(BulkDynamicViscosity, YAML) {
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"Pa·s\"}");
  EXPECT_EQ(BulkDynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond)
                .YAML(Unit::DynamicViscosity::KilopascalSecond),
            "{value:" + Print(1.0) + ",unit:\"kPa·s\"}");
}

TEST(BulkDynamicViscosity, Zero) {
  EXPECT_EQ(BulkDynamicViscosity<>::Zero(),
            BulkDynamicViscosity(0.0, Unit::DynamicViscosity::PascalSecond));
}

}  // namespace

}  // namespace PhQ
