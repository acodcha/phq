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

#include "../../include/PhQ/Unit/Angle.hpp"

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

constexpr std::array<Angle, 5> Units = {
    Angle::Radian, Angle::Degree, Angle::Arcminute, Angle::Arcsecond, Angle::Revolution,
};

TEST(UnitAngle, Abbreviation) {
  EXPECT_EQ(Abbreviation(Angle::Radian), "rad");
  EXPECT_EQ(Abbreviation(Angle::Degree), "deg");
  EXPECT_EQ(Abbreviation(Angle::Arcminute), "arcmin");
  EXPECT_EQ(Abbreviation(Angle::Arcsecond), "arcsec");
  EXPECT_EQ(Abbreviation(Angle::Revolution), "rev");
}

TEST(UnitAngle, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::MetreKilogramSecondKelvin), Angle::Radian);
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::MillimetreGramSecondKelvin), Angle::Radian);
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::FootPoundSecondRankine), Angle::Radian);
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::InchPoundSecondRankine), Angle::Radian);
}

TEST(UnitAngle, ConvertFromStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<Angle, Angle::Radian, Angle::Radian>(value, value);
  Internal::TestUnitConversions<Angle, Angle::Radian, Angle::Degree>(value, value * 180.0 / Pi);
  Internal::TestUnitConversions<Angle, Angle::Radian, Angle::Arcminute>(
      value, value * 10800.0 / Pi);
  Internal::TestUnitConversions<Angle, Angle::Radian, Angle::Arcsecond>(
      value, value * 648000.0 / Pi);
  Internal::TestUnitConversions<Angle, Angle::Radian, Angle::Revolution>(value, value / (2.0 * Pi));
}

TEST(UnitAngle, ConvertToStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<Angle, Angle::Radian, Angle::Radian>(value, value);
  Internal::TestUnitConversions<Angle, Angle::Degree, Angle::Radian>(value, value * Pi / 180.0);
  Internal::TestUnitConversions<Angle, Angle::Arcminute, Angle::Radian>(
      value, value * Pi / 10800.0);
  Internal::TestUnitConversions<Angle, Angle::Arcsecond, Angle::Radian>(
      value, value * Pi / 648000.0);
  Internal::TestUnitConversions<Angle, Angle::Revolution, Angle::Radian>(value, value * 2.0 * Pi);
}

TEST(UnitAngle, Parse) {
  EXPECT_EQ(Parse<Angle>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Angle>("rad"), Angle::Radian);
  EXPECT_EQ(Parse<Angle>("deg"), Angle::Degree);
  EXPECT_EQ(Parse<Angle>("arcmin"), Angle::Arcminute);
  EXPECT_EQ(Parse<Angle>("arcsec"), Angle::Arcsecond);
  EXPECT_EQ(Parse<Angle>("rev"), Angle::Revolution);
}

TEST(UnitAngle, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Angle>, Dimensions{});
}

TEST(UnitAngle, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Angle::Radian), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Angle::Degree), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Angle::Arcminute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Angle::Arcsecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Angle::Revolution), std::nullopt);
}

TEST(UnitAngle, Standard) {
  EXPECT_EQ(Standard<Angle>, Angle::Radian);
}

TEST(UnitAngle, Stream) {
  std::ostringstream stream;
  stream << Angle::Radian;
  EXPECT_EQ(stream.str(), Abbreviation(Angle::Radian));
}

}  // namespace

}  // namespace PhQ::Unit
