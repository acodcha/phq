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
  {
    Temperature temperature{1.0, Unit::Temperature::Kelvin};
    temperature += Temperature(2.0, Unit::Temperature::Kelvin);
    EXPECT_EQ(temperature, Temperature(3.0, Unit::Temperature::Kelvin));
  }
  {
    Temperature temperature{1.0, Unit::Temperature::Kelvin};
    temperature += TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
    EXPECT_EQ(temperature, Temperature(3.0, Unit::Temperature::Kelvin));
  }
}

TEST(Temperature, AssignmentOperatorDivision) {
  Temperature temperature{8.0, Unit::Temperature::Kelvin};
  temperature /= 2.0;
  EXPECT_EQ(temperature, Temperature(4.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, AssignmentOperatorMultiplication) {
  Temperature temperature{4.0, Unit::Temperature::Kelvin};
  temperature *= 2.0;
  EXPECT_EQ(temperature, Temperature(8.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, AssignmentOperatorSubtraction) {
  {
    Temperature temperature{3.0, Unit::Temperature::Kelvin};
    temperature -= Temperature(2.0, Unit::Temperature::Kelvin);
    EXPECT_EQ(temperature, Temperature(1.0, Unit::Temperature::Kelvin));
  }
  {
    Temperature temperature{3.0, Unit::Temperature::Kelvin};
    temperature -= TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
    EXPECT_EQ(temperature, Temperature(1.0, Unit::Temperature::Kelvin));
  }
}

TEST(Temperature, ComparisonOperators) {
  const Temperature first{1.0, Unit::Temperature::Kelvin};
  const Temperature second{2.0, Unit::Temperature::Kelvin};
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
  const Temperature first{1.0, Unit::Temperature::Kelvin};
  Temperature second = Temperature<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Temperature, CopyConstructor) {
  const Temperature first{1.0, Unit::Temperature::Kelvin};
  const Temperature second{first};
  EXPECT_EQ(second, first);
}

TEST(Temperature, Create) {
  constexpr Temperature temperature = Temperature<>::Create<Unit::Temperature::Kelvin>(1.0);
  EXPECT_EQ(temperature, Temperature(1.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, DefaultConstructor) {
  EXPECT_NO_THROW(Temperature<>{});
}

TEST(Temperature, Dimensions) {
  EXPECT_EQ(Temperature<>::Dimensions(), RelatedDimensions<Unit::Temperature>);
}

TEST(Temperature, Hash) {
  const Temperature first{1.0, Unit::Temperature::Kelvin};
  const Temperature second{1.000001, Unit::Temperature::Kelvin};
  const Temperature third{-1.0, Unit::Temperature::Kelvin};
  const std::hash<Temperature<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Temperature, JSON) {
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Kelvin).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"K\"}");
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Rankine).JSON(Unit::Temperature::Rankine),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"°R\"}");
}

TEST(Temperature, MoveAssignmentOperator) {
  Temperature first{1.0, Unit::Temperature::Kelvin};
  Temperature second = Temperature<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Temperature(1.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, MoveConstructor) {
  Temperature first{1.0, Unit::Temperature::Kelvin};
  const Temperature second{std::move(first)};
  EXPECT_EQ(second, Temperature(1.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, MutableValue) {
  Temperature temperature{1.0, Unit::Temperature::Kelvin};
  double& value = temperature.MutableValue();
  value = 2.0;
  EXPECT_EQ(temperature.Value(), 2.0);
}

TEST(Temperature, Print) {
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Kelvin).Print(), Print(1.0) + " K");
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Rankine).Print(Unit::Temperature::Rankine),
            Print(1.0) + " °R");
}

TEST(Temperature, SetValue) {
  Temperature temperature{1.0, Unit::Temperature::Kelvin};
  temperature.SetValue(2.0);
  EXPECT_EQ(temperature.Value(), 2.0);
}

TEST(Temperature, SizeOf) {
  EXPECT_EQ(sizeof(Temperature<>{}), sizeof(double));
}

TEST(Temperature, StandardConstructor) {
  EXPECT_NO_THROW(Temperature(1.0, Unit::Temperature::Rankine));
}

TEST(Temperature, StaticValue) {
  constexpr Temperature temperature = Temperature<>::Create<Unit::Temperature::Rankine>(1.0);
  constexpr double value = temperature.StaticValue<Unit::Temperature::Rankine>();
  EXPECT_EQ(value, 1.0);
}

TEST(Temperature, Stream) {
  std::ostringstream stream;
  stream << Temperature(1.0, Unit::Temperature::Kelvin);
  EXPECT_EQ(stream.str(), Temperature(1.0, Unit::Temperature::Kelvin).Print());
}

TEST(Temperature, Unit) {
  EXPECT_EQ(Temperature<>::Unit(), Standard<Unit::Temperature>);
}

TEST(Temperature, Value) {
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Kelvin).Value(), 1.0);
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Rankine).Value(Unit::Temperature::Rankine), 1.0);
}

TEST(Temperature, XML) {
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Kelvin).XML(),
            "<value>" + Print(1.0) + "</value><unit>K</unit>");
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Rankine).XML(Unit::Temperature::Rankine),
            "<value>" + Print(1.0) + "</value><unit>°R</unit>");
}

TEST(Temperature, YAML) {
  EXPECT_EQ(
      Temperature(1.0, Unit::Temperature::Kelvin).YAML(), "{value:" + Print(1.0) + ",unit:\"K\"}");
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Rankine).YAML(Unit::Temperature::Rankine),
            "{value:" + Print(1.0) + ",unit:\"°R\"}");
}

TEST(Temperature, Zero) {
  EXPECT_EQ(Temperature<>::Zero(), Temperature(0.0, Unit::Temperature::Kelvin));
}

}  // namespace

}  // namespace PhQ
