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

#include "../../include/PhQ/Unit/Area.hpp"

#include <array>
#include <cmath>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Area, 15> Units = {
    Area::SquareNauticalMile,
    Area::SquareMile,
    Area::SquareKilometre,
    Area::Hectare,
    Area::Acre,
    Area::SquareMetre,
    Area::SquareYard,
    Area::SquareFoot,
    Area::SquareDecimetre,
    Area::SquareInch,
    Area::SquareCentimetre,
    Area::SquareMillimetre,
    Area::SquareMilliinch,
    Area::SquareMicrometre,
    Area::SquareMicroinch,
};

TEST(UnitArea, Abbreviation) {
  EXPECT_EQ(Abbreviation(Area::SquareNauticalMile), "nmi^2");
  EXPECT_EQ(Abbreviation(Area::SquareMile), "mi^2");
  EXPECT_EQ(Abbreviation(Area::SquareKilometre), "km^2");
  EXPECT_EQ(Abbreviation(Area::Hectare), "ha");
  EXPECT_EQ(Abbreviation(Area::Acre), "ac");
  EXPECT_EQ(Abbreviation(Area::SquareMetre), "m^2");
  EXPECT_EQ(Abbreviation(Area::SquareYard), "yd^2");
  EXPECT_EQ(Abbreviation(Area::SquareFoot), "ft^2");
  EXPECT_EQ(Abbreviation(Area::SquareDecimetre), "dm^2");
  EXPECT_EQ(Abbreviation(Area::SquareInch), "in^2");
  EXPECT_EQ(Abbreviation(Area::SquareCentimetre), "cm^2");
  EXPECT_EQ(Abbreviation(Area::SquareMillimetre), "mm^2");
  EXPECT_EQ(Abbreviation(Area::SquareMilliinch), "mil^2");
  EXPECT_EQ(Abbreviation(Area::SquareMicrometre), "μm^2");
  EXPECT_EQ(Abbreviation(Area::SquareMicroinch), "μin^2");
}

TEST(UnitArea, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Area>(UnitSystem::MetreKilogramSecondKelvin), Area::SquareMetre);
  EXPECT_EQ(ConsistentUnit<Area>(UnitSystem::MillimetreGramSecondKelvin), Area::SquareMillimetre);
  EXPECT_EQ(ConsistentUnit<Area>(UnitSystem::FootPoundSecondRankine), Area::SquareFoot);
  EXPECT_EQ(ConsistentUnit<Area>(UnitSystem::InchPoundSecondRankine), Area::SquareInch);
}

TEST(UnitArea, ConversionReciprocity) {
  constexpr long double original_value{1.234567890123456789L};
  for (const Area original_unit : Units) {
    for (const Area intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitArea, ConvertFromStandard) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareNauticalMile>(
      value, value / std::pow(1852.0L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareMile>(
      value, value / std::pow(1609.344L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareKilometre>(
      value, value * std::pow(0.001L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::Hectare>(value, value * 0.0001L);
  Internal::TestConversions<Area, Area::SquareMetre, Area::Acre>(
      value, value * 640.0L / std::pow(1609.344L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareMetre>(value, value);
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareYard>(
      value, value / std::pow(0.9144L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareFoot>(
      value, value / std::pow(0.3048L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareDecimetre>(
      value, value * std::pow(10.0L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareInch>(
      value, value / std::pow(0.0254L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareCentimetre>(
      value, value * std::pow(100.0L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareMillimetre>(
      value, value * std::pow(1000.0L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareMilliinch>(
      value, value / std::pow(0.0000254L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareMicrometre>(
      value, value * std::pow(1000000.0L, 2));
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareMicroinch>(
      value, value / std::pow(0.0000000254L, 2));
}

TEST(UnitArea, ConvertToStandard) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConversions<Area, Area::SquareNauticalMile, Area::SquareMetre>(
      value, value * std::pow(1852.0L, 2));
  Internal::TestConversions<Area, Area::SquareMile, Area::SquareMetre>(
      value, value * std::pow(1609.344L, 2));
  Internal::TestConversions<Area, Area::SquareKilometre, Area::SquareMetre>(
      value, value * std::pow(1000.0L, 2));
  Internal::TestConversions<Area, Area::Hectare, Area::SquareMetre>(value, value * 10000.0L);
  Internal::TestConversions<Area, Area::Acre, Area::SquareMetre>(
      value, value * std::pow(1609.344L, 2) / 640.0L);
  Internal::TestConversions<Area, Area::SquareMetre, Area::SquareMetre>(value, value);
  Internal::TestConversions<Area, Area::SquareYard, Area::SquareMetre>(
      value, value * std::pow(0.9144L, 2));
  Internal::TestConversions<Area, Area::SquareFoot, Area::SquareMetre>(
      value, value * std::pow(0.3048L, 2));
  Internal::TestConversions<Area, Area::SquareDecimetre, Area::SquareMetre>(
      value, value * std::pow(0.1, 2));
  Internal::TestConversions<Area, Area::SquareInch, Area::SquareMetre>(
      value, value * std::pow(0.0254L, 2));
  Internal::TestConversions<Area, Area::SquareCentimetre, Area::SquareMetre>(
      value, value * std::pow(0.01, 2));
  Internal::TestConversions<Area, Area::SquareMillimetre, Area::SquareMetre>(
      value, value * std::pow(0.001L, 2));
  Internal::TestConversions<Area, Area::SquareMilliinch, Area::SquareMetre>(
      value, value * std::pow(0.0000254L, 2));
  Internal::TestConversions<Area, Area::SquareMicrometre, Area::SquareMetre>(
      value, value * std::pow(0.000001, 2));
  Internal::TestConversions<Area, Area::SquareMicroinch, Area::SquareMetre>(
      value, value * std::pow(0.0000000254L, 2));
}

TEST(UnitArea, Parse) {
  EXPECT_EQ(Parse<Area>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Area>("nmi^2"), Area::SquareNauticalMile);
  EXPECT_EQ(Parse<Area>("mi^2"), Area::SquareMile);
  EXPECT_EQ(Parse<Area>("km^2"), Area::SquareKilometre);
  EXPECT_EQ(Parse<Area>("ha"), Area::Hectare);
  EXPECT_EQ(Parse<Area>("ac"), Area::Acre);
  EXPECT_EQ(Parse<Area>("m^2"), Area::SquareMetre);
  EXPECT_EQ(Parse<Area>("yd^2"), Area::SquareYard);
  EXPECT_EQ(Parse<Area>("ft^2"), Area::SquareFoot);
  EXPECT_EQ(Parse<Area>("dm^2"), Area::SquareDecimetre);
  EXPECT_EQ(Parse<Area>("in^2"), Area::SquareInch);
  EXPECT_EQ(Parse<Area>("cm^2"), Area::SquareCentimetre);
  EXPECT_EQ(Parse<Area>("mm^2"), Area::SquareMillimetre);
  EXPECT_EQ(Parse<Area>("mil^2"), Area::SquareMilliinch);
  EXPECT_EQ(Parse<Area>("μm^2"), Area::SquareMicrometre);
  EXPECT_EQ(Parse<Area>("μin^2"), Area::SquareMicroinch);
}

TEST(UnitArea, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Area>, Dimensions(Dimension::Time{0}, Dimension::Length{2}));
}

TEST(UnitArea, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Area::SquareNauticalMile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareKilometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::Hectare), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::Acre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMetre), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareYard), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareFoot), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareDecimetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareInch), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareCentimetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMillimetre), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMilliinch), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMicrometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMicroinch), std::nullopt);
}

TEST(UnitArea, Standard) {
  EXPECT_EQ(Standard<Area>, Area::SquareMetre);
}

TEST(UnitArea, Stream) {
  std::ostringstream stream;
  stream << Area::SquareMetre;
  EXPECT_EQ(stream.str(), Abbreviation(Area::SquareMetre));
}

}  // namespace

}  // namespace PhQ::Unit
