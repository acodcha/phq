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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_ENUMERATION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_ENUMERATION_HPP

#include <map>
#include <optional>
#include <string_view>
#include <unordered_map>

namespace PhQ {

namespace Internal {

// Map of enumerations to their corresponding abbreviations. This is an internal
// implementation detail and is not intended to be used except by the
// PhQ::Abbreviation function.
template<typename Enumeration>
inline const std::map<Enumeration, std::string_view> Abbreviations;

// Map of spellings to their corresponding enumeration values. This is an
// internal implementation detail and is not intended to be used except by the
// PhQ::Parse function.
template<typename Enumeration>
inline const std::unordered_map<std::string_view, Enumeration> Spellings;

}  // namespace Internal

// Returns the abbreviation of a given enumeration value. For example,
// PhQ::Abbreviation(PhQ::Unit::Time::Hour) returns "hr".
template<typename Enumeration>
inline std::string_view Abbreviation(const Enumeration enumeration) noexcept {
  return Internal::Abbreviations<Enumeration>.find(enumeration)->second;
}

// Attempts to parse some given text into an enumeration. Returns the
// enumeration if one is found, or std::nullopt otherwise. For example,
// PhQ::Parse<PhQ::Unit::Time>("hr") returns PhQ::Unit::Time::Hour.
template<typename Enumeration>
std::optional<Enumeration> Parse(const std::string_view spelling) noexcept {
  const typename std::unordered_map<std::string_view,
                                    Enumeration>::const_iterator found{
      Internal::Spellings<Enumeration>.find(spelling)};
  if (found != Internal::Spellings<Enumeration>.cend()) {
    return found->second;
  } else {
    return std::nullopt;
  }
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_ENUMERATION_HPP
