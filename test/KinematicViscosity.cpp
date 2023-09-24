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

#include "../include/PhQ/KinematicViscosity.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(KinematicViscosity, Accessor) {
  const KinematicViscosity viscosity{
      0.1, Unit::Diffusivity::SquareMetrePerSecond};
  EXPECT_DOUBLE_EQ(viscosity.Value(), 0.1);
  EXPECT_DOUBLE_EQ(viscosity.Value(Unit::Diffusivity::SquareFootPerSecond),
                   0.1 / (0.3048 * 0.3048));
}

TEST(KinematicViscosity, Arithmetic) {
  const KinematicViscosity viscosity0{
      0.0, Unit::Diffusivity::SquareMetrePerSecond};
  const KinematicViscosity viscosity1{
      1.0, Unit::Diffusivity::SquareMetrePerSecond};
  const KinematicViscosity viscosity2{
      2.0, Unit::Diffusivity::SquareMetrePerSecond};
  EXPECT_EQ(viscosity1 + viscosity1, viscosity2);
  EXPECT_EQ(viscosity1 - viscosity1, viscosity0);
  EXPECT_EQ(viscosity1 * 2.0, viscosity2);
  EXPECT_EQ(2.0 * viscosity1, viscosity2);
  EXPECT_EQ(viscosity2 / 2.0, viscosity1);
  EXPECT_EQ(viscosity2 / viscosity2, 1.0);

  KinematicViscosity viscosity3{viscosity1};
  viscosity3 += viscosity1;
  EXPECT_EQ(viscosity3, viscosity2);

  KinematicViscosity viscosity4{viscosity1};
  viscosity4 -= viscosity1;
  EXPECT_EQ(viscosity4, viscosity0);

  KinematicViscosity viscosity5{viscosity1};
  viscosity5 *= 2.0;
  EXPECT_EQ(viscosity5, viscosity2);

  KinematicViscosity viscosity6{viscosity2};
  viscosity6 /= 2.0;
  EXPECT_EQ(viscosity6, viscosity1);
}

TEST(KinematicViscosity, Comparison) {
  const KinematicViscosity viscosity0{
      0.1, Unit::Diffusivity::SquareMetrePerSecond};
  const KinematicViscosity viscosity1{
      0.2, Unit::Diffusivity::SquareMetrePerSecond};
  EXPECT_EQ(viscosity0, viscosity0);
  EXPECT_NE(viscosity0, viscosity1);
  EXPECT_LT(viscosity0, viscosity1);
  EXPECT_GT(viscosity1, viscosity0);
  EXPECT_LE(viscosity0, viscosity0);
  EXPECT_LE(viscosity0, viscosity1);
  EXPECT_GE(viscosity0, viscosity0);
  EXPECT_GE(viscosity1, viscosity0);
}

TEST(KinematicViscosity, Constructor) {
  constexpr KinematicViscosity viscosity0{};
  const KinematicViscosity viscosity1{
      1.0, Unit::Diffusivity::SquareMetrePerSecond};
  const KinematicViscosity viscosity2{
      100.0, Unit::Diffusivity::SquareFootPerSecond};
  constexpr KinematicViscosity viscosity3{
      KinematicViscosity::Create<Unit::Diffusivity::SquareFootPerSecond>(4.0)};
}

TEST(KinematicViscosity, Copy) {
  const KinematicViscosity reference{
      1.11, Unit::Diffusivity::SquareMetrePerSecond};
  const KinematicViscosity first{reference};
  EXPECT_EQ(first, reference);
  KinematicViscosity second = KinematicViscosity::Zero();
  second = reference;
  EXPECT_EQ(second, reference);
}

TEST(KinematicViscosity, Dimensions) {
  EXPECT_EQ(
      KinematicViscosity::Dimensions(), RelatedDimensions<Unit::Diffusivity>);
}

TEST(KinematicViscosity, Hash) {
  const KinematicViscosity viscosity0{
      10.0, Unit::Diffusivity::SquareFootPerSecond};
  const KinematicViscosity viscosity1{
      10.000001, Unit::Diffusivity::SquareFootPerSecond};
  const KinematicViscosity viscosity2{
      11.0, Unit::Diffusivity::SquareFootPerSecond};
  const KinematicViscosity viscosity3{
      -10.0, Unit::Diffusivity::SquareFootPerSecond};
  const KinematicViscosity viscosity4{
      20000.0, Unit::Diffusivity::SquareFootPerSecond};
  const KinematicViscosity viscosity5{
      -123.456, Unit::Diffusivity::SquareFootPerSecond};
  const std::hash<KinematicViscosity> hasher;
  EXPECT_NE(hasher(viscosity0), hasher(viscosity1));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity2));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity3));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity4));
  EXPECT_NE(hasher(viscosity0), hasher(viscosity5));
  const std::unordered_set<KinematicViscosity> unordered{
      viscosity0, viscosity1, viscosity2, viscosity3, viscosity4, viscosity5};
}

TEST(KinematicViscosity, JSON) {
  EXPECT_EQ(
      KinematicViscosity(1.11, Unit::Diffusivity::SquareMetrePerSecond).JSON(),
      "{\"value\":1.110000000000000,\"unit\":\"m^2/s\"}");
  EXPECT_EQ(KinematicViscosity(-5.0, Unit::Diffusivity::SquareFootPerSecond)
                .JSON(Unit::Diffusivity::SquareFootPerSecond),
            "{\"value\":-5.000000000000000,\"unit\":\"ft^2/s\"}");
}

TEST(KinematicViscosity, Move) {
  const KinematicViscosity reference{
      1.11, Unit::Diffusivity::SquareMetrePerSecond};
  KinematicViscosity first{1.11, Unit::Diffusivity::SquareMetrePerSecond};
  KinematicViscosity second{std::move(first)};
  EXPECT_EQ(second, reference);
  KinematicViscosity third = KinematicViscosity::Zero();
  third = std::move(second);
  EXPECT_EQ(third, reference);
}

TEST(KinematicViscosity, Print) {
  EXPECT_EQ(
      KinematicViscosity(1.11, Unit::Diffusivity::SquareMetrePerSecond).Print(),
      "1.110000000000000 m^2/s");
  EXPECT_EQ(KinematicViscosity(-5.0, Unit::Diffusivity::SquareFootPerSecond)
                .Print(Unit::Diffusivity::SquareFootPerSecond),
            "-5.000000000000000 ft^2/s");
}

TEST(KinematicViscosity, SizeOf) {
  const KinematicViscosity viscosity{
      1.11, Unit::Diffusivity::SquareMetrePerSecond};
  EXPECT_EQ(sizeof(viscosity), sizeof(double));
}

TEST(KinematicViscosity, Stream) {
  const KinematicViscosity viscosity{
      1.11, Unit::Diffusivity::SquareMetrePerSecond};
  std::ostringstream stream;
  stream << viscosity;
  EXPECT_EQ(stream.str(), viscosity.Print());
}

TEST(KinematicViscosity, Unit) {
  EXPECT_EQ(KinematicViscosity::Unit(), Standard<Unit::Diffusivity>);
}

TEST(KinematicViscosity, XML) {
  EXPECT_EQ(
      KinematicViscosity(1.11, Unit::Diffusivity::SquareMetrePerSecond).XML(),
      "<value>1.110000000000000</value><unit>m^2/s</unit>");
  EXPECT_EQ(KinematicViscosity(-5.0, Unit::Diffusivity::SquareFootPerSecond)
                .XML(Unit::Diffusivity::SquareFootPerSecond),
            "<value>-5.000000000000000</value><unit>ft^2/s</unit>");
}

TEST(KinematicViscosity, YAML) {
  EXPECT_EQ(
      KinematicViscosity(1.11, Unit::Diffusivity::SquareMetrePerSecond).YAML(),
      "{value:1.110000000000000,unit:\"m^2/s\"}");
  EXPECT_EQ(KinematicViscosity(-5.0, Unit::Diffusivity::SquareFootPerSecond)
                .YAML(Unit::Diffusivity::SquareFootPerSecond),
            "{value:-5.000000000000000,unit:\"ft^2/s\"}");
}

TEST(KinematicViscosity, Zero) {
  EXPECT_EQ(KinematicViscosity::Zero(),
            KinematicViscosity(0.0, Unit::Diffusivity::SquareMetrePerSecond));
}

}  // namespace

}  // namespace PhQ
