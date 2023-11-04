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

#ifndef PHYSICAL_QUANTITIES_TEST_UNIT_HPP
#define PHYSICAL_QUANTITIES_TEST_UNIT_HPP

#include <gtest/gtest.h>

#include "../include/PhQ/Unit.hpp"

namespace PhQ::Internal {

// Tests unit conversion functions. Verifies that a given original value
// expressed in a given original unit correctly converts to a given new value
// expressed in a given new unit.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
void TestUnitConversions(const double original_value, const double new_value) {
  // double
  {
    double converted_value = original_value;
    Convert(converted_value, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_value, new_value);

    const double copied_converted_value =
        ConvertCopy(original_value, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(copied_converted_value, new_value);

    const double statically_copied_converted_value =
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(original_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_value, new_value);
  }

  // std::array
  {
    const std::array<double, 3> original_values{
        original_value, original_value, original_value};

    std::array<double, 3> converted_values = original_values;
    Convert(converted_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_values[0], new_value);
    EXPECT_DOUBLE_EQ(converted_values[1], new_value);
    EXPECT_DOUBLE_EQ(converted_values[2], new_value);

    const std::array<double, 3> copied_converted_values =
        ConvertCopy(original_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(copied_converted_values[0], new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values[1], new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values[2], new_value);

    const std::array<double, 3> statically_copied_converted_values =
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(original_values);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values[0], new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values[1], new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values[2], new_value);
  }

  // std::vector
  {
    const std::vector<double> original_values{
        original_value, original_value, original_value};

    std::vector<double> converted_values = original_values;
    Convert(converted_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_values[0], new_value);
    EXPECT_DOUBLE_EQ(converted_values[1], new_value);
    EXPECT_DOUBLE_EQ(converted_values[2], new_value);

    const std::vector<double> copied_converted_values =
        ConvertCopy(original_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(copied_converted_values[0], new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values[1], new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values[2], new_value);
  }

  // Value::Vector
  {
    const Value::Vector original_values{
        original_value, original_value, original_value};

    Value::Vector converted_values = original_values;
    Convert(converted_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_values.x(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.y(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.z(), new_value);

    const Value::Vector copied_converted_values =
        ConvertCopy(original_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(copied_converted_values.x(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.y(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.z(), new_value);

    const Value::Vector statically_copied_converted_values =
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(original_values);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.x(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.y(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.z(), new_value);
  }

  // Value::SymmetricDyad
  {
    const Value::SymmetricDyad original_values{
        original_value, original_value, original_value,
        original_value, original_value, original_value};

    Value::SymmetricDyad converted_values = original_values;
    Convert(converted_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_values.xx(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.xy(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.xz(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.yy(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.yz(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.zz(), new_value);

    const Value::SymmetricDyad copied_converted_values =
        ConvertCopy(original_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(copied_converted_values.xx(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.xy(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.xz(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.yy(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.yz(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.zz(), new_value);

    const Value::SymmetricDyad statically_copied_converted_values =
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(original_values);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.xx(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.xy(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.xz(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.yy(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.yz(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.zz(), new_value);
  }

  // Value::Dyad
  {
    const Value::Dyad original_values{
        original_value, original_value, original_value,
        original_value, original_value, original_value,
        original_value, original_value, original_value};

    Value::Dyad converted_values = original_values;
    Convert(converted_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_values.xx(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.xy(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.xz(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.yx(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.yy(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.yz(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.zx(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.zy(), new_value);
    EXPECT_DOUBLE_EQ(converted_values.zz(), new_value);

    const Value::Dyad copied_converted_values =
        ConvertCopy(original_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(copied_converted_values.xx(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.xy(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.xz(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.yx(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.yy(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.yz(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.zx(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.zy(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_values.zz(), new_value);

    const Value::Dyad statically_copied_converted_values =
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(original_values);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.xx(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.xy(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.xz(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.yx(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.yy(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.yz(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.zx(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.zy(), new_value);
    EXPECT_DOUBLE_EQ(statically_copied_converted_values.zz(), new_value);
  }
}

}  // namespace PhQ::Internal

#endif  // PHYSICAL_QUANTITIES_TEST_UNIT_HPP
