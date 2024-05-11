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

#include "../include/PhQ/AngularSpeed.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/AngularSpeed.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(AngularSpeed, ArithmeticOperatorAddition) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond)
                + AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            AngularSpeed(3.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, ArithmeticOperatorDivision) {
  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond) / 2.0,
            AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            4.0);

  EXPECT_EQ(
      AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond) / Angle(2.0, Unit::Angle::Radian),
      Frequency(4.0, Unit::Frequency::Hertz));

  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            Angle(4.0, Unit::Angle::Radian));

  EXPECT_EQ(Angle(8.0, Unit::Angle::Radian) / Time(2.0, Unit::Time::Second),
            AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(
      Angle(8.0, Unit::Angle::Radian) / AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
      Time(4.0, Unit::Time::Second));
}

TEST(AngularSpeed, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond) * 2.0,
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(2.0 * AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(Angle(4.0, Unit::Angle::Radian) * Frequency(2.0, Unit::Frequency::Hertz),
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * Angle(2.0, Unit::Angle::Radian),
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(AngularSpeed(3.0, Unit::AngularSpeed::RadianPerSecond)
                - AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, AssignmentOperatorAddition) {
  AngularSpeed angular_speed{1.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed += AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond);
  EXPECT_EQ(angular_speed, AngularSpeed(3.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, AssignmentOperatorDivision) {
  AngularSpeed angular_speed{8.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed /= 2.0;
  EXPECT_EQ(angular_speed, AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, AssignmentOperatorMultiplication) {
  AngularSpeed angular_speed{4.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed *= 2.0;
  EXPECT_EQ(angular_speed, AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, AssignmentOperatorSubtraction) {
  AngularSpeed angular_speed{3.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed -= AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond);
  EXPECT_EQ(angular_speed, AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, ComparisonOperators) {
  const AngularSpeed first{1.0, Unit::AngularSpeed::RadianPerSecond};
  const AngularSpeed second{2.0, Unit::AngularSpeed::RadianPerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(AngularSpeed, CopyAssignmentOperator) {
  const AngularSpeed first{1.0, Unit::AngularSpeed::RadianPerSecond};
  AngularSpeed second = AngularSpeed<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(AngularSpeed, CopyConstructor) {
  const AngularSpeed first{1.0, Unit::AngularSpeed::RadianPerSecond};
  const AngularSpeed second{first};
  EXPECT_EQ(second, first);
}

TEST(AngularSpeed, Create) {
  constexpr AngularSpeed angular_speed =
      AngularSpeed<>::Create<Unit::AngularSpeed::RadianPerSecond>(1.0);
  EXPECT_EQ(angular_speed, AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, DefaultConstructor) {
  EXPECT_NO_THROW(AngularSpeed{});
}

TEST(AngularSpeed, Dimensions) {
  EXPECT_EQ(AngularSpeed<>::Dimensions(), RelatedDimensions<Unit::AngularSpeed>);
}

TEST(AngularSpeed, Hash) {
  const AngularSpeed first{1.0, Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed second{1.000001, Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed third{-1.0, Unit::AngularSpeed::DegreePerSecond};
  const std::hash<AngularSpeed<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(AngularSpeed, JSON) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"rad/s\"}");
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond)
                .JSON(Unit::AngularSpeed::DegreePerSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"deg/s\"}");
}

TEST(AngularSpeed, MiscellaneousConstructors) {
  EXPECT_EQ(AngularSpeed(Angle(8.0, Unit::Angle::Radian), Time(2.0, Unit::Time::Second)),
            AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(AngularSpeed(Angle(4.0, Unit::Angle::Radian), Frequency(2.0, Unit::Frequency::Hertz)),
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(
      Angle(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond), Time(2.0, Unit::Time::Second)),
      Angle(8.0, Unit::Angle::Radian));

  EXPECT_EQ(Angle(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                  Frequency(2.0, Unit::Frequency::Hertz)),
            Angle(4.0, Unit::Angle::Radian));

  EXPECT_EQ(
      Time(Angle(8.0, Unit::Angle::Radian), AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond)),
      Time(4.0, Unit::Time::Second));

  EXPECT_EQ(Frequency(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                      Angle(2.0, Unit::Angle::Radian)),
            Frequency(4.0, Unit::Frequency::Hertz));
}

TEST(AngularSpeed, MoveAssignmentOperator) {
  AngularSpeed first{1.0, Unit::AngularSpeed::RadianPerSecond};
  AngularSpeed second = AngularSpeed<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, MoveConstructor) {
  AngularSpeed first{1.0, Unit::AngularSpeed::RadianPerSecond};
  const AngularSpeed second{std::move(first)};
  EXPECT_EQ(second, AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, MutableValue) {
  AngularSpeed angular_speed{1.0, Unit::AngularSpeed::RadianPerSecond};
  double& value = angular_speed.MutableValue();
  value = 2.0;
  EXPECT_EQ(angular_speed.Value(), 2.0);
}

TEST(AngularSpeed, Print) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).Print(), Print(1.0) + " rad/s");
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond)
                .Print(Unit::AngularSpeed::DegreePerSecond),
            Print(1.0) + " deg/s");
}

TEST(AngularSpeed, SetValue) {
  AngularSpeed angular_speed{1.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed.SetValue(2.0);
  EXPECT_EQ(angular_speed.Value(), 2.0);
}

TEST(AngularSpeed, SizeOf) {
  EXPECT_EQ(sizeof(AngularSpeed{}), sizeof(double));
}

TEST(AngularSpeed, StandardConstructor) {
  EXPECT_NO_THROW(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond));
}

TEST(AngularSpeed, StaticValue) {
  constexpr AngularSpeed angular_speed =
      AngularSpeed<>::Create<Unit::AngularSpeed::DegreePerSecond>(1.0);
  constexpr double value = angular_speed.StaticValue<Unit::AngularSpeed::DegreePerSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(AngularSpeed, Stream) {
  std::ostringstream stream;
  stream << AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond);
  EXPECT_EQ(stream.str(), AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).Print());
}

TEST(AngularSpeed, Unit) {
  EXPECT_EQ(AngularSpeed<>::Unit(), Standard<Unit::AngularSpeed>);
}

TEST(AngularSpeed, Value) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).Value(), 1.0);
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond)
                .Value(Unit::AngularSpeed::DegreePerSecond),
            1.0);
}

TEST(AngularSpeed, XML) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>rad/s</unit>");
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond)
                .XML(Unit::AngularSpeed::DegreePerSecond),
            "<value>" + Print(1.0) + "</value><unit>deg/s</unit>");
}

TEST(AngularSpeed, YAML) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"rad/s\"}");
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond)
                .YAML(Unit::AngularSpeed::DegreePerSecond),
            "{value:" + Print(1.0) + ",unit:\"deg/s\"}");
}

TEST(AngularSpeed, Zero) {
  EXPECT_EQ(AngularSpeed<>::Zero(), AngularSpeed(0.0, Unit::AngularSpeed::RadianPerSecond));
}

}  // namespace

}  // namespace PhQ
