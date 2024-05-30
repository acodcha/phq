// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
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

TEST(UnitTime, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<Time>(
      Time::Second, Time::Nanosecond, value, value * 1000000000.0L);
  Internal::TestConvertAndConvertCopy<Time>(
      Time::Second, Time::Microsecond, value, value * 1000000.0L);
  Internal::TestConvertAndConvertCopy<Time>(
      Time::Second, Time::Millisecond, value, value * 1000.0L);
  Internal::TestConvertAndConvertCopy<Time>(Time::Second, Time::Second, value, value);
  Internal::TestConvertAndConvertCopy<Time>(Time::Second, Time::Minute, value, value / 60.0L);
  Internal::TestConvertAndConvertCopy<Time>(Time::Second, Time::Hour, value, value / 3600.0L);
}

TEST(UnitTime, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Time>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Time>("ns"), Time::Nanosecond);
  EXPECT_EQ(ParseEnumeration<Time>("μs"), Time::Microsecond);
  EXPECT_EQ(ParseEnumeration<Time>("ms"), Time::Millisecond);
  EXPECT_EQ(ParseEnumeration<Time>("s"), Time::Second);
  EXPECT_EQ(ParseEnumeration<Time>("min"), Time::Minute);
  EXPECT_EQ(ParseEnumeration<Time>("hr"), Time::Hour);
}

TEST(UnitTime, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Time>,
            Dimensions(Dimension::Time{1}, Dimension::Length{0}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
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

TEST(UnitTime, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Time, Time::Second, Time::Hour>(value, value / 3600.0L);
}

TEST(UnitTime, Stream) {
  std::ostringstream stream;
  stream << Time::Second;
  EXPECT_EQ(stream.str(), Abbreviation(Time::Second));
}

}  // namespace

}  // namespace PhQ::Unit
