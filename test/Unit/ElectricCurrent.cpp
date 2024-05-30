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

#include "../../include/PhQ/Unit/ElectricCurrent.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<ElectricCurrent, 11> Units = {
    ElectricCurrent::Ampere,
    ElectricCurrent::Kiloampere,
    ElectricCurrent::Megaampere,
    ElectricCurrent::Gigaampere,
    ElectricCurrent::Teraampere,
    ElectricCurrent::Milliampere,
    ElectricCurrent::Microampere,
    ElectricCurrent::Nanoampere,
    ElectricCurrent::ElementaryChargePerSecond,
    ElectricCurrent::ElementaryChargePerMinute,
    ElectricCurrent::ElementaryChargePerHour,
};

TEST(UnitAngle, Abbreviation) {
  EXPECT_EQ(Abbreviation(ElectricCurrent::Ampere), "A");
  EXPECT_EQ(Abbreviation(ElectricCurrent::Kiloampere), "kA");
  EXPECT_EQ(Abbreviation(ElectricCurrent::Megaampere), "MA");
  EXPECT_EQ(Abbreviation(ElectricCurrent::Gigaampere), "GA");
  EXPECT_EQ(Abbreviation(ElectricCurrent::Teraampere), "TA");
  EXPECT_EQ(Abbreviation(ElectricCurrent::Milliampere), "mA");
  EXPECT_EQ(Abbreviation(ElectricCurrent::Microampere), "μA");
  EXPECT_EQ(Abbreviation(ElectricCurrent::Nanoampere), "nA");
  EXPECT_EQ(Abbreviation(ElectricCurrent::ElementaryChargePerSecond), "e/s");
  EXPECT_EQ(Abbreviation(ElectricCurrent::ElementaryChargePerMinute), "e/min");
  EXPECT_EQ(Abbreviation(ElectricCurrent::ElementaryChargePerHour), "e/hr");
}

TEST(UnitAngle, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<ElectricCurrent>(UnitSystem::MetreKilogramSecondKelvin),
            ElectricCurrent::Ampere);
  EXPECT_EQ(ConsistentUnit<ElectricCurrent>(UnitSystem::MillimetreGramSecondKelvin),
            ElectricCurrent::Ampere);
  EXPECT_EQ(
      ConsistentUnit<ElectricCurrent>(UnitSystem::FootPoundSecondRankine), ElectricCurrent::Ampere);
  EXPECT_EQ(
      ConsistentUnit<ElectricCurrent>(UnitSystem::InchPoundSecondRankine), ElectricCurrent::Ampere);
}

TEST(UnitAngle, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<ElectricCurrent>(
      ElectricCurrent::Ampere, ElectricCurrent::Ampere, value, value);
  Internal::TestConvertAndConvertCopy<ElectricCurrent>(
      ElectricCurrent::Ampere, ElectricCurrent::Kiloampere, value, value * 0.001L);
  Internal::TestConvertAndConvertCopy<ElectricCurrent>(
      ElectricCurrent::Ampere, ElectricCurrent::Megaampere, value, value * 1.0E-6L);
  Internal::TestConvertAndConvertCopy<ElectricCurrent>(
      ElectricCurrent::Ampere, ElectricCurrent::Gigaampere, value, value * 1.0E-9L);
  Internal::TestConvertAndConvertCopy<ElectricCurrent>(
      ElectricCurrent::Ampere, ElectricCurrent::Teraampere, value, value * 1.0E-12L);
  Internal::TestConvertAndConvertCopy<ElectricCurrent>(
      ElectricCurrent::Ampere, ElectricCurrent::Milliampere, value, value * 1000.0L);
  Internal::TestConvertAndConvertCopy<ElectricCurrent>(
      ElectricCurrent::Ampere, ElectricCurrent::Microampere, value, value * 1.0E6L);
  Internal::TestConvertAndConvertCopy<ElectricCurrent>(
      ElectricCurrent::Ampere, ElectricCurrent::Nanoampere, value, value * 1.0E9L);
  Internal::TestConvertAndConvertCopy<ElectricCurrent>(
      ElectricCurrent::Ampere, ElectricCurrent::ElementaryChargePerSecond, value,
      value / 1.602176634E-19L);
  Internal::TestConvertAndConvertCopy<ElectricCurrent>(
      ElectricCurrent::Ampere, ElectricCurrent::ElementaryChargePerMinute, value,
      value * 60.0L / 1.602176634E-19L);
  Internal::TestConvertAndConvertCopy<ElectricCurrent>(
      ElectricCurrent::Ampere, ElectricCurrent::ElementaryChargePerHour, value,
      value * 3600.0L / 1.602176634E-19L);
}

TEST(UnitAngle, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("A"), ElectricCurrent::Ampere);
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("kA"), ElectricCurrent::Kiloampere);
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("MA"), ElectricCurrent::Megaampere);
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("GA"), ElectricCurrent::Gigaampere);
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("TA"), ElectricCurrent::Teraampere);
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("mA"), ElectricCurrent::Milliampere);
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("μA"), ElectricCurrent::Microampere);
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("nA"), ElectricCurrent::Nanoampere);
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("e/s"), ElectricCurrent::ElementaryChargePerSecond);
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("e/min"), ElectricCurrent::ElementaryChargePerMinute);
  EXPECT_EQ(ParseEnumeration<ElectricCurrent>("e/hr"), ElectricCurrent::ElementaryChargePerHour);
}

TEST(UnitAngle, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<ElectricCurrent>,
            Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{1}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitAngle, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(ElectricCurrent::Ampere), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCurrent::Kiloampere), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCurrent::Megaampere), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCurrent::Gigaampere), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCurrent::Teraampere), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCurrent::Milliampere), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCurrent::Microampere), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCurrent::Nanoampere), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCurrent::ElementaryChargePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCurrent::ElementaryChargePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCurrent::ElementaryChargePerHour), std::nullopt);
}

TEST(UnitAngle, Standard) {
  EXPECT_EQ(Standard<ElectricCurrent>, ElectricCurrent::Ampere);
}

TEST(UnitAngle, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<ElectricCurrent, ElectricCurrent::Ampere,
                                  ElectricCurrent::Kiloampere>(value, value * 0.001L);
}

TEST(UnitAngle, Stream) {
  std::ostringstream stream;
  stream << ElectricCurrent::Ampere;
  EXPECT_EQ(stream.str(), Abbreviation(ElectricCurrent::Ampere));
}

}  // namespace

}  // namespace PhQ::Unit
