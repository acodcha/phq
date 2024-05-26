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

#include "../include/PhQ/DynamicViscosity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/KinematicViscosity.hpp"
#include "../include/PhQ/MassDensity.hpp"
#include "../include/PhQ/Unit/Diffusivity.hpp"
#include "../include/PhQ/Unit/DynamicViscosity.hpp"
#include "../include/PhQ/Unit/MassDensity.hpp"

namespace PhQ {

namespace {

TEST(DynamicViscosity, ArithmeticOperatorAddition) {
  EXPECT_EQ(DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)
                + DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            DynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, ArithmeticOperatorDivision) {
  EXPECT_EQ(DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond) / 2.0,
            DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  EXPECT_EQ(DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond)
                / DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            4.0);
  EXPECT_EQ(DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond)
                / MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
            KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond));
  EXPECT_EQ(DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond)
                / KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond),
            MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(DynamicViscosity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond) * 2.0,
            DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));
  EXPECT_EQ(2.0 * DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond),
            DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));
  EXPECT_EQ(KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond)
                * MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));
  EXPECT_EQ(MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)
                * KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond),
            DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(DynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond)
                - DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, AssignmentOperatorAddition) {
  DynamicViscosity dynamic_viscosity{1.0, Unit::DynamicViscosity::PascalSecond};
  dynamic_viscosity += DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond);
  EXPECT_EQ(dynamic_viscosity, DynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, AssignmentOperatorDivision) {
  DynamicViscosity dynamic_viscosity{8.0, Unit::DynamicViscosity::PascalSecond};
  dynamic_viscosity /= 2.0;
  EXPECT_EQ(dynamic_viscosity, DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, AssignmentOperatorMultiplication) {
  DynamicViscosity dynamic_viscosity{4.0, Unit::DynamicViscosity::PascalSecond};
  dynamic_viscosity *= 2.0;
  EXPECT_EQ(dynamic_viscosity, DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, AssignmentOperatorSubtraction) {
  DynamicViscosity dynamic_viscosity{3.0, Unit::DynamicViscosity::PascalSecond};
  dynamic_viscosity -= DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond);
  EXPECT_EQ(dynamic_viscosity, DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, ComparisonOperators) {
  const DynamicViscosity first{1.0, Unit::DynamicViscosity::PascalSecond};
  const DynamicViscosity second{2.0, Unit::DynamicViscosity::PascalSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(DynamicViscosity, CopyAssignmentOperator) {
  {
    const DynamicViscosity<float> first(1.0F, Unit::DynamicViscosity::PascalSecond);
    DynamicViscosity<double> second = DynamicViscosity<double>::Zero();
    second = first;
    EXPECT_EQ(second, DynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
  {
    const DynamicViscosity<double> first(1.0, Unit::DynamicViscosity::PascalSecond);
    DynamicViscosity<double> second = DynamicViscosity<double>::Zero();
    second = first;
    EXPECT_EQ(second, DynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
  {
    const DynamicViscosity<long double> first(1.0L, Unit::DynamicViscosity::PascalSecond);
    DynamicViscosity<double> second = DynamicViscosity<double>::Zero();
    second = first;
    EXPECT_EQ(second, DynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
}

TEST(DynamicViscosity, CopyConstructor) {
  {
    const DynamicViscosity<float> first(1.0F, Unit::DynamicViscosity::PascalSecond);
    const DynamicViscosity<double> second{first};
    EXPECT_EQ(second, DynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
  {
    const DynamicViscosity<double> first(1.0, Unit::DynamicViscosity::PascalSecond);
    const DynamicViscosity<double> second{first};
    EXPECT_EQ(second, DynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
  {
    const DynamicViscosity<long double> first(1.0L, Unit::DynamicViscosity::PascalSecond);
    const DynamicViscosity<double> second{first};
    EXPECT_EQ(second, DynamicViscosity<double>(1.0, Unit::DynamicViscosity::PascalSecond));
  }
}

TEST(DynamicViscosity, Create) {
  constexpr DynamicViscosity dynamic_viscosity =
      DynamicViscosity<>::Create<Unit::DynamicViscosity::PascalSecond>(1.0);
  EXPECT_EQ(dynamic_viscosity, DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, DefaultConstructor) {
  EXPECT_NO_THROW(DynamicViscosity<>{});
}

TEST(DynamicViscosity, Dimensions) {
  EXPECT_EQ(DynamicViscosity<>::Dimensions(), RelatedDimensions<Unit::DynamicViscosity>);
}

TEST(DynamicViscosity, Hash) {
  const DynamicViscosity first{1.0, Unit::DynamicViscosity::KilopascalSecond};
  const DynamicViscosity second{1.000001, Unit::DynamicViscosity::KilopascalSecond};
  const DynamicViscosity third{-1.0, Unit::DynamicViscosity::KilopascalSecond};
  const std::hash<DynamicViscosity<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DynamicViscosity, JSON) {
  EXPECT_EQ(DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Pa·s\"}");
  EXPECT_EQ(DynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond)
                .JSON(Unit::DynamicViscosity::KilopascalSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kPa·s\"}");
}

TEST(DynamicViscosity, MiscellaneousConstructors) {
  EXPECT_EQ(DynamicViscosity(MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                             KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond)),
            DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));
  EXPECT_EQ(KinematicViscosity(DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                               MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)),
            KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond));
  EXPECT_EQ(MassDensity(DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                        KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond)),
            MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(DynamicViscosity, MoveAssignmentOperator) {
  DynamicViscosity first{1.0, Unit::DynamicViscosity::PascalSecond};
  DynamicViscosity second = DynamicViscosity<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, MoveConstructor) {
  DynamicViscosity first{1.0, Unit::DynamicViscosity::PascalSecond};
  const DynamicViscosity second{std::move(first)};
  EXPECT_EQ(second, DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, MutableValue) {
  DynamicViscosity dynamic_viscosity{1.0, Unit::DynamicViscosity::PascalSecond};
  double& value = dynamic_viscosity.MutableValue();
  value = 2.0;
  EXPECT_EQ(dynamic_viscosity.Value(), 2.0);
}

TEST(DynamicViscosity, Print) {
  EXPECT_EQ(
      DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).Print(), Print(1.0) + " Pa·s");
  EXPECT_EQ(DynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond)
                .Print(Unit::DynamicViscosity::KilopascalSecond),
            Print(1.0) + " kPa·s");
}

TEST(DynamicViscosity, SetValue) {
  DynamicViscosity dynamic_viscosity{1.0, Unit::DynamicViscosity::PascalSecond};
  dynamic_viscosity.SetValue(2.0);
  EXPECT_EQ(dynamic_viscosity.Value(), 2.0);
}

TEST(DynamicViscosity, SizeOf) {
  EXPECT_EQ(sizeof(DynamicViscosity<>{}), sizeof(double));
}

TEST(DynamicViscosity, StandardConstructor) {
  EXPECT_NO_THROW(DynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond));
}

TEST(DynamicViscosity, StaticValue) {
  constexpr DynamicViscosity dynamic_viscosity =
      DynamicViscosity<>::Create<Unit::DynamicViscosity::KilopascalSecond>(1.0);
  constexpr double value =
      dynamic_viscosity.StaticValue<Unit::DynamicViscosity::KilopascalSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(DynamicViscosity, Stream) {
  std::ostringstream stream;
  stream << DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond);
  EXPECT_EQ(stream.str(), DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).Print());
}

TEST(DynamicViscosity, Unit) {
  EXPECT_EQ(DynamicViscosity<>::Unit(), Standard<Unit::DynamicViscosity>);
}

TEST(DynamicViscosity, Value) {
  EXPECT_EQ(DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).Value(), 1.0);
  EXPECT_EQ(DynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond)
                .Value(Unit::DynamicViscosity::KilopascalSecond),
            1.0);
}

TEST(DynamicViscosity, XML) {
  EXPECT_EQ(DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>Pa·s</unit>");
  EXPECT_EQ(DynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond)
                .XML(Unit::DynamicViscosity::KilopascalSecond),
            "<value>" + Print(1.0) + "</value><unit>kPa·s</unit>");
}

TEST(DynamicViscosity, YAML) {
  EXPECT_EQ(DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"Pa·s\"}");
  EXPECT_EQ(DynamicViscosity(1.0, Unit::DynamicViscosity::KilopascalSecond)
                .YAML(Unit::DynamicViscosity::KilopascalSecond),
            "{value:" + Print(1.0) + ",unit:\"kPa·s\"}");
}

TEST(DynamicViscosity, Zero) {
  EXPECT_EQ(
      DynamicViscosity<>::Zero(), DynamicViscosity(0.0, Unit::DynamicViscosity::PascalSecond));
}

}  // namespace

}  // namespace PhQ
