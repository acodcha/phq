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

#include "../include/PhQ/TransportEnergyConsumption.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(TransportEnergyConsumption, Accessor) {
  const TransportEnergyConsumption consumption{10.0, Unit::Force::Newton};
  EXPECT_DOUBLE_EQ(consumption.Value(), 10.0);
  EXPECT_DOUBLE_EQ(
      consumption.Value(Unit::Force::KilowattHourPerKilometre), 10.0 / 3600.0);
}

TEST(TransportEnergyConsumption, Arithmetic) {
  const TransportEnergyConsumption consumption0{1.0, Unit::Force::Newton};
  const Energy energy{2.0, Unit::Energy::Joule};
  const Length length{2.0, Unit::Length::Metre};
  const Speed speed{2.0, Unit::Speed::MetrePerSecond};
  const Power power{2.0, Unit::Power::Watt};
  EXPECT_EQ(consumption0 + consumption0,
            TransportEnergyConsumption(2.0, Unit::Force::Newton));
  EXPECT_EQ(consumption0 - consumption0,
            TransportEnergyConsumption(0.0, Unit::Force::Newton));
  EXPECT_EQ(
      consumption0 * 2.0, TransportEnergyConsumption(2.0, Unit::Force::Newton));
  EXPECT_EQ(
      2.0 * consumption0, TransportEnergyConsumption(2.0, Unit::Force::Newton));
  EXPECT_EQ(consumption0 * length, energy);
  EXPECT_EQ(length * consumption0, energy);
  EXPECT_EQ(consumption0 * speed, power);
  EXPECT_EQ(speed * consumption0, power);
  EXPECT_EQ(
      consumption0 / 2.0, TransportEnergyConsumption(0.5, Unit::Force::Newton));
  EXPECT_EQ(energy / length, consumption0);
  EXPECT_EQ(energy / consumption0, length);
  EXPECT_EQ(consumption0 / consumption0, 1.0);

  TransportEnergyConsumption consumption1{1.0, Unit::Force::Newton};
  consumption1 += TransportEnergyConsumption{1.0, Unit::Force::Newton};
  EXPECT_EQ(consumption1, TransportEnergyConsumption(2.0, Unit::Force::Newton));

  TransportEnergyConsumption consumption2{2.0, Unit::Force::Newton};
  consumption2 -= TransportEnergyConsumption{1.0, Unit::Force::Newton};
  EXPECT_EQ(consumption2, TransportEnergyConsumption(1.0, Unit::Force::Newton));

  TransportEnergyConsumption consumption3{1.0, Unit::Force::Newton};
  consumption3 *= 2.0;
  EXPECT_EQ(consumption3, TransportEnergyConsumption(2.0, Unit::Force::Newton));

  TransportEnergyConsumption consumption4{2.0, Unit::Force::Newton};
  consumption4 /= 2.0;
  EXPECT_EQ(consumption4, TransportEnergyConsumption(1.0, Unit::Force::Newton));
}

TEST(TransportEnergyConsumption, Comparison) {
  const TransportEnergyConsumption consumption0{0.1, Unit::Force::Newton};
  const TransportEnergyConsumption consumption1{0.2, Unit::Force::Newton};
  EXPECT_EQ(consumption0, consumption0);
  EXPECT_NE(consumption0, consumption1);
  EXPECT_LT(consumption0, consumption1);
  EXPECT_GT(consumption1, consumption0);
  EXPECT_LE(consumption0, consumption0);
  EXPECT_LE(consumption0, consumption1);
  EXPECT_GE(consumption0, consumption0);
  EXPECT_GE(consumption1, consumption0);
}

TEST(TransportEnergyConsumption, Constructor) {
  constexpr TransportEnergyConsumption consumption0;
  const TransportEnergyConsumption consumption1{4.0, Unit::Force::Newton};
  constexpr TransportEnergyConsumption consumption2{
      TransportEnergyConsumption::Create<Unit::Force::Newton>(4.0)};
  const Energy energy{8.0, Unit::Energy::Joule};
  const Length length{2.0, Unit::Length::Metre};
  const Speed speed{2.0, Unit::Speed::MetrePerSecond};
  const Power power{8.0, Unit::Power::Watt};
  EXPECT_EQ(TransportEnergyConsumption(length, energy), consumption1);
  EXPECT_EQ(Energy(length, consumption1), energy);
  EXPECT_EQ(Length(energy, consumption1), length);
  EXPECT_EQ(Power(speed, consumption1), power);
}

TEST(TransportEnergyConsumption, Hash) {
  const TransportEnergyConsumption consumption0{10.0, Unit::Force::Newton};
  const TransportEnergyConsumption consumption1{10.000001, Unit::Force::Newton};
  const TransportEnergyConsumption consumption2{11.0, Unit::Force::Newton};
  const TransportEnergyConsumption consumption3{-10.0, Unit::Force::Newton};
  const TransportEnergyConsumption consumption4{20000.0, Unit::Force::Newton};
  const TransportEnergyConsumption consumption5{-123.456, Unit::Force::Newton};
  const std::hash<TransportEnergyConsumption> hasher;
  EXPECT_NE(hasher(consumption0), hasher(consumption1));
  EXPECT_NE(hasher(consumption0), hasher(consumption2));
  EXPECT_NE(hasher(consumption0), hasher(consumption3));
  EXPECT_NE(hasher(consumption0), hasher(consumption4));
  EXPECT_NE(hasher(consumption0), hasher(consumption5));
  const std::unordered_set<TransportEnergyConsumption> unordered{
      consumption0, consumption1, consumption2,
      consumption3, consumption4, consumption5};
}

TEST(TransportEnergyConsumption, JSON) {
  EXPECT_EQ(TransportEnergyConsumption(1.11, Unit::Force::Newton).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"N\"}");
  EXPECT_EQ(
      TransportEnergyConsumption(-5.0, Unit::Force::KilowattHourPerKilometre)
          .JSON(Unit::Force::KilowattHourPerKilometre),
      "{\"value\":-5.000000000000000,\"unit\":\"kW·hr/km\"}");
}

TEST(TransportEnergyConsumption, Print) {
  EXPECT_EQ(TransportEnergyConsumption(1.11, Unit::Force::Newton).Print(),
            "1.110000000000000 N");
  EXPECT_EQ(
      TransportEnergyConsumption(-5.0, Unit::Force::KilowattHourPerKilometre)
          .Print(Unit::Force::KilowattHourPerKilometre),
      "-5.000000000000000 kW·hr/km");
}

TEST(TransportEnergyConsumption, Stream) {
  const TransportEnergyConsumption consumption{1.11, Unit::Force::Newton};
  std::ostringstream stream;
  stream << consumption;
  EXPECT_EQ(stream.str(), consumption.Print());
}

TEST(TransportEnergyConsumption, XML) {
  EXPECT_EQ(TransportEnergyConsumption(1.11, Unit::Force::Newton).XML(),
            "<value>1.110000000000000</value><unit>N</unit>");
  EXPECT_EQ(
      TransportEnergyConsumption(-5.0, Unit::Force::KilowattHourPerKilometre)
          .XML(Unit::Force::KilowattHourPerKilometre),
      "<value>-5.000000000000000</value><unit>kW·hr/km</unit>");
}

TEST(TransportEnergyConsumption, YAML) {
  EXPECT_EQ(TransportEnergyConsumption(1.11, Unit::Force::Newton).YAML(),
            "{value:1.110000000000000,unit:\"N\"}");
  EXPECT_EQ(
      TransportEnergyConsumption(-5.0, Unit::Force::KilowattHourPerKilometre)
          .YAML(Unit::Force::KilowattHourPerKilometre),
      "{value:-5.000000000000000,unit:\"kW·hr/km\"}");
}

TEST(TransportEnergyConsumption, Zero) {
  EXPECT_EQ(TransportEnergyConsumption::Zero(),
            TransportEnergyConsumption(0.0, Unit::Force::Newton));
}

}  // namespace

}  // namespace PhQ
