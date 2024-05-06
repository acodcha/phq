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

// Tests the PhQ::Convert and PhQ::ConvertCopy unit conversion functions for a given unit of
// measure. Verifies that a given first value expressed in a given first unit correctly converts to
// a given second value expressed in a given second unit, and vice-versa.
template <typename Unit>
void TestConvertAndConvertCopy(const Unit first_unit, const Unit second_unit,
                               const long double first_value, const long double second_value) {
  // PhQ::Convert(float)
  {
    float converted_value{static_cast<float>(first_value)};
    PhQ::Convert(converted_value, first_unit, second_unit);
    EXPECT_FLOAT_EQ(converted_value, static_cast<float>(second_value));
  }
  {
    float converted_value{static_cast<float>(second_value)};
    PhQ::Convert(converted_value, second_unit, first_unit);
    EXPECT_FLOAT_EQ(converted_value, static_cast<float>(first_value));
  }

  // PhQ::Convert(double)
  {
    double converted_value{static_cast<double>(first_value)};
    PhQ::Convert(converted_value, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_value, static_cast<double>(second_value));
  }
  {
    double converted_value{static_cast<double>(second_value)};
    PhQ::Convert(converted_value, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_value, static_cast<double>(first_value));
  }

  // PhQ::Convert(long double)
  {
    long double converted_value{static_cast<long double>(first_value)};
    PhQ::Convert(converted_value, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_value, static_cast<long double>(second_value));
  }
  {
    long double converted_value{static_cast<long double>(second_value)};
    PhQ::Convert(converted_value, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_value, static_cast<long double>(first_value));
  }

  // PhQ::ConvertCopy(float)
  EXPECT_FLOAT_EQ(PhQ::ConvertCopy(static_cast<float>(first_value), first_unit, second_unit),
                  static_cast<float>(second_value));
  EXPECT_FLOAT_EQ(PhQ::ConvertCopy(static_cast<float>(second_value), second_unit, first_unit),
                  static_cast<float>(first_value));

  // PhQ::ConvertCopy(double)
  EXPECT_DOUBLE_EQ(PhQ::ConvertCopy(static_cast<double>(first_value), first_unit, second_unit),
                   static_cast<double>(second_value));
  EXPECT_DOUBLE_EQ(PhQ::ConvertCopy(static_cast<double>(second_value), second_unit, first_unit),
                   static_cast<double>(first_value));

  // PhQ::ConvertCopy(long double)
  EXPECT_DOUBLE_EQ(PhQ::ConvertCopy(static_cast<long double>(first_value), first_unit, second_unit),
                   static_cast<long double>(second_value));
  EXPECT_DOUBLE_EQ(
      PhQ::ConvertCopy(static_cast<long double>(second_value), second_unit, first_unit),
      static_cast<long double>(first_value));

  // PhQ::Convert(std::array<float>)
  {
    std::array<float, 3> converted_array{
        static_cast<float>(first_value), static_cast<float>(first_value),
        static_cast<float>(first_value)};
    PhQ::Convert(converted_array, first_unit, second_unit);
    EXPECT_FLOAT_EQ(converted_array[0], static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_array[1], static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_array[2], static_cast<float>(second_value));
  }
  {
    std::array<float, 3> converted_array{
        static_cast<float>(second_value), static_cast<float>(second_value),
        static_cast<float>(second_value)};
    PhQ::Convert(converted_array, second_unit, first_unit);
    EXPECT_FLOAT_EQ(converted_array[0], static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_array[1], static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_array[2], static_cast<float>(first_value));
  }

  // PhQ::Convert(std::array<double>)
  {
    std::array<double, 3> converted_array{
        static_cast<double>(first_value), static_cast<double>(first_value),
        static_cast<double>(first_value)};
    PhQ::Convert(converted_array, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<double>(second_value));
  }
  {
    std::array<double, 3> converted_array{
        static_cast<double>(second_value), static_cast<double>(second_value),
        static_cast<double>(second_value)};
    PhQ::Convert(converted_array, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<double>(first_value));
  }

  // PhQ::Convert(std::array<long double>)
  {
    std::array<long double, 3> converted_array{
        static_cast<long double>(first_value), static_cast<long double>(first_value),
        static_cast<long double>(first_value)};
    PhQ::Convert(converted_array, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<long double>(second_value));
  }
  {
    std::array<long double, 3> converted_array{
        static_cast<long double>(second_value), static_cast<long double>(second_value),
        static_cast<long double>(second_value)};
    PhQ::Convert(converted_array, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<long double>(first_value));
  }

  // PhQ::ConvertCopy(std::array<float>)
  {
    const std::array<float, 3> copied_converted_array{PhQ::ConvertCopy(
        std::array<float, 3>{static_cast<float>(first_value), static_cast<float>(first_value),
                             static_cast<float>(first_value)},
        first_unit, second_unit)};
    EXPECT_FLOAT_EQ(copied_converted_array[0], static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_array[1], static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_array[2], static_cast<float>(second_value));
  }
  {
    const std::array<float, 3> copied_converted_array{PhQ::ConvertCopy(
        std::array<float, 3>{static_cast<float>(second_value), static_cast<float>(second_value),
                             static_cast<float>(second_value)},
        second_unit, first_unit)};
    EXPECT_FLOAT_EQ(copied_converted_array[0], static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_array[1], static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_array[2], static_cast<float>(first_value));
  }

  // PhQ::ConvertCopy(std::array<double>)
  {
    const std::array<double, 3> copied_converted_array{PhQ::ConvertCopy(
        std::array<double, 3>{static_cast<double>(first_value), static_cast<double>(first_value),
                              static_cast<double>(first_value)},
        first_unit, second_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_array[0], static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[1], static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[2], static_cast<double>(second_value));
  }
  {
    const std::array<double, 3> copied_converted_array{PhQ::ConvertCopy(
        std::array<double, 3>{static_cast<double>(second_value), static_cast<double>(second_value),
                              static_cast<double>(second_value)},
        second_unit, first_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_array[0], static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[1], static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[2], static_cast<double>(first_value));
  }

  // PhQ::ConvertCopy(std::array<long double>)
  {
    const std::array<long double, 3> copied_converted_array{PhQ::ConvertCopy(
        std::array<long double, 3>{
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value)},
        first_unit, second_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_array[0], static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[1], static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[2], static_cast<long double>(second_value));
  }
  {
    const std::array<long double, 3> copied_converted_array{PhQ::ConvertCopy(
        std::array<long double, 3>{
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value)},
        second_unit, first_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_array[0], static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[1], static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_array[2], static_cast<long double>(first_value));
  }

  // PhQ::Convert(std::vector<float>)
  {
    std::vector<float> converted_std_vector{
        static_cast<float>(first_value), static_cast<float>(first_value),
        static_cast<float>(first_value)};
    PhQ::Convert(converted_std_vector, first_unit, second_unit);
    EXPECT_FLOAT_EQ(converted_std_vector[0], static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_std_vector[1], static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_std_vector[2], static_cast<float>(second_value));
  }
  {
    std::vector<float> converted_std_vector{
        static_cast<float>(second_value), static_cast<float>(second_value),
        static_cast<float>(second_value)};
    PhQ::Convert(converted_std_vector, second_unit, first_unit);
    EXPECT_FLOAT_EQ(converted_std_vector[0], static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_std_vector[1], static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_std_vector[2], static_cast<float>(first_value));
  }

  // PhQ::Convert(std::vector<double>)
  {
    std::vector<double> converted_std_vector{
        static_cast<double>(first_value), static_cast<double>(first_value),
        static_cast<double>(first_value)};
    PhQ::Convert(converted_std_vector, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_std_vector[0], static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[1], static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[2], static_cast<double>(second_value));
  }
  {
    std::vector<double> converted_std_vector{
        static_cast<double>(second_value), static_cast<double>(second_value),
        static_cast<double>(second_value)};
    PhQ::Convert(converted_std_vector, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_std_vector[0], static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[1], static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[2], static_cast<double>(first_value));
  }

  // PhQ::Convert(std::vector<long double>)
  {
    std::vector<long double> converted_std_vector{
        static_cast<long double>(first_value), static_cast<long double>(first_value),
        static_cast<long double>(first_value)};
    PhQ::Convert(converted_std_vector, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_std_vector[0], static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[1], static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[2], static_cast<long double>(second_value));
  }
  {
    std::vector<long double> converted_std_vector{
        static_cast<long double>(second_value), static_cast<long double>(second_value),
        static_cast<long double>(second_value)};
    PhQ::Convert(converted_std_vector, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_std_vector[0], static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[1], static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_std_vector[2], static_cast<long double>(first_value));
  }

  // PhQ::ConvertCopy(std::vector<float>)
  {
    const std::vector<float> copied_converted_std_vector{PhQ::ConvertCopy(
        std::vector<float>{static_cast<float>(first_value), static_cast<float>(first_value),
                           static_cast<float>(first_value)},
        first_unit, second_unit)};
    EXPECT_FLOAT_EQ(copied_converted_std_vector[0], static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_std_vector[1], static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_std_vector[2], static_cast<float>(second_value));
  }
  {
    const std::vector<float> copied_converted_std_vector{PhQ::ConvertCopy(
        std::vector<float>{static_cast<float>(second_value), static_cast<float>(second_value),
                           static_cast<float>(second_value)},
        second_unit, first_unit)};
    EXPECT_FLOAT_EQ(copied_converted_std_vector[0], static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_std_vector[1], static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_std_vector[2], static_cast<float>(first_value));
  }

  // PhQ::ConvertCopy(std::vector<double>)
  {
    const std::vector<double> copied_converted_std_vector{PhQ::ConvertCopy(
        std::vector<double>{static_cast<double>(first_value), static_cast<double>(first_value),
                            static_cast<double>(first_value)},
        first_unit, second_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[0], static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[1], static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[2], static_cast<double>(second_value));
  }
  {
    const std::vector<double> copied_converted_std_vector{PhQ::ConvertCopy(
        std::vector<double>{static_cast<double>(second_value), static_cast<double>(second_value),
                            static_cast<double>(second_value)},
        second_unit, first_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[0], static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[1], static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[2], static_cast<double>(first_value));
  }

  // PhQ::ConvertCopy(std::vector<long double>)
  {
    const std::vector<long double> copied_converted_std_vector{PhQ::ConvertCopy(
        std::vector<long double>{
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value)},
        first_unit, second_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[0], static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[1], static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[2], static_cast<long double>(second_value));
  }
  {
    const std::vector<long double> copied_converted_std_vector{PhQ::ConvertCopy(
        std::vector<long double>{
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value)},
        second_unit, first_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[0], static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[1], static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_std_vector[2], static_cast<long double>(first_value));
  }

  // PhQ::Convert(PhQ::Vector<float>)
  {
    PhQ::Vector<float> converted_vector{
        static_cast<float>(first_value), static_cast<float>(first_value),
        static_cast<float>(first_value)};
    PhQ::Convert(converted_vector, first_unit, second_unit);
    EXPECT_FLOAT_EQ(converted_vector.x(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_vector.y(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_vector.z(), static_cast<float>(second_value));
  }
  {
    PhQ::Vector<float> converted_vector{
        static_cast<float>(second_value), static_cast<float>(second_value),
        static_cast<float>(second_value)};
    PhQ::Convert(converted_vector, second_unit, first_unit);
    EXPECT_FLOAT_EQ(converted_vector.x(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_vector.y(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_vector.z(), static_cast<float>(first_value));
  }

  // PhQ::Convert(PhQ::Vector<double>)
  {
    PhQ::Vector<double> converted_vector{
        static_cast<double>(first_value), static_cast<double>(first_value),
        static_cast<double>(first_value)};
    PhQ::Convert(converted_vector, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<double>(second_value));
  }
  {
    PhQ::Vector<double> converted_vector{
        static_cast<double>(second_value), static_cast<double>(second_value),
        static_cast<double>(second_value)};
    PhQ::Convert(converted_vector, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<double>(first_value));
  }

  // PhQ::Convert(PhQ::Vector<long double>)
  {
    PhQ::Vector<long double> converted_vector{
        static_cast<long double>(first_value), static_cast<long double>(first_value),
        static_cast<long double>(first_value)};
    PhQ::Convert(converted_vector, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<long double>(second_value));
  }
  {
    PhQ::Vector<long double> converted_vector{
        static_cast<long double>(second_value), static_cast<long double>(second_value),
        static_cast<long double>(second_value)};
    PhQ::Convert(converted_vector, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<long double>(first_value));
  }

  // PhQ::ConvertCopy(PhQ::Vector<float>)
  {
    const PhQ::Vector<float> copied_converted_vector{PhQ::ConvertCopy(
        PhQ::Vector<float>{static_cast<float>(first_value), static_cast<float>(first_value),
                           static_cast<float>(first_value)},
        first_unit, second_unit)};
    EXPECT_FLOAT_EQ(copied_converted_vector.x(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_vector.y(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_vector.z(), static_cast<float>(second_value));
  }
  {
    const PhQ::Vector<float> copied_converted_vector{PhQ::ConvertCopy(
        PhQ::Vector<float>{static_cast<float>(second_value), static_cast<float>(second_value),
                           static_cast<float>(second_value)},
        second_unit, first_unit)};
    EXPECT_FLOAT_EQ(copied_converted_vector.x(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_vector.y(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_vector.z(), static_cast<float>(first_value));
  }

  // PhQ::ConvertCopy(PhQ::Vector<double>)
  {
    const PhQ::Vector<double> copied_converted_vector{PhQ::ConvertCopy(
        PhQ::Vector<double>{static_cast<double>(first_value), static_cast<double>(first_value),
                            static_cast<double>(first_value)},
        first_unit, second_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_vector.x(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.y(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.z(), static_cast<double>(second_value));
  }
  {
    const PhQ::Vector<double> copied_converted_vector{PhQ::ConvertCopy(
        PhQ::Vector<double>{static_cast<double>(second_value), static_cast<double>(second_value),
                            static_cast<double>(second_value)},
        second_unit, first_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_vector.x(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.y(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.z(), static_cast<double>(first_value));
  }

  // PhQ::ConvertCopy(PhQ::Vector<long double>)
  {
    const PhQ::Vector<long double> copied_converted_vector{PhQ::ConvertCopy(
        PhQ::Vector<long double>{
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value)},
        first_unit, second_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_vector.x(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.y(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.z(), static_cast<long double>(second_value));
  }
  {
    const PhQ::Vector<long double> copied_converted_vector{PhQ::ConvertCopy(
        PhQ::Vector<long double>{
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value)},
        second_unit, first_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_vector.x(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.y(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_vector.z(), static_cast<long double>(first_value));
  }

  // PhQ::Convert(PhQ::SymmetricDyad<float>)
  {
    PhQ::SymmetricDyad<float> converted_symmetric_dyad{
        static_cast<float>(first_value), static_cast<float>(first_value),
        static_cast<float>(first_value), static_cast<float>(first_value),
        static_cast<float>(first_value), static_cast<float>(first_value)};
    PhQ::Convert(converted_symmetric_dyad, first_unit, second_unit);
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.zz(), static_cast<float>(second_value));
  }
  {
    PhQ::SymmetricDyad<float> converted_symmetric_dyad{
        static_cast<float>(second_value), static_cast<float>(second_value),
        static_cast<float>(second_value), static_cast<float>(second_value),
        static_cast<float>(second_value), static_cast<float>(second_value)};
    PhQ::Convert(converted_symmetric_dyad, second_unit, first_unit);
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.zz(), static_cast<float>(first_value));
  }

  // PhQ::Convert(PhQ::SymmetricDyad<double>)
  {
    PhQ::SymmetricDyad<double> converted_symmetric_dyad{
        static_cast<double>(first_value), static_cast<double>(first_value),
        static_cast<double>(first_value), static_cast<double>(first_value),
        static_cast<double>(first_value), static_cast<double>(first_value)};
    PhQ::Convert(converted_symmetric_dyad, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<double>(second_value));
  }
  {
    PhQ::SymmetricDyad<double> converted_symmetric_dyad{
        static_cast<double>(second_value), static_cast<double>(second_value),
        static_cast<double>(second_value), static_cast<double>(second_value),
        static_cast<double>(second_value), static_cast<double>(second_value)};
    PhQ::Convert(converted_symmetric_dyad, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<double>(first_value));
  }

  // PhQ::Convert(PhQ::SymmetricDyad<long double>)
  {
    PhQ::SymmetricDyad<long double> converted_symmetric_dyad{
        static_cast<long double>(first_value), static_cast<long double>(first_value),
        static_cast<long double>(first_value), static_cast<long double>(first_value),
        static_cast<long double>(first_value), static_cast<long double>(first_value)};
    PhQ::Convert(converted_symmetric_dyad, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<long double>(second_value));
  }
  {
    PhQ::SymmetricDyad<long double> converted_symmetric_dyad{
        static_cast<long double>(second_value), static_cast<long double>(second_value),
        static_cast<long double>(second_value), static_cast<long double>(second_value),
        static_cast<long double>(second_value), static_cast<long double>(second_value)};
    PhQ::Convert(converted_symmetric_dyad, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<long double>(first_value));
  }

  // PhQ::ConvertCopy(PhQ::SymmetricDyad<float>)
  {
    const PhQ::SymmetricDyad<float> copied_converted_symmetric_dyad{PhQ::ConvertCopy(
        PhQ::SymmetricDyad<float>{static_cast<float>(first_value), static_cast<float>(first_value),
                                  static_cast<float>(first_value), static_cast<float>(first_value),
                                  static_cast<float>(first_value), static_cast<float>(first_value)},
        first_unit, second_unit)};
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.xx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.xy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.xz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.yy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.yz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.zz(), static_cast<float>(second_value));
  }
  {
    const PhQ::SymmetricDyad<float> copied_converted_symmetric_dyad{PhQ::ConvertCopy(
        PhQ::SymmetricDyad<float>{
            static_cast<float>(second_value), static_cast<float>(second_value),
            static_cast<float>(second_value), static_cast<float>(second_value),
            static_cast<float>(second_value), static_cast<float>(second_value)},
        second_unit, first_unit)};
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.xx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.xy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.xz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.yy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.yz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_symmetric_dyad.zz(), static_cast<float>(first_value));
  }

  // PhQ::ConvertCopy(PhQ::SymmetricDyad<double>)
  {
    const PhQ::SymmetricDyad<double> copied_converted_symmetric_dyad{PhQ::ConvertCopy(
        PhQ::SymmetricDyad<double>{
            static_cast<double>(first_value), static_cast<double>(first_value),
            static_cast<double>(first_value), static_cast<double>(first_value),
            static_cast<double>(first_value), static_cast<double>(first_value)},
        first_unit, second_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.zz(), static_cast<double>(second_value));
  }
  {
    const PhQ::SymmetricDyad<double> copied_converted_symmetric_dyad{PhQ::ConvertCopy(
        PhQ::SymmetricDyad<double>{
            static_cast<double>(second_value), static_cast<double>(second_value),
            static_cast<double>(second_value), static_cast<double>(second_value),
            static_cast<double>(second_value), static_cast<double>(second_value)},
        second_unit, first_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.zz(), static_cast<double>(first_value));
  }

  // PhQ::ConvertCopy(PhQ::SymmetricDyad<long double>)
  {
    const PhQ::SymmetricDyad<long double> copied_converted_symmetric_dyad{PhQ::ConvertCopy(
        PhQ::SymmetricDyad<long double>{
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value), static_cast<long double>(first_value)},
        first_unit, second_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.zz(), static_cast<long double>(second_value));
  }
  {
    const PhQ::SymmetricDyad<long double> copied_converted_symmetric_dyad{PhQ::ConvertCopy(
        PhQ::SymmetricDyad<long double>{
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value), static_cast<long double>(second_value)},
        second_unit, first_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.xz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.yz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_symmetric_dyad.zz(), static_cast<long double>(first_value));
  }

  // PhQ::Convert(PhQ::Dyad<float>)
  {
    PhQ::Dyad<float> converted_dyad{
        static_cast<float>(first_value), static_cast<float>(first_value),
        static_cast<float>(first_value), static_cast<float>(first_value),
        static_cast<float>(first_value), static_cast<float>(first_value),
        static_cast<float>(first_value), static_cast<float>(first_value),
        static_cast<float>(first_value)};
    PhQ::Convert(converted_dyad, first_unit, second_unit);
    EXPECT_FLOAT_EQ(converted_dyad.xx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.xy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.xz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.yx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.yy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.yz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.zx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.zy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.zz(), static_cast<float>(second_value));
  }
  {
    PhQ::Dyad<float> converted_dyad{
        static_cast<float>(second_value), static_cast<float>(second_value),
        static_cast<float>(second_value), static_cast<float>(second_value),
        static_cast<float>(second_value), static_cast<float>(second_value),
        static_cast<float>(second_value), static_cast<float>(second_value),
        static_cast<float>(second_value)};
    PhQ::Convert(converted_dyad, second_unit, first_unit);
    EXPECT_FLOAT_EQ(converted_dyad.xx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.xy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.xz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.yx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.yy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.yz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.zx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.zy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.zz(), static_cast<float>(first_value));
  }

  // PhQ::Convert(PhQ::Dyad<double>)
  {
    PhQ::Dyad<double> converted_dyad{
        static_cast<double>(first_value), static_cast<double>(first_value),
        static_cast<double>(first_value), static_cast<double>(first_value),
        static_cast<double>(first_value), static_cast<double>(first_value),
        static_cast<double>(first_value), static_cast<double>(first_value),
        static_cast<double>(first_value)};
    PhQ::Convert(converted_dyad, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<double>(second_value));
  }
  {
    PhQ::Dyad<double> converted_dyad{
        static_cast<double>(second_value), static_cast<double>(second_value),
        static_cast<double>(second_value), static_cast<double>(second_value),
        static_cast<double>(second_value), static_cast<double>(second_value),
        static_cast<double>(second_value), static_cast<double>(second_value),
        static_cast<double>(second_value)};
    PhQ::Convert(converted_dyad, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<double>(first_value));
  }

  // PhQ::Convert(PhQ::Dyad<long double>)
  {
    PhQ::Dyad<long double> converted_dyad{
        static_cast<long double>(first_value), static_cast<long double>(first_value),
        static_cast<long double>(first_value), static_cast<long double>(first_value),
        static_cast<long double>(first_value), static_cast<long double>(first_value),
        static_cast<long double>(first_value), static_cast<long double>(first_value),
        static_cast<long double>(first_value)};
    PhQ::Convert(converted_dyad, first_unit, second_unit);
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<long double>(second_value));
  }
  {
    PhQ::Dyad<long double> converted_dyad{
        static_cast<long double>(second_value), static_cast<long double>(second_value),
        static_cast<long double>(second_value), static_cast<long double>(second_value),
        static_cast<long double>(second_value), static_cast<long double>(second_value),
        static_cast<long double>(second_value), static_cast<long double>(second_value),
        static_cast<long double>(second_value)};
    PhQ::Convert(converted_dyad, second_unit, first_unit);
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<long double>(first_value));
  }

  // PhQ::ConvertCopy(PhQ::Dyad<float>)
  {
    const PhQ::Dyad<float> copied_converted_dyad{PhQ::ConvertCopy(
        PhQ::Dyad<float>{static_cast<float>(first_value), static_cast<float>(first_value),
                         static_cast<float>(first_value), static_cast<float>(first_value),
                         static_cast<float>(first_value), static_cast<float>(first_value),
                         static_cast<float>(first_value), static_cast<float>(first_value),
                         static_cast<float>(first_value)},
        first_unit, second_unit)};
    EXPECT_FLOAT_EQ(copied_converted_dyad.xx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.xy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.xz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.yx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.yy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.yz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.zx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.zy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.zz(), static_cast<float>(second_value));
  }
  {
    const PhQ::Dyad<float> copied_converted_dyad{PhQ::ConvertCopy(
        PhQ::Dyad<float>{static_cast<float>(second_value), static_cast<float>(second_value),
                         static_cast<float>(second_value), static_cast<float>(second_value),
                         static_cast<float>(second_value), static_cast<float>(second_value),
                         static_cast<float>(second_value), static_cast<float>(second_value),
                         static_cast<float>(second_value)},
        second_unit, first_unit)};
    EXPECT_FLOAT_EQ(copied_converted_dyad.xx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.xy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.xz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.yx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.yy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.yz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.zx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.zy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(copied_converted_dyad.zz(), static_cast<float>(first_value));
  }

  // PhQ::ConvertCopy(PhQ::Dyad<double>)
  {
    const PhQ::Dyad<double> copied_converted_dyad{PhQ::ConvertCopy(
        PhQ::Dyad<double>{static_cast<double>(first_value), static_cast<double>(first_value),
                          static_cast<double>(first_value), static_cast<double>(first_value),
                          static_cast<double>(first_value), static_cast<double>(first_value),
                          static_cast<double>(first_value), static_cast<double>(first_value),
                          static_cast<double>(first_value)},
        first_unit, second_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zz(), static_cast<double>(second_value));
  }
  {
    const PhQ::Dyad<double> copied_converted_dyad{PhQ::ConvertCopy(
        PhQ::Dyad<double>{static_cast<double>(second_value), static_cast<double>(second_value),
                          static_cast<double>(second_value), static_cast<double>(second_value),
                          static_cast<double>(second_value), static_cast<double>(second_value),
                          static_cast<double>(second_value), static_cast<double>(second_value),
                          static_cast<double>(second_value)},
        second_unit, first_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zz(), static_cast<double>(first_value));
  }

  // PhQ::ConvertCopy(PhQ::Dyad<long double>)
  {
    const PhQ::Dyad<long double> copied_converted_dyad{PhQ::ConvertCopy(
        PhQ::Dyad<long double>{
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value)},
        first_unit, second_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zz(), static_cast<long double>(second_value));
  }
  {
    const PhQ::Dyad<long double> copied_converted_dyad{PhQ::ConvertCopy(
        PhQ::Dyad<long double>{
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value)},
        second_unit, first_unit)};
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.xz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.yz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(copied_converted_dyad.zz(), static_cast<long double>(first_value));
  }
}

// Tests the PhQ::StaticConvertCopy unit conversion functions for a given unit of measure. Verifies
// that a given first value expressed in a given first unit correctly converts to a given second
// value expressed in a given second unit, and vice-versa.
template <typename Unit, Unit FirstUnit, Unit SecondUnit>
void TestStaticConvertCopy(const long double first_value, const long double second_value) {
  // float
  EXPECT_FLOAT_EQ(
      (PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(static_cast<float>(first_value))),
      static_cast<float>(second_value));
  EXPECT_FLOAT_EQ(
      (PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(static_cast<float>(second_value))),
      static_cast<float>(first_value));

  // double
  EXPECT_DOUBLE_EQ(
      (PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(static_cast<double>(first_value))),
      static_cast<double>(second_value));
  EXPECT_DOUBLE_EQ(
      (PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(static_cast<double>(second_value))),
      static_cast<double>(first_value));

  // long double
  EXPECT_DOUBLE_EQ(
      (PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(static_cast<long double>(first_value))),
      static_cast<long double>(second_value));
  EXPECT_DOUBLE_EQ(
      (PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(static_cast<long double>(second_value))),
      static_cast<long double>(first_value));

  // std::array<float>
  {
    const std::array<float, 3> converted_array{PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(
        std::array<float, 3>{static_cast<float>(first_value), static_cast<float>(first_value),
                             static_cast<float>(first_value)})};
    EXPECT_FLOAT_EQ(converted_array[0], static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_array[1], static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_array[2], static_cast<float>(second_value));
  }
  {
    const std::array<float, 3> converted_array{PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(
        std::array<float, 3>{static_cast<float>(second_value), static_cast<float>(second_value),
                             static_cast<float>(second_value)})};
    EXPECT_FLOAT_EQ(converted_array[0], static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_array[1], static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_array[2], static_cast<float>(first_value));
  }

  // std::array<double>
  {
    const std::array<double, 3> converted_array{PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(
        std::array<double, 3>{static_cast<double>(first_value), static_cast<double>(first_value),
                              static_cast<double>(first_value)})};
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<double>(second_value));
  }
  {
    const std::array<double, 3> converted_array{PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(
        std::array<double, 3>{static_cast<double>(second_value), static_cast<double>(second_value),
                              static_cast<double>(second_value)})};
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<double>(first_value));
  }

  // std::array<long double>
  {
    const std::array<long double, 3> converted_array{
        PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(std::array<long double, 3>{
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value)})};
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<long double>(second_value));
  }
  {
    const std::array<long double, 3> converted_array{
        PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(std::array<long double, 3>{
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value)})};
    EXPECT_DOUBLE_EQ(converted_array[0], static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_array[1], static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_array[2], static_cast<long double>(first_value));
  }

  // PhQ::Vector<float>
  {
    const PhQ::Vector<float> converted_vector{PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(
        PhQ::Vector<float>{static_cast<float>(first_value), static_cast<float>(first_value),
                           static_cast<float>(first_value)})};
    EXPECT_FLOAT_EQ(converted_vector.x(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_vector.y(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_vector.z(), static_cast<float>(second_value));
  }
  {
    const PhQ::Vector<float> converted_vector{PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(
        PhQ::Vector<float>{static_cast<float>(second_value), static_cast<float>(second_value),
                           static_cast<float>(second_value)})};
    EXPECT_FLOAT_EQ(converted_vector.x(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_vector.y(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_vector.z(), static_cast<float>(first_value));
  }

  // PhQ::Vector<double>
  {
    const PhQ::Vector<double> converted_vector{PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(
        PhQ::Vector<double>{static_cast<double>(first_value), static_cast<double>(first_value),
                            static_cast<double>(first_value)})};
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<double>(second_value));
  }
  {
    const PhQ::Vector<double> converted_vector{PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(
        PhQ::Vector<double>{static_cast<double>(second_value), static_cast<double>(second_value),
                            static_cast<double>(second_value)})};
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<double>(first_value));
  }

  // PhQ::Vector<long double>
  {
    const PhQ::Vector<long double> converted_vector{
        PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(Vector<long double>{
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value)})};
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<long double>(second_value));
  }
  {
    const PhQ::Vector<long double> converted_vector{
        PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(Vector<long double>{
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value)})};
    EXPECT_DOUBLE_EQ(converted_vector.x(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_vector.y(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_vector.z(), static_cast<long double>(first_value));
  }

  // PhQ::SymmetricDyad<float>
  {
    const PhQ::SymmetricDyad<float> converted_symmetric_dyad{
        PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(SymmetricDyad<float>{
            static_cast<float>(first_value), static_cast<float>(first_value),
            static_cast<float>(first_value), static_cast<float>(first_value),
            static_cast<float>(first_value), static_cast<float>(first_value)})};
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.zz(), static_cast<float>(second_value));
  }
  {
    const PhQ::SymmetricDyad<float> converted_symmetric_dyad{
        PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(SymmetricDyad<float>{
            static_cast<float>(second_value), static_cast<float>(second_value),
            static_cast<float>(second_value), static_cast<float>(second_value),
            static_cast<float>(second_value), static_cast<float>(second_value)})};
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.xz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.yz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_symmetric_dyad.zz(), static_cast<float>(first_value));
  }

  // PhQ::SymmetricDyad<double>
  {
    const PhQ::SymmetricDyad<double> converted_symmetric_dyad{
        PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(SymmetricDyad<double>{
            static_cast<double>(first_value), static_cast<double>(first_value),
            static_cast<double>(first_value), static_cast<double>(first_value),
            static_cast<double>(first_value), static_cast<double>(first_value)})};
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<double>(second_value));
  }
  {
    const PhQ::SymmetricDyad<double> converted_symmetric_dyad{
        PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(SymmetricDyad<double>{
            static_cast<double>(second_value), static_cast<double>(second_value),
            static_cast<double>(second_value), static_cast<double>(second_value),
            static_cast<double>(second_value), static_cast<double>(second_value)})};
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<double>(first_value));
  }

  // PhQ::SymmetricDyad<long double>
  {
    const PhQ::SymmetricDyad<long double> converted_symmetric_dyad{
        PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(SymmetricDyad<long double>{
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value), static_cast<long double>(first_value)})};
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<long double>(second_value));
  }
  {
    const PhQ::SymmetricDyad<long double> converted_symmetric_dyad{
        PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(SymmetricDyad<long double>{
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value), static_cast<long double>(second_value)})};
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.xz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.yz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_symmetric_dyad.zz(), static_cast<long double>(first_value));
  }

  // PhQ::Dyad<float>
  {
    const PhQ::Dyad<float> converted_dyad{PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(
        PhQ::Dyad<float>{static_cast<float>(first_value), static_cast<float>(first_value),
                         static_cast<float>(first_value), static_cast<float>(first_value),
                         static_cast<float>(first_value), static_cast<float>(first_value),
                         static_cast<float>(first_value), static_cast<float>(first_value),
                         static_cast<float>(first_value)})};
    EXPECT_FLOAT_EQ(converted_dyad.xx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.xy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.xz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.yx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.yy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.yz(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.zx(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.zy(), static_cast<float>(second_value));
    EXPECT_FLOAT_EQ(converted_dyad.zz(), static_cast<float>(second_value));
  }
  {
    const PhQ::Dyad<float> converted_dyad{PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(
        PhQ::Dyad<float>{static_cast<float>(second_value), static_cast<float>(second_value),
                         static_cast<float>(second_value), static_cast<float>(second_value),
                         static_cast<float>(second_value), static_cast<float>(second_value),
                         static_cast<float>(second_value), static_cast<float>(second_value),
                         static_cast<float>(second_value)})};
    EXPECT_FLOAT_EQ(converted_dyad.xx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.xy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.xz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.yx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.yy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.yz(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.zx(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.zy(), static_cast<float>(first_value));
    EXPECT_FLOAT_EQ(converted_dyad.zz(), static_cast<float>(first_value));
  }

  // PhQ::Dyad<double>
  {
    const PhQ::Dyad<double> converted_dyad{PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(
        PhQ::Dyad<double>{static_cast<double>(first_value), static_cast<double>(first_value),
                          static_cast<double>(first_value), static_cast<double>(first_value),
                          static_cast<double>(first_value), static_cast<double>(first_value),
                          static_cast<double>(first_value), static_cast<double>(first_value),
                          static_cast<double>(first_value)})};
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<double>(second_value));
  }
  {
    const PhQ::Dyad<double> converted_dyad{PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(
        PhQ::Dyad<double>{static_cast<double>(second_value), static_cast<double>(second_value),
                          static_cast<double>(second_value), static_cast<double>(second_value),
                          static_cast<double>(second_value), static_cast<double>(second_value),
                          static_cast<double>(second_value), static_cast<double>(second_value),
                          static_cast<double>(second_value)})};
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<double>(first_value));
  }

  // PhQ::Dyad<long double>
  {
    const PhQ::Dyad<long double> converted_dyad{
        PhQ::StaticConvertCopy<Unit, FirstUnit, SecondUnit>(Dyad<long double>{
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value), static_cast<long double>(first_value),
            static_cast<long double>(first_value)})};
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<long double>(second_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<long double>(second_value));
  }
  {
    const PhQ::Dyad<long double> converted_dyad{
        PhQ::StaticConvertCopy<Unit, SecondUnit, FirstUnit>(Dyad<long double>{
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value), static_cast<long double>(second_value),
            static_cast<long double>(second_value)})};
    EXPECT_DOUBLE_EQ(converted_dyad.xx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.xz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.yz(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zx(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zy(), static_cast<long double>(first_value));
    EXPECT_DOUBLE_EQ(converted_dyad.zz(), static_cast<long double>(first_value));
  }
}

}  // namespace PhQ::Internal

#endif  // PHYSICAL_QUANTITIES_TEST_UNIT_HPP
