// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_ENUMERATION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_ENUMERATION_HPP

#include <map>
#include <optional>
#include <string>
#include <unordered_map>

namespace PhQ {

template <typename Enumeration> const std::map<Enumeration, std::string> Abbreviations;

template <typename Enumeration> std::string abbreviation(const Enumeration enumeration) noexcept {
  return Abbreviations<Enumeration>.find(enumeration)->second;
}

template <typename Enumeration> const std::unordered_map<std::string, Enumeration> Spellings;

template <typename Enumeration> std::optional<Enumeration> parse(const std::string& spelling) noexcept {
  const typename std::unordered_map<std::string, Enumeration>::const_iterator enumeration{Spellings<Enumeration>.find(spelling)};
  if (enumeration != Spellings<Enumeration>.cend()) {
    return {enumeration->second};
  } else {
    return {};
  }
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_ENUMERATION_HPP
