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

#include "../include/PhQ/Acceleration.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Acceleration, Angle) {
  EXPECT_EQ(
      Acceleration({0.0, -2.22, 0.0}, Unit::Acceleration::MetrePerSquareSecond)
          .Angle(Acceleration(
              {0.0, 0.0, 3.33}, Unit::Acceleration::MetrePerSquareSecond)),
      Angle(90.0, Unit::Angle::Degree));
}

TEST(Acceleration, ArithmeticAddition) {
  EXPECT_EQ(
      Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond)
          + Acceleration(
              {2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond),
      Acceleration({3.0, -6.0, 9.0}, Unit::Acceleration::MetrePerSquareSecond));

  Acceleration quantity(
      {1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond);
  quantity +=
      Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(quantity, Acceleration({3.0, -6.0, 9.0},
                                   Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, ArithmeticDivision) {
  EXPECT_EQ(
      Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond)
          / 2.0,
      Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(
      Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond)
          / Frequency(2.0, Unit::Frequency::Hertz),
      Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(
      Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond)
          / Time(2.0, Unit::Time::Second),
      Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));

  Acceleration quantity(
      {2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond);
  quantity /= 2.0;
  EXPECT_EQ(quantity, Acceleration({1.0, -2.0, 3.0},
                                   Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, ArithmeticMultiplication) {
  EXPECT_EQ(
      Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond)
          * 2.0,
      Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(
      2.0
          * Acceleration(
              {1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond),
      Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(
      Direction(2.0, -3.0, 6.0)
          * AccelerationMagnitude(
              7.0, Unit::Acceleration::MetrePerSquareSecond),
      Acceleration({2.0, -3.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(
      AccelerationMagnitude(7.0, Unit::Acceleration::MetrePerSquareSecond)
          * Direction(2.0, -3.0, 6.0),
      Acceleration({2.0, -3.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(
      Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond)
          * Time(2.0, Unit::Time::Second),
      Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Time(2.0, Unit::Time::Second)
                * Acceleration(
                    {1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond),
            Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(
      Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond)
          * Frequency(2.0, Unit::Frequency::Hertz),
      Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond));

  Acceleration quantity(
      {1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond);
  quantity *= 2.0;
  EXPECT_EQ(quantity, Acceleration({2.0, -4.0, 6.0},
                                   Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, ArithmeticSubtraction) {
  EXPECT_EQ(
      Acceleration({3.0, -6.0, 9.0}, Unit::Acceleration::MetrePerSquareSecond)
          - Acceleration(
              {2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond),
      Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));

  Acceleration quantity(
      {3.0, -6.0, 9.0}, Unit::Acceleration::MetrePerSquareSecond);
  quantity -=
      Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(quantity, Acceleration({1.0, -2.0, 3.0},
                                   Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, Comparisons) {
  const Acceleration first(
      {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond);
  const Acceleration second(
      {1.11, -2.22, 3.330001}, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Acceleration, CopyAssignment) {
  const Acceleration first(
      {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond);
  Acceleration second = Acceleration::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Acceleration, CopyConstructor) {
  const Acceleration first(
      {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond);
  const Acceleration second{first};
  EXPECT_EQ(second, first);
}

TEST(Acceleration, Create) {
  constexpr Acceleration quantity =
      Acceleration::Create<Unit::Acceleration::MetrePerSquareSecond>(
          {1.11, -2.22, 3.33});
  EXPECT_EQ(quantity, Acceleration({1.11, -2.22, 3.33},
                                   Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, DefaultConstructor) {
  EXPECT_NO_THROW(Acceleration{});
}

TEST(Acceleration, Dimensions) {
  EXPECT_EQ(Acceleration::Dimensions(), RelatedDimensions<Unit::Acceleration>);
}

TEST(Acceleration, Hash) {
  const Acceleration first(
      {1.11, -2.22, 3.33}, Unit::Acceleration::MillimetrePerSquareSecond);
  const Acceleration second(
      {1.11, -2.22, 3.330001}, Unit::Acceleration::MillimetrePerSquareSecond);
  const Acceleration third(
      {1.11, 2.22, 3.33}, Unit::Acceleration::MillimetrePerSquareSecond);
  const std::hash<Acceleration> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Acceleration, JSON) {
  EXPECT_EQ(Acceleration(
                {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond)
                .JSON(),
            "{\"value\":{\"x\":1.110000000000000,\"y\":-2.220000000000000,"
            "\"z\":3.330000000000000},\"unit\":\"m/s^2\"}");
  EXPECT_EQ(Acceleration({0.0, -2.22, 0.0},
                         Unit::Acceleration::MillimetrePerSquareSecond)
                .JSON(Unit::Acceleration::MillimetrePerSquareSecond),
            "{\"value\":{\"x\":0,\"y\":-2.220000000000000,\"z\":0},\"unit\":"
            "\"mm/s^2\"}");
}

TEST(Acceleration, Magnitude) {
  EXPECT_EQ(
      Acceleration({2.0, -3.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond)
          .Magnitude(),
      AccelerationMagnitude(7.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(Acceleration(
                {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond)),
            Direction(1.11, -2.22, 3.33));

  EXPECT_EQ(Angle(Acceleration({0.0, -2.22, 0.0},
                               Unit::Acceleration::MetrePerSquareSecond),
                  Acceleration({0.0, 0.0, 3.33},
                               Unit::Acceleration::MetrePerSquareSecond)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(
      AccelerationMagnitude(Acceleration(
          {2.0, -3.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond)),
      AccelerationMagnitude(7.0, Unit::Acceleration::MetrePerSquareSecond));

  EXPECT_EQ(Velocity(Acceleration({1.0, -2.0, 3.0},
                                  Unit::Acceleration::MetrePerSquareSecond),
                     Time(2.0, Unit::Time::Second)),
            Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Velocity(Acceleration({2.0, -4.0, 6.0},
                                  Unit::Acceleration::MetrePerSquareSecond),
                     Frequency(2.0, Unit::Frequency::Hertz)),
            Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
}

TEST(Acceleration, MoveAssignment) {
  Acceleration first(
      {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond);
  Acceleration second = Acceleration::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Acceleration({1.11, -2.22, 3.33},
                                 Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, MoveConstructor) {
  Acceleration first(
      {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond);
  Acceleration second{std::move(first)};
  EXPECT_EQ(second, Acceleration({1.11, -2.22, 3.33},
                                 Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, MutableValue) {
  Acceleration quantity(
      {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond);
  Value::Vector& value = quantity.MutableValue();
  value = Value::Vector{-4.44, 5.55, -6.66};
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(Acceleration, Print) {
  EXPECT_EQ(Acceleration(
                {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond)
                .Print(),
            "(1.110000000000000, -2.220000000000000, 3.330000000000000) m/s^2");
  EXPECT_EQ(Acceleration({0.0, -2.22, 0.0},
                         Unit::Acceleration::MillimetrePerSquareSecond)
                .Print(Unit::Acceleration::MillimetrePerSquareSecond),
            "(0, -2.220000000000000, 0) mm/s^2");
}

TEST(Acceleration, SetValue) {
  Acceleration quantity(
      {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond);
  quantity.SetValue({-4.44, 5.55, -6.66});
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(Acceleration, SizeOf) {
  EXPECT_EQ(sizeof(Acceleration{}), 3 * sizeof(double));
}

TEST(Acceleration, StandardConstructor) {
  EXPECT_NO_THROW(Acceleration(
      {1.11, -2.22, 3.33}, Unit::Acceleration::MillimetrePerSquareSecond));
}

TEST(Acceleration, StaticValue) {
  constexpr Acceleration quantity =
      Acceleration::Create<Unit::Acceleration::MillimetrePerSquareSecond>(
          {1.11, -2.22, 3.33});
  constexpr Value::Vector value =
      quantity.StaticValue<Unit::Acceleration::MillimetrePerSquareSecond>();
  EXPECT_EQ(value, Value::Vector(1.11, -2.22, 3.33));
}

TEST(Acceleration, Stream) {
  std::ostringstream stream;
  stream << Acceleration(
      {1.11, -2.22, 3.33}, Unit::Acceleration::MillimetrePerSquareSecond);
  EXPECT_EQ(stream.str(),
            Acceleration({1.11, -2.22, 3.33},
                         Unit::Acceleration::MillimetrePerSquareSecond)
                .Print());
}

TEST(Acceleration, Unit) {
  EXPECT_EQ(Acceleration::Unit(), Standard<Unit::Acceleration>);
}

TEST(Acceleration, Value) {
  EXPECT_EQ(Acceleration(
                {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond)
                .Value(),
            Value::Vector(1.11, -2.22, 3.33));
  EXPECT_EQ(Acceleration({1.11, -2.22, 3.33},
                         Unit::Acceleration::MillimetrePerSquareSecond)
                .Value(Unit::Acceleration::MillimetrePerSquareSecond),
            Value::Vector(1.11, -2.22, 3.33));
}

TEST(Acceleration, XML) {
  EXPECT_EQ(Acceleration(
                {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond)
                .XML(),
            "<value><x>1.110000000000000</x><y>-2.220000000000000</"
            "y><z>3.330000000000000</z></value><unit>m/s^2</unit>");
  EXPECT_EQ(Acceleration({0.0, -2.22, 0.0},
                         Unit::Acceleration::MillimetrePerSquareSecond)
                .XML(Unit::Acceleration::MillimetrePerSquareSecond),
            "<value><x>0</x><y>-2.220000000000000</y><z>0</z></value><unit>mm/"
            "s^2</unit>");
}

TEST(Acceleration, YAML) {
  EXPECT_EQ(Acceleration(
                {1.11, -2.22, 3.33}, Unit::Acceleration::MetrePerSquareSecond)
                .YAML(),
            "{value:{x:1.110000000000000,y:-2.220000000000000,z:3."
            "330000000000000},unit:\"m/s^2\"}");
  EXPECT_EQ(Acceleration({0.0, -2.22, 0.0},
                         Unit::Acceleration::MillimetrePerSquareSecond)
                .YAML(Unit::Acceleration::MillimetrePerSquareSecond),
            "{value:{x:0,y:-2.220000000000000,z:0},unit:\"mm/s^2\"}");
}

TEST(Acceleration, Zero) {
  EXPECT_EQ(
      Acceleration::Zero(),
      Acceleration({0.0, 0.0, 0.0}, Unit::Acceleration::MetrePerSquareSecond));
}

}  // namespace

}  // namespace PhQ
