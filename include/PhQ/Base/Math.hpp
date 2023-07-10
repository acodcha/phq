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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_CONSTANT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_CONSTANT_HPP

#include <cmath>
#include <limits>

namespace PhQ {

// The mathematical constant pi = 3.14... expressed as a double-precision
// floating-point number.
inline constexpr double Pi{3.14159265358979323846};

namespace Internal {

// Internal square root solver that recursively factors the input number until
// it falls within a small interval and then applies an iterative Newton-Raphson
// method. When using this function, initially call it with factor = 1.
inline constexpr double SquareRootSolver(
    const double number, const double factor) noexcept {
  // Intervals:
  //   All values are exact due to the IEEE 754 flaoting-point arithmetic
  //   standard.
  //   ]0, 2^-16[ = ]0, 1.52587890625e-5[
  //   [2^-16, 2^-8[ = [1.52587890625e-5, 0.00390625[
  //   [2^-8, 2^-4[ = [0.00390625, 0.0625[
  //   [2^-4, 2^-2[ = [0.0625, 0.25[
  //   [2^-2, 2^2] = [0.25, 4]
  //   ]2^2, 2^4] = ]4, 16]
  //   ]2^4, 2^8] = ]16, 256]
  //   ]2^8, 2^16] = ]256, 65536]
  //   ]2^16, 2^32] = ]65536, 4294967296]
  //   ]2^32, 2^64] = ]4294967296, 18446744073709551616]
  //   ]2^64, +inf[ = ]18446744073709551616, +inf[

  // Recursively factor the input number until it falls within the [0.25, 4]
  // interval.
  if (number >= 0.25) {
    // Interval: [0.25, +inf[
    if (number <= 4.0) {
      // Interval: [0.25, 4]
      // Apply an iterative Newton-Raphson method to compute the square root.
      double current_square_root = number;
      double previous_square_root = 0.0;
      while (current_square_root != previous_square_root) {
        previous_square_root = current_square_root;
        current_square_root =
            0.5 * (current_square_root + number / current_square_root);
      }
      // Finally, re-apply the factor to obtain the true square root of the
      // original input number.
      return current_square_root * factor;
    } else {
      // Interval: ]4, +inf[
      if (number <= 256.0) {
        // Interval: ]4, 256]
        if (number <= 16.0) {
          // Interval: ]4, 16]
          return SquareRootSolver(number * 0.25, 2.0 * factor);
        } else {
          // Interval: ]16, 256]
          return SquareRootSolver(number * 0.0625, 4.0 * factor);
        }
      } else {
        // Interval: ]256, +inf[
        if (number <= 4294967296.0) {
          // Interval: ]256, 4294967296]
          if (number <= 65536.0) {
            // Interval: ]256, 65536]
            return SquareRootSolver(number * 0.00390625, 16.0 * factor);
          } else {
            // Interval: ]65536, 4294967296]
            return SquareRootSolver(number * 1.52587890625e-5, 256.0 * factor);
          }
        } else {
          // Interval: ]4294967296, +inf[
          if (number <= 18446744073709551616.0) {
            // Interval: ]4294967296, 18446744073709551616]
            return SquareRootSolver(number / 4294967296.0, 65536.0 * factor);
          } else {
            // Interval: ]18446744073709551616, +inf[
            return SquareRootSolver(
                number / 18446744073709551616.0, 4294967296.0 * factor);
          }
        }
      }
    }
  } else {
    // Interval: ]0, 0.25[
    if (number >= 0.00390625) {
      // Interval: [0.00390625, 0.25[
      if (number >= 0.0625) {
        // Interval: [0.0625, 0.25[
        return SquareRootSolver(number * 4.0, 0.5 * factor);
      } else {
        // Interval: [0.00390625, 0.0625[
        return SquareRootSolver(number * 16.0, 0.25 * factor);
      }
    } else {
      // Interval: ]0, 0.00390625[
      if (number >= 0.0000152587890625) {
        // Interval: [1.52587890625e-5, 0.00390625[
        return SquareRootSolver(number * 256.0, 0.0625 * factor);
      } else {
        // Interval: ]0, 1.52587890625e-5[
        return SquareRootSolver(number * 65536.0, 0.00390625 * factor);
      }
    }
  }
}

}  // namespace Internal

// Returns the square root of a double-precision floating-point number. This
// implementation is a constant expression, unlike std::sqrt().
inline constexpr double SquareRoot(const double number) noexcept {
  // The square root of zero is zero. Notably, the square root solver is
  // designed to not handle this value, so it is treated separately.
  if (number == 0.0) {
    return number;
  }

  // The square root of a negative number or of an undefined number is
  // undefined.
  if (number < 0.0 || std::isnan(number)) {
    return std::numeric_limits<double>::quiet_NaN();
  }

  // The square root of positive infinity is positive infinity.
  if (number == std::numeric_limits<double>::infinity()) {
    return number;
  }

  return Internal::SquareRootSolver(number, 1.0);
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_CONSTANT_HPP
