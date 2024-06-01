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

#include "../include/PhQ/Strain.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimensions.hpp"
#include "../include/PhQ/SymmetricDyad.hpp"

namespace PhQ {

namespace {

TEST(Strain, ArithmeticOperatorAddition) {
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) + Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0),
            Strain(3.0, -6.0, 9.0, -12.0, 15.0, -18.0));
}

TEST(Strain, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0) / 2.0, Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Strain, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * 2.0, Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  EXPECT_EQ(
      2.0 * Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0), Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
}

TEST(Strain, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Strain(3.0, -6.0, 9.0, -12.0, 15.0, -18.0) - Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0),
            Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Strain, AssignmentOperatorAddition) {
  Strain strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  strain += Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
  EXPECT_EQ(strain, Strain(3.0, -6.0, 9.0, -12.0, 15.0, -18.0));
}

TEST(Strain, AssignmentOperatorDivision) {
  Strain strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
  strain /= 2.0;
  EXPECT_EQ(strain, Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Strain, AssignmentOperatorMultiplication) {
  Strain strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  strain *= 2.0;
  EXPECT_EQ(strain, Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
}

TEST(Strain, AssignmentOperatorSubtraction) {
  Strain strain(3.0, -6.0, 9.0, -12.0, 15.0, -18.0);
  strain -= Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
  EXPECT_EQ(strain, Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Strain, ComparisonOperators) {
  constexpr Strain first(1.0, -2.0, 3.0, -4.0, 5.0, -6.000001);
  constexpr Strain second(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Strain, Constructor) {
  EXPECT_EQ(Strain(std::array<double, 6>{1.0, -2.0, 3.0, -4.0, 5.0, -6.0}),
            Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(Strain(SymmetricDyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0}),
            Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Strain, CopyAssignmentOperator) {
  {
    const Strain<float> first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    Strain<double> second = Strain<double>::Zero();
    second = first;
    EXPECT_EQ(second, Strain<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    const Strain<double> first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    Strain<double> second = Strain<double>::Zero();
    second = first;
    EXPECT_EQ(second, Strain<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    const Strain<long double> first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    Strain<double> second = Strain<double>::Zero();
    second = first;
    EXPECT_EQ(second, Strain<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
}

TEST(Strain, CopyConstructor) {
  {
    const Strain<float> first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    const Strain<double> second{first};
    EXPECT_EQ(second, Strain<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    const Strain<double> first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    const Strain<double> second{first};
    EXPECT_EQ(second, Strain<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    const Strain<long double> first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    const Strain<double> second{first};
    EXPECT_EQ(second, Strain<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
}

TEST(Strain, DefaultConstructor) {
  EXPECT_NO_THROW(Strain<>{});
}

TEST(Strain, Dimensions) {
  EXPECT_EQ(Strain<>::Dimensions(), Dimensionless);
}

TEST(Strain, Hash) {
  constexpr Strain first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  constexpr Strain second(1.0, -2.0, 3.0, -4.0, 5.0, -6.000001);
  constexpr Strain third(1.0, -2.0, 3.0, 4.0, 5.0, -6.0);
  const std::hash<Strain<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Strain, JSON) {
  EXPECT_EQ(
      Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).JSON(),
      "{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
          + ",\"yy\":" + Print(-4.0) + ",\"yz\":" + Print(5.0) + ",\"zz\":" + Print(-6.0) + "}");
}

TEST(Strain, MoveAssignmentOperator) {
  Strain first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  Strain second = Strain<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Strain, MoveConstructor) {
  Strain first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  const Strain second{std::move(first)};
  EXPECT_EQ(second, Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Strain, MutableValue) {
  Strain strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  SymmetricDyad<>& value = strain.MutableValue();
  value = SymmetricDyad{-7.0, 8.0, -9.0, 10.0, -11.0, 12.0};
  EXPECT_EQ(strain.Value(), SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
}

TEST(Strain, Print) {
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + "; " + Print(-6.0) + ")");
}

TEST(Strain, SetValue) {
  Strain strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  strain.SetValue(SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  EXPECT_EQ(strain.Value(), SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
}

TEST(Strain, SizeOf) {
  EXPECT_EQ(sizeof(Strain<>{}), 6 * sizeof(double));
}

TEST(Strain, Stream) {
  std::ostringstream stream;
  stream << Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  EXPECT_EQ(stream.str(), Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).Print());
}

TEST(Strain, Value) {
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).Value(),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Strain, XML) {
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).XML(),
            "<xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0) + "</xz><yy>"
                + Print(-4.0) + "</yy><yz>" + Print(5.0) + "</yz><zz>" + Print(-6.0) + "</zz>");
}

TEST(Strain, XYZ) {
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).xx(), ScalarStrain(1.0));
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).xy(), ScalarStrain(-2.0));
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).xz(), ScalarStrain(3.0));
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).yx(), ScalarStrain(-2.0));
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).yy(), ScalarStrain(-4.0));
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).yz(), ScalarStrain(5.0));
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).zx(), ScalarStrain(3.0));
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).zy(), ScalarStrain(5.0));
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).zz(), ScalarStrain(-6.0));
}

TEST(Strain, YAML) {
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).YAML(),
            "{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yy:" + Print(-4.0)
                + ",yz:" + Print(5.0) + ",zz:" + Print(-6.0) + "}");
}

TEST(Strain, Zero) {
  EXPECT_EQ(Strain<>::Zero(), Strain(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
