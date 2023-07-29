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

#include <unordered_set>

namespace PhQ {

namespace {

TEST(SoundSpeed, Accessor) {
  const SoundSpeed sound_speed{343.0, Unit::Speed::MetrePerSecond};
  EXPECT_DOUBLE_EQ(sound_speed.Value(), 343.0);
  EXPECT_DOUBLE_EQ(
      sound_speed.Value(Unit::Speed::FootPerSecond), 343.0 / 0.3048);
}

TEST(SoundSpeed, Arithmetic) {
  const SoundSpeed sound_speed_0{1.0, Unit::Speed::MetrePerSecond};
  const Speed speed0{1.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(sound_speed_0 + sound_speed_0,
            SoundSpeed(2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(sound_speed_0 + speed0, Speed(2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(speed0 + sound_speed_0, Speed(2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(sound_speed_0 - sound_speed_0,
            SoundSpeed(0.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(sound_speed_0 - speed0, Speed(0.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(speed0 - sound_speed_0, Speed(0.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(sound_speed_0 * 2.0, SoundSpeed(2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(2.0 * sound_speed_0, SoundSpeed(2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(sound_speed_0 / 2.0, SoundSpeed(0.5, Unit::Speed::MetrePerSecond));

  SoundSpeed sound_speed_1{1.0, Unit::Speed::MetrePerSecond};
  sound_speed_1 += SoundSpeed{1.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(sound_speed_1, SoundSpeed(2.0, Unit::Speed::MetrePerSecond));
  sound_speed_1 += Speed{1.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(sound_speed_1, SoundSpeed(3.0, Unit::Speed::MetrePerSecond));

  SoundSpeed sound_speed_2{2.0, Unit::Speed::MetrePerSecond};
  sound_speed_2 -= SoundSpeed{1.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(sound_speed_2, SoundSpeed(1.0, Unit::Speed::MetrePerSecond));
  sound_speed_2 -= Speed{1.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(sound_speed_2, SoundSpeed(0.0, Unit::Speed::MetrePerSecond));

  SoundSpeed sound_speed_3{1.0, Unit::Speed::MetrePerSecond};
  sound_speed_3 *= 2.0;
  EXPECT_EQ(sound_speed_3, SoundSpeed(2.0, Unit::Speed::MetrePerSecond));

  SoundSpeed sound_speed_4{2.0, Unit::Speed::MetrePerSecond};
  sound_speed_4 /= 2.0;
  EXPECT_EQ(sound_speed_4, SoundSpeed(1.0, Unit::Speed::MetrePerSecond));

  Speed speed1{1.0, Unit::Speed::MetrePerSecond};
  speed1 += SoundSpeed{1.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(speed1, Speed(2.0, Unit::Speed::MetrePerSecond));

  Speed speed2{2.0, Unit::Speed::MetrePerSecond};
  speed2 -= SoundSpeed{1.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(speed2, Speed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, Comparison) {
  const SoundSpeed sound_speed_0{0.1, Unit::Speed::MetrePerSecond};
  const SoundSpeed sound_speed_1{0.2, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(sound_speed_0, sound_speed_0);
  EXPECT_NE(sound_speed_0, sound_speed_1);
  EXPECT_LT(sound_speed_0, sound_speed_1);
  EXPECT_GT(sound_speed_1, sound_speed_0);
  EXPECT_LE(sound_speed_0, sound_speed_0);
  EXPECT_LE(sound_speed_0, sound_speed_1);
  EXPECT_GE(sound_speed_0, sound_speed_0);
  EXPECT_GE(sound_speed_1, sound_speed_0);
}

TEST(SoundSpeed, Constructor) {
  constexpr SoundSpeed sound_speed_0;
  const SoundSpeed sound_speed_1{4.0, Unit::Speed::MetrePerSecond};
  constexpr SoundSpeed sound_speed_2{
      SoundSpeed::Create<Unit::Speed::MetrePerSecond>(4.0)};
  const MassDensity mass_density{
      16.0, Unit::MassDensity::KilogramPerCubicMetre};
  const IsentropicBulkModulus isentropic_bulk_modulus{
      256.0, Unit::Pressure::Pascal};
  const SpecificGasConstant specific_gas_constant{
      1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificHeatRatio specific_heat_ratio{4.0};
  const StaticPressure static_pressure{64.0, Unit::Pressure::Pascal};
  const Temperature temperature{4.0, Unit::Temperature::Kelvin};
  EXPECT_EQ(SoundSpeed(mass_density, isentropic_bulk_modulus), sound_speed_1);
  EXPECT_EQ(MassDensity(isentropic_bulk_modulus, sound_speed_1), mass_density);
  EXPECT_EQ(IsentropicBulkModulus(mass_density, sound_speed_1),
            isentropic_bulk_modulus);
  EXPECT_EQ(SoundSpeed(mass_density, static_pressure, specific_heat_ratio),
            sound_speed_1);
  EXPECT_EQ(SoundSpeed(temperature, specific_gas_constant, specific_heat_ratio),
            sound_speed_1);
}

TEST(SoundSpeed, Hash) {
  const SoundSpeed sound_speed_0{10.0, Unit::Speed::FootPerSecond};
  const SoundSpeed sound_speed_1{10.000001, Unit::Speed::FootPerSecond};
  const SoundSpeed sound_speed_2{11.0, Unit::Speed::FootPerSecond};
  const SoundSpeed sound_speed_3{-10.0, Unit::Speed::FootPerSecond};
  const SoundSpeed sound_speed_4{20000.0, Unit::Speed::FootPerSecond};
  const SoundSpeed sound_speed_5{-123.456, Unit::Speed::FootPerSecond};
  const std::hash<SoundSpeed> hasher;
  EXPECT_NE(hasher(sound_speed_0), hasher(sound_speed_1));
  EXPECT_NE(hasher(sound_speed_0), hasher(sound_speed_2));
  EXPECT_NE(hasher(sound_speed_0), hasher(sound_speed_3));
  EXPECT_NE(hasher(sound_speed_0), hasher(sound_speed_4));
  EXPECT_NE(hasher(sound_speed_0), hasher(sound_speed_5));
  const std::unordered_set<SoundSpeed> unordered{
      sound_speed_0, sound_speed_1, sound_speed_2,
      sound_speed_3, sound_speed_4, sound_speed_5};
}

TEST(SoundSpeed, JSON) {
  EXPECT_EQ(SoundSpeed(1.11, Unit::Speed::MetrePerSecond).JSON(),
            "{\"value\":1.110000,\"unit\":\"m/s\"}");
  EXPECT_EQ(SoundSpeed(-5.0, Unit::Speed::FootPerSecond)
                .JSON(Unit::Speed::FootPerSecond),
            "{\"value\":-5.000000,\"unit\":\"ft/s\"}");
}

TEST(SoundSpeed, Print) {
  EXPECT_EQ(
      SoundSpeed(1.11, Unit::Speed::MetrePerSecond).Print(), "1.110000 m/s");
  EXPECT_EQ(SoundSpeed(-5.0, Unit::Speed::FootPerSecond)
                .Print(Unit::Speed::FootPerSecond),
            "-5.000000 ft/s");
}

TEST(SoundSpeed, Stream) {
  const SoundSpeed sound_speed{1.11, Unit::Speed::MetrePerSecond};
  std::ostringstream stream;
  stream << sound_speed;
  EXPECT_EQ(stream.str(), sound_speed.Print());
}

TEST(SoundSpeed, XML) {
  EXPECT_EQ(SoundSpeed(1.11, Unit::Speed::MetrePerSecond).XML(),
            "<value>1.110000</value><unit>m/s</unit>");
  EXPECT_EQ(SoundSpeed(-5.0, Unit::Speed::FootPerSecond)
                .XML(Unit::Speed::FootPerSecond),
            "<value>-5.000000</value><unit>ft/s</unit>");
}

TEST(SoundSpeed, YAML) {
  EXPECT_EQ(SoundSpeed(1.11, Unit::Speed::MetrePerSecond).YAML(),
            "{value:1.110000,unit:\"m/s\"}");
  EXPECT_EQ(SoundSpeed(-5.0, Unit::Speed::FootPerSecond)
                .YAML(Unit::Speed::FootPerSecond),
            "{value:-5.000000,unit:\"ft/s\"}");
}

TEST(SoundSpeed, Zero) {
  EXPECT_EQ(SoundSpeed::Zero(), SoundSpeed(0.0, Unit::Speed::MetrePerSecond));
}

}  // namespace

}  // namespace PhQ
