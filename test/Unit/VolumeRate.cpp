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

constexpr std::array<VolumeRate, 14> Units = {
    VolumeRate::CubicMilePerSecond,       VolumeRate::CubicKilometrePerSecond,
    VolumeRate::CubicMetrePerSecond,      VolumeRate::CubicYardPerSecond,
    VolumeRate::CubicFootPerSecond,       VolumeRate::CubicDecimetrePerSecond,
    VolumeRate::LitrePerSecond,           VolumeRate::CubicInchPerSecond,
    VolumeRate::CubicCentimetrePerSecond, VolumeRate::MillilitrePerSecond,
    VolumeRate::CubicMillimetrePerSecond, VolumeRate::CubicMilliinchPerSecond,
    VolumeRate::CubicMicrometrePerSecond, VolumeRate::CubicMicroinchPerSecond,
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

TEST(UnitVolumeRate, DimensionSet) {
  EXPECT_EQ(Dimensions<VolumeRate>,
            Dimension::Set(Dimension::Time{-1}, Dimension::Length{3}));
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
}

TEST(UnitVolumeRate, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicKilometrePerSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMetrePerSecond),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicYardPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicFootPerSecond),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicDecimetrePerSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::LitrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicInchPerSecond),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicCentimetrePerSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::MillilitrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMillimetrePerSecond),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMilliinchPerSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMicrometrePerSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(VolumeRate::CubicMicroinchPerSecond),
            std::nullopt);
}

TEST(UnitVolumeRate, StandardUnit) {
  EXPECT_EQ(StandardUnit<VolumeRate>, VolumeRate::CubicMetrePerSecond);
}

}  // namespace

}  // namespace PhQ::Unit
