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

#include "../include/PhQ/Dyad.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/VelocityGradient.hpp"

namespace PhQ {

namespace {

// Since PhQ::DimensionalDyad is an abstract base class, tests use PhQ::VelocityGradient, which is
// one of its derived classes.

TEST(DimensionalDyad, Dimensions) {
  EXPECT_EQ(VelocityGradient::Dimensions(), RelatedDimensions<Unit::Frequency>);
}

TEST(DimensionalDyad, Hash) {
  const VelocityGradient first(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Kilohertz);
  const VelocityGradient second(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.000001}, Unit::Frequency::Kilohertz);
  const VelocityGradient third(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, 8.0, 9.0}, Unit::Frequency::Kilohertz);
  const std::hash<VelocityGradient> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionalDyad, JSON) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .JSON(),
      "{\"value\":{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
          + ",\"yx\":" + Print(-4.0) + ",\"yy\":" + Print(5.0) + ",\"yz\":" + Print(-6.0)
          + ",\"zx\":" + Print(7.0) + ",\"zy\":" + Print(-8.0) + ",\"zz\":" + Print(9.0)
          + "},\"unit\":\"Hz\"}");
  EXPECT_EQ(VelocityGradient(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Kilohertz)
                .JSON(Unit::Frequency::Kilohertz),
            "{\"value\":{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
                + ",\"yx\":" + Print(-4.0) + ",\"yy\":" + Print(5.0) + ",\"yz\":" + Print(-6.0)
                + ",\"zx\":" + Print(7.0) + ",\"zy\":" + Print(-8.0) + ",\"zz\":" + Print(9.0)
                + "},\"unit\":\"kHz\"}");
}

TEST(DimensionalDyad, MutableValue) {
  VelocityGradient velocity_gradient(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz);
  Dyad<>& value = velocity_gradient.MutableValue();
  value = Dyad{-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18};
  EXPECT_EQ(velocity_gradient.Value(),
            Dyad(-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
}

TEST(DimensionalDyad, Print) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .Print(),
      "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
          + Print(5.0) + ", " + Print(-6.0) + "; " + Print(7.0) + ", " + Print(-8.0) + ", "
          + Print(9.0) + ") Hz");
  EXPECT_EQ(VelocityGradient(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Kilohertz)
                .Print(Unit::Frequency::Kilohertz),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + ", " + Print(-6.0) + "; " + Print(7.0) + ", " + Print(-8.0) + ", "
                + Print(9.0) + ") kHz");
}

TEST(DimensionalDyad, SetValue) {
  VelocityGradient velocity_gradient(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz);
  velocity_gradient.SetValue(
      Dyad(-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
  EXPECT_EQ(velocity_gradient.Value(),
            Dyad(-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
}

TEST(DimensionalDyad, SizeOf) {
  EXPECT_EQ(sizeof(VelocityGradient{}), 9 * sizeof(double));
}

TEST(DimensionalDyad, StaticValue) {
  constexpr VelocityGradient velocity_gradient =
      VelocityGradient::Create<Unit::Frequency::Kilohertz>(
          1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  constexpr Dyad value = velocity_gradient.StaticValue<Unit::Frequency::Kilohertz>();
  EXPECT_EQ(value, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DimensionalDyad, Stream) {
  std::ostringstream stream;
  stream << VelocityGradient(
      {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz);
  EXPECT_EQ(
      stream.str(),
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .Print());
}

TEST(DimensionalDyad, Value) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .Value(),
      Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  EXPECT_EQ(VelocityGradient(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Kilohertz)
                .Value(Unit::Frequency::Kilohertz),
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DimensionalDyad, XML) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .XML(),
      "<value><xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0)
          + "</xz><yx>" + Print(-4.0) + "</yx><yy>" + Print(5.0) + "</yy><yz>" + Print(-6.0)
          + "</yz><zx>" + Print(7.0) + "</zx><zy>" + Print(-8.0) + "</zy><zz>" + Print(9.0)
          + "</zz></value><unit>Hz</unit>");
  EXPECT_EQ(VelocityGradient(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Kilohertz)
                .XML(Unit::Frequency::Kilohertz),
            "<value><xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0)
                + "</xz><yx>" + Print(-4.0) + "</yx><yy>" + Print(5.0) + "</yy><yz>" + Print(-6.0)
                + "</yz><zx>" + Print(7.0) + "</zx><zy>" + Print(-8.0) + "</zy><zz>" + Print(9.0)
                + "</zz></value><unit>kHz</unit>");
}

TEST(DimensionalDyad, YAML) {
  EXPECT_EQ(
      VelocityGradient({1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Hertz)
          .YAML(),
      "{value:{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yx:" + Print(-4.0)
          + ",yy:" + Print(5.0) + ",yz:" + Print(-6.0) + ",zx:" + Print(7.0) + ",zy:" + Print(-8.0)
          + ",zz:" + Print(9.0) + "},unit:\"Hz\"}");
  EXPECT_EQ(VelocityGradient(
                {1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}, Unit::Frequency::Kilohertz)
                .YAML(Unit::Frequency::Kilohertz),
            "{value:{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yx:"
                + Print(-4.0) + ",yy:" + Print(5.0) + ",yz:" + Print(-6.0) + ",zx:" + Print(7.0)
                + ",zy:" + Print(-8.0) + ",zz:" + Print(9.0) + "},unit:\"kHz\"}");
}

}  // namespace

}  // namespace PhQ
