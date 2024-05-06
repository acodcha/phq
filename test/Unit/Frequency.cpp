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

#include "../../include/PhQ/Unit/Frequency.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Frequency, 6> Units = {
    Frequency::Hertz,     Frequency::Kilohertz, Frequency::Megahertz,
    Frequency::Gigahertz, Frequency::PerMinute, Frequency::PerHour,
};

TEST(UnitFrequency, Abbreviation) {
  EXPECT_EQ(Abbreviation(Frequency::Hertz), "Hz");
  EXPECT_EQ(Abbreviation(Frequency::Kilohertz), "kHz");
  EXPECT_EQ(Abbreviation(Frequency::Megahertz), "MHz");
  EXPECT_EQ(Abbreviation(Frequency::Gigahertz), "GHz");
  EXPECT_EQ(Abbreviation(Frequency::PerMinute), "/min");
  EXPECT_EQ(Abbreviation(Frequency::PerHour), "/hr");
}

TEST(UnitFrequency, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Frequency>(UnitSystem::MetreKilogramSecondKelvin), Frequency::Hertz);
  EXPECT_EQ(ConsistentUnit<Frequency>(UnitSystem::MillimetreGramSecondKelvin), Frequency::Hertz);
  EXPECT_EQ(ConsistentUnit<Frequency>(UnitSystem::FootPoundSecondRankine), Frequency::Hertz);
  EXPECT_EQ(ConsistentUnit<Frequency>(UnitSystem::InchPoundSecondRankine), Frequency::Hertz);
}

TEST(UnitFrequency, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<Frequency>(Frequency::Hertz, Frequency::Hertz, value, value);
  Internal::TestConvertAndConvertCopy<Frequency>(
      Frequency::Hertz, Frequency::Kilohertz, value, value * 0.001L);
  Internal::TestConvertAndConvertCopy<Frequency>(
      Frequency::Hertz, Frequency::Megahertz, value, value * 0.000001L);
  Internal::TestConvertAndConvertCopy<Frequency>(
      Frequency::Hertz, Frequency::Gigahertz, value, value * 0.000000001L);
  Internal::TestConvertAndConvertCopy<Frequency>(
      Frequency::Hertz, Frequency::PerMinute, value, value * 60.0L);
  Internal::TestConvertAndConvertCopy<Frequency>(
      Frequency::Hertz, Frequency::PerHour, value, value * 3600.0L);
}

TEST(UnitFrequency, Parse) {
  EXPECT_EQ(Parse<Frequency>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Frequency>("Hz"), Frequency::Hertz);
  EXPECT_EQ(Parse<Frequency>("kHz"), Frequency::Kilohertz);
  EXPECT_EQ(Parse<Frequency>("MHz"), Frequency::Megahertz);
  EXPECT_EQ(Parse<Frequency>("GHz"), Frequency::Gigahertz);
  EXPECT_EQ(Parse<Frequency>("/min"), Frequency::PerMinute);
  EXPECT_EQ(Parse<Frequency>("/hr"), Frequency::PerHour);
}

TEST(UnitFrequency, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Frequency>, Dimensions(Dimension::Time{-1}));
}

TEST(UnitFrequency, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Frequency::Hertz), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Frequency::Kilohertz), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Frequency::Megahertz), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Frequency::Gigahertz), std::nullopt);
}

TEST(UnitFrequency, Standard) {
  EXPECT_EQ(Standard<Frequency>, Frequency::Hertz);
}

TEST(UnitFrequency, StaticConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestStaticConvertCopy<Frequency, Frequency::Hertz, Frequency::Kilohertz>(
      value, value * 0.001L);
}

TEST(UnitFrequency, Stream) {
  std::ostringstream stream;
  stream << Frequency::Hertz;
  EXPECT_EQ(stream.str(), Abbreviation(Frequency::Hertz));
}

}  // namespace

}  // namespace PhQ::Unit
