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

#include "../../include/PhQ/Unit/SpecificHeatCapacity.hpp"

#include <array>
#include <cmath>
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

constexpr std::array<SpecificHeatCapacity, 4> Units = {
    SpecificHeatCapacity::JoulePerKilogramPerKelvin,
    SpecificHeatCapacity::NanojoulePerGramPerKelvin,
    SpecificHeatCapacity::FootPoundPerSlugPerRankine,
    SpecificHeatCapacity::InchPoundPerSlinchPerRankine,
};

TEST(UnitSpecificHeatCapacity, Abbreviation) {
  EXPECT_EQ(Abbreviation(SpecificHeatCapacity::JoulePerKilogramPerKelvin), "J/kg/K");
  EXPECT_EQ(Abbreviation(SpecificHeatCapacity::NanojoulePerGramPerKelvin), "nJ/g/K");
  EXPECT_EQ(Abbreviation(SpecificHeatCapacity::FootPoundPerSlugPerRankine), "ft·lbf/slug/°R");
  EXPECT_EQ(Abbreviation(SpecificHeatCapacity::InchPoundPerSlinchPerRankine), "in·lbf/slinch/°R");
}

TEST(UnitSpecificHeatCapacity, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<SpecificHeatCapacity>(UnitSystem::MetreKilogramSecondKelvin),
            SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(ConsistentUnit<SpecificHeatCapacity>(UnitSystem::MillimetreGramSecondKelvin),
            SpecificHeatCapacity::NanojoulePerGramPerKelvin);
  EXPECT_EQ(ConsistentUnit<SpecificHeatCapacity>(UnitSystem::FootPoundSecondRankine),
            SpecificHeatCapacity::FootPoundPerSlugPerRankine);
  EXPECT_EQ(ConsistentUnit<SpecificHeatCapacity>(UnitSystem::InchPoundSecondRankine),
            SpecificHeatCapacity::InchPoundPerSlinchPerRankine);
}

TEST(UnitSpecificHeatCapacity, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const SpecificHeatCapacity original_unit : Units) {
    for (const SpecificHeatCapacity intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitSpecificHeatCapacity, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};
  Internal::TestConversions<SpecificHeatCapacity, SpecificHeatCapacity::JoulePerKilogramPerKelvin,
                            SpecificHeatCapacity::JoulePerKilogramPerKelvin>(value, value);
  Internal::TestConversions<SpecificHeatCapacity, SpecificHeatCapacity::JoulePerKilogramPerKelvin,
                            SpecificHeatCapacity::NanojoulePerGramPerKelvin>(
      value, value * 1000000.0);
  Internal::TestConversions<SpecificHeatCapacity, SpecificHeatCapacity::JoulePerKilogramPerKelvin,
                            SpecificHeatCapacity::FootPoundPerSlugPerRankine>(
      value, value / (1.8 * std::pow(0.3048, 2)));
  Internal::TestConversions<SpecificHeatCapacity, SpecificHeatCapacity::JoulePerKilogramPerKelvin,
                            SpecificHeatCapacity::InchPoundPerSlinchPerRankine>(
      value, value / (1.8 * std::pow(0.0254, 2)));
}

TEST(UnitSpecificHeatCapacity, ConvertToStandard) {
  constexpr double value{1.234567890123456789};
  Internal::TestConversions<SpecificHeatCapacity, SpecificHeatCapacity::JoulePerKilogramPerKelvin,
                            SpecificHeatCapacity::JoulePerKilogramPerKelvin>(value, value);
  Internal::TestConversions<SpecificHeatCapacity, SpecificHeatCapacity::NanojoulePerGramPerKelvin,
                            SpecificHeatCapacity::JoulePerKilogramPerKelvin>(
      value, value * 0.000001);
  Internal::TestConversions<SpecificHeatCapacity, SpecificHeatCapacity::FootPoundPerSlugPerRankine,
                            SpecificHeatCapacity::JoulePerKilogramPerKelvin>(
      value, value * 1.8 * std::pow(0.3048, 2));
  Internal::TestConversions<SpecificHeatCapacity,
                            SpecificHeatCapacity::InchPoundPerSlinchPerRankine,
                            SpecificHeatCapacity::JoulePerKilogramPerKelvin>(
      value, value * 1.8 * std::pow(0.0254, 2));
}

TEST(UnitSpecificHeatCapacity, Parse) {
  EXPECT_EQ(Parse<SpecificHeatCapacity>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<SpecificHeatCapacity>("J/kg/K"), SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(Parse<SpecificHeatCapacity>("nJ/g/K"), SpecificHeatCapacity::NanojoulePerGramPerKelvin);
  EXPECT_EQ(Parse<SpecificHeatCapacity>("ft·lbf/slug/°R"),
            SpecificHeatCapacity::FootPoundPerSlugPerRankine);
  EXPECT_EQ(Parse<SpecificHeatCapacity>("in·lbf/slinch/°R"),
            SpecificHeatCapacity::InchPoundPerSlinchPerRankine);
}

TEST(UnitSpecificHeatCapacity, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<SpecificHeatCapacity>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{},
                       Dimension::ElectricCurrent{}, Dimension::Temperature{-1}));
}

TEST(UnitSpecificHeatCapacity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificHeatCapacity::FootPoundPerSlugPerRankine),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(SpecificHeatCapacity::InchPoundPerSlinchPerRankine),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitSpecificHeatCapacity, Standard) {
  EXPECT_EQ(Standard<SpecificHeatCapacity>, SpecificHeatCapacity::JoulePerKilogramPerKelvin);
}

TEST(UnitSpecificHeatCapacity, Stream) {
  std::ostringstream stream;
  stream << SpecificHeatCapacity::JoulePerKilogramPerKelvin;
  EXPECT_EQ(stream.str(), Abbreviation(SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

}  // namespace

}  // namespace PhQ::Unit
