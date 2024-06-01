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

TEST(UnitTemperatureGradient, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<TemperatureGradient>(
      TemperatureGradient::KelvinPerMetre, TemperatureGradient::KelvinPerMetre, value, value);
  Internal::TestConvert<TemperatureGradient>(
      TemperatureGradient::KelvinPerMetre, TemperatureGradient::KelvinPerMillimetre, value,
      value * 0.001L);
  Internal::TestConvert<TemperatureGradient>(
      TemperatureGradient::KelvinPerMetre, TemperatureGradient::CelsiusPerMetre, value, value);
  Internal::TestConvert<TemperatureGradient>(
      TemperatureGradient::KelvinPerMetre, TemperatureGradient::CelsiusPerMillimetre, value,
      value * 0.001L);
  Internal::TestConvert<TemperatureGradient>(
      TemperatureGradient::KelvinPerMetre, TemperatureGradient::RankinePerFoot, value,
      value * 1.8L * 0.3048L);
  Internal::TestConvert<TemperatureGradient>(
      TemperatureGradient::KelvinPerMetre, TemperatureGradient::RankinePerInch, value,
      value * 1.8L * 0.0254L);
  Internal::TestConvert<TemperatureGradient>(
      TemperatureGradient::KelvinPerMetre, TemperatureGradient::FahrenheitPerFoot, value,
      value * 1.8L * 0.3048L);
  Internal::TestConvert<TemperatureGradient>(
      TemperatureGradient::KelvinPerMetre, TemperatureGradient::FahrenheitPerInch, value,
      value * 1.8L * 0.0254L);
}

TEST(UnitTemperatureGradient, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<TemperatureGradient, TemperatureGradient::KelvinPerMetre,
                                  TemperatureGradient::FahrenheitPerFoot>(
      value, value * 1.8L * 0.3048L);
}

TEST(UnitTemperatureGradient, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<TemperatureGradient>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<TemperatureGradient>("K/m"), TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(
      ParseEnumeration<TemperatureGradient>("K/mm"), TemperatureGradient::KelvinPerMillimetre);
  EXPECT_EQ(ParseEnumeration<TemperatureGradient>("°C/m"), TemperatureGradient::CelsiusPerMetre);
  EXPECT_EQ(
      ParseEnumeration<TemperatureGradient>("°C/mm"), TemperatureGradient::CelsiusPerMillimetre);
  EXPECT_EQ(ParseEnumeration<TemperatureGradient>("°R/ft"), TemperatureGradient::RankinePerFoot);
  EXPECT_EQ(ParseEnumeration<TemperatureGradient>("°R/in"), TemperatureGradient::RankinePerInch);
  EXPECT_EQ(ParseEnumeration<TemperatureGradient>("°F/ft"), TemperatureGradient::FahrenheitPerFoot);
  EXPECT_EQ(ParseEnumeration<TemperatureGradient>("°F/in"), TemperatureGradient::FahrenheitPerInch);
}

TEST(UnitTemperatureGradient, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<TemperatureGradient>,
            Dimensions(Dimension::Time{0}, Dimension::Length{-1}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{1},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
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
