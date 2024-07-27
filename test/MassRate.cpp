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

#include "../include/PhQ/MassRate.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Mass.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Mass.hpp"
#include "../include/PhQ/Unit/MassRate.hpp"
#include "../include/PhQ/Unit/Time.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(MassRate, ArithmeticOperatorAddition) {
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::KilogramPerSecond)
                + MassRate(2.0, Unit::MassRate::KilogramPerSecond),
            MassRate(3.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, ArithmeticOperatorDivision) {
  EXPECT_EQ(MassRate(8.0, Unit::MassRate::KilogramPerSecond) / 2.0,
            MassRate(4.0, Unit::MassRate::KilogramPerSecond));
  EXPECT_EQ(MassRate(8.0, Unit::MassRate::KilogramPerSecond)
                / MassRate(2.0, Unit::MassRate::KilogramPerSecond),
            4.0);
  EXPECT_EQ(
      MassRate(8.0, Unit::MassRate::KilogramPerSecond) / Frequency(4.0, Unit::Frequency::Hertz),
      Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(MassRate(8.0, Unit::MassRate::KilogramPerSecond) / Mass(4.0, Unit::Mass::Kilogram),
            Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(Mass(8.0, Unit::Mass::Kilogram) / MassRate(4.0, Unit::MassRate::KilogramPerSecond),
            Time(2.0, Unit::Time::Second));
  EXPECT_EQ(Mass(8.0, Unit::Mass::Kilogram) / Time(4.0, Unit::Time::Second),
            MassRate(2.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(MassRate(4.0, Unit::MassRate::KilogramPerSecond) * 2.0,
            MassRate(8.0, Unit::MassRate::KilogramPerSecond));
  EXPECT_EQ(2.0 * MassRate(4.0, Unit::MassRate::KilogramPerSecond),
            MassRate(8.0, Unit::MassRate::KilogramPerSecond));
  EXPECT_EQ(MassRate(4.0, Unit::MassRate::KilogramPerSecond) * Time(2.0, Unit::Time::Second),
            Mass(8.0, Unit::Mass::Kilogram));
  EXPECT_EQ(Time(4.0, Unit::Time::Second) * MassRate(2.0, Unit::MassRate::KilogramPerSecond),
            Mass(8.0, Unit::Mass::Kilogram));
}

TEST(MassRate, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(MassRate(3.0, Unit::MassRate::KilogramPerSecond)
                - MassRate(2.0, Unit::MassRate::KilogramPerSecond),
            MassRate(1.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, AssignmentOperatorAddition) {
  MassRate mass_rate{1.0, Unit::MassRate::KilogramPerSecond};
  mass_rate += MassRate(2.0, Unit::MassRate::KilogramPerSecond);
  EXPECT_EQ(mass_rate, MassRate(3.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, AssignmentOperatorDivision) {
  MassRate mass_rate{8.0, Unit::MassRate::KilogramPerSecond};
  mass_rate /= 2.0;
  EXPECT_EQ(mass_rate, MassRate(4.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, AssignmentOperatorMultiplication) {
  MassRate mass_rate{4.0, Unit::MassRate::KilogramPerSecond};
  mass_rate *= 2.0;
  EXPECT_EQ(mass_rate, MassRate(8.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, AssignmentOperatorSubtraction) {
  MassRate mass_rate{3.0, Unit::MassRate::KilogramPerSecond};
  mass_rate -= MassRate(2.0, Unit::MassRate::KilogramPerSecond);
  EXPECT_EQ(mass_rate, MassRate(1.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, ComparisonOperators) {
  const MassRate first{1.0, Unit::MassRate::KilogramPerSecond};
  const MassRate second{2.0, Unit::MassRate::KilogramPerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(MassRate, Constructor) {
  EXPECT_NO_THROW(MassRate(1.0, Unit::MassRate::GramPerSecond));
  EXPECT_EQ(Mass(MassRate(4.0, Unit::MassRate::KilogramPerSecond), Time(2.0, Unit::Time::Second)),
            Mass(8.0, Unit::Mass::Kilogram));
  EXPECT_EQ(Mass(MassRate(8.0, Unit::MassRate::KilogramPerSecond),
                 Frequency(4.0, Unit::Frequency::Hertz)),
            Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(Time(Mass(8.0, Unit::Mass::Kilogram), MassRate(4.0, Unit::MassRate::KilogramPerSecond)),
            Time(2.0, Unit::Time::Second));
  EXPECT_EQ(
      Frequency(MassRate(8.0, Unit::MassRate::KilogramPerSecond), Mass(4.0, Unit::Mass::Kilogram)),
      Frequency(2.0, Unit::Frequency::Hertz));
}

TEST(MassRate, CopyAssignmentOperator) {
  {
    const MassRate<float> first(1.0F, Unit::MassRate::KilogramPerSecond);
    MassRate<double> second = MassRate<double>::Zero();
    second = first;
    EXPECT_EQ(second, MassRate<double>(1.0, Unit::MassRate::KilogramPerSecond));
  }
  {
    const MassRate<double> first(1.0, Unit::MassRate::KilogramPerSecond);
    MassRate<double> second = MassRate<double>::Zero();
    second = first;
    EXPECT_EQ(second, MassRate<double>(1.0, Unit::MassRate::KilogramPerSecond));
  }
  {
    const MassRate<long double> first(1.0L, Unit::MassRate::KilogramPerSecond);
    MassRate<double> second = MassRate<double>::Zero();
    second = first;
    EXPECT_EQ(second, MassRate<double>(1.0, Unit::MassRate::KilogramPerSecond));
  }
}

TEST(MassRate, CopyConstructor) {
  {
    const MassRate<float> first(1.0F, Unit::MassRate::KilogramPerSecond);
    const MassRate<double> second{first};
    EXPECT_EQ(second, MassRate<double>(1.0, Unit::MassRate::KilogramPerSecond));
  }
  {
    const MassRate<double> first(1.0, Unit::MassRate::KilogramPerSecond);
    const MassRate<double> second{first};
    EXPECT_EQ(second, MassRate<double>(1.0, Unit::MassRate::KilogramPerSecond));
  }
  {
    const MassRate<long double> first(1.0L, Unit::MassRate::KilogramPerSecond);
    const MassRate<double> second{first};
    EXPECT_EQ(second, MassRate<double>(1.0, Unit::MassRate::KilogramPerSecond));
  }
}

TEST(MassRate, Create) {
  constexpr MassRate mass_rate = MassRate<>::Create<Unit::MassRate::KilogramPerSecond>(1.0);
  EXPECT_EQ(mass_rate, MassRate(1.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, DefaultConstructor) {
  EXPECT_NO_THROW(MassRate<>{});
}

TEST(MassRate, Dimensions) {
  EXPECT_EQ(MassRate<>::Dimensions(), RelatedDimensions<Unit::MassRate>);
}

TEST(MassRate, Hash) {
  const MassRate first{1.0, Unit::MassRate::GramPerSecond};
  const MassRate second{1.00001, Unit::MassRate::GramPerSecond};
  const MassRate third{-1.0, Unit::MassRate::GramPerSecond};
  const std::hash<MassRate<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(MassRate, JSON) {
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::KilogramPerSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kg/s\"}");
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::GramPerSecond).JSON(Unit::MassRate::GramPerSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"g/s\"}");
}

TEST(MassRate, MoveAssignmentOperator) {
  MassRate first{1.0, Unit::MassRate::KilogramPerSecond};
  MassRate second = MassRate<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, MassRate(1.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, MoveConstructor) {
  MassRate first{1.0, Unit::MassRate::KilogramPerSecond};
  const MassRate second{std::move(first)};
  EXPECT_EQ(second, MassRate(1.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, MutableValue) {
  MassRate mass_rate{1.0, Unit::MassRate::KilogramPerSecond};
  double& value = mass_rate.MutableValue();
  value = 2.0;
  EXPECT_EQ(mass_rate.Value(), 2.0);
}

TEST(MassRate, Performance) {
  MassRate first{1.2345678901234567890, Unit::MassRate::KilogramPerSecond};
  MassRate second{1.2345678901234567890, Unit::MassRate::KilogramPerSecond};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(MassRate, Print) {
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::KilogramPerSecond).Print(), Print(1.0) + " kg/s");
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::GramPerSecond).Print(Unit::MassRate::GramPerSecond),
            Print(1.0) + " g/s");
}

TEST(MassRate, SetValue) {
  MassRate mass_rate{1.0, Unit::MassRate::KilogramPerSecond};
  mass_rate.SetValue(2.0);
  EXPECT_EQ(mass_rate.Value(), 2.0);
}

TEST(MassRate, SizeOf) {
  EXPECT_EQ(sizeof(MassRate<>{}), sizeof(double));
}

TEST(MassRate, StaticValue) {
  constexpr MassRate mass_rate = MassRate<>::Create<Unit::MassRate::GramPerSecond>(1.0);
  constexpr double value = mass_rate.StaticValue<Unit::MassRate::GramPerSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(MassRate, Stream) {
  std::ostringstream stream;
  stream << MassRate(1.0, Unit::MassRate::KilogramPerSecond);
  EXPECT_EQ(stream.str(), MassRate(1.0, Unit::MassRate::KilogramPerSecond).Print());
}

TEST(MassRate, Unit) {
  EXPECT_EQ(MassRate<>::Unit(), Standard<Unit::MassRate>);
}

TEST(MassRate, Value) {
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::KilogramPerSecond).Value(), 1.0);
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::GramPerSecond).Value(Unit::MassRate::GramPerSecond), 1.0);
}

TEST(MassRate, XML) {
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::KilogramPerSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>kg/s</unit>");
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::GramPerSecond).XML(Unit::MassRate::GramPerSecond),
            "<value>" + Print(1.0) + "</value><unit>g/s</unit>");
}

TEST(MassRate, YAML) {
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::KilogramPerSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"kg/s\"}");
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::GramPerSecond).YAML(Unit::MassRate::GramPerSecond),
            "{value:" + Print(1.0) + ",unit:\"g/s\"}");
}

TEST(MassRate, Zero) {
  EXPECT_EQ(MassRate<>::Zero(), MassRate(0.0, Unit::MassRate::KilogramPerSecond));
}

}  // namespace

}  // namespace PhQ
