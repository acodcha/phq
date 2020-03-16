#pragma once

#include "Base.hpp"

namespace PhQ {

enum class System : uint_least8_t {
  MetreKilogramSecondKelvin,
  CentimetreGramSecondKelvin,
  MillimetreGramSecondKelvin,
  FootPoundSecondRankine,
  InchPoundSecondRankine,
};

const System standard{System::MetreKilogramSecondKelvin};

const std::map<System, std::string> abbreviations {
  {System::MetreKilogramSecondKelvin, "m·kg·s·K"},
  {System::CentimetreGramSecondKelvin, "cm·g·s·K"},
  {System::MillimetreGramSecondKelvin, "mm·g·s·K"},
  {System::FootPoundSecondRankine, "ft·lbf·s·°R"},
  {System::InchPoundSecondRankine, "in·lbf·s·°R"}
};

const std::unordered_map<std::string, System> spellings {
  {"m·kg·s·K", System::MetreKilogramSecondKelvin},
  {"m-kg-s-K", System::MetreKilogramSecondKelvin},
  {"m kg s K", System::MetreKilogramSecondKelvin},
  {"m, kg, s, K", System::MetreKilogramSecondKelvin},
  {"m·kg·s", System::MetreKilogramSecondKelvin},
  {"m-kg-s", System::MetreKilogramSecondKelvin},
  {"m kg s", System::MetreKilogramSecondKelvin},
  {"m, kg, s", System::MetreKilogramSecondKelvin},
  {"m·kg", System::MetreKilogramSecondKelvin},
  {"m-kg", System::MetreKilogramSecondKelvin},
  {"m kg", System::MetreKilogramSecondKelvin},
  {"m, kg", System::MetreKilogramSecondKelvin},
  {"m", System::MetreKilogramSecondKelvin},
  {"kg", System::MetreKilogramSecondKelvin},
  {"cm·g·s·K", System::CentimetreGramSecondKelvin},
  {"cm-g-s-K", System::CentimetreGramSecondKelvin},
  {"cm g s K", System::CentimetreGramSecondKelvin},
  {"cm, g, s, K", System::CentimetreGramSecondKelvin},
  {"cm·g·s", System::CentimetreGramSecondKelvin},
  {"cm-g-s", System::CentimetreGramSecondKelvin},
  {"cm g s", System::CentimetreGramSecondKelvin},
  {"cm, g, s", System::CentimetreGramSecondKelvin},
  {"cm·g", System::CentimetreGramSecondKelvin},
  {"cm-g", System::CentimetreGramSecondKelvin},
  {"cm g", System::CentimetreGramSecondKelvin},
  {"cm, g", System::CentimetreGramSecondKelvin},
  {"cm", System::CentimetreGramSecondKelvin},
  {"mm·g·s·K", System::MillimetreGramSecondKelvin},
  {"mm-g-s-K", System::MillimetreGramSecondKelvin},
  {"mm g s K", System::MillimetreGramSecondKelvin},
  {"mm, g, s, K", System::MillimetreGramSecondKelvin},
  {"mm·g·s", System::MillimetreGramSecondKelvin},
  {"mm-g-s", System::MillimetreGramSecondKelvin},
  {"mm g s", System::MillimetreGramSecondKelvin},
  {"mm, g, s", System::MillimetreGramSecondKelvin},
  {"mm·g", System::MillimetreGramSecondKelvin},
  {"mm-g", System::MillimetreGramSecondKelvin},
  {"mm g", System::MillimetreGramSecondKelvin},
  {"mm, g", System::MillimetreGramSecondKelvin},
  {"mm", System::MillimetreGramSecondKelvin},
  {"ft·lbf·s·°R", System::FootPoundSecondRankine},
  {"ft-lbf-s-°R", System::FootPoundSecondRankine},
  {"ft lbf s °R", System::FootPoundSecondRankine},
  {"ft, lbf, s, °R", System::FootPoundSecondRankine},
  {"ft·lb·s·°R", System::FootPoundSecondRankine},
  {"ft-lb-s-°R", System::FootPoundSecondRankine},
  {"ft lb s °R", System::FootPoundSecondRankine},
  {"ft, lb, s, °R", System::FootPoundSecondRankine},
  {"ft·lbf·s·R", System::FootPoundSecondRankine},
  {"ft-lbf-s-R", System::FootPoundSecondRankine},
  {"ft lbf s R", System::FootPoundSecondRankine},
  {"ft, lbf, s, R", System::FootPoundSecondRankine},
  {"ft·lb·s·R", System::FootPoundSecondRankine},
  {"ft-lb-s-R", System::FootPoundSecondRankine},
  {"ft lb s R", System::FootPoundSecondRankine},
  {"ft, lb, s, R", System::FootPoundSecondRankine},
  {"ft·lbf·s", System::FootPoundSecondRankine},
  {"ft-lbf-s", System::FootPoundSecondRankine},
  {"ft lbf s", System::FootPoundSecondRankine},
  {"ft, lbf, s", System::FootPoundSecondRankine},
  {"ft·lb·s", System::FootPoundSecondRankine},
  {"ft-lb-s", System::FootPoundSecondRankine},
  {"ft lb s", System::FootPoundSecondRankine},
  {"ft, lb, s", System::FootPoundSecondRankine},
  {"ft·lbf", System::FootPoundSecondRankine},
  {"ft-lbf", System::FootPoundSecondRankine},
  {"ft lbf", System::FootPoundSecondRankine},
  {"ft, lbf", System::FootPoundSecondRankine},
  {"ft·lb", System::FootPoundSecondRankine},
  {"ft-lb", System::FootPoundSecondRankine},
  {"ft lb", System::FootPoundSecondRankine},
  {"ft, lb", System::FootPoundSecondRankine},
  {"ft", System::FootPoundSecondRankine},
  {"in·lbf·s·°R", System::InchPoundSecondRankine},
  {"in-lbf-s-°R", System::InchPoundSecondRankine},
  {"in lbf s °R", System::InchPoundSecondRankine},
  {"in, lbf, s, °R", System::InchPoundSecondRankine},
  {"in·lb·s·°R", System::InchPoundSecondRankine},
  {"in-lb-s-°R", System::InchPoundSecondRankine},
  {"in lb s °R", System::InchPoundSecondRankine},
  {"in, lb, s, °R", System::InchPoundSecondRankine},
  {"in·lbf·s·R", System::InchPoundSecondRankine},
  {"in-lbf-s-R", System::InchPoundSecondRankine},
  {"in lbf s R", System::InchPoundSecondRankine},
  {"in, lbf, s, R", System::InchPoundSecondRankine},
  {"in·lb·s·R", System::InchPoundSecondRankine},
  {"in-lb-s-R", System::InchPoundSecondRankine},
  {"in lb s R", System::InchPoundSecondRankine},
  {"in, lb, s, R", System::InchPoundSecondRankine},
  {"in·lbf·s", System::InchPoundSecondRankine},
  {"in-lbf-s", System::InchPoundSecondRankine},
  {"in lbf s", System::InchPoundSecondRankine},
  {"in, lbf, s", System::InchPoundSecondRankine},
  {"in·lb·s", System::InchPoundSecondRankine},
  {"in-lb-s", System::InchPoundSecondRankine},
  {"in lb s", System::InchPoundSecondRankine},
  {"in, lb, s", System::InchPoundSecondRankine},
  {"in·lbf", System::InchPoundSecondRankine},
  {"in-lbf", System::InchPoundSecondRankine},
  {"in lbf", System::InchPoundSecondRankine},
  {"in, lbf", System::InchPoundSecondRankine},
  {"in·lb", System::InchPoundSecondRankine},
  {"in-lb", System::InchPoundSecondRankine},
  {"in lb", System::InchPoundSecondRankine},
  {"in, lb", System::InchPoundSecondRankine},
  {"in", System::InchPoundSecondRankine},
};

/// \brief Abbreviation of a unit system.
/// \details For example, abbreviate(System::MetreKilogramSecondKelvin) returns "m-kg-s-K".
std::string abbreviation(System system) noexcept {
  return abbreviations.find(system)->second;
}

std::ostream& operator<<(std::ostream& outputStream, System system) noexcept {
  outputStream << abbreviation(system);
  return outputStream;
}

/// \brief Obtain a unit system from its spelling.
/// \details For example, PhQ::parse_system("m-kg-s") returns PhQ::System::MetreKilogramSecondKelvin.
std::optional<System> parse_system(const std::string& spelling) noexcept {
  const typename std::unordered_map<std::string, System>::const_iterator system{spellings.find(spelling)};
  if (system != spellings.cend()) {
    return {system->second};
  } else {
    return {};
  }
}

template <typename Unit> const std::map<System, Unit> consistent_units;

/// \brief Obtain a unit of a given type from a unit system.
/// \details For example, PhQ::unit<Force>(PhQ::System::MetreKilogramSecondKelvin) returns PhQ::Unit::Force::Newton.
template <typename Unit> constexpr Unit unit(const System& system) noexcept {
  return consistent_units<Unit>.at(system);
}

template <typename Unit> const std::map<Unit, System> related_systems;

/// \brief Obtain a unit system, if one exists, from a unit.
/// \details For example, PhQ::system(PhQ::Unit::Length::Millimetre) returns PhQ::System::MillimetreGramSecondKelvin.
template <typename Unit> std::optional<System> system(const Unit& unit) noexcept {
  const typename std::map<Unit, System>::const_iterator system{related_systems<Unit>.find(unit)};
  if (system != related_systems<Unit>.cend()) {
    return {system->second};
  } else {
    return {};
  }
}

} // namespace PhQ
