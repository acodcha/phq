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

#include "../../include/PhQ/Unit/Diffusivity.hpp"

#include <gtest/gtest.h>

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Diffusivity, 14> Units = {
    Diffusivity::SquareMilePerSecond,
    Diffusivity::SquareKilometrePerSecond,
    Diffusivity::HectarePerSecond,
    Diffusivity::AcrePerSecond,
    Diffusivity::SquareYardPerSecond,
    Diffusivity::SquareMetrePerSecond,
    Diffusivity::SquareFootPerSecond,
    Diffusivity::SquareDecimetrePerSecond,
    Diffusivity::SquareInchPerSecond,
    Diffusivity::SquareCentimetrePerSecond,
    Diffusivity::SquareMillimetrePerSecond,
    Diffusivity::SquareMilliinchPerSecond,
    Diffusivity::SquareMicrometrePerSecond,
    Diffusivity::SquareMicroinchPerSecond,
};

TEST(UnitDiffusivity, Abbreviation) {
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMilePerSecond), "mi^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareKilometrePerSecond), "km^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::HectarePerSecond), "ha/s");
  EXPECT_EQ(Abbreviation(Diffusivity::AcrePerSecond), "ac/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareYardPerSecond), "yd^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMetrePerSecond), "m^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareFootPerSecond), "ft^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareDecimetrePerSecond), "dm^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareInchPerSecond), "in^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareCentimetrePerSecond), "cm^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMillimetrePerSecond), "mm^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMilliinchPerSecond), "mil^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMicrometrePerSecond), "μm^2/s");
  EXPECT_EQ(Abbreviation(Diffusivity::SquareMicroinchPerSecond), "μin^2/s");
}

TEST(UnitDiffusivity, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Diffusivity>(UnitSystem::MetreKilogramSecondKelvin),
            Diffusivity::SquareMetrePerSecond);
  EXPECT_EQ(ConsistentUnit<Diffusivity>(UnitSystem::MillimetreGramSecondKelvin),
            Diffusivity::SquareMillimetrePerSecond);
  EXPECT_EQ(ConsistentUnit<Diffusivity>(UnitSystem::FootPoundSecondRankine),
            Diffusivity::SquareFootPerSecond);
  EXPECT_EQ(ConsistentUnit<Diffusivity>(UnitSystem::InchPoundSecondRankine),
            Diffusivity::SquareInchPerSecond);
}

TEST(UnitDiffusivity, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareMilePerSecond),
                   value / std::pow(1609.344, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareKilometrePerSecond),
                   value * std::pow(0.001, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::HectarePerSecond),
                   value * 0.0001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::AcrePerSecond),
                   value * 640.0 / std::pow(1609.344, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareYardPerSecond),
                   value / std::pow(0.9144, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareFootPerSecond),
                   value / std::pow(0.3048, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareDecimetrePerSecond),
                   value * std::pow(10.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareInchPerSecond),
                   value / std::pow(0.0254, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareCentimetrePerSecond),
                   value * std::pow(100.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareMillimetrePerSecond),
                   value * std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareMilliinchPerSecond),
                   value / std::pow(0.0000254, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareMicrometrePerSecond),
                   value * std::pow(1000000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareMicroinchPerSecond),
                   value / std::pow(0.0000000254, 2));
}

TEST(UnitDiffusivity, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMilePerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(1609.344, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareKilometrePerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(1000.0, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::HectarePerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * 10000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::AcrePerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(1609.344, 2) / 640.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareYardPerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(0.9144, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMetrePerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareFootPerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(0.3048, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareDecimetrePerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(0.1, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareInchPerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(0.0254, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareCentimetrePerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(0.01, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMillimetrePerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(0.001, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMilliinchPerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(0.0000254, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMicrometrePerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(0.000001, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Diffusivity::SquareMicroinchPerSecond,
                               Diffusivity::SquareMetrePerSecond),
                   value * std::pow(0.0000000254, 2));
}

TEST(UnitDiffusivity, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Diffusivity old_unit : Units) {
    for (const Diffusivity new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitDiffusivity, DimensionSet) {
  EXPECT_EQ(Dimensions<Diffusivity>,
            Dimension::Set(Dimension::Time{-1}, Dimension::Length{2}));
}

TEST(UnitDiffusivity, Parse) {
  EXPECT_EQ(Parse<Diffusivity>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Diffusivity>("mi^2/s"), Diffusivity::SquareMilePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("km^2/s"),
            Diffusivity::SquareKilometrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("ha/s"), Diffusivity::HectarePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("ac/s"), Diffusivity::AcrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("yd^2/s"), Diffusivity::SquareYardPerSecond);
  EXPECT_EQ(Parse<Diffusivity>("m^2/s"), Diffusivity::SquareMetrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("ft^2/s"), Diffusivity::SquareFootPerSecond);
  EXPECT_EQ(Parse<Diffusivity>("dm^2/s"),
            Diffusivity::SquareDecimetrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("in^2/s"), Diffusivity::SquareInchPerSecond);
  EXPECT_EQ(Parse<Diffusivity>("cm^2/s"),
            Diffusivity::SquareCentimetrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("mm^2/s"),
            Diffusivity::SquareMillimetrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("mil^2/s"),
            Diffusivity::SquareMilliinchPerSecond);
  EXPECT_EQ(Parse<Diffusivity>("μm^2/s"),
            Diffusivity::SquareMicrometrePerSecond);
  EXPECT_EQ(Parse<Diffusivity>("μin^2/s"),
            Diffusivity::SquareMicroinchPerSecond);
}

TEST(UnitDiffusivity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareMilePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareKilometrePerSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::HectarePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::AcrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareYardPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareMetrePerSecond),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareFootPerSecond),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareDecimetrePerSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareInchPerSecond),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareCentimetrePerSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareMillimetrePerSecond),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareMilliinchPerSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareMicrometrePerSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Diffusivity::SquareMicroinchPerSecond),
            std::nullopt);
}

TEST(UnitDiffusivity, StandardUnit) {
  EXPECT_EQ(StandardUnit<Diffusivity>, Diffusivity::SquareMetrePerSecond);
}

}  // namespace

}  // namespace PhQ::Unit
