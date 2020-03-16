#pragma once

#include "../Dimension/Set.hpp"
#include "../System.hpp"

namespace PhQ {

namespace Unit {

template <typename Unit> constexpr const Unit standard{consistent_units<Unit>.at(PhQ::standard)};

template <typename Unit> constexpr const Dimension::Set dimension;

template <typename Unit> const std::map<Unit, std::string> abbreviations;

template <typename Unit> const std::unordered_map<std::string, Unit> spellings;

template <typename Unit, size_t size> const std::map<Unit, std::map<Unit, std::function<void(std::array<double, size>&)>>> conversions;

/// \brief Abbreviation of a unit of measure.
/// \details For example, PhQ::Unit::abbreviation(PhQ::Unit::Length::Centimetre) returns "cm".
template <typename Unit> std::string abbreviation(Unit unit) noexcept {
  return abbreviations<Unit>.at(unit);
}

template <typename Unit> std::ostream& operator<<(std::ostream& stream, Unit unit) noexcept {
  stream << abbreviation<Unit>(unit);
  return stream;
}

/// \brief Obtain a unit of measure from its spelling.
/// \details For example, PhQ::Unit::parse<Unit::Length>("km") returns PhQ::Unit::Length::Kilometre.
template <typename Unit> std::optional<Unit> parse(const std::string& spelling) noexcept {
  const typename std::unordered_map<std::string, Unit>::const_iterator unit{spellings<Unit>.find(spelling)};
  if (unit != spellings<Unit>.cend()) {
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
    conversions<Unit, 1>.at(old_unit).at(new_unit)(values);
    return values[0];
  } else {
    return value;
  }
}

/// \brief Converts an array of values between units of measure of the same dimension.
template <typename Unit, size_t size> std::array<double, size> convert(const std::array<double, size>& values, Unit old_unit, Unit new_unit) noexcept {
  if (old_unit != new_unit) {
    std::array<double, size> new_values{values};
    conversions<Unit, size>.at(old_unit).at(new_unit)(new_values);
    return new_values;
  } else {
    return values;
  }
}

} // namespace Unit

} // namespace PhQ
