// Copyright 2020 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FREQUENCY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FREQUENCY_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Frequency : int_least8_t {
  Hertz,
  Kilohertz,
  Megahertz,
  Gigahertz,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Frequency StandardUnit<Unit::Frequency>{
    Unit::Frequency::Hertz};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Frequency>{
    Dimension::Set{Dimension::Time{-1}}};

template <>
inline const std::map<UnitSystem, Unit::Frequency>
    ConsistentUnits<Unit::Frequency>{
        {UnitSystem::MetreKilogramSecondKelvin, Unit::Frequency::Hertz},
        {UnitSystem::MillimetreGramSecondKelvin, Unit::Frequency::Hertz},
        {UnitSystem::FootPoundSecondRankine, Unit::Frequency::Hertz},
        {UnitSystem::InchPoundSecondRankine, Unit::Frequency::Hertz},
    };

template <>
inline const std::map<Unit::Frequency, UnitSystem>
    RelatedUnitSystems<Unit::Frequency>{};

template <>
inline const std::map<Unit::Frequency, std::string_view>
    Abbreviations<Unit::Frequency>{
        {Unit::Frequency::Hertz, "Hz"},
        {Unit::Frequency::Kilohertz, "kHz"},
        {Unit::Frequency::Megahertz, "MHz"},
        {Unit::Frequency::Gigahertz, "GHz"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::Frequency>
    Spellings<Unit::Frequency>{
        {"Hz", Unit::Frequency::Hertz},
        {"1/s", Unit::Frequency::Hertz},
        {"/s", Unit::Frequency::Hertz},
        {"kHz", Unit::Frequency::Kilohertz},
        {"MHz", Unit::Frequency::Megahertz},
        {"GHz", Unit::Frequency::Gigahertz},
    };

template <>
inline const std::map<
    Unit::Frequency,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::Frequency>{
        {Unit::Frequency::Hertz,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Frequency::Kilohertz,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Frequency::Megahertz,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::Frequency::Gigahertz,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000000001;
           }
         }},
    };

template <>
inline const std::map<
    Unit::Frequency,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::Frequency>{
        {Unit::Frequency::Hertz,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Frequency::Kilohertz,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Frequency::Megahertz,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::Frequency::Gigahertz,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000000.0;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_FREQUENCY_HPP
