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

#include "../include/PhQ/IsentropicBulkModulus.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Pressure.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(IsentropicBulkModulus, ArithmeticOperatorAddition) {
  EXPECT_EQ(IsentropicBulkModulus(1.0, Unit::Pressure::Pascal)
                + IsentropicBulkModulus(2.0, Unit::Pressure::Pascal),
            IsentropicBulkModulus(3.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, ArithmeticOperatorDivision) {
  EXPECT_EQ(IsentropicBulkModulus(8.0, Unit::Pressure::Pascal) / 2.0,
            IsentropicBulkModulus(4.0, Unit::Pressure::Pascal));
  EXPECT_EQ(IsentropicBulkModulus(8.0, Unit::Pressure::Pascal)
                / IsentropicBulkModulus(2.0, Unit::Pressure::Pascal),
            4.0);
}

TEST(IsentropicBulkModulus, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(IsentropicBulkModulus(4.0, Unit::Pressure::Pascal) * 2.0,
            IsentropicBulkModulus(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(2.0 * IsentropicBulkModulus(4.0, Unit::Pressure::Pascal),
            IsentropicBulkModulus(8.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(IsentropicBulkModulus(3.0, Unit::Pressure::Pascal)
                - IsentropicBulkModulus(2.0, Unit::Pressure::Pascal),
            IsentropicBulkModulus(1.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, AssignmentOperatorAddition) {
  IsentropicBulkModulus isentropic_bulk_modulus{1.0, Unit::Pressure::Pascal};
  isentropic_bulk_modulus += IsentropicBulkModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(isentropic_bulk_modulus, IsentropicBulkModulus(3.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, AssignmentOperatorDivision) {
  IsentropicBulkModulus isentropic_bulk_modulus{8.0, Unit::Pressure::Pascal};
  isentropic_bulk_modulus /= 2.0;
  EXPECT_EQ(isentropic_bulk_modulus, IsentropicBulkModulus(4.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, AssignmentOperatorMultiplication) {
  IsentropicBulkModulus isentropic_bulk_modulus{4.0, Unit::Pressure::Pascal};
  isentropic_bulk_modulus *= 2.0;
  EXPECT_EQ(isentropic_bulk_modulus, IsentropicBulkModulus(8.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, AssignmentOperatorSubtraction) {
  IsentropicBulkModulus isentropic_bulk_modulus{3.0, Unit::Pressure::Pascal};
  isentropic_bulk_modulus -= IsentropicBulkModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(isentropic_bulk_modulus, IsentropicBulkModulus(1.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, ComparisonOperators) {
  const IsentropicBulkModulus first{1.0, Unit::Pressure::Pascal};
  const IsentropicBulkModulus second{2.0, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(IsentropicBulkModulus, Constructor) {
  EXPECT_NO_THROW(IsentropicBulkModulus(1.0, Unit::Pressure::Kilopascal));
}

TEST(IsentropicBulkModulus, CopyAssignmentOperator) {
  {
    const IsentropicBulkModulus<float> first(1.0F, Unit::Pressure::Pascal);
    IsentropicBulkModulus<double> second = IsentropicBulkModulus<double>::Zero();
    second = first;
    EXPECT_EQ(second, IsentropicBulkModulus<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const IsentropicBulkModulus<double> first(1.0, Unit::Pressure::Pascal);
    IsentropicBulkModulus<double> second = IsentropicBulkModulus<double>::Zero();
    second = first;
    EXPECT_EQ(second, IsentropicBulkModulus<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const IsentropicBulkModulus<long double> first(1.0L, Unit::Pressure::Pascal);
    IsentropicBulkModulus<double> second = IsentropicBulkModulus<double>::Zero();
    second = first;
    EXPECT_EQ(second, IsentropicBulkModulus<double>(1.0, Unit::Pressure::Pascal));
  }
}

TEST(IsentropicBulkModulus, CopyConstructor) {
  {
    const IsentropicBulkModulus<float> first(1.0F, Unit::Pressure::Pascal);
    const IsentropicBulkModulus<double> second{first};
    EXPECT_EQ(second, IsentropicBulkModulus<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const IsentropicBulkModulus<double> first(1.0, Unit::Pressure::Pascal);
    const IsentropicBulkModulus<double> second{first};
    EXPECT_EQ(second, IsentropicBulkModulus<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const IsentropicBulkModulus<long double> first(1.0L, Unit::Pressure::Pascal);
    const IsentropicBulkModulus<double> second{first};
    EXPECT_EQ(second, IsentropicBulkModulus<double>(1.0, Unit::Pressure::Pascal));
  }
}

TEST(IsentropicBulkModulus, Create) {
  constexpr IsentropicBulkModulus isentropic_bulk_modulus =
      IsentropicBulkModulus<>::Create<Unit::Pressure::Pascal>(1.0);
  EXPECT_EQ(isentropic_bulk_modulus, IsentropicBulkModulus(1.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, DefaultConstructor) {
  EXPECT_NO_THROW(IsentropicBulkModulus<>{});
}

TEST(IsentropicBulkModulus, Dimensions) {
  EXPECT_EQ(IsentropicBulkModulus<>::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(IsentropicBulkModulus, Hash) {
  const IsentropicBulkModulus first{1.0, Unit::Pressure::Kilopascal};
  const IsentropicBulkModulus second{1.00001, Unit::Pressure::Kilopascal};
  const IsentropicBulkModulus third{-1.0, Unit::Pressure::Kilopascal};
  const std::hash<IsentropicBulkModulus<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(IsentropicBulkModulus, JSON) {
  EXPECT_EQ(IsentropicBulkModulus(1.0, Unit::Pressure::Pascal).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Pa\"}");
  EXPECT_EQ(IsentropicBulkModulus(1.0, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kPa\"}");
}

TEST(IsentropicBulkModulus, MoveAssignmentOperator) {
  IsentropicBulkModulus first{1.0, Unit::Pressure::Pascal};
  IsentropicBulkModulus second = IsentropicBulkModulus<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, IsentropicBulkModulus(1.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, MoveConstructor) {
  IsentropicBulkModulus first{1.0, Unit::Pressure::Pascal};
  const IsentropicBulkModulus second{std::move(first)};
  EXPECT_EQ(second, IsentropicBulkModulus(1.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, MutableValue) {
  IsentropicBulkModulus isentropic_bulk_modulus{1.0, Unit::Pressure::Pascal};
  double& value = isentropic_bulk_modulus.MutableValue();
  value = 2.0;
  EXPECT_EQ(isentropic_bulk_modulus.Value(), 2.0);
}

TEST(IsentropicBulkModulus, Performance) {
  IsentropicBulkModulus first{1.2345678901234567890, Unit::Pressure::Pascal};
  IsentropicBulkModulus second{1.2345678901234567890, Unit::Pressure::Pascal};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(IsentropicBulkModulus, Print) {
  EXPECT_EQ(IsentropicBulkModulus(1.0, Unit::Pressure::Pascal).Print(), Print(1.0) + " Pa");
  EXPECT_EQ(
      IsentropicBulkModulus(1.0, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
      Print(1.0) + " kPa");
}

TEST(IsentropicBulkModulus, SetValue) {
  IsentropicBulkModulus isentropic_bulk_modulus{1.0, Unit::Pressure::Pascal};
  isentropic_bulk_modulus.SetValue(2.0);
  EXPECT_EQ(isentropic_bulk_modulus.Value(), 2.0);
}

TEST(IsentropicBulkModulus, SizeOf) {
  EXPECT_EQ(sizeof(IsentropicBulkModulus<>{}), sizeof(double));
}

TEST(IsentropicBulkModulus, StaticValue) {
  constexpr IsentropicBulkModulus isentropic_bulk_modulus =
      IsentropicBulkModulus<>::Create<Unit::Pressure::Kilopascal>(2.0);
  constexpr double value = isentropic_bulk_modulus.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 2.0);
}

TEST(IsentropicBulkModulus, Stream) {
  std::ostringstream stream;
  stream << IsentropicBulkModulus(1.0, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), IsentropicBulkModulus(1.0, Unit::Pressure::Pascal).Print());
}

TEST(IsentropicBulkModulus, Unit) {
  EXPECT_EQ(IsentropicBulkModulus<>::Unit(), Standard<Unit::Pressure>);
}

TEST(IsentropicBulkModulus, Value) {
  EXPECT_EQ(IsentropicBulkModulus(1.0, Unit::Pressure::Pascal).Value(), 1.0);
  EXPECT_EQ(
      IsentropicBulkModulus(2.0, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal),
      2.0);
}

TEST(IsentropicBulkModulus, XML) {
  EXPECT_EQ(IsentropicBulkModulus(1.0, Unit::Pressure::Pascal).XML(),
            "<value>" + Print(1.0) + "</value><unit>Pa</unit>");
  EXPECT_EQ(IsentropicBulkModulus(1.0, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value>" + Print(1.0) + "</value><unit>kPa</unit>");
}

TEST(IsentropicBulkModulus, YAML) {
  EXPECT_EQ(IsentropicBulkModulus(1.0, Unit::Pressure::Pascal).YAML(),
            "{value:" + Print(1.0) + ",unit:\"Pa\"}");
  EXPECT_EQ(IsentropicBulkModulus(1.0, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
            "{value:" + Print(1.0) + ",unit:\"kPa\"}");
}

TEST(IsentropicBulkModulus, Zero) {
  EXPECT_EQ(IsentropicBulkModulus<>::Zero(), IsentropicBulkModulus(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
