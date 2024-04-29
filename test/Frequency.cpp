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

#include "../include/PhQ/Frequency.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(Frequency, ArithmeticOperatorAddition) {
  EXPECT_EQ(Frequency(1.0, Unit::Frequency::Hertz) + Frequency(2.0, Unit::Frequency::Hertz),
            Frequency(3.0, Unit::Frequency::Hertz));
}

TEST(Frequency, ArithmeticOperatorDivision) {
  EXPECT_EQ(Frequency(8.0, Unit::Frequency::Hertz) / 2.0, Frequency(4.0, Unit::Frequency::Hertz));
  EXPECT_EQ(Frequency(8.0, Unit::Frequency::Hertz) / Frequency(2.0, Unit::Frequency::Hertz), 4.0);
}

TEST(Frequency, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * 2.0, Frequency(8.0, Unit::Frequency::Hertz));
  EXPECT_EQ(2.0 * Frequency(4.0, Unit::Frequency::Hertz), Frequency(8.0, Unit::Frequency::Hertz));
  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * Time(2.0, Unit::Time::Second), 8.0);
  EXPECT_EQ(Time(4.0, Unit::Time::Second) * Frequency(2.0, Unit::Frequency::Hertz), 8.0);
}

TEST(Frequency, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Frequency(3.0, Unit::Frequency::Hertz) - Frequency(2.0, Unit::Frequency::Hertz),
            Frequency(1.0, Unit::Frequency::Hertz));
}

TEST(Frequency, AssignmentOperatorAddition) {
  Frequency frequency{1.0, Unit::Frequency::Hertz};
  frequency += Frequency(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(frequency, Frequency(3.0, Unit::Frequency::Hertz));
}

TEST(Frequency, AssignmentOperatorDivision) {
  Frequency frequency{8.0, Unit::Frequency::Hertz};
  frequency /= 2.0;
  EXPECT_EQ(frequency, Frequency(4.0, Unit::Frequency::Hertz));
}

TEST(Frequency, AssignmentOperatorMultiplication) {
  Frequency frequency{4.0, Unit::Frequency::Hertz};
  frequency *= 2.0;
  EXPECT_EQ(frequency, Frequency(8.0, Unit::Frequency::Hertz));
}

TEST(Frequency, AssignmentOperatorSubtraction) {
  Frequency frequency{3.0, Unit::Frequency::Hertz};
  frequency -= Frequency(2.0, Unit::Frequency::Hertz);
  EXPECT_EQ(frequency, Frequency(1.0, Unit::Frequency::Hertz));
}

TEST(Frequency, ComparisonOperators) {
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

TEST(Frequency, CopyAssignmentOperator) {
  const Frequency first{1.0, Unit::Frequency::Hertz};
  Frequency second = Frequency::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Frequency, CopyConstructor) {
  const Frequency first{1.0, Unit::Frequency::Hertz};
  const Frequency second{first};
  EXPECT_EQ(second, first);
}

TEST(Frequency, Create) {
  constexpr Frequency frequency = Frequency::Create<Unit::Frequency::Hertz>(1.0);
  EXPECT_EQ(frequency, Frequency(1.0, Unit::Frequency::Hertz));
}

TEST(Frequency, DefaultConstructor) {
  EXPECT_NO_THROW(Frequency{});
}

TEST(Frequency, Dimensions) {
  EXPECT_EQ(Frequency::Dimensions(), RelatedDimensions<Unit::Frequency>);
}

TEST(Frequency, Hash) {
  const Frequency first{1.0, Unit::Frequency::Hertz};
  const Frequency second{1.000001, Unit::Frequency::Hertz};
  const Frequency third{-1.0, Unit::Frequency::Hertz};
  const std::hash<Frequency> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Frequency, JSON) {
  EXPECT_EQ(Frequency(1.0, Unit::Frequency::Hertz).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Hz\"}");
  EXPECT_EQ(Frequency(1.0, Unit::Frequency::Kilohertz).JSON(Unit::Frequency::Kilohertz),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kHz\"}");
}

TEST(Frequency, MiscellaneousConstructors) {
  EXPECT_EQ(Time(Frequency(0.5, Unit::Frequency::Hertz)), Time(2.0, Unit::Time::Second));
}

TEST(Frequency, MiscellaneousMethods) {
  EXPECT_EQ(Frequency(0.5, Unit::Frequency::Hertz).Period(), Time(2.0, Unit::Time::Second));
  EXPECT_EQ(Time(0.5, Unit::Time::Second).Frequency(), Frequency(2.0, Unit::Frequency::Hertz));
}

TEST(Frequency, MoveAssignmentOperator) {
  Frequency first{1.0, Unit::Frequency::Hertz};
  Frequency second = Frequency::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Frequency(1.0, Unit::Frequency::Hertz));
}

TEST(Frequency, MoveConstructor) {
  Frequency first{1.0, Unit::Frequency::Hertz};
  const Frequency second{std::move(first)};
  EXPECT_EQ(second, Frequency(1.0, Unit::Frequency::Hertz));
}

TEST(Frequency, MutableValue) {
  Frequency frequency{1.0, Unit::Frequency::Hertz};
  double& value = frequency.MutableValue();
  value = 2.0;
  EXPECT_EQ(frequency.Value(), 2.0);
}

TEST(Frequency, Print) {
  EXPECT_EQ(Frequency(1.0, Unit::Frequency::Hertz).Print(), Print(1.0) + " Hz");
  EXPECT_EQ(Frequency(1.0, Unit::Frequency::Kilohertz).Print(Unit::Frequency::Kilohertz),
            Print(1.0) + " kHz");
}

TEST(Frequency, SetValue) {
  Frequency frequency{1.0, Unit::Frequency::Hertz};
  frequency.SetValue(2.0);
  EXPECT_EQ(frequency.Value(), 2.0);
}

TEST(Frequency, SizeOf) {
  EXPECT_EQ(sizeof(Frequency{}), sizeof(double));
}

TEST(Frequency, StandardConstructor) {
  EXPECT_NO_THROW(Frequency(1.0, Unit::Frequency::Kilohertz));
}

TEST(Frequency, StaticValue) {
  constexpr Frequency frequency = Frequency::Create<Unit::Frequency::Kilohertz>(1.0);
  constexpr double value = frequency.StaticValue<Unit::Frequency::Kilohertz>();
  EXPECT_EQ(value, 1.0);
}

TEST(Frequency, Stream) {
  std::ostringstream stream;
  stream << Frequency(1.0, Unit::Frequency::Hertz);
  EXPECT_EQ(stream.str(), Frequency(1.0, Unit::Frequency::Hertz).Print());
}

TEST(Frequency, Unit) {
  EXPECT_EQ(Frequency::Unit(), Standard<Unit::Frequency>);
}

TEST(Frequency, Value) {
  EXPECT_EQ(Frequency(1.0, Unit::Frequency::Hertz).Value(), 1.0);
  EXPECT_EQ(Frequency(1.0, Unit::Frequency::Kilohertz).Value(Unit::Frequency::Kilohertz), 1.0);
}

TEST(Frequency, XML) {
  EXPECT_EQ(Frequency(1.0, Unit::Frequency::Hertz).XML(),
            "<value>" + Print(1.0) + "</value><unit>Hz</unit>");
  EXPECT_EQ(Frequency(1.0, Unit::Frequency::Kilohertz).XML(Unit::Frequency::Kilohertz),
            "<value>" + Print(1.0) + "</value><unit>kHz</unit>");
}

TEST(Frequency, YAML) {
  EXPECT_EQ(
      Frequency(1.0, Unit::Frequency::Hertz).YAML(), "{value:" + Print(1.0) + ",unit:\"Hz\"}");
  EXPECT_EQ(Frequency(1.0, Unit::Frequency::Kilohertz).YAML(Unit::Frequency::Kilohertz),
            "{value:" + Print(1.0) + ",unit:\"kHz\"}");
}

TEST(Frequency, Zero) {
  EXPECT_EQ(Frequency::Zero(), Frequency(0.0, Unit::Frequency::Hertz));
}

}  // namespace

}  // namespace PhQ
