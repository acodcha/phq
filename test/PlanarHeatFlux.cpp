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

#include "../include/PhQ/PlanarHeatFlux.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/PlanarDirection.hpp"
#include "../include/PhQ/PlanarTemperatureGradient.hpp"
#include "../include/PhQ/PlanarVector.hpp"
#include "../include/PhQ/ScalarHeatFlux.hpp"
#include "../include/PhQ/ScalarThermalConductivity.hpp"
#include "../include/PhQ/ThermalConductivity.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/EnergyFlux.hpp"
#include "../include/PhQ/Unit/TemperatureGradient.hpp"
#include "../include/PhQ/Unit/ThermalConductivity.hpp"

namespace PhQ {

namespace {

TEST(PlanarHeatFlux, Angle) {
  EXPECT_EQ(PlanarHeatFlux({0.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre)
                .Angle(PlanarHeatFlux({3.0, 0.0}, Unit::EnergyFlux::WattPerSquareMetre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarHeatFlux, ArithmeticOperatorAddition) {
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre)
                + PlanarHeatFlux({2.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre),
            PlanarHeatFlux({3.0, -6.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, ArithmeticOperatorDivision) {
  EXPECT_EQ(PlanarHeatFlux({2.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre) / 2.0,
            PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre) * 2.0,
            PlanarHeatFlux({2.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(2.0 * PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre),
            PlanarHeatFlux({2.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(PlanarDirection(3.0, -4.0) * ScalarHeatFlux(5.0, Unit::EnergyFlux::WattPerSquareMetre),
            PlanarHeatFlux({3.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(ScalarHeatFlux(5.0, Unit::EnergyFlux::WattPerSquareMetre) * PlanarDirection(3.0, -4.0),
            PlanarHeatFlux({3.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PlanarHeatFlux({3.0, -6.0}, Unit::EnergyFlux::WattPerSquareMetre)
                - PlanarHeatFlux({2.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre),
            PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, AssignmentOperatorAddition) {
  PlanarHeatFlux heat_flux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre);
  heat_flux += PlanarHeatFlux({2.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(heat_flux, PlanarHeatFlux({3.0, -6.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, AssignmentOperatorDivision) {
  PlanarHeatFlux heat_flux({2.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre);
  heat_flux /= 2.0;
  EXPECT_EQ(heat_flux, PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, AssignmentOperatorMultiplication) {
  PlanarHeatFlux heat_flux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre);
  heat_flux *= 2.0;
  EXPECT_EQ(heat_flux, PlanarHeatFlux({2.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, AssignmentOperatorSubtraction) {
  PlanarHeatFlux heat_flux({3.0, -6.0}, Unit::EnergyFlux::WattPerSquareMetre);
  heat_flux -= PlanarHeatFlux({2.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(heat_flux, PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, ComparisonOperators) {
  const PlanarHeatFlux first({1.0, -2.000001}, Unit::EnergyFlux::WattPerSquareMetre);
  const PlanarHeatFlux second({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PlanarHeatFlux, Constructor) {
  EXPECT_NO_THROW(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre));
  EXPECT_EQ(PlanarHeatFlux(ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre),
                           ScalarHeatFlux(-2.0, Unit::EnergyFlux::WattPerSquareMetre)),
            PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(PlanarDirection(PlanarHeatFlux({3.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre)),
            PlanarDirection(3.0, -4.0));
  EXPECT_EQ(Angle(PlanarHeatFlux({0.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre),
                  PlanarHeatFlux({3.0, 0.0}, Unit::EnergyFlux::WattPerSquareMetre)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(PlanarHeatFlux(
                ScalarThermalConductivity(2.0, Unit::ThermalConductivity::WattPerMetrePerKelvin),
                PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre)),
            PlanarHeatFlux({-2.0, 4.0}, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(PlanarHeatFlux(
                ThermalConductivity({1.0, -2.0, 3.0, -4.0, 5.0, -6.0},
                                    Unit::ThermalConductivity::WattPerMetrePerKelvin),
                PlanarTemperatureGradient({1.0, -2.0}, Unit::TemperatureGradient::KelvinPerMetre)),
            PlanarHeatFlux({-5.0, -6.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, CopyAssignmentOperator) {
  {
    const PlanarHeatFlux<float> first({1.0F, -2.0F}, Unit::EnergyFlux::WattPerSquareMetre);
    PlanarHeatFlux<double> second = PlanarHeatFlux<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarHeatFlux<double>({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
  {
    const PlanarHeatFlux<double> first({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre);
    PlanarHeatFlux<double> second = PlanarHeatFlux<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarHeatFlux<double>({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
  {
    const PlanarHeatFlux<long double> first({1.0L, -2.0L}, Unit::EnergyFlux::WattPerSquareMetre);
    PlanarHeatFlux<double> second = PlanarHeatFlux<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarHeatFlux<double>({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
}

TEST(PlanarHeatFlux, CopyConstructor) {
  {
    const PlanarHeatFlux<float> first({1.0F, -2.0F}, Unit::EnergyFlux::WattPerSquareMetre);
    const PlanarHeatFlux<double> second{first};
    EXPECT_EQ(second, PlanarHeatFlux<double>({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
  {
    const PlanarHeatFlux<double> first({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre);
    const PlanarHeatFlux<double> second{first};
    EXPECT_EQ(second, PlanarHeatFlux<double>({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
  {
    const PlanarHeatFlux<long double> first({1.0L, -2.0L}, Unit::EnergyFlux::WattPerSquareMetre);
    const PlanarHeatFlux<double> second{first};
    EXPECT_EQ(second, PlanarHeatFlux<double>({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
}

TEST(PlanarHeatFlux, Create) {
  {
    constexpr PlanarHeatFlux heat_flux =
        PlanarHeatFlux<>::Create<Unit::EnergyFlux::WattPerSquareMetre>(1.0, -2.0);
    EXPECT_EQ(heat_flux, PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
  {
    constexpr PlanarHeatFlux heat_flux =
        PlanarHeatFlux<>::Create<Unit::EnergyFlux::WattPerSquareMetre>(
            std::array<double, 2>{1.0, -2.0});
    EXPECT_EQ(heat_flux, PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
  {
    constexpr PlanarHeatFlux heat_flux =
        PlanarHeatFlux<>::Create<Unit::EnergyFlux::WattPerSquareMetre>(PlanarVector{1.0, -2.0});
    EXPECT_EQ(heat_flux, PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
  }
}

TEST(PlanarHeatFlux, DefaultConstructor) {
  EXPECT_NO_THROW(PlanarHeatFlux<>{});
}

TEST(PlanarHeatFlux, Dimensions) {
  EXPECT_EQ(PlanarHeatFlux<>::Dimensions(), RelatedDimensions<Unit::EnergyFlux>);
}

TEST(PlanarHeatFlux, Hash) {
  const PlanarHeatFlux first({1.0, -2.000001}, Unit::EnergyFlux::NanowattPerSquareMillimetre);
  const PlanarHeatFlux second({1.0, -2.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre);
  const PlanarHeatFlux third({1.0, 2.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre);
  const std::hash<PlanarHeatFlux<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PlanarHeatFlux, JSON) {
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"W/m^2\"}");
  EXPECT_EQ(
      PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre)
          .JSON(Unit::EnergyFlux::NanowattPerSquareMillimetre),
      "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"nW/mm^2\"}");
}

TEST(PlanarHeatFlux, Magnitude) {
  EXPECT_EQ(PlanarHeatFlux({3.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre).Magnitude(),
            ScalarHeatFlux(5.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, MoveAssignmentOperator) {
  PlanarHeatFlux first({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre);
  PlanarHeatFlux second = PlanarHeatFlux<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, MoveConstructor) {
  PlanarHeatFlux first({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre);
  const PlanarHeatFlux second{std::move(first)};
  EXPECT_EQ(second, PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, MutableValue) {
  PlanarHeatFlux heat_flux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre);
  PlanarVector<>& value = heat_flux.MutableValue();
  value = PlanarVector{-4.0, 5.0};
  EXPECT_EQ(heat_flux.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarHeatFlux, PlanarDirection) {
  EXPECT_EQ(PlanarHeatFlux({3.0, -4.0}, Unit::EnergyFlux::WattPerSquareMetre).PlanarDirection(),
            PlanarDirection(3.0, -4.0));
}

TEST(PlanarHeatFlux, Print) {
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") W/m^2");
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Print(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") nW/mm^2");
}

TEST(PlanarHeatFlux, SetValue) {
  PlanarHeatFlux heat_flux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre);
  heat_flux.SetValue({-4.0, 5.0});
  EXPECT_EQ(heat_flux.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarHeatFlux, SizeOf) {
  EXPECT_EQ(sizeof(PlanarHeatFlux<>{}), 2 * sizeof(double));
}

TEST(PlanarHeatFlux, StaticValue) {
  constexpr PlanarHeatFlux heat_flux =
      PlanarHeatFlux<>::Create<Unit::EnergyFlux::NanowattPerSquareMillimetre>(1.0, -2.0);
  constexpr PlanarVector value =
      heat_flux.StaticValue<Unit::EnergyFlux::NanowattPerSquareMillimetre>();
  EXPECT_EQ(value, PlanarVector(1.0, -2.0));
}

TEST(PlanarHeatFlux, Stream) {
  std::ostringstream stream;
  stream << PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre);
  EXPECT_EQ(
      stream.str(), PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre).Print());
}

TEST(PlanarHeatFlux, Unit) {
  EXPECT_EQ(PlanarHeatFlux<>::Unit(), Standard<Unit::EnergyFlux>);
}

TEST(PlanarHeatFlux, Value) {
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre).Value(),
            PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .Value(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            PlanarVector(1.0, -2.0));
}

TEST(PlanarHeatFlux, XML) {
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>W/m^2</unit>");
  EXPECT_EQ(
      PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre)
          .XML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
      "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>nW/mm^2</unit>");
}

TEST(PlanarHeatFlux, XY) {
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre).x(),
            ScalarHeatFlux(1.0, Unit::EnergyFlux::WattPerSquareMetre));
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre).y(),
            ScalarHeatFlux(-2.0, Unit::EnergyFlux::WattPerSquareMetre));
}

TEST(PlanarHeatFlux, YAML) {
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::WattPerSquareMetre).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"W/m^2\"}");
  EXPECT_EQ(PlanarHeatFlux({1.0, -2.0}, Unit::EnergyFlux::NanowattPerSquareMillimetre)
                .YAML(Unit::EnergyFlux::NanowattPerSquareMillimetre),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"nW/mm^2\"}");
}

TEST(PlanarHeatFlux, Zero) {
  EXPECT_EQ(
      PlanarHeatFlux<>::Zero(), PlanarHeatFlux({0.0, 0.0}, Unit::EnergyFlux::WattPerSquareMetre));
}

}  // namespace

}  // namespace PhQ
