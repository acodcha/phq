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

#include "../include/PhQ/HeatFlux.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Direction.hpp"
#include "../include/PhQ/ScalarHeatFlux.hpp"
#include "../include/PhQ/ScalarThermalConductivity.hpp"
#include "../include/PhQ/TemperatureGradient.hpp"
#include "../include/PhQ/ThermalConductivity.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/EnergyFlux.hpp"
#include "../include/PhQ/Unit/TemperatureGradient.hpp"
#include "../include/PhQ/Unit/ThermalConductivity.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(HeatFlux, Angle) {
  EXPECT_EQ(HeatFlux({0.0, -2.0, 0.0}, Unit::EnergyFlux::WattPerSquareMetre)
                .Angle(HeatFlux({0.0, 0.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(HeatFlux, ArithmeticOperatorAddition) {
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre)
                + HeatFlux({2.0, -4.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre),
            HeatFlux({3.0, -6.0, 9.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, ArithmeticOperatorDivision) {
  EXPECT_EQ(HeatFlux({2.0, -4.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre) / 2.0,
            HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre) * 2.0,
            HeatFlux({2.0, -4.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(2.0 * HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre),
            HeatFlux({2.0, -4.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(Direction(2.0, -3.0, 6.0) * ScalarHeatFlux(7.0, Unit::EnergyFlux::WattPerSquareMetre),
            HeatFlux({2.0, -3.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(ScalarHeatFlux(7.0, Unit::EnergyFlux::WattPerSquareMetre) * Direction(2.0, -3.0, 6.0),
            HeatFlux({2.0, -3.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(HeatFlux({3.0, -6.0, 9.0}, Unit::EnergyFlux::WattPerSquareMetre)
                - HeatFlux({2.0, -4.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre),
            HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, AssignmentOperatorAddition) {
  HeatFlux heat_flux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre);
  heat_flux += HeatFlux({2.0, -4.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(heat_flux, HeatFlux({3.0, -6.0, 9.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, AssignmentOperatorDivision) {
  HeatFlux heat_flux({2.0, -4.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre);
  heat_flux /= 2.0;
  EXPECT_EQ(heat_flux, HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, AssignmentOperatorMultiplication) {
  HeatFlux heat_flux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre);
  heat_flux *= 2.0;
  EXPECT_EQ(heat_flux, HeatFlux({2.0, -4.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, AssignmentOperatorSubtraction) {
  HeatFlux heat_flux({3.0, -6.0, 9.0}, Unit::EnergyFlux::WattPerSquareMetre);
  heat_flux -= HeatFlux({2.0, -4.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(heat_flux, HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, ComparisonOperators) {
  const HeatFlux first({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre);
  const HeatFlux second({1.0, -2.0, 3.000001}, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(HeatFlux, CopyAssignmentOperator) {
  const HeatFlux first({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre);
  HeatFlux second = HeatFlux<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(HeatFlux, CopyConstructor) {
  const HeatFlux first({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre);
  const HeatFlux second{first};
  EXPECT_EQ(second, first);
}

TEST(HeatFlux, Create) {
  {
    constexpr HeatFlux heat_flux =
        HeatFlux<>::Create<Unit::EnergyFlux::WattPerSquareMetre>(1.0, -2.0, 3.0);
    EXPECT_EQ(heat_flux, HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
  {
    constexpr HeatFlux heat_flux = HeatFlux<>::Create<Unit::EnergyFlux::WattPerSquareMetre>(
        std::array<double, 3>{1.0, -2.0, 3.0});
    EXPECT_EQ(heat_flux, HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
  {
    constexpr HeatFlux heat_flux =
        HeatFlux<>::Create<Unit::EnergyFlux::WattPerSquareMetre>(Vector{1.0, -2.0, 3.0});
    EXPECT_EQ(heat_flux, HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
}

TEST(HeatFlux, DefaultConstructor) {
  EXPECT_NO_THROW(HeatFlux{});
}

TEST(HeatFlux, Dimensions) {
  EXPECT_EQ(HeatFlux<>::Dimensions(), RelatedDimensions<Unit::EnergyFlux>);
}

TEST(HeatFlux, Direction) {
  EXPECT_EQ(HeatFlux({2.0, -3.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre).Direction(),
            Direction(2.0, -3.0, 6.0));
}

TEST(HeatFlux, Hash) {
  const HeatFlux first({1.0, -2.0, 3.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre);
  const HeatFlux second({1.0, -2.0, 3.000001}, Unit::EnergyFlux::NanowattPerSquareMillimetre);
  const HeatFlux third({1.0, 2.0, 3.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre);
  const std::hash<HeatFlux<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(HeatFlux, JSON) {
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"W/m^2\"}");
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .JSON(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"nW/mm^2\"}");
}

TEST(HeatFlux, Magnitude) {
  EXPECT_EQ(HeatFlux({2.0, -3.0, 6.0}, Unit::EnergyFlux::WattPerSquareMetre).Magnitude(),
            ScalarHeatFlux(7.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre)),
            Direction(1.0, -2.0, 3.0));
  EXPECT_EQ(Angle(HeatFlux({0.0, -2.0, 0.0}, Unit::EnergyFlux::WattPerSquareMetre),
                  HeatFlux({0.0, 0.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(
      HeatFlux(ScalarThermalConductivity(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
               TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)),
      HeatFlux({-2.0, 4.0, -6.0}, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(
      HeatFlux(ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                   Unit::ThermalConductivity::WattPerMetrePerKelvin),
               TemperatureGradient({1.0, -2.0, 3.0}, Unit::TemperatureGradient::KelvinPerMetre)),
      HeatFlux({-14.0, -21.0, 25.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, MoveAssignmentOperator) {
  HeatFlux first({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre);
  HeatFlux second = HeatFlux<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, MoveConstructor) {
  HeatFlux first({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre);
  const HeatFlux second{std::move(first)};
  EXPECT_EQ(second, HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, MutableValue) {
  HeatFlux heat_flux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre);
  Vector<>& value = heat_flux.MutableValue();
  value = Vector{-4.0, 5.0, -6.0};
  EXPECT_EQ(heat_flux.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(HeatFlux, Print) {
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") W/m^2");
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Print(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") nW/mm^2");
}

TEST(HeatFlux, SetValue) {
  HeatFlux heat_flux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre);
  heat_flux.SetValue({-4.0, 5.0, -6.0});
  EXPECT_EQ(heat_flux.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(HeatFlux, SizeOf) {
  EXPECT_EQ(sizeof(HeatFlux{}), 3 * sizeof(double));
}

TEST(HeatFlux, StandardConstructor) {
  EXPECT_NO_THROW(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre));
}

TEST(HeatFlux, StaticValue) {
  constexpr HeatFlux heat_flux =
      HeatFlux<>::Create<Unit::EnergyFlux::NanowattPerSquareMillimetre>(1.0, -2.0, 3.0);
  constexpr Vector value = heat_flux.StaticValue<Unit::EnergyFlux::NanowattPerSquareMillimetre>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(HeatFlux, Stream) {
  std::ostringstream stream;
  stream << HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(stream.str(), HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre).Print());
}

TEST(HeatFlux, Unit) {
  EXPECT_EQ(HeatFlux<>::Unit(), Standard<Unit::EnergyFlux>);
}

TEST(HeatFlux, Value) {
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre).Value(),
            Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Value(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            Vector(1.0, -2.0, 3.0));
}

TEST(HeatFlux, XML) {
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>W/m^2</unit>");
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .XML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>nW/mm^2</unit>");
}

TEST(HeatFlux, XYZ) {
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre).x(),
            ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre).y(),
            ScalarHeatFlux(-2.0, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre).z(),
            ScalarHeatFlux(3.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(HeatFlux, YAML) {
  EXPECT_EQ(
      HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::WattPerSquareMetre).YAML(),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"W/m^2\"}");
  EXPECT_EQ(
      HeatFlux({1.0, -2.0, 3.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre)
          .YAML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"nW/mm^2\"}");
}

TEST(HeatFlux, Zero) {
  EXPECT_EQ(HeatFlux<>::Zero(), HeatFlux({0.0, 0.0, 0.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

}  // namespace

}  // namespace PhQ
