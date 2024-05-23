// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_UNIT_MEMORY_HPP
#define PHQ_UNIT_MEMORY_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimension/ElectricCurrent.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/LuminousIntensity.hpp"
#include "../Dimension/Mass.hpp"
#include "../Dimension/SubstanceAmount.hpp"
#include "../Dimension/Temperature.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

/// \brief Computer memory units.
enum class Memory : int8_t {
  /// \brief Bit (b) memory unit.
  Bit,

  /// \brief Byte (B) memory unit.
  Byte,

  /// \brief Kilobit (kb) memory unit.
  Kilobit,

  /// \brief Kibibit (kib) memory unit.
  Kibibit,

  /// \brief Kilobyte (kB) memory unit.
  Kilobyte,

  /// \brief Kibibyte (kiB) memory unit.
  Kibibyte,

  /// \brief Megabit (Mb) memory unit.
  Megabit,

  /// \brief Mebibit (Mib) memory unit.
  Mebibit,

  /// \brief Megabyte (MB) memory unit.
  Megabyte,

  /// \brief Mebibyte (MiB) memory unit.
  Mebibyte,

  /// \brief Gigabit (Gb) memory unit.
  Gigabit,

  /// \brief Gibibit (Gib) memory unit.
  Gibibit,

  /// \brief Gigabyte (GB) memory unit.
  Gigabyte,

  /// \brief Gibibyte (GiB) memory unit.
  Gibibyte,

  /// \brief Terabit (Tb) memory unit.
  Terabit,

  /// \brief Tebibit (Tib) memory unit.
  Tebibit,

  /// \brief Terabyte (TB) memory unit.
  Terabyte,

  /// \brief Tebibyte (TiB) memory unit.
  Tebibyte,

  /// \brief Petabit (Pb) memory unit.
  Petabit,

  /// \brief Pebibit (Pib) memory unit.
  Pebibit,

  /// \brief Petabyte (PB) memory unit.
  Petabyte,

  /// \brief Pebibyte (PiB) memory unit.
  Pebibyte,
};

}  // namespace Unit

/// \brief Standard computer memory unit: bit (b).
template <>
inline constexpr const Unit::Memory Standard<Unit::Memory>{Unit::Memory::Bit};

/// \brief Physical dimension set of computer memory units.
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
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Bit>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Bit>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Byte>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.125L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Byte>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kilobit>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kilobit>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kibibit>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kibibit>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kilobyte>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(8000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kilobyte>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kibibyte>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kibibyte>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Megabit>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Megabit>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Mebibit>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Mebibit>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Megabyte>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(8000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Megabyte>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Mebibyte>::FromStandard(
    Number& value) noexcept {
  value /=
      (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Mebibyte>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gigabit>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gigabit>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gibibit>::FromStandard(
    Number& value) noexcept {
  value /=
      (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gibibit>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gigabyte>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(8.0E9L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gigabyte>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E9L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gibibyte>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
            * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gibibyte>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Terabit>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-12L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Terabit>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E12L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Tebibit>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
            * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Tebibit>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Terabyte>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(8.0E12L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Terabyte>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E12L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Tebibyte>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
            * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Tebibyte>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
           * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Petabit>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Petabit>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Pebibit>::FromStandard(
    Number& value) noexcept {
  value /=
      (static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
       * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Pebibit>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
      * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Petabyte>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(8.0E15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Petabyte>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(8.0E15L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Pebibyte>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
            * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
            * static_cast<Number>(1024.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Pebibyte>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(8.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L)
      * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L) * static_cast<Number>(1024.0L);
}

template <typename Number>
inline const std::map<Unit::Memory, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Memory, Number>{
        {Unit::Memory::Bit,      Conversions<Unit::Memory, Unit::Memory::Bit>::FromStandard<Number>     },
        {Unit::Memory::Byte,     Conversions<Unit::Memory, Unit::Memory::Byte>::FromStandard<Number>    },
        {Unit::Memory::Kilobit,
         Conversions<Unit::Memory,                         Unit::Memory::Kilobit>::FromStandard<Number> },
        {Unit::Memory::Kibibit,
         Conversions<Unit::Memory,                         Unit::Memory::Kibibit>::FromStandard<Number> },
        {Unit::Memory::Kilobyte,
         Conversions<Unit::Memory,                         Unit::Memory::Kilobyte>::FromStandard<Number>},
        {Unit::Memory::Kibibyte,
         Conversions<Unit::Memory,                         Unit::Memory::Kibibyte>::FromStandard<Number>},
        {Unit::Memory::Megabit,
         Conversions<Unit::Memory,                         Unit::Memory::Megabit>::FromStandard<Number> },
        {Unit::Memory::Mebibit,
         Conversions<Unit::Memory,                         Unit::Memory::Mebibit>::FromStandard<Number> },
        {Unit::Memory::Megabyte,
         Conversions<Unit::Memory,                         Unit::Memory::Megabyte>::FromStandard<Number>},
        {Unit::Memory::Mebibyte,
         Conversions<Unit::Memory,                         Unit::Memory::Mebibyte>::FromStandard<Number>},
        {Unit::Memory::Gigabit,
         Conversions<Unit::Memory,                         Unit::Memory::Gigabit>::FromStandard<Number> },
        {Unit::Memory::Gibibit,
         Conversions<Unit::Memory,                         Unit::Memory::Gibibit>::FromStandard<Number> },
        {Unit::Memory::Gigabyte,
         Conversions<Unit::Memory,                         Unit::Memory::Gigabyte>::FromStandard<Number>},
        {Unit::Memory::Gibibyte,
         Conversions<Unit::Memory,                         Unit::Memory::Gibibyte>::FromStandard<Number>},
        {Unit::Memory::Terabit,
         Conversions<Unit::Memory,                         Unit::Memory::Terabit>::FromStandard<Number> },
        {Unit::Memory::Tebibit,
         Conversions<Unit::Memory,                         Unit::Memory::Tebibit>::FromStandard<Number> },
        {Unit::Memory::Terabyte,
         Conversions<Unit::Memory,                         Unit::Memory::Terabyte>::FromStandard<Number>},
        {Unit::Memory::Tebibyte,
         Conversions<Unit::Memory,                         Unit::Memory::Tebibyte>::FromStandard<Number>},
        {Unit::Memory::Petabit,
         Conversions<Unit::Memory,                         Unit::Memory::Petabit>::FromStandard<Number> },
        {Unit::Memory::Pebibit,
         Conversions<Unit::Memory,                         Unit::Memory::Pebibit>::FromStandard<Number> },
        {Unit::Memory::Petabyte,
         Conversions<Unit::Memory,                         Unit::Memory::Petabyte>::FromStandard<Number>},
        {Unit::Memory::Pebibyte,
         Conversions<Unit::Memory,                         Unit::Memory::Pebibyte>::FromStandard<Number>},
};

template <typename Number>
inline const std::map<Unit::Memory,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Memory, Number>{
        {Unit::Memory::Bit,      Conversions<Unit::Memory, Unit::Memory::Bit>::ToStandard<Number>     },
        {Unit::Memory::Byte,     Conversions<Unit::Memory, Unit::Memory::Byte>::ToStandard<Number>    },
        {Unit::Memory::Kilobit,
         Conversions<Unit::Memory,                         Unit::Memory::Kilobit>::ToStandard<Number> },
        {Unit::Memory::Kibibit,
         Conversions<Unit::Memory,                         Unit::Memory::Kibibit>::ToStandard<Number> },
        {Unit::Memory::Kilobyte,
         Conversions<Unit::Memory,                         Unit::Memory::Kilobyte>::ToStandard<Number>},
        {Unit::Memory::Kibibyte,
         Conversions<Unit::Memory,                         Unit::Memory::Kibibyte>::ToStandard<Number>},
        {Unit::Memory::Megabit,
         Conversions<Unit::Memory,                         Unit::Memory::Megabit>::ToStandard<Number> },
        {Unit::Memory::Mebibit,
         Conversions<Unit::Memory,                         Unit::Memory::Mebibit>::ToStandard<Number> },
        {Unit::Memory::Megabyte,
         Conversions<Unit::Memory,                         Unit::Memory::Megabyte>::ToStandard<Number>},
        {Unit::Memory::Mebibyte,
         Conversions<Unit::Memory,                         Unit::Memory::Mebibyte>::ToStandard<Number>},
        {Unit::Memory::Gigabit,
         Conversions<Unit::Memory,                         Unit::Memory::Gigabit>::ToStandard<Number> },
        {Unit::Memory::Gibibit,
         Conversions<Unit::Memory,                         Unit::Memory::Gibibit>::ToStandard<Number> },
        {Unit::Memory::Gigabyte,
         Conversions<Unit::Memory,                         Unit::Memory::Gigabyte>::ToStandard<Number>},
        {Unit::Memory::Gibibyte,
         Conversions<Unit::Memory,                         Unit::Memory::Gibibyte>::ToStandard<Number>},
        {Unit::Memory::Terabit,
         Conversions<Unit::Memory,                         Unit::Memory::Terabit>::ToStandard<Number> },
        {Unit::Memory::Tebibit,
         Conversions<Unit::Memory,                         Unit::Memory::Tebibit>::ToStandard<Number> },
        {Unit::Memory::Terabyte,
         Conversions<Unit::Memory,                         Unit::Memory::Terabyte>::ToStandard<Number>},
        {Unit::Memory::Tebibyte,
         Conversions<Unit::Memory,                         Unit::Memory::Tebibyte>::ToStandard<Number>},
        {Unit::Memory::Petabit,
         Conversions<Unit::Memory,                         Unit::Memory::Petabit>::ToStandard<Number> },
        {Unit::Memory::Pebibit,
         Conversions<Unit::Memory,                         Unit::Memory::Pebibit>::ToStandard<Number> },
        {Unit::Memory::Petabyte,
         Conversions<Unit::Memory,                         Unit::Memory::Petabyte>::ToStandard<Number>},
        {Unit::Memory::Pebibyte,
         Conversions<Unit::Memory,                         Unit::Memory::Pebibyte>::ToStandard<Number>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_MEMORY_HPP
