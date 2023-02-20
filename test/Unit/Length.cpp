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

#include "../../include/PhQ/Unit/Length.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

const std::set<UnitSystem> UnitSystems = {
    UnitSystem::MetreKilogramSecondKelvin,
    UnitSystem::MillimetreGramSecondKelvin, UnitSystem::FootPoundSecondRankine,
    UnitSystem::InchPoundSecondRankine};

const std::set<Unit::Length> LengthUnits = {
    Unit::Length::Mile,      Unit::Length::Kilometre,  Unit::Length::Yard,
    Unit::Length::Metre,     Unit::Length::Foot,       Unit::Length::Decimetre,
    Unit::Length::Inch,      Unit::Length::Centimetre, Unit::Length::Millimetre,
    Unit::Length::Milliinch, Unit::Length::Micrometre, Unit::Length::Microinch};

TEST(UnitLength, Abbreviation) {
  EXPECT_EQ(Abbreviation(Unit::Length::Mile), "mi");
  EXPECT_EQ(Abbreviation(Unit::Length::Kilometre), "km");
  EXPECT_EQ(Abbreviation(Unit::Length::Yard), "yd");
  EXPECT_EQ(Abbreviation(Unit::Length::Metre), "m");
  EXPECT_EQ(Abbreviation(Unit::Length::Foot), "ft");
  EXPECT_EQ(Abbreviation(Unit::Length::Decimetre), "dm");
  EXPECT_EQ(Abbreviation(Unit::Length::Inch), "in");
  EXPECT_EQ(Abbreviation(Unit::Length::Centimetre), "cm");
  EXPECT_EQ(Abbreviation(Unit::Length::Millimetre), "mm");
  EXPECT_EQ(Abbreviation(Unit::Length::Milliinch), "thou");
  EXPECT_EQ(Abbreviation(Unit::Length::Micrometre), "μm");
  EXPECT_EQ(Abbreviation(Unit::Length::Microinch), "μin");
}

TEST(UnitLength, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Unit::Length>(UnitSystem::MetreKilogramSecondKelvin),
            Unit::Length::Metre);
  EXPECT_EQ(
      ConsistentUnit<Unit::Length>(UnitSystem::MillimetreGramSecondKelvin),
      Unit::Length::Millimetre);
  EXPECT_EQ(ConsistentUnit<Unit::Length>(UnitSystem::FootPoundSecondRankine),
            Unit::Length::Foot);
  EXPECT_EQ(ConsistentUnit<Unit::Length>(UnitSystem::InchPoundSecondRankine),
            Unit::Length::Inch);
}

TEST(UnitLength, ConversionValidation) {
  constexpr double value{10.0};
  // Convert from the standard unit to unit systems.
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre,
                           UnitSystem::MetreKilogramSecondKelvin),
                   value);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre,
                           UnitSystem::MillimetreGramSecondKelvin),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(
      Convert(value, Unit::Length::Metre, UnitSystem::FootPoundSecondRankine),
      value / 0.3048);
  EXPECT_DOUBLE_EQ(
      Convert(value, Unit::Length::Metre, UnitSystem::InchPoundSecondRankine),
      value / 0.0254);
  // Convert from the standard unit to various units.
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre, Unit::Length::Mile),
                   value / 1609.344);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre, Unit::Length::Kilometre),
                   value / 1000.0);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre, Unit::Length::Yard),
                   value / 0.9144);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre, Unit::Length::Metre),
                   value);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre, Unit::Length::Foot),
                   value / 0.3048);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre, Unit::Length::Decimetre),
                   value * 10.0);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre, Unit::Length::Inch),
                   value / 0.0254);
  EXPECT_DOUBLE_EQ(
      Convert(value, Unit::Length::Metre, Unit::Length::Centimetre),
      value * 100.0);
  EXPECT_DOUBLE_EQ(
      Convert(value, Unit::Length::Metre, Unit::Length::Millimetre),
      value * 1000.0);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre, Unit::Length::Milliinch),
                   value / 0.0000254);
  EXPECT_DOUBLE_EQ(
      Convert(value, Unit::Length::Metre, Unit::Length::Micrometre),
      value * 1000000.0);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre, Unit::Length::Microinch),
                   value / 0.0000000254);
  // Convert from various units to the standard unit.
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Mile, Unit::Length::Metre),
                   value * 1609.344);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Kilometre, Unit::Length::Metre),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Yard, Unit::Length::Metre),
                   value * 0.9144);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Metre, Unit::Length::Metre),
                   value);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Foot, Unit::Length::Metre),
                   value * 0.3048);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Decimetre, Unit::Length::Metre),
                   value * 0.1);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Inch, Unit::Length::Metre),
                   value * 0.0254);
  EXPECT_DOUBLE_EQ(
      Convert(value, Unit::Length::Centimetre, Unit::Length::Metre),
      value * 0.01);
  EXPECT_DOUBLE_EQ(
      Convert(value, Unit::Length::Millimetre, Unit::Length::Metre),
      value * 0.001);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Milliinch, Unit::Length::Metre),
                   value * 0.0000254);
  EXPECT_DOUBLE_EQ(
      Convert(value, Unit::Length::Micrometre, Unit::Length::Metre),
      value * 0.000001);
  EXPECT_DOUBLE_EQ(Convert(value, Unit::Length::Microinch, Unit::Length::Metre),
                   value * 0.0000000254);
}

TEST(UnitLength, ConversionVerification) {
  constexpr double value{10.0};
  const std::array<double, 3> array{10.0, -20.0, 30.0};
  const std::vector<double> plain_vector{10.0, -20.0, 30.0};
  const Value::Vector vector_value{10.0, -20.0, 30.0};
  const Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  const Value::Dyad dyad{10.0,  -20.0, 30.0,  -40.0, 50.0,
                         -60.0, 70.0,  -80.0, 90.0};
  for (const Unit::Length old_unit : LengthUnits) {
    for (const UnitSystem new_unit_system : UnitSystems) {
      Convert(value, old_unit, new_unit_system);
      Convert(array, old_unit, new_unit_system);
      Convert(plain_vector, old_unit, new_unit_system);
      Convert(vector_value, old_unit, new_unit_system);
      Convert(symdyad, old_unit, new_unit_system);
      Convert(dyad, old_unit, new_unit_system);
    }
    for (const Unit::Length new_unit : LengthUnits) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(plain_vector, old_unit, new_unit);
      Convert(vector_value, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitLength, DimensionSet) {
  EXPECT_EQ(Dimensions<Unit::Length>, Dimension::Set{Dimension::Length{1}});
}

TEST(UnitLength, Parse) {
  EXPECT_EQ(Parse<Unit::Length>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Unit::Length>("mi"), Unit::Length::Mile);
  EXPECT_EQ(Parse<Unit::Length>("km"), Unit::Length::Kilometre);
  EXPECT_EQ(Parse<Unit::Length>("yd"), Unit::Length::Yard);
  EXPECT_EQ(Parse<Unit::Length>("m"), Unit::Length::Metre);
  EXPECT_EQ(Parse<Unit::Length>("ft"), Unit::Length::Foot);
  EXPECT_EQ(Parse<Unit::Length>("dm"), Unit::Length::Decimetre);
  EXPECT_EQ(Parse<Unit::Length>("in"), Unit::Length::Inch);
  EXPECT_EQ(Parse<Unit::Length>("cm"), Unit::Length::Centimetre);
  EXPECT_EQ(Parse<Unit::Length>("mm"), Unit::Length::Millimetre);
  EXPECT_EQ(Parse<Unit::Length>("thou"), Unit::Length::Milliinch);
  EXPECT_EQ(Parse<Unit::Length>("μm"), Unit::Length::Micrometre);
  EXPECT_EQ(Parse<Unit::Length>("μin"), Unit::Length::Microinch);
}

TEST(UnitLength, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Mile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Kilometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Yard), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Metre),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Foot),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Decimetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Inch),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Centimetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Millimetre),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Milliinch), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Micrometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Unit::Length::Microinch), std::nullopt);
}

TEST(UnitLength, StandardUnit) {
  EXPECT_EQ(StandardUnit<Unit::Length>, Unit::Length::Metre);
}

}  // namespace

}  // namespace PhQ
