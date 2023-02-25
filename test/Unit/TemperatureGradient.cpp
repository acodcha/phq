// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#include "../../include/PhQ/Unit/TemperatureGradient.hpp"

#include <gtest/gtest.h>

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<TemperatureGradient, 8> Units = {
    TemperatureGradient::KelvinPerMetre,
    TemperatureGradient::KelvinPerMillimetre,
    TemperatureGradient::CelsiusPerMetre,
    TemperatureGradient::CelsiusPerMillimetre,
    TemperatureGradient::RankinePerFoot,
    TemperatureGradient::RankinePerInch,
    TemperatureGradient::FahrenheitPerFoot,
    TemperatureGradient::FahrenheitPerInch,
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
  EXPECT_EQ(ConsistentUnit<TemperatureGradient>(
                UnitSystem::MetreKilogramSecondKelvin),
            TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(ConsistentUnit<TemperatureGradient>(
                UnitSystem::MillimetreGramSecondKelvin),
            TemperatureGradient::KelvinPerMillimetre);
  EXPECT_EQ(
      ConsistentUnit<TemperatureGradient>(UnitSystem::FootPoundSecondRankine),
      TemperatureGradient::RankinePerFoot);
  EXPECT_EQ(
      ConsistentUnit<TemperatureGradient>(UnitSystem::InchPoundSecondRankine),
      TemperatureGradient::RankinePerInch);
}

TEST(UnitTemperatureGradient, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::KelvinPerMetre,
                               TemperatureGradient::KelvinPerMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::KelvinPerMetre,
                               TemperatureGradient::KelvinPerMillimetre),
                   value * 0.001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::KelvinPerMetre,
                               TemperatureGradient::CelsiusPerMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::KelvinPerMetre,
                               TemperatureGradient::CelsiusPerMillimetre),
                   value * 0.001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::KelvinPerMetre,
                               TemperatureGradient::RankinePerFoot),
                   value * 1.8 * 0.3048);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::KelvinPerMetre,
                               TemperatureGradient::RankinePerInch),
                   value * 1.8 * 0.0254);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::KelvinPerMetre,
                               TemperatureGradient::FahrenheitPerFoot),
                   value * 1.8 * 0.3048);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::KelvinPerMetre,
                               TemperatureGradient::FahrenheitPerInch),
                   value * 1.8 * 0.0254);
}

TEST(UnitTemperatureGradient, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::KelvinPerMetre,
                               TemperatureGradient::KelvinPerMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::KelvinPerMillimetre,
                               TemperatureGradient::KelvinPerMetre),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::CelsiusPerMetre,
                               TemperatureGradient::KelvinPerMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::CelsiusPerMillimetre,
                               TemperatureGradient::KelvinPerMetre),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::RankinePerFoot,
                               TemperatureGradient::KelvinPerMetre),
                   value / (1.8 * 0.3048));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::RankinePerInch,
                               TemperatureGradient::KelvinPerMetre),
                   value / (1.8 * 0.0254));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::FahrenheitPerFoot,
                               TemperatureGradient::KelvinPerMetre),
                   value / (1.8 * 0.3048));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureGradient::FahrenheitPerInch,
                               TemperatureGradient::KelvinPerMetre),
                   value / (1.8 * 0.0254));
}

TEST(UnitTemperatureGradient, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const TemperatureGradient old_unit : Units) {
    for (const TemperatureGradient new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitTemperatureGradient, DimensionSet) {
  EXPECT_EQ(Dimensions<TemperatureGradient>,
            Dimension::Set(Dimension::Time{}, Dimension::Length{-1},
                           Dimension::Mass{}, Dimension::ElectricCurrent{},
                           Dimension::Temperature{1}));
}

TEST(UnitTemperatureGradient, Parse) {
  EXPECT_EQ(Parse<TemperatureGradient>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<TemperatureGradient>("K/m"),
            TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(Parse<TemperatureGradient>("K/mm"),
            TemperatureGradient::KelvinPerMillimetre);
  EXPECT_EQ(Parse<TemperatureGradient>("°C/m"),
            TemperatureGradient::CelsiusPerMetre);
  EXPECT_EQ(Parse<TemperatureGradient>("°C/mm"),
            TemperatureGradient::CelsiusPerMillimetre);
  EXPECT_EQ(Parse<TemperatureGradient>("°R/ft"),
            TemperatureGradient::RankinePerFoot);
  EXPECT_EQ(Parse<TemperatureGradient>("°R/in"),
            TemperatureGradient::RankinePerInch);
  EXPECT_EQ(Parse<TemperatureGradient>("°F/ft"),
            TemperatureGradient::FahrenheitPerFoot);
  EXPECT_EQ(Parse<TemperatureGradient>("°F/in"),
            TemperatureGradient::FahrenheitPerInch);
}

TEST(UnitTemperatureGradient, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::KelvinPerMetre),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::KelvinPerMillimetre),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::CelsiusPerMetre),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::CelsiusPerMillimetre),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::RankinePerFoot),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::RankinePerInch),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::FahrenheitPerFoot),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TemperatureGradient::FahrenheitPerInch),
            std::nullopt);
}

TEST(UnitTemperatureGradient, StandardUnit) {
  EXPECT_EQ(StandardUnit<TemperatureGradient>,
            TemperatureGradient::KelvinPerMetre);
}

}  // namespace

}  // namespace PhQ::Unit
