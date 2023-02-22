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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_LENGTH_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_LENGTH_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Length : int_least8_t {
  Mile,
  Kilometre,
  Yard,
  Metre,
  Foot,
  Decimetre,
  Inch,
  Centimetre,
  Millimetre,
  Milliinch,
  Micrometre,
  Microinch,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Length StandardUnit<Unit::Length>{
    Unit::Length::Metre};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Length>{
    Dimension::Set{Dimension::Time{0}, Dimension::Length{1}}};

template <>
inline const std::map<UnitSystem, Unit::Length> ConsistentUnits<Unit::Length>{
    {UnitSystem::MetreKilogramSecondKelvin, Unit::Length::Metre},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Length::Millimetre},
    {UnitSystem::FootPoundSecondRankine, Unit::Length::Foot},
    {UnitSystem::InchPoundSecondRankine, Unit::Length::Inch},
};

template <>
inline const std::map<Unit::Length, UnitSystem>
    RelatedUnitSystems<Unit::Length>{
        {Unit::Length::Metre, UnitSystem::MetreKilogramSecondKelvin},
        {Unit::Length::Millimetre, UnitSystem::MillimetreGramSecondKelvin},
        {Unit::Length::Foot, UnitSystem::FootPoundSecondRankine},
        {Unit::Length::Inch, UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::Length, std::string_view>
    Abbreviations<Unit::Length>{
        {Unit::Length::Mile, "mi"},       {Unit::Length::Kilometre, "km"},
        {Unit::Length::Yard, "yd"},       {Unit::Length::Metre, "m"},
        {Unit::Length::Foot, "ft"},       {Unit::Length::Decimetre, "dm"},
        {Unit::Length::Inch, "in"},       {Unit::Length::Centimetre, "cm"},
        {Unit::Length::Millimetre, "mm"}, {Unit::Length::Milliinch, "mil"},
        {Unit::Length::Micrometre, "μm"}, {Unit::Length::Microinch, "μin"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::Length>
    Spellings<Unit::Length>{
        {"mi", Unit::Length::Mile},
        {"mile", Unit::Length::Mile},
        {"miles", Unit::Length::Mile},
        {"km", Unit::Length::Kilometre},
        {"kilometer", Unit::Length::Kilometre},
        {"kilometers", Unit::Length::Kilometre},
        {"kilometre", Unit::Length::Kilometre},
        {"kilometres", Unit::Length::Kilometre},
        {"yd", Unit::Length::Yard},
        {"yard", Unit::Length::Yard},
        {"yards", Unit::Length::Yard},
        {"m", Unit::Length::Metre},
        {"meter", Unit::Length::Metre},
        {"meters", Unit::Length::Metre},
        {"metre", Unit::Length::Metre},
        {"metres", Unit::Length::Metre},
        {"ft", Unit::Length::Foot},
        {"foot", Unit::Length::Foot},
        {"feet", Unit::Length::Foot},
        {"dm", Unit::Length::Decimetre},
        {"decimeter", Unit::Length::Decimetre},
        {"decimeters", Unit::Length::Decimetre},
        {"decimetre", Unit::Length::Decimetre},
        {"decimetres", Unit::Length::Decimetre},
        {"in", Unit::Length::Inch},
        {"inch", Unit::Length::Inch},
        {"inches", Unit::Length::Inch},
        {"cm", Unit::Length::Centimetre},
        {"centimeter", Unit::Length::Centimetre},
        {"centimeters", Unit::Length::Centimetre},
        {"centimetre", Unit::Length::Centimetre},
        {"centimetres", Unit::Length::Centimetre},
        {"mm", Unit::Length::Millimetre},
        {"millimeter", Unit::Length::Millimetre},
        {"millimeters", Unit::Length::Millimetre},
        {"millimetre", Unit::Length::Millimetre},
        {"millimetres", Unit::Length::Millimetre},
        {"milin", Unit::Length::Milliinch},
        {"milliinch", Unit::Length::Milliinch},
        {"milliinches", Unit::Length::Milliinch},
        {"mil", Unit::Length::Milliinch},
        {"mils", Unit::Length::Milliinch},
        {"thou", Unit::Length::Milliinch},
        {"thous", Unit::Length::Milliinch},
        {"thousandth", Unit::Length::Milliinch},
        {"thousandths", Unit::Length::Milliinch},
        {"μm", Unit::Length::Micrometre},
        {"um", Unit::Length::Micrometre},
        {"micrometer", Unit::Length::Micrometre},
        {"micrometers", Unit::Length::Micrometre},
        {"Micrometre", Unit::Length::Micrometre},
        {"Micrometres", Unit::Length::Micrometre},
        {"micron", Unit::Length::Micrometre},
        {"microns", Unit::Length::Micrometre},
        {"μin", Unit::Length::Microinch},
        {"uin", Unit::Length::Microinch},
        {"microinch", Unit::Length::Microinch},
        {"microinches", Unit::Length::Microinch},
    };

template <>
inline const std::map<Unit::Length, std::function<void(double* const values,
                                                       const std::size_t size)>>
    ConversionsFromStandard<Unit::Length>{
        {Unit::Length::Mile,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1609.344;
           }
         }},
        {Unit::Length::Kilometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Length::Yard,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.9144;
           }
         }},
        {Unit::Length::Metre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Length::Foot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.3048;
           }
         }},
        {Unit::Length::Decimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 10.0;
           }
         }},
        {Unit::Length::Inch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.0254;
           }
         }},
        {Unit::Length::Centimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 100.0;
           }
         }},
        {Unit::Length::Millimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Length::Milliinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.0000254;
           }
         }},
        {Unit::Length::Micrometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::Length::Microinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 0.0000000254;
           }
         }},
    };

template <>
inline const std::map<Unit::Length, std::function<void(double* const values,
                                                       const std::size_t size)>>
    ConversionsToStandard<Unit::Length>{
        {Unit::Length::Mile,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1609.344;
           }
         }},
        {Unit::Length::Kilometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Length::Yard,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.9144;
           }
         }},
        {Unit::Length::Metre,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Length::Foot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.3048;
           }
         }},
        {Unit::Length::Decimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.1;
           }
         }},
        {Unit::Length::Inch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0254;
           }
         }},
        {Unit::Length::Centimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.01;
           }
         }},
        {Unit::Length::Millimetre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Length::Milliinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0000254;
           }
         }},
        {Unit::Length::Micrometre,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::Length::Microinch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.0000000254;
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_LENGTH_HPP
