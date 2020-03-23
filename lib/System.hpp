#pragma once

#include "Base/String.hpp"
#include "Base/Type.hpp"

namespace PhQ {

enum class System : uint_least8_t {
  MetreKilogramSecondKelvin,
  MillimetreGramSecondKelvin,
  FootPoundSecondRankine,
  InchPoundSecondRankine,
};

const System standard_system{System::MetreKilogramSecondKelvin};

template <> const std::map<System, std::string> abbreviations<System>{
  {System::MetreKilogramSecondKelvin, "m·kg·s·K"},
  {System::MillimetreGramSecondKelvin, "mm·g·s·K"},
  {System::FootPoundSecondRankine, "ft·lbf·s·°R"},
  {System::InchPoundSecondRankine, "in·lbf·s·°R"}
};

template <> const std::unordered_map<std::string, System> spellings<System>{
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
