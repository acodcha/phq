// Copyright 2020-2023 Alexandre Coderre-Chabot
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

TEST(UnitTemperatureDifference, ConvertFromStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<TemperatureDifference, TemperatureDifference::Kelvin,
                                TemperatureDifference::Kelvin>(value, value);
  Internal::TestUnitConversions<TemperatureDifference, TemperatureDifference::Kelvin,
                                TemperatureDifference::Celsius>(value, value);
  Internal::TestUnitConversions<TemperatureDifference, TemperatureDifference::Kelvin,
                                TemperatureDifference::Rankine>(value, value * 1.8);
  Internal::TestUnitConversions<TemperatureDifference, TemperatureDifference::Kelvin,
                                TemperatureDifference::Fahrenheit>(value, value * 1.8);
}

TEST(UnitTemperatureDifference, ConvertToStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<TemperatureDifference, TemperatureDifference::Kelvin,
                                TemperatureDifference::Kelvin>(value, value);
  Internal::TestUnitConversions<TemperatureDifference, TemperatureDifference::Celsius,
                                TemperatureDifference::Kelvin>(value, value);
  Internal::TestUnitConversions<TemperatureDifference, TemperatureDifference::Rankine,
                                TemperatureDifference::Kelvin>(value, value / 1.8);
  Internal::TestUnitConversions<TemperatureDifference, TemperatureDifference::Fahrenheit,
                                TemperatureDifference::Kelvin>(value, value / 1.8);
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

TEST(UnitTemperatureDifference, Stream) {
  std::ostringstream stream;
  stream << TemperatureDifference::Kelvin;
  EXPECT_EQ(stream.str(), Abbreviation(TemperatureDifference::Kelvin));
}

}  // namespace

}  // namespace PhQ::Unit
