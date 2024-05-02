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

TEST(UnitPower, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const Power original_unit : Units) {
    for (const Power intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitPower, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};
  Internal::TestConversions<Power, Power::Watt, Power::Watt>(value, value);
  Internal::TestConversions<Power, Power::Watt, Power::Milliwatt>(value, value * 1000.0);
  Internal::TestConversions<Power, Power::Watt, Power::Microwatt>(value, value * 1000000.0);
  Internal::TestConversions<Power, Power::Watt, Power::Nanowatt>(value, value * 1000000000.0);
  Internal::TestConversions<Power, Power::Watt, Power::Kilowatt>(value, value * 0.001);
  Internal::TestConversions<Power, Power::Watt, Power::Megawatt>(value, value * 0.000001);
  Internal::TestConversions<Power, Power::Watt, Power::Gigawatt>(value, value * 0.000000001);
  Internal::TestConversions<Power, Power::Watt, Power::FootPoundPerSecond>(
      value, value / (0.3048 * 0.45359237 * 9.80665));
  Internal::TestConversions<Power, Power::Watt, Power::InchPoundPerSecond>(
      value, value / (0.0254 * 0.45359237 * 9.80665));
}

TEST(UnitPower, ConvertToStandard) {
  constexpr double value{1.234567890123456789};
  Internal::TestConversions<Power, Power::Watt, Power::Watt>(value, value);
  Internal::TestConversions<Power, Power::Milliwatt, Power::Watt>(value, value * 0.001);
  Internal::TestConversions<Power, Power::Microwatt, Power::Watt>(value, value * 0.000001);
  Internal::TestConversions<Power, Power::Nanowatt, Power::Watt>(value, value * 0.000000001);
  Internal::TestConversions<Power, Power::Kilowatt, Power::Watt>(value, value * 1000.0);
  Internal::TestConversions<Power, Power::Megawatt, Power::Watt>(value, value * 1000000.0);
  Internal::TestConversions<Power, Power::Gigawatt, Power::Watt>(value, value * 1000000000.0);
  Internal::TestConversions<Power, Power::FootPoundPerSecond, Power::Watt>(
      value, value * 0.3048 * 0.45359237 * 9.80665);
  Internal::TestConversions<Power, Power::InchPoundPerSecond, Power::Watt>(
      value, value * 0.0254 * 0.45359237 * 9.80665);
}

TEST(UnitPower, Parse) {
  EXPECT_EQ(Parse<Power>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Power>("W"), Power::Watt);
  EXPECT_EQ(Parse<Power>("mW"), Power::Milliwatt);
  EXPECT_EQ(Parse<Power>("μW"), Power::Microwatt);
  EXPECT_EQ(Parse<Power>("nW"), Power::Nanowatt);
  EXPECT_EQ(Parse<Power>("kW"), Power::Kilowatt);
  EXPECT_EQ(Parse<Power>("MW"), Power::Megawatt);
  EXPECT_EQ(Parse<Power>("GW"), Power::Gigawatt);
  EXPECT_EQ(Parse<Power>("ft·lbf/s"), Power::FootPoundPerSecond);
  EXPECT_EQ(Parse<Power>("in·lbf/s"), Power::InchPoundPerSecond);
}

TEST(UnitPower, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Power>,
            Dimensions(Dimension::Time{-3}, Dimension::Length{2}, Dimension::Mass{1}));
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
