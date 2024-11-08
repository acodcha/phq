// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

TEST(UnitTransportEnergyConsumption, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::JoulePerMile, value,
      value * 1609.344L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::JoulePerKilometre,
      value, value * 1000.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::JoulePerMetre, value,
      value);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::NanojoulePerMillimetre,
      value, value * 1000000.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::KilojoulePerMile,
      value, value * 1.609344L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::WattMinutePerMile,
      value, value * 1609.344L / 60.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::WattHourPerMile, value,
      value * 1609.344L / 3600.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::WattMinutePerKilometre,
      value, value / 0.06L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::WattHourPerKilometre,
      value, value / 3.6L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::WattMinutePerMetre,
      value, value / 60.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::WattHourPerMetre,
      value, value / 3600.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::KilowattMinutePerMile,
      value, value * 1609.344L / 60000.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::KilowattHourPerMile,
      value, value * 1609.344L / 3600000.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre,
      TransportEnergyConsumption::KilowattMinutePerKilometre, value, value / 60.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre,
      TransportEnergyConsumption::KilowattHourPerKilometre, value, value / 3600.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::KilowattMinutePerMetre,
      value, value / 60000.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::KilowattHourPerMetre,
      value, value / 3600000.0L);
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::FootPoundPerFoot,
      value, value / (0.45359237L * 9.80665L));
  Internal::TestConvert<TransportEnergyConsumption>(
      TransportEnergyConsumption::JoulePerMetre, TransportEnergyConsumption::InchPoundPerInch,
      value, value / (0.45359237L * 9.80665L));
}

TEST(UnitTransportEnergyConsumption, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::
      TestConvertStatically<TransportEnergyConsumption, TransportEnergyConsumption::JoulePerMetre,
                            TransportEnergyConsumption::FootPoundPerFoot>(
          value, value / (0.45359237L * 9.80665L));
}

TEST(UnitTransportEnergyConsumption, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("J/m"),
            TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("J/mi"),
            TransportEnergyConsumption::JoulePerMile);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("J/km"),
            TransportEnergyConsumption::JoulePerKilometre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("J/m"),
            TransportEnergyConsumption::JoulePerMetre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("nJ/mm"),
            TransportEnergyConsumption::NanojoulePerMillimetre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("kJ/mi"),
            TransportEnergyConsumption::KilojoulePerMile);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("W·min/mi"),
            TransportEnergyConsumption::WattMinutePerMile);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("W·hr/mi"),
            TransportEnergyConsumption::WattHourPerMile);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("W·min/km"),
            TransportEnergyConsumption::WattMinutePerKilometre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("W·hr/km"),
            TransportEnergyConsumption::WattHourPerKilometre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("W·min/m"),
            TransportEnergyConsumption::WattMinutePerMetre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("W·hr/m"),
            TransportEnergyConsumption::WattHourPerMetre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("kW·min/mi"),
            TransportEnergyConsumption::KilowattMinutePerMile);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("kW·hr/mi"),
            TransportEnergyConsumption::KilowattHourPerMile);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("kW·min/km"),
            TransportEnergyConsumption::KilowattMinutePerKilometre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("kW·hr/km"),
            TransportEnergyConsumption::KilowattHourPerKilometre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("kW·min/m"),
            TransportEnergyConsumption::KilowattMinutePerMetre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("kW·hr/m"),
            TransportEnergyConsumption::KilowattHourPerMetre);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("ft·lbf/ft"),
            TransportEnergyConsumption::FootPoundPerFoot);
  EXPECT_EQ(ParseEnumeration<TransportEnergyConsumption>("in·lbf/in"),
            TransportEnergyConsumption::InchPoundPerInch);
}

TEST(UnitTransportEnergyConsumption, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<TransportEnergyConsumption>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
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
