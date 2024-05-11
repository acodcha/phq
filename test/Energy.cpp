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

#include "../include/PhQ/Energy.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Energy.hpp"

namespace PhQ {

namespace {

TEST(Energy, ArithmeticOperatorAddition) {
  EXPECT_EQ(Energy(1.0, Unit::Energy::Joule) + Energy(2.0, Unit::Energy::Joule),
            Energy(3.0, Unit::Energy::Joule));
}

TEST(Energy, ArithmeticOperatorDivision) {
  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule) / 2.0, Energy(4.0, Unit::Energy::Joule));
  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule) / Energy(2.0, Unit::Energy::Joule), 4.0);
}

TEST(Energy, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Energy(4.0, Unit::Energy::Joule) * 2.0, Energy(8.0, Unit::Energy::Joule));
  EXPECT_EQ(2.0 * Energy(4.0, Unit::Energy::Joule), Energy(8.0, Unit::Energy::Joule));
}

TEST(Energy, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Energy(3.0, Unit::Energy::Joule) - Energy(2.0, Unit::Energy::Joule),
            Energy(1.0, Unit::Energy::Joule));
}

TEST(Energy, AssignmentOperatorAddition) {
  Energy energy{1.0, Unit::Energy::Joule};
  energy += Energy(2.0, Unit::Energy::Joule);
  EXPECT_EQ(energy, Energy(3.0, Unit::Energy::Joule));
}

TEST(Energy, AssignmentOperatorDivision) {
  Energy energy{8.0, Unit::Energy::Joule};
  energy /= 2.0;
  EXPECT_EQ(energy, Energy(4.0, Unit::Energy::Joule));
}

TEST(Energy, AssignmentOperatorMultiplication) {
  Energy energy{4.0, Unit::Energy::Joule};
  energy *= 2.0;
  EXPECT_EQ(energy, Energy(8.0, Unit::Energy::Joule));
}

TEST(Energy, AssignmentOperatorSubtraction) {
  Energy energy{3.0, Unit::Energy::Joule};
  energy -= Energy(2.0, Unit::Energy::Joule);
  EXPECT_EQ(energy, Energy(1.0, Unit::Energy::Joule));
}

TEST(Energy, ComparisonOperators) {
  const Energy first{1.0, Unit::Energy::Joule};
  const Energy second{2.0, Unit::Energy::Joule};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Energy, CopyAssignmentOperator) {
  const Energy first{1.0, Unit::Energy::Joule};
  Energy second = Energy<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Energy, CopyConstructor) {
  const Energy first{1.0, Unit::Energy::Joule};
  const Energy second{first};
  EXPECT_EQ(second, first);
}

TEST(Energy, Create) {
  constexpr Energy energy = Energy<>::Create<Unit::Energy::Joule>(1.0);
  EXPECT_EQ(energy, Energy(1.0, Unit::Energy::Joule));
}

TEST(Energy, DefaultConstructor) {
  EXPECT_NO_THROW(Energy<>{});
}

TEST(Energy, Dimensions) {
  EXPECT_EQ(Energy<>::Dimensions(), RelatedDimensions<Unit::Energy>);
}

TEST(Energy, Hash) {
  const Energy first{1.0, Unit::Energy::Nanojoule};
  const Energy second{1.000001, Unit::Energy::Nanojoule};
  const Energy third{-1.0, Unit::Energy::Nanojoule};
  const std::hash<Energy<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Energy, JSON) {
  EXPECT_EQ(
      Energy(1.0, Unit::Energy::Joule).JSON(), "{\"value\":" + Print(1.0) + ",\"unit\":\"J\"}");
  EXPECT_EQ(Energy(1.0, Unit::Energy::Nanojoule).JSON(Unit::Energy::Nanojoule),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"nJ\"}");
}

TEST(Energy, MoveAssignmentOperator) {
  Energy first{1.0, Unit::Energy::Joule};
  Energy second = Energy<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Energy(1.0, Unit::Energy::Joule));
}

TEST(Energy, MoveConstructor) {
  Energy first{1.0, Unit::Energy::Joule};
  const Energy second{std::move(first)};
  EXPECT_EQ(second, Energy(1.0, Unit::Energy::Joule));
}

TEST(Energy, MutableValue) {
  Energy energy{1.0, Unit::Energy::Joule};
  double& value = energy.MutableValue();
  value = 2.0;
  EXPECT_EQ(energy.Value(), 2.0);
}

TEST(Energy, Print) {
  EXPECT_EQ(Energy(1.0, Unit::Energy::Joule).Print(), Print(1.0) + " J");
  EXPECT_EQ(
      Energy(1.0, Unit::Energy::Nanojoule).Print(Unit::Energy::Nanojoule), Print(1.0) + " nJ");
}

TEST(Energy, SetValue) {
  Energy energy{1.0, Unit::Energy::Joule};
  energy.SetValue(2.0);
  EXPECT_EQ(energy.Value(), 2.0);
}

TEST(Energy, SizeOf) {
  EXPECT_EQ(sizeof(Energy<>{}), sizeof(double));
}

TEST(Energy, StandardConstructor) {
  EXPECT_NO_THROW(Energy(1.0, Unit::Energy::Nanojoule));
}

TEST(Energy, StaticValue) {
  constexpr Energy energy = Energy<>::Create<Unit::Energy::Nanojoule>(1.0);
  constexpr double value = energy.StaticValue<Unit::Energy::Nanojoule>();
  EXPECT_EQ(value, 1.0);
}

TEST(Energy, Stream) {
  std::ostringstream stream;
  stream << Energy(1.0, Unit::Energy::Joule);
  EXPECT_EQ(stream.str(), Energy(1.0, Unit::Energy::Joule).Print());
}

TEST(Energy, Unit) {
  EXPECT_EQ(Energy<>::Unit(), Standard<Unit::Energy>);
}

TEST(Energy, Value) {
  EXPECT_EQ(Energy(1.0, Unit::Energy::Joule).Value(), 1.0);
  EXPECT_EQ(Energy(1.0, Unit::Energy::Nanojoule).Value(Unit::Energy::Nanojoule), 1.0);
}

TEST(Energy, XML) {
  EXPECT_EQ(
      Energy(1.0, Unit::Energy::Joule).XML(), "<value>" + Print(1.0) + "</value><unit>J</unit>");
  EXPECT_EQ(Energy(1.0, Unit::Energy::Nanojoule).XML(Unit::Energy::Nanojoule),
            "<value>" + Print(1.0) + "</value><unit>nJ</unit>");
}

TEST(Energy, YAML) {
  EXPECT_EQ(Energy(1.0, Unit::Energy::Joule).YAML(), "{value:" + Print(1.0) + ",unit:\"J\"}");
  EXPECT_EQ(Energy(1.0, Unit::Energy::Nanojoule).YAML(Unit::Energy::Nanojoule),
            "{value:" + Print(1.0) + ",unit:\"nJ\"}");
}

TEST(Energy, Zero) {
  EXPECT_EQ(Energy<>::Zero(), Energy(0.0, Unit::Energy::Joule));
}

}  // namespace

}  // namespace PhQ
