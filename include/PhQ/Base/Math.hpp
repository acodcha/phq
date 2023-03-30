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

/// \brief The mathematical constant \f$ \pi = 3.14... \f$.
inline constexpr double Pi{3.14159265358979323846};

/// \brief Returns the square of a number. Equivalent to std::pow(number, 2).
inline constexpr double Power2(const double number) noexcept {
  return number * number;
}

/// \brief Returns the cube of a number. Equivalent to std::pow(number, 3).
inline constexpr double Power3(const double number) noexcept {
  return number * number * number;
}

namespace Internal {

/// \brief Returns the square root of a number using Newton's method. Typically,
/// only a few recursions are needed.
inline constexpr double SquareRoot(const double number,
                                   const double current_square_root,
                                   const double previous_square_root) noexcept {
  if (current_square_root == previous_square_root) {
    return current_square_root;
  }
  return Internal::SquareRoot(
      number, 0.5 * (current_square_root + number / current_square_root),
      current_square_root);
}

}  // namespace Internal

/// \brief Returns the square root of a number. Equivalent to std::sqrt(number).
/// However, this implementation is a constant expression, unlike std::sqrt().
inline constexpr double SquareRoot(const double number) noexcept {
  if (number >= 0.0 && std::isfinite(number)) {
    return Internal::SquareRoot(number, number, 0.0);
  }
  return std::numeric_limits<double>::quiet_NaN();
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_CONSTANT_HPP
