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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_DIFFERENCE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_DIFFERENCE_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class TemperatureDifference : int_least8_t {
  Kelvin,
  Celsius,
  Rankine,
  Fahrenheit,
};

}  // namespace Unit

template <>
inline constexpr const Unit::TemperatureDifference
    StandardUnit<Unit::TemperatureDifference>{
        Unit::TemperatureDifference::Kelvin};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::TemperatureDifference>{
    Dimension::Set{Dimension::Time{}, Dimension::Length{}, Dimension::Mass{},
                   Dimension::ElectricCurrent{}, Dimension::Temperature{1}}};

template <>
inline const std::map<UnitSystem, Unit::TemperatureDifference>
    ConsistentUnits<Unit::TemperatureDifference>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::TemperatureDifference::Kelvin},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::TemperatureDifference::Kelvin},
        {UnitSystem::FootPoundSecondRankine,
         Unit::TemperatureDifference::Rankine},
        {UnitSystem::InchPoundSecondRankine,
         Unit::TemperatureDifference::Rankine},
    };

template <>
inline const std::map<Unit::TemperatureDifference, UnitSystem>
    RelatedUnitSystems<Unit::TemperatureDifference>{};

template <>
inline const std::map<Unit::TemperatureDifference, std::string_view>
    Abbreviations<Unit::TemperatureDifference>{
        {Unit::TemperatureDifference::Kelvin, "K"},
        {Unit::TemperatureDifference::Celsius, "°C"},
        {Unit::TemperatureDifference::Rankine, "°R"},
        {Unit::TemperatureDifference::Fahrenheit, "°F"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::TemperatureDifference>
    Spellings<Unit::TemperatureDifference>{
        {"K", Unit::TemperatureDifference::Kelvin},
        {"°K", Unit::TemperatureDifference::Kelvin},
        {"degK", Unit::TemperatureDifference::Kelvin},
        {"°C", Unit::TemperatureDifference::Celsius},
        {"C", Unit::TemperatureDifference::Celsius},
        {"degC", Unit::TemperatureDifference::Celsius},
        {"°R", Unit::TemperatureDifference::Rankine},
        {"R", Unit::TemperatureDifference::Rankine},
        {"degR", Unit::TemperatureDifference::Rankine},
        {"°F", Unit::TemperatureDifference::Fahrenheit},
        {"F", Unit::TemperatureDifference::Fahrenheit},
        {"degF", Unit::TemperatureDifference::Fahrenheit},
    };

template <>
inline const std::map<
    Unit::TemperatureDifference,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::TemperatureDifference>{
        {Unit::TemperatureDifference::Kelvin,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::TemperatureDifference::Celsius,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::TemperatureDifference::Rankine,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1.8;
           }
         }},
        {Unit::TemperatureDifference::Fahrenheit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1.8;
           }
         }},
    };

template <>
inline const std::map<
    Unit::TemperatureDifference,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::TemperatureDifference>{
        {Unit::TemperatureDifference::Kelvin,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::TemperatureDifference::Celsius,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::TemperatureDifference::Rankine,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1.8;
           }
         }},
        {Unit::TemperatureDifference::Fahrenheit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1.8;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_DIFFERENCE_HPP
