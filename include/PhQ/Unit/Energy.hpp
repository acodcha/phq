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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Energy : int_least8_t {
  Joule,
  Millijoule,
  Microjoule,
  Nanojoule,
  Kilojoule,
  Megajoule,
  Gigajoule,
  FootPound,
  InchPound,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Energy StandardUnit<Unit::Energy>{
    Unit::Energy::Joule};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Energy>{Dimension::Set{
    Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1}}};

template <>
inline const std::map<UnitSystem, Unit::Energy> ConsistentUnits<Unit::Energy>{
    {UnitSystem::MetreKilogramSecondKelvin, Unit::Energy::Joule},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Energy::Nanojoule},
    {UnitSystem::FootPoundSecondRankine, Unit::Energy::FootPound},
    {UnitSystem::InchPoundSecondRankine, Unit::Energy::InchPound},
};

template <>
inline const std::map<Unit::Energy, UnitSystem>
    RelatedUnitSystems<Unit::Energy>{
        {Unit::Energy::Joule, UnitSystem::MetreKilogramSecondKelvin},
        {Unit::Energy::Nanojoule, UnitSystem::MillimetreGramSecondKelvin},
        {Unit::Energy::FootPound, UnitSystem::FootPoundSecondRankine},
        {Unit::Energy::InchPound, UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::Energy, std::string_view> Abbreviations<
    Unit::Energy>{
    {Unit::Energy::Joule, "J"},          {Unit::Energy::Millijoule, "mJ"},
    {Unit::Energy::Microjoule, "μJ"},    {Unit::Energy::Nanojoule, "nJ"},
    {Unit::Energy::Kilojoule, "kJ"},     {Unit::Energy::Megajoule, "MJ"},
    {Unit::Energy::Gigajoule, "GJ"},     {Unit::Energy::FootPound, "ft·lbf"},
    {Unit::Energy::InchPound, "in·lbf"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Energy>
    Spellings<Unit::Energy>{
        {"J", Unit::Energy::Joule},
        {"N·m", Unit::Energy::Joule},
        {"N*m", Unit::Energy::Joule},
        {"kg·m^2/s^2", Unit::Energy::Joule},
        {"kg*m^2/s^2", Unit::Energy::Joule},
        {"kg·m2/s2", Unit::Energy::Joule},
        {"kg*m2/s2", Unit::Energy::Joule},
        {"mJ", Unit::Energy::Millijoule},
        {"μJ", Unit::Energy::Microjoule},
        {"uJ", Unit::Energy::Microjoule},
        {"nJ", Unit::Energy::Nanojoule},
        {"μN·mm", Unit::Energy::Nanojoule},
        {"μN*mm", Unit::Energy::Nanojoule},
        {"uN·mm", Unit::Energy::Nanojoule},
        {"uN*mm", Unit::Energy::Nanojoule},
        {"g·mm^2/s^2", Unit::Energy::Nanojoule},
        {"g*mm^2/s^2", Unit::Energy::Nanojoule},
        {"g·mm2/s2", Unit::Energy::Nanojoule},
        {"g*mm2/s2", Unit::Energy::Nanojoule},
        {"kJ", Unit::Energy::Kilojoule},
        {"MJ", Unit::Energy::Megajoule},
        {"GJ", Unit::Energy::Gigajoule},
        {"ft·lbf", Unit::Energy::FootPound},
        {"ft*lbf", Unit::Energy::FootPound},
        {"ft·lb", Unit::Energy::FootPound},
        {"ft*lb", Unit::Energy::FootPound},
        {"in·lbf", Unit::Energy::InchPound},
        {"in*lbf", Unit::Energy::InchPound},
        {"in·lb", Unit::Energy::InchPound},
        {"in*lb", Unit::Energy::InchPound},
    };

template <>
inline const std::map<Unit::Energy, std::function<void(double* const values,
                                                       const std::size_t size)>>
    ConversionsFromStandard<Unit::Energy>{
        {Unit::Energy::Joule,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Energy::Millijoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Energy::Microjoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::Energy::Nanojoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000000.0;
           }
         }},
        {Unit::Energy::Kilojoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Energy::Megajoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::Energy::Gigajoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000000001;
           }
         }},
        {Unit::Energy::FootPound,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.3048 * 0.45359237 * 9.80665;
           }
         }},
        {Unit::Energy::InchPound,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.0254 * 0.45359237 * 9.80665;
           }
         }},
    };

template <>
inline const std::map<Unit::Energy, std::function<void(double* const values,
                                                       const std::size_t size)>>
    ConversionsToStandard<Unit::Energy>{
        {Unit::Energy::Joule,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Energy::Millijoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Energy::Microjoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::Energy::Nanojoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000000001;
           }
         }},
        {Unit::Energy::Kilojoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Energy::Megajoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::Energy::Gigajoule,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000000.0;
           }
         }},
        {Unit::Energy::FootPound,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.3048 * 0.45359237 * 9.80665;
           }
         }},
        {Unit::Energy::InchPound,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0254 * 0.45359237 * 9.80665;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_HPP
