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

#include "../include/PhQ/Time.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Time, Accessor) {
  const Time time{10.0, Unit::Time::Second};
  EXPECT_DOUBLE_EQ(time.Value(), 10.0);
  EXPECT_DOUBLE_EQ(time.Value(Unit::Time::Minute), 10.0 / 60.0);
}

TEST(Time, Arithmetic) {
  const Time time0{1.0, Unit::Time::Second};
  EXPECT_EQ(time0 + time0, Time(2.0, Unit::Time::Second));
  EXPECT_EQ(time0 - time0, Time(0.0, Unit::Time::Second));
  EXPECT_EQ(time0 * 2.0, Time(2.0, Unit::Time::Second));
  EXPECT_EQ(2.0 * time0, Time(2.0, Unit::Time::Second));
  EXPECT_EQ(time0 / 2.0, Time(0.5, Unit::Time::Second));

  Time time1{1.0, Unit::Time::Second};
  time1 += Time{1.0, Unit::Time::Second};
  EXPECT_EQ(time1, Time(2.0, Unit::Time::Second));

  Time time2{2.0, Unit::Time::Second};
  time2 -= Time{1.0, Unit::Time::Second};
  EXPECT_EQ(time2, Time(1.0, Unit::Time::Second));

  Time time3{1.0, Unit::Time::Second};
  time3 *= 2.0;
  EXPECT_EQ(time3, Time(2.0, Unit::Time::Second));

  Time time4{2.0, Unit::Time::Second};
  time4 /= 2.0;
  EXPECT_EQ(time4, Time(1.0, Unit::Time::Second));
}

TEST(Time, Comparison) {
  const Time time0{0.1, Unit::Time::Second};
  const Time time1{0.2, Unit::Time::Second};
  EXPECT_EQ(time0, time0);
  EXPECT_NE(time0, time1);
  EXPECT_LT(time0, time1);
  EXPECT_GT(time1, time0);
  EXPECT_LE(time0, time0);
  EXPECT_LE(time0, time1);
  EXPECT_GE(time0, time0);
  EXPECT_GE(time1, time0);
}

TEST(Time, Constructor) {
  constexpr Time time0;
  const Time time1{4.0, Unit::Time::Minute};
  constexpr Time time2{Time::Create<Unit::Time::Minute>(4.0)};
}

TEST(Time, Hash) {
  const Time time0{10.0, Unit::Time::Second};
  const Time time1{10.000001, Unit::Time::Second};
  const Time time2{11.0, Unit::Time::Second};
  const Time time3{-10.0, Unit::Time::Second};
  const Time time4{20000.0, Unit::Time::Second};
  const Time time5{-123.456, Unit::Time::Second};
  const std::hash<Time> hasher;
  EXPECT_NE(hasher(time0), hasher(time1));
  EXPECT_NE(hasher(time0), hasher(time2));
  EXPECT_NE(hasher(time0), hasher(time3));
  EXPECT_NE(hasher(time0), hasher(time4));
  EXPECT_NE(hasher(time0), hasher(time5));
  const std::unordered_set<Time> unordered{
      time0, time1, time2, time3, time4, time5};
}

TEST(Time, JSON) {
  EXPECT_EQ(Time(1.11, Unit::Time::Second).JSON(),
            "{\"value\":1.110000,\"unit\":\"s\"}");
  EXPECT_EQ(Time(-5.0, Unit::Time::Minute).JSON(Unit::Time::Minute),
            "{\"value\":-5.000000,\"unit\":\"min\"}");
}

TEST(Time, Print) {
  EXPECT_EQ(Time(1.11, Unit::Time::Second).Print(), "1.110000 s");
  EXPECT_EQ(Time(-5.0, Unit::Time::Minute).Print(Unit::Time::Minute),
            "-5.000000 min");
}

TEST(Time, Stream) {
  const Time time{1.11, Unit::Time::Second};
  std::ostringstream stream;
  stream << time;
  EXPECT_EQ(stream.str(), time.Print());
}

TEST(Time, XML) {
  EXPECT_EQ(Time(1.11, Unit::Time::Second).XML(),
            "<value>1.110000</value><unit>s</unit>");
  EXPECT_EQ(Time(-5.0, Unit::Time::Minute).XML(Unit::Time::Minute),
            "<value>-5.000000</value><unit>min</unit>");
}

TEST(Time, YAML) {
  EXPECT_EQ(
      Time(1.11, Unit::Time::Second).YAML(), "{value:1.110000,unit:\"s\"}");
  EXPECT_EQ(Time(-5.0, Unit::Time::Minute).YAML(Unit::Time::Minute),
            "{value:-5.000000,unit:\"min\"}");
}

TEST(Time, Zero) { EXPECT_EQ(Time::Zero(), Time(0.0, Unit::Time::Second)); }

}  // namespace

}  // namespace PhQ
