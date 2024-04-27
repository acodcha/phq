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

TEST(UnitPressure, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const Pressure original_unit : Units) {
    for (const Pressure intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitPressure, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(Pressure::Pascal, Pressure::Pascal, value, value);
  Internal::TestConversions(Pressure::Pascal, Pressure::Kilopascal, value, value * 0.001);
  Internal::TestConversions(Pressure::Pascal, Pressure::Megapascal, value, value * 0.000001);
  Internal::TestConversions(Pressure::Pascal, Pressure::Gigapascal, value, value * 0.000000001);
  Internal::TestConversions(Pressure::Pascal, Pressure::Bar, value, value * 0.00001);
  Internal::TestConversions(Pressure::Pascal, Pressure::Atmosphere, value, value / 101325.0);
  Internal::TestConversions(Pressure::Pascal, Pressure::PoundPerSquareFoot, value,
                            value * std::pow(0.3048, 2) / (0.45359237 * 9.80665));
  Internal::TestConversions(Pressure::Pascal, Pressure::PoundPerSquareInch, value,
                            value * std::pow(0.0254, 2) / (0.45359237 * 9.80665));

  Internal::TestStaticConversions<Pressure, Pressure::Pascal, Pressure::PoundPerSquareFoot>(
      value, value * std::pow(0.3048, 2) / (0.45359237 * 9.80665));
}

TEST(UnitPressure, ConvertToStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(Pressure::Pascal, Pressure::Pascal, value, value);
  Internal::TestConversions(Pressure::Kilopascal, Pressure::Pascal, value, value * 1000.0);
  Internal::TestConversions(Pressure::Megapascal, Pressure::Pascal, value, value * 1000000.0);
  Internal::TestConversions(Pressure::Gigapascal, Pressure::Pascal, value, value * 1000000000.0);
  Internal::TestConversions(Pressure::Bar, Pressure::Pascal, value, value * 100000.0);
  Internal::TestConversions(Pressure::Atmosphere, Pressure::Pascal, value, value * 101325.0);
  Internal::TestConversions(Pressure::PoundPerSquareFoot, Pressure::Pascal, value,
                            value * 0.45359237 * 9.80665 / std::pow(0.3048, 2));
  Internal::TestConversions(Pressure::PoundPerSquareInch, Pressure::Pascal, value,
                            value * 0.45359237 * 9.80665 / std::pow(0.0254, 2));

  Internal::TestStaticConversions<Pressure, Pressure::PoundPerSquareFoot, Pressure::Pascal>(
      value, value * 0.45359237 * 9.80665 / std::pow(0.3048, 2));
}

TEST(UnitPressure, Parse) {
  EXPECT_EQ(Parse<Pressure>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Pressure>("Pa"), Pressure::Pascal);
  EXPECT_EQ(Parse<Pressure>("kPa"), Pressure::Kilopascal);
  EXPECT_EQ(Parse<Pressure>("MPa"), Pressure::Megapascal);
  EXPECT_EQ(Parse<Pressure>("GPa"), Pressure::Gigapascal);
  EXPECT_EQ(Parse<Pressure>("bar"), Pressure::Bar);
  EXPECT_EQ(Parse<Pressure>("atm"), Pressure::Atmosphere);
  EXPECT_EQ(Parse<Pressure>("lbf/ft^2"), Pressure::PoundPerSquareFoot);
  EXPECT_EQ(Parse<Pressure>("lbf/in^2"), Pressure::PoundPerSquareInch);
}

TEST(UnitPressure, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Pressure>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{-1}, Dimension::Mass{1}));
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
