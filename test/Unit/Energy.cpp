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

#include "../../include/PhQ/Unit/Energy.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<Energy, 17> Units = {
    Energy::Joule,          Energy::Millijoule,     Energy::Microjoule,
    Energy::Nanojoule,      Energy::Kilojoule,      Energy::Megajoule,
    Energy::Gigajoule,      Energy::WattMinute,     Energy::WattHour,
    Energy::KilowattMinute, Energy::KilowattHour,   Energy::MegawattMinute,
    Energy::MegawattHour,   Energy::GigawattMinute, Energy::GigawattHour,
    Energy::FootPound,      Energy::InchPound,
};

TEST(UnitEnergy, Abbreviation) {
  EXPECT_EQ(Abbreviation(Energy::Joule), "J");
  EXPECT_EQ(Abbreviation(Energy::Millijoule), "mJ");
  EXPECT_EQ(Abbreviation(Energy::Microjoule), "μJ");
  EXPECT_EQ(Abbreviation(Energy::Nanojoule), "nJ");
  EXPECT_EQ(Abbreviation(Energy::Kilojoule), "kJ");
  EXPECT_EQ(Abbreviation(Energy::Megajoule), "MJ");
  EXPECT_EQ(Abbreviation(Energy::Gigajoule), "GJ");
  EXPECT_EQ(Abbreviation(Energy::WattMinute), "W·min");
  EXPECT_EQ(Abbreviation(Energy::WattHour), "W·hr");
  EXPECT_EQ(Abbreviation(Energy::KilowattMinute), "kW·min");
  EXPECT_EQ(Abbreviation(Energy::KilowattHour), "kW·hr");
  EXPECT_EQ(Abbreviation(Energy::MegawattMinute), "MW·min");
  EXPECT_EQ(Abbreviation(Energy::MegawattHour), "MW·hr");
  EXPECT_EQ(Abbreviation(Energy::GigawattMinute), "GW·min");
  EXPECT_EQ(Abbreviation(Energy::GigawattHour), "GW·hr");
  EXPECT_EQ(Abbreviation(Energy::FootPound), "ft·lbf");
  EXPECT_EQ(Abbreviation(Energy::InchPound), "in·lbf");
}

TEST(UnitEnergy, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Energy>(UnitSystem::MetreKilogramSecondKelvin),
            Energy::Joule);
  EXPECT_EQ(ConsistentUnit<Energy>(UnitSystem::MillimetreGramSecondKelvin),
            Energy::Nanojoule);
  EXPECT_EQ(ConsistentUnit<Energy>(UnitSystem::FootPoundSecondRankine),
            Energy::FootPound);
  EXPECT_EQ(ConsistentUnit<Energy>(UnitSystem::InchPoundSecondRankine),
            Energy::InchPound);
}

TEST(UnitEnergy, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::Joule), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::Joule, Energy::Millijoule), value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::Joule, Energy::Microjoule), value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::Nanojoule),
                   value * 1000000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::Joule, Energy::Kilojoule), value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::Joule, Energy::Megajoule), value * 0.000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::Gigajoule),
                   value * 0.000000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::Joule, Energy::WattMinute), value / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::Joule, Energy::WattHour), value / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::KilowattMinute),
                   value / 60000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::KilowattHour),
                   value / 3600000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::MegawattMinute),
                   value / 60000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::MegawattHour),
                   value / 3600000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::GigawattMinute),
                   value / 60000000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::GigawattHour),
                   value / 3600000000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::FootPound),
                   value / (0.3048 * 0.45359237 * 9.80665));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::InchPound),
                   value / (0.0254 * 0.45359237 * 9.80665));
}

TEST(UnitEnergy, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Joule, Energy::Joule), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::Millijoule, Energy::Joule), value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::Microjoule, Energy::Joule), value * 0.000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Nanojoule, Energy::Joule),
                   value * 0.000000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::Kilojoule, Energy::Joule), value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::Megajoule, Energy::Joule), value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::Gigajoule, Energy::Joule),
                   value * 1000000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::WattMinute, Energy::Joule), value * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Energy::WattHour, Energy::Joule), value * 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::KilowattMinute, Energy::Joule),
                   value * 60000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::KilowattHour, Energy::Joule),
                   value * 3600000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::MegawattMinute, Energy::Joule),
                   value * 60000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::MegawattHour, Energy::Joule),
                   value * 3600000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::GigawattMinute, Energy::Joule),
                   value * 60000000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::GigawattHour, Energy::Joule),
                   value * 3600000000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::FootPound, Energy::Joule),
                   value * (0.3048 * 0.45359237 * 9.80665));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Energy::InchPound, Energy::Joule),
                   value * (0.0254 * 0.45359237 * 9.80665));
}

TEST(UnitEnergy, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Energy old_unit : Units) {
    for (const Energy new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitEnergy, DimensionSet) {
  EXPECT_EQ(Dimensions<Energy>,
            Dimension::Set(
                Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1}));
}

TEST(UnitEnergy, Parse) {
  EXPECT_EQ(Parse<Energy>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Energy>("J"), Energy::Joule);
  EXPECT_EQ(Parse<Energy>("mJ"), Energy::Millijoule);
  EXPECT_EQ(Parse<Energy>("μJ"), Energy::Microjoule);
  EXPECT_EQ(Parse<Energy>("nJ"), Energy::Nanojoule);
  EXPECT_EQ(Parse<Energy>("kJ"), Energy::Kilojoule);
  EXPECT_EQ(Parse<Energy>("MJ"), Energy::Megajoule);
  EXPECT_EQ(Parse<Energy>("GJ"), Energy::Gigajoule);
  EXPECT_EQ(Parse<Energy>("W·min"), Energy::WattMinute);
  EXPECT_EQ(Parse<Energy>("W·hr"), Energy::WattHour);
  EXPECT_EQ(Parse<Energy>("kW·min"), Energy::KilowattMinute);
  EXPECT_EQ(Parse<Energy>("kW·hr"), Energy::KilowattHour);
  EXPECT_EQ(Parse<Energy>("MW·min"), Energy::MegawattMinute);
  EXPECT_EQ(Parse<Energy>("MW·hr"), Energy::MegawattHour);
  EXPECT_EQ(Parse<Energy>("GW·min"), Energy::GigawattMinute);
  EXPECT_EQ(Parse<Energy>("GW·hr"), Energy::GigawattHour);
  EXPECT_EQ(Parse<Energy>("ft·lbf"), Energy::FootPound);
  EXPECT_EQ(Parse<Energy>("in·lbf"), Energy::InchPound);
}

TEST(UnitEnergy, RelatedUnitSystem) {
  EXPECT_EQ(
      RelatedUnitSystem(Energy::Joule), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Energy::Millijoule), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Microjoule), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Nanojoule),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Energy::Kilojoule), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Megajoule), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Gigajoule), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(Energy::FootPound), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(
      RelatedUnitSystem(Energy::InchPound), UnitSystem::InchPoundSecondRankine);
}

TEST(UnitEnergy, StandardUnit) {
  EXPECT_EQ(StandardUnit<Energy>, Energy::Joule);
}

}  // namespace

}  // namespace PhQ::Unit
