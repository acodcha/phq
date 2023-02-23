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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DIFFUSIVITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DIFFUSIVITY_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Diffusivity : int_least8_t {
  SquareMilePerSecond,
  SquareKilometrePerSecond,
  HectarePerSecond,
  AcrePerSecond,
  SquareYardPerSecond,
  SquareMetrePerSecond,
  SquareFootPerSecond,
  SquareDecimetrePerSecond,
  SquareInchPerSecond,
  SquareCentimetrePerSecond,
  SquareMillimetrePerSecond,
  SquareMilliinchPerSecond,
  SquareMicrometrePerSecond,
  SquareMicroinchPerSecond,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Diffusivity StandardUnit<Unit::Diffusivity>{
    Unit::Diffusivity::SquareMetrePerSecond};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Diffusivity>{
    Dimension::Set{Dimension::Time{-1}, Dimension::Length{2}}};

template <>
inline const std::map<UnitSystem, Unit::Diffusivity>
    ConsistentUnits<Unit::Diffusivity>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::Diffusivity::SquareMetrePerSecond},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::Diffusivity::SquareMillimetrePerSecond},
        {UnitSystem::FootPoundSecondRankine,
         Unit::Diffusivity::SquareFootPerSecond},
        {UnitSystem::InchPoundSecondRankine,
         Unit::Diffusivity::SquareInchPerSecond}};

template <>
inline const std::map<Unit::Diffusivity, UnitSystem>
    RelatedUnitSystems<Unit::Diffusivity>{
        {Unit::Diffusivity::SquareMetrePerSecond,
         UnitSystem::MetreKilogramSecondKelvin},
        {Unit::Diffusivity::SquareMillimetrePerSecond,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::Diffusivity::SquareFootPerSecond,
         UnitSystem::FootPoundSecondRankine},
        {Unit::Diffusivity::SquareInchPerSecond,
         UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::Diffusivity, std::string_view>
    Abbreviations<Unit::Diffusivity>{
        {Unit::Diffusivity::SquareMilePerSecond, "mi^2/s"},
        {Unit::Diffusivity::SquareKilometrePerSecond, "km^2/s"},
        {Unit::Diffusivity::HectarePerSecond, "ha/s"},
        {Unit::Diffusivity::AcrePerSecond, "ac/s"},
        {Unit::Diffusivity::SquareYardPerSecond, "yd^2/s"},
        {Unit::Diffusivity::SquareMetrePerSecond, "m^2/s"},
        {Unit::Diffusivity::SquareFootPerSecond, "ft^2/s"},
        {Unit::Diffusivity::SquareDecimetrePerSecond, "dm^2/s"},
        {Unit::Diffusivity::SquareInchPerSecond, "in^2/s"},
        {Unit::Diffusivity::SquareCentimetrePerSecond, "cm^2/s"},
        {Unit::Diffusivity::SquareMillimetrePerSecond, "mm^2/s"},
        {Unit::Diffusivity::SquareMilliinchPerSecond, "mil^2/s"},
        {Unit::Diffusivity::SquareMicrometrePerSecond, "μm^2/s"},
        {Unit::Diffusivity::SquareMicroinchPerSecond, "μin^2/s"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::Diffusivity>
    Spellings<Unit::Diffusivity>{
        {"mi^2/s", Unit::Diffusivity::SquareMilePerSecond},
        {"mi^2/sec", Unit::Diffusivity::SquareMilePerSecond},
        {"mi2/s", Unit::Diffusivity::SquareMilePerSecond},
        {"mi2/sec", Unit::Diffusivity::SquareMilePerSecond},
        {"km^2/s", Unit::Diffusivity::SquareKilometrePerSecond},
        {"km^2/sec", Unit::Diffusivity::SquareKilometrePerSecond},
        {"km2/s", Unit::Diffusivity::SquareKilometrePerSecond},
        {"km2/sec", Unit::Diffusivity::SquareKilometrePerSecond},
        {"ha/s", Unit::Diffusivity::HectarePerSecond},
        {"ha/sec", Unit::Diffusivity::HectarePerSecond},
        {"ac/s", Unit::Diffusivity::AcrePerSecond},
        {"ac/sec", Unit::Diffusivity::AcrePerSecond},
        {"yd^2/s", Unit::Diffusivity::SquareYardPerSecond},
        {"yd^2/sec", Unit::Diffusivity::SquareYardPerSecond},
        {"yd2/s", Unit::Diffusivity::SquareYardPerSecond},
        {"yd2/sec", Unit::Diffusivity::SquareYardPerSecond},
        {"m^2/s", Unit::Diffusivity::SquareMetrePerSecond},
        {"m^2/sec", Unit::Diffusivity::SquareMetrePerSecond},
        {"m2/s", Unit::Diffusivity::SquareMetrePerSecond},
        {"m2/sec", Unit::Diffusivity::SquareMetrePerSecond},
        {"ft^2/s", Unit::Diffusivity::SquareFootPerSecond},
        {"ft^2/sec", Unit::Diffusivity::SquareFootPerSecond},
        {"ft2/s", Unit::Diffusivity::SquareFootPerSecond},
        {"ft2/sec", Unit::Diffusivity::SquareFootPerSecond},
        {"dm^2/s", Unit::Diffusivity::SquareDecimetrePerSecond},
        {"dm^2/sec", Unit::Diffusivity::SquareDecimetrePerSecond},
        {"dm2/s", Unit::Diffusivity::SquareDecimetrePerSecond},
        {"dm2/sec", Unit::Diffusivity::SquareDecimetrePerSecond},
        {"in^2/s", Unit::Diffusivity::SquareInchPerSecond},
        {"in^2/sec", Unit::Diffusivity::SquareInchPerSecond},
        {"in2/s", Unit::Diffusivity::SquareInchPerSecond},
        {"in2/sec", Unit::Diffusivity::SquareInchPerSecond},
        {"cm^2/s", Unit::Diffusivity::SquareCentimetrePerSecond},
        {"cm^2/sec", Unit::Diffusivity::SquareCentimetrePerSecond},
        {"cm2/s", Unit::Diffusivity::SquareCentimetrePerSecond},
        {"cm2/sec", Unit::Diffusivity::SquareCentimetrePerSecond},
        {"mm^2/s", Unit::Diffusivity::SquareMillimetrePerSecond},
        {"mm^2/sec", Unit::Diffusivity::SquareMillimetrePerSecond},
        {"mm2/s", Unit::Diffusivity::SquareMillimetrePerSecond},
        {"mm2/sec", Unit::Diffusivity::SquareMillimetrePerSecond},
        {"millinch^2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"millinch^2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"millinch2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"millinch2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"milliinch^2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"milliinch^2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"milliinch2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"milliinch2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"mil^2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"mil^2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"mil2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"mil2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"thou^2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"thou^2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"thou2/s", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"thou2/sec", Unit::Diffusivity::SquareMilliinchPerSecond},
        {"μm^2/s", Unit::Diffusivity::SquareMicrometrePerSecond},
        {"μm^2/sec", Unit::Diffusivity::SquareMicrometrePerSecond},
        {"μm2/s", Unit::Diffusivity::SquareMicrometrePerSecond},
        {"μm2/sec", Unit::Diffusivity::SquareMicrometrePerSecond},
        {"um^2/s", Unit::Diffusivity::SquareMicrometrePerSecond},
        {"um^2/sec", Unit::Diffusivity::SquareMicrometrePerSecond},
        {"um2/s", Unit::Diffusivity::SquareMicrometrePerSecond},
        {"um2/sec", Unit::Diffusivity::SquareMicrometrePerSecond},
        {"μin^2/s", Unit::Diffusivity::SquareMicroinchPerSecond},
        {"μin^2/sec", Unit::Diffusivity::SquareMicroinchPerSecond},
        {"μin2/s", Unit::Diffusivity::SquareMicroinchPerSecond},
        {"μin2/sec", Unit::Diffusivity::SquareMicroinchPerSecond},
        {"uin^2/s", Unit::Diffusivity::SquareMicroinchPerSecond},
        {"uin^2/sec", Unit::Diffusivity::SquareMicroinchPerSecond},
        {"uin2/s", Unit::Diffusivity::SquareMicroinchPerSecond},
        {"uin2/sec", Unit::Diffusivity::SquareMicroinchPerSecond},
    };

template <>
inline const std::map<
    Unit::Diffusivity,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::Diffusivity>{
        {Unit::Diffusivity::SquareMilePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1609.344, 2);
           }
         }},
        {Unit::Diffusivity::SquareKilometrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.001, 2);
           }
         }},
        {Unit::Diffusivity::HectarePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0001;
           }
         }},
        {Unit::Diffusivity::AcrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 640.0 / std::pow(1609.344, 2);
           }
         }},
        {Unit::Diffusivity::SquareYardPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.9144, 2);
           }
         }},
        {Unit::Diffusivity::SquareMetrePerSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Diffusivity::SquareFootPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.3048, 2);
           }
         }},
        {Unit::Diffusivity::SquareDecimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(10.0, 2);
           }
         }},
        {Unit::Diffusivity::SquareInchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0254, 2);
           }
         }},
        {Unit::Diffusivity::SquareCentimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(100.0, 2);
           }
         }},
        {Unit::Diffusivity::SquareMillimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 2);
           }
         }},
        {Unit::Diffusivity::SquareMilliinchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0000254, 2);
           }
         }},
        {Unit::Diffusivity::SquareMicrometrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000000.0, 2);
           }
         }},
        {Unit::Diffusivity::SquareMicroinchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(0.0000000254, 2);
           }
         }},
    };

template <>
inline const std::map<
    Unit::Diffusivity,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::Diffusivity>{
        {Unit::Diffusivity::SquareMilePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1609.344, 2);
           }
         }},
        {Unit::Diffusivity::SquareKilometrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 2);
           }
         }},
        {Unit::Diffusivity::HectarePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 10000.0;
           }
         }},
        {Unit::Diffusivity::AcrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1609.344, 2) / 640.0;
           }
         }},
        {Unit::Diffusivity::SquareYardPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.9144, 2);
           }
         }},
        {Unit::Diffusivity::SquareMetrePerSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Diffusivity::SquareFootPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.3048, 2);
           }
         }},
        {Unit::Diffusivity::SquareDecimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.1, 2);
           }
         }},
        {Unit::Diffusivity::SquareInchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0254, 2);
           }
         }},
        {Unit::Diffusivity::SquareCentimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.01, 2);
           }
         }},
        {Unit::Diffusivity::SquareMillimetrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.001, 2);
           }
         }},
        {Unit::Diffusivity::SquareMilliinchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0000254, 2);
           }
         }},
        {Unit::Diffusivity::SquareMicrometrePerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.000001, 2);
           }
         }},
        {Unit::Diffusivity::SquareMicroinchPerSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0000000254, 2);
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DIFFUSIVITY_HPP
