// Copyright 2020 Alexandre Coderre-Chabot
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

#include "../../include/PhQ/Unit/Acceleration.hpp"

#include <gtest/gtest.h>

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Acceleration, 12> Units = {
    Acceleration::MilePerSquareSecond,
    Acceleration::KilometrePerSquareSecond,
    Acceleration::YardPerSquareSecond,
    Acceleration::MetrePerSquareSecond,
    Acceleration::FootPerSquareSecond,
    Acceleration::DecimetrePerSquareSecond,
    Acceleration::InchPerSquareSecond,
    Acceleration::CentimetrePerSquareSecond,
    Acceleration::MillimetrePerSquareSecond,
    Acceleration::MilliinchPerSquareSecond,
    Acceleration::MicrometrePerSquareSecond,
    Acceleration::MicroinchPerSquareSecond,
};

TEST(UnitLength, Abbreviation) {
  EXPECT_EQ(Abbreviation(Acceleration::MilePerSquareSecond), "mi/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::KilometrePerSquareSecond), "km/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::YardPerSquareSecond), "yd/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::MetrePerSquareSecond), "m/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::FootPerSquareSecond), "ft/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::DecimetrePerSquareSecond), "dm/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::InchPerSquareSecond), "in/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::CentimetrePerSquareSecond), "cm/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::MillimetrePerSquareSecond), "mm/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::MilliinchPerSquareSecond), "mil/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::MicrometrePerSquareSecond), "μm/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::MicroinchPerSquareSecond), "μin/s^2");
}

TEST(UnitLength, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Acceleration>(UnitSystem::MetreKilogramSecondKelvin),
            Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(
      ConsistentUnit<Acceleration>(UnitSystem::MillimetreGramSecondKelvin),
      Acceleration::MillimetrePerSquareSecond);
  EXPECT_EQ(ConsistentUnit<Acceleration>(UnitSystem::FootPoundSecondRankine),
            Acceleration::FootPerSquareSecond);
  EXPECT_EQ(ConsistentUnit<Acceleration>(UnitSystem::InchPoundSecondRankine),
            Acceleration::InchPerSquareSecond);
}

TEST(UnitLength, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::MilePerSquareSecond),
                   value / 1609.344);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::KilometrePerSquareSecond),
                   value * 0.001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::YardPerSquareSecond),
                   value / 0.9144);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::FootPerSquareSecond),
                   value / 0.3048);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::DecimetrePerSquareSecond),
                   value * 10.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::InchPerSquareSecond),
                   value / 0.0254);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::CentimetrePerSquareSecond),
                   value * 100.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::MillimetrePerSquareSecond),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::MilliinchPerSquareSecond),
                   value / 0.0000254);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::MicrometrePerSquareSecond),
                   value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::MicroinchPerSquareSecond),
                   value / 0.0000000254);
}

TEST(UnitLength, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MilePerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value * 1609.344);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::KilometrePerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::YardPerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value * 0.9144);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MetrePerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::FootPerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value * 0.3048);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::DecimetrePerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value * 0.1);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::InchPerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value * 0.0254);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::CentimetrePerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value * 0.01);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MillimetrePerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value * 0.001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MilliinchPerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value * 0.0000254);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MicrometrePerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value * 0.000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Acceleration::MicroinchPerSquareSecond,
                               Acceleration::MetrePerSquareSecond),
                   value * 0.0000000254);
}

TEST(UnitLength, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Acceleration old_unit : Units) {
    for (const Acceleration new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitLength, DimensionSet) {
  EXPECT_EQ(Dimensions<Acceleration>,
            Dimension::Set(Dimension::Time{-2}, Dimension::Length{1}));
}

TEST(UnitLength, Parse) {
  EXPECT_EQ(Parse<Acceleration>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Acceleration>("mi/s^2"), Acceleration::MilePerSquareSecond);
  EXPECT_EQ(Parse<Acceleration>("km/s^2"),
            Acceleration::KilometrePerSquareSecond);
  EXPECT_EQ(Parse<Acceleration>("yd/s^2"), Acceleration::YardPerSquareSecond);
  EXPECT_EQ(Parse<Acceleration>("m/s^2"), Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(Parse<Acceleration>("ft/s^2"), Acceleration::FootPerSquareSecond);
  EXPECT_EQ(Parse<Acceleration>("dm/s^2"),
            Acceleration::DecimetrePerSquareSecond);
  EXPECT_EQ(Parse<Acceleration>("in/s^2"), Acceleration::InchPerSquareSecond);
  EXPECT_EQ(Parse<Acceleration>("cm/s^2"),
            Acceleration::CentimetrePerSquareSecond);
  EXPECT_EQ(Parse<Acceleration>("mm/s^2"),
            Acceleration::MillimetrePerSquareSecond);
  EXPECT_EQ(Parse<Acceleration>("mil/s^2"),
            Acceleration::MilliinchPerSquareSecond);
  EXPECT_EQ(Parse<Acceleration>("μm/s^2"),
            Acceleration::MicrometrePerSquareSecond);
  EXPECT_EQ(Parse<Acceleration>("μin/s^2"),
            Acceleration::MicroinchPerSquareSecond);
}

TEST(UnitLength, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MilePerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::KilometrePerSquareSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::YardPerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MetrePerSquareSecond),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::FootPerSquareSecond),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::DecimetrePerSquareSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::InchPerSquareSecond),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::CentimetrePerSquareSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MillimetrePerSquareSecond),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MilliinchPerSquareSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MicrometrePerSquareSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MicroinchPerSquareSecond),
            std::nullopt);
}

TEST(UnitLength, StandardUnit) {
  EXPECT_EQ(StandardUnit<Acceleration>, Acceleration::MetrePerSquareSecond);
}

}  // namespace

}  // namespace PhQ::Unit
