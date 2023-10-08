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

#include "../../include/PhQ/ConstitutiveModel/CompressibleNewtonianFluid.hpp"

#include <gtest/gtest.h>

#include <memory>

namespace PhQ {

namespace {

TEST(ConstitutiveModelCompressibleNewtonianFluid, Comparisons) {
  const ConstitutiveModel::CompressibleNewtonianFluid first{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::CompressibleNewtonianFluid second{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-3.0, Unit::DynamicViscosity::PascalSecond)};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, CopyAssignment) {
  const ConstitutiveModel::CompressibleNewtonianFluid first{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::CompressibleNewtonianFluid second{
      DynamicViscosity(12.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-8.0, Unit::DynamicViscosity::PascalSecond)};
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, CopyConstructor) {
  const ConstitutiveModel::CompressibleNewtonianFluid first{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::CompressibleNewtonianFluid second{first};
  EXPECT_EQ(second, first);
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, DefaultConstructor) {
  EXPECT_NO_THROW(ConstitutiveModel::CompressibleNewtonianFluid{});
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, Hash) {
  const ConstitutiveModel::CompressibleNewtonianFluid first{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::CompressibleNewtonianFluid second{
      DynamicViscosity(6.000001, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::CompressibleNewtonianFluid third{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.000001, Unit::DynamicViscosity::PascalSecond)};
  const std::hash<ConstitutiveModel::CompressibleNewtonianFluid> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, JSON) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid>(
          DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->JSON(),
      "{\"type\":\"compressible_newtonian_fluid\",\"dynamic_viscosity\":"
          + DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond).JSON()
          + ",\"bulk_dynamic_viscosity\":"
          + BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)
                .JSON()
          + "}");
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, MoveAssignment) {
  const ConstitutiveModel::CompressibleNewtonianFluid first{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::CompressibleNewtonianFluid second{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::CompressibleNewtonianFluid third{
      DynamicViscosity(12.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-8.0, Unit::DynamicViscosity::PascalSecond)};
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, MoveConstructor) {
  const ConstitutiveModel::CompressibleNewtonianFluid first{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::CompressibleNewtonianFluid second{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::CompressibleNewtonianFluid third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, Print) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid>(
          DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->Print(),
      "Type = Compressible Newtonian Fluid, Dynamic Viscosity = "
          + DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond).Print()
          + ", Bulk Dynamic Viscosity = "
          + BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)
                .Print());
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, StandardConstructors) {
  const ConstitutiveModel::CompressibleNewtonianFluid first{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)};
  EXPECT_EQ(first.DynamicViscosity(),
            DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond));
  EXPECT_EQ(first.BulkDynamicViscosity(),
            BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond));

  const ConstitutiveModel::CompressibleNewtonianFluid second{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond)};
  EXPECT_EQ(second.DynamicViscosity(),
            DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond));
  EXPECT_EQ(second.BulkDynamicViscosity(),
            BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, Stream) {
  const ConstitutiveModel::CompressibleNewtonianFluid first_model{
      DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)};
  std::ostringstream first_stream;
  first_stream << first_model;
  EXPECT_EQ(first_stream.str(), first_model.Print());

  const std::unique_ptr<const ConstitutiveModel> second_model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid>(
          DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(second_model, nullptr);
  std::ostringstream second_stream;
  second_stream << *second_model;
  EXPECT_EQ(second_stream.str(), second_model->Print());
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, StressAndStrain) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid>(
          DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond));
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

TEST(ConstitutiveModelCompressibleNewtonianFluid, Type) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid>(
          DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->GetType(), ConstitutiveModel::Type::CompressibleNewtonianFluid);
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, XML) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid>(
          DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->XML(),
      "<type>compressible_newtonian_fluid</type><dynamic_viscosity>"
          + DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond).XML()
          + "</dynamic_viscosity><bulk_dynamic_viscosity>"
          + BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)
                .XML()
          + "</bulk_dynamic_viscosity>");
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, YAML) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid>(
          DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->YAML(),
      "{type:\"compressible_newtonian_fluid\",dynamic_viscosity:"
          + DynamicViscosity(6.0, Unit::DynamicViscosity::PascalSecond).YAML()
          + ",bulk_dynamic_viscosity:"
          + BulkDynamicViscosity(-4.0, Unit::DynamicViscosity::PascalSecond)
                .YAML()
          + "}");
}

}  // namespace

}  // namespace PhQ
