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
#include <unordered_set>

namespace PhQ {

namespace {

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Accessor) {
  const DynamicViscosity dynamic_viscosity{
      4.0, Unit::DynamicViscosity::PascalSecond};
  const ConstitutiveModel::IncompressibleNewtonianFluid model{
      dynamic_viscosity};
  EXPECT_EQ(
      model.GetType(), ConstitutiveModel::Type::IncompressibleNewtonianFluid);
  EXPECT_EQ(model.DynamicViscosity(), dynamic_viscosity);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Comparison) {
  const ConstitutiveModel::IncompressibleNewtonianFluid model0{
      DynamicViscosity{4.0, Unit::DynamicViscosity::PascalSecond}
  };
  const ConstitutiveModel::IncompressibleNewtonianFluid model1{
      DynamicViscosity{8.0, Unit::DynamicViscosity::PascalSecond}
  };
  EXPECT_EQ(model0, model0);
  EXPECT_NE(model0, model1);
  EXPECT_LT(model0, model1);
  EXPECT_GT(model1, model0);
  EXPECT_LE(model0, model0);
  EXPECT_LE(model0, model1);
  EXPECT_GE(model0, model0);
  EXPECT_GE(model1, model0);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Constructor) {
  const ConstitutiveModel::IncompressibleNewtonianFluid model0{};
  const ConstitutiveModel::IncompressibleNewtonianFluid model1{
      DynamicViscosity{4.0, Unit::DynamicViscosity::PascalSecond}
  };
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Hash) {
  const ConstitutiveModel::IncompressibleNewtonianFluid model0{
      DynamicViscosity{4.0, Unit::DynamicViscosity::PascalSecond}
  };
  const ConstitutiveModel::IncompressibleNewtonianFluid model1{
      DynamicViscosity{4.000001, Unit::DynamicViscosity::PascalSecond}
  };
  const ConstitutiveModel::IncompressibleNewtonianFluid model2{
      DynamicViscosity{4.0e32, Unit::DynamicViscosity::PascalSecond}
  };
  const std::hash<ConstitutiveModel::IncompressibleNewtonianFluid> hasher;
  EXPECT_NE(hasher(model0), hasher(model1));
  EXPECT_NE(hasher(model0), hasher(model2));
  const std::unordered_set<ConstitutiveModel::IncompressibleNewtonianFluid>
      unordered{model0, model1, model2};
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, JSON) {
  const DynamicViscosity dynamic_viscosity{
      4.0, Unit::DynamicViscosity::PascalSecond};
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          dynamic_viscosity);
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->JSON(),
            "{\"type\":\"incompressible_newtonian_fluid\",\"dynamic_"
            "viscosity\":"
                + dynamic_viscosity.JSON() + "}");
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Print) {
  const DynamicViscosity dynamic_viscosity{
      4.0, Unit::DynamicViscosity::PascalSecond};
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          dynamic_viscosity);
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->Print(),
            "Type = Incompressible Newtonian Fluid, Dynamic Viscosity = "
                + dynamic_viscosity.Print());
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, Stream) {
  const ConstitutiveModel::IncompressibleNewtonianFluid model{
      DynamicViscosity{4.0, Unit::DynamicViscosity::PascalSecond}
  };
  std::ostringstream stream;
  stream << model;
  EXPECT_EQ(stream.str(), model.Print());
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, StressAndStrain) {
  const DynamicViscosity dynamic_viscosity{
      4.0, Unit::DynamicViscosity::PascalSecond};
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          dynamic_viscosity);
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
          DynamicViscosity{4.0, Unit::DynamicViscosity::PascalSecond});
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->GetType(), ConstitutiveModel::Type::IncompressibleNewtonianFluid);
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, XML) {
  const DynamicViscosity dynamic_viscosity{
      4.0, Unit::DynamicViscosity::PascalSecond};
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          dynamic_viscosity);
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->XML(),
            "<type>incompressible_newtonian_fluid</type><dynamic_viscosity>"
                + dynamic_viscosity.XML() + "</dynamic_viscosity>");
}

TEST(ConstitutiveModelIncompressibleNewtonianFluid, YAML) {
  const DynamicViscosity dynamic_viscosity{
      4.0, Unit::DynamicViscosity::PascalSecond};
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ConstitutiveModel::IncompressibleNewtonianFluid>(
          dynamic_viscosity);
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->YAML(),
            "{type:\"incompressible_newtonian_fluid\",dynamic_viscosity:"
                + dynamic_viscosity.YAML() + "}");
}

}  // namespace

}  // namespace PhQ
