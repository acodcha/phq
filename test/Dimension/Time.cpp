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

#include "../../include/PhQ/Dimension/Time.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionTime, Abbreviation) { EXPECT_EQ(Time::Abbreviation(), "T"); }

TEST(DimensionTime, Accessor) {
  EXPECT_EQ(Time{}.Value(), 0);
  EXPECT_EQ(Time{-2}.Value(), -2);
  EXPECT_EQ(Time{-1}.Value(), -1);
  EXPECT_EQ(Time{0}.Value(), 0);
  EXPECT_EQ(Time{1}.Value(), 1);
  EXPECT_EQ(Time{2}.Value(), 2);
  EXPECT_EQ(Time{3}.Value(), 3);
}

TEST(DimensionTime, Comparison) {
  const Time time0{-1};
  const Time time1{2};
  EXPECT_EQ(time0, time0);
  EXPECT_NE(time0, time1);
  EXPECT_LT(time0, time1);
  EXPECT_LE(time0, time0);
  EXPECT_LE(time0, time1);
  EXPECT_GT(time1, time0);
  EXPECT_GE(time1, time0);
  EXPECT_GE(time0, time0);
  const std::set<Time> increasing{time0, time1};
  EXPECT_EQ(*increasing.begin(), time0);
  const std::set<Time, std::greater<Time>> decreasing{time0, time1};
  EXPECT_EQ(*decreasing.begin(), time1);
}

TEST(DimensionTime, Hash) {
  const Time time0{-2};
  const Time time1{-1};
  const Time time2{0};
  const Time time3{1};
  const Time time4{2};
  const Time time5{3};
  const std::hash<Time> hasher;
  EXPECT_NE(hasher(time0), hasher(time1));
  EXPECT_NE(hasher(time0), hasher(time2));
  EXPECT_NE(hasher(time0), hasher(time3));
  EXPECT_NE(hasher(time0), hasher(time4));
  EXPECT_NE(hasher(time0), hasher(time5));
  const std::unordered_set<Time> unordered{time0, time1, time2,
                                           time3, time4, time5};
}

TEST(DimensionTime, Label) { EXPECT_EQ(Time::Label(), "Time"); }

TEST(DimensionTime, Print) {
  EXPECT_EQ(Time{}.Print(), "");
  EXPECT_EQ(Time{-2}.Print(), "T^(-2)");
  EXPECT_EQ(Time{-1}.Print(), "T^(-1)");
  EXPECT_EQ(Time{0}.Print(), "");
  EXPECT_EQ(Time{1}.Print(), "T");
  EXPECT_EQ(Time{2}.Print(), "T^2");
  EXPECT_EQ(Time{3}.Print(), "T^3");
}

TEST(DimensionTime, Stream) {
  const Time time{3};
  std::ostringstream stream;
  stream << time;
  EXPECT_EQ(stream.str(), time.Print());
}

}  // namespace

}  // namespace PhQ::Dimension
