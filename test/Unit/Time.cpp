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

#include "../../include/PhQ/Unit/Time.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<Time, 6> Units = {
    Time::Nanosecond, Time::Microsecond, Time::Millisecond,
    Time::Second,     Time::Minute,      Time::Hour,
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
  EXPECT_EQ(ConsistentUnit<Time>(UnitSystem::MetreKilogramSecondKelvin),
            Time::Second);
  EXPECT_EQ(ConsistentUnit<Time>(UnitSystem::MillimetreGramSecondKelvin),
            Time::Second);
  EXPECT_EQ(
      ConsistentUnit<Time>(UnitSystem::FootPoundSecondRankine), Time::Second);
  EXPECT_EQ(
      ConsistentUnit<Time>(UnitSystem::InchPoundSecondRankine), Time::Second);
}

TEST(UnitTime, Convert) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Time old_unit : Units) {
    for (const Time new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitTime, ConvertCopy) {
  constexpr double value{10.0};
  constexpr std::array<double, 3> array{10.0, -20.0, 30.0};
  const std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  constexpr Value::Vector value_vector{10.0, -20.0, 30.0};
  constexpr Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  constexpr Value::Dyad dyad{
      10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Time old_unit : Units) {
    for (const Time new_unit : Units) {
      ConvertCopy(value, old_unit, new_unit);
      ConvertCopy(array, old_unit, new_unit);
      ConvertCopy(std_vector, old_unit, new_unit);
      ConvertCopy(value_vector, old_unit, new_unit);
      ConvertCopy(symdyad, old_unit, new_unit);
      ConvertCopy(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitTime, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Time::Second, Time::Nanosecond), value * 1000000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Time::Second, Time::Microsecond), value * 1000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Time::Second, Time::Millisecond), value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Time::Second, Time::Second), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Time::Second, Time::Minute), value / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Time::Second, Time::Hour), value / 3600.0);
}

TEST(UnitTime, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Time::Nanosecond, Time::Second), value * 0.000000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Time::Microsecond, Time::Second), value * 0.000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Time::Millisecond, Time::Second), value * 0.001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Time::Second, Time::Second), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Time::Minute, Time::Second), value * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Time::Hour, Time::Second), value * 3600.0);
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

TEST(UnitTime, Standard) { EXPECT_EQ(Standard<Time>, Time::Second); }

TEST(UnitTime, StaticConvert) {
  double value{10.0};
  StaticConvert<Time, Time::Minute, Time::Millisecond>(value);
  std::array<double, 3> array{10.0, -20.0, 30.0};
  StaticConvert<Time, Time::Minute, Time::Millisecond>(array);
  Value::Vector vector{10.0, -20.0, 30.0};
  StaticConvert<Time, Time::Minute, Time::Millisecond>(vector);
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  StaticConvert<Time, Time::Minute, Time::Millisecond>(symdyad);
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  StaticConvert<Time, Time::Minute, Time::Millisecond>(dyad);
}

TEST(UnitTime, StaticConvertCopy) {
  constexpr double value{10.0};
  StaticConvertCopy<Time, Time::Minute, Time::Millisecond>(value);
  constexpr std::array<double, 3> array{10.0, -20.0, 30.0};
  StaticConvertCopy<Time, Time::Minute, Time::Millisecond>(array);
  constexpr Value::Vector vector{10.0, -20.0, 30.0};
  StaticConvertCopy<Time, Time::Minute, Time::Millisecond>(vector);
  constexpr Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  StaticConvertCopy<Time, Time::Minute, Time::Millisecond>(symdyad);
  constexpr Value::Dyad dyad{
      10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  StaticConvertCopy<Time, Time::Minute, Time::Millisecond>(dyad);
}

}  // namespace

}  // namespace PhQ::Unit
