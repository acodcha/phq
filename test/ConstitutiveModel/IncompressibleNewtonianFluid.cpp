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

#include "../../include/PhQ/ConstitutiveModel/IncompressibleNewtonianFluid.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <memory>
#include <sstream>
#include <utility>

#include "../../include/PhQ/ConstitutiveModel.hpp"
#include "../../include/PhQ/DynamicViscosity.hpp"
#include "../../include/PhQ/Strain.hpp"
#include "../../include/PhQ/StrainRate.hpp"
#include "../../include/PhQ/Stress.hpp"
#include "../../include/PhQ/Unit/DynamicViscosity.hpp"
#include "../../include/PhQ/Unit/Frequency.hpp"

namespace PhQ {

namespace {

TEST(ConstitutiveModelIncompressibleNewtonianFluid, ComparisonOperators) {
  const ConstitutiveModel::IncompressibleNewtonianFluid<> first{
    DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::IncompressibleNewtonianFluid<> second{
    DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond)};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Constructor) {
  const ConstitutiveModel::IncompressibleNewtonianFluid<> model{
    DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  EXPECT_EQ(model.DynamicViscosity(), DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, CopyAssignmentOperator) {
  const ConstitutiveModel::IncompressibleNewtonianFluid<> first{
    DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::IncompressibleNewtonianFluid<> second{
    DynamicViscosity(12.0, Unit::DynamicViscosity::PascalSecond)};
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, CopyConstructor) {
  const ConstitutiveModel::IncompressibleNewtonianFluid<> first{
    DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::IncompressibleNewtonianFluid<> second{first};
  EXPECT_EQ(second, first);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, DefaultConstructor) {
  EXPECT_NO_THROW(ConstitutiveModel::IncompressibleNewtonianFluid<>{});
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Hash) {
  const ConstitutiveModel::IncompressibleNewtonianFluid<> first{
    DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::IncompressibleNewtonianFluid<> second{
    DynamicViscosity(4.000001, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::IncompressibleNewtonianFluid<> third{
    DynamicViscosity(4.0e32, Unit::DynamicViscosity::PascalSecond)};
  const std::hash<ConstitutiveModel::IncompressibleNewtonianFluid<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, JSON) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid<>>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->JSON(),
            "{\"type\":\"incompressible_newtonian_fluid\",\"dynamic_viscosity\":"
                + DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond).JSON() + "}");
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, MoveAssignmentOperator) {
  ConstitutiveModel::IncompressibleNewtonianFluid<> first{
    DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::IncompressibleNewtonianFluid<> second{
    DynamicViscosity(12.0, Unit::DynamicViscosity::PascalSecond)};
  second = std::move(first);
  EXPECT_EQ(second, ConstitutiveModel::IncompressibleNewtonianFluid<>(
                        DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)));
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, MoveConstructor) {
  ConstitutiveModel::IncompressibleNewtonianFluid<> first{
    DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::IncompressibleNewtonianFluid<> second{std::move(first)};
  EXPECT_EQ(second, ConstitutiveModel::IncompressibleNewtonianFluid<>(
                        DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)));
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Print) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid<>>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->Print(),
            "Type = Incompressible Newtonian Fluid, Dynamic Viscosity = "
                + DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond).Print());
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Stream) {
  const ConstitutiveModel::IncompressibleNewtonianFluid<> first_model{
    DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond)};
  std::ostringstream first_stream;
  first_stream << first_model;
  EXPECT_EQ(first_stream.str(), first_model.Print());

  const std::unique_ptr<ConstitutiveModel> second_model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid<>>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(second_model, nullptr);
  std::ostringstream second_stream;
  second_stream << *second_model;
  EXPECT_EQ(second_stream.str(), second_model->Print());
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, StressAndStrainFloat) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid<float>>(
          DynamicViscosity<float>(100.0F, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  const Strain<float> strain{32.0F, -4.0F, -2.0F, 16.0F, -1.0F, 8.0F};
  const StrainRate<float> strain_rate{
    {32.0F, -4.0F, -2.0F, 16.0F, -1.0F, 8.0F},
    Unit::Frequency::Hertz
  };
  const Stress stress = model->Stress(strain_rate);
  EXPECT_EQ(model->Strain(stress), Strain<float>::Zero());
  EXPECT_EQ(model->StrainRate(Stress<float>::Zero()), StrainRate<float>::Zero());
  EXPECT_EQ(model->StrainRate(stress), strain_rate);
  EXPECT_EQ(model->Stress(strain), Stress<float>::Zero());
  EXPECT_EQ(model->Stress(strain_rate), stress);
  EXPECT_EQ(model->Stress(strain, strain_rate), stress);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, StressAndStrainDouble) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid<>>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  const Strain strain{32.0, -4.0, -2.0, 16.0, -1.0, 8.0};
  const StrainRate strain_rate{
    {32.0, -4.0, -2.0, 16.0, -1.0, 8.0},
    Unit::Frequency::Hertz
  };
  const Stress stress = model->Stress(strain_rate);
  EXPECT_EQ(model->Strain(stress), Strain<>::Zero());
  EXPECT_EQ(model->StrainRate(Stress<>::Zero()), StrainRate<>::Zero());
  EXPECT_EQ(model->StrainRate(stress), strain_rate);
  EXPECT_EQ(model->Stress(strain), Stress<>::Zero());
  EXPECT_EQ(model->Stress(strain_rate), stress);
  EXPECT_EQ(model->Stress(strain, strain_rate), stress);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, StressAndStrainLongDouble) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid<long double>>(
          DynamicViscosity<long double>(4.0L, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  const Strain<long double> strain{32.0L, -4.0L, -2.0L, 16.0L, -1.0L, 8.0L};
  const StrainRate<long double> strain_rate{
    {32.0L, -4.0L, -2.0L, 16.0L, -1.0L, 8.0L},
    Unit::Frequency::Hertz
  };
  const Stress stress = model->Stress(strain_rate);
  EXPECT_EQ(model->Strain(stress), Strain<long double>::Zero());
  EXPECT_EQ(model->StrainRate(Stress<long double>::Zero()), StrainRate<long double>::Zero());
  EXPECT_EQ(model->StrainRate(stress), strain_rate);
  EXPECT_EQ(model->Stress(strain), Stress<long double>::Zero());
  EXPECT_EQ(model->Stress(strain_rate), stress);
  EXPECT_EQ(model->Stress(strain, strain_rate), stress);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Type) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid<>>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->GetType(), ConstitutiveModel::Type::IncompressibleNewtonianFluid);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, XML) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid<>>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->XML(), "<type>incompressible_newtonian_fluid</type><dynamic_viscosity>"
                              + DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond).XML()
                              + "</dynamic_viscosity>");
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, YAML) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid<>>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->YAML(),
            "{type:\"incompressible_newtonian_fluid\",dynamic_viscosity:"
                + DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond).YAML() + "}");
}

}  // namespace

}  // namespace PhQ
