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

#ifndef PHYSICAL_QUANTITIES_TEST_UNIT_HPP
#define PHYSICAL_QUANTITIES_TEST_UNIT_HPP

#include <gtest/gtest.h>

#include "../include/PhQ/Dyad.hpp"
#include "../include/PhQ/SymmetricDyad.hpp"
#include "../include/PhQ/Unit.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ::Internal {

// Tests that the unit conversion functions are reciprocal for a given unit of measure; that is,
// tests that converting a value in a given unit to an intermediary unit and then converting back to
// its original unit produces the original value. Due to the finiteness of floating point precision,
// information regarding the unit in the last precision (ULP) may be lost in the process, so the
// returned value may be within a few ULPs of the original.
template <typename Unit>
void TestConversionReciprocity(
    const Unit original_unit, const Unit intermediary_unit, const long double original_value) {
  {
    float converted_value{static_cast<float>(original_value)};
    Convert(converted_value, original_unit, intermediary_unit);
    Convert(converted_value, intermediary_unit, original_unit);
    EXPECT_FLOAT_EQ(converted_value, original_value);
  }
  {
    double converted_value{static_cast<double>(original_value)};
    Convert(converted_value, original_unit, intermediary_unit);
    Convert(converted_value, intermediary_unit, original_unit);
    EXPECT_DOUBLE_EQ(converted_value, original_value);
  }
  {
    long double converted_value{original_value};
    Convert(converted_value, original_unit, intermediary_unit);
    Convert(converted_value, intermediary_unit, original_unit);
    EXPECT_DOUBLE_EQ(converted_value, original_value);
  }
}

// Tests the PhQ::Convert, PhQ::ConvertCopy, and PhQ::StaticConvertCopy unit conversion functions
// for a given unit of measure. Verifies that a given original value expressed in a given original
// unit correctly converts to a given new value expressed in a given new unit.
template <typename Unit, Unit OriginalUnit, Unit NewUnit>
void TestConversions(const long double original_value, const long double new_value) {
  // Convert a single value.
  {
    float converted_value{static_cast<float>(original_value)};
    Convert(converted_value, OriginalUnit, NewUnit);
    EXPECT_FLOAT_EQ(converted_value, static_cast<float>(new_value));
  }
  {
    double converted_value{static_cast<double>(original_value)};
    Convert(converted_value, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_value, static_cast<double>(new_value));
  }
  {
    long double converted_value{static_cast<long double>(original_value)};
    Convert(converted_value, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_value, static_cast<long double>(new_value));
  }

  // ConvertCopy a single value.
  {
    const float copied_converted_value{
        ConvertCopy(static_cast<float>(original_value), OriginalUnit, NewUnit)};
    EXPECT_FLOAT_EQ(copied_converted_value, static_cast<float>(new_value));
  }
  {
    const double copied_converted_value{
        ConvertCopy(static_cast<double>(original_value), OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_value, static_cast<double>(new_value));
  }
  {
    const long double copied_converted_value{
        ConvertCopy(static_cast<long double>(original_value), OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_value, static_cast<long double>(new_value));
  }

  // StaticConvertCopy a single value.
  {
    const float converted_value{
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(static_cast<float>(original_value))};
    EXPECT_FLOAT_EQ(converted_value, static_cast<float>(new_value));
  }
  {
    const double converted_value{
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(static_cast<double>(original_value))};
    EXPECT_DOUBLE_EQ(converted_value, static_cast<double>(new_value));
  }
  {
    const long double converted_value{
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(static_cast<long double>(original_value))};
    EXPECT_DOUBLE_EQ(converted_value, static_cast<long double>(new_value));
  }

  // Convert a std::array.
  {
    std::array<float, 3> converted_array{
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value)};
    Convert(converted_array, OriginalUnit, NewUnit);
    EXPECT_FLOAT_EQ(converted_array[0], static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_array[1], static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_array[2], static_cast<float>(new_value));
  }
  {
    std::array<double, 3> converted_array{
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value)};
    Convert(converted_array, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<double>(new_value));
  }
  {
    std::array<long double, 3> converted_array{
        static_cast<long double>(original_value), static_cast<long double>(original_value),
        static_cast<long double>(original_value)};
    Convert(converted_array, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<long double>(new_value));
  }

  // ConvertCopy a std::array.
  {
    const std::array<float, 3> copied_converted_array{ConvertCopy(
        std::array<float, 3>{static_cast<float>(original_value), static_cast<float>(original_value),
                             static_cast<float>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_FLOAT_EQ(copied_converted_array[0], static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_array[1], static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_array[2], static_cast<float>(new_value));
  }
  {
    const std::array<double, 3> copied_converted_array{ConvertCopy(
        std::array<double, 3>{
            static_cast<double>(original_value), static_cast<double>(original_value),
            static_cast<double>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_array[0], static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[1], static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[2], static_cast<double>(new_value));
  }
  {
    const std::array<long double, 3> copied_converted_array{ConvertCopy(
        std::array<long double, 3>{
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_array[0], static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[1], static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[2], static_cast<long double>(new_value));
  }

  // StaticConvertCopy a std::array.
  {
    const std::array<float, 3> converted_array{StaticConvertCopy<Unit, OriginalUnit, NewUnit>(
        std::array<float, 3>{static_cast<float>(original_value), static_cast<float>(original_value),
                             static_cast<float>(original_value)})};
    EXPECT_FLOAT_EQ(converted_array[0], static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_array[1], static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_array[2], static_cast<float>(new_value));
  }
  {
    const std::array<double, 3> converted_array{
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(std::array<double, 3>{
            static_cast<double>(original_value), static_cast<double>(original_value),
            static_cast<double>(original_value)})};
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<double>(new_value));
  }
  {
    const std::array<long double, 3> converted_array{
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(std::array<long double, 3>{
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value)})};
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<long double>(new_value));
  }

  // Convert a std::vector.
  {
    std::vector<float> converted_std_vector{
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value)};
    Convert(converted_std_vector, OriginalUnit, NewUnit);
    EXPECT_FLOAT_EQ(converted_std_vector[0], static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_std_vector[1], static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_std_vector[2], static_cast<float>(new_value));
  }
  {
    std::vector<double> converted_std_vector{
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value)};
    Convert(converted_std_vector, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_std_vector[0], static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[1], static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[2], static_cast<double>(new_value));
  }
  {
    std::vector<long double> converted_std_vector{
        static_cast<long double>(original_value), static_cast<long double>(original_value),
        static_cast<long double>(original_value)};
    Convert(converted_std_vector, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_std_vector[0], static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[1], static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[2], static_cast<long double>(new_value));
  }

  // ConvertCopy a std::vector.
  {
    const std::vector<float> copied_converted_std_vector{ConvertCopy(
        std::vector<float>{static_cast<float>(original_value), static_cast<float>(original_value),
                           static_cast<float>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_FLOAT_EQ(copied_converted_std_vector[0], static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_std_vector[1], static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_std_vector[2], static_cast<float>(new_value));
  }
  {
    const std::vector<double> copied_converted_std_vector{ConvertCopy(
        std::vector<double>{
            static_cast<double>(original_value), static_cast<double>(original_value),
            static_cast<double>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[0], static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[1], static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[2], static_cast<double>(new_value));
  }
  {
    const std::vector<long double> copied_converted_std_vector{ConvertCopy(
        std::vector<long double>{
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[0], static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[1], static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[2], static_cast<long double>(new_value));
  }

  // Convert a PhQ::Vector.
  {
    Vector<float> converted_vector{
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value)};
    Convert(converted_vector, OriginalUnit, NewUnit);
    EXPECT_FLOAT_EQ(converted_vector.x(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_vector.y(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_vector.z(), static_cast<float>(new_value));
  }
  {
    Vector<double> converted_vector{
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value)};
    Convert(converted_vector, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<double>(new_value));
  }
  {
    Vector<long double> converted_vector{
        static_cast<long double>(original_value), static_cast<long double>(original_value),
        static_cast<long double>(original_value)};
    Convert(converted_vector, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<long double>(new_value));
  }

  // ConvertCopy a PhQ::Vector.
  {
    const Vector<float> copied_converted_vector{ConvertCopy(
        Vector<float>{static_cast<float>(original_value), static_cast<float>(original_value),
                      static_cast<float>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_FLOAT_EQ(copied_converted_vector.x(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_vector.y(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_vector.z(), static_cast<float>(new_value));
  }
  {
    const Vector<double> copied_converted_vector{ConvertCopy(
        Vector<double>{static_cast<double>(original_value), static_cast<double>(original_value),
                       static_cast<double>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_vector.x(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.y(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.z(), static_cast<double>(new_value));
  }
  {
    const Vector<long double> copied_converted_vector{ConvertCopy(
        Vector<long double>{
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_vector.x(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.y(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.z(), static_cast<long double>(new_value));
  }

  // StaticConvertCopy a PhQ::Vector.
  {
    const Vector<float> converted_vector{StaticConvertCopy<Unit, OriginalUnit, NewUnit>(
        Vector<float>{static_cast<float>(original_value), static_cast<float>(original_value),
                      static_cast<float>(original_value)})};
    EXPECT_FLOAT_EQ(converted_vector.x(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_vector.y(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_vector.z(), static_cast<float>(new_value));
  }
  {
    const Vector<double> converted_vector{StaticConvertCopy<Unit, OriginalUnit, NewUnit>(
        Vector<double>{static_cast<double>(original_value), static_cast<double>(original_value),
                       static_cast<double>(original_value)})};
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<double>(new_value));
  }
  {
    const Vector<long double> converted_vector{
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(Vector<long double>{
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value)})};
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<long double>(new_value));
  }

  // Convert a PhQ::SymmetricDyad.
  {
    SymmetricDyad<float> converted_symmetric_dyad{
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value), static_cast<float>(original_value)};
    Convert(converted_symmetric_dyad, OriginalUnit, NewUnit);
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.zz(), static_cast<float>(new_value));
  }
  {
    SymmetricDyad<double> converted_symmetric_dyad{
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value), static_cast<double>(original_value)};
    Convert(converted_symmetric_dyad, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<double>(new_value));
  }
  {
    SymmetricDyad<long double> converted_symmetric_dyad{
        static_cast<long double>(original_value), static_cast<long double>(original_value),
        static_cast<long double>(original_value), static_cast<long double>(original_value),
        static_cast<long double>(original_value), static_cast<long double>(original_value)};
    Convert(converted_symmetric_dyad, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<long double>(new_value));
  }

  // ConvertCopy a PhQ::SymmetricDyad.
  {
    const SymmetricDyad<float> copied_converted_symmetric_dyad{ConvertCopy(
        SymmetricDyad<float>{
            static_cast<float>(original_value), static_cast<float>(original_value),
            static_cast<float>(original_value), static_cast<float>(original_value),
            static_cast<float>(original_value), static_cast<float>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.xx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.xy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.xz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.yy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.yz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.zz(), static_cast<float>(new_value));
  }
  {
    const SymmetricDyad<double> copied_converted_symmetric_dyad{ConvertCopy(
        SymmetricDyad<double>{
            static_cast<double>(original_value), static_cast<double>(original_value),
            static_cast<double>(original_value), static_cast<double>(original_value),
            static_cast<double>(original_value), static_cast<double>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.zz(), static_cast<double>(new_value));
  }
  {
    const SymmetricDyad<long double> copied_converted_symmetric_dyad{ConvertCopy(
        SymmetricDyad<long double>{
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value), static_cast<long double>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.zz(), static_cast<long double>(new_value));
  }

  // StaticConvertCopy a PhQ::SymmetricDyad.
  {
    const SymmetricDyad<float> converted_symmetric_dyad{
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(SymmetricDyad<float>{
            static_cast<float>(original_value), static_cast<float>(original_value),
            static_cast<float>(original_value), static_cast<float>(original_value),
            static_cast<float>(original_value), static_cast<float>(original_value)})};
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.zz(), static_cast<float>(new_value));
  }
  {
    const SymmetricDyad<double> converted_symmetric_dyad{
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(SymmetricDyad<double>{
            static_cast<double>(original_value), static_cast<double>(original_value),
            static_cast<double>(original_value), static_cast<double>(original_value),
            static_cast<double>(original_value), static_cast<double>(original_value)})};
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<double>(new_value));
  }
  {
    const SymmetricDyad<long double> converted_symmetric_dyad{
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(SymmetricDyad<long double>{
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value), static_cast<long double>(original_value)})};
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<long double>(new_value));
  }

  // Convert a PhQ::Dyad.
  {
    Dyad<float> converted_dyad{
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value)};
    Convert(converted_dyad, OriginalUnit, NewUnit);
    EXPECT_FLOAT_EQ(converted_dyad.xx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.xy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.xz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.yx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.yy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.yz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.zx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.zy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.zz(), static_cast<float>(new_value));
  }
  {
    Dyad<double> converted_dyad{
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value)};
    Convert(converted_dyad, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<double>(new_value));
  }
  {
    Dyad<long double> converted_dyad{
        static_cast<long double>(original_value), static_cast<long double>(original_value),
        static_cast<long double>(original_value), static_cast<long double>(original_value),
        static_cast<long double>(original_value), static_cast<long double>(original_value),
        static_cast<long double>(original_value), static_cast<long double>(original_value),
        static_cast<long double>(original_value)};
    Convert(converted_dyad, OriginalUnit, NewUnit);
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<long double>(new_value));
  }

  // ConvertCopy a PhQ::Dyad.
  {
    const Dyad<float> copied_converted_dyad{ConvertCopy(
        Dyad<float>{static_cast<float>(original_value), static_cast<float>(original_value),
                    static_cast<float>(original_value), static_cast<float>(original_value),
                    static_cast<float>(original_value), static_cast<float>(original_value),
                    static_cast<float>(original_value), static_cast<float>(original_value),
                    static_cast<float>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_FLOAT_EQ(copied_converted_dyad.xx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.xy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.xz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.yx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.yy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.yz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.zx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.zy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.zz(), static_cast<float>(new_value));
  }
  {
    const Dyad<double> copied_converted_dyad{ConvertCopy(
        Dyad<double>{static_cast<double>(original_value), static_cast<double>(original_value),
                     static_cast<double>(original_value), static_cast<double>(original_value),
                     static_cast<double>(original_value), static_cast<double>(original_value),
                     static_cast<double>(original_value), static_cast<double>(original_value),
                     static_cast<double>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zz(), static_cast<double>(new_value));
  }
  {
    const Dyad<long double> copied_converted_dyad{ConvertCopy(
        Dyad<long double>{
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value)},
        OriginalUnit, NewUnit)};
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zz(), static_cast<long double>(new_value));
  }

  // StaticConvertCopy a PhQ::Dyad.
  {
    const Dyad<float> converted_dyad{StaticConvertCopy<Unit, OriginalUnit, NewUnit>(Dyad<float>{
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value), static_cast<float>(original_value),
        static_cast<float>(original_value)})};
    EXPECT_FLOAT_EQ(converted_dyad.xx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.xy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.xz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.yx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.yy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.yz(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.zx(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.zy(), static_cast<float>(new_value));
    EXPECT_FLOAT_EQ(converted_dyad.zz(), static_cast<float>(new_value));
  }
  {
    const Dyad<double> converted_dyad{StaticConvertCopy<Unit, OriginalUnit, NewUnit>(Dyad<double>{
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value), static_cast<double>(original_value),
        static_cast<double>(original_value)})};
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<double>(new_value));
  }
  {
    const Dyad<long double> converted_dyad{
        StaticConvertCopy<Unit, OriginalUnit, NewUnit>(Dyad<long double>{
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value), static_cast<long double>(original_value),
            static_cast<long double>(original_value)})};
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<long double>(new_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<long double>(new_value));
  }
}

}  // namespace PhQ::Internal

#endif  // PHYSICAL_QUANTITIES_TEST_UNIT_HPP
