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

#include "../../include/PhQ/Unit/Energy.hpp"

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

constexpr std::array<Energy, 32> Units = {
    Energy::Joule,
    Energy::Millijoule,
    Energy::Microjoule,
    Energy::Nanojoule,
    Energy::Kilojoule,
    Energy::Megajoule,
    Energy::Gigajoule,
    Energy::WattMinute,
    Energy::WattHour,
    Energy::KilowattMinute,
    Energy::KilowattHour,
    Energy::MegawattMinute,
    Energy::MegawattHour,
    Energy::GigawattMinute,
    Energy::GigawattHour,
    Energy::FootPound,
    Energy::InchPound,
    Energy::Calorie,
    Energy::Millicalorie,
    Energy::Microcalorie,
    Energy::Nanocalorie,
    Energy::Kilocalorie,
    Energy::Megacalorie,
    Energy::Gigacalorie,
    Energy::Electronvolt,
    Energy::Millielectronvolt,
    Energy::Microelectronvolt,
    Energy::Nanoelectronvolt,
    Energy::Kiloelectronvolt,
    Energy::Megaelectronvolt,
    Energy::Gigaelectronvolt,
    Energy::BritishThermalUnit,
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
  EXPECT_EQ(Abbreviation(Energy::Calorie), "cal");
  EXPECT_EQ(Abbreviation(Energy::Millicalorie), "mcal");
  EXPECT_EQ(Abbreviation(Energy::Microcalorie), "μcal");
  EXPECT_EQ(Abbreviation(Energy::Nanocalorie), "ncal");
  EXPECT_EQ(Abbreviation(Energy::Kilocalorie), "kcal");
  EXPECT_EQ(Abbreviation(Energy::Megacalorie), "Mcal");
  EXPECT_EQ(Abbreviation(Energy::Gigacalorie), "Gcal");
  EXPECT_EQ(Abbreviation(Energy::Electronvolt), "eV");
  EXPECT_EQ(Abbreviation(Energy::Millielectronvolt), "meV");
  EXPECT_EQ(Abbreviation(Energy::Microelectronvolt), "μeV");
  EXPECT_EQ(Abbreviation(Energy::Nanoelectronvolt), "neV");
  EXPECT_EQ(Abbreviation(Energy::Kiloelectronvolt), "keV");
  EXPECT_EQ(Abbreviation(Energy::Megaelectronvolt), "MeV");
  EXPECT_EQ(Abbreviation(Energy::Gigaelectronvolt), "GeV");
  EXPECT_EQ(Abbreviation(Energy::BritishThermalUnit), "BTU");
}

TEST(UnitEnergy, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Energy>(UnitSystem::MetreKilogramSecondKelvin), Energy::Joule);
  EXPECT_EQ(ConsistentUnit<Energy>(UnitSystem::MillimetreGramSecondKelvin), Energy::Nanojoule);
  EXPECT_EQ(ConsistentUnit<Energy>(UnitSystem::FootPoundSecondRankine), Energy::FootPound);
  EXPECT_EQ(ConsistentUnit<Energy>(UnitSystem::InchPoundSecondRankine), Energy::InchPound);
}

TEST(UnitEnergy, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const Energy original_unit : Units) {
    for (const Energy intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitEnergy, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(Energy::Joule, Energy::Joule, value, value);
  Internal::TestConversions(Energy::Joule, Energy::Millijoule, value, value * 1000.0);
  Internal::TestConversions(Energy::Joule, Energy::Microjoule, value, value * 1000000.0);
  Internal::TestConversions(Energy::Joule, Energy::Nanojoule, value, value * 1000000000.0);
  Internal::TestConversions(Energy::Joule, Energy::Kilojoule, value, value * 0.001);
  Internal::TestConversions(Energy::Joule, Energy::Megajoule, value, value * 0.000001);
  Internal::TestConversions(Energy::Joule, Energy::Gigajoule, value, value * 0.000000001);
  Internal::TestConversions(Energy::Joule, Energy::WattMinute, value, value / 60.0);
  Internal::TestConversions(Energy::Joule, Energy::WattHour, value, value / 3600.0);
  Internal::TestConversions(Energy::Joule, Energy::KilowattMinute, value, value / 60000.0);
  Internal::TestConversions(Energy::Joule, Energy::KilowattHour, value, value / 3600000.0);
  Internal::TestConversions(Energy::Joule, Energy::MegawattMinute, value, value / 60000000.0);
  Internal::TestConversions(Energy::Joule, Energy::MegawattHour, value, value / 3600000000.0);
  Internal::TestConversions(Energy::Joule, Energy::GigawattMinute, value, value / 60000000000.0);
  Internal::TestConversions(Energy::Joule, Energy::GigawattHour, value, value / 3600000000000.0);
  Internal::TestConversions(
      Energy::Joule, Energy::FootPound, value, value / (0.3048 * 0.45359237 * 9.80665));
  Internal::TestConversions(
      Energy::Joule, Energy::InchPound, value, value / (0.0254 * 0.45359237 * 9.80665));
  Internal::TestConversions(Energy::Joule, Energy::Calorie, value, value / 4.184);
  Internal::TestConversions(Energy::Joule, Energy::Millicalorie, value, value / 0.004184);
  Internal::TestConversions(Energy::Joule, Energy::Microcalorie, value, value / 0.000004184);
  Internal::TestConversions(Energy::Joule, Energy::Nanocalorie, value, value / 0.000000004184);
  Internal::TestConversions(Energy::Joule, Energy::Kilocalorie, value, value / 4184.0);
  Internal::TestConversions(Energy::Joule, Energy::Megacalorie, value, value / 4184000.0);
  Internal::TestConversions(Energy::Joule, Energy::Gigacalorie, value, value / 4184000000.0);
  Internal::TestConversions(Energy::Joule, Energy::Electronvolt, value, value / 1.602176634e-19);
  Internal::TestConversions(
      Energy::Joule, Energy::Millielectronvolt, value, value / 1.602176634e-22);
  Internal::TestConversions(
      Energy::Joule, Energy::Microelectronvolt, value, value / 1.602176634e-25);
  Internal::TestConversions(
      Energy::Joule, Energy::Nanoelectronvolt, value, value / 1.602176634e-28);
  Internal::TestConversions(
      Energy::Joule, Energy::Kiloelectronvolt, value, value / 1.602176634e-16);
  Internal::TestConversions(
      Energy::Joule, Energy::Megaelectronvolt, value, value / 1.602176634e-13);
  Internal::TestConversions(
      Energy::Joule, Energy::Gigaelectronvolt, value, value / 1.602176634e-10);
  Internal::TestConversions(
      Energy::Joule, Energy::BritishThermalUnit, value, value * 1.8 / (4.1868 * 453.59237));

  Internal::TestStaticConversions<Energy, Energy::Joule, Energy::FootPound>(
      value, value / (0.3048 * 0.45359237 * 9.80665));
}

TEST(UnitEnergy, ConvertToStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(Energy::Joule, Energy::Joule, value, value);
  Internal::TestConversions(Energy::Millijoule, Energy::Joule, value, value * 0.001);
  Internal::TestConversions(Energy::Microjoule, Energy::Joule, value, value * 0.000001);
  Internal::TestConversions(Energy::Nanojoule, Energy::Joule, value, value * 0.000000001);
  Internal::TestConversions(Energy::Kilojoule, Energy::Joule, value, value * 1000.0);
  Internal::TestConversions(Energy::Megajoule, Energy::Joule, value, value * 1000000.0);
  Internal::TestConversions(Energy::Gigajoule, Energy::Joule, value, value * 1000000000.0);
  Internal::TestConversions(Energy::WattMinute, Energy::Joule, value, value * 60.0);
  Internal::TestConversions(Energy::WattHour, Energy::Joule, value, value * 3600.0);
  Internal::TestConversions(Energy::KilowattMinute, Energy::Joule, value, value * 60000.0);
  Internal::TestConversions(Energy::KilowattHour, Energy::Joule, value, value * 3600000.0);
  Internal::TestConversions(Energy::MegawattMinute, Energy::Joule, value, value * 60000000.0);
  Internal::TestConversions(Energy::MegawattHour, Energy::Joule, value, value * 3600000000.0);
  Internal::TestConversions(Energy::GigawattMinute, Energy::Joule, value, value * 60000000000.0);
  Internal::TestConversions(Energy::GigawattHour, Energy::Joule, value, value * 3600000000000.0);
  Internal::TestConversions(
      Energy::FootPound, Energy::Joule, value, value * (0.3048 * 0.45359237 * 9.80665));
  Internal::TestConversions(
      Energy::InchPound, Energy::Joule, value, value * (0.0254 * 0.45359237 * 9.80665));
  Internal::TestConversions(Energy::Calorie, Energy::Joule, value, value * 4.184);
  Internal::TestConversions(Energy::Millicalorie, Energy::Joule, value, value * 0.004184);
  Internal::TestConversions(Energy::Microcalorie, Energy::Joule, value, value * 0.000004184);
  Internal::TestConversions(Energy::Nanocalorie, Energy::Joule, value, value * 0.000000004184);
  Internal::TestConversions(Energy::Kilocalorie, Energy::Joule, value, value * 4184.0);
  Internal::TestConversions(Energy::Megacalorie, Energy::Joule, value, value * 4184000.0);
  Internal::TestConversions(Energy::Gigacalorie, Energy::Joule, value, value * 4184000000.0);
  Internal::TestConversions(Energy::Electronvolt, Energy::Joule, value, value * 1.602176634e-19);
  Internal::TestConversions(
      Energy::Millielectronvolt, Energy::Joule, value, value * 1.602176634e-22);
  Internal::TestConversions(
      Energy::Microelectronvolt, Energy::Joule, value, value * 1.602176634e-25);
  Internal::TestConversions(
      Energy::Nanoelectronvolt, Energy::Joule, value, value * 1.602176634e-28);
  Internal::TestConversions(
      Energy::Kiloelectronvolt, Energy::Joule, value, value * 1.602176634e-16);
  Internal::TestConversions(
      Energy::Megaelectronvolt, Energy::Joule, value, value * 1.602176634e-13);
  Internal::TestConversions(
      Energy::Gigaelectronvolt, Energy::Joule, value, value * 1.602176634e-10);
  Internal::TestConversions(
      Energy::BritishThermalUnit, Energy::Joule, value, value * 4.1868 * 453.59237 / 1.8);

  Internal::TestStaticConversions<Energy, Energy::FootPound, Energy::Joule>(
      value, value * (0.3048 * 0.45359237 * 9.80665));
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
  EXPECT_EQ(Parse<Energy>("cal"), Energy::Calorie);
  EXPECT_EQ(Parse<Energy>("mcal"), Energy::Millicalorie);
  EXPECT_EQ(Parse<Energy>("μcal"), Energy::Microcalorie);
  EXPECT_EQ(Parse<Energy>("ncal"), Energy::Nanocalorie);
  EXPECT_EQ(Parse<Energy>("kcal"), Energy::Kilocalorie);
  EXPECT_EQ(Parse<Energy>("Mcal"), Energy::Megacalorie);
  EXPECT_EQ(Parse<Energy>("Gcal"), Energy::Gigacalorie);
  EXPECT_EQ(Parse<Energy>("eV"), Energy::Electronvolt);
  EXPECT_EQ(Parse<Energy>("meV"), Energy::Millielectronvolt);
  EXPECT_EQ(Parse<Energy>("μeV"), Energy::Microelectronvolt);
  EXPECT_EQ(Parse<Energy>("neV"), Energy::Nanoelectronvolt);
  EXPECT_EQ(Parse<Energy>("keV"), Energy::Kiloelectronvolt);
  EXPECT_EQ(Parse<Energy>("MeV"), Energy::Megaelectronvolt);
  EXPECT_EQ(Parse<Energy>("GeV"), Energy::Gigaelectronvolt);
  EXPECT_EQ(Parse<Energy>("BTU"), Energy::BritishThermalUnit);
}

TEST(UnitEnergy, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Energy>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1}));
}

TEST(UnitEnergy, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Energy::Joule), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Energy::Millijoule), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Microjoule), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Nanojoule), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Energy::Kilojoule), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Megajoule), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Gigajoule), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::FootPound), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Energy::InchPound), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Energy::Calorie), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Millicalorie), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Microcalorie), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Nanocalorie), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Kilocalorie), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Megacalorie), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Gigacalorie), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Electronvolt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Millielectronvolt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Microelectronvolt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Nanoelectronvolt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Kiloelectronvolt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Megaelectronvolt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::Gigaelectronvolt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Energy::BritishThermalUnit), std::nullopt);
}

TEST(UnitEnergy, Standard) {
  EXPECT_EQ(Standard<Energy>, Energy::Joule);
}

TEST(UnitEnergy, Stream) {
  std::ostringstream stream;
  stream << Energy::Joule;
  EXPECT_EQ(stream.str(), Abbreviation(Energy::Joule));
}

}  // namespace

}  // namespace PhQ::Unit
