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

#include "../include/PhQ/SpecificEnergy.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Energy.hpp"
#include "../include/PhQ/Mass.hpp"
#include "../include/PhQ/Unit/Energy.hpp"
#include "../include/PhQ/Unit/Mass.hpp"
#include "../include/PhQ/Unit/SpecificEnergy.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(SpecificEnergy, ArithmeticOperatorAddition) {
  EXPECT_EQ(SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram)
                + SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            SpecificEnergy(3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, ArithmeticOperatorDivision) {
  EXPECT_EQ(SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram) / 2.0,
            SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram)
                / SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            4.0);
  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule)
                / SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram),
            Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule) / Mass(4.0, Unit::Mass::Kilogram),
            SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram) * 2.0,
            SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(2.0 * SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram),
            SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(
      SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram) * Mass(2.0, Unit::Mass::Kilogram),
      Energy(8.0, Unit::Energy::Joule));
  EXPECT_EQ(
      Mass(4.0, Unit::Mass::Kilogram) * SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram),
      Energy(8.0, Unit::Energy::Joule));
}

TEST(SpecificEnergy, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(SpecificEnergy(3.0, Unit::SpecificEnergy::JoulePerKilogram)
                - SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, AssignmentOperatorAddition) {
  SpecificEnergy quantity{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity += SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(quantity, SpecificEnergy(3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, AssignmentOperatorDivision) {
  SpecificEnergy quantity{8.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity /= 2.0;
  EXPECT_EQ(quantity, SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, AssignmentOperatorMultiplication) {
  SpecificEnergy quantity{4.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity *= 2.0;
  EXPECT_EQ(quantity, SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, AssignmentOperatorSubtraction) {
  SpecificEnergy quantity{3.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity -= SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(quantity, SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, ComparisonOperators) {
  const SpecificEnergy first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  const SpecificEnergy second{2.0, Unit::SpecificEnergy::JoulePerKilogram};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(SpecificEnergy, Constructor) {
  EXPECT_NO_THROW(SpecificEnergy(1.0, Unit::SpecificEnergy::NanojoulePerGram));
  EXPECT_EQ(SpecificEnergy(Energy(8.0, Unit::Energy::Joule), Mass(4.0, Unit::Mass::Kilogram)),
            SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(Mass(Energy(8.0, Unit::Energy::Joule),
                 SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram)),
            Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(Energy(SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram),
                   Mass(2.0, Unit::Mass::Kilogram)),
            Energy(8.0, Unit::Energy::Joule));
}

TEST(SpecificEnergy, CopyAssignmentOperator) {
  {
    const SpecificEnergy<float> first(1.0F, Unit::SpecificEnergy::JoulePerKilogram);
    SpecificEnergy<double> second = SpecificEnergy<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificEnergy<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const SpecificEnergy<double> first(1.0, Unit::SpecificEnergy::JoulePerKilogram);
    SpecificEnergy<double> second = SpecificEnergy<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificEnergy<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const SpecificEnergy<long double> first(1.0L, Unit::SpecificEnergy::JoulePerKilogram);
    SpecificEnergy<double> second = SpecificEnergy<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificEnergy<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
}

TEST(SpecificEnergy, CopyConstructor) {
  {
    const SpecificEnergy<float> first(1.0F, Unit::SpecificEnergy::JoulePerKilogram);
    const SpecificEnergy<double> second{first};
    EXPECT_EQ(second, SpecificEnergy<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const SpecificEnergy<double> first(1.0, Unit::SpecificEnergy::JoulePerKilogram);
    const SpecificEnergy<double> second{first};
    EXPECT_EQ(second, SpecificEnergy<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const SpecificEnergy<long double> first(1.0L, Unit::SpecificEnergy::JoulePerKilogram);
    const SpecificEnergy<double> second{first};
    EXPECT_EQ(second, SpecificEnergy<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
}

TEST(SpecificEnergy, Create) {
  constexpr SpecificEnergy quantity =
      SpecificEnergy<>::Create<Unit::SpecificEnergy::JoulePerKilogram>(1.0);
  EXPECT_EQ(quantity, SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, DefaultConstructor) {
  EXPECT_NO_THROW(SpecificEnergy<>{});
}

TEST(SpecificEnergy, Dimensions) {
  EXPECT_EQ(SpecificEnergy<>::Dimensions(), RelatedDimensions<Unit::SpecificEnergy>);
}

TEST(SpecificEnergy, Hash) {
  const SpecificEnergy first{1.0, Unit::SpecificEnergy::NanojoulePerGram};
  const SpecificEnergy second{1.00001, Unit::SpecificEnergy::NanojoulePerGram};
  const SpecificEnergy third{-1.0, Unit::SpecificEnergy::NanojoulePerGram};
  const std::hash<SpecificEnergy<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(SpecificEnergy, JSON) {
  EXPECT_EQ(SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"J/kg\"}");
  EXPECT_EQ(SpecificEnergy(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .JSON(Unit::SpecificEnergy::NanojoulePerGram),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"nJ/g\"}");
}

TEST(SpecificEnergy, MoveAssignmentOperator) {
  SpecificEnergy first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  SpecificEnergy second = SpecificEnergy<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, MoveConstructor) {
  SpecificEnergy first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  const SpecificEnergy second{std::move(first)};
  EXPECT_EQ(second, SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, MutableValue) {
  SpecificEnergy quantity{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SpecificEnergy, Performance) {
  SpecificEnergy first{1.2345678901234567890, Unit::SpecificEnergy::JoulePerKilogram};
  SpecificEnergy second{1.2345678901234567890, Unit::SpecificEnergy::JoulePerKilogram};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(SpecificEnergy, Print) {
  EXPECT_EQ(
      SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram).Print(), Print(1.0) + " J/kg");
  EXPECT_EQ(SpecificEnergy(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .Print(Unit::SpecificEnergy::NanojoulePerGram),
            Print(1.0) + " nJ/g");
}

TEST(SpecificEnergy, SetValue) {
  SpecificEnergy quantity{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SpecificEnergy, SizeOf) {
  EXPECT_EQ(sizeof(SpecificEnergy<>{}), sizeof(double));
}

TEST(SpecificEnergy, StaticValue) {
  constexpr SpecificEnergy quantity =
      SpecificEnergy<>::Create<Unit::SpecificEnergy::NanojoulePerGram>(2.0);
  constexpr double value = quantity.StaticValue<Unit::SpecificEnergy::NanojoulePerGram>();
  EXPECT_EQ(value, 2.0);
}

TEST(SpecificEnergy, Stream) {
  std::ostringstream stream;
  stream << SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(stream.str(), SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram).Print());
}

TEST(SpecificEnergy, Unit) {
  EXPECT_EQ(SpecificEnergy<>::Unit(), Standard<Unit::SpecificEnergy>);
}

TEST(SpecificEnergy, Value) {
  EXPECT_EQ(SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram).Value(), 1.0);
  EXPECT_EQ(SpecificEnergy(2.0, Unit::SpecificEnergy::NanojoulePerGram)
                .Value(Unit::SpecificEnergy::NanojoulePerGram),
            2.0);
}

TEST(SpecificEnergy, XML) {
  EXPECT_EQ(SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram).XML(),
            "<value>" + Print(1.0) + "</value><unit>J/kg</unit>");
  EXPECT_EQ(SpecificEnergy(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .XML(Unit::SpecificEnergy::NanojoulePerGram),
            "<value>" + Print(1.0) + "</value><unit>nJ/g</unit>");
}

TEST(SpecificEnergy, YAML) {
  EXPECT_EQ(SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram).YAML(),
            "{value:" + Print(1.0) + ",unit:\"J/kg\"}");
  EXPECT_EQ(SpecificEnergy(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .YAML(Unit::SpecificEnergy::NanojoulePerGram),
            "{value:" + Print(1.0) + ",unit:\"nJ/g\"}");
}

TEST(SpecificEnergy, Zero) {
  EXPECT_EQ(SpecificEnergy<>::Zero(), SpecificEnergy(0.0, Unit::SpecificEnergy::JoulePerKilogram));
}

}  // namespace

}  // namespace PhQ
