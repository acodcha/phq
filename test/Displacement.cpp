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

#include "../include/PhQ/Displacement.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Displacement, Angle) {
  EXPECT_EQ(Displacement({0.0, -2.22, 0.0}, Unit::Length::Metre)
                .Angle(Displacement({0.0, 0.0, 3.33}, Unit::Length::Metre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Displacement, ArithmeticAddition) {
  EXPECT_EQ(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre)
                + Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre),
            Displacement({3.0, -6.0, 9.0}, Unit::Length::Metre));

  Displacement quantity({1.0, -2.0, 3.0}, Unit::Length::Metre);
  quantity += Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre);
  EXPECT_EQ(quantity, Displacement({3.0, -6.0, 9.0}, Unit::Length::Metre));
}

TEST(Displacement, ArithmeticDivision) {
  EXPECT_EQ(Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre) / 2.0,
            Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));

  Displacement quantity({2.0, -4.0, 6.0}, Unit::Length::Metre);
  quantity /= 2.0;
  EXPECT_EQ(quantity, Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Displacement, ArithmeticMultiplication) {
  EXPECT_EQ(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre) * 2.0,
            Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));

  EXPECT_EQ(2.0 * Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre),
            Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));

  Displacement quantity({1.0, -2.0, 3.0}, Unit::Length::Metre);
  quantity *= 2.0;
  EXPECT_EQ(quantity, Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));
}

TEST(Displacement, ArithmeticSubtraction) {
  EXPECT_EQ(Displacement({3.0, -6.0, 9.0}, Unit::Length::Metre)
                - Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre),
            Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));

  Displacement quantity({3.0, -6.0, 9.0}, Unit::Length::Metre);
  quantity -= Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre);
  EXPECT_EQ(quantity, Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Displacement, Comparisons) {
  const Displacement first({1.11, -2.22, 3.33}, Unit::Length::Metre);
  const Displacement second({1.11, -2.22, 3.330001}, Unit::Length::Metre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Displacement, CopyAssignment) {
  const Displacement first({1.11, -2.22, 3.33}, Unit::Length::Metre);
  Displacement second = Displacement::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Displacement, CopyConstructor) {
  const Displacement first({1.11, -2.22, 3.33}, Unit::Length::Metre);
  const Displacement second{first};
  EXPECT_EQ(second, first);
}

TEST(Displacement, Create) {
  constexpr Displacement quantity =
      Displacement::Create<Unit::Length::Metre>({1.11, -2.22, 3.33});
  EXPECT_EQ(quantity, Displacement({1.11, -2.22, 3.33}, Unit::Length::Metre));
}

TEST(Displacement, DefaultConstructor) {
  EXPECT_NO_THROW(Displacement{});
}

TEST(Displacement, Dimensions) {
  EXPECT_EQ(Displacement::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(Displacement, Hash) {
  const Displacement first({1.11, -2.22, 3.33}, Unit::Length::Millimetre);
  const Displacement second({1.11, -2.22, 3.330001}, Unit::Length::Millimetre);
  const Displacement third({1.11, 2.22, 3.33}, Unit::Length::Millimetre);
  const std::hash<Displacement> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Displacement, JSON) {
  EXPECT_EQ(Displacement({1.11, -2.22, 3.33}, Unit::Length::Metre).JSON(),
            "{\"value\":{\"x\":1.110000000000000,\"y\":-2.220000000000000,"
            "\"z\":"
            "3.330000000000000},\"unit\":\"m\"}");
  EXPECT_EQ(Displacement({0.0, -2.22, 0.0}, Unit::Length::Millimetre)
                .JSON(Unit::Length::Millimetre),
            "{\"value\":{\"x\":0,\"y\":-2.220000000000000,\"z\":0},\"unit\":"
            "\"mm\"}");
}

TEST(Displacement, Magnitude) {
  EXPECT_EQ(Displacement({2.0, -3.0, 6.0}, Unit::Length::Metre).Magnitude(),
            Length(7.0, Unit::Length::Metre));
}

TEST(Displacement, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(Displacement({1.11, -2.22, 3.33}, Unit::Length::Metre)),
            Direction(1.11, -2.22, 3.33));

  EXPECT_EQ(Angle(Displacement({0.0, -2.22, 0.0}, Unit::Length::Metre),
                  Displacement({0.0, 0.0, 3.33}, Unit::Length::Metre)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(Length(Displacement({2.0, -3.0, 6.0}, Unit::Length::Metre)),
            Length(7.0, Unit::Length::Metre));
}

TEST(Displacement, MoveAssignment) {
  const Displacement first({1.11, -2.22, 3.33}, Unit::Length::Metre);
  Displacement second({1.11, -2.22, 3.33}, Unit::Length::Metre);
  Displacement third = Displacement::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(Displacement, MoveConstructor) {
  const Displacement first({1.11, -2.22, 3.33}, Unit::Length::Metre);
  Displacement second({1.11, -2.22, 3.33}, Unit::Length::Metre);
  Displacement third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(Displacement, MutableValue) {
  Displacement quantity({1.11, -2.22, 3.33}, Unit::Length::Metre);
  Value::Vector& value = quantity.MutableValue();
  value = Value::Vector{-4.44, 5.55, -6.66};
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(Displacement, Print) {
  EXPECT_EQ(Displacement({1.11, -2.22, 3.33}, Unit::Length::Metre).Print(),
            "(1.110000000000000, -2.220000000000000, 3.330000000000000) m");
  EXPECT_EQ(Displacement({0.0, -2.22, 0.0}, Unit::Length::Millimetre)
                .Print(Unit::Length::Millimetre),
            "(0, -2.220000000000000, 0) mm");
}

TEST(Displacement, SetValue) {
  Displacement quantity({1.11, -2.22, 3.33}, Unit::Length::Metre);
  quantity.SetValue({-4.44, 5.55, -6.66});
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(Displacement, SizeOf) {
  EXPECT_EQ(sizeof(Displacement{}), 3 * sizeof(double));
}

TEST(Displacement, StandardConstructor) {
  EXPECT_NO_THROW(Displacement({1.11, -2.22, 3.33}, Unit::Length::Millimetre));
}

TEST(Displacement, StaticValue) {
  constexpr Displacement quantity =
      Displacement::Create<Unit::Length::Millimetre>({1.11, -2.22, 3.33});
  constexpr Value::Vector value =
      quantity.StaticValue<Unit::Length::Millimetre>();
  EXPECT_EQ(value, Value::Vector(1.11, -2.22, 3.33));
}

TEST(Displacement, Stream) {
  const Displacement quantity({1.11, 2.22, 4.44}, Unit::Length::Metre);
  std::ostringstream stream;
  stream << quantity;
  EXPECT_EQ(stream.str(), quantity.Print());
}

TEST(Displacement, Unit) {
  EXPECT_EQ(Displacement::Unit(), Standard<Unit::Length>);
}

TEST(Displacement, Value) {
  EXPECT_EQ(Displacement({1.11, -2.22, 3.33}, Unit::Length::Metre).Value(),
            Value::Vector(1.11, -2.22, 3.33));
  EXPECT_EQ(Displacement({1.11, -2.22, 3.33}, Unit::Length::Millimetre)
                .Value(Unit::Length::Millimetre),
            Value::Vector(1.11, -2.22, 3.33));
}

TEST(Displacement, XML) {
  EXPECT_EQ(Displacement({1.11, -2.22, 3.33}, Unit::Length::Metre).XML(),
            "<value><x>1.110000000000000</x><y>-2.220000000000000</"
            "y><z>3.330000000000000</z></value><unit>m</unit>");
  EXPECT_EQ(Displacement({0.0, -2.22, 0.0}, Unit::Length::Millimetre)
                .XML(Unit::Length::Millimetre),
            "<value><x>0</x><y>-2.220000000000000</y><z>0</z></value><unit>mm</"
            "unit>");
}

TEST(Displacement, YAML) {
  EXPECT_EQ(Displacement({1.11, -2.22, 3.33}, Unit::Length::Metre).YAML(),
            "{value:{x:1.110000000000000,y:-2.220000000000000,z:3."
            "330000000000000},unit:\"m\"}");
  EXPECT_EQ(Displacement({0.0, -2.22, 0.0}, Unit::Length::Millimetre)
                .YAML(Unit::Length::Millimetre),
            "{value:{x:0,y:-2.220000000000000,z:0},unit:\"mm\"}");
}

TEST(Displacement, Zero) {
  EXPECT_EQ(
      Displacement::Zero(), Displacement({0.0, 0.0, 0.0}, Unit::Length::Metre));
}

}  // namespace

}  // namespace PhQ
