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

#include "../../include/PhQ/Unit/MassRate.hpp"

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

constexpr std::array<MassRate, 15> Units = {
    MassRate::KilogramPerSecond, MassRate::GramPerSecond,   MassRate::SlugPerSecond,
    MassRate::SlinchPerSecond,   MassRate::PoundPerSecond,  MassRate::KilogramPerMinute,
    MassRate::GramPerMinute,     MassRate::SlugPerMinute,   MassRate::SlinchPerMinute,
    MassRate::PoundPerMinute,    MassRate::KilogramPerHour, MassRate::GramPerHour,
    MassRate::SlugPerHour,       MassRate::SlinchPerHour,   MassRate::PoundPerHour,
};

TEST(UnitMassRate, Abbreviation) {
  EXPECT_EQ(Abbreviation(MassRate::KilogramPerSecond), "kg/s");
  EXPECT_EQ(Abbreviation(MassRate::GramPerSecond), "g/s");
  EXPECT_EQ(Abbreviation(MassRate::SlugPerSecond), "slug/s");
  EXPECT_EQ(Abbreviation(MassRate::SlinchPerSecond), "slinch/s");
  EXPECT_EQ(Abbreviation(MassRate::PoundPerSecond), "lbm/s");
  EXPECT_EQ(Abbreviation(MassRate::KilogramPerMinute), "kg/min");
  EXPECT_EQ(Abbreviation(MassRate::GramPerMinute), "g/min");
  EXPECT_EQ(Abbreviation(MassRate::SlugPerMinute), "slug/min");
  EXPECT_EQ(Abbreviation(MassRate::SlinchPerMinute), "slinch/min");
  EXPECT_EQ(Abbreviation(MassRate::PoundPerMinute), "lbm/min");
  EXPECT_EQ(Abbreviation(MassRate::KilogramPerHour), "kg/hr");
  EXPECT_EQ(Abbreviation(MassRate::GramPerHour), "g/hr");
  EXPECT_EQ(Abbreviation(MassRate::SlugPerHour), "slug/hr");
  EXPECT_EQ(Abbreviation(MassRate::SlinchPerHour), "slinch/hr");
  EXPECT_EQ(Abbreviation(MassRate::PoundPerHour), "lbm/hr");
}

TEST(UnitMassRate, ConsistentUnit) {
  EXPECT_EQ(
      ConsistentUnit<MassRate>(UnitSystem::MetreKilogramSecondKelvin), MassRate::KilogramPerSecond);
  EXPECT_EQ(
      ConsistentUnit<MassRate>(UnitSystem::MillimetreGramSecondKelvin), MassRate::GramPerSecond);
  EXPECT_EQ(ConsistentUnit<MassRate>(UnitSystem::FootPoundSecondRankine), MassRate::SlugPerSecond);
  EXPECT_EQ(
      ConsistentUnit<MassRate>(UnitSystem::InchPoundSecondRankine), MassRate::SlinchPerSecond);
}

TEST(UnitMassRate, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const MassRate original_unit : Units) {
    for (const MassRate intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitMassRate, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(MassRate::KilogramPerSecond, MassRate::KilogramPerSecond, value, value);
  Internal::TestConversions(
      MassRate::KilogramPerSecond, MassRate::GramPerSecond, value, value * 1000.0);
  Internal::TestConversions(MassRate::KilogramPerSecond, MassRate::SlugPerSecond, value,
                            value * 0.3048 / (0.45359237 * 9.80665));
  Internal::TestConversions(MassRate::KilogramPerSecond, MassRate::SlinchPerSecond, value,
                            value * 0.0254 / (0.45359237 * 9.80665));
  Internal::TestConversions(
      MassRate::KilogramPerSecond, MassRate::PoundPerSecond, value, value / 0.45359237);
  Internal::TestConversions(
      MassRate::KilogramPerSecond, MassRate::KilogramPerMinute, value, value * 60.0);
  Internal::TestConversions(
      MassRate::KilogramPerSecond, MassRate::GramPerMinute, value, value * 60000.0);
  Internal::TestConversions(MassRate::KilogramPerSecond, MassRate::SlugPerMinute, value,
                            value * 60.0 * 0.3048 / (0.45359237 * 9.80665));
  Internal::TestConversions(MassRate::KilogramPerSecond, MassRate::SlinchPerMinute, value,
                            value * 60.0 * 0.0254 / (0.45359237 * 9.80665));
  Internal::TestConversions(
      MassRate::KilogramPerSecond, MassRate::PoundPerMinute, value, value * 60.0 / 0.45359237);
  Internal::TestConversions(
      MassRate::KilogramPerSecond, MassRate::KilogramPerHour, value, value * 3600.0);
  Internal::TestConversions(
      MassRate::KilogramPerSecond, MassRate::GramPerHour, value, value * 3600000.0);
  Internal::TestConversions(MassRate::KilogramPerSecond, MassRate::SlugPerHour, value,
                            value * 3600.0 * 0.3048 / (0.45359237 * 9.80665));
  Internal::TestConversions(MassRate::KilogramPerSecond, MassRate::SlinchPerHour, value,
                            value * 3600.0 * 0.0254 / (0.45359237 * 9.80665));
  Internal::TestConversions(
      MassRate::KilogramPerSecond, MassRate::PoundPerHour, value, value * 3600.0 / 0.45359237);

  Internal::TestStaticConversions<MassRate, MassRate::KilogramPerSecond, MassRate::SlugPerSecond>(
      value, value * 0.3048 / (0.45359237 * 9.80665));
}

TEST(UnitMassRate, ConvertToStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(MassRate::KilogramPerSecond, MassRate::KilogramPerSecond, value, value);
  Internal::TestConversions(
      MassRate::GramPerSecond, MassRate::KilogramPerSecond, value, value * 0.001);
  Internal::TestConversions(MassRate::SlugPerSecond, MassRate::KilogramPerSecond, value,
                            value * 0.45359237 * 9.80665 / 0.3048);
  Internal::TestConversions(MassRate::SlinchPerSecond, MassRate::KilogramPerSecond, value,
                            value * 0.45359237 * 9.80665 / 0.0254);
  Internal::TestConversions(
      MassRate::PoundPerSecond, MassRate::KilogramPerSecond, value, value * 0.45359237);
  Internal::TestConversions(
      MassRate::KilogramPerMinute, MassRate::KilogramPerSecond, value, value / 60.0);
  Internal::TestConversions(
      MassRate::GramPerMinute, MassRate::KilogramPerSecond, value, value / 60000.0);
  Internal::TestConversions(MassRate::SlugPerMinute, MassRate::KilogramPerSecond, value,
                            value * 0.45359237 * 9.80665 / (0.3048 * 60.0));
  Internal::TestConversions(MassRate::SlinchPerMinute, MassRate::KilogramPerSecond, value,
                            value * 0.45359237 * 9.80665 / (0.0254 * 60.0));
  Internal::TestConversions(
      MassRate::PoundPerMinute, MassRate::KilogramPerSecond, value, value * 0.45359237 / 60.0);
  Internal::TestConversions(
      MassRate::KilogramPerHour, MassRate::KilogramPerSecond, value, value / 3600.0);
  Internal::TestConversions(
      MassRate::GramPerHour, MassRate::KilogramPerSecond, value, value / 3600000.0);
  Internal::TestConversions(MassRate::SlugPerHour, MassRate::KilogramPerSecond, value,
                            value * 0.45359237 * 9.80665 / (0.3048 * 3600.0));
  Internal::TestConversions(MassRate::SlinchPerHour, MassRate::KilogramPerSecond, value,
                            value * 0.45359237 * 9.80665 / (0.0254 * 3600.0));
  Internal::TestConversions(
      MassRate::PoundPerHour, MassRate::KilogramPerSecond, value, value * 0.45359237 / 3600.0);

  Internal::TestStaticConversions<MassRate, MassRate::SlugPerSecond, MassRate::KilogramPerSecond>(
      value, value * 0.45359237 * 9.80665 / 0.3048);
}

TEST(UnitMassRate, Parse) {
  EXPECT_EQ(Parse<MassRate>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<MassRate>("kg/s"), MassRate::KilogramPerSecond);
  EXPECT_EQ(Parse<MassRate>("g/s"), MassRate::GramPerSecond);
  EXPECT_EQ(Parse<MassRate>("slug/s"), MassRate::SlugPerSecond);
  EXPECT_EQ(Parse<MassRate>("slinch/s"), MassRate::SlinchPerSecond);
  EXPECT_EQ(Parse<MassRate>("lbm/s"), MassRate::PoundPerSecond);
  EXPECT_EQ(Parse<MassRate>("kg/min"), MassRate::KilogramPerMinute);
  EXPECT_EQ(Parse<MassRate>("g/min"), MassRate::GramPerMinute);
  EXPECT_EQ(Parse<MassRate>("slug/min"), MassRate::SlugPerMinute);
  EXPECT_EQ(Parse<MassRate>("slinch/min"), MassRate::SlinchPerMinute);
  EXPECT_EQ(Parse<MassRate>("lbm/min"), MassRate::PoundPerMinute);
  EXPECT_EQ(Parse<MassRate>("kg/hr"), MassRate::KilogramPerHour);
  EXPECT_EQ(Parse<MassRate>("g/hr"), MassRate::GramPerHour);
  EXPECT_EQ(Parse<MassRate>("slug/hr"), MassRate::SlugPerHour);
  EXPECT_EQ(Parse<MassRate>("slinch/hr"), MassRate::SlinchPerHour);
  EXPECT_EQ(Parse<MassRate>("lbm/hr"), MassRate::PoundPerHour);
}

TEST(UnitMassRate, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<MassRate>,
            Dimensions(Dimension::Time{-1}, Dimension::Length{0}, Dimension::Mass{1}));
}

TEST(UnitMassRate, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(MassRate::KilogramPerSecond), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(MassRate::GramPerSecond), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(MassRate::SlugPerSecond), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(MassRate::SlinchPerSecond), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(MassRate::PoundPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassRate::KilogramPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassRate::GramPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassRate::SlugPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassRate::SlinchPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassRate::PoundPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassRate::KilogramPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassRate::GramPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassRate::SlugPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassRate::SlinchPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassRate::PoundPerHour), std::nullopt);
}

TEST(UnitMassRate, Standard) {
  EXPECT_EQ(Standard<MassRate>, MassRate::KilogramPerSecond);
}

TEST(UnitMassRate, Stream) {
  std::ostringstream stream;
  stream << MassRate::KilogramPerSecond;
  EXPECT_EQ(stream.str(), Abbreviation(MassRate::KilogramPerSecond));
}

}  // namespace

}  // namespace PhQ::Unit
