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

#include "../include/PhQ/Dimensions.hpp"
#include "../include/PhQ/DisplacementGradient.hpp"
#include "../include/PhQ/Dyad.hpp"

namespace PhQ {

namespace {

// Since PhQ::DimensionlessDyad is an abstract base class, tests use PhQ::DisplacementGradient,
// which is one of its derived classes.

TEST(DimensionlessDyad, Dimensions) {
  EXPECT_EQ(DisplacementGradient::Dimensions(), Dimensionless);
}

TEST(DimensionlessDyad, Hash) {
  constexpr DisplacementGradient first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  constexpr DisplacementGradient second(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.00001);
  constexpr DisplacementGradient third(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, 8.0, 9.0);
  const std::hash<DisplacementGradient> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionlessDyad, JSON) {
  EXPECT_EQ(
      DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).JSON(),
      "{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
          + ",\"yx\":" + Print(-4.0) + ",\"yy\":" + Print(5.0) + ",\"yz\":" + Print(-6.0)
          + ",\"zx\":" + Print(7.0) + ",\"zy\":" + Print(-8.0) + ",\"zz\":" + Print(9.0) + "}");
}

TEST(DimensionlessDyad, MutableValue) {
  DisplacementGradient displacement_gradient{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
  Dyad<>& value = displacement_gradient.MutableValue();
  value = Dyad{-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18};
  EXPECT_EQ(displacement_gradient.Value(),
            Dyad(-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
}

TEST(DimensionlessDyad, Print) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + ", " + Print(-6.0) + "; " + Print(7.0) + ", " + Print(-8.0) + ", "
                + Print(9.0) + ")");
}

TEST(DimensionlessDyad, SetValue) {
  DisplacementGradient displacement_gradient{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
  displacement_gradient.SetValue(
      Dyad{-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18});
  EXPECT_EQ(displacement_gradient.Value(),
            Dyad(-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
}

TEST(DimensionlessDyad, SizeOf) {
  EXPECT_EQ(sizeof(DisplacementGradient{}), 9 * sizeof(double));
}

TEST(DimensionlessDyad, Stream) {
  std::ostringstream stream;
  stream << DisplacementGradient{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
  EXPECT_EQ(
      stream.str(), DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).Print());
}

TEST(DimensionlessDyad, Value) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).Value(),
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DimensionlessDyad, XML) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).XML(),
            "<xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0) + "</xz><yx>"
                + Print(-4.0) + "</yx><yy>" + Print(5.0) + "</yy><yz>" + Print(-6.0) + "</yz><zx>"
                + Print(7.0) + "</zx><zy>" + Print(-8.0) + "</zy><zz>" + Print(9.0) + "</zz>");
}

TEST(DimensionlessDyad, YAML) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).YAML(),
            "{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yx:" + Print(-4.0)
                + ",yy:" + Print(5.0) + ",yz:" + Print(-6.0) + ",zx:" + Print(7.0)
                + ",zy:" + Print(-8.0) + ",zz:" + Print(9.0) + "}");
}

}  // namespace

}  // namespace PhQ
