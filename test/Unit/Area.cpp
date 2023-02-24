// Copyright 2020 Alexandre Coderre-Chabot
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

#include "../../include/PhQ/Unit/Area.hpp"

#include <gtest/gtest.h>

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Area, 14> Units = {
    Area::SquareMile,       Area::SquareKilometre,
    Area::Hectare,          Area::Acre,
    Area::SquareMetre,      Area::SquareYard,
    Area::SquareFoot,       Area::SquareDecimetre,
    Area::SquareInch,       Area::SquareCentimetre,
    Area::SquareMillimetre, Area::SquareMilliinch,
    Area::SquareMicrometre, Area::SquareMicroinch,
};

TEST(UnitArea, Abbreviation) {
  EXPECT_EQ(Abbreviation(Area::SquareMile), "mi^2");
  EXPECT_EQ(Abbreviation(Area::SquareKilometre), "km^2");
  EXPECT_EQ(Abbreviation(Area::Hectare), "ha");
  EXPECT_EQ(Abbreviation(Area::Acre), "ac");
  EXPECT_EQ(Abbreviation(Area::SquareMetre), "m^2");
  EXPECT_EQ(Abbreviation(Area::SquareYard), "yd^2");
  EXPECT_EQ(Abbreviation(Area::SquareFoot), "ft^2");
  EXPECT_EQ(Abbreviation(Area::SquareDecimetre), "dm^2");
  EXPECT_EQ(Abbreviation(Area::SquareInch), "in^2");
  EXPECT_EQ(Abbreviation(Area::SquareCentimetre), "cm^2");
  EXPECT_EQ(Abbreviation(Area::SquareMillimetre), "mm^2");
  EXPECT_EQ(Abbreviation(Area::SquareMilliinch), "mil^2");
  EXPECT_EQ(Abbreviation(Area::SquareMicrometre), "μm^2");
  EXPECT_EQ(Abbreviation(Area::SquareMicroinch), "μin^2");
}

TEST(UnitArea, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Area>(UnitSystem::MetreKilogramSecondKelvin),
            Area::SquareMetre);
  EXPECT_EQ(ConsistentUnit<Area>(UnitSystem::MillimetreGramSecondKelvin),
            Area::SquareMillimetre);
  EXPECT_EQ(ConsistentUnit<Area>(UnitSystem::FootPoundSecondRankine),
            Area::SquareFoot);
  EXPECT_EQ(ConsistentUnit<Area>(UnitSystem::InchPoundSecondRankine),
            Area::SquareInch);
}

TEST(UnitArea, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::SquareMile),
                   value / std::pow(1609.344, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::SquareKilometre),
                   value * std::pow(0.001, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::Hectare),
                   value * 0.0001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::Acre),
                   value * 640.0 / std::pow(1609.344, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::SquareMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::SquareYard),
                   value / std::pow(0.9144, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::SquareFoot),
                   value / std::pow(0.3048, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::SquareDecimetre),
                   value * std::pow(10.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::SquareInch),
                   value / std::pow(0.0254, 2));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Area::SquareMetre, Area::SquareCentimetre),
      value * std::pow(100.0, 2));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Area::SquareMetre, Area::SquareMillimetre),
      value * std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::SquareMilliinch),
                   value / std::pow(0.0000254, 2));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Area::SquareMetre, Area::SquareMicrometre),
      value * std::pow(1000000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::SquareMicroinch),
                   value / std::pow(0.0000000254, 2));
}

TEST(UnitArea, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMile, Area::SquareMetre),
                   value * std::pow(1609.344, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareKilometre, Area::SquareMetre),
                   value * std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::Hectare, Area::SquareMetre),
                   value * 10000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::Acre, Area::SquareMetre),
                   value * std::pow(1609.344, 2) / 640.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMetre, Area::SquareMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareYard, Area::SquareMetre),
                   value * std::pow(0.9144, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareFoot, Area::SquareMetre),
                   value * std::pow(0.3048, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareDecimetre, Area::SquareMetre),
                   value * std::pow(0.1, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareInch, Area::SquareMetre),
                   value * std::pow(0.0254, 2));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Area::SquareCentimetre, Area::SquareMetre),
      value * std::pow(0.01, 2));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Area::SquareMillimetre, Area::SquareMetre),
      value * std::pow(0.001, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMilliinch, Area::SquareMetre),
                   value * std::pow(0.0000254, 2));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Area::SquareMicrometre, Area::SquareMetre),
      value * std::pow(0.000001, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Area::SquareMicroinch, Area::SquareMetre),
                   value * std::pow(0.0000000254, 2));
}

TEST(UnitArea, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Area old_unit : Units) {
    for (const Area new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitArea, DimensionSet) {
  EXPECT_EQ(Dimensions<Area>,
            Dimension::Set(Dimension::Time{0}, Dimension::Length{2}));
}

TEST(UnitArea, Parse) {
  EXPECT_EQ(Parse<Area>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Area>("mi^2"), Area::SquareMile);
  EXPECT_EQ(Parse<Area>("km^2"), Area::SquareKilometre);
  EXPECT_EQ(Parse<Area>("ha"), Area::Hectare);
  EXPECT_EQ(Parse<Area>("ac"), Area::Acre);
  EXPECT_EQ(Parse<Area>("m^2"), Area::SquareMetre);
  EXPECT_EQ(Parse<Area>("yd^2"), Area::SquareYard);
  EXPECT_EQ(Parse<Area>("ft^2"), Area::SquareFoot);
  EXPECT_EQ(Parse<Area>("dm^2"), Area::SquareDecimetre);
  EXPECT_EQ(Parse<Area>("in^2"), Area::SquareInch);
  EXPECT_EQ(Parse<Area>("cm^2"), Area::SquareCentimetre);
  EXPECT_EQ(Parse<Area>("mm^2"), Area::SquareMillimetre);
  EXPECT_EQ(Parse<Area>("mil^2"), Area::SquareMilliinch);
  EXPECT_EQ(Parse<Area>("μm^2"), Area::SquareMicrometre);
  EXPECT_EQ(Parse<Area>("μin^2"), Area::SquareMicroinch);
}

TEST(UnitArea, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareKilometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::Hectare), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::Acre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMetre),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareYard), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareFoot),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareDecimetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareInch),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareCentimetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMillimetre),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMilliinch), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMicrometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Area::SquareMicroinch), std::nullopt);
}

TEST(UnitArea, StandardUnit) {
  EXPECT_EQ(StandardUnit<Area>, Area::SquareMetre);
}

}  // namespace

}  // namespace PhQ::Unit
