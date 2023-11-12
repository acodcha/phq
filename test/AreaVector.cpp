// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#include "../include/PhQ/AreaVector.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Area.hpp"
#include "../include/PhQ/Direction.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Area.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(AreaVector, Angle) {
  EXPECT_EQ(AreaVector({0.0, -2.22, 0.0}, Unit::Area::SquareMetre)
                .Angle(AreaVector({0.0, 0.0, 3.33}, Unit::Area::SquareMetre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(AreaVector, ArithmeticOperatorAddition) {
  EXPECT_EQ(AreaVector({1.0, -2.0, 3.0}, Unit::Area::SquareMetre)
                + AreaVector({2.0, -4.0, 6.0}, Unit::Area::SquareMetre),
            AreaVector({3.0, -6.0, 9.0}, Unit::Area::SquareMetre));
}

TEST(AreaVector, ArithmeticOperatorDivision) {
  EXPECT_EQ(AreaVector({2.0, -4.0, 6.0}, Unit::Area::SquareMetre) / 2.0,
            AreaVector({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
}

TEST(AreaVector, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(AreaVector({1.0, -2.0, 3.0}, Unit::Area::SquareMetre) * 2.0,
            AreaVector({2.0, -4.0, 6.0}, Unit::Area::SquareMetre));

  EXPECT_EQ(2.0 * AreaVector({1.0, -2.0, 3.0}, Unit::Area::SquareMetre),
            AreaVector({2.0, -4.0, 6.0}, Unit::Area::SquareMetre));

  EXPECT_EQ(Direction(2.0, -3.0, 6.0) * Area(7.0, Unit::Area::SquareMetre),
            AreaVector({2.0, -3.0, 6.0}, Unit::Area::SquareMetre));

  EXPECT_EQ(Area(7.0, Unit::Area::SquareMetre) * Direction(2.0, -3.0, 6.0),
            AreaVector({2.0, -3.0, 6.0}, Unit::Area::SquareMetre));
}

TEST(AreaVector, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(AreaVector({3.0, -6.0, 9.0}, Unit::Area::SquareMetre)
                - AreaVector({2.0, -4.0, 6.0}, Unit::Area::SquareMetre),
            AreaVector({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
}

TEST(AreaVector, AssignmentOperatorAddition) {
  AreaVector quantity({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  quantity += AreaVector({2.0, -4.0, 6.0}, Unit::Area::SquareMetre);
  EXPECT_EQ(quantity, AreaVector({3.0, -6.0, 9.0}, Unit::Area::SquareMetre));
}

TEST(AreaVector, AssignmentOperatorDivision) {
  AreaVector quantity({2.0, -4.0, 6.0}, Unit::Area::SquareMetre);
  quantity /= 2.0;
  EXPECT_EQ(quantity, AreaVector({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
}

TEST(AreaVector, AssignmentOperatorMultiplication) {
  AreaVector quantity({1.0, -2.0, 3.0}, Unit::Area::SquareMetre);
  quantity *= 2.0;
  EXPECT_EQ(quantity, AreaVector({2.0, -4.0, 6.0}, Unit::Area::SquareMetre));
}

TEST(AreaVector, AssignmentOperatorSubtraction) {
  AreaVector quantity({3.0, -6.0, 9.0}, Unit::Area::SquareMetre);
  quantity -= AreaVector({2.0, -4.0, 6.0}, Unit::Area::SquareMetre);
  EXPECT_EQ(quantity, AreaVector({1.0, -2.0, 3.0}, Unit::Area::SquareMetre));
}

TEST(AreaVector, ComparisonOperators) {
  const AreaVector first({1.0, 2.0, 4.0}, Unit::Area::SquareMetre);
  const AreaVector second({1.0, 2.0, 8.0}, Unit::Area::SquareMetre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(AreaVector, CopyAssignmentOperator) {
  const AreaVector first({1.11, -2.22, 3.33}, Unit::Area::SquareMetre);
  AreaVector second = AreaVector::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(AreaVector, CopyConstructor) {
  const AreaVector first({1.11, -2.22, 3.33}, Unit::Area::SquareMetre);
  const AreaVector second{first};
  EXPECT_EQ(second, first);
}

TEST(AreaVector, Create) {
  constexpr AreaVector first = AreaVector::Create<Unit::Area::SquareMetre>(1.11, -2.22, 3.33);
  EXPECT_EQ(first, AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre));

  constexpr AreaVector second =
      AreaVector::Create<Unit::Area::SquareMetre>(std::array<double, 3>{1.11, -2.22, 3.33});
  EXPECT_EQ(second, AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre));

  constexpr AreaVector third =
      AreaVector::Create<Unit::Area::SquareMetre>(Vector{1.11, -2.22, 3.33});
  EXPECT_EQ(third, AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre));
}

TEST(AreaVector, DefaultConstructor) {
  EXPECT_NO_THROW(AreaVector{});
}

TEST(AreaVector, Dimensions) {
  EXPECT_EQ(AreaVector::Dimensions(), RelatedDimensions<Unit::Area>);
}

TEST(AreaVector, Direction) {
  EXPECT_EQ(
      AreaVector({2.0, -3.0, 6.0}, Unit::Area::SquareMetre).Direction(), Direction(2.0, -3.0, 6.0));
}

TEST(AreaVector, Hash) {
  const AreaVector first({1.11, -2.22, 3.33}, Unit::Area::SquareMillimetre);
  const AreaVector second({1.11, -2.22, 3.330001}, Unit::Area::SquareMillimetre);
  const AreaVector third({1.11, 2.22, 3.33}, Unit::Area::SquareMillimetre);
  const std::hash<AreaVector> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(AreaVector, JSON) {
  EXPECT_EQ(AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre).JSON(),
            "{\"value\":{\"x\":1.110000000000000,\"y\":-2.220000000000000,"
            "\"z\":3.330000000000000},\"unit\":\"m^2\"}");
  EXPECT_EQ(AreaVector({0.0, -2.22, 0.0}, Unit::Area::SquareMillimetre)
                .JSON(Unit::Area::SquareMillimetre),
            "{\"value\":{\"x\":0,\"y\":-2.220000000000000,\"z\":0},\"unit\":"
            "\"mm^2\"}");
}

TEST(AreaVector, Magnitude) {
  EXPECT_EQ(AreaVector({2.0, -3.0, 6.0}, Unit::Area::SquareMetre).Magnitude(),
            Area(7.0, Unit::Area::SquareMetre));
}

TEST(AreaVector, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre)),
            Direction(1.11, -2.22, 3.33));

  EXPECT_EQ(Angle(AreaVector({0.0, -2.22, 0.0}, Unit::Area::SquareMetre),
                  AreaVector({0.0, 0.0, 3.33}, Unit::Area::SquareMetre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(AreaVector, MoveAssignmentOperator) {
  AreaVector first({1.11, -2.22, 3.33}, Unit::Area::SquareMetre);
  AreaVector second = AreaVector::Zero();
  second = std::move(first);
  EXPECT_EQ(second, AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre));
}

TEST(AreaVector, MoveConstructor) {
  AreaVector first({1.11, -2.22, 3.33}, Unit::Area::SquareMetre);
  const AreaVector second{std::move(first)};
  EXPECT_EQ(second, AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre));
}

TEST(AreaVector, MutableValue) {
  AreaVector quantity({1.11, -2.22, 3.33}, Unit::Area::SquareMetre);
  Vector& value = quantity.MutableValue();
  value = Vector{-4.44, 5.55, -6.66};
  EXPECT_EQ(quantity.Value(), Vector(-4.44, 5.55, -6.66));
}

TEST(AreaVector, Print) {
  EXPECT_EQ(AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre).Print(),
            "(1.110000000000000, -2.220000000000000, 3.330000000000000) m^2");
  EXPECT_EQ(AreaVector({0.0, -2.22, 0.0}, Unit::Area::SquareMillimetre)
                .Print(Unit::Area::SquareMillimetre),
            "(0, -2.220000000000000, 0) mm^2");
}

TEST(AreaVector, SetValue) {
  AreaVector quantity({1.11, -2.22, 3.33}, Unit::Area::SquareMetre);
  quantity.SetValue({-4.44, 5.55, -6.66});
  EXPECT_EQ(quantity.Value(), Vector(-4.44, 5.55, -6.66));
}

TEST(AreaVector, SizeOf) {
  EXPECT_EQ(sizeof(AreaVector{}), 3 * sizeof(double));
}

TEST(AreaVector, StandardConstructor) {
  EXPECT_NO_THROW(AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMillimetre));
}

TEST(AreaVector, StaticValue) {
  constexpr AreaVector quantity = AreaVector::Create<Unit::Area::SquareMillimetre>(1.0, -2.0, 3.0);
  constexpr Vector value = quantity.StaticValue<Unit::Area::SquareMillimetre>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(AreaVector, Stream) {
  std::ostringstream stream;
  stream << AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre);
  EXPECT_EQ(stream.str(), AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre).Print());
}

TEST(AreaVector, Unit) {
  EXPECT_EQ(AreaVector::Unit(), Standard<Unit::Area>);
}

TEST(AreaVector, Value) {
  EXPECT_EQ(
      AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre).Value(), Vector(1.11, -2.22, 3.33));
  EXPECT_EQ(AreaVector({1.0, -2.0, 3.0}, Unit::Area::SquareMillimetre)
                .Value(Unit::Area::SquareMillimetre),
            Vector(1.0, -2.0, 3.0));
}

TEST(AreaVector, XML) {
  EXPECT_EQ(AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre).XML(),
            "<value><x>1.110000000000000</x><y>-2.220000000000000</"
            "y><z>3.330000000000000</z></value><unit>m^2</unit>");
  EXPECT_EQ(
      AreaVector({0.0, -2.22, 0.0}, Unit::Area::SquareMillimetre).XML(Unit::Area::SquareMillimetre),
      "<value><x>0</x><y>-2.220000000000000</y><z>0</z></"
      "value><unit>mm^2</unit>");
}

TEST(AreaVector, XYZ) {
  EXPECT_EQ(AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre).x(),
            Area(1.11, Unit::Area::SquareMetre));
  EXPECT_EQ(AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre).y(),
            Area(-2.22, Unit::Area::SquareMetre));
  EXPECT_EQ(AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre).z(),
            Area(3.33, Unit::Area::SquareMetre));
}

TEST(AreaVector, YAML) {
  EXPECT_EQ(AreaVector({1.11, -2.22, 3.33}, Unit::Area::SquareMetre).YAML(),
            "{value:{x:1.110000000000000,y:-2.220000000000000,z:3."
            "330000000000000},unit:\"m^2\"}");
  EXPECT_EQ(AreaVector({0.0, -2.22, 0.0}, Unit::Area::SquareMillimetre)
                .YAML(Unit::Area::SquareMillimetre),
            "{value:{x:0,y:-2.220000000000000,z:0},unit:\"mm^2\"}");
}

TEST(AreaVector, Zero) {
  EXPECT_EQ(AreaVector::Zero(), AreaVector({0.0, 0.0, 0.0}, Unit::Area::SquareMetre));
}

}  // namespace

}  // namespace PhQ
