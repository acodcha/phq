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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Volume : int_least8_t {
  CubicMile,
  CubicKilometre,
  CubicMetre,
  CubicYard,
  CubicFoot,
  CubicDecimetre,
  Litre,
  CubicInch,
  CubicCentimetre,
  Millilitre,
  CubicMillimetre,
  CubicMilliinch,
  CubicMicrometre,
  CubicMicroinch,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Volume StandardUnit<Unit::Volume>{
    Unit::Volume::CubicMetre};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Volume>{
    Dimension::Set{Dimension::Time{}, Dimension::Length{3}}};

template <>
inline const std::map<UnitSystem, Unit::Volume> ConsistentUnits<Unit::Volume>{
    {UnitSystem::MetreKilogramSecondKelvin, Unit::Volume::CubicMetre},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Volume::CubicMillimetre},
    {UnitSystem::FootPoundSecondRankine, Unit::Volume::CubicFoot},
    {UnitSystem::InchPoundSecondRankine, Unit::Volume::CubicInch},
};

template <>
inline const std::map<Unit::Volume, UnitSystem>
    RelatedUnitSystems<Unit::Volume>{
        {Unit::Volume::CubicMetre, UnitSystem::MetreKilogramSecondKelvin},
        {Unit::Volume::CubicMillimetre, UnitSystem::MillimetreGramSecondKelvin},
        {Unit::Volume::CubicFoot, UnitSystem::FootPoundSecondRankine},
        {Unit::Volume::CubicInch, UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::Volume, std::string_view>
    Abbreviations<Unit::Volume>{
        {Unit::Volume::CubicMile, "mi^3"},
        {Unit::Volume::CubicKilometre, "km^3"},
        {Unit::Volume::CubicMetre, "m^3"},
        {Unit::Volume::CubicYard, "yd^3"},
        {Unit::Volume::CubicFoot, "ft^3"},
        {Unit::Volume::CubicDecimetre, "dm^3"},
        {Unit::Volume::Litre, "L"},
        {Unit::Volume::CubicInch, "in^3"},
        {Unit::Volume::CubicCentimetre, "cm^3"},
        {Unit::Volume::Millilitre, "mL"},
        {Unit::Volume::CubicMillimetre, "mm^3"},
        {Unit::Volume::CubicMilliinch, "mil^3"},
        {Unit::Volume::CubicMicrometre, "μm^3"},
        {Unit::Volume::CubicMicroinch, "μin^3"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::Volume>
    Spellings<Unit::Volume>{
        {"mi^3", Unit::Volume::CubicMile},
        {"mi3", Unit::Volume::CubicMile},
        {"km^3", Unit::Volume::CubicKilometre},
        {"km3", Unit::Volume::CubicKilometre},
        {"m^3", Unit::Volume::CubicMetre},
        {"m3", Unit::Volume::CubicMetre},
        {"yd^3", Unit::Volume::CubicYard},
        {"yd3", Unit::Volume::CubicYard},
        {"ft^3", Unit::Volume::CubicFoot},
        {"ft3", Unit::Volume::CubicFoot},
        {"dm^3", Unit::Volume::CubicDecimetre},
        {"dm3", Unit::Volume::CubicDecimetre},
        {"L", Unit::Volume::Litre},
        {"in^3", Unit::Volume::CubicInch},
        {"in3", Unit::Volume::CubicInch},
        {"cm^3", Unit::Volume::CubicCentimetre},
        {"cm3", Unit::Volume::CubicCentimetre},
        {"mL", Unit::Volume::Millilitre},
        {"mm^3", Unit::Volume::CubicMillimetre},
        {"mm3", Unit::Volume::CubicMillimetre},
        {"millinch^3", Unit::Volume::CubicMilliinch},
        {"millinch3", Unit::Volume::CubicMilliinch},
        {"milliinch^3", Unit::Volume::CubicMilliinch},
        {"milliinch3", Unit::Volume::CubicMilliinch},
        {"mil^3", Unit::Volume::CubicMilliinch},
        {"mil3", Unit::Volume::CubicMilliinch},
        {"thou^3", Unit::Volume::CubicMilliinch},
        {"thou3", Unit::Volume::CubicMilliinch},
        {"μm^3", Unit::Volume::CubicMicrometre},
        {"μm3", Unit::Volume::CubicMicrometre},
        {"um^3", Unit::Volume::CubicMicrometre},
        {"um3", Unit::Volume::CubicMicrometre},
        {"μin^3", Unit::Volume::CubicMicroinch},
        {"μin3", Unit::Volume::CubicMicroinch},
        {"uin^3", Unit::Volume::CubicMicroinch},
        {"uin3", Unit::Volume::CubicMicroinch},
    };

template <>
inline const std::map<Unit::Volume, std::function<void(double* const values,
                                                       const std::size_t size)>>
    ConversionsFromStandard<Unit::Volume>{
        {Unit::Volume::CubicMile,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1609.344, 3);
           }
         }},
        {Unit::Volume::CubicKilometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.001, 3);
           }
         }},
        {Unit::Volume::CubicMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Volume::CubicYard,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.9144, 3);
           }
         }},
        {Unit::Volume::CubicFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.3048, 3);
           }
         }},
        {Unit::Volume::CubicDecimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(10.0, 3);
           }
         }},
        {Unit::Volume::Litre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(10.0, 3);
           }
         }},
        {Unit::Volume::CubicInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0254, 3);
           }
         }},
        {Unit::Volume::CubicCentimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(100.0, 3);
           }
         }},
        {Unit::Volume::Millilitre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(100.0, 3);
           }
         }},
        {Unit::Volume::CubicMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 3);
           }
         }},
        {Unit::Volume::CubicMilliinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0000254, 3);
           }
         }},
        {Unit::Volume::CubicMicrometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000000.0, 3);
           }
         }},
        {Unit::Volume::CubicMicroinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0000000254, 3);
           }
         }},
    };

template <>
inline const std::map<Unit::Volume, std::function<void(double* const values,
                                                       const std::size_t size)>>
    ConversionsToStandard<Unit::Volume>{
        {Unit::Volume::CubicMile,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1609.344, 3);
           }
         }},
        {Unit::Volume::CubicKilometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 3);
           }
         }},
        {Unit::Volume::CubicMetre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Volume::CubicYard,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.9144, 3);
           }
         }},
        {Unit::Volume::CubicFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.3048, 3);
           }
         }},
        {Unit::Volume::CubicDecimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.1, 3);
           }
         }},
        {Unit::Volume::Litre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.1, 3);
           }
         }},
        {Unit::Volume::CubicInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0254, 3);
           }
         }},
        {Unit::Volume::CubicCentimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.01, 3);
           }
         }},
        {Unit::Volume::Millilitre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.01, 3);
           }
         }},
        {Unit::Volume::CubicMillimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.001, 3);
           }
         }},
        {Unit::Volume::CubicMilliinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0000254, 3);
           }
         }},
        {Unit::Volume::CubicMicrometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.000001, 3);
           }
         }},
        {Unit::Volume::CubicMicroinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0000000254, 3);
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_HPP
