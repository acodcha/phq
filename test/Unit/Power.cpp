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

#include "../../include/PhQ/Unit/Power.hpp"

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

constexpr std::array<Power, 9> Units = {
    Power::Watt,     Power::Milliwatt,          Power::Microwatt,
    Power::Nanowatt, Power::Kilowatt,           Power::Megawatt,
    Power::Gigawatt, Power::FootPoundPerSecond, Power::InchPoundPerSecond,
};

TEST(UnitPower, Abbreviation) {
  EXPECT_EQ(Abbreviation(Power::Watt), "W");
  EXPECT_EQ(Abbreviation(Power::Milliwatt), "mW");
  EXPECT_EQ(Abbreviation(Power::Microwatt), "μW");
  EXPECT_EQ(Abbreviation(Power::Nanowatt), "nW");
  EXPECT_EQ(Abbreviation(Power::Kilowatt), "kW");
  EXPECT_EQ(Abbreviation(Power::Megawatt), "MW");
  EXPECT_EQ(Abbreviation(Power::Gigawatt), "GW");
  EXPECT_EQ(Abbreviation(Power::FootPoundPerSecond), "ft·lbf/s");
  EXPECT_EQ(Abbreviation(Power::InchPoundPerSecond), "in·lbf/s");
}

TEST(UnitPower, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Power>(UnitSystem::MetreKilogramSecondKelvin), Power::Watt);
  EXPECT_EQ(ConsistentUnit<Power>(UnitSystem::MillimetreGramSecondKelvin), Power::Nanowatt);
  EXPECT_EQ(ConsistentUnit<Power>(UnitSystem::FootPoundSecondRankine), Power::FootPoundPerSecond);
  EXPECT_EQ(ConsistentUnit<Power>(UnitSystem::InchPoundSecondRankine), Power::InchPoundPerSecond);
}

TEST(UnitPower, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<Power>(Power::Watt, Power::Watt, value, value);
  Internal::TestConvert<Power>(Power::Watt, Power::Milliwatt, value, value * 1000.0L);
  Internal::TestConvert<Power>(Power::Watt, Power::Microwatt, value, value * 1000000.0L);
  Internal::TestConvert<Power>(Power::Watt, Power::Nanowatt, value, value * 1000000000.0L);
  Internal::TestConvert<Power>(Power::Watt, Power::Kilowatt, value, value * 0.001L);
  Internal::TestConvert<Power>(Power::Watt, Power::Megawatt, value, value * 0.000001L);
  Internal::TestConvert<Power>(Power::Watt, Power::Gigawatt, value, value * 0.000000001L);
  Internal::TestConvert<Power>(
      Power::Watt, Power::FootPoundPerSecond, value, value / (0.3048L * 0.45359237L * 9.80665L));
  Internal::TestConvert<Power>(
      Power::Watt, Power::InchPoundPerSecond, value, value / (0.0254L * 0.45359237L * 9.80665L));
}

TEST(UnitPower, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Power, Power::Watt, Power::FootPoundPerSecond>(
      value, value / (0.3048L * 0.45359237L * 9.80665L));
}

TEST(UnitPower, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Power>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Power>("W"), Power::Watt);
  EXPECT_EQ(ParseEnumeration<Power>("mW"), Power::Milliwatt);
  EXPECT_EQ(ParseEnumeration<Power>("μW"), Power::Microwatt);
  EXPECT_EQ(ParseEnumeration<Power>("nW"), Power::Nanowatt);
  EXPECT_EQ(ParseEnumeration<Power>("kW"), Power::Kilowatt);
  EXPECT_EQ(ParseEnumeration<Power>("MW"), Power::Megawatt);
  EXPECT_EQ(ParseEnumeration<Power>("GW"), Power::Gigawatt);
  EXPECT_EQ(ParseEnumeration<Power>("ft·lbf/s"), Power::FootPoundPerSecond);
  EXPECT_EQ(ParseEnumeration<Power>("in·lbf/s"), Power::InchPoundPerSecond);
}

TEST(UnitPower, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Power>,
            Dimensions(Dimension::Time{-3}, Dimension::Length{2}, Dimension::Mass{1},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitPower, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Power::Watt), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Power::Milliwatt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Power::Microwatt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Power::Nanowatt), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Power::Kilowatt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Power::Megawatt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Power::Gigawatt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Power::FootPoundPerSecond), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Power::InchPoundPerSecond), UnitSystem::InchPoundSecondRankine);
}

TEST(UnitPower, Standard) {
  EXPECT_EQ(Standard<Power>, Power::Watt);
}

TEST(UnitPower, Stream) {
  std::ostringstream stream;
  stream << Power::Watt;
  EXPECT_EQ(stream.str(), Abbreviation(Power::Watt));
}

}  // namespace

}  // namespace PhQ::Unit
