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

#include "../include/PhQ/SoundSpeed.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/HeatCapacityRatio.hpp"
#include "../include/PhQ/IsentropicBulkModulus.hpp"
#include "../include/PhQ/MassDensity.hpp"
#include "../include/PhQ/SpecificGasConstant.hpp"
#include "../include/PhQ/Speed.hpp"
#include "../include/PhQ/StaticPressure.hpp"
#include "../include/PhQ/Temperature.hpp"
#include "../include/PhQ/Unit/MassDensity.hpp"
#include "../include/PhQ/Unit/Pressure.hpp"
#include "../include/PhQ/Unit/SpecificHeatCapacity.hpp"
#include "../include/PhQ/Unit/Speed.hpp"
#include "../include/PhQ/Unit/Temperature.hpp"

namespace PhQ {

namespace {

TEST(SoundSpeed, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      SoundSpeed(1.0, Unit::Speed::MetrePerSecond) + SoundSpeed(2.0, Unit::Speed::MetrePerSecond),
      SoundSpeed(3.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(SoundSpeed(1.0, Unit::Speed::MetrePerSecond) + Speed(2.0, Unit::Speed::MetrePerSecond),
            Speed(3.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Speed(1.0, Unit::Speed::MetrePerSecond) + SoundSpeed(2.0, Unit::Speed::MetrePerSecond),
            Speed(3.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, ArithmeticOperatorDivision) {
  EXPECT_EQ(SoundSpeed(8.0, Unit::Speed::MetrePerSecond) / 2.0,
            SoundSpeed(4.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(
      SoundSpeed(8.0, Unit::Speed::MetrePerSecond) / SoundSpeed(2.0, Unit::Speed::MetrePerSecond),
      4.0);
}

TEST(SoundSpeed, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SoundSpeed(4.0, Unit::Speed::MetrePerSecond) * 2.0,
            SoundSpeed(8.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(2.0 * SoundSpeed(4.0, Unit::Speed::MetrePerSecond),
            SoundSpeed(8.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      SoundSpeed(3.0, Unit::Speed::MetrePerSecond) - SoundSpeed(2.0, Unit::Speed::MetrePerSecond),
      SoundSpeed(1.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(SoundSpeed(3.0, Unit::Speed::MetrePerSecond) - Speed(2.0, Unit::Speed::MetrePerSecond),
            Speed(1.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Speed(3.0, Unit::Speed::MetrePerSecond) - SoundSpeed(2.0, Unit::Speed::MetrePerSecond),
            Speed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, AssignmentOperatorAddition) {
  SoundSpeed first{1.0, Unit::Speed::MetrePerSecond};
  first += SoundSpeed(2.0, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(first, SoundSpeed(3.0, Unit::Speed::MetrePerSecond));

  SoundSpeed second{1.0, Unit::Speed::MetrePerSecond};
  second += Speed{2.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(second, SoundSpeed(3.0, Unit::Speed::MetrePerSecond));

  Speed third{1.0, Unit::Speed::MetrePerSecond};
  third += SoundSpeed{2.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(third, Speed(3.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, AssignmentOperatorDivision) {
  SoundSpeed quantity{8.0, Unit::Speed::MetrePerSecond};
  quantity /= 2.0;
  EXPECT_EQ(quantity, SoundSpeed(4.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, AssignmentOperatorMultiplication) {
  SoundSpeed quantity{4.0, Unit::Speed::MetrePerSecond};
  quantity *= 2.0;
  EXPECT_EQ(quantity, SoundSpeed(8.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, AssignmentOperatorSubtraction) {
  SoundSpeed first{3.0, Unit::Speed::MetrePerSecond};
  first -= SoundSpeed(2.0, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(first, SoundSpeed(1.0, Unit::Speed::MetrePerSecond));

  SoundSpeed second{3.0, Unit::Speed::MetrePerSecond};
  second -= Speed{2.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(second, SoundSpeed(1.0, Unit::Speed::MetrePerSecond));

  Speed third{3.0, Unit::Speed::MetrePerSecond};
  third -= SoundSpeed{2.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(third, Speed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, ComparisonOperators) {
  const SoundSpeed first{1.0, Unit::Speed::MetrePerSecond};
  const SoundSpeed second{2.0, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(SoundSpeed, Constructor) {
  EXPECT_NO_THROW(SoundSpeed(1.0, Unit::Speed::MillimetrePerSecond));
  EXPECT_EQ(SoundSpeed(IsentropicBulkModulus(32.0, Unit::Pressure::Pascal),
                       MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre)),
            SoundSpeed(4.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(MassDensity(IsentropicBulkModulus(16.0, Unit::Pressure::Pascal),
                        SoundSpeed(2.0, Unit::Speed::MetrePerSecond)),
            MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre));
  EXPECT_EQ(IsentropicBulkModulus(MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                                  SoundSpeed(4.0, Unit::Speed::MetrePerSecond)),
            IsentropicBulkModulus(32.0, Unit::Pressure::Pascal));
  EXPECT_EQ(SoundSpeed(HeatCapacityRatio(2.0), StaticPressure(8.0, Unit::Pressure::Pascal),
                       MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)),
            SoundSpeed(2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(
      SoundSpeed(HeatCapacityRatio(2.0),
                 SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
                 Temperature(8.0, Unit::Temperature::Kelvin)),
      SoundSpeed(8.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, CopyAssignmentOperator) {
  {
    const SoundSpeed<float> first(1.0F, Unit::Speed::MetrePerSecond);
    SoundSpeed<double> second = SoundSpeed<double>::Zero();
    second = first;
    EXPECT_EQ(second, SoundSpeed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
  {
    const SoundSpeed<double> first(1.0, Unit::Speed::MetrePerSecond);
    SoundSpeed<double> second = SoundSpeed<double>::Zero();
    second = first;
    EXPECT_EQ(second, SoundSpeed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
  {
    const SoundSpeed<long double> first(1.0L, Unit::Speed::MetrePerSecond);
    SoundSpeed<double> second = SoundSpeed<double>::Zero();
    second = first;
    EXPECT_EQ(second, SoundSpeed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
}

TEST(SoundSpeed, CopyConstructor) {
  {
    const SoundSpeed<float> first(1.0F, Unit::Speed::MetrePerSecond);
    const SoundSpeed<double> second{first};
    EXPECT_EQ(second, SoundSpeed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
  {
    const SoundSpeed<double> first(1.0, Unit::Speed::MetrePerSecond);
    const SoundSpeed<double> second{first};
    EXPECT_EQ(second, SoundSpeed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
  {
    const SoundSpeed<long double> first(1.0L, Unit::Speed::MetrePerSecond);
    const SoundSpeed<double> second{first};
    EXPECT_EQ(second, SoundSpeed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
}

TEST(SoundSpeed, Create) {
  constexpr SoundSpeed quantity = SoundSpeed<>::Create<Unit::Speed::MetrePerSecond>(1.0);
  EXPECT_EQ(quantity, SoundSpeed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, DefaultConstructor) {
  EXPECT_NO_THROW(SoundSpeed<>{});
}

TEST(SoundSpeed, Dimensions) {
  EXPECT_EQ(SoundSpeed<>::Dimensions(), RelatedDimensions<Unit::Speed>);
}

TEST(SoundSpeed, Hash) {
  const SoundSpeed first{1.0, Unit::Speed::MillimetrePerSecond};
  const SoundSpeed second{1.00001, Unit::Speed::MillimetrePerSecond};
  const SoundSpeed third{-1.0, Unit::Speed::MillimetrePerSecond};
  const std::hash<SoundSpeed<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(SoundSpeed, JSON) {
  EXPECT_EQ(SoundSpeed(1.0, Unit::Speed::MetrePerSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"m/s\"}");
  EXPECT_EQ(
      SoundSpeed(1.0, Unit::Speed::MillimetrePerSecond).JSON(Unit::Speed::MillimetrePerSecond),
      "{\"value\":" + Print(1.0) + ",\"unit\":\"mm/s\"}");
}

TEST(SoundSpeed, MoveAssignmentOperator) {
  SoundSpeed first{1.0, Unit::Speed::MetrePerSecond};
  SoundSpeed second = SoundSpeed<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, SoundSpeed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, MoveConstructor) {
  SoundSpeed first{1.0, Unit::Speed::MetrePerSecond};
  const SoundSpeed second{std::move(first)};
  EXPECT_EQ(second, SoundSpeed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(SoundSpeed, MutableValue) {
  SoundSpeed quantity{1.0, Unit::Speed::MetrePerSecond};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SoundSpeed, Print) {
  EXPECT_EQ(SoundSpeed(1.0, Unit::Speed::MetrePerSecond).Print(), Print(1.0) + " m/s");
  EXPECT_EQ(
      SoundSpeed(1.0, Unit::Speed::MillimetrePerSecond).Print(Unit::Speed::MillimetrePerSecond),
      Print(1.0) + " mm/s");
}

TEST(SoundSpeed, SetValue) {
  SoundSpeed quantity{1.0, Unit::Speed::MetrePerSecond};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SoundSpeed, SizeOf) {
  EXPECT_EQ(sizeof(SoundSpeed<>{}), sizeof(double));
}

TEST(SoundSpeed, StaticValue) {
  constexpr SoundSpeed quantity = SoundSpeed<>::Create<Unit::Speed::MillimetrePerSecond>(1.0);
  constexpr double value = quantity.StaticValue<Unit::Speed::MillimetrePerSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(SoundSpeed, Stream) {
  std::ostringstream stream;
  stream << SoundSpeed(1.0, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(stream.str(), SoundSpeed(1.0, Unit::Speed::MetrePerSecond).Print());
}

TEST(SoundSpeed, Unit) {
  EXPECT_EQ(SoundSpeed<>::Unit(), Standard<Unit::Speed>);
}

TEST(SoundSpeed, Value) {
  EXPECT_EQ(SoundSpeed(1.0, Unit::Speed::MetrePerSecond).Value(), 1.0);
  EXPECT_EQ(
      SoundSpeed(1.0, Unit::Speed::MillimetrePerSecond).Value(Unit::Speed::MillimetrePerSecond),
      1.0);
}

TEST(SoundSpeed, XML) {
  EXPECT_EQ(SoundSpeed(1.0, Unit::Speed::MetrePerSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>m/s</unit>");
  EXPECT_EQ(SoundSpeed(1.0, Unit::Speed::MillimetrePerSecond).XML(Unit::Speed::MillimetrePerSecond),
            "<value>" + Print(1.0) + "</value><unit>mm/s</unit>");
}

TEST(SoundSpeed, YAML) {
  EXPECT_EQ(SoundSpeed(1.0, Unit::Speed::MetrePerSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"m/s\"}");
  EXPECT_EQ(
      SoundSpeed(1.0, Unit::Speed::MillimetrePerSecond).YAML(Unit::Speed::MillimetrePerSecond),
      "{value:" + Print(1.0) + ",unit:\"mm/s\"}");
}

TEST(SoundSpeed, Zero) {
  EXPECT_EQ(SoundSpeed<>::Zero(), SoundSpeed(0.0, Unit::Speed::MetrePerSecond));
}

}  // namespace

}  // namespace PhQ
