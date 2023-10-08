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

#include "../../include/PhQ/Unit/TransportEnergyConsumption.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<TransportEnergyConsumption, 19> Units = {
    TransportEnergyConsumption::JoulePerMile,
    TransportEnergyConsumption::JoulePerKilometre,
    TransportEnergyConsumption::JoulePerMetre,
    TransportEnergyConsumption::NanojoulePerMillimetre,
    TransportEnergyConsumption::KilojoulePerMile,
    TransportEnergyConsumption::WattMinutePerMile,
    TransportEnergyConsumption::WattHourPerMile,
    TransportEnergyConsumption::WattMinutePerKilometre,
    TransportEnergyConsumption::WattHourPerKilometre,
    TransportEnergyConsumption::WattMinutePerMetre,
    TransportEnergyConsumption::WattHourPerMetre,
    TransportEnergyConsumption::KilowattMinutePerMile,
    TransportEnergyConsumption::KilowattHourPerMile,
    TransportEnergyConsumption::KilowattMinutePerKilometre,
    TransportEnergyConsumption::KilowattHourPerKilometre,
    TransportEnergyConsumption::KilowattMinutePerMetre,
    TransportEnergyConsumption::KilowattHourPerMetre,
    TransportEnergyConsumption::FootPoundPerFoot,
    TransportEnergyConsumption::InchPoundPerInch,
};

TEST(UnitTransportEnergyConsumption, Abbreviation) {
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::JoulePerMile), "J/mi");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::JoulePerKilometre),
            "J/"
            "km");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::JoulePerMetre), "J/m");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::NanojoulePerMillimetre),
            "nJ/mm");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilojoulePerMile),
            "kJ/"
            "mi");
  EXPECT_EQ(
      Abbreviation(TransportEnergyConsumption::WattMinutePerMile), "W·min/mi");
  EXPECT_EQ(
      Abbreviation(TransportEnergyConsumption::WattHourPerMile), "W·hr/mi");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::WattMinutePerKilometre),
            "W·min/km");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::WattHourPerKilometre),
            "W·hr/km");
  EXPECT_EQ(
      Abbreviation(TransportEnergyConsumption::WattMinutePerMetre), "W·min/m");
  EXPECT_EQ(
      Abbreviation(TransportEnergyConsumption::WattHourPerMetre), "W·hr/m");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilowattMinutePerMile),
            "kW·min/mi");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilowattHourPerMile),
            "kW·hr/mi");
  EXPECT_EQ(
      Abbreviation(TransportEnergyConsumption::KilowattMinutePerKilometre),
      "kW·min/km");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilowattHourPerKilometre),
            "kW·hr/km");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilowattMinutePerMetre),
            "kW·min/m");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilowattHourPerMetre),
            "kW·hr/m");
  EXPECT_EQ(
      Abbreviation(TransportEnergyConsumption::FootPoundPerFoot), "ft·lbf/ft");
  EXPECT_EQ(
      Abbreviation(TransportEnergyConsumption::InchPoundPerInch), "in·lbf/in");
}

TEST(UnitTransportEnergyConsumption, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<TransportEnergyConsumption>(
                UnitSystem::MetreKilogramSecondKelvin),
            TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(ConsistentUnit<TransportEnergyConsumption>(
                UnitSystem::MillimetreGramSecondKelvin),
            TransportEnergyConsumption::NanojoulePerMillimetre);
  EXPECT_EQ(ConsistentUnit<TransportEnergyConsumption>(
                UnitSystem::FootPoundSecondRankine),
            TransportEnergyConsumption::FootPoundPerFoot);
  EXPECT_EQ(ConsistentUnit<TransportEnergyConsumption>(
                UnitSystem::InchPoundSecondRankine),
            TransportEnergyConsumption::InchPoundPerInch);
}

TEST(UnitTransportEnergyConsumption, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::JoulePerMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::JoulePerMile),
                   value * 1609.344);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::JoulePerKilometre),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::JoulePerMetre),
                   value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                  TransportEnergyConsumption::NanojoulePerMillimetre),
      value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::KilojoulePerMile),
                   value * 1.609344);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::WattMinutePerMile),
                   value * 1609.344 / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::WattHourPerMile),
                   value * 1609.344 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                  TransportEnergyConsumption::WattMinutePerKilometre),
      value / 0.06);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                  TransportEnergyConsumption::WattHourPerKilometre),
      value / 3.6);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::WattMinutePerMetre),
                   value / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::WattHourPerMetre),
                   value / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                  TransportEnergyConsumption::KilowattMinutePerMile),
      value * 1609.344 / 60000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::KilowattHourPerMile),
                   value * 1609.344 / 3600000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                  TransportEnergyConsumption::KilowattMinutePerKilometre),
      value / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                  TransportEnergyConsumption::KilowattHourPerKilometre),
      value / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                  TransportEnergyConsumption::KilowattMinutePerMetre),
      value / 60000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                  TransportEnergyConsumption::KilowattHourPerMetre),
      value / 3600000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::FootPoundPerFoot),
                   value / (0.45359237 * 9.80665));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::InchPoundPerInch),
                   value / (0.45359237 * 9.80665));
}

TEST(UnitTransportEnergyConsumption, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::JoulePerMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMile,
                               TransportEnergyConsumption::JoulePerMetre),
                   value / 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::JoulePerKilometre,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 0.001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TransportEnergyConsumption::JoulePerMetre,
                               TransportEnergyConsumption::JoulePerMetre),
                   value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::NanojoulePerMillimetre,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 0.000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::KilojoulePerMile,
                  TransportEnergyConsumption::JoulePerMetre),
      value / 1.609344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::WattMinutePerMile,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 60.0 / 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::WattHourPerMile,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 3600.0 / 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::WattMinutePerKilometre,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 0.06);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::WattHourPerKilometre,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 3.6);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::WattMinutePerMetre,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::WattHourPerMetre,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::KilowattMinutePerMile,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 60000.0 / 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::KilowattHourPerMile,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 3600000.0 / 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::KilowattMinutePerKilometre,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::KilowattHourPerKilometre,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::KilowattMinutePerMetre,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 60000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::KilowattHourPerMetre,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 3600000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::FootPoundPerFoot,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 0.45359237 * 9.80665);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, TransportEnergyConsumption::InchPoundPerInch,
                  TransportEnergyConsumption::JoulePerMetre),
      value * 0.45359237 * 9.80665);
}

TEST(UnitTransportEnergyConsumption, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const TransportEnergyConsumption old_unit : Units) {
    for (const TransportEnergyConsumption new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitTransportEnergyConsumption, Parse) {
  EXPECT_EQ(Parse<TransportEnergyConsumption>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("J/m"),
            TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("J/mi"),
            TransportEnergyConsumption::JoulePerMile);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("J/km"),
            TransportEnergyConsumption::JoulePerKilometre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("J/m"),
            TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("nJ/mm"),
            TransportEnergyConsumption::NanojoulePerMillimetre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("kJ/mi"),
            TransportEnergyConsumption::KilojoulePerMile);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("W·min/mi"),
            TransportEnergyConsumption::WattMinutePerMile);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("W·hr/mi"),
            TransportEnergyConsumption::WattHourPerMile);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("W·min/km"),
            TransportEnergyConsumption::WattMinutePerKilometre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("W·hr/km"),
            TransportEnergyConsumption::WattHourPerKilometre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("W·min/m"),
            TransportEnergyConsumption::WattMinutePerMetre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("W·hr/m"),
            TransportEnergyConsumption::WattHourPerMetre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("kW·min/mi"),
            TransportEnergyConsumption::KilowattMinutePerMile);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("kW·hr/mi"),
            TransportEnergyConsumption::KilowattHourPerMile);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("kW·min/km"),
            TransportEnergyConsumption::KilowattMinutePerKilometre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("kW·hr/km"),
            TransportEnergyConsumption::KilowattHourPerKilometre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("kW·min/m"),
            TransportEnergyConsumption::KilowattMinutePerMetre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("kW·hr/m"),
            TransportEnergyConsumption::KilowattHourPerMetre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("ft·lbf/ft"),
            TransportEnergyConsumption::FootPoundPerFoot);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("in·lbf/in"),
            TransportEnergyConsumption::InchPoundPerInch);
}

TEST(UnitTransportEnergyConsumption, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<TransportEnergyConsumption>,
            Dimensions(
                Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1}));
}

TEST(UnitTransportEnergyConsumption, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::JoulePerMile),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::JoulePerKilometre),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::JoulePerMetre),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(
      RelatedUnitSystem(TransportEnergyConsumption::NanojoulePerMillimetre),
      UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::KilojoulePerMile),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::WattMinutePerMile),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::WattHourPerMile),
            std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(TransportEnergyConsumption::WattMinutePerKilometre),
      std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::WattHourPerKilometre),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::WattMinutePerMetre),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::WattHourPerMetre),
            std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(TransportEnergyConsumption::KilowattMinutePerMile),
      std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::KilowattHourPerMile),
            std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(TransportEnergyConsumption::KilowattMinutePerKilometre),
      std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(TransportEnergyConsumption::KilowattHourPerKilometre),
      std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(TransportEnergyConsumption::KilowattMinutePerMetre),
      std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::KilowattHourPerMetre),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::FootPoundPerFoot),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::InchPoundPerInch),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitTransportEnergyConsumption, Standard) {
  EXPECT_EQ(Standard<TransportEnergyConsumption>,
            TransportEnergyConsumption::JoulePerMetre);
}

TEST(UnitTransportEnergyConsumption, Stream) {
  std::ostringstream stream;
  stream << TransportEnergyConsumption::JoulePerMetre;
  EXPECT_EQ(
      stream.str(), Abbreviation(TransportEnergyConsumption::JoulePerMetre));
}

}  // namespace

}  // namespace PhQ::Unit
