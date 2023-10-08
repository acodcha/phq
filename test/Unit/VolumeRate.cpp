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

#include "../../include/PhQ/Unit/VolumeRate.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<VolumeRate, 42> Units = {
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

TEST(UnitVolumeRate, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMilePerSecond),
                   value / std::pow(1609.344, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicKilometrePerSecond),
                   value * std::pow(0.001, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicYardPerSecond),
                   value / std::pow(0.9144, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicFootPerSecond),
                   value / std::pow(0.3048, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicDecimetrePerSecond),
                   value * std::pow(10.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::LitrePerSecond),
                   value * std::pow(10.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicInchPerSecond),
                   value / std::pow(0.0254, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicCentimetrePerSecond),
                   value * std::pow(100.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::MillilitrePerSecond),
                   value * std::pow(100.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMillimetrePerSecond),
                   value * std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMilliinchPerSecond),
                   value / std::pow(0.0000254, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMicrometrePerSecond),
                   value * std::pow(1000000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMicroinchPerSecond),
                   value / std::pow(0.0000000254, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMilePerMinute),
                   value * 60.0 / std::pow(1609.344, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicKilometrePerMinute),
                   value * 60.0 * std::pow(0.001, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMetrePerMinute),
                   value * 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicYardPerMinute),
                   value * 60.0 / std::pow(0.9144, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicFootPerMinute),
                   value * 60.0 / std::pow(0.3048, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicDecimetrePerMinute),
                   value * 60.0 * std::pow(10.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::LitrePerMinute),
                   value * 60.0 * std::pow(10.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicInchPerMinute),
                   value * 60.0 / std::pow(0.0254, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicCentimetrePerMinute),
                   value * 60.0 * std::pow(100.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::MillilitrePerMinute),
                   value * 60.0 * std::pow(100.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMillimetrePerMinute),
                   value * 60.0 * std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMilliinchPerMinute),
                   value * 60.0 / std::pow(0.0000254, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMicrometrePerMinute),
                   value * 60.0 * std::pow(1000000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMicroinchPerMinute),
                   value * 60.0 / std::pow(0.0000000254, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMilePerHour),
                   value * 3600.0 / std::pow(1609.344, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicKilometrePerHour),
                   value * 3600.0 * std::pow(0.001, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMetrePerHour),
                   value * 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicYardPerHour),
                   value * 3600.0 / std::pow(0.9144, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicFootPerHour),
                   value * 3600.0 / std::pow(0.3048, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicDecimetrePerHour),
                   value * 3600.0 * std::pow(10.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::LitrePerHour),
                   value * 3600.0 * std::pow(10.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicInchPerHour),
                   value * 3600.0 / std::pow(0.0254, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicCentimetrePerHour),
                   value * 3600.0 * std::pow(100.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::MillilitrePerHour),
                   value * 3600.0 * std::pow(100.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMillimetrePerHour),
                   value * 3600.0 * std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMilliinchPerHour),
                   value * 3600.0 / std::pow(0.0000254, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMicrometrePerHour),
                   value * 3600.0 * std::pow(1000000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMicroinchPerHour),
                   value * 3600.0 / std::pow(0.0000000254, 3));
}

TEST(UnitVolumeRate, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMilePerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(1609.344, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicKilometrePerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(1000.0, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicYardPerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.9144, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicFootPerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.3048, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicDecimetrePerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.1, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::LitrePerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.1, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicInchPerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.0254, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicCentimetrePerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.01, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::MillilitrePerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.01, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMillimetrePerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.001, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMilliinchPerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.0000254, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMicrometrePerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.000001, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMicroinchPerSecond,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.0000000254, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMilePerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(1609.344, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicKilometrePerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(1000.0, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicYardPerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.9144, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicFootPerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.3048, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicDecimetrePerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.1, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::LitrePerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.1, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicInchPerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.0254, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicCentimetrePerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.01, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::MillilitrePerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.01, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMillimetrePerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.001, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMilliinchPerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.0000254, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMicrometrePerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.000001, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMicroinchPerMinute,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.0000000254, 3) / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMilePerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(1609.344, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicKilometrePerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(1000.0, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMetrePerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicYardPerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.9144, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicFootPerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.3048, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicDecimetrePerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.1, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::LitrePerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.1, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicInchPerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.0254, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicCentimetrePerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.01, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::MillilitrePerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.01, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMillimetrePerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.001, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMilliinchPerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.0000254, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMicrometrePerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.000001, 3) / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, VolumeRate::CubicMicroinchPerHour,
                               VolumeRate::CubicMetrePerSecond),
                   value * std::pow(0.0000000254, 3) / 3600.0);
}

TEST(UnitVolumeRate, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const VolumeRate old_unit : Units) {
    for (const VolumeRate new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitVolumeRate, Parse) {
  EXPECT_EQ(Parse<VolumeRate>("Hello world!"), std::nullopt);
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
  EXPECT_EQ(Parse<VolumeRate>("mi^3/min"), VolumeRate::CubicMilePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("km^3/min"), VolumeRate::CubicKilometrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("m^3/min"), VolumeRate::CubicMetrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("yd^3/min"), VolumeRate::CubicYardPerMinute);
  EXPECT_EQ(Parse<VolumeRate>("ft^3/min"), VolumeRate::CubicFootPerMinute);
  EXPECT_EQ(Parse<VolumeRate>("dm^3/min"), VolumeRate::CubicDecimetrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("L/min"), VolumeRate::LitrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("in^3/min"), VolumeRate::CubicInchPerMinute);
  EXPECT_EQ(
      Parse<VolumeRate>("cm^3/min"), VolumeRate::CubicCentimetrePerMinute);
  EXPECT_EQ(Parse<VolumeRate>("mL/min"), VolumeRate::MillilitrePerMinute);
  EXPECT_EQ(
      Parse<VolumeRate>("mm^3/min"), VolumeRate::CubicMillimetrePerMinute);
  EXPECT_EQ(
      Parse<VolumeRate>("mil^3/min"), VolumeRate::CubicMilliinchPerMinute);
  EXPECT_EQ(
      Parse<VolumeRate>("μm^3/min"), VolumeRate::CubicMicrometrePerMinute);
  EXPECT_EQ(
      Parse<VolumeRate>("μin^3/min"), VolumeRate::CubicMicroinchPerMinute);
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
  EXPECT_EQ(RelatedDimensions<VolumeRate>,
            Dimensions(Dimension::Time{-1}, Dimension::Length{3}));
}

TEST(UnitVolumeRate, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilePerSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicKilometrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMetrePerSecond),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicYardPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicFootPerSecond),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicDecimetrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::LitrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicInchPerSecond),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicCentimetrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::MillilitrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMillimetrePerSecond),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicMilliinchPerSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicMicrometrePerSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicMicroinchPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilePerMinute), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicKilometrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMetrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicYardPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicFootPerMinute), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicDecimetrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::LitrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicInchPerMinute), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicCentimetrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::MillilitrePerMinute), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicMillimetrePerMinute), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicMilliinchPerMinute), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicMicrometrePerMinute), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicMicroinchPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicKilometrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicYardPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicFootPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicDecimetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::LitrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicInchPerHour), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicCentimetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::MillilitrePerHour), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicMillimetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilliinchPerHour), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(VolumeRate::CubicMicrometrePerHour), std::nullopt);
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
