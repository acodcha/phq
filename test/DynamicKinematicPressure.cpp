// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
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

#include "../include/PhQ/DynamicKinematicPressure.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/DynamicPressure.hpp"
#include "../include/PhQ/MassDensity.hpp"
#include "../include/PhQ/Speed.hpp"
#include "../include/PhQ/Unit/MassDensity.hpp"
#include "../include/PhQ/Unit/Pressure.hpp"
#include "../include/PhQ/Unit/SpecificEnergy.hpp"
#include "../include/PhQ/Unit/Speed.hpp"

namespace PhQ {

namespace {

TEST(DynamicKinematicPressure, ArithmeticOperatorAddition) {
  EXPECT_EQ(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram)
                + DynamicKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            DynamicKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(DynamicKinematicPressure, ArithmeticOperatorDivision) {
  EXPECT_EQ(DynamicKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram) / 2.0,
            DynamicKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(DynamicKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram)
                / DynamicKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            4.0);
  EXPECT_EQ(DynamicPressure(8.0, Unit::Pressure::Pascal)
                / MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
            DynamicKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(DynamicKinematicPressure, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(DynamicKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram) * 2.0,
            DynamicKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(2.0 * DynamicKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram),
            DynamicKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(DynamicKinematicPressure, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(DynamicKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram)
                - DynamicKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(DynamicKinematicPressure, AssignmentOperatorAddition) {
  DynamicKinematicPressure dynamic_kinematic_pressure{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  dynamic_kinematic_pressure +=
      DynamicKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(dynamic_kinematic_pressure,
            DynamicKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(DynamicKinematicPressure, AssignmentOperatorDivision) {
  DynamicKinematicPressure dynamic_kinematic_pressure{8.0, Unit::SpecificEnergy::JoulePerKilogram};
  dynamic_kinematic_pressure /= 2.0;
  EXPECT_EQ(dynamic_kinematic_pressure,
            DynamicKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(DynamicKinematicPressure, AssignmentOperatorMultiplication) {
  DynamicKinematicPressure dynamic_kinematic_pressure{4.0, Unit::SpecificEnergy::JoulePerKilogram};
  dynamic_kinematic_pressure *= 2.0;
  EXPECT_EQ(dynamic_kinematic_pressure,
            DynamicKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(DynamicKinematicPressure, AssignmentOperatorSubtraction) {
  DynamicKinematicPressure dynamic_kinematic_pressure{3.0, Unit::SpecificEnergy::JoulePerKilogram};
  dynamic_kinematic_pressure -=
      DynamicKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(dynamic_kinematic_pressure,
            DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(DynamicKinematicPressure, ComparisonOperators) {
  const DynamicKinematicPressure first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  const DynamicKinematicPressure second{2.0, Unit::SpecificEnergy::JoulePerKilogram};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(DynamicKinematicPressure, CopyAssignmentOperator) {
  {
    const DynamicKinematicPressure<float> first(1.0F, Unit::SpecificEnergy::JoulePerKilogram);
    DynamicKinematicPressure<double> second = DynamicKinematicPressure<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, DynamicKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const DynamicKinematicPressure<double> first(1.0, Unit::SpecificEnergy::JoulePerKilogram);
    DynamicKinematicPressure<double> second = DynamicKinematicPressure<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, DynamicKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const DynamicKinematicPressure<long double> first(1.0L, Unit::SpecificEnergy::JoulePerKilogram);
    DynamicKinematicPressure<double> second = DynamicKinematicPressure<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, DynamicKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
}

TEST(DynamicKinematicPressure, CopyConstructor) {
  {
    const DynamicKinematicPressure<float> first(1.0F, Unit::SpecificEnergy::JoulePerKilogram);
    const DynamicKinematicPressure<double> second{first};
    EXPECT_EQ(
        second, DynamicKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const DynamicKinematicPressure<double> first(1.0, Unit::SpecificEnergy::JoulePerKilogram);
    const DynamicKinematicPressure<double> second{first};
    EXPECT_EQ(
        second, DynamicKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
  {
    const DynamicKinematicPressure<long double> first(1.0L, Unit::SpecificEnergy::JoulePerKilogram);
    const DynamicKinematicPressure<double> second{first};
    EXPECT_EQ(
        second, DynamicKinematicPressure<double>(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  }
}

TEST(DynamicKinematicPressure, Create) {
  constexpr DynamicKinematicPressure dynamic_kinematic_pressure =
      DynamicKinematicPressure<>::Create<Unit::SpecificEnergy::JoulePerKilogram>(1.0);
  EXPECT_EQ(dynamic_kinematic_pressure,
            DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(DynamicKinematicPressure, DefaultConstructor) {
  EXPECT_NO_THROW(DynamicKinematicPressure<>{});
}

TEST(DynamicKinematicPressure, Dimensions) {
  EXPECT_EQ(DynamicKinematicPressure<>::Dimensions(), RelatedDimensions<Unit::SpecificEnergy>);
}

TEST(DynamicKinematicPressure, Hash) {
  const DynamicKinematicPressure first{1.0, Unit::SpecificEnergy::NanojoulePerGram};
  const DynamicKinematicPressure second{1.000001, Unit::SpecificEnergy::NanojoulePerGram};
  const DynamicKinematicPressure third{-1.0, Unit::SpecificEnergy::NanojoulePerGram};
  const std::hash<DynamicKinematicPressure<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DynamicKinematicPressure, JSON) {
  EXPECT_EQ(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"J/kg\"}");
  EXPECT_EQ(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .JSON(Unit::SpecificEnergy::NanojoulePerGram),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"nJ/g\"}");
}

TEST(DynamicKinematicPressure, MiscellaneousConstructors) {
  EXPECT_EQ(DynamicKinematicPressure(Speed(4.0, Unit::Speed::MetrePerSecond)),
            DynamicKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(DynamicKinematicPressure(DynamicPressure(8.0, Unit::Pressure::Pascal),
                                     MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)),
            DynamicKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(Speed(DynamicKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram)),
            Speed(4.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(DynamicPressure(MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                            DynamicKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram)),
            DynamicPressure(8.0, Unit::Pressure::Pascal));
}

TEST(DynamicKinematicPressure, MoveAssignmentOperator) {
  DynamicKinematicPressure first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  DynamicKinematicPressure second = DynamicKinematicPressure<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(DynamicKinematicPressure, MoveConstructor) {
  DynamicKinematicPressure first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  const DynamicKinematicPressure second{std::move(first)};
  EXPECT_EQ(second, DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(DynamicKinematicPressure, MutableValue) {
  DynamicKinematicPressure dynamic_kinematic_pressure{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  double& value = dynamic_kinematic_pressure.MutableValue();
  value = 2.0;
  EXPECT_EQ(dynamic_kinematic_pressure.Value(), 2.0);
}

TEST(DynamicKinematicPressure, Print) {
  EXPECT_EQ(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).Print(),
            Print(1.0) + " J/kg");
  EXPECT_EQ(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .Print(Unit::SpecificEnergy::NanojoulePerGram),
            Print(1.0) + " nJ/g");
}

TEST(DynamicKinematicPressure, SetValue) {
  DynamicKinematicPressure dynamic_kinematic_pressure{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  dynamic_kinematic_pressure.SetValue(2.0);
  EXPECT_EQ(dynamic_kinematic_pressure.Value(), 2.0);
}

TEST(DynamicKinematicPressure, SizeOf) {
  EXPECT_EQ(sizeof(DynamicKinematicPressure<>{}), sizeof(double));
}

TEST(DynamicKinematicPressure, StandardConstructor) {
  EXPECT_NO_THROW(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram));
}

TEST(DynamicKinematicPressure, StaticValue) {
  constexpr DynamicKinematicPressure dynamic_kinematic_pressure =
      DynamicKinematicPressure<>::Create<Unit::SpecificEnergy::NanojoulePerGram>(2.0);
  constexpr double value =
      dynamic_kinematic_pressure.StaticValue<Unit::SpecificEnergy::NanojoulePerGram>();
  EXPECT_EQ(value, 2.0);
}

TEST(DynamicKinematicPressure, Stream) {
  std::ostringstream stream;
  stream << DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(
      stream.str(), DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).Print());
}

TEST(DynamicKinematicPressure, Unit) {
  EXPECT_EQ(DynamicKinematicPressure<>::Unit(), Standard<Unit::SpecificEnergy>);
}

TEST(DynamicKinematicPressure, Value) {
  EXPECT_EQ(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).Value(), 1.0);
  EXPECT_EQ(DynamicKinematicPressure(2.0, Unit::SpecificEnergy::NanojoulePerGram)
                .Value(Unit::SpecificEnergy::NanojoulePerGram),
            2.0);
}

TEST(DynamicKinematicPressure, XML) {
  EXPECT_EQ(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).XML(),
            "<value>" + Print(1.0) + "</value><unit>J/kg</unit>");
  EXPECT_EQ(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .XML(Unit::SpecificEnergy::NanojoulePerGram),
            "<value>" + Print(1.0) + "</value><unit>nJ/g</unit>");
}

TEST(DynamicKinematicPressure, YAML) {
  EXPECT_EQ(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).YAML(),
            "{value:" + Print(1.0) + ",unit:\"J/kg\"}");
  EXPECT_EQ(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .YAML(Unit::SpecificEnergy::NanojoulePerGram),
            "{value:" + Print(1.0) + ",unit:\"nJ/g\"}");
}

TEST(DynamicKinematicPressure, Zero) {
  EXPECT_EQ(DynamicKinematicPressure<>::Zero(),
            DynamicKinematicPressure(0.0, Unit::SpecificEnergy::JoulePerKilogram));
}

}  // namespace

}  // namespace PhQ
