// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/TransportEnergyConsumption.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Energy.hpp"
#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/Power.hpp"
#include "../include/PhQ/Speed.hpp"
#include "../include/PhQ/Unit/Energy.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "../include/PhQ/Unit/Power.hpp"
#include "../include/PhQ/Unit/Speed.hpp"
#include "../include/PhQ/Unit/TransportEnergyConsumption.hpp"

namespace PhQ {

namespace {

TEST(TransportEnergyConsumption, ArithmeticOperatorAddition) {
  EXPECT_EQ(TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                + TransportEnergyConsumption(2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            TransportEnergyConsumption(3.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, ArithmeticOperatorDivision) {
  EXPECT_EQ(TransportEnergyConsumption(8.0, Unit::TransportEnergyConsumption::JoulePerMetre) / 2.0,
            TransportEnergyConsumption(4.0, Unit::TransportEnergyConsumption::JoulePerMetre));
  EXPECT_EQ(TransportEnergyConsumption(8.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                / TransportEnergyConsumption(2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            4.0);
  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule) / Length(4.0, Unit::Length::Metre),
            TransportEnergyConsumption(2.0, Unit::TransportEnergyConsumption::JoulePerMetre));
  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule)
                / TransportEnergyConsumption(4.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            Length(2.0, Unit::Length::Metre));
}

TEST(TransportEnergyConsumption, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(TransportEnergyConsumption(4.0, Unit::TransportEnergyConsumption::JoulePerMetre) * 2.0,
            TransportEnergyConsumption(8.0, Unit::TransportEnergyConsumption::JoulePerMetre));
  EXPECT_EQ(2.0 * TransportEnergyConsumption(4.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            TransportEnergyConsumption(8.0, Unit::TransportEnergyConsumption::JoulePerMetre));
  EXPECT_EQ(TransportEnergyConsumption(4.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                * Length(2.0, Unit::Length::Metre),
            Energy(8.0, Unit::Energy::Joule));
  EXPECT_EQ(Length(4.0, Unit::Length::Metre)
                * TransportEnergyConsumption(2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            Energy(8.0, Unit::Energy::Joule));
  EXPECT_EQ(TransportEnergyConsumption(4.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                * Speed(2.0, Unit::Speed::MetrePerSecond),
            Power(8.0, Unit::Power::Watt));
  EXPECT_EQ(Speed(4.0, Unit::Speed::MetrePerSecond)
                * TransportEnergyConsumption(2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            Power(8.0, Unit::Power::Watt));
}

TEST(TransportEnergyConsumption, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(TransportEnergyConsumption(3.0, Unit::TransportEnergyConsumption::JoulePerMetre)
                - TransportEnergyConsumption(2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
            TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, AssignmentOperatorAddition) {
  TransportEnergyConsumption transport_energy_consumption{
      1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  transport_energy_consumption +=
      TransportEnergyConsumption(2.0, Unit::TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(transport_energy_consumption,
            TransportEnergyConsumption(3.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, AssignmentOperatorDivision) {
  TransportEnergyConsumption transport_energy_consumption{
      8.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  transport_energy_consumption /= 2.0;
  EXPECT_EQ(transport_energy_consumption,
            TransportEnergyConsumption(4.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, AssignmentOperatorMultiplication) {
  TransportEnergyConsumption transport_energy_consumption{
      4.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  transport_energy_consumption *= 2.0;
  EXPECT_EQ(transport_energy_consumption,
            TransportEnergyConsumption(8.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, AssignmentOperatorSubtraction) {
  TransportEnergyConsumption transport_energy_consumption{
      3.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  transport_energy_consumption -=
      TransportEnergyConsumption(2.0, Unit::TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(transport_energy_consumption,
            TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, ComparisonOperators) {
  const TransportEnergyConsumption first{1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption second{2.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(TransportEnergyConsumption, CopyAssignmentOperator) {
  const TransportEnergyConsumption first{1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  TransportEnergyConsumption second = TransportEnergyConsumption<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(TransportEnergyConsumption, CopyConstructor) {
  const TransportEnergyConsumption first{1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption second{first};
  EXPECT_EQ(second, first);
}

TEST(TransportEnergyConsumption, Create) {
  constexpr TransportEnergyConsumption transport_energy_consumption =
      TransportEnergyConsumption<>::Create<Unit::TransportEnergyConsumption::JoulePerMetre>(1.0);
  EXPECT_EQ(transport_energy_consumption,
            TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, DefaultConstructor) {
  EXPECT_NO_THROW(TransportEnergyConsumption<>{});
}

TEST(TransportEnergyConsumption, Dimensions) {
  EXPECT_EQ(TransportEnergyConsumption<>::Dimensions(),
            RelatedDimensions<Unit::TransportEnergyConsumption>);
}

TEST(TransportEnergyConsumption, Hash) {
  const TransportEnergyConsumption first{1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption second{
      1.000001, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption third{-1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  const std::hash<TransportEnergyConsumption<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(TransportEnergyConsumption, JSON) {
  EXPECT_EQ(TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::JoulePerMetre).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"J/m\"}");
  EXPECT_EQ(
      TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .JSON(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      "{\"value\":" + Print(1.0) + ",\"unit\":\"kW·hr/km\"}");
}

TEST(TransportEnergyConsumption, MiscellaneousConstructors) {
  EXPECT_EQ(TransportEnergyConsumption(
                Energy(8.0, Unit::Energy::Joule), Length(4.0, Unit::Length::Metre)),
            TransportEnergyConsumption(2.0, Unit::TransportEnergyConsumption::JoulePerMetre));
  EXPECT_EQ(Energy(TransportEnergyConsumption(2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
                   Length(4.0, Unit::Length::Metre)),
            Energy(8.0, Unit::Energy::Joule));
  EXPECT_EQ(
      Length(Energy(8.0, Unit::Energy::Joule),
             TransportEnergyConsumption(4.0, Unit::TransportEnergyConsumption::JoulePerMetre)),
      Length(2.0, Unit::Length::Metre));
  EXPECT_EQ(Power(TransportEnergyConsumption(2.0, Unit::TransportEnergyConsumption::JoulePerMetre),
                  Speed(4.0, Unit::Speed::MetrePerSecond)),
            Power(8.0, Unit::Power::Watt));
}

TEST(TransportEnergyConsumption, MoveAssignmentOperator) {
  TransportEnergyConsumption first{1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  TransportEnergyConsumption second = TransportEnergyConsumption<>::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, MoveConstructor) {
  TransportEnergyConsumption first{1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  const TransportEnergyConsumption second{std::move(first)};
  EXPECT_EQ(
      second, TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

TEST(TransportEnergyConsumption, MutableValue) {
  TransportEnergyConsumption transport_energy_consumption{
      1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  double& value = transport_energy_consumption.MutableValue();
  value = 2.0;
  EXPECT_EQ(transport_energy_consumption.Value(), 2.0);
}

TEST(TransportEnergyConsumption, Print) {
  EXPECT_EQ(
      TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::JoulePerMetre).Print(),
      Print(1.0) + " J/m");
  EXPECT_EQ(
      TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .Print(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      Print(1.0) + " kW·hr/km");
}

TEST(TransportEnergyConsumption, SetValue) {
  TransportEnergyConsumption transport_energy_consumption{
      1.0, Unit::TransportEnergyConsumption::JoulePerMetre};
  transport_energy_consumption.SetValue(2.0);
  EXPECT_EQ(transport_energy_consumption.Value(), 2.0);
}

TEST(TransportEnergyConsumption, SizeOf) {
  EXPECT_EQ(sizeof(TransportEnergyConsumption<>{}), sizeof(double));
}

TEST(TransportEnergyConsumption, StandardConstructor) {
  EXPECT_NO_THROW(
      TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre));
}

TEST(TransportEnergyConsumption, StaticValue) {
  constexpr TransportEnergyConsumption transport_energy_consumption =
      TransportEnergyConsumption<>::Create<
          Unit::TransportEnergyConsumption::KilowattHourPerKilometre>(1.0);
  constexpr double value =
      transport_energy_consumption
          .StaticValue<Unit::TransportEnergyConsumption::KilowattHourPerKilometre>();
  EXPECT_EQ(value, 1.0);
}

TEST(TransportEnergyConsumption, Stream) {
  std::ostringstream stream;
  stream << TransportEnergyConsumption(
      1.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre);
  EXPECT_EQ(
      stream.str(),
      TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .Print());
}

TEST(TransportEnergyConsumption, Unit) {
  EXPECT_EQ(TransportEnergyConsumption<>::Unit(), Standard<Unit::TransportEnergyConsumption>);
}

TEST(TransportEnergyConsumption, Value) {
  EXPECT_EQ(
      TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::JoulePerMetre).Value(),
      1.0);
  EXPECT_EQ(
      TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .Value(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      1.0);
}

TEST(TransportEnergyConsumption, XML) {
  EXPECT_EQ(TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::JoulePerMetre).XML(),
            "<value>" + Print(1.0) + "</value><unit>J/m</unit>");
  EXPECT_EQ(
      TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .XML(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      "<value>" + Print(1.0) + "</value><unit>kW·hr/km</unit>");
}

TEST(TransportEnergyConsumption, YAML) {
  EXPECT_EQ(TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::JoulePerMetre).YAML(),
            "{value:" + Print(1.0) + ",unit:\"J/m\"}");
  EXPECT_EQ(
      TransportEnergyConsumption(1.0, Unit::TransportEnergyConsumption::KilowattHourPerKilometre)
          .YAML(Unit::TransportEnergyConsumption::KilowattHourPerKilometre),
      "{value:" + Print(1.0) + ",unit:\"kW·hr/km\"}");
}

TEST(TransportEnergyConsumption, Zero) {
  EXPECT_EQ(TransportEnergyConsumption<>::Zero(),
            TransportEnergyConsumption(0.0, Unit::TransportEnergyConsumption::JoulePerMetre));
}

}  // namespace

}  // namespace PhQ
