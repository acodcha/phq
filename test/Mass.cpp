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

#include "../include/PhQ/Mass.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Mass, Accessor) {
  const Mass mass{0.1, Unit::Mass::Kilogram};
  EXPECT_DOUBLE_EQ(mass.Value(), 0.1);
  EXPECT_DOUBLE_EQ(mass.Value(Unit::Mass::Gram), 0.1 * 1000.0);
}

TEST(Mass, Arithmetic) {
  const Mass mass0{1.0, Unit::Mass::Kilogram};
  EXPECT_EQ(mass0 + mass0, Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(mass0 - mass0, Mass(0.0, Unit::Mass::Kilogram));
  EXPECT_EQ(mass0 * 2.0, Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(2.0 * mass0, Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(mass0 / 2.0, Mass(0.5, Unit::Mass::Kilogram));
  EXPECT_EQ(mass0 / mass0, 1.0);

  Mass mass1{1.0, Unit::Mass::Kilogram};
  mass1 += Mass{1.0, Unit::Mass::Kilogram};
  EXPECT_EQ(mass1, Mass(2.0, Unit::Mass::Kilogram));

  Mass mass2{2.0, Unit::Mass::Kilogram};
  mass2 -= Mass{1.0, Unit::Mass::Kilogram};
  EXPECT_EQ(mass2, Mass(1.0, Unit::Mass::Kilogram));

  Mass mass3{1.0, Unit::Mass::Kilogram};
  mass3 *= 2.0;
  EXPECT_EQ(mass3, Mass(2.0, Unit::Mass::Kilogram));

  Mass mass4{2.0, Unit::Mass::Kilogram};
  mass4 /= 2.0;
  EXPECT_EQ(mass4, Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, Comparison) {
  const Mass mass0{0.1, Unit::Mass::Kilogram};
  const Mass mass1{0.2, Unit::Mass::Kilogram};
  EXPECT_EQ(mass0, mass0);
  EXPECT_NE(mass0, mass1);
  EXPECT_LT(mass0, mass1);
  EXPECT_GT(mass1, mass0);
  EXPECT_LE(mass0, mass0);
  EXPECT_LE(mass0, mass1);
  EXPECT_GE(mass0, mass0);
  EXPECT_GE(mass1, mass0);
}

TEST(Mass, Constructor) {
  constexpr Mass mass0;
  const Mass mass1{100.0, Unit::Mass::Gram};
  constexpr Mass mass2{Mass::Create<Unit::Mass::Gram>(100.0)};
}

TEST(Mass, Hash) {
  const Mass mass0{10.0, Unit::Mass::Gram};
  const Mass mass1{10.000001, Unit::Mass::Gram};
  const Mass mass2{11.0, Unit::Mass::Gram};
  const Mass mass3{-10.0, Unit::Mass::Gram};
  const Mass mass4{20000.0, Unit::Mass::Gram};
  const Mass mass5{-123.456, Unit::Mass::Gram};
  const std::hash<Mass> hasher;
  EXPECT_NE(hasher(mass0), hasher(mass1));
  EXPECT_NE(hasher(mass0), hasher(mass2));
  EXPECT_NE(hasher(mass0), hasher(mass3));
  EXPECT_NE(hasher(mass0), hasher(mass4));
  EXPECT_NE(hasher(mass0), hasher(mass5));
  const std::unordered_set<Mass> unordered{
      mass0, mass1, mass2, mass3, mass4, mass5};
}

TEST(Mass, JSON) {
  EXPECT_EQ(Mass(1.11, Unit::Mass::Kilogram).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"kg\"}");
  EXPECT_EQ(Mass(-5.0, Unit::Mass::Gram).JSON(Unit::Mass::Gram),
            "{\"value\":-5.000000000000000,\"unit\":\"g\"}");
}

TEST(Mass, Print) {
  EXPECT_EQ(Mass(1.11, Unit::Mass::Kilogram).Print(), "1.110000000000000 kg");
  EXPECT_EQ(Mass(-5.0, Unit::Mass::Gram).Print(Unit::Mass::Gram),
            "-5.000000000000000 g");
}

TEST(Mass, SizeOf) {
  const Mass mass{1.11, Unit::Mass::Kilogram};
  EXPECT_EQ(sizeof(mass), sizeof(double));
}

TEST(Mass, Stream) {
  const Mass mass{1.11, Unit::Mass::Kilogram};
  std::ostringstream stream;
  stream << mass;
  EXPECT_EQ(stream.str(), mass.Print());
}

TEST(Mass, XML) {
  EXPECT_EQ(Mass(1.11, Unit::Mass::Kilogram).XML(),
            "<value>1.110000000000000</value><unit>kg</unit>");
  EXPECT_EQ(Mass(-5.0, Unit::Mass::Gram).XML(Unit::Mass::Gram),
            "<value>-5.000000000000000</value><unit>g</unit>");
}

TEST(Mass, YAML) {
  EXPECT_EQ(Mass(1.11, Unit::Mass::Kilogram).YAML(),
            "{value:1.110000000000000,unit:\"kg\"}");
  EXPECT_EQ(Mass(-5.0, Unit::Mass::Gram).YAML(Unit::Mass::Gram),
            "{value:-5.000000000000000,unit:\"g\"}");
}

TEST(Mass, Zero) { EXPECT_EQ(Mass::Zero(), Mass(0.0, Unit::Mass::Kilogram)); }

}  // namespace

}  // namespace PhQ
