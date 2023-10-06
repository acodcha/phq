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

#include "../include/PhQ/MachNumber.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(MachNumber, ArithmeticAddition) {
  EXPECT_EQ(MachNumber(1.0) + MachNumber(2.0), MachNumber(3.0));

  MachNumber quantity{1.0};
  quantity += MachNumber(2.0);
  EXPECT_EQ(quantity, MachNumber(3.0));
}

TEST(MachNumber, ArithmeticDivision) {
  EXPECT_EQ(MachNumber(8.0) / 2.0, MachNumber(4.0));

  EXPECT_EQ(MachNumber(8.0) / MachNumber(2.0), 4.0);

  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond)
                / SoundSpeed(4.0, Unit::Speed::MetrePerSecond),
            MachNumber(2.0));

  MachNumber quantity{8.0};
  quantity /= 2.0;
  EXPECT_EQ(quantity, MachNumber(4.0));
}

TEST(MachNumber, ArithmeticMultiplication) {
  EXPECT_EQ(MachNumber(4.0) * 2.0, MachNumber(8.0));

  EXPECT_EQ(2.0 * MachNumber(4.0), MachNumber(8.0));

  MachNumber quantity{4.0};
  quantity *= 2.0;
  EXPECT_EQ(quantity, MachNumber(8.0));
}

TEST(MachNumber, ArithmeticSubtraction) {
  EXPECT_EQ(MachNumber(3.0) - MachNumber(2.0), MachNumber(1.0));

  MachNumber quantity{3.0};
  quantity -= MachNumber(2.0);
  EXPECT_EQ(quantity, MachNumber(1.0));
}

TEST(MachNumber, Comparisons) {
  const MachNumber first{1.11};
  const MachNumber second{2.22};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(MachNumber, CopyAssignment) {
  const MachNumber first{1.11};
  MachNumber second = MachNumber::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(MachNumber, CopyConstructor) {
  const MachNumber first{1.11};
  const MachNumber second{first};
  EXPECT_EQ(second, first);
}

TEST(MachNumber, DefaultConstructor) {
  EXPECT_NO_THROW(MachNumber{});
}

TEST(MachNumber, Dimensions) {
  EXPECT_EQ(MachNumber::Dimensions(), Dimensions{});
}

TEST(MachNumber, Hash) {
  const MachNumber first{1.11};
  const MachNumber second{1.110001};
  const MachNumber third{-1.11};
  const std::hash<MachNumber> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(MachNumber, JSON) {
  EXPECT_EQ(MachNumber(1.11).JSON(), "1.110000000000000");
}

TEST(MachNumber, MiscellaneousConstructors) {
  EXPECT_EQ(MachNumber(Speed(8.0, Unit::Speed::MetrePerSecond),
                       SoundSpeed(4.0, Unit::Speed::MetrePerSecond)),
            MachNumber(2.0));

  EXPECT_EQ(
      SoundSpeed(Speed(8.0, Unit::Speed::MetrePerSecond), MachNumber(4.0)),
      SoundSpeed(2.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(
      Speed(SoundSpeed(4.0, Unit::Speed::MetrePerSecond), MachNumber(2.0)),
      Speed(8.0, Unit::Speed::MetrePerSecond));
}

TEST(MachNumber, MoveAssignment) {
  const MachNumber first{1.11};
  MachNumber second{1.11};
  MachNumber third = MachNumber::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(MachNumber, MoveConstructor) {
  const MachNumber first{1.11};
  MachNumber second{1.11};
  MachNumber third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(MachNumber, MutableValue) {
  MachNumber quantity{1.11};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(value, 2.22);
}

TEST(MachNumber, Print) {
  EXPECT_EQ(MachNumber(1.11).Print(), "1.110000000000000");
}

TEST(MachNumber, SetValue) {
  MachNumber quantity{1.11};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(MachNumber, SizeOf) {
  EXPECT_EQ(sizeof(MachNumber{}), sizeof(double));
}

TEST(MachNumber, StandardConstructor) {
  EXPECT_NO_THROW(MachNumber(1.11));
}

TEST(MachNumber, Stream) {
  const MachNumber quantity{1.11};
  std::ostringstream stream;
  stream << quantity;
  EXPECT_EQ(stream.str(), quantity.Print());
}

TEST(MachNumber, Value) {
  EXPECT_EQ(MachNumber(1.11).Value(), 1.11);
}

TEST(MachNumber, XML) {
  EXPECT_EQ(MachNumber(1.11).XML(), "1.110000000000000");
}

TEST(MachNumber, YAML) {
  EXPECT_EQ(MachNumber(1.11).YAML(), "1.110000000000000");
}

TEST(MachNumber, Zero) {
  EXPECT_EQ(MachNumber::Zero(), MachNumber(0.0));
}

}  // namespace

}  // namespace PhQ
