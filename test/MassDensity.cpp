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

#include "../include/PhQ/MassDensity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Mass.hpp"
#include "../include/PhQ/Unit/Mass.hpp"
#include "../include/PhQ/Unit/MassDensity.hpp"
#include "../include/PhQ/Unit/Volume.hpp"
#include "../include/PhQ/Volume.hpp"

namespace PhQ {

namespace {

TEST(MassDensity, ArithmeticOperatorAddition) {
  EXPECT_EQ(MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre)
                + MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            MassDensity(3.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, ArithmeticOperatorDivision) {
  EXPECT_EQ(MassDensity(8.0, Unit::MassDensity::KilogramPerCubicMetre) / 2.0,
            MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre));
  EXPECT_EQ(MassDensity(8.0, Unit::MassDensity::KilogramPerCubicMetre)
                / MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            4.0);
  EXPECT_EQ(Mass(8.0, Unit::Mass::Kilogram) / Volume(4.0, Unit::Volume::CubicMetre),
            MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre));
  EXPECT_EQ(
      Mass(8.0, Unit::Mass::Kilogram) / MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
      Volume(2.0, Unit::Volume::CubicMetre));
}

TEST(MassDensity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre) * 2.0,
            MassDensity(8.0, Unit::MassDensity::KilogramPerCubicMetre));
  EXPECT_EQ(2.0 * MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
            MassDensity(8.0, Unit::MassDensity::KilogramPerCubicMetre));
  EXPECT_EQ(MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)
                * Volume(2.0, Unit::Volume::CubicMetre),
            Mass(8.0, Unit::Mass::Kilogram));
  EXPECT_EQ(Volume(4.0, Unit::Volume::CubicMetre)
                * MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            Mass(8.0, Unit::Mass::Kilogram));
}

TEST(MassDensity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(MassDensity(3.0, Unit::MassDensity::KilogramPerCubicMetre)
                - MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, AssignmentOperatorAddition) {
  MassDensity mass_density{1.0, Unit::MassDensity::KilogramPerCubicMetre};
  mass_density += MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre);
  EXPECT_EQ(mass_density, MassDensity(3.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, AssignmentOperatorDivision) {
  MassDensity mass_density{8.0, Unit::MassDensity::KilogramPerCubicMetre};
  mass_density /= 2.0;
  EXPECT_EQ(mass_density, MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, AssignmentOperatorMultiplication) {
  MassDensity mass_density{4.0, Unit::MassDensity::KilogramPerCubicMetre};
  mass_density *= 2.0;
  EXPECT_EQ(mass_density, MassDensity(8.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, AssignmentOperatorSubtraction) {
  MassDensity mass_density{3.0, Unit::MassDensity::KilogramPerCubicMetre};
  mass_density -= MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre);
  EXPECT_EQ(mass_density, MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, ComparisonOperators) {
  const MassDensity first{1.0, Unit::MassDensity::KilogramPerCubicMetre};
  const MassDensity second{2.0, Unit::MassDensity::KilogramPerCubicMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(MassDensity, CopyAssignmentOperator) {
  const MassDensity first{1.0, Unit::MassDensity::KilogramPerCubicMetre};
  MassDensity second = MassDensity<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(MassDensity, CopyConstructor) {
  const MassDensity first{1.0, Unit::MassDensity::KilogramPerCubicMetre};
  const MassDensity second{first};
  EXPECT_EQ(second, first);
}

TEST(MassDensity, Create) {
  constexpr MassDensity mass_density =
      MassDensity<>::Create<Unit::MassDensity::KilogramPerCubicMetre>(1.0);
  EXPECT_EQ(mass_density, MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, DefaultConstructor) {
  EXPECT_NO_THROW(MassDensity<>{});
}

TEST(MassDensity, Dimensions) {
  EXPECT_EQ(MassDensity<>::Dimensions(), RelatedDimensions<Unit::MassDensity>);
}

TEST(MassDensity, Hash) {
  const MassDensity first{1.0, Unit::MassDensity::GramPerCubicMillimetre};
  const MassDensity second{1.00001, Unit::MassDensity::GramPerCubicMillimetre};
  const MassDensity third{-1.0, Unit::MassDensity::GramPerCubicMillimetre};
  const std::hash<MassDensity<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(MassDensity, JSON) {
  EXPECT_EQ(MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kg/m^3\"}");
  EXPECT_EQ(MassDensity(1.0, Unit::MassDensity::GramPerCubicMillimetre)
                .JSON(Unit::MassDensity::GramPerCubicMillimetre),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"g/mm^3\"}");
}

TEST(MassDensity, MiscellaneousConstructor) {
  EXPECT_EQ(MassDensity(Mass(8.0, Unit::Mass::Kilogram), Volume(4.0, Unit::Volume::CubicMetre)),
            MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre));
  EXPECT_EQ(Mass(MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                 Volume(2.0, Unit::Volume::CubicMetre)),
            Mass(8.0, Unit::Mass::Kilogram));
  EXPECT_EQ(Volume(Mass(8.0, Unit::Mass::Kilogram),
                   MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)),
            Volume(2.0, Unit::Volume::CubicMetre));
}

TEST(MassDensity, MoveAssignmentOperator) {
  MassDensity first{1.0, Unit::MassDensity::KilogramPerCubicMetre};
  MassDensity second = MassDensity<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, MoveConstructor) {
  MassDensity first{1.0, Unit::MassDensity::KilogramPerCubicMetre};
  const MassDensity second{std::move(first)};
  EXPECT_EQ(second, MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, MutableValue) {
  MassDensity mass_density{1.0, Unit::MassDensity::KilogramPerCubicMetre};
  double& value = mass_density.MutableValue();
  value = 2.0;
  EXPECT_EQ(mass_density.Value(), 2.0);
}

TEST(MassDensity, Print) {
  EXPECT_EQ(
      MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre).Print(), Print(1.0) + " kg/m^3");
  EXPECT_EQ(MassDensity(1.0, Unit::MassDensity::GramPerCubicMillimetre)
                .Print(Unit::MassDensity::GramPerCubicMillimetre),
            Print(1.0) + " g/mm^3");
}

TEST(MassDensity, SetValue) {
  MassDensity mass_density{1.0, Unit::MassDensity::KilogramPerCubicMetre};
  mass_density.SetValue(2.0);
  EXPECT_EQ(mass_density.Value(), 2.0);
}

TEST(MassDensity, SizeOf) {
  EXPECT_EQ(sizeof(MassDensity<>{}), sizeof(double));
}

TEST(MassDensity, StandardConstructor) {
  EXPECT_NO_THROW(MassDensity(1.0, Unit::MassDensity::GramPerCubicMillimetre));
}

TEST(MassDensity, StaticValue) {
  constexpr MassDensity mass_density =
      MassDensity<>::Create<Unit::MassDensity::GramPerCubicMillimetre>(2.0);
  constexpr double value = mass_density.StaticValue<Unit::MassDensity::GramPerCubicMillimetre>();
  EXPECT_EQ(value, 2.0);
}

TEST(MassDensity, Stream) {
  std::ostringstream stream;
  stream << MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre);
  EXPECT_EQ(stream.str(), MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre).Print());
}

TEST(MassDensity, Unit) {
  EXPECT_EQ(MassDensity<>::Unit(), Standard<Unit::MassDensity>);
}

TEST(MassDensity, Value) {
  EXPECT_EQ(MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre).Value(), 1.0);
  EXPECT_EQ(MassDensity(2.0, Unit::MassDensity::GramPerCubicMillimetre)
                .Value(Unit::MassDensity::GramPerCubicMillimetre),
            2.0);
}

TEST(MassDensity, XML) {
  EXPECT_EQ(MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre).XML(),
            "<value>" + Print(1.0) + "</value><unit>kg/m^3</unit>");
  EXPECT_EQ(MassDensity(1.0, Unit::MassDensity::GramPerCubicMillimetre)
                .XML(Unit::MassDensity::GramPerCubicMillimetre),
            "<value>" + Print(1.0) + "</value><unit>g/mm^3</unit>");
}

TEST(MassDensity, YAML) {
  EXPECT_EQ(MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre).YAML(),
            "{value:" + Print(1.0) + ",unit:\"kg/m^3\"}");
  EXPECT_EQ(MassDensity(1.0, Unit::MassDensity::GramPerCubicMillimetre)
                .YAML(Unit::MassDensity::GramPerCubicMillimetre),
            "{value:" + Print(1.0) + ",unit:\"g/mm^3\"}");
}

TEST(MassDensity, Zero) {
  EXPECT_EQ(MassDensity<>::Zero(), MassDensity(0.0, Unit::MassDensity::KilogramPerCubicMetre));
}

}  // namespace

}  // namespace PhQ
