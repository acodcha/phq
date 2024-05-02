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

#include "../../include/PhQ/Unit/ThermalExpansion.hpp"

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

constexpr std::array<ThermalExpansion, 4> Units = {
    ThermalExpansion::PerKelvin,
    ThermalExpansion::PerCelsius,
    ThermalExpansion::PerRankine,
    ThermalExpansion::PerFahrenheit,
};

TEST(UnitThermalExpansion, Abbreviation) {
  EXPECT_EQ(Abbreviation(ThermalExpansion::PerKelvin), "/K");
  EXPECT_EQ(Abbreviation(ThermalExpansion::PerCelsius), "/°C");
  EXPECT_EQ(Abbreviation(ThermalExpansion::PerRankine), "/°R");
  EXPECT_EQ(Abbreviation(ThermalExpansion::PerFahrenheit), "/°F");
}

TEST(UnitThermalExpansion, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<ThermalExpansion>(UnitSystem::MetreKilogramSecondKelvin),
            ThermalExpansion::PerKelvin);
  EXPECT_EQ(ConsistentUnit<ThermalExpansion>(UnitSystem::MillimetreGramSecondKelvin),
            ThermalExpansion::PerKelvin);
  EXPECT_EQ(ConsistentUnit<ThermalExpansion>(UnitSystem::FootPoundSecondRankine),
            ThermalExpansion::PerRankine);
  EXPECT_EQ(ConsistentUnit<ThermalExpansion>(UnitSystem::InchPoundSecondRankine),
            ThermalExpansion::PerRankine);
}

TEST(UnitThermalExpansion, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const ThermalExpansion original_unit : Units) {
    for (const ThermalExpansion intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitThermalExpansion, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};
  Internal::TestConversions<ThermalExpansion, ThermalExpansion::PerKelvin,
                            ThermalExpansion::PerKelvin>(value, value);
  Internal::TestConversions<ThermalExpansion, ThermalExpansion::PerKelvin,
                            ThermalExpansion::PerCelsius>(value, value);
  Internal::TestConversions<ThermalExpansion, ThermalExpansion::PerKelvin,
                            ThermalExpansion::PerRankine>(value, value / 1.8);
  Internal::TestConversions<ThermalExpansion, ThermalExpansion::PerKelvin,
                            ThermalExpansion::PerFahrenheit>(value, value / 1.8);
}

TEST(UnitThermalExpansion, ConvertToStandard) {
  constexpr double value{1.234567890123456789};
  Internal::TestConversions<ThermalExpansion, ThermalExpansion::PerKelvin,
                            ThermalExpansion::PerKelvin>(value, value);
  Internal::TestConversions<ThermalExpansion, ThermalExpansion::PerCelsius,
                            ThermalExpansion::PerKelvin>(value, value);
  Internal::TestConversions<ThermalExpansion, ThermalExpansion::PerRankine,
                            ThermalExpansion::PerKelvin>(value, value * 1.8);
  Internal::TestConversions<ThermalExpansion, ThermalExpansion::PerFahrenheit,
                            ThermalExpansion::PerKelvin>(value, value * 1.8);
}

TEST(UnitThermalExpansion, Parse) {
  EXPECT_EQ(Parse<ThermalExpansion>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<ThermalExpansion>("/K"), ThermalExpansion::PerKelvin);
  EXPECT_EQ(Parse<ThermalExpansion>("/°C"), ThermalExpansion::PerCelsius);
  EXPECT_EQ(Parse<ThermalExpansion>("/°R"), ThermalExpansion::PerRankine);
  EXPECT_EQ(Parse<ThermalExpansion>("/°F"), ThermalExpansion::PerFahrenheit);
}

TEST(UnitThermalExpansion, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<ThermalExpansion>,
            Dimensions(Dimension::Time{}, Dimension::Length{}, Dimension::Mass{},
                       Dimension::ElectricCurrent{}, Dimension::Temperature{-1}));
}

TEST(UnitThermalExpansion, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(ThermalExpansion::PerKelvin), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ThermalExpansion::PerCelsius), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ThermalExpansion::PerRankine), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ThermalExpansion::PerFahrenheit), std::nullopt);
}

TEST(UnitThermalExpansion, Standard) {
  EXPECT_EQ(Standard<ThermalExpansion>, ThermalExpansion::PerKelvin);
}

TEST(UnitThermalExpansion, Stream) {
  std::ostringstream stream;
  stream << ThermalExpansion::PerKelvin;
  EXPECT_EQ(stream.str(), Abbreviation(ThermalExpansion::PerKelvin));
}

}  // namespace

}  // namespace PhQ::Unit
