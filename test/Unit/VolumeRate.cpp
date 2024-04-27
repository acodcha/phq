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

#include "../../include/PhQ/Unit/VolumeRate.hpp"

#include <array>
#include <cmath>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<VolumeRate, 45> Units = {
    VolumeRate::CubicNauticalMilePerSecond,
    VolumeRate::CubicMilePerSecond,
    VolumeRate::CubicKilometrePerSecond,
    VolumeRate::CubicMetrePerSecond,
    VolumeRate::CubicYardPerSecond,
    VolumeRate::CubicFootPerSecond,
    VolumeRate::CubicDecimetrePerSecond,
    VolumeRate::LitrePerSecond,
    VolumeRate::CubicInchPerSecond,
    VolumeRate::CubicCentimetrePerSecond,
    VolumeRate::MillilitrePerSecond,
    VolumeRate::CubicMillimetrePerSecond,
    VolumeRate::CubicMilliinchPerSecond,
    VolumeRate::CubicMicrometrePerSecond,
    VolumeRate::CubicMicroinchPerSecond,
    VolumeRate::CubicNauticalMilePerMinute,
    VolumeRate::CubicMilePerMinute,
    VolumeRate::CubicKilometrePerMinute,
    VolumeRate::CubicMetrePerMinute,
    VolumeRate::CubicYardPerMinute,
    VolumeRate::CubicFootPerMinute,
    VolumeRate::CubicDecimetrePerMinute,
    VolumeRate::LitrePerMinute,
    VolumeRate::CubicInchPerMinute,
    VolumeRate::CubicCentimetrePerMinute,
    VolumeRate::MillilitrePerMinute,
    VolumeRate::CubicMillimetrePerMinute,
    VolumeRate::CubicMilliinchPerMinute,
    VolumeRate::CubicMicrometrePerMinute,
    VolumeRate::CubicMicroinchPerMinute,
    VolumeRate::CubicNauticalMilePerHour,
    VolumeRate::CubicMilePerHour,
    VolumeRate::CubicKilometrePerHour,
    VolumeRate::CubicMetrePerHour,
    VolumeRate::CubicYardPerHour,
    VolumeRate::CubicFootPerHour,
    VolumeRate::CubicDecimetrePerHour,
    VolumeRate::LitrePerHour,
    VolumeRate::CubicInchPerHour,
    VolumeRate::CubicCentimetrePerHour,
    VolumeRate::MillilitrePerHour,
    VolumeRate::CubicMillimetrePerHour,
    VolumeRate::CubicMilliinchPerHour,
    VolumeRate::CubicMicrometrePerHour,
    VolumeRate::CubicMicroinchPerHour,
};

TEST(UnitVolumeRate, Abbreviation) {
  EXPECT_EQ(Abbreviation(VolumeRate::CubicNauticalMilePerSecond), "nmi^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMilePerSecond), "mi^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicKilometrePerSecond), "km^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMetrePerSecond), "m^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicYardPerSecond), "yd^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicFootPerSecond), "ft^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicDecimetrePerSecond), "dm^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::LitrePerSecond), "L/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicInchPerSecond), "in^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicCentimetrePerSecond), "cm^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::MillilitrePerSecond), "mL/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMillimetrePerSecond), "mm^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMilliinchPerSecond), "mil^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMicrometrePerSecond), "μm^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMicroinchPerSecond), "μin^3/s");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicNauticalMilePerMinute), "nmi^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMilePerMinute), "mi^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicKilometrePerMinute), "km^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMetrePerMinute), "m^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicYardPerMinute), "yd^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicFootPerMinute), "ft^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicDecimetrePerMinute), "dm^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::LitrePerMinute), "L/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicInchPerMinute), "in^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicCentimetrePerMinute), "cm^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::MillilitrePerMinute), "mL/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMillimetrePerMinute), "mm^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMilliinchPerMinute), "mil^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMicrometrePerMinute), "μm^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMicroinchPerMinute), "μin^3/min");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicNauticalMilePerHour), "nmi^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMilePerHour), "mi^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicKilometrePerHour), "km^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMetrePerHour), "m^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicYardPerHour), "yd^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicFootPerHour), "ft^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicDecimetrePerHour), "dm^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::LitrePerHour), "L/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicInchPerHour), "in^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicCentimetrePerHour), "cm^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::MillilitrePerHour), "mL/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMillimetrePerHour), "mm^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMilliinchPerHour), "mil^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMicrometrePerHour), "μm^3/hr");
  EXPECT_EQ(Abbreviation(VolumeRate::CubicMicroinchPerHour), "μin^3/hr");
}

TEST(UnitVolumeRate, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<VolumeRate>(UnitSystem::MetreKilogramSecondKelvin),
            VolumeRate::CubicMetrePerSecond);
  EXPECT_EQ(ConsistentUnit<VolumeRate>(UnitSystem::MillimetreGramSecondKelvin),
            VolumeRate::CubicMillimetrePerSecond);
  EXPECT_EQ(ConsistentUnit<VolumeRate>(UnitSystem::FootPoundSecondRankine),
            VolumeRate::CubicFootPerSecond);
  EXPECT_EQ(ConsistentUnit<VolumeRate>(UnitSystem::InchPoundSecondRankine),
            VolumeRate::CubicInchPerSecond);
}

TEST(UnitVolumeRate, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const VolumeRate original_unit : Units) {
    for (const VolumeRate intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitVolumeRate, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicNauticalMilePerSecond,
                            value, value / std::pow(1852.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilePerSecond, value,
                            value / std::pow(1609.344, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicKilometrePerSecond,
                            value, value * std::pow(0.001, 3));
  Internal::TestConversions(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMetrePerSecond, value, value);
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicYardPerSecond, value,
                            value / std::pow(0.9144, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicFootPerSecond, value,
                            value / std::pow(0.3048, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicDecimetrePerSecond,
                            value, value * std::pow(10.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::LitrePerSecond, value,
                            value * std::pow(10.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicInchPerSecond, value,
                            value / std::pow(0.0254, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicCentimetrePerSecond,
                            value, value * std::pow(100.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::MillilitrePerSecond, value,
                            value * std::pow(100.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMillimetrePerSecond,
                            value, value * std::pow(1000.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilliinchPerSecond,
                            value, value / std::pow(0.0000254, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicrometrePerSecond,
                            value, value * std::pow(1000000.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicroinchPerSecond,
                            value, value / std::pow(0.0000000254, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicNauticalMilePerMinute,
                            value, value * 60.0 / std::pow(1852.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilePerMinute, value,
                            value * 60.0 / std::pow(1609.344, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicKilometrePerMinute,
                            value, value * 60.0 * std::pow(0.001, 3));
  Internal::TestConversions(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMetrePerMinute, value, value * 60.0);
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicYardPerMinute, value,
                            value * 60.0 / std::pow(0.9144, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicFootPerMinute, value,
                            value * 60.0 / std::pow(0.3048, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicDecimetrePerMinute,
                            value, value * 60.0 * std::pow(10.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::LitrePerMinute, value,
                            value * 60.0 * std::pow(10.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicInchPerMinute, value,
                            value * 60.0 / std::pow(0.0254, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicCentimetrePerMinute,
                            value, value * 60.0 * std::pow(100.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::MillilitrePerMinute, value,
                            value * 60.0 * std::pow(100.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMillimetrePerMinute,
                            value, value * 60.0 * std::pow(1000.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilliinchPerMinute,
                            value, value * 60.0 / std::pow(0.0000254, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicrometrePerMinute,
                            value, value * 60.0 * std::pow(1000000.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicroinchPerMinute,
                            value, value * 60.0 / std::pow(0.0000000254, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicNauticalMilePerHour,
                            value, value * 3600.0 / std::pow(1852.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilePerHour, value,
                            value * 3600.0 / std::pow(1609.344, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicKilometrePerHour,
                            value, value * 3600.0 * std::pow(0.001, 3));
  Internal::TestConversions(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMetrePerHour, value, value * 3600.0);
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicYardPerHour, value,
                            value * 3600.0 / std::pow(0.9144, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicFootPerHour, value,
                            value * 3600.0 / std::pow(0.3048, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicDecimetrePerHour,
                            value, value * 3600.0 * std::pow(10.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::LitrePerHour, value,
                            value * 3600.0 * std::pow(10.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicInchPerHour, value,
                            value * 3600.0 / std::pow(0.0254, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicCentimetrePerHour,
                            value, value * 3600.0 * std::pow(100.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::MillilitrePerHour, value,
                            value * 3600.0 * std::pow(100.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMillimetrePerHour,
                            value, value * 3600.0 * std::pow(1000.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilliinchPerHour,
                            value, value * 3600.0 / std::pow(0.0000254, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicrometrePerHour,
                            value, value * 3600.0 * std::pow(1000000.0, 3));
  Internal::TestConversions(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicroinchPerHour,
                            value, value * 3600.0 / std::pow(0.0000000254, 3));

  Internal::TestStaticConversions<VolumeRate, VolumeRate::CubicMetrePerSecond,
                                  VolumeRate::CubicFootPerSecond>(
      value, value / std::pow(0.3048, 3));
}

TEST(UnitVolumeRate, ConvertToStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(VolumeRate::CubicNauticalMilePerSecond, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(1852.0, 3));
  Internal::TestConversions(VolumeRate::CubicMilePerSecond, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(1609.344, 3));
  Internal::TestConversions(VolumeRate::CubicKilometrePerSecond, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(1000.0, 3));
  Internal::TestConversions(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMetrePerSecond, value, value);
  Internal::TestConversions(VolumeRate::CubicYardPerSecond, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.9144, 3));
  Internal::TestConversions(VolumeRate::CubicFootPerSecond, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.3048, 3));
  Internal::TestConversions(VolumeRate::CubicDecimetrePerSecond, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.1, 3));
  Internal::TestConversions(
      VolumeRate::LitrePerSecond, VolumeRate::CubicMetrePerSecond, value, value * std::pow(0.1, 3));
  Internal::TestConversions(VolumeRate::CubicInchPerSecond, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.0254, 3));
  Internal::TestConversions(VolumeRate::CubicCentimetrePerSecond, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.01, 3));
  Internal::TestConversions(VolumeRate::MillilitrePerSecond, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.01, 3));
  Internal::TestConversions(VolumeRate::CubicMillimetrePerSecond, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.001, 3));
  Internal::TestConversions(VolumeRate::CubicMilliinchPerSecond, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.0000254, 3));
  Internal::TestConversions(VolumeRate::CubicMicrometrePerSecond, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.000001, 3));
  Internal::TestConversions(VolumeRate::CubicMicroinchPerSecond, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.0000000254, 3));
  Internal::TestConversions(VolumeRate::CubicNauticalMilePerMinute, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(1852.0, 3) / 60.0);
  Internal::TestConversions(VolumeRate::CubicMilePerMinute, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(1609.344, 3) / 60.0);
  Internal::TestConversions(VolumeRate::CubicKilometrePerMinute, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(1000.0, 3) / 60.0);
  Internal::TestConversions(
      VolumeRate::CubicMetrePerMinute, VolumeRate::CubicMetrePerSecond, value, value / 60.0);
  Internal::TestConversions(VolumeRate::CubicYardPerMinute, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.9144, 3) / 60.0);
  Internal::TestConversions(VolumeRate::CubicFootPerMinute, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.3048, 3) / 60.0);
  Internal::TestConversions(VolumeRate::CubicDecimetrePerMinute, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.1, 3) / 60.0);
  Internal::TestConversions(VolumeRate::LitrePerMinute, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.1, 3) / 60.0);
  Internal::TestConversions(VolumeRate::CubicInchPerMinute, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.0254, 3) / 60.0);
  Internal::TestConversions(VolumeRate::CubicCentimetrePerMinute, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.01, 3) / 60.0);
  Internal::TestConversions(VolumeRate::MillilitrePerMinute, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.01, 3) / 60.0);
  Internal::TestConversions(VolumeRate::CubicMillimetrePerMinute, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.001, 3) / 60.0);
  Internal::TestConversions(VolumeRate::CubicMilliinchPerMinute, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.0000254, 3) / 60.0);
  Internal::TestConversions(VolumeRate::CubicMicrometrePerMinute, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.000001, 3) / 60.0);
  Internal::TestConversions(VolumeRate::CubicMicroinchPerMinute, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.0000000254, 3) / 60.0);
  Internal::TestConversions(VolumeRate::CubicNauticalMilePerHour, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(1852.0, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::CubicMilePerHour, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(1609.344, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::CubicKilometrePerHour, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(1000.0, 3) / 3600.0);
  Internal::TestConversions(
      VolumeRate::CubicMetrePerHour, VolumeRate::CubicMetrePerSecond, value, value / 3600.0);
  Internal::TestConversions(VolumeRate::CubicYardPerHour, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.9144, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::CubicFootPerHour, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.3048, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::CubicDecimetrePerHour, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.1, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::LitrePerHour, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.1, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::CubicInchPerHour, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.0254, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::CubicCentimetrePerHour, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.01, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::MillilitrePerHour, VolumeRate::CubicMetrePerSecond, value,
                            value * std::pow(0.01, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::CubicMillimetrePerHour, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.001, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::CubicMilliinchPerHour, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.0000254, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::CubicMicrometrePerHour, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.000001, 3) / 3600.0);
  Internal::TestConversions(VolumeRate::CubicMicroinchPerHour, VolumeRate::CubicMetrePerSecond,
                            value, value * std::pow(0.0000000254, 3) / 3600.0);

  Internal::TestStaticConversions<VolumeRate, VolumeRate::CubicFootPerSecond,
                                  VolumeRate::CubicMetrePerSecond>(
      value, value * std::pow(0.3048, 3));
}

TEST(UnitVolumeRate, Parse) {
  EXPECT_EQ(Parse<VolumeRate>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<VolumeRate>("nmi^3/s"), VolumeRate::CubicNauticalMilePerSecond);
  EXPECT_EQ(Parse<VolumeRate>("mi^3/s"), VolumeRate::CubicMilePerSecond);
  EXPECT_EQ(Parse<VolumeRate>("km^3/s"), VolumeRate::CubicKilometrePerSecond);
  EXPECT_EQ(Parse<VolumeRate>("m^3/s"), VolumeRate::CubicMetrePerSecond);
  EXPECT_EQ(Parse<VolumeRate>("yd^3/s"), VolumeRate::CubicYardPerSecond);
  EXPECT_EQ(Parse<VolumeRate>("ft^3/s"), VolumeRate::CubicFootPerSecond);
  EXPECT_EQ(Parse<VolumeRate>("dm^3/s"), VolumeRate::CubicDecimetrePerSecond);
  EXPECT_EQ(Parse<VolumeRate>("L/s"), VolumeRate::LitrePerSecond);
  EXPECT_EQ(Parse<VolumeRate>("in^3/s"), VolumeRate::CubicInchPerSecond);
  EXPECT_EQ(Parse<VolumeRate>("cm^3/s"), VolumeRate::CubicCentimetrePerSecond);
  EXPECT_EQ(Parse<VolumeRate>("mL/s"), VolumeRate::MillilitrePerSecond);
  EXPECT_EQ(Parse<VolumeRate>("mm^3/s"), VolumeRate::CubicMillimetrePerSecond);
  EXPECT_EQ(Parse<VolumeRate>("mil^3/s"), VolumeRate::CubicMilliinchPerSecond);
  EXPECT_EQ(Parse<VolumeRate>("μm^3/s"), VolumeRate::CubicMicrometrePerSecond);
  EXPECT_EQ(Parse<VolumeRate>("μin^3/s"), VolumeRate::CubicMicroinchPerSecond);
  EXPECT_EQ(Parse<VolumeRate>("nmi^3/min"), VolumeRate::CubicNauticalMilePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("mi^3/min"), VolumeRate::CubicMilePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("km^3/min"), VolumeRate::CubicKilometrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("m^3/min"), VolumeRate::CubicMetrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("yd^3/min"), VolumeRate::CubicYardPerMinute);
  EXPECT_EQ(Parse<VolumeRate>("ft^3/min"), VolumeRate::CubicFootPerMinute);
  EXPECT_EQ(Parse<VolumeRate>("dm^3/min"), VolumeRate::CubicDecimetrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("L/min"), VolumeRate::LitrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("in^3/min"), VolumeRate::CubicInchPerMinute);
  EXPECT_EQ(Parse<VolumeRate>("cm^3/min"), VolumeRate::CubicCentimetrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("mL/min"), VolumeRate::MillilitrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("mm^3/min"), VolumeRate::CubicMillimetrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("mil^3/min"), VolumeRate::CubicMilliinchPerMinute);
  EXPECT_EQ(Parse<VolumeRate>("μm^3/min"), VolumeRate::CubicMicrometrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("μin^3/min"), VolumeRate::CubicMicroinchPerMinute);
  EXPECT_EQ(Parse<VolumeRate>("nmi^3/hr"), VolumeRate::CubicNauticalMilePerHour);
  EXPECT_EQ(Parse<VolumeRate>("mi^3/hr"), VolumeRate::CubicMilePerHour);
  EXPECT_EQ(Parse<VolumeRate>("km^3/hr"), VolumeRate::CubicKilometrePerHour);
  EXPECT_EQ(Parse<VolumeRate>("m^3/hr"), VolumeRate::CubicMetrePerHour);
  EXPECT_EQ(Parse<VolumeRate>("yd^3/hr"), VolumeRate::CubicYardPerHour);
  EXPECT_EQ(Parse<VolumeRate>("ft^3/hr"), VolumeRate::CubicFootPerHour);
  EXPECT_EQ(Parse<VolumeRate>("dm^3/hr"), VolumeRate::CubicDecimetrePerHour);
  EXPECT_EQ(Parse<VolumeRate>("L/hr"), VolumeRate::LitrePerHour);
  EXPECT_EQ(Parse<VolumeRate>("in^3/hr"), VolumeRate::CubicInchPerHour);
  EXPECT_EQ(Parse<VolumeRate>("cm^3/hr"), VolumeRate::CubicCentimetrePerHour);
  EXPECT_EQ(Parse<VolumeRate>("mL/hr"), VolumeRate::MillilitrePerHour);
  EXPECT_EQ(Parse<VolumeRate>("mm^3/hr"), VolumeRate::CubicMillimetrePerHour);
  EXPECT_EQ(Parse<VolumeRate>("mil^3/hr"), VolumeRate::CubicMilliinchPerHour);
  EXPECT_EQ(Parse<VolumeRate>("μm^3/hr"), VolumeRate::CubicMicrometrePerHour);
  EXPECT_EQ(Parse<VolumeRate>("μin^3/hr"), VolumeRate::CubicMicroinchPerHour);
}

TEST(UnitVolumeRate, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<VolumeRate>, Dimensions(Dimension::Time{-1}, Dimension::Length{3}));
}

TEST(UnitVolumeRate, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicNauticalMilePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicKilometrePerSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicMetrePerSecond), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicYardPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicFootPerSecond), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicDecimetrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::LitrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicInchPerSecond), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicCentimetrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::MillilitrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMillimetrePerSecond),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilliinchPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMicrometrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMicroinchPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicNauticalMilePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicKilometrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMetrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicYardPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicFootPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicDecimetrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::LitrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicInchPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicCentimetrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::MillilitrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMillimetrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilliinchPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMicrometrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMicroinchPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicNauticalMilePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicKilometrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicYardPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicFootPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicDecimetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::LitrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicInchPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicCentimetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::MillilitrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMillimetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilliinchPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMicrometrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMicroinchPerHour), std::nullopt);
}

TEST(UnitVolumeRate, Standard) {
  EXPECT_EQ(Standard<VolumeRate>, VolumeRate::CubicMetrePerSecond);
}

TEST(UnitVolumeRate, Stream) {
  std::ostringstream stream;
  stream << VolumeRate::CubicMetrePerSecond;
  EXPECT_EQ(stream.str(), Abbreviation(VolumeRate::CubicMetrePerSecond));
}

}  // namespace

}  // namespace PhQ::Unit
