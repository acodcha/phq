// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#include "../../include/PhQ/Unit/Time.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Time, 6> Units = {
    Time::Nanosecond, Time::Microsecond, Time::Millisecond, Time::Second, Time::Minute, Time::Hour,
};

TEST(UnitTime, Abbreviation) {
  EXPECT_EQ(Abbreviation(Time::Nanosecond), "ns");
  EXPECT_EQ(Abbreviation(Time::Microsecond), "μs");
  EXPECT_EQ(Abbreviation(Time::Millisecond), "ms");
  EXPECT_EQ(Abbreviation(Time::Second), "s");
  EXPECT_EQ(Abbreviation(Time::Minute), "min");
  EXPECT_EQ(Abbreviation(Time::Hour), "hr");
}

TEST(UnitTime, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Time>(UnitSystem::MetreKilogramSecondKelvin), Time::Second);
  EXPECT_EQ(ConsistentUnit<Time>(UnitSystem::MillimetreGramSecondKelvin), Time::Second);
  EXPECT_EQ(ConsistentUnit<Time>(UnitSystem::FootPoundSecondRankine), Time::Second);
  EXPECT_EQ(ConsistentUnit<Time>(UnitSystem::InchPoundSecondRankine), Time::Second);
}

TEST(UnitTime, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const Time original_unit : Units) {
    for (const Time intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitTime, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};
  Internal::TestConversions<Time, Time::Second, Time::Nanosecond>(value, value * 1000000000.0);
  Internal::TestConversions<Time, Time::Second, Time::Microsecond>(value, value * 1000000.0);
  Internal::TestConversions<Time, Time::Second, Time::Millisecond>(value, value * 1000.0);
  Internal::TestConversions<Time, Time::Second, Time::Second>(value, value);
  Internal::TestConversions<Time, Time::Second, Time::Minute>(value, value / 60.0);
  Internal::TestConversions<Time, Time::Second, Time::Hour>(value, value / 3600.0);
}

TEST(UnitTime, ConvertToStandard) {
  constexpr double value{1.234567890123456789};
  Internal::TestConversions<Time, Time::Nanosecond, Time::Second>(value, value * 0.000000001);
  Internal::TestConversions<Time, Time::Microsecond, Time::Second>(value, value * 0.000001);
  Internal::TestConversions<Time, Time::Millisecond, Time::Second>(value, value * 0.001);
  Internal::TestConversions<Time, Time::Second, Time::Second>(value, value);
  Internal::TestConversions<Time, Time::Minute, Time::Second>(value, value * 60.0);
  Internal::TestConversions<Time, Time::Hour, Time::Second>(value, value * 3600.0);
}

TEST(UnitTime, Parse) {
  EXPECT_EQ(Parse<Time>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Time>("ns"), Time::Nanosecond);
  EXPECT_EQ(Parse<Time>("μs"), Time::Microsecond);
  EXPECT_EQ(Parse<Time>("ms"), Time::Millisecond);
  EXPECT_EQ(Parse<Time>("s"), Time::Second);
  EXPECT_EQ(Parse<Time>("min"), Time::Minute);
  EXPECT_EQ(Parse<Time>("hr"), Time::Hour);
}

TEST(UnitTime, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Time>, Dimensions(Dimension::Time{1}));
}

TEST(UnitTime, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Time::Nanosecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Time::Microsecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Time::Millisecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Time::Second), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Time::Minute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Time::Hour), std::nullopt);
}

TEST(UnitTime, Standard) {
  EXPECT_EQ(Standard<Time>, Time::Second);
}

TEST(UnitTime, Stream) {
  std::ostringstream stream;
  stream << Time::Second;
  EXPECT_EQ(stream.str(), Abbreviation(Time::Second));
}

}  // namespace

}  // namespace PhQ::Unit
