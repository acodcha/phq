// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/MachNumber.hpp"

#include <cmath>
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
  MachNumber mach_number{1.0};
  mach_number += MachNumber(2.0);
  EXPECT_EQ(mach_number, MachNumber(3.0));
}

TEST(MachNumber, AssignmentOperatorDivision) {
  MachNumber mach_number{8.0};
  mach_number /= 2.0;
  EXPECT_EQ(mach_number, MachNumber(4.0));
}

TEST(MachNumber, AssignmentOperatorMultiplication) {
  MachNumber mach_number{4.0};
  mach_number *= 2.0;
  EXPECT_EQ(mach_number, MachNumber(8.0));
}

TEST(MachNumber, AssignmentOperatorSubtraction) {
  MachNumber mach_number{3.0};
  mach_number -= MachNumber(2.0);
  EXPECT_EQ(mach_number, MachNumber(1.0));
}

TEST(MachNumber, ComparisonOperators) {
  const MachNumber first{1.0};
  const MachNumber second{2.0};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(MachNumber, Constructor) {
  EXPECT_NO_THROW(MachNumber(1.0));
  EXPECT_EQ(MachNumber(Speed(8.0, Unit::Speed::MetrePerSecond),
                       SoundSpeed(4.0, Unit::Speed::MetrePerSecond)),
            MachNumber(2.0));
  EXPECT_EQ(SoundSpeed(Speed(8.0, Unit::Speed::MetrePerSecond), MachNumber(4.0)),
            SoundSpeed(2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Speed(SoundSpeed(4.0, Unit::Speed::MetrePerSecond), MachNumber(2.0)),
            Speed(8.0, Unit::Speed::MetrePerSecond));
}

TEST(MachNumber, CopyAssignmentOperator) {
  {
    const MachNumber<float> first(1.0F);
    MachNumber<double> second = MachNumber<double>::Zero();
    second = first;
    EXPECT_EQ(second, MachNumber<double>(1.0));
  }
  {
    const MachNumber<double> first(1.0);
    MachNumber<double> second = MachNumber<double>::Zero();
    second = first;
    EXPECT_EQ(second, MachNumber<double>(1.0));
  }
  {
    const MachNumber<long double> first(1.0L);
    MachNumber<double> second = MachNumber<double>::Zero();
    second = first;
    EXPECT_EQ(second, MachNumber<double>(1.0));
  }
}

TEST(MachNumber, CopyConstructor) {
  {
    const MachNumber<float> first(1.0F);
    const MachNumber<double> second{first};
    EXPECT_EQ(second, MachNumber<double>(1.0));
  }
  {
    const MachNumber<double> first(1.0);
    const MachNumber<double> second{first};
    EXPECT_EQ(second, MachNumber<double>(1.0));
  }
  {
    const MachNumber<long double> first(1.0L);
    const MachNumber<double> second{first};
    EXPECT_EQ(second, MachNumber<double>(1.0));
  }
}

TEST(MachNumber, DefaultConstructor) {
  EXPECT_NO_THROW(MachNumber<>{});
}

TEST(MachNumber, Dimensions) {
  EXPECT_EQ(MachNumber<>::Dimensions(), Dimensionless);
}

TEST(MachNumber, Hash) {
  const MachNumber first{1.0};
  const MachNumber second{1.00001};
  const MachNumber third{-1.0};
  const std::hash<MachNumber<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(MachNumber, JSON) {
  EXPECT_EQ(MachNumber(1.0).JSON(), Print(1.0));
}

TEST(MachNumber, Mathematics) {
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

TEST(MachNumber, MoveAssignmentOperator) {
  MachNumber first{1.0};
  MachNumber second = MachNumber<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, MachNumber(1.0));
}

TEST(MachNumber, MoveConstructor) {
  MachNumber first{1.0};
  const MachNumber second{std::move(first)};
  EXPECT_EQ(second, MachNumber(1.0));
}

TEST(MachNumber, MutableValue) {
  MachNumber mach_number{1.0};
  double& value = mach_number.MutableValue();
  value = 2.0;
  EXPECT_EQ(mach_number.Value(), 2.0);
}

TEST(MachNumber, Print) {
  EXPECT_EQ(MachNumber(1.0).Print(), Print(1.0));
}

TEST(MachNumber, SetValue) {
  MachNumber mach_number{1.0};
  mach_number.SetValue(2.0);
  EXPECT_EQ(mach_number.Value(), 2.0);
}

TEST(MachNumber, SizeOf) {
  EXPECT_EQ(sizeof(MachNumber<>{}), sizeof(double));
}

TEST(MachNumber, Stream) {
  std::ostringstream stream;
  stream << MachNumber(1.0);
  EXPECT_EQ(stream.str(), MachNumber(1.0).Print());
}

TEST(MachNumber, Value) {
  EXPECT_EQ(MachNumber(1.0).Value(), 1.0);
}

TEST(MachNumber, XML) {
  EXPECT_EQ(MachNumber(1.0).XML(), Print(1.0));
}

TEST(MachNumber, YAML) {
  EXPECT_EQ(MachNumber(1.0).YAML(), Print(1.0));
}

TEST(MachNumber, Zero) {
  EXPECT_EQ(MachNumber<>::Zero(), MachNumber(0.0));
}

}  // namespace

}  // namespace PhQ
