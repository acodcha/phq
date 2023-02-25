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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ACCELERATION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ACCELERATION_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Acceleration : int_least8_t {
  MilePerSquareSecond,
  KilometrePerSquareSecond,
  YardPerSquareSecond,
  MetrePerSquareSecond,
  FootPerSquareSecond,
  DecimetrePerSquareSecond,
  InchPerSquareSecond,
  CentimetrePerSquareSecond,
  MillimetrePerSquareSecond,
  MilliinchPerSquareSecond,
  MicrometrePerSquareSecond,
  MicroinchPerSquareSecond,
};

}  // namespace Unit

template <>
constexpr const Unit::Acceleration StandardUnit<Unit::Acceleration>{
    Unit::Acceleration::MetrePerSquareSecond};

template <>
constexpr const Dimension::Set Dimensions<Unit::Acceleration>{
    Dimension::Set{Dimension::Time{-2}, Dimension::Length{1}}};

template <>
inline const std::map<UnitSystem, Unit::Acceleration>
    ConsistentUnits<Unit::Acceleration>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::Acceleration::MetrePerSquareSecond},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::Acceleration::MillimetrePerSquareSecond},
        {UnitSystem::FootPoundSecondRankine,
         Unit::Acceleration::FootPerSquareSecond},
        {UnitSystem::InchPoundSecondRankine,
         Unit::Acceleration::InchPerSquareSecond},
    };

template <>
inline const std::map<Unit::Acceleration, UnitSystem>
    RelatedUnitSystems<Unit::Acceleration>{
        {Unit::Acceleration::MetrePerSquareSecond,
         UnitSystem::MetreKilogramSecondKelvin},
        {Unit::Acceleration::MillimetrePerSquareSecond,
         UnitSystem::MillimetreGramSecondKelvin},
        {Unit::Acceleration::FootPerSquareSecond,
         UnitSystem::FootPoundSecondRankine},
        {Unit::Acceleration::InchPerSquareSecond,
         UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::Acceleration, std::string_view>
    Abbreviations<Unit::Acceleration>{
        {Unit::Acceleration::MilePerSquareSecond, "mi/s^2"},
        {Unit::Acceleration::KilometrePerSquareSecond, "km/s^2"},
        {Unit::Acceleration::YardPerSquareSecond, "yd/s^2"},
        {Unit::Acceleration::MetrePerSquareSecond, "m/s^2"},
        {Unit::Acceleration::FootPerSquareSecond, "ft/s^2"},
        {Unit::Acceleration::DecimetrePerSquareSecond, "dm/s^2"},
        {Unit::Acceleration::InchPerSquareSecond, "in/s^2"},
        {Unit::Acceleration::CentimetrePerSquareSecond, "cm/s^2"},
        {Unit::Acceleration::MillimetrePerSquareSecond, "mm/s^2"},
        {Unit::Acceleration::MilliinchPerSquareSecond, "mil/s^2"},
        {Unit::Acceleration::MicrometrePerSquareSecond, "μm/s^2"},
        {Unit::Acceleration::MicroinchPerSquareSecond, "μin/s^2"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::Acceleration>
    Spellings<Unit::Acceleration>{
        {"mi/s^2", Unit::Acceleration::MilePerSquareSecond},
        {"mi/s2", Unit::Acceleration::MilePerSquareSecond},
        {"mi/s/s", Unit::Acceleration::MilePerSquareSecond},
        {"mi/sec^2", Unit::Acceleration::MilePerSquareSecond},
        {"mi/sec2", Unit::Acceleration::MilePerSquareSecond},
        {"mi/sec/sec", Unit::Acceleration::MilePerSquareSecond},
        {"km/s^2", Unit::Acceleration::KilometrePerSquareSecond},
        {"km/s2", Unit::Acceleration::KilometrePerSquareSecond},
        {"km/s/s", Unit::Acceleration::KilometrePerSquareSecond},
        {"km/sec^2", Unit::Acceleration::KilometrePerSquareSecond},
        {"km/sec2", Unit::Acceleration::KilometrePerSquareSecond},
        {"km/sec/sec", Unit::Acceleration::KilometrePerSquareSecond},
        {"yd/s^2", Unit::Acceleration::YardPerSquareSecond},
        {"yd/s2", Unit::Acceleration::YardPerSquareSecond},
        {"yd/s/s", Unit::Acceleration::YardPerSquareSecond},
        {"yd/sec^2", Unit::Acceleration::YardPerSquareSecond},
        {"yd/sec2", Unit::Acceleration::YardPerSquareSecond},
        {"yd/sec/sec", Unit::Acceleration::YardPerSquareSecond},
        {"m/s^2", Unit::Acceleration::MetrePerSquareSecond},
        {"m/s2", Unit::Acceleration::MetrePerSquareSecond},
        {"m/s/s", Unit::Acceleration::MetrePerSquareSecond},
        {"m/sec^2", Unit::Acceleration::MetrePerSquareSecond},
        {"m/sec2", Unit::Acceleration::MetrePerSquareSecond},
        {"m/sec/sec", Unit::Acceleration::MetrePerSquareSecond},
        {"ft/s^2", Unit::Acceleration::FootPerSquareSecond},
        {"ft/s2", Unit::Acceleration::FootPerSquareSecond},
        {"ft/s/s", Unit::Acceleration::FootPerSquareSecond},
        {"ft/sec^2", Unit::Acceleration::FootPerSquareSecond},
        {"ft/sec2", Unit::Acceleration::FootPerSquareSecond},
        {"ft/sec/sec", Unit::Acceleration::FootPerSquareSecond},
        {"dm/s^2", Unit::Acceleration::DecimetrePerSquareSecond},
        {"dm/s2", Unit::Acceleration::DecimetrePerSquareSecond},
        {"dm/s/s", Unit::Acceleration::DecimetrePerSquareSecond},
        {"dm/sec^2", Unit::Acceleration::DecimetrePerSquareSecond},
        {"dm/sec2", Unit::Acceleration::DecimetrePerSquareSecond},
        {"dm/sec/sec", Unit::Acceleration::DecimetrePerSquareSecond},
        {"in/s^2", Unit::Acceleration::InchPerSquareSecond},
        {"in/s2", Unit::Acceleration::InchPerSquareSecond},
        {"in/s/s", Unit::Acceleration::InchPerSquareSecond},
        {"in/sec^2", Unit::Acceleration::InchPerSquareSecond},
        {"in/sec2", Unit::Acceleration::InchPerSquareSecond},
        {"in/sec/sec", Unit::Acceleration::InchPerSquareSecond},
        {"cm/s^2", Unit::Acceleration::CentimetrePerSquareSecond},
        {"cm/s2", Unit::Acceleration::CentimetrePerSquareSecond},
        {"cm/s/s", Unit::Acceleration::CentimetrePerSquareSecond},
        {"cm/sec^2", Unit::Acceleration::CentimetrePerSquareSecond},
        {"cm/sec2", Unit::Acceleration::CentimetrePerSquareSecond},
        {"cm/sec/sec", Unit::Acceleration::CentimetrePerSquareSecond},
        {"mm/s^2", Unit::Acceleration::MillimetrePerSquareSecond},
        {"mm/s2", Unit::Acceleration::MillimetrePerSquareSecond},
        {"mm/s/s", Unit::Acceleration::MillimetrePerSquareSecond},
        {"mm/sec^2", Unit::Acceleration::MillimetrePerSquareSecond},
        {"mm/sec2", Unit::Acceleration::MillimetrePerSquareSecond},
        {"mm/sec/sec", Unit::Acceleration::MillimetrePerSquareSecond},
        {"milin/s^2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"milin/s2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"milin/s/s", Unit::Acceleration::MilliinchPerSquareSecond},
        {"milin/sec^2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"milin/sec2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"milin/sec/sec", Unit::Acceleration::MilliinchPerSquareSecond},
        {"milliinch/s^2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"milliinch/s2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"milliinch/s/s", Unit::Acceleration::MilliinchPerSquareSecond},
        {"milliinch/sec^2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"milliinch/sec2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"milliinch/sec/sec", Unit::Acceleration::MilliinchPerSquareSecond},
        {"mil/s^2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"mil/s2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"mil/s/s", Unit::Acceleration::MilliinchPerSquareSecond},
        {"mil/sec^2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"mil/sec2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"mil/sec/sec", Unit::Acceleration::MilliinchPerSquareSecond},
        {"thou/s^2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"thou/s2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"thou/s/s", Unit::Acceleration::MilliinchPerSquareSecond},
        {"thou/sec^2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"thou/sec2", Unit::Acceleration::MilliinchPerSquareSecond},
        {"thou/sec/sec", Unit::Acceleration::MilliinchPerSquareSecond},
        {"μm/s^2", Unit::Acceleration::MicrometrePerSquareSecond},
        {"μm/s2", Unit::Acceleration::MicrometrePerSquareSecond},
        {"μm/s/s", Unit::Acceleration::MicrometrePerSquareSecond},
        {"μm/sec^2", Unit::Acceleration::MicrometrePerSquareSecond},
        {"μm/sec2", Unit::Acceleration::MicrometrePerSquareSecond},
        {"μm/sec/sec", Unit::Acceleration::MicrometrePerSquareSecond},
        {"um/s^2", Unit::Acceleration::MicrometrePerSquareSecond},
        {"um/s2", Unit::Acceleration::MicrometrePerSquareSecond},
        {"um/s/s", Unit::Acceleration::MicrometrePerSquareSecond},
        {"um/sec^2", Unit::Acceleration::MicrometrePerSquareSecond},
        {"um/sec2", Unit::Acceleration::MicrometrePerSquareSecond},
        {"um/sec/sec", Unit::Acceleration::MicrometrePerSquareSecond},
        {"μin/s^2", Unit::Acceleration::MicroinchPerSquareSecond},
        {"μin/s2", Unit::Acceleration::MicroinchPerSquareSecond},
        {"μin/s/s", Unit::Acceleration::MicroinchPerSquareSecond},
        {"μin/sec^2", Unit::Acceleration::MicroinchPerSquareSecond},
        {"μin/sec2", Unit::Acceleration::MicroinchPerSquareSecond},
        {"μin/sec/sec", Unit::Acceleration::MicroinchPerSquareSecond},
        {"uin/s^2", Unit::Acceleration::MicroinchPerSquareSecond},
        {"uin/s2", Unit::Acceleration::MicroinchPerSquareSecond},
        {"uin/s/s", Unit::Acceleration::MicroinchPerSquareSecond},
        {"uin/sec^2", Unit::Acceleration::MicroinchPerSquareSecond},
        {"uin/sec2", Unit::Acceleration::MicroinchPerSquareSecond},
        {"uin/sec/sec", Unit::Acceleration::MicroinchPerSquareSecond},
    };

template <>
inline const std::map<
    Unit::Acceleration,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::Acceleration>{
        {Unit::Acceleration::MilePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1609.344;
           }
         }},
        {Unit::Acceleration::KilometrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Acceleration::YardPerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.9144;
           }
         }},
        {Unit::Acceleration::MetrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Acceleration::FootPerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.3048;
           }
         }},
        {Unit::Acceleration::DecimetrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 10.0;
           }
         }},
        {Unit::Acceleration::InchPerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.0254;
           }
         }},
        {Unit::Acceleration::CentimetrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 100.0;
           }
         }},
        {Unit::Acceleration::MillimetrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Acceleration::MilliinchPerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.0000254;
           }
         }},
        {Unit::Acceleration::MicrometrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::Acceleration::MicroinchPerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.0000000254;
           }
         }},
    };

template <>
inline const std::map<
    Unit::Acceleration,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::Acceleration>{
        {Unit::Acceleration::MilePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1609.344;
           }
         }},
        {Unit::Acceleration::KilometrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Acceleration::YardPerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.9144;
           }
         }},
        {Unit::Acceleration::MetrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Acceleration::FootPerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.3048;
           }
         }},
        {Unit::Acceleration::DecimetrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.1;
           }
         }},
        {Unit::Acceleration::InchPerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0254;
           }
         }},
        {Unit::Acceleration::CentimetrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.01;
           }
         }},
        {Unit::Acceleration::MillimetrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Acceleration::MilliinchPerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0000254;
           }
         }},
        {Unit::Acceleration::MicrometrePerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::Acceleration::MicroinchPerSquareSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0000000254;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ACCELERATION_HPP
