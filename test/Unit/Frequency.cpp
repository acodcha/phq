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

#include "../../include/PhQ/Unit/Frequency.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<Frequency, 6> Units = {
    Frequency::Hertz,     Frequency::Kilohertz, Frequency::Megahertz,
    Frequency::Gigahertz, Frequency::PerMinute, Frequency::PerHour,
};

TEST(UnitFrequency, Abbreviation) {
  EXPECT_EQ(Abbreviation(Frequency::Hertz), "Hz");
  EXPECT_EQ(Abbreviation(Frequency::Kilohertz), "kHz");
  EXPECT_EQ(Abbreviation(Frequency::Megahertz), "MHz");
  EXPECT_EQ(Abbreviation(Frequency::Gigahertz), "GHz");
  EXPECT_EQ(Abbreviation(Frequency::PerMinute), "/min");
  EXPECT_EQ(Abbreviation(Frequency::PerHour), "/hr");
}

TEST(UnitFrequency, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Frequency>(UnitSystem::MetreKilogramSecondKelvin),
            Frequency::Hertz);
  EXPECT_EQ(ConsistentUnit<Frequency>(UnitSystem::MillimetreGramSecondKelvin),
            Frequency::Hertz);
  EXPECT_EQ(ConsistentUnit<Frequency>(UnitSystem::FootPoundSecondRankine),
            Frequency::Hertz);
  EXPECT_EQ(ConsistentUnit<Frequency>(UnitSystem::InchPoundSecondRankine),
            Frequency::Hertz);
}

TEST(UnitFrequency, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Frequency::Hertz, Frequency::Hertz), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Frequency::Hertz, Frequency::Kilohertz),
                   value * 0.001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Frequency::Hertz, Frequency::Megahertz),
                   value * 0.000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Frequency::Hertz, Frequency::Gigahertz),
                   value * 0.000000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Frequency::Hertz, Frequency::PerMinute), value * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Frequency::Hertz, Frequency::PerHour), value * 3600.0);
}

TEST(UnitFrequency, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Frequency::Hertz, Frequency::Hertz), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Frequency::Kilohertz, Frequency::Hertz),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Frequency::Megahertz, Frequency::Hertz),
                   value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Frequency::Gigahertz, Frequency::Hertz),
                   value * 1000000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Frequency::PerMinute, Frequency::Hertz), value / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Frequency::PerHour, Frequency::Hertz), value / 3600.0);
}

TEST(UnitFrequency, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Frequency old_unit : Units) {
    for (const Frequency new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitFrequency, Parse) {
  EXPECT_EQ(Parse<Frequency>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Frequency>("Hz"), Frequency::Hertz);
  EXPECT_EQ(Parse<Frequency>("kHz"), Frequency::Kilohertz);
  EXPECT_EQ(Parse<Frequency>("MHz"), Frequency::Megahertz);
  EXPECT_EQ(Parse<Frequency>("GHz"), Frequency::Gigahertz);
  EXPECT_EQ(Parse<Frequency>("/min"), Frequency::PerMinute);
  EXPECT_EQ(Parse<Frequency>("/hr"), Frequency::PerHour);
}

TEST(UnitFrequency, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Frequency>, Dimensions(Dimension::Time{-1}));
}

TEST(UnitFrequency, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Frequency::Hertz), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Frequency::Kilohertz), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Frequency::Megahertz), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Frequency::Gigahertz), std::nullopt);
}

TEST(UnitFrequency, Standard) {
  EXPECT_EQ(Standard<Frequency>, Frequency::Hertz);
}

TEST(UnitFrequency, Stream) {
  std::ostringstream stream;
  stream << Frequency::Hertz;
  EXPECT_EQ(stream.str(), Abbreviation(Frequency::Hertz));
}

}  // namespace

}  // namespace PhQ::Unit
