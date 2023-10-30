// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#include "../include/PhQ/Traction.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Traction, Angle) {
  EXPECT_EQ(Traction({0.0, -2.22, 0.0}, Unit::Pressure::Pascal)
                .Angle(Traction({0.0, 0.0, 3.33}, Unit::Pressure::Pascal)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Traction, ArithmeticOperatorAddition) {
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal)
                + Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal),
            Traction({3.0, -6.0, 9.0}, Unit::Pressure::Pascal));
}

TEST(Traction, ArithmeticOperatorDivision) {
  EXPECT_EQ(Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal) / 2.0,
            Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));

  EXPECT_EQ(Force({2.0, -4.0, 6.0}, Unit::Force::Newton)
                / Area(2.0, Unit::Area::SquareMetre),
            Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
}

TEST(Traction, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal) * 2.0,
            Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal));

  EXPECT_EQ(2.0 * Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal),
            Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal));

  EXPECT_EQ(
      Direction(2.0, -3.0, 6.0) * StaticPressure(7.0, Unit::Pressure::Pascal),
      Traction({-2.0, 3.0, -6.0}, Unit::Pressure::Pascal));

  EXPECT_EQ(
      StaticPressure(7.0, Unit::Pressure::Pascal) * Direction(2.0, -3.0, 6.0),
      Traction({-2.0, 3.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(Traction, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Traction({3.0, -6.0, 9.0}, Unit::Pressure::Pascal)
                - Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal),
            Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
}

TEST(Traction, AssignmentOperatorAddition) {
  Traction quantity({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  quantity += Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, Traction({3.0, -6.0, 9.0}, Unit::Pressure::Pascal));
}

TEST(Traction, AssignmentOperatorDivision) {
  Traction quantity({2.0, -4.0, 6.0}, Unit::Pressure::Pascal);
  quantity /= 2.0;
  EXPECT_EQ(quantity, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
}

TEST(Traction, AssignmentOperatorMultiplication) {
  Traction quantity({1.0, -2.0, 3.0}, Unit::Pressure::Pascal);
  quantity *= 2.0;
  EXPECT_EQ(quantity, Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal));
}

TEST(Traction, AssignmentOperatorSubtraction) {
  Traction quantity({3.0, -6.0, 9.0}, Unit::Pressure::Pascal);
  quantity -= Traction({2.0, -4.0, 6.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));
}

TEST(Traction, ComparisonOperators) {
  const Traction first({1.11, -2.22, 3.33}, Unit::Pressure::Pascal);
  const Traction second({1.11, -2.22, 3.330001}, Unit::Pressure::Pascal);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Traction, CopyAssignmentOperator) {
  const Traction first({1.11, -2.22, 3.33}, Unit::Pressure::Pascal);
  Traction second = Traction::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Traction, CopyConstructor) {
  const Traction first({1.11, -2.22, 3.33}, Unit::Pressure::Pascal);
  const Traction second{first};
  EXPECT_EQ(second, first);
}

TEST(Traction, Create) {
  constexpr Traction first =
      Traction::Create<Unit::Pressure::Pascal>(1.11, -2.22, 3.33);
  EXPECT_EQ(first, Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal));

  constexpr Traction second = Traction::Create<Unit::Pressure::Pascal>(
      std::array<double, 3>{1.11, -2.22, 3.33});
  EXPECT_EQ(second, Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal));

  constexpr Traction third = Traction::Create<Unit::Pressure::Pascal>(
      Value::Vector{1.11, -2.22, 3.33});
  EXPECT_EQ(third, Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal));
}

TEST(Traction, DefaultConstructor) {
  EXPECT_NO_THROW(Traction{});
}

TEST(Traction, Dimensions) {
  EXPECT_EQ(Traction::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(Traction, Hash) {
  const Traction first({1.11, -2.22, 3.33}, Unit::Pressure::Kilopascal);
  const Traction second({1.11, -2.22, 3.330001}, Unit::Pressure::Kilopascal);
  const Traction third({1.11, 2.22, 3.33}, Unit::Pressure::Kilopascal);
  const std::hash<Traction> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Traction, JSON) {
  EXPECT_EQ(Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal).JSON(),
            "{\"value\":{\"x\":1.110000000000000,\"y\":-2.220000000000000,"
            "\"z\":3.330000000000000},\"unit\":\"Pa\"}");
  EXPECT_EQ(Traction({0.0, -2.22, 0.0}, Unit::Pressure::Kilopascal)
                .JSON(Unit::Pressure::Kilopascal),
            "{\"value\":{\"x\":0,\"y\":-2.220000000000000,\"z\":0},\"unit\":"
            "\"kPa\"}");
}

TEST(Traction, Magnitude) {
  EXPECT_EQ(Traction({2.0, -3.0, 6.0}, Unit::Pressure::Pascal).Magnitude(),
            StaticPressure(-7.0, Unit::Pressure::Pascal));
}

TEST(Traction, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal)),
            Direction(1.11, -2.22, 3.33));

  EXPECT_EQ(Angle(Traction({0.0, -2.22, 0.0}, Unit::Pressure::Pascal),
                  Traction({0.0, 0.0, 3.33}, Unit::Pressure::Pascal)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(StaticPressure(Traction({2.0, -3.0, 6.0}, Unit::Pressure::Pascal)),
            StaticPressure(-7.0, Unit::Pressure::Pascal));

  EXPECT_EQ(Traction(Force({2.0, -4.0, 6.0}, Unit::Force::Newton),
                     Area(2.0, Unit::Area::SquareMetre)),
            Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal));

  EXPECT_EQ(Force(Traction({1.0, -2.0, 3.0}, Unit::Pressure::Pascal),
                  Area(2.0, Unit::Area::SquareMetre)),
            Force({2.0, -4.0, 6.0}, Unit::Force::Newton));
}

TEST(Traction, MoveAssignmentOperator) {
  Traction first({1.11, -2.22, 3.33}, Unit::Pressure::Pascal);
  Traction second = Traction::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal));
}

TEST(Traction, MoveConstructor) {
  Traction first({1.11, -2.22, 3.33}, Unit::Pressure::Pascal);
  Traction second{std::move(first)};
  EXPECT_EQ(second, Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal));
}

TEST(Traction, MutableValue) {
  Traction quantity({1.11, -2.22, 3.33}, Unit::Pressure::Pascal);
  Value::Vector& value = quantity.MutableValue();
  value = Value::Vector{-4.44, 5.55, -6.66};
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(Traction, Print) {
  EXPECT_EQ(Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal).Print(),
            "(1.110000000000000, -2.220000000000000, 3.330000000000000) Pa");
  EXPECT_EQ(Traction({0.0, -2.22, 0.0}, Unit::Pressure::Kilopascal)
                .Print(Unit::Pressure::Kilopascal),
            "(0, -2.220000000000000, 0) kPa");
}

TEST(Traction, SetValue) {
  Traction quantity({1.11, -2.22, 3.33}, Unit::Pressure::Pascal);
  quantity.SetValue({-4.44, 5.55, -6.66});
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(Traction, SizeOf) {
  EXPECT_EQ(sizeof(Traction{}), 3 * sizeof(double));
}

TEST(Traction, StandardConstructor) {
  EXPECT_NO_THROW(Traction({1.11, -2.22, 3.33}, Unit::Pressure::Kilopascal));
}

TEST(Traction, StaticValue) {
  constexpr Traction quantity =
      Traction::Create<Unit::Pressure::Kilopascal>(1.11, -2.22, 3.33);
  constexpr Value::Vector value =
      quantity.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, Value::Vector(1.11, -2.22, 3.33));
}

TEST(Traction, Stream) {
  std::ostringstream stream;
  stream << Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(),
            Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal).Print());
}

TEST(Traction, Unit) {
  EXPECT_EQ(Traction::Unit(), Standard<Unit::Pressure>);
}

TEST(Traction, Value) {
  EXPECT_EQ(Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal).Value(),
            Value::Vector(1.11, -2.22, 3.33));
  EXPECT_EQ(Traction({1.11, -2.22, 3.33}, Unit::Pressure::Kilopascal)
                .Value(Unit::Pressure::Kilopascal),
            Value::Vector(1.11, -2.22, 3.33));
}

TEST(Traction, XML) {
  EXPECT_EQ(Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal).XML(),
            "<value><x>1.110000000000000</x><y>-2.220000000000000</"
            "y><z>3.330000000000000</z></value><unit>Pa</unit>");
  EXPECT_EQ(Traction({0.0, -2.22, 0.0}, Unit::Pressure::Kilopascal)
                .XML(Unit::Pressure::Kilopascal),
            "<value><x>0</x><y>-2.220000000000000</y><z>0</z></"
            "value><unit>kPa</unit>");
}

TEST(Traction, YAML) {
  EXPECT_EQ(Traction({1.11, -2.22, 3.33}, Unit::Pressure::Pascal).YAML(),
            "{value:{x:1.110000000000000,y:-2.220000000000000,z:3."
            "330000000000000},unit:\"Pa\"}");
  EXPECT_EQ(Traction({0.0, -2.22, 0.0}, Unit::Pressure::Kilopascal)
                .YAML(Unit::Pressure::Kilopascal),
            "{value:{x:0,y:-2.220000000000000,z:0},unit:\"kPa\"}");
}

TEST(Traction, Zero) {
  EXPECT_EQ(
      Traction::Zero(), Traction({0.0, 0.0, 0.0}, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
