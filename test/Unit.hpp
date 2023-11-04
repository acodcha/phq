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

// Tests single-value unit conversion functions. Verifies that a given original
// value expressed in a given original unit correctly converts to a given new
// value expressed in a given new unit.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
void TestUnitConversionSingle(
    const double original_value, const double reference_value) {
  {
    double new_value = original_value;
    PhQ::Convert(new_value, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(new_value, reference_value);
  }

  {
    const double new_value =
        PhQ::ConvertCopy(original_value, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(new_value, reference_value);
  }

  {
    double new_value = original_value;
    PhQ::StaticConvert<Unit, OriginalUnit, NewUnit>(new_value);
    EXPECT_DOUBLE_EQ(new_value, reference_value);
  }

  {
    const double new_value =
        PhQ::StaticConvertCopy<Unit, OriginalUnit, NewUnit>(original_value);
    EXPECT_DOUBLE_EQ(new_value, reference_value);
  }
}

// Tests unit conversion functions for std::array. Verifies that an array
// composed of repeated original values expressed in a given original unit
// correctly converts to an array composed of repeated new values expressed in a
// given new unit.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
void TestUnitConversionArray(
    const double original_value, const double reference_value) {
  const std::array<double, 4> original_values{
      original_value, original_value, original_value, original_value};

  const std::array<double, 4> reference_values{
      reference_value, reference_value, reference_value, reference_value};

  {
    std::array<double, 4> new_values = original_values;
    PhQ::Convert(new_values, OriginalUnit, NewUnit);
    for (std::size_t index = 0; index < 4; ++index) {
      EXPECT_DOUBLE_EQ(new_values[index], reference_values[index]);
    }
  }

  {
    const std::array<double, 4> new_values =
        PhQ::ConvertCopy(original_values, OriginalUnit, NewUnit);
    for (std::size_t index = 0; index < 4; ++index) {
      EXPECT_DOUBLE_EQ(new_values[index], reference_values[index]);
    }
  }

  {
    std::array<double, 4> new_values = original_values;
    PhQ::StaticConvert<Unit, OriginalUnit, NewUnit>(new_values);
    for (std::size_t index = 0; index < 4; ++index) {
      EXPECT_DOUBLE_EQ(new_values[index], reference_values[index]);
    }
  }

  {
    const std::array<double, 4> new_values =
        PhQ::StaticConvertCopy<Unit, OriginalUnit, NewUnit>(original_values);
    for (std::size_t index = 0; index < 4; ++index) {
      EXPECT_DOUBLE_EQ(new_values[index], reference_values[index]);
    }
  }
}

// Tests unit conversion functions for std::vector. Verifies that a vector
// composed of repeated original values expressed in a given original unit
// correctly converts to a vector composed of repeated new values expressed in a
// given new unit.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
void TestUnitConversionVector(
    const double original_value, const double reference_value) {
  const std::vector<double> original_values{
      original_value, original_value, original_value, original_value};

  const std::vector<double> reference_values{
      reference_value, reference_value, reference_value, reference_value};

  {
    std::vector<double> new_values = original_values;
    PhQ::Convert(new_values, OriginalUnit, NewUnit);
    for (std::size_t index = 0; index < 4; ++index) {
      EXPECT_DOUBLE_EQ(new_values[index], reference_values[index]);
    }
  }

  {
    const std::vector<double> new_values =
        PhQ::ConvertCopy(original_values, OriginalUnit, NewUnit);
    for (std::size_t index = 0; index < 4; ++index) {
      EXPECT_DOUBLE_EQ(new_values[index], reference_values[index]);
    }
  }
}

// Tests unit conversion functions for three-dimensional Cartesian vector
// values. Verifies that a vector composed of repeated original values expressed
// in a given original unit correctly converts to a vector composed of repeated
// new values expressed in a given new unit.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
void TestUnitConversionValueVector(
    const double original_value, const double reference_value) {
  const PhQ::Value::Vector original_values{
      original_value, original_value, original_value};

  const PhQ::Value::Vector reference_values{
      reference_value, reference_value, reference_value};

  {
    PhQ::Value::Vector new_values = original_values;
    PhQ::Convert(new_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(new_values.x(), reference_values.x());
    EXPECT_DOUBLE_EQ(new_values.y(), reference_values.y());
    EXPECT_DOUBLE_EQ(new_values.z(), reference_values.z());
  }

  {
    const PhQ::Value::Vector new_values =
        PhQ::ConvertCopy(original_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(new_values.x(), reference_values.x());
    EXPECT_DOUBLE_EQ(new_values.y(), reference_values.y());
    EXPECT_DOUBLE_EQ(new_values.z(), reference_values.z());
  }

  {
    PhQ::Value::Vector new_values = original_values;
    PhQ::StaticConvert<Unit, OriginalUnit, NewUnit>(new_values);
    EXPECT_DOUBLE_EQ(new_values.x(), reference_values.x());
    EXPECT_DOUBLE_EQ(new_values.y(), reference_values.y());
    EXPECT_DOUBLE_EQ(new_values.z(), reference_values.z());
  }

  {
    const PhQ::Value::Vector new_values =
        PhQ::StaticConvertCopy<Unit, OriginalUnit, NewUnit>(original_values);
    EXPECT_DOUBLE_EQ(new_values.x(), reference_values.x());
    EXPECT_DOUBLE_EQ(new_values.y(), reference_values.y());
    EXPECT_DOUBLE_EQ(new_values.z(), reference_values.z());
  }
}

// Tests unit conversion functions for three-dimensional Cartesian symmetric
// dyadic tensor values. Verifies that a symmetric dyadic tensor composed of
// repeated original values expressed in a given original unit correctly
// converts to a symmetric dyadic tensor composed of repeated new values
// expressed in a given new unit.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
void TestUnitConversionValueSymmetricDyad(
    const double original_value, const double reference_value) {
  const PhQ::Value::SymmetricDyad original_values{
      original_value, original_value, original_value,
      original_value, original_value, original_value};

  const PhQ::Value::SymmetricDyad reference_values{
      reference_value, reference_value, reference_value,
      reference_value, reference_value, reference_value};

  {
    PhQ::Value::SymmetricDyad new_values = original_values;
    PhQ::Convert(new_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(new_values.xx(), reference_values.xx());
    EXPECT_DOUBLE_EQ(new_values.xy(), reference_values.xy());
    EXPECT_DOUBLE_EQ(new_values.xz(), reference_values.xz());
    EXPECT_DOUBLE_EQ(new_values.yy(), reference_values.yy());
    EXPECT_DOUBLE_EQ(new_values.yz(), reference_values.yz());
    EXPECT_DOUBLE_EQ(new_values.zz(), reference_values.zz());
  }

  {
    const PhQ::Value::SymmetricDyad new_values =
        PhQ::ConvertCopy(original_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(new_values.xx(), reference_values.xx());
    EXPECT_DOUBLE_EQ(new_values.xy(), reference_values.xy());
    EXPECT_DOUBLE_EQ(new_values.xz(), reference_values.xz());
    EXPECT_DOUBLE_EQ(new_values.yy(), reference_values.yy());
    EXPECT_DOUBLE_EQ(new_values.yz(), reference_values.yz());
    EXPECT_DOUBLE_EQ(new_values.zz(), reference_values.zz());
  }

  {
    PhQ::Value::SymmetricDyad new_values = original_values;
    PhQ::StaticConvert<Unit, OriginalUnit, NewUnit>(new_values);
    EXPECT_DOUBLE_EQ(new_values.xx(), reference_values.xx());
    EXPECT_DOUBLE_EQ(new_values.xy(), reference_values.xy());
    EXPECT_DOUBLE_EQ(new_values.xz(), reference_values.xz());
    EXPECT_DOUBLE_EQ(new_values.yy(), reference_values.yy());
    EXPECT_DOUBLE_EQ(new_values.yz(), reference_values.yz());
    EXPECT_DOUBLE_EQ(new_values.zz(), reference_values.zz());
  }

  {
    const PhQ::Value::SymmetricDyad new_values =
        PhQ::StaticConvertCopy<Unit, OriginalUnit, NewUnit>(original_values);
    EXPECT_DOUBLE_EQ(new_values.xx(), reference_values.xx());
    EXPECT_DOUBLE_EQ(new_values.xy(), reference_values.xy());
    EXPECT_DOUBLE_EQ(new_values.xz(), reference_values.xz());
    EXPECT_DOUBLE_EQ(new_values.yy(), reference_values.yy());
    EXPECT_DOUBLE_EQ(new_values.yz(), reference_values.yz());
    EXPECT_DOUBLE_EQ(new_values.zz(), reference_values.zz());
  }
}

// Tests unit conversion functions for three-dimensional Cartesian dyadic tensor
// values. Verifies that a dyadic tensor composed of repeated original values
// expressed in a given original unit correctly converts to a dyadic tensor
// composed of repeated new values expressed in a given new unit.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
void TestUnitConversionValueDyad(
    const double original_value, const double reference_value) {
  const PhQ::Value::Dyad original_values{
      original_value, original_value, original_value,
      original_value, original_value, original_value,
      original_value, original_value, original_value};

  const PhQ::Value::Dyad reference_values{
      reference_value, reference_value, reference_value,
      reference_value, reference_value, reference_value,
      reference_value, reference_value, reference_value};

  {
    PhQ::Value::Dyad new_values = original_values;
    PhQ::Convert(new_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(new_values.xx(), reference_values.xx());
    EXPECT_DOUBLE_EQ(new_values.xy(), reference_values.xy());
    EXPECT_DOUBLE_EQ(new_values.xz(), reference_values.xz());
    EXPECT_DOUBLE_EQ(new_values.yx(), reference_values.yx());
    EXPECT_DOUBLE_EQ(new_values.yy(), reference_values.yy());
    EXPECT_DOUBLE_EQ(new_values.yz(), reference_values.yz());
    EXPECT_DOUBLE_EQ(new_values.zx(), reference_values.zx());
    EXPECT_DOUBLE_EQ(new_values.zy(), reference_values.zy());
    EXPECT_DOUBLE_EQ(new_values.zz(), reference_values.zz());
  }

  {
    const PhQ::Value::Dyad new_values =
        PhQ::ConvertCopy(original_values, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(new_values.xx(), reference_values.xx());
    EXPECT_DOUBLE_EQ(new_values.xy(), reference_values.xy());
    EXPECT_DOUBLE_EQ(new_values.xz(), reference_values.xz());
    EXPECT_DOUBLE_EQ(new_values.yx(), reference_values.yx());
    EXPECT_DOUBLE_EQ(new_values.yy(), reference_values.yy());
    EXPECT_DOUBLE_EQ(new_values.yz(), reference_values.yz());
    EXPECT_DOUBLE_EQ(new_values.zx(), reference_values.zx());
    EXPECT_DOUBLE_EQ(new_values.zy(), reference_values.zy());
    EXPECT_DOUBLE_EQ(new_values.zz(), reference_values.zz());
  }

  {
    PhQ::Value::Dyad new_values = original_values;
    PhQ::StaticConvert<Unit, OriginalUnit, NewUnit>(new_values);
    EXPECT_DOUBLE_EQ(new_values.xx(), reference_values.xx());
    EXPECT_DOUBLE_EQ(new_values.xy(), reference_values.xy());
    EXPECT_DOUBLE_EQ(new_values.xz(), reference_values.xz());
    EXPECT_DOUBLE_EQ(new_values.yx(), reference_values.yx());
    EXPECT_DOUBLE_EQ(new_values.yy(), reference_values.yy());
    EXPECT_DOUBLE_EQ(new_values.yz(), reference_values.yz());
    EXPECT_DOUBLE_EQ(new_values.zx(), reference_values.zx());
    EXPECT_DOUBLE_EQ(new_values.zy(), reference_values.zy());
    EXPECT_DOUBLE_EQ(new_values.zz(), reference_values.zz());
  }

  {
    const PhQ::Value::Dyad new_values =
        PhQ::StaticConvertCopy<Unit, OriginalUnit, NewUnit>(original_values);
    EXPECT_DOUBLE_EQ(new_values.xx(), reference_values.xx());
    EXPECT_DOUBLE_EQ(new_values.xy(), reference_values.xy());
    EXPECT_DOUBLE_EQ(new_values.xz(), reference_values.xz());
    EXPECT_DOUBLE_EQ(new_values.yx(), reference_values.yx());
    EXPECT_DOUBLE_EQ(new_values.yy(), reference_values.yy());
    EXPECT_DOUBLE_EQ(new_values.yz(), reference_values.yz());
    EXPECT_DOUBLE_EQ(new_values.zx(), reference_values.zx());
    EXPECT_DOUBLE_EQ(new_values.zy(), reference_values.zy());
    EXPECT_DOUBLE_EQ(new_values.zz(), reference_values.zz());
  }
}

// Tests unit conversion functions. Verifies that a given original value
// expressed in a given original unit correctly converts to a given new value
// expressed in a given new unit.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
void TestUnitConversions(const double original_value, const double new_value) {
  PhQ::Internal::TestUnitConversionSingle<Unit, OriginalUnit, NewUnit>(
      original_value, new_value);
  PhQ::Internal::TestUnitConversionArray<Unit, OriginalUnit, NewUnit>(
      original_value, new_value);
  PhQ::Internal::TestUnitConversionVector<Unit, OriginalUnit, NewUnit>(
      original_value, new_value);
  PhQ::Internal::TestUnitConversionValueVector<Unit, OriginalUnit, NewUnit>(
      original_value, new_value);
  PhQ::Internal::TestUnitConversionValueSymmetricDyad<
      Unit, OriginalUnit, NewUnit>(original_value, new_value);
  PhQ::Internal::TestUnitConversionValueDyad<Unit, OriginalUnit, NewUnit>(
      original_value, new_value);
}

}  // namespace PhQ::Internal

#endif  // PHYSICAL_QUANTITIES_TEST_UNIT_HPP
