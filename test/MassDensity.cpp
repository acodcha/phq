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

#include "../include/PhQ/MassDensity.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(MassDensity, Accessor) {
  const MassDensity density{0.1, Unit::MassDensity::KilogramPerCubicMetre};
  EXPECT_DOUBLE_EQ(density.Value(), 0.1);
  EXPECT_DOUBLE_EQ(density.Value(Unit::MassDensity::GramPerCubicMillimetre),
                   0.1 * 0.000001);
}

TEST(MassDensity, Arithmetic) {
  const Mass mass{2.0, Unit::Mass::Kilogram};
  const Volume volume{2.0, Unit::Volume::CubicMetre};
  const MassDensity density0{0.0, Unit::MassDensity::KilogramPerCubicMetre};
  const MassDensity density1{1.0, Unit::MassDensity::KilogramPerCubicMetre};
  const MassDensity density2{2.0, Unit::MassDensity::KilogramPerCubicMetre};
  EXPECT_EQ(density1 + density1, density2);
  EXPECT_EQ(density1 - density1, density0);
  EXPECT_EQ(density1 * 2.0, density2);
  EXPECT_EQ(2.0 * density1, density2);
  EXPECT_EQ(density1 * volume, mass);
  EXPECT_EQ(volume * density1, mass);
  EXPECT_EQ(density2 / 2.0, density1);
  EXPECT_EQ(mass / volume, density1);

  MassDensity density3{density1};
  density3 += density1;
  EXPECT_EQ(density3, density2);

  MassDensity density4{density1};
  density4 -= density1;
  EXPECT_EQ(density4, density0);

  MassDensity density5{density1};
  density5 *= 2.0;
  EXPECT_EQ(density5, density2);

  MassDensity density6{density2};
  density6 /= 2.0;
  EXPECT_EQ(density6, density1);
}

TEST(MassDensity, Comparison) {
  const MassDensity density0{0.1, Unit::MassDensity::KilogramPerCubicMetre};
  const MassDensity density1{0.2, Unit::MassDensity::KilogramPerCubicMetre};
  EXPECT_EQ(density0, density0);
  EXPECT_NE(density0, density1);
  EXPECT_LT(density0, density1);
  EXPECT_GT(density1, density0);
  EXPECT_LE(density0, density0);
  EXPECT_LE(density0, density1);
  EXPECT_GE(density0, density0);
  EXPECT_GE(density1, density0);
}

TEST(MassDensity, Constructor) {
  const Mass mass0{2.0, Unit::Mass::Kilogram};
  const Volume volume0{2.0, Unit::Volume::CubicMetre};
  constexpr MassDensity density0;
  const MassDensity density1{1.0, Unit::MassDensity::KilogramPerCubicMetre};
  const MassDensity density2{100.0, Unit::MassDensity::GramPerCubicMillimetre};
  constexpr MassDensity density3{
      MassDensity::Create<Unit::MassDensity::GramPerCubicMillimetre>(100.0)};
  const MassDensity density4{mass0, volume0};
  const Mass mass1{density0, volume0};
  const Volume volume1{density0, mass0};
}

TEST(MassDensity, Hash) {
  const MassDensity density0{10.0, Unit::MassDensity::GramPerCubicMillimetre};
  const MassDensity density1{10.000001,
                             Unit::MassDensity::GramPerCubicMillimetre};
  const MassDensity density2{11.0, Unit::MassDensity::GramPerCubicMillimetre};
  const MassDensity density3{-10.0, Unit::MassDensity::GramPerCubicMillimetre};
  const MassDensity density4{20000.0,
                             Unit::MassDensity::GramPerCubicMillimetre};
  const MassDensity density5{-123.456,
                             Unit::MassDensity::GramPerCubicMillimetre};
  const std::hash<MassDensity> hasher;
  EXPECT_NE(hasher(density0), hasher(density1));
  EXPECT_NE(hasher(density0), hasher(density2));
  EXPECT_NE(hasher(density0), hasher(density3));
  EXPECT_NE(hasher(density0), hasher(density4));
  EXPECT_NE(hasher(density0), hasher(density5));
  const std::unordered_set<MassDensity> unordered{density0, density1, density2,
                                                  density3, density4, density5};
}

TEST(MassDensity, JSON) {
  EXPECT_EQ(MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre).JSON(),
            "{\"value\":1.110000,\"unit\":\"kg/m^3\"}");
  EXPECT_EQ(MassDensity(-5.0, Unit::MassDensity::GramPerCubicMillimetre)
                .Json(Unit::MassDensity::GramPerCubicMillimetre),
            "{\"value\":-5.000000,\"unit\":\"g/mm^3\"}");
}

TEST(MassDensity, Print) {
  EXPECT_EQ(MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre).Print(),
            "1.110000 kg/m^3");
  EXPECT_EQ(MassDensity(-5.0, Unit::MassDensity::GramPerCubicMillimetre)
                .Print(Unit::MassDensity::GramPerCubicMillimetre),
            "-5.000000 g/mm^3");
}

TEST(MassDensity, Stream) {
  const MassDensity density{1.11, Unit::MassDensity::KilogramPerCubicMetre};
  std::ostringstream stream;
  stream << density;
  EXPECT_EQ(stream.str(), density.Print());
}

TEST(MassDensity, XML) {
  EXPECT_EQ(MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre).XML(),
            "<value>1.110000</value><unit>kg/m^3</unit>");
  EXPECT_EQ(MassDensity(-5.0, Unit::MassDensity::GramPerCubicMillimetre)
                .Xml(Unit::MassDensity::GramPerCubicMillimetre),
            "<value>-5.000000</value><unit>g/mm^3</unit>");
}

TEST(MassDensity, YAML) {
  EXPECT_EQ(MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre).YAML(),
            "{value:1.110000,unit:\"kg/m^3\"}");
  EXPECT_EQ(MassDensity(-5.0, Unit::MassDensity::GramPerCubicMillimetre)
                .Yaml(Unit::MassDensity::GramPerCubicMillimetre),
            "{value:-5.000000,unit:\"g/mm^3\"}");
}

}  // namespace

}  // namespace PhQ
