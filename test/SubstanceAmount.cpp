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

#include <unordered_set>

namespace PhQ {

namespace {

TEST(SubstanceAmount, Accessor) {
  const SubstanceAmount substance_amount{0.1, Unit::SubstanceAmount::Mole};
  EXPECT_DOUBLE_EQ(substance_amount.Value(), 0.1);
  EXPECT_DOUBLE_EQ(
      substance_amount.Value(Unit::SubstanceAmount::Kilomole), 0.1 * 0.001);
}

TEST(SubstanceAmount, Arithmetic) {
  const SubstanceAmount substance_amount_0{1.0, Unit::SubstanceAmount::Mole};
  EXPECT_EQ(substance_amount_0 + substance_amount_0,
            SubstanceAmount(2.0, Unit::SubstanceAmount::Mole));
  EXPECT_EQ(substance_amount_0 - substance_amount_0,
            SubstanceAmount(0.0, Unit::SubstanceAmount::Mole));
  EXPECT_EQ(substance_amount_0 * 2.0,
            SubstanceAmount(2.0, Unit::SubstanceAmount::Mole));
  EXPECT_EQ(2.0 * substance_amount_0,
            SubstanceAmount(2.0, Unit::SubstanceAmount::Mole));
  EXPECT_EQ(substance_amount_0 / 2.0,
            SubstanceAmount(0.5, Unit::SubstanceAmount::Mole));
  EXPECT_EQ(substance_amount_0 / substance_amount_0, 1.0);

  SubstanceAmount substance_amount_1{1.0, Unit::SubstanceAmount::Mole};
  substance_amount_1 += SubstanceAmount{1.0, Unit::SubstanceAmount::Mole};
  EXPECT_EQ(
      substance_amount_1, SubstanceAmount(2.0, Unit::SubstanceAmount::Mole));

  SubstanceAmount substance_amount_2{2.0, Unit::SubstanceAmount::Mole};
  substance_amount_2 -= SubstanceAmount{1.0, Unit::SubstanceAmount::Mole};
  EXPECT_EQ(
      substance_amount_2, SubstanceAmount(1.0, Unit::SubstanceAmount::Mole));

  SubstanceAmount substance_amount_3{1.0, Unit::SubstanceAmount::Mole};
  substance_amount_3 *= 2.0;
  EXPECT_EQ(
      substance_amount_3, SubstanceAmount(2.0, Unit::SubstanceAmount::Mole));

  SubstanceAmount substance_amount_4{2.0, Unit::SubstanceAmount::Mole};
  substance_amount_4 /= 2.0;
  EXPECT_EQ(
      substance_amount_4, SubstanceAmount(1.0, Unit::SubstanceAmount::Mole));
}

TEST(SubstanceAmount, Comparison) {
  const SubstanceAmount substance_amount_0{0.1, Unit::SubstanceAmount::Mole};
  const SubstanceAmount substance_amount_1{0.2, Unit::SubstanceAmount::Mole};
  EXPECT_EQ(substance_amount_0, substance_amount_0);
  EXPECT_NE(substance_amount_0, substance_amount_1);
  EXPECT_LT(substance_amount_0, substance_amount_1);
  EXPECT_GT(substance_amount_1, substance_amount_0);
  EXPECT_LE(substance_amount_0, substance_amount_0);
  EXPECT_LE(substance_amount_0, substance_amount_1);
  EXPECT_GE(substance_amount_0, substance_amount_0);
  EXPECT_GE(substance_amount_1, substance_amount_0);
}

TEST(SubstanceAmount, Constructor) {
  constexpr SubstanceAmount substance_amount_0;
  const SubstanceAmount substance_amount_1{
      2.0, Unit::SubstanceAmount::Kilomole};
  constexpr SubstanceAmount substance_amount_2{
      SubstanceAmount::Create<Unit::SubstanceAmount::Kilomole>(4.0)};
}

TEST(SubstanceAmount, Copy) {
  const SubstanceAmount reference{1.11, Unit::SubstanceAmount::Mole};
  const SubstanceAmount first{reference};
  EXPECT_EQ(first, reference);
  SubstanceAmount second = SubstanceAmount::Zero();
  second = reference;
  EXPECT_EQ(second, reference);
}

TEST(SubstanceAmount, Dimensions) {
  EXPECT_EQ(
      SubstanceAmount::Dimensions(), RelatedDimensions<Unit::SubstanceAmount>);
}

TEST(SubstanceAmount, Hash) {
  const SubstanceAmount substance_amount_0{
      10.0, Unit::SubstanceAmount::Kilomole};
  const SubstanceAmount substance_amount_1{
      10.000001, Unit::SubstanceAmount::Kilomole};
  const SubstanceAmount substance_amount_2{
      11.0, Unit::SubstanceAmount::Kilomole};
  const SubstanceAmount substance_amount_3{
      -10.0, Unit::SubstanceAmount::Kilomole};
  const SubstanceAmount substance_amount_4{
      20000.0, Unit::SubstanceAmount::Kilomole};
  const SubstanceAmount substance_amount_5{
      -123.456, Unit::SubstanceAmount::Kilomole};
  const std::hash<SubstanceAmount> hasher;
  EXPECT_NE(hasher(substance_amount_0), hasher(substance_amount_1));
  EXPECT_NE(hasher(substance_amount_0), hasher(substance_amount_2));
  EXPECT_NE(hasher(substance_amount_0), hasher(substance_amount_3));
  EXPECT_NE(hasher(substance_amount_0), hasher(substance_amount_4));
  EXPECT_NE(hasher(substance_amount_0), hasher(substance_amount_5));
  const std::unordered_set<SubstanceAmount> unordered{
      substance_amount_0, substance_amount_1, substance_amount_2,
      substance_amount_3, substance_amount_4, substance_amount_5};
}

TEST(SubstanceAmount, JSON) {
  EXPECT_EQ(SubstanceAmount(1.11, Unit::SubstanceAmount::Mole).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"mol\"}");
  EXPECT_EQ(SubstanceAmount(-5.0, Unit::SubstanceAmount::Kilomole)
                .JSON(Unit::SubstanceAmount::Kilomole),
            "{\"value\":-5.000000000000000,\"unit\":\"kmol\"}");
}

TEST(SubstanceAmount, Move) {
  const SubstanceAmount reference{1.11, Unit::SubstanceAmount::Mole};
  SubstanceAmount first{1.11, Unit::SubstanceAmount::Mole};
  SubstanceAmount second{std::move(first)};
  EXPECT_EQ(second, reference);
  SubstanceAmount third = SubstanceAmount::Zero();
  third = std::move(second);
  EXPECT_EQ(third, reference);
}

TEST(SubstanceAmount, Print) {
  EXPECT_EQ(SubstanceAmount(1.11, Unit::SubstanceAmount::Mole).Print(),
            "1.110000000000000 mol");
  EXPECT_EQ(SubstanceAmount(-5.0, Unit::SubstanceAmount::Kilomole)
                .Print(Unit::SubstanceAmount::Kilomole),
            "-5.000000000000000 kmol");
}

TEST(SubstanceAmount, SizeOf) {
  const SubstanceAmount substance_amount{1.11, Unit::SubstanceAmount::Mole};
  EXPECT_EQ(sizeof(substance_amount), sizeof(double));
}

TEST(SubstanceAmount, Stream) {
  const SubstanceAmount substance_amount{1.11, Unit::SubstanceAmount::Mole};
  std::ostringstream stream;
  stream << substance_amount;
  EXPECT_EQ(stream.str(), substance_amount.Print());
}

TEST(SubstanceAmount, Unit) {
  EXPECT_EQ(SubstanceAmount::Unit(), Standard<Unit::SubstanceAmount>);
}

TEST(SubstanceAmount, XML) {
  EXPECT_EQ(SubstanceAmount(1.11, Unit::SubstanceAmount::Mole).XML(),
            "<value>1.110000000000000</value><unit>mol</unit>");
  EXPECT_EQ(SubstanceAmount(-5.0, Unit::SubstanceAmount::Kilomole)
                .XML(Unit::SubstanceAmount::Kilomole),
            "<value>-5.000000000000000</value><unit>kmol</unit>");
}

TEST(SubstanceAmount, YAML) {
  EXPECT_EQ(SubstanceAmount(1.11, Unit::SubstanceAmount::Mole).YAML(),
            "{value:1.110000000000000,unit:\"mol\"}");
  EXPECT_EQ(SubstanceAmount(-5.0, Unit::SubstanceAmount::Kilomole)
                .YAML(Unit::SubstanceAmount::Kilomole),
            "{value:-5.000000000000000,unit:\"kmol\"}");
}

TEST(SubstanceAmount, Zero) {
  EXPECT_EQ(SubstanceAmount::Zero(),
            SubstanceAmount(0.0, Unit::SubstanceAmount::Mole));
}

}  // namespace

}  // namespace PhQ
