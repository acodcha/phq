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

#include "../../include/PhQ/Unit/Force.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<Force, 18> Units = {
    Force::Newton,
    Force::Micronewton,
    Force::JoulePerMile,
    Force::JoulePerKilometre,
    Force::KilojoulePerMile,
    Force::WattMinutePerMile,
    Force::WattHourPerMile,
    Force::WattMinutePerKilometre,
    Force::WattHourPerKilometre,
    Force::WattMinutePerMetre,
    Force::WattHourPerMetre,
    Force::KilowattMinutePerMile,
    Force::KilowattHourPerMile,
    Force::KilowattMinutePerKilometre,
    Force::KilowattHourPerKilometre,
    Force::KilowattMinutePerMetre,
    Force::KilowattHourPerMetre,
    Force::Pound,
};

TEST(UnitForce, Abbreviation) {
  EXPECT_EQ(Abbreviation(Force::Newton), "N");
  EXPECT_EQ(Abbreviation(Force::Micronewton), "μN");
  EXPECT_EQ(Abbreviation(Force::JoulePerMile), "J/mi");
  EXPECT_EQ(Abbreviation(Force::JoulePerKilometre), "J/km");
  EXPECT_EQ(Abbreviation(Force::KilojoulePerMile), "kJ/mi");
  EXPECT_EQ(Abbreviation(Force::WattMinutePerMile), "W·min/mi");
  EXPECT_EQ(Abbreviation(Force::WattHourPerMile), "W·hr/mi");
  EXPECT_EQ(Abbreviation(Force::WattMinutePerKilometre), "W·min/km");
  EXPECT_EQ(Abbreviation(Force::WattHourPerKilometre), "W·hr/km");
  EXPECT_EQ(Abbreviation(Force::WattMinutePerMetre), "W·min/m");
  EXPECT_EQ(Abbreviation(Force::WattHourPerMetre), "W·hr/m");
  EXPECT_EQ(Abbreviation(Force::KilowattMinutePerMile), "kW·min/mi");
  EXPECT_EQ(Abbreviation(Force::KilowattHourPerMile), "kW·hr/mi");
  EXPECT_EQ(Abbreviation(Force::KilowattMinutePerKilometre), "kW·min/km");
  EXPECT_EQ(Abbreviation(Force::KilowattHourPerKilometre), "kW·hr/km");
  EXPECT_EQ(Abbreviation(Force::KilowattMinutePerMetre), "kW·min/m");
  EXPECT_EQ(Abbreviation(Force::KilowattHourPerMetre), "kW·hr/m");
  EXPECT_EQ(Abbreviation(Force::Pound), "lbf");
}

TEST(UnitForce, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Force>(UnitSystem::MetreKilogramSecondKelvin),
            Force::Newton);
  EXPECT_EQ(ConsistentUnit<Force>(UnitSystem::MillimetreGramSecondKelvin),
            Force::Micronewton);
  EXPECT_EQ(
      ConsistentUnit<Force>(UnitSystem::FootPoundSecondRankine), Force::Pound);
}

TEST(UnitForce, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Newton), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::Micronewton), value * 1000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::JoulePerMile), value * 1609.344);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::JoulePerKilometre),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::KilojoulePerMile),
                   value * 1.609344);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::WattMinutePerMile),
                   value * 1609.344 / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::WattHourPerMile),
                   value * 1609.344 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::WattMinutePerKilometre),
      value / 0.06);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::WattHourPerKilometre),
      value / 3.6);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::WattMinutePerMetre),
                   value / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::WattHourPerMetre),
                   value / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::KilowattMinutePerMile),
      value * 1609.344 / 60000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::KilowattHourPerMile),
      value * 1609.344 / 3600000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::KilowattMinutePerKilometre),
      value / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::KilowattHourPerKilometre),
      value / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::KilowattMinutePerMetre),
      value / 60000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::KilowattHourPerMetre),
      value / 3600000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Pound),
                   value / (0.45359237 * 9.80665));
}

TEST(UnitForce, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Newton), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Micronewton, Force::Newton), value * 0.000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::JoulePerMile, Force::Newton), value / 1609.344);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::JoulePerKilometre, Force::Newton),
                   value * 0.001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::KilojoulePerMile, Force::Newton),
                   value / 1.609344);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::WattMinutePerMile, Force::Newton),
                   value * 60.0 / 1609.344);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::WattHourPerMile, Force::Newton),
                   value * 3600.0 / 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::WattMinutePerKilometre, Force::Newton),
      value * 0.06);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::WattHourPerKilometre, Force::Newton),
      value * 3.6);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::WattMinutePerMetre, Force::Newton),
                   value * 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::WattHourPerMetre, Force::Newton),
                   value * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::KilowattMinutePerMile, Force::Newton),
      value * 60000.0 / 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::KilowattHourPerMile, Force::Newton),
      value * 3600000.0 / 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::KilowattMinutePerKilometre, Force::Newton),
      value * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::KilowattHourPerKilometre, Force::Newton),
      value * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::KilowattMinutePerMetre, Force::Newton),
      value * 60000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::KilowattHourPerMetre, Force::Newton),
      value * 3600000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Pound, Force::Newton),
                   value * 0.45359237 * 9.80665);
}

TEST(UnitForce, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Force old_unit : Units) {
    for (const Force new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitForce, Parse) {
  EXPECT_EQ(Parse<Force>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Force>("N"), Force::Newton);
  EXPECT_EQ(Parse<Force>("μN"), Force::Micronewton);
  EXPECT_EQ(Parse<Force>("J/mi"), Force::JoulePerMile);
  EXPECT_EQ(Parse<Force>("J/km"), Force::JoulePerKilometre);
  EXPECT_EQ(Parse<Force>("kJ/mi"), Force::KilojoulePerMile);
  EXPECT_EQ(Parse<Force>("W·min/mi"), Force::WattMinutePerMile);
  EXPECT_EQ(Parse<Force>("W·hr/mi"), Force::WattHourPerMile);
  EXPECT_EQ(Parse<Force>("W·min/km"), Force::WattMinutePerKilometre);
  EXPECT_EQ(Parse<Force>("W·hr/km"), Force::WattHourPerKilometre);
  EXPECT_EQ(Parse<Force>("W·min/m"), Force::WattMinutePerMetre);
  EXPECT_EQ(Parse<Force>("W·hr/m"), Force::WattHourPerMetre);
  EXPECT_EQ(Parse<Force>("kW·min/mi"), Force::KilowattMinutePerMile);
  EXPECT_EQ(Parse<Force>("kW·hr/mi"), Force::KilowattHourPerMile);
  EXPECT_EQ(Parse<Force>("kW·min/km"), Force::KilowattMinutePerKilometre);
  EXPECT_EQ(Parse<Force>("kW·hr/km"), Force::KilowattHourPerKilometre);
  EXPECT_EQ(Parse<Force>("kW·min/m"), Force::KilowattMinutePerMetre);
  EXPECT_EQ(Parse<Force>("kW·hr/m"), Force::KilowattHourPerMetre);
  EXPECT_EQ(Parse<Force>("lbf"), Force::Pound);
}

TEST(UnitForce, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Force>,
            Dimensions(
                Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1}));
}

TEST(UnitForce, RelatedUnitSystem) {
  EXPECT_EQ(
      RelatedUnitSystem(Force::Newton), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Force::Micronewton),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Force::Pound), std::nullopt);
}

TEST(UnitForce, Standard) { EXPECT_EQ(Standard<Force>, Force::Newton); }

}  // namespace

}  // namespace PhQ::Unit
