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

TEST(UnitSystem, Parse) {
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>(""), std::nullopt);
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("Hello world!"), std::nullopt);
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("m·kg·s·K"),
            std::optional{PhQ::UnitSystem::MetreKilogramSecondKelvin});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("m-kg-s-K"),
            std::optional{PhQ::UnitSystem::MetreKilogramSecondKelvin});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("m, kg, s, K"),
            std::optional{PhQ::UnitSystem::MetreKilogramSecondKelvin});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("m·kg·s"),
            std::optional{PhQ::UnitSystem::MetreKilogramSecondKelvin});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("m·kg"),
            std::optional{PhQ::UnitSystem::MetreKilogramSecondKelvin});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("mm·g·s·K"),
            std::optional{PhQ::UnitSystem::MillimetreGramSecondKelvin});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("mm·g·s"),
            std::optional{PhQ::UnitSystem::MillimetreGramSecondKelvin});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("mm·g"),
            std::optional{PhQ::UnitSystem::MillimetreGramSecondKelvin});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("ft·lbf·s·°R"),
            std::optional{PhQ::UnitSystem::FootPoundSecondRankine});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("ft·lbf·s·R"),
            std::optional{PhQ::UnitSystem::FootPoundSecondRankine});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("ft·lbf·s"),
            std::optional{PhQ::UnitSystem::FootPoundSecondRankine});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("ft·lbf"),
            std::optional{PhQ::UnitSystem::FootPoundSecondRankine});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("in·lbf·s·°R"),
            std::optional{PhQ::UnitSystem::InchPoundSecondRankine});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("in·lbf·s·R"),
            std::optional{PhQ::UnitSystem::InchPoundSecondRankine});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("in·lbf·s"),
            std::optional{PhQ::UnitSystem::InchPoundSecondRankine});
  EXPECT_EQ(PhQ::Parse<PhQ::UnitSystem>("in·lbf"),
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
