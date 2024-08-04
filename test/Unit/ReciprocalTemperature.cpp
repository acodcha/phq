// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../../include/PhQ/Unit/ReciprocalTemperature.hpp"

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

constexpr std::array<ReciprocalTemperature, 4> Units = {
    ReciprocalTemperature::PerKelvin,
    ReciprocalTemperature::PerCelsius,
    ReciprocalTemperature::PerRankine,
    ReciprocalTemperature::PerFahrenheit,
};

TEST(UnitThermalExpansion, Abbreviation) {
  EXPECT_EQ(Abbreviation(ReciprocalTemperature::PerKelvin), "/K");
  EXPECT_EQ(Abbreviation(ReciprocalTemperature::PerCelsius), "/°C");
  EXPECT_EQ(Abbreviation(ReciprocalTemperature::PerRankine), "/°R");
  EXPECT_EQ(Abbreviation(ReciprocalTemperature::PerFahrenheit), "/°F");
}

TEST(UnitThermalExpansion, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<ReciprocalTemperature>(UnitSystem::MetreKilogramSecondKelvin),
            ReciprocalTemperature::PerKelvin);
  EXPECT_EQ(ConsistentUnit<ReciprocalTemperature>(UnitSystem::MillimetreGramSecondKelvin),
            ReciprocalTemperature::PerKelvin);
  EXPECT_EQ(ConsistentUnit<ReciprocalTemperature>(UnitSystem::FootPoundSecondRankine),
            ReciprocalTemperature::PerRankine);
  EXPECT_EQ(ConsistentUnit<ReciprocalTemperature>(UnitSystem::InchPoundSecondRankine),
            ReciprocalTemperature::PerRankine);
}

TEST(UnitThermalExpansion, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<ReciprocalTemperature>(
      ReciprocalTemperature::PerKelvin, ReciprocalTemperature::PerKelvin, value, value);
  Internal::TestConvert<ReciprocalTemperature>(
      ReciprocalTemperature::PerKelvin, ReciprocalTemperature::PerCelsius, value, value);
  Internal::TestConvert<ReciprocalTemperature>(
      ReciprocalTemperature::PerKelvin, ReciprocalTemperature::PerRankine, value, value / 1.8L);
  Internal::TestConvert<ReciprocalTemperature>(
      ReciprocalTemperature::PerKelvin, ReciprocalTemperature::PerFahrenheit, value, value / 1.8L);
}

TEST(UnitThermalExpansion, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<ReciprocalTemperature, ReciprocalTemperature::PerKelvin,
                                  ReciprocalTemperature::PerFahrenheit>(value, value / 1.8L);
}

TEST(UnitThermalExpansion, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<ReciprocalTemperature>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<ReciprocalTemperature>("/K"), ReciprocalTemperature::PerKelvin);
  EXPECT_EQ(ParseEnumeration<ReciprocalTemperature>("/°C"), ReciprocalTemperature::PerCelsius);
  EXPECT_EQ(ParseEnumeration<ReciprocalTemperature>("/°R"), ReciprocalTemperature::PerRankine);
  EXPECT_EQ(ParseEnumeration<ReciprocalTemperature>("/°F"), ReciprocalTemperature::PerFahrenheit);
}

TEST(UnitThermalExpansion, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<ReciprocalTemperature>,
            Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{-1},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitThermalExpansion, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(ReciprocalTemperature::PerKelvin), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ReciprocalTemperature::PerCelsius), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ReciprocalTemperature::PerRankine), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ReciprocalTemperature::PerFahrenheit), std::nullopt);
}

TEST(UnitThermalExpansion, Standard) {
  EXPECT_EQ(Standard<ReciprocalTemperature>, ReciprocalTemperature::PerKelvin);
}

TEST(UnitThermalExpansion, Stream) {
  std::ostringstream stream;
  stream << ReciprocalTemperature::PerKelvin;
  EXPECT_EQ(stream.str(), Abbreviation(ReciprocalTemperature::PerKelvin));
}

}  // namespace

}  // namespace PhQ::Unit
