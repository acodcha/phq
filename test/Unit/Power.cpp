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

#include "../../include/PhQ/Unit/Power.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<Power, 9> Units = {
    Power::Watt,     Power::Milliwatt,          Power::Microwatt,
    Power::Nanowatt, Power::Kilowatt,           Power::Megawatt,
    Power::Gigawatt, Power::FootPoundPerSecond, Power::InchPoundPerSecond,
};

TEST(UnitPower, Abbreviation) {
  EXPECT_EQ(Abbreviation(Power::Watt), "W");
  EXPECT_EQ(Abbreviation(Power::Milliwatt), "mW");
  EXPECT_EQ(Abbreviation(Power::Microwatt), "μW");
  EXPECT_EQ(Abbreviation(Power::Nanowatt), "nW");
  EXPECT_EQ(Abbreviation(Power::Kilowatt), "kW");
  EXPECT_EQ(Abbreviation(Power::Megawatt), "MW");
  EXPECT_EQ(Abbreviation(Power::Gigawatt), "GW");
  EXPECT_EQ(Abbreviation(Power::FootPoundPerSecond), "ft·lbf/s");
  EXPECT_EQ(Abbreviation(Power::InchPoundPerSecond), "in·lbf/s");
}

TEST(UnitPower, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Power>(UnitSystem::MetreKilogramSecondKelvin),
            Power::Watt);
  EXPECT_EQ(ConsistentUnit<Power>(UnitSystem::MillimetreGramSecondKelvin),
            Power::Nanowatt);
  EXPECT_EQ(ConsistentUnit<Power>(UnitSystem::FootPoundSecondRankine),
            Power::FootPoundPerSecond);
  EXPECT_EQ(ConsistentUnit<Power>(UnitSystem::InchPoundSecondRankine),
            Power::InchPoundPerSecond);
}

TEST(UnitPower, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Power::Watt, Power::Watt), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Watt, Power::Milliwatt), value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Watt, Power::Microwatt), value * 1000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Watt, Power::Nanowatt), value * 1000000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Watt, Power::Kilowatt), value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Watt, Power::Megawatt), value * 0.000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Watt, Power::Gigawatt), value * 0.000000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Power::Watt, Power::FootPoundPerSecond),
                   value / (0.3048 * 0.45359237 * 9.80665));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Power::Watt, Power::InchPoundPerSecond),
                   value / (0.0254 * 0.45359237 * 9.80665));
}

TEST(UnitPower, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Power::Watt, Power::Watt), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Milliwatt, Power::Watt), value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Microwatt, Power::Watt), value * 0.000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Nanowatt, Power::Watt), value * 0.000000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Kilowatt, Power::Watt), value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Megawatt, Power::Watt), value * 1000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Power::Gigawatt, Power::Watt), value * 1000000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Power::FootPoundPerSecond, Power::Watt),
                   value * 0.3048 * 0.45359237 * 9.80665);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Power::InchPoundPerSecond, Power::Watt),
                   value * 0.0254 * 0.45359237 * 9.80665);
}

TEST(UnitPower, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Power old_unit : Units) {
    for (const Power new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitPower, Parse) {
  EXPECT_EQ(Parse<Power>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Power>("W"), Power::Watt);
  EXPECT_EQ(Parse<Power>("mW"), Power::Milliwatt);
  EXPECT_EQ(Parse<Power>("μW"), Power::Microwatt);
  EXPECT_EQ(Parse<Power>("nW"), Power::Nanowatt);
  EXPECT_EQ(Parse<Power>("kW"), Power::Kilowatt);
  EXPECT_EQ(Parse<Power>("MW"), Power::Megawatt);
  EXPECT_EQ(Parse<Power>("GW"), Power::Gigawatt);
  EXPECT_EQ(Parse<Power>("ft·lbf/s"), Power::FootPoundPerSecond);
  EXPECT_EQ(Parse<Power>("in·lbf/s"), Power::InchPoundPerSecond);
}

TEST(UnitPower, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Power>,
            Dimensions(
                Dimension::Time{-3}, Dimension::Length{2}, Dimension::Mass{1}));
}

TEST(UnitPower, RelatedUnitSystem) {
  EXPECT_EQ(
      RelatedUnitSystem(Power::Watt), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Power::Milliwatt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Power::Microwatt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Power::Nanowatt),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Power::Kilowatt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Power::Megawatt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Power::Gigawatt), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Power::FootPoundPerSecond),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Power::InchPoundPerSecond),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitPower, Standard) {
  EXPECT_EQ(Standard<Power>, Power::Watt);
}

}  // namespace

}  // namespace PhQ::Unit
