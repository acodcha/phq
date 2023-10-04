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

#include "../include/PhQ/SoundSpeed.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(SoundSpeed, ArithmeticAddition) {
  EXPECT_EQ(SoundSpeed(1.0, Unit::Speed::MetrePerSecond)
                + SoundSpeed(2.0, Unit::Speed::MetrePerSecond),
            SoundSpeed(3.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(SoundSpeed(1.0, Unit::Speed::MetrePerSecond)
                + Speed(2.0, Unit::Speed::MetrePerSecond),
            Speed(3.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Speed(1.0, Unit::Speed::MetrePerSecond)
                + SoundSpeed(2.0, Unit::Speed::MetrePerSecond),
            Speed(3.0, Unit::Speed::MetrePerSecond));

  SoundSpeed sound_speed_0{1.0, Unit::Speed::MetrePerSecond};
  sound_speed_0 += SoundSpeed(2.0, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(sound_speed_0, SoundSpeed(3.0, Unit::Speed::MetrePerSecond));

  SoundSpeed sound_speed_1{1.0, Unit::Speed::MetrePerSecond};
  sound_speed_1 += Speed{2.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(sound_speed_1, SoundSpeed(3.0, Unit::Speed::MetrePerSecond));

  Speed speed{1.0, Unit::Speed::MetrePerSecond};
  speed += SoundSpeed{2.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(speed, Speed(3.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, ArithmeticDivision) {
  EXPECT_EQ(SoundSpeed(8.0, Unit::Speed::MetrePerSecond) / 2.0,
            SoundSpeed(4.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(SoundSpeed(8.0, Unit::Speed::MetrePerSecond)
                / SoundSpeed(2.0, Unit::Speed::MetrePerSecond),
            4.0);

  SoundSpeed quantity{8.0, Unit::Speed::MetrePerSecond};
  quantity /= 2.0;
  EXPECT_EQ(quantity, SoundSpeed(4.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, ArithmeticMultiplication) {
  EXPECT_EQ(SoundSpeed(4.0, Unit::Speed::MetrePerSecond) * 2.0,
            SoundSpeed(8.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(2.0 * SoundSpeed(4.0, Unit::Speed::MetrePerSecond),
            SoundSpeed(8.0, Unit::Speed::MetrePerSecond));

  SoundSpeed quantity{4.0, Unit::Speed::MetrePerSecond};
  quantity *= 2.0;
  EXPECT_EQ(quantity, SoundSpeed(8.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, ArithmeticSubtraction) {
  EXPECT_EQ(SoundSpeed(3.0, Unit::Speed::MetrePerSecond)
                - SoundSpeed(2.0, Unit::Speed::MetrePerSecond),
            SoundSpeed(1.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(SoundSpeed(3.0, Unit::Speed::MetrePerSecond)
                - Speed(2.0, Unit::Speed::MetrePerSecond),
            Speed(1.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Speed(3.0, Unit::Speed::MetrePerSecond)
                - SoundSpeed(2.0, Unit::Speed::MetrePerSecond),
            Speed(1.0, Unit::Speed::MetrePerSecond));

  SoundSpeed sound_speed_0{3.0, Unit::Speed::MetrePerSecond};
  sound_speed_0 -= SoundSpeed(2.0, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(sound_speed_0, SoundSpeed(1.0, Unit::Speed::MetrePerSecond));

  SoundSpeed sound_speed_1{3.0, Unit::Speed::MetrePerSecond};
  sound_speed_1 -= Speed{2.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(sound_speed_1, SoundSpeed(1.0, Unit::Speed::MetrePerSecond));

  Speed speed{3.0, Unit::Speed::MetrePerSecond};
  speed -= SoundSpeed{2.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(speed, Speed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, Comparisons) {
  const SoundSpeed first{1.11, Unit::Speed::MetrePerSecond};
  const SoundSpeed second{2.22, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(SoundSpeed, CopyAssignment) {
  const SoundSpeed first{1.11, Unit::Speed::MetrePerSecond};
  SoundSpeed second = SoundSpeed::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(SoundSpeed, CopyConstructor) {
  const SoundSpeed first{1.11, Unit::Speed::MetrePerSecond};
  const SoundSpeed second{first};
  EXPECT_EQ(second, first);
}

TEST(SoundSpeed, Create) {
  constexpr SoundSpeed quantity =
      SoundSpeed::Create<Unit::Speed::MetrePerSecond>(1.11);
  EXPECT_EQ(quantity, SoundSpeed(1.11, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, DefaultConstructor) {
  EXPECT_NO_THROW(SoundSpeed{});
}

TEST(SoundSpeed, Dimensions) {
  EXPECT_EQ(SoundSpeed::Dimensions(), RelatedDimensions<Unit::Speed>);
}

TEST(SoundSpeed, Hash) {
  const SoundSpeed first{1.11, Unit::Speed::FootPerSecond};
  const SoundSpeed second{1.110001, Unit::Speed::FootPerSecond};
  const SoundSpeed third{-1.11, Unit::Speed::FootPerSecond};
  const std::hash<SoundSpeed> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(SoundSpeed, JSON) {
  EXPECT_EQ(SoundSpeed(1.11, Unit::Speed::MetrePerSecond).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"m/s\"}");
  EXPECT_EQ(SoundSpeed(-2.22, Unit::Speed::FootPerSecond)
                .JSON(Unit::Speed::FootPerSecond),
            "{\"value\":-2.220000000000000,\"unit\":\"ft/s\"}");
}

TEST(SoundSpeed, MiscellaneousConstructors) {
  EXPECT_EQ(
      SoundSpeed(MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                 IsentropicBulkModulus(32.0, Unit::Pressure::Pascal)),
      SoundSpeed(4.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(MassDensity(IsentropicBulkModulus(16.0, Unit::Pressure::Pascal),
                        SoundSpeed(2.0, Unit::Speed::MetrePerSecond)),
            MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre));

  EXPECT_EQ(IsentropicBulkModulus(
                MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                SoundSpeed(4.0, Unit::Speed::MetrePerSecond)),
            IsentropicBulkModulus(32.0, Unit::Pressure::Pascal));

  EXPECT_EQ(
      SoundSpeed(MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                 StaticPressure(8.0, Unit::Pressure::Pascal),
                 HeatCapacityRatio(2.0)),
      SoundSpeed(2.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(SoundSpeed(
                Temperature(8.0, Unit::Temperature::Kelvin),
                SpecificGasConstant(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
                HeatCapacityRatio(2.0)),
            SoundSpeed(8.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, MoveAssignment) {
  const SoundSpeed first{1.11, Unit::Speed::MetrePerSecond};
  SoundSpeed second{1.11, Unit::Speed::MetrePerSecond};
  SoundSpeed third = SoundSpeed::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(SoundSpeed, MoveConstructor) {
  const SoundSpeed first{1.11, Unit::Speed::MetrePerSecond};
  SoundSpeed second{1.11, Unit::Speed::MetrePerSecond};
  SoundSpeed third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(SoundSpeed, MutableValue) {
  SoundSpeed quantity{1.11, Unit::Speed::MetrePerSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(value, 2.22);
}

TEST(SoundSpeed, Print) {
  EXPECT_EQ(SoundSpeed(1.11, Unit::Speed::MetrePerSecond).Print(),
            "1.110000000000000 m/s");
  EXPECT_EQ(SoundSpeed(-2.22, Unit::Speed::FootPerSecond)
                .Print(Unit::Speed::FootPerSecond),
            "-2.220000000000000 ft/s");
}

TEST(SoundSpeed, SetValue) {
  SoundSpeed quantity{1.11, Unit::Speed::MetrePerSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(SoundSpeed, SizeOf) {
  EXPECT_EQ(sizeof(SoundSpeed{}), sizeof(double));
}

TEST(SoundSpeed, StandardConstructor) {
  EXPECT_NO_THROW(SoundSpeed(1.11, Unit::Speed::FootPerSecond));
}

TEST(SoundSpeed, StaticValue) {
  constexpr SoundSpeed quantity =
      SoundSpeed::Create<Unit::Speed::FootPerSecond>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Speed::FootPerSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(SoundSpeed, Stream) {
  const SoundSpeed quantity{1.11, Unit::Speed::MetrePerSecond};
  std::ostringstream stream;
  stream << quantity;
  EXPECT_EQ(stream.str(), quantity.Print());
}

TEST(SoundSpeed, Unit) {
  EXPECT_EQ(SoundSpeed::Unit(), Standard<Unit::Speed>);
}

TEST(SoundSpeed, Value) {
  EXPECT_EQ(SoundSpeed(1.11, Unit::Speed::MetrePerSecond).Value(), 1.11);
  EXPECT_EQ(SoundSpeed(1.11, Unit::Speed::FootPerSecond)
                .Value(Unit::Speed::FootPerSecond),
            1.11);
}

TEST(SoundSpeed, XML) {
  EXPECT_EQ(SoundSpeed(1.11, Unit::Speed::MetrePerSecond).XML(),
            "<value>1.110000000000000</value><unit>m/s</unit>");
  EXPECT_EQ(SoundSpeed(-2.22, Unit::Speed::FootPerSecond)
                .XML(Unit::Speed::FootPerSecond),
            "<value>-2.220000000000000</value><unit>ft/s</unit>");
}

TEST(SoundSpeed, YAML) {
  EXPECT_EQ(SoundSpeed(1.11, Unit::Speed::MetrePerSecond).YAML(),
            "{value:1.110000000000000,unit:\"m/s\"}");
  EXPECT_EQ(SoundSpeed(-2.22, Unit::Speed::FootPerSecond)
                .YAML(Unit::Speed::FootPerSecond),
            "{value:-2.220000000000000,unit:\"ft/s\"}");
}

TEST(SoundSpeed, Zero) {
  EXPECT_EQ(SoundSpeed::Zero(), SoundSpeed(0.0, Unit::Speed::MetrePerSecond));
}

}  // namespace

}  // namespace PhQ
