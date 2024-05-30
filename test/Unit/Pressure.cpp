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

#include "../../include/PhQ/Unit/Pressure.hpp"

#include <array>
#include <cmath>
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

constexpr std::array<Pressure, 8> Units = {
    Pressure::Pascal,
    Pressure::Kilopascal,
    Pressure::Megapascal,
    Pressure::Gigapascal,
    Pressure::Bar,
    Pressure::Atmosphere,
    Pressure::PoundPerSquareFoot,
    Pressure::PoundPerSquareInch,
};

TEST(UnitPressure, Abbreviation) {
  EXPECT_EQ(Abbreviation(Pressure::Pascal), "Pa");
  EXPECT_EQ(Abbreviation(Pressure::Kilopascal), "kPa");
  EXPECT_EQ(Abbreviation(Pressure::Megapascal), "MPa");
  EXPECT_EQ(Abbreviation(Pressure::Gigapascal), "GPa");
  EXPECT_EQ(Abbreviation(Pressure::Bar), "bar");
  EXPECT_EQ(Abbreviation(Pressure::Atmosphere), "atm");
  EXPECT_EQ(Abbreviation(Pressure::PoundPerSquareFoot), "lbf/ft^2");
  EXPECT_EQ(Abbreviation(Pressure::PoundPerSquareInch), "lbf/in^2");
}

TEST(UnitPressure, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Pressure>(UnitSystem::MetreKilogramSecondKelvin), Pressure::Pascal);
  EXPECT_EQ(ConsistentUnit<Pressure>(UnitSystem::MillimetreGramSecondKelvin), Pressure::Pascal);
  EXPECT_EQ(
      ConsistentUnit<Pressure>(UnitSystem::FootPoundSecondRankine), Pressure::PoundPerSquareFoot);
  EXPECT_EQ(
      ConsistentUnit<Pressure>(UnitSystem::InchPoundSecondRankine), Pressure::PoundPerSquareInch);
}

TEST(UnitPressure, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<Pressure>(Pressure::Pascal, Pressure::Pascal, value, value);
  Internal::TestConvert<Pressure>(Pressure::Pascal, Pressure::Kilopascal, value, value * 0.001L);
  Internal::TestConvert<Pressure>(Pressure::Pascal, Pressure::Megapascal, value, value * 0.000001L);
  Internal::TestConvert<Pressure>(
      Pressure::Pascal, Pressure::Gigapascal, value, value * 0.000000001L);
  Internal::TestConvert<Pressure>(Pressure::Pascal, Pressure::Bar, value, value * 0.00001L);
  Internal::TestConvert<Pressure>(Pressure::Pascal, Pressure::Atmosphere, value, value / 101325.0L);
  Internal::TestConvert<Pressure>(Pressure::Pascal, Pressure::PoundPerSquareFoot, value,
                                  value * std::pow(0.3048L, 2) / (0.45359237L * 9.80665L));
  Internal::TestConvert<Pressure>(Pressure::Pascal, Pressure::PoundPerSquareInch, value,
                                  value * std::pow(0.0254L, 2) / (0.45359237L * 9.80665L));
}

TEST(UnitPressure, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Pressure, Pressure::Pascal, Pressure::PoundPerSquareFoot>(
      value, value * std::pow(0.3048L, 2) / (0.45359237L * 9.80665L));
}

TEST(UnitPressure, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Pressure>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Pressure>("Pa"), Pressure::Pascal);
  EXPECT_EQ(ParseEnumeration<Pressure>("kPa"), Pressure::Kilopascal);
  EXPECT_EQ(ParseEnumeration<Pressure>("MPa"), Pressure::Megapascal);
  EXPECT_EQ(ParseEnumeration<Pressure>("GPa"), Pressure::Gigapascal);
  EXPECT_EQ(ParseEnumeration<Pressure>("bar"), Pressure::Bar);
  EXPECT_EQ(ParseEnumeration<Pressure>("atm"), Pressure::Atmosphere);
  EXPECT_EQ(ParseEnumeration<Pressure>("lbf/ft^2"), Pressure::PoundPerSquareFoot);
  EXPECT_EQ(ParseEnumeration<Pressure>("lbf/in^2"), Pressure::PoundPerSquareInch);
}

TEST(UnitPressure, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Pressure>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{-1}, Dimension::Mass{1},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitPressure, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Pressure::Pascal), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Pressure::Kilopascal), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Pressure::Megapascal), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Pressure::Gigapascal), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Pressure::Bar), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Pressure::Atmosphere), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Pressure::PoundPerSquareFoot), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Pressure::PoundPerSquareInch), UnitSystem::InchPoundSecondRankine);
}

TEST(UnitPressure, Standard) {
  EXPECT_EQ(Standard<Pressure>, Pressure::Pascal);
}

TEST(UnitPressure, Stream) {
  std::ostringstream stream;
  stream << Pressure::Pascal;
  EXPECT_EQ(stream.str(), Abbreviation(Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ::Unit
