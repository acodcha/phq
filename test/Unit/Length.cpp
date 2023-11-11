// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#include "../../include/PhQ/Unit/Length.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Length, 12> Units = {
    Length::Mile,       Length::Kilometre, Length::Metre,      Length::Yard,
    Length::Foot,       Length::Decimetre, Length::Inch,       Length::Centimetre,
    Length::Millimetre, Length::Milliinch, Length::Micrometre, Length::Microinch,
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
  EXPECT_EQ(ConsistentUnit<Length>(UnitSystem::MetreKilogramSecondKelvin), Length::Metre);
  EXPECT_EQ(ConsistentUnit<Length>(UnitSystem::MillimetreGramSecondKelvin), Length::Millimetre);
  EXPECT_EQ(ConsistentUnit<Length>(UnitSystem::FootPoundSecondRankine), Length::Foot);
  EXPECT_EQ(ConsistentUnit<Length>(UnitSystem::InchPoundSecondRankine), Length::Inch);
}

TEST(UnitLength, ConvertFromStandard) {
  constexpr double value{10.0};

  Internal::TestConversions(Length::Metre, Length::Mile, value, value / 1609.344);
  Internal::TestConversions(Length::Metre, Length::Kilometre, value, value * 0.001);
  Internal::TestConversions(Length::Metre, Length::Metre, value, value);
  Internal::TestConversions(Length::Metre, Length::Yard, value, value / 0.9144);
  Internal::TestConversions(Length::Metre, Length::Foot, value, value / 0.3048);
  Internal::TestConversions(Length::Metre, Length::Decimetre, value, value * 10.0);
  Internal::TestConversions(Length::Metre, Length::Inch, value, value / 0.0254);
  Internal::TestConversions(Length::Metre, Length::Centimetre, value, value * 100.0);
  Internal::TestConversions(Length::Metre, Length::Millimetre, value, value * 1000.0);
  Internal::TestConversions(Length::Metre, Length::Milliinch, value, value / 0.0000254);
  Internal::TestConversions(Length::Metre, Length::Micrometre, value, value * 1000000.0);
  Internal::TestConversions(Length::Metre, Length::Microinch, value, value / 0.0000000254);

  Internal::TestStaticConversions<Length, Length::Metre, Length::Foot>(value, value / 0.3048);
}

TEST(UnitLength, ConvertToStandard) {
  constexpr double value{10.0};

  Internal::TestConversions(Length::Mile, Length::Metre, value, value * 1609.344);
  Internal::TestConversions(Length::Kilometre, Length::Metre, value, value * 1000.0);
  Internal::TestConversions(Length::Metre, Length::Metre, value, value);
  Internal::TestConversions(Length::Yard, Length::Metre, value, value * 0.9144);
  Internal::TestConversions(Length::Foot, Length::Metre, value, value * 0.3048);
  Internal::TestConversions(Length::Decimetre, Length::Metre, value, value * 0.1);
  Internal::TestConversions(Length::Inch, Length::Metre, value, value * 0.0254);
  Internal::TestConversions(Length::Centimetre, Length::Metre, value, value * 0.01);
  Internal::TestConversions(Length::Millimetre, Length::Metre, value, value * 0.001);
  Internal::TestConversions(Length::Milliinch, Length::Metre, value, value * 0.0000254);
  Internal::TestConversions(Length::Micrometre, Length::Metre, value, value * 0.000001);
  Internal::TestConversions(Length::Microinch, Length::Metre, value, value * 0.0000000254);

  Internal::TestStaticConversions<Length, Length::Foot, Length::Metre>(value, value * 0.3048);
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

TEST(UnitLength, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Length>, Dimensions(Dimension::Time{0}, Dimension::Length{1}));
}

TEST(UnitLength, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Length::Mile), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Kilometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Metre), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Length::Yard), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Foot), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Length::Decimetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Inch), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Length::Centimetre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Millimetre), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Length::Milliinch), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Micrometre), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Length::Microinch), std::nullopt);
}

TEST(UnitLength, Standard) {
  EXPECT_EQ(Standard<Length>, Length::Metre);
}

TEST(UnitLength, Stream) {
  std::ostringstream stream;
  stream << Length::Metre;
  EXPECT_EQ(stream.str(), Abbreviation(Length::Metre));
}

}  // namespace

}  // namespace PhQ::Unit
