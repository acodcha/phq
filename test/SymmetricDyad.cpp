// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/SymmetricDyad.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>
#include <utility>

#include "../include/PhQ/Base.hpp"
#include "../include/PhQ/PlanarVector.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(SymmetricDyad, Adjugate) {
  EXPECT_EQ(SymmetricDyad(8.0F, 2.0F, 1.0F, 16.0F, 4.0F, 32.0F).Adjugate(),
            SymmetricDyad(496.0F, -60.0F, -8.0F, 255.0F, -30.0F, 124.0F));
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Adjugate(),
            SymmetricDyad(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
  EXPECT_EQ(SymmetricDyad(8.0L, 2.0L, 1.0L, 16.0L, 4.0L, 32.0L).Adjugate(),
            SymmetricDyad(496.0L, -60.0L, -8.0L, 255.0L, -30.0L, 124.0L));
}

TEST(SymmetricDyad, ArithmeticOperatorAddition) {
  EXPECT_EQ(SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F)
                + SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F),
            SymmetricDyad(3.0F, -6.0F, 9.0F, -12.0F, 15.0F, -18.0F));
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0)
                + SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0),
            SymmetricDyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0));
  EXPECT_EQ(SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L)
                + SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L),
            SymmetricDyad(3.0L, -6.0L, 9.0L, -12.0L, 15.0L, -18.0L));
}

TEST(SymmetricDyad, ArithmeticOperatorDivision) {
  EXPECT_EQ(SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F) / 2.0F,
            SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  EXPECT_EQ(SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F) / 2.0,
            SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  EXPECT_EQ(SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F) / 2.0L,
            SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  EXPECT_EQ(SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0) / 2.0F,
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0) / 2.0,
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0) / 2.0L,
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L) / 2.0F,
            SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  EXPECT_EQ(SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L) / 2.0,
            SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  EXPECT_EQ(SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L) / 2.0L,
            SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
}

TEST(SymmetricDyad, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F) * 2.0F,
            SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F));
  EXPECT_EQ(SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F) * 2.0,
            SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F));
  EXPECT_EQ(SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F) * 2.0L,
            SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F));
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * 2.0F,
            SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * 2.0,
            SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * 2.0L,
            SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  EXPECT_EQ(SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L) * 2.0F,
            SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L));
  EXPECT_EQ(SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L) * 2.0,
            SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L));
  EXPECT_EQ(SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L) * 2.0L,
            SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L));
  EXPECT_EQ(2.0F * SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F),
            SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F));
  EXPECT_EQ(2.0 * SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F),
            SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F));
  EXPECT_EQ(2.0L * SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F),
            SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F));
  EXPECT_EQ(2.0F * SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0),
            SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  EXPECT_EQ(2.0 * SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0),
            SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  EXPECT_EQ(2.0L * SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0),
            SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  EXPECT_EQ(2.0F * SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L),
            SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L));
  EXPECT_EQ(2.0 * SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L),
            SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L));
  EXPECT_EQ(2.0L * SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L),
            SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L));
  EXPECT_EQ(SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F) * PlanarVector(1.0F, -2.0F),
            Vector(5.0F, 6.0F, -7.0F));
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * PlanarVector(1.0, -2.0),
            Vector(5.0, 6.0, -7.0));
  EXPECT_EQ(SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L) * PlanarVector(1.0L, -2.0L),
            Vector(5.0L, 6.0L, -7.0L));
  EXPECT_EQ(SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F) * Vector(1.0F, -2.0F, 3.0F),
            Vector(14.0F, 21.0F, -25.0F));
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * Vector(1.0, -2.0, 3.0),
            Vector(14.0, 21.0, -25.0));
  EXPECT_EQ(SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L) * Vector(1.0L, -2.0L, 3.0L),
            Vector(14.0L, 21.0L, -25.0L));
}

TEST(SymmetricDyad, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(SymmetricDyad(3.0F, -6.0F, 9.0F, -12.0F, 15.0F, -18.0F)
                - SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F),
            SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  EXPECT_EQ(SymmetricDyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0)
                - SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(SymmetricDyad(3.0L, -6.0L, 9.0L, -12.0L, 15.0L, -18.0L)
                - SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L),
            SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
}

TEST(SymmetricDyad, AssignmentOperatorAddition) {
  {
    SymmetricDyad symmetric_dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    symmetric_dyad += SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(3.0F, -6.0F, 9.0F, -12.0F, 15.0F, -18.0F));
  }
  {
    SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    symmetric_dyad += SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0));
  }
  {
    SymmetricDyad symmetric_dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    symmetric_dyad += SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(3.0L, -6.0L, 9.0L, -12.0L, 15.0L, -18.0L));
  }
}

TEST(SymmetricDyad, AssignmentOperatorDivision) {
  {
    SymmetricDyad symmetric_dyad{2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F};
    symmetric_dyad /= 2.0F;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    SymmetricDyad symmetric_dyad{2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F};
    symmetric_dyad /= 2.0;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    SymmetricDyad symmetric_dyad{2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F};
    symmetric_dyad /= 2.0L;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    SymmetricDyad symmetric_dyad{2.0, -4.0, 6.0, -8.0, 10.0, -12.0};
    symmetric_dyad /= 2.0F;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    SymmetricDyad symmetric_dyad{2.0, -4.0, 6.0, -8.0, 10.0, -12.0};
    symmetric_dyad /= 2.0;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    SymmetricDyad symmetric_dyad{2.0, -4.0, 6.0, -8.0, 10.0, -12.0};
    symmetric_dyad /= 2.0L;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    SymmetricDyad symmetric_dyad{2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L};
    symmetric_dyad /= 2.0F;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
  {
    SymmetricDyad symmetric_dyad{2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L};
    symmetric_dyad /= 2.0;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
  {
    SymmetricDyad symmetric_dyad{2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L};
    symmetric_dyad /= 2.0L;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
}

TEST(SymmetricDyad, AssignmentOperatorMultiplication) {
  {
    SymmetricDyad symmetric_dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    symmetric_dyad *= 2.0F;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F));
  }
  {
    SymmetricDyad symmetric_dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    symmetric_dyad *= 2.0;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F));
  }
  {
    SymmetricDyad symmetric_dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    symmetric_dyad *= 2.0L;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F));
  }
  {
    SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    symmetric_dyad *= 2.0F;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  }
  {
    SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    symmetric_dyad *= 2.0;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  }
  {
    SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    symmetric_dyad *= 2.0L;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  }
  {
    SymmetricDyad symmetric_dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    symmetric_dyad *= 2.0F;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L));
  }
  {
    SymmetricDyad symmetric_dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    symmetric_dyad *= 2.0;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L));
  }
  {
    SymmetricDyad symmetric_dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    symmetric_dyad *= 2.0L;
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L));
  }
}

TEST(SymmetricDyad, AssignmentOperatorSubtraction) {
  {
    SymmetricDyad symmetric_dyad{3.0F, -6.0F, 9.0F, -12.0F, 15.0F, -18.0F};
    symmetric_dyad -= SymmetricDyad(2.0F, -4.0F, 6.0F, -8.0F, 10.0F, -12.0F);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    SymmetricDyad symmetric_dyad{3.0, -6.0, 9.0, -12.0, 15.0, -18.0};
    symmetric_dyad -= SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    SymmetricDyad symmetric_dyad{3.0L, -6.0L, 9.0L, -12.0L, 15.0L, -18.0L};
    symmetric_dyad -= SymmetricDyad(2.0L, -4.0L, 6.0L, -8.0L, 10.0L, -12.0L);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
}

TEST(SymmetricDyad, Cofactors) {
  EXPECT_EQ(SymmetricDyad(8.0F, 2.0F, 1.0F, 16.0F, 4.0F, 32.0F).Cofactors(),
            SymmetricDyad(496.0F, -60.0F, -8.0F, 255.0F, -30.0F, 124.0F));
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Cofactors(),
            SymmetricDyad(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
  EXPECT_EQ(SymmetricDyad(8.0L, 2.0L, 1.0L, 16.0L, 4.0L, 32.0L).Cofactors(),
            SymmetricDyad(496.0L, -60.0L, -8.0L, 255.0L, -30.0L, 124.0L));
}

TEST(SymmetricDyad, ComparisonOperators) {
  {
    constexpr SymmetricDyad first{1.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    constexpr SymmetricDyad second{2.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_GT(second, first);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
  }
  {
    constexpr SymmetricDyad first{1.0, -2.0, 0.0, 0.0, 0.0, 0.0};
    constexpr SymmetricDyad second{1.0, -1.0, 0.0, 0.0, 0.0, 0.0};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_GT(second, first);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
  }
  {
    constexpr SymmetricDyad first{1.0, -2.0, 3.0, 0.0, 0.0, 0.0};
    constexpr SymmetricDyad second{1.0, -2.0, 4.0, 0.0, 0.0, 0.0};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_GT(second, first);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
  }
  {
    constexpr SymmetricDyad first{1.0, -2.0, 3.0, -4.0, 0.0, 0.0};
    constexpr SymmetricDyad second{1.0, -2.0, 3.0, -3.0, 0.0, 0.0};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_GT(second, first);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
  }
  {
    constexpr SymmetricDyad first{1.0, -2.0, 3.0, -4.0, 5.0, 0.0};
    constexpr SymmetricDyad second{1.0, -2.0, 3.0, -4.0, 6.0, 0.0};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_GT(second, first);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
  }
  {
    constexpr SymmetricDyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.000001F};
    constexpr SymmetricDyad second{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_GT(second, first);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
  }
  {
    constexpr SymmetricDyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.000001};
    constexpr SymmetricDyad second{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_GT(second, first);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
  }
  {
    constexpr SymmetricDyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.000001L};
    constexpr SymmetricDyad second{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_GT(second, first);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
  }
}

TEST(SymmetricDyad, Constructor) {
  EXPECT_EQ(SymmetricDyad(std::array<float, 6>{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F}),
            SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  EXPECT_EQ(SymmetricDyad(std::array<double, 6>{1.0, -2.0, 3.0, -4.0, 5.0, -6.0}),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(SymmetricDyad(std::array<long double, 6>{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L}),
            SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  {
    SymmetricDyad symmetric_dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    symmetric_dyad = std::array<float, 6>{-7.0F, 8.0F, -9.0F, 10.0F, -11.0F, 12.0F};
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0F, 8.0F, -9.0F, 10.0F, -11.0F, 12.0F));
  }
  {
    SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    symmetric_dyad = std::array<double, 6>{7.0, -8.0, 9.0, -10.0, 11.0, -12.0};
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(7.0, -8.0, 9.0, -10.0, 11.0, -12.0));
  }
  {
    SymmetricDyad symmetric_dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    symmetric_dyad = std::array<long double, 6>{-7.0L, 8.0L, -9.0L, 10.0L, -11.0L, 12.0L};
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0L, 8.0L, -9.0L, 10.0L, -11.0L, 12.0L));
  }
}

TEST(SymmetricDyad, CopyAssignmentOperator) {
  {
    constexpr SymmetricDyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    SymmetricDyad second{7.0F, -8.0F, 9.0F, -10.0F, 11.0F, -12.0F};
    second = first;
    EXPECT_EQ(second, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    constexpr SymmetricDyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    SymmetricDyad second{7.0, -8.0, 9.0, -10.0, 11.0, -12.0};
    second = first;
    EXPECT_EQ(second, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    constexpr SymmetricDyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    SymmetricDyad second{7.0L, -8.0L, 9.0L, -10.0L, 11.0L, -12.0L};
    second = first;
    EXPECT_EQ(second, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
  {
    constexpr SymmetricDyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    SymmetricDyad second{7.0F, -8.0F, 9.0F, -10.0F, 11.0F, -12.0F};
    second = first;
    EXPECT_EQ(second, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    constexpr SymmetricDyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    SymmetricDyad second{7.0, -8.0, 9.0, -10.0, 11.0, -12.0};
    second = first;
    EXPECT_EQ(second, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    constexpr SymmetricDyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    SymmetricDyad second{7.0L, -8.0L, 9.0L, -10.0L, 11.0L, -12.0L};
    second = first;
    EXPECT_EQ(second, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
  {
    constexpr SymmetricDyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    SymmetricDyad second{7.0F, -8.0F, 9.0F, -10.0F, 11.0F, -12.0F};
    second = first;
    EXPECT_EQ(second, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    constexpr SymmetricDyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    SymmetricDyad second{7.0, -8.0, 9.0, -10.0, 11.0, -12.0};
    second = first;
    EXPECT_EQ(second, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    constexpr SymmetricDyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    SymmetricDyad second{7.0L, -8.0L, 9.0L, -10.0L, 11.0L, -12.0L};
    second = first;
    EXPECT_EQ(second, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
}

TEST(SymmetricDyad, CopyConstructor) {
  {
    constexpr SymmetricDyad first(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F);
    constexpr SymmetricDyad<float> second{first};
    EXPECT_EQ(second, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    constexpr SymmetricDyad first(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F);
    constexpr SymmetricDyad<double> second{first};
    EXPECT_EQ(second, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    constexpr SymmetricDyad first(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F);
    constexpr SymmetricDyad<long double> second{first};
    EXPECT_EQ(second, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
  {
    constexpr SymmetricDyad first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    constexpr SymmetricDyad<float> second{first};
    EXPECT_EQ(second, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    constexpr SymmetricDyad first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    constexpr SymmetricDyad<double> second{first};
    EXPECT_EQ(second, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    constexpr SymmetricDyad first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    constexpr SymmetricDyad<long double> second{first};
    EXPECT_EQ(second, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
  {
    constexpr SymmetricDyad first(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L);
    constexpr SymmetricDyad<float> second{first};
    EXPECT_EQ(second, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    constexpr SymmetricDyad first(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L);
    constexpr SymmetricDyad<double> second{first};
    EXPECT_EQ(second, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    constexpr SymmetricDyad first(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L);
    constexpr SymmetricDyad<long double> second{first};
    EXPECT_EQ(second, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
}

TEST(SymmetricDyad, DefaultConstructor) {
  EXPECT_NO_THROW(SymmetricDyad{});
  EXPECT_NO_THROW(SymmetricDyad<>{});
  EXPECT_NO_THROW(SymmetricDyad<float>{});
  EXPECT_NO_THROW(SymmetricDyad<double>{});
  EXPECT_NO_THROW(SymmetricDyad<long double>{});
}

TEST(SymmetricDyad, Determinant) {
  EXPECT_EQ(SymmetricDyad(8.0F, 2.0F, 1.0F, 16.0F, 4.0F, 32.0F).Determinant(), 3840.0F);
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Determinant(), 3840.0);
  EXPECT_EQ(SymmetricDyad(8.0L, 2.0L, 1.0L, 16.0L, 4.0L, 32.0L).Determinant(), 3840.0L);
}

TEST(SymmetricDyad, Hash) {
  {
    constexpr SymmetricDyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    constexpr SymmetricDyad second{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.000001F};
    constexpr SymmetricDyad third{1.0F, -2.0F, 3.0F, 4.0F, 5.0F, -6.0F};
    constexpr std::hash<SymmetricDyad<float>> hasher;
    EXPECT_NE(hasher(first), hasher(second));
    EXPECT_NE(hasher(first), hasher(third));
    EXPECT_NE(hasher(second), hasher(third));
  }
  {
    constexpr SymmetricDyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    constexpr SymmetricDyad second{1.0, -2.0, 3.0, -4.0, 5.0, -6.000001};
    constexpr SymmetricDyad third{1.0, -2.0, 3.0, 4.0, 5.0, -6.0};
    constexpr std::hash<SymmetricDyad<>> hasher;
    EXPECT_NE(hasher(first), hasher(second));
    EXPECT_NE(hasher(first), hasher(third));
    EXPECT_NE(hasher(second), hasher(third));
  }
  {
    constexpr SymmetricDyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    constexpr SymmetricDyad second{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.000001L};
    constexpr SymmetricDyad third{1.0L, -2.0L, 3.0L, 4.0L, 5.0L, -6.0L};
    constexpr std::hash<SymmetricDyad<long double>> hasher;
    EXPECT_NE(hasher(first), hasher(second));
    EXPECT_NE(hasher(first), hasher(third));
    EXPECT_NE(hasher(second), hasher(third));
  }
}

TEST(SymmetricDyad, Inverse) {
  {
    constexpr SymmetricDyad symmetric_dyad{8.0F, 2.0F, 1.0F, 16.0F, 4.0F, 32.0F};
    const std::optional<SymmetricDyad<float>> inverse{symmetric_dyad.Inverse()};
    ASSERT_TRUE(inverse.has_value());
    EXPECT_DOUBLE_EQ(inverse.value().xx(), 496.0F / 3840.0F);
    EXPECT_DOUBLE_EQ(inverse.value().xy(), -60.0F / 3840.0F);
    EXPECT_DOUBLE_EQ(inverse.value().xz(), -8.0F / 3840.0F);
    EXPECT_DOUBLE_EQ(inverse.value().yy(), 255.0F / 3840.0F);
    EXPECT_DOUBLE_EQ(inverse.value().yz(), -30.0F / 3840.0F);
    EXPECT_DOUBLE_EQ(inverse.value().zz(), 124.0F / 3840.0F);
  }
  {
    constexpr SymmetricDyad symmetric_dyad{8.0, 2.0, 1.0, 16.0, 4.0, 32.0};
    const std::optional<SymmetricDyad<>> inverse{symmetric_dyad.Inverse()};
    ASSERT_TRUE(inverse.has_value());
    EXPECT_DOUBLE_EQ(inverse.value().xx(), 496.0 / 3840.0);
    EXPECT_DOUBLE_EQ(inverse.value().xy(), -60.0 / 3840.0);
    EXPECT_DOUBLE_EQ(inverse.value().xz(), -8.0 / 3840.0);
    EXPECT_DOUBLE_EQ(inverse.value().yy(), 255.0 / 3840.0);
    EXPECT_DOUBLE_EQ(inverse.value().yz(), -30.0 / 3840.0);
    EXPECT_DOUBLE_EQ(inverse.value().zz(), 124.0 / 3840.0);
  }
  {
    constexpr SymmetricDyad symmetric_dyad{8.0L, 2.0L, 1.0L, 16.0L, 4.0L, 32.0L};
    const std::optional<SymmetricDyad<long double>> inverse{symmetric_dyad.Inverse()};
    ASSERT_TRUE(inverse.has_value());
    EXPECT_DOUBLE_EQ(inverse.value().xx(), 496.0L / 3840.0L);
    EXPECT_DOUBLE_EQ(inverse.value().xy(), -60.0L / 3840.0L);
    EXPECT_DOUBLE_EQ(inverse.value().xz(), -8.0L / 3840.0L);
    EXPECT_DOUBLE_EQ(inverse.value().yy(), 255.0L / 3840.0L);
    EXPECT_DOUBLE_EQ(inverse.value().yz(), -30.0L / 3840.0L);
    EXPECT_DOUBLE_EQ(inverse.value().zz(), 124.0L / 3840.0L);
  }
  {
    constexpr SymmetricDyad symmetric_dyad{0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F};
    const std::optional<SymmetricDyad<float>> inverse{symmetric_dyad.Inverse()};
    EXPECT_FALSE(inverse.has_value());
  }
  {
    constexpr SymmetricDyad symmetric_dyad{0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    const std::optional<SymmetricDyad<>> inverse{symmetric_dyad.Inverse()};
    EXPECT_FALSE(inverse.has_value());
  }
  {
    constexpr SymmetricDyad symmetric_dyad{0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L};
    const std::optional<SymmetricDyad<long double>> inverse{symmetric_dyad.Inverse()};
    EXPECT_FALSE(inverse.has_value());
  }
}

TEST(SymmetricDyad, JSON) {
  EXPECT_EQ(
      SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F).JSON(),
      "{\"xx\":" + Print(1.0F) + ",\"xy\":" + Print(-2.0F) + ",\"xz\":" + Print(3.0F)
          + ",\"yy\":" + Print(-4.0F) + ",\"yz\":" + Print(5.0F) + ",\"zz\":" + Print(-6.0F) + "}");
  EXPECT_EQ(
      SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).JSON(),
      "{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
          + ",\"yy\":" + Print(-4.0) + ",\"yz\":" + Print(5.0) + ",\"zz\":" + Print(-6.0) + "}");
  EXPECT_EQ(
      SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L).JSON(),
      "{\"xx\":" + Print(1.0L) + ",\"xy\":" + Print(-2.0L) + ",\"xz\":" + Print(3.0L)
          + ",\"yy\":" + Print(-4.0L) + ",\"yz\":" + Print(5.0L) + ",\"zz\":" + Print(-6.0L) + "}");
}

TEST(SymmetricDyad, MoveAssignmentOperator) {
  {
    SymmetricDyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    SymmetricDyad second{7.0F, -8.0F, 9.0F, -10.0F, 11.0F, -12.0F};
    second = std::move(first);
    EXPECT_EQ(second, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    SymmetricDyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    SymmetricDyad second{7.0, -8.0, 9.0, -10.0, 11.0, -12.0};
    second = std::move(first);
    EXPECT_EQ(second, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    SymmetricDyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    SymmetricDyad second{7.0L, -8.0L, 9.0L, -10.0L, 11.0L, -12.0L};
    second = std::move(first);
    EXPECT_EQ(second, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
}

TEST(SymmetricDyad, MoveConstructor) {
  {
    SymmetricDyad first{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    const SymmetricDyad second{std::move(first)};
    EXPECT_EQ(second, SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  }
  {
    SymmetricDyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    const SymmetricDyad second{std::move(first)};
    EXPECT_EQ(second, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
  {
    SymmetricDyad first{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    const SymmetricDyad second{std::move(first)};
    EXPECT_EQ(second, SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
  }
}

TEST(SymmetricDyad, Mutable) {
  {
    SymmetricDyad symmetric_dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    std::array<float, 6>& mutable_xx_xy_xz_yy_yz_zz = symmetric_dyad.Mutable_xx_xy_xz_yy_yz_zz();
    mutable_xx_xy_xz_yy_yz_zz = {-7.0F, 8.0F, -9.0F, 10.0F, -11.0F, 12.0F};
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0F, 8.0F, -9.0F, 10.0F, -11.0F, 12.0F));
  }
  {
    SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    std::array<double, 6>& mutable_xx_xy_xz_yy_yz_zz = symmetric_dyad.Mutable_xx_xy_xz_yy_yz_zz();
    mutable_xx_xy_xz_yy_yz_zz = {-7.0, 8.0, -9.0, 10.0, -11.0, 12.0};
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  }
  {
    SymmetricDyad symmetric_dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    std::array<long double, 6>& mutable_xx_xy_xz_yy_yz_zz =
        symmetric_dyad.Mutable_xx_xy_xz_yy_yz_zz();
    mutable_xx_xy_xz_yy_yz_zz = {-7.0L, 8.0L, -9.0L, 10.0L, -11.0L, 12.0L};
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0L, 8.0L, -9.0L, 10.0L, -11.0L, 12.0L));
  }
  {
    SymmetricDyad second{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    float& mutable_xx = second.Mutable_xx();
    mutable_xx = -7.0F;
    float& mutable_xy = second.Mutable_xy();
    mutable_xy = 8.0F;
    float& mutable_xz = second.Mutable_xz();
    mutable_xz = -9.0F;
    float& mutable_yy = second.Mutable_yy();
    mutable_yy = 10.0F;
    float& mutable_yz = second.Mutable_yz();
    mutable_yz = -11.0F;
    float& mutable_zz = second.Mutable_zz();
    mutable_zz = 12.0F;
    EXPECT_EQ(second.xx(), -7.0F);
    EXPECT_EQ(second.xy(), 8.0F);
    EXPECT_EQ(second.xz(), -9.0F);
    EXPECT_EQ(second.yy(), 10.0F);
    EXPECT_EQ(second.yz(), -11.0F);
    EXPECT_EQ(second.zz(), 12.0F);
  }
  {
    SymmetricDyad second{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    double& mutable_xx = second.Mutable_xx();
    mutable_xx = -7.0;
    double& mutable_xy = second.Mutable_xy();
    mutable_xy = 8.0;
    double& mutable_xz = second.Mutable_xz();
    mutable_xz = -9.0;
    double& mutable_yy = second.Mutable_yy();
    mutable_yy = 10.0;
    double& mutable_yz = second.Mutable_yz();
    mutable_yz = -11.0;
    double& mutable_zz = second.Mutable_zz();
    mutable_zz = 12.0;
    EXPECT_EQ(second.xx(), -7.0);
    EXPECT_EQ(second.xy(), 8.0);
    EXPECT_EQ(second.xz(), -9.0);
    EXPECT_EQ(second.yy(), 10.0);
    EXPECT_EQ(second.yz(), -11.0);
    EXPECT_EQ(second.zz(), 12.0);
  }
  {
    SymmetricDyad second{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    long double& mutable_xx = second.Mutable_xx();
    mutable_xx = -7.0L;
    long double& mutable_xy = second.Mutable_xy();
    mutable_xy = 8.0L;
    long double& mutable_xz = second.Mutable_xz();
    mutable_xz = -9.0L;
    long double& mutable_yy = second.Mutable_yy();
    mutable_yy = 10.0L;
    long double& mutable_yz = second.Mutable_yz();
    mutable_yz = -11.0L;
    long double& mutable_zz = second.Mutable_zz();
    mutable_zz = 12.0L;
    EXPECT_EQ(second.xx(), -7.0L);
    EXPECT_EQ(second.xy(), 8.0L);
    EXPECT_EQ(second.xz(), -9.0L);
    EXPECT_EQ(second.yy(), 10.0L);
    EXPECT_EQ(second.yz(), -11.0L);
    EXPECT_EQ(second.zz(), 12.0L);
  }
  {
    SymmetricDyad symmetric_dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    float& mutable_yx = symmetric_dyad.Mutable_yx();
    mutable_yx = -13.0F;
    float& mutable_zx = symmetric_dyad.Mutable_zx();
    mutable_zx = 14.0F;
    float& mutable_zy = symmetric_dyad.Mutable_zy();
    mutable_zy = -15.0F;
    EXPECT_EQ(symmetric_dyad.yx(), -13.0F);
    EXPECT_EQ(symmetric_dyad.zx(), 14.0F);
    EXPECT_EQ(symmetric_dyad.zy(), -15.0F);
  }
  {
    SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    double& mutable_yx = symmetric_dyad.Mutable_yx();
    mutable_yx = -13.0;
    double& mutable_zx = symmetric_dyad.Mutable_zx();
    mutable_zx = 14.0;
    double& mutable_zy = symmetric_dyad.Mutable_zy();
    mutable_zy = -15.0;
    EXPECT_EQ(symmetric_dyad.yx(), -13.0);
    EXPECT_EQ(symmetric_dyad.zx(), 14.0);
    EXPECT_EQ(symmetric_dyad.zy(), -15.0);
  }
  {
    SymmetricDyad symmetric_dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    long double& mutable_yx = symmetric_dyad.Mutable_yx();
    mutable_yx = -13.0L;
    long double& mutable_zx = symmetric_dyad.Mutable_zx();
    mutable_zx = 14.0L;
    long double& mutable_zy = symmetric_dyad.Mutable_zy();
    mutable_zy = -15.0L;
    EXPECT_EQ(symmetric_dyad.yx(), -13.0L);
    EXPECT_EQ(symmetric_dyad.zx(), 14.0L);
    EXPECT_EQ(symmetric_dyad.zy(), -15.0L);
  }
}

TEST(SymmetricDyad, Print) {
  EXPECT_EQ(SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F).Print(),
            "(" + Print(1.0F) + ", " + Print(-2.0F) + ", " + Print(3.0F) + "; " + Print(-4.0F)
                + ", " + Print(5.0F) + "; " + Print(-6.0F) + ")");
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + "; " + Print(-6.0) + ")");
  EXPECT_EQ(SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L).Print(),
            "(" + Print(1.0L) + ", " + Print(-2.0L) + ", " + Print(3.0L) + "; " + Print(-4.0L)
                + ", " + Print(5.0L) + "; " + Print(-6.0L) + ")");
}

TEST(SymmetricDyad, Set) {
  {
    SymmetricDyad symmetric_dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    symmetric_dyad.Set_xx_xy_xz_yy_yz_zz(
        std::array<float, 6>{-7.0F, 8.0F, -9.0F, 10.0F, -11.0F, 12.0F});
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0F, 8.0F, -9.0F, 10.0F, -11.0F, 12.0F));
  }
  {
    SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    symmetric_dyad.Set_xx_xy_xz_yy_yz_zz(std::array<double, 6>{-7.0, 8.0, -9.0, 10.0, -11.0, 12.0});
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  }
  {
    SymmetricDyad symmetric_dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    symmetric_dyad.Set_xx_xy_xz_yy_yz_zz(
        std::array<long double, 6>{-7.0L, 8.0L, -9.0L, 10.0L, -11.0L, 12.0L});
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0L, 8.0L, -9.0L, 10.0L, -11.0L, 12.0L));
  }
  {
    SymmetricDyad symmetric_dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    symmetric_dyad.Set_xx_xy_xz_yy_yz_zz(-7.0F, 8.0F, -9.0F, 10.0F, -11.0F, 12.0F);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0F, 8.0F, -9.0F, 10.0F, -11.0F, 12.0F));
  }
  {
    SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    symmetric_dyad.Set_xx_xy_xz_yy_yz_zz(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  }
  {
    SymmetricDyad symmetric_dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    symmetric_dyad.Set_xx_xy_xz_yy_yz_zz(-7.0L, 8.0L, -9.0L, 10.0L, -11.0L, 12.0L);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0L, 8.0L, -9.0L, 10.0L, -11.0L, 12.0L));
  }
  {
    SymmetricDyad symmetric_dyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    symmetric_dyad.Set_xx(-7.0F);
    symmetric_dyad.Set_xy(8.0F);
    symmetric_dyad.Set_xz(-9.0F);
    symmetric_dyad.Set_yy(10.0F);
    symmetric_dyad.Set_yz(-11.0F);
    symmetric_dyad.Set_zz(12.0F);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0F, 8.0F, -9.0F, 10.0F, -11.0F, 12.0F));
  }
  {
    SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    symmetric_dyad.Set_xx(-7.0);
    symmetric_dyad.Set_xy(8.0);
    symmetric_dyad.Set_xz(-9.0);
    symmetric_dyad.Set_yy(10.0);
    symmetric_dyad.Set_yz(-11.0);
    symmetric_dyad.Set_zz(12.0);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  }
  {
    SymmetricDyad symmetric_dyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    symmetric_dyad.Set_xx(-7.0L);
    symmetric_dyad.Set_xy(8.0L);
    symmetric_dyad.Set_xz(-9.0L);
    symmetric_dyad.Set_yy(10.0L);
    symmetric_dyad.Set_yz(-11.0L);
    symmetric_dyad.Set_zz(12.0L);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0L, 8.0L, -9.0L, 10.0L, -11.0L, 12.0L));
  }
}

TEST(SymmetricDyad, SizeOf) {
  EXPECT_EQ(sizeof(SymmetricDyad<>{}), 6 * sizeof(double));
  EXPECT_EQ(sizeof(SymmetricDyad<float>{}), 6 * sizeof(float));
  EXPECT_EQ(sizeof(SymmetricDyad<double>{}), 6 * sizeof(double));
  EXPECT_EQ(sizeof(SymmetricDyad<long double>{}), 6 * sizeof(long double));
}

TEST(SymmetricDyad, Stream) {
  {
    std::ostringstream stream;
    stream << SymmetricDyad{1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F};
    EXPECT_EQ(stream.str(), SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F).Print());
  }
  {
    std::ostringstream stream;
    stream << SymmetricDyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    EXPECT_EQ(stream.str(), SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).Print());
  }
  {
    std::ostringstream stream;
    stream << SymmetricDyad{1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L};
    EXPECT_EQ(stream.str(), SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L).Print());
  }
}

TEST(SymmetricDyad, Trace) {
  EXPECT_EQ(SymmetricDyad(1.0F, 2.0F, 4.0F, 8.0F, 16.0F, 32.0F).Trace(), 41.0F);
  EXPECT_EQ(SymmetricDyad(1.0, 2.0, 4.0, 8.0, 16.0, 32.0).Trace(), 41.0);
  EXPECT_EQ(SymmetricDyad(1.0L, 2.0L, 4.0L, 8.0L, 16.0L, 32.0L).Trace(), 41.0L);
}

TEST(SymmetricDyad, Transpose) {
  EXPECT_EQ(SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F).Transpose(),
            SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F));
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).Transpose(),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L).Transpose(),
            SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L));
}

TEST(SymmetricDyad, XML) {
  EXPECT_EQ(
      SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F).XML(),
      "<xx>" + Print(1.0F) + "</xx><xy>" + Print(-2.0F) + "</xy><xz>" + Print(3.0F) + "</xz><yy>"
          + Print(-4.0F) + "</yy><yz>" + Print(5.0F) + "</yz><zz>" + Print(-6.0F) + "</zz>");
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).XML(),
            "<xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0) + "</xz><yy>"
                + Print(-4.0) + "</yy><yz>" + Print(5.0) + "</yz><zz>" + Print(-6.0) + "</zz>");
  EXPECT_EQ(
      SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L).XML(),
      "<xx>" + Print(1.0L) + "</xx><xy>" + Print(-2.0L) + "</xy><xz>" + Print(3.0L) + "</xz><yy>"
          + Print(-4.0L) + "</yy><yz>" + Print(5.0L) + "</yz><zz>" + Print(-6.0L) + "</zz>");
}

TEST(SymmetricDyad, YAML) {
  EXPECT_EQ(SymmetricDyad(1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F).YAML(),
            "{xx:" + Print(1.0F) + ",xy:" + Print(-2.0F) + ",xz:" + Print(3.0F)
                + ",yy:" + Print(-4.0F) + ",yz:" + Print(5.0F) + ",zz:" + Print(-6.0F) + "}");
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).YAML(),
            "{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yy:" + Print(-4.0)
                + ",yz:" + Print(5.0) + ",zz:" + Print(-6.0) + "}");
  EXPECT_EQ(SymmetricDyad(1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L).YAML(),
            "{xx:" + Print(1.0L) + ",xy:" + Print(-2.0L) + ",xz:" + Print(3.0L)
                + ",yy:" + Print(-4.0L) + ",yz:" + Print(5.0L) + ",zz:" + Print(-6.0L) + "}");
}

TEST(SymmetricDyad, Zero) {
  EXPECT_EQ(SymmetricDyad<>::Zero(), SymmetricDyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(SymmetricDyad<float>::Zero(), SymmetricDyad(0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F));
  EXPECT_EQ(SymmetricDyad<double>::Zero(), SymmetricDyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(SymmetricDyad<long double>::Zero(), SymmetricDyad(0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L));
}

}  // namespace

}  // namespace PhQ
