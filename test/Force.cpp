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

#include "../include/PhQ/Force.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Force, Angle) {
  EXPECT_EQ(Force({0.0, -2.22, 0.0}, Unit::Force::Newton)
                .Angle(Force({0.0, 0.0, 3.33}, Unit::Force::Newton)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Force, ArithmeticAddition) {
  EXPECT_EQ(Force({1.0, -2.0, 3.0}, Unit::Force::Newton)
                + Force({2.0, -4.0, 6.0}, Unit::Force::Newton),
            Force({3.0, -6.0, 9.0}, Unit::Force::Newton));

  Force quantity({1.0, -2.0, 3.0}, Unit::Force::Newton);
  quantity += Force({2.0, -4.0, 6.0}, Unit::Force::Newton);
  EXPECT_EQ(quantity, Force({3.0, -6.0, 9.0}, Unit::Force::Newton));
}

TEST(Force, ArithmeticDivision) {
  EXPECT_EQ(Force({2.0, -4.0, 6.0}, Unit::Force::Newton) / 2.0,
            Force({1.0, -2.0, 3.0}, Unit::Force::Newton));

  Force quantity({2.0, -4.0, 6.0}, Unit::Force::Newton);
  quantity /= 2.0;
  EXPECT_EQ(quantity, Force({1.0, -2.0, 3.0}, Unit::Force::Newton));
}

TEST(Force, ArithmeticMultiplication) {
  EXPECT_EQ(Force({1.0, -2.0, 3.0}, Unit::Force::Newton) * 2.0,
            Force({2.0, -4.0, 6.0}, Unit::Force::Newton));

  EXPECT_EQ(2.0 * Force({1.0, -2.0, 3.0}, Unit::Force::Newton),
            Force({2.0, -4.0, 6.0}, Unit::Force::Newton));

  EXPECT_EQ(
      Direction(2.0, -3.0, 6.0) * ForceMagnitude(7.0, Unit::Force::Newton),
      Force({2.0, -3.0, 6.0}, Unit::Force::Newton));

  EXPECT_EQ(
      ForceMagnitude(7.0, Unit::Force::Newton) * Direction(2.0, -3.0, 6.0),
      Force({2.0, -3.0, 6.0}, Unit::Force::Newton));

  Force quantity({1.0, -2.0, 3.0}, Unit::Force::Newton);
  quantity *= 2.0;
  EXPECT_EQ(quantity, Force({2.0, -4.0, 6.0}, Unit::Force::Newton));
}

TEST(Force, ArithmeticSubtraction) {
  EXPECT_EQ(Force({3.0, -6.0, 9.0}, Unit::Force::Newton)
                - Force({2.0, -4.0, 6.0}, Unit::Force::Newton),
            Force({1.0, -2.0, 3.0}, Unit::Force::Newton));

  Force quantity({3.0, -6.0, 9.0}, Unit::Force::Newton);
  quantity -= Force({2.0, -4.0, 6.0}, Unit::Force::Newton);
  EXPECT_EQ(quantity, Force({1.0, -2.0, 3.0}, Unit::Force::Newton));
}

TEST(Force, Comparisons) {
  const Force first({1.11, -2.22, 3.33}, Unit::Force::Newton);
  const Force second({1.11, -2.22, 3.330001}, Unit::Force::Newton);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Force, CopyAssignment) {
  const Force first({1.11, -2.22, 3.33}, Unit::Force::Newton);
  Force second = Force::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Force, CopyConstructor) {
  const Force first({1.11, -2.22, 3.33}, Unit::Force::Newton);
  const Force second{first};
  EXPECT_EQ(second, first);
}

TEST(Force, Create) {
  constexpr Force quantity =
      Force::Create<Unit::Force::Newton>({1.11, -2.22, 3.33});
  EXPECT_EQ(quantity, Force({1.11, -2.22, 3.33}, Unit::Force::Newton));
}

TEST(Force, DefaultConstructor) {
  EXPECT_NO_THROW(Force{});
}

TEST(Force, Dimensions) {
  EXPECT_EQ(Force::Dimensions(), RelatedDimensions<Unit::Force>);
}

TEST(Force, Hash) {
  const Force first({1.11, -2.22, 3.33}, Unit::Force::Pound);
  const Force second({1.11, -2.22, 3.330001}, Unit::Force::Pound);
  const Force third({1.11, 2.22, 3.33}, Unit::Force::Pound);
  const std::hash<Force> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Force, JSON) {
  EXPECT_EQ(Force({1.11, -2.22, 3.33}, Unit::Force::Newton).JSON(),
            "{\"value\":{\"x\":1.110000000000000,\"y\":-2.220000000000000,"
            "\"z\":3.330000000000000},\"unit\":\"N\"}");
  EXPECT_EQ(
      Force({0.0, -2.22, 0.0}, Unit::Force::Pound).JSON(Unit::Force::Pound),
      "{\"value\":{\"x\":0,\"y\":-2.220000000000000,\"z\":0},\"unit\":"
      "\"lbf\"}");
}

TEST(Force, Magnitude) {
  EXPECT_EQ(Force({2.0, -3.0, 6.0}, Unit::Force::Newton).Magnitude(),
            ForceMagnitude(7.0, Unit::Force::Newton));
}

TEST(Force, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(Force({1.11, -2.22, 3.33}, Unit::Force::Newton)),
            Direction(1.11, -2.22, 3.33));

  EXPECT_EQ(Angle(Force({0.0, -2.22, 0.0}, Unit::Force::Newton),
                  Force({0.0, 0.0, 3.33}, Unit::Force::Newton)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(ForceMagnitude(Force({2.0, -3.0, 6.0}, Unit::Force::Newton)),
            ForceMagnitude(7.0, Unit::Force::Newton));
}

TEST(Force, MoveAssignment) {
  const Force first({1.11, -2.22, 3.33}, Unit::Force::Newton);
  Force second({1.11, -2.22, 3.33}, Unit::Force::Newton);
  Force third = Force::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(Force, MoveConstructor) {
  const Force first({1.11, -2.22, 3.33}, Unit::Force::Newton);
  Force second({1.11, -2.22, 3.33}, Unit::Force::Newton);
  Force third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(Force, MutableValue) {
  Force quantity({1.11, -2.22, 3.33}, Unit::Force::Newton);
  Value::Vector& value = quantity.MutableValue();
  value = Value::Vector{-4.44, 5.55, -6.66};
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(Force, Print) {
  EXPECT_EQ(Force({1.11, -2.22, 3.33}, Unit::Force::Newton).Print(),
            "(1.110000000000000, -2.220000000000000, 3.330000000000000) N");
  EXPECT_EQ(
      Force({0.0, -2.22, 0.0}, Unit::Force::Pound).Print(Unit::Force::Pound),
      "(0, -2.220000000000000, 0) lbf");
}

TEST(Force, SetValue) {
  Force quantity({1.11, -2.22, 3.33}, Unit::Force::Newton);
  quantity.SetValue({-4.44, 5.55, -6.66});
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(Force, SizeOf) {
  EXPECT_EQ(sizeof(Force{}), 3 * sizeof(double));
}

TEST(Force, StandardConstructor) {
  EXPECT_NO_THROW(Force({1.11, -2.22, 3.33}, Unit::Force::Pound));
}

TEST(Force, StaticValue) {
  constexpr Force quantity =
      Force::Create<Unit::Force::Pound>({1.11, -2.22, 3.33});
  constexpr Value::Vector value = quantity.StaticValue<Unit::Force::Pound>();
  EXPECT_EQ(value, Value::Vector(1.11, -2.22, 3.33));
}

TEST(Force, Stream) {
  std::ostringstream stream;
  stream << Force({1.11, -2.22, 3.33}, Unit::Force::Newton);
  EXPECT_EQ(
      stream.str(), Force({1.11, -2.22, 3.33}, Unit::Force::Newton).Print());
}

TEST(Force, Unit) {
  EXPECT_EQ(Force::Unit(), Standard<Unit::Force>);
}

TEST(Force, Value) {
  EXPECT_EQ(Force({1.11, -2.22, 3.33}, Unit::Force::Newton).Value(),
            Value::Vector(1.11, -2.22, 3.33));
  EXPECT_EQ(
      Force({1.11, -2.22, 3.33}, Unit::Force::Pound).Value(Unit::Force::Pound),
      Value::Vector(1.11, -2.22, 3.33));
}

TEST(Force, XML) {
  EXPECT_EQ(Force({1.11, -2.22, 3.33}, Unit::Force::Newton).XML(),
            "<value><x>1.110000000000000</x><y>-2.220000000000000</"
            "y><z>3.330000000000000</z></value><unit>N</unit>");
  EXPECT_EQ(
      Force({0.0, -2.22, 0.0}, Unit::Force::Pound).XML(Unit::Force::Pound),
      "<value><x>0</x><y>-2.220000000000000</y><z>0</z></value><unit>lbf</"
      "unit>");
}

TEST(Force, YAML) {
  EXPECT_EQ(Force({1.11, -2.22, 3.33}, Unit::Force::Newton).YAML(),
            "{value:{x:1.110000000000000,y:-2.220000000000000,z:3."
            "330000000000000},unit:\"N\"}");
  EXPECT_EQ(
      Force({0.0, -2.22, 0.0}, Unit::Force::Pound).YAML(Unit::Force::Pound),
      "{value:{x:0,y:-2.220000000000000,z:0},unit:\"lbf\"}");
}

TEST(Force, Zero) {
  EXPECT_EQ(Force::Zero(), Force({0.0, 0.0, 0.0}, Unit::Force::Newton));
}

}  // namespace

}  // namespace PhQ
