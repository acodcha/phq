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

namespace PhQ {

namespace {

TEST(Frequency, ArithmeticAddition) {
  EXPECT_EQ(Frequency(1.0, Unit::Frequency::Hertz)
                + Frequency(2.0, Unit::Frequency::Hertz),
            Frequency(3.0, Unit::Frequency::Hertz));

  Frequency quantity{1.0, Unit::Frequency::Hertz};
  quantity += Frequency(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, Frequency(3.0, Unit::Frequency::Hertz));
}

TEST(Frequency, ArithmeticDivision) {
  EXPECT_EQ(Frequency(8.0, Unit::Frequency::Hertz) / 2.0,
            Frequency(4.0, Unit::Frequency::Hertz));

  EXPECT_EQ(Frequency(8.0, Unit::Frequency::Hertz)
                / Frequency(2.0, Unit::Frequency::Hertz),
            4.0);

  Frequency quantity{8.0, Unit::Frequency::Hertz};
  quantity /= 2.0;
  EXPECT_EQ(quantity, Frequency(4.0, Unit::Frequency::Hertz));
}

TEST(Frequency, ArithmeticMultiplication) {
  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * 2.0,
            Frequency(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(2.0 * Frequency(4.0, Unit::Frequency::Hertz),
            Frequency(8.0, Unit::Frequency::Hertz));

  EXPECT_EQ(
      Frequency(4.0, Unit::Frequency::Hertz) * Time(2.0, Unit::Time::Second),
      8.0);

  EXPECT_EQ(
      Time(4.0, Unit::Time::Second) * Frequency(2.0, Unit::Frequency::Hertz),
      8.0);

  Frequency quantity{4.0, Unit::Frequency::Hertz};
  quantity *= 2.0;
  EXPECT_EQ(quantity, Frequency(8.0, Unit::Frequency::Hertz));
}

TEST(Frequency, ArithmeticSubtraction) {
  EXPECT_EQ(Frequency(3.0, Unit::Frequency::Hertz)
                - Frequency(2.0, Unit::Frequency::Hertz),
            Frequency(1.0, Unit::Frequency::Hertz));

  Frequency quantity{3.0, Unit::Frequency::Hertz};
  quantity -= Frequency(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(quantity, Frequency(1.0, Unit::Frequency::Hertz));
}

TEST(Frequency, Comparisons) {
  const Frequency first{0.1, Unit::Frequency::Hertz};
  const Frequency second{0.2, Unit::Frequency::Hertz};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Frequency, CopyAssignment) {
  const Frequency first{1.11, Unit::Frequency::Hertz};
  Frequency second = Frequency::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Frequency, CopyConstructor) {
  const Frequency first{1.11, Unit::Frequency::Hertz};
  const Frequency second{first};
  EXPECT_EQ(second, first);
}

TEST(Frequency, Create) {
  constexpr Frequency quantity =
      Frequency::Create<Unit::Frequency::Hertz>(1.11);
  EXPECT_EQ(quantity, Frequency(1.11, Unit::Frequency::Hertz));
}

TEST(Frequency, DefaultConstructor) {
  EXPECT_NO_THROW(Frequency{});
}

TEST(Frequency, Dimensions) {
  EXPECT_EQ(Frequency::Dimensions(), RelatedDimensions<Unit::Frequency>);
}

TEST(Frequency, Hash) {
  const Frequency first{1.11, Unit::Frequency::Hertz};
  const Frequency second{1.110001, Unit::Frequency::Hertz};
  const Frequency third{-1.11, Unit::Frequency::Hertz};
  const std::hash<Frequency> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Frequency, JSON) {
  EXPECT_EQ(Frequency(1.11, Unit::Frequency::Hertz).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Hz\"}");
  EXPECT_EQ(Frequency(-2.22, Unit::Frequency::Kilohertz)
                .JSON(Unit::Frequency::Kilohertz),
            "{\"value\":-2.220000000000000,\"unit\":\"kHz\"}");
}

TEST(Frequency, MiscellaneousConstructors) {
  EXPECT_EQ(Time(Frequency(0.5, Unit::Frequency::Hertz)),
            Time(2.0, Unit::Time::Second));
}

TEST(Frequency, MiscellaneousMethods) {
  EXPECT_EQ(Frequency(0.5, Unit::Frequency::Hertz).Period(),
            Time(2.0, Unit::Time::Second));
  EXPECT_EQ(Time(0.5, Unit::Time::Second).Frequency(),
            Frequency(2.0, Unit::Frequency::Hertz));
}

TEST(Frequency, MoveAssignment) {
  const Frequency first{1.11, Unit::Frequency::Hertz};
  Frequency second{1.11, Unit::Frequency::Hertz};
  Frequency third = Frequency::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(Frequency, MoveConstructor) {
  const Frequency first{1.11, Unit::Frequency::Hertz};
  Frequency second{1.11, Unit::Frequency::Hertz};
  Frequency third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(Frequency, MutableValue) {
  Frequency quantity{1.11, Unit::Frequency::Hertz};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Frequency, Print) {
  EXPECT_EQ(
      Frequency(1.11, Unit::Frequency::Hertz).Print(), "1.110000000000000 Hz");
  EXPECT_EQ(Frequency(-2.22, Unit::Frequency::Kilohertz)
                .Print(Unit::Frequency::Kilohertz),
            "-2.220000000000000 kHz");
}

TEST(Frequency, SetValue) {
  Frequency quantity{1.11, Unit::Frequency::Hertz};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Frequency, SizeOf) {
  EXPECT_EQ(sizeof(Frequency{}), sizeof(double));
}

TEST(Frequency, StandardConstructor) {
  EXPECT_NO_THROW(Frequency(1.11, Unit::Frequency::Kilohertz));
}

TEST(Frequency, StaticValue) {
  constexpr Frequency quantity =
      Frequency::Create<Unit::Frequency::Kilohertz>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Frequency::Kilohertz>();
  EXPECT_EQ(value, 1.11);
}

TEST(Frequency, Stream) {
  std::ostringstream stream;
  stream << Frequency(1.11, Unit::Frequency::Hertz);
  EXPECT_EQ(stream.str(), Frequency(1.11, Unit::Frequency::Hertz).Print());
}

TEST(Frequency, Unit) {
  EXPECT_EQ(Frequency::Unit(), Standard<Unit::Frequency>);
}

TEST(Frequency, Value) {
  EXPECT_EQ(Frequency(1.11, Unit::Frequency::Hertz).Value(), 1.11);
  EXPECT_EQ(Frequency(1.11, Unit::Frequency::Kilohertz)
                .Value(Unit::Frequency::Kilohertz),
            1.11);
}

TEST(Frequency, XML) {
  EXPECT_EQ(Frequency(1.11, Unit::Frequency::Hertz).XML(),
            "<value>1.110000000000000</value><unit>Hz</unit>");
  EXPECT_EQ(Frequency(-2.22, Unit::Frequency::Kilohertz)
                .XML(Unit::Frequency::Kilohertz),
            "<value>-2.220000000000000</value><unit>kHz</unit>");
}

TEST(Frequency, YAML) {
  EXPECT_EQ(Frequency(1.11, Unit::Frequency::Hertz).YAML(),
            "{value:1.110000000000000,unit:\"Hz\"}");
  EXPECT_EQ(Frequency(-2.22, Unit::Frequency::Kilohertz)
                .YAML(Unit::Frequency::Kilohertz),
            "{value:-2.220000000000000,unit:\"kHz\"}");
}

TEST(Frequency, Zero) {
  EXPECT_EQ(Frequency::Zero(), Frequency(0.0, Unit::Frequency::Hertz));
}

}  // namespace

}  // namespace PhQ
