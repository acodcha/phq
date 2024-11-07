// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Bit>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Bit>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Byte>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.125L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Byte>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kilobit>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kilobit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kibibit>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kibibit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kilobyte>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(8000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kilobyte>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kibibyte>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Kibibyte>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Megabit>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Megabit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Mebibit>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Mebibit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Megabyte>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(8000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Megabyte>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Mebibyte>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Mebibyte>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gigabit>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gigabit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gibibit>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gibibit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gigabyte>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(8.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gigabyte>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gibibyte>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Gibibyte>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Terabit>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Terabit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Tebibit>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Tebibit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Terabyte>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(8.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Terabyte>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E12L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Tebibyte>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Tebibyte>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Petabit>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-15L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Petabit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E15L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Pebibit>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Pebibit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Petabyte>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(8.0E15L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Petabyte>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0E15L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Pebibyte>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
            * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Memory, Unit::Memory::Pebibyte>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(8.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L)
           * static_cast<NumericType>(1024.0L) * static_cast<NumericType>(1024.0L);
}

template <typename NumericType>
inline const std::map<Unit::Memory,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Memory, NumericType>{
      {Unit::Memory::Bit,      Conversions<Unit::Memory, Unit::Memory::Bit>::FromStandard<NumericType>     },
      {Unit::Memory::Byte,
       Conversions<Unit::Memory,                         Unit::Memory::Byte>::FromStandard<NumericType>    },
      {Unit::Memory::Kilobit,
       Conversions<Unit::Memory,                         Unit::Memory::Kilobit>::FromStandard<NumericType> },
      {Unit::Memory::Kibibit,
       Conversions<Unit::Memory,                         Unit::Memory::Kibibit>::FromStandard<NumericType> },
      {Unit::Memory::Kilobyte,
       Conversions<Unit::Memory,                         Unit::Memory::Kilobyte>::FromStandard<NumericType>},
      {Unit::Memory::Kibibyte,
       Conversions<Unit::Memory,                         Unit::Memory::Kibibyte>::FromStandard<NumericType>},
      {Unit::Memory::Megabit,
       Conversions<Unit::Memory,                         Unit::Memory::Megabit>::FromStandard<NumericType> },
      {Unit::Memory::Mebibit,
       Conversions<Unit::Memory,                         Unit::Memory::Mebibit>::FromStandard<NumericType> },
      {Unit::Memory::Megabyte,
       Conversions<Unit::Memory,                         Unit::Memory::Megabyte>::FromStandard<NumericType>},
      {Unit::Memory::Mebibyte,
       Conversions<Unit::Memory,                         Unit::Memory::Mebibyte>::FromStandard<NumericType>},
      {Unit::Memory::Gigabit,
       Conversions<Unit::Memory,                         Unit::Memory::Gigabit>::FromStandard<NumericType> },
      {Unit::Memory::Gibibit,
       Conversions<Unit::Memory,                         Unit::Memory::Gibibit>::FromStandard<NumericType> },
      {Unit::Memory::Gigabyte,
       Conversions<Unit::Memory,                         Unit::Memory::Gigabyte>::FromStandard<NumericType>},
      {Unit::Memory::Gibibyte,
       Conversions<Unit::Memory,                         Unit::Memory::Gibibyte>::FromStandard<NumericType>},
      {Unit::Memory::Terabit,
       Conversions<Unit::Memory,                         Unit::Memory::Terabit>::FromStandard<NumericType> },
      {Unit::Memory::Tebibit,
       Conversions<Unit::Memory,                         Unit::Memory::Tebibit>::FromStandard<NumericType> },
      {Unit::Memory::Terabyte,
       Conversions<Unit::Memory,                         Unit::Memory::Terabyte>::FromStandard<NumericType>},
      {Unit::Memory::Tebibyte,
       Conversions<Unit::Memory,                         Unit::Memory::Tebibyte>::FromStandard<NumericType>},
      {Unit::Memory::Petabit,
       Conversions<Unit::Memory,                         Unit::Memory::Petabit>::FromStandard<NumericType> },
      {Unit::Memory::Pebibit,
       Conversions<Unit::Memory,                         Unit::Memory::Pebibit>::FromStandard<NumericType> },
      {Unit::Memory::Petabyte,
       Conversions<Unit::Memory,                         Unit::Memory::Petabyte>::FromStandard<NumericType>},
      {Unit::Memory::Pebibyte,
       Conversions<Unit::Memory,                         Unit::Memory::Pebibyte>::FromStandard<NumericType>},
};

template <typename NumericType>
inline const std::map<Unit::Memory,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Memory, NumericType>{
      {Unit::Memory::Bit,      Conversions<Unit::Memory, Unit::Memory::Bit>::ToStandard<NumericType>     },
      {Unit::Memory::Byte,     Conversions<Unit::Memory, Unit::Memory::Byte>::ToStandard<NumericType>    },
      {Unit::Memory::Kilobit,
       Conversions<Unit::Memory,                         Unit::Memory::Kilobit>::ToStandard<NumericType> },
      {Unit::Memory::Kibibit,
       Conversions<Unit::Memory,                         Unit::Memory::Kibibit>::ToStandard<NumericType> },
      {Unit::Memory::Kilobyte,
       Conversions<Unit::Memory,                         Unit::Memory::Kilobyte>::ToStandard<NumericType>},
      {Unit::Memory::Kibibyte,
       Conversions<Unit::Memory,                         Unit::Memory::Kibibyte>::ToStandard<NumericType>},
      {Unit::Memory::Megabit,
       Conversions<Unit::Memory,                         Unit::Memory::Megabit>::ToStandard<NumericType> },
      {Unit::Memory::Mebibit,
       Conversions<Unit::Memory,                         Unit::Memory::Mebibit>::ToStandard<NumericType> },
      {Unit::Memory::Megabyte,
       Conversions<Unit::Memory,                         Unit::Memory::Megabyte>::ToStandard<NumericType>},
      {Unit::Memory::Mebibyte,
       Conversions<Unit::Memory,                         Unit::Memory::Mebibyte>::ToStandard<NumericType>},
      {Unit::Memory::Gigabit,
       Conversions<Unit::Memory,                         Unit::Memory::Gigabit>::ToStandard<NumericType> },
      {Unit::Memory::Gibibit,
       Conversions<Unit::Memory,                         Unit::Memory::Gibibit>::ToStandard<NumericType> },
      {Unit::Memory::Gigabyte,
       Conversions<Unit::Memory,                         Unit::Memory::Gigabyte>::ToStandard<NumericType>},
      {Unit::Memory::Gibibyte,
       Conversions<Unit::Memory,                         Unit::Memory::Gibibyte>::ToStandard<NumericType>},
      {Unit::Memory::Terabit,
       Conversions<Unit::Memory,                         Unit::Memory::Terabit>::ToStandard<NumericType> },
      {Unit::Memory::Tebibit,
       Conversions<Unit::Memory,                         Unit::Memory::Tebibit>::ToStandard<NumericType> },
      {Unit::Memory::Terabyte,
       Conversions<Unit::Memory,                         Unit::Memory::Terabyte>::ToStandard<NumericType>},
      {Unit::Memory::Tebibyte,
       Conversions<Unit::Memory,                         Unit::Memory::Tebibyte>::ToStandard<NumericType>},
      {Unit::Memory::Petabit,
       Conversions<Unit::Memory,                         Unit::Memory::Petabit>::ToStandard<NumericType> },
      {Unit::Memory::Pebibit,
       Conversions<Unit::Memory,                         Unit::Memory::Pebibit>::ToStandard<NumericType> },
      {Unit::Memory::Petabyte,
       Conversions<Unit::Memory,                         Unit::Memory::Petabyte>::ToStandard<NumericType>},
      {Unit::Memory::Pebibyte,
       Conversions<Unit::Memory,                         Unit::Memory::Pebibyte>::ToStandard<NumericType>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_MEMORY_HPP
