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

constexpr std::array<Diffusivity, 14> Units = {
    Diffusivity::SquareMilePerSecond,       Diffusivity::SquareKilometrePerSecond,
    Diffusivity::HectarePerSecond,          Diffusivity::AcrePerSecond,
    Diffusivity::SquareMetrePerSecond,      Diffusivity::SquareYardPerSecond,
    Diffusivity::SquareFootPerSecond,       Diffusivity::SquareDecimetrePerSecond,
    Diffusivity::SquareInchPerSecond,       Diffusivity::SquareCentimetrePerSecond,
    Diffusivity::SquareMillimetrePerSecond, Diffusivity::SquareMilliinchPerSecond,
    Diffusivity::SquareMicrometrePerSecond, Diffusivity::SquareMicroinchPerSecond,
};

TEST(UnitDiffusivity, Abbreviation) {
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

TEST(UnitDiffusivity, ConvertFromStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareMilePerSecond>(
      value, value / std::pow(1609.344, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareKilometrePerSecond>(
      value, value * std::pow(0.001, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::HectarePerSecond>(value, value * 0.0001);
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::AcrePerSecond>(
      value, value * 640.0 / std::pow(1609.344, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareMetrePerSecond>(value, value);
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareYardPerSecond>(
      value, value / std::pow(0.9144, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareFootPerSecond>(
      value, value / std::pow(0.3048, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareDecimetrePerSecond>(
      value, value * std::pow(10.0, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareInchPerSecond>(
      value, value / std::pow(0.0254, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareCentimetrePerSecond>(
      value, value * std::pow(100.0, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareMillimetrePerSecond>(
      value, value * std::pow(1000.0, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareMilliinchPerSecond>(
      value, value / std::pow(0.0000254, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareMicrometrePerSecond>(
      value, value * std::pow(1000000.0, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareMicroinchPerSecond>(
      value, value / std::pow(0.0000000254, 2));
}

TEST(UnitDiffusivity, ConvertToStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMilePerSecond,
                                Diffusivity::SquareMetrePerSecond>(
      value, value * std::pow(1609.344, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareKilometrePerSecond,
                                Diffusivity::SquareMetrePerSecond>(
      value, value * std::pow(1000.0, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::HectarePerSecond,
                                Diffusivity::SquareMetrePerSecond>(value, value * 10000.0);
  Internal::TestUnitConversions<Diffusivity, Diffusivity::AcrePerSecond,
                                Diffusivity::SquareMetrePerSecond>(
      value, value * std::pow(1609.344, 2) / 640.0);
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMetrePerSecond,
                                Diffusivity::SquareMetrePerSecond>(value, value);
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareYardPerSecond,
                                Diffusivity::SquareMetrePerSecond>(
      value, value * std::pow(0.9144, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareFootPerSecond,
                                Diffusivity::SquareMetrePerSecond>(
      value, value * std::pow(0.3048, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareDecimetrePerSecond,
                                Diffusivity::SquareMetrePerSecond>(value, value * std::pow(0.1, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareInchPerSecond,
                                Diffusivity::SquareMetrePerSecond>(
      value, value * std::pow(0.0254, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareCentimetrePerSecond,
                                Diffusivity::SquareMetrePerSecond>(
      value, value * std::pow(0.01, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMillimetrePerSecond,
                                Diffusivity::SquareMetrePerSecond>(
      value, value * std::pow(0.001, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMilliinchPerSecond,
                                Diffusivity::SquareMetrePerSecond>(
      value, value * std::pow(0.0000254, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMicrometrePerSecond,
                                Diffusivity::SquareMetrePerSecond>(
      value, value * std::pow(0.000001, 2));
  Internal::TestUnitConversions<Diffusivity, Diffusivity::SquareMicroinchPerSecond,
                                Diffusivity::SquareMetrePerSecond>(
      value, value * std::pow(0.0000000254, 2));
}

TEST(UnitDiffusivity, Parse) {
  EXPECT_EQ(Parse<Diffusivity>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Diffusivity>("mi^2/s"), Diffusivity::SquareMilePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("km^2/s"), Diffusivity::SquareKilometrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("ha/s"), Diffusivity::HectarePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("ac/s"), Diffusivity::AcrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("m^2/s"), Diffusivity::SquareMetrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("yd^2/s"), Diffusivity::SquareYardPerSecond);
  EXPECT_EQ(Parse<Diffusivity>("ft^2/s"), Diffusivity::SquareFootPerSecond);
  EXPECT_EQ(Parse<Diffusivity>("dm^2/s"), Diffusivity::SquareDecimetrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("in^2/s"), Diffusivity::SquareInchPerSecond);
  EXPECT_EQ(Parse<Diffusivity>("cm^2/s"), Diffusivity::SquareCentimetrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("mm^2/s"), Diffusivity::SquareMillimetrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("mil^2/s"), Diffusivity::SquareMilliinchPerSecond);
  EXPECT_EQ(Parse<Diffusivity>("μm^2/s"), Diffusivity::SquareMicrometrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("μin^2/s"), Diffusivity::SquareMicroinchPerSecond);
}

TEST(UnitDiffusivity, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Diffusivity>, Dimensions(Dimension::Time{-1}, Dimension::Length{2}));
}

TEST(UnitDiffusivity, RelatedUnitSystem) {
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
