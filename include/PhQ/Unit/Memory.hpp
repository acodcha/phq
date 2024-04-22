// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MEMORY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MEMORY_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

// Computer memory units.
enum class Memory : int8_t {
  // Bit (b) memory unit.
  Bit,

  // Byte (B) memory unit.
  Byte,

  // Kilobit (kb) memory unit.
  Kilobit,

  // Kibibit (kib) memory unit.
  Kibibit,

  // Kilobyte (kB) memory unit.
  Kilobyte,

  // Kibibyte (kiB) memory unit.
  Kibibyte,

  // Megabit (Mb) memory unit.
  Megabit,

  // Mebibit (Mib) memory unit.
  Mebibit,

  // Megabyte (MB) memory unit.
  Megabyte,

  // Mebibyte (MiB) memory unit.
  Mebibyte,

  // Gigabit (Gb) memory unit.
  Gigabit,

  // Gibibit (Gib) memory unit.
  Gibibit,

  // Gigabyte (GB) memory unit.
  Gigabyte,

  // Gibibyte (GiB) memory unit.
  Gibibyte,

  // Terabit (Tb) memory unit.
  Terabit,

  // Tebibit (Tib) memory unit.
  Tebibit,

  // Terabyte (TB) memory unit.
  Terabyte,

  // Tebibyte (TiB) memory unit.
  Tebibyte,

  // Petabit (Pb) memory unit.
  Petabit,

  // Pebibit (Pib) memory unit.
  Pebibit,

  // Petabyte (PB) memory unit.
  Petabyte,

  // Pebibyte (PiB) memory unit.
  Pebibyte,
};

}  // namespace Unit

// Standard computer memory unit: bit (b).
template <>
inline constexpr const Unit::Memory Standard<Unit::Memory>{Unit::Memory::Bit};

// Physical dimension set of computer memory units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Memory>{Dimensionless};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Memory unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Memory> ConsistentUnits<Unit::Memory>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Memory::Bit},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Memory::Bit},
    {UnitSystem::FootPoundSecondRankine,     Unit::Memory::Bit},
    {UnitSystem::InchPoundSecondRankine,     Unit::Memory::Bit},
};

template <>
inline const std::map<Unit::Memory, UnitSystem> RelatedUnitSystems<Unit::Memory>{};

template <>
inline const std::map<Unit::Memory, std::string_view> Abbreviations<Unit::Memory>{
    {Unit::Memory::Bit,      "b"  },
    {Unit::Memory::Byte,     "B"  },
    {Unit::Memory::Kilobit,  "kb" },
    {Unit::Memory::Kibibit,  "kib"},
    {Unit::Memory::Kilobyte, "kB" },
    {Unit::Memory::Kibibyte, "kiB"},
    {Unit::Memory::Megabit,  "Mb" },
    {Unit::Memory::Mebibit,  "Mib"},
    {Unit::Memory::Megabyte, "MB" },
    {Unit::Memory::Mebibyte, "MiB"},
    {Unit::Memory::Gigabit,  "Gb" },
    {Unit::Memory::Gibibit,  "Gib"},
    {Unit::Memory::Gigabyte, "GB" },
    {Unit::Memory::Gibibyte, "GiB"},
    {Unit::Memory::Terabit,  "Tb" },
    {Unit::Memory::Tebibit,  "Tib"},
    {Unit::Memory::Terabyte, "TB" },
    {Unit::Memory::Tebibyte, "TiB"},
    {Unit::Memory::Petabit,  "Pb" },
    {Unit::Memory::Pebibit,  "Pib"},
    {Unit::Memory::Petabyte, "PB" },
    {Unit::Memory::Pebibyte, "PiB"},
};

template <>
inline const std::unordered_map<std::string_view, Unit::Memory> Spellings<Unit::Memory>{
    {"b",         Unit::Memory::Bit     },
    {"bit",       Unit::Memory::Bit     },
    {"bits",      Unit::Memory::Bit     },
    {"B",         Unit::Memory::Byte    },
    {"byte",      Unit::Memory::Byte    },
    {"bytes",     Unit::Memory::Byte    },
    {"kb",        Unit::Memory::Kilobit },
    {"kilobit",   Unit::Memory::Kilobit },
    {"kilobits",  Unit::Memory::Kilobit },
    {"kib",       Unit::Memory::Kibibit },
    {"kibibit",   Unit::Memory::Kibibit },
    {"kibibits",  Unit::Memory::Kibibit },
    {"kB",        Unit::Memory::Kilobyte},
    {"kilobyte",  Unit::Memory::Kilobyte},
    {"kilobytes", Unit::Memory::Kilobyte},
    {"kiB",       Unit::Memory::Kibibyte},
    {"kibibyte",  Unit::Memory::Kibibyte},
    {"kibibytes", Unit::Memory::Kibibyte},
    {"Mb",        Unit::Memory::Megabit },
    {"megabit",   Unit::Memory::Megabit },
    {"megabits",  Unit::Memory::Megabit },
    {"Mib",       Unit::Memory::Mebibit },
    {"mebibit",   Unit::Memory::Mebibit },
    {"mebibits",  Unit::Memory::Mebibit },
    {"MB",        Unit::Memory::Megabyte},
    {"megabyte",  Unit::Memory::Megabyte},
    {"megabytes", Unit::Memory::Megabyte},
    {"MiB",       Unit::Memory::Mebibyte},
    {"mebibyte",  Unit::Memory::Mebibyte},
    {"mebibytes", Unit::Memory::Mebibyte},
    {"Gb",        Unit::Memory::Gigabit },
    {"gigabit",   Unit::Memory::Gigabit },
    {"gigabits",  Unit::Memory::Gigabit },
    {"Gib",       Unit::Memory::Gibibit },
    {"gibibit",   Unit::Memory::Gibibit },
    {"gibibits",  Unit::Memory::Gibibit },
    {"GB",        Unit::Memory::Gigabyte},
    {"gigabyte",  Unit::Memory::Gigabyte},
    {"gigabytes", Unit::Memory::Gigabyte},
    {"GiB",       Unit::Memory::Gibibyte},
    {"gibibyte",  Unit::Memory::Gibibyte},
    {"gibibytes", Unit::Memory::Gibibyte},
    {"Tb",        Unit::Memory::Terabit },
    {"terabit",   Unit::Memory::Terabit },
    {"terabits",  Unit::Memory::Terabit },
    {"Tib",       Unit::Memory::Tebibit },
    {"tebibit",   Unit::Memory::Tebibit },
    {"tebibits",  Unit::Memory::Tebibit },
    {"TB",        Unit::Memory::Terabyte},
    {"terabyte",  Unit::Memory::Terabyte},
    {"terabytes", Unit::Memory::Terabyte},
    {"TiB",       Unit::Memory::Tebibyte},
    {"tebibyte",  Unit::Memory::Tebibyte},
    {"tebibytes", Unit::Memory::Tebibyte},
    {"Pb",        Unit::Memory::Petabit },
    {"petabit",   Unit::Memory::Petabit },
    {"petabits",  Unit::Memory::Petabit },
    {"Pib",       Unit::Memory::Pebibit },
    {"pebibit",   Unit::Memory::Pebibit },
    {"pebibits",  Unit::Memory::Pebibit },
    {"PB",        Unit::Memory::Petabyte},
    {"petabyte",  Unit::Memory::Petabyte},
    {"petabytes", Unit::Memory::Petabyte},
    {"PiB",       Unit::Memory::Pebibyte},
    {"pebibyte",  Unit::Memory::Pebibyte},
    {"pebibytes", Unit::Memory::Pebibyte},
};

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Bit>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Bit>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Byte>(
    double& value) noexcept {
  value *= 0.125;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Byte>(
    double& value) noexcept {
  value *= 8.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Kilobit>(
    double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Kilobit>(
    double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Kibibit>(
    double& value) noexcept {
  value *= 1.0 / 1024.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Kibibit>(
    double& value) noexcept {
  value *= 1024.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Kilobyte>(
    double& value) noexcept {
  value *= 1.0 / 8000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Kilobyte>(
    double& value) noexcept {
  value *= 8000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Kibibyte>(
    double& value) noexcept {
  value *= 1.0 / (8.0 * 1024.0);
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Kibibyte>(
    double& value) noexcept {
  value *= 8.0 * 1024.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Megabit>(
    double& value) noexcept {
  value *= 0.000001;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Megabit>(
    double& value) noexcept {
  value *= 1000000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Mebibit>(
    double& value) noexcept {
  value *= 1.0 / (1024.0 * 1024.0);
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Mebibit>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Megabyte>(
    double& value) noexcept {
  value *= 1.0 / 8000000.0;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Megabyte>(
    double& value) noexcept {
  value *= 8000000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Mebibyte>(
    double& value) noexcept {
  value *= 1.0 / (8.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Mebibyte>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Gigabit>(
    double& value) noexcept {
  value *= 1.0e-9;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Gigabit>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Gibibit>(
    double& value) noexcept {
  value *= 1.0 / (1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Gibibit>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Gigabyte>(
    double& value) noexcept {
  value *= 1.0 / 8.0e9;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Gigabyte>(
    double& value) noexcept {
  value *= 8.0e9;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Gibibyte>(
    double& value) noexcept {
  value *= 1.0 / (8.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Gibibyte>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Terabit>(
    double& value) noexcept {
  value *= 1.0e-12;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Terabit>(
    double& value) noexcept {
  value *= 1.0e12;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Tebibit>(
    double& value) noexcept {
  value *= 1.0 / (1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Tebibit>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Terabyte>(
    double& value) noexcept {
  value *= 1.0 / 8.0e12;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Terabyte>(
    double& value) noexcept {
  value *= 8.0e12;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Tebibyte>(
    double& value) noexcept {
  value *= 1.0 / (8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Tebibyte>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Petabit>(
    double& value) noexcept {
  value *= 1.0e-15;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Petabit>(
    double& value) noexcept {
  value *= 1.0e15;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Pebibit>(
    double& value) noexcept {
  value *= 1.0 / (1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Pebibit>(
    double& value) noexcept {
  value *= 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Petabyte>(
    double& value) noexcept {
  value *= 1.0 / 8.0e15;
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Petabyte>(
    double& value) noexcept {
  value *= 8.0e15;
}

template <>
inline constexpr void ConversionFromStandard<Unit::Memory, Unit::Memory::Pebibyte>(
    double& value) noexcept {
  value *= 1.0 / (8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0);
}

template <>
inline constexpr void ConversionToStandard<Unit::Memory, Unit::Memory::Pebibyte>(
    double& value) noexcept {
  value *= 8.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0 * 1024.0;
}

template <>
inline const std::map<Unit::Memory, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Memory>{
        {Unit::Memory::Bit,      ConversionsFromStandard<Unit::Memory, Unit::Memory::Bit>     },
        {Unit::Memory::Byte,     ConversionsFromStandard<Unit::Memory, Unit::Memory::Byte>    },
        {Unit::Memory::Kilobit,  ConversionsFromStandard<Unit::Memory, Unit::Memory::Kilobit> },
        {Unit::Memory::Kibibit,  ConversionsFromStandard<Unit::Memory, Unit::Memory::Kibibit> },
        {Unit::Memory::Kilobyte, ConversionsFromStandard<Unit::Memory, Unit::Memory::Kilobyte>},
        {Unit::Memory::Kibibyte, ConversionsFromStandard<Unit::Memory, Unit::Memory::Kibibyte>},
        {Unit::Memory::Megabit,  ConversionsFromStandard<Unit::Memory, Unit::Memory::Megabit> },
        {Unit::Memory::Mebibit,  ConversionsFromStandard<Unit::Memory, Unit::Memory::Mebibit> },
        {Unit::Memory::Megabyte, ConversionsFromStandard<Unit::Memory, Unit::Memory::Megabyte>},
        {Unit::Memory::Mebibyte, ConversionsFromStandard<Unit::Memory, Unit::Memory::Mebibyte>},
        {Unit::Memory::Gigabit,  ConversionsFromStandard<Unit::Memory, Unit::Memory::Gigabit> },
        {Unit::Memory::Gibibit,  ConversionsFromStandard<Unit::Memory, Unit::Memory::Gibibit> },
        {Unit::Memory::Gigabyte, ConversionsFromStandard<Unit::Memory, Unit::Memory::Gigabyte>},
        {Unit::Memory::Gibibyte, ConversionsFromStandard<Unit::Memory, Unit::Memory::Gibibyte>},
        {Unit::Memory::Terabit,  ConversionsFromStandard<Unit::Memory, Unit::Memory::Terabit> },
        {Unit::Memory::Tebibit,  ConversionsFromStandard<Unit::Memory, Unit::Memory::Tebibit> },
        {Unit::Memory::Terabyte, ConversionsFromStandard<Unit::Memory, Unit::Memory::Terabyte>},
        {Unit::Memory::Tebibyte, ConversionsFromStandard<Unit::Memory, Unit::Memory::Tebibyte>},
        {Unit::Memory::Petabit,  ConversionsFromStandard<Unit::Memory, Unit::Memory::Petabit> },
        {Unit::Memory::Pebibit,  ConversionsFromStandard<Unit::Memory, Unit::Memory::Pebibit> },
        {Unit::Memory::Petabyte, ConversionsFromStandard<Unit::Memory, Unit::Memory::Petabyte>},
        {Unit::Memory::Pebibyte, ConversionsFromStandard<Unit::Memory, Unit::Memory::Pebibyte>},
};

template <>
inline const std::map<Unit::Memory,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Memory>{
        {Unit::Memory::Bit,      ConversionsToStandard<Unit::Memory, Unit::Memory::Bit>     },
        {Unit::Memory::Byte,     ConversionsToStandard<Unit::Memory, Unit::Memory::Byte>    },
        {Unit::Memory::Kilobit,  ConversionsToStandard<Unit::Memory, Unit::Memory::Kilobit> },
        {Unit::Memory::Kibibit,  ConversionsToStandard<Unit::Memory, Unit::Memory::Kibibit> },
        {Unit::Memory::Kilobyte, ConversionsToStandard<Unit::Memory, Unit::Memory::Kilobyte>},
        {Unit::Memory::Kibibyte, ConversionsToStandard<Unit::Memory, Unit::Memory::Kibibyte>},
        {Unit::Memory::Megabit,  ConversionsToStandard<Unit::Memory, Unit::Memory::Megabit> },
        {Unit::Memory::Mebibit,  ConversionsToStandard<Unit::Memory, Unit::Memory::Mebibit> },
        {Unit::Memory::Megabyte, ConversionsToStandard<Unit::Memory, Unit::Memory::Megabyte>},
        {Unit::Memory::Mebibyte, ConversionsToStandard<Unit::Memory, Unit::Memory::Mebibyte>},
        {Unit::Memory::Gigabit,  ConversionsToStandard<Unit::Memory, Unit::Memory::Gigabit> },
        {Unit::Memory::Gibibit,  ConversionsToStandard<Unit::Memory, Unit::Memory::Gibibit> },
        {Unit::Memory::Gigabyte, ConversionsToStandard<Unit::Memory, Unit::Memory::Gigabyte>},
        {Unit::Memory::Gibibyte, ConversionsToStandard<Unit::Memory, Unit::Memory::Gibibyte>},
        {Unit::Memory::Terabit,  ConversionsToStandard<Unit::Memory, Unit::Memory::Terabit> },
        {Unit::Memory::Tebibit,  ConversionsToStandard<Unit::Memory, Unit::Memory::Tebibit> },
        {Unit::Memory::Terabyte, ConversionsToStandard<Unit::Memory, Unit::Memory::Terabyte>},
        {Unit::Memory::Tebibyte, ConversionsToStandard<Unit::Memory, Unit::Memory::Tebibyte>},
        {Unit::Memory::Petabit,  ConversionsToStandard<Unit::Memory, Unit::Memory::Petabit> },
        {Unit::Memory::Pebibit,  ConversionsToStandard<Unit::Memory, Unit::Memory::Pebibit> },
        {Unit::Memory::Petabyte, ConversionsToStandard<Unit::Memory, Unit::Memory::Petabyte>},
        {Unit::Memory::Pebibyte, ConversionsToStandard<Unit::Memory, Unit::Memory::Pebibyte>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MEMORY_HPP
