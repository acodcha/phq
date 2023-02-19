// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#include "../../include/PhQ/Unit/Length.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

const std::set<PhQ::UnitSystem> UnitSystems = {
    PhQ::UnitSystem::MetreKilogramSecondKelvin,
    PhQ::UnitSystem::MillimetreGramSecondKelvin,
    PhQ::UnitSystem::FootPoundSecondRankine,
    PhQ::UnitSystem::InchPoundSecondRankine};

const std::set<PhQ::Unit::Length> LengthUnits = {
    PhQ::Unit::Length::Mile,
    PhQ::Unit::Length::Kilometre,
    PhQ::Unit::Length::Yard,
    PhQ::Unit::Length::Metre,
    PhQ::Unit::Length::Foot,
    PhQ::Unit::Length::Decimetre,
    PhQ::Unit::Length::Inch,
    PhQ::Unit::Length::Centimetre,
    PhQ::Unit::Length::Millimetre,
    PhQ::Unit::Length::Milliinch,
    PhQ::Unit::Length::Micrometre,
    PhQ::Unit::Length::Microinch};

TEST(UnitLength, Abbreviation) {
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Mile), "mi");
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Kilometre), "km");
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Yard), "yd");
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Metre), "m");
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Foot), "ft");
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Decimetre), "dm");
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Inch), "in");
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Centimetre), "cm");
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Millimetre), "mm");
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Milliinch), "thou");
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Micrometre), "μm");
  EXPECT_EQ(PhQ::abbreviation(PhQ::Unit::Length::Microinch), "μin");
}

TEST(UnitLength, ConversionValidation) {
  constexpr double k{10.0};
  // Convert from metres to unit systems.
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::UnitSystem::MetreKilogramSecondKelvin), k);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::UnitSystem::MillimetreGramSecondKelvin), k * 1000.0);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::UnitSystem::FootPoundSecondRankine), k / 0.3048);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::UnitSystem::InchPoundSecondRankine), k / 0.0254);
  // Convert from metres to various units.
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Mile), k / 1609.344);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Kilometre), k / 1000.0);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Yard), k / 0.9144);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Metre), k);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Foot), k / 0.3048);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Decimetre), k * 10.0);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Inch), k / 0.0254);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Centimetre), k * 100.0);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Millimetre), k * 1000.0);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Milliinch), k / 0.0000254);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Micrometre), k * 1000000.0);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Microinch), k / 0.0000000254);
  // Convert from various units to metres.
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Mile, PhQ::Unit::Length::Metre), k * 1609.344);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Kilometre, PhQ::Unit::Length::Metre), k * 1000.0);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Yard, PhQ::Unit::Length::Metre), k * 0.9144);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Metre, PhQ::Unit::Length::Metre), k);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Foot, PhQ::Unit::Length::Metre), k * 0.3048);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Decimetre, PhQ::Unit::Length::Metre), k * 0.1);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Inch, PhQ::Unit::Length::Metre), k * 0.0254);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Centimetre, PhQ::Unit::Length::Metre), k * 0.01);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Millimetre, PhQ::Unit::Length::Metre), k * 0.001);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Milliinch, PhQ::Unit::Length::Metre), k * 0.0000254);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Micrometre, PhQ::Unit::Length::Metre), k * 0.000001);
  EXPECT_DOUBLE_EQ(PhQ::convert(k, PhQ::Unit::Length::Microinch, PhQ::Unit::Length::Metre), k * 0.0000000254);
}

TEST(UnitLength, ConversionVerification) {
  constexpr double value{10.0};
  const std::array<double, 3> array{10.0, -20.0, 30.0};
  const std::vector<double> plain_vector{10.0, -20.0, 30.0};
  const PhQ::Value::Vector vector_value{10.0, -20.0, 30.0};
  const PhQ::Value::SymmetricDyadic symmetric{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  const PhQ::Value::Dyadic dyadic{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const PhQ::Unit::Length old_unit : LengthUnits) {
    for (const PhQ::UnitSystem new_unit_system : UnitSystems) {
      PhQ::convert(value, old_unit, new_unit_system);
      PhQ::convert(array, old_unit, new_unit_system);
      PhQ::convert(plain_vector, old_unit, new_unit_system);
      PhQ::convert(vector_value, old_unit, new_unit_system);
      PhQ::convert(symmetric, old_unit, new_unit_system);
      PhQ::convert(dyadic, old_unit, new_unit_system);
    }
    for (const PhQ::Unit::Length new_unit : LengthUnits) {
      PhQ::convert(value, old_unit, new_unit);
      PhQ::convert(array, old_unit, new_unit);
      PhQ::convert(plain_vector, old_unit, new_unit);
      PhQ::convert(vector_value, old_unit, new_unit);
      PhQ::convert(symmetric, old_unit, new_unit);
      PhQ::convert(dyadic, old_unit, new_unit);
    }
  }
}

TEST(UnitLength, DimensionSet) {
  EXPECT_EQ(PhQ::Dimensions<PhQ::Unit::Length>, Dimension::Set{Dimension::Length{1}});
}

TEST(UnitLength, Parse) {
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("Hello world!"), std::nullopt);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("mi"), PhQ::Unit::Length::Mile);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("km"), PhQ::Unit::Length::Kilometre);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("yd"), PhQ::Unit::Length::Yard);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("m"), PhQ::Unit::Length::Metre);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("ft"), PhQ::Unit::Length::Foot);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("dm"), PhQ::Unit::Length::Decimetre);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("in"), PhQ::Unit::Length::Inch);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("cm"), PhQ::Unit::Length::Centimetre);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("mm"), PhQ::Unit::Length::Millimetre);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("thou"), PhQ::Unit::Length::Milliinch);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("μm"), PhQ::Unit::Length::Micrometre);
  EXPECT_EQ(PhQ::parse<PhQ::Unit::Length>("μin"), PhQ::Unit::Length::Microinch);
}

TEST(UnitLength, StandardUnit) {
  EXPECT_EQ(PhQ::StandardUnit<PhQ::Unit::Length>, PhQ::Unit::Length::Metre);
}

TEST(UnitLength, UnitFromUnitSystem) {
  EXPECT_EQ(PhQ::unit<PhQ::Unit::Length>(PhQ::UnitSystem::MetreKilogramSecondKelvin), PhQ::Unit::Length::Metre);
  EXPECT_EQ(PhQ::unit<PhQ::Unit::Length>(PhQ::UnitSystem::MillimetreGramSecondKelvin), PhQ::Unit::Length::Millimetre);
  EXPECT_EQ(PhQ::unit<PhQ::Unit::Length>(PhQ::UnitSystem::FootPoundSecondRankine), PhQ::Unit::Length::Foot);
  EXPECT_EQ(PhQ::unit<PhQ::Unit::Length>(PhQ::UnitSystem::InchPoundSecondRankine), PhQ::Unit::Length::Inch);
}

TEST(UnitLength, UnitSystemFromUnit) {
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Mile), std::nullopt);
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Kilometre), std::nullopt);
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Yard), std::nullopt);
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Metre), PhQ::UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Foot), PhQ::UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Decimetre), std::nullopt);
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Inch), PhQ::UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Centimetre), std::nullopt);
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Millimetre), PhQ::UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Milliinch), std::nullopt);
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Micrometre), std::nullopt);
  EXPECT_EQ(PhQ::unit_system(PhQ::Unit::Length::Microinch), std::nullopt);
}

}  // namespace

}  // namespace PhQ
