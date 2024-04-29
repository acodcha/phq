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

#include "../include/PhQ/VolumeRate.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Time.hpp"
#include "../include/PhQ/Unit/Volume.hpp"
#include "../include/PhQ/Unit/VolumeRate.hpp"
#include "../include/PhQ/Volume.hpp"

namespace PhQ {

namespace {

TEST(VolumeRate, ArithmeticOperatorAddition) {
  EXPECT_EQ(VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond)
                + VolumeRate(2.0, Unit::VolumeRate::CubicMetrePerSecond),
            VolumeRate(3.0, Unit::VolumeRate::CubicMetrePerSecond));
}

TEST(VolumeRate, ArithmeticOperatorDivision) {
  EXPECT_EQ(VolumeRate(8.0, Unit::VolumeRate::CubicMetrePerSecond) / 2.0,
            VolumeRate(4.0, Unit::VolumeRate::CubicMetrePerSecond));
  EXPECT_EQ(VolumeRate(8.0, Unit::VolumeRate::CubicMetrePerSecond)
                / VolumeRate(2.0, Unit::VolumeRate::CubicMetrePerSecond),
            4.0);
  EXPECT_EQ(VolumeRate(8.0, Unit::VolumeRate::CubicMetrePerSecond)
                / Frequency(4.0, Unit::Frequency::Hertz),
            Volume(2.0, Unit::Volume::CubicMetre));
  EXPECT_EQ(VolumeRate(8.0, Unit::VolumeRate::CubicMetrePerSecond)
                / Volume(4.0, Unit::Volume::CubicMetre),
            Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(Volume(8.0, Unit::Volume::CubicMetre)
                / VolumeRate(4.0, Unit::VolumeRate::CubicMetrePerSecond),
            Time(2.0, Unit::Time::Second));
  EXPECT_EQ(Volume(8.0, Unit::Volume::CubicMetre) / Time(4.0, Unit::Time::Second),
            VolumeRate(2.0, Unit::VolumeRate::CubicMetrePerSecond));
}

TEST(VolumeRate, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(VolumeRate(4.0, Unit::VolumeRate::CubicMetrePerSecond) * 2.0,
            VolumeRate(8.0, Unit::VolumeRate::CubicMetrePerSecond));
  EXPECT_EQ(2.0 * VolumeRate(4.0, Unit::VolumeRate::CubicMetrePerSecond),
            VolumeRate(8.0, Unit::VolumeRate::CubicMetrePerSecond));
  EXPECT_EQ(VolumeRate(4.0, Unit::VolumeRate::CubicMetrePerSecond) * Time(2.0, Unit::Time::Second),
            Volume(8.0, Unit::Volume::CubicMetre));
  EXPECT_EQ(Time(4.0, Unit::Time::Second) * VolumeRate(2.0, Unit::VolumeRate::CubicMetrePerSecond),
            Volume(8.0, Unit::Volume::CubicMetre));
}

TEST(VolumeRate, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(VolumeRate(3.0, Unit::VolumeRate::CubicMetrePerSecond)
                - VolumeRate(2.0, Unit::VolumeRate::CubicMetrePerSecond),
            VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond));
}

TEST(VolumeRate, AssignmentOperatorAddition) {
  VolumeRate volume_rate{1.0, Unit::VolumeRate::CubicMetrePerSecond};
  volume_rate += VolumeRate(2.0, Unit::VolumeRate::CubicMetrePerSecond);
  EXPECT_EQ(volume_rate, VolumeRate(3.0, Unit::VolumeRate::CubicMetrePerSecond));
}

TEST(VolumeRate, AssignmentOperatorDivision) {
  VolumeRate volume_rate{8.0, Unit::VolumeRate::CubicMetrePerSecond};
  volume_rate /= 2.0;
  EXPECT_EQ(volume_rate, VolumeRate(4.0, Unit::VolumeRate::CubicMetrePerSecond));
}

TEST(VolumeRate, AssignmentOperatorMultiplication) {
  VolumeRate volume_rate{4.0, Unit::VolumeRate::CubicMetrePerSecond};
  volume_rate *= 2.0;
  EXPECT_EQ(volume_rate, VolumeRate(8.0, Unit::VolumeRate::CubicMetrePerSecond));
}

TEST(VolumeRate, AssignmentOperatorSubtraction) {
  VolumeRate volume_rate{3.0, Unit::VolumeRate::CubicMetrePerSecond};
  volume_rate -= VolumeRate(2.0, Unit::VolumeRate::CubicMetrePerSecond);
  EXPECT_EQ(volume_rate, VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond));
}

TEST(VolumeRate, ComparisonOperators) {
  const VolumeRate first{1.0, Unit::VolumeRate::CubicMetrePerSecond};
  const VolumeRate second{2.0, Unit::VolumeRate::CubicMetrePerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(VolumeRate, CopyAssignmentOperator) {
  const VolumeRate first{1.0, Unit::VolumeRate::CubicMetrePerSecond};
  VolumeRate second = VolumeRate::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(VolumeRate, CopyConstructor) {
  const VolumeRate first{1.0, Unit::VolumeRate::CubicMetrePerSecond};
  const VolumeRate second{first};
  EXPECT_EQ(second, first);
}

TEST(VolumeRate, Create) {
  constexpr VolumeRate volume_rate = VolumeRate::Create<Unit::VolumeRate::CubicMetrePerSecond>(1.0);
  EXPECT_EQ(volume_rate, VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond));
}

TEST(VolumeRate, DefaultConstructor) {
  EXPECT_NO_THROW(VolumeRate{});
}

TEST(VolumeRate, Dimensions) {
  EXPECT_EQ(VolumeRate::Dimensions(), RelatedDimensions<Unit::VolumeRate>);
}

TEST(VolumeRate, Hash) {
  const VolumeRate first{1.0, Unit::VolumeRate::CubicFootPerSecond};
  const VolumeRate second{1.000001, Unit::VolumeRate::CubicFootPerSecond};
  const VolumeRate third{-1.0, Unit::VolumeRate::CubicFootPerSecond};
  const std::hash<VolumeRate> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(VolumeRate, JSON) {
  EXPECT_EQ(VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"m^3/s\"}");
  EXPECT_EQ(VolumeRate(1.0, Unit::VolumeRate::CubicFootPerSecond)
                .JSON(Unit::VolumeRate::CubicFootPerSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"ft^3/s\"}");
}

TEST(VolumeRate, MiscellaneousConstructors) {
  EXPECT_EQ(
      Volume(VolumeRate(4.0, Unit::VolumeRate::CubicMetrePerSecond), Time(2.0, Unit::Time::Second)),
      Volume(8.0, Unit::Volume::CubicMetre));

  EXPECT_EQ(Volume(VolumeRate(8.0, Unit::VolumeRate::CubicMetrePerSecond),
                   Frequency(4.0, Unit::Frequency::Hertz)),
            Volume(2.0, Unit::Volume::CubicMetre));

  EXPECT_EQ(Time(Volume(8.0, Unit::Volume::CubicMetre),
                 VolumeRate(4.0, Unit::VolumeRate::CubicMetrePerSecond)),
            Time(2.0, Unit::Time::Second));

  EXPECT_EQ(Frequency(VolumeRate(8.0, Unit::VolumeRate::CubicMetrePerSecond),
                      Volume(4.0, Unit::Volume::CubicMetre)),
            Frequency(2.0, Unit::Frequency::Hertz));
}

TEST(VolumeRate, MoveAssignmentOperator) {
  VolumeRate first{1.0, Unit::VolumeRate::CubicMetrePerSecond};
  VolumeRate second = VolumeRate::Zero();
  second = std::move(first);
  EXPECT_EQ(second, VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond));
}

TEST(VolumeRate, MoveConstructor) {
  VolumeRate first{1.0, Unit::VolumeRate::CubicMetrePerSecond};
  const VolumeRate second{std::move(first)};
  EXPECT_EQ(second, VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond));
}

TEST(VolumeRate, MutableValue) {
  VolumeRate volume_rate{1.0, Unit::VolumeRate::CubicMetrePerSecond};
  double& value = volume_rate.MutableValue();
  value = 2.0;
  EXPECT_EQ(volume_rate.Value(), 2.0);
}

TEST(VolumeRate, Print) {
  EXPECT_EQ(VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond).Print(), Print(1.0) + " m^3/s");
  EXPECT_EQ(VolumeRate(1.0, Unit::VolumeRate::CubicFootPerSecond)
                .Print(Unit::VolumeRate::CubicFootPerSecond),
            Print(1.0) + " ft^3/s");
}

TEST(VolumeRate, SetValue) {
  VolumeRate volume_rate{1.0, Unit::VolumeRate::CubicMetrePerSecond};
  volume_rate.SetValue(2.0);
  EXPECT_EQ(volume_rate.Value(), 2.0);
}

TEST(VolumeRate, SizeOf) {
  EXPECT_EQ(sizeof(VolumeRate{}), sizeof(double));
}

TEST(VolumeRate, StandardConstructor) {
  EXPECT_NO_THROW(VolumeRate(1.0, Unit::VolumeRate::CubicFootPerSecond));
}

TEST(VolumeRate, StaticValue) {
  constexpr VolumeRate volume_rate = VolumeRate::Create<Unit::VolumeRate::CubicFootPerSecond>(1.0);
  constexpr double value = volume_rate.StaticValue<Unit::VolumeRate::CubicFootPerSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(VolumeRate, Stream) {
  std::ostringstream stream;
  stream << VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond);
  EXPECT_EQ(stream.str(), VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond).Print());
}

TEST(VolumeRate, Unit) {
  EXPECT_EQ(VolumeRate::Unit(), Standard<Unit::VolumeRate>);
}

TEST(VolumeRate, Value) {
  EXPECT_EQ(VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond).Value(), 1.0);
  EXPECT_EQ(VolumeRate(1.0, Unit::VolumeRate::CubicFootPerSecond)
                .Value(Unit::VolumeRate::CubicFootPerSecond),
            1.0);
}

TEST(VolumeRate, XML) {
  EXPECT_EQ(VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>m^3/s</unit>");
  EXPECT_EQ(VolumeRate(1.0, Unit::VolumeRate::CubicFootPerSecond)
                .XML(Unit::VolumeRate::CubicFootPerSecond),
            "<value>" + Print(1.0) + "</value><unit>ft^3/s</unit>");
}

TEST(VolumeRate, YAML) {
  EXPECT_EQ(VolumeRate(1.0, Unit::VolumeRate::CubicMetrePerSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"m^3/s\"}");
  EXPECT_EQ(VolumeRate(1.0, Unit::VolumeRate::CubicFootPerSecond)
                .YAML(Unit::VolumeRate::CubicFootPerSecond),
            "{value:" + Print(1.0) + ",unit:\"ft^3/s\"}");
}

TEST(VolumeRate, Zero) {
  EXPECT_EQ(VolumeRate::Zero(), VolumeRate(0.0, Unit::VolumeRate::CubicMetrePerSecond));
}

}  // namespace

}  // namespace PhQ
