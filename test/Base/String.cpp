// Copyright 2020 Alexandre Coderre-Chabot
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

#include "../../include/PhQ/Base/String.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(BaseString, LowerCase) {
  std::string text0;
  LowerCase(text0);
  EXPECT_EQ(text0, "");
  std::string text1{"AbCd123!?^-_"};
  LowerCase(text1);
  EXPECT_EQ(text1, "abcd123!?^-_");
}

TEST(BaseString, LowerCaseCopy) {
  EXPECT_EQ(LowerCaseCopy(""), "");
  EXPECT_EQ(LowerCaseCopy("AbCd123!?^-_"), "abcd123!?^-_");
}

TEST(BaseString, ParseToInteger) {
  EXPECT_EQ(ParseToInteger(""), std::nullopt);
  EXPECT_EQ(ParseToInteger("-Inf"), std::nullopt);
  EXPECT_EQ(ParseToInteger("-1.23456789e10"), std::nullopt);
  EXPECT_EQ(ParseToInteger("-7"), -7);
  EXPECT_EQ(ParseToInteger("-1.23456789"), std::nullopt);
  EXPECT_EQ(ParseToInteger("42"), 42);
  EXPECT_EQ(ParseToInteger("Inf"), std::nullopt);
  EXPECT_EQ(ParseToInteger("NaN"), std::nullopt);
}

TEST(BaseString, ParseToDouble) {
  EXPECT_EQ(ParseToDouble(""), std::nullopt);
  EXPECT_EQ(ParseToDouble("-Inf"), std::nullopt);
  EXPECT_EQ(ParseToDouble("-1.23456789e10"), -1.23456789e10);
  EXPECT_EQ(ParseToDouble("-7"), -7.0);
  EXPECT_EQ(ParseToDouble("-1.23456789"), -1.23456789);
  EXPECT_EQ(ParseToDouble("42"), 42.0);
  EXPECT_EQ(ParseToDouble("1.0e10000"), std::nullopt);
  EXPECT_EQ(ParseToDouble("Inf"), std::nullopt);
  EXPECT_EQ(ParseToDouble("NaN"), std::nullopt);
}

TEST(BaseString, Print) {
  EXPECT_EQ(Print(-12345678.9), "-1.234568e+07");
  EXPECT_EQ(Print(-10000000.0), "-1.000000e+07");
  EXPECT_EQ(Print(-1234567.89), "-1.234568e+06");
  EXPECT_EQ(Print(-1000000.0), "-1.000000e+06");
  EXPECT_EQ(Print(-123456.789), "-1.234568e+05");
  EXPECT_EQ(Print(-100000.0), "-1.000000e+05");
  EXPECT_EQ(Print(-12345.6789), "-1.234568e+04");
  EXPECT_EQ(Print(-10000.0), "-1.000000e+04");
  EXPECT_EQ(Print(-1234.56789), "-1234.568");
  EXPECT_EQ(Print(-1000.0), "-1000.000");
  EXPECT_EQ(Print(-123.456789), "-123.4568");
  EXPECT_EQ(Print(-100.0), "-100.0000");
  EXPECT_EQ(Print(-12.3456789), "-12.34568");
  EXPECT_EQ(Print(-10.0), "-10.00000");
  EXPECT_EQ(Print(-1.23456789), "-1.234568");
  EXPECT_EQ(Print(-1.0), "-1.000000");
  EXPECT_EQ(Print(-0.123456789), "-0.1234568");
  EXPECT_EQ(Print(-0.1), "-0.1000000");
  EXPECT_EQ(Print(-0.0123456789), "-0.01234568");
  EXPECT_EQ(Print(-0.01), "-0.01000000");
  EXPECT_EQ(Print(-0.00123456789), "-0.001234568");
  EXPECT_EQ(Print(-0.001), "-0.001000000");
  EXPECT_EQ(Print(-0.000123456789), "-1.234568e-04");
  EXPECT_EQ(Print(-0.0001), "-1.000000e-04");
  EXPECT_EQ(Print(-0.0000123456789), "-1.234568e-05");
  EXPECT_EQ(Print(-0.00001), "-1.000000e-05");
  EXPECT_EQ(Print(-0.00000123456789), "-1.234568e-06");
  EXPECT_EQ(Print(-0.000001), "-1.000000e-06");
  EXPECT_EQ(Print(-0.000000123456789), "-1.234568e-07");
  EXPECT_EQ(Print(-0.0000001), "-1.000000e-07");
  EXPECT_EQ(Print(0.0), "0");
  EXPECT_EQ(Print(0.0000001), "1.000000e-07");
  EXPECT_EQ(Print(0.000000123456789), "1.234568e-07");
  EXPECT_EQ(Print(0.000001), "1.000000e-06");
  EXPECT_EQ(Print(0.00000123456789), "1.234568e-06");
  EXPECT_EQ(Print(0.00001), "1.000000e-05");
  EXPECT_EQ(Print(0.0000123456789), "1.234568e-05");
  EXPECT_EQ(Print(0.0001), "1.000000e-04");
  EXPECT_EQ(Print(0.000123456789), "1.234568e-04");
  EXPECT_EQ(Print(0.001), "0.001000000");
  EXPECT_EQ(Print(0.00123456789), "0.001234568");
  EXPECT_EQ(Print(0.01), "0.01000000");
  EXPECT_EQ(Print(0.0123456789), "0.01234568");
  EXPECT_EQ(Print(0.1), "0.1000000");
  EXPECT_EQ(Print(0.123456789), "0.1234568");
  EXPECT_EQ(Print(1.0), "1.000000");
  EXPECT_EQ(Print(1.23456789), "1.234568");
  EXPECT_EQ(Print(10.0), "10.00000");
  EXPECT_EQ(Print(12.3456789), "12.34568");
  EXPECT_EQ(Print(100.0), "100.0000");
  EXPECT_EQ(Print(123.456789), "123.4568");
  EXPECT_EQ(Print(1000.0), "1000.000");
  EXPECT_EQ(Print(1234.56789), "1234.568");
  EXPECT_EQ(Print(10000.0), "1.000000e+04");
  EXPECT_EQ(Print(12345.6789), "1.234568e+04");
  EXPECT_EQ(Print(100000.0), "1.000000e+05");
  EXPECT_EQ(Print(123456.789), "1.234568e+05");
  EXPECT_EQ(Print(1000000.0), "1.000000e+06");
  EXPECT_EQ(Print(1234567.89), "1.234568e+06");
  EXPECT_EQ(Print(10000000.0), "1.000000e+07");
  EXPECT_EQ(Print(12345678.9), "1.234568e+07");
}

TEST(BaseString, Replace) {
  std::string text0;
  Replace(text0, 'A', 'B');
  EXPECT_EQ(text0, "");
  std::string text1{"AbCd123!?^-_"};
  Replace(text1, 'C', 'D');
  EXPECT_EQ(text1, "AbDd123!?^-_");
  Replace(text1, 'X', 'Y');
  EXPECT_EQ(text1, "AbDd123!?^-_");
}

TEST(BaseString, ReplaceCopy) {
  EXPECT_EQ(ReplaceCopy("", 'A', 'B'), "");
  EXPECT_EQ(ReplaceCopy("AbCd123!?^-_", 'C', 'D'), "AbDd123!?^-_");
  EXPECT_EQ(ReplaceCopy("AbCd123!?^-_", 'X', 'Y'), "AbCd123!?^-_");
}

TEST(BaseString, SnakeCase) {
  std::string text0;
  SnakeCase(text0);
  EXPECT_EQ(text0, "");
  std::string text1{"Ab Cd 123   !?^-_"};
  SnakeCase(text1);
  EXPECT_EQ(text1, "ab_cd_123___!?^-_");
}

TEST(BaseString, SnakeCaseCopy) {
  EXPECT_EQ(SnakeCaseCopy(""), "");
  EXPECT_EQ(SnakeCaseCopy("Ab Cd 123   !?^-_"), "ab_cd_123___!?^-_");
}

TEST(BaseString, SplitByWhitespace) {
  EXPECT_EQ(SplitByWhitespace(""), std::vector<std::string>());
  EXPECT_EQ(SplitByWhitespace("aaa bbb   ccc\t\tddd\neee"),
            std::vector<std::string>({std::string("aaa"), std::string("bbb"),
                                      std::string("ccc"), std::string("ddd"),
                                      std::string("eee")}));
}

TEST(BaseString, UpperCase) {
  std::string text0;
  UpperCase(text0);
  EXPECT_EQ(text0, "");
  std::string text1{"AbCd123!?^-_"};
  UpperCase(text1);
  EXPECT_EQ(text1, "ABCD123!?^-_");
}

TEST(BaseString, UpperCaseCopy) {
  EXPECT_EQ(UpperCaseCopy(""), "");
  EXPECT_EQ(UpperCaseCopy("AbCd123.!?*^-_"), "ABCD123.!?*^-_");
}

}  // namespace

}  // namespace PhQ
