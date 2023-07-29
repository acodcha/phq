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

#include "../include/PhQ/VolumeRate.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(VolumeRate, Accessor) {
  const VolumeRate rate{0.1, Unit::VolumeRate::CubicMetrePerSecond};
  EXPECT_DOUBLE_EQ(rate.Value(), 0.1);
  EXPECT_DOUBLE_EQ(rate.Value(Unit::VolumeRate::CubicFootPerSecond),
                   0.1 / std::pow(0.3048, 3));
}

TEST(VolumeRate, Arithmetic) {
  const Time time{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  const Volume volume{0.5, Unit::Volume::CubicMetre};
  const VolumeRate rate0{0.0, Unit::VolumeRate::CubicMetrePerSecond};
  const VolumeRate rate1{1.0, Unit::VolumeRate::CubicMetrePerSecond};
  const VolumeRate rate2{2.0, Unit::VolumeRate::CubicMetrePerSecond};
  EXPECT_EQ(rate1 + rate1, rate2);
  EXPECT_EQ(rate1 - rate1, rate0);
  EXPECT_EQ(rate1 * 2.0, rate2);
  EXPECT_EQ(2.0 * rate1, rate2);
  EXPECT_EQ(rate1 * time, volume);
  EXPECT_EQ(time * rate1, volume);
  EXPECT_EQ(rate2 / 2.0, rate1);
  EXPECT_EQ(rate1 / frequency, volume);
  EXPECT_EQ(rate1 / volume, frequency);
  EXPECT_EQ(volume / rate1, time);
  EXPECT_EQ(volume / time, rate1);

  VolumeRate rate3{rate1};
  rate3 += rate1;
  EXPECT_EQ(rate3, rate2);

  VolumeRate rate4{rate1};
  rate4 -= rate1;
  EXPECT_EQ(rate4, rate0);

  VolumeRate rate5{rate1};
  rate5 *= 2.0;
  EXPECT_EQ(rate5, rate2);

  VolumeRate rate6{rate2};
  rate6 /= 2.0;
  EXPECT_EQ(rate6, rate1);
}

TEST(VolumeRate, Comparison) {
  const VolumeRate rate0{0.1, Unit::VolumeRate::CubicMetrePerSecond};
  const VolumeRate rate1{0.2, Unit::VolumeRate::CubicMetrePerSecond};
  EXPECT_EQ(rate0, rate0);
  EXPECT_NE(rate0, rate1);
  EXPECT_LT(rate0, rate1);
  EXPECT_GT(rate1, rate0);
  EXPECT_LE(rate0, rate0);
  EXPECT_LE(rate0, rate1);
  EXPECT_GE(rate0, rate0);
  EXPECT_GE(rate1, rate0);
}

TEST(VolumeRate, Constructor) {
  const Time time0{0.5, Unit::Time::Second};
  const Frequency frequency0{2.0, Unit::Frequency::Hertz};
  const Volume volume0{0.5, Unit::Volume::CubicMetre};
  constexpr VolumeRate rate0;
  const VolumeRate rate1{100.0, Unit::VolumeRate::CubicFootPerSecond};
  constexpr VolumeRate rate2{
      VolumeRate::Create<Unit::VolumeRate::CubicFootPerSecond>(100.0)};
  const Volume volume1{rate1, time0};
  const Volume volume2{rate1, frequency0};
  const Time time1{rate1, volume0};
  const Frequency frequency1{rate1, volume0};
}

TEST(VolumeRate, Hash) {
  const VolumeRate rate0{10.0, Unit::VolumeRate::CubicFootPerSecond};
  const VolumeRate rate1{10.000001, Unit::VolumeRate::CubicFootPerSecond};
  const VolumeRate rate2{11.0, Unit::VolumeRate::CubicFootPerSecond};
  const VolumeRate rate3{-10.0, Unit::VolumeRate::CubicFootPerSecond};
  const VolumeRate rate4{20000.0, Unit::VolumeRate::CubicFootPerSecond};
  const VolumeRate rate5{-123.456, Unit::VolumeRate::CubicFootPerSecond};
  const std::hash<VolumeRate> hasher;
  EXPECT_NE(hasher(rate0), hasher(rate1));
  EXPECT_NE(hasher(rate0), hasher(rate2));
  EXPECT_NE(hasher(rate0), hasher(rate3));
  EXPECT_NE(hasher(rate0), hasher(rate4));
  EXPECT_NE(hasher(rate0), hasher(rate5));
  const std::unordered_set<VolumeRate> unordered{
      rate0, rate1, rate2, rate3, rate4, rate5};
}

TEST(VolumeRate, JSON) {
  EXPECT_EQ(VolumeRate(1.11, Unit::VolumeRate::CubicMetrePerSecond).JSON(),
            "{\"value\":1.110000,\"unit\":\"m^3/s\"}");
  EXPECT_EQ(VolumeRate(-5.0, Unit::VolumeRate::CubicFootPerSecond)
                .JSON(Unit::VolumeRate::CubicFootPerSecond),
            "{\"value\":-5.000000,\"unit\":\"ft^3/s\"}");
}

TEST(VolumeRate, Print) {
  EXPECT_EQ(VolumeRate(1.11, Unit::VolumeRate::CubicMetrePerSecond).Print(),
            "1.110000 m^3/s");
  EXPECT_EQ(VolumeRate(-5.0, Unit::VolumeRate::CubicFootPerSecond)
                .Print(Unit::VolumeRate::CubicFootPerSecond),
            "-5.000000 ft^3/s");
}

TEST(VolumeRate, Stream) {
  const VolumeRate rate{1.11, Unit::VolumeRate::CubicMetrePerSecond};
  std::ostringstream stream;
  stream << rate;
  EXPECT_EQ(stream.str(), rate.Print());
}

TEST(VolumeRate, XML) {
  EXPECT_EQ(VolumeRate(1.11, Unit::VolumeRate::CubicMetrePerSecond).XML(),
            "<value>1.110000</value><unit>m^3/s</unit>");
  EXPECT_EQ(VolumeRate(-5.0, Unit::VolumeRate::CubicFootPerSecond)
                .XML(Unit::VolumeRate::CubicFootPerSecond),
            "<value>-5.000000</value><unit>ft^3/s</unit>");
}

TEST(VolumeRate, YAML) {
  EXPECT_EQ(VolumeRate(1.11, Unit::VolumeRate::CubicMetrePerSecond).YAML(),
            "{value:1.110000,unit:\"m^3/s\"}");
  EXPECT_EQ(VolumeRate(-5.0, Unit::VolumeRate::CubicFootPerSecond)
                .YAML(Unit::VolumeRate::CubicFootPerSecond),
            "{value:-5.000000,unit:\"ft^3/s\"}");
}

TEST(VolumeRate, Zero) {
  EXPECT_EQ(VolumeRate::Zero(),
            VolumeRate(0.0, Unit::VolumeRate::CubicMetrePerSecond));
}

}  // namespace

}  // namespace PhQ
