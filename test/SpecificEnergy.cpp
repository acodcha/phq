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

#include "../include/PhQ/SpecificEnergy.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Energy.hpp"
#include "../include/PhQ/Mass.hpp"
#include "../include/PhQ/Unit/Energy.hpp"
#include "../include/PhQ/Unit/Mass.hpp"
#include "../include/PhQ/Unit/SpecificEnergy.hpp"

namespace PhQ {

namespace {

TEST(SpecificEnergy, ArithmeticOperatorAddition) {
  EXPECT_EQ(SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram)
                + SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            SpecificEnergy(3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, ArithmeticOperatorDivision) {
  EXPECT_EQ(SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram) / 2.0,
            SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram));

  EXPECT_EQ(SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram)
                / SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            4.0);

  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule)
                / SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram),
            Mass(2.0, Unit::Mass::Kilogram));

  EXPECT_EQ(Energy(8.0, Unit::Energy::Joule) / Mass(4.0, Unit::Mass::Kilogram),
            SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram) * 2.0,
            SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram));

  EXPECT_EQ(2.0 * SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram),
            SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram));

  EXPECT_EQ(
      SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram) * Mass(2.0, Unit::Mass::Kilogram),
      Energy(8.0, Unit::Energy::Joule));

  EXPECT_EQ(
      Mass(4.0, Unit::Mass::Kilogram) * SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram),
      Energy(8.0, Unit::Energy::Joule));
}

TEST(SpecificEnergy, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(SpecificEnergy(3.0, Unit::SpecificEnergy::JoulePerKilogram)
                - SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, AssignmentOperatorAddition) {
  SpecificEnergy quantity{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity += SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(quantity, SpecificEnergy(3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, AssignmentOperatorDivision) {
  SpecificEnergy quantity{8.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity /= 2.0;
  EXPECT_EQ(quantity, SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, AssignmentOperatorMultiplication) {
  SpecificEnergy quantity{4.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity *= 2.0;
  EXPECT_EQ(quantity, SpecificEnergy(8.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, AssignmentOperatorSubtraction) {
  SpecificEnergy quantity{3.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity -= SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(quantity, SpecificEnergy(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, ComparisonOperators) {
  const SpecificEnergy first{1.11, Unit::SpecificEnergy::JoulePerKilogram};
  const SpecificEnergy second{2.22, Unit::SpecificEnergy::JoulePerKilogram};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(SpecificEnergy, CopyAssignmentOperator) {
  const SpecificEnergy first{1.11, Unit::SpecificEnergy::JoulePerKilogram};
  SpecificEnergy second = SpecificEnergy::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(SpecificEnergy, CopyConstructor) {
  const SpecificEnergy first{1.11, Unit::SpecificEnergy::JoulePerKilogram};
  const SpecificEnergy second{first};
  EXPECT_EQ(second, first);
}

TEST(SpecificEnergy, Create) {
  constexpr SpecificEnergy quantity =
      SpecificEnergy::Create<Unit::SpecificEnergy::JoulePerKilogram>(1.11);
  EXPECT_EQ(quantity, SpecificEnergy(1.11, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, DefaultConstructor) {
  EXPECT_NO_THROW(SpecificEnergy{});
}

TEST(SpecificEnergy, Dimensions) {
  EXPECT_EQ(SpecificEnergy::Dimensions(), RelatedDimensions<Unit::SpecificEnergy>);
}

TEST(SpecificEnergy, Hash) {
  const SpecificEnergy first{1.11, Unit::SpecificEnergy::NanojoulePerGram};
  const SpecificEnergy second{1.110001, Unit::SpecificEnergy::NanojoulePerGram};
  const SpecificEnergy third{-1.11, Unit::SpecificEnergy::NanojoulePerGram};
  const std::hash<SpecificEnergy> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(SpecificEnergy, JSON) {
  EXPECT_EQ(SpecificEnergy(1.11, Unit::SpecificEnergy::JoulePerKilogram).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"J/kg\"}");
  EXPECT_EQ(SpecificEnergy(-2.22, Unit::SpecificEnergy::NanojoulePerGram)
                .JSON(Unit::SpecificEnergy::NanojoulePerGram),
            "{\"value\":-2.220000000000000,\"unit\":\"nJ/g\"}");
}

TEST(SpecificEnergy, MiscellaneousConstructors) {
  EXPECT_EQ(SpecificEnergy(Energy(8.0, Unit::Energy::Joule), Mass(4.0, Unit::Mass::Kilogram)),
            SpecificEnergy(2.0, Unit::SpecificEnergy::JoulePerKilogram));

  EXPECT_EQ(Mass(Energy(8.0, Unit::Energy::Joule),
                 SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram)),
            Mass(2.0, Unit::Mass::Kilogram));

  EXPECT_EQ(Energy(SpecificEnergy(4.0, Unit::SpecificEnergy::JoulePerKilogram),
                   Mass(2.0, Unit::Mass::Kilogram)),
            Energy(8.0, Unit::Energy::Joule));
}

TEST(SpecificEnergy, MoveAssignmentOperator) {
  SpecificEnergy first{1.11, Unit::SpecificEnergy::JoulePerKilogram};
  SpecificEnergy second = SpecificEnergy::Zero();
  second = std::move(first);
  EXPECT_EQ(second, SpecificEnergy(1.11, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, MoveConstructor) {
  SpecificEnergy first{1.11, Unit::SpecificEnergy::JoulePerKilogram};
  const SpecificEnergy second{std::move(first)};
  EXPECT_EQ(second, SpecificEnergy(1.11, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(SpecificEnergy, MutableValue) {
  SpecificEnergy quantity{1.11, Unit::SpecificEnergy::JoulePerKilogram};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(SpecificEnergy, Print) {
  EXPECT_EQ(SpecificEnergy(1.11, Unit::SpecificEnergy::JoulePerKilogram).Print(),
            "1.110000000000000 J/kg");
  EXPECT_EQ(SpecificEnergy(-2.22, Unit::SpecificEnergy::NanojoulePerGram)
                .Print(Unit::SpecificEnergy::NanojoulePerGram),
            "-2.220000000000000 nJ/g");
}

TEST(SpecificEnergy, SetValue) {
  SpecificEnergy quantity{1.11, Unit::SpecificEnergy::JoulePerKilogram};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(SpecificEnergy, SizeOf) {
  EXPECT_EQ(sizeof(SpecificEnergy{}), sizeof(double));
}

TEST(SpecificEnergy, StandardConstructor) {
  EXPECT_NO_THROW(SpecificEnergy(1.11, Unit::SpecificEnergy::NanojoulePerGram));
}

TEST(SpecificEnergy, StaticValue) {
  constexpr SpecificEnergy quantity =
      SpecificEnergy::Create<Unit::SpecificEnergy::NanojoulePerGram>(2.0);
  constexpr double value = quantity.StaticValue<Unit::SpecificEnergy::NanojoulePerGram>();
  EXPECT_EQ(value, 2.0);
}

TEST(SpecificEnergy, Stream) {
  std::ostringstream stream;
  stream << SpecificEnergy(1.11, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(stream.str(), SpecificEnergy(1.11, Unit::SpecificEnergy::JoulePerKilogram).Print());
}

TEST(SpecificEnergy, Unit) {
  EXPECT_EQ(SpecificEnergy::Unit(), Standard<Unit::SpecificEnergy>);
}

TEST(SpecificEnergy, Value) {
  EXPECT_EQ(SpecificEnergy(1.11, Unit::SpecificEnergy::JoulePerKilogram).Value(), 1.11);
  EXPECT_EQ(SpecificEnergy(2.0, Unit::SpecificEnergy::NanojoulePerGram)
                .Value(Unit::SpecificEnergy::NanojoulePerGram),
            2.0);
}

TEST(SpecificEnergy, XML) {
  EXPECT_EQ(SpecificEnergy(1.11, Unit::SpecificEnergy::JoulePerKilogram).XML(),
            "<value>1.110000000000000</value><unit>J/kg</unit>");
  EXPECT_EQ(SpecificEnergy(-2.22, Unit::SpecificEnergy::NanojoulePerGram)
                .XML(Unit::SpecificEnergy::NanojoulePerGram),
            "<value>-2.220000000000000</value><unit>nJ/g</unit>");
}

TEST(SpecificEnergy, YAML) {
  EXPECT_EQ(SpecificEnergy(1.11, Unit::SpecificEnergy::JoulePerKilogram).YAML(),
            "{value:1.110000000000000,unit:\"J/kg\"}");
  EXPECT_EQ(SpecificEnergy(-2.22, Unit::SpecificEnergy::NanojoulePerGram)
                .YAML(Unit::SpecificEnergy::NanojoulePerGram),
            "{value:-2.220000000000000,unit:\"nJ/g\"}");
}

TEST(SpecificEnergy, Zero) {
  EXPECT_EQ(SpecificEnergy::Zero(), SpecificEnergy(0.0, Unit::SpecificEnergy::JoulePerKilogram));
}

}  // namespace

}  // namespace PhQ
