// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#ifndef PHQ_UNIT_MASS_RATE_HPP
#define PHQ_UNIT_MASS_RATE_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <ostream>
#include <string_view>
#include <unordered_map>

#include "../Base.hpp"
#include "../Dimension/Length.hpp"
#include "../Dimension/Mass.hpp"
#include "../Dimension/Time.hpp"
#include "../Dimensions.hpp"
#include "../Unit.hpp"
#include "../UnitSystem.hpp"

namespace PhQ {

namespace Unit {

// Mass rate units. Can represent the time rate of change of a mass or a mass
// flow rate.
enum class MassRate : int8_t {
  // Kilogram per second (kg/s) mass rate unit.
  KilogramPerSecond,

  // Gram per second (g/s) mass rate unit.
  GramPerSecond,

  // Slug per second (slug/s) mass rate unit.
  SlugPerSecond,

  // Slinch per second (slinch/s) mass rate unit.
  SlinchPerSecond,

  // Pound per second (lbm/s) mass rate unit.
  PoundPerSecond,

  // Kilogram per minute (kg/min) mass rate unit.
  KilogramPerMinute,

  // Gram per minute (g/min) mass rate unit.
  GramPerMinute,

  // Slug per minute (slug/min) mass rate unit.
  SlugPerMinute,

  // Slinch per minute (slinch/min) mass rate unit.
  SlinchPerMinute,

  // Pound per minute (lbm/min) mass rate unit.
  PoundPerMinute,

  // Kilogram per hour (kg/hr) mass rate unit.
  KilogramPerHour,

  // Gram per hour (g/hr) mass rate unit.
  GramPerHour,

  // Slug per hour (slug/hr) mass rate unit.
  SlugPerHour,

  // Slinch per hour (slinch/hr) mass rate unit.
  SlinchPerHour,

  // Pound per hour (lbm/hr) mass rate unit.
  PoundPerHour,
};

}  // namespace Unit

// Standard time rate of mass unit: kilogram per second (kg/s).
template <>
inline constexpr const Unit::MassRate Standard<Unit::MassRate>{Unit::MassRate::KilogramPerSecond};

// Physical dimension set of time rate of mass units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::MassRate>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{0}, Dimension::Mass{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::MassRate unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::MassRate> ConsistentUnits<Unit::MassRate>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::MassRate::KilogramPerSecond},
    {UnitSystem::MillimetreGramSecondKelvin, Unit::MassRate::GramPerSecond    },
    {UnitSystem::FootPoundSecondRankine,     Unit::MassRate::SlugPerSecond    },
    {UnitSystem::InchPoundSecondRankine,     Unit::MassRate::SlinchPerSecond  },
};

template <>
inline const std::map<Unit::MassRate, UnitSystem> RelatedUnitSystems<Unit::MassRate>{
    {Unit::MassRate::KilogramPerSecond, UnitSystem::MetreKilogramSecondKelvin },
    {Unit::MassRate::GramPerSecond,     UnitSystem::MillimetreGramSecondKelvin},
    {Unit::MassRate::SlugPerSecond,     UnitSystem::FootPoundSecondRankine    },
    {Unit::MassRate::SlinchPerSecond,   UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::MassRate, std::string_view> Abbreviations<Unit::MassRate>{
    {Unit::MassRate::KilogramPerSecond, "kg/s"      },
    {Unit::MassRate::GramPerSecond,     "g/s"       },
    {Unit::MassRate::SlugPerSecond,     "slug/s"    },
    {Unit::MassRate::SlinchPerSecond,   "slinch/s"  },
    {Unit::MassRate::PoundPerSecond,    "lbm/s"     },
    {Unit::MassRate::KilogramPerMinute, "kg/min"    },
    {Unit::MassRate::GramPerMinute,     "g/min"     },
    {Unit::MassRate::SlugPerMinute,     "slug/min"  },
    {Unit::MassRate::SlinchPerMinute,   "slinch/min"},
    {Unit::MassRate::PoundPerMinute,    "lbm/min"   },
    {Unit::MassRate::KilogramPerHour,   "kg/hr"     },
    {Unit::MassRate::GramPerHour,       "g/hr"      },
    {Unit::MassRate::SlugPerHour,       "slug/hr"   },
    {Unit::MassRate::SlinchPerHour,     "slinch/hr" },
    {Unit::MassRate::PoundPerHour,      "lbm/hr"    },
};

template <>
inline const std::unordered_map<std::string_view, Unit::MassRate> Spellings<Unit::MassRate>{
    {"kg/s",       Unit::MassRate::KilogramPerSecond},
    {"g/s",        Unit::MassRate::GramPerSecond    },
    {"slug/s",     Unit::MassRate::SlugPerSecond    },
    {"slinch/s",   Unit::MassRate::SlinchPerSecond  },
    {"lbm/s",      Unit::MassRate::PoundPerSecond   },
    {"lb/s",       Unit::MassRate::PoundPerSecond   },
    {"kg/min",     Unit::MassRate::KilogramPerMinute},
    {"g/min",      Unit::MassRate::GramPerMinute    },
    {"slug/min",   Unit::MassRate::SlugPerMinute    },
    {"slinch/min", Unit::MassRate::SlinchPerMinute  },
    {"lbm/min",    Unit::MassRate::PoundPerMinute   },
    {"lb/min",     Unit::MassRate::PoundPerMinute   },
    {"kg/hr",      Unit::MassRate::KilogramPerHour  },
    {"g/hr",       Unit::MassRate::GramPerHour      },
    {"slug/hr",    Unit::MassRate::SlugPerHour      },
    {"slinch/hr",  Unit::MassRate::SlinchPerHour    },
    {"lbm/hr",     Unit::MassRate::PoundPerHour     },
    {"lb/hr",      Unit::MassRate::PoundPerHour     },
};

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::KilogramPerSecond>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::KilogramPerSecond>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::GramPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::GramPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlugPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlugPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlinchPerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlinchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::PoundPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.45359237L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::PoundPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::KilogramPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::KilogramPerMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::GramPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::GramPerMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlugPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) * static_cast<Number>(0.3048L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlugPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / (static_cast<Number>(0.3048L) * static_cast<Number>(60.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlinchPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) * static_cast<Number>(0.0254L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlinchPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / (static_cast<Number>(0.0254L) * static_cast<Number>(60.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::PoundPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(0.45359237L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::PoundPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::KilogramPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::KilogramPerHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::GramPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::GramPerHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlugPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) * static_cast<Number>(0.3048L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlugPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / (static_cast<Number>(0.3048L) * static_cast<Number>(3600.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlinchPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) * static_cast<Number>(0.0254L)
           / (static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::SlinchPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) * static_cast<Number>(9.80665L)
           / (static_cast<Number>(0.0254L) * static_cast<Number>(3600.0L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::PoundPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.45359237L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::MassRate, Unit::MassRate::PoundPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.45359237L) / static_cast<Number>(3600.0L);
}

template <typename Number>
inline const std::map<Unit::MassRate, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::MassRate, Number>{
        {Unit::MassRate::KilogramPerSecond,
         Conversions<Unit::MassRate, Unit::MassRate::KilogramPerSecond>::FromStandard<Number>},
        {Unit::MassRate::GramPerSecond,
         Conversions<Unit::MassRate, Unit::MassRate::GramPerSecond>::FromStandard<Number>    },
        {Unit::MassRate::SlugPerSecond,
         Conversions<Unit::MassRate, Unit::MassRate::SlugPerSecond>::FromStandard<Number>    },
        {Unit::MassRate::SlinchPerSecond,
         Conversions<Unit::MassRate, Unit::MassRate::SlinchPerSecond>::FromStandard<Number>  },
        {Unit::MassRate::PoundPerSecond,
         Conversions<Unit::MassRate, Unit::MassRate::PoundPerSecond>::FromStandard<Number>   },
        {Unit::MassRate::KilogramPerMinute,
         Conversions<Unit::MassRate, Unit::MassRate::KilogramPerMinute>::FromStandard<Number>},
        {Unit::MassRate::GramPerMinute,
         Conversions<Unit::MassRate, Unit::MassRate::GramPerMinute>::FromStandard<Number>    },
        {Unit::MassRate::SlugPerMinute,
         Conversions<Unit::MassRate, Unit::MassRate::SlugPerMinute>::FromStandard<Number>    },
        {Unit::MassRate::SlinchPerMinute,
         Conversions<Unit::MassRate, Unit::MassRate::SlinchPerMinute>::FromStandard<Number>  },
        {Unit::MassRate::PoundPerMinute,
         Conversions<Unit::MassRate, Unit::MassRate::PoundPerMinute>::FromStandard<Number>   },
        {Unit::MassRate::KilogramPerHour,
         Conversions<Unit::MassRate, Unit::MassRate::KilogramPerHour>::FromStandard<Number>  },
        {Unit::MassRate::GramPerHour,
         Conversions<Unit::MassRate, Unit::MassRate::GramPerHour>::FromStandard<Number>      },
        {Unit::MassRate::SlugPerHour,
         Conversions<Unit::MassRate, Unit::MassRate::SlugPerHour>::FromStandard<Number>      },
        {Unit::MassRate::SlinchPerHour,
         Conversions<Unit::MassRate, Unit::MassRate::SlinchPerHour>::FromStandard<Number>    },
        {Unit::MassRate::PoundPerHour,
         Conversions<Unit::MassRate, Unit::MassRate::PoundPerHour>::FromStandard<Number>     },
};

template <typename Number>
inline const std::map<Unit::MassRate,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::MassRate, Number>{
        {Unit::MassRate::KilogramPerSecond,
         Conversions<Unit::MassRate, Unit::MassRate::KilogramPerSecond>::ToStandard<Number>},
        {Unit::MassRate::GramPerSecond,
         Conversions<Unit::MassRate, Unit::MassRate::GramPerSecond>::ToStandard<Number>    },
        {Unit::MassRate::SlugPerSecond,
         Conversions<Unit::MassRate, Unit::MassRate::SlugPerSecond>::ToStandard<Number>    },
        {Unit::MassRate::SlinchPerSecond,
         Conversions<Unit::MassRate, Unit::MassRate::SlinchPerSecond>::ToStandard<Number>  },
        {Unit::MassRate::PoundPerSecond,
         Conversions<Unit::MassRate, Unit::MassRate::PoundPerSecond>::ToStandard<Number>   },
        {Unit::MassRate::KilogramPerMinute,
         Conversions<Unit::MassRate, Unit::MassRate::KilogramPerMinute>::ToStandard<Number>},
        {Unit::MassRate::GramPerMinute,
         Conversions<Unit::MassRate, Unit::MassRate::GramPerMinute>::ToStandard<Number>    },
        {Unit::MassRate::SlugPerMinute,
         Conversions<Unit::MassRate, Unit::MassRate::SlugPerMinute>::ToStandard<Number>    },
        {Unit::MassRate::SlinchPerMinute,
         Conversions<Unit::MassRate, Unit::MassRate::SlinchPerMinute>::ToStandard<Number>  },
        {Unit::MassRate::PoundPerMinute,
         Conversions<Unit::MassRate, Unit::MassRate::PoundPerMinute>::ToStandard<Number>   },
        {Unit::MassRate::KilogramPerHour,
         Conversions<Unit::MassRate, Unit::MassRate::KilogramPerHour>::ToStandard<Number>  },
        {Unit::MassRate::GramPerHour,
         Conversions<Unit::MassRate, Unit::MassRate::GramPerHour>::ToStandard<Number>      },
        {Unit::MassRate::SlugPerHour,
         Conversions<Unit::MassRate, Unit::MassRate::SlugPerHour>::ToStandard<Number>      },
        {Unit::MassRate::SlinchPerHour,
         Conversions<Unit::MassRate, Unit::MassRate::SlinchPerHour>::ToStandard<Number>    },
        {Unit::MassRate::PoundPerHour,
         Conversions<Unit::MassRate, Unit::MassRate::PoundPerHour>::ToStandard<Number>     },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_MASS_RATE_HPP
