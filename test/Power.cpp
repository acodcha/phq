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

#include "../include/PhQ/Power.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Power, ArithmeticOperatorAddition) {
  EXPECT_EQ(Power(1.0, Unit::Power::Watt) + Power(2.0, Unit::Power::Watt),
            Power(3.0, Unit::Power::Watt));
}

TEST(Power, ArithmeticOperatorDivision) {
  EXPECT_EQ(Power(8.0, Unit::Power::Watt) / 2.0, Power(4.0, Unit::Power::Watt));

  EXPECT_EQ(Power(8.0, Unit::Power::Watt) / Power(2.0, Unit::Power::Watt), 4.0);

  EXPECT_EQ(
      Power(8.0, Unit::Power::Watt) / Frequency(4.0, Unit::Frequency::Hertz),
      Energy(2.0, Unit::Energy::Joule));

  EXPECT_EQ(Power(8.0, Unit::Power::Watt) / Energy(4.0, Unit::Energy::Joule),
            Frequency(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule) / Time(4.0, Unit::Time::Second),
            Power(2.0, Unit::Power::Watt));

  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule) / Power(4.0, Unit::Power::Watt),
            Time(2.0, Unit::Time::Second));
}

TEST(Power, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Power(4.0, Unit::Power::Watt) * 2.0, Power(8.0, Unit::Power::Watt));

  EXPECT_EQ(2.0 * Power(4.0, Unit::Power::Watt), Power(8.0, Unit::Power::Watt));

  EXPECT_EQ(Power(4.0, Unit::Power::Watt) * Time(2.0, Unit::Time::Second),
            Energy(8.0, Unit::Energy::Joule));

  EXPECT_EQ(Time(4.0, Unit::Time::Second) * Power(2.0, Unit::Power::Watt),
            Energy(8.0, Unit::Energy::Joule));

  EXPECT_EQ(
      Frequency(4.0, Unit::Frequency::Hertz) * Energy(2.0, Unit::Energy::Joule),
      Power(8.0, Unit::Power::Watt));

  EXPECT_EQ(
      Energy(4.0, Unit::Energy::Joule) * Frequency(2.0, Unit::Frequency::Hertz),
      Power(8.0, Unit::Power::Watt));
}

TEST(Power, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Power(3.0, Unit::Power::Watt) - Power(2.0, Unit::Power::Watt),
            Power(1.0, Unit::Power::Watt));
}

TEST(Power, AssignmentOperatorAddition) {
  Power quantity{1.0, Unit::Power::Watt};
  quantity += Power(2.0, Unit::Power::Watt);
  EXPECT_EQ(quantity, Power(3.0, Unit::Power::Watt));
}

TEST(Power, AssignmentOperatorDivision) {
  Power quantity{8.0, Unit::Power::Watt};
  quantity /= 2.0;
  EXPECT_EQ(quantity, Power(4.0, Unit::Power::Watt));
}

TEST(Power, AssignmentOperatorMultiplication) {
  Power quantity{4.0, Unit::Power::Watt};
  quantity *= 2.0;
  EXPECT_EQ(quantity, Power(8.0, Unit::Power::Watt));
}

TEST(Power, AssignmentOperatorSubtraction) {
  Power quantity{3.0, Unit::Power::Watt};
  quantity -= Power(2.0, Unit::Power::Watt);
  EXPECT_EQ(quantity, Power(1.0, Unit::Power::Watt));
}

TEST(Power, ComparisonOperators) {
  const Power first{1.11, Unit::Power::Watt};
  const Power second{2.22, Unit::Power::Watt};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Power, CopyAssignmentOperator) {
  const Power first{1.11, Unit::Power::Watt};
  Power second = Power::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Power, CopyConstructor) {
  const Power first{1.11, Unit::Power::Watt};
  const Power second{first};
  EXPECT_EQ(second, first);
}

TEST(Power, Create) {
  constexpr Power quantity = Power::Create<Unit::Power::Watt>(1.11);
  EXPECT_EQ(quantity, Power(1.11, Unit::Power::Watt));
}

TEST(Power, DefaultConstructor) {
  EXPECT_NO_THROW(Power{});
}

TEST(Power, Dimensions) {
  EXPECT_EQ(Power::Dimensions(), RelatedDimensions<Unit::Power>);
}

TEST(Power, Hash) {
  const Power first{1.11, Unit::Power::Kilowatt};
  const Power second{1.110001, Unit::Power::Kilowatt};
  const Power third{-1.11, Unit::Power::Kilowatt};
  const std::hash<Power> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(Power, JSON) {
  EXPECT_EQ(Power(1.11, Unit::Power::Watt).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"W\"}");
  EXPECT_EQ(Power(-2.22, Unit::Power::Kilowatt).JSON(Unit::Power::Kilowatt),
            "{\"value\":-2.220000000000000,\"unit\":\"kW\"}");
}

TEST(Power, MiscellaneousConstructors) {
  EXPECT_EQ(
      Power(Energy(8.0, Unit::Energy::Joule), Time(4.0, Unit::Time::Second)),
      Power(2.0, Unit::Power::Watt));

  EXPECT_EQ(Power(Energy(4.0, Unit::Energy::Joule),
                  Frequency(2.0, Unit::Frequency::Hertz)),
            Power(8.0, Unit::Power::Watt));

  EXPECT_EQ(
      Time(Energy(8.0, Unit::Energy::Joule), Power(4.0, Unit::Power::Watt)),
      Time(2.0, Unit::Time::Second));

  EXPECT_EQ(Frequency(Power(8.0, Unit::Power::Watt),
                      Energy(4.0, Unit::Energy::Joule)),
            Frequency(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(
      Energy(Power(4.0, Unit::Power::Watt), Time(2.0, Unit::Time::Second)),
      Energy(8.0, Unit::Energy::Joule));

  EXPECT_EQ(Energy(Power(8.0, Unit::Power::Watt),
                   Frequency(4.0, Unit::Frequency::Hertz)),
            Energy(2.0, Unit::Energy::Joule));
}

TEST(Power, MoveAssignmentOperator) {
  Power first{1.11, Unit::Power::Watt};
  Power second = Power::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Power(1.11, Unit::Power::Watt));
}

TEST(Power, MoveConstructor) {
  Power first{1.11, Unit::Power::Watt};
  Power second{std::move(first)};
  EXPECT_EQ(second, Power(1.11, Unit::Power::Watt));
}

TEST(Power, MutableValue) {
  Power quantity{1.11, Unit::Power::Watt};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Power, Print) {
  EXPECT_EQ(Power(1.11, Unit::Power::Watt).Print(), "1.110000000000000 W");
  EXPECT_EQ(Power(-2.22, Unit::Power::Kilowatt).Print(Unit::Power::Kilowatt),
            "-2.220000000000000 kW");
}

TEST(Power, SetValue) {
  Power quantity{1.11, Unit::Power::Watt};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Power, SizeOf) {
  EXPECT_EQ(sizeof(Power{}), sizeof(double));
}

TEST(Power, StandardConstructor) {
  EXPECT_NO_THROW(Power(1.11, Unit::Power::Kilowatt));
}

TEST(Power, StaticValue) {
  constexpr Power quantity = Power::Create<Unit::Power::Kilowatt>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Power::Kilowatt>();
  EXPECT_EQ(value, 1.11);
}

TEST(Power, Stream) {
  std::ostringstream stream;
  stream << Power(1.11, Unit::Power::Watt);
  EXPECT_EQ(stream.str(), Power(1.11, Unit::Power::Watt).Print());
}

TEST(Power, Unit) {
  EXPECT_EQ(Power::Unit(), Standard<Unit::Power>);
}

TEST(Power, Value) {
  EXPECT_EQ(Power(1.11, Unit::Power::Watt).Value(), 1.11);
  EXPECT_EQ(
      Power(1.11, Unit::Power::Kilowatt).Value(Unit::Power::Kilowatt), 1.11);
}

TEST(Power, XML) {
  EXPECT_EQ(Power(1.11, Unit::Power::Watt).XML(),
            "<value>1.110000000000000</value><unit>W</unit>");
  EXPECT_EQ(Power(-2.22, Unit::Power::Kilowatt).XML(Unit::Power::Kilowatt),
            "<value>-2.220000000000000</value><unit>kW</unit>");
}

TEST(Power, YAML) {
  EXPECT_EQ(Power(1.11, Unit::Power::Watt).YAML(),
            "{value:1.110000000000000,unit:\"W\"}");
  EXPECT_EQ(Power(-2.22, Unit::Power::Kilowatt).YAML(Unit::Power::Kilowatt),
            "{value:-2.220000000000000,unit:\"kW\"}");
}

TEST(Power, Zero) {
  EXPECT_EQ(Power::Zero(), Power(0.0, Unit::Power::Watt));
}

}  // namespace

}  // namespace PhQ
