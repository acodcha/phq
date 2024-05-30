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

#include "../include/PhQ/UnitSystem.hpp"

#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../include/PhQ/Base.hpp"

namespace {

TEST(UnitSystem, Abbreviation) {
  EXPECT_EQ(PhQ::Abbreviation(PhQ::UnitSystem::MetreKilogramSecondKelvin), "m·kg·s·K");
  EXPECT_EQ(PhQ::Abbreviation(PhQ::UnitSystem::MillimetreGramSecondKelvin), "mm·g·s·K");
  EXPECT_EQ(PhQ::Abbreviation(PhQ::UnitSystem::FootPoundSecondRankine), "ft·lbf·s·°R");
  EXPECT_EQ(PhQ::Abbreviation(PhQ::UnitSystem::InchPoundSecondRankine), "in·lbf·s·°R");
}

TEST(UnitSystem, ParseEnumeration) {
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>(""), std::nullopt);
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("Hello world!"), std::nullopt);
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("m·kg·s·K"),
            std::optional{PhQ::UnitSystem::MetreKilogramSecondKelvin});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("m-kg-s-K"),
            std::optional{PhQ::UnitSystem::MetreKilogramSecondKelvin});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("m, kg, s, K"),
            std::optional{PhQ::UnitSystem::MetreKilogramSecondKelvin});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("m·kg·s"),
            std::optional{PhQ::UnitSystem::MetreKilogramSecondKelvin});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("m·kg"),
            std::optional{PhQ::UnitSystem::MetreKilogramSecondKelvin});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("mm·g·s·K"),
            std::optional{PhQ::UnitSystem::MillimetreGramSecondKelvin});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("mm·g·s"),
            std::optional{PhQ::UnitSystem::MillimetreGramSecondKelvin});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("mm·g"),
            std::optional{PhQ::UnitSystem::MillimetreGramSecondKelvin});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("ft·lbf·s·°R"),
            std::optional{PhQ::UnitSystem::FootPoundSecondRankine});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("ft·lbf·s·R"),
            std::optional{PhQ::UnitSystem::FootPoundSecondRankine});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("ft·lbf·s"),
            std::optional{PhQ::UnitSystem::FootPoundSecondRankine});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("ft·lbf"),
            std::optional{PhQ::UnitSystem::FootPoundSecondRankine});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("in·lbf·s·°R"),
            std::optional{PhQ::UnitSystem::InchPoundSecondRankine});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("in·lbf·s·R"),
            std::optional{PhQ::UnitSystem::InchPoundSecondRankine});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("in·lbf·s"),
            std::optional{PhQ::UnitSystem::InchPoundSecondRankine});
  EXPECT_EQ(PhQ::ParseEnumeration<PhQ::UnitSystem>("in·lbf"),
            std::optional{PhQ::UnitSystem::InchPoundSecondRankine});
}

TEST(UnitSystem, Standard) {
  EXPECT_EQ(PhQ::Standard<PhQ::UnitSystem>, PhQ::UnitSystem::MetreKilogramSecondKelvin);
}

TEST(UnitSystem, Stream) {
  std::ostringstream stream;
  stream << PhQ::UnitSystem::MetreKilogramSecondKelvin;
  EXPECT_EQ(stream.str(), PhQ::Abbreviation(PhQ::UnitSystem::MetreKilogramSecondKelvin));
}

}  // namespace
