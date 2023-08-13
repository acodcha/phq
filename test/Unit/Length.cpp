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

#include "../../include/PhQ/Unit/Length.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<Length, 12> Units = {
    Length::Mile,      Length::Kilometre,  Length::Metre,
    Length::Yard,      Length::Foot,       Length::Decimetre,
    Length::Inch,      Length::Centimetre, Length::Millimetre,
    Length::Milliinch, Length::Micrometre, Length::Microinch,
};

TEST(UnitLength, Abbreviation) {
  EXPECT_EQ(Abbreviation(Length::Mile), "mi");
  EXPECT_EQ(Abbreviation(Length::Kilometre), "km");
  EXPECT_EQ(Abbreviation(Length::Metre), "m");
  EXPECT_EQ(Abbreviation(Length::Yard), "yd");
  EXPECT_EQ(Abbreviation(Length::Foot), "ft");
  EXPECT_EQ(Abbreviation(Length::Decimetre), "dm");
  EXPECT_EQ(Abbreviation(Length::Inch), "in");
  EXPECT_EQ(Abbreviation(Length::Centimetre), "cm");
  EXPECT_EQ(Abbreviation(Length::Millimetre), "mm");
  EXPECT_EQ(Abbreviation(Length::Milliinch), "mil");
  EXPECT_EQ(Abbreviation(Length::Micrometre), "μm");
  EXPECT_EQ(Abbreviation(Length::Microinch), "μin");
}

TEST(UnitLength, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Length>(UnitSystem::MetreKilogramSecondKelvin),
            Length::Metre);
  EXPECT_EQ(ConsistentUnit<Length>(UnitSystem::MillimetreGramSecondKelvin),
            Length::Millimetre);
  EXPECT_EQ(
      ConsistentUnit<Length>(UnitSystem::FootPoundSecondRankine), Length::Foot);
  EXPECT_EQ(
      ConsistentUnit<Length>(UnitSystem::InchPoundSecondRankine), Length::Inch);
}

TEST(UnitLength, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Metre, Length::Mile), value / 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Metre, Length::Kilometre), value * 0.001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Length::Metre, Length::Metre), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Metre, Length::Yard), value / 0.9144);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Metre, Length::Foot), value / 0.3048);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Metre, Length::Decimetre), value * 10.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Metre, Length::Inch), value / 0.0254);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Metre, Length::Centimetre), value * 100.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Metre, Length::Millimetre), value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Metre, Length::Milliinch), value / 0.0000254);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Metre, Length::Micrometre), value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Length::Metre, Length::Microinch),
                   value / 0.0000000254);
}

TEST(UnitLength, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Mile, Length::Metre), value * 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Kilometre, Length::Metre), value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Length::Metre, Length::Metre), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Yard, Length::Metre), value * 0.9144);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Foot, Length::Metre), value * 0.3048);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Decimetre, Length::Metre), value * 0.1);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Inch, Length::Metre), value * 0.0254);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Centimetre, Length::Metre), value * 0.01);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Millimetre, Length::Metre), value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Milliinch, Length::Metre), value * 0.0000254);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Length::Micrometre, Length::Metre), value * 0.000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Length::Microinch, Length::Metre),
                   value * 0.0000000254);
}

TEST(UnitLength, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Length old_unit : Units) {
    for (const Length new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitLength, DimensionSet) {
  EXPECT_EQ(Dimensions<Length>,
            Dimension::Set(Dimension::Time{0}, Dimension::Length{1}));
}

TEST(UnitLength, Parse) {
  EXPECT_EQ(Parse<Length>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Length>("mi"), Length::Mile);
  EXPECT_EQ(Parse<Length>("km"), Length::Kilometre);
  EXPECT_EQ(Parse<Length>("m"), Length::Metre);
  EXPECT_EQ(Parse<Length>("yd"), Length::Yard);
  EXPECT_EQ(Parse<Length>("ft"), Length::Foot);
  EXPECT_EQ(Parse<Length>("dm"), Length::Decimetre);
  EXPECT_EQ(Parse<Length>("in"), Length::Inch);
  EXPECT_EQ(Parse<Length>("cm"), Length::Centimetre);
  EXPECT_EQ(Parse<Length>("mm"), Length::Millimetre);
  EXPECT_EQ(Parse<Length>("mil"), Length::Milliinch);
  EXPECT_EQ(Parse<Length>("μm"), Length::Micrometre);
  EXPECT_EQ(Parse<Length>("μin"), Length::Microinch);
}

TEST(UnitLength, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Length::Mile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Kilometre), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(Length::Metre), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Length::Yard), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(Length::Foot), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Length::Decimetre), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(Length::Inch), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Length::Centimetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Millimetre),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Length::Milliinch), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Micrometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Microinch), std::nullopt);
}

TEST(UnitLength, Standard) { EXPECT_EQ(Standard<Length>, Length::Metre); }

}  // namespace

}  // namespace PhQ::Unit
