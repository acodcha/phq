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

#ifndef PHYSICAL_QUANTITIES_TEST_UNIT_HPP
#define PHYSICAL_QUANTITIES_TEST_UNIT_HPP

#include <gtest/gtest.h>

#include "../include/PhQ/Dyad.hpp"
#include "../include/PhQ/SymmetricDyad.hpp"
#include "../include/PhQ/Unit.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ::Internal {

// Tests the PhQ::Convert and PhQ::ConvertCopy unit conversion functions for a given unit of
// measure. Verifies that a given original value expressed in a given original unit correctly
// converts to a given new value expressed in a given new unit.
template <typename Unit>
void TestConversions(const Unit original_unit, const Unit new_unit, const double original_value,
                     const double new_value) {
  {
    double converted_value = original_value;
    Convert(converted_value, original_unit, new_unit);
    EXPECT_DOUBLE_EQ(converted_value, new_value);
  }

  {
    const double copied_converted_value = ConvertCopy(original_value, original_unit, new_unit);
    EXPECT_DOUBLE_EQ(copied_converted_value, new_value);
  }

  {
    std::array<double, 3> converted_array{original_value, original_value, original_value};
    Convert(converted_array, original_unit, new_unit);
    EXPECT_DOUBLE_EQ(converted_array[0], new_value);
    EXPECT_DOUBLE_EQ(converted_array[1], new_value);
    EXPECT_DOUBLE_EQ(converted_array[2], new_value);
  }

  {
    const std::array<double, 3> copied_converted_array =
        ConvertCopy(std::array<double, 3>{original_value, original_value, original_value},
                    original_unit, new_unit);
    EXPECT_DOUBLE_EQ(copied_converted_array[0], new_value);
    EXPECT_DOUBLE_EQ(copied_converted_array[1], new_value);
    EXPECT_DOUBLE_EQ(copied_converted_array[2], new_value);
  }

  {
    std::vector<double> converted_std_vector{original_value, original_value, original_value};
    Convert(converted_std_vector, original_unit, new_unit);
    EXPECT_DOUBLE_EQ(converted_std_vector[0], new_value);
    EXPECT_DOUBLE_EQ(converted_std_vector[1], new_value);
    EXPECT_DOUBLE_EQ(converted_std_vector[2], new_value);
  }

  {
    const std::vector<double> copied_converted_std_vector =
        ConvertCopy(std::vector<double>{original_value, original_value, original_value},
                    original_unit, new_unit);
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[0], new_value);
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[1], new_value);
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[2], new_value);
  }

  {
    Vector converted_vector{original_value, original_value, original_value};
    Convert(converted_vector, original_unit, new_unit);
    EXPECT_DOUBLE_EQ(converted_vector.x(), new_value);
    EXPECT_DOUBLE_EQ(converted_vector.y(), new_value);
    EXPECT_DOUBLE_EQ(converted_vector.z(), new_value);
  }

  {
    const Vector copied_converted_vector = ConvertCopy(
        Vector{original_value, original_value, original_value}, original_unit, new_unit);
    EXPECT_DOUBLE_EQ(copied_converted_vector.x(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_vector.y(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_vector.z(), new_value);
  }

  {
    SymmetricDyad converted_symmetric_dyad{original_value, original_value, original_value,
                                           original_value, original_value, original_value};
    Convert(converted_symmetric_dyad, original_unit, new_unit);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), new_value);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), new_value);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), new_value);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), new_value);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), new_value);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), new_value);
  }

  {
    const SymmetricDyad copied_converted_symmetric_dyad = ConvertCopy(
        SymmetricDyad{original_value, original_value, original_value, original_value,
                      original_value, original_value},
        original_unit, new_unit);
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xx(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xy(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xz(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yy(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yz(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.zz(), new_value);
  }

  {
    Dyad converted_dyad{
        original_value, original_value, original_value, original_value, original_value,
        original_value, original_value, original_value, original_value};
    Convert(converted_dyad, original_unit, new_unit);
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), new_value);
  }

  {
    const Dyad copied_converted_dyad = ConvertCopy(
        Dyad{original_value, original_value, original_value, original_value, original_value,
             original_value, original_value, original_value, original_value},
        original_unit, new_unit);
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xx(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xy(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xz(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yx(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yy(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yz(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zx(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zy(), new_value);
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zz(), new_value);
  }
}

// Tests the PhQ::StaticConvertCopy unit conversion functions for a given unit of measure. Verifies
// that a given original value expressed in a given original unit correctly converts to a given new
// value expressed in a given new unit.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
void TestStaticConversions(const double original_value, const double new_value) {
  {
    const double converted_value = StaticConvertCopy<Unit, OriginalUnit, NewUnit>(original_value);
    EXPECT_DOUBLE_EQ(converted_value, new_value);
  }

  {
    const std::array<double, 3> converted_array = StaticConvertCopy<Unit, OriginalUnit, NewUnit>(
        std::array<double, 3>{original_value, original_value, original_value});
    EXPECT_DOUBLE_EQ(converted_array[0], new_value);
    EXPECT_DOUBLE_EQ(converted_array[1], new_value);
    EXPECT_DOUBLE_EQ(converted_array[2], new_value);
  }

  {
    const Vector converted_vector = StaticConvertCopy<Unit, OriginalUnit, NewUnit>(
        Vector{original_value, original_value, original_value});
    EXPECT_DOUBLE_EQ(converted_vector.x(), new_value);
    EXPECT_DOUBLE_EQ(converted_vector.y(), new_value);
    EXPECT_DOUBLE_EQ(converted_vector.z(), new_value);
  }

  {
    const SymmetricDyad converted_symmetric_dyad = StaticConvertCopy<Unit, OriginalUnit, NewUnit>(
        SymmetricDyad{original_value, original_value, original_value, original_value,
                      original_value, original_value});
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), new_value);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), new_value);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), new_value);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), new_value);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), new_value);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), new_value);
  }

  {
    const Dyad converted_dyad = StaticConvertCopy<Unit, OriginalUnit, NewUnit>(
        Dyad{original_value, original_value, original_value, original_value, original_value,
             original_value, original_value, original_value, original_value});
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), new_value);
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), new_value);
  }
}

}  // namespace PhQ::Internal

#endif  // PHYSICAL_QUANTITIES_TEST_UNIT_HPP
