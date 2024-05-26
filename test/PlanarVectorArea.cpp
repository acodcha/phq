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

#include "../include/PhQ/PlanarVectorArea.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Area.hpp"
#include "../include/PhQ/PlanarDirection.hpp"
#include "../include/PhQ/PlanarVector.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Area.hpp"

namespace PhQ {

namespace {

TEST(PlanarVectorArea, Angle) {
  EXPECT_EQ(PlanarVectorArea(
                {
                    0.0,
                    -2.0,
                },
                Unit::Area::SquareMetre)
                .Angle(PlanarVectorArea({3.0, 0.0}, Unit::Area::SquareMetre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarVectorArea, ArithmeticOperatorAddition) {
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre)
                + PlanarVectorArea({2.0, -4.0}, Unit::Area::SquareMetre),
            PlanarVectorArea({3.0, -6.0}, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, ArithmeticOperatorDivision) {
  EXPECT_EQ(PlanarVectorArea({2.0, -4.0}, Unit::Area::SquareMetre) / 2.0,
            PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre) * 2.0,
            PlanarVectorArea({2.0, -4.0}, Unit::Area::SquareMetre));
  EXPECT_EQ(2.0 * PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre),
            PlanarVectorArea({2.0, -4.0}, Unit::Area::SquareMetre));
  EXPECT_EQ(PlanarDirection(3.0, -4.0) * Area(5.0, Unit::Area::SquareMetre),
            PlanarVectorArea({3.0, -4.0}, Unit::Area::SquareMetre));
  EXPECT_EQ(Area(5.0, Unit::Area::SquareMetre) * PlanarDirection(3.0, -4.0),
            PlanarVectorArea({3.0, -4.0}, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PlanarVectorArea({3.0, -6.0}, Unit::Area::SquareMetre)
                - PlanarVectorArea({2.0, -4.0}, Unit::Area::SquareMetre),
            PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, AssignmentOperatorAddition) {
  PlanarVectorArea vector_area({1.0, -2.0}, Unit::Area::SquareMetre);
  vector_area += PlanarVectorArea({2.0, -4.0}, Unit::Area::SquareMetre);
  EXPECT_EQ(vector_area, PlanarVectorArea({3.0, -6.0}, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, AssignmentOperatorDivision) {
  PlanarVectorArea vector_area({2.0, -4.0}, Unit::Area::SquareMetre);
  vector_area /= 2.0;
  EXPECT_EQ(vector_area, PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, AssignmentOperatorMultiplication) {
  PlanarVectorArea vector_area({1.0, -2.0}, Unit::Area::SquareMetre);
  vector_area *= 2.0;
  EXPECT_EQ(vector_area, PlanarVectorArea({2.0, -4.0}, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, AssignmentOperatorSubtraction) {
  PlanarVectorArea vector_area({3.0, -6.0}, Unit::Area::SquareMetre);
  vector_area -= PlanarVectorArea({2.0, -4.0}, Unit::Area::SquareMetre);
  EXPECT_EQ(vector_area, PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, ComparisonOperators) {
  const PlanarVectorArea first({1.0, -2.000001}, Unit::Area::SquareMetre);
  const PlanarVectorArea second({1.0, -2.0}, Unit::Area::SquareMetre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PlanarVectorArea, CopyAssignmentOperator) {
  {
    const PlanarVectorArea<float> first({1.0F, -2.0F}, Unit::Area::SquareMetre);
    PlanarVectorArea<double> second = PlanarVectorArea<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarVectorArea<double>({1.0, -2.0}, Unit::Area::SquareMetre));
  }
  {
    const PlanarVectorArea<double> first({1.0, -2.0}, Unit::Area::SquareMetre);
    PlanarVectorArea<double> second = PlanarVectorArea<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarVectorArea<double>({1.0, -2.0}, Unit::Area::SquareMetre));
  }
  {
    const PlanarVectorArea<long double> first({1.0L, -2.0L}, Unit::Area::SquareMetre);
    PlanarVectorArea<double> second = PlanarVectorArea<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarVectorArea<double>({1.0, -2.0}, Unit::Area::SquareMetre));
  }
}

TEST(PlanarVectorArea, CopyConstructor) {
  {
    const PlanarVectorArea<float> first({1.0F, -2.0F}, Unit::Area::SquareMetre);
    const PlanarVectorArea<double> second{first};
    EXPECT_EQ(second, PlanarVectorArea<double>({1.0, -2.0}, Unit::Area::SquareMetre));
  }
  {
    const PlanarVectorArea<double> first({1.0, -2.0}, Unit::Area::SquareMetre);
    const PlanarVectorArea<double> second{first};
    EXPECT_EQ(second, PlanarVectorArea<double>({1.0, -2.0}, Unit::Area::SquareMetre));
  }
  {
    const PlanarVectorArea<long double> first({1.0L, -2.0L}, Unit::Area::SquareMetre);
    const PlanarVectorArea<double> second{first};
    EXPECT_EQ(second, PlanarVectorArea<double>({1.0, -2.0}, Unit::Area::SquareMetre));
  }
}

TEST(PlanarVectorArea, Create) {
  {
    constexpr PlanarVectorArea vector_area =
        PlanarVectorArea<>::Create<Unit::Area::SquareMetre>(1.0, -2.0);
    EXPECT_EQ(vector_area, PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre));
  }
  {
    constexpr PlanarVectorArea vector_area =
        PlanarVectorArea<>::Create<Unit::Area::SquareMetre>(std::array<double, 2>{1.0, -2.0});
    EXPECT_EQ(vector_area, PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre));
  }
  {
    constexpr PlanarVectorArea vector_area =
        PlanarVectorArea<>::Create<Unit::Area::SquareMetre>(PlanarVector{1.0, -2.0});
    EXPECT_EQ(vector_area, PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre));
  }
}

TEST(PlanarVectorArea, DefaultConstructor) {
  EXPECT_NO_THROW(PlanarVectorArea<>{});
}

TEST(PlanarVectorArea, Dimensions) {
  EXPECT_EQ(PlanarVectorArea<>::Dimensions(), RelatedDimensions<Unit::Area>);
}

TEST(PlanarVectorArea, Hash) {
  const PlanarVectorArea first({1.0, -2.000001}, Unit::Area::SquareMillimetre);
  const PlanarVectorArea second({1.0, -2.0}, Unit::Area::SquareMillimetre);
  const PlanarVectorArea third({1.0, 2.0}, Unit::Area::SquareMillimetre);
  const std::hash<PlanarVectorArea<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PlanarVectorArea, JSON) {
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"m^2\"}");
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMillimetre)
                .JSON(Unit::Area::SquareMillimetre),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"mm^2\"}");
}

TEST(PlanarVectorArea, Magnitude) {
  EXPECT_EQ(PlanarVectorArea({3.0, -4.0}, Unit::Area::SquareMetre).Magnitude(),
            Area(5.0, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, MiscellaneousConstructors) {
  EXPECT_EQ(PlanarDirection(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre)),
            PlanarDirection(1.0, -2.0));
  EXPECT_EQ(Angle(PlanarVectorArea({0.0, -2.0}, Unit::Area::SquareMetre),
                  PlanarVectorArea({3.0, 0.0}, Unit::Area::SquareMetre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarVectorArea, MoveAssignmentOperator) {
  PlanarVectorArea first({1.0, -2.0}, Unit::Area::SquareMetre);
  PlanarVectorArea second = PlanarVectorArea<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, MoveConstructor) {
  PlanarVectorArea first({1.0, -2.0}, Unit::Area::SquareMetre);
  const PlanarVectorArea second{std::move(first)};
  EXPECT_EQ(second, PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, MutableValue) {
  PlanarVectorArea vector_area({1.0, -2.0}, Unit::Area::SquareMetre);
  PlanarVector<>& value = vector_area.MutableValue();
  value = PlanarVector{-4.0, 5.0};
  EXPECT_EQ(vector_area.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarVectorArea, PlanarDirection) {
  EXPECT_EQ(PlanarVectorArea({3.0, -4.0}, Unit::Area::SquareMetre).PlanarDirection(),
            PlanarDirection(3.0, -4.0));
}

TEST(PlanarVectorArea, Print) {
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") m^2");
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMillimetre)
                .Print(Unit::Area::SquareMillimetre),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") mm^2");
}

TEST(PlanarVectorArea, SetValue) {
  PlanarVectorArea vector_area({1.0, -2.0}, Unit::Area::SquareMetre);
  vector_area.SetValue({-4.0, 5.0});
  EXPECT_EQ(vector_area.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarVectorArea, SizeOf) {
  EXPECT_EQ(sizeof(PlanarVectorArea<>{}), 2 * sizeof(double));
}

TEST(PlanarVectorArea, StandardConstructor) {
  EXPECT_NO_THROW(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMillimetre));
}

TEST(PlanarVectorArea, StaticValue) {
  constexpr PlanarVectorArea vector_area =
      PlanarVectorArea<>::Create<Unit::Area::SquareMillimetre>(1.0, -2.0);
  constexpr PlanarVector value = vector_area.StaticValue<Unit::Area::SquareMillimetre>();
  EXPECT_EQ(value, PlanarVector(1.0, -2.0));
}

TEST(PlanarVectorArea, Stream) {
  std::ostringstream stream;
  stream << PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre);
  EXPECT_EQ(stream.str(), PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre).Print());
}

TEST(PlanarVectorArea, Unit) {
  EXPECT_EQ(PlanarVectorArea<>::Unit(), Standard<Unit::Area>);
}

TEST(PlanarVectorArea, Value) {
  EXPECT_EQ(
      PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre).Value(), PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMillimetre)
                .Value(Unit::Area::SquareMillimetre),
            PlanarVector(1.0, -2.0));
}

TEST(PlanarVectorArea, XML) {
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>m^2</unit>");
  EXPECT_EQ(
      PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMillimetre).XML(Unit::Area::SquareMillimetre),
      "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>mm^2</unit>");
}

TEST(PlanarVectorArea, XY) {
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre).x(),
            Area(1.0, Unit::Area::SquareMetre));
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre).y(),
            Area(-2.0, Unit::Area::SquareMetre));
}

TEST(PlanarVectorArea, YAML) {
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMetre).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"m^2\"}");
  EXPECT_EQ(PlanarVectorArea({1.0, -2.0}, Unit::Area::SquareMillimetre)
                .YAML(Unit::Area::SquareMillimetre),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"mm^2\"}");
}

TEST(PlanarVectorArea, Zero) {
  EXPECT_EQ(PlanarVectorArea<>::Zero(), PlanarVectorArea({0.0, 0.0}, Unit::Area::SquareMetre));
}

}  // namespace

}  // namespace PhQ
