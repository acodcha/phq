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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_GRADIENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_GRADIENT_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class TemperatureGradient : int_least8_t {
  KelvinPerMetre,
  KelvinPerMillimetre,
  CelsiusPerMetre,
  CelsiusPerMillimetre,
  RankinePerFoot,
  RankinePerInch,
  FahrenheitPerFoot,
  FahrenheitPerInch,
};

}  // namespace Unit

template <>
inline constexpr const Unit::TemperatureGradient
    StandardUnit<Unit::TemperatureGradient>{
        Unit::TemperatureGradient::KelvinPerMetre};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::TemperatureGradient>{
    Dimension::Set{Dimension::Time{}, Dimension::Length{-1}, Dimension::Mass{},
                   Dimension::ElectricCurrent{}, Dimension::Temperature{1}}};

template <>
inline const std::map<UnitSystem, Unit::TemperatureGradient>
    ConsistentUnits<Unit::TemperatureGradient>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::TemperatureGradient::KelvinPerMetre},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::TemperatureGradient::KelvinPerMillimetre},
        {UnitSystem::FootPoundSecondRankine,
         Unit::TemperatureGradient::RankinePerFoot},
        {UnitSystem::InchPoundSecondRankine,
         Unit::TemperatureGradient::RankinePerInch},
    };

template <>
inline const std::map<Unit::TemperatureGradient, UnitSystem>
    RelatedUnitSystems<Unit::TemperatureGradient>{
        {Unit::TemperatureGradient::KelvinPerMetre,
         UnitSystem::MetreKilogramSecondKelvin},
        {Unit::TemperatureGradient::KelvinPerMillimetre,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::TemperatureGradient::RankinePerFoot,
         UnitSystem::FootPoundSecondRankine},
        {Unit::TemperatureGradient::RankinePerInch,
         UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::TemperatureGradient, std::string_view>
    Abbreviations<Unit::TemperatureGradient>{
        {Unit::TemperatureGradient::KelvinPerMetre, "K/m"},
        {Unit::TemperatureGradient::CelsiusPerMetre, "°C/m"},
        {Unit::TemperatureGradient::KelvinPerMillimetre, "K/mm"},
        {Unit::TemperatureGradient::CelsiusPerMillimetre, "°C/mm"},
        {Unit::TemperatureGradient::RankinePerFoot, "°R/ft"},
        {Unit::TemperatureGradient::FahrenheitPerFoot, "°F/ft"},
        {Unit::TemperatureGradient::RankinePerInch, "°R/in"},
        {Unit::TemperatureGradient::FahrenheitPerInch, "°F/in"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::TemperatureGradient>
    Spellings<Unit::TemperatureGradient>{
        {"K/m", Unit::TemperatureGradient::KelvinPerMetre},
        {"°K/m", Unit::TemperatureGradient::KelvinPerMetre},
        {"degK/m", Unit::TemperatureGradient::KelvinPerMetre},
        {"°C/m", Unit::TemperatureGradient::CelsiusPerMetre},
        {"C/m", Unit::TemperatureGradient::CelsiusPerMetre},
        {"degC/m", Unit::TemperatureGradient::CelsiusPerMetre},
        {"K/mm", Unit::TemperatureGradient::KelvinPerMillimetre},
        {"°K/mm", Unit::TemperatureGradient::KelvinPerMillimetre},
        {"degK/mm", Unit::TemperatureGradient::KelvinPerMillimetre},
        {"°C/mm", Unit::TemperatureGradient::CelsiusPerMillimetre},
        {"C/mm", Unit::TemperatureGradient::CelsiusPerMillimetre},
        {"degC/mm", Unit::TemperatureGradient::CelsiusPerMillimetre},
        {"°R/ft", Unit::TemperatureGradient::RankinePerFoot},
        {"R/ft", Unit::TemperatureGradient::RankinePerFoot},
        {"degR/ft", Unit::TemperatureGradient::RankinePerFoot},
        {"°F/ft", Unit::TemperatureGradient::FahrenheitPerFoot},
        {"F/ft", Unit::TemperatureGradient::FahrenheitPerFoot},
        {"degF/ft", Unit::TemperatureGradient::FahrenheitPerFoot},
        {"°R/in", Unit::TemperatureGradient::RankinePerInch},
        {"R/in", Unit::TemperatureGradient::RankinePerInch},
        {"degR/in", Unit::TemperatureGradient::RankinePerInch},
        {"°F/in", Unit::TemperatureGradient::FahrenheitPerInch},
        {"F/in", Unit::TemperatureGradient::FahrenheitPerInch},
        {"degF/in", Unit::TemperatureGradient::FahrenheitPerInch},
    };

template <>
inline const std::map<
    Unit::TemperatureGradient,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::TemperatureGradient>{
        {Unit::TemperatureGradient::KelvinPerMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::TemperatureGradient::KelvinPerMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::TemperatureGradient::CelsiusPerMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::TemperatureGradient::CelsiusPerMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::TemperatureGradient::RankinePerFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1.8 * 0.3048;
           }
         }},
        {Unit::TemperatureGradient::RankinePerInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1.8 * 0.0254;
           }
         }},
        {Unit::TemperatureGradient::FahrenheitPerFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1.8 * 0.3048;
           }
         }},
        {Unit::TemperatureGradient::FahrenheitPerInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1.8 * 0.0254;
           }
         }},
    };

template <>
inline const std::map<
    Unit::TemperatureGradient,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::TemperatureGradient>{
        {Unit::TemperatureGradient::KelvinPerMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::TemperatureGradient::KelvinPerMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::TemperatureGradient::CelsiusPerMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::TemperatureGradient::CelsiusPerMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::TemperatureGradient::RankinePerFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1.8 * 0.3048;
           }
         }},
        {Unit::TemperatureGradient::RankinePerInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1.8 * 0.0254;
           }
         }},
        {Unit::TemperatureGradient::FahrenheitPerFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1.8 * 0.3048;
           }
         }},
        {Unit::TemperatureGradient::FahrenheitPerInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1.8 * 0.0254;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_TEMPERATURE_GRADIENT_HPP
