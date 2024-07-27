// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHYSICAL_QUANTITIES_TEST_PERFORMANCE_HPP
#define PHYSICAL_QUANTITIES_TEST_PERFORMANCE_HPP

#include <array>
#include <chrono>
#include <gtest/gtest.h>

namespace PhQ::Internal {

/// @brief Tests the performance of arithmetic operators of scalar quantities of a given type.
/// Performance is compared to using raw floating-point numbers to represent the same data.
template <typename Type>
void TestScalarPerformance(
    Type& quantity1, Type& quantity2, double& reference1, double& reference2) {
  const double factor1{1.2345678901234567890};
  const double factor2{2.3456789012345678901};

  std::chrono::duration<double> quantity_duration{std::chrono::duration<double>::zero()};
  std::chrono::duration<double> reference_duration{std::chrono::duration<double>::zero()};

  for (std::size_t outer_iteration = 0; outer_iteration < 100; ++outer_iteration) {
    const std::chrono::time_point quantity_time_start{std::chrono::steady_clock::now()};
    for (std::size_t inner_iteration = 0; inner_iteration < 10000; ++inner_iteration) {
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 *= factor1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity2 *= factor1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 /= factor2;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity2 /= factor2;
    }
    const std::chrono::time_point quantity_time_end{std::chrono::steady_clock::now()};
    quantity_duration += quantity_time_end - quantity_time_start;

    const std::chrono::time_point reference_time_start{std::chrono::steady_clock::now()};
    for (std::size_t inner_iteration = 0; inner_iteration < 10000; ++inner_iteration) {
      reference1 += reference2;
      reference2 += reference1;
      reference1 += reference2;
      reference2 += reference1;
      reference1 *= factor1;
      reference1 += reference2;
      reference2 += reference1;
      reference1 += reference2;
      reference2 += reference1;
      reference2 *= factor1;
      reference1 += reference2;
      reference2 += reference1;
      reference1 += reference2;
      reference2 += reference1;
      reference1 /= factor2;
      reference1 += reference2;
      reference2 += reference1;
      reference1 += reference2;
      reference2 += reference1;
      reference2 /= factor2;
    }
    const std::chrono::time_point reference_time_end{std::chrono::steady_clock::now()};
    reference_duration += reference_time_end - reference_time_start;
  }

  const double error{std::abs(quantity_duration / reference_duration - 1.0)};
  EXPECT_LE(error, 1.0);

  EXPECT_EQ(quantity1.Value(), reference1);

  EXPECT_EQ(quantity2.Value(), reference2);
}

/// @brief Tests the performance of arithmetic operators of planar vector quantities of a given
/// type. Performance is compared to using raw floating-point numbers to represent the same data.
template <typename Type>
void TestPlanarVectorPerformance(
    Type& quantity1, Type& quantity2, std::array<double, 2>& reference1,
    std::array<double, 2>& reference2) {
  const double factor1{1.2345678901234567890};
  const double factor2{2.3456789012345678901};

  std::chrono::duration<double> quantity_duration{std::chrono::duration<double>::zero()};
  std::chrono::duration<double> reference_duration{std::chrono::duration<double>::zero()};

  for (std::size_t outer_iteration = 0; outer_iteration < 100; ++outer_iteration) {
    const std::chrono::time_point quantity_time_start{std::chrono::steady_clock::now()};
    for (std::size_t inner_iteration = 0; inner_iteration < 10000; ++inner_iteration) {
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 *= factor1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity2 *= factor1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 /= factor2;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity2 /= factor2;
    }
    const std::chrono::time_point quantity_time_end{std::chrono::steady_clock::now()};
    quantity_duration += quantity_time_end - quantity_time_start;

    const std::chrono::time_point reference_time_start{std::chrono::steady_clock::now()};
    for (std::size_t inner_iteration = 0; inner_iteration < 10000; ++inner_iteration) {
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference1[0] *= factor1;
      reference1[1] *= factor1;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[0] *= factor1;
      reference2[1] *= factor1;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference1[0] /= factor2;
      reference1[1] /= factor2;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[0] /= factor2;
      reference2[1] /= factor2;
    }
    const std::chrono::time_point reference_time_end{std::chrono::steady_clock::now()};
    reference_duration += reference_time_end - reference_time_start;
  }

  const double error{std::abs(quantity_duration / reference_duration - 1.0)};
  EXPECT_LE(error, 1.0);

  EXPECT_EQ(quantity1.Value().x(), reference1[0]);
  EXPECT_EQ(quantity1.Value().y(), reference1[1]);

  EXPECT_EQ(quantity2.Value().x(), reference2[0]);
  EXPECT_EQ(quantity2.Value().y(), reference2[1]);
}

/// @brief Tests the performance of arithmetic operators of vector quantities of a given type.
/// Performance is compared to using raw floating-point numbers to represent the same data.
template <typename Type>
void TestVectorPerformance(Type& quantity1, Type& quantity2, std::array<double, 3>& reference1,
                           std::array<double, 3>& reference2) {
  const double factor1{1.2345678901234567890};
  const double factor2{2.3456789012345678901};

  std::chrono::duration<double> quantity_duration{std::chrono::duration<double>::zero()};
  std::chrono::duration<double> reference_duration{std::chrono::duration<double>::zero()};

  for (std::size_t outer_iteration = 0; outer_iteration < 100; ++outer_iteration) {
    const std::chrono::time_point quantity_time_start{std::chrono::steady_clock::now()};
    for (std::size_t inner_iteration = 0; inner_iteration < 10000; ++inner_iteration) {
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 *= factor1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity2 *= factor1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 /= factor2;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity2 /= factor2;
    }
    const std::chrono::time_point quantity_time_end{std::chrono::steady_clock::now()};
    quantity_duration += quantity_time_end - quantity_time_start;

    const std::chrono::time_point reference_time_start{std::chrono::steady_clock::now()};
    for (std::size_t inner_iteration = 0; inner_iteration < 10000; ++inner_iteration) {
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference1[0] *= factor1;
      reference1[1] *= factor1;
      reference1[2] *= factor1;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[0] *= factor1;
      reference2[1] *= factor1;
      reference2[2] *= factor1;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference1[0] /= factor2;
      reference1[1] /= factor2;
      reference1[2] /= factor2;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[0] /= factor2;
      reference2[1] /= factor2;
      reference2[2] /= factor2;
    }
    const std::chrono::time_point reference_time_end{std::chrono::steady_clock::now()};
    reference_duration += reference_time_end - reference_time_start;
  }

  const double error{std::abs(quantity_duration / reference_duration - 1.0)};
  EXPECT_LE(error, 1.0);

  EXPECT_EQ(quantity1.Value().x(), reference1[0]);
  EXPECT_EQ(quantity1.Value().y(), reference1[1]);
  EXPECT_EQ(quantity1.Value().z(), reference1[2]);

  EXPECT_EQ(quantity2.Value().x(), reference2[0]);
  EXPECT_EQ(quantity2.Value().y(), reference2[1]);
  EXPECT_EQ(quantity2.Value().z(), reference2[2]);
}

/// @brief Tests the performance of arithmetic operators of symmetric dyad quantities of a given
/// type. Performance is compared to using raw floating-point numbers to represent the same data.
template <typename Type>
void TestSymmetricDyadPerformance(
    Type& quantity1, Type& quantity2, std::array<double, 6>& reference1,
    std::array<double, 6>& reference2) {
  const double factor1{1.2345678901234567890};
  const double factor2{2.3456789012345678901};

  std::chrono::duration<double> quantity_duration{std::chrono::duration<double>::zero()};
  std::chrono::duration<double> reference_duration{std::chrono::duration<double>::zero()};

  for (std::size_t outer_iteration = 0; outer_iteration < 100; ++outer_iteration) {
    const std::chrono::time_point quantity_time_start{std::chrono::steady_clock::now()};
    for (std::size_t inner_iteration = 0; inner_iteration < 10000; ++inner_iteration) {
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 *= factor1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity2 *= factor1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 /= factor2;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity2 /= factor2;
    }
    const std::chrono::time_point quantity_time_end{std::chrono::steady_clock::now()};
    quantity_duration += quantity_time_end - quantity_time_start;

    const std::chrono::time_point reference_time_start{std::chrono::steady_clock::now()};
    for (std::size_t inner_iteration = 0; inner_iteration < 10000; ++inner_iteration) {
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference1[0] *= factor1;
      reference1[1] *= factor1;
      reference1[2] *= factor1;
      reference1[3] *= factor1;
      reference1[4] *= factor1;
      reference1[5] *= factor1;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference2[0] *= factor1;
      reference2[1] *= factor1;
      reference2[2] *= factor1;
      reference2[3] *= factor1;
      reference2[4] *= factor1;
      reference2[5] *= factor1;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference1[0] /= factor2;
      reference1[1] /= factor2;
      reference1[2] /= factor2;
      reference1[3] /= factor2;
      reference1[4] /= factor2;
      reference1[5] /= factor2;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference2[0] /= factor2;
      reference2[1] /= factor2;
      reference2[2] /= factor2;
      reference2[3] /= factor2;
      reference2[4] /= factor2;
      reference2[5] /= factor2;
    }
    const std::chrono::time_point reference_time_end{std::chrono::steady_clock::now()};
    reference_duration += reference_time_end - reference_time_start;
  }

  const double error{std::abs(quantity_duration / reference_duration - 1.0)};
  EXPECT_LE(error, 1.0);

  EXPECT_EQ(quantity1.Value().xx(), reference1[0]);
  EXPECT_EQ(quantity1.Value().xy(), reference1[1]);
  EXPECT_EQ(quantity1.Value().xz(), reference1[2]);
  EXPECT_EQ(quantity1.Value().yy(), reference1[3]);
  EXPECT_EQ(quantity1.Value().yz(), reference1[4]);
  EXPECT_EQ(quantity1.Value().zz(), reference1[5]);

  EXPECT_EQ(quantity2.Value().xx(), reference2[0]);
  EXPECT_EQ(quantity2.Value().xy(), reference2[1]);
  EXPECT_EQ(quantity2.Value().xz(), reference2[2]);
  EXPECT_EQ(quantity2.Value().yy(), reference2[3]);
  EXPECT_EQ(quantity2.Value().yz(), reference2[4]);
  EXPECT_EQ(quantity2.Value().zz(), reference2[5]);
}

/// @brief Tests the performance of arithmetic operators of dyad quantities of a given type.
/// Performance is compared to using raw floating-point numbers to represent the same data.
template <typename Type>
void TestDyadPerformance(Type& quantity1, Type& quantity2, std::array<double, 9>& reference1,
                         std::array<double, 9>& reference2) {
  const double factor1{1.2345678901234567890};
  const double factor2{2.3456789012345678901};

  std::chrono::duration<double> quantity_duration{std::chrono::duration<double>::zero()};
  std::chrono::duration<double> reference_duration{std::chrono::duration<double>::zero()};

  for (std::size_t outer_iteration = 0; outer_iteration < 100; ++outer_iteration) {
    const std::chrono::time_point quantity_time_start{std::chrono::steady_clock::now()};
    for (std::size_t inner_iteration = 0; inner_iteration < 10000; ++inner_iteration) {
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 *= factor1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity2 *= factor1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 /= factor2;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity1 += quantity2;
      quantity2 += quantity1;
      quantity2 /= factor2;
    }
    const std::chrono::time_point quantity_time_end{std::chrono::steady_clock::now()};
    quantity_duration += quantity_time_end - quantity_time_start;

    const std::chrono::time_point reference_time_start{std::chrono::steady_clock::now()};
    for (std::size_t inner_iteration = 0; inner_iteration < 10000; ++inner_iteration) {
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference1[6] += reference2[6];
      reference1[7] += reference2[7];
      reference1[8] += reference2[8];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference2[6] += reference1[6];
      reference2[7] += reference1[7];
      reference2[8] += reference1[8];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference1[6] += reference2[6];
      reference1[7] += reference2[7];
      reference1[8] += reference2[8];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference2[6] += reference1[6];
      reference2[7] += reference1[7];
      reference2[8] += reference1[8];
      reference1[0] *= factor1;
      reference1[1] *= factor1;
      reference1[2] *= factor1;
      reference1[3] *= factor1;
      reference1[4] *= factor1;
      reference1[5] *= factor1;
      reference1[6] *= factor1;
      reference1[7] *= factor1;
      reference1[8] *= factor1;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference1[6] += reference2[6];
      reference1[7] += reference2[7];
      reference1[8] += reference2[8];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference2[6] += reference1[6];
      reference2[7] += reference1[7];
      reference2[8] += reference1[8];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference1[6] += reference2[6];
      reference1[7] += reference2[7];
      reference1[8] += reference2[8];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference2[6] += reference1[6];
      reference2[7] += reference1[7];
      reference2[8] += reference1[8];
      reference2[0] *= factor1;
      reference2[1] *= factor1;
      reference2[2] *= factor1;
      reference2[3] *= factor1;
      reference2[4] *= factor1;
      reference2[5] *= factor1;
      reference2[6] *= factor1;
      reference2[7] *= factor1;
      reference2[8] *= factor1;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference1[6] += reference2[6];
      reference1[7] += reference2[7];
      reference1[8] += reference2[8];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference2[6] += reference1[6];
      reference2[7] += reference1[7];
      reference2[8] += reference1[8];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference1[6] += reference2[6];
      reference1[7] += reference2[7];
      reference1[8] += reference2[8];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference2[6] += reference1[6];
      reference2[7] += reference1[7];
      reference2[8] += reference1[8];
      reference1[0] /= factor2;
      reference1[1] /= factor2;
      reference1[2] /= factor2;
      reference1[3] /= factor2;
      reference1[4] /= factor2;
      reference1[5] /= factor2;
      reference1[6] /= factor2;
      reference1[7] /= factor2;
      reference1[8] /= factor2;
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference1[6] += reference2[6];
      reference1[7] += reference2[7];
      reference1[8] += reference2[8];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference2[6] += reference1[6];
      reference2[7] += reference1[7];
      reference2[8] += reference1[8];
      reference1[0] += reference2[0];
      reference1[1] += reference2[1];
      reference1[2] += reference2[2];
      reference1[3] += reference2[3];
      reference1[4] += reference2[4];
      reference1[5] += reference2[5];
      reference1[6] += reference2[6];
      reference1[7] += reference2[7];
      reference1[8] += reference2[8];
      reference2[0] += reference1[0];
      reference2[1] += reference1[1];
      reference2[2] += reference1[2];
      reference2[3] += reference1[3];
      reference2[4] += reference1[4];
      reference2[5] += reference1[5];
      reference2[6] += reference1[6];
      reference2[7] += reference1[7];
      reference2[8] += reference1[8];
      reference2[0] /= factor2;
      reference2[1] /= factor2;
      reference2[2] /= factor2;
      reference2[3] /= factor2;
      reference2[4] /= factor2;
      reference2[5] /= factor2;
      reference2[6] /= factor2;
      reference2[7] /= factor2;
      reference2[8] /= factor2;
    }
    const std::chrono::time_point reference_time_end{std::chrono::steady_clock::now()};
    reference_duration += reference_time_end - reference_time_start;
  }

  const double error{std::abs(quantity_duration / reference_duration - 1.0)};
  EXPECT_LE(error, 1.0);

  EXPECT_EQ(quantity1.Value().xx(), reference1[0]);
  EXPECT_EQ(quantity1.Value().xy(), reference1[1]);
  EXPECT_EQ(quantity1.Value().xz(), reference1[2]);
  EXPECT_EQ(quantity1.Value().yx(), reference1[3]);
  EXPECT_EQ(quantity1.Value().yy(), reference1[4]);
  EXPECT_EQ(quantity1.Value().yz(), reference1[5]);
  EXPECT_EQ(quantity1.Value().zx(), reference1[6]);
  EXPECT_EQ(quantity1.Value().zy(), reference1[7]);
  EXPECT_EQ(quantity1.Value().zz(), reference1[8]);

  EXPECT_EQ(quantity2.Value().xx(), reference2[0]);
  EXPECT_EQ(quantity2.Value().xy(), reference2[1]);
  EXPECT_EQ(quantity2.Value().xz(), reference2[2]);
  EXPECT_EQ(quantity2.Value().yx(), reference2[3]);
  EXPECT_EQ(quantity2.Value().yy(), reference2[4]);
  EXPECT_EQ(quantity2.Value().yz(), reference2[5]);
  EXPECT_EQ(quantity2.Value().zx(), reference2[6]);
  EXPECT_EQ(quantity2.Value().zy(), reference2[7]);
  EXPECT_EQ(quantity2.Value().zz(), reference2[8]);
}

}  // namespace PhQ::Internal

#endif  // PHYSICAL_QUANTITIES_TEST_PERFORMANCE_HPP
