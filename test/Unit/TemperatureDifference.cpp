// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

#include "../../include/PhQ/Unit/TemperatureDifference.hpp"

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

constexpr std::array<TemperatureDifference, 4> Units = {
    TemperatureDifference::Kelvin,
    TemperatureDifference::Celsius,
    TemperatureDifference::Rankine,
    TemperatureDifference::Fahrenheit,
};

TEST(UnitTemperatureDifference, Abbreviation) {
  EXPECT_EQ(Abbreviation(TemperatureDifference::Kelvin), "K");
  EXPECT_EQ(Abbreviation(TemperatureDifference::Celsius), "°C");
  EXPECT_EQ(Abbreviation(TemperatureDifference::Rankine), "°R");
  EXPECT_EQ(Abbreviation(TemperatureDifference::Fahrenheit), "°F");
}

TEST(UnitTemperatureDifference, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<TemperatureDifference>(UnitSystem::MetreKilogramSecondKelvin),
            TemperatureDifference::Kelvin);
  EXPECT_EQ(ConsistentUnit<TemperatureDifference>(UnitSystem::MillimetreGramSecondKelvin),
            TemperatureDifference::Kelvin);
  EXPECT_EQ(ConsistentUnit<TemperatureDifference>(UnitSystem::FootPoundSecondRankine),
            TemperatureDifference::Rankine);
  EXPECT_EQ(ConsistentUnit<TemperatureDifference>(UnitSystem::InchPoundSecondRankine),
            TemperatureDifference::Rankine);
}

TEST(UnitTemperatureDifference, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<TemperatureDifference>(
      TemperatureDifference::Kelvin, TemperatureDifference::Kelvin, value, value);
  Internal::TestConvertAndConvertCopy<TemperatureDifference>(
      TemperatureDifference::Kelvin, TemperatureDifference::Celsius, value, value);
  Internal::TestConvertAndConvertCopy<TemperatureDifference>(
      TemperatureDifference::Kelvin, TemperatureDifference::Rankine, value, value * 1.8L);
  Internal::TestConvertAndConvertCopy<TemperatureDifference>(
      TemperatureDifference::Kelvin, TemperatureDifference::Fahrenheit, value, value * 1.8L);
}

TEST(UnitTemperatureDifference, Parse) {
  EXPECT_EQ(Parse<TemperatureDifference>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<TemperatureDifference>("K"), TemperatureDifference::Kelvin);
  EXPECT_EQ(Parse<TemperatureDifference>("°C"), TemperatureDifference::Celsius);
  EXPECT_EQ(Parse<TemperatureDifference>("°R"), TemperatureDifference::Rankine);
  EXPECT_EQ(Parse<TemperatureDifference>("°F"), TemperatureDifference::Fahrenheit);
}

TEST(UnitTemperatureDifference, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<TemperatureDifference>,
            Dimensions(Dimension::Time{}, Dimension::Length{}, Dimension::Mass{},
                       Dimension::ElectricCurrent{}, Dimension::Temperature{1}));
}

TEST(UnitTemperatureDifference, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(TemperatureDifference::Kelvin), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TemperatureDifference::Celsius), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TemperatureDifference::Rankine), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TemperatureDifference::Fahrenheit), std::nullopt);
}

TEST(UnitTemperatureDifference, Standard) {
  EXPECT_EQ(Standard<TemperatureDifference>, TemperatureDifference::Kelvin);
}

TEST(UnitTemperatureDifference, StaticConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestStaticConvertCopy<TemperatureDifference, TemperatureDifference::Kelvin,
                                  TemperatureDifference::Fahrenheit>(value, value * 1.8L);
}

TEST(UnitTemperatureDifference, Stream) {
  std::ostringstream stream;
  stream << TemperatureDifference::Kelvin;
  EXPECT_EQ(stream.str(), Abbreviation(TemperatureDifference::Kelvin));
}

}  // namespace

}  // namespace PhQ::Unit
