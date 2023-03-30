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

/// \brief Returns the square root of a number. This implementation is a
/// constant expression, unlike std::sqrt().
inline constexpr double SquareRoot(const double number) noexcept {
  if (number < 0.0 || !std::isfinite(number)) {
    return std::numeric_limits<double>::quiet_NaN();
  }
  double current_square_root = number;
  double previous_square_root = 0.0;
  while (current_square_root != previous_square_root) {
    previous_square_root = current_square_root;
    current_square_root =
        0.5 * (current_square_root + number / current_square_root);
  }
  return current_square_root;
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_CONSTANT_HPP
