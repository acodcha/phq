// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#include "../../include/PhQ/ConstitutiveModel/IncompressibleNewtonianFluid.hpp"

#include <gtest/gtest.h>

#include <memory>

namespace PhQ {

namespace {

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Comparisons) {
  const ConstitutiveModel::IncompressibleNewtonianFluid first{
      DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::IncompressibleNewtonianFluid second{
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

TEST(ConstitutiveModelIncompressibleNewtonianFluid, CopyAssignment) {
  const ConstitutiveModel::IncompressibleNewtonianFluid first{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::IncompressibleNewtonianFluid second{
      DynamicViscosity(12.0, Unit::DynamicViscosity::PascalSecond)};
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, CopyConstructor) {
  const ConstitutiveModel::IncompressibleNewtonianFluid first{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::IncompressibleNewtonianFluid second{first};
  EXPECT_EQ(second, first);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, DefaultConstructor) {
  EXPECT_NO_THROW(ConstitutiveModel::IncompressibleNewtonianFluid{});
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Hash) {
  const ConstitutiveModel::IncompressibleNewtonianFluid first{
      DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::IncompressibleNewtonianFluid second{
      DynamicViscosity(4.000001, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::IncompressibleNewtonianFluid third{
      DynamicViscosity(4.0e32, Unit::DynamicViscosity::PascalSecond)};
  const std::hash<ConstitutiveModel::IncompressibleNewtonianFluid> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, JSON) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->JSON(),
      "{\"type\":\"incompressible_newtonian_fluid\",\"dynamic_"
      "viscosity\":"
          + DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond).JSON()
          + "}");
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, MoveAssignment) {
  const ConstitutiveModel::IncompressibleNewtonianFluid first{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::IncompressibleNewtonianFluid second{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::IncompressibleNewtonianFluid third{
      DynamicViscosity(12.0, Unit::DynamicViscosity::PascalSecond)};
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, MoveConstructor) {
  const ConstitutiveModel::IncompressibleNewtonianFluid first{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::IncompressibleNewtonianFluid second{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::IncompressibleNewtonianFluid third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Print) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->Print(),
            "Type = Incompressible Newtonian Fluid, Dynamic Viscosity = "
                + DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond)
                      .Print());
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, StandardConstructor) {
  const ConstitutiveModel::IncompressibleNewtonianFluid model{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  EXPECT_EQ(model.DynamicViscosity(),
            DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Stream) {
  const ConstitutiveModel::IncompressibleNewtonianFluid first_model{
      DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond)};
  std::ostringstream first_stream;
  first_stream << first_model;
  EXPECT_EQ(first_stream.str(), first_model.Print());

  const std::unique_ptr<ConstitutiveModel> second_model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(second_model, nullptr);
  std::ostringstream second_stream;
  second_stream << *second_model;
  EXPECT_EQ(second_stream.str(), second_model->Print());
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, StressAndStrain) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  const Strain zero_strain{
      {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
  };
  const StrainRate zero_strain_rate{
      {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
      Unit::Frequency::Hertz
  };
  const Stress zero_stress{
      {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
      Unit::Pressure::Pascal
  };
  const Strain strain{
      {32.0, -4.0, -2.0, 16.0, -1.0, 8.0}
  };
  const StrainRate strain_rate{
      {32.0, -4.0, -2.0, 16.0, -1.0, 8.0},
      Unit::Frequency::Hertz
  };
  const Stress stress = model->Stress(strain_rate);
  EXPECT_EQ(model->Strain(stress), zero_strain);
  EXPECT_EQ(model->StrainRate(zero_stress), zero_strain_rate);
  EXPECT_EQ(model->StrainRate(stress), strain_rate);
  EXPECT_EQ(model->Stress(strain), zero_stress);
  EXPECT_EQ(model->Stress(strain_rate), stress);
  EXPECT_EQ(model->Stress(strain, strain_rate), stress);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Type) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->GetType(), ConstitutiveModel::Type::IncompressibleNewtonianFluid);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, XML) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->XML(),
      "<type>incompressible_newtonian_fluid</type><dynamic_viscosity>"
          + DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond).XML()
          + "</dynamic_viscosity>");
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, YAML) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->YAML(),
      "{type:\"incompressible_newtonian_fluid\",dynamic_viscosity:"
          + DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond).YAML()
          + "}");
}

}  // namespace

}  // namespace PhQ
