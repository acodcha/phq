// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

TEST(UnitEnergy, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<Energy>(Energy::Joule, Energy::Joule, value, value);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Millijoule, value, value * 1000.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Microjoule, value, value * 1000000.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Nanojoule, value, value * 1000000000.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Kilojoule, value, value * 0.001L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Megajoule, value, value * 0.000001L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Gigajoule, value, value * 0.000000001L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::WattMinute, value, value / 60.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::WattHour, value, value / 3600.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::KilowattMinute, value, value / 60000.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::KilowattHour, value, value / 3600000.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::MegawattMinute, value, value / 60000000.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::MegawattHour, value, value / 3600000000.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::GigawattMinute, value, value / 60000000000.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::GigawattHour, value, value / 3600000000000.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::FootPound, value, value / (0.3048L * 0.45359237L * 9.80665L));
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::InchPound, value, value / (0.0254L * 0.45359237L * 9.80665L));
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Calorie, value, value / 4.184L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Millicalorie, value, value / 0.004184L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Microcalorie, value, value / 0.000004184L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Nanocalorie, value, value / 0.000000004184L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Kilocalorie, value, value / 4184.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Megacalorie, value, value / 4184000.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Gigacalorie, value, value / 4184000000.0L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Electronvolt, value, value / 1.602176634e-19L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Millielectronvolt, value, value / 1.602176634e-22L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Microelectronvolt, value, value / 1.602176634e-25L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Nanoelectronvolt, value, value / 1.602176634e-28L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Kiloelectronvolt, value, value / 1.602176634e-16L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Megaelectronvolt, value, value / 1.602176634e-13L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::Gigaelectronvolt, value, value / 1.602176634e-10L);
  Internal::TestConvertAndConvertCopy<Energy>(
      Energy::Joule, Energy::BritishThermalUnit, value, value * 1.8L / (4.1868L * 453.59237L));
}

TEST(UnitEnergy, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Energy>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Energy>("J"), Energy::Joule);
  EXPECT_EQ(ParseEnumeration<Energy>("mJ"), Energy::Millijoule);
  EXPECT_EQ(ParseEnumeration<Energy>("μJ"), Energy::Microjoule);
  EXPECT_EQ(ParseEnumeration<Energy>("nJ"), Energy::Nanojoule);
  EXPECT_EQ(ParseEnumeration<Energy>("kJ"), Energy::Kilojoule);
  EXPECT_EQ(ParseEnumeration<Energy>("MJ"), Energy::Megajoule);
  EXPECT_EQ(ParseEnumeration<Energy>("GJ"), Energy::Gigajoule);
  EXPECT_EQ(ParseEnumeration<Energy>("W·min"), Energy::WattMinute);
  EXPECT_EQ(ParseEnumeration<Energy>("W·hr"), Energy::WattHour);
  EXPECT_EQ(ParseEnumeration<Energy>("kW·min"), Energy::KilowattMinute);
  EXPECT_EQ(ParseEnumeration<Energy>("kW·hr"), Energy::KilowattHour);
  EXPECT_EQ(ParseEnumeration<Energy>("MW·min"), Energy::MegawattMinute);
  EXPECT_EQ(ParseEnumeration<Energy>("MW·hr"), Energy::MegawattHour);
  EXPECT_EQ(ParseEnumeration<Energy>("GW·min"), Energy::GigawattMinute);
  EXPECT_EQ(ParseEnumeration<Energy>("GW·hr"), Energy::GigawattHour);
  EXPECT_EQ(ParseEnumeration<Energy>("ft·lbf"), Energy::FootPound);
  EXPECT_EQ(ParseEnumeration<Energy>("in·lbf"), Energy::InchPound);
  EXPECT_EQ(ParseEnumeration<Energy>("cal"), Energy::Calorie);
  EXPECT_EQ(ParseEnumeration<Energy>("mcal"), Energy::Millicalorie);
  EXPECT_EQ(ParseEnumeration<Energy>("μcal"), Energy::Microcalorie);
  EXPECT_EQ(ParseEnumeration<Energy>("ncal"), Energy::Nanocalorie);
  EXPECT_EQ(ParseEnumeration<Energy>("kcal"), Energy::Kilocalorie);
  EXPECT_EQ(ParseEnumeration<Energy>("Mcal"), Energy::Megacalorie);
  EXPECT_EQ(ParseEnumeration<Energy>("Gcal"), Energy::Gigacalorie);
  EXPECT_EQ(ParseEnumeration<Energy>("eV"), Energy::Electronvolt);
  EXPECT_EQ(ParseEnumeration<Energy>("meV"), Energy::Millielectronvolt);
  EXPECT_EQ(ParseEnumeration<Energy>("μeV"), Energy::Microelectronvolt);
  EXPECT_EQ(ParseEnumeration<Energy>("neV"), Energy::Nanoelectronvolt);
  EXPECT_EQ(ParseEnumeration<Energy>("keV"), Energy::Kiloelectronvolt);
  EXPECT_EQ(ParseEnumeration<Energy>("MeV"), Energy::Megaelectronvolt);
  EXPECT_EQ(ParseEnumeration<Energy>("GeV"), Energy::Gigaelectronvolt);
  EXPECT_EQ(ParseEnumeration<Energy>("BTU"), Energy::BritishThermalUnit);
}

TEST(UnitEnergy, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Energy>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
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

TEST(UnitEnergy, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Energy, Energy::Joule, Energy::FootPound>(
      value, value / (0.3048L * 0.45359237L * 9.80665L));
}

TEST(UnitEnergy, Stream) {
  std::ostringstream stream;
  stream << Energy::Joule;
  EXPECT_EQ(stream.str(), Abbreviation(Energy::Joule));
}

}  // namespace

}  // namespace PhQ::Unit
