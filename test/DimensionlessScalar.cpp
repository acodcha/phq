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

#include <cmath>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>

#include "../include/PhQ/Dimensions.hpp"
#include "../include/PhQ/MachNumber.hpp"

namespace PhQ {

namespace {

// Since PhQ::DimensionlessScalar is an abstract base class, tests use PhQ::MachNumber, which is one
// of its derived classes.

TEST(DimensionlessScalar, Dimensions) {
  EXPECT_EQ(MachNumber::Dimensions(), Dimensionless);
}

TEST(DimensionlessScalar, Hash) {
  const MachNumber first{1.0};
  const MachNumber second{1.00001};
  const MachNumber third{-1.0};
  const std::hash<MachNumber> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionlessScalar, JSON) {
  EXPECT_EQ(MachNumber(1.0).JSON(), Print(1.0));
}

TEST(DimensionlessScalar, Mathematics) {
  EXPECT_EQ(std::abs(MachNumber(-1.0)), std::abs(-1.0));
  EXPECT_EQ(std::cbrt(MachNumber(-8.0)), std::cbrt(-8.0));
  EXPECT_EQ(std::exp(MachNumber(2.0)), std::exp(2.0));
  EXPECT_EQ(std::log(MachNumber(2.0)), std::log(2.0));
  EXPECT_EQ(std::log2(MachNumber(8.0)), std::log2(8.0));
  EXPECT_EQ(std::log10(MachNumber(100.0)), std::log10(100.0));
  EXPECT_EQ(std::pow(MachNumber(4.0), 3), std::pow(4.0, 3));
  EXPECT_EQ(std::pow(MachNumber(4.0), 3L), std::pow(4.0, 3L));
  EXPECT_EQ(std::pow(MachNumber(4.0), 3LL), std::pow(4.0, 3LL));
  EXPECT_EQ(std::pow(MachNumber(4.0), 3.0F), std::pow(4.0, 3.0F));
  EXPECT_EQ(std::pow(MachNumber(4.0), 3.0), std::pow(4.0, 3.0));
  EXPECT_EQ(std::pow(MachNumber(4.0), 3.0L), std::pow(4.0, 3.0L));
  EXPECT_EQ(std::sqrt(MachNumber(9.0)), std::sqrt(9.0));
}

TEST(DimensionlessScalar, MutableValue) {
  MachNumber mach_number{1.0};
  double& value = mach_number.MutableValue();
  value = 2.0;
  EXPECT_EQ(mach_number.Value(), 2.0);
}

TEST(DimensionlessScalar, Print) {
  EXPECT_EQ(MachNumber(1.0).Print(), Print(1.0));
}

TEST(DimensionlessScalar, SetValue) {
  MachNumber mach_number{1.0};
  mach_number.SetValue(2.0);
  EXPECT_EQ(mach_number.Value(), 2.0);
}

TEST(DimensionlessScalar, SizeOf) {
  EXPECT_EQ(sizeof(MachNumber{}), sizeof(double));
}

TEST(DimensionlessScalar, Stream) {
  std::ostringstream stream;
  stream << MachNumber{1.0};
  EXPECT_EQ(stream.str(), MachNumber(1.0).Print());
}

TEST(DimensionlessScalar, Value) {
  EXPECT_EQ(MachNumber(1.0).Value(), 1.0);
}

TEST(DimensionlessScalar, XML) {
  EXPECT_EQ(MachNumber(1.0).XML(), Print(1.0));
}

TEST(DimensionlessScalar, YAML) {
  EXPECT_EQ(MachNumber(1.0).YAML(), Print(1.0));
}

TEST(DimensionlessScalar, Zero) {
  EXPECT_EQ(MachNumber::Zero(), MachNumber(0.0));
}

}  // namespace

}  // namespace PhQ
