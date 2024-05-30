// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
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

#include "../../include/PhQ/Unit/EnergyFlux.hpp"

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

constexpr std::array<EnergyFlux, 4> Units = {
    EnergyFlux::WattPerSquareMetre,
    EnergyFlux::NanowattPerSquareMillimetre,
    EnergyFlux::FootPoundPerSquareFootPerSecond,
    EnergyFlux::InchPoundPerSquareInchPerSecond,
};

TEST(UnitEnergyFlux, Abbreviation) {
  EXPECT_EQ(Abbreviation(EnergyFlux::WattPerSquareMetre), "W/m^2");
  EXPECT_EQ(Abbreviation(EnergyFlux::NanowattPerSquareMillimetre), "nW/mm^2");
  EXPECT_EQ(Abbreviation(EnergyFlux::FootPoundPerSquareFootPerSecond), "ft·lbf/ft^2/s");
  EXPECT_EQ(Abbreviation(EnergyFlux::InchPoundPerSquareInchPerSecond), "in·lbf/in^2/s");
}

TEST(UnitEnergyFlux, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<EnergyFlux>(UnitSystem::MetreKilogramSecondKelvin),
            EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(ConsistentUnit<EnergyFlux>(UnitSystem::MillimetreGramSecondKelvin),
            EnergyFlux::NanowattPerSquareMillimetre);
  EXPECT_EQ(ConsistentUnit<EnergyFlux>(UnitSystem::FootPoundSecondRankine),
            EnergyFlux::FootPoundPerSquareFootPerSecond);
  EXPECT_EQ(ConsistentUnit<EnergyFlux>(UnitSystem::InchPoundSecondRankine),
            EnergyFlux::InchPoundPerSquareInchPerSecond);
}

TEST(UnitEnergyFlux, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<EnergyFlux>(
      EnergyFlux::WattPerSquareMetre, EnergyFlux::WattPerSquareMetre, value, value);
  Internal::TestConvert<EnergyFlux>(
      EnergyFlux::WattPerSquareMetre, EnergyFlux::NanowattPerSquareMillimetre, value,
      value * 1000.0L);
  Internal::TestConvert<EnergyFlux>(
      EnergyFlux::WattPerSquareMetre, EnergyFlux::FootPoundPerSquareFootPerSecond, value,
      value * 0.3048L / (0.45359237L * 9.80665L));
  Internal::TestConvert<EnergyFlux>(
      EnergyFlux::WattPerSquareMetre, EnergyFlux::InchPoundPerSquareInchPerSecond, value,
      value * 0.0254L / (0.45359237L * 9.80665L));
}

TEST(UnitEnergyFlux, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<EnergyFlux, EnergyFlux::WattPerSquareMetre,
                                  EnergyFlux::FootPoundPerSquareFootPerSecond>(
      value, value * 0.3048L / (0.45359237L * 9.80665L));
}

TEST(UnitEnergyFlux, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<EnergyFlux>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<EnergyFlux>("W/m^2"), EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(ParseEnumeration<EnergyFlux>("nW/mm^2"), EnergyFlux::NanowattPerSquareMillimetre);
  EXPECT_EQ(
      ParseEnumeration<EnergyFlux>("ft·lbf/ft^2/s"), EnergyFlux::FootPoundPerSquareFootPerSecond);
  EXPECT_EQ(
      ParseEnumeration<EnergyFlux>("in·lbf/in^2/s"), EnergyFlux::InchPoundPerSquareInchPerSecond);
}

TEST(UnitEnergyFlux, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<EnergyFlux>,
            Dimensions(Dimension::Time{-3}, Dimension::Length{0}, Dimension::Mass{1},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitEnergyFlux, RelatedUnitSystem) {
  EXPECT_EQ(
      RelatedUnitSystem(EnergyFlux::WattPerSquareMetre), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(EnergyFlux::NanowattPerSquareMillimetre),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(EnergyFlux::FootPoundPerSquareFootPerSecond),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(EnergyFlux::InchPoundPerSquareInchPerSecond),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitEnergyFlux, Standard) {
  EXPECT_EQ(Standard<EnergyFlux>, EnergyFlux::WattPerSquareMetre);
}

TEST(UnitEnergyFlux, Stream) {
  std::ostringstream stream;
  stream << EnergyFlux::WattPerSquareMetre;
  EXPECT_EQ(stream.str(), Abbreviation(EnergyFlux::WattPerSquareMetre));
}

}  // namespace

}  // namespace PhQ::Unit
