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

TEST(UnitTemperature, ConversionReciprocity) {
  constexpr double original_value{123.45};
  for (const Temperature original_unit : Units) {
    for (const Temperature intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitTemperature, ConvertFromStandard) {
  constexpr double value{123.4567890123456789};

  Internal::TestConversions(Temperature::Kelvin, Temperature::Kelvin, value, value);
  Internal::TestConversions(Temperature::Kelvin, Temperature::Celsius, value, value - 273.15);
  Internal::TestConversions(Temperature::Kelvin, Temperature::Rankine, value, value * 1.8);
  Internal::TestConversions(
      Temperature::Kelvin, Temperature::Fahrenheit, value, (value * 1.8) - 459.67);

  Internal::TestStaticConversions<Temperature, Temperature::Kelvin, Temperature::Rankine>(
      value, value * 1.8);
}

TEST(UnitTemperature, ConvertToStandard) {
  constexpr double value{123.4567890123456789};

  Internal::TestConversions(Temperature::Kelvin, Temperature::Kelvin, value, value);
  Internal::TestConversions(Temperature::Celsius, Temperature::Kelvin, value, value + 273.15);
  Internal::TestConversions(Temperature::Rankine, Temperature::Kelvin, value, value / 1.8);
  Internal::TestConversions(
      Temperature::Fahrenheit, Temperature::Kelvin, value, (value + 459.67) / 1.8);

  Internal::TestStaticConversions<Temperature, Temperature::Rankine, Temperature::Kelvin>(
      value, value / 1.8);
}

TEST(UnitTemperature, Parse) {
  EXPECT_EQ(Parse<Temperature>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Temperature>("K"), Temperature::Kelvin);
  EXPECT_EQ(Parse<Temperature>("°C"), Temperature::Celsius);
  EXPECT_EQ(Parse<Temperature>("°R"), Temperature::Rankine);
  EXPECT_EQ(Parse<Temperature>("°F"), Temperature::Fahrenheit);
}

TEST(UnitTemperature, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Temperature>,
            Dimensions(Dimension::Time{}, Dimension::Length{}, Dimension::Mass{},
                       Dimension::ElectricCurrent{}, Dimension::Temperature{1}));
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
