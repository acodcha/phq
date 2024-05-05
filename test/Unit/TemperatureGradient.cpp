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

#include "../../include/PhQ/Unit/TemperatureGradient.hpp"

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

constexpr std::array<TemperatureGradient, 8> Units = {
    TemperatureGradient::KelvinPerMetre,    TemperatureGradient::KelvinPerMillimetre,
    TemperatureGradient::CelsiusPerMetre,   TemperatureGradient::CelsiusPerMillimetre,
    TemperatureGradient::RankinePerFoot,    TemperatureGradient::RankinePerInch,
    TemperatureGradient::FahrenheitPerFoot, TemperatureGradient::FahrenheitPerInch,
};

TEST(UnitTemperatureGradient, Abbreviation) {
  EXPECT_EQ(Abbreviation(TemperatureGradient::KelvinPerMetre), "K/m");
  EXPECT_EQ(Abbreviation(TemperatureGradient::KelvinPerMillimetre), "K/mm");
  EXPECT_EQ(Abbreviation(TemperatureGradient::CelsiusPerMetre), "°C/m");
  EXPECT_EQ(Abbreviation(TemperatureGradient::CelsiusPerMillimetre), "°C/mm");
  EXPECT_EQ(Abbreviation(TemperatureGradient::RankinePerFoot), "°R/ft");
  EXPECT_EQ(Abbreviation(TemperatureGradient::RankinePerInch), "°R/in");
  EXPECT_EQ(Abbreviation(TemperatureGradient::FahrenheitPerFoot), "°F/ft");
  EXPECT_EQ(Abbreviation(TemperatureGradient::FahrenheitPerInch), "°F/in");
}

TEST(UnitTemperatureGradient, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<TemperatureGradient>(UnitSystem::MetreKilogramSecondKelvin),
            TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(ConsistentUnit<TemperatureGradient>(UnitSystem::MillimetreGramSecondKelvin),
            TemperatureGradient::KelvinPerMillimetre);
  EXPECT_EQ(ConsistentUnit<TemperatureGradient>(UnitSystem::FootPoundSecondRankine),
            TemperatureGradient::RankinePerFoot);
  EXPECT_EQ(ConsistentUnit<TemperatureGradient>(UnitSystem::InchPoundSecondRankine),
            TemperatureGradient::RankinePerInch);
}

TEST(UnitTemperatureGradient, ConversionReciprocity) {
  constexpr long double original_value{1.234567890123456789L};
  for (const TemperatureGradient original_unit : Units) {
    for (const TemperatureGradient intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitTemperatureGradient, ConvertFromStandard) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::KelvinPerMetre,
                            TemperatureGradient::KelvinPerMetre>(value, value);
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::KelvinPerMetre,
                            TemperatureGradient::KelvinPerMillimetre>(value, value * 0.001L);
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::KelvinPerMetre,
                            TemperatureGradient::CelsiusPerMetre>(value, value);
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::KelvinPerMetre,
                            TemperatureGradient::CelsiusPerMillimetre>(value, value * 0.001L);
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::KelvinPerMetre,
                            TemperatureGradient::RankinePerFoot>(value, value * 1.8L * 0.3048L);
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::KelvinPerMetre,
                            TemperatureGradient::RankinePerInch>(value, value * 1.8L * 0.0254L);
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::KelvinPerMetre,
                            TemperatureGradient::FahrenheitPerFoot>(value, value * 1.8L * 0.3048L);
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::KelvinPerMetre,
                            TemperatureGradient::FahrenheitPerInch>(value, value * 1.8L * 0.0254L);
}

TEST(UnitTemperatureGradient, ConvertToStandard) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::KelvinPerMetre,
                            TemperatureGradient::KelvinPerMetre>(value, value);
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::KelvinPerMillimetre,
                            TemperatureGradient::KelvinPerMetre>(value, value * 1000.0L);
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::CelsiusPerMetre,
                            TemperatureGradient::KelvinPerMetre>(value, value);
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::CelsiusPerMillimetre,
                            TemperatureGradient::KelvinPerMetre>(value, value * 1000.0L);
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::RankinePerFoot,
                            TemperatureGradient::KelvinPerMetre>(value, value / (1.8L * 0.3048L));
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::RankinePerInch,
                            TemperatureGradient::KelvinPerMetre>(value, value / (1.8L * 0.0254L));
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::FahrenheitPerFoot,
                            TemperatureGradient::KelvinPerMetre>(value, value / (1.8L * 0.3048L));
  Internal::TestConversions<TemperatureGradient, TemperatureGradient::FahrenheitPerInch,
                            TemperatureGradient::KelvinPerMetre>(value, value / (1.8L * 0.0254L));
}

TEST(UnitTemperatureGradient, Parse) {
  EXPECT_EQ(Parse<TemperatureGradient>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<TemperatureGradient>("K/m"), TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(Parse<TemperatureGradient>("K/mm"), TemperatureGradient::KelvinPerMillimetre);
  EXPECT_EQ(Parse<TemperatureGradient>("°C/m"), TemperatureGradient::CelsiusPerMetre);
  EXPECT_EQ(Parse<TemperatureGradient>("°C/mm"), TemperatureGradient::CelsiusPerMillimetre);
  EXPECT_EQ(Parse<TemperatureGradient>("°R/ft"), TemperatureGradient::RankinePerFoot);
  EXPECT_EQ(Parse<TemperatureGradient>("°R/in"), TemperatureGradient::RankinePerInch);
  EXPECT_EQ(Parse<TemperatureGradient>("°F/ft"), TemperatureGradient::FahrenheitPerFoot);
  EXPECT_EQ(Parse<TemperatureGradient>("°F/in"), TemperatureGradient::FahrenheitPerInch);
}

TEST(UnitTemperatureGradient, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<TemperatureGradient>,
            Dimensions(Dimension::Time{}, Dimension::Length{-1}, Dimension::Mass{},
                       Dimension::ElectricCurrent{}, Dimension::Temperature{1}));
}

TEST(UnitTemperatureGradient, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::KelvinPerMetre),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::KelvinPerMillimetre),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::CelsiusPerMetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::CelsiusPerMillimetre), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(TemperatureGradient::RankinePerFoot), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(
      RelatedUnitSystem(TemperatureGradient::RankinePerInch), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::FahrenheitPerFoot), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::FahrenheitPerInch), std::nullopt);
}

TEST(UnitTemperatureGradient, Standard) {
  EXPECT_EQ(Standard<TemperatureGradient>, TemperatureGradient::KelvinPerMetre);
}

TEST(UnitTemperatureGradient, Stream) {
  std::ostringstream stream;
  stream << TemperatureGradient::KelvinPerMetre;
  EXPECT_EQ(stream.str(), Abbreviation(TemperatureGradient::KelvinPerMetre));
}

}  // namespace

}  // namespace PhQ::Unit
