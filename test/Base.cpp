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

#include "../include/PhQ/Base.hpp"

#include <gtest/gtest.h>
#include <optional>
#include <string>
#include <vector>

namespace PhQ {

namespace {

TEST(Base, Pi) {
  EXPECT_EQ(Pi, 3.14159265358979323846);
}

TEST(Base, PrecisionAbbreviation) {
  EXPECT_EQ(Abbreviation(Precision::Double), "Double");
  EXPECT_EQ(Abbreviation(Precision::Single), "Single");
}

TEST(Base, PrecisionParse) {
  EXPECT_EQ(Parse<Precision>("DOUBLE"), Precision::Double);
  EXPECT_EQ(Parse<Precision>("Double"), Precision::Double);
  EXPECT_EQ(Parse<Precision>("double"), Precision::Double);
  EXPECT_EQ(Parse<Precision>("SINGLE"), Precision::Single);
  EXPECT_EQ(Parse<Precision>("Single"), Precision::Single);
  EXPECT_EQ(Parse<Precision>("single"), Precision::Single);
}

TEST(Base, Lowercase) {
  std::string text0;
  Lowercase(text0);
  EXPECT_EQ(text0, "");
  std::string text1{"AbCd123!?^-_"};
  Lowercase(text1);
  EXPECT_EQ(text1, "abcd123!?^-_");
}

TEST(Base, LowercaseCopy) {
  EXPECT_EQ(LowercaseCopy(""), "");
  EXPECT_EQ(LowercaseCopy("AbCd123!?^-_"), "abcd123!?^-_");
}

TEST(Base, ParseToInteger) {
  EXPECT_EQ(ParseToInteger(""), std::nullopt);
  EXPECT_EQ(ParseToInteger("-Inf"), std::nullopt);
  EXPECT_EQ(ParseToInteger("-1.23456789e10"), std::nullopt);
  EXPECT_EQ(ParseToInteger("-7"), -7);
  EXPECT_EQ(ParseToInteger("-1.23456789"), std::nullopt);
  EXPECT_EQ(ParseToInteger("42"), 42);
  EXPECT_EQ(ParseToInteger("Inf"), std::nullopt);
  EXPECT_EQ(ParseToInteger("NaN"), std::nullopt);
}

TEST(Base, ParseToDouble) {
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

TEST(Base, PrintDefault) {
  EXPECT_EQ(Print(-12345678.9012345678901234567890), "-1.234567890123457e+07");
  EXPECT_EQ(Print(-10000000.0), "-1.000000000000000e+07");
  EXPECT_EQ(Print(-1234567.89012345678901234567890), "-1.234567890123457e+06");
  EXPECT_EQ(Print(-1000000.0), "-1.000000000000000e+06");
  EXPECT_EQ(Print(-123456.789012345678901234567890), "-1.234567890123457e+05");
  EXPECT_EQ(Print(-100000.0), "-1.000000000000000e+05");
  EXPECT_EQ(Print(-12345.6789012345678901234567890), "-1.234567890123457e+04");
  EXPECT_EQ(Print(-10000.0), "-1.000000000000000e+04");
  EXPECT_EQ(Print(-1234.56789012345678901234567890), "-1234.567890123457");
  EXPECT_EQ(Print(-1000.0), "-1000.000000000000");
  EXPECT_EQ(Print(-123.456789012345678901234567890), "-123.4567890123457");
  EXPECT_EQ(Print(-100.0), "-100.0000000000000");
  EXPECT_EQ(Print(-12.3456789012345678901234567890), "-12.34567890123457");
  EXPECT_EQ(Print(-10.0), "-10.00000000000000");
  EXPECT_EQ(Print(-1.23456789012345678901234567890), "-1.234567890123457");
  EXPECT_EQ(Print(-1.0), "-1.000000000000000");
  EXPECT_EQ(Print(-0.123456789012345678901234567890), "-0.1234567890123457");
  EXPECT_EQ(Print(-0.1), "-0.1000000000000000");
  EXPECT_EQ(Print(-0.0123456789012345678901234567890), "-0.01234567890123457");
  EXPECT_EQ(Print(-0.01), "-0.01000000000000000");
  EXPECT_EQ(Print(-0.00123456789012345678901234567890),
            "-0."
            "001234567890123457");
  EXPECT_EQ(Print(-0.001), "-0.001000000000000000");
  EXPECT_EQ(Print(-0.000123456789012345678901234567890), "-1.234567890123457e-04");
  EXPECT_EQ(Print(-0.0001), "-1.000000000000000e-04");
  EXPECT_EQ(Print(-0.0000123456789012345678901234567890), "-1.234567890123457e-05");
  EXPECT_EQ(Print(-0.00001), "-1.000000000000000e-05");
  EXPECT_EQ(Print(-0.00000123456789012345678901234567890), "-1.234567890123457e-06");
  EXPECT_EQ(Print(-0.000001), "-1.000000000000000e-06");
  EXPECT_EQ(Print(-0.000000123456789012345678901234567890), "-1.234567890123457e-07");
  EXPECT_EQ(Print(-0.0000001), "-1.000000000000000e-07");
  EXPECT_EQ(Print(0.0), "0");
  EXPECT_EQ(Print(0.0000001), "1.000000000000000e-07");
  EXPECT_EQ(Print(0.000000123456789012345678901234567890), "1.234567890123457e-07");
  EXPECT_EQ(Print(0.000001), "1.000000000000000e-06");
  EXPECT_EQ(Print(0.00000123456789012345678901234567890), "1.234567890123457e-06");
  EXPECT_EQ(Print(0.00001), "1.000000000000000e-05");
  EXPECT_EQ(Print(0.0000123456789012345678901234567890), "1.234567890123457e-05");
  EXPECT_EQ(Print(0.0001), "1.000000000000000e-04");
  EXPECT_EQ(Print(0.000123456789012345678901234567890),
            "1.234567890123457e-"
            "04");
  EXPECT_EQ(Print(0.001), "0.001000000000000000");
  EXPECT_EQ(Print(0.00123456789012345678901234567890), "0.001234567890123457");
  EXPECT_EQ(Print(0.01), "0.01000000000000000");
  EXPECT_EQ(Print(0.0123456789012345678901234567890), "0.01234567890123457");
  EXPECT_EQ(Print(0.1), "0.1000000000000000");
  EXPECT_EQ(Print(0.123456789012345678901234567890), "0.1234567890123457");
  EXPECT_EQ(Print(1.0), "1.000000000000000");
  EXPECT_EQ(Print(1.23456789012345678901234567890), "1.234567890123457");
  EXPECT_EQ(Print(10.0), "10.00000000000000");
  EXPECT_EQ(Print(12.3456789012345678901234567890), "12.34567890123457");
  EXPECT_EQ(Print(100.0), "100.0000000000000");
  EXPECT_EQ(Print(123.456789012345678901234567890), "123.4567890123457");
  EXPECT_EQ(Print(1000.0), "1000.000000000000");
  EXPECT_EQ(Print(1234.56789012345678901234567890), "1234.567890123457");
  EXPECT_EQ(Print(10000.0), "1.000000000000000e+04");
  EXPECT_EQ(Print(12345.6789012345678901234567890), "1.234567890123457e+04");
  EXPECT_EQ(Print(100000.0), "1.000000000000000e+05");
  EXPECT_EQ(Print(123456.789012345678901234567890), "1.234567890123457e+05");
  EXPECT_EQ(Print(1000000.0), "1.000000000000000e+06");
  EXPECT_EQ(Print(1234567.89012345678901234567890), "1.234567890123457e+06");
  EXPECT_EQ(Print(10000000.0), "1.000000000000000e+07");
  EXPECT_EQ(Print(12345678.9012345678901234567890), "1.234567890123457e+07");
}

TEST(Base, PrintDoublePrecision) {
  EXPECT_EQ(Print(-12345678.9012345678901234567890, Precision::Double), "-1.234567890123457e+07");
  EXPECT_EQ(Print(-10000000.0, Precision::Double), "-1.000000000000000e+07");
  EXPECT_EQ(Print(-1234567.89012345678901234567890, Precision::Double), "-1.234567890123457e+06");
  EXPECT_EQ(Print(-1000000.0, Precision::Double), "-1.000000000000000e+06");
  EXPECT_EQ(Print(-123456.789012345678901234567890, Precision::Double), "-1.234567890123457e+05");
  EXPECT_EQ(Print(-100000.0, Precision::Double), "-1.000000000000000e+05");
  EXPECT_EQ(Print(-12345.6789012345678901234567890, Precision::Double), "-1.234567890123457e+04");
  EXPECT_EQ(Print(-10000.0, Precision::Double), "-1.000000000000000e+04");
  EXPECT_EQ(Print(-1234.56789012345678901234567890, Precision::Double), "-1234.567890123457");
  EXPECT_EQ(Print(-1000.0, Precision::Double), "-1000.000000000000");
  EXPECT_EQ(Print(-123.456789012345678901234567890, Precision::Double), "-123.4567890123457");
  EXPECT_EQ(Print(-100.0, Precision::Double), "-100.0000000000000");
  EXPECT_EQ(Print(-12.3456789012345678901234567890, Precision::Double), "-12.34567890123457");
  EXPECT_EQ(Print(-10.0, Precision::Double), "-10.00000000000000");
  EXPECT_EQ(Print(-1.23456789012345678901234567890, Precision::Double), "-1.234567890123457");
  EXPECT_EQ(Print(-1.0, Precision::Double), "-1.000000000000000");
  EXPECT_EQ(Print(-0.123456789012345678901234567890, Precision::Double), "-0.1234567890123457");
  EXPECT_EQ(Print(-0.1, Precision::Double), "-0.1000000000000000");
  EXPECT_EQ(Print(-0.0123456789012345678901234567890, Precision::Double), "-0.01234567890123457");
  EXPECT_EQ(Print(-0.01, Precision::Double), "-0.01000000000000000");
  EXPECT_EQ(Print(-0.00123456789012345678901234567890, Precision::Double), "-0.001234567890123457");
  EXPECT_EQ(Print(-0.001, Precision::Double), "-0.001000000000000000");
  EXPECT_EQ(
      Print(-0.000123456789012345678901234567890, Precision::Double), "-1.234567890123457e-04");
  EXPECT_EQ(Print(-0.0001, Precision::Double), "-1.000000000000000e-04");
  EXPECT_EQ(
      Print(-0.0000123456789012345678901234567890, Precision::Double), "-1.234567890123457e-05");
  EXPECT_EQ(Print(-0.00001, Precision::Double), "-1.000000000000000e-05");
  EXPECT_EQ(
      Print(-0.00000123456789012345678901234567890, Precision::Double), "-1.234567890123457e-06");
  EXPECT_EQ(Print(-0.000001, Precision::Double), "-1.000000000000000e-06");
  EXPECT_EQ(
      Print(-0.000000123456789012345678901234567890, Precision::Double), "-1.234567890123457e-07");
  EXPECT_EQ(Print(-0.0000001, Precision::Double), "-1.000000000000000e-07");
  EXPECT_EQ(Print(0.0, Precision::Double), "0");
  EXPECT_EQ(Print(0.0000001, Precision::Double), "1.000000000000000e-07");
  EXPECT_EQ(
      Print(0.000000123456789012345678901234567890, Precision::Double), "1.234567890123457e-07");
  EXPECT_EQ(Print(0.000001, Precision::Double), "1.000000000000000e-06");
  EXPECT_EQ(
      Print(0.00000123456789012345678901234567890, Precision::Double), "1.234567890123457e-06");
  EXPECT_EQ(Print(0.00001, Precision::Double), "1.000000000000000e-05");
  EXPECT_EQ(
      Print(0.0000123456789012345678901234567890, Precision::Double), "1.234567890123457e-05");
  EXPECT_EQ(Print(0.0001, Precision::Double), "1.000000000000000e-04");
  EXPECT_EQ(Print(0.000123456789012345678901234567890, Precision::Double), "1.234567890123457e-04");
  EXPECT_EQ(Print(0.001, Precision::Double), "0.001000000000000000");
  EXPECT_EQ(Print(0.00123456789012345678901234567890, Precision::Double), "0.001234567890123457");
  EXPECT_EQ(Print(0.01, Precision::Double), "0.01000000000000000");
  EXPECT_EQ(Print(0.0123456789012345678901234567890, Precision::Double), "0.01234567890123457");
  EXPECT_EQ(Print(0.1, Precision::Double), "0.1000000000000000");
  EXPECT_EQ(Print(0.123456789012345678901234567890, Precision::Double), "0.1234567890123457");
  EXPECT_EQ(Print(1.0, Precision::Double), "1.000000000000000");
  EXPECT_EQ(Print(1.23456789012345678901234567890, Precision::Double), "1.234567890123457");
  EXPECT_EQ(Print(10.0, Precision::Double), "10.00000000000000");
  EXPECT_EQ(Print(12.3456789012345678901234567890, Precision::Double), "12.34567890123457");
  EXPECT_EQ(Print(100.0, Precision::Double), "100.0000000000000");
  EXPECT_EQ(Print(123.456789012345678901234567890, Precision::Double), "123.4567890123457");
  EXPECT_EQ(Print(1000.0, Precision::Double), "1000.000000000000");
  EXPECT_EQ(Print(1234.56789012345678901234567890, Precision::Double), "1234.567890123457");
  EXPECT_EQ(Print(10000.0, Precision::Double), "1.000000000000000e+04");
  EXPECT_EQ(Print(12345.6789012345678901234567890, Precision::Double), "1.234567890123457e+04");
  EXPECT_EQ(Print(100000.0, Precision::Double), "1.000000000000000e+05");
  EXPECT_EQ(Print(123456.789012345678901234567890, Precision::Double), "1.234567890123457e+05");
  EXPECT_EQ(Print(1000000.0, Precision::Double), "1.000000000000000e+06");
  EXPECT_EQ(Print(1234567.89012345678901234567890, Precision::Double), "1.234567890123457e+06");
  EXPECT_EQ(Print(10000000.0, Precision::Double), "1.000000000000000e+07");
  EXPECT_EQ(Print(12345678.9012345678901234567890, Precision::Double), "1.234567890123457e+07");
}

TEST(Base, PrintSinglePrecision) {
  EXPECT_EQ(Print(-12345678.9012345678901234567890, Precision::Single), "-1.234568e+07");
  EXPECT_EQ(Print(-10000000.0, Precision::Single), "-1.000000e+07");
  EXPECT_EQ(Print(-1234567.89012345678901234567890, Precision::Single), "-1.234568e+06");
  EXPECT_EQ(Print(-1000000.0, Precision::Single), "-1.000000e+06");
  EXPECT_EQ(Print(-123456.789012345678901234567890, Precision::Single), "-1.234568e+05");
  EXPECT_EQ(Print(-100000.0, Precision::Single), "-1.000000e+05");
  EXPECT_EQ(Print(-12345.6789012345678901234567890, Precision::Single), "-1.234568e+04");
  EXPECT_EQ(Print(-10000.0, Precision::Single), "-1.000000e+04");
  EXPECT_EQ(Print(-1234.56789012345678901234567890, Precision::Single), "-1234.568");
  EXPECT_EQ(Print(-1000.0, Precision::Single), "-1000.000");
  EXPECT_EQ(Print(-123.456789012345678901234567890, Precision::Single), "-123.4568");
  EXPECT_EQ(Print(-100.0, Precision::Single), "-100.0000");
  EXPECT_EQ(Print(-12.3456789012345678901234567890, Precision::Single), "-12.34568");
  EXPECT_EQ(Print(-10.0, Precision::Single), "-10.00000");
  EXPECT_EQ(Print(-1.23456789012345678901234567890, Precision::Single), "-1.234568");
  EXPECT_EQ(Print(-1.0, Precision::Single), "-1.000000");
  EXPECT_EQ(Print(-0.123456789012345678901234567890, Precision::Single), "-0.1234568");
  EXPECT_EQ(Print(-0.1, Precision::Single), "-0.1000000");
  EXPECT_EQ(Print(-0.0123456789012345678901234567890, Precision::Single), "-0.01234568");
  EXPECT_EQ(Print(-0.01, Precision::Single), "-0.01000000");
  EXPECT_EQ(Print(-0.00123456789012345678901234567890, Precision::Single), "-0.001234568");
  EXPECT_EQ(Print(-0.001, Precision::Single), "-0.001000000");
  EXPECT_EQ(Print(-0.000123456789012345678901234567890, Precision::Single), "-1.234568e-04");
  EXPECT_EQ(Print(-0.0001, Precision::Single), "-1.000000e-04");
  EXPECT_EQ(Print(-0.0000123456789012345678901234567890, Precision::Single), "-1.234568e-05");
  EXPECT_EQ(Print(-0.00001, Precision::Single), "-1.000000e-05");
  EXPECT_EQ(Print(-0.00000123456789012345678901234567890, Precision::Single), "-1.234568e-06");
  EXPECT_EQ(Print(-0.000001, Precision::Single), "-1.000000e-06");
  EXPECT_EQ(Print(-0.000000123456789012345678901234567890, Precision::Single), "-1.234568e-07");
  EXPECT_EQ(Print(-0.0000001, Precision::Single), "-1.000000e-07");
  EXPECT_EQ(Print(0.0, Precision::Single), "0");
  EXPECT_EQ(Print(0.0000001, Precision::Single), "1.000000e-07");
  EXPECT_EQ(Print(0.000000123456789012345678901234567890, Precision::Single), "1.234568e-07");
  EXPECT_EQ(Print(0.000001, Precision::Single), "1.000000e-06");
  EXPECT_EQ(Print(0.00000123456789012345678901234567890, Precision::Single), "1.234568e-06");
  EXPECT_EQ(Print(0.00001, Precision::Single), "1.000000e-05");
  EXPECT_EQ(Print(0.0000123456789012345678901234567890, Precision::Single), "1.234568e-05");
  EXPECT_EQ(Print(0.0001, Precision::Single), "1.000000e-04");
  EXPECT_EQ(Print(0.000123456789012345678901234567890, Precision::Single), "1.234568e-04");
  EXPECT_EQ(Print(0.001, Precision::Single), "0.001000000");
  EXPECT_EQ(Print(0.00123456789012345678901234567890, Precision::Single), "0.001234568");
  EXPECT_EQ(Print(0.01, Precision::Single), "0.01000000");
  EXPECT_EQ(Print(0.0123456789012345678901234567890, Precision::Single), "0.01234568");
  EXPECT_EQ(Print(0.1, Precision::Single), "0.1000000");
  EXPECT_EQ(Print(0.123456789012345678901234567890, Precision::Single), "0.1234568");
  EXPECT_EQ(Print(1.0, Precision::Single), "1.000000");
  EXPECT_EQ(Print(1.23456789012345678901234567890, Precision::Single), "1.234568");
  EXPECT_EQ(Print(10.0, Precision::Single), "10.00000");
  EXPECT_EQ(Print(12.3456789012345678901234567890, Precision::Single), "12.34568");
  EXPECT_EQ(Print(100.0, Precision::Single), "100.0000");
  EXPECT_EQ(Print(123.456789012345678901234567890, Precision::Single), "123.4568");
  EXPECT_EQ(Print(1000.0, Precision::Single), "1000.000");
  EXPECT_EQ(Print(1234.56789012345678901234567890, Precision::Single), "1234.568");
  EXPECT_EQ(Print(10000.0, Precision::Single), "1.000000e+04");
  EXPECT_EQ(Print(12345.6789012345678901234567890, Precision::Single), "1.234568e+04");
  EXPECT_EQ(Print(100000.0, Precision::Single), "1.000000e+05");
  EXPECT_EQ(Print(123456.789012345678901234567890, Precision::Single), "1.234568e+05");
  EXPECT_EQ(Print(1000000.0, Precision::Single), "1.000000e+06");
  EXPECT_EQ(Print(1234567.89012345678901234567890, Precision::Single), "1.234568e+06");
  EXPECT_EQ(Print(10000000.0, Precision::Single), "1.000000e+07");
  EXPECT_EQ(Print(12345678.9012345678901234567890, Precision::Single), "1.234568e+07");
}

TEST(Base, Replace) {
  std::string text0;
  Replace(text0, 'A', 'B');
  EXPECT_EQ(text0, "");
  std::string text1{"AbCd123!?^-_"};
  Replace(text1, 'C', 'D');
  EXPECT_EQ(text1, "AbDd123!?^-_");
  Replace(text1, 'X', 'Y');
  EXPECT_EQ(text1, "AbDd123!?^-_");
}

TEST(Base, ReplaceCopy) {
  EXPECT_EQ(ReplaceCopy("", 'A', 'B'), "");
  EXPECT_EQ(ReplaceCopy("AbCd123!?^-_", 'C', 'D'), "AbDd123!?^-_");
  EXPECT_EQ(ReplaceCopy("AbCd123!?^-_", 'X', 'Y'), "AbCd123!?^-_");
}

TEST(Base, SnakeCase) {
  std::string text0;
  SnakeCase(text0);
  EXPECT_EQ(text0, "");
  std::string text1{"Ab Cd 123   !?^-_"};
  SnakeCase(text1);
  EXPECT_EQ(text1, "ab_cd_123___!?^-_");
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
  std::string text0;
  Uppercase(text0);
  EXPECT_EQ(text0, "");
  std::string text1{"AbCd123!?^-_"};
  Uppercase(text1);
  EXPECT_EQ(text1, "ABCD123!?^-_");
}

TEST(Base, UppercaseCopy) {
  EXPECT_EQ(UppercaseCopy(""), "");
  EXPECT_EQ(UppercaseCopy("AbCd123.!?*^-_"), "ABCD123.!?*^-_");
}

}  // namespace

}  // namespace PhQ
