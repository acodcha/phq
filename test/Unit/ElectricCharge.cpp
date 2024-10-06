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

#include "../../include/PhQ/Unit/ElectricCharge.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<ElectricCharge, 25> Units = {
  ElectricCharge::Coulomb,          ElectricCharge::Kilocoulomb,
  ElectricCharge::Megacoulomb,      ElectricCharge::Gigacoulomb,
  ElectricCharge::Teracoulomb,      ElectricCharge::Millicoulomb,
  ElectricCharge::Microcoulomb,     ElectricCharge::Nanocoulomb,
  ElectricCharge::ElementaryCharge, ElectricCharge::AmpereMinute,
  ElectricCharge::AmpereHour,       ElectricCharge::KiloampereMinute,
  ElectricCharge::KiloampereHour,   ElectricCharge::MegaampereMinute,
  ElectricCharge::MegaampereHour,   ElectricCharge::GigaampereMinute,
  ElectricCharge::GigaampereHour,   ElectricCharge::TeraampereMinute,
  ElectricCharge::TeraampereHour,   ElectricCharge::MilliampereMinute,
  ElectricCharge::MilliampereHour,  ElectricCharge::MicroampereMinute,
  ElectricCharge::MicroampereHour,  ElectricCharge::NanoampereMinute,
  ElectricCharge::NanoampereHour,
};

TEST(UnitAngle, Abbreviation) {
  EXPECT_EQ(Abbreviation(ElectricCharge::Coulomb), "C");
  EXPECT_EQ(Abbreviation(ElectricCharge::Kilocoulomb), "kC");
  EXPECT_EQ(Abbreviation(ElectricCharge::Megacoulomb), "MC");
  EXPECT_EQ(Abbreviation(ElectricCharge::Gigacoulomb), "GC");
  EXPECT_EQ(Abbreviation(ElectricCharge::Teracoulomb), "TC");
  EXPECT_EQ(Abbreviation(ElectricCharge::Millicoulomb), "mC");
  EXPECT_EQ(Abbreviation(ElectricCharge::Microcoulomb), "μC");
  EXPECT_EQ(Abbreviation(ElectricCharge::Nanocoulomb), "nC");
  EXPECT_EQ(Abbreviation(ElectricCharge::ElementaryCharge), "e");
  EXPECT_EQ(Abbreviation(ElectricCharge::AmpereMinute), "A·min");
  EXPECT_EQ(Abbreviation(ElectricCharge::AmpereHour), "A·hr");
  EXPECT_EQ(Abbreviation(ElectricCharge::KiloampereMinute), "kA·min");
  EXPECT_EQ(Abbreviation(ElectricCharge::KiloampereHour), "kA·hr");
  EXPECT_EQ(Abbreviation(ElectricCharge::MegaampereMinute), "MA·min");
  EXPECT_EQ(Abbreviation(ElectricCharge::MegaampereHour), "MA·hr");
  EXPECT_EQ(Abbreviation(ElectricCharge::GigaampereMinute), "GA·min");
  EXPECT_EQ(Abbreviation(ElectricCharge::GigaampereHour), "GA·hr");
  EXPECT_EQ(Abbreviation(ElectricCharge::TeraampereMinute), "TA·min");
  EXPECT_EQ(Abbreviation(ElectricCharge::TeraampereHour), "TA·hr");
  EXPECT_EQ(Abbreviation(ElectricCharge::MilliampereMinute), "mA·min");
  EXPECT_EQ(Abbreviation(ElectricCharge::MilliampereHour), "mA·hr");
  EXPECT_EQ(Abbreviation(ElectricCharge::MicroampereMinute), "μA·min");
  EXPECT_EQ(Abbreviation(ElectricCharge::MicroampereHour), "μA·hr");
  EXPECT_EQ(Abbreviation(ElectricCharge::NanoampereMinute), "nA·min");
  EXPECT_EQ(Abbreviation(ElectricCharge::NanoampereHour), "nA·hr");
}

TEST(UnitAngle, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<ElectricCharge>(UnitSystem::MetreKilogramSecondKelvin),
            ElectricCharge::Coulomb);
  EXPECT_EQ(ConsistentUnit<ElectricCharge>(UnitSystem::MillimetreGramSecondKelvin),
            ElectricCharge::Coulomb);
  EXPECT_EQ(
      ConsistentUnit<ElectricCharge>(UnitSystem::FootPoundSecondRankine), ElectricCharge::Coulomb);
  EXPECT_EQ(
      ConsistentUnit<ElectricCharge>(UnitSystem::InchPoundSecondRankine), ElectricCharge::Coulomb);
}

TEST(UnitAngle, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::Coulomb, value, value);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::Kilocoulomb, value, value * 0.001L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::Megacoulomb, value, value * 1.0E-6L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::Gigacoulomb, value, value * 1.0E-9L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::Teracoulomb, value, value * 1.0E-12L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::Millicoulomb, value, value * 1000.0L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::Microcoulomb, value, value * 1.0E6L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::Nanocoulomb, value, value * 1.0E9L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::ElementaryCharge, value, value / 1.602176634E-19L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::AmpereMinute, value, value / 60.0L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::AmpereHour, value, value / 3600.0L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::KiloampereMinute, value, value / 6.0E4L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::KiloampereHour, value, value / 3.6E6L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::MegaampereMinute, value, value / 6.0E7L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::MegaampereHour, value, value / 3.6E9L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::GigaampereMinute, value, value / 6.0E10L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::GigaampereHour, value, value / 3.6E12L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::TeraampereMinute, value, value / 6.0E13L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::TeraampereHour, value, value / 3.6E15L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::MilliampereMinute, value, value / 0.06L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::MilliampereHour, value, value / 3.6L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::MicroampereMinute, value, value / 6.0E-5L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::MicroampereHour, value, value / 3.6E-3L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::NanoampereMinute, value, value / 6.0E-8L);
  Internal::TestConvert<ElectricCharge>(
      ElectricCharge::Coulomb, ElectricCharge::NanoampereHour, value, value / 3.6E-6L);
}

TEST(UnitAngle, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::
      TestConvertStatically<ElectricCharge, ElectricCharge::Coulomb, ElectricCharge::Kilocoulomb>(
          value, value * 0.001L);
}

TEST(UnitAngle, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("C"), ElectricCharge::Coulomb);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("kC"), ElectricCharge::Kilocoulomb);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("MC"), ElectricCharge::Megacoulomb);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("GC"), ElectricCharge::Gigacoulomb);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("TC"), ElectricCharge::Teracoulomb);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("mC"), ElectricCharge::Millicoulomb);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("μC"), ElectricCharge::Microcoulomb);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("nC"), ElectricCharge::Nanocoulomb);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("e"), ElectricCharge::ElementaryCharge);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("A·min"), ElectricCharge::AmpereMinute);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("A·hr"), ElectricCharge::AmpereHour);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("kA·min"), ElectricCharge::KiloampereMinute);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("kA·hr"), ElectricCharge::KiloampereHour);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("MA·min"), ElectricCharge::MegaampereMinute);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("MA·hr"), ElectricCharge::MegaampereHour);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("GA·min"), ElectricCharge::GigaampereMinute);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("GA·hr"), ElectricCharge::GigaampereHour);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("TA·min"), ElectricCharge::TeraampereMinute);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("TA·hr"), ElectricCharge::TeraampereHour);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("mA·min"), ElectricCharge::MilliampereMinute);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("mA·hr"), ElectricCharge::MilliampereHour);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("μA·min"), ElectricCharge::MicroampereMinute);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("μA·hr"), ElectricCharge::MicroampereHour);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("nA·min"), ElectricCharge::NanoampereMinute);
  EXPECT_EQ(ParseEnumeration<ElectricCharge>("nA·hr"), ElectricCharge::NanoampereHour);
}

TEST(UnitAngle, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<ElectricCharge>,
            Dimensions(Dimension::Time{1}, Dimension::Length{0}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{1}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitAngle, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::Coulomb), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::Kilocoulomb), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::Megacoulomb), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::Gigacoulomb), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::Teracoulomb), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::Millicoulomb), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::Microcoulomb), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::Nanocoulomb), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::ElementaryCharge), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::AmpereMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::AmpereHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::KiloampereMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::KiloampereHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::MegaampereMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::MegaampereHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::GigaampereMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::GigaampereHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::TeraampereMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::TeraampereHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::MilliampereMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::MilliampereHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::MicroampereMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::MicroampereHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::NanoampereMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ElectricCharge::NanoampereHour), std::nullopt);
}

TEST(UnitAngle, Standard) {
  EXPECT_EQ(Standard<ElectricCharge>, ElectricCharge::Coulomb);
}

TEST(UnitAngle, Stream) {
  std::ostringstream stream;
  stream << ElectricCharge::Coulomb;
  EXPECT_EQ(stream.str(), Abbreviation(ElectricCharge::Coulomb));
}

}  // namespace

}  // namespace PhQ::Unit
