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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FORCE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FORCE_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Force : int_least8_t {
  Newton,
  Micronewton,
  Pound,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Force StandardUnit<Unit::Force>{
    Unit::Force::Newton};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Force>{Dimension::Set{
    Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1}}};

template <>
inline const std::map<UnitSystem, Unit::Force> ConsistentUnits<Unit::Force>{
    {UnitSystem::MetreKilogramSecondKelvin, Unit::Force::Newton},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Force::Micronewton},
    {UnitSystem::FootPoundSecondRankine, Unit::Force::Pound},
    {UnitSystem::InchPoundSecondRankine, Unit::Force::Pound},
};

template <>
inline const std::map<Unit::Force, UnitSystem> RelatedUnitSystems<Unit::Force>{
    {Unit::Force::Newton, UnitSystem::MetreKilogramSecondKelvin},
    {Unit::Force::Micronewton, UnitSystem::MillimetreGramSecondKelvin},
};

template <>
inline const std::map<Unit::Force, std::string_view> Abbreviations<Unit::Force>{
    {Unit::Force::Newton, "N"},
    {Unit::Force::Micronewton, "μN"},
    {Unit::Force::Pound, "lbf"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Force>
    Spellings<Unit::Force>{
        {"N", Unit::Force::Newton},
        {"kg*m/s^2", Unit::Force::Newton},
        {"kg*m/s2", Unit::Force::Newton},
        {"μN", Unit::Force::Micronewton},
        {"uN", Unit::Force::Micronewton},
        {"g*mm/s^2", Unit::Force::Micronewton},
        {"g*mm/s2", Unit::Force::Micronewton},
        {"lbf", Unit::Force::Pound},
        {"lb", Unit::Force::Pound},
    };

template <>
inline const std::map<Unit::Force, std::function<void(double* const values,
                                                      const std::size_t size)>>
    Internal::MapOfConversionsFromStandard<Unit::Force>{
        {Unit::Force::Newton,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Force::Micronewton,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::Force::Pound,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.45359237 * 9.80665;
           }
         }},
    };

template <>
inline const std::map<Unit::Force, std::function<void(double* const values,
                                                      const std::size_t size)>>
    Internal::MapOfConversionsToStandard<Unit::Force>{
        {Unit::Force::Newton,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Force::Micronewton,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::Force::Pound,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FORCE_HPP
