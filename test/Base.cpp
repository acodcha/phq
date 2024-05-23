// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
  {
    std::string text;
    Lowercase(text);
    EXPECT_EQ(text, "");
  }
  {
    std::string text{"AbCd123!?^-_"};
    Lowercase(text);
    EXPECT_EQ(text, "abcd123!?^-_");
  }
}

TEST(Base, LowercaseCopy) {
  EXPECT_EQ(LowercaseCopy(""), "");
  EXPECT_EQ(LowercaseCopy("AbCd123!?^-_"), "abcd123!?^-_");
}

TEST(Base, ParseToNumberDefault) {
  EXPECT_EQ(ParseToNumber<>(""), std::nullopt);
  EXPECT_EQ(ParseToNumber<>("Hello world!"), std::nullopt);
  ASSERT_TRUE(ParseToNumber<>("NaN").has_value());
  EXPECT_EQ(ParseToNumber<>("NaN").value(), std::numeric_limits<double>::quiet_NaN());
  ASSERT_TRUE(ParseToNumber<>("-NaN").has_value());
  EXPECT_EQ(ParseToNumber<>("-NaN").value(), std::numeric_limits<double>::quiet_NaN());
  ASSERT_TRUE(ParseToNumber<>("infinity").has_value());
  EXPECT_EQ(ParseToNumber<>("infinity").value(), std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseToNumber<>("inf").has_value());
  EXPECT_EQ(ParseToNumber<>("inf").value(), std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseToNumber<>("-infinity").has_value());
  EXPECT_EQ(ParseToNumber<>("-infinity").value(), -std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseToNumber<>("-inf").has_value());
  EXPECT_EQ(ParseToNumber<>("-inf").value(), -std::numeric_limits<double>::infinity());
  EXPECT_EQ(ParseToNumber<>("-1.0e1000000"), std::nullopt);
  EXPECT_EQ(ParseToNumber<>("-1.23456789e12"), -1.23456789e12);
  EXPECT_EQ(ParseToNumber<>("-100"), -100.0);
  EXPECT_EQ(ParseToNumber<>("-1.23456789"), -1.23456789);
  EXPECT_EQ(ParseToNumber<>("-0"), 0.0);
  EXPECT_EQ(ParseToNumber<>("0"), 0.0);
  EXPECT_EQ(ParseToNumber<>("1.23456789"), 1.23456789);
  EXPECT_EQ(ParseToNumber<>("100"), 100.0);
  EXPECT_EQ(ParseToNumber<>("1.23456789e12"), 1.23456789e12);
  EXPECT_EQ(ParseToNumber<>("1.0e1000000"), std::nullopt);
}

TEST(Base, ParseToNumberDouble) {
  EXPECT_EQ(ParseToNumber<double>(""), std::nullopt);
  EXPECT_EQ(ParseToNumber<double>("Hello world!"), std::nullopt);
  ASSERT_TRUE(ParseToNumber<double>("NaN").has_value());
  EXPECT_EQ(ParseToNumber<double>("NaN").value(), std::numeric_limits<double>::quiet_NaN());
  ASSERT_TRUE(ParseToNumber<double>("-NaN").has_value());
  EXPECT_EQ(ParseToNumber<double>("-NaN").value(), std::numeric_limits<double>::quiet_NaN());
  ASSERT_TRUE(ParseToNumber<double>("infinity").has_value());
  EXPECT_EQ(ParseToNumber<double>("infinity").value(), std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseToNumber<double>("inf").has_value());
  EXPECT_EQ(ParseToNumber<double>("inf").value(), std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseToNumber<double>("-infinity").has_value());
  EXPECT_EQ(ParseToNumber<double>("-infinity").value(), -std::numeric_limits<double>::infinity());
  ASSERT_TRUE(ParseToNumber<double>("-inf").has_value());
  EXPECT_EQ(ParseToNumber<double>("-inf").value(), -std::numeric_limits<double>::infinity());
  EXPECT_EQ(ParseToNumber<double>("-1.0e1000000"), std::nullopt);
  EXPECT_EQ(ParseToNumber<double>("-1.23456789e12"), -1.23456789e12);
  EXPECT_EQ(ParseToNumber<double>("-100"), -100.0);
  EXPECT_EQ(ParseToNumber<double>("-1.23456789"), -1.23456789);
  EXPECT_EQ(ParseToNumber<double>("-0"), 0.0);
  EXPECT_EQ(ParseToNumber<double>("0"), 0.0);
  EXPECT_EQ(ParseToNumber<double>("1.23456789"), 1.23456789);
  EXPECT_EQ(ParseToNumber<double>("100"), 100.0);
  EXPECT_EQ(ParseToNumber<double>("1.23456789e12"), 1.23456789e12);
  EXPECT_EQ(ParseToNumber<double>("1.0e1000000"), std::nullopt);
}

TEST(Base, ParseToNumberFloat) {
  EXPECT_EQ(ParseToNumber<float>(""), std::nullopt);
  EXPECT_EQ(ParseToNumber<float>("Hello world!"), std::nullopt);
  ASSERT_TRUE(ParseToNumber<float>("NaN").has_value());
  EXPECT_EQ(ParseToNumber<float>("NaN").value(), std::numeric_limits<float>::quiet_NaN());
  ASSERT_TRUE(ParseToNumber<float>("-NaN").has_value());
  EXPECT_EQ(ParseToNumber<float>("-NaN").value(), std::numeric_limits<float>::quiet_NaN());
  ASSERT_TRUE(ParseToNumber<float>("infinity").has_value());
  EXPECT_EQ(ParseToNumber<float>("infinity").value(), std::numeric_limits<float>::infinity());
  ASSERT_TRUE(ParseToNumber<float>("inf").has_value());
  EXPECT_EQ(ParseToNumber<float>("inf").value(), std::numeric_limits<float>::infinity());
  ASSERT_TRUE(ParseToNumber<float>("-infinity").has_value());
  EXPECT_EQ(ParseToNumber<float>("-infinity").value(), -std::numeric_limits<float>::infinity());
  ASSERT_TRUE(ParseToNumber<float>("-inf").has_value());
  EXPECT_EQ(ParseToNumber<float>("-inf").value(), -std::numeric_limits<float>::infinity());
  EXPECT_EQ(ParseToNumber<float>("-1.0e1000000"), std::nullopt);
  EXPECT_EQ(ParseToNumber<float>("-1.23456789e12"), -1.23456789e12F);
  EXPECT_EQ(ParseToNumber<float>("-100"), -100.0F);
  EXPECT_EQ(ParseToNumber<float>("-1.23456789"), -1.23456789F);
  EXPECT_EQ(ParseToNumber<float>("-0"), 0.0F);
  EXPECT_EQ(ParseToNumber<float>("0"), 0.0F);
  EXPECT_EQ(ParseToNumber<float>("1.23456789"), 1.23456789F);
  EXPECT_EQ(ParseToNumber<float>("100"), 100.0F);
  EXPECT_EQ(ParseToNumber<float>("1.23456789e12"), 1.23456789e12F);
  EXPECT_EQ(ParseToNumber<float>("1.0e1000000"), std::nullopt);
}

TEST(Base, ParseToNumberLongDouble) {
  EXPECT_EQ(ParseToNumber<long double>(""), std::nullopt);
  EXPECT_EQ(ParseToNumber<long double>("Hello world!"), std::nullopt);
  ASSERT_TRUE(ParseToNumber<long double>("NaN").has_value());
  EXPECT_EQ(
      ParseToNumber<long double>("NaN").value(), std::numeric_limits<long double>::quiet_NaN());
  ASSERT_TRUE(ParseToNumber<long double>("-NaN").has_value());
  EXPECT_EQ(
      ParseToNumber<long double>("-NaN").value(), std::numeric_limits<long double>::quiet_NaN());
  ASSERT_TRUE(ParseToNumber<long double>("infinity").has_value());
  EXPECT_EQ(
      ParseToNumber<long double>("infinity").value(), std::numeric_limits<long double>::infinity());
  ASSERT_TRUE(ParseToNumber<long double>("inf").has_value());
  EXPECT_EQ(
      ParseToNumber<long double>("inf").value(), std::numeric_limits<long double>::infinity());
  ASSERT_TRUE(ParseToNumber<long double>("-infinity").has_value());
  EXPECT_EQ(ParseToNumber<long double>("-infinity").value(),
            -std::numeric_limits<long double>::infinity());
  ASSERT_TRUE(ParseToNumber<long double>("-inf").has_value());
  EXPECT_EQ(
      ParseToNumber<long double>("-inf").value(), -std::numeric_limits<long double>::infinity());
  EXPECT_EQ(ParseToNumber<long double>("-1.0e1000000"), std::nullopt);
  EXPECT_EQ(ParseToNumber<long double>("-1.23456789e12"), -1.23456789e12L);
  EXPECT_EQ(ParseToNumber<long double>("-100"), -100.0L);
  EXPECT_EQ(ParseToNumber<long double>("-1.23456789"), -1.23456789L);
  EXPECT_EQ(ParseToNumber<long double>("-0"), 0.0L);
  EXPECT_EQ(ParseToNumber<long double>("0"), 0.0L);
  EXPECT_EQ(ParseToNumber<long double>("1.23456789"), 1.23456789L);
  EXPECT_EQ(ParseToNumber<long double>("100"), 100.0L);
  EXPECT_EQ(ParseToNumber<long double>("1.23456789e12"), 1.23456789e12L);
  EXPECT_EQ(ParseToNumber<long double>("1.0e1000000"), std::nullopt);
}

TEST(Base, Pi) {
  EXPECT_EQ(Pi<>, static_cast<double>(3.141592653589793238462643383279502884L));
  EXPECT_EQ(Pi<float>, static_cast<float>(3.141592653589793238462643383279502884L));
  EXPECT_EQ(Pi<double>, static_cast<double>(3.141592653589793238462643383279502884L));
  EXPECT_EQ(Pi<long double>, 3.141592653589793238462643383279502884L);
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

TEST(Base, Replace) {
  {
    std::string text;
    Replace(text, 'A', 'B');
    EXPECT_EQ(text, "");
  }
  {
    std::string text{"AbCd123!?^-_"};
    Replace(text, 'C', 'D');
    EXPECT_EQ(text, "AbDd123!?^-_");
    Replace(text, 'X', 'Y');
    EXPECT_EQ(text, "AbDd123!?^-_");
  }
}

TEST(Base, ReplaceCopy) {
  EXPECT_EQ(ReplaceCopy("", 'A', 'B'), "");
  EXPECT_EQ(ReplaceCopy("AbCd123!?^-_", 'C', 'D'), "AbDd123!?^-_");
  EXPECT_EQ(ReplaceCopy("AbCd123!?^-_", 'X', 'Y'), "AbCd123!?^-_");
}

TEST(Base, SnakeCase) {
  {
    std::string text;
    SnakeCase(text);
    EXPECT_EQ(text, "");
  }
  {
    std::string text{"Ab Cd 123   !?^-_"};
    SnakeCase(text);
    EXPECT_EQ(text, "ab_cd_123___!?^-_");
  }
}

TEST(Base, SnakeCaseCopy) {
  EXPECT_EQ(SnakeCaseCopy(""), "");
  EXPECT_EQ(SnakeCaseCopy("Ab Cd 123   !?^-_"), "ab_cd_123___!?^-_");
}

TEST(Base, SplitByWhitespace) {
  EXPECT_EQ(SplitByWhitespace(""), std::vector<std::string>());
  EXPECT_EQ(SplitByWhitespace("aaa bbb   ccc\t\tddd\neee"),
            std::vector<std::string>({std::string("aaa"), std::string("bbb"), std::string("ccc"),
                                      std::string("ddd"), std::string("eee")}));
}

TEST(Base, Uppercase) {
  {
    std::string text;
    Uppercase(text);
    EXPECT_EQ(text, "");
  }
  {
    std::string text{"AbCd123!?^-_"};
    Uppercase(text);
    EXPECT_EQ(text, "ABCD123!?^-_");
  }
}

TEST(Base, UppercaseCopy) {
  EXPECT_EQ(UppercaseCopy(""), "");
  EXPECT_EQ(UppercaseCopy("AbCd123.!?*^-_"), "ABCD123.!?*^-_");
}

}  // namespace

}  // namespace PhQ
