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
  EXPECT_EQ(abbreviation(Unit::Length::Mile), "mi");
  EXPECT_EQ(abbreviation(Unit::Length::Kilometre), "km");
  EXPECT_EQ(abbreviation(Unit::Length::Yard), "yd");
  EXPECT_EQ(abbreviation(Unit::Length::Metre), "m");
  EXPECT_EQ(abbreviation(Unit::Length::Foot), "ft");
  EXPECT_EQ(abbreviation(Unit::Length::Decimetre), "dm");
  EXPECT_EQ(abbreviation(Unit::Length::Inch), "in");
  EXPECT_EQ(abbreviation(Unit::Length::Centimetre), "cm");
  EXPECT_EQ(abbreviation(Unit::Length::Millimetre), "mm");
  EXPECT_EQ(abbreviation(Unit::Length::Milliinch), "thou");
  EXPECT_EQ(abbreviation(Unit::Length::Micrometre), "μm");
  EXPECT_EQ(abbreviation(Unit::Length::Microinch), "μin");
}

TEST(UnitLength, ConversionValidation) {
  constexpr double k{10.0};
  // Convert from metres to unit systems.
  EXPECT_DOUBLE_EQ(
      convert(k, Unit::Length::Metre, UnitSystem::MetreKilogramSecondKelvin),
      k);
  EXPECT_DOUBLE_EQ(
      convert(k, Unit::Length::Metre, UnitSystem::MillimetreGramSecondKelvin),
      k * 1000.0);
  EXPECT_DOUBLE_EQ(
      convert(k, Unit::Length::Metre, UnitSystem::FootPoundSecondRankine),
      k / 0.3048);
  EXPECT_DOUBLE_EQ(
      convert(k, Unit::Length::Metre, UnitSystem::InchPoundSecondRankine),
      k / 0.0254);
  // Convert from metres to various units.
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Mile),
                   k / 1609.344);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Kilometre),
                   k / 1000.0);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Yard),
                   k / 0.9144);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Metre), k);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Foot),
                   k / 0.3048);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Decimetre),
                   k * 10.0);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Inch),
                   k / 0.0254);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Centimetre),
                   k * 100.0);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Millimetre),
                   k * 1000.0);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Milliinch),
                   k / 0.0000254);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Micrometre),
                   k * 1000000.0);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Microinch),
                   k / 0.0000000254);
  // Convert from various units to metres.
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Mile, Unit::Length::Metre),
                   k * 1609.344);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Kilometre, Unit::Length::Metre),
                   k * 1000.0);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Yard, Unit::Length::Metre),
                   k * 0.9144);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Metre, Unit::Length::Metre), k);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Foot, Unit::Length::Metre),
                   k * 0.3048);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Decimetre, Unit::Length::Metre),
                   k * 0.1);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Inch, Unit::Length::Metre),
                   k * 0.0254);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Centimetre, Unit::Length::Metre),
                   k * 0.01);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Millimetre, Unit::Length::Metre),
                   k * 0.001);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Milliinch, Unit::Length::Metre),
                   k * 0.0000254);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Micrometre, Unit::Length::Metre),
                   k * 0.000001);
  EXPECT_DOUBLE_EQ(convert(k, Unit::Length::Microinch, Unit::Length::Metre),
                   k * 0.0000000254);
}

TEST(UnitLength, ConversionVerification) {
  constexpr double value{10.0};
  const std::array<double, 3> array{10.0, -20.0, 30.0};
  const std::vector<double> plain_vector{10.0, -20.0, 30.0};
  const Value::Vector vector_value{10.0, -20.0, 30.0};
  const Value::SymmetricDyadic symmetric{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  const Value::Dyadic dyadic{10.0,  -20.0, 30.0,  -40.0, 50.0,
                             -60.0, 70.0,  -80.0, 90.0};
  for (const Unit::Length old_unit : LengthUnits) {
    for (const UnitSystem new_unit_system : UnitSystems) {
      convert(value, old_unit, new_unit_system);
      convert(array, old_unit, new_unit_system);
      convert(plain_vector, old_unit, new_unit_system);
      convert(vector_value, old_unit, new_unit_system);
      convert(symmetric, old_unit, new_unit_system);
      convert(dyadic, old_unit, new_unit_system);
    }
    for (const Unit::Length new_unit : LengthUnits) {
      convert(value, old_unit, new_unit);
      convert(array, old_unit, new_unit);
      convert(plain_vector, old_unit, new_unit);
      convert(vector_value, old_unit, new_unit);
      convert(symmetric, old_unit, new_unit);
      convert(dyadic, old_unit, new_unit);
    }
  }
}

TEST(UnitLength, DimensionSet) {
  EXPECT_EQ(Dimensions<Unit::Length>, Dimension::Set{Dimension::Length{1}});
}

TEST(UnitLength, Parse) {
  EXPECT_EQ(parse<Unit::Length>("Hello world!"), std::nullopt);
  EXPECT_EQ(parse<Unit::Length>("mi"), Unit::Length::Mile);
  EXPECT_EQ(parse<Unit::Length>("km"), Unit::Length::Kilometre);
  EXPECT_EQ(parse<Unit::Length>("yd"), Unit::Length::Yard);
  EXPECT_EQ(parse<Unit::Length>("m"), Unit::Length::Metre);
  EXPECT_EQ(parse<Unit::Length>("ft"), Unit::Length::Foot);
  EXPECT_EQ(parse<Unit::Length>("dm"), Unit::Length::Decimetre);
  EXPECT_EQ(parse<Unit::Length>("in"), Unit::Length::Inch);
  EXPECT_EQ(parse<Unit::Length>("cm"), Unit::Length::Centimetre);
  EXPECT_EQ(parse<Unit::Length>("mm"), Unit::Length::Millimetre);
  EXPECT_EQ(parse<Unit::Length>("thou"), Unit::Length::Milliinch);
  EXPECT_EQ(parse<Unit::Length>("μm"), Unit::Length::Micrometre);
  EXPECT_EQ(parse<Unit::Length>("μin"), Unit::Length::Microinch);
}

TEST(UnitLength, StandardUnit) {
  EXPECT_EQ(StandardUnit<Unit::Length>, Unit::Length::Metre);
}

TEST(UnitLength, UnitFromUnitSystem) {
  EXPECT_EQ(unit<Unit::Length>(UnitSystem::MetreKilogramSecondKelvin),
            Unit::Length::Metre);
  EXPECT_EQ(unit<Unit::Length>(UnitSystem::MillimetreGramSecondKelvin),
            Unit::Length::Millimetre);
  EXPECT_EQ(unit<Unit::Length>(UnitSystem::FootPoundSecondRankine),
            Unit::Length::Foot);
  EXPECT_EQ(unit<Unit::Length>(UnitSystem::InchPoundSecondRankine),
            Unit::Length::Inch);
}

TEST(UnitLength, UnitSystemFromUnit) {
  EXPECT_EQ(unit_system(Unit::Length::Mile), std::nullopt);
  EXPECT_EQ(unit_system(Unit::Length::Kilometre), std::nullopt);
  EXPECT_EQ(unit_system(Unit::Length::Yard), std::nullopt);
  EXPECT_EQ(unit_system(Unit::Length::Metre),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(unit_system(Unit::Length::Foot),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(unit_system(Unit::Length::Decimetre), std::nullopt);
  EXPECT_EQ(unit_system(Unit::Length::Inch),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(unit_system(Unit::Length::Centimetre), std::nullopt);
  EXPECT_EQ(unit_system(Unit::Length::Millimetre),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(unit_system(Unit::Length::Milliinch), std::nullopt);
  EXPECT_EQ(unit_system(Unit::Length::Micrometre), std::nullopt);
  EXPECT_EQ(unit_system(Unit::Length::Microinch), std::nullopt);
}

}  // namespace

}  // namespace PhQ
