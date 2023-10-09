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

namespace PhQ {

namespace {

TEST(TransportEnergyConsumption, ArithmeticAddition) {
  EXPECT_EQ(TransportEnergyConsumption(
                1.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                + TransportEnergyConsumption(
                    2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            TransportEnergyConsumption(
                3.0, Unit::TransportEnergyConsumption::JoulePerMetre));

  TransportEnergyConsumption quantity{
      1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  quantity += TransportEnergyConsumption(
      2.0, Unit::TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(quantity,
            TransportEnergyConsumption(
                3.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, ArithmeticDivision) {
  EXPECT_EQ(TransportEnergyConsumption(
                8.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                / 2.0,
            TransportEnergyConsumption(
                4.0, Unit::TransportEnergyConsumption::JoulePerMetre));

  EXPECT_EQ(TransportEnergyConsumption(
                8.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                / TransportEnergyConsumption(
                    2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            4.0);

  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule) / Length(4.0, Unit::Length::Metre),
            TransportEnergyConsumption(
                2.0, Unit::TransportEnergyConsumption::JoulePerMetre));

  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule)
                / TransportEnergyConsumption(
                    4.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            Length(2.0, Unit::Length::Metre));

  TransportEnergyConsumption quantity{
      8.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  quantity /= 2.0;
  EXPECT_EQ(quantity,
            TransportEnergyConsumption(
                4.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, ArithmeticMultiplication) {
  EXPECT_EQ(TransportEnergyConsumption(
                4.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                * 2.0,
            TransportEnergyConsumption(
                8.0, Unit::TransportEnergyConsumption::JoulePerMetre));

  EXPECT_EQ(2.0
                * TransportEnergyConsumption(
                    4.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            TransportEnergyConsumption(
                8.0, Unit::TransportEnergyConsumption::JoulePerMetre));

  EXPECT_EQ(TransportEnergyConsumption(
                4.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                * Length(2.0, Unit::Length::Metre),
            Energy(8.0, Unit::Energy::Joule));

  EXPECT_EQ(Length(4.0, Unit::Length::Metre)
                * TransportEnergyConsumption(
                    2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            Energy(8.0, Unit::Energy::Joule));

  EXPECT_EQ(TransportEnergyConsumption(
                4.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                * Speed(2.0, Unit::Speed::MetrePerSecond),
            Power(8.0, Unit::Power::Watt));

  EXPECT_EQ(Speed(4.0, Unit::Speed::MetrePerSecond)
                * TransportEnergyConsumption(
                    2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            Power(8.0, Unit::Power::Watt));

  TransportEnergyConsumption quantity{
      4.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  quantity *= 2.0;
  EXPECT_EQ(quantity,
            TransportEnergyConsumption(
                8.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, ArithmeticSubtraction) {
  EXPECT_EQ(TransportEnergyConsumption(
                3.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                - TransportEnergyConsumption(
                    2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            TransportEnergyConsumption(
                1.0, Unit::TransportEnergyConsumption::JoulePerMetre));

  TransportEnergyConsumption quantity{
      3.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  quantity -= TransportEnergyConsumption(
      2.0, Unit::TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(quantity,
            TransportEnergyConsumption(
                1.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, Comparisons) {
  const TransportEnergyConsumption first{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption second{
      2.22, Unit::TransportEnergyConsumption::JoulePerMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(TransportEnergyConsumption, CopyAssignment) {
  const TransportEnergyConsumption first{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  TransportEnergyConsumption second = TransportEnergyConsumption::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(TransportEnergyConsumption, CopyConstructor) {
  const TransportEnergyConsumption first{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption second{first};
  EXPECT_EQ(second, first);
}

TEST(TransportEnergyConsumption, Create) {
  constexpr TransportEnergyConsumption quantity =
      TransportEnergyConsumption::Create<
          Unit::TransportEnergyConsumption::JoulePerMetre>(1.11);
  EXPECT_EQ(quantity,
            TransportEnergyConsumption(
                1.11, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, DefaultConstructor) {
  EXPECT_NO_THROW(TransportEnergyConsumption{});
}

TEST(TransportEnergyConsumption, Dimensions) {
  EXPECT_EQ(TransportEnergyConsumption::Dimensions(),
            RelatedDimensions<Unit::TransportEnergyConsumption>);
}

TEST(TransportEnergyConsumption, Hash) {
  const TransportEnergyConsumption first{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption second{
      1.110001, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption third{
      -1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  const std::hash<TransportEnergyConsumption> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(TransportEnergyConsumption, JSON) {
  EXPECT_EQ(TransportEnergyConsumption(
                1.11, Unit::TransportEnergyConsumption::JoulePerMetre)
                .JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"J/m\"}");
  EXPECT_EQ(
      TransportEnergyConsumption(
          -2.22, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .JSON(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      "{\"value\":-2.220000000000000,\"unit\":\"kW·hr/km\"}");
}

TEST(TransportEnergyConsumption, MiscellaneousConstructors) {
  EXPECT_EQ(TransportEnergyConsumption(Energy(8.0, Unit::Energy::Joule),
                                       Length(4.0, Unit::Length::Metre)),
            TransportEnergyConsumption(
                2.0, Unit::TransportEnergyConsumption::JoulePerMetre));

  EXPECT_EQ(Energy(TransportEnergyConsumption(
                       2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
                   Length(4.0, Unit::Length::Metre)),
            Energy(8.0, Unit::Energy::Joule));

  EXPECT_EQ(Length(Energy(8.0, Unit::Energy::Joule),
                   TransportEnergyConsumption(
                       4.0, Unit::TransportEnergyConsumption::JoulePerMetre)),
            Length(2.0, Unit::Length::Metre));

  EXPECT_EQ(Power(TransportEnergyConsumption(
                      2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
                  Speed(4.0, Unit::Speed::MetrePerSecond)),
            Power(8.0, Unit::Power::Watt));
}

TEST(TransportEnergyConsumption, MoveAssignment) {
  TransportEnergyConsumption first{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  TransportEnergyConsumption second = TransportEnergyConsumption::Zero();
  second = std::move(first);
  EXPECT_EQ(second, TransportEnergyConsumption(
                        1.11, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, MoveConstructor) {
  TransportEnergyConsumption first{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  TransportEnergyConsumption second{std::move(first)};
  EXPECT_EQ(second, TransportEnergyConsumption(
                        1.11, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, MutableValue) {
  TransportEnergyConsumption quantity{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(TransportEnergyConsumption, Print) {
  EXPECT_EQ(TransportEnergyConsumption(
                1.11, Unit::TransportEnergyConsumption::JoulePerMetre)
                .Print(),
            "1.110000000000000 J/m");
  EXPECT_EQ(
      TransportEnergyConsumption(
          -2.22, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .Print(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      "-2.220000000000000 kW·hr/km");
}

TEST(TransportEnergyConsumption, SetValue) {
  TransportEnergyConsumption quantity{
      1.11, Unit::TransportEnergyConsumption::JoulePerMetre};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(TransportEnergyConsumption, SizeOf) {
  EXPECT_EQ(sizeof(TransportEnergyConsumption{}), sizeof(double));
}

TEST(TransportEnergyConsumption, StandardConstructor) {
  EXPECT_NO_THROW(TransportEnergyConsumption(
      1.11, Unit::TransportEnergyConsumption::KilowattHourPerKilometre));
}

TEST(TransportEnergyConsumption, StaticValue) {
  constexpr TransportEnergyConsumption quantity =
      TransportEnergyConsumption::Create<
          Unit::TransportEnergyConsumption::KilowattHourPerKilometre>(1.11);
  constexpr double value = quantity.StaticValue<
      Unit::TransportEnergyConsumption::KilowattHourPerKilometre>();
  EXPECT_EQ(value, 1.11);
}

TEST(TransportEnergyConsumption, Stream) {
  std::ostringstream stream;
  stream << TransportEnergyConsumption(
      1.11, Unit::TransportEnergyConsumption::KilowattHourPerKilometre);
  EXPECT_EQ(
      stream.str(),
      TransportEnergyConsumption(
          1.11, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .Print());
}

TEST(TransportEnergyConsumption, Unit) {
  EXPECT_EQ(TransportEnergyConsumption::Unit(),
            Standard<Unit::TransportEnergyConsumption>);
}

TEST(TransportEnergyConsumption, Value) {
  EXPECT_EQ(TransportEnergyConsumption(
                1.11, Unit::TransportEnergyConsumption::JoulePerMetre)
                .Value(),
            1.11);
  EXPECT_EQ(
      TransportEnergyConsumption(
          1.11, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .Value(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      1.11);
}

TEST(TransportEnergyConsumption, XML) {
  EXPECT_EQ(TransportEnergyConsumption(
                1.11, Unit::TransportEnergyConsumption::JoulePerMetre)
                .XML(),
            "<value>1.110000000000000</value><unit>J/m</unit>");
  EXPECT_EQ(
      TransportEnergyConsumption(
          -2.22, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .XML(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      "<value>-2.220000000000000</value><unit>kW·hr/km</unit>");
}

TEST(TransportEnergyConsumption, YAML) {
  EXPECT_EQ(TransportEnergyConsumption(
                1.11, Unit::TransportEnergyConsumption::JoulePerMetre)
                .YAML(),
            "{value:1.110000000000000,unit:\"J/m\"}");
  EXPECT_EQ(
      TransportEnergyConsumption(
          -2.22, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .YAML(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      "{value:-2.220000000000000,unit:\"kW·hr/km\"}");
}

TEST(TransportEnergyConsumption, Zero) {
  EXPECT_EQ(TransportEnergyConsumption::Zero(),
            TransportEnergyConsumption(
                0.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

}  // namespace

}  // namespace PhQ
