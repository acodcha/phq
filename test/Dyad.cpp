// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#include "../include/PhQ/Dyad.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>
#include <utility>

#include "../include/PhQ/Base.hpp"
#include "../include/PhQ/SymmetricDyad.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(Dyad, Adjugate) {
  EXPECT_EQ(
      Dyad(64.0F, 4.0F, 1.0F, 16.0F, 128.0F, 8.0F, 2.0F, 32.0F, 256.0F).Adjugate(),
      Dyad(32512.0F, -992.0F, -96.0F, -4080.0F, 16382.0F, -496.0F, 256.0F, -2040.0F, 8128.0F));
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Adjugate(),
            Dyad(32512.0, -992.0, -96.0, -4080.0, 16382.0, -496.0, 256.0, -2040.0, 8128.0));
  EXPECT_EQ(
      Dyad(64.0L, 4.0L, 1.0L, 16.0L, 128.0L, 8.0L, 2.0L, 32.0L, 256.0L).Adjugate(),
      Dyad(32512.0L, -992.0L, -96.0L, -4080.0L, 16382.0L, -496.0L, 256.0L, -2040.0L, 8128.0L));
}

TEST(Dyad, ArithmeticOperatorAddition) {
  EXPECT_EQ(Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F)
                + Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F),
            Dyad(3.0F, -6.0F, 9.0F, -12.0F, 15.0F, -18.0F, 21.0F, -24.0F, 27.0F));
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0)
                + Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0),
            Dyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0));
  EXPECT_EQ(Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L)
                + Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L),
            Dyad(3.0L, -6.0L, 9.0L, -12.0L, 15.0L, -18.0L, 21.0L, -24.0L, 27.0L));
}

TEST(Dyad, ArithmeticOperatorDivision) {
  EXPECT_EQ(Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F) / 2.0F,
            Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  EXPECT_EQ(Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F) / 2.0,
            Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  EXPECT_EQ(Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F) / 2.0L,
            Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  EXPECT_EQ(Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0) / 2.0F,
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  EXPECT_EQ(Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0) / 2.0,
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  EXPECT_EQ(Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0) / 2.0L,
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  EXPECT_EQ(Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L) / 2.0F,
            Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  EXPECT_EQ(Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L) / 2.0,
            Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  EXPECT_EQ(Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L) / 2.0L,
            Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
}

TEST(Dyad, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F) * 2.0F,
            Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F));
  EXPECT_EQ(Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F) * 2.0,
            Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F));
  EXPECT_EQ(Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F) * 2.0L,
            Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F));
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0) * 2.0F,
            Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0) * 2.0,
            Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0) * 2.0L,
            Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
  EXPECT_EQ(Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L) * 2.0F,
            Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L));
  EXPECT_EQ(Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L) * 2.0,
            Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L));
  EXPECT_EQ(Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L) * 2.0L,
            Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L));
  EXPECT_EQ(2.0F * Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F),
            Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F));
  EXPECT_EQ(2.0 * Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F),
            Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F));
  EXPECT_EQ(2.0L * Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F),
            Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F));
  EXPECT_EQ(2.0F * Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0),
            Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
  EXPECT_EQ(2.0 * Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0),
            Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
  EXPECT_EQ(2.0L * Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0),
            Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
  EXPECT_EQ(2.0F * Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L),
            Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L));
  EXPECT_EQ(2.0 * Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L),
            Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L));
  EXPECT_EQ(2.0L * Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L),
            Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L));
  EXPECT_EQ(
      Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F) * Vector(1.0F, -2.0F, 3.0F),
      Vector(14.0F, -32.0F, 50.0F));
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0) * Vector(1.0, -2.0, 3.0),
            Vector(14.0, -32.0, 50.0));
  EXPECT_EQ(
      Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L) * Vector(1.0L, -2.0L, 3.0L),
      Vector(14.0L, -32.0L, 50.0L));
  EXPECT_EQ(SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F)
                * SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F),
            Dyad(14.0F, 21.0F, -25.0F, 21.0F, 45.0F, -56.0F, -25.0F, -56.0F, 70.0F));
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0)
                * SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0),
            Dyad(14.0, 21.0, -25.0, 21.0, 45.0, -56.0, -25.0, -56.0, 70.0));
  EXPECT_EQ(SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L)
                * SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L),
            Dyad(14.0L, 21.0L, -25.0L, 21.0L, 45.0L, -56.0L, -25.0L, -56.0L, 70.0L));
  EXPECT_EQ(Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F)
                * SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F),
            Dyad(14.0F, 21.0F, -25.0F, -32.0F, -42.0F, 49.0F, 50.0F, 63.0F, -73.0F));
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0)
                * SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0),
            Dyad(14.0, 21.0, -25.0, -32.0, -42.0, 49.0, 50.0, 63.0, -73.0));
  EXPECT_EQ(Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L)
                * SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L),
            Dyad(14.0L, 21.0L, -25.0L, -32.0L, -42.0L, 49.0L, 50.0L, 63.0L, -73.0L));
  EXPECT_EQ(SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F)
                * Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F),
            Dyad(30.0F, -36.0F, 42.0F, 49.0F, -56.0F, 63.0F, -59.0F, 67.0F, -75.0F));
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0)
                * Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0),
            Dyad(30.0, -36.0, 42.0, 49.0, -56.0, 63.0, -59.0, 67.0, -75.0));
  EXPECT_EQ(SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L)
                * Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L),
            Dyad(30.0L, -36.0L, 42.0L, 49.0L, -56.0L, 63.0L, -59.0L, 67.0L, -75.0L));
  EXPECT_EQ(Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F)
                * Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F),
            Dyad(30.0F, -36.0F, 42.0F, -66.0F, 81.0F, -96.0F, 102.0F, -126.0F, 150.0F));
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0)
                * Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0),
            Dyad(30.0, -36.0, 42.0, -66.0, 81.0, -96.0, 102.0, -126.0, 150.0));
  EXPECT_EQ(Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L)
                * Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L),
            Dyad(30.0L, -36.0L, 42.0L, -66.0L, 81.0L, -96.0L, 102.0L, -126.0L, 150.0L));
}

TEST(Dyad, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Dyad(3.0F, -6.0F, 9.0F, -12.0F, 15.0F, -18.0F, 21.0F, -24.0F, 27.0F)
                - Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F),
            Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  EXPECT_EQ(Dyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0)
                - Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0),
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  EXPECT_EQ(Dyad(3.0L, -6.0L, 9.0L, -12.0L, 15.0L, -18.0L, 21.0L, -24.0L, 27.0L)
                - Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L),
            Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
}

TEST(Dyad, AssignmentOperatorAddition) {
  {
    Dyad dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    dyad += Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F);
    EXPECT_EQ(dyad, Dyad(3.0F, -6.0F, 9.0F, -12.0F, 15.0F, -18.0F, 21.0F, -24.0F, 27.0F));
  }
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    dyad += Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
    EXPECT_EQ(dyad, Dyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0));
  }
  {
    Dyad dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    dyad += Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L);
    EXPECT_EQ(dyad, Dyad(3.0L, -6.0L, 9.0L, -12.0L, 15.0L, -18.0L, 21.0L, -24.0L, 27.0L));
  }
}

TEST(Dyad, AssignmentOperatorDivision) {
  {
    Dyad dyad{2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F};
    dyad /= 2.0F;
    EXPECT_EQ(dyad, Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  }
  {
    Dyad dyad{2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0};
    dyad /= 2.0;
    EXPECT_EQ(dyad, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    Dyad dyad{2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L};
    dyad /= 2.0L;
    EXPECT_EQ(dyad, Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  }
}

TEST(Dyad, AssignmentOperatorMultiplication) {
  {
    Dyad dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    dyad *= 2.0F;
    EXPECT_EQ(dyad, Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F));
  }
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    dyad *= 2.0;
    EXPECT_EQ(dyad, Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
  }
  {
    Dyad dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    dyad *= 2.0L;
    EXPECT_EQ(dyad, Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L));
  }
}

TEST(Dyad, AssignmentOperatorSubtraction) {
  {
    Dyad dyad{3.0F, -6.0F, 9.0F, -12.0F, 15.0F, -18.0F, 21.0F, -24.0F, 27.0F};
    dyad -= Dyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F, 14.0F, -16.0F, 18.0F);
    EXPECT_EQ(dyad, Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  }
  {
    Dyad dyad{3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0};
    dyad -= Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
    EXPECT_EQ(dyad, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    Dyad dyad{3.0L, -6.0L, 9.0L, -12.0L, 15.0L, -18.0L, 21.0L, -24.0L, 27.0L};
    dyad -= Dyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L, 14.0L, -16.0L, 18.0L);
    EXPECT_EQ(dyad, Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  }
}

TEST(Dyad, Cofactors) {
  EXPECT_EQ(
      Dyad(64.0F, 4.0F, 1.0F, 16.0F, 128.0F, 8.0F, 2.0F, 32.0F, 256.0F).Cofactors(),
      Dyad(32512.0F, -4080.0F, 256.0F, -992.0F, 16382.0F, -2040.0F, -96.0F, -496.0F, 8128.0F));
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Cofactors(),
            Dyad(32512.0, -4080.0, 256.0, -992.0, 16382.0, -2040.0, -96.0, -496.0, 8128.0));
  EXPECT_EQ(
      Dyad(64.0L, 4.0L, 1.0L, 16.0L, 128.0L, 8.0L, 2.0L, 32.0L, 256.0L).Cofactors(),
      Dyad(32512.0L, -4080.0L, 256.0L, -992.0L, 16382.0L, -2040.0L, -96.0L, -496.0L, 8128.0L));
}

TEST(Dyad, ComparisonOperators) {
  {
    constexpr Dyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    constexpr Dyad second{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.000001F};
    constexpr Dyad third{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, 6.0F, 7.0F, -8.0F, 9.0F};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_LT(second, third);
    EXPECT_GT(second, first);
    EXPECT_GT(third, second);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_LE(second, third);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
    EXPECT_GE(third, second);
  }
  {
    constexpr Dyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    constexpr Dyad second{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.000001};
    constexpr Dyad third{1.0, -2.0, 3.0, -4.0, 5.0, 6.0, 7.0, -8.0, 9.0};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_LT(second, third);
    EXPECT_GT(second, first);
    EXPECT_GT(third, second);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_LE(second, third);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
    EXPECT_GE(third, second);
  }
  {
    constexpr Dyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    constexpr Dyad second{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.000001L};
    constexpr Dyad third{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, 6.0L, 7.0L, -8.0L, 9.0L};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_LT(second, third);
    EXPECT_GT(second, first);
    EXPECT_GT(third, second);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_LE(second, third);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
    EXPECT_GE(third, second);
  }
}

TEST(Dyad, CopyAssignmentOperator) {
  {
    constexpr Dyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    Dyad second{-10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F};
    second = first;
    EXPECT_EQ(second, Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  }
  {
    constexpr Dyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    Dyad second{-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0};
    second = first;
    EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    constexpr Dyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    Dyad second{-10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L};
    second = first;
    EXPECT_EQ(second, Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  }
  {
    constexpr Dyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    Dyad second{-10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F};
    second = first;
    EXPECT_EQ(second, Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  }
  {
    constexpr Dyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    Dyad second{-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0};
    second = first;
    EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    constexpr Dyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    Dyad second{-10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L};
    second = first;
    EXPECT_EQ(second, Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  }
  {
    constexpr Dyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    Dyad second{-10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F};
    second = first;
    EXPECT_EQ(second, Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  }
  {
    constexpr Dyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    Dyad second{-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0};
    second = first;
    EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    constexpr Dyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    Dyad second{-10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L};
    second = first;
    EXPECT_EQ(second, Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  }
}

TEST(Dyad, CopyConstructor) {
  {
    constexpr Dyad first(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F);
    constexpr Dyad<float> second{first};
    EXPECT_EQ(second, Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  }
  {
    constexpr Dyad first(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F);
    constexpr Dyad<double> second{first};
    EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    constexpr Dyad first(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F);
    constexpr Dyad<long double> second{first};
    EXPECT_EQ(second, Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  }
  {
    constexpr Dyad first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
    constexpr Dyad<float> second{first};
    EXPECT_EQ(second, Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  }
  {
    constexpr Dyad first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
    constexpr Dyad second{first};
    EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    constexpr Dyad first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
    constexpr Dyad<long double> second{first};
    EXPECT_EQ(second, Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  }
  {
    constexpr Dyad first(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L);
    constexpr Dyad<float> second{first};
    EXPECT_EQ(second, Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  }
  {
    constexpr Dyad first(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L);
    constexpr Dyad<double> second{first};
    EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    constexpr Dyad first(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L);
    constexpr Dyad<long double> second{first};
    EXPECT_EQ(second, Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  }
}

TEST(Dyad, DefaultConstructor) {
  EXPECT_NO_THROW(Dyad{});
  EXPECT_NO_THROW(Dyad<>{});
  EXPECT_NO_THROW(Dyad<float>{});
  EXPECT_NO_THROW(Dyad<double>{});
  EXPECT_NO_THROW(Dyad<long double>{});
}

TEST(Dyad, Determinant) {
  EXPECT_EQ(
      Dyad(64.0F, 4.0F, 1.0F, 16.0F, 128.0F, 8.0F, 2.0F, 32.0F, 256.0F).Determinant(), 2064704.0F);
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Determinant(), 2064704.0);
  EXPECT_EQ(
      Dyad(64.0L, 4.0L, 1.0L, 16.0L, 128.0L, 8.0L, 2.0L, 32.0L, 256.0L).Determinant(), 2064704.0L);
}

TEST(Dyad, DyadicProduct) {
  EXPECT_EQ(Vector(1.0F, 2.0F, 4.0F).Dyadic(Vector(8.0F, 16.0F, 32.0F)),
            Dyad(8.0F, 16.0F, 32.0F, 16.0F, 32.0F, 64.0F, 32.0F, 64.0F, 128.0F));
  EXPECT_EQ(Vector(1.0, 2.0, 4.0).Dyadic(Vector(8.0, 16.0, 32.0)),
            Dyad(8.0, 16.0, 32.0, 16.0, 32.0, 64.0, 32.0, 64.0, 128.0));
  EXPECT_EQ(Vector(1.0L, 2.0L, 4.0L).Dyadic(Vector(8.0L, 16.0L, 32.0L)),
            Dyad(8.0L, 16.0L, 32.0L, 16.0L, 32.0L, 64.0L, 32.0L, 64.0L, 128.0L));
}

TEST(Dyad, Hash) {
  {
    constexpr Dyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    constexpr Dyad second{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.000001F};
    constexpr Dyad third{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, 6.0F, 7.0F, -8.0F, 9.0F};
    constexpr std::hash<Dyad<float><>> hash;
    EXPECT_NE(hash(first), hash(second));
    EXPECT_NE(hash(first), hash(third));
    EXPECT_NE(hash(second), hash(third));
  }
  {
    constexpr Dyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    constexpr Dyad second{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.000001};
    constexpr Dyad third{1.0, -2.0, 3.0, -4.0, 5.0, 6.0, 7.0, -8.0, 9.0};
    constexpr std::hash<Dyad<><>> hash;
    EXPECT_NE(hash(first), hash(second));
    EXPECT_NE(hash(first), hash(third));
    EXPECT_NE(hash(second), hash(third));
  }
  {
    constexpr Dyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    constexpr Dyad second{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.000001L};
    constexpr Dyad third{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, 6.0L, 7.0L, -8.0L, 9.0L};
    constexpr std::hash<Dyad<long double><>> hash;
    EXPECT_NE(hash(first), hash(second));
    EXPECT_NE(hash(first), hash(third));
    EXPECT_NE(hash(second), hash(third));
  }
}

TEST(Dyad, Inverse) {
  {
    constexpr Dyad dyad{64.0F, 4.0F, 1.0F, 16.0F, 128.0F, 8.0F, 2.0F, 32.0F, 256.0F};
    const std::optional<Dyad<float>> inverse{dyad.Inverse()};
    ASSERT_TRUE(inverse.has_value());
    EXPECT_DOUBLE_EQ(inverse.value().xx(), 32512.0F / 2064704.0F);
    EXPECT_DOUBLE_EQ(inverse.value().xy(), -992.0F / 2064704.0F);
    EXPECT_DOUBLE_EQ(inverse.value().xz(), -96.0F / 2064704.0F);
    EXPECT_DOUBLE_EQ(inverse.value().yx(), -4080.0F / 2064704.0F);
    EXPECT_DOUBLE_EQ(inverse.value().yy(), 16382.0F / 2064704.0F);
    EXPECT_DOUBLE_EQ(inverse.value().yz(), -496.0F / 2064704.0F);
    EXPECT_DOUBLE_EQ(inverse.value().zx(), 256.0F / 2064704.0F);
    EXPECT_DOUBLE_EQ(inverse.value().zy(), -2040.0F / 2064704.0F);
    EXPECT_DOUBLE_EQ(inverse.value().zz(), 8128.0F / 2064704.0F);
  }
  {
    constexpr Dyad dyad{64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0};
    const std::optional<Dyad<>> inverse{dyad.Inverse()};
    ASSERT_TRUE(inverse.has_value());
    EXPECT_DOUBLE_EQ(inverse.value().xx(), 32512.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().xy(), -992.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().xz(), -96.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().yx(), -4080.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().yy(), 16382.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().yz(), -496.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().zx(), 256.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().zy(), -2040.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().zz(), 8128.0 / 2064704.0);
  }
  {
    constexpr Dyad dyad{64.0L, 4.0L, 1.0L, 16.0L, 128.0L, 8.0L, 2.0L, 32.0L, 256.0L};
    const std::optional<Dyad<long double>> inverse{dyad.Inverse()};
    ASSERT_TRUE(inverse.has_value());
    EXPECT_DOUBLE_EQ(inverse.value().xx(), 32512.0L / 2064704.0L);
    EXPECT_DOUBLE_EQ(inverse.value().xy(), -992.0L / 2064704.0L);
    EXPECT_DOUBLE_EQ(inverse.value().xz(), -96.0L / 2064704.0L);
    EXPECT_DOUBLE_EQ(inverse.value().yx(), -4080.0L / 2064704.0L);
    EXPECT_DOUBLE_EQ(inverse.value().yy(), 16382.0L / 2064704.0L);
    EXPECT_DOUBLE_EQ(inverse.value().yz(), -496.0L / 2064704.0L);
    EXPECT_DOUBLE_EQ(inverse.value().zx(), 256.0L / 2064704.0L);
    EXPECT_DOUBLE_EQ(inverse.value().zy(), -2040.0L / 2064704.0L);
    EXPECT_DOUBLE_EQ(inverse.value().zz(), 8128.0L / 2064704.0L);
  }
  {
    constexpr Dyad dyad{0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};
    const std::optional<Dyad<float>> inverse{dyad.Inverse()};
    EXPECT_FALSE(inverse.has_value());
  }
  {
    constexpr Dyad dyad{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    const std::optional<Dyad<>> inverse{dyad.Inverse()};
    EXPECT_FALSE(inverse.has_value());
  }
  {
    constexpr Dyad dyad{0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L};
    const std::optional<Dyad<long double>> inverse{dyad.Inverse()};
    EXPECT_FALSE(inverse.has_value());
  }
}

TEST(Dyad, IsSymmetric) {
  EXPECT_FALSE(Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F).IsSymmetric());
  EXPECT_FALSE(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).IsSymmetric());
  EXPECT_FALSE(Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L).IsSymmetric());
  EXPECT_TRUE(Dyad(1.0F, -2.0F, 3.0F, -2.0F, 4.0F, -5.0F, 3.0F, -5.0F, 6.0F).IsSymmetric());
  EXPECT_TRUE(Dyad(1.0, -2.0, 3.0, -2.0, 4.0, -5.0, 3.0, -5.0, 6.0).IsSymmetric());
  EXPECT_TRUE(Dyad(1.0L, -2.0L, 3.0L, -2.0L, 4.0L, -5.0L, 3.0L, -5.0L, 6.0L).IsSymmetric());
}

TEST(Dyad, JSON) {
  EXPECT_EQ(
      Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F).JSON(),
      "{\"xx\":" + Print(1.0F) + ",\"xy\":" + Print(-2.0F) + ",\"xz\":" + Print(3.0F)
          + ",\"yx\":" + Print(-4.0F) + ",\"yy\":" + Print(5.0F) + ",\"yz\":" + Print(-6.0F)
          + ",\"zx\":" + Print(7.0F) + ",\"zy\":" + Print(-8.0F) + ",\"zz\":" + Print(9.0F) + "}");
  EXPECT_EQ(
      Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).JSON(),
      "{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
          + ",\"yx\":" + Print(-4.0) + ",\"yy\":" + Print(5.0) + ",\"yz\":" + Print(-6.0)
          + ",\"zx\":" + Print(7.0) + ",\"zy\":" + Print(-8.0) + ",\"zz\":" + Print(9.0) + "}");
  EXPECT_EQ(
      Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L).JSON(),
      "{\"xx\":" + Print(1.0L) + ",\"xy\":" + Print(-2.0L) + ",\"xz\":" + Print(3.0L)
          + ",\"yx\":" + Print(-4.0L) + ",\"yy\":" + Print(5.0L) + ",\"yz\":" + Print(-6.0L)
          + ",\"zx\":" + Print(7.0L) + ",\"zy\":" + Print(-8.0L) + ",\"zz\":" + Print(9.0L) + "}");
}

TEST(Dyad, MoveAssignmentOperator) {
  {
    Dyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    Dyad second{-10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F};
    second = std::move(first);
    EXPECT_EQ(second, Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  }
  {
    Dyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    Dyad second{-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0};
    second = std::move(first);
    EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    Dyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    Dyad second{-10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L};
    second = std::move(first);
    EXPECT_EQ(second, Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  }
}

TEST(Dyad, MoveConstructor) {
  {
    Dyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    const Dyad second{std::move(first)};
    EXPECT_EQ(second, Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  }
  {
    Dyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    const Dyad second{std::move(first)};
    EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    Dyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    const Dyad second{std::move(first)};
    EXPECT_EQ(second, Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  }
}

TEST(Dyad, Mutable) {
  {
    Dyad dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    std::array<float, 9>& mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz =
        dyad.Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz();
    mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz = {
        -10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F};
    EXPECT_EQ(dyad, Dyad(-10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F));
  }
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    std::array<double, 9>& mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz =
        dyad.Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz();
    mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz = {
        -10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0};
    EXPECT_EQ(dyad, Dyad(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0));
  }
  {
    Dyad dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    std::array<long double, 9>& mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz =
        dyad.Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz();
    mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz = {
        -10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L};
    EXPECT_EQ(dyad, Dyad(-10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L));
  }
  {
    Dyad dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    float& mutable_xx = dyad.Mutable_xx();
    mutable_xx = -10.0F;
    float& mutable_xy = dyad.Mutable_xy();
    mutable_xy = 11.0F;
    float& mutable_xz = dyad.Mutable_xz();
    mutable_xz = -12.0F;
    float& mutable_yx = dyad.Mutable_yx();
    mutable_yx = 13.0F;
    float& mutable_yy = dyad.Mutable_yy();
    mutable_yy = -14.0F;
    float& mutable_yz = dyad.Mutable_yz();
    mutable_yz = 15.0F;
    float& mutable_zx = dyad.Mutable_zx();
    mutable_zx = -16.0F;
    float& mutable_zy = dyad.Mutable_zy();
    mutable_zy = 17.0F;
    float& mutable_zz = dyad.Mutable_zz();
    mutable_zz = -18.0F;
    EXPECT_EQ(dyad.xx(), -10.0F);
    EXPECT_EQ(dyad.xy(), 11.0F);
    EXPECT_EQ(dyad.xz(), -12.0F);
    EXPECT_EQ(dyad.yx(), 13.0F);
    EXPECT_EQ(dyad.yy(), -14.0F);
    EXPECT_EQ(dyad.yz(), 15.0F);
    EXPECT_EQ(dyad.zx(), -16.0F);
    EXPECT_EQ(dyad.zy(), 17.0F);
    EXPECT_EQ(dyad.zz(), -18.0F);
  }
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    double& mutable_xx = dyad.Mutable_xx();
    mutable_xx = -10.0;
    double& mutable_xy = dyad.Mutable_xy();
    mutable_xy = 11.0;
    double& mutable_xz = dyad.Mutable_xz();
    mutable_xz = -12.0;
    double& mutable_yx = dyad.Mutable_yx();
    mutable_yx = 13.0;
    double& mutable_yy = dyad.Mutable_yy();
    mutable_yy = -14.0;
    double& mutable_yz = dyad.Mutable_yz();
    mutable_yz = 15.0;
    double& mutable_zx = dyad.Mutable_zx();
    mutable_zx = -16.0;
    double& mutable_zy = dyad.Mutable_zy();
    mutable_zy = 17.0;
    double& mutable_zz = dyad.Mutable_zz();
    mutable_zz = -18.0;
    EXPECT_EQ(dyad.xx(), -10.0);
    EXPECT_EQ(dyad.xy(), 11.0);
    EXPECT_EQ(dyad.xz(), -12.0);
    EXPECT_EQ(dyad.yx(), 13.0);
    EXPECT_EQ(dyad.yy(), -14.0);
    EXPECT_EQ(dyad.yz(), 15.0);
    EXPECT_EQ(dyad.zx(), -16.0);
    EXPECT_EQ(dyad.zy(), 17.0);
    EXPECT_EQ(dyad.zz(), -18.0);
  }
  {
    Dyad dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    long double& mutable_xx = dyad.Mutable_xx();
    mutable_xx = -10.0L;
    long double& mutable_xy = dyad.Mutable_xy();
    mutable_xy = 11.0L;
    long double& mutable_xz = dyad.Mutable_xz();
    mutable_xz = -12.0L;
    long double& mutable_yx = dyad.Mutable_yx();
    mutable_yx = 13.0L;
    long double& mutable_yy = dyad.Mutable_yy();
    mutable_yy = -14.0L;
    long double& mutable_yz = dyad.Mutable_yz();
    mutable_yz = 15.0L;
    long double& mutable_zx = dyad.Mutable_zx();
    mutable_zx = -16.0L;
    long double& mutable_zy = dyad.Mutable_zy();
    mutable_zy = 17.0L;
    long double& mutable_zz = dyad.Mutable_zz();
    mutable_zz = -18.0L;
    EXPECT_EQ(dyad.xx(), -10.0L);
    EXPECT_EQ(dyad.xy(), 11.0L);
    EXPECT_EQ(dyad.xz(), -12.0L);
    EXPECT_EQ(dyad.yx(), 13.0L);
    EXPECT_EQ(dyad.yy(), -14.0L);
    EXPECT_EQ(dyad.yz(), 15.0L);
    EXPECT_EQ(dyad.zx(), -16.0L);
    EXPECT_EQ(dyad.zy(), 17.0L);
    EXPECT_EQ(dyad.zz(), -18.0L);
  }
}

TEST(Dyad, Print) {
  EXPECT_EQ(Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F).Print(),
            "(" + Print(1.0F) + ", " + Print(-2.0F) + ", " + Print(3.0F) + "; " + Print(-4.0F)
                + ", " + Print(5.0F) + ", " + Print(-6.0F) + "; " + Print(7.0F) + ", "
                + Print(-8.0F) + ", " + Print(9.0F) + ")");
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + ", " + Print(-6.0) + "; " + Print(7.0) + ", " + Print(-8.0) + ", "
                + Print(9.0) + ")");
  EXPECT_EQ(Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L).Print(),
            "(" + Print(1.0L) + ", " + Print(-2.0L) + ", " + Print(3.0L) + "; " + Print(-4.0L)
                + ", " + Print(5.0L) + ", " + Print(-6.0L) + "; " + Print(7.0L) + ", "
                + Print(-8.0L) + ", " + Print(9.0L) + ")");
}

TEST(Dyad, Set) {
  {
    Dyad dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    dyad.Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
        -10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F);
    EXPECT_EQ(dyad, Dyad(-10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F));
  }
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    dyad.Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0);
    EXPECT_EQ(dyad, Dyad(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0));
  }
  {
    Dyad dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    dyad.Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
        -10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L);
    EXPECT_EQ(dyad, Dyad(-10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L));
  }
  {
    Dyad dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    dyad.Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
        std::array<float, 9>{-10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F});
    EXPECT_EQ(dyad, Dyad(-10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F));
  }
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    dyad.Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
        std::array<double, 9>{-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0});
    EXPECT_EQ(dyad, Dyad(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0));
  }
  {
    Dyad dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    dyad.Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(std::array<long double, 9>{
        -10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L});
    EXPECT_EQ(dyad, Dyad(-10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L));
  }
  {
    Dyad dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    dyad.Set_xx(-10.0F);
    dyad.Set_xy(11.0F);
    dyad.Set_xz(-12.0F);
    dyad.Set_yx(13.0F);
    dyad.Set_yy(-14.0F);
    dyad.Set_yz(15.0F);
    dyad.Set_zx(-16.0F);
    dyad.Set_zy(17.0F);
    dyad.Set_zz(-18.0F);
    EXPECT_EQ(dyad, Dyad(-10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F));
  }
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    dyad.Set_xx(-10.0);
    dyad.Set_xy(11.0);
    dyad.Set_xz(-12.0);
    dyad.Set_yx(13.0);
    dyad.Set_yy(-14.0);
    dyad.Set_yz(15.0);
    dyad.Set_zx(-16.0);
    dyad.Set_zy(17.0);
    dyad.Set_zz(-18.0);
    EXPECT_EQ(dyad, Dyad(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0));
  }
  {
    Dyad dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    dyad.Set_xx(-10.0L);
    dyad.Set_xy(11.0L);
    dyad.Set_xz(-12.0L);
    dyad.Set_yx(13.0L);
    dyad.Set_yy(-14.0L);
    dyad.Set_yz(15.0L);
    dyad.Set_zx(-16.0L);
    dyad.Set_zy(17.0L);
    dyad.Set_zz(-18.0L);
    EXPECT_EQ(dyad, Dyad(-10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L));
  }
}

TEST(Dyad, SizeOf) {
  EXPECT_EQ(sizeof(Dyad<>{}), 9 * sizeof(double));
  EXPECT_EQ(sizeof(Dyad<float>{}), 9 * sizeof(float));
  EXPECT_EQ(sizeof(Dyad<double>{}), 9 * sizeof(double));
  EXPECT_EQ(sizeof(Dyad<long double>{}), 9 * sizeof(long double));
}

TEST(Dyad, StandardConstructor) {
  EXPECT_EQ(Dyad(std::array<float, 9>{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F}),
            Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F));
  EXPECT_EQ(Dyad(std::array<double, 9>{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}),
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  EXPECT_EQ(
      Dyad(std::array<long double, 9>{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L}),
      Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L));
  {
    Dyad dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    dyad = std::array<float, 9>{-10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F};
    EXPECT_EQ(dyad, Dyad(-10.0F, 11.0F, -12.0F, 13.0F, -14.0F, 15.0F, -16.0F, 17.0F, -18.0F));
  }
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    dyad = std::array<double, 9>{-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0};
    EXPECT_EQ(dyad, Dyad(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0));
  }
  {
    Dyad dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    dyad = std::array<long double, 9>{
        -10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L};
    EXPECT_EQ(dyad, Dyad(-10.0L, 11.0L, -12.0L, 13.0L, -14.0L, 15.0L, -16.0L, 17.0L, -18.0L));
  }
}

TEST(Dyad, Stream) {
  {
    std::ostringstream stream;
    stream << Dyad{1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F};
    EXPECT_EQ(stream.str(), Dyad(1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F).Print());
  }
  {
    std::ostringstream stream;
    stream << Dyad{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    EXPECT_EQ(stream.str(), Dyad(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0).Print());
  }
  {
    std::ostringstream stream;
    stream << Dyad{1.0L, 2.0L, 3.0L, 4.0L, 5.0L, 6.0L, 7.0L, 8.0L, 9.0L};
    EXPECT_EQ(stream.str(), Dyad(1.0L, 2.0L, 3.0L, 4.0L, 5.0L, 6.0L, 7.0L, 8.0L, 9.0L).Print());
  }
}

TEST(Dyad, Trace) {
  EXPECT_EQ(Dyad(64.0F, 4.0F, 1.0F, 16.0F, 128.0F, 8.0F, 2.0F, 32.0F, 256.0F).Trace(), 448.0F);
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Trace(), 448.0);
  EXPECT_EQ(Dyad(64.0L, 4.0L, 1.0L, 16.0L, 128.0L, 8.0L, 2.0L, 32.0L, 256.0L).Trace(), 448.0L);
}

TEST(Dyad, Transpose) {
  EXPECT_EQ(Dyad(64.0F, 4.0F, 1.0F, 16.0F, 128.0F, 8.0F, 2.0F, 32.0F, 256.0F).Transpose(),
            Dyad(64.0F, 16.0F, 2.0F, 4.0F, 128.0F, 32.0F, 1.0F, 8.0F, 256.0F));
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Transpose(),
            Dyad(64.0, 16.0, 2.0, 4.0, 128.0, 32.0, 1.0, 8.0, 256.0));
  EXPECT_EQ(Dyad(64.0L, 4.0L, 1.0L, 16.0L, 128.0L, 8.0L, 2.0L, 32.0L, 256.0L).Transpose(),
            Dyad(64.0L, 16.0L, 2.0L, 4.0L, 128.0L, 32.0L, 1.0L, 8.0L, 256.0L));
}

TEST(Dyad, XML) {
  EXPECT_EQ(
      Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F).XML(),
      "<xx>" + Print(1.0F) + "</xx><xy>" + Print(-2.0F) + "</xy><xz>" + Print(3.0F) + "</xz><yx>"
          + Print(-4.0F) + "</yx><yy>" + Print(5.0F) + "</yy><yz>" + Print(-6.0F) + "</yz><zx>"
          + Print(7.0F) + "</zx><zy>" + Print(-8.0F) + "</zy><zz>" + Print(9.0F) + "</zz>");
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).XML(),
            "<xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0) + "</xz><yx>"
                + Print(-4.0) + "</yx><yy>" + Print(5.0) + "</yy><yz>" + Print(-6.0) + "</yz><zx>"
                + Print(7.0) + "</zx><zy>" + Print(-8.0) + "</zy><zz>" + Print(9.0) + "</zz>");
  EXPECT_EQ(
      Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L).XML(),
      "<xx>" + Print(1.0L) + "</xx><xy>" + Print(-2.0L) + "</xy><xz>" + Print(3.0L) + "</xz><yx>"
          + Print(-4.0L) + "</yx><yy>" + Print(5.0L) + "</yy><yz>" + Print(-6.0L) + "</yz><zx>"
          + Print(7.0L) + "</zx><zy>" + Print(-8.0L) + "</zy><zz>" + Print(9.0L) + "</zz>");
}

TEST(Dyad, YAML) {
  EXPECT_EQ(Dyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F).YAML(),
            "{xx:" + Print(1.0F) + ",xy:" + Print(-2.0F) + ",xz:" + Print(3.0F)
                + ",yx:" + Print(-4.0F) + ",yy:" + Print(5.0F) + ",yz:" + Print(-6.0F)
                + ",zx:" + Print(7.0F) + ",zy:" + Print(-8.0F) + ",zz:" + Print(9.0F) + "}");
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).YAML(),
            "{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yx:" + Print(-4.0)
                + ",yy:" + Print(5.0) + ",yz:" + Print(-6.0) + ",zx:" + Print(7.0)
                + ",zy:" + Print(-8.0) + ",zz:" + Print(9.0) + "}");
  EXPECT_EQ(Dyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L).YAML(),
            "{xx:" + Print(1.0L) + ",xy:" + Print(-2.0L) + ",xz:" + Print(3.0L)
                + ",yx:" + Print(-4.0L) + ",yy:" + Print(5.0L) + ",yz:" + Print(-6.0L)
                + ",zx:" + Print(7.0L) + ",zy:" + Print(-8.0L) + ",zz:" + Print(9.0L) + "}");
}

TEST(Dyad, Zero) {
  EXPECT_EQ(Dyad<><>::Zero(), Dyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(Dyad<float><>::Zero(), Dyad(0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F));
  EXPECT_EQ(Dyad<double><>::Zero(), Dyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(
      Dyad<long double><>::Zero(), Dyad(0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L));
}

}  // namespace

}  // namespace PhQ
