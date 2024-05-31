// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/StaticKinematicPressure.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/MassDensity.hpp"
#include "../include/PhQ/StaticPressure.hpp"
#include "../include/PhQ/Unit/MassDensity.hpp"
#include "../include/PhQ/Unit/Pressure.hpp"
#include "../include/PhQ/Unit/SpecificEnergy.hpp"

namespace PhQ {

namespace {

TEST(StaticKinematicPressure, ArithmeticOperatorAddition) {
  EXPECT_EQ(StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram)
                + StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            StaticKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, ArithmeticOperatorDivision) {
  EXPECT_EQ(StaticKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram) / 2.0,
            StaticKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(StaticKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram)
                / StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            4.0);
  EXPECT_EQ(StaticPressure(8.0, Unit::Pressure::Pascal)
                / MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
            StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(StaticKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram) * 2.0,
            StaticKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(2.0 * StaticKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram),
            StaticKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(StaticKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram)
                * MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            StaticPressure(8.0, Unit::Pressure::Pascal));
}

TEST(StaticKinematicPressure, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(StaticKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram)
                - StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, AssignmentOperatorAddition) {
  StaticKinematicPressure quantity{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity += StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(quantity, StaticKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, AssignmentOperatorDivision) {
  StaticKinematicPressure quantity{8.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity /= 2.0;
  EXPECT_EQ(quantity, StaticKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, AssignmentOperatorMultiplication) {
  StaticKinematicPressure quantity{4.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity *= 2.0;
  EXPECT_EQ(quantity, StaticKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, AssignmentOperatorSubtraction) {
  StaticKinematicPressure quantity{3.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity -= StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(quantity, StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, ComparisonOperators) {
  const StaticKinematicPressure first{0.1, Unit::SpecificEnergy::JoulePerKilogram};
  const StaticKinematicPressure second{0.2, Unit::SpecificEnergy::JoulePerKilogram};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(StaticKinematicPressure, Constructor) {
  EXPECT_NO_THROW(StaticKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram));
  EXPECT_EQ(StaticKinematicPressure(StaticPressure(8.0, Unit::Pressure::Pascal),
                                    MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)),
            StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(StaticPressure(MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                           StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram)),
            StaticPressure(8.0, Unit::Pressure::Pascal));
}

TEST(StaticKinematicPressure, CopyAssignmentOperator) {
  {
    const StaticKinematicPressure<float> first(1.0F, Unit::SpecificEnergy::JoulePerKilogram);
    StaticKinematicPressure<double> second = StaticKinematicPressure<double>::Zero();
    second = first;
    EXPECT_EQ(second, StaticKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const StaticKinematicPressure<double> first(1.0, Unit::SpecificEnergy::JoulePerKilogram);
    StaticKinematicPressure<double> second = StaticKinematicPressure<double>::Zero();
    second = first;
    EXPECT_EQ(second, StaticKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const StaticKinematicPressure<long double> first(1.0L, Unit::SpecificEnergy::JoulePerKilogram);
    StaticKinematicPressure<double> second = StaticKinematicPressure<double>::Zero();
    second = first;
    EXPECT_EQ(second, StaticKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
}

TEST(StaticKinematicPressure, CopyConstructor) {
  {
    const StaticKinematicPressure<float> first(1.0F, Unit::SpecificEnergy::JoulePerKilogram);
    const StaticKinematicPressure<double> second{first};
    EXPECT_EQ(second, StaticKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const StaticKinematicPressure<double> first(1.0, Unit::SpecificEnergy::JoulePerKilogram);
    const StaticKinematicPressure<double> second{first};
    EXPECT_EQ(second, StaticKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const StaticKinematicPressure<long double> first(1.0L, Unit::SpecificEnergy::JoulePerKilogram);
    const StaticKinematicPressure<double> second{first};
    EXPECT_EQ(second, StaticKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
}

TEST(StaticKinematicPressure, Create) {
  constexpr StaticKinematicPressure quantity =
      StaticKinematicPressure<>::Create<Unit::SpecificEnergy::JoulePerKilogram>(1.0);
  EXPECT_EQ(quantity, StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, DefaultConstructor) {
  EXPECT_NO_THROW(StaticKinematicPressure<>{});
}

TEST(StaticKinematicPressure, Dimensions) {
  EXPECT_EQ(StaticKinematicPressure<>::Dimensions(), RelatedDimensions<Unit::SpecificEnergy>);
}

TEST(StaticKinematicPressure, Hash) {
  const StaticKinematicPressure first{1.0, Unit::SpecificEnergy::NanojoulePerGram};
  const StaticKinematicPressure second{1.00001, Unit::SpecificEnergy::NanojoulePerGram};
  const StaticKinematicPressure third{-1.0, Unit::SpecificEnergy::NanojoulePerGram};
  const std::hash<StaticKinematicPressure<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(StaticKinematicPressure, JSON) {
  EXPECT_EQ(StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"J/kg\"}");
  EXPECT_EQ(StaticKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .JSON(Unit::SpecificEnergy::NanojoulePerGram),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"nJ/g\"}");
}

TEST(StaticKinematicPressure, MoveAssignmentOperator) {
  StaticKinematicPressure first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  StaticKinematicPressure second = StaticKinematicPressure<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, MoveConstructor) {
  StaticKinematicPressure first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  const StaticKinematicPressure second{std::move(first)};
  EXPECT_EQ(second, StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, MutableValue) {
  StaticKinematicPressure quantity{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(StaticKinematicPressure, Print) {
  EXPECT_EQ(StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).Print(),
            Print(1.0) + " J/kg");
  EXPECT_EQ(StaticKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .Print(Unit::SpecificEnergy::NanojoulePerGram),
            Print(1.0) + " nJ/g");
}

TEST(StaticKinematicPressure, SetValue) {
  StaticKinematicPressure quantity{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(StaticKinematicPressure, SizeOf) {
  EXPECT_EQ(sizeof(StaticKinematicPressure<>{}), sizeof(double));
}

TEST(StaticKinematicPressure, StaticValue) {
  constexpr StaticKinematicPressure quantity =
      StaticKinematicPressure<>::Create<Unit::SpecificEnergy::NanojoulePerGram>(2.0);
  constexpr double value = quantity.StaticValue<Unit::SpecificEnergy::NanojoulePerGram>();
  EXPECT_EQ(value, 2.0);
}

TEST(StaticKinematicPressure, Stream) {
  std::ostringstream stream;
  stream << StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(
      stream.str(), StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).Print());
}

TEST(StaticKinematicPressure, Unit) {
  EXPECT_EQ(StaticKinematicPressure<>::Unit(), Standard<Unit::SpecificEnergy>);
}

TEST(StaticKinematicPressure, Value) {
  EXPECT_EQ(StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).Value(), 1.0);
  EXPECT_EQ(StaticKinematicPressure(2.0, Unit::SpecificEnergy::NanojoulePerGram)
                .Value(Unit::SpecificEnergy::NanojoulePerGram),
            2.0);
}

TEST(StaticKinematicPressure, XML) {
  EXPECT_EQ(StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).XML(),
            "<value>" + Print(1.0) + "</value><unit>J/kg</unit>");
  EXPECT_EQ(StaticKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .XML(Unit::SpecificEnergy::NanojoulePerGram),
            "<value>" + Print(1.0) + "</value><unit>nJ/g</unit>");
}

TEST(StaticKinematicPressure, YAML) {
  EXPECT_EQ(StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).YAML(),
            "{value:" + Print(1.0) + ",unit:\"J/kg\"}");
  EXPECT_EQ(StaticKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .YAML(Unit::SpecificEnergy::NanojoulePerGram),
            "{value:" + Print(1.0) + ",unit:\"nJ/g\"}");
}

TEST(StaticKinematicPressure, Zero) {
  EXPECT_EQ(StaticKinematicPressure<>::Zero(),
            StaticKinematicPressure(0.0, Unit::SpecificEnergy::JoulePerKilogram));
}

}  // namespace

}  // namespace PhQ
