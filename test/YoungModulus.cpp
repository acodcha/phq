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

#include "../include/PhQ/YoungModulus.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

TEST(YoungModulus, ArithmeticOperatorAddition) {
  EXPECT_EQ(YoungModulus(1.0, Unit::Pressure::Pascal) + YoungModulus(2.0, Unit::Pressure::Pascal),
            YoungModulus(3.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      YoungModulus(8.0, Unit::Pressure::Pascal) / 2.0, YoungModulus(4.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      YoungModulus(8.0, Unit::Pressure::Pascal) / YoungModulus(2.0, Unit::Pressure::Pascal), 4.0);
}

TEST(YoungModulus, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      YoungModulus(4.0, Unit::Pressure::Pascal) * 2.0, YoungModulus(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      2.0 * YoungModulus(4.0, Unit::Pressure::Pascal), YoungModulus(8.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(YoungModulus(3.0, Unit::Pressure::Pascal) - YoungModulus(2.0, Unit::Pressure::Pascal),
            YoungModulus(1.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, AssignmentOperatorAddition) {
  YoungModulus young_modulus{1.0, Unit::Pressure::Pascal};
  young_modulus += YoungModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(young_modulus, YoungModulus(3.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, AssignmentOperatorDivision) {
  YoungModulus young_modulus{8.0, Unit::Pressure::Pascal};
  young_modulus /= 2.0;
  EXPECT_EQ(young_modulus, YoungModulus(4.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, AssignmentOperatorMultiplication) {
  YoungModulus young_modulus{4.0, Unit::Pressure::Pascal};
  young_modulus *= 2.0;
  EXPECT_EQ(young_modulus, YoungModulus(8.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, AssignmentOperatorSubtraction) {
  YoungModulus young_modulus{3.0, Unit::Pressure::Pascal};
  young_modulus -= YoungModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(young_modulus, YoungModulus(1.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, ComparisonOperators) {
  const YoungModulus first{1.0, Unit::Pressure::Pascal};
  const YoungModulus second{2.0, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(YoungModulus, CopyAssignmentOperator) {
  const YoungModulus first{1.0, Unit::Pressure::Pascal};
  YoungModulus second = YoungModulus<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(YoungModulus, CopyConstructor) {
  const YoungModulus first{1.0, Unit::Pressure::Pascal};
  const YoungModulus second{first};
  EXPECT_EQ(second, first);
}

TEST(YoungModulus, Create) {
  constexpr YoungModulus young_modulus = YoungModulus<>::Create<Unit::Pressure::Pascal>(1.0);
  EXPECT_EQ(young_modulus, YoungModulus(1.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, DefaultConstructor) {
  EXPECT_NO_THROW(YoungModulus{});
}

TEST(YoungModulus, Dimensions) {
  EXPECT_EQ(YoungModulus<>::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(YoungModulus, Hash) {
  const YoungModulus first{1.0, Unit::Pressure::Kilopascal};
  const YoungModulus second{1.000001, Unit::Pressure::Kilopascal};
  const YoungModulus third{-1.0, Unit::Pressure::Kilopascal};
  const std::hash<YoungModulus<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(YoungModulus, JSON) {
  EXPECT_EQ(YoungModulus(1.0, Unit::Pressure::Pascal).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Pa\"}");
  EXPECT_EQ(YoungModulus(1.0, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kPa\"}");
}

TEST(YoungModulus, MoveAssignmentOperator) {
  YoungModulus first{1.0, Unit::Pressure::Pascal};
  YoungModulus second = YoungModulus<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, YoungModulus(1.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, MoveConstructor) {
  YoungModulus first{1.0, Unit::Pressure::Pascal};
  const YoungModulus second{std::move(first)};
  EXPECT_EQ(second, YoungModulus(1.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, MutableValue) {
  YoungModulus young_modulus{1.0, Unit::Pressure::Pascal};
  double& value = young_modulus.MutableValue();
  value = 2.0;
  EXPECT_EQ(young_modulus.Value(), 2.0);
}

TEST(YoungModulus, Print) {
  EXPECT_EQ(YoungModulus(1.0, Unit::Pressure::Pascal).Print(), Print(1.0) + " Pa");
  EXPECT_EQ(YoungModulus(1.0, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
            Print(1.0) + " kPa");
}

TEST(YoungModulus, SetValue) {
  YoungModulus young_modulus{1.0, Unit::Pressure::Pascal};
  young_modulus.SetValue(2.0);
  EXPECT_EQ(young_modulus.Value(), 2.0);
}

TEST(YoungModulus, SizeOf) {
  EXPECT_EQ(sizeof(YoungModulus{}), sizeof(double));
}

TEST(YoungModulus, StandardConstructor) {
  EXPECT_NO_THROW(YoungModulus(1.0, Unit::Pressure::Kilopascal));
}

TEST(YoungModulus, StaticValue) {
  constexpr YoungModulus young_modulus = YoungModulus<>::Create<Unit::Pressure::Kilopascal>(1.0);
  constexpr double value = young_modulus.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.0);
}

TEST(YoungModulus, Stream) {
  std::ostringstream stream;
  stream << YoungModulus(1.0, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), YoungModulus(1.0, Unit::Pressure::Pascal).Print());
}

TEST(YoungModulus, Unit) {
  EXPECT_EQ(YoungModulus<>::Unit(), Standard<Unit::Pressure>);
}

TEST(YoungModulus, Value) {
  EXPECT_EQ(YoungModulus(1.0, Unit::Pressure::Pascal).Value(), 1.0);
  EXPECT_EQ(YoungModulus(1.0, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal), 1.0);
}

TEST(YoungModulus, XML) {
  EXPECT_EQ(YoungModulus(1.0, Unit::Pressure::Pascal).XML(),
            "<value>" + Print(1.0) + "</value><unit>Pa</unit>");
  EXPECT_EQ(YoungModulus(1.0, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value>" + Print(1.0) + "</value><unit>kPa</unit>");
}

TEST(YoungModulus, YAML) {
  EXPECT_EQ(
      YoungModulus(1.0, Unit::Pressure::Pascal).YAML(), "{value:" + Print(1.0) + ",unit:\"Pa\"}");
  EXPECT_EQ(YoungModulus(1.0, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
            "{value:" + Print(1.0) + ",unit:\"kPa\"}");
}

TEST(YoungModulus, Zero) {
  EXPECT_EQ(YoungModulus<>::Zero(), YoungModulus(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
