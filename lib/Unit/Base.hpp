#pragma once

#include "../Dimension/Set.hpp"
#include "../System.hpp"
#include "../Value/Dyadic.hpp"

namespace PhQ {

template <typename Unit> constexpr const Unit standard_unit;

template <typename Unit> constexpr const Dimension::Set dimension;

template <typename Unit, typename RelatedUnit> const std::map<Unit, RelatedUnit> related_units;

/// \brief Obtain a related unit of measure of a different type.
/// \details For example, PhQ::Unit::related_unit<PhQ::Unit::Unit::Volume>(PhQ::Unit::Unit::Length::Millimetre) returns PhQ::Unit::Unit::Volume::CubicMillimetre.
template <typename Unit, typename RelatedUnit> std::optional<RelatedUnit> related_unit(Unit unit) noexcept {
  const typename std::map<Unit, RelatedUnit>::const_iterator related_unit{related_units<Unit, RelatedUnit>.find(unit)};
  if (related_unit != related_units<Unit, RelatedUnit>.cend()) {
    return {related_unit->second};
  } else {
    return {};
  }
}

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
