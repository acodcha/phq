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

#include "../include/PhQ/Frequency.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Frequency, Accessor) {
  const Frequency frequency{20.0, Unit::Frequency::Hertz};
  EXPECT_DOUBLE_EQ(frequency.Value(), 20.0);
  EXPECT_DOUBLE_EQ(frequency.Value(Unit::Frequency::Kilohertz), 20.0 / 1000.0);
}

TEST(Frequency, Arithmetic) {
  const Time time{2.0, Unit::Time::Second};
  const Frequency frequency0{1.0, Unit::Frequency::Hertz};
  EXPECT_EQ(frequency0 + frequency0, Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(frequency0 - frequency0, Frequency(0.0, Unit::Frequency::Hertz));
  EXPECT_EQ(frequency0 * 2.0, Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(2.0 * frequency0, Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(frequency0 * time, 2.0);
  EXPECT_EQ(time * frequency0, 2.0);
  EXPECT_EQ(frequency0 / 2.0, Frequency(0.5, Unit::Frequency::Hertz));

  Frequency frequency1{1.0, Unit::Frequency::Hertz};
  frequency1 += Frequency{1.0, Unit::Frequency::Hertz};
  EXPECT_EQ(frequency1, Frequency(2.0, Unit::Frequency::Hertz));

  Frequency frequency2{2.0, Unit::Frequency::Hertz};
  frequency2 -= Frequency{1.0, Unit::Frequency::Hertz};
  EXPECT_EQ(frequency2, Frequency(1.0, Unit::Frequency::Hertz));

  Frequency frequency3{1.0, Unit::Frequency::Hertz};
  frequency3 *= 2.0;
  EXPECT_EQ(frequency3, Frequency(2.0, Unit::Frequency::Hertz));

  Frequency frequency4{2.0, Unit::Frequency::Hertz};
  frequency4 /= 2.0;
  EXPECT_EQ(frequency4, Frequency(1.0, Unit::Frequency::Hertz));
}

TEST(Frequency, Comparison) {
  const Frequency frequency0{0.1, Unit::Frequency::Hertz};
  const Frequency frequency1{0.2, Unit::Frequency::Hertz};
  EXPECT_EQ(frequency0, frequency0);
  EXPECT_NE(frequency0, frequency1);
  EXPECT_LT(frequency0, frequency1);
  EXPECT_GT(frequency1, frequency0);
  EXPECT_LE(frequency0, frequency0);
  EXPECT_LE(frequency0, frequency1);
  EXPECT_GE(frequency0, frequency0);
  EXPECT_GE(frequency1, frequency0);
}

TEST(Frequency, Constructor) {
  const Frequency frequency0;
  const Frequency frequency1{4.0, Unit::Frequency::Kilohertz};
  EXPECT_EQ(Frequency(Time(2.0, Unit::Time::Second)),
            Frequency(0.5, Unit::Frequency::Hertz));
}

TEST(Frequency, Hash) {
  const Frequency frequency0{10.0, Unit::Frequency::Hertz};
  const Frequency frequency1{10.000001, Unit::Frequency::Hertz};
  const Frequency frequency2{11.0, Unit::Frequency::Hertz};
  const Frequency frequency3{-10.0, Unit::Frequency::Hertz};
  const Frequency frequency4{20000.0, Unit::Frequency::Hertz};
  const Frequency frequency5{-123.456, Unit::Frequency::Hertz};
  const std::hash<Frequency> hasher;
  EXPECT_NE(hasher(frequency0), hasher(frequency1));
  EXPECT_NE(hasher(frequency0), hasher(frequency2));
  EXPECT_NE(hasher(frequency0), hasher(frequency3));
  EXPECT_NE(hasher(frequency0), hasher(frequency4));
  EXPECT_NE(hasher(frequency0), hasher(frequency5));
  const std::unordered_set<Frequency> unordered{
      frequency0, frequency1, frequency2, frequency3, frequency4, frequency5};
}

TEST(Frequency, Json) {
  EXPECT_EQ(Frequency(1.11, Unit::Frequency::Hertz).Json(),
            "{\"value\":1.110000,\"unit\":\"Hz\"}");
  EXPECT_EQ(Frequency(-5.0, Unit::Frequency::Kilohertz)
                .Json(Unit::Frequency::Kilohertz),
            "{\"value\":-5.000000,\"unit\":\"kHz\"}");
}

TEST(Frequency, Period) {
  const Time time{0.5, Unit::Time::Second};
  const Frequency frequency{2.0, Unit::Frequency::Hertz};
  EXPECT_EQ(frequency.Period(), time);
  EXPECT_EQ(Time(frequency), time);
  EXPECT_EQ(time.Frequency(), frequency);
}

TEST(Frequency, Print) {
  EXPECT_EQ(Frequency(1.11, Unit::Frequency::Hertz).Print(), "1.110000 Hz");
  EXPECT_EQ(Frequency(-5.0, Unit::Frequency::Kilohertz)
                .Print(Unit::Frequency::Kilohertz),
            "-5.000000 kHz");
}

TEST(Frequency, Stream) {
  const Frequency frequency{1.11, Unit::Frequency::Hertz};
  std::ostringstream stream;
  stream << frequency;
  EXPECT_EQ(stream.str(), frequency.Print());
}

TEST(Frequency, Xml) {
  EXPECT_EQ(Frequency(1.11, Unit::Frequency::Hertz).Xml(),
            "<value>1.110000</value><unit>Hz</unit>");
  EXPECT_EQ(Frequency(-5.0, Unit::Frequency::Kilohertz)
                .Xml(Unit::Frequency::Kilohertz),
            "<value>-5.000000</value><unit>kHz</unit>");
}

TEST(Frequency, Yaml) {
  EXPECT_EQ(Frequency(1.11, Unit::Frequency::Hertz).Yaml(),
            "{value:1.110000,unit:\"Hz\"}");
  EXPECT_EQ(Frequency(-5.0, Unit::Frequency::Kilohertz)
                .Yaml(Unit::Frequency::Kilohertz),
            "{value:-5.000000,unit:\"kHz\"}");
}

}  // namespace

}  // namespace PhQ
