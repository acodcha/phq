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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_PRESSURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_PRESSURE_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Pressure : int_least8_t {
  Pascal,
  Kilopascal,
  Megapascal,
  Gigapascal,
  Bar,
  Atmosphere,
  PoundPerSquareFoot,
  PoundPerSquareInch,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Pressure StandardUnit<Unit::Pressure>{
    Unit::Pressure::Pascal};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Pressure>{Dimension::Set{
    Dimension::Time{-2}, Dimension::Length{-1}, Dimension::Mass{1}}};

template <>
inline const std::map<UnitSystem, Unit::Pressure>
    ConsistentUnits<Unit::Pressure>{
        {UnitSystem::MetreKilogramSecondKelvin, Unit::Pressure::Pascal},
        {UnitSystem::MillimetreGramSecondKelvin, Unit::Pressure::Pascal},
        {UnitSystem::FootPoundSecondRankine,
         Unit::Pressure::PoundPerSquareFoot},
        {UnitSystem::InchPoundSecondRankine,
         Unit::Pressure::PoundPerSquareInch},
    };

template <>
inline const std::map<Unit::Pressure, UnitSystem>
    RelatedUnitSystems<Unit::Pressure>{
        {Unit::Pressure::PoundPerSquareFoot,
         UnitSystem::FootPoundSecondRankine},
        {Unit::Pressure::PoundPerSquareInch,
         UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::Pressure, std::string_view>
    Abbreviations<Unit::Pressure>{
        {Unit::Pressure::Pascal, "Pa"},
        {Unit::Pressure::Kilopascal, "kPa"},
        {Unit::Pressure::Megapascal, "MPa"},
        {Unit::Pressure::Gigapascal, "GPa"},
        {Unit::Pressure::Bar, "bar"},
        {Unit::Pressure::Atmosphere, "atm"},
        {Unit::Pressure::PoundPerSquareFoot, "lbf/ft^2"},
        {Unit::Pressure::PoundPerSquareInch, "lbf/in^2"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::Pressure>
    Spellings<Unit::Pressure>{
        {"Pa", Unit::Pressure::Pascal},
        {"N/m^2", Unit::Pressure::Pascal},
        {"N/m2", Unit::Pressure::Pascal},
        {"kg/(m·s^2)", Unit::Pressure::Pascal},
        {"kg/(m·s2)", Unit::Pressure::Pascal},
        {"kg/(m*s^2)", Unit::Pressure::Pascal},
        {"kg/(m*s2)", Unit::Pressure::Pascal},
        {"kg/m/s^2", Unit::Pressure::Pascal},
        {"kg/m/s2", Unit::Pressure::Pascal},
        {"kPa", Unit::Pressure::Kilopascal},
        {"kN/m^2", Unit::Pressure::Kilopascal},
        {"kN/m2", Unit::Pressure::Kilopascal},
        {"MPa", Unit::Pressure::Megapascal},
        {"N/mm^2", Unit::Pressure::Megapascal},
        {"N/mm2", Unit::Pressure::Megapascal},
        {"MN/m^2", Unit::Pressure::Megapascal},
        {"MN/m2", Unit::Pressure::Megapascal},
        {"GPa", Unit::Pressure::Gigapascal},
        {"GN/m^2", Unit::Pressure::Gigapascal},
        {"GN/m2", Unit::Pressure::Gigapascal},
        {"kN/mm^2", Unit::Pressure::Gigapascal},
        {"kN/mm2", Unit::Pressure::Gigapascal},
        {"bar", Unit::Pressure::Bar},
        {"atm", Unit::Pressure::Atmosphere},
        {"atmosphere", Unit::Pressure::Atmosphere},
        {"lbf/ft^2", Unit::Pressure::PoundPerSquareFoot},
        {"lbf/ft2", Unit::Pressure::PoundPerSquareFoot},
        {"lb/ft^2", Unit::Pressure::PoundPerSquareFoot},
        {"lb/ft2", Unit::Pressure::PoundPerSquareFoot},
        {"psf", Unit::Pressure::PoundPerSquareFoot},
        {"lbf/in^2", Unit::Pressure::PoundPerSquareInch},
        {"lbf/in2", Unit::Pressure::PoundPerSquareInch},
        {"lb/in^2", Unit::Pressure::PoundPerSquareInch},
        {"lb/in2", Unit::Pressure::PoundPerSquareInch},
        {"psi", Unit::Pressure::PoundPerSquareInch},
    };

template <>
inline const std::map<
    Unit::Pressure,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsFromStandard<Unit::Pressure>{
        {Unit::Pressure::Pascal,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Pressure::Kilopascal,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::Pressure::Megapascal,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::Pressure::Gigapascal,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000000001;
           }
         }},
        {Unit::Pressure::Bar,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.00001;
           }
         }},
        {Unit::Pressure::Atmosphere,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 101325.0;
           }
         }},
        {Unit::Pressure::PoundPerSquareFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.3048, 2) / (0.45359237 * 9.80665);
           }
         }},
        {Unit::Pressure::PoundPerSquareInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0254, 2) / (0.45359237 * 9.80665);
           }
         }},
    };

template <>
inline const std::map<
    Unit::Pressure,
    std::function<void(double* const values, const std::size_t size)>>
    ConversionsToStandard<Unit::Pressure>{
        {Unit::Pressure::Pascal,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Pressure::Kilopascal,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Pressure::Megapascal,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::Pressure::Gigapascal,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000000.0;
           }
         }},
        {Unit::Pressure::Bar,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 100000.0;
           }
         }},
        {Unit::Pressure::Atmosphere,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 101325.0;
           }
         }},
        {Unit::Pressure::PoundPerSquareFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / std::pow(0.3048, 2);
           }
         }},
        {Unit::Pressure::PoundPerSquareInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / std::pow(0.0254, 2);
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_PRESSURE_HPP
