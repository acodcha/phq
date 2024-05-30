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

TEST(UnitForce, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<Force>(Force::Newton, Force::Newton, value, value);
  Internal::TestConvert<Force>(Force::Newton, Force::Kilonewton, value, value * 0.001L);
  Internal::TestConvert<Force>(Force::Newton, Force::Meganewton, value, value * 0.000001L);
  Internal::TestConvert<Force>(Force::Newton, Force::Giganewton, value, value * 0.000000001L);
  Internal::TestConvert<Force>(Force::Newton, Force::Millinewton, value, value * 1000.0L);
  Internal::TestConvert<Force>(Force::Newton, Force::Micronewton, value, value * 1000000.0L);
  Internal::TestConvert<Force>(Force::Newton, Force::Nanonewton, value, value * 1000000000.0L);
  Internal::TestConvert<Force>(Force::Newton, Force::Dyne, value, value * 100000.0L);
  Internal::TestConvert<Force>(
      Force::Newton, Force::Pound, value, value / (0.45359237L * 9.80665L));
}

TEST(UnitForce, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Force, Force::Newton, Force::Pound>(
      value, value / (0.45359237L * 9.80665L));
}

TEST(UnitForce, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Force>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Force>("N"), Force::Newton);
  EXPECT_EQ(ParseEnumeration<Force>("kN"), Force::Kilonewton);
  EXPECT_EQ(ParseEnumeration<Force>("MN"), Force::Meganewton);
  EXPECT_EQ(ParseEnumeration<Force>("GN"), Force::Giganewton);
  EXPECT_EQ(ParseEnumeration<Force>("mN"), Force::Millinewton);
  EXPECT_EQ(ParseEnumeration<Force>("μN"), Force::Micronewton);
  EXPECT_EQ(ParseEnumeration<Force>("nN"), Force::Nanonewton);
  EXPECT_EQ(ParseEnumeration<Force>("dyn"), Force::Dyne);
  EXPECT_EQ(ParseEnumeration<Force>("lbf"), Force::Pound);
}

TEST(UnitForce, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Force>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
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

TEST(UnitForce, Stream) {
  std::ostringstream stream;
  stream << Force::Newton;
  EXPECT_EQ(stream.str(), Abbreviation(Force::Newton));
}

}  // namespace

}  // namespace PhQ::Unit
