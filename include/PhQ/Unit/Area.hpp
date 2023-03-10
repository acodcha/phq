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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_AREA_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_AREA_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Area : int_least8_t {
  SquareMile,
  SquareKilometre,
  Hectare,
  Acre,
  SquareMetre,
  SquareYard,
  SquareFoot,
  SquareDecimetre,
  SquareInch,
  SquareCentimetre,
  SquareMillimetre,
  SquareMilliinch,
  SquareMicrometre,
  SquareMicroinch,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Area StandardUnit<Unit::Area>{
    Unit::Area::SquareMetre};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Area>{
    Dimension::Set{Dimension::Time{0}, Dimension::Length{2}}};

template <>
inline const std::map<UnitSystem, Unit::Area> ConsistentUnits<Unit::Area>{
    {UnitSystem::MetreKilogramSecondKelvin, Unit::Area::SquareMetre},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Area::SquareMillimetre},
    {UnitSystem::FootPoundSecondRankine, Unit::Area::SquareFoot},
    {UnitSystem::InchPoundSecondRankine, Unit::Area::SquareInch},
};

template <>
inline const std::map<Unit::Area, UnitSystem> RelatedUnitSystems<Unit::Area>{
    {Unit::Area::SquareMetre, UnitSystem::MetreKilogramSecondKelvin},
    {Unit::Area::SquareMillimetre, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Area::SquareFoot, UnitSystem::FootPoundSecondRankine},
    {Unit::Area::SquareInch, UnitSystem::InchPoundSecondRankine},
};

template <>
inline const std::map<Unit::Area, std::string_view> Abbreviations<Unit::Area>{
    {Unit::Area::SquareMile, "mi^2"},
    {Unit::Area::SquareKilometre, "km^2"},
    {Unit::Area::Hectare, "ha"},
    {Unit::Area::Acre, "ac"},
    {Unit::Area::SquareMetre, "m^2"},
    {Unit::Area::SquareYard, "yd^2"},
    {Unit::Area::SquareFoot, "ft^2"},
    {Unit::Area::SquareDecimetre, "dm^2"},
    {Unit::Area::SquareInch, "in^2"},
    {Unit::Area::SquareCentimetre, "cm^2"},
    {Unit::Area::SquareMillimetre, "mm^2"},
    {Unit::Area::SquareMilliinch, "mil^2"},
    {Unit::Area::SquareMicrometre, "μm^2"},
    {Unit::Area::SquareMicroinch, "μin^2"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Area>
    Spellings<Unit::Area>{
        {"mi^2", Unit::Area::SquareMile},
        {"mi2", Unit::Area::SquareMile},
        {"km^2", Unit::Area::SquareKilometre},
        {"km2", Unit::Area::SquareKilometre},
        {"ha", Unit::Area::Hectare},
        {"ac", Unit::Area::Acre},
        {"m^2", Unit::Area::SquareMetre},
        {"m2", Unit::Area::SquareMetre},
        {"yd^2", Unit::Area::SquareYard},
        {"yd2", Unit::Area::SquareYard},
        {"ft^2", Unit::Area::SquareFoot},
        {"ft2", Unit::Area::SquareFoot},
        {"dm^2", Unit::Area::SquareDecimetre},
        {"dm2", Unit::Area::SquareDecimetre},
        {"in^2", Unit::Area::SquareInch},
        {"in2", Unit::Area::SquareInch},
        {"cm^2", Unit::Area::SquareCentimetre},
        {"cm2", Unit::Area::SquareCentimetre},
        {"mm^2", Unit::Area::SquareMillimetre},
        {"mm2", Unit::Area::SquareMillimetre},
        {"millinch^2", Unit::Area::SquareMilliinch},
        {"millinch2", Unit::Area::SquareMilliinch},
        {"milliinch^2", Unit::Area::SquareMilliinch},
        {"milliinch2", Unit::Area::SquareMilliinch},
        {"mil^2", Unit::Area::SquareMilliinch},
        {"mil2", Unit::Area::SquareMilliinch},
        {"thou^2", Unit::Area::SquareMilliinch},
        {"thou2", Unit::Area::SquareMilliinch},
        {"μm^2", Unit::Area::SquareMicrometre},
        {"μm2", Unit::Area::SquareMicrometre},
        {"um^2", Unit::Area::SquareMicrometre},
        {"um2", Unit::Area::SquareMicrometre},
        {"μin^2", Unit::Area::SquareMicroinch},
        {"μin2", Unit::Area::SquareMicroinch},
        {"uin^2", Unit::Area::SquareMicroinch},
        {"uin2", Unit::Area::SquareMicroinch},
    };

template <>
inline const std::map<Unit::Area, std::function<void(double* const values,
                                                     const std::size_t size)>>
    Internal::MapOfConversionsFromStandard<Unit::Area>{
        {Unit::Area::SquareMile,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1609.344, 2);
           }
         }},
        {Unit::Area::SquareKilometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.001, 2);
           }
         }},
        {Unit::Area::Hectare,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0001;
           }
         }},
        {Unit::Area::Acre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 640.0 / std::pow(1609.344, 2);
           }
         }},
        {Unit::Area::SquareMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Area::SquareYard,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.9144, 2);
           }
         }},
        {Unit::Area::SquareFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.3048, 2);
           }
         }},
        {Unit::Area::SquareDecimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(10.0, 2);
           }
         }},
        {Unit::Area::SquareInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0254, 2);
           }
         }},
        {Unit::Area::SquareCentimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(100.0, 2);
           }
         }},
        {Unit::Area::SquareMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 2);
           }
         }},
        {Unit::Area::SquareMilliinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0000254, 2);
           }
         }},
        {Unit::Area::SquareMicrometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000000.0, 2);
           }
         }},
        {Unit::Area::SquareMicroinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0000000254, 2);
           }
         }},
    };

template <>
inline const std::map<Unit::Area, std::function<void(double* const values,
                                                     const std::size_t size)>>
    Internal::MapOfConversionsToStandard<Unit::Area>{
        {Unit::Area::SquareMile,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1609.344, 2);
           }
         }},
        {Unit::Area::SquareKilometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 2);
           }
         }},
        {Unit::Area::Hectare,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 10000.0;
           }
         }},
        {Unit::Area::Acre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1609.344, 2) / 640.0;
           }
         }},
        {Unit::Area::SquareMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Area::SquareYard,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.9144, 2);
           }
         }},
        {Unit::Area::SquareFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.3048, 2);
           }
         }},
        {Unit::Area::SquareDecimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.1, 2);
           }
         }},
        {Unit::Area::SquareInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0254, 2);
           }
         }},
        {Unit::Area::SquareCentimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.01, 2);
           }
         }},
        {Unit::Area::SquareMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.001, 2);
           }
         }},
        {Unit::Area::SquareMilliinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0000254, 2);
           }
         }},
        {Unit::Area::SquareMicrometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.000001, 2);
           }
         }},
        {Unit::Area::SquareMicroinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0000000254, 2);
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_AREA_HPP
