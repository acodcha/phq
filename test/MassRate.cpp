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

#include "../include/PhQ/MassRate.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(MassRate, Accessor) {
  const MassRate rate{0.1, Unit::MassRate::KilogramPerSecond};
  EXPECT_DOUBLE_EQ(rate.Value(), 0.1);
  EXPECT_DOUBLE_EQ(rate.Value(Unit::MassRate::GramPerSecond), 0.1 * 1000.0);
}

TEST(MassRate, Arithmetic) {
  const Time time{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  const Mass mass{0.5, Unit::Mass::Kilogram};
  const MassRate rate0{0.0, Unit::MassRate::KilogramPerSecond};
  const MassRate rate1{1.0, Unit::MassRate::KilogramPerSecond};
  const MassRate rate2{2.0, Unit::MassRate::KilogramPerSecond};
  EXPECT_EQ(rate1 + rate1, rate2);
  EXPECT_EQ(rate1 - rate1, rate0);
  EXPECT_EQ(rate1 * 2.0, rate2);
  EXPECT_EQ(2.0 * rate1, rate2);
  EXPECT_EQ(rate1 * time, mass);
  EXPECT_EQ(time * rate1, mass);
  EXPECT_EQ(rate2 / 2.0, rate1);
  EXPECT_EQ(rate1 / frequency, mass);
  EXPECT_EQ(rate1 / mass, frequency);
  EXPECT_EQ(mass / rate1, time);
  EXPECT_EQ(mass / time, rate1);
  EXPECT_EQ(rate2 / rate2, 1.0);

  MassRate rate3{rate1};
  rate3 += rate1;
  EXPECT_EQ(rate3, rate2);

  MassRate rate4{rate1};
  rate4 -= rate1;
  EXPECT_EQ(rate4, rate0);

  MassRate rate5{rate1};
  rate5 *= 2.0;
  EXPECT_EQ(rate5, rate2);

  MassRate rate6{rate2};
  rate6 /= 2.0;
  EXPECT_EQ(rate6, rate1);
}

TEST(MassRate, Comparison) {
  const MassRate rate0{0.1, Unit::MassRate::KilogramPerSecond};
  const MassRate rate1{0.2, Unit::MassRate::KilogramPerSecond};
  EXPECT_EQ(rate0, rate0);
  EXPECT_NE(rate0, rate1);
  EXPECT_LT(rate0, rate1);
  EXPECT_GT(rate1, rate0);
  EXPECT_LE(rate0, rate0);
  EXPECT_LE(rate0, rate1);
  EXPECT_GE(rate0, rate0);
  EXPECT_GE(rate1, rate0);
}

TEST(MassRate, Constructor) {
  const Time time0{0.5, Unit::Time::Second};
  const Frequency frequency0{2.0, Unit::Frequency::Hertz};
  const Mass mass0{0.5, Unit::Mass::Kilogram};
  constexpr MassRate rate0{};
  const MassRate rate1{100.0, Unit::MassRate::GramPerSecond};
  constexpr MassRate rate2{
      MassRate::Create<Unit::MassRate::GramPerSecond>(100.0)};
  const Mass mass1{rate1, time0};
  const Mass mass2{rate1, frequency0};
  const Time time1{rate1, mass0};
  const Frequency frequency1{rate1, mass0};
}

TEST(MassRate, Copy) {
  const MassRate reference{1.11, Unit::MassRate::KilogramPerSecond};
  const MassRate first{reference};
  EXPECT_EQ(first, reference);
  MassRate second = MassRate::Zero();
  second = reference;
  EXPECT_EQ(second, reference);
}

TEST(MassRate, Dimensions) {
  EXPECT_EQ(MassRate::Dimensions(), RelatedDimensions<Unit::MassRate>);
}

TEST(MassRate, Hash) {
  const MassRate rate0{10.0, Unit::MassRate::GramPerSecond};
  const MassRate rate1{10.000001, Unit::MassRate::GramPerSecond};
  const MassRate rate2{11.0, Unit::MassRate::GramPerSecond};
  const MassRate rate3{-10.0, Unit::MassRate::GramPerSecond};
  const MassRate rate4{20000.0, Unit::MassRate::GramPerSecond};
  const MassRate rate5{-123.456, Unit::MassRate::GramPerSecond};
  const std::hash<MassRate> hasher;
  EXPECT_NE(hasher(rate0), hasher(rate1));
  EXPECT_NE(hasher(rate0), hasher(rate2));
  EXPECT_NE(hasher(rate0), hasher(rate3));
  EXPECT_NE(hasher(rate0), hasher(rate4));
  EXPECT_NE(hasher(rate0), hasher(rate5));
  const std::unordered_set<MassRate> unordered{
      rate0, rate1, rate2, rate3, rate4, rate5};
}

TEST(MassRate, JSON) {
  EXPECT_EQ(MassRate(1.11, Unit::MassRate::KilogramPerSecond).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"kg/s\"}");
  EXPECT_EQ(MassRate(-5.0, Unit::MassRate::GramPerSecond)
                .JSON(Unit::MassRate::GramPerSecond),
            "{\"value\":-5.000000000000000,\"unit\":\"g/s\"}");
}

TEST(MassRate, Move) {
  const MassRate reference{1.11, Unit::MassRate::KilogramPerSecond};
  MassRate first{1.11, Unit::MassRate::KilogramPerSecond};
  MassRate second{std::move(first)};
  EXPECT_EQ(second, reference);
  MassRate third = MassRate::Zero();
  third = std::move(second);
  EXPECT_EQ(third, reference);
}

TEST(MassRate, Print) {
  EXPECT_EQ(MassRate(1.11, Unit::MassRate::KilogramPerSecond).Print(),
            "1.110000000000000 kg/s");
  EXPECT_EQ(MassRate(-5.0, Unit::MassRate::GramPerSecond)
                .Print(Unit::MassRate::GramPerSecond),
            "-5.000000000000000 g/s");
}

TEST(MassRate, SizeOf) {
  const MassRate rate{1.11, Unit::MassRate::KilogramPerSecond};
  EXPECT_EQ(sizeof(rate), sizeof(double));
}

TEST(MassRate, Stream) {
  const MassRate rate{1.11, Unit::MassRate::KilogramPerSecond};
  std::ostringstream stream;
  stream << rate;
  EXPECT_EQ(stream.str(), rate.Print());
}

TEST(MassRate, Unit) {
  EXPECT_EQ(MassRate::Unit(), Standard<Unit::MassRate>);
}

TEST(MassRate, XML) {
  EXPECT_EQ(MassRate(1.11, Unit::MassRate::KilogramPerSecond).XML(),
            "<value>1.110000000000000</value><unit>kg/s</unit>");
  EXPECT_EQ(MassRate(-5.0, Unit::MassRate::GramPerSecond)
                .XML(Unit::MassRate::GramPerSecond),
            "<value>-5.000000000000000</value><unit>g/s</unit>");
}

TEST(MassRate, YAML) {
  EXPECT_EQ(MassRate(1.11, Unit::MassRate::KilogramPerSecond).YAML(),
            "{value:1.110000000000000,unit:\"kg/s\"}");
  EXPECT_EQ(MassRate(-5.0, Unit::MassRate::GramPerSecond)
                .YAML(Unit::MassRate::GramPerSecond),
            "{value:-5.000000000000000,unit:\"g/s\"}");
}

TEST(MassRate, Zero) {
  EXPECT_EQ(MassRate::Zero(), MassRate(0.0, Unit::MassRate::KilogramPerSecond));
}

}  // namespace

}  // namespace PhQ
