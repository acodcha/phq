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

TEST(UnitVolumeRate, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicNauticalMilePerSecond, value,
      value / std::pow(1852.0L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilePerSecond,
                                    value, value / std::pow(1609.344L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicKilometrePerSecond, value,
      value * std::pow(0.001L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMetrePerSecond, value, value);
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicYardPerSecond,
                                    value, value / std::pow(0.9144L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicFootPerSecond,
                                    value, value / std::pow(0.3048L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicDecimetrePerSecond, value,
      value * std::pow(10.0L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::LitrePerSecond,
                                    value, value * std::pow(10.0L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicInchPerSecond,
                                    value, value / std::pow(0.0254L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicCentimetrePerSecond, value,
      value * std::pow(100.0L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::MillilitrePerSecond, value,
      value * std::pow(100.0L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMillimetrePerSecond, value,
      value * std::pow(1000.0L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilliinchPerSecond, value,
      value / std::pow(0.0000254L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicrometrePerSecond, value,
      value * std::pow(1000000.0L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicroinchPerSecond, value,
      value / std::pow(0.0000000254L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicNauticalMilePerMinute, value,
      value * 60.0L / std::pow(1852.0L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilePerMinute,
                                    value, value * 60.0L / std::pow(1609.344L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicKilometrePerMinute, value,
      value * 60.0L * std::pow(0.001L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMetrePerMinute, value, value * 60.0L);
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicYardPerMinute,
                                    value, value * 60.0L / std::pow(0.9144L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicFootPerMinute,
                                    value, value * 60.0L / std::pow(0.3048L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicDecimetrePerMinute, value,
      value * 60.0L * std::pow(10.0L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::LitrePerMinute,
                                    value, value * 60.0L * std::pow(10.0L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicInchPerMinute,
                                    value, value * 60.0L / std::pow(0.0254L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicCentimetrePerMinute, value,
      value * 60.0L * std::pow(100.0L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::MillilitrePerMinute, value,
      value * 60.0L * std::pow(100.0L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMillimetrePerMinute, value,
      value * 60.0L * std::pow(1000.0L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilliinchPerMinute, value,
      value * 60.0L / std::pow(0.0000254L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicrometrePerMinute, value,
      value * 60.0L * std::pow(1000000.0L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicroinchPerMinute, value,
      value * 60.0L / std::pow(0.0000000254L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicNauticalMilePerHour, value,
      value * 3600.0L / std::pow(1852.0L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilePerHour,
                                    value, value * 3600.0L / std::pow(1609.344L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicKilometrePerHour, value,
      value * 3600.0L * std::pow(0.001L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMetrePerHour, value, value * 3600.0L);
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicYardPerHour,
                                    value, value * 3600.0L / std::pow(0.9144L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicFootPerHour,
                                    value, value * 3600.0L / std::pow(0.3048L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicDecimetrePerHour, value,
      value * 3600.0L * std::pow(10.0L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::LitrePerHour,
                                    value, value * 3600.0L * std::pow(10.0L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::CubicInchPerHour,
                                    value, value * 3600.0L / std::pow(0.0254L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicCentimetrePerHour, value,
      value * 3600.0L * std::pow(100.0L, 3));
  Internal::TestConvert<VolumeRate>(VolumeRate::CubicMetrePerSecond, VolumeRate::MillilitrePerHour,
                                    value, value * 3600.0L * std::pow(100.0L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMillimetrePerHour, value,
      value * 3600.0L * std::pow(1000.0L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMilliinchPerHour, value,
      value * 3600.0L / std::pow(0.0000254L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicrometrePerHour, value,
      value * 3600.0L * std::pow(1000000.0L, 3));
  Internal::TestConvert<VolumeRate>(
      VolumeRate::CubicMetrePerSecond, VolumeRate::CubicMicroinchPerHour, value,
      value * 3600.0L / std::pow(0.0000000254L, 3));
}

TEST(UnitVolumeRate, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<VolumeRate, VolumeRate::CubicMetrePerSecond,
                                  VolumeRate::CubicFootPerSecond>(
      value, value / std::pow(0.3048L, 3));
}

TEST(UnitVolumeRate, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<VolumeRate>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("nmi^3/s"), VolumeRate::CubicNauticalMilePerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mi^3/s"), VolumeRate::CubicMilePerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("km^3/s"), VolumeRate::CubicKilometrePerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("m^3/s"), VolumeRate::CubicMetrePerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("yd^3/s"), VolumeRate::CubicYardPerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("ft^3/s"), VolumeRate::CubicFootPerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("dm^3/s"), VolumeRate::CubicDecimetrePerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("L/s"), VolumeRate::LitrePerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("in^3/s"), VolumeRate::CubicInchPerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("cm^3/s"), VolumeRate::CubicCentimetrePerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mL/s"), VolumeRate::MillilitrePerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mm^3/s"), VolumeRate::CubicMillimetrePerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mil^3/s"), VolumeRate::CubicMilliinchPerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("μm^3/s"), VolumeRate::CubicMicrometrePerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("μin^3/s"), VolumeRate::CubicMicroinchPerSecond);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("nmi^3/min"), VolumeRate::CubicNauticalMilePerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mi^3/min"), VolumeRate::CubicMilePerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("km^3/min"), VolumeRate::CubicKilometrePerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("m^3/min"), VolumeRate::CubicMetrePerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("yd^3/min"), VolumeRate::CubicYardPerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("ft^3/min"), VolumeRate::CubicFootPerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("dm^3/min"), VolumeRate::CubicDecimetrePerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("L/min"), VolumeRate::LitrePerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("in^3/min"), VolumeRate::CubicInchPerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("cm^3/min"), VolumeRate::CubicCentimetrePerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mL/min"), VolumeRate::MillilitrePerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mm^3/min"), VolumeRate::CubicMillimetrePerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mil^3/min"), VolumeRate::CubicMilliinchPerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("μm^3/min"), VolumeRate::CubicMicrometrePerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("μin^3/min"), VolumeRate::CubicMicroinchPerMinute);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("nmi^3/hr"), VolumeRate::CubicNauticalMilePerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mi^3/hr"), VolumeRate::CubicMilePerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("km^3/hr"), VolumeRate::CubicKilometrePerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("m^3/hr"), VolumeRate::CubicMetrePerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("yd^3/hr"), VolumeRate::CubicYardPerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("ft^3/hr"), VolumeRate::CubicFootPerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("dm^3/hr"), VolumeRate::CubicDecimetrePerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("L/hr"), VolumeRate::LitrePerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("in^3/hr"), VolumeRate::CubicInchPerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("cm^3/hr"), VolumeRate::CubicCentimetrePerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mL/hr"), VolumeRate::MillilitrePerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mm^3/hr"), VolumeRate::CubicMillimetrePerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("mil^3/hr"), VolumeRate::CubicMilliinchPerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("μm^3/hr"), VolumeRate::CubicMicrometrePerHour);
  EXPECT_EQ(ParseEnumeration<VolumeRate>("μin^3/hr"), VolumeRate::CubicMicroinchPerHour);
}

TEST(UnitVolumeRate, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<VolumeRate>,
            Dimensions(Dimension::Time{-1}, Dimension::Length{3}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
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
