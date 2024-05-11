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

#include "../include/PhQ/PWaveModulus.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

TEST(PWaveModulus, ArithmeticOperatorAddition) {
  EXPECT_EQ(PWaveModulus(1.0, Unit::Pressure::Pascal) + PWaveModulus(2.0, Unit::Pressure::Pascal),
            PWaveModulus(3.0, Unit::Pressure::Pascal));
}

TEST(PWaveModulus, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      PWaveModulus(8.0, Unit::Pressure::Pascal) / 2.0, PWaveModulus(4.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      PWaveModulus(8.0, Unit::Pressure::Pascal) / PWaveModulus(2.0, Unit::Pressure::Pascal), 4.0);
}

TEST(PWaveModulus, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      PWaveModulus(4.0, Unit::Pressure::Pascal) * 2.0, PWaveModulus(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      2.0 * PWaveModulus(4.0, Unit::Pressure::Pascal), PWaveModulus(8.0, Unit::Pressure::Pascal));
}

TEST(PWaveModulus, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PWaveModulus(3.0, Unit::Pressure::Pascal) - PWaveModulus(2.0, Unit::Pressure::Pascal),
            PWaveModulus(1.0, Unit::Pressure::Pascal));
}

TEST(PWaveModulus, AssignmentOperatorAddition) {
  PWaveModulus p_wave_modulus{1.0, Unit::Pressure::Pascal};
  p_wave_modulus += PWaveModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(p_wave_modulus, PWaveModulus(3.0, Unit::Pressure::Pascal));
}

TEST(PWaveModulus, AssignmentOperatorDivision) {
  PWaveModulus p_wave_modulus{8.0, Unit::Pressure::Pascal};
  p_wave_modulus /= 2.0;
  EXPECT_EQ(p_wave_modulus, PWaveModulus(4.0, Unit::Pressure::Pascal));
}

TEST(PWaveModulus, AssignmentOperatorMultiplication) {
  PWaveModulus p_wave_modulus{4.0, Unit::Pressure::Pascal};
  p_wave_modulus *= 2.0;
  EXPECT_EQ(p_wave_modulus, PWaveModulus(8.0, Unit::Pressure::Pascal));
}

TEST(PWaveModulus, AssignmentOperatorSubtraction) {
  PWaveModulus p_wave_modulus{3.0, Unit::Pressure::Pascal};
  p_wave_modulus -= PWaveModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(p_wave_modulus, PWaveModulus(1.0, Unit::Pressure::Pascal));
}

TEST(PWaveModulus, ComparisonOperators) {
  const PWaveModulus first{1.0, Unit::Pressure::Pascal};
  const PWaveModulus second{2.0, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PWaveModulus, CopyAssignmentOperator) {
  const PWaveModulus first{1.0, Unit::Pressure::Pascal};
  PWaveModulus second = PWaveModulus<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(PWaveModulus, CopyConstructor) {
  const PWaveModulus first{1.0, Unit::Pressure::Pascal};
  const PWaveModulus second{first};
  EXPECT_EQ(second, first);
}

TEST(PWaveModulus, Create) {
  constexpr PWaveModulus p_wave_modulus = PWaveModulus<>::Create<Unit::Pressure::Pascal>(1.0);
  EXPECT_EQ(p_wave_modulus, PWaveModulus(1.0, Unit::Pressure::Pascal));
}

TEST(PWaveModulus, DefaultConstructor) {
  EXPECT_NO_THROW(PWaveModulus{});
}

TEST(PWaveModulus, Dimensions) {
  EXPECT_EQ(PWaveModulus<>::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(PWaveModulus, Hash) {
  const PWaveModulus first{1.0, Unit::Pressure::Kilopascal};
  const PWaveModulus second{1.000001, Unit::Pressure::Kilopascal};
  const PWaveModulus third{-1.0, Unit::Pressure::Kilopascal};
  const std::hash<PWaveModulus<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(PWaveModulus, JSON) {
  EXPECT_EQ(PWaveModulus(1.0, Unit::Pressure::Pascal).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Pa\"}");
  EXPECT_EQ(PWaveModulus(1.0, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kPa\"}");
}

TEST(PWaveModulus, MoveAssignmentOperator) {
  PWaveModulus first{1.0, Unit::Pressure::Pascal};
  PWaveModulus second = PWaveModulus<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PWaveModulus(1.0, Unit::Pressure::Pascal));
}

TEST(PWaveModulus, MoveConstructor) {
  PWaveModulus first{1.0, Unit::Pressure::Pascal};
  const PWaveModulus second{std::move(first)};
  EXPECT_EQ(second, PWaveModulus(1.0, Unit::Pressure::Pascal));
}

TEST(PWaveModulus, MutableValue) {
  PWaveModulus p_wave_modulus{1.0, Unit::Pressure::Pascal};
  double& value = p_wave_modulus.MutableValue();
  value = 2.0;
  EXPECT_EQ(p_wave_modulus.Value(), 2.0);
}

TEST(PWaveModulus, Print) {
  EXPECT_EQ(PWaveModulus(1.0, Unit::Pressure::Pascal).Print(), Print(1.0) + " Pa");
  EXPECT_EQ(PWaveModulus(1.0, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
            Print(1.0) + " kPa");
}

TEST(PWaveModulus, SetValue) {
  PWaveModulus p_wave_modulus{1.0, Unit::Pressure::Pascal};
  p_wave_modulus.SetValue(2.0);
  EXPECT_EQ(p_wave_modulus.Value(), 2.0);
}

TEST(PWaveModulus, SizeOf) {
  EXPECT_EQ(sizeof(PWaveModulus{}), sizeof(double));
}

TEST(PWaveModulus, StandardConstructor) {
  EXPECT_NO_THROW(PWaveModulus(1.0, Unit::Pressure::Kilopascal));
}

TEST(PWaveModulus, StaticValue) {
  constexpr PWaveModulus p_wave_modulus = PWaveModulus<>::Create<Unit::Pressure::Kilopascal>(1.0);
  constexpr double value = p_wave_modulus.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.0);
}

TEST(PWaveModulus, Stream) {
  std::ostringstream stream;
  stream << PWaveModulus(1.0, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), PWaveModulus(1.0, Unit::Pressure::Pascal).Print());
}

TEST(PWaveModulus, Unit) {
  EXPECT_EQ(PWaveModulus<>::Unit(), Standard<Unit::Pressure>);
}

TEST(PWaveModulus, Value) {
  EXPECT_EQ(PWaveModulus(1.0, Unit::Pressure::Pascal).Value(), 1.0);
  EXPECT_EQ(PWaveModulus(1.0, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal), 1.0);
}

TEST(PWaveModulus, XML) {
  EXPECT_EQ(PWaveModulus(1.0, Unit::Pressure::Pascal).XML(),
            "<value>" + Print(1.0) + "</value><unit>Pa</unit>");
  EXPECT_EQ(PWaveModulus(1.0, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value>" + Print(1.0) + "</value><unit>kPa</unit>");
}

TEST(PWaveModulus, YAML) {
  EXPECT_EQ(
      PWaveModulus(1.0, Unit::Pressure::Pascal).YAML(), "{value:" + Print(1.0) + ",unit:\"Pa\"}");
  EXPECT_EQ(PWaveModulus(1.0, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
            "{value:" + Print(1.0) + ",unit:\"kPa\"}");
}

TEST(PWaveModulus, Zero) {
  EXPECT_EQ(PWaveModulus<>::Zero(), PWaveModulus(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
