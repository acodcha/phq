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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MEMORY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MEMORY_HPP

#include "Base.hpp"

namespace PhQ {

namespace Unit {

enum class Memory : int_least8_t {
  Bit,
  Byte,
  Kilobit,
  Kibibit,
  Kilobyte,
  Kibibyte,
  Megabit,
  Mebibit,
  Megabyte,
  Mebibyte,
  Gigabit,
  Gibibit,
  Gigabyte,
  Gibibyte,
  Terabit,
  Tebibit,
  Terabyte,
  Tebibyte,
  Petabit,
  Pebibit,
  Petabyte,
  Pebibyte,
};

}  // namespace Unit

template <>
inline constexpr const Unit::Memory StandardUnit<Unit::Memory>{
    Unit::Memory::Bit};

template <>
inline constexpr const Dimension::Set Dimensions<Unit::Memory>{
    Dimension::Set{}};

template <>
inline const std::map<UnitSystem, Unit::Memory> ConsistentUnits<Unit::Memory>{
    {UnitSystem::MetreKilogramSecondKelvin, Unit::Memory::Bit},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Memory::Bit},
    {UnitSystem::FootPoundSecondRankine, Unit::Memory::Bit},
    {UnitSystem::InchPoundSecondRankine, Unit::Memory::Bit},
};

template <>
inline const std::map<Unit::Memory, UnitSystem>
    RelatedUnitSystems<Unit::Memory>{};

template <>
inline const std::map<Unit::Memory, std::string_view>
    Abbreviations<Unit::Memory>{
        {Unit::Memory::Bit, "b"},       {Unit::Memory::Byte, "B"},
        {Unit::Memory::Kilobit, "kb"},  {Unit::Memory::Kibibit, "kib"},
        {Unit::Memory::Kilobyte, "kB"}, {Unit::Memory::Kibibyte, "kiB"},
        {Unit::Memory::Megabit, "Mb"},  {Unit::Memory::Mebibit, "Mib"},
        {Unit::Memory::Megabyte, "MB"}, {Unit::Memory::Mebibyte, "MiB"},
        {Unit::Memory::Gigabit, "Gb"},  {Unit::Memory::Gibibit, "Gib"},
        {Unit::Memory::Gigabyte, "GB"}, {Unit::Memory::Gibibyte, "GiB"},
        {Unit::Memory::Terabit, "Tb"},  {Unit::Memory::Tebibit, "Tib"},
        {Unit::Memory::Terabyte, "TB"}, {Unit::Memory::Tebibyte, "TiB"},
        {Unit::Memory::Petabit, "Pb"},  {Unit::Memory::Pebibit, "Pib"},
        {Unit::Memory::Petabyte, "PB"}, {Unit::Memory::Pebibyte, "PiB"},
    };

template <>
inline const std::unordered_map<std::string_view, Unit::Memory>
    Spellings<Unit::Memory>{
        {"b", Unit::Memory::Bit},
        {"bit", Unit::Memory::Bit},
        {"bits", Unit::Memory::Bit},
        {"B", Unit::Memory::Byte},
        {"byte", Unit::Memory::Byte},
        {"bytes", Unit::Memory::Byte},
        {"kb", Unit::Memory::Kilobit},
        {"kilobit", Unit::Memory::Kilobit},
        {"kilobits", Unit::Memory::Kilobit},
        {"kib", Unit::Memory::Kibibit},
        {"kibibit", Unit::Memory::Kibibit},
        {"kibibits", Unit::Memory::Kibibit},
        {"kB", Unit::Memory::Kilobyte},
        {"kilobyte", Unit::Memory::Kilobyte},
        {"kilobytes", Unit::Memory::Kilobyte},
        {"kiB", Unit::Memory::Kibibyte},
        {"kibibyte", Unit::Memory::Kibibyte},
        {"kibibytes", Unit::Memory::Kibibyte},
        {"Mb", Unit::Memory::Megabit},
        {"megabit", Unit::Memory::Megabit},
        {"megabits", Unit::Memory::Megabit},
        {"Mib", Unit::Memory::Mebibit},
        {"mebibit", Unit::Memory::Mebibit},
        {"mebibits", Unit::Memory::Mebibit},
        {"MB", Unit::Memory::Megabyte},
        {"megabyte", Unit::Memory::Megabyte},
        {"megabytes", Unit::Memory::Megabyte},
        {"MiB", Unit::Memory::Mebibyte},
        {"mebibyte", Unit::Memory::Mebibyte},
        {"mebibytes", Unit::Memory::Mebibyte},
        {"Gb", Unit::Memory::Gigabit},
        {"gigabit", Unit::Memory::Gigabit},
        {"gigabits", Unit::Memory::Gigabit},
        {"Gib", Unit::Memory::Gibibit},
        {"gibibit", Unit::Memory::Gibibit},
        {"gibibits", Unit::Memory::Gibibit},
        {"GB", Unit::Memory::Gigabyte},
        {"gigabyte", Unit::Memory::Gigabyte},
        {"gigabytes", Unit::Memory::Gigabyte},
        {"GiB", Unit::Memory::Gibibyte},
        {"gibibyte", Unit::Memory::Gibibyte},
        {"gibibytes", Unit::Memory::Gibibyte},
        {"Tb", Unit::Memory::Terabit},
        {"terabit", Unit::Memory::Terabit},
        {"terabits", Unit::Memory::Terabit},
        {"Tib", Unit::Memory::Tebibit},
        {"tebibit", Unit::Memory::Tebibit},
        {"tebibits", Unit::Memory::Tebibit},
        {"TB", Unit::Memory::Terabyte},
        {"terabyte", Unit::Memory::Terabyte},
        {"terabytes", Unit::Memory::Terabyte},
        {"TiB", Unit::Memory::Tebibyte},
        {"tebibyte", Unit::Memory::Tebibyte},
        {"tebibytes", Unit::Memory::Tebibyte},
        {"Pb", Unit::Memory::Petabit},
        {"petabit", Unit::Memory::Petabit},
        {"petabits", Unit::Memory::Petabit},
        {"Pib", Unit::Memory::Pebibit},
        {"pebibit", Unit::Memory::Pebibit},
        {"pebibits", Unit::Memory::Pebibit},
        {"PB", Unit::Memory::Petabyte},
        {"petabyte", Unit::Memory::Petabyte},
        {"petabytes", Unit::Memory::Petabyte},
        {"PiB", Unit::Memory::Pebibyte},
        {"pebibyte", Unit::Memory::Pebibyte},
        {"pebibytes", Unit::Memory::Pebibyte},
    };

template <>
inline const std::map<Unit::Memory, std::function<void(double* const values,
                                                       const std::size_t size)>>
    Internal::MapOfConversionsFromStandard<Unit::Memory>{
        {Unit::Memory::Bit,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Memory::Byte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0;
           }
         }},
        {Unit::Memory::Kilobit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1000.0;
           }
         }},
        {Unit::Memory::Kibibit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 1024.0;
           }
         }},
        {Unit::Memory::Kilobyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * 1000.0;
           }
         }},
        {Unit::Memory::Kibibyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * 1024.0;
           }
         }},
        {Unit::Memory::Megabit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1000.0, 2);
           }
         }},
        {Unit::Memory::Mebibit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1024.0, 2);
           }
         }},
        {Unit::Memory::Megabyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1000.0, 2);
           }
         }},
        {Unit::Memory::Mebibyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1024.0, 2);
           }
         }},
        {Unit::Memory::Gigabit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1000.0, 3);
           }
         }},
        {Unit::Memory::Gibibit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1024.0, 3);
           }
         }},
        {Unit::Memory::Gigabyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1000.0, 3);
           }
         }},
        {Unit::Memory::Gibibyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1024.0, 3);
           }
         }},
        {Unit::Memory::Terabit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1000.0, 4);
           }
         }},
        {Unit::Memory::Tebibit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1024.0, 4);
           }
         }},
        {Unit::Memory::Terabyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1000.0, 4);
           }
         }},
        {Unit::Memory::Tebibyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1024.0, 4);
           }
         }},
        {Unit::Memory::Petabit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1000.0, 5);
           }
         }},
        {Unit::Memory::Pebibit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= std::pow(1024.0, 5);
           }
         }},
        {Unit::Memory::Petabyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1000.0, 5);
           }
         }},
        {Unit::Memory::Pebibyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values /= 8.0 * std::pow(1024.0, 5);
           }
         }},
    };

template <>
inline const std::map<Unit::Memory, std::function<void(double* const values,
                                                       const std::size_t size)>>
    Internal::MapOfConversionsToStandard<Unit::Memory>{
        {Unit::Memory::Bit,
         [](double* values, const std::size_t size) -> void {}},
        {Unit::Memory::Byte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0;
           }
         }},
        {Unit::Memory::Kilobit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1000.0;
           }
         }},
        {Unit::Memory::Kibibit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 1024.0;
           }
         }},
        {Unit::Memory::Kilobyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * 1000.0;
           }
         }},
        {Unit::Memory::Kibibyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * 1024.0;
           }
         }},
        {Unit::Memory::Megabit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 2);
           }
         }},
        {Unit::Memory::Mebibit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1024.0, 2);
           }
         }},
        {Unit::Memory::Megabyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1000.0, 2);
           }
         }},
        {Unit::Memory::Mebibyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1024.0, 2);
           }
         }},
        {Unit::Memory::Gigabit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 3);
           }
         }},
        {Unit::Memory::Gibibit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1024.0, 3);
           }
         }},
        {Unit::Memory::Gigabyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1000.0, 3);
           }
         }},
        {Unit::Memory::Gibibyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1024.0, 3);
           }
         }},
        {Unit::Memory::Terabit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 4);
           }
         }},
        {Unit::Memory::Tebibit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1024.0, 4);
           }
         }},
        {Unit::Memory::Terabyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1000.0, 4);
           }
         }},
        {Unit::Memory::Tebibyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1024.0, 4);
           }
         }},
        {Unit::Memory::Petabit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1000.0, 5);
           }
         }},
        {Unit::Memory::Pebibit,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= std::pow(1024.0, 5);
           }
         }},
        {Unit::Memory::Petabyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1000.0, 5);
           }
         }},
        {Unit::Memory::Pebibyte,
         [](double* values, const std::size_t size) -> void {
           const double* const end{values + size};
           for (; values < end; ++values) {
             *values *= 8.0 * std::pow(1024.0, 5);
           }
         }},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MEMORY_HPP
