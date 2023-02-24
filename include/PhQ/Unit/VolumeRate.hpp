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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_RATE_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class VolumeRate : int_least8_t {
  CubicMilePerSecond,
  CubicKilometrePerSecond,
  CubicMetrePerSecond,
  CubicYardPerSecond,
  CubicFootPerSecond,
  CubicDecimetrePerSecond,
  LitrePerSecond,
  CubicInchPerSecond,
  CubicCentimetrePerSecond,
  MillilitrePerSecond,
  CubicMillimetrePerSecond,
  CubicMilliinchPerSecond,
  CubicMicrometrePerSecond,
  CubicMicroinchPerSecond,
};

}  // namespace Unit

template <>
inline constexpr const Unit::VolumeRate StandardUnit<Unit::VolumeRate>{
    Unit::VolumeRate::CubicMetrePerSecond};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::VolumeRate>{
    Dimension::Set{Dimension::Time{-1}, Dimension::Length{3}}};

template <>
inline const std::map<UnitSystem, Unit::VolumeRate>
    ConsistentUnits<Unit::VolumeRate>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::VolumeRate::CubicMetrePerSecond},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::VolumeRate::CubicMillimetrePerSecond},
        {UnitSystem::FootPoundSecondRankine,
         Unit::VolumeRate::CubicFootPerSecond},
        {UnitSystem::InchPoundSecondRankine,
         Unit::VolumeRate::CubicInchPerSecond},
    };

template <>
inline const std::map<Unit::VolumeRate, UnitSystem>
    RelatedUnitSystems<Unit::VolumeRate>{
        {Unit::VolumeRate::CubicMetrePerSecond,
         UnitSystem::MetreKilogramSecondKelvin},
        {Unit::VolumeRate::CubicMillimetrePerSecond,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::VolumeRate::CubicFootPerSecond,
         UnitSystem::FootPoundSecondRankine},
        {Unit::VolumeRate::CubicInchPerSecond,
         UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::VolumeRate, std::string_view>
    Abbreviations<Unit::VolumeRate>{
        {Unit::VolumeRate::CubicMilePerSecond, "mi^3/s"},
        {Unit::VolumeRate::CubicKilometrePerSecond, "km^3/s"},
        {Unit::VolumeRate::CubicMetrePerSecond, "m^3/s"},
        {Unit::VolumeRate::CubicYardPerSecond, "yd^3/s"},
        {Unit::VolumeRate::CubicFootPerSecond, "ft^3/s"},
        {Unit::VolumeRate::CubicDecimetrePerSecond, "dm^3/s"},
        {Unit::VolumeRate::LitrePerSecond, "L/s"},
        {Unit::VolumeRate::CubicInchPerSecond, "in^3/s"},
        {Unit::VolumeRate::CubicCentimetrePerSecond, "cm^3/s"},
        {Unit::VolumeRate::MillilitrePerSecond, "mL/s"},
        {Unit::VolumeRate::CubicMillimetrePerSecond, "mm^3/s"},
        {Unit::VolumeRate::CubicMilliinchPerSecond, "mil^3/s"},
        {Unit::VolumeRate::CubicMicrometrePerSecond, "μm^3/s"},
        {Unit::VolumeRate::CubicMicroinchPerSecond, "μin^3/s"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::VolumeRate>
    Spellings<Unit::VolumeRate>{
        {"mi^3/s", Unit::VolumeRate::CubicMilePerSecond},
        {"mi^3/sec", Unit::VolumeRate::CubicMilePerSecond},
        {"mi3/s", Unit::VolumeRate::CubicMilePerSecond},
        {"mi3/sec", Unit::VolumeRate::CubicMilePerSecond},
        {"km^3/s", Unit::VolumeRate::CubicKilometrePerSecond},
        {"km^3/sec", Unit::VolumeRate::CubicKilometrePerSecond},
        {"km3/s", Unit::VolumeRate::CubicKilometrePerSecond},
        {"km3/sec", Unit::VolumeRate::CubicKilometrePerSecond},
        {"m^3/s", Unit::VolumeRate::CubicMetrePerSecond},
        {"m^3/sec", Unit::VolumeRate::CubicMetrePerSecond},
        {"m3/s", Unit::VolumeRate::CubicMetrePerSecond},
        {"m3/sec", Unit::VolumeRate::CubicMetrePerSecond},
        {"yd^3/s", Unit::VolumeRate::CubicYardPerSecond},
        {"yd^3/sec", Unit::VolumeRate::CubicYardPerSecond},
        {"yd3/s", Unit::VolumeRate::CubicYardPerSecond},
        {"yd3/sec", Unit::VolumeRate::CubicYardPerSecond},
        {"ft^3/s", Unit::VolumeRate::CubicFootPerSecond},
        {"ft^3/sec", Unit::VolumeRate::CubicFootPerSecond},
        {"ft3/s", Unit::VolumeRate::CubicFootPerSecond},
        {"ft3/sec", Unit::VolumeRate::CubicFootPerSecond},
        {"dm^3/s", Unit::VolumeRate::CubicDecimetrePerSecond},
        {"dm^3/sec", Unit::VolumeRate::CubicDecimetrePerSecond},
        {"dm3/s", Unit::VolumeRate::CubicDecimetrePerSecond},
        {"dm3/sec", Unit::VolumeRate::CubicDecimetrePerSecond},
        {"L/s", Unit::VolumeRate::LitrePerSecond},
        {"L/sec", Unit::VolumeRate::LitrePerSecond},
        {"in^3/s", Unit::VolumeRate::CubicInchPerSecond},
        {"in^3/sec", Unit::VolumeRate::CubicInchPerSecond},
        {"in3/s", Unit::VolumeRate::CubicInchPerSecond},
        {"in3/sec", Unit::VolumeRate::CubicInchPerSecond},
        {"cm^3/s", Unit::VolumeRate::CubicCentimetrePerSecond},
        {"cm^3/sec", Unit::VolumeRate::CubicCentimetrePerSecond},
        {"cm3/s", Unit::VolumeRate::CubicCentimetrePerSecond},
        {"cm3/sec", Unit::VolumeRate::CubicCentimetrePerSecond},
        {"mL/s", Unit::VolumeRate::MillilitrePerSecond},
        {"mL/sec", Unit::VolumeRate::MillilitrePerSecond},
        {"mm^3/s", Unit::VolumeRate::CubicMillimetrePerSecond},
        {"mm^3/sec", Unit::VolumeRate::CubicMillimetrePerSecond},
        {"mm3/s", Unit::VolumeRate::CubicMillimetrePerSecond},
        {"mm3/sec", Unit::VolumeRate::CubicMillimetrePerSecond},
        {"millinch^3/s", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"millinch^3/sec", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"millinch3/s", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"millinch3/sec", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"milliinch^3/s", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"milliinch^3/sec", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"milliinch3/s", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"milliinch3/sec", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"mil^3/s", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"mil^3/sec", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"mil3/s", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"mil3/sec", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"thou^3/s", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"thou^3/sec", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"thou3/s", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"thou3/sec", Unit::VolumeRate::CubicMilliinchPerSecond},
        {"μm^3/s", Unit::VolumeRate::CubicMicrometrePerSecond},
        {"μm^3/sec", Unit::VolumeRate::CubicMicrometrePerSecond},
        {"μm3/s", Unit::VolumeRate::CubicMicrometrePerSecond},
        {"μm3/sec", Unit::VolumeRate::CubicMicrometrePerSecond},
        {"um^3/s", Unit::VolumeRate::CubicMicrometrePerSecond},
        {"um^3/sec", Unit::VolumeRate::CubicMicrometrePerSecond},
        {"um3/s", Unit::VolumeRate::CubicMicrometrePerSecond},
        {"um3/sec", Unit::VolumeRate::CubicMicrometrePerSecond},
        {"μin^3/s", Unit::VolumeRate::CubicMicroinchPerSecond},
        {"μin^3/sec", Unit::VolumeRate::CubicMicroinchPerSecond},
        {"μin3/s", Unit::VolumeRate::CubicMicroinchPerSecond},
        {"μin3/sec", Unit::VolumeRate::CubicMicroinchPerSecond},
        {"uin^3/s", Unit::VolumeRate::CubicMicroinchPerSecond},
        {"uin^3/sec", Unit::VolumeRate::CubicMicroinchPerSecond},
        {"uin3/s", Unit::VolumeRate::CubicMicroinchPerSecond},
        {"uin3/sec", Unit::VolumeRate::CubicMicroinchPerSecond},
    };

template <>
inline const std::map<
    Unit::VolumeRate,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::VolumeRate>{
        {Unit::VolumeRate::CubicMilePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1609.344, 3);
           }
         }},
        {Unit::VolumeRate::CubicKilometrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.001, 3);
           }
         }},
        {Unit::VolumeRate::CubicMetrePerSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::VolumeRate::CubicYardPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.9144, 3);
           }
         }},
        {Unit::VolumeRate::CubicFootPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.3048, 3);
           }
         }},
        {Unit::VolumeRate::CubicDecimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(10.0, 3);
           }
         }},
        {Unit::VolumeRate::LitrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(10.0, 3);
           }
         }},
        {Unit::VolumeRate::CubicInchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0254, 3);
           }
         }},
        {Unit::VolumeRate::CubicCentimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(100.0, 3);
           }
         }},
        {Unit::VolumeRate::MillilitrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(100.0, 3);
           }
         }},
        {Unit::VolumeRate::CubicMillimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 3);
           }
         }},
        {Unit::VolumeRate::CubicMilliinchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0000254, 3);
           }
         }},
        {Unit::VolumeRate::CubicMicrometrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000000.0, 3);
           }
         }},
        {Unit::VolumeRate::CubicMicroinchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0000000254, 3);
           }
         }},
    };

template <>
inline const std::map<
    Unit::VolumeRate,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::VolumeRate>{
        {Unit::VolumeRate::CubicMilePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1609.344, 3);
           }
         }},
        {Unit::VolumeRate::CubicKilometrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 3);
           }
         }},
        {Unit::VolumeRate::CubicMetrePerSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::VolumeRate::CubicYardPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.9144, 3);
           }
         }},
        {Unit::VolumeRate::CubicFootPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.3048, 3);
           }
         }},
        {Unit::VolumeRate::CubicDecimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.1, 3);
           }
         }},
        {Unit::VolumeRate::LitrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.1, 3);
           }
         }},
        {Unit::VolumeRate::CubicInchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0254, 3);
           }
         }},
        {Unit::VolumeRate::CubicCentimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.01, 3);
           }
         }},
        {Unit::VolumeRate::MillilitrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.01, 3);
           }
         }},
        {Unit::VolumeRate::CubicMillimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.001, 3);
           }
         }},
        {Unit::VolumeRate::CubicMilliinchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0000254, 3);
           }
         }},
        {Unit::VolumeRate::CubicMicrometrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.000001, 3);
           }
         }},
        {Unit::VolumeRate::CubicMicroinchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0000000254, 3);
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_VOLUME_RATE_HPP
