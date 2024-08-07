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

#include "../include/PhQ/SpecificPower.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Mass.hpp"
#include "../include/PhQ/Power.hpp"
#include "../include/PhQ/SpecificEnergy.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Mass.hpp"
#include "../include/PhQ/Unit/Power.hpp"
#include "../include/PhQ/Unit/SpecificEnergy.hpp"
#include "../include/PhQ/Unit/SpecificPower.hpp"
#include "../include/PhQ/Unit/Time.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(SpecificPower, ArithmeticOperatorAddition) {
  EXPECT_EQ(SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram)
                + SpecificPower(2.0, Unit::SpecificPower::WattPerKilogram),
            SpecificPower(3.0, Unit::SpecificPower::WattPerKilogram));
}

TEST(SpecificPower, ArithmeticOperatorDivision) {
  EXPECT_EQ(SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram) / 2.0,
            SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram));
  EXPECT_EQ(SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram)
                / SpecificPower(2.0, Unit::SpecificPower::WattPerKilogram),
            4.0);
  EXPECT_EQ(SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram)
                / Frequency(2.0, Unit::Frequency::Hertz),
            SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram)
                / SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            Frequency(4.0, Unit::Frequency::Hertz));
  EXPECT_EQ(
      Power(8.0, Unit::Power::Watt) / SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram),
      Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(Power(8.0, Unit::Power::Watt) / Mass(4.0, Unit::Mass::Kilogram),
            SpecificPower(2.0, Unit::SpecificPower::WattPerKilogram));
  EXPECT_EQ(
      SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram) / Time(4.0, Unit::Time::Second),
      SpecificPower(2.0, Unit::SpecificPower::WattPerKilogram));
  EXPECT_EQ(SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram)
                / SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram),
            Time(2.0, Unit::Time::Second));
}

TEST(SpecificPower, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram) * 2.0,
            SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram));
  EXPECT_EQ(2.0 * SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram),
            SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram));
  EXPECT_EQ(
      SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram) * Time(2.0, Unit::Time::Second),
      SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(
      SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram) * Mass(2.0, Unit::Mass::Kilogram),
      Power(8.0, Unit::Power::Watt));
  EXPECT_EQ(
      Mass(4.0, Unit::Mass::Kilogram) * SpecificPower(2.0, Unit::SpecificPower::WattPerKilogram),
      Power(8.0, Unit::Power::Watt));
  EXPECT_EQ(
      Time(4.0, Unit::Time::Second) * SpecificPower(2.0, Unit::SpecificPower::WattPerKilogram),
      SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz)
                * SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram));
  EXPECT_EQ(SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram)
                * Frequency(2.0, Unit::Frequency::Hertz),
            SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram));
}

TEST(SpecificPower, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(SpecificPower(3.0, Unit::SpecificPower::WattPerKilogram)
                - SpecificPower(2.0, Unit::SpecificPower::WattPerKilogram),
            SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram));
}

TEST(SpecificPower, AssignmentOperatorAddition) {
  SpecificPower quantity{1.0, Unit::SpecificPower::WattPerKilogram};
  quantity += SpecificPower(2.0, Unit::SpecificPower::WattPerKilogram);
  EXPECT_EQ(quantity, SpecificPower(3.0, Unit::SpecificPower::WattPerKilogram));
}

TEST(SpecificPower, AssignmentOperatorDivision) {
  SpecificPower quantity{8.0, Unit::SpecificPower::WattPerKilogram};
  quantity /= 2.0;
  EXPECT_EQ(quantity, SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram));
}

TEST(SpecificPower, AssignmentOperatorMultiplication) {
  SpecificPower quantity{4.0, Unit::SpecificPower::WattPerKilogram};
  quantity *= 2.0;
  EXPECT_EQ(quantity, SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram));
}

TEST(SpecificPower, AssignmentOperatorSubtraction) {
  SpecificPower quantity{3.0, Unit::SpecificPower::WattPerKilogram};
  quantity -= SpecificPower(2.0, Unit::SpecificPower::WattPerKilogram);
  EXPECT_EQ(quantity, SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram));
}

TEST(SpecificPower, ComparisonOperators) {
  const SpecificPower first{1.0, Unit::SpecificPower::WattPerKilogram};
  const SpecificPower second{2.0, Unit::SpecificPower::WattPerKilogram};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(SpecificPower, Constructor) {
  EXPECT_NO_THROW(SpecificPower(1.0, Unit::SpecificPower::NanowattPerGram));
  EXPECT_EQ(SpecificPower(SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram),
                          Time(4.0, Unit::Time::Second)),
            SpecificPower(2.0, Unit::SpecificPower::WattPerKilogram));
  EXPECT_EQ(SpecificPower(SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram),
                          Frequency(2.0, Unit::Frequency::Hertz)),
            SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram));
  EXPECT_EQ(SpecificPower(Power(8.0, Unit::Power::Watt), Mass(4.0, Unit::Mass::Kilogram)),
            SpecificPower(2.0, Unit::SpecificPower::WattPerKilogram));
  EXPECT_EQ(Time(SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram),
                 SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram)),
            Time(2.0, Unit::Time::Second));
  EXPECT_EQ(Frequency(SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram),
                      SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram)),
            Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(
      Mass(Power(8.0, Unit::Power::Watt), SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram)),
      Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(Power(SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram),
                  Mass(2.0, Unit::Mass::Kilogram)),
            Power(8.0, Unit::Power::Watt));
  EXPECT_EQ(SpecificEnergy(SpecificPower(4.0, Unit::SpecificPower::WattPerKilogram),
                           Time(2.0, Unit::Time::Second)),
            SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(SpecificEnergy(SpecificPower(8.0, Unit::SpecificPower::WattPerKilogram),
                           Frequency(2.0, Unit::Frequency::Hertz)),
            SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificPower, CopyAssignmentOperator) {
  {
    const SpecificPower<float> first(1.0F, Unit::SpecificPower::WattPerKilogram);
    SpecificPower<double> second = SpecificPower<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificPower<double>(1.0, Unit::SpecificPower::WattPerKilogram));
  }
  {
    const SpecificPower<double> first(1.0, Unit::SpecificPower::WattPerKilogram);
    SpecificPower<double> second = SpecificPower<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificPower<double>(1.0, Unit::SpecificPower::WattPerKilogram));
  }
  {
    const SpecificPower<long double> first(1.0L, Unit::SpecificPower::WattPerKilogram);
    SpecificPower<double> second = SpecificPower<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificPower<double>(1.0, Unit::SpecificPower::WattPerKilogram));
  }
}

TEST(SpecificPower, CopyConstructor) {
  {
    const SpecificPower<float> first(1.0F, Unit::SpecificPower::WattPerKilogram);
    const SpecificPower<double> second{first};
    EXPECT_EQ(second, SpecificPower<double>(1.0, Unit::SpecificPower::WattPerKilogram));
  }
  {
    const SpecificPower<double> first(1.0, Unit::SpecificPower::WattPerKilogram);
    const SpecificPower<double> second{first};
    EXPECT_EQ(second, SpecificPower<double>(1.0, Unit::SpecificPower::WattPerKilogram));
  }
  {
    const SpecificPower<long double> first(1.0L, Unit::SpecificPower::WattPerKilogram);
    const SpecificPower<double> second{first};
    EXPECT_EQ(second, SpecificPower<double>(1.0, Unit::SpecificPower::WattPerKilogram));
  }
}

TEST(SpecificPower, Create) {
  constexpr SpecificPower quantity =
      SpecificPower<>::Create<Unit::SpecificPower::WattPerKilogram>(1.0);
  EXPECT_EQ(quantity, SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram));
}

TEST(SpecificPower, DefaultConstructor) {
  EXPECT_NO_THROW(SpecificPower<>{});
}

TEST(SpecificPower, Dimensions) {
  EXPECT_EQ(SpecificPower<>::Dimensions(), RelatedDimensions<Unit::SpecificPower>);
}

TEST(SpecificPower, Hash) {
  const SpecificPower first{1.0, Unit::SpecificPower::NanowattPerGram};
  const SpecificPower second{1.00001, Unit::SpecificPower::NanowattPerGram};
  const SpecificPower third{-1.0, Unit::SpecificPower::NanowattPerGram};
  const std::hash<SpecificPower<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(SpecificPower, JSON) {
  EXPECT_EQ(SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"W/kg\"}");
  EXPECT_EQ(SpecificPower(1.0, Unit::SpecificPower::NanowattPerGram)
                .JSON(Unit::SpecificPower::NanowattPerGram),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"nW/g\"}");
}

TEST(SpecificPower, MoveAssignmentOperator) {
  SpecificPower first{1.0, Unit::SpecificPower::WattPerKilogram};
  SpecificPower second = SpecificPower<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram));
}

TEST(SpecificPower, MoveConstructor) {
  SpecificPower first{1.0, Unit::SpecificPower::WattPerKilogram};
  const SpecificPower second{std::move(first)};
  EXPECT_EQ(second, SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram));
}

TEST(SpecificPower, MutableValue) {
  SpecificPower quantity{1.0, Unit::SpecificPower::WattPerKilogram};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SpecificPower, Performance) {
  SpecificPower first{1.2345678901234567890, Unit::SpecificPower::WattPerKilogram};
  SpecificPower second{1.2345678901234567890, Unit::SpecificPower::WattPerKilogram};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(SpecificPower, Print) {
  EXPECT_EQ(SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram).Print(), Print(1.0) + " W/kg");
  EXPECT_EQ(SpecificPower(1.0, Unit::SpecificPower::NanowattPerGram)
                .Print(Unit::SpecificPower::NanowattPerGram),
            Print(1.0) + " nW/g");
}

TEST(SpecificPower, SetValue) {
  SpecificPower quantity{1.0, Unit::SpecificPower::WattPerKilogram};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SpecificPower, SizeOf) {
  EXPECT_EQ(sizeof(SpecificPower<>{}), sizeof(double));
}

TEST(SpecificPower, StaticValue) {
  constexpr SpecificPower quantity =
      SpecificPower<>::Create<Unit::SpecificPower::NanowattPerGram>(2.0);
  constexpr double value = quantity.StaticValue<Unit::SpecificPower::NanowattPerGram>();
  EXPECT_EQ(value, 2.0);
}

TEST(SpecificPower, Stream) {
  std::ostringstream stream;
  stream << SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram);
  EXPECT_EQ(stream.str(), SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram).Print());
}

TEST(SpecificPower, Unit) {
  EXPECT_EQ(SpecificPower<>::Unit(), Standard<Unit::SpecificPower>);
}

TEST(SpecificPower, Value) {
  EXPECT_EQ(SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram).Value(), 1.0);
  EXPECT_EQ(SpecificPower(2.0, Unit::SpecificPower::NanowattPerGram)
                .Value(Unit::SpecificPower::NanowattPerGram),
            2.0);
}

TEST(SpecificPower, XML) {
  EXPECT_EQ(SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram).XML(),
            "<value>" + Print(1.0) + "</value><unit>W/kg</unit>");
  EXPECT_EQ(SpecificPower(1.0, Unit::SpecificPower::NanowattPerGram)
                .XML(Unit::SpecificPower::NanowattPerGram),
            "<value>" + Print(1.0) + "</value><unit>nW/g</unit>");
}

TEST(SpecificPower, YAML) {
  EXPECT_EQ(SpecificPower(1.0, Unit::SpecificPower::WattPerKilogram).YAML(),
            "{value:" + Print(1.0) + ",unit:\"W/kg\"}");
  EXPECT_EQ(SpecificPower(1.0, Unit::SpecificPower::NanowattPerGram)
                .YAML(Unit::SpecificPower::NanowattPerGram),
            "{value:" + Print(1.0) + ",unit:\"nW/g\"}");
}

TEST(SpecificPower, Zero) {
  EXPECT_EQ(SpecificPower<>::Zero(), SpecificPower(0.0, Unit::SpecificPower::WattPerKilogram));
}

}  // namespace

}  // namespace PhQ
