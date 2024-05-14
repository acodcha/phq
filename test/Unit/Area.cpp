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

TEST(UnitArea, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareNauticalMile, value, value / std::pow(1852.0L, 2));
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareMile, value, value / std::pow(1609.344L, 2));
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareKilometre, value, value * std::pow(0.001L, 2));
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::Hectare, value, value * 0.0001L);
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::Acre, value, value * 640.0L / std::pow(1609.344L, 2));
  Internal::TestConvertAndConvertCopy<Area>(Area::SquareMetre, Area::SquareMetre, value, value);
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareYard, value, value / std::pow(0.9144L, 2));
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareFoot, value, value / std::pow(0.3048L, 2));
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareDecimetre, value, value * std::pow(10.0L, 2));
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareInch, value, value / std::pow(0.0254L, 2));
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareCentimetre, value, value * std::pow(100.0L, 2));
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareMillimetre, value, value * std::pow(1000.0L, 2));
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareMilliinch, value, value / std::pow(0.0000254L, 2));
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareMicrometre, value, value * std::pow(1000000.0L, 2));
  Internal::TestConvertAndConvertCopy<Area>(
      Area::SquareMetre, Area::SquareMicroinch, value, value / std::pow(0.0000000254L, 2));
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

TEST(UnitArea, StaticConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestStaticConvertCopy<Area, Area::SquareMetre, Area::SquareFoot>(
      value, value / std::pow(0.3048L, 2));
}

TEST(UnitArea, Stream) {
  std::ostringstream stream;
  stream << Area::SquareMetre;
  EXPECT_EQ(stream.str(), Abbreviation(Area::SquareMetre));
}

}  // namespace

}  // namespace PhQ::Unit
