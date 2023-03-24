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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPEED_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPEED_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Speed : int_least8_t {
  MilePerSecond,
  KilometrePerSecond,
  MetrePerSecond,
  YardPerSecond,
  FootPerSecond,
  DecimetrePerSecond,
  InchPerSecond,
  CentimetrePerSecond,
  MillimetrePerSecond,
  MilliinchPerSecond,
  MicrometrePerSecond,
  MicroinchPerSecond,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Speed StandardUnit<Unit::Speed>{
    Unit::Speed::MetrePerSecond};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Speed>{
    Dimension::Set{Dimension::Time{-1}, Dimension::Length{1}}};

template <>
inline const std::map<UnitSystem, Unit::Speed> ConsistentUnits<Unit::Speed>{
    {UnitSystem::MetreKilogramSecondKelvin, Unit::Speed::MetrePerSecond},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Speed::MillimetrePerSecond},
    {UnitSystem::FootPoundSecondRankine, Unit::Speed::FootPerSecond},
    {UnitSystem::InchPoundSecondRankine, Unit::Speed::InchPerSecond},
};

template <>
inline const std::map<Unit::Speed, UnitSystem> RelatedUnitSystems<Unit::Speed>{
    {Unit::Speed::MetrePerSecond, UnitSystem::MetreKilogramSecondKelvin},
    {Unit::Speed::MillimetrePerSecond, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Speed::FootPerSecond, UnitSystem::FootPoundSecondRankine},
    {Unit::Speed::InchPerSecond, UnitSystem::InchPoundSecondRankine},
};

template <>
inline const std::map<Unit::Speed, std::string_view> Abbreviations<Unit::Speed>{
    {Unit::Speed::MilePerSecond, "mi/s"},
    {Unit::Speed::KilometrePerSecond, "km/s"},
    {Unit::Speed::MetrePerSecond, "m/s"},
    {Unit::Speed::YardPerSecond, "yd/s"},
    {Unit::Speed::FootPerSecond, "ft/s"},
    {Unit::Speed::DecimetrePerSecond, "dm/s"},
    {Unit::Speed::InchPerSecond, "in/s"},
    {Unit::Speed::CentimetrePerSecond, "cm/s"},
    {Unit::Speed::MillimetrePerSecond, "mm/s"},
    {Unit::Speed::MilliinchPerSecond, "mil/s"},
    {Unit::Speed::MicrometrePerSecond, "μm/s"},
    {Unit::Speed::MicroinchPerSecond, "μin/s"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Speed>
    Spellings<Unit::Speed>{
        {"mi/s", Unit::Speed::MilePerSecond},
        {"mi/sec", Unit::Speed::MilePerSecond},
        {"km/s", Unit::Speed::KilometrePerSecond},
        {"km/sec", Unit::Speed::KilometrePerSecond},
        {"m/s", Unit::Speed::MetrePerSecond},
        {"m/sec", Unit::Speed::MetrePerSecond},
        {"yd/s", Unit::Speed::YardPerSecond},
        {"yd/sec", Unit::Speed::YardPerSecond},
        {"ft/s", Unit::Speed::FootPerSecond},
        {"ft/sec", Unit::Speed::FootPerSecond},
        {"dm/s", Unit::Speed::DecimetrePerSecond},
        {"dm/sec", Unit::Speed::DecimetrePerSecond},
        {"in/s", Unit::Speed::InchPerSecond},
        {"in/sec", Unit::Speed::InchPerSecond},
        {"cm/s", Unit::Speed::CentimetrePerSecond},
        {"cm/sec", Unit::Speed::CentimetrePerSecond},
        {"mm/s", Unit::Speed::MillimetrePerSecond},
        {"mm/sec", Unit::Speed::MillimetrePerSecond},
        {"milin/s", Unit::Speed::MilliinchPerSecond},
        {"milin/sec", Unit::Speed::MilliinchPerSecond},
        {"milliinch/s", Unit::Speed::MilliinchPerSecond},
        {"milliinch/sec", Unit::Speed::MilliinchPerSecond},
        {"mil/s", Unit::Speed::MilliinchPerSecond},
        {"mil/sec", Unit::Speed::MilliinchPerSecond},
        {"thou/s", Unit::Speed::MilliinchPerSecond},
        {"thou/sec", Unit::Speed::MilliinchPerSecond},
        {"μm/s", Unit::Speed::MicrometrePerSecond},
        {"μm/sec", Unit::Speed::MicrometrePerSecond},
        {"um/s", Unit::Speed::MicrometrePerSecond},
        {"um/sec", Unit::Speed::MicrometrePerSecond},
        {"μin/s", Unit::Speed::MicroinchPerSecond},
        {"μin/sec", Unit::Speed::MicroinchPerSecond},
        {"uin/s", Unit::Speed::MicroinchPerSecond},
        {"uin/sec", Unit::Speed::MicroinchPerSecond},
    };

namespace Internal {

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::MilePerSecond>(
    double& value) noexcept {
  value /= 1609.344;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::KilometrePerSecond>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::MetrePerSecond>(
    double& value) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::YardPerSecond>(
    double& value) noexcept {
  value /= 0.9144;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::FootPerSecond>(
    double& value) noexcept {
  value /= 0.3048;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::DecimetrePerSecond>(
    double& value) noexcept {
  value *= 10.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::InchPerSecond>(
    double& value) noexcept {
  value /= 0.0254;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::CentimetrePerSecond>(
    double& value) noexcept {
  value *= 100.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::MillimetrePerSecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::MilliinchPerSecond>(
    double& value) noexcept {
  value /= 0.0000254;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::MicrometrePerSecond>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::Speed, Unit::Speed::MicroinchPerSecond>(
    double& value) noexcept {
  value /= 0.0000000254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::MilePerSecond>(
    double& value) noexcept {
  value *= 1609.344;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::KilometrePerSecond>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::MetrePerSecond>(
    double& value) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::YardPerSecond>(
    double& value) noexcept {
  value *= 0.9144;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::FootPerSecond>(
    double& value) noexcept {
  value *= 0.3048;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::DecimetrePerSecond>(
    double& value) noexcept {
  value *= 0.1;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::InchPerSecond>(
    double& value) noexcept {
  value *= 0.0254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::CentimetrePerSecond>(
    double& value) noexcept {
  value *= 0.01;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::MillimetrePerSecond>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::MilliinchPerSecond>(
    double& value) noexcept {
  value *= 0.0000254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::MicrometrePerSecond>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::Speed, Unit::Speed::MicroinchPerSecond>(
    double& value) noexcept {
  value *= 0.0000000254;
}

template <>
inline const std::map<
    Unit::Speed, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Speed>{
        {Unit::Speed::MilePerSecond,
         ConversionsFromStandard<Unit::Speed, Unit::Speed::MilePerSecond>},
        {Unit::Speed::KilometrePerSecond,
         ConversionsFromStandard<Unit::Speed, Unit::Speed::KilometrePerSecond>},
        {Unit::Speed::MetrePerSecond,
         ConversionsFromStandard<Unit::Speed, Unit::Speed::MetrePerSecond>},
        {Unit::Speed::YardPerSecond,
         ConversionsFromStandard<Unit::Speed, Unit::Speed::YardPerSecond>},
        {Unit::Speed::FootPerSecond,
         ConversionsFromStandard<Unit::Speed, Unit::Speed::FootPerSecond>},
        {Unit::Speed::DecimetrePerSecond,
         ConversionsFromStandard<Unit::Speed, Unit::Speed::DecimetrePerSecond>},
        {Unit::Speed::InchPerSecond,
         ConversionsFromStandard<Unit::Speed, Unit::Speed::InchPerSecond>},
        {Unit::Speed::CentimetrePerSecond,
         ConversionsFromStandard<Unit::Speed,
                                 Unit::Speed::CentimetrePerSecond>},
        {Unit::Speed::MillimetrePerSecond,
         ConversionsFromStandard<Unit::Speed,
                                 Unit::Speed::MillimetrePerSecond>},
        {Unit::Speed::MilliinchPerSecond,
         ConversionsFromStandard<Unit::Speed, Unit::Speed::MilliinchPerSecond>},
        {Unit::Speed::MicrometrePerSecond,
         ConversionsFromStandard<Unit::Speed,
                                 Unit::Speed::MicrometrePerSecond>},
        {Unit::Speed::MicroinchPerSecond,
         ConversionsFromStandard<Unit::Speed, Unit::Speed::MicroinchPerSecond>},
    };

template <>
inline const std::map<Unit::Speed, std::function<void(double* const values,
                                                      const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Speed>{
        {Unit::Speed::MilePerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::MilePerSecond>},
        {Unit::Speed::KilometrePerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::KilometrePerSecond>},
        {Unit::Speed::MetrePerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::MetrePerSecond>},
        {Unit::Speed::YardPerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::YardPerSecond>},
        {Unit::Speed::FootPerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::FootPerSecond>},
        {Unit::Speed::DecimetrePerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::DecimetrePerSecond>},
        {Unit::Speed::InchPerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::InchPerSecond>},
        {Unit::Speed::CentimetrePerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::CentimetrePerSecond>},
        {Unit::Speed::MillimetrePerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::MillimetrePerSecond>},
        {Unit::Speed::MilliinchPerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::MilliinchPerSecond>},
        {Unit::Speed::MicrometrePerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::MicrometrePerSecond>},
        {Unit::Speed::MicroinchPerSecond,
         ConversionsToStandard<Unit::Speed, Unit::Speed::MicroinchPerSecond>},
    };

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_SPEED_HPP
