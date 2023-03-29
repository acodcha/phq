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

#include "../include/PhQ/DynamicViscosity.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(DynamicViscosity, Accessor) {
  const DynamicViscosity viscosity{0.1, Unit::DynamicViscosity::PascalSecond};
  EXPECT_DOUBLE_EQ(viscosity.Value(), 0.1);
  EXPECT_DOUBLE_EQ(viscosity.Value(Unit::DynamicViscosity::KilopascalSecond),
                   0.1 * 0.001);
}

TEST(DynamicViscosity, Arithmetic) {
  const KinematicViscosity kinematic{2.0,
                                     Unit::Diffusivity::SquareMetrePerSecond};
  const MassDensity density{0.5, Unit::MassDensity::KilogramPerCubicMetre};
  const DynamicViscosity viscosity0{0.0, Unit::DynamicViscosity::PascalSecond};
  const DynamicViscosity viscosity1{1.0, Unit::DynamicViscosity::PascalSecond};
  const DynamicViscosity viscosity2{2.0, Unit::DynamicViscosity::PascalSecond};
  EXPECT_EQ(viscosity1 + viscosity1, viscosity2);
  EXPECT_EQ(viscosity1 - viscosity1, viscosity0);
  EXPECT_EQ(viscosity1 * 2.0, viscosity2);
  EXPECT_EQ(2.0 * viscosity1, viscosity2);
  EXPECT_EQ(kinematic * density, viscosity1);
  EXPECT_EQ(density * kinematic, viscosity1);
  EXPECT_EQ(viscosity2 / 2.0, viscosity1);
  EXPECT_EQ(viscosity1 / density, kinematic);
  EXPECT_EQ(viscosity1 / kinematic, density);

  DynamicViscosity viscosity3{viscosity1};
  viscosity3 += viscosity1;
  EXPECT_EQ(viscosity3, viscosity2);

  DynamicViscosity viscosity4{viscosity1};
  viscosity4 -= viscosity1;
  EXPECT_EQ(viscosity4, viscosity0);

  DynamicViscosity viscosity5{viscosity1};
  viscosity5 *= 2.0;
  EXPECT_EQ(viscosity5, viscosity2);

  DynamicViscosity viscosity6{viscosity2};
  viscosity6 /= 2.0;
  EXPECT_EQ(viscosity6, viscosity1);
}

TEST(DynamicViscosity, Comparison) {
  const DynamicViscosity viscosity0{0.1, Unit::DynamicViscosity::PascalSecond};
  const DynamicViscosity viscosity1{0.2, Unit::DynamicViscosity::PascalSecond};
  EXPECT_EQ(viscosity0, viscosity0);
  EXPECT_NE(viscosity0, viscosity1);
  EXPECT_LT(viscosity0, viscosity1);
  EXPECT_GT(viscosity1, viscosity0);
  EXPECT_LE(viscosity0, viscosity0);
  EXPECT_LE(viscosity0, viscosity1);
  EXPECT_GE(viscosity0, viscosity0);
  EXPECT_GE(viscosity1, viscosity0);
}

TEST(DynamicViscosity, Constructor) {
  const KinematicViscosity kinematic0{2.0,
                                      Unit::Diffusivity::SquareMetrePerSecond};
  const MassDensity density0{0.5, Unit::MassDensity::KilogramPerCubicMetre};
  const DynamicViscosity dynamic0{kinematic0, density0};
  const KinematicViscosity kinematic1{dynamic0, density0};
  const MassDensity density1{dynamic0, kinematic1};
  constexpr DynamicViscosity dynamic1;
  const DynamicViscosity dynamic2{100.0,
                                  Unit::DynamicViscosity::KilopascalSecond};
  constexpr DynamicViscosity dynamic3{
      DynamicViscosity::Create<Unit::DynamicViscosity::KilopascalSecond>(
          100.0)};
}

TEST(DynamicViscosity, Hash) {
  const DynamicViscosity viscosity0{10.0,
                                    Unit::DynamicViscosity::KilopascalSecond};
  const DynamicViscosity viscosity1{10.000001,
                                    Unit::DynamicViscosity::KilopascalSecond};
  const DynamicViscosity viscosity2{11.0,
                                    Unit::DynamicViscosity::KilopascalSecond};
  const DynamicViscosity viscosity3{-10.0,
                                    Unit::DynamicViscosity::KilopascalSecond};
  const DynamicViscosity viscosity4{20000.0,
                                    Unit::DynamicViscosity::KilopascalSecond};
  const DynamicViscosity viscosity5{-123.456,
                                    Unit::DynamicViscosity::KilopascalSecond};
  const std::hash<DynamicViscosity> hasher;
  EXPECT_NE(hasher(viscosity0), hasher(viscosity1));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity2));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity3));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity4));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity5));
  const std::unordered_set<DynamicViscosity> unordered{
      viscosity0, viscosity1, viscosity2, viscosity3, viscosity4, viscosity5};
}

TEST(DynamicViscosity, Json) {
  EXPECT_EQ(DynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).Json(),
            "{\"value\":1.110000,\"unit\":\"Pa·s\"}");
  EXPECT_EQ(DynamicViscosity(-5.0, Unit::DynamicViscosity::KilopascalSecond)
                .Json(Unit::DynamicViscosity::KilopascalSecond),
            "{\"value\":-5.000000,\"unit\":\"kPa·s\"}");
}

TEST(DynamicViscosity, Print) {
  EXPECT_EQ(
      DynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).Print(),
      "1.110000 Pa·s");
  EXPECT_EQ(DynamicViscosity(-5.0, Unit::DynamicViscosity::KilopascalSecond)
                .Print(Unit::DynamicViscosity::KilopascalSecond),
            "-5.000000 kPa·s");
}

TEST(DynamicViscosity, Stream) {
  const DynamicViscosity viscosity{1.11, Unit::DynamicViscosity::PascalSecond};
  std::ostringstream stream;
  stream << viscosity;
  EXPECT_EQ(stream.str(), viscosity.Print());
}

TEST(DynamicViscosity, Xml) {
  EXPECT_EQ(DynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).Xml(),
            "<value>1.110000</value><unit>Pa·s</unit>");
  EXPECT_EQ(DynamicViscosity(-5.0, Unit::DynamicViscosity::KilopascalSecond)
                .Xml(Unit::DynamicViscosity::KilopascalSecond),
            "<value>-5.000000</value><unit>kPa·s</unit>");
}

TEST(DynamicViscosity, Yaml) {
  EXPECT_EQ(DynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).Yaml(),
            "{value:1.110000,unit:\"Pa·s\"}");
  EXPECT_EQ(DynamicViscosity(-5.0, Unit::DynamicViscosity::KilopascalSecond)
                .Yaml(Unit::DynamicViscosity::KilopascalSecond),
            "{value:-5.000000,unit:\"kPa·s\"}");
}

}  // namespace

}  // namespace PhQ
