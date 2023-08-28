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

#include "../include/PhQ/BulkDynamicViscosity.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(BulkDynamicViscosity, Accessor) {
  const BulkDynamicViscosity viscosity{
      0.1, Unit::DynamicViscosity::PascalSecond};
  EXPECT_DOUBLE_EQ(viscosity.Value(), 0.1);
  EXPECT_DOUBLE_EQ(
      viscosity.Value(Unit::DynamicViscosity::KilopascalSecond), 0.1 * 0.001);
}

TEST(BulkDynamicViscosity, Arithmetic) {
  const BulkDynamicViscosity viscosity0{
      0.0, Unit::DynamicViscosity::PascalSecond};
  const BulkDynamicViscosity viscosity1{
      1.0, Unit::DynamicViscosity::PascalSecond};
  const BulkDynamicViscosity viscosity2{
      2.0, Unit::DynamicViscosity::PascalSecond};
  EXPECT_EQ(viscosity1 + viscosity1, viscosity2);
  EXPECT_EQ(viscosity1 - viscosity1, viscosity0);
  EXPECT_EQ(viscosity1 * 2.0, viscosity2);
  EXPECT_EQ(2.0 * viscosity1, viscosity2);
  EXPECT_EQ(viscosity2 / 2.0, viscosity1);
  EXPECT_EQ(viscosity2 / viscosity2, 1.0);

  BulkDynamicViscosity viscosity3{viscosity1};
  viscosity3 += viscosity1;
  EXPECT_EQ(viscosity3, viscosity2);

  BulkDynamicViscosity viscosity4{viscosity1};
  viscosity4 -= viscosity1;
  EXPECT_EQ(viscosity4, viscosity0);

  BulkDynamicViscosity viscosity5{viscosity1};
  viscosity5 *= 2.0;
  EXPECT_EQ(viscosity5, viscosity2);

  BulkDynamicViscosity viscosity6{viscosity2};
  viscosity6 /= 2.0;
  EXPECT_EQ(viscosity6, viscosity1);
}

TEST(BulkDynamicViscosity, Comparison) {
  const BulkDynamicViscosity viscosity0{
      0.1, Unit::DynamicViscosity::PascalSecond};
  const BulkDynamicViscosity viscosity1{
      0.2, Unit::DynamicViscosity::PascalSecond};
  EXPECT_EQ(viscosity0, viscosity0);
  EXPECT_NE(viscosity0, viscosity1);
  EXPECT_LT(viscosity0, viscosity1);
  EXPECT_GT(viscosity1, viscosity0);
  EXPECT_LE(viscosity0, viscosity0);
  EXPECT_LE(viscosity0, viscosity1);
  EXPECT_GE(viscosity0, viscosity0);
  EXPECT_GE(viscosity1, viscosity0);
}

TEST(BulkDynamicViscosity, Constructor) {
  constexpr BulkDynamicViscosity viscosity0;
  const BulkDynamicViscosity viscosity1{
      1.0, Unit::DynamicViscosity::PascalSecond};
  const BulkDynamicViscosity viscosity2{
      100.0, Unit::DynamicViscosity::KilopascalSecond};
  constexpr BulkDynamicViscosity viscosity3{
      BulkDynamicViscosity::Create<Unit::DynamicViscosity::KilopascalSecond>(
          100.0)};
}

TEST(BulkDynamicViscosity, Hash) {
  const BulkDynamicViscosity viscosity0{
      10.0, Unit::DynamicViscosity::KilopascalSecond};
  const BulkDynamicViscosity viscosity1{
      10.000001, Unit::DynamicViscosity::KilopascalSecond};
  const BulkDynamicViscosity viscosity2{
      11.0, Unit::DynamicViscosity::KilopascalSecond};
  const BulkDynamicViscosity viscosity3{
      -10.0, Unit::DynamicViscosity::KilopascalSecond};
  const BulkDynamicViscosity viscosity4{
      20000.0, Unit::DynamicViscosity::KilopascalSecond};
  const BulkDynamicViscosity viscosity5{
      -123.456, Unit::DynamicViscosity::KilopascalSecond};
  const std::hash<BulkDynamicViscosity> hasher;
  EXPECT_NE(hasher(viscosity0), hasher(viscosity1));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity2));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity3));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity4));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity5));
  const std::unordered_set<BulkDynamicViscosity> unordered{
      viscosity0, viscosity1, viscosity2, viscosity3, viscosity4, viscosity5};
}

TEST(BulkDynamicViscosity, JSON) {
  EXPECT_EQ(
      BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).JSON(),
      "{\"value\":1.110000000000000,\"unit\":\"Pa·s\"}");
  EXPECT_EQ(BulkDynamicViscosity(-5.0, Unit::DynamicViscosity::KilopascalSecond)
                .JSON(Unit::DynamicViscosity::KilopascalSecond),
            "{\"value\":-5.000000000000000,\"unit\":\"kPa·s\"}");
}

TEST(BulkDynamicViscosity, Print) {
  EXPECT_EQ(
      BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).Print(),
      "1.110000000000000 Pa·s");
  EXPECT_EQ(BulkDynamicViscosity(-5.0, Unit::DynamicViscosity::KilopascalSecond)
                .Print(Unit::DynamicViscosity::KilopascalSecond),
            "-5.000000000000000 kPa·s");
}

TEST(BulkDynamicViscosity, SizeOf) {
  const BulkDynamicViscosity viscosity{
      1.11, Unit::DynamicViscosity::PascalSecond};
  EXPECT_EQ(sizeof(viscosity), sizeof(double));
}

TEST(BulkDynamicViscosity, Stream) {
  const BulkDynamicViscosity viscosity{
      1.11, Unit::DynamicViscosity::PascalSecond};
  std::ostringstream stream;
  stream << viscosity;
  EXPECT_EQ(stream.str(), viscosity.Print());
}

TEST(BulkDynamicViscosity, XML) {
  EXPECT_EQ(
      BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).XML(),
      "<value>1.110000000000000</value><unit>Pa·s</unit>");
  EXPECT_EQ(BulkDynamicViscosity(-5.0, Unit::DynamicViscosity::KilopascalSecond)
                .XML(Unit::DynamicViscosity::KilopascalSecond),
            "<value>-5.000000000000000</value><unit>kPa·s</unit>");
}

TEST(BulkDynamicViscosity, YAML) {
  EXPECT_EQ(
      BulkDynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).YAML(),
      "{value:1.110000000000000,unit:\"Pa·s\"}");
  EXPECT_EQ(BulkDynamicViscosity(-5.0, Unit::DynamicViscosity::KilopascalSecond)
                .YAML(Unit::DynamicViscosity::KilopascalSecond),
            "{value:-5.000000000000000,unit:\"kPa·s\"}");
}

TEST(BulkDynamicViscosity, Zero) {
  EXPECT_EQ(BulkDynamicViscosity::Zero(),
            BulkDynamicViscosity(0.0, Unit::DynamicViscosity::PascalSecond));
}

}  // namespace

}  // namespace PhQ
