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

#include "../include/PhQ/Velocity.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Velocity, Angle) {
  EXPECT_EQ(Velocity({0.0, -2.22, 0.0}, Unit::Speed::MetrePerSecond)
                .Angle(Velocity({0.0, 0.0, 3.33}, Unit::Speed::MetrePerSecond)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Velocity, ArithmeticAddition) {
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond)
                + Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond),
            Velocity({3.0, -6.0, 9.0}, Unit::Speed::MetrePerSecond));

  Velocity quantity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  quantity += Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(quantity, Velocity({3.0, -6.0, 9.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, ArithmeticDivision) {
  EXPECT_EQ(Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond) / 2.0,
            Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));

  Velocity quantity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond);
  quantity /= 2.0;
  EXPECT_EQ(quantity, Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, ArithmeticMultiplication) {
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond) * 2.0,
            Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(2.0 * Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond),
            Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Direction(2.0, -3.0, 6.0) * Speed(7.0, Unit::Speed::MetrePerSecond),
            Velocity({2.0, -3.0, 6.0}, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Speed(7.0, Unit::Speed::MetrePerSecond) * Direction(2.0, -3.0, 6.0),
            Velocity({2.0, -3.0, 6.0}, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond)
                * Time(2.0, Unit::Time::Second),
            Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));

  EXPECT_EQ(Time(2.0, Unit::Time::Second)
                * Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond),
            Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));

  Velocity quantity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  quantity *= 2.0;
  EXPECT_EQ(quantity, Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, ArithmeticSubtraction) {
  EXPECT_EQ(Velocity({3.0, -6.0, 9.0}, Unit::Speed::MetrePerSecond)
                - Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond),
            Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));

  Velocity quantity({3.0, -6.0, 9.0}, Unit::Speed::MetrePerSecond);
  quantity -= Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(quantity, Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, Comparisons) {
  const Velocity first({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond);
  const Velocity second({1.11, -2.22, 3.330001}, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Velocity, CopyAssignment) {
  const Velocity first({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond);
  Velocity second = Velocity::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Velocity, CopyConstructor) {
  const Velocity first({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond);
  const Velocity second{first};
  EXPECT_EQ(second, first);
}

TEST(Velocity, Create) {
  constexpr Velocity quantity =
      Velocity::Create<Unit::Speed::MetrePerSecond>({1.11, -2.22, 3.33});
  EXPECT_EQ(
      quantity, Velocity({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, DefaultConstructor) {
  EXPECT_NO_THROW(Velocity{});
}

TEST(Velocity, Dimensions) {
  EXPECT_EQ(Velocity::Dimensions(), RelatedDimensions<Unit::Speed>);
}

TEST(Velocity, Hash) {
  const Velocity first({1.11, -2.22, 3.33}, Unit::Speed::MillimetrePerSecond);
  const Velocity second(
      {1.11, -2.22, 3.330001}, Unit::Speed::MillimetrePerSecond);
  const Velocity third({1.11, 2.22, 3.33}, Unit::Speed::MillimetrePerSecond);
  const std::hash<Velocity> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Velocity, JSON) {
  EXPECT_EQ(Velocity({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond).JSON(),
            "{\"value\":{\"x\":1.110000000000000,\"y\":-2.220000000000000,"
            "\"z\":3.330000000000000},\"unit\":\"m/s\"}");
  EXPECT_EQ(Velocity({0.0, -2.22, 0.0}, Unit::Speed::MillimetrePerSecond)
                .JSON(Unit::Speed::MillimetrePerSecond),
            "{\"value\":{\"x\":0,\"y\":-2.220000000000000,\"z\":0},\"unit\":"
            "\"mm/s\"}");
}

TEST(Velocity, Magnitude) {
  EXPECT_EQ(Velocity({2.0, -3.0, 6.0}, Unit::Speed::MetrePerSecond).Magnitude(),
            Speed(7.0, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, MiscellaneousConstructors) {
  EXPECT_EQ(
      Direction(Velocity({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond)),
      Direction(1.11, -2.22, 3.33));

  EXPECT_EQ(Angle(Velocity({0.0, -2.22, 0.0}, Unit::Speed::MetrePerSecond),
                  Velocity({0.0, 0.0, 3.33}, Unit::Speed::MetrePerSecond)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(Speed(Velocity({2.0, -3.0, 6.0}, Unit::Speed::MetrePerSecond)),
            Speed(7.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(
      Displacement(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond),
                   Time(2.0, Unit::Time::Second)),
      Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));

  EXPECT_EQ(
      Displacement(Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond),
                   Frequency(2.0, Unit::Frequency::Hertz)),
      Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Velocity, MoveAssignment) {
  const Velocity first({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond);
  Velocity second({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond);
  Velocity third = Velocity::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(Velocity, MoveConstructor) {
  const Velocity first({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond);
  Velocity second({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond);
  Velocity third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(Velocity, MutableValue) {
  Velocity quantity({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond);
  Value::Vector& value = quantity.MutableValue();
  value = Value::Vector{-4.44, 2.225, -6.66};
  EXPECT_EQ(value, Value::Vector(-4.44, 2.225, -6.66));
}

TEST(Velocity, Print) {
  EXPECT_EQ(Velocity({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond).Print(),
            "(1.110000000000000, -2.220000000000000, 3.330000000000000) m/s");
  EXPECT_EQ(Velocity({0.0, -2.22, 0.0}, Unit::Speed::MillimetrePerSecond)
                .Print(Unit::Speed::MillimetrePerSecond),
            "(0, -2.220000000000000, 0) mm/s");
}

TEST(Velocity, SetValue) {
  Velocity quantity({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond);
  quantity.SetValue({-4.44, 5.55, -6.66});
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(Velocity, SizeOf) {
  EXPECT_EQ(sizeof(Velocity{}), 3 * sizeof(double));
}

TEST(Velocity, StandardConstructor) {
  EXPECT_NO_THROW(
      Velocity({1.11, -2.22, 3.33}, Unit::Speed::MillimetrePerSecond));
}

TEST(Velocity, StaticValue) {
  constexpr Velocity quantity =
      Velocity::Create<Unit::Speed::MillimetrePerSecond>({1.11, -2.22, 3.33});
  constexpr Value::Vector value =
      quantity.StaticValue<Unit::Speed::MillimetrePerSecond>();
  EXPECT_EQ(value, Value::Vector(1.11, -2.22, 3.33));
}

TEST(Velocity, Stream) {
  const Velocity quantity({1.11, 2.22, 4.44}, Unit::Speed::MetrePerSecond);
  std::ostringstream stream;
  stream << quantity;
  EXPECT_EQ(stream.str(), quantity.Print());
}

TEST(Velocity, Unit) {
  EXPECT_EQ(Velocity::Unit(), Standard<Unit::Speed>);
}

TEST(Velocity, Value) {
  EXPECT_EQ(Velocity({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond).Value(),
            Value::Vector(1.11, -2.22, 3.33));
  EXPECT_EQ(Velocity({1.11, -2.22, 3.33}, Unit::Speed::MillimetrePerSecond)
                .Value(Unit::Speed::MillimetrePerSecond),
            Value::Vector(1.11, -2.22, 3.33));
}

TEST(Velocity, XML) {
  EXPECT_EQ(Velocity({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond).XML(),
            "<value><x>1.110000000000000</x><y>-2.220000000000000</"
            "y><z>3.330000000000000</z></value><unit>m/s</unit>");
  EXPECT_EQ(Velocity({0.0, -2.22, 0.0}, Unit::Speed::MillimetrePerSecond)
                .XML(Unit::Speed::MillimetrePerSecond),
            "<value><x>0</x><y>-2.220000000000000</y><z>0</z></value><unit>mm/"
            "s</unit>");
}

TEST(Velocity, YAML) {
  EXPECT_EQ(Velocity({1.11, -2.22, 3.33}, Unit::Speed::MetrePerSecond).YAML(),
            "{value:{x:1.110000000000000,y:-2.220000000000000,z:3."
            "330000000000000},unit:\"m/s\"}");
  EXPECT_EQ(Velocity({0.0, -2.22, 0.0}, Unit::Speed::MillimetrePerSecond)
                .YAML(Unit::Speed::MillimetrePerSecond),
            "{value:{x:0,y:-2.220000000000000,z:0},unit:\"mm/s\"}");
}

TEST(Velocity, Zero) {
  EXPECT_EQ(
      Velocity::Zero(), Velocity({0.0, 0.0, 0.0}, Unit::Speed::MetrePerSecond));
}

}  // namespace

}  // namespace PhQ
