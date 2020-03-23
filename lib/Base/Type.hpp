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

template <class Type> constexpr bool sort(const Type& type1, const Type& type2) noexcept;

} // namespace PhQ
