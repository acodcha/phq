// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Dimension/Set.hpp"
#include "../System.hpp"
#include "../Value/Dyadic.hpp"

namespace PhQ {

template <typename Unit> constexpr const Unit standard_unit;

template <typename Unit> constexpr const Dimension::Set dimension;

template <typename Unit, size_t size> const std::map<Unit, std::map<Unit, std::function<void(std::array<double, size>&)>>> conversions;

template <typename Unit> double convert(double value, Unit old_unit, Unit new_unit) noexcept {
  if (old_unit != new_unit) {
    std::array<double, 1> new_value{value};
    conversions<Unit, 1>.find(old_unit)->second.find(new_unit)->second(new_value);
    return new_value[0];
  } else {
    return value;
  }
}

template <typename Unit> double convert(double value, Unit old_unit, System new_system) noexcept {
  return convert<Unit>(value, old_unit, unit<Unit>(new_system));
}

template <typename Unit, size_t size> std::array<double, size> convert(const std::array<double, size>& values, Unit old_unit, Unit new_unit) noexcept {
  if (old_unit != new_unit) {
    std::array<double, size> new_values{values};
    conversions<Unit, size>.find(old_unit)->second.find(new_unit)->second(new_values);
    return new_values;
  } else {
    return values;
  }
}

template <typename Unit, size_t size> std::array<double, size> convert(const std::array<double, size>& values, Unit old_unit, System new_system) noexcept {
  return convert<Unit, size>(values, old_unit, unit<Unit>(new_system));
}

template <typename Unit> Value::Vector convert(const Value::Vector& values, Unit old_unit, Unit new_unit) noexcept {
  return {convert(values.x_y_z(), old_unit, new_unit)};
}

template <typename Unit> Value::Vector convert(const Value::Vector& values, Unit old_unit, System new_system) noexcept {
  return {convert(values.x_y_z(), old_unit, unit<Unit>(new_system))};
}

template <typename Unit> Value::SymmetricDyadic convert(const Value::SymmetricDyadic& values, Unit old_unit, Unit new_unit) noexcept {
  return {convert(values.xx_xy_xz_yy_yz_zz(), old_unit, new_unit)};
}

template <typename Unit> Value::SymmetricDyadic convert(const Value::SymmetricDyadic& values, Unit old_unit, System new_system) noexcept {
  return {convert(values.xx_xy_xz_yy_yz_zz(), old_unit, unit<Unit>(new_system))};
}

template <typename Unit> Value::Dyadic convert(const Value::Dyadic& values, Unit old_unit, Unit new_unit) noexcept {
  return {convert(values.xx_xy_xz_yx_yy_yz_zx_zy_zz(), old_unit, new_unit)};
}

template <typename Unit> Value::Dyadic convert(const Value::Dyadic& values, Unit old_unit, System new_system) noexcept {
  return {convert(values.xx_xy_xz_yx_yy_yz_zx_zy_zz(), old_unit, unit<Unit>(new_system))};
}

} // namespace PhQ
