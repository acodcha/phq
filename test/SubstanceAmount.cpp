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

#include "../include/PhQ/SubstanceAmount.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(SubstanceAmount, ArithmeticAddition) {
  EXPECT_EQ(SubstanceAmount(1.0, Unit::SubstanceAmount::Mole)
                + SubstanceAmount(2.0, Unit::SubstanceAmount::Mole),
            SubstanceAmount(3.0, Unit::SubstanceAmount::Mole));

  SubstanceAmount quantity{1.0, Unit::SubstanceAmount::Mole};
  quantity += SubstanceAmount(2.0, Unit::SubstanceAmount::Mole);
  EXPECT_EQ(quantity, SubstanceAmount(3.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, ArithmeticDivision) {
  EXPECT_EQ(SubstanceAmount(8.0, Unit::SubstanceAmount::Mole) / 2.0,
            SubstanceAmount(4.0, Unit::SubstanceAmount::Mole));

  EXPECT_EQ(SubstanceAmount(8.0, Unit::SubstanceAmount::Mole)
                / SubstanceAmount(2.0, Unit::SubstanceAmount::Mole),
            4.0);

  SubstanceAmount quantity{8.0, Unit::SubstanceAmount::Mole};
  quantity /= 2.0;
  EXPECT_EQ(quantity, SubstanceAmount(4.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, ArithmeticMultiplication) {
  EXPECT_EQ(SubstanceAmount(4.0, Unit::SubstanceAmount::Mole) * 2.0,
            SubstanceAmount(8.0, Unit::SubstanceAmount::Mole));

  EXPECT_EQ(2.0 * SubstanceAmount(4.0, Unit::SubstanceAmount::Mole),
            SubstanceAmount(8.0, Unit::SubstanceAmount::Mole));

  SubstanceAmount quantity{4.0, Unit::SubstanceAmount::Mole};
  quantity *= 2.0;
  EXPECT_EQ(quantity, SubstanceAmount(8.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, ArithmeticSubtraction) {
  EXPECT_EQ(SubstanceAmount(3.0, Unit::SubstanceAmount::Mole)
                - SubstanceAmount(2.0, Unit::SubstanceAmount::Mole),
            SubstanceAmount(1.0, Unit::SubstanceAmount::Mole));

  SubstanceAmount quantity{3.0, Unit::SubstanceAmount::Mole};
  quantity -= SubstanceAmount(2.0, Unit::SubstanceAmount::Mole);
  EXPECT_EQ(quantity, SubstanceAmount(1.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, Comparisons) {
  const SubstanceAmount first{0.1, Unit::SubstanceAmount::Mole};
  const SubstanceAmount second{0.2, Unit::SubstanceAmount::Mole};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(SubstanceAmount, CopyAssignment) {
  const SubstanceAmount first{1.11, Unit::SubstanceAmount::Mole};
  SubstanceAmount second = SubstanceAmount::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(SubstanceAmount, CopyConstructor) {
  const SubstanceAmount first{1.11, Unit::SubstanceAmount::Mole};
  const SubstanceAmount second{first};
  EXPECT_EQ(second, first);
}

TEST(SubstanceAmount, Create) {
  constexpr SubstanceAmount quantity =
      SubstanceAmount::Create<Unit::SubstanceAmount::Mole>(1.11);
  EXPECT_EQ(quantity, SubstanceAmount(1.11, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, DefaultConstructor) {
  EXPECT_NO_THROW(SubstanceAmount{});
}

TEST(SubstanceAmount, Dimensions) {
  EXPECT_EQ(
      SubstanceAmount::Dimensions(), RelatedDimensions<Unit::SubstanceAmount>);
}

TEST(SubstanceAmount, Hash) {
  const SubstanceAmount first{1.11, Unit::SubstanceAmount::Kilomole};
  const SubstanceAmount second{1.110001, Unit::SubstanceAmount::Kilomole};
  const SubstanceAmount third{-1.11, Unit::SubstanceAmount::Kilomole};
  const std::hash<SubstanceAmount> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(SubstanceAmount, JSON) {
  EXPECT_EQ(SubstanceAmount(1.11, Unit::SubstanceAmount::Mole).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"mol\"}");
  EXPECT_EQ(SubstanceAmount(-2.22, Unit::SubstanceAmount::Kilomole)
                .JSON(Unit::SubstanceAmount::Kilomole),
            "{\"value\":-2.220000000000000,\"unit\":\"kmol\"}");
}

TEST(SubstanceAmount, MoveAssignment) {
  const SubstanceAmount first{1.11, Unit::SubstanceAmount::Mole};
  SubstanceAmount second{1.11, Unit::SubstanceAmount::Mole};
  SubstanceAmount third = SubstanceAmount::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(SubstanceAmount, MoveConstructor) {
  const SubstanceAmount first{1.11, Unit::SubstanceAmount::Mole};
  SubstanceAmount second{1.11, Unit::SubstanceAmount::Mole};
  SubstanceAmount third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(SubstanceAmount, MutableValue) {
  SubstanceAmount quantity{1.11, Unit::SubstanceAmount::Mole};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(value, 2.22);
}

TEST(SubstanceAmount, Print) {
  EXPECT_EQ(SubstanceAmount(1.11, Unit::SubstanceAmount::Mole).Print(),
            "1.110000000000000 mol");
  EXPECT_EQ(SubstanceAmount(-2.22, Unit::SubstanceAmount::Kilomole)
                .Print(Unit::SubstanceAmount::Kilomole),
            "-2.220000000000000 kmol");
}

TEST(SubstanceAmount, SetValue) {
  SubstanceAmount quantity{1.11, Unit::SubstanceAmount::Mole};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(SubstanceAmount, SizeOf) {
  EXPECT_EQ(sizeof(SubstanceAmount{}), sizeof(double));
}

TEST(SubstanceAmount, StandardConstructor) {
  EXPECT_NO_THROW(SubstanceAmount(1.11, Unit::SubstanceAmount::Kilomole));
}

TEST(SubstanceAmount, StaticValue) {
  constexpr SubstanceAmount quantity =
      SubstanceAmount::Create<Unit::SubstanceAmount::Kilomole>(1.11);
  constexpr double value =
      quantity.StaticValue<Unit::SubstanceAmount::Kilomole>();
  EXPECT_EQ(value, 1.11);
}

TEST(SubstanceAmount, Stream) {
  const SubstanceAmount quantity{1.11, Unit::SubstanceAmount::Mole};
  std::ostringstream stream;
  stream << quantity;
  EXPECT_EQ(stream.str(), quantity.Print());
}

TEST(SubstanceAmount, Unit) {
  EXPECT_EQ(SubstanceAmount::Unit(), Standard<Unit::SubstanceAmount>);
}

TEST(SubstanceAmount, Value) {
  EXPECT_EQ(SubstanceAmount(1.11, Unit::SubstanceAmount::Mole).Value(), 1.11);
  EXPECT_EQ(SubstanceAmount(1.11, Unit::SubstanceAmount::Kilomole)
                .Value(Unit::SubstanceAmount::Kilomole),
            1.11);
}

TEST(SubstanceAmount, XML) {
  EXPECT_EQ(SubstanceAmount(1.11, Unit::SubstanceAmount::Mole).XML(),
            "<value>1.110000000000000</value><unit>mol</unit>");
  EXPECT_EQ(SubstanceAmount(-2.22, Unit::SubstanceAmount::Kilomole)
                .XML(Unit::SubstanceAmount::Kilomole),
            "<value>-2.220000000000000</value><unit>kmol</unit>");
}

TEST(SubstanceAmount, YAML) {
  EXPECT_EQ(SubstanceAmount(1.11, Unit::SubstanceAmount::Mole).YAML(),
            "{value:1.110000000000000,unit:\"mol\"}");
  EXPECT_EQ(SubstanceAmount(-2.22, Unit::SubstanceAmount::Kilomole)
                .YAML(Unit::SubstanceAmount::Kilomole),
            "{value:-2.220000000000000,unit:\"kmol\"}");
}

TEST(SubstanceAmount, Zero) {
  EXPECT_EQ(SubstanceAmount::Zero(),
            SubstanceAmount(0.0, Unit::SubstanceAmount::Mole));
}

}  // namespace

}  // namespace PhQ
