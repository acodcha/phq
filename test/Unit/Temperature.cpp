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

#include "../../include/PhQ/Unit/Temperature.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/ElectricCurrent.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Mass.hpp"
#include "../../include/PhQ/Dimension/Temperature.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Temperature, 4> Units = {
    Temperature::Kelvin,
    Temperature::Celsius,
    Temperature::Rankine,
    Temperature::Fahrenheit,
};

TEST(UnitTemperature, Abbreviation) {
  EXPECT_EQ(Abbreviation(Temperature::Kelvin), "K");
  EXPECT_EQ(Abbreviation(Temperature::Celsius), "°C");
  EXPECT_EQ(Abbreviation(Temperature::Rankine), "°R");
  EXPECT_EQ(Abbreviation(Temperature::Fahrenheit), "°F");
}

TEST(UnitTemperature, ConsistentUnit) {
  EXPECT_EQ(
      ConsistentUnit<Temperature>(UnitSystem::MetreKilogramSecondKelvin), Temperature::Kelvin);
  EXPECT_EQ(
      ConsistentUnit<Temperature>(UnitSystem::MillimetreGramSecondKelvin), Temperature::Kelvin);
  EXPECT_EQ(ConsistentUnit<Temperature>(UnitSystem::FootPoundSecondRankine), Temperature::Rankine);
  EXPECT_EQ(ConsistentUnit<Temperature>(UnitSystem::InchPoundSecondRankine), Temperature::Rankine);
}

TEST(UnitTemperature, ConvertAndConvertCopy) {
  constexpr long double value{123.4567890123456789L};
  Internal::TestConvert<Temperature>(Temperature::Kelvin, Temperature::Kelvin, value, value);
  Internal::TestConvert<Temperature>(
      Temperature::Kelvin, Temperature::Celsius, value, value - 273.15L);
  Internal::TestConvert<Temperature>(
      Temperature::Kelvin, Temperature::Rankine, value, value * 1.8L);
  Internal::TestConvert<Temperature>(
      Temperature::Kelvin, Temperature::Fahrenheit, value, (value * 1.8L) - 459.67L);
}

TEST(UnitTemperature, ConvertStatically) {
  constexpr long double value{123.4567890123456789L};
  Internal::TestConvertStatically<Temperature, Temperature::Kelvin, Temperature::Fahrenheit>(
      value, (value * 1.8L) - 459.67L);
}

TEST(UnitTemperature, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Temperature>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Temperature>("K"), Temperature::Kelvin);
  EXPECT_EQ(ParseEnumeration<Temperature>("°C"), Temperature::Celsius);
  EXPECT_EQ(ParseEnumeration<Temperature>("°R"), Temperature::Rankine);
  EXPECT_EQ(ParseEnumeration<Temperature>("°F"), Temperature::Fahrenheit);
}

TEST(UnitTemperature, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Temperature>,
            Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{1},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitTemperature, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Temperature::Kelvin), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Temperature::Celsius), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Temperature::Rankine), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Temperature::Fahrenheit), std::nullopt);
}

TEST(UnitTemperature, Standard) {
  EXPECT_EQ(Standard<Temperature>, Temperature::Kelvin);
}

TEST(UnitTemperature, Stream) {
  std::ostringstream stream;
  stream << Temperature::Kelvin;
  EXPECT_EQ(stream.str(), Abbreviation(Temperature::Kelvin));
}

}  // namespace

}  // namespace PhQ::Unit
