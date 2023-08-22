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

#include "../../include/PhQ/Unit/EnergyFlux.hpp"

#include <gtest/gtest.h>

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
  EXPECT_EQ(Abbreviation(EnergyFlux::FootPoundPerSquareFootPerSecond),
            "ft·lbf/ft^2/s");
  EXPECT_EQ(Abbreviation(EnergyFlux::InchPoundPerSquareInchPerSecond),
            "in·lbf/in^2/s");
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

TEST(UnitEnergyFlux, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, EnergyFlux::WattPerSquareMetre,
                               EnergyFlux::WattPerSquareMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, EnergyFlux::WattPerSquareMetre,
                               EnergyFlux::NanowattPerSquareMillimetre),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, EnergyFlux::WattPerSquareMetre,
                               EnergyFlux::FootPoundPerSquareFootPerSecond),
                   value * 0.3048 / (0.45359237 * 9.80665));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, EnergyFlux::WattPerSquareMetre,
                               EnergyFlux::InchPoundPerSquareInchPerSecond),
                   value * 0.0254 / (0.45359237 * 9.80665));
}

TEST(UnitEnergyFlux, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, EnergyFlux::WattPerSquareMetre,
                               EnergyFlux::WattPerSquareMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, EnergyFlux::NanowattPerSquareMillimetre,
                               EnergyFlux::WattPerSquareMetre),
                   value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, EnergyFlux::FootPoundPerSquareFootPerSecond,
                  EnergyFlux::WattPerSquareMetre),
      value * 0.45359237 * 9.80665 / 0.3048);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, EnergyFlux::InchPoundPerSquareInchPerSecond,
                  EnergyFlux::WattPerSquareMetre),
      value * 0.45359237 * 9.80665 / 0.0254);
}

TEST(UnitEnergyFlux, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const EnergyFlux old_unit : Units) {
    for (const EnergyFlux new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitEnergyFlux, Parse) {
  EXPECT_EQ(Parse<EnergyFlux>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<EnergyFlux>("W/m^2"), EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(
      Parse<EnergyFlux>("nW/mm^2"), EnergyFlux::NanowattPerSquareMillimetre);
  EXPECT_EQ(Parse<EnergyFlux>("ft·lbf/ft^2/s"),
            EnergyFlux::FootPoundPerSquareFootPerSecond);
  EXPECT_EQ(Parse<EnergyFlux>("in·lbf/in^2/s"),
            EnergyFlux::InchPoundPerSquareInchPerSecond);
}

TEST(UnitEnergyFlux, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<EnergyFlux>,
            Dimensions(
                Dimension::Time{-3}, Dimension::Length{0}, Dimension::Mass{1}));
}

TEST(UnitEnergyFlux, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(EnergyFlux::WattPerSquareMetre),
            UnitSystem::MetreKilogramSecondKelvin);
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

}  // namespace

}  // namespace PhQ::Unit
