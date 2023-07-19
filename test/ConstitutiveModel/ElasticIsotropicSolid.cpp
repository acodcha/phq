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

#include "../../include/PhQ/ConstitutiveModel/ElasticIsotropicSolid.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <unordered_set>

namespace PhQ {

namespace {

TEST(ConstitutiveModelElasticIsotropicSolid, Accessor) {
  const ShearModulus shear_modulus{4.0, Unit::Pressure::Pascal};
  const LameFirstModulus lame_first_modulus{-2.0, Unit::Pressure::Pascal};
  const ElasticIsotropicSolid model{shear_modulus, lame_first_modulus};
  EXPECT_EQ(model.GetType(), ConstitutiveModel::Type::ElasticIsotropicSolid);
  EXPECT_EQ(model.ShearModulus(), shear_modulus);
  EXPECT_EQ(model.LameFirstModulus(), lame_first_modulus);
}

TEST(ConstitutiveModelElasticIsotropicSolid, Comparison) {
  const ElasticIsotropicSolid model0{
      ShearModulus{4.0,  Unit::Pressure::Pascal},
      LameFirstModulus{-2.0, Unit::Pressure::Pascal}
  };
  const ElasticIsotropicSolid model1{
      ShearModulus{4.0,  Unit::Pressure::Pascal},
      LameFirstModulus{-1.0, Unit::Pressure::Pascal}
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

TEST(ConstitutiveModelElasticIsotropicSolid, Constructor) {
  const YoungModulus young_modulus{4.0, Unit::Pressure::Pascal};
  const ShearModulus shear_modulus{4.0, Unit::Pressure::Pascal};
  const IsentropicBulkModulus isentropic_bulk_modulus{
      4.0, Unit::Pressure::Pascal};
  const IsothermalBulkModulus isothermal_bulk_modulus{
      4.0, Unit::Pressure::Pascal};
  const LameFirstModulus lame_first_modulus{-2.0, Unit::Pressure::Pascal};
  const PWaveModulus p_wave_modulus{4.0, Unit::Pressure::Pascal};
  const PoissonRatio poisson_ratio{0.25};
  const ElasticIsotropicSolid model00;
  const ElasticIsotropicSolid model01{young_modulus, shear_modulus};
  const ElasticIsotropicSolid model02{young_modulus, isentropic_bulk_modulus};
  const ElasticIsotropicSolid model03{young_modulus, lame_first_modulus};
  const ElasticIsotropicSolid model04{young_modulus, p_wave_modulus};
  const ElasticIsotropicSolid model05{young_modulus, poisson_ratio};
  const ElasticIsotropicSolid model06{shear_modulus, isentropic_bulk_modulus};
  const ElasticIsotropicSolid model07{shear_modulus, lame_first_modulus};
  const ElasticIsotropicSolid model08{shear_modulus, p_wave_modulus};
  const ElasticIsotropicSolid model09{shear_modulus, poisson_ratio};
  const ElasticIsotropicSolid model10{
      isentropic_bulk_modulus, lame_first_modulus};
  const ElasticIsotropicSolid model11{isentropic_bulk_modulus, p_wave_modulus};
  const ElasticIsotropicSolid model12{isentropic_bulk_modulus, poisson_ratio};
  const ElasticIsotropicSolid model13{lame_first_modulus, p_wave_modulus};
  const ElasticIsotropicSolid model14{lame_first_modulus, poisson_ratio};
  const ElasticIsotropicSolid model15{p_wave_modulus, poisson_ratio};
}

TEST(ConstitutiveModelElasticIsotropicSolid, Hash) {
  const ElasticIsotropicSolid model0{
      ShearModulus{4.0,  Unit::Pressure::Pascal},
      LameFirstModulus{-2.0, Unit::Pressure::Pascal}
  };
  const ElasticIsotropicSolid model1{
      ShearModulus{4.000001, Unit::Pressure::Pascal},
      LameFirstModulus{-2.0,     Unit::Pressure::Pascal}
  };
  const ElasticIsotropicSolid model2{
      ShearModulus{4.0,       Unit::Pressure::Pascal},
      LameFirstModulus{-2.000001, Unit::Pressure::Pascal}
  };
  const std::hash<ElasticIsotropicSolid> hasher;
  EXPECT_NE(hasher(model0), hasher(model1));
  EXPECT_NE(hasher(model0), hasher(model2));
  const std::unordered_set<ElasticIsotropicSolid> unordered{
      model0, model1, model2};
}

TEST(ConstitutiveModelElasticIsotropicSolid, JSON) {
  const ShearModulus shear_modulus{4.0, Unit::Pressure::Pascal};
  const LameFirstModulus lame_first_modulus{-2.0, Unit::Pressure::Pascal};
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ElasticIsotropicSolid>(
          shear_modulus, lame_first_modulus);
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->JSON(),
            "{\"type\":\"elastic_isotropic_solid\",\"shear_modulus\":"
                + shear_modulus.JSON()
                + ",\"lame_first_modulus\":" + lame_first_modulus.JSON() + "}");
}

TEST(ConstitutiveModelElasticIsotropicSolid, Print) {
  const ShearModulus shear_modulus{4.0, Unit::Pressure::Pascal};
  const LameFirstModulus lame_first_modulus{-2.0, Unit::Pressure::Pascal};
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ElasticIsotropicSolid>(
          shear_modulus, lame_first_modulus);
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->Print(),
      "Type = Elastic Isotropic Solid, Shear Modulus = " + shear_modulus.Print()
          + ", Lamé's First Modulus = " + lame_first_modulus.Print());
}

TEST(ConstitutiveModelElasticIsotropicSolid, Stream) {
  const ElasticIsotropicSolid model{
      ShearModulus{4.0,  Unit::Pressure::Pascal},
      LameFirstModulus{-2.0, Unit::Pressure::Pascal}
  };
  std::ostringstream stream;
  stream << model;
  EXPECT_EQ(stream.str(), model.Print());
}

TEST(ConstitutiveModelElasticIsotropicSolid, StressAndStrain) {
  const ShearModulus shear_modulus{4.0, Unit::Pressure::Pascal};
  const LameFirstModulus lame_first_modulus{-2.0, Unit::Pressure::Pascal};
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ElasticIsotropicSolid>(
          shear_modulus, lame_first_modulus);
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
  const Stress stress = model->Stress(strain);
  EXPECT_EQ(model->Strain(stress), strain);
  EXPECT_EQ(model->Strain(zero_stress), zero_strain);
  EXPECT_EQ(model->StrainRate(stress), zero_strain_rate);
  EXPECT_EQ(model->Stress(strain), stress);
  EXPECT_EQ(model->Stress(strain_rate), zero_stress);
  EXPECT_EQ(model->Stress(strain, strain_rate), stress);
}

TEST(ConstitutiveModelElasticIsotropicSolid, Type) {
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ElasticIsotropicSolid>(
          ShearModulus{4.0, Unit::Pressure::Pascal},
          LameFirstModulus{-2.0, Unit::Pressure::Pascal});
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->GetType(), ConstitutiveModel::Type::ElasticIsotropicSolid);
}

TEST(ConstitutiveModelElasticIsotropicSolid, XML) {
  const ShearModulus shear_modulus{4.0, Unit::Pressure::Pascal};
  const LameFirstModulus lame_first_modulus{-2.0, Unit::Pressure::Pascal};
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ElasticIsotropicSolid>(
          shear_modulus, lame_first_modulus);
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(model->XML(),
            "<type>elastic_isotropic_solid</type><shear_modulus>"
                + shear_modulus.XML() + "</shear_modulus><lame_first_modulus>"
                + lame_first_modulus.XML() + "</lame_first_modulus>");
}

TEST(ConstitutiveModelElasticIsotropicSolid, YAML) {
  const ShearModulus shear_modulus{4.0, Unit::Pressure::Pascal};
  const LameFirstModulus lame_first_modulus{-2.0, Unit::Pressure::Pascal};
  const std::unique_ptr<ConstitutiveModel> model =
      std::make_unique<ElasticIsotropicSolid>(
          shear_modulus, lame_first_modulus);
  ASSERT_NE(model, nullptr);
  EXPECT_EQ(
      model->YAML(),
      "{type:\"elastic_isotropic_solid\",shear_modulus:" + shear_modulus.YAML()
          + ",lame_first_modulus:" + lame_first_modulus.YAML() + "}");
}

}  // namespace

}  // namespace PhQ
