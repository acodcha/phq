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

#include "../../include/PhQ/Unit/ThermalConductivity.hpp"

#include <gtest/gtest.h>

#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<ThermalConductivity, 3> Units = {
    ThermalConductivity::WattPerMetrePerKelvin,
    ThermalConductivity::NanowattPerMillimetrePerKelvin,
    ThermalConductivity::PoundPerSecondPerRankine,
};

TEST(UnitThermalConductivity, Abbreviation) {
  EXPECT_EQ(Abbreviation(ThermalConductivity::WattPerMetrePerKelvin), "W/m/K");
  EXPECT_EQ(Abbreviation(ThermalConductivity::NanowattPerMillimetrePerKelvin),
            "nW/mm/K");
  EXPECT_EQ(
      Abbreviation(ThermalConductivity::PoundPerSecondPerRankine), "lbf/s/°R");
}

TEST(UnitThermalConductivity, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<ThermalConductivity>(
                UnitSystem::MetreKilogramSecondKelvin),
            ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(ConsistentUnit<ThermalConductivity>(
                UnitSystem::MillimetreGramSecondKelvin),
            ThermalConductivity::NanowattPerMillimetrePerKelvin);
  EXPECT_EQ(
      ConsistentUnit<ThermalConductivity>(UnitSystem::FootPoundSecondRankine),
      ThermalConductivity::PoundPerSecondPerRankine);
  EXPECT_EQ(
      ConsistentUnit<ThermalConductivity>(UnitSystem::InchPoundSecondRankine),
      ThermalConductivity::PoundPerSecondPerRankine);
}

TEST(UnitThermalConductivity, ConvertFromStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<
      ThermalConductivity, ThermalConductivity::WattPerMetrePerKelvin,
      ThermalConductivity::WattPerMetrePerKelvin>(value, value);
  Internal::TestUnitConversions<
      ThermalConductivity, ThermalConductivity::WattPerMetrePerKelvin,
      ThermalConductivity::NanowattPerMillimetrePerKelvin>(
      value, value * 1000000.0);
  Internal::TestUnitConversions<ThermalConductivity,
                                ThermalConductivity::WattPerMetrePerKelvin,
                                ThermalConductivity::PoundPerSecondPerRankine>(
      value, value / (0.45359237 * 9.80665 * 1.8));
}

TEST(UnitThermalConductivity, ConvertToStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<
      ThermalConductivity, ThermalConductivity::WattPerMetrePerKelvin,
      ThermalConductivity::WattPerMetrePerKelvin>(value, value);
  Internal::TestUnitConversions<
      ThermalConductivity, ThermalConductivity::NanowattPerMillimetrePerKelvin,
      ThermalConductivity::WattPerMetrePerKelvin>(value, value * 0.000001);
  Internal::TestUnitConversions<ThermalConductivity,
                                ThermalConductivity::PoundPerSecondPerRankine,
                                ThermalConductivity::WattPerMetrePerKelvin>(
      value, value * 0.45359237 * 9.80665 * 1.8);
}

TEST(UnitThermalConductivity, Parse) {
  EXPECT_EQ(Parse<ThermalConductivity>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<ThermalConductivity>("W/m/K"),
            ThermalConductivity::WattPerMetrePerKelvin);
  EXPECT_EQ(Parse<ThermalConductivity>("nW/mm/°C"),
            ThermalConductivity::NanowattPerMillimetrePerKelvin);
  EXPECT_EQ(Parse<ThermalConductivity>("lbf/s/°R"),
            ThermalConductivity::PoundPerSecondPerRankine);
}

TEST(UnitThermalConductivity, RelatedDimensions) {
  EXPECT_EQ(
      RelatedDimensions<ThermalConductivity>,
      Dimensions(Dimension::Time{-3}, Dimension::Length{1}, Dimension::Mass{1},
                 Dimension::ElectricCurrent{}, Dimension::Temperature{-1}));
}

TEST(UnitThermalConductivity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(ThermalConductivity::WattPerMetrePerKelvin),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(
      RelatedUnitSystem(ThermalConductivity::NanowattPerMillimetrePerKelvin),
      UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(ThermalConductivity::PoundPerSecondPerRankine),
            std::nullopt);
}

TEST(UnitThermalConductivity, Standard) {
  EXPECT_EQ(Standard<ThermalConductivity>,
            ThermalConductivity::WattPerMetrePerKelvin);
}

TEST(UnitThermalConductivity, Stream) {
  std::ostringstream stream;
  stream << ThermalConductivity::WattPerMetrePerKelvin;
  EXPECT_EQ(
      stream.str(), Abbreviation(ThermalConductivity::WattPerMetrePerKelvin));
}

}  // namespace

}  // namespace PhQ::Unit
