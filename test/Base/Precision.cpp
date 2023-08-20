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

#include "../../include/PhQ/Base/Precision.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(BasePrecision, Abbreviation) {
  EXPECT_EQ(Abbreviation(Precision::Double), "Double");
  EXPECT_EQ(Abbreviation(Precision::Single), "Single");
}

TEST(BasePrecision, Parse) {
  EXPECT_EQ(Parse<Precision>("DOUBLE"), Precision::Double);
  EXPECT_EQ(Parse<Precision>("Double"), Precision::Double);
  EXPECT_EQ(Parse<Precision>("double"), Precision::Double);
  EXPECT_EQ(Parse<Precision>("SINGLE"), Precision::Single);
  EXPECT_EQ(Parse<Precision>("Single"), Precision::Single);
  EXPECT_EQ(Parse<Precision>("single"), Precision::Single);
}

}  // namespace

}  // namespace PhQ
