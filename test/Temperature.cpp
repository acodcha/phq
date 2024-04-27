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

#include "../include/PhQ/Temperature.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/Temperature.hpp"
#include "../include/PhQ/Unit/TemperatureDifference.hpp"

namespace PhQ {

namespace {

TEST(Temperature, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      Temperature(1.0, Unit::Temperature::Kelvin) + Temperature(2.0, Unit::Temperature::Kelvin),
      Temperature(3.0, Unit::Temperature::Kelvin));

  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Kelvin)
                + TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            Temperature(3.0, Unit::Temperature::Kelvin));

  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin)
                + Temperature(2.0, Unit::Temperature::Kelvin),
            Temperature(3.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, ArithmeticOperatorDivision) {
  EXPECT_EQ(Temperature(8.0, Unit::Temperature::Kelvin) / 2.0,
            Temperature(4.0, Unit::Temperature::Kelvin));

  EXPECT_EQ(
      Temperature(8.0, Unit::Temperature::Kelvin) / Temperature(2.0, Unit::Temperature::Kelvin),
      4.0);
}

TEST(Temperature, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Temperature(4.0, Unit::Temperature::Kelvin) * 2.0,
            Temperature(8.0, Unit::Temperature::Kelvin));

  EXPECT_EQ(2.0 * Temperature(4.0, Unit::Temperature::Kelvin),
            Temperature(8.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      Temperature(3.0, Unit::Temperature::Kelvin) - Temperature(2.0, Unit::Temperature::Kelvin),
      TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));

  EXPECT_EQ(Temperature(3.0, Unit::Temperature::Kelvin)
                - TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            Temperature(1.0, Unit::Temperature::Kelvin));

  EXPECT_EQ(TemperatureDifference(3.0, Unit::TemperatureDifference::Kelvin)
                - Temperature(2.0, Unit::Temperature::Kelvin),
            Temperature(1.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, AssignmentOperatorAddition) {
  Temperature first{1.0, Unit::Temperature::Kelvin};
  first += Temperature(2.0, Unit::Temperature::Kelvin);
  EXPECT_EQ(first, Temperature(3.0, Unit::Temperature::Kelvin));

  Temperature second{1.0, Unit::Temperature::Kelvin};
  second += TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
  EXPECT_EQ(second, Temperature(3.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, AssignmentOperatorDivision) {
  Temperature quantity{8.0, Unit::Temperature::Kelvin};
  quantity /= 2.0;
  EXPECT_EQ(quantity, Temperature(4.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, AssignmentOperatorMultiplication) {
  Temperature quantity{4.0, Unit::Temperature::Kelvin};
  quantity *= 2.0;
  EXPECT_EQ(quantity, Temperature(8.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, AssignmentOperatorSubtraction) {
  Temperature first{3.0, Unit::Temperature::Kelvin};
  first -= Temperature(2.0, Unit::Temperature::Kelvin);
  EXPECT_EQ(first, Temperature(1.0, Unit::Temperature::Kelvin));

  Temperature second{3.0, Unit::Temperature::Kelvin};
  second -= TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
  EXPECT_EQ(second, Temperature(1.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, ComparisonOperators) {
  const Temperature first{0.1, Unit::Temperature::Kelvin};
  const Temperature second{0.2, Unit::Temperature::Kelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Temperature, CopyAssignmentOperator) {
  const Temperature first{1.11, Unit::Temperature::Kelvin};
  Temperature second = Temperature::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Temperature, CopyConstructor) {
  const Temperature first{1.11, Unit::Temperature::Kelvin};
  const Temperature second{first};
  EXPECT_EQ(second, first);
}

TEST(Temperature, Create) {
  constexpr Temperature quantity = Temperature::Create<Unit::Temperature::Kelvin>(1.11);
  EXPECT_EQ(quantity, Temperature(1.11, Unit::Temperature::Kelvin));
}

TEST(Temperature, DefaultConstructor) {
  EXPECT_NO_THROW(Temperature{});
}

TEST(Temperature, Dimensions) {
  EXPECT_EQ(Temperature::Dimensions(), RelatedDimensions<Unit::Temperature>);
}

TEST(Temperature, Hash) {
  const Temperature first{1.11, Unit::Temperature::Kelvin};
  const Temperature second{1.110001, Unit::Temperature::Kelvin};
  const Temperature third{-1.11, Unit::Temperature::Kelvin};
  const std::hash<Temperature> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Temperature, JSON) {
  EXPECT_EQ(Temperature(1.11, Unit::Temperature::Kelvin).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"K\"}");
  EXPECT_EQ(Temperature(-2.22, Unit::Temperature::Rankine).JSON(Unit::Temperature::Rankine),
            "{\"value\":-2.220000000000000,\"unit\":\"°R\"}");
}

TEST(Temperature, MoveAssignmentOperator) {
  Temperature first{1.11, Unit::Temperature::Kelvin};
  Temperature second = Temperature::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Temperature(1.11, Unit::Temperature::Kelvin));
}

TEST(Temperature, MoveConstructor) {
  Temperature first{1.11, Unit::Temperature::Kelvin};
  const Temperature second{std::move(first)};
  EXPECT_EQ(second, Temperature(1.11, Unit::Temperature::Kelvin));
}

TEST(Temperature, MutableValue) {
  Temperature quantity{1.11, Unit::Temperature::Kelvin};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Temperature, Print) {
  EXPECT_EQ(Temperature(1.11, Unit::Temperature::Kelvin).Print(), "1.110000000000000 K");
  EXPECT_EQ(Temperature(-2.22, Unit::Temperature::Rankine).Print(Unit::Temperature::Rankine),
            "-2.220000000000000 °R");
}

TEST(Temperature, SetValue) {
  Temperature quantity{1.11, Unit::Temperature::Kelvin};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Temperature, SizeOf) {
  EXPECT_EQ(sizeof(Temperature{}), sizeof(double));
}

TEST(Temperature, StandardConstructor) {
  EXPECT_NO_THROW(Temperature(1.11, Unit::Temperature::Rankine));
}

TEST(Temperature, StaticValue) {
  constexpr Temperature quantity = Temperature::Create<Unit::Temperature::Rankine>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Temperature::Rankine>();
  EXPECT_EQ(value, 1.11);
}

TEST(Temperature, Stream) {
  std::ostringstream stream;
  stream << Temperature(1.11, Unit::Temperature::Kelvin);
  EXPECT_EQ(stream.str(), Temperature(1.11, Unit::Temperature::Kelvin).Print());
}

TEST(Temperature, Unit) {
  EXPECT_EQ(Temperature::Unit(), Standard<Unit::Temperature>);
}

TEST(Temperature, Value) {
  EXPECT_EQ(Temperature(1.11, Unit::Temperature::Kelvin).Value(), 1.11);
  EXPECT_EQ(Temperature(1.11, Unit::Temperature::Rankine).Value(Unit::Temperature::Rankine), 1.11);
}

TEST(Temperature, XML) {
  EXPECT_EQ(Temperature(1.11, Unit::Temperature::Kelvin).XML(),
            "<value>1.110000000000000</value><unit>K</unit>");
  EXPECT_EQ(Temperature(-2.22, Unit::Temperature::Rankine).XML(Unit::Temperature::Rankine),
            "<value>-2.220000000000000</value><unit>°R</unit>");
}

TEST(Temperature, YAML) {
  EXPECT_EQ(
      Temperature(1.11, Unit::Temperature::Kelvin).YAML(), "{value:1.110000000000000,unit:\"K\"}");
  EXPECT_EQ(Temperature(-2.22, Unit::Temperature::Rankine).YAML(Unit::Temperature::Rankine),
            "{value:-2.220000000000000,unit:\"°R\"}");
}

TEST(Temperature, Zero) {
  EXPECT_EQ(Temperature::Zero(), Temperature(0.0, Unit::Temperature::Kelvin));
}

}  // namespace

}  // namespace PhQ
