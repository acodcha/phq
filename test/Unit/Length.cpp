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

#include "../../include/PhQ/Unit/Length.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Length, 13> Units = {
    Length::NauticalMile, Length::Mile,       Length::Kilometre, Length::Metre,
    Length::Yard,         Length::Foot,       Length::Decimetre, Length::Inch,
    Length::Centimetre,   Length::Millimetre, Length::Milliinch, Length::Micrometre,
    Length::Microinch,
};

TEST(UnitLength, Abbreviation) {
  EXPECT_EQ(Abbreviation(Length::NauticalMile), "nmi");
  EXPECT_EQ(Abbreviation(Length::Mile), "mi");
  EXPECT_EQ(Abbreviation(Length::Kilometre), "km");
  EXPECT_EQ(Abbreviation(Length::Metre), "m");
  EXPECT_EQ(Abbreviation(Length::Yard), "yd");
  EXPECT_EQ(Abbreviation(Length::Foot), "ft");
  EXPECT_EQ(Abbreviation(Length::Decimetre), "dm");
  EXPECT_EQ(Abbreviation(Length::Inch), "in");
  EXPECT_EQ(Abbreviation(Length::Centimetre), "cm");
  EXPECT_EQ(Abbreviation(Length::Millimetre), "mm");
  EXPECT_EQ(Abbreviation(Length::Milliinch), "mil");
  EXPECT_EQ(Abbreviation(Length::Micrometre), "μm");
  EXPECT_EQ(Abbreviation(Length::Microinch), "μin");
}

TEST(UnitLength, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Length>(UnitSystem::MetreKilogramSecondKelvin), Length::Metre);
  EXPECT_EQ(ConsistentUnit<Length>(UnitSystem::MillimetreGramSecondKelvin), Length::Millimetre);
  EXPECT_EQ(ConsistentUnit<Length>(UnitSystem::FootPoundSecondRankine), Length::Foot);
  EXPECT_EQ(ConsistentUnit<Length>(UnitSystem::InchPoundSecondRankine), Length::Inch);
}

TEST(UnitLength, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<Length>(
      Length::Metre, Length::NauticalMile, value, value / 1852.0L);
  Internal::TestConvertAndConvertCopy<Length>(
      Length::Metre, Length::Mile, value, value / 1609.344L);
  Internal::TestConvertAndConvertCopy<Length>(
      Length::Metre, Length::Kilometre, value, value * 0.001L);
  Internal::TestConvertAndConvertCopy<Length>(Length::Metre, Length::Metre, value, value);
  Internal::TestConvertAndConvertCopy<Length>(Length::Metre, Length::Yard, value, value / 0.9144L);
  Internal::TestConvertAndConvertCopy<Length>(Length::Metre, Length::Foot, value, value / 0.3048L);
  Internal::TestConvertAndConvertCopy<Length>(
      Length::Metre, Length::Decimetre, value, value * 10.0L);
  Internal::TestConvertAndConvertCopy<Length>(Length::Metre, Length::Inch, value, value / 0.0254L);
  Internal::TestConvertAndConvertCopy<Length>(
      Length::Metre, Length::Centimetre, value, value * 100.0L);
  Internal::TestConvertAndConvertCopy<Length>(
      Length::Metre, Length::Millimetre, value, value * 1000.0L);
  Internal::TestConvertAndConvertCopy<Length>(
      Length::Metre, Length::Milliinch, value, value / 0.0000254L);
  Internal::TestConvertAndConvertCopy<Length>(
      Length::Metre, Length::Micrometre, value, value * 1000000.0L);
  Internal::TestConvertAndConvertCopy<Length>(
      Length::Metre, Length::Microinch, value, value / 0.0000000254L);
}

TEST(UnitLength, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Length>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Length>("nmi"), Length::NauticalMile);
  EXPECT_EQ(ParseEnumeration<Length>("mi"), Length::Mile);
  EXPECT_EQ(ParseEnumeration<Length>("km"), Length::Kilometre);
  EXPECT_EQ(ParseEnumeration<Length>("m"), Length::Metre);
  EXPECT_EQ(ParseEnumeration<Length>("yd"), Length::Yard);
  EXPECT_EQ(ParseEnumeration<Length>("ft"), Length::Foot);
  EXPECT_EQ(ParseEnumeration<Length>("dm"), Length::Decimetre);
  EXPECT_EQ(ParseEnumeration<Length>("in"), Length::Inch);
  EXPECT_EQ(ParseEnumeration<Length>("cm"), Length::Centimetre);
  EXPECT_EQ(ParseEnumeration<Length>("mm"), Length::Millimetre);
  EXPECT_EQ(ParseEnumeration<Length>("mil"), Length::Milliinch);
  EXPECT_EQ(ParseEnumeration<Length>("μm"), Length::Micrometre);
  EXPECT_EQ(ParseEnumeration<Length>("μin"), Length::Microinch);
}

TEST(UnitLength, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Length>,
            Dimensions(Dimension::Time{0}, Dimension::Length{1}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitLength, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Length::NauticalMile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Mile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Kilometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Metre), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Length::Yard), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Foot), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Length::Decimetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Inch), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Length::Centimetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Millimetre), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Length::Milliinch), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Micrometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Microinch), std::nullopt);
}

TEST(UnitLength, Standard) {
  EXPECT_EQ(Standard<Length>, Length::Metre);
}

TEST(UnitLength, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Length, Length::Metre, Length::Foot>(value, value / 0.3048L);
}

TEST(UnitLength, Stream) {
  std::ostringstream stream;
  stream << Length::Metre;
  EXPECT_EQ(stream.str(), Abbreviation(Length::Metre));
}

}  // namespace

}  // namespace PhQ::Unit
