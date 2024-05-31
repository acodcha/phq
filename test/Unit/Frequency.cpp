// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

TEST(UnitFrequency, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<Frequency>(Frequency::Hertz, Frequency::Hertz, value, value);
  Internal::TestConvert<Frequency>(Frequency::Hertz, Frequency::Kilohertz, value, value * 0.001L);
  Internal::TestConvert<Frequency>(
      Frequency::Hertz, Frequency::Megahertz, value, value * 0.000001L);
  Internal::TestConvert<Frequency>(
      Frequency::Hertz, Frequency::Gigahertz, value, value * 0.000000001L);
  Internal::TestConvert<Frequency>(Frequency::Hertz, Frequency::PerMinute, value, value * 60.0L);
  Internal::TestConvert<Frequency>(Frequency::Hertz, Frequency::PerHour, value, value * 3600.0L);
}

TEST(UnitFrequency, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Frequency, Frequency::Hertz, Frequency::Kilohertz>(
      value, value * 0.001L);
}

TEST(UnitFrequency, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Frequency>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Frequency>("Hz"), Frequency::Hertz);
  EXPECT_EQ(ParseEnumeration<Frequency>("kHz"), Frequency::Kilohertz);
  EXPECT_EQ(ParseEnumeration<Frequency>("MHz"), Frequency::Megahertz);
  EXPECT_EQ(ParseEnumeration<Frequency>("GHz"), Frequency::Gigahertz);
  EXPECT_EQ(ParseEnumeration<Frequency>("/min"), Frequency::PerMinute);
  EXPECT_EQ(ParseEnumeration<Frequency>("/hr"), Frequency::PerHour);
}

TEST(UnitFrequency, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Frequency>,
            Dimensions(Dimension::Time{-1}, Dimension::Length{0}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
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

TEST(UnitFrequency, Stream) {
  std::ostringstream stream;
  stream << Frequency::Hertz;
  EXPECT_EQ(stream.str(), Abbreviation(Frequency::Hertz));
}

}  // namespace

}  // namespace PhQ::Unit
