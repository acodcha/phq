// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#include "../include/PhQ/MachNumber.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimensions.hpp"
#include "../include/PhQ/SoundSpeed.hpp"
#include "../include/PhQ/Speed.hpp"
#include "../include/PhQ/Unit/Speed.hpp"

namespace PhQ {

namespace {

TEST(MachNumber, ArithmeticOperatorAddition) {
  EXPECT_EQ(MachNumber(1.0) + MachNumber(2.0), MachNumber(3.0));
}

TEST(MachNumber, ArithmeticOperatorDivision) {
  EXPECT_EQ(MachNumber(8.0) / 2.0, MachNumber(4.0));

  EXPECT_EQ(MachNumber(8.0) / MachNumber(2.0), 4.0);

  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond) / SoundSpeed(4.0, Unit::Speed::MetrePerSecond),
            MachNumber(2.0));
}

TEST(MachNumber, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(MachNumber(4.0) * 2.0, MachNumber(8.0));

  EXPECT_EQ(2.0 * MachNumber(4.0), MachNumber(8.0));

  EXPECT_EQ(MachNumber(2.0) * SoundSpeed(4.0, Unit::Speed::MetrePerSecond),
            Speed(8.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(SoundSpeed(2.0, Unit::Speed::MetrePerSecond) * MachNumber(4.0),
            Speed(8.0, Unit::Speed::MetrePerSecond));
}

TEST(MachNumber, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(MachNumber(3.0) - MachNumber(2.0), MachNumber(1.0));
}

TEST(MachNumber, AssignmentOperatorAddition) {
  MachNumber quantity{1.0};
  quantity += MachNumber(2.0);
  EXPECT_EQ(quantity, MachNumber(3.0));
}

TEST(MachNumber, AssignmentOperatorDivision) {
  MachNumber quantity{8.0};
  quantity /= 2.0;
  EXPECT_EQ(quantity, MachNumber(4.0));
}

TEST(MachNumber, AssignmentOperatorMultiplication) {
  MachNumber quantity{4.0};
  quantity *= 2.0;
  EXPECT_EQ(quantity, MachNumber(8.0));
}

TEST(MachNumber, AssignmentOperatorSubtraction) {
  MachNumber quantity{3.0};
  quantity -= MachNumber(2.0);
  EXPECT_EQ(quantity, MachNumber(1.0));
}

TEST(MachNumber, ComparisonOperators) {
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

TEST(MachNumber, CopyAssignmentOperator) {
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
  EXPECT_EQ(MachNumber::Dimensions(), Dimensionless);
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

  EXPECT_EQ(SoundSpeed(Speed(8.0, Unit::Speed::MetrePerSecond), MachNumber(4.0)),
            SoundSpeed(2.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Speed(SoundSpeed(4.0, Unit::Speed::MetrePerSecond), MachNumber(2.0)),
            Speed(8.0, Unit::Speed::MetrePerSecond));
}

TEST(MachNumber, MoveAssignmentOperator) {
  MachNumber first{1.11};
  MachNumber second = MachNumber::Zero();
  second = std::move(first);
  EXPECT_EQ(second, MachNumber(1.11));
}

TEST(MachNumber, MoveConstructor) {
  MachNumber first{1.11};
  const MachNumber second{std::move(first)};
  EXPECT_EQ(second, MachNumber(1.11));
}

TEST(MachNumber, MutableValue) {
  MachNumber quantity{1.11};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
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
  std::ostringstream stream;
  stream << MachNumber(1.11);
  EXPECT_EQ(stream.str(), MachNumber(1.11).Print());
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
