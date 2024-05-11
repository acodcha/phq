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

#include "../include/PhQ/TemperatureDifference.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/TemperatureDifference.hpp"

namespace PhQ {

namespace {

TEST(TemperatureDifference, ArithmeticOperatorAddition) {
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin)
                + TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            TemperatureDifference(3.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, ArithmeticOperatorDivision) {
  EXPECT_EQ(TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin) / 2.0,
            TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin));
  EXPECT_EQ(TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin)
                / TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            4.0);
}

TEST(TemperatureDifference, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin) * 2.0,
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
  EXPECT_EQ(2.0 * TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin),
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(TemperatureDifference(3.0, Unit::TemperatureDifference::Kelvin)
                - TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorAddition) {
  TemperatureDifference temperature_difference{1.0, Unit::TemperatureDifference::Kelvin};
  temperature_difference += TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
  EXPECT_EQ(
      temperature_difference, TemperatureDifference(3.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorDivision) {
  TemperatureDifference temperature_difference{8.0, Unit::TemperatureDifference::Kelvin};
  temperature_difference /= 2.0;
  EXPECT_EQ(
      temperature_difference, TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorMultiplication) {
  TemperatureDifference temperature_difference{4.0, Unit::TemperatureDifference::Kelvin};
  temperature_difference *= 2.0;
  EXPECT_EQ(
      temperature_difference, TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorSubtraction) {
  TemperatureDifference temperature_difference{3.0, Unit::TemperatureDifference::Kelvin};
  temperature_difference -= TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
  EXPECT_EQ(
      temperature_difference, TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, ComparisonOperators) {
  const TemperatureDifference first{1.0, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference second{2.0, Unit::TemperatureDifference::Kelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(TemperatureDifference, CopyAssignmentOperator) {
  const TemperatureDifference first{1.0, Unit::TemperatureDifference::Kelvin};
  TemperatureDifference second = TemperatureDifference<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(TemperatureDifference, CopyConstructor) {
  const TemperatureDifference first{1.0, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference second{first};
  EXPECT_EQ(second, first);
}

TEST(TemperatureDifference, Create) {
  constexpr TemperatureDifference temperature_difference =
      TemperatureDifference<>::Create<Unit::TemperatureDifference::Kelvin>(1.0);
  EXPECT_EQ(
      temperature_difference, TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, DefaultConstructor) {
  EXPECT_NO_THROW(TemperatureDifference{});
}

TEST(TemperatureDifference, Dimensions) {
  EXPECT_EQ(TemperatureDifference<>::Dimensions(), RelatedDimensions<Unit::TemperatureDifference>);
}

TEST(TemperatureDifference, Hash) {
  const TemperatureDifference first{1.0, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference second{1.000001, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference third{-1.0, Unit::TemperatureDifference::Kelvin};
  const std::hash<TemperatureDifference<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(TemperatureDifference, JSON) {
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"K\"}");
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine)
                .JSON(Unit::TemperatureDifference::Rankine),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"°R\"}");
}

TEST(TemperatureDifference, MoveAssignmentOperator) {
  TemperatureDifference first{1.0, Unit::TemperatureDifference::Kelvin};
  TemperatureDifference second = TemperatureDifference<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, MoveConstructor) {
  TemperatureDifference first{1.0, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference second{std::move(first)};
  EXPECT_EQ(second, TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, MutableValue) {
  TemperatureDifference temperature_difference{1.0, Unit::TemperatureDifference::Kelvin};
  double& value = temperature_difference.MutableValue();
  value = 2.0;
  EXPECT_EQ(temperature_difference.Value(), 2.0);
}

TEST(TemperatureDifference, Print) {
  EXPECT_EQ(
      TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).Print(), Print(1.0) + " K");
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine)
                .Print(Unit::TemperatureDifference::Rankine),
            Print(1.0) + " °R");
}

TEST(TemperatureDifference, SetValue) {
  TemperatureDifference temperature_difference{1.0, Unit::TemperatureDifference::Kelvin};
  temperature_difference.SetValue(2.0);
  EXPECT_EQ(temperature_difference.Value(), 2.0);
}

TEST(TemperatureDifference, SizeOf) {
  EXPECT_EQ(sizeof(TemperatureDifference{}), sizeof(double));
}

TEST(TemperatureDifference, StandardConstructor) {
  EXPECT_NO_THROW(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine));
}

TEST(TemperatureDifference, StaticValue) {
  constexpr TemperatureDifference temperature_difference =
      TemperatureDifference<>::Create<Unit::TemperatureDifference::Rankine>(1.0);
  constexpr double value =
      temperature_difference.StaticValue<Unit::TemperatureDifference::Rankine>();
  EXPECT_EQ(value, 1.0);
}

TEST(TemperatureDifference, Stream) {
  std::ostringstream stream;
  stream << TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin);
  EXPECT_EQ(stream.str(), TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).Print());
}

TEST(TemperatureDifference, Unit) {
  EXPECT_EQ(TemperatureDifference<>::Unit(), Standard<Unit::TemperatureDifference>);
}

TEST(TemperatureDifference, Value) {
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).Value(), 1.0);
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine)
                .Value(Unit::TemperatureDifference::Rankine),
            1.0);
}

TEST(TemperatureDifference, XML) {
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).XML(),
            "<value>" + Print(1.0) + "</value><unit>K</unit>");
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine)
                .XML(Unit::TemperatureDifference::Rankine),
            "<value>" + Print(1.0) + "</value><unit>°R</unit>");
}

TEST(TemperatureDifference, YAML) {
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).YAML(),
            "{value:" + Print(1.0) + ",unit:\"K\"}");
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine)
                .YAML(Unit::TemperatureDifference::Rankine),
            "{value:" + Print(1.0) + ",unit:\"°R\"}");
}

TEST(TemperatureDifference, Zero) {
  EXPECT_EQ(TemperatureDifference<>::Zero(),
            TemperatureDifference(0.0, Unit::TemperatureDifference::Kelvin));
}

}  // namespace

}  // namespace PhQ
