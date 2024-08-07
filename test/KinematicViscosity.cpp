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

#include "../include/PhQ/KinematicViscosity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Diffusivity.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(KinematicViscosity, ArithmeticOperatorAddition) {
  EXPECT_EQ(KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond)
                + KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond),
            KinematicViscosity(3.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(KinematicViscosity, ArithmeticOperatorDivision) {
  EXPECT_EQ(KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond) / 2.0,
            KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond));
  EXPECT_EQ(KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond)
                / KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond),
            4.0);
}

TEST(KinematicViscosity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond) * 2.0,
            KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond));
  EXPECT_EQ(2.0 * KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond),
            KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(KinematicViscosity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(KinematicViscosity(3.0, Unit::Diffusivity::SquareMetrePerSecond)
                - KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond),
            KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(KinematicViscosity, AssignmentOperatorAddition) {
  KinematicViscosity kinematic_viscosity{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  kinematic_viscosity += KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond);
  EXPECT_EQ(kinematic_viscosity, KinematicViscosity(3.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(KinematicViscosity, AssignmentOperatorDivision) {
  KinematicViscosity kinematic_viscosity{8.0, Unit::Diffusivity::SquareMetrePerSecond};
  kinematic_viscosity /= 2.0;
  EXPECT_EQ(kinematic_viscosity, KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(KinematicViscosity, AssignmentOperatorMultiplication) {
  KinematicViscosity kinematic_viscosity{4.0, Unit::Diffusivity::SquareMetrePerSecond};
  kinematic_viscosity *= 2.0;
  EXPECT_EQ(kinematic_viscosity, KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(KinematicViscosity, AssignmentOperatorSubtraction) {
  KinematicViscosity kinematic_viscosity{3.0, Unit::Diffusivity::SquareMetrePerSecond};
  kinematic_viscosity -= KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond);
  EXPECT_EQ(kinematic_viscosity, KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(KinematicViscosity, ComparisonOperators) {
  const KinematicViscosity first{0.1, Unit::Diffusivity::SquareMetrePerSecond};
  const KinematicViscosity second{0.2, Unit::Diffusivity::SquareMetrePerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(KinematicViscosity, Constructor) {
  EXPECT_NO_THROW(KinematicViscosity(1.0, Unit::Diffusivity::SquareFootPerSecond));
}

TEST(KinematicViscosity, CopyAssignmentOperator) {
  {
    const KinematicViscosity<float> first(1.0F, Unit::Diffusivity::SquareMetrePerSecond);
    KinematicViscosity<double> second = KinematicViscosity<double>::Zero();
    second = first;
    EXPECT_EQ(second, KinematicViscosity<double>(1.0, Unit::Diffusivity::SquareMetrePerSecond));
  }
  {
    const KinematicViscosity<double> first(1.0, Unit::Diffusivity::SquareMetrePerSecond);
    KinematicViscosity<double> second = KinematicViscosity<double>::Zero();
    second = first;
    EXPECT_EQ(second, KinematicViscosity<double>(1.0, Unit::Diffusivity::SquareMetrePerSecond));
  }
  {
    const KinematicViscosity<long double> first(1.0L, Unit::Diffusivity::SquareMetrePerSecond);
    KinematicViscosity<double> second = KinematicViscosity<double>::Zero();
    second = first;
    EXPECT_EQ(second, KinematicViscosity<double>(1.0, Unit::Diffusivity::SquareMetrePerSecond));
  }
}

TEST(KinematicViscosity, CopyConstructor) {
  {
    const KinematicViscosity<float> first(1.0F, Unit::Diffusivity::SquareMetrePerSecond);
    const KinematicViscosity<double> second{first};
    EXPECT_EQ(second, KinematicViscosity<double>(1.0, Unit::Diffusivity::SquareMetrePerSecond));
  }
  {
    const KinematicViscosity<double> first(1.0, Unit::Diffusivity::SquareMetrePerSecond);
    const KinematicViscosity<double> second{first};
    EXPECT_EQ(second, KinematicViscosity<double>(1.0, Unit::Diffusivity::SquareMetrePerSecond));
  }
  {
    const KinematicViscosity<long double> first(1.0L, Unit::Diffusivity::SquareMetrePerSecond);
    const KinematicViscosity<double> second{first};
    EXPECT_EQ(second, KinematicViscosity<double>(1.0, Unit::Diffusivity::SquareMetrePerSecond));
  }
}

TEST(KinematicViscosity, Create) {
  constexpr KinematicViscosity kinematic_viscosity =
      KinematicViscosity<>::Create<Unit::Diffusivity::SquareMetrePerSecond>(1.0);
  EXPECT_EQ(kinematic_viscosity, KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(KinematicViscosity, DefaultConstructor) {
  EXPECT_NO_THROW(KinematicViscosity<>{});
}

TEST(KinematicViscosity, Dimensions) {
  EXPECT_EQ(KinematicViscosity<>::Dimensions(), RelatedDimensions<Unit::Diffusivity>);
}

TEST(KinematicViscosity, Hash) {
  const KinematicViscosity first{1.0, Unit::Diffusivity::SquareFootPerSecond};
  const KinematicViscosity second{1.00001, Unit::Diffusivity::SquareFootPerSecond};
  const KinematicViscosity third{-1.0, Unit::Diffusivity::SquareFootPerSecond};
  const std::hash<KinematicViscosity<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(KinematicViscosity, JSON) {
  EXPECT_EQ(KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"m^2/s\"}");
  EXPECT_EQ(KinematicViscosity(1.0, Unit::Diffusivity::SquareFootPerSecond)
                .JSON(Unit::Diffusivity::SquareFootPerSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"ft^2/s\"}");
}

TEST(KinematicViscosity, MoveAssignmentOperator) {
  KinematicViscosity first{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  KinematicViscosity second = KinematicViscosity<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(KinematicViscosity, MoveConstructor) {
  KinematicViscosity first{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  const KinematicViscosity second{std::move(first)};
  EXPECT_EQ(second, KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond));
}

TEST(KinematicViscosity, MutableValue) {
  KinematicViscosity kinematic_viscosity{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  double& value = kinematic_viscosity.MutableValue();
  value = 2.0;
  EXPECT_EQ(kinematic_viscosity.Value(), 2.0);
}

TEST(KinematicViscosity, Performance) {
  KinematicViscosity first{1.2345678901234567890, Unit::Diffusivity::SquareMetrePerSecond};
  KinematicViscosity second{1.2345678901234567890, Unit::Diffusivity::SquareMetrePerSecond};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(KinematicViscosity, Print) {
  EXPECT_EQ(KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond).Print(),
            Print(1.0) + " m^2/s");
  EXPECT_EQ(KinematicViscosity(1.0, Unit::Diffusivity::SquareFootPerSecond)
                .Print(Unit::Diffusivity::SquareFootPerSecond),
            Print(1.0) + " ft^2/s");
}

TEST(KinematicViscosity, SetValue) {
  KinematicViscosity kinematic_viscosity{1.0, Unit::Diffusivity::SquareMetrePerSecond};
  kinematic_viscosity.SetValue(2.0);
  EXPECT_EQ(kinematic_viscosity.Value(), 2.0);
}

TEST(KinematicViscosity, SizeOf) {
  EXPECT_EQ(sizeof(KinematicViscosity<>{}), sizeof(double));
}

TEST(KinematicViscosity, StaticValue) {
  constexpr KinematicViscosity kinematic_viscosity =
      KinematicViscosity<>::Create<Unit::Diffusivity::SquareFootPerSecond>(1.0);
  constexpr double value =
      kinematic_viscosity.StaticValue<Unit::Diffusivity::SquareFootPerSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(KinematicViscosity, Stream) {
  std::ostringstream stream;
  stream << KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond);
  EXPECT_EQ(stream.str(), KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond).Print());
}

TEST(KinematicViscosity, Unit) {
  EXPECT_EQ(KinematicViscosity<>::Unit(), Standard<Unit::Diffusivity>);
}

TEST(KinematicViscosity, Value) {
  EXPECT_EQ(KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond).Value(), 1.0);
  EXPECT_EQ(KinematicViscosity(1.0, Unit::Diffusivity::SquareFootPerSecond)
                .Value(Unit::Diffusivity::SquareFootPerSecond),
            1.0);
}

TEST(KinematicViscosity, XML) {
  EXPECT_EQ(KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>m^2/s</unit>");
  EXPECT_EQ(KinematicViscosity(1.0, Unit::Diffusivity::SquareFootPerSecond)
                .XML(Unit::Diffusivity::SquareFootPerSecond),
            "<value>" + Print(1.0) + "</value><unit>ft^2/s</unit>");
}

TEST(KinematicViscosity, YAML) {
  EXPECT_EQ(KinematicViscosity(1.0, Unit::Diffusivity::SquareMetrePerSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"m^2/s\"}");
  EXPECT_EQ(KinematicViscosity(1.0, Unit::Diffusivity::SquareFootPerSecond)
                .YAML(Unit::Diffusivity::SquareFootPerSecond),
            "{value:" + Print(1.0) + ",unit:\"ft^2/s\"}");
}

TEST(KinematicViscosity, Zero) {
  EXPECT_EQ(KinematicViscosity<>::Zero(),
            KinematicViscosity(0.0, Unit::Diffusivity::SquareMetrePerSecond));
}

}  // namespace

}  // namespace PhQ
