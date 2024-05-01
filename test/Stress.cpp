// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#include "../include/PhQ/Stress.hpp"

#include <array>
#include <cmath>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/ScalarStress.hpp"
#include "../include/PhQ/StaticPressure.hpp"
#include "../include/PhQ/SymmetricDyad.hpp"
#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

TEST(Stress, ArithmeticOperatorAddition) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal)
                + Stress({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Pressure::Pascal),
            Stress({3.0, -6.0, 9.0, -12.0, 15.0, -18.0}, Unit::Pressure::Pascal));
}

TEST(Stress, ArithmeticOperatorDivision) {
  EXPECT_EQ(Stress({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Pressure::Pascal) / 2.0,
            Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(Stress, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal) * 2.0,
            Stress({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(2.0 * Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal),
            Stress({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Pressure::Pascal));
}

TEST(Stress, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Stress({3.0, -6.0, 9.0, -12.0, 15.0, -18.0}, Unit::Pressure::Pascal)
                - Stress({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Pressure::Pascal),
            Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(Stress, AssignmentOperatorAddition) {
  Stress stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  stress += Stress({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(stress, Stress({3.0, -6.0, 9.0, -12.0, 15.0, -18.0}, Unit::Pressure::Pascal));
}

TEST(Stress, AssignmentOperatorDivision) {
  Stress stress({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Pressure::Pascal);
  stress /= 2.0;
  EXPECT_EQ(stress, Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(Stress, AssignmentOperatorMultiplication) {
  Stress stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  stress *= 2.0;
  EXPECT_EQ(stress, Stress({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Pressure::Pascal));
}

TEST(Stress, AssignmentOperatorSubtraction) {
  Stress stress({3.0, -6.0, 9.0, -12.0, 15.0, -18.0}, Unit::Pressure::Pascal);
  stress -= Stress({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(stress, Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(Stress, ComparisonOperators) {
  const Stress first({1.0, -2.0, 3.0, -4.0, 5.0, -6.000001}, Unit::Pressure::Pascal);
  const Stress second({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Stress, CopyAssignmentOperator) {
  const Stress first({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  Stress second = Stress::Zero();
  second = first;
  EXPECT_EQ(second, Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(Stress, CopyConstructor) {
  const Stress first({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  const Stress second{first};
  EXPECT_EQ(second, Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(Stress, Create) {
  {
    constexpr Stress stress =
        Stress::Create<Unit::Pressure::Pascal>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    EXPECT_EQ(stress, Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
  }
  {
    constexpr Stress stress = Stress::Create<Unit::Pressure::Pascal>(
        std::array<double, 6>{1.0, -2.0, 3.0, -4.0, 5.0, -6.0});
    EXPECT_EQ(stress, Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
  }
  {
    constexpr Stress stress =
        Stress::Create<Unit::Pressure::Pascal>(SymmetricDyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0});
    EXPECT_EQ(stress, Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
  }
}

TEST(Stress, DefaultConstructor) {
  EXPECT_NO_THROW(Stress{});
}

TEST(Stress, Dimensions) {
  EXPECT_EQ(Stress::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(Stress, Hash) {
  const Stress first({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal);
  const Stress second({1.0, -2.0, 3.0, -4.0, 5.0, -6.000001}, Unit::Pressure::Kilopascal);
  const Stress third({1.0, -2.0, 3.0, 4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal);
  const std::hash<Stress> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Stress, JSON) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).JSON(),
            "{\"value\":{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
                + ",\"yy\":" + Print(-4.0) + ",\"yz\":" + Print(5.0) + ",\"zz\":" + Print(-6.0)
                + "},\"unit\":\"Pa\"}");
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal)
                .JSON(Unit::Pressure::Kilopascal),
            "{\"value\":{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
                + ",\"yy\":" + Print(-4.0) + ",\"yz\":" + Print(5.0) + ",\"zz\":" + Print(-6.0)
                + "},\"unit\":\"kPa\"}");
}

TEST(Stress, MiscellaneousConstructors) {
  EXPECT_EQ(Stress(StaticPressure(2.0, Unit::Pressure::Pascal)),
            Stress({-2.0, 0.0, 0.0, -2.0, 0.0, -2.0}, Unit::Pressure::Pascal));

  EXPECT_EQ(StaticPressure(2.0, Unit::Pressure::Pascal).Stress(),
            Stress({-2.0, 0.0, 0.0, -2.0, 0.0, -2.0}, Unit::Pressure::Pascal));

  EXPECT_EQ(Traction(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal),
                     Direction(0.0, -1.0, 0.0)),
            Traction({2.0, 4.0, -5.0}, Unit::Pressure::Pascal));
}

TEST(Stress, MiscellaneousMethods) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal)
                .Traction(Direction(0.0, -1.0, 0.0)),
            Traction({2.0, 4.0, -5.0}, Unit::Pressure::Pascal));
  EXPECT_EQ(
      Stress({8.0, 1.0, 2.0, 16.0, 4.0, 32.0}, Unit::Pressure::Pascal).VonMises(),
      ScalarStress(
          std::sqrt(0.5
                    * (std::pow(8.0 - 16.0, 2) + std::pow(16.0 - 32.0, 2) + std::pow(32.0 - 8.0, 2)
                       + 6.0 * (std::pow(1.0, 2) + std::pow(2.0, 2) + std::pow(4.0, 2)))),
          Unit::Pressure::Pascal));
}

TEST(Stress, MoveAssignmentOperator) {
  Stress first({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  Stress second = Stress::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(Stress, MoveConstructor) {
  Stress first({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  const Stress second{std::move(first)};
  EXPECT_EQ(second, Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(Stress, MutableValue) {
  Stress stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  SymmetricDyad<double>& value = stress.MutableValue();
  value = SymmetricDyad{-7.0, 8.0, -9.0, 10.0, -11.0, 12.0};
  EXPECT_EQ(stress.Value(), SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
}

TEST(Stress, Print) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + "; " + Print(-6.0) + ") Pa");
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal)
                .Print(Unit::Pressure::Kilopascal),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + "; " + Print(-6.0) + ") kPa");
}

TEST(Stress, SetValue) {
  Stress stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  stress.SetValue(SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  EXPECT_EQ(stress.Value(), SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
}

TEST(Stress, SizeOf) {
  EXPECT_EQ(sizeof(Stress{}), 6 * sizeof(double));
}

TEST(Stress, StandardConstructor) {
  EXPECT_NO_THROW(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal));
}

TEST(Stress, StaticValue) {
  constexpr Stress stress =
      Stress::Create<Unit::Pressure::Kilopascal>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  constexpr SymmetricDyad value = stress.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Stress, Stream) {
  std::ostringstream stream;
  stream << Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(
      stream.str(), Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).Print());
}

TEST(Stress, Value) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).Value(),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal)
                .Value(Unit::Pressure::Kilopascal),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Stress, XML) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).XML(),
            "<value><xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0)
                + "</xz><yy>" + Print(-4.0) + "</yy><yz>" + Print(5.0) + "</yz><zz>" + Print(-6.0)
                + "</zz></value><unit>Pa</unit>");
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal)
                .XML(Unit::Pressure::Kilopascal),
            "<value><xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0)
                + "</xz><yy>" + Print(-4.0) + "</yy><yz>" + Print(5.0) + "</yz><zz>" + Print(-6.0)
                + "</zz></value><unit>kPa</unit>");
}

TEST(Stress, XYZ) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).xx(),
            ScalarStress(1.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).xy(),
            ScalarStress(-2.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).xz(),
            ScalarStress(3.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).yx(),
            ScalarStress(-2.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).yy(),
            ScalarStress(-4.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).yz(),
            ScalarStress(5.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).zx(),
            ScalarStress(3.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).zy(),
            ScalarStress(5.0, Unit::Pressure::Pascal));
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).zz(),
            ScalarStress(-6.0, Unit::Pressure::Pascal));
}

TEST(Stress, YAML) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).YAML(),
            "{value:{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yy:"
                + Print(-4.0) + ",yz:" + Print(5.0) + ",zz:" + Print(-6.0) + "},unit:\"Pa\"}");
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal)
                .YAML(Unit::Pressure::Kilopascal),
            "{value:{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yy:"
                + Print(-4.0) + ",yz:" + Print(5.0) + ",zz:" + Print(-6.0) + "},unit:\"kPa\"}");
}

TEST(Stress, Zero) {
  EXPECT_EQ(Stress::Zero(), Stress({0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
