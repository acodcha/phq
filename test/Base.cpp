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

#include "../include/PhQ/Base.hpp"

#include <cmath>
#include <gtest/gtest.h>
#include <numbers>
#include <optional>
#include <string>
#include <vector>

namespace PhQ {

namespace {

TEST(Base, Lowercase) {
  EXPECT_EQ(Lowercase(""), "");
  EXPECT_EQ(Lowercase("AbCd123!?^-_"), "abcd123!?^-_");
}

TEST(Base, ParseNumberDefault) {
  EXPECT_EQ(ParseNumber<>(""), std::nullopt);
  EXPECT_EQ(ParseNumber<>("Hello world!"), std::nullopt);
  ASSERT_TRUE(ParseNumber<>("NaN").has_value());
  ASSERT_TRUE(ParseNumber<>("-NaN").has_value());
  ASSERT_TRUE(ParseNumber<>("infinity").has_value());
  EXPECT_EQ(ParseNumber<>("infinity").value(), std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseNumber<>("inf").has_value());
  EXPECT_EQ(ParseNumber<>("inf").value(), std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseNumber<>("-infinity").has_value());
  EXPECT_EQ(ParseNumber<>("-infinity").value(), -std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseNumber<>("-inf").has_value());
  EXPECT_EQ(ParseNumber<>("-inf").value(), -std::numeric_limits<double>::infinity());
  EXPECT_EQ(ParseNumber<>("-1.0e1000000"), std::nullopt);
  EXPECT_EQ(ParseNumber<>("-1.23456789e12"), -1.23456789e12);
  EXPECT_EQ(ParseNumber<>("-100"), -100.0);
  EXPECT_EQ(ParseNumber<>("-1.23456789"), -1.23456789);
  EXPECT_EQ(ParseNumber<>("-0"), 0.0);
  EXPECT_EQ(ParseNumber<>("0"), 0.0);
  EXPECT_EQ(ParseNumber<>("1.23456789"), 1.23456789);
  EXPECT_EQ(ParseNumber<>("100"), 100.0);
  EXPECT_EQ(ParseNumber<>("1.23456789e12"), 1.23456789e12);
  EXPECT_EQ(ParseNumber<>("1.0e1000000"), std::nullopt);
}

TEST(Base, ParseNumberDouble) {
  EXPECT_EQ(ParseNumber<double>(""), std::nullopt);
  EXPECT_EQ(ParseNumber<double>("Hello world!"), std::nullopt);
  ASSERT_TRUE(ParseNumber<double>("NaN").has_value());
  ASSERT_TRUE(ParseNumber<double>("-NaN").has_value());
  ASSERT_TRUE(ParseNumber<double>("infinity").has_value());
  EXPECT_EQ(ParseNumber<double>("infinity").value(), std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseNumber<double>("inf").has_value());
  EXPECT_EQ(ParseNumber<double>("inf").value(), std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseNumber<double>("-infinity").has_value());
  EXPECT_EQ(ParseNumber<double>("-infinity").value(), -std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseNumber<double>("-inf").has_value());
  EXPECT_EQ(ParseNumber<double>("-inf").value(), -std::numeric_limits<double>::infinity());
  EXPECT_EQ(ParseNumber<double>("-1.0e1000000"), std::nullopt);
  EXPECT_EQ(ParseNumber<double>("-1.23456789e12"), -1.23456789e12);
  EXPECT_EQ(ParseNumber<double>("-100"), -100.0);
  EXPECT_EQ(ParseNumber<double>("-1.23456789"), -1.23456789);
  EXPECT_EQ(ParseNumber<double>("-0"), 0.0);
  EXPECT_EQ(ParseNumber<double>("0"), 0.0);
  EXPECT_EQ(ParseNumber<double>("1.23456789"), 1.23456789);
  EXPECT_EQ(ParseNumber<double>("100"), 100.0);
  EXPECT_EQ(ParseNumber<double>("1.23456789e12"), 1.23456789e12);
  EXPECT_EQ(ParseNumber<double>("1.0e1000000"), std::nullopt);
}

TEST(Base, ParseNumberFloat) {
  EXPECT_EQ(ParseNumber<float>(""), std::nullopt);
  EXPECT_EQ(ParseNumber<float>("Hello world!"), std::nullopt);
  ASSERT_TRUE(ParseNumber<float>("NaN").has_value());
  ASSERT_TRUE(ParseNumber<float>("-NaN").has_value());
  ASSERT_TRUE(ParseNumber<float>("infinity").has_value());
  EXPECT_EQ(ParseNumber<float>("infinity").value(), std::numeric_limits<float>::infinity());
  ASSERT_TRUE(ParseNumber<float>("inf").has_value());
  EXPECT_EQ(ParseNumber<float>("inf").value(), std::numeric_limits<float>::infinity());
  ASSERT_TRUE(ParseNumber<float>("-infinity").has_value());
  EXPECT_EQ(ParseNumber<float>("-infinity").value(), -std::numeric_limits<float>::infinity());
  ASSERT_TRUE(ParseNumber<float>("-inf").has_value());
  EXPECT_EQ(ParseNumber<float>("-inf").value(), -std::numeric_limits<float>::infinity());
  EXPECT_EQ(ParseNumber<float>("-1.0e1000000"), std::nullopt);
  EXPECT_EQ(ParseNumber<float>("-1.23456789e12"), -1.23456789e12F);
  EXPECT_EQ(ParseNumber<float>("-100"), -100.0F);
  EXPECT_EQ(ParseNumber<float>("-1.23456789"), -1.23456789F);
  EXPECT_EQ(ParseNumber<float>("-0"), 0.0F);
  EXPECT_EQ(ParseNumber<float>("0"), 0.0F);
  EXPECT_EQ(ParseNumber<float>("1.23456789"), 1.23456789F);
  EXPECT_EQ(ParseNumber<float>("100"), 100.0F);
  EXPECT_EQ(ParseNumber<float>("1.23456789e12"), 1.23456789e12F);
  EXPECT_EQ(ParseNumber<float>("1.0e1000000"), std::nullopt);
}

TEST(Base, ParseNumberLongDouble) {
  EXPECT_EQ(ParseNumber<long double>(""), std::nullopt);
  EXPECT_EQ(ParseNumber<long double>("Hello world!"), std::nullopt);
  ASSERT_TRUE(ParseNumber<long double>("NaN").has_value());
  ASSERT_TRUE(ParseNumber<long double>("-NaN").has_value());
  ASSERT_TRUE(ParseNumber<long double>("infinity").has_value());
  EXPECT_EQ(
      ParseNumber<long double>("infinity").value(), std::numeric_limits<long double>::infinity());
  ASSERT_TRUE(ParseNumber<long double>("inf").has_value());
  EXPECT_EQ(ParseNumber<long double>("inf").value(), std::numeric_limits<long double>::infinity());
  ASSERT_TRUE(ParseNumber<long double>("-infinity").has_value());
  EXPECT_EQ(
      ParseNumber<long double>("-infinity").value(), -std::numeric_limits<long double>::infinity());
  ASSERT_TRUE(ParseNumber<long double>("-inf").has_value());
  EXPECT_EQ(
      ParseNumber<long double>("-inf").value(), -std::numeric_limits<long double>::infinity());
  EXPECT_EQ(ParseNumber<long double>("-1.0e1000000"), std::nullopt);
  EXPECT_EQ(ParseNumber<long double>("-1.23456789e12"), -1.23456789e12L);
  EXPECT_EQ(ParseNumber<long double>("-100"), -100.0L);
  EXPECT_EQ(ParseNumber<long double>("-1.23456789"), -1.23456789L);
  EXPECT_EQ(ParseNumber<long double>("-0"), 0.0L);
  EXPECT_EQ(ParseNumber<long double>("0"), 0.0L);
  EXPECT_EQ(ParseNumber<long double>("1.23456789"), 1.23456789L);
  EXPECT_EQ(ParseNumber<long double>("100"), 100.0L);
  EXPECT_EQ(ParseNumber<long double>("1.23456789e12"), 1.23456789e12L);
  EXPECT_EQ(ParseNumber<long double>("1.0e1000000"), std::nullopt);
}

TEST(Base, Pi) {
  EXPECT_EQ(Pi<>, static_cast<double>(3.141592653589793238462643383279502884L));
  EXPECT_EQ(Pi<float>, static_cast<float>(3.141592653589793238462643383279502884L));
  EXPECT_EQ(Pi<double>, static_cast<double>(3.141592653589793238462643383279502884L));
  EXPECT_EQ(Pi<long double>, 3.141592653589793238462643383279502884L);
}

TEST(Base, PrintDouble) {
  EXPECT_EQ(Print(-16384.0), "-1.63840000000000000e+04");
  EXPECT_EQ(Print(-1024.0), "-1024.00000000000000");
  EXPECT_EQ(Print(-128.0), "-128.000000000000000");
  EXPECT_EQ(Print(-16.0), "-16.0000000000000000");
  EXPECT_EQ(Print(-1.0), "-1.00000000000000000");
  EXPECT_EQ(Print(-0.125), "-0.125000000000000000");
  EXPECT_EQ(Print(-0.015625), "-0.0156250000000000000");
  EXPECT_EQ(Print(-0.001953125), "-0.00195312500000000000");
  EXPECT_EQ(Print(-0.0001220703125), "-1.22070312500000000e-04");
  EXPECT_EQ(Print(-0.0), "0");
  EXPECT_EQ(Print(0.0), "0");
  EXPECT_EQ(Print(0.0001220703125), "1.22070312500000000e-04");
  EXPECT_EQ(Print(0.001953125), "0.00195312500000000000");
  EXPECT_EQ(Print(0.015625), "0.0156250000000000000");
  EXPECT_EQ(Print(0.125), "0.125000000000000000");
  EXPECT_EQ(Print(1.0), "1.00000000000000000");
  EXPECT_EQ(Print(16.0), "16.0000000000000000");
  EXPECT_EQ(Print(128.0), "128.000000000000000");
  EXPECT_EQ(Print(1024.0), "1024.00000000000000");
  EXPECT_EQ(Print(16384.0), "1.63840000000000000e+04");
}

TEST(Base, PrintFloat) {
  EXPECT_EQ(Print(-16384.0F), "-1.638400000e+04");
  EXPECT_EQ(Print(-1024.0F), "-1024.000000");
  EXPECT_EQ(Print(-128.0F), "-128.0000000");
  EXPECT_EQ(Print(-16.0F), "-16.00000000");
  EXPECT_EQ(Print(-1.0F), "-1.000000000");
  EXPECT_EQ(Print(-0.125F), "-0.1250000000");
  EXPECT_EQ(Print(-0.015625F), "-0.01562500000");
  EXPECT_EQ(Print(-0.001953125F), "-0.001953125000");
  EXPECT_EQ(Print(-0.0001220703125F), "-1.220703125e-04");
  EXPECT_EQ(Print(-0.0F), "0");
  EXPECT_EQ(Print(0.0F), "0");
  EXPECT_EQ(Print(0.0001220703125F), "1.220703125e-04");
  EXPECT_EQ(Print(0.001953125F), "0.001953125000");
  EXPECT_EQ(Print(0.015625F), "0.01562500000");
  EXPECT_EQ(Print(0.125F), "0.1250000000");
  EXPECT_EQ(Print(1.0F), "1.000000000");
  EXPECT_EQ(Print(16.0F), "16.00000000");
  EXPECT_EQ(Print(128.0F), "128.0000000");
  EXPECT_EQ(Print(1024.0F), "1024.000000");
  EXPECT_EQ(Print(16384.0F), "1.638400000e+04");
}

TEST(Base, PrintLongDouble) {
  // The implementation of the long double type can vary on different systems, so we simply compare
  // it to the double type.
  EXPECT_GE(Print(-16384.0L).size(), Print(-16384.0).size());
  EXPECT_GE(Print(-1024.0L).size(), Print(-1024.0).size());
  EXPECT_GE(Print(-128.0L).size(), Print(-128.0).size());
  EXPECT_GE(Print(-16.0L).size(), Print(-16.0).size());
  EXPECT_GE(Print(-1.0L).size(), Print(-1.0).size());
  EXPECT_GE(Print(-0.125L).size(), Print(-0.125).size());
  EXPECT_GE(Print(-0.015625L).size(), Print(-0.015625).size());
  EXPECT_GE(Print(-0.001953125L).size(), Print(-0.001953125).size());
  EXPECT_GE(Print(-0.0001220703125L).size(), Print(-0.0001220703125).size());
  EXPECT_EQ(Print(-0.0L), "0");
  EXPECT_EQ(Print(0.0L), "0");
  EXPECT_GE(Print(0.0001220703125L).size(), Print(0.0001220703125).size());
  EXPECT_GE(Print(0.001953125L).size(), Print(0.001953125).size());
  EXPECT_GE(Print(0.015625L).size(), Print(0.015625).size());
  EXPECT_GE(Print(0.125L).size(), Print(0.125).size());
  EXPECT_GE(Print(1.0L).size(), Print(1.0).size());
  EXPECT_GE(Print(16.0L).size(), Print(16.0).size());
  EXPECT_GE(Print(128.0L).size(), Print(128.0).size());
  EXPECT_GE(Print(1024.0L).size(), Print(1024.0).size());
  EXPECT_GE(Print(16384.0L).size(), Print(16384.0).size());
}

TEST(Base, SnakeCase) {
  EXPECT_EQ(SnakeCase(""), "");
  EXPECT_EQ(SnakeCase("Ab Cd 123   !?^-_"), "ab_cd_123___!?^-_");
}

TEST(Base, Uppercase) {
  EXPECT_EQ(Uppercase(""), "");
  EXPECT_EQ(Uppercase("AbCd123.!?*^-_"), "ABCD123.!?*^-_");
}

}  // namespace

}  // namespace PhQ
