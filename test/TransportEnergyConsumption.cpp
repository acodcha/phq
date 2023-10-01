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
  const TransportEnergyConsumption consumption{
      10.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  EXPECT_DOUBLE_EQ(consumption.Value(), 10.0);
  EXPECT_DOUBLE_EQ(
      consumption.Value(
          Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      10.0 / 3600.0);
}

TEST(TransportEnergyConsumption, Arithmetic) {
  const TransportEnergyConsumption consumption0{
      1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  const Energy energy{2.0, Unit::Energy::Joule};
  const Length length{2.0, Unit::Length::Metre};
  const Speed speed{2.0, Unit::Speed::MetrePerSecond};
  const Power power{2.0, Unit::Power::Watt};
  EXPECT_EQ(consumption0 + consumption0,
            TransportEnergyConsumption(
                2.0, Unit::TransportEnergyConsumption::JoulePerMetre));
  EXPECT_EQ(consumption0 - consumption0,
            TransportEnergyConsumption(
                0.0, Unit::TransportEnergyConsumption::JoulePerMetre));
  EXPECT_EQ(consumption0 * 2.0,
            TransportEnergyConsumption(
                2.0, Unit::TransportEnergyConsumption::JoulePerMetre));
  EXPECT_EQ(2.0 * consumption0,
            TransportEnergyConsumption(
                2.0, Unit::TransportEnergyConsumption::JoulePerMetre));
  EXPECT_EQ(consumption0 * length, energy);
  EXPECT_EQ(length * consumption0, energy);
  EXPECT_EQ(consumption0 * speed, power);
  EXPECT_EQ(speed * consumption0, power);
  EXPECT_EQ(consumption0 / 2.0,
            TransportEnergyConsumption(
                0.5, Unit::TransportEnergyConsumption::JoulePerMetre));
  EXPECT_EQ(energy / length, consumption0);
  EXPECT_EQ(energy / consumption0, length);
  EXPECT_EQ(consumption0 / consumption0, 1.0);

  TransportEnergyConsumption consumption1{
      1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  consumption1 += TransportEnergyConsumption{
      1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  EXPECT_EQ(consumption1,
            TransportEnergyConsumption(
                2.0, Unit::TransportEnergyConsumption::JoulePerMetre));

  TransportEnergyConsumption consumption2{
      2.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  consumption2 -= TransportEnergyConsumption{
      1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  EXPECT_EQ(consumption2,
            TransportEnergyConsumption(
                1.0, Unit::TransportEnergyConsumption::JoulePerMetre));

  TransportEnergyConsumption consumption3{
      1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  consumption3 *= 2.0;
  EXPECT_EQ(consumption3,
            TransportEnergyConsumption(
                2.0, Unit::TransportEnergyConsumption::JoulePerMetre));

  TransportEnergyConsumption consumption4{
      2.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  consumption4 /= 2.0;
  EXPECT_EQ(consumption4,
            TransportEnergyConsumption(
                1.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, Comparison) {
  const TransportEnergyConsumption consumption0{
      0.1, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption consumption1{
      0.2, Unit::TransportEnergyConsumption::JoulePerMetre};
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
  constexpr TransportEnergyConsumption consumption0{};
  const TransportEnergyConsumption consumption1{
      4.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  constexpr TransportEnergyConsumption consumption2{
      TransportEnergyConsumption::Create<
          Unit::TransportEnergyConsumption::JoulePerMetre>(4.0)};
  const Energy energy{8.0, Unit::Energy::Joule};
  const Length length{2.0, Unit::Length::Metre};
  const Speed speed{2.0, Unit::Speed::MetrePerSecond};
  const Power power{8.0, Unit::Power::Watt};
  EXPECT_EQ(TransportEnergyConsumption(length, energy), consumption1);
  EXPECT_EQ(Energy(length, consumption1), energy);
  EXPECT_EQ(Length(energy, consumption1), length);
  EXPECT_EQ(Power(speed, consumption1), power);
}

TEST(TransportEnergyConsumption, Copy) {
  const TransportEnergyConsumption reference{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption first{reference};
  EXPECT_EQ(first, reference);
  TransportEnergyConsumption second = TransportEnergyConsumption::Zero();
  second = reference;
  EXPECT_EQ(second, reference);
}

TEST(TransportEnergyConsumption, Dimensions) {
  EXPECT_EQ(TransportEnergyConsumption::Dimensions(),
            RelatedDimensions<Unit::TransportEnergyConsumption>);
}

TEST(TransportEnergyConsumption, Hash) {
  const TransportEnergyConsumption consumption0{
      10.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption consumption1{
      10.000001, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption consumption2{
      11.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption consumption3{
      -10.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption consumption4{
      20000.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption consumption5{
      -123.456, Unit::TransportEnergyConsumption::JoulePerMetre};
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
  EXPECT_EQ(TransportEnergyConsumption(
                1.11, Unit::TransportEnergyConsumption::JoulePerMetre)
                .JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"J/m\"}");
  EXPECT_EQ(
      TransportEnergyConsumption(
          -5.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .JSON(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      "{\"value\":-5.000000000000000,\"unit\":\"kW·hr/km\"}");
}

TEST(TransportEnergyConsumption, Move) {
  const TransportEnergyConsumption reference{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  TransportEnergyConsumption first{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  TransportEnergyConsumption second{std::move(first)};
  EXPECT_EQ(second, reference);
  TransportEnergyConsumption third = TransportEnergyConsumption::Zero();
  third = std::move(second);
  EXPECT_EQ(third, reference);
}

TEST(TransportEnergyConsumption, Print) {
  EXPECT_EQ(TransportEnergyConsumption(
                1.11, Unit::TransportEnergyConsumption::JoulePerMetre)
                .Print(),
            "1.110000000000000 J/m");
  EXPECT_EQ(
      TransportEnergyConsumption(
          -5.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .Print(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      "-5.000000000000000 kW·hr/km");
}

TEST(TransportEnergyConsumption, SizeOf) {
  const TransportEnergyConsumption consumption{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  EXPECT_EQ(sizeof(consumption), sizeof(double));
}

TEST(TransportEnergyConsumption, Stream) {
  const TransportEnergyConsumption consumption{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  std::ostringstream stream;
  stream << consumption;
  EXPECT_EQ(stream.str(), consumption.Print());
}

TEST(TransportEnergyConsumption, Unit) {
  EXPECT_EQ(TransportEnergyConsumption::Unit(),
            Standard<Unit::TransportEnergyConsumption>);
}

TEST(TransportEnergyConsumption, XML) {
  EXPECT_EQ(TransportEnergyConsumption(
                1.11, Unit::TransportEnergyConsumption::JoulePerMetre)
                .XML(),
            "<value>1.110000000000000</value><unit>J/m</unit>");
  EXPECT_EQ(
      TransportEnergyConsumption(
          -5.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .XML(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      "<value>-5.000000000000000</value><unit>kW·hr/km</unit>");
}

TEST(TransportEnergyConsumption, YAML) {
  EXPECT_EQ(TransportEnergyConsumption(
                1.11, Unit::TransportEnergyConsumption::JoulePerMetre)
                .YAML(),
            "{value:1.110000000000000,unit:\"J/m\"}");
  EXPECT_EQ(
      TransportEnergyConsumption(
          -5.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .YAML(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      "{value:-5.000000000000000,unit:\"kW·hr/km\"}");
}

TEST(TransportEnergyConsumption, Zero) {
  EXPECT_EQ(TransportEnergyConsumption::Zero(),
            TransportEnergyConsumption(
                0.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

}  // namespace

}  // namespace PhQ
