// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Dimension/Set.hpp"
#include "../System.hpp"
#include "../Value/Dyadic.hpp"

namespace PhQ {

template <typename Unit> constexpr const Unit standard_unit;

template <typename Unit> constexpr const Dimension::Set dimension;

template <typename Unit> const std::map<Unit, std::map<Unit, std::function<void(std::vector<double>&)>>> conversions;

template <typename Unit> double convert(double value, Unit old_unit, Unit new_unit) noexcept {
  if (old_unit != new_unit) {
    std::vector<double> value_vector{value};
    conversions<Unit>.find(old_unit)->second.find(new_unit)->second(value_vector);
    return value_vector[0];
  } else {
    return value;
  }
}

template <typename Unit> double convert(double value, Unit old_unit, System new_system) noexcept {
  return convert<Unit>(value, old_unit, unit<Unit>(new_system));
}

template <typename Unit> std::vector<double> convert(const std::vector<double>& values, Unit old_unit, Unit new_unit) noexcept {
  if (old_unit != new_unit) {
    std::vector<double> new_values{values};
    conversions<Unit>.find(old_unit)->second.find(new_unit)->second(new_values);
    return new_values;
  } else {
    return values;
  }
}

template <typename Unit> std::vector<double> convert(const std::vector<double>& values, Unit old_unit, System new_system) noexcept {
  return convert<Unit>(values, old_unit, unit<Unit>(new_system));
}

template <typename Unit> Value::Vector convert(const Value::Vector& values, Unit old_unit, Unit new_unit) noexcept {
  const std::vector<double> values_vector{convert(std::vector<double>{values.x(), values.y(), values.z()}, old_unit, new_unit)};
  return {values_vector[0], values_vector[1], values_vector[2]};
}

template <typename Unit> Value::Vector convert(const Value::Vector& values, Unit old_unit, System new_system) noexcept {
  return convert(values, old_unit, unit<Unit>(new_system));
}

template <typename Unit> Value::SymmetricDyadic convert(const Value::SymmetricDyadic& values, Unit old_unit, Unit new_unit) noexcept {
  const std::vector<double> values_vector{convert(std::vector<double>{values.xx(), values.xy(), values.xz(), values.yy(), values.yz(), values.zz()}, old_unit, new_unit)};
  return {values_vector[0], values_vector[1], values_vector[2], values_vector[3], values_vector[4], values_vector[5]};
}

template <typename Unit> Value::SymmetricDyadic convert(const Value::SymmetricDyadic& values, Unit old_unit, System new_system) noexcept {
  return convert(values, old_unit, unit<Unit>(new_system));
}

template <typename Unit> Value::Dyadic convert(const Value::Dyadic& values, Unit old_unit, Unit new_unit) noexcept {
  const std::vector<double> values_vector{convert(std::vector<double>{values.xx(), values.xy(), values.xz(), values.yx(), values.yy(), values.yz(), values.zx(), values.zy(), values.zz()}, old_unit, new_unit)};
  return {values_vector[0], values_vector[1], values_vector[2], values_vector[3], values_vector[4], values_vector[5], values_vector[6], values_vector[7], values_vector[8]};
}

template <typename Unit> Value::Dyadic convert(const Value::Dyadic& values, Unit old_unit, System new_system) noexcept {
  return convert(values, old_unit, unit<Unit>(new_system));
}

} // namespace PhQ
