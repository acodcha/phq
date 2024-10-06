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

#include "../include/PhQ/Dimensions.hpp"

#include <cstdint>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimension/ElectricCurrent.hpp"
#include "../include/PhQ/Dimension/Length.hpp"
#include "../include/PhQ/Dimension/LuminousIntensity.hpp"
#include "../include/PhQ/Dimension/Mass.hpp"
#include "../include/PhQ/Dimension/SubstanceAmount.hpp"
#include "../include/PhQ/Dimension/Temperature.hpp"
#include "../include/PhQ/Dimension/Time.hpp"

namespace PhQ {

namespace {

TEST(Dimensions, Accessors) {
  constexpr Dimensions dimensions{
    Dimension::Time(-3),
    Dimension::Length(-2),
    Dimension::Mass(-1),
    Dimension::ElectricCurrent(0),
    Dimension::Temperature(1),
    Dimension::SubstanceAmount(2),
    Dimension::LuminousIntensity(3)};
  EXPECT_EQ(dimensions.Time(), Dimension::Time(-3));
  EXPECT_EQ(dimensions.Length(), Dimension::Length(-2));
  EXPECT_EQ(dimensions.Mass(), Dimension::Mass(-1));
  EXPECT_EQ(dimensions.ElectricCurrent(), Dimension::ElectricCurrent(0));
  EXPECT_EQ(dimensions.Temperature(), Dimension::Temperature(1));
  EXPECT_EQ(dimensions.SubstanceAmount(), Dimension::SubstanceAmount(2));
  EXPECT_EQ(dimensions.LuminousIntensity(), Dimension::LuminousIntensity(3));
}

TEST(Dimensions, ComparisonOperators) {
  {
    constexpr Dimensions first{
      Dimension::Time(-3),
      Dimension::Length(0),
      Dimension::Mass(0),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(0),
      Dimension::SubstanceAmount(0),
      Dimension::LuminousIntensity(0)};
    constexpr Dimensions second{
      Dimension::Time(-2),
      Dimension::Length(0),
      Dimension::Mass(0),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(0),
      Dimension::SubstanceAmount(0),
      Dimension::LuminousIntensity(0)};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GT(second, first);
    EXPECT_GE(second, first);
    EXPECT_GE(first, first);
  }
  {
    constexpr Dimensions first{
      Dimension::Time(-3),
      Dimension::Length(-2),
      Dimension::Mass(0),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(0),
      Dimension::SubstanceAmount(0),
      Dimension::LuminousIntensity(0)};
    constexpr Dimensions second{
      Dimension::Time(-3),
      Dimension::Length(-1),
      Dimension::Mass(0),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(0),
      Dimension::SubstanceAmount(0),
      Dimension::LuminousIntensity(0)};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GT(second, first);
    EXPECT_GE(second, first);
    EXPECT_GE(first, first);
  }
  {
    constexpr Dimensions first{
      Dimension::Time(-3),
      Dimension::Length(-2),
      Dimension::Mass(-1),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(0),
      Dimension::SubstanceAmount(0),
      Dimension::LuminousIntensity(0)};
    constexpr Dimensions second{
      Dimension::Time(-3),
      Dimension::Length(-2),
      Dimension::Mass(0),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(0),
      Dimension::SubstanceAmount(0),
      Dimension::LuminousIntensity(0)};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GT(second, first);
    EXPECT_GE(second, first);
    EXPECT_GE(first, first);
  }
  {
    constexpr Dimensions first{
      Dimension::Time(-3),
      Dimension::Length(-2),
      Dimension::Mass(-1),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(0),
      Dimension::SubstanceAmount(0),
      Dimension::LuminousIntensity(0)};
    constexpr Dimensions second{
      Dimension::Time(-3),
      Dimension::Length(-2),
      Dimension::Mass(-1),
      Dimension::ElectricCurrent(1),
      Dimension::Temperature(0),
      Dimension::SubstanceAmount(0),
      Dimension::LuminousIntensity(0)};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GT(second, first);
    EXPECT_GE(second, first);
    EXPECT_GE(first, first);
  }
  {
    constexpr Dimensions first{
      Dimension::Time(-3),
      Dimension::Length(-2),
      Dimension::Mass(-1),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(1),
      Dimension::SubstanceAmount(0),
      Dimension::LuminousIntensity(0)};
    constexpr Dimensions second{
      Dimension::Time(-3),
      Dimension::Length(-2),
      Dimension::Mass(-1),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(2),
      Dimension::SubstanceAmount(0),
      Dimension::LuminousIntensity(0)};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GT(second, first);
    EXPECT_GE(second, first);
    EXPECT_GE(first, first);
  }
  {
    constexpr Dimensions first{
      Dimension::Time(-3),
      Dimension::Length(-2),
      Dimension::Mass(-1),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(1),
      Dimension::SubstanceAmount(2),
      Dimension::LuminousIntensity(0)};
    constexpr Dimensions second{
      Dimension::Time(-3),
      Dimension::Length(-2),
      Dimension::Mass(-1),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(1),
      Dimension::SubstanceAmount(3),
      Dimension::LuminousIntensity(0)};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GT(second, first);
    EXPECT_GE(second, first);
    EXPECT_GE(first, first);
  }
  {
    constexpr Dimensions first{
      Dimension::Time(-3),
      Dimension::Length(-2),
      Dimension::Mass(-1),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(1),
      Dimension::SubstanceAmount(2),
      Dimension::LuminousIntensity(3)};
    constexpr Dimensions second{
      Dimension::Time(-3),
      Dimension::Length(-2),
      Dimension::Mass(-1),
      Dimension::ElectricCurrent(0),
      Dimension::Temperature(1),
      Dimension::SubstanceAmount(2),
      Dimension::LuminousIntensity(4)};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GT(second, first);
    EXPECT_GE(second, first);
    EXPECT_GE(first, first);
  }
}

TEST(Dimensions, Constructor) {
  EXPECT_NO_THROW(Dimensions({}, {}, {}, {}, {}, {}, {}));
}

TEST(Dimensions, CopyAssignmentOperator) {
  constexpr Dimensions first{Dimension::Time(-2), Dimension::Length(1), {}, {}, {}, {}, {}};
  Dimensions second;
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Dimensions, CopyConstructor) {
  constexpr Dimensions first{Dimension::Time(-2), Dimension::Length(1), {}, {}, {}, {}, {}};
  constexpr Dimensions second{first};
  EXPECT_EQ(second, first);
}

TEST(Dimensions, DefaultConstructor) {
  EXPECT_EQ(Dimensions{},
            Dimensions(Dimension::Time(0), Dimension::Length(0), Dimension::Mass(0),
                       Dimension::ElectricCurrent(0), Dimension::Temperature(0),
                       Dimension::SubstanceAmount(0), Dimension::LuminousIntensity(0)));
}

TEST(Dimensions, Hash) {
  constexpr Dimensions first;
  constexpr Dimensions second{
    Dimension::Time(3), Dimension::Length(0), Dimension::Mass(-1), {}, {}, {}, {}};
  constexpr Dimensions third{
    Dimension::Time(3),
    Dimension::Length(0),
    Dimension::Mass(-1),
    Dimension::ElectricCurrent(0),
    Dimension::Temperature(0),
    Dimension::SubstanceAmount(0),
    Dimension::LuminousIntensity(1)};
  const std::hash<Dimensions> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(Dimensions, JSON) {
  EXPECT_EQ(Dimensions(Dimension::Time(-2), Dimension::Length(2), Dimension::Mass(1),
                       Dimension::ElectricCurrent(0), Dimension::Temperature(-1), {}, {})
                .JSON(),
            "{\"time\":-2,\"length\":2,\"mass\":1,\"temperature\":-1}");
  EXPECT_EQ(Dimensions(Dimension::Time(0), Dimension::Length(0), Dimension::Mass(1),
                       Dimension::ElectricCurrent(0), Dimension::Temperature(0),
                       Dimension::SubstanceAmount(-1), {})
                .JSON(),
            "{\"mass\":1,\"substance_amount\":-1}");
  EXPECT_EQ(Dimensions(Dimension::Time(1), Dimension::Length(-1), Dimension::Mass(2),
                       Dimension::ElectricCurrent(-2), Dimension::Temperature(3),
                       Dimension::SubstanceAmount(-3), Dimension::LuminousIntensity(4))
                .JSON(),
            "{\"time\":1,\"length\":-1,\"mass\":2,\"electric_current\":-2,\"temperature\":3,"
            "\"substance_amount\":-3,\"luminous_intensity\":4}");
}

TEST(Dimensions, MoveAssignmentOperator) {
  Dimensions first{Dimension::Time(-2), Dimension::Length(1), {}, {}, {}, {}, {}};
  Dimensions second;
  second = std::move(first);
  EXPECT_EQ(second, Dimensions(Dimension::Time(-2), Dimension::Length(1), {}, {}, {}, {}, {}));
}

TEST(Dimensions, MoveConstructor) {
  Dimensions first{Dimension::Time(-2), Dimension::Length(1), {}, {}, {}, {}, {}};
  const Dimensions second{std::move(first)};
  EXPECT_EQ(second, Dimensions(Dimension::Time(-2), Dimension::Length(1), {}, {}, {}, {}, {}));
}

TEST(Dimensions, Print) {
  EXPECT_EQ(Dimensions{}.Print(), "1");
  EXPECT_EQ(Dimensions(Dimension::Time(2), {}, {}, {}, {}, {}, {}).Print(), "T^2");
  EXPECT_EQ(Dimensions(Dimension::Time(1), Dimension::Length(-3), {}, {}, {}, {}, {}).Print(),
            "T·L^(-3)");
  EXPECT_EQ(
      Dimensions(Dimension::Time(-1), Dimension::Length(3), Dimension::Mass(0), {}, {}, {}, {})
          .Print(),
      "T^(-1)·L^3");
  EXPECT_EQ(Dimensions(Dimension::Time(2), Dimension::Length(-2), Dimension::Mass(-1),
                       Dimension::ElectricCurrent(1), {}, {}, {})
                .Print(),
            "T^2·L^(-2)·M^(-1)·I");
  EXPECT_EQ(Dimensions(Dimension::Time(-2), Dimension::Length(2), Dimension::Mass(1),
                       Dimension::ElectricCurrent(0), Dimension::Temperature(-1), {}, {})
                .Print(),
            "T^(-2)·L^2·M·Θ^(-1)");
  EXPECT_EQ(Dimensions(Dimension::Time(0), Dimension::Length(0), Dimension::Mass(1),
                       Dimension::ElectricCurrent(0), Dimension::Temperature(0),
                       Dimension::SubstanceAmount(-1), {})
                .Print(),
            "M·N^(-1)");
  EXPECT_EQ(Dimensions(Dimension::Time(0), Dimension::Length(0), Dimension::Mass(0),
                       Dimension::ElectricCurrent(0), Dimension::Temperature(-1),
                       Dimension::SubstanceAmount(0), Dimension::LuminousIntensity(1))
                .Print(),
            "Θ^(-1)·J");
  EXPECT_EQ(Dimensions(Dimension::Time(1), Dimension::Length(-1), Dimension::Mass(2),
                       Dimension::ElectricCurrent(-2), Dimension::Temperature(3),
                       Dimension::SubstanceAmount(-3), Dimension::LuminousIntensity(4))
                .Print(),
            "T·L^(-1)·M^2·I^(-2)·Θ^3·N^(-3)·J^4");
}

TEST(Dimensions, SizeOf) {
  EXPECT_EQ(sizeof(Dimensions{}), 7 * sizeof(int8_t));
}

TEST(Dimensions, Stream) {
  std::ostringstream stream;
  stream << Dimensions(Dimension::Time(2), Dimension::Length(-2), Dimension::Mass(-1),
                       Dimension::ElectricCurrent(1), {}, {}, {});
  EXPECT_EQ(stream.str(), Dimensions(Dimension::Time(2), Dimension::Length(-2), Dimension::Mass(-1),
                                     Dimension::ElectricCurrent(1), {}, {}, {})
                              .Print());
}

TEST(Dimensions, XML) {
  EXPECT_EQ(Dimensions(Dimension::Time(-2), Dimension::Length(2), Dimension::Mass(1),
                       Dimension::ElectricCurrent(0), Dimension::Temperature(-1), {}, {})
                .XML(),
            "<time>-2</time><length>2</length><mass>1</mass><temperature>-1</temperature>");
  EXPECT_EQ(Dimensions(Dimension::Time(0), Dimension::Length(0), Dimension::Mass(1),
                       Dimension::ElectricCurrent(0), Dimension::Temperature(0),
                       Dimension::SubstanceAmount(-1), {})
                .XML(),
            "<mass>1</mass><substance_amount>-1</substance_amount>");
  EXPECT_EQ(Dimensions(Dimension::Time(1), Dimension::Length(-1), Dimension::Mass(2),
                       Dimension::ElectricCurrent(-2), Dimension::Temperature(3),
                       Dimension::SubstanceAmount(-3), Dimension::LuminousIntensity(4))
                .XML(),
            "<time>1</time><length>-1</length><mass>2</mass><electric_current>-2</"
            "electric_current><temperature>3</temperature><substance_amount>-3</"
            "substance_amount><luminous_intensity>4</luminous_intensity>");
}

TEST(Dimensions, YAML) {
  EXPECT_EQ(Dimensions(Dimension::Time(-2), Dimension::Length(2), Dimension::Mass(1),
                       Dimension::ElectricCurrent(0), Dimension::Temperature(-1), {}, {})
                .YAML(),
            "{time:-2,length:2,mass:1,temperature:-1}");
  EXPECT_EQ(Dimensions(Dimension::Time(0), Dimension::Length(0), Dimension::Mass(1),
                       Dimension::ElectricCurrent(0), Dimension::Temperature(0),
                       Dimension::SubstanceAmount(-1), {})
                .YAML(),
            "{mass:1,substance_amount:-1}");
  EXPECT_EQ(Dimensions(Dimension::Time(1), Dimension::Length(-1), Dimension::Mass(2),
                       Dimension::ElectricCurrent(-2), Dimension::Temperature(3),
                       Dimension::SubstanceAmount(-3), Dimension::LuminousIntensity(4))
                .YAML(),
            "{time:1,length:-1,mass:2,electric_current:-2,temperature:3,substance_amount:-3,"
            "luminous_intensity:4}");
}

}  // namespace

}  // namespace PhQ
