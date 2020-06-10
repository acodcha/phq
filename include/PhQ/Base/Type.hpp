// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Include.hpp"

namespace PhQ {

template <typename Enumeration> const std::map<Enumeration, std::string> abbreviations;

template <typename Enumeration> std::string abbreviation(Enumeration enumeration) noexcept {
  return abbreviations<Enumeration>.find(enumeration)->second;
}

template <typename Enumeration> const std::unordered_map<std::string, Enumeration> spellings;

template <typename Enumeration> std::optional<Enumeration> parse(const std::string& spelling) noexcept {
  const typename std::unordered_map<std::string, Enumeration>::const_iterator enumeration{spellings<Enumeration>.find(spelling)};
  if (enumeration != spellings<Enumeration>.cend()) {
    return {enumeration->second};
  } else {
    return {};
  }
}

template <class Type> constexpr bool sort(const Type& type_1, const Type& type_2) noexcept;

template <> constexpr bool sort(const double& real_1, const double& real_2) noexcept {
  return real_1 < real_2;
}

} // namespace PhQ
