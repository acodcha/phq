// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#include "../include/PhQ/SubstanceAmount.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Area.hpp"
#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/Unit/Area.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "../include/PhQ/Unit/Volume.hpp"

namespace PhQ {

namespace {

TEST(SubstanceAmount, ArithmeticOperatorAddition) {
  EXPECT_EQ(SubstanceAmount(1.0, Unit::SubstanceAmount::Mole)
                + SubstanceAmount(2.0, Unit::SubstanceAmount::Mole),
            SubstanceAmount(3.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, ArithmeticOperatorDivision) {
  EXPECT_EQ(SubstanceAmount(8.0, Unit::SubstanceAmount::Mole) / 2.0,
            SubstanceAmount(4.0, Unit::SubstanceAmount::Mole));
  EXPECT_EQ(SubstanceAmount(8.0, Unit::SubstanceAmount::Mole)
                / SubstanceAmount(2.0, Unit::SubstanceAmount::Mole),
            4.0);
}

TEST(SubstanceAmount, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SubstanceAmount(4.0, Unit::SubstanceAmount::Mole) * 2.0,
            SubstanceAmount(8.0, Unit::SubstanceAmount::Mole));
  EXPECT_EQ(2.0 * SubstanceAmount(4.0, Unit::SubstanceAmount::Mole),
            SubstanceAmount(8.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(SubstanceAmount(3.0, Unit::SubstanceAmount::Mole)
                - SubstanceAmount(2.0, Unit::SubstanceAmount::Mole),
            SubstanceAmount(1.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, AssignmentOperatorAddition) {
  SubstanceAmount substance_amount{1.0, Unit::SubstanceAmount::Mole};
  substance_amount += SubstanceAmount(2.0, Unit::SubstanceAmount::Mole);
  EXPECT_EQ(substance_amount, SubstanceAmount(3.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, AssignmentOperatorDivision) {
  SubstanceAmount substance_amount{8.0, Unit::SubstanceAmount::Mole};
  substance_amount /= 2.0;
  EXPECT_EQ(substance_amount, SubstanceAmount(4.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, AssignmentOperatorMultiplication) {
  SubstanceAmount substance_amount{4.0, Unit::SubstanceAmount::Mole};
  substance_amount *= 2.0;
  EXPECT_EQ(substance_amount, SubstanceAmount(8.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, AssignmentOperatorSubtraction) {
  SubstanceAmount substance_amount{3.0, Unit::SubstanceAmount::Mole};
  substance_amount -= SubstanceAmount(2.0, Unit::SubstanceAmount::Mole);
  EXPECT_EQ(substance_amount, SubstanceAmount(1.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, ComparisonOperators) {
  const SubstanceAmount first{1.0, Unit::SubstanceAmount::Mole};
  const SubstanceAmount second{2.0, Unit::SubstanceAmount::Mole};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(SubstanceAmount, CopyAssignmentOperator) {
  const SubstanceAmount first{1.0, Unit::SubstanceAmount::Mole};
  SubstanceAmount second = SubstanceAmount::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(SubstanceAmount, CopyConstructor) {
  const SubstanceAmount first{1.0, Unit::SubstanceAmount::Mole};
  const SubstanceAmount second{first};
  EXPECT_EQ(second, first);
}

TEST(SubstanceAmount, Create) {
  constexpr SubstanceAmount substance_amount =
      SubstanceAmount::Create<Unit::SubstanceAmount::Mole>(1.0);
  EXPECT_EQ(substance_amount, SubstanceAmount(1.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, DefaultConstructor) {
  EXPECT_NO_THROW(SubstanceAmount{});
}

TEST(SubstanceAmount, Dimensions) {
  EXPECT_EQ(SubstanceAmount::Dimensions(), RelatedDimensions<Unit::SubstanceAmount>);
}

TEST(SubstanceAmount, Hash) {
  const SubstanceAmount first{1.0, Unit::SubstanceAmount::Kilomole};
  const SubstanceAmount second{1.000001, Unit::SubstanceAmount::Kilomole};
  const SubstanceAmount third{-1.0, Unit::SubstanceAmount::Kilomole};
  const std::hash<SubstanceAmount> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(SubstanceAmount, JSON) {
  EXPECT_EQ(SubstanceAmount(1.0, Unit::SubstanceAmount::Mole).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"mol\"}");
  EXPECT_EQ(
      SubstanceAmount(1.0, Unit::SubstanceAmount::Kilomole).JSON(Unit::SubstanceAmount::Kilomole),
      "{\"value\":" + Print(1.0) + ",\"unit\":\"kmol\"}");
}

TEST(SubstanceAmount, MoveAssignmentOperator) {
  SubstanceAmount first{1.0, Unit::SubstanceAmount::Mole};
  SubstanceAmount second = SubstanceAmount::Zero();
  second = std::move(first);
  EXPECT_EQ(second, SubstanceAmount(1.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, MoveConstructor) {
  SubstanceAmount first{1.0, Unit::SubstanceAmount::Mole};
  SubstanceAmount second{std::move(first)};
  EXPECT_EQ(second, SubstanceAmount(1.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, MutableValue) {
  SubstanceAmount substance_amount{1.0, Unit::SubstanceAmount::Mole};
  double& value = substance_amount.MutableValue();
  value = 2.0;
  EXPECT_EQ(substance_amount.Value(), 2.0);
}

TEST(SubstanceAmount, Print) {
  EXPECT_EQ(SubstanceAmount(1.0, Unit::SubstanceAmount::Mole).Print(), Print(1.0) + " mol");
  EXPECT_EQ(
      SubstanceAmount(1.0, Unit::SubstanceAmount::Kilomole).Print(Unit::SubstanceAmount::Kilomole),
      Print(1.0) + " kmol");
}

TEST(SubstanceAmount, SetValue) {
  SubstanceAmount substance_amount{1.0, Unit::SubstanceAmount::Mole};
  substance_amount.SetValue(2.0);
  EXPECT_EQ(substance_amount.Value(), 2.0);
}

TEST(SubstanceAmount, SizeOf) {
  EXPECT_EQ(sizeof(SubstanceAmount{}), sizeof(double));
}

TEST(SubstanceAmount, StandardConstructor) {
  EXPECT_NO_THROW(SubstanceAmount(1.0, Unit::SubstanceAmount::Kilomole));
}

TEST(SubstanceAmount, StaticValue) {
  constexpr SubstanceAmount substance_amount =
      SubstanceAmount::Create<Unit::SubstanceAmount::Kilomole>(1.0);
  constexpr double value = substance_amount.StaticValue<Unit::SubstanceAmount::Kilomole>();
  EXPECT_EQ(value, 1.0);
}

TEST(SubstanceAmount, Stream) {
  std::ostringstream stream;
  stream << SubstanceAmount(1.0, Unit::SubstanceAmount::Mole);
  EXPECT_EQ(stream.str(), SubstanceAmount(1.0, Unit::SubstanceAmount::Mole).Print());
}

TEST(SubstanceAmount, Unit) {
  EXPECT_EQ(SubstanceAmount::Unit(), Standard<Unit::SubstanceAmount>);
}

TEST(SubstanceAmount, Value) {
  EXPECT_EQ(SubstanceAmount(1.0, Unit::SubstanceAmount::Mole).Value(), 1.0);
  EXPECT_EQ(
      SubstanceAmount(1.0, Unit::SubstanceAmount::Kilomole).Value(Unit::SubstanceAmount::Kilomole),
      1.0);
}

TEST(SubstanceAmount, XML) {
  EXPECT_EQ(SubstanceAmount(1.0, Unit::SubstanceAmount::Mole).XML(),
            "<value>" + Print(1.0) + "</value><unit>mol</unit>");
  EXPECT_EQ(
      SubstanceAmount(1.0, Unit::SubstanceAmount::Kilomole).XML(Unit::SubstanceAmount::Kilomole),
      "<value>" + Print(1.0) + "</value><unit>kmol</unit>");
}

TEST(SubstanceAmount, YAML) {
  EXPECT_EQ(SubstanceAmount(1.0, Unit::SubstanceAmount::Mole).YAML(),
            "{value:" + Print(1.0) + ",unit:\"mol\"}");
  EXPECT_EQ(
      SubstanceAmount(1.0, Unit::SubstanceAmount::Kilomole).YAML(Unit::SubstanceAmount::Kilomole),
      "{value:" + Print(1.0) + ",unit:\"kmol\"}");
}

TEST(SubstanceAmount, Zero) {
  EXPECT_EQ(SubstanceAmount::Zero(), SubstanceAmount(0.0, Unit::SubstanceAmount::Mole));
}

}  // namespace

}  // namespace PhQ
