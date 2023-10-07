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

#include "../include/PhQ/AngularSpeed.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(AngularSpeed, ArithmeticAddition) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond)
                + AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            AngularSpeed(3.0, Unit::AngularSpeed::RadianPerSecond));

  AngularSpeed quantity{1.0, Unit::AngularSpeed::RadianPerSecond};
  quantity += AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond);
  EXPECT_EQ(quantity, AngularSpeed(3.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, ArithmeticDivision) {
  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond) / 2.0,
            AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            4.0);

  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / Angle(2.0, Unit::Angle::Radian),
            Frequency(4.0, Unit::Frequency::Hertz));

  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            Angle(4.0, Unit::Angle::Radian));

  EXPECT_EQ(Angle(8.0, Unit::Angle::Radian) / Time(2.0, Unit::Time::Second),
            AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(Angle(8.0, Unit::Angle::Radian)
                / AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            Time(4.0, Unit::Time::Second));

  AngularSpeed quantity{8.0, Unit::AngularSpeed::RadianPerSecond};
  quantity /= 2.0;
  EXPECT_EQ(quantity, AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, ArithmeticMultiplication) {
  EXPECT_EQ(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond) * 2.0,
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(2.0 * AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(
      Angle(4.0, Unit::Angle::Radian) * Frequency(2.0, Unit::Frequency::Hertz),
      AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(
      Frequency(4.0, Unit::Frequency::Hertz) * Angle(2.0, Unit::Angle::Radian),
      AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  AngularSpeed quantity{4.0, Unit::AngularSpeed::RadianPerSecond};
  quantity *= 2.0;
  EXPECT_EQ(quantity, AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, ArithmeticSubtraction) {
  EXPECT_EQ(AngularSpeed(3.0, Unit::AngularSpeed::RadianPerSecond)
                - AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));

  AngularSpeed quantity{3.0, Unit::AngularSpeed::RadianPerSecond};
  quantity -= AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond);
  EXPECT_EQ(quantity, AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, Comparisons) {
  const AngularSpeed first{0.1, Unit::AngularSpeed::RadianPerSecond};
  const AngularSpeed second{0.2, Unit::AngularSpeed::RadianPerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(AngularSpeed, CopyAssignment) {
  const AngularSpeed first{1.11, Unit::AngularSpeed::RadianPerSecond};
  AngularSpeed second = AngularSpeed::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(AngularSpeed, CopyConstructor) {
  const AngularSpeed first{1.11, Unit::AngularSpeed::RadianPerSecond};
  const AngularSpeed second{first};
  EXPECT_EQ(second, first);
}

TEST(AngularSpeed, Create) {
  constexpr AngularSpeed quantity =
      AngularSpeed::Create<Unit::AngularSpeed::RadianPerSecond>(1.11);
  EXPECT_EQ(quantity, AngularSpeed(1.11, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, DefaultConstructor) {
  EXPECT_NO_THROW(AngularSpeed{});
}

TEST(AngularSpeed, Dimensions) {
  EXPECT_EQ(AngularSpeed::Dimensions(), RelatedDimensions<Unit::AngularSpeed>);
}

TEST(AngularSpeed, Hash) {
  const AngularSpeed first{1.11, Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed second{1.110001, Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed third{-1.11, Unit::AngularSpeed::DegreePerSecond};
  const std::hash<AngularSpeed> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(AngularSpeed, JSON) {
  EXPECT_EQ(AngularSpeed(1.11, Unit::AngularSpeed::RadianPerSecond).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"rad/s\"}");
  EXPECT_EQ(AngularSpeed(-2.22, Unit::AngularSpeed::DegreePerSecond)
                .JSON(Unit::AngularSpeed::DegreePerSecond),
            "{\"value\":-2.220000000000000,\"unit\":\"deg/s\"}");
}

TEST(AngularSpeed, MiscellaneousConstructors) {
  EXPECT_EQ(AngularSpeed(
                Angle(8.0, Unit::Angle::Radian), Time(2.0, Unit::Time::Second)),
            AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(AngularSpeed(Angle(4.0, Unit::Angle::Radian),
                         Frequency(2.0, Unit::Frequency::Hertz)),
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(Angle(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
                  Time(2.0, Unit::Time::Second)),
            Angle(8.0, Unit::Angle::Radian));

  EXPECT_EQ(Angle(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                  Frequency(2.0, Unit::Frequency::Hertz)),
            Angle(4.0, Unit::Angle::Radian));

  EXPECT_EQ(Time(Angle(8.0, Unit::Angle::Radian),
                 AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond)),
            Time(4.0, Unit::Time::Second));

  EXPECT_EQ(Frequency(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                      Angle(2.0, Unit::Angle::Radian)),
            Frequency(4.0, Unit::Frequency::Hertz));
}

TEST(AngularSpeed, MoveAssignment) {
  const AngularSpeed first{1.11, Unit::AngularSpeed::RadianPerSecond};
  AngularSpeed second{1.11, Unit::AngularSpeed::RadianPerSecond};
  AngularSpeed third = AngularSpeed::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(AngularSpeed, MoveConstructor) {
  const AngularSpeed first{1.11, Unit::AngularSpeed::RadianPerSecond};
  AngularSpeed second{1.11, Unit::AngularSpeed::RadianPerSecond};
  AngularSpeed third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(AngularSpeed, MutableValue) {
  AngularSpeed quantity{1.11, Unit::AngularSpeed::RadianPerSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(AngularSpeed, Print) {
  EXPECT_EQ(AngularSpeed(1.11, Unit::AngularSpeed::RadianPerSecond).Print(),
            "1.110000000000000 rad/s");
  EXPECT_EQ(AngularSpeed(-2.22, Unit::AngularSpeed::DegreePerSecond)
                .Print(Unit::AngularSpeed::DegreePerSecond),
            "-2.220000000000000 deg/s");
}

TEST(AngularSpeed, SetValue) {
  AngularSpeed quantity{1.11, Unit::AngularSpeed::RadianPerSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(AngularSpeed, SizeOf) {
  EXPECT_EQ(sizeof(AngularSpeed{}), sizeof(double));
}

TEST(AngularSpeed, StandardConstructor) {
  EXPECT_NO_THROW(AngularSpeed(1.11, Unit::AngularSpeed::DegreePerSecond));
}

TEST(AngularSpeed, StaticValue) {
  constexpr AngularSpeed quantity =
      AngularSpeed::Create<Unit::AngularSpeed::DegreePerSecond>(1.11);
  constexpr double value =
      quantity.StaticValue<Unit::AngularSpeed::DegreePerSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(AngularSpeed, Stream) {
  const AngularSpeed quantity{1.11, Unit::AngularSpeed::RadianPerSecond};
  std::ostringstream stream;
  stream << quantity;
  EXPECT_EQ(stream.str(), quantity.Print());
}

TEST(AngularSpeed, Unit) {
  EXPECT_EQ(AngularSpeed::Unit(), Standard<Unit::AngularSpeed>);
}

TEST(AngularSpeed, Value) {
  EXPECT_EQ(
      AngularSpeed(1.11, Unit::AngularSpeed::RadianPerSecond).Value(), 1.11);
  EXPECT_EQ(AngularSpeed(1.11, Unit::AngularSpeed::DegreePerSecond)
                .Value(Unit::AngularSpeed::DegreePerSecond),
            1.11);
}

TEST(AngularSpeed, XML) {
  EXPECT_EQ(AngularSpeed(1.11, Unit::AngularSpeed::RadianPerSecond).XML(),
            "<value>1.110000000000000</value><unit>rad/s</unit>");
  EXPECT_EQ(AngularSpeed(-2.22, Unit::AngularSpeed::DegreePerSecond)
                .XML(Unit::AngularSpeed::DegreePerSecond),
            "<value>-2.220000000000000</value><unit>deg/s</unit>");
}

TEST(AngularSpeed, YAML) {
  EXPECT_EQ(AngularSpeed(1.11, Unit::AngularSpeed::RadianPerSecond).YAML(),
            "{value:1.110000000000000,unit:\"rad/s\"}");
  EXPECT_EQ(AngularSpeed(-2.22, Unit::AngularSpeed::DegreePerSecond)
                .YAML(Unit::AngularSpeed::DegreePerSecond),
            "{value:-2.220000000000000,unit:\"deg/s\"}");
}

TEST(AngularSpeed, Zero) {
  EXPECT_EQ(AngularSpeed::Zero(),
            AngularSpeed(0.0, Unit::AngularSpeed::RadianPerSecond));
}

}  // namespace

}  // namespace PhQ
