// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#include "../../include/PhQ/ConstitutiveModel/CompressibleNewtonianFluid.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <memory>
#include <sstream>
#include <utility>

#include "../../include/PhQ/BulkDynamicViscosity.hpp"
#include "../../include/PhQ/ConstitutiveModel.hpp"
#include "../../include/PhQ/DynamicViscosity.hpp"
#include "../../include/PhQ/Strain.hpp"
#include "../../include/PhQ/StrainRate.hpp"
#include "../../include/PhQ/Stress.hpp"
#include "../../include/PhQ/Unit/DynamicViscosity.hpp"
#include "../../include/PhQ/Unit/Frequency.hpp"

namespace PhQ {

namespace {

TEST(ConstitutiveModelCompressibleNewtonianFluid, ComparisonOperators) {
  {
    const ConstitutiveModel::CompressibleNewtonianFluid<> first{
        DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond),
        BulkDynamicViscosity(0.0, Unit::DynamicViscosity::PascalSecond)};
    const ConstitutiveModel::CompressibleNewtonianFluid<> second{
        DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
        BulkDynamicViscosity(0.0, Unit::DynamicViscosity::PascalSecond)};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_GT(second, first);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
  }
  {
    const ConstitutiveModel::CompressibleNewtonianFluid<> first{
        DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
        BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)};
    const ConstitutiveModel::CompressibleNewtonianFluid<> second{
        DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
        BulkDynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond)};
    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
    EXPECT_LT(first, second);
    EXPECT_GT(second, first);
    EXPECT_LE(first, first);
    EXPECT_LE(first, second);
    EXPECT_GE(first, first);
    EXPECT_GE(second, first);
  }
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, Constructor) {
  {
    const ConstitutiveModel::CompressibleNewtonianFluid<> model{
        DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
        BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)};
    EXPECT_EQ(
        model.DynamicViscosity(), DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond));
    EXPECT_EQ(model.BulkDynamicViscosity(),
              BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
  }
  {
    const ConstitutiveModel::CompressibleNewtonianFluid<> model{
        DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond)};
    EXPECT_EQ(
        model.DynamicViscosity(), DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond));
    EXPECT_EQ(model.BulkDynamicViscosity(),
              BulkDynamicViscosity(0.0, Unit::DynamicViscosity::PascalSecond));
  }
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, CopyAssignmentOperator) {
  const ConstitutiveModel::CompressibleNewtonianFluid<> first{
      DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::CompressibleNewtonianFluid<> second{
      DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond)};
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, CopyConstructor) {
  const ConstitutiveModel::CompressibleNewtonianFluid<> first{
      DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::CompressibleNewtonianFluid<> second{first};
  EXPECT_EQ(second, first);
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, DefaultConstructor) {
  EXPECT_NO_THROW(ConstitutiveModel::CompressibleNewtonianFluid<>{});
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, Hash) {
  const ConstitutiveModel::CompressibleNewtonianFluid<> first{
      DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::CompressibleNewtonianFluid<> second{
      DynamicViscosity(2.000001, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::CompressibleNewtonianFluid<> third{
      DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(1.000001, Unit::DynamicViscosity::PascalSecond)};
  const std::hash<ConstitutiveModel::CompressibleNewtonianFluid<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, JSON) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid<>>(
          DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->JSON(),
            "{\"type\":\"compressible_newtonian_fluid\",\"dynamic_viscosity\":"
                + DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond).JSON()
                + ",\"bulk_dynamic_viscosity\":"
                + BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).JSON() + "}");
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, MoveAssignmentOperator) {
  ConstitutiveModel::CompressibleNewtonianFluid<> first{
      DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)};
  ConstitutiveModel::CompressibleNewtonianFluid<> second{
      DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond)};
  second = std::move(first);
  EXPECT_EQ(second, ConstitutiveModel::CompressibleNewtonianFluid<>(
                        DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
                        BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)));
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, MoveConstructor) {
  ConstitutiveModel::CompressibleNewtonianFluid<> first{
      DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)};
  const ConstitutiveModel::CompressibleNewtonianFluid<> second{std::move(first)};
  EXPECT_EQ(second, ConstitutiveModel::CompressibleNewtonianFluid<>(
                        DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
                        BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)));
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, Print) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid<>>(
          DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->Print(),
            "Type = Compressible Newtonian Fluid, Dynamic Viscosity = "
                + DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond).Print()
                + ", Bulk Dynamic Viscosity = "
                + BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).Print());
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, Stream) {
  const ConstitutiveModel::CompressibleNewtonianFluid<> first_model{
      DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
      BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)};
  std::ostringstream first_stream;
  first_stream << first_model;
  EXPECT_EQ(first_stream.str(), first_model.Print());

  const std::unique_ptr<const ConstitutiveModel> second_model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid<>>(
          DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(second_model, nullptr);
  std::ostringstream second_stream;
  second_stream << *second_model;
  EXPECT_EQ(second_stream.str(), second_model->Print());
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, StressAndStrainFloat) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid<float>>(
          DynamicViscosity<float>(2.0F, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity<float>(0.0F, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  const Strain<float> strain{32.0F, 1.0F, -2.0F, 16.0F, -1.0F, 8.0F};
  const StrainRate<float> strain_rate{
      {32.0F, 1.0F, -2.0F, 16.0F, -1.0F, 8.0F},
      Unit::Frequency::Hertz
  };
  const Stress<float> stress = model->Stress(strain_rate);
  EXPECT_EQ(model->Strain(stress), Strain<float>::Zero());
  EXPECT_EQ(model->StrainRate(Stress<float>::Zero()), StrainRate<float>::Zero());
  EXPECT_EQ(model->StrainRate(stress), strain_rate);
  EXPECT_EQ(model->Stress(strain), Stress<float>::Zero());
  EXPECT_EQ(model->Stress(strain_rate), stress);
  EXPECT_EQ(model->Stress(strain, strain_rate), stress);
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, StressAndStrainDouble) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid<>>(
          DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  const Strain strain{32.0, 1.0, -2.0, 16.0, -1.0, 8.0};
  const StrainRate strain_rate{
      {32.0, 1.0, -2.0, 16.0, -1.0, 8.0},
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

TEST(ConstitutiveModelCompressibleNewtonianFluid, StressAndStrainLongDouble) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid<long double>>(
          DynamicViscosity<long double>(2.0L, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity<long double>(1.0L, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  const Strain<long double> strain{32.0L, 1.0L, -2.0L, 16.0L, -1.0L, 8.0L};
  const StrainRate<long double> strain_rate{
      {32.0L, 1.0L, -2.0L, 16.0L, -1.0L, 8.0L},
      Unit::Frequency::Hertz
  };
  const Stress<long double> stress = model->Stress(strain_rate);
  EXPECT_EQ(model->Strain(stress), Strain<long double>::Zero());
  EXPECT_EQ(model->StrainRate(Stress<long double>::Zero()), StrainRate<long double>::Zero());
  EXPECT_EQ(model->StrainRate(stress), strain_rate);
  EXPECT_EQ(model->Stress(strain), Stress<long double>::Zero());
  EXPECT_EQ(model->Stress(strain_rate), stress);
  EXPECT_EQ(model->Stress(strain, strain_rate), stress);
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, Type) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid<>>(
          DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->GetType(), ConstitutiveModel::Type::CompressibleNewtonianFluid);
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, XML) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid<>>(
          DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->XML(),
            "<type>compressible_newtonian_fluid</type><dynamic_viscosity>"
                + DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond).XML()
                + "</dynamic_viscosity><bulk_dynamic_viscosity>"
                + BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).XML()
                + "</bulk_dynamic_viscosity>");
}

TEST(ConstitutiveModelCompressibleNewtonianFluid, YAML) {
  const std::unique_ptr<const ConstitutiveModel> model =
      std::make_unique<const ConstitutiveModel::CompressibleNewtonianFluid<>>(
          DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
          BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->YAML(),
            "{type:\"compressible_newtonian_fluid\",dynamic_viscosity:"
                + DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond).YAML()
                + ",bulk_dynamic_viscosity:"
                + BulkDynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond).YAML() + "}");
}

}  // namespace

}  // namespace PhQ
