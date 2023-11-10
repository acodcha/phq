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

#include "../include/PhQ/MassRate.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Mass.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Mass.hpp"
#include "../include/PhQ/Unit/MassRate.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(MassRate, ArithmeticOperatorAddition) {
  EXPECT_EQ(MassRate(1.0, Unit::MassRate::KilogramPerSecond)
                + MassRate(2.0, Unit::MassRate::KilogramPerSecond),
            MassRate(3.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, ArithmeticOperatorDivision) {
  EXPECT_EQ(MassRate(8.0, Unit::MassRate::KilogramPerSecond) / 2.0,
            MassRate(4.0, Unit::MassRate::KilogramPerSecond));

  EXPECT_EQ(MassRate(8.0, Unit::MassRate::KilogramPerSecond)
                / MassRate(2.0, Unit::MassRate::KilogramPerSecond),
            4.0);

  EXPECT_EQ(
      MassRate(8.0, Unit::MassRate::KilogramPerSecond) / Frequency(4.0, Unit::Frequency::Hertz),
      Mass(2.0, Unit::Mass::Kilogram));

  EXPECT_EQ(MassRate(8.0, Unit::MassRate::KilogramPerSecond) / Mass(4.0, Unit::Mass::Kilogram),
            Frequency(2.0, Unit::Frequency::Hertz));

  EXPECT_EQ(Mass(8.0, Unit::Mass::Kilogram) / MassRate(4.0, Unit::MassRate::KilogramPerSecond),
            Time(2.0, Unit::Time::Second));

  EXPECT_EQ(Mass(8.0, Unit::Mass::Kilogram) / Time(4.0, Unit::Time::Second),
            MassRate(2.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(MassRate(4.0, Unit::MassRate::KilogramPerSecond) * 2.0,
            MassRate(8.0, Unit::MassRate::KilogramPerSecond));

  EXPECT_EQ(2.0 * MassRate(4.0, Unit::MassRate::KilogramPerSecond),
            MassRate(8.0, Unit::MassRate::KilogramPerSecond));

  EXPECT_EQ(MassRate(4.0, Unit::MassRate::KilogramPerSecond) * Time(2.0, Unit::Time::Second),
            Mass(8.0, Unit::Mass::Kilogram));

  EXPECT_EQ(Time(4.0, Unit::Time::Second) * MassRate(2.0, Unit::MassRate::KilogramPerSecond),
            Mass(8.0, Unit::Mass::Kilogram));
}

TEST(MassRate, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(MassRate(3.0, Unit::MassRate::KilogramPerSecond)
                - MassRate(2.0, Unit::MassRate::KilogramPerSecond),
            MassRate(1.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, AssignmentOperatorAddition) {
  MassRate quantity{1.0, Unit::MassRate::KilogramPerSecond};
  quantity += MassRate(2.0, Unit::MassRate::KilogramPerSecond);
  EXPECT_EQ(quantity, MassRate(3.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, AssignmentOperatorDivision) {
  MassRate quantity{8.0, Unit::MassRate::KilogramPerSecond};
  quantity /= 2.0;
  EXPECT_EQ(quantity, MassRate(4.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, AssignmentOperatorMultiplication) {
  MassRate quantity{4.0, Unit::MassRate::KilogramPerSecond};
  quantity *= 2.0;
  EXPECT_EQ(quantity, MassRate(8.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, AssignmentOperatorSubtraction) {
  MassRate quantity{3.0, Unit::MassRate::KilogramPerSecond};
  quantity -= MassRate(2.0, Unit::MassRate::KilogramPerSecond);
  EXPECT_EQ(quantity, MassRate(1.0, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, ComparisonOperators) {
  const MassRate first{1.11, Unit::MassRate::KilogramPerSecond};
  const MassRate second{2.22, Unit::MassRate::KilogramPerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(MassRate, CopyAssignmentOperator) {
  const MassRate first{1.11, Unit::MassRate::KilogramPerSecond};
  MassRate second = MassRate::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(MassRate, CopyConstructor) {
  const MassRate first{1.11, Unit::MassRate::KilogramPerSecond};
  const MassRate second{first};
  EXPECT_EQ(second, first);
}

TEST(MassRate, Create) {
  constexpr MassRate quantity = MassRate::Create<Unit::MassRate::KilogramPerSecond>(1.11);
  EXPECT_EQ(quantity, MassRate(1.11, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, DefaultConstructor) {
  EXPECT_NO_THROW(MassRate{});
}

TEST(MassRate, Dimensions) {
  EXPECT_EQ(MassRate::Dimensions(), RelatedDimensions<Unit::MassRate>);
}

TEST(MassRate, Hash) {
  const MassRate first{1.11, Unit::MassRate::GramPerSecond};
  const MassRate second{1.110001, Unit::MassRate::GramPerSecond};
  const MassRate third{-1.11, Unit::MassRate::GramPerSecond};
  const std::hash<MassRate> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(MassRate, JSON) {
  EXPECT_EQ(MassRate(1.11, Unit::MassRate::KilogramPerSecond).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"kg/s\"}");
  EXPECT_EQ(MassRate(-2.22, Unit::MassRate::GramPerSecond).JSON(Unit::MassRate::GramPerSecond),
            "{\"value\":-2.220000000000000,\"unit\":\"g/s\"}");
}

TEST(MassRate, MiscellaneousConstructors) {
  EXPECT_EQ(Mass(MassRate(4.0, Unit::MassRate::KilogramPerSecond), Time(2.0, Unit::Time::Second)),
            Mass(8.0, Unit::Mass::Kilogram));

  EXPECT_EQ(Mass(MassRate(8.0, Unit::MassRate::KilogramPerSecond),
                 Frequency(4.0, Unit::Frequency::Hertz)),
            Mass(2.0, Unit::Mass::Kilogram));

  EXPECT_EQ(Time(Mass(8.0, Unit::Mass::Kilogram), MassRate(4.0, Unit::MassRate::KilogramPerSecond)),
            Time(2.0, Unit::Time::Second));

  EXPECT_EQ(
      Frequency(MassRate(8.0, Unit::MassRate::KilogramPerSecond), Mass(4.0, Unit::Mass::Kilogram)),
      Frequency(2.0, Unit::Frequency::Hertz));
}

TEST(MassRate, MoveAssignmentOperator) {
  MassRate first{1.11, Unit::MassRate::KilogramPerSecond};
  MassRate second = MassRate::Zero();
  second = std::move(first);
  EXPECT_EQ(second, MassRate(1.11, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, MoveConstructor) {
  MassRate first{1.11, Unit::MassRate::KilogramPerSecond};
  const MassRate second{std::move(first)};
  EXPECT_EQ(second, MassRate(1.11, Unit::MassRate::KilogramPerSecond));
}

TEST(MassRate, MutableValue) {
  MassRate quantity{1.11, Unit::MassRate::KilogramPerSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(MassRate, Print) {
  EXPECT_EQ(MassRate(1.11, Unit::MassRate::KilogramPerSecond).Print(), "1.110000000000000 kg/s");
  EXPECT_EQ(MassRate(-2.22, Unit::MassRate::GramPerSecond).Print(Unit::MassRate::GramPerSecond),
            "-2.220000000000000 g/s");
}

TEST(MassRate, SetValue) {
  MassRate quantity{1.11, Unit::MassRate::KilogramPerSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(MassRate, SizeOf) {
  EXPECT_EQ(sizeof(MassRate{}), sizeof(double));
}

TEST(MassRate, StandardConstructor) {
  EXPECT_NO_THROW(MassRate(1.11, Unit::MassRate::GramPerSecond));
}

TEST(MassRate, StaticValue) {
  constexpr MassRate quantity = MassRate::Create<Unit::MassRate::GramPerSecond>(1.11);
  constexpr double value = quantity.StaticValue<Unit::MassRate::GramPerSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(MassRate, Stream) {
  std::ostringstream stream;
  stream << MassRate(1.11, Unit::MassRate::KilogramPerSecond);
  EXPECT_EQ(stream.str(), MassRate(1.11, Unit::MassRate::KilogramPerSecond).Print());
}

TEST(MassRate, Unit) {
  EXPECT_EQ(MassRate::Unit(), Standard<Unit::MassRate>);
}

TEST(MassRate, Value) {
  EXPECT_EQ(MassRate(1.11, Unit::MassRate::KilogramPerSecond).Value(), 1.11);
  EXPECT_EQ(
      MassRate(1.11, Unit::MassRate::GramPerSecond).Value(Unit::MassRate::GramPerSecond), 1.11);
}

TEST(MassRate, XML) {
  EXPECT_EQ(MassRate(1.11, Unit::MassRate::KilogramPerSecond).XML(),
            "<value>1.110000000000000</value><unit>kg/s</unit>");
  EXPECT_EQ(MassRate(-2.22, Unit::MassRate::GramPerSecond).XML(Unit::MassRate::GramPerSecond),
            "<value>-2.220000000000000</value><unit>g/s</unit>");
}

TEST(MassRate, YAML) {
  EXPECT_EQ(MassRate(1.11, Unit::MassRate::KilogramPerSecond).YAML(),
            "{value:1.110000000000000,unit:\"kg/s\"}");
  EXPECT_EQ(MassRate(-2.22, Unit::MassRate::GramPerSecond).YAML(Unit::MassRate::GramPerSecond),
            "{value:-2.220000000000000,unit:\"g/s\"}");
}

TEST(MassRate, Zero) {
  EXPECT_EQ(MassRate::Zero(), MassRate(0.0, Unit::MassRate::KilogramPerSecond));
}

}  // namespace

}  // namespace PhQ
