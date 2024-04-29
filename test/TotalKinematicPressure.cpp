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

#include "../include/PhQ/TotalKinematicPressure.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/DynamicKinematicPressure.hpp"
#include "../include/PhQ/MassDensity.hpp"
#include "../include/PhQ/StaticKinematicPressure.hpp"
#include "../include/PhQ/TotalPressure.hpp"
#include "../include/PhQ/Unit/MassDensity.hpp"
#include "../include/PhQ/Unit/Pressure.hpp"
#include "../include/PhQ/Unit/SpecificEnergy.hpp"

namespace PhQ {

namespace {

TEST(TotalKinematicPressure, ArithmeticOperatorAddition) {
  EXPECT_EQ(TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram)
                + TotalKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            TotalKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram)
                + DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram),
            TotalKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram)
                + StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            TotalKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, ArithmeticOperatorDivision) {
  EXPECT_EQ(TotalKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram) / 2.0,
            TotalKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(TotalKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram)
                / TotalKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            4.0);
  EXPECT_EQ(TotalPressure(8.0, Unit::Pressure::Pascal)
                / MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
            TotalKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(TotalKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram) * 2.0,
            TotalKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(2.0 * TotalKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram),
            TotalKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(TotalKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram)
                - TotalKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(TotalKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram)
                - StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
            DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(TotalKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram)
                - DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram),
            StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, AssignmentOperatorAddition) {
  TotalKinematicPressure total_kinematic_pressure{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  total_kinematic_pressure += TotalKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(total_kinematic_pressure,
            TotalKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, AssignmentOperatorDivision) {
  TotalKinematicPressure total_kinematic_pressure{8.0, Unit::SpecificEnergy::JoulePerKilogram};
  total_kinematic_pressure /= 2.0;
  EXPECT_EQ(total_kinematic_pressure,
            TotalKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, AssignmentOperatorMultiplication) {
  TotalKinematicPressure total_kinematic_pressure{4.0, Unit::SpecificEnergy::JoulePerKilogram};
  total_kinematic_pressure *= 2.0;
  EXPECT_EQ(total_kinematic_pressure,
            TotalKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, AssignmentOperatorSubtraction) {
  TotalKinematicPressure total_kinematic_pressure{3.0, Unit::SpecificEnergy::JoulePerKilogram};
  total_kinematic_pressure -= TotalKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(total_kinematic_pressure,
            TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, ComparisonOperators) {
  const TotalKinematicPressure first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  const TotalKinematicPressure second{2.0, Unit::SpecificEnergy::JoulePerKilogram};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(TotalKinematicPressure, CopyAssignmentOperator) {
  const TotalKinematicPressure first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  TotalKinematicPressure second = TotalKinematicPressure::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(TotalKinematicPressure, CopyConstructor) {
  const TotalKinematicPressure first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  const TotalKinematicPressure second{first};
  EXPECT_EQ(second, first);
}

TEST(TotalKinematicPressure, Create) {
  constexpr TotalKinematicPressure total_kinematic_pressure =
      TotalKinematicPressure::Create<Unit::SpecificEnergy::JoulePerKilogram>(1.0);
  EXPECT_EQ(total_kinematic_pressure,
            TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, DefaultConstructor) {
  EXPECT_NO_THROW(TotalKinematicPressure{});
}

TEST(TotalKinematicPressure, Dimensions) {
  EXPECT_EQ(TotalKinematicPressure::Dimensions(), RelatedDimensions<Unit::SpecificEnergy>);
}

TEST(TotalKinematicPressure, Hash) {
  const TotalKinematicPressure first{1.0, Unit::SpecificEnergy::NanojoulePerGram};
  const TotalKinematicPressure second{1.000001, Unit::SpecificEnergy::NanojoulePerGram};
  const TotalKinematicPressure third{-1.0, Unit::SpecificEnergy::NanojoulePerGram};
  const std::hash<TotalKinematicPressure> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(TotalKinematicPressure, JSON) {
  EXPECT_EQ(TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"J/kg\"}");
  EXPECT_EQ(TotalKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .JSON(Unit::SpecificEnergy::NanojoulePerGram),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"nJ/g\"}");
}

TEST(TotalKinematicPressure, MiscellaneousConstructors) {
  EXPECT_EQ(
      TotalKinematicPressure(StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram),
                             DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram)),
      TotalKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(TotalKinematicPressure(TotalPressure(8.0, Unit::Pressure::Pascal),
                                   MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre)),
            TotalKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(TotalPressure(MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                          TotalKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram)),
            TotalPressure(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(StaticKinematicPressure(
                TotalKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram),
                DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram)),
            StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram));
  EXPECT_EQ(DynamicKinematicPressure(
                TotalKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram),
                StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram)),
            DynamicKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, MoveAssignmentOperator) {
  TotalKinematicPressure first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  TotalKinematicPressure second = TotalKinematicPressure::Zero();
  second = std::move(first);
  EXPECT_EQ(second, TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, MoveConstructor) {
  TotalKinematicPressure first{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  const TotalKinematicPressure second{std::move(first)};
  EXPECT_EQ(second, TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(TotalKinematicPressure, MutableValue) {
  TotalKinematicPressure total_kinematic_pressure{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  double& value = total_kinematic_pressure.MutableValue();
  value = 2.0;
  EXPECT_EQ(total_kinematic_pressure.Value(), 2.0);
}

TEST(TotalKinematicPressure, Print) {
  EXPECT_EQ(TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).Print(),
            Print(1.0) + " J/kg");
  EXPECT_EQ(TotalKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .Print(Unit::SpecificEnergy::NanojoulePerGram),
            Print(1.0) + " nJ/g");
}

TEST(TotalKinematicPressure, SetValue) {
  TotalKinematicPressure total_kinematic_pressure{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  total_kinematic_pressure.SetValue(2.0);
  EXPECT_EQ(total_kinematic_pressure.Value(), 2.0);
}

TEST(TotalKinematicPressure, SizeOf) {
  EXPECT_EQ(sizeof(TotalKinematicPressure{}), sizeof(double));
}

TEST(TotalKinematicPressure, StandardConstructor) {
  EXPECT_NO_THROW(TotalKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram));
}

TEST(TotalKinematicPressure, StaticValue) {
  constexpr TotalKinematicPressure total_kinematic_pressure =
      TotalKinematicPressure::Create<Unit::SpecificEnergy::NanojoulePerGram>(2.0);
  constexpr double value =
      total_kinematic_pressure.StaticValue<Unit::SpecificEnergy::NanojoulePerGram>();
  EXPECT_EQ(value, 2.0);
}

TEST(TotalKinematicPressure, Stream) {
  std::ostringstream stream;
  stream << TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(
      stream.str(), TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).Print());
}

TEST(TotalKinematicPressure, Unit) {
  EXPECT_EQ(TotalKinematicPressure::Unit(), Standard<Unit::SpecificEnergy>);
}

TEST(TotalKinematicPressure, Value) {
  EXPECT_EQ(TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).Value(), 1.0);
  EXPECT_EQ(TotalKinematicPressure(2.0, Unit::SpecificEnergy::NanojoulePerGram)
                .Value(Unit::SpecificEnergy::NanojoulePerGram),
            2.0);
}

TEST(TotalKinematicPressure, XML) {
  EXPECT_EQ(TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).XML(),
            "<value>" + Print(1.0) + "</value><unit>J/kg</unit>");
  EXPECT_EQ(TotalKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .XML(Unit::SpecificEnergy::NanojoulePerGram),
            "<value>" + Print(1.0) + "</value><unit>nJ/g</unit>");
}

TEST(TotalKinematicPressure, YAML) {
  EXPECT_EQ(TotalKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram).YAML(),
            "{value:" + Print(1.0) + ",unit:\"J/kg\"}");
  EXPECT_EQ(TotalKinematicPressure(1.0, Unit::SpecificEnergy::NanojoulePerGram)
                .YAML(Unit::SpecificEnergy::NanojoulePerGram),
            "{value:" + Print(1.0) + ",unit:\"nJ/g\"}");
}

TEST(TotalKinematicPressure, Zero) {
  EXPECT_EQ(TotalKinematicPressure::Zero(),
            TotalKinematicPressure(0.0, Unit::SpecificEnergy::JoulePerKilogram));
}

}  // namespace

}  // namespace PhQ
