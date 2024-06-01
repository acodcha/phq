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

#include "../include/PhQ/Power.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Energy.hpp"
#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Energy.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Power.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(Power, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      Power(1.0, Unit::Power::Watt) + Power(2.0, Unit::Power::Watt), Power(3.0, Unit::Power::Watt));
}

TEST(Power, ArithmeticOperatorDivision) {
  EXPECT_EQ(Power(8.0, Unit::Power::Watt) / 2.0, Power(4.0, Unit::Power::Watt));
  EXPECT_EQ(Power(8.0, Unit::Power::Watt) / Power(2.0, Unit::Power::Watt), 4.0);
  EXPECT_EQ(Power(8.0, Unit::Power::Watt) / Frequency(4.0, Unit::Frequency::Hertz),
            Energy(2.0, Unit::Energy::Joule));
  EXPECT_EQ(Power(8.0, Unit::Power::Watt) / Energy(4.0, Unit::Energy::Joule),
            Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule) / Time(4.0, Unit::Time::Second),
            Power(2.0, Unit::Power::Watt));
  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule) / Power(4.0, Unit::Power::Watt),
            Time(2.0, Unit::Time::Second));
}

TEST(Power, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Power(4.0, Unit::Power::Watt) * 2.0, Power(8.0, Unit::Power::Watt));
  EXPECT_EQ(2.0 * Power(4.0, Unit::Power::Watt), Power(8.0, Unit::Power::Watt));
  EXPECT_EQ(Power(4.0, Unit::Power::Watt) * Time(2.0, Unit::Time::Second),
            Energy(8.0, Unit::Energy::Joule));
  EXPECT_EQ(Time(4.0, Unit::Time::Second) * Power(2.0, Unit::Power::Watt),
            Energy(8.0, Unit::Energy::Joule));
  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * Energy(2.0, Unit::Energy::Joule),
            Power(8.0, Unit::Power::Watt));
  EXPECT_EQ(Energy(4.0, Unit::Energy::Joule) * Frequency(2.0, Unit::Frequency::Hertz),
            Power(8.0, Unit::Power::Watt));
}

TEST(Power, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      Power(3.0, Unit::Power::Watt) - Power(2.0, Unit::Power::Watt), Power(1.0, Unit::Power::Watt));
}

TEST(Power, AssignmentOperatorAddition) {
  Power power{1.0, Unit::Power::Watt};
  power += Power(2.0, Unit::Power::Watt);
  EXPECT_EQ(power, Power(3.0, Unit::Power::Watt));
}

TEST(Power, AssignmentOperatorDivision) {
  Power power{8.0, Unit::Power::Watt};
  power /= 2.0;
  EXPECT_EQ(power, Power(4.0, Unit::Power::Watt));
}

TEST(Power, AssignmentOperatorMultiplication) {
  Power power{4.0, Unit::Power::Watt};
  power *= 2.0;
  EXPECT_EQ(power, Power(8.0, Unit::Power::Watt));
}

TEST(Power, AssignmentOperatorSubtraction) {
  Power power{3.0, Unit::Power::Watt};
  power -= Power(2.0, Unit::Power::Watt);
  EXPECT_EQ(power, Power(1.0, Unit::Power::Watt));
}

TEST(Power, ComparisonOperators) {
  const Power first{1.0, Unit::Power::Watt};
  const Power second{2.0, Unit::Power::Watt};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Power, Constructor) {
  EXPECT_NO_THROW(Power(1.0, Unit::Power::Kilowatt));
  EXPECT_EQ(Power(Energy(8.0, Unit::Energy::Joule), Time(4.0, Unit::Time::Second)),
            Power(2.0, Unit::Power::Watt));
  EXPECT_EQ(Power(Energy(4.0, Unit::Energy::Joule), Frequency(2.0, Unit::Frequency::Hertz)),
            Power(8.0, Unit::Power::Watt));
  EXPECT_EQ(Time(Energy(8.0, Unit::Energy::Joule), Power(4.0, Unit::Power::Watt)),
            Time(2.0, Unit::Time::Second));
  EXPECT_EQ(Frequency(Power(8.0, Unit::Power::Watt), Energy(4.0, Unit::Energy::Joule)),
            Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(Energy(Power(4.0, Unit::Power::Watt), Time(2.0, Unit::Time::Second)),
            Energy(8.0, Unit::Energy::Joule));
  EXPECT_EQ(Energy(Power(8.0, Unit::Power::Watt), Frequency(4.0, Unit::Frequency::Hertz)),
            Energy(2.0, Unit::Energy::Joule));
}

TEST(Power, CopyAssignmentOperator) {
  {
    const Power<float> first(1.0F, Unit::Power::Watt);
    Power<double> second = Power<double>::Zero();
    second = first;
    EXPECT_EQ(second, Power<double>(1.0, Unit::Power::Watt));
  }
  {
    const Power<double> first(1.0, Unit::Power::Watt);
    Power<double> second = Power<double>::Zero();
    second = first;
    EXPECT_EQ(second, Power<double>(1.0, Unit::Power::Watt));
  }
  {
    const Power<long double> first(1.0L, Unit::Power::Watt);
    Power<double> second = Power<double>::Zero();
    second = first;
    EXPECT_EQ(second, Power<double>(1.0, Unit::Power::Watt));
  }
}

TEST(Power, CopyConstructor) {
  {
    const Power<float> first(1.0F, Unit::Power::Watt);
    const Power<double> second{first};
    EXPECT_EQ(second, Power<double>(1.0, Unit::Power::Watt));
  }
  {
    const Power<double> first(1.0, Unit::Power::Watt);
    const Power<double> second{first};
    EXPECT_EQ(second, Power<double>(1.0, Unit::Power::Watt));
  }
  {
    const Power<long double> first(1.0L, Unit::Power::Watt);
    const Power<double> second{first};
    EXPECT_EQ(second, Power<double>(1.0, Unit::Power::Watt));
  }
}

TEST(Power, Create) {
  constexpr Power power = Power<>::Create<Unit::Power::Watt>(1.0);
  EXPECT_EQ(power, Power(1.0, Unit::Power::Watt));
}

TEST(Power, DefaultConstructor) {
  EXPECT_NO_THROW(Power<>{});
}

TEST(Power, Dimensions) {
  EXPECT_EQ(Power<>::Dimensions(), RelatedDimensions<Unit::Power>);
}

TEST(Power, Hash) {
  const Power first{1.0, Unit::Power::Kilowatt};
  const Power second{1.000001, Unit::Power::Kilowatt};
  const Power third{-1.0, Unit::Power::Kilowatt};
  const std::hash<Power<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(Power, JSON) {
  EXPECT_EQ(Power(1.0, Unit::Power::Watt).JSON(), "{\"value\":" + Print(1.0) + ",\"unit\":\"W\"}");
  EXPECT_EQ(Power(1.0, Unit::Power::Kilowatt).JSON(Unit::Power::Kilowatt),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kW\"}");
}

TEST(Power, MoveAssignmentOperator) {
  Power first{1.0, Unit::Power::Watt};
  Power second = Power<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Power(1.0, Unit::Power::Watt));
}

TEST(Power, MoveConstructor) {
  Power first{1.0, Unit::Power::Watt};
  const Power second{std::move(first)};
  EXPECT_EQ(second, Power(1.0, Unit::Power::Watt));
}

TEST(Power, MutableValue) {
  Power power{1.0, Unit::Power::Watt};
  double& value = power.MutableValue();
  value = 2.0;
  EXPECT_EQ(power.Value(), 2.0);
}

TEST(Power, Print) {
  EXPECT_EQ(Power(1.0, Unit::Power::Watt).Print(), Print(1.0) + " W");
  EXPECT_EQ(Power(1.0, Unit::Power::Kilowatt).Print(Unit::Power::Kilowatt), Print(1.0) + " kW");
}

TEST(Power, SetValue) {
  Power power{1.0, Unit::Power::Watt};
  power.SetValue(2.0);
  EXPECT_EQ(power.Value(), 2.0);
}

TEST(Power, SizeOf) {
  EXPECT_EQ(sizeof(Power<>{}), sizeof(double));
}

TEST(Power, StaticValue) {
  constexpr Power power = Power<>::Create<Unit::Power::Kilowatt>(1.0);
  constexpr double value = power.StaticValue<Unit::Power::Kilowatt>();
  EXPECT_EQ(value, 1.0);
}

TEST(Power, Stream) {
  std::ostringstream stream;
  stream << Power(1.0, Unit::Power::Watt);
  EXPECT_EQ(stream.str(), Power(1.0, Unit::Power::Watt).Print());
}

TEST(Power, Unit) {
  EXPECT_EQ(Power<>::Unit(), Standard<Unit::Power>);
}

TEST(Power, Value) {
  EXPECT_EQ(Power(1.0, Unit::Power::Watt).Value(), 1.0);
  EXPECT_EQ(Power(1.0, Unit::Power::Kilowatt).Value(Unit::Power::Kilowatt), 1.0);
}

TEST(Power, XML) {
  EXPECT_EQ(Power(1.0, Unit::Power::Watt).XML(), "<value>" + Print(1.0) + "</value><unit>W</unit>");
  EXPECT_EQ(Power(1.0, Unit::Power::Kilowatt).XML(Unit::Power::Kilowatt),
            "<value>" + Print(1.0) + "</value><unit>kW</unit>");
}

TEST(Power, YAML) {
  EXPECT_EQ(Power(1.0, Unit::Power::Watt).YAML(), "{value:" + Print(1.0) + ",unit:\"W\"}");
  EXPECT_EQ(Power(1.0, Unit::Power::Kilowatt).YAML(Unit::Power::Kilowatt),
            "{value:" + Print(1.0) + ",unit:\"kW\"}");
}

TEST(Power, Zero) {
  EXPECT_EQ(Power<>::Zero(), Power(0.0, Unit::Power::Watt));
}

}  // namespace

}  // namespace PhQ
