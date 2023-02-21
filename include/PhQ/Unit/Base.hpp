// Copyright 2020 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_BASE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_BASE_HPP

#include "../Dimension/Set.hpp"
#include "../UnitSystem.hpp"
#include "../Value/Dyad.hpp"

namespace PhQ {

template <typename Unit>
inline constexpr Unit StandardUnit;

template <typename Unit>
inline constexpr Dimension::Set Dimensions;

template <typename Unit>
inline const std::map<
    Unit, std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard;

template <typename Unit>
inline const std::map<
    Unit, std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard;

template <typename Unit>
void Convert(double& value, const Unit old_unit, const Unit new_unit) noexcept {
  if (old_unit == new_unit) {
    return;
  }
  ConversionsToStandard<Unit>.find(old_unit)->second(&value, 1);
  if (new_unit == StandardUnit<Unit>) {
    return;
  }
  ConversionsFromStandard<Unit>.find(new_unit)->second(&value, 1);
}

template <typename Unit>
void Convert(double& value, const Unit old_unit,
             const UnitSystem new_unit_system) noexcept {
  const Unit new_unit{ConsistentUnit<Unit>(new_unit_system)};
  if (old_unit == new_unit) {
    return;
  }
  ConversionsToStandard<Unit>.find(old_unit)->second(&value, 1);
  if (new_unit == StandardUnit<Unit>) {
    return;
  }
  ConversionsFromStandard<Unit>.find(new_unit)->second(&value, 1);
}

template <typename Unit, std::size_t Size>
void Convert(std::array<double, Size>& values, const Unit old_unit,
             const Unit new_unit) noexcept {
  if (old_unit == new_unit) {
    return;
  }
  ConversionsToStandard<Unit>.find(old_unit)->second(&values[0], Size);
  if (new_unit == StandardUnit<Unit>) {
    return;
  }
  ConversionsFromStandard<Unit>.find(new_unit)->second(&values[0], Size);
}

template <typename Unit, std::size_t Size>
void Convert(std::array<double, Size>& values, const Unit old_unit,
             const UnitSystem new_unit_system) noexcept {
  const Unit new_unit{ConsistentUnit<Unit>(new_unit_system)};
  if (old_unit == new_unit) {
    return;
  }
  ConversionsToStandard<Unit>.find(old_unit)->second(&values[0], Size);
  if (new_unit == StandardUnit<Unit>) {
    return;
  }
  ConversionsFromStandard<Unit>.find(new_unit)->second(&values[0], Size);
}

template <typename Unit>
void Convert(Value::Vector& vector, const Unit old_unit,
             const Unit new_unit) noexcept {
  Convert<Unit, 3>(vector.x_y_z_, old_unit, new_unit);
}

template <typename Unit>
void Convert(Value::Vector& vector, const Unit old_unit,
             const UnitSystem new_unit_system) noexcept {
  Convert<Unit, 3>(vector.x_y_z_, old_unit, new_unit_system);
}

template <typename Unit>
void Convert(Value::SymmetricDyad& symdyad, const Unit old_unit,
             const Unit new_unit) noexcept {
  Convert<Unit, 6>(symdyad.xx_xy_xz_yy_yz_zz_, old_unit, new_unit);
}

template <typename Unit>
void Convert(Value::SymmetricDyad& symdyad, const Unit old_unit,
             const UnitSystem new_unit_system) noexcept {
  Convert<Unit, 6>(symdyad.xx_xy_xz_yy_yz_zz_, old_unit, new_unit_system);
}

template <typename Unit>
void Convert(Value::Dyad& dyad, const Unit old_unit,
             const Unit new_unit) noexcept {
  Convert<Unit, 9>(dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_, old_unit, new_unit);
}

template <typename Unit>
void Convert(Value::Dyad& dyad, const Unit old_unit,
             const UnitSystem new_unit_system) noexcept {
  Convert<Unit, 9>(dyad.xx_xy_xz_yx_yy_yz_zx_zy_zz_, old_unit, new_unit_system);
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_BASE_HPP
