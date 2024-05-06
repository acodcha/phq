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

#include "../../include/PhQ/Unit/Force.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Mass.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Force, 9> Units = {
    Force::Newton,      Force::Kilonewton, Force::Meganewton, Force::Giganewton, Force::Millinewton,
    Force::Micronewton, Force::Nanonewton, Force::Dyne,       Force::Pound,
};

TEST(UnitForce, Abbreviation) {
  EXPECT_EQ(Abbreviation(Force::Newton), "N");
  EXPECT_EQ(Abbreviation(Force::Kilonewton), "kN");
  EXPECT_EQ(Abbreviation(Force::Meganewton), "MN");
  EXPECT_EQ(Abbreviation(Force::Giganewton), "GN");
  EXPECT_EQ(Abbreviation(Force::Millinewton), "mN");
  EXPECT_EQ(Abbreviation(Force::Micronewton), "μN");
  EXPECT_EQ(Abbreviation(Force::Nanonewton), "nN");
  EXPECT_EQ(Abbreviation(Force::Dyne), "dyn");
  EXPECT_EQ(Abbreviation(Force::Pound), "lbf");
}

TEST(UnitForce, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Force>(UnitSystem::MetreKilogramSecondKelvin), Force::Newton);
  EXPECT_EQ(ConsistentUnit<Force>(UnitSystem::MillimetreGramSecondKelvin), Force::Micronewton);
  EXPECT_EQ(ConsistentUnit<Force>(UnitSystem::FootPoundSecondRankine), Force::Pound);
  EXPECT_EQ(ConsistentUnit<Force>(UnitSystem::InchPoundSecondRankine), Force::Pound);
}

TEST(UnitForce, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<Force>(Force::Newton, Force::Newton, value, value);
  Internal::TestConvertAndConvertCopy<Force>(
      Force::Newton, Force::Kilonewton, value, value * 0.001L);
  Internal::TestConvertAndConvertCopy<Force>(
      Force::Newton, Force::Meganewton, value, value * 0.000001L);
  Internal::TestConvertAndConvertCopy<Force>(
      Force::Newton, Force::Giganewton, value, value * 0.000000001L);
  Internal::TestConvertAndConvertCopy<Force>(
      Force::Newton, Force::Millinewton, value, value * 1000.0L);
  Internal::TestConvertAndConvertCopy<Force>(
      Force::Newton, Force::Micronewton, value, value * 1000000.0L);
  Internal::TestConvertAndConvertCopy<Force>(
      Force::Newton, Force::Nanonewton, value, value * 1000000000.0L);
  Internal::TestConvertAndConvertCopy<Force>(Force::Newton, Force::Dyne, value, value * 100000.0L);
  Internal::TestConvertAndConvertCopy<Force>(
      Force::Newton, Force::Pound, value, value / (0.45359237L * 9.80665L));
}

TEST(UnitForce, Parse) {
  EXPECT_EQ(Parse<Force>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Force>("N"), Force::Newton);
  EXPECT_EQ(Parse<Force>("kN"), Force::Kilonewton);
  EXPECT_EQ(Parse<Force>("MN"), Force::Meganewton);
  EXPECT_EQ(Parse<Force>("GN"), Force::Giganewton);
  EXPECT_EQ(Parse<Force>("mN"), Force::Millinewton);
  EXPECT_EQ(Parse<Force>("μN"), Force::Micronewton);
  EXPECT_EQ(Parse<Force>("nN"), Force::Nanonewton);
  EXPECT_EQ(Parse<Force>("dyn"), Force::Dyne);
  EXPECT_EQ(Parse<Force>("lbf"), Force::Pound);
}

TEST(UnitForce, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Force>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1}));
}

TEST(UnitForce, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Force::Newton), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Force::Kilonewton), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Meganewton), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Giganewton), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Millinewton), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Micronewton), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Force::Nanonewton), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Dyne), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Pound), std::nullopt);
}

TEST(UnitForce, Standard) {
  EXPECT_EQ(Standard<Force>, Force::Newton);
}

TEST(UnitForce, StaticConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestStaticConvertCopy<Force, Force::Newton, Force::Pound>(
      value, value / (0.45359237L * 9.80665L));
}

TEST(UnitForce, Stream) {
  std::ostringstream stream;
  stream << Force::Newton;
  EXPECT_EQ(stream.str(), Abbreviation(Force::Newton));
}

}  // namespace

}  // namespace PhQ::Unit
