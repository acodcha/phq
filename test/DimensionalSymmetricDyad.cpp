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

#include <functional>
#include <gtest/gtest.h>
#include <sstream>

#include "../include/PhQ/Stress.hpp"
#include "../include/PhQ/SymmetricDyad.hpp"
#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

// Since PhQ::DimensionalSymmetricDyad is an abstract base class, tests use PhQ::Stress, which is
// one of its derived classes.

TEST(DimensionalSymmetricDyad, Dimensions) {
  EXPECT_EQ(Stress::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(DimensionalSymmetricDyad, Hash) {
  const Stress first({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal);
  const Stress second({1.0, -2.0, 3.0, -4.0, 5.0, -6.000001}, Unit::Pressure::Kilopascal);
  const Stress third({1.0, -2.0, 3.0, 4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal);
  const std::hash<Stress> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionalSymmetricDyad, JSON) {
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

TEST(DimensionalSymmetricDyad, MutableValue) {
  Stress stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  SymmetricDyad<>& value = stress.MutableValue();
  value = SymmetricDyad{-7.0, 8.0, -9.0, 10.0, -11.0, 12.0};
  EXPECT_EQ(stress.Value(), SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
}

TEST(DimensionalSymmetricDyad, Print) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + "; " + Print(-6.0) + ") Pa");
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal)
                .Print(Unit::Pressure::Kilopascal),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + "; " + Print(-6.0) + ") kPa");
}

TEST(DimensionalSymmetricDyad, SetValue) {
  Stress stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  stress.SetValue(SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  EXPECT_EQ(stress.Value(), SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
}

TEST(DimensionalSymmetricDyad, SizeOf) {
  EXPECT_EQ(sizeof(Stress{}), 6 * sizeof(double));
}

TEST(DimensionalSymmetricDyad, StaticValue) {
  constexpr Stress stress =
      Stress::Create<Unit::Pressure::Kilopascal>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  constexpr SymmetricDyad value = stress.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(DimensionalSymmetricDyad, Stream) {
  std::ostringstream stream;
  stream << Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal);
  EXPECT_EQ(
      stream.str(), Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).Print());
}

TEST(DimensionalSymmetricDyad, Value) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).Value(),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal)
                .Value(Unit::Pressure::Kilopascal),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(DimensionalSymmetricDyad, XML) {
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

TEST(DimensionalSymmetricDyad, YAML) {
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Pascal).YAML(),
            "{value:{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yy:"
                + Print(-4.0) + ",yz:" + Print(5.0) + ",zz:" + Print(-6.0) + "},unit:\"Pa\"}");
  EXPECT_EQ(Stress({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Pressure::Kilopascal)
                .YAML(Unit::Pressure::Kilopascal),
            "{value:{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yy:"
                + Print(-4.0) + ",yz:" + Print(5.0) + ",zz:" + Print(-6.0) + "},unit:\"kPa\"}");
}

}  // namespace

}  // namespace PhQ
