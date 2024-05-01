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

#include "../include/PhQ/StrainRate.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/ScalarStrainRate.hpp"
#include "../include/PhQ/Strain.hpp"
#include "../include/PhQ/SymmetricDyad.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(StrainRate, ArithmeticOperatorAddition) {
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz)
                + StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz),
            StrainRate({3.0, -6.0, 9.0, -12.0, 15.0, -18.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, ArithmeticOperatorDivision) {
  EXPECT_EQ(StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz) / 2.0,
            StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
  EXPECT_EQ(StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz)
                / Frequency(2.0, Unit::Frequency::Hertz),
            Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0) / Time(2.0, Unit::Time::Second),
            StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz) * 2.0,
            StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz));
  EXPECT_EQ(2.0 * StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz),
            StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz));
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz)
                * Time(2.0, Unit::Time::Second),
            Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  EXPECT_EQ(Time(2.0, Unit::Time::Second)
                * StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz),
            Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  EXPECT_EQ(Frequency(2.0, Unit::Frequency::Hertz) * Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0),
            StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz));
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * Frequency(2.0, Unit::Frequency::Hertz),
            StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(StrainRate({3.0, -6.0, 9.0, -12.0, 15.0, -18.0}, Unit::Frequency::Hertz)
                - StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz),
            StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, AssignmentOperatorAddition) {
  StrainRate strain_rate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz);
  strain_rate += StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz);
  EXPECT_EQ(strain_rate, StrainRate({3.0, -6.0, 9.0, -12.0, 15.0, -18.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, AssignmentOperatorDivision) {
  StrainRate strain_rate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz);
  strain_rate /= 2.0;
  EXPECT_EQ(strain_rate, StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, AssignmentOperatorMultiplication) {
  StrainRate strain_rate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz);
  strain_rate *= 2.0;
  EXPECT_EQ(strain_rate, StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, AssignmentOperatorSubtraction) {
  StrainRate strain_rate({3.0, -6.0, 9.0, -12.0, 15.0, -18.0}, Unit::Frequency::Hertz);
  strain_rate -= StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz);
  EXPECT_EQ(strain_rate, StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, ComparisonOperators) {
  const StrainRate first({1.0, -2.0, 3.0, -4.0, 5.0, -6.000001}, Unit::Frequency::Hertz);
  const StrainRate second({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(StrainRate, CopyAssignmentOperator) {
  const StrainRate first({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz);
  StrainRate second = StrainRate::Zero();
  second = first;
  EXPECT_EQ(second, StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, CopyConstructor) {
  const StrainRate first({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz);
  const StrainRate second{first};
  EXPECT_EQ(second, StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, Create) {
  {
    constexpr StrainRate strain_rate =
        StrainRate::Create<Unit::Frequency::Hertz>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    EXPECT_EQ(strain_rate, StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
  }
  {
    constexpr StrainRate strain_rate = StrainRate::Create<Unit::Frequency::Hertz>(
        std::array<double, 6>{1.0, -2.0, 3.0, -4.0, 5.0, -6.0});
    EXPECT_EQ(strain_rate, StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
  }
  {
    constexpr StrainRate strain_rate =
        StrainRate::Create<Unit::Frequency::Hertz>(SymmetricDyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0});
    EXPECT_EQ(strain_rate, StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
  }
}

TEST(StrainRate, DefaultConstructor) {
  EXPECT_NO_THROW(StrainRate{});
}

TEST(StrainRate, Dimensions) {
  EXPECT_EQ(StrainRate::Dimensions(), RelatedDimensions<Unit::Frequency>);
}

TEST(StrainRate, Hash) {
  const StrainRate first({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Kilohertz);
  const StrainRate second({1.0, -2.0, 3.0, -4.0, 5.0, -6.000001}, Unit::Frequency::Kilohertz);
  const StrainRate third({1.0, -2.0, 3.0, 4.0, 5.0, -6.0}, Unit::Frequency::Kilohertz);
  const std::hash<StrainRate> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(StrainRate, JSON) {
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).JSON(),
            "{\"value\":{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
                + ",\"yy\":" + Print(-4.0) + ",\"yz\":" + Print(5.0) + ",\"zz\":" + Print(-6.0)
                + "},\"unit\":\"Hz\"}");
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Kilohertz)
                .JSON(Unit::Frequency::Kilohertz),
            "{\"value\":{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
                + ",\"yy\":" + Print(-4.0) + ",\"yz\":" + Print(5.0) + ",\"zz\":" + Print(-6.0)
                + "},\"unit\":\"kHz\"}");
}

TEST(StrainRate, MiscellaneousConstructors) {
  EXPECT_EQ(StrainRate(Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0), Time(2.0, Unit::Time::Second)),
            StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));

  EXPECT_EQ(
      StrainRate(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0), Frequency(2.0, Unit::Frequency::Hertz)),
      StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz));

  EXPECT_EQ(Strain(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz),
                   Time(2.0, Unit::Time::Second)),
            Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));

  EXPECT_EQ(Strain(StrainRate({2.0, -4.0, 6.0, -8.0, 10.0, -12.0}, Unit::Frequency::Hertz),
                   Frequency(2.0, Unit::Frequency::Hertz)),
            Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(StrainRate, MoveAssignmentOperator) {
  StrainRate first({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz);
  StrainRate second = StrainRate::Zero();
  second = std::move(first);
  EXPECT_EQ(second, StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, MoveConstructor) {
  StrainRate first({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz);
  const StrainRate second{std::move(first)};
  EXPECT_EQ(second, StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, MutableValue) {
  StrainRate strain_rate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz);
  SymmetricDyad<double>& value = strain_rate.MutableValue();
  value = SymmetricDyad{-7.0, 8.0, -9.0, 10.0, -11.0, 12.0};
  EXPECT_EQ(strain_rate.Value(), SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
}

TEST(StrainRate, Print) {
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + "; " + Print(-6.0) + ") Hz");
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Kilohertz)
                .Print(Unit::Frequency::Kilohertz),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + "; " + Print(-6.0) + ") kHz");
}

TEST(StrainRate, SetValue) {
  StrainRate strain_rate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz);
  strain_rate.SetValue(SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  EXPECT_EQ(strain_rate.Value(), SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
}

TEST(StrainRate, SizeOf) {
  EXPECT_EQ(sizeof(StrainRate{}), 6 * sizeof(double));
}

TEST(StrainRate, StandardConstructor) {
  EXPECT_NO_THROW(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz));
}

TEST(StrainRate, StaticValue) {
  constexpr StrainRate strain_rate =
      StrainRate::Create<Unit::Frequency::Kilohertz>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  constexpr SymmetricDyad value = strain_rate.StaticValue<Unit::Frequency::Kilohertz>();
  EXPECT_EQ(value, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(StrainRate, Stream) {
  std::ostringstream stream;
  stream << StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz);
  EXPECT_EQ(
      stream.str(), StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).Print());
}

TEST(StrainRate, Value) {
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).Value(),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Kilohertz)
                .Value(Unit::Frequency::Kilohertz),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(StrainRate, XML) {
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).XML(),
            "<value><xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0)
                + "</xz><yy>" + Print(-4.0) + "</yy><yz>" + Print(5.0) + "</yz><zz>" + Print(-6.0)
                + "</zz></value><unit>Hz</unit>");
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Kilohertz)
                .XML(Unit::Frequency::Kilohertz),
            "<value><xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0)
                + "</xz><yy>" + Print(-4.0) + "</yy><yz>" + Print(5.0) + "</yz><zz>" + Print(-6.0)
                + "</zz></value><unit>kHz</unit>");
}

TEST(StrainRate, XYZ) {
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).xx(),
            ScalarStrainRate(1.0, Unit::Frequency::Hertz));
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).xy(),
            ScalarStrainRate(-2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).xz(),
            ScalarStrainRate(3.0, Unit::Frequency::Hertz));
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).yx(),
            ScalarStrainRate(-2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).yy(),
            ScalarStrainRate(-4.0, Unit::Frequency::Hertz));
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).yz(),
            ScalarStrainRate(5.0, Unit::Frequency::Hertz));
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).zx(),
            ScalarStrainRate(3.0, Unit::Frequency::Hertz));
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).zy(),
            ScalarStrainRate(5.0, Unit::Frequency::Hertz));
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).zz(),
            ScalarStrainRate(-6.0, Unit::Frequency::Hertz));
}

TEST(StrainRate, YAML) {
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Hertz).YAML(),
            "{value:{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yy:"
                + Print(-4.0) + ",yz:" + Print(5.0) + ",zz:" + Print(-6.0) + "},unit:\"Hz\"}");
  EXPECT_EQ(StrainRate({1.0, -2.0, 3.0, -4.0, 5.0, -6.0}, Unit::Frequency::Kilohertz)
                .YAML(Unit::Frequency::Kilohertz),
            "{value:{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yy:"
                + Print(-4.0) + ",yz:" + Print(5.0) + ",zz:" + Print(-6.0) + "},unit:\"kHz\"}");
}

TEST(StrainRate, Zero) {
  EXPECT_EQ(StrainRate::Zero(), StrainRate({0.0, 0.0, 0.0, 0.0, 0.0, 0.0}, Unit::Frequency::Hertz));
}

}  // namespace

}  // namespace PhQ
