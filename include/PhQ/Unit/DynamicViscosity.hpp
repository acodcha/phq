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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DYNAMIC_VISCOSITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DYNAMIC_VISCOSITY_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class DynamicViscosity : int_least8_t {
  PascalSecond,
  KilopascalSecond,
  MegapascalSecond,
  GigapascalSecond,
  PoundSecondPerSquareFoot,
  PoundSecondPerSquareInch,
};

}  // namespace Unit

template <>
inline constexpr const Unit::DynamicViscosity
    StandardUnit<Unit::DynamicViscosity>{Unit::DynamicViscosity::PascalSecond};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::DynamicViscosity>{
    Dimension::Set{Dimension::Time{-1}, Dimension::Length{-1},
                   Dimension::Mass{1}}};

template <>
inline const std::map<UnitSystem, Unit::DynamicViscosity>
    ConsistentUnits<Unit::DynamicViscosity>{
        {UnitSystem::MetreKilogramSecondKelvin,
         Unit::DynamicViscosity::PascalSecond},
        {UnitSystem::MillimetreGramSecondKelvin,
         Unit::DynamicViscosity::PascalSecond},
        {UnitSystem::FootPoundSecondRankine,
         Unit::DynamicViscosity::PoundSecondPerSquareFoot},
        {UnitSystem::InchPoundSecondRankine,
         Unit::DynamicViscosity::PoundSecondPerSquareInch},
    };

template <>
inline const std::map<Unit::DynamicViscosity, UnitSystem>
    RelatedUnitSystems<Unit::DynamicViscosity>{
        {Unit::DynamicViscosity::PoundSecondPerSquareFoot,
         UnitSystem::FootPoundSecondRankine},
        {Unit::DynamicViscosity::PoundSecondPerSquareInch,
         UnitSystem::InchPoundSecondRankine},
    };

template <>
inline const std::map<Unit::DynamicViscosity, std::string_view>
    Abbreviations<Unit::DynamicViscosity>{
        {Unit::DynamicViscosity::PascalSecond, "Pa·s"},
        {Unit::DynamicViscosity::KilopascalSecond, "kPa·s"},
        {Unit::DynamicViscosity::MegapascalSecond, "MPa·s"},
        {Unit::DynamicViscosity::GigapascalSecond, "GPa·s"},
        {Unit::DynamicViscosity::PoundSecondPerSquareFoot, "lbf·s/ft^2"},
        {Unit::DynamicViscosity::PoundSecondPerSquareInch, "lbf·s/in^2"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::DynamicViscosity>
    Spellings<Unit::DynamicViscosity>{
        {"Pa·s", Unit::DynamicViscosity::PascalSecond},
        {"Pa*s", Unit::DynamicViscosity::PascalSecond},
        {"N·s/m^2", Unit::DynamicViscosity::PascalSecond},
        {"N·s/m2", Unit::DynamicViscosity::PascalSecond},
        {"N*s/m^2", Unit::DynamicViscosity::PascalSecond},
        {"N*s/m2", Unit::DynamicViscosity::PascalSecond},
        {"kg/(m·s)", Unit::DynamicViscosity::PascalSecond},
        {"kg/(m*s)", Unit::DynamicViscosity::PascalSecond},
        {"kg/m/s", Unit::DynamicViscosity::PascalSecond},
        {"kPa·s", Unit::DynamicViscosity::KilopascalSecond},
        {"kPa*s", Unit::DynamicViscosity::KilopascalSecond},
        {"kN·s/m^2", Unit::DynamicViscosity::KilopascalSecond},
        {"kN·s/m2", Unit::DynamicViscosity::KilopascalSecond},
        {"kN*s/m^2", Unit::DynamicViscosity::KilopascalSecond},
        {"kN*s/m2", Unit::DynamicViscosity::KilopascalSecond},
        {"MPa·s", Unit::DynamicViscosity::MegapascalSecond},
        {"MPa*s", Unit::DynamicViscosity::MegapascalSecond},
        {"N·s/mm^2", Unit::DynamicViscosity::MegapascalSecond},
        {"N·s/mm^2", Unit::DynamicViscosity::MegapascalSecond},
        {"N*s/mm2", Unit::DynamicViscosity::MegapascalSecond},
        {"N*s/mm2", Unit::DynamicViscosity::MegapascalSecond},
        {"MN·s/m^2", Unit::DynamicViscosity::MegapascalSecond},
        {"MN·s/m2", Unit::DynamicViscosity::MegapascalSecond},
        {"MN*s/m^2", Unit::DynamicViscosity::MegapascalSecond},
        {"MN*s/m2", Unit::DynamicViscosity::MegapascalSecond},
        {"GPa·s", Unit::DynamicViscosity::GigapascalSecond},
        {"GPa*s", Unit::DynamicViscosity::GigapascalSecond},
        {"GN·s/m^2", Unit::DynamicViscosity::GigapascalSecond},
        {"GN·s/m2", Unit::DynamicViscosity::GigapascalSecond},
        {"GN*s/m^2", Unit::DynamicViscosity::GigapascalSecond},
        {"GN*s/m2", Unit::DynamicViscosity::GigapascalSecond},
        {"kN·s/mm^2", Unit::DynamicViscosity::GigapascalSecond},
        {"kN·s/mm2", Unit::DynamicViscosity::GigapascalSecond},
        {"kN*s/mm^2", Unit::DynamicViscosity::GigapascalSecond},
        {"kN*s/mm2", Unit::DynamicViscosity::GigapascalSecond},
        {"lbf·s/ft^2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
        {"lbf·s/ft2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
        {"lbf*s/ft^2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
        {"lbf*s/ft2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
        {"lb·s/ft^2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
        {"lb·s/ft2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
        {"lb*s/ft^2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
        {"lb*s/ft2", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
        {"psf·s", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
        {"psf*s", Unit::DynamicViscosity::PoundSecondPerSquareFoot},
        {"lbf·s/in^2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
        {"lbf·s/in2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
        {"lbf*s/in^2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
        {"lbf*s/in2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
        {"lb·s/in^2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
        {"lb·s/in2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
        {"lb*s/in^2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
        {"lb*s/in2", Unit::DynamicViscosity::PoundSecondPerSquareInch},
        {"psi·s", Unit::DynamicViscosity::PoundSecondPerSquareInch},
        {"psi*s", Unit::DynamicViscosity::PoundSecondPerSquareInch},
    };

template <>
inline const std::map<
    Unit::DynamicViscosity,
    std::function<void(double* const values, const std::size_t size)>>
    Internal::MapOfConversionsFromStandard<Unit::DynamicViscosity>{
        {Unit::DynamicViscosity::PascalSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::DynamicViscosity::KilopascalSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.001;
           }
         }},
        {Unit::DynamicViscosity::MegapascalSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000001;
           }
         }},
        {Unit::DynamicViscosity::GigapascalSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.000000001;
           }
         }},
        {Unit::DynamicViscosity::PoundSecondPerSquareFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.3048, 2) / (0.45359237 * 9.80665);
           }
         }},
        {Unit::DynamicViscosity::PoundSecondPerSquareInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(0.0254, 2) / (0.45359237 * 9.80665);
           }
         }},
    };

template <>
inline const std::map<
    Unit::DynamicViscosity,
    std::function<void(double* const values, const std::size_t size)>>
    Internal::MapOfConversionsToStandard<Unit::DynamicViscosity>{
        {Unit::DynamicViscosity::PascalSecond,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::DynamicViscosity::KilopascalSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::DynamicViscosity::MegapascalSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000.0;
           }
         }},
        {Unit::DynamicViscosity::GigapascalSecond,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000000000.0;
           }
         }},
        {Unit::DynamicViscosity::PoundSecondPerSquareFoot,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / std::pow(0.3048, 2);
           }
         }},
        {Unit::DynamicViscosity::PoundSecondPerSquareInch,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 0.45359237 * 9.80665 / std::pow(0.0254, 2);
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_DYNAMIC_VISCOSITY_HPP
