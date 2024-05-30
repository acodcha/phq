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

#include "../../include/PhQ/Unit/ThermalConductivity.hpp"

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

constexpr std::array<ThermalConductivity, 3> Units = {
    ThermalConductivity::WattPerMetrePerKelvin,
    ThermalConductivity::NanowattPerMillimetrePerKelvin,
    ThermalConductivity::PoundPerSecondPerRankine,
};

TEST(UnitThermalConductivity, Abbreviation) {
  EXPECT_EQ(Abbreviation(ThermalConductivity::WattPerMetrePerKelvin), "W/m/K");
  EXPECT_EQ(Abbreviation(ThermalConductivity::NanowattPerMillimetrePerKelvin), "nW/mm/K");
  EXPECT_EQ(Abbreviation(ThermalConductivity::PoundPerSecondPerRankine), "lbf/s/°R");
}

TEST(UnitThermalConductivity, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<ThermalConductivity>(UnitSystem::MetreKilogramSecondKelvin),
            ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(ConsistentUnit<ThermalConductivity>(UnitSystem::MillimetreGramSecondKelvin),
            ThermalConductivity::NanowattPerMillimetrePerKelvin);
  EXPECT_EQ(ConsistentUnit<ThermalConductivity>(UnitSystem::FootPoundSecondRankine),
            ThermalConductivity::PoundPerSecondPerRankine);
  EXPECT_EQ(ConsistentUnit<ThermalConductivity>(UnitSystem::InchPoundSecondRankine),
            ThermalConductivity::PoundPerSecondPerRankine);
}

TEST(UnitThermalConductivity, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<ThermalConductivity>(
      ThermalConductivity::WattPerMetrePerKelvin, ThermalConductivity::WattPerMetrePerKelvin, value,
      value);
  Internal::TestConvertAndConvertCopy<ThermalConductivity>(
      ThermalConductivity::WattPerMetrePerKelvin,
      ThermalConductivity::NanowattPerMillimetrePerKelvin, value, value * 1000000.0L);
  Internal::TestConvertAndConvertCopy<ThermalConductivity>(
      ThermalConductivity::WattPerMetrePerKelvin, ThermalConductivity::PoundPerSecondPerRankine,
      value, value / (0.45359237L * 9.80665L * 1.8L));
}

TEST(UnitThermalConductivity, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<ThermalConductivity, ThermalConductivity::WattPerMetrePerKelvin,
                                  ThermalConductivity::PoundPerSecondPerRankine>(
      value, value / (0.45359237L * 9.80665L * 1.8L));
}

TEST(UnitThermalConductivity, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<ThermalConductivity>("Hello world!"), std::nullopt);
  EXPECT_EQ(
      ParseEnumeration<ThermalConductivity>("W/m/K"), ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(ParseEnumeration<ThermalConductivity>("nW/mm/°C"),
            ThermalConductivity::NanowattPerMillimetrePerKelvin);
  EXPECT_EQ(ParseEnumeration<ThermalConductivity>("lbf/s/°R"),
            ThermalConductivity::PoundPerSecondPerRankine);
}

TEST(UnitThermalConductivity, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<ThermalConductivity>,
            Dimensions(Dimension::Time{-3}, Dimension::Length{1}, Dimension::Mass{1},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{-1},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitThermalConductivity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(ThermalConductivity::WattPerMetrePerKelvin),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(ThermalConductivity::NanowattPerMillimetrePerKelvin),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(ThermalConductivity::PoundPerSecondPerRankine), std::nullopt);
}

TEST(UnitThermalConductivity, Standard) {
  EXPECT_EQ(Standard<ThermalConductivity>, ThermalConductivity::WattPerMetrePerKelvin);
}

TEST(UnitThermalConductivity, Stream) {
  std::ostringstream stream;
  stream << ThermalConductivity::WattPerMetrePerKelvin;
  EXPECT_EQ(stream.str(), Abbreviation(ThermalConductivity::WattPerMetrePerKelvin));
}

}  // namespace

}  // namespace PhQ::Unit
