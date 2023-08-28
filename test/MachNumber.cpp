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

#include <unordered_set>

namespace PhQ {

namespace {

TEST(MachNumber, Accessor) {
  const MachNumber mach_number{0.1};
  EXPECT_DOUBLE_EQ(mach_number.Value(), 0.1);
}

TEST(MachNumber, Arithmetic) {
  const MachNumber mach_number_0{0.0};
  const MachNumber mach_number_1{1.0};
  const MachNumber mach_number_2{2.0};
  EXPECT_EQ(mach_number_1 + mach_number_1, mach_number_2);
  EXPECT_EQ(mach_number_1 - mach_number_1, mach_number_0);
  EXPECT_EQ(mach_number_1 * 2.0, mach_number_2);
  EXPECT_EQ(2.0 * mach_number_1, mach_number_2);
  EXPECT_EQ(mach_number_2 / 2.0, mach_number_1);
  EXPECT_EQ(mach_number_2 / mach_number_2, 1.0);

  MachNumber mach_number_3{mach_number_1};
  mach_number_3 += mach_number_1;
  EXPECT_EQ(mach_number_3, mach_number_2);

  MachNumber mach_number_4{mach_number_1};
  mach_number_4 -= mach_number_1;
  EXPECT_EQ(mach_number_4, mach_number_0);

  MachNumber mach_number_5{mach_number_1};
  mach_number_5 *= 2.0;
  EXPECT_EQ(mach_number_5, mach_number_2);

  MachNumber mach_number_6{mach_number_2};
  mach_number_6 /= 2.0;
  EXPECT_EQ(mach_number_6, mach_number_1);
}

TEST(MachNumber, Comparison) {
  const MachNumber mach_number_0{0.1};
  const MachNumber mach_number_1{0.2};
  EXPECT_EQ(mach_number_0, mach_number_0);
  EXPECT_NE(mach_number_0, mach_number_1);
  EXPECT_LT(mach_number_0, mach_number_1);
  EXPECT_GT(mach_number_1, mach_number_0);
  EXPECT_LE(mach_number_0, mach_number_0);
  EXPECT_LE(mach_number_0, mach_number_1);
  EXPECT_GE(mach_number_0, mach_number_0);
  EXPECT_GE(mach_number_1, mach_number_0);
}

TEST(MachNumber, Constructor) {
  constexpr MachNumber mach_number_0;
  constexpr MachNumber mach_number_1{0.5};
  const Speed speed{2.0, Unit::Speed::MetrePerSecond};
  const SoundSpeed sound_speed{4.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(MachNumber(speed, sound_speed), mach_number_1);
  EXPECT_EQ(SoundSpeed(speed, mach_number_1), sound_speed);
  EXPECT_EQ(Speed(sound_speed, mach_number_1), speed);
}

TEST(MachNumber, Hash) {
  const MachNumber mach_number_0{10.0};
  const MachNumber mach_number_1{10.000001};
  const MachNumber mach_number_2{11.0};
  const MachNumber mach_number_3{-10.0};
  const MachNumber mach_number_4{20000.0};
  const MachNumber mach_number_5{-123.456};
  const std::hash<MachNumber> hasher;
  EXPECT_NE(hasher(mach_number_0), hasher(mach_number_1));
  EXPECT_NE(hasher(mach_number_0), hasher(mach_number_2));
  EXPECT_NE(hasher(mach_number_0), hasher(mach_number_3));
  EXPECT_NE(hasher(mach_number_0), hasher(mach_number_4));
  EXPECT_NE(hasher(mach_number_0), hasher(mach_number_5));
  const std::unordered_set<MachNumber> unordered{
      mach_number_0, mach_number_1, mach_number_2,
      mach_number_3, mach_number_4, mach_number_5};
}

TEST(MachNumber, JSON) {
  EXPECT_EQ(MachNumber(1.11).JSON(), "1.110000000000000");
}

TEST(MachNumber, Print) {
  EXPECT_EQ(MachNumber(1.11).Print(), "1.110000000000000");
}

TEST(MachNumber, SizeOf) {
  const MachNumber mach_number{1.11};
  EXPECT_EQ(sizeof(mach_number), sizeof(double));
}

TEST(MachNumber, Stream) {
  const MachNumber mach_number{1.11};
  std::ostringstream stream;
  stream << mach_number;
  EXPECT_EQ(stream.str(), mach_number.Print());
}

TEST(MachNumber, XML) {
  EXPECT_EQ(MachNumber(1.11).XML(), "1.110000000000000");
}

TEST(MachNumber, YAML) {
  EXPECT_EQ(MachNumber(1.11).YAML(), "1.110000000000000");
}

TEST(MachNumber, Zero) { EXPECT_EQ(MachNumber::Zero(), MachNumber(0.0)); }

}  // namespace

}  // namespace PhQ
