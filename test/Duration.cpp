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

#include "../include/PhQ/Duration.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Duration, Accessor) {
  const Duration duration{10.0, Unit::Time::Second};
  EXPECT_DOUBLE_EQ(duration.Value(), 10.0);
  EXPECT_DOUBLE_EQ(duration.Value(Unit::Time::Minute), 10.0 / 60.0);
}

TEST(Duration, Arithmetic) {
  const Duration duration0{1.0, Unit::Time::Second};
  EXPECT_EQ(duration0 + duration0, Duration(2.0, Unit::Time::Second));
  EXPECT_EQ(duration0 - duration0, Duration(0.0, Unit::Time::Second));
  EXPECT_EQ(duration0 * 2.0, Duration(2.0, Unit::Time::Second));
  EXPECT_EQ(2.0 * duration0, Duration(2.0, Unit::Time::Second));
  EXPECT_EQ(duration0 / 2.0, Duration(0.5, Unit::Time::Second));

  Duration duration1{1.0, Unit::Time::Second};
  duration1 += Duration{1.0, Unit::Time::Second};
  EXPECT_EQ(duration1, Duration(2.0, Unit::Time::Second));

  Duration duration2{2.0, Unit::Time::Second};
  duration2 -= Duration{1.0, Unit::Time::Second};
  EXPECT_EQ(duration2, Duration(1.0, Unit::Time::Second));

  Duration duration3{1.0, Unit::Time::Second};
  duration3 *= 2.0;
  EXPECT_EQ(duration3, Duration(2.0, Unit::Time::Second));

  Duration duration4{2.0, Unit::Time::Second};
  duration4 /= 2.0;
  EXPECT_EQ(duration4, Duration(1.0, Unit::Time::Second));
}

TEST(Duration, Comparison) {
  const Duration duration0{0.1, Unit::Time::Second};
  const Duration duration1{0.2, Unit::Time::Second};
  EXPECT_EQ(duration0, duration0);
  EXPECT_NE(duration0, duration1);
  EXPECT_LT(duration0, duration1);
  EXPECT_GT(duration1, duration0);
  EXPECT_LE(duration0, duration0);
  EXPECT_LE(duration0, duration1);
  EXPECT_GE(duration0, duration0);
  EXPECT_GE(duration1, duration0);
}

TEST(Duration, Constructor) {
  const Duration duration0;
  const Duration duration1{4.0, Unit::Time::Minute};
}

TEST(Duration, Hash) {
  const Duration duration0{10.0, Unit::Time::Second};
  const Duration duration1{10.000001, Unit::Time::Second};
  const Duration duration2{11.0, Unit::Time::Second};
  const Duration duration3{-10.0, Unit::Time::Second};
  const Duration duration4{20000.0, Unit::Time::Second};
  const Duration duration5{-123.456, Unit::Time::Second};
  const std::hash<Duration> hasher;
  EXPECT_NE(hasher(duration0), hasher(duration1));
  EXPECT_NE(hasher(duration0), hasher(duration2));
  EXPECT_NE(hasher(duration0), hasher(duration3));
  EXPECT_NE(hasher(duration0), hasher(duration4));
  EXPECT_NE(hasher(duration0), hasher(duration5));
  const std::unordered_set<Duration> unordered{duration0, duration1, duration2,
                                               duration3, duration4, duration5};
}

TEST(Duration, Json) {
  EXPECT_EQ(Duration(1.11, Unit::Time::Second).Json(),
            "{\"value\":1.110000,\"unit\":\"s\"}");
  EXPECT_EQ(Duration(-5.0, Unit::Time::Minute).Json(Unit::Time::Minute),
            "{\"value\":-5.000000,\"unit\":\"min\"}");
}

TEST(Duration, Print) {
  EXPECT_EQ(Duration(1.11, Unit::Time::Second).Print(), "1.110000 s");
  EXPECT_EQ(Duration(-5.0, Unit::Time::Minute).Print(Unit::Time::Minute),
            "-5.000000 min");
}

TEST(Duration, Stream) {
  const Duration duration{1.11, Unit::Time::Second};
  std::ostringstream stream;
  stream << duration;
  EXPECT_EQ(stream.str(), duration.Print());
}

TEST(Duration, Xml) {
  EXPECT_EQ(Duration(1.11, Unit::Time::Second).Xml(),
            "<value>1.110000</value><unit>s</unit>");
  EXPECT_EQ(Duration(-5.0, Unit::Time::Minute).Xml(Unit::Time::Minute),
            "<value>-5.000000</value><unit>min</unit>");
}

TEST(Duration, Yaml) {
  EXPECT_EQ(Duration(1.11, Unit::Time::Second).Yaml(),
            "{value:1.110000,unit:\"s\"}");
  EXPECT_EQ(Duration(-5.0, Unit::Time::Minute).Yaml(Unit::Time::Minute),
            "{value:-5.000000,unit:\"min\"}");
}

}  // namespace

}  // namespace PhQ
