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

#include "../../include/PhQ/Unit/Diffusivity.hpp"

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

constexpr std::array<Diffusivity, 15> Units = {
  Diffusivity::SquareNauticalMilePerSecond,
  Diffusivity::SquareMilePerSecond,
  Diffusivity::SquareKilometrePerSecond,
  Diffusivity::HectarePerSecond,
  Diffusivity::AcrePerSecond,
  Diffusivity::SquareMetrePerSecond,
  Diffusivity::SquareYardPerSecond,
  Diffusivity::SquareFootPerSecond,
  Diffusivity::SquareDecimetrePerSecond,
  Diffusivity::SquareInchPerSecond,
  Diffusivity::SquareCentimetrePerSecond,
  Diffusivity::SquareMillimetrePerSecond,
  Diffusivity::SquareMilliinchPerSecond,
  Diffusivity::SquareMicrometrePerSecond,
  Diffusivity::SquareMicroinchPerSecond,
};

TEST(UnitDiffusivity, Abbreviation) {
  EXPECT_EQ(Abbreviation(Diffusivity::SquareNauticalMilePerSecond), "nmi^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMilePerSecond), "mi^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareKilometrePerSecond), "km^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::HectarePerSecond), "ha/s");
  EXPECT_EQ(Abbreviation(Diffusivity::AcrePerSecond), "ac/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMetrePerSecond), "m^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareYardPerSecond), "yd^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareFootPerSecond), "ft^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareDecimetrePerSecond), "dm^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareInchPerSecond), "in^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareCentimetrePerSecond), "cm^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMillimetrePerSecond), "mm^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMilliinchPerSecond), "mil^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMicrometrePerSecond), "μm^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMicroinchPerSecond), "μin^2/s");
}

TEST(UnitDiffusivity, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Diffusivity>(UnitSystem::MetreKilogramSecondKelvin),
            Diffusivity::SquareMetrePerSecond);
  EXPECT_EQ(ConsistentUnit<Diffusivity>(UnitSystem::MillimetreGramSecondKelvin),
            Diffusivity::SquareMillimetrePerSecond);
  EXPECT_EQ(ConsistentUnit<Diffusivity>(UnitSystem::FootPoundSecondRankine),
            Diffusivity::SquareFootPerSecond);
  EXPECT_EQ(ConsistentUnit<Diffusivity>(UnitSystem::InchPoundSecondRankine),
            Diffusivity::SquareInchPerSecond);
}

TEST(UnitDiffusivity, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareNauticalMilePerSecond, value,
      value / std::pow(1852.0L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareMilePerSecond, value,
      value / std::pow(1609.344L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareKilometrePerSecond, value,
      value * std::pow(0.001L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::HectarePerSecond, value, value * 0.0001L);
  Internal::TestConvert<Diffusivity>(Diffusivity::SquareMetrePerSecond, Diffusivity::AcrePerSecond,
                                     value, value * 640.0L / std::pow(1609.344L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareMetrePerSecond, value, value);
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareYardPerSecond, value,
      value / std::pow(0.9144L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareFootPerSecond, value,
      value / std::pow(0.3048L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareDecimetrePerSecond, value,
      value * std::pow(10.0L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareInchPerSecond, value,
      value / std::pow(0.0254L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareCentimetrePerSecond, value,
      value * std::pow(100.0L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareMillimetrePerSecond, value,
      value * std::pow(1000.0L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareMilliinchPerSecond, value,
      value / std::pow(0.0000254L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareMicrometrePerSecond, value,
      value * std::pow(1000000.0L, 2));
  Internal::TestConvert<Diffusivity>(
      Diffusivity::SquareMetrePerSecond, Diffusivity::SquareMicroinchPerSecond, value,
      value / std::pow(0.0000000254L, 2));
}

TEST(UnitDiffusivity, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                  Diffusivity::SquareFootPerSecond>(
      value, value / std::pow(0.3048L, 2));
}

TEST(UnitDiffusivity, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Diffusivity>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("nmi^2/s"), Diffusivity::SquareNauticalMilePerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("mi^2/s"), Diffusivity::SquareMilePerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("km^2/s"), Diffusivity::SquareKilometrePerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("ha/s"), Diffusivity::HectarePerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("ac/s"), Diffusivity::AcrePerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("m^2/s"), Diffusivity::SquareMetrePerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("yd^2/s"), Diffusivity::SquareYardPerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("ft^2/s"), Diffusivity::SquareFootPerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("dm^2/s"), Diffusivity::SquareDecimetrePerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("in^2/s"), Diffusivity::SquareInchPerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("cm^2/s"), Diffusivity::SquareCentimetrePerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("mm^2/s"), Diffusivity::SquareMillimetrePerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("mil^2/s"), Diffusivity::SquareMilliinchPerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("μm^2/s"), Diffusivity::SquareMicrometrePerSecond);
  EXPECT_EQ(ParseEnumeration<Diffusivity>("μin^2/s"), Diffusivity::SquareMicroinchPerSecond);
}

TEST(UnitDiffusivity, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Diffusivity>,
            Dimensions(Dimension::Time{-1}, Dimension::Length{2}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitDiffusivity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareNauticalMilePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareMilePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareKilometrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::HectarePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::AcrePerSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(Diffusivity::SquareMetrePerSecond), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareYardPerSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(Diffusivity::SquareFootPerSecond), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareDecimetrePerSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(Diffusivity::SquareInchPerSecond), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareCentimetrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareMillimetrePerSecond),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareMilliinchPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareMicrometrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareMicroinchPerSecond), std::nullopt);
}

TEST(UnitDiffusivity, Standard) {
  EXPECT_EQ(Standard<Diffusivity>, Diffusivity::SquareMetrePerSecond);
}

TEST(UnitDiffusivity, Stream) {
  std::ostringstream stream;
  stream << Diffusivity::SquareMetrePerSecond;
  EXPECT_EQ(stream.str(), Abbreviation(Diffusivity::SquareMetrePerSecond));
}

}  // namespace

}  // namespace PhQ::Unit
