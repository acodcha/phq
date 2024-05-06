// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#include "../../include/PhQ/Unit/TransportEnergyConsumption.hpp"

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
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::JoulePerKilometre), "J/km");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::JoulePerMetre), "J/m");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::NanojoulePerMillimetre), "nJ/mm");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilojoulePerMile), "kJ/mi");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::WattMinutePerMile), "W·min/mi");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::WattHourPerMile), "W·hr/mi");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::WattMinutePerKilometre), "W·min/km");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::WattHourPerKilometre), "W·hr/km");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::WattMinutePerMetre), "W·min/m");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::WattHourPerMetre), "W·hr/m");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilowattMinutePerMile), "kW·min/mi");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilowattHourPerMile), "kW·hr/mi");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilowattMinutePerKilometre), "kW·min/km");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilowattHourPerKilometre), "kW·hr/km");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilowattMinutePerMetre), "kW·min/m");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::KilowattHourPerMetre), "kW·hr/m");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::FootPoundPerFoot), "ft·lbf/ft");
  EXPECT_EQ(Abbreviation(TransportEnergyConsumption::InchPoundPerInch), "in·lbf/in");
}

TEST(UnitTransportEnergyConsumption, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<TransportEnergyConsumption>(UnitSystem::MetreKilogramSecondKelvin),
            TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(ConsistentUnit<TransportEnergyConsumption>(UnitSystem::MillimetreGramSecondKelvin),
            TransportEnergyConsumption::NanojoulePerMillimetre);
  EXPECT_EQ(ConsistentUnit<TransportEnergyConsumption>(UnitSystem::FootPoundSecondRankine),
            TransportEnergyConsumption::FootPoundPerFoot);
  EXPECT_EQ(ConsistentUnit<TransportEnergyConsumption>(UnitSystem::InchPoundSecondRankine),
            TransportEnergyConsumption::InchPoundPerInch);
}

TEST(UnitTransportEnergyConsumption, ConversionReciprocity) {
  constexpr long double original_value{1.234567890123456789L};
  for (const TransportEnergyConsumption original_unit : Units) {
    for (const TransportEnergyConsumption intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitTransportEnergyConsumption, ConvertFromStandard) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::JoulePerMile>(value, value * 1609.344L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::JoulePerKilometre>(value, value * 1000.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::NanojoulePerMillimetre>(
      value, value * 1000000.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::KilojoulePerMile>(value, value * 1.609344L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::WattMinutePerMile>(
      value, value * 1609.344L / 60.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::WattHourPerMile>(
      value, value * 1609.344L / 3600.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::WattMinutePerKilometre>(
      value, value / 0.06L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::WattHourPerKilometre>(value, value / 3.6L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::WattMinutePerMetre>(value, value / 60.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::WattHourPerMetre>(value, value / 3600.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::KilowattMinutePerMile>(
      value, value * 1609.344L / 60000.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::KilowattHourPerMile>(
      value, value * 1609.344L / 3600000.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::KilowattMinutePerKilometre>(
      value, value / 60.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::KilowattHourPerKilometre>(
      value, value / 3600.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::KilowattMinutePerMetre>(
      value, value / 60000.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::KilowattHourPerMetre>(
      value, value / 3600000.0L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::FootPoundPerFoot>(
      value, value / (0.45359237L * 9.80665L));
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::InchPoundPerInch>(
      value, value / (0.45359237L * 9.80665L));
}

TEST(UnitTransportEnergyConsumption, ConvertToStandard) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMile,
                            TransportEnergyConsumption::JoulePerMetre>(value, value / 1609.344L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::JoulePerKilometre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value * 0.001L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::NanojoulePerMillimetre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value * 0.000001L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::KilojoulePerMile,
                            TransportEnergyConsumption::JoulePerMetre>(value, value / 1.609344L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::WattMinutePerMile,
                            TransportEnergyConsumption::JoulePerMetre>(
      value, value * 60.0L / 1609.344L);
  Internal::TestConversions<TransportEnergyConsumption, TransportEnergyConsumption::WattHourPerMile,
                            TransportEnergyConsumption::JoulePerMetre>(
      value, value * 3600.0L / 1609.344L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::WattMinutePerKilometre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value * 0.06L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::WattHourPerKilometre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value * 3.6L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::WattMinutePerMetre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value * 60.0L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::WattHourPerMetre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value * 3600.0L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::KilowattMinutePerMile,
                            TransportEnergyConsumption::JoulePerMetre>(
      value, value * 60000.0L / 1609.344L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::KilowattHourPerMile,
                            TransportEnergyConsumption::JoulePerMetre>(
      value, value * 3600000.0L / 1609.344L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::KilowattMinutePerKilometre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value * 60.0L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::KilowattHourPerKilometre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value * 3600.0L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::KilowattMinutePerMetre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value * 60000.0L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::KilowattHourPerMetre,
                            TransportEnergyConsumption::JoulePerMetre>(value, value * 3600000.0L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::FootPoundPerFoot,
                            TransportEnergyConsumption::JoulePerMetre>(
      value, value * 0.45359237L * 9.80665L);
  Internal::TestConversions<TransportEnergyConsumption,
                            TransportEnergyConsumption::InchPoundPerInch,
                            TransportEnergyConsumption::JoulePerMetre>(
      value, value * 0.45359237L * 9.80665L);
}

TEST(UnitTransportEnergyConsumption, Parse) {
  EXPECT_EQ(Parse<TransportEnergyConsumption>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("J/m"), TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("J/mi"), TransportEnergyConsumption::JoulePerMile);
  EXPECT_EQ(
      Parse<TransportEnergyConsumption>("J/km"), TransportEnergyConsumption::JoulePerKilometre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("J/m"), TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("nJ/mm"),
            TransportEnergyConsumption::NanojoulePerMillimetre);
  EXPECT_EQ(
      Parse<TransportEnergyConsumption>("kJ/mi"), TransportEnergyConsumption::KilojoulePerMile);
  EXPECT_EQ(
      Parse<TransportEnergyConsumption>("W·min/mi"), TransportEnergyConsumption::WattMinutePerMile);
  EXPECT_EQ(
      Parse<TransportEnergyConsumption>("W·hr/mi"), TransportEnergyConsumption::WattHourPerMile);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("W·min/km"),
            TransportEnergyConsumption::WattMinutePerKilometre);
  EXPECT_EQ(Parse<TransportEnergyConsumption>("W·hr/km"),
            TransportEnergyConsumption::WattHourPerKilometre);
  EXPECT_EQ(
      Parse<TransportEnergyConsumption>("W·min/m"), TransportEnergyConsumption::WattMinutePerMetre);
  EXPECT_EQ(
      Parse<TransportEnergyConsumption>("W·hr/m"), TransportEnergyConsumption::WattHourPerMetre);
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
  EXPECT_EQ(
      Parse<TransportEnergyConsumption>("ft·lbf/ft"), TransportEnergyConsumption::FootPoundPerFoot);
  EXPECT_EQ(
      Parse<TransportEnergyConsumption>("in·lbf/in"), TransportEnergyConsumption::InchPoundPerInch);
}

TEST(UnitTransportEnergyConsumption, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<TransportEnergyConsumption>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1}));
}

TEST(UnitTransportEnergyConsumption, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::JoulePerMile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::JoulePerKilometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::JoulePerMetre),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::NanojoulePerMillimetre),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::KilojoulePerMile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::WattMinutePerMile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::WattHourPerMile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::WattMinutePerKilometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::WattHourPerKilometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::WattMinutePerMetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::WattHourPerMetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::KilowattMinutePerMile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::KilowattHourPerMile), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(TransportEnergyConsumption::KilowattMinutePerKilometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::KilowattHourPerKilometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::KilowattMinutePerMetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::KilowattHourPerMetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::FootPoundPerFoot),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(TransportEnergyConsumption::InchPoundPerInch),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitTransportEnergyConsumption, Standard) {
  EXPECT_EQ(Standard<TransportEnergyConsumption>, TransportEnergyConsumption::JoulePerMetre);
}

TEST(UnitTransportEnergyConsumption, Stream) {
  std::ostringstream stream;
  stream << TransportEnergyConsumption::JoulePerMetre;
  EXPECT_EQ(stream.str(), Abbreviation(TransportEnergyConsumption::JoulePerMetre));
}

}  // namespace

}  // namespace PhQ::Unit
