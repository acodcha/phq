// Copyright 2020-2023 Alexandre Coderre-Chabot
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

TEST(UnitEnergyFlux, ConvertFromStandard) {
  constexpr double value{10.0};

  Internal::TestConversions(
      EnergyFlux::WattPerSquareMetre, EnergyFlux::WattPerSquareMetre, value, value);
  Internal::TestConversions(EnergyFlux::WattPerSquareMetre, EnergyFlux::NanowattPerSquareMillimetre,
                            value, value * 1000.0);
  Internal::TestConversions(
      EnergyFlux::WattPerSquareMetre, EnergyFlux::FootPoundPerSquareFootPerSecond, value,
      value * 0.3048 / (0.45359237 * 9.80665));
  Internal::TestConversions(
      EnergyFlux::WattPerSquareMetre, EnergyFlux::InchPoundPerSquareInchPerSecond, value,
      value * 0.0254 / (0.45359237 * 9.80665));

  Internal::TestStaticConversions<EnergyFlux, EnergyFlux::WattPerSquareMetre,
                                  EnergyFlux::FootPoundPerSquareFootPerSecond>(
      value, value * 0.3048 / (0.45359237 * 9.80665));
}

TEST(UnitEnergyFlux, ConvertToStandard) {
  constexpr double value{10.0};

  Internal::TestConversions(
      EnergyFlux::WattPerSquareMetre, EnergyFlux::WattPerSquareMetre, value, value);
  Internal::TestConversions(EnergyFlux::NanowattPerSquareMillimetre, EnergyFlux::WattPerSquareMetre,
                            value, value * 0.001);
  Internal::TestConversions(
      EnergyFlux::FootPoundPerSquareFootPerSecond, EnergyFlux::WattPerSquareMetre, value,
      value * 0.45359237 * 9.80665 / 0.3048);
  Internal::TestConversions(
      EnergyFlux::InchPoundPerSquareInchPerSecond, EnergyFlux::WattPerSquareMetre, value,
      value * 0.45359237 * 9.80665 / 0.0254);

  Internal::TestStaticConversions<EnergyFlux, EnergyFlux::FootPoundPerSquareFootPerSecond,
                                  EnergyFlux::WattPerSquareMetre>(
      value, value * 0.45359237 * 9.80665 / 0.3048);
}

TEST(UnitEnergyFlux, Parse) {
  EXPECT_EQ(Parse<EnergyFlux>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<EnergyFlux>("W/m^2"), EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(Parse<EnergyFlux>("nW/mm^2"), EnergyFlux::NanowattPerSquareMillimetre);
  EXPECT_EQ(Parse<EnergyFlux>("ft·lbf/ft^2/s"), EnergyFlux::FootPoundPerSquareFootPerSecond);
  EXPECT_EQ(Parse<EnergyFlux>("in·lbf/in^2/s"), EnergyFlux::InchPoundPerSquareInchPerSecond);
}

TEST(UnitEnergyFlux, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<EnergyFlux>,
            Dimensions(Dimension::Time{-3}, Dimension::Length{0}, Dimension::Mass{1}));
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
