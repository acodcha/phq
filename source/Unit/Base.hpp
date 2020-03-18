#pragma once

#include "../Dimension/Set.hpp"
#include "../Dyad.hpp"
#include "../System.hpp"
#include "../Vector.hpp"

namespace PhQ {

namespace Unit {

template <typename Unit> constexpr const Unit standard{PhQ::consistent_units<Unit>.find(PhQ::standard)->second};

template <typename Unit> constexpr const Dimension::Set dimension;

template <typename Unit> const std::map<Unit, std::string> abbreviations;

template <typename Unit> const std::unordered_map<std::string, Unit> spellings;

template <typename Unit, size_t size> const std::map<Unit, std::map<Unit, std::function<void(std::array<double, size>&)>>> conversions;

/// \brief Abbreviation of a unit of measure.
/// \details For example, PhQ::Unit::abbreviation(PhQ::Unit::Length::Centimetre) returns "cm".
template <typename Unit> std::string abbreviation(Unit unit) noexcept {
  return PhQ::Unit::abbreviations<Unit>.find(unit)->second;
}

template <typename Unit> std::ostream& operator<<(std::ostream& stream, Unit unit) noexcept {
  using std::operator<<;
  stream << PhQ::Unit::abbreviation<Unit>(unit);
  return stream;
}

/// \brief Obtain a unit of measure from its spelling.
/// \details For example, PhQ::Unit::parse<Unit::Length>("km") returns PhQ::Unit::Length::Kilometre.
template <typename Unit> std::optional<Unit> parse(const std::string& spelling) noexcept {
  const typename std::unordered_map<std::string, Unit>::const_iterator unit{PhQ::Unit::spellings<Unit>.find(spelling)};
  if (unit != PhQ::Unit::spellings<Unit>.cend()) {
    return {unit->second};
  } else {
    return {};
  }
}

/// \brief Converts a value between units of measure of the same dimension.
/// \details For example, PhQ::Unit::convert(1.0, PhQ::Unit::Length::Foot, PhQ::Unit::Length::Metre) converts the value from 1.0 to 0.3048.
template <typename Unit> double convert(double value, Unit old_unit, Unit new_unit) noexcept {
  if (old_unit != new_unit) {
    std::array<double, 1> values{value};
    PhQ::Unit::conversions<Unit, 1>.find(old_unit)->second.find(new_unit)->second(values);
    return values[0];
  } else {
    return value;
  }
}

template <typename Unit> double convert(double value, Unit old_unit, System new_system) noexcept {
  const Unit new_unit{PhQ::unit<Unit>(new_system)};
  return PhQ::Unit::convert<Unit>(value, old_unit, new_unit);
}

/// \brief Converts an array of values between units of measure of the same dimension.
template <typename Unit, size_t size> std::array<double, size> convert(const std::array<double, size>& values, Unit old_unit, Unit new_unit) noexcept {
  if (old_unit != new_unit) {
    std::array<double, size> new_values{values};
    PhQ::Unit::conversions<Unit, size>.find(old_unit)->second.find(new_unit)->second(new_values);
    return new_values;
  } else {
    return values;
  }
}

template <typename Unit, size_t size> std::array<double, size> convert(const std::array<double, size>& values, Unit old_unit, System new_system) noexcept {
  const Unit new_unit{PhQ::unit<Unit>(new_system)};
  return PhQ::Unit::convert<Unit, size>(values, old_unit, new_unit);
}

template <typename Unit> PhQ::Value::CartesianVector convert(const PhQ::Value::CartesianVector& values, Unit old_unit, Unit new_unit) noexcept {
  return {PhQ::Unit::convert(values.x_y_z(), old_unit, new_unit)};
}

template <typename Unit> PhQ::Value::CartesianVector convert(const PhQ::Value::CartesianVector& values, Unit old_unit, System new_system) noexcept {
  return {PhQ::Unit::convert(values.x_y_z(), old_unit, new_system)};
}

} // namespace Unit

} // namespace PhQ
