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

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Time, 3> Units = {
    Time::Second,
    Time::Minute,
    Time::Hour,
};

TEST(UnitTime, Abbreviation) {
  EXPECT_EQ(Abbreviation(Time::Second), "s");
  EXPECT_EQ(Abbreviation(Time::Minute), "min");
  EXPECT_EQ(Abbreviation(Time::Hour), "hr");
}

TEST(UnitTime, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Time>(UnitSystem::MetreKilogramSecondKelvin),
            Time::Second);
  EXPECT_EQ(ConsistentUnit<Time>(UnitSystem::MillimetreGramSecondKelvin),
            Time::Second);
  EXPECT_EQ(ConsistentUnit<Time>(UnitSystem::FootPoundSecondRankine),
            Time::Second);
  EXPECT_EQ(ConsistentUnit<Time>(UnitSystem::InchPoundSecondRankine),
            Time::Second);
}

TEST(UnitTime, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Time::Second, Time::Second), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Time::Second, Time::Minute),
                   value / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Time::Second, Time::Hour),
                   value / 3600.0);
}

TEST(UnitTime, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Time::Second, Time::Second), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Time::Minute, Time::Second),
                   value * 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Time::Hour, Time::Second),
                   value * 3600.0);
}

TEST(UnitTime, ConvertVerification) {
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

TEST(UnitTime, DimensionSet) {
  EXPECT_EQ(Dimensions<Time>, Dimension::Set(Dimension::Time{1}));
}

TEST(UnitTime, Parse) {
  EXPECT_EQ(Parse<Time>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Time>("s"), Time::Second);
  EXPECT_EQ(Parse<Time>("min"), Time::Minute);
  EXPECT_EQ(Parse<Time>("hr"), Time::Hour);
}

TEST(UnitTime, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Time::Second), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Time::Minute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Time::Hour), std::nullopt);
}

TEST(UnitTime, StandardUnit) { EXPECT_EQ(StandardUnit<Time>, Time::Second); }

}  // namespace

}  // namespace PhQ::Unit
