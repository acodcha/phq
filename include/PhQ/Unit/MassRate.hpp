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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_RATE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_RATE_HPP

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
inline constexpr void ConversionFromStandard<Unit::MassRate, Unit::MassRate::KilogramPerSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::GramPerSecond>(double& value) noexcept {
  value *= 1000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::SlugPerSecond>(double& value) noexcept {
  value *= 0.3048 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::SlinchPerSecond>(double& value) noexcept {
  value *= 0.0254 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::PoundPerSecond>(double& value) noexcept {
  value /= 0.45359237;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::KilogramPerMinute>(double& value) noexcept {
  value *= 60.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::GramPerMinute>(double& value) noexcept {
  value *= 60000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::SlugPerMinute>(double& value) noexcept {
  value *= 60.0 * 0.3048 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::SlinchPerMinute>(double& value) noexcept {
  value *= 60.0 * 0.0254 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::PoundPerMinute>(double& value) noexcept {
  value *= 60.0 / 0.45359237;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::KilogramPerHour>(double& value) noexcept {
  value *= 3600.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::GramPerHour>(double& value) noexcept {
  value *= 3600000.0;
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::SlugPerHour>(double& value) noexcept {
  value *= 3600.0 * 0.3048 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::SlinchPerHour>(double& value) noexcept {
  value *= 3600.0 * 0.0254 / (0.45359237 * 9.80665);
}

template <>
inline constexpr void
ConversionFromStandard<Unit::MassRate, Unit::MassRate::PoundPerHour>(double& value) noexcept {
  value *= 3600.0 / 0.45359237;
}

template <>
inline constexpr void ConversionToStandard<Unit::MassRate, Unit::MassRate::KilogramPerSecond>(
    double& /*value*/) noexcept {}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::GramPerSecond>(double& value) noexcept {
  value *= 0.001;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::SlugPerSecond>(double& value) noexcept {
  value *= 0.45359237 * 9.80665 / 0.3048;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::SlinchPerSecond>(double& value) noexcept {
  value *= 0.45359237 * 9.80665 / 0.0254;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::PoundPerSecond>(double& value) noexcept {
  value *= 0.45359237;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::KilogramPerMinute>(double& value) noexcept {
  value /= 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::GramPerMinute>(double& value) noexcept {
  value /= 60000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::SlugPerMinute>(double& value) noexcept {
  value *= 0.45359237 * 9.80665 / (0.3048 * 60.0);
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::SlinchPerMinute>(double& value) noexcept {
  value *= 0.45359237 * 9.80665 / (0.0254 * 60.0);
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::PoundPerMinute>(double& value) noexcept {
  value *= 0.45359237 / 60.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::KilogramPerHour>(double& value) noexcept {
  value /= 3600.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::GramPerHour>(double& value) noexcept {
  value /= 3600000.0;
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::SlugPerHour>(double& value) noexcept {
  value *= 0.45359237 * 9.80665 / (0.3048 * 3600.0);
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::SlinchPerHour>(double& value) noexcept {
  value *= 0.45359237 * 9.80665 / (0.0254 * 3600.0);
}

template <>
inline constexpr void
ConversionToStandard<Unit::MassRate, Unit::MassRate::PoundPerHour>(double& value) noexcept {
  value *= 0.45359237 / 3600.0;
}

template <>
inline const std::map<Unit::MassRate, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::MassRate>{
        {Unit::MassRate::KilogramPerSecond,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::KilogramPerSecond>},
        {Unit::MassRate::GramPerSecond,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::GramPerSecond>    },
        {Unit::MassRate::SlugPerSecond,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::SlugPerSecond>    },
        {Unit::MassRate::SlinchPerSecond,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::SlinchPerSecond>  },
        {Unit::MassRate::PoundPerSecond,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::PoundPerSecond>   },
        {Unit::MassRate::KilogramPerMinute,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::KilogramPerMinute>},
        {Unit::MassRate::GramPerMinute,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::GramPerMinute>    },
        {Unit::MassRate::SlugPerMinute,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::SlugPerMinute>    },
        {Unit::MassRate::SlinchPerMinute,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::SlinchPerMinute>  },
        {Unit::MassRate::PoundPerMinute,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::PoundPerMinute>   },
        {Unit::MassRate::KilogramPerHour,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::KilogramPerHour>  },
        {Unit::MassRate::GramPerHour,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::GramPerHour>      },
        {Unit::MassRate::SlugPerHour,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::SlugPerHour>      },
        {Unit::MassRate::SlinchPerHour,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::SlinchPerHour>    },
        {Unit::MassRate::PoundPerHour,
         ConversionsFromStandard<Unit::MassRate, Unit::MassRate::PoundPerHour>     },
};

template <>
inline const std::map<Unit::MassRate,
                      std::function<void(double* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::MassRate>{
        {Unit::MassRate::KilogramPerSecond,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::KilogramPerSecond>},
        {Unit::MassRate::GramPerSecond,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::GramPerSecond>    },
        {Unit::MassRate::SlugPerSecond,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::SlugPerSecond>    },
        {Unit::MassRate::SlinchPerSecond,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::SlinchPerSecond>  },
        {Unit::MassRate::PoundPerSecond,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::PoundPerSecond>   },
        {Unit::MassRate::KilogramPerMinute,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::KilogramPerMinute>},
        {Unit::MassRate::GramPerMinute,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::GramPerMinute>    },
        {Unit::MassRate::SlugPerMinute,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::SlugPerMinute>    },
        {Unit::MassRate::SlinchPerMinute,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::SlinchPerMinute>  },
        {Unit::MassRate::PoundPerMinute,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::PoundPerMinute>   },
        {Unit::MassRate::KilogramPerHour,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::KilogramPerHour>  },
        {Unit::MassRate::GramPerHour,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::GramPerHour>      },
        {Unit::MassRate::SlugPerHour,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::SlugPerHour>      },
        {Unit::MassRate::SlinchPerHour,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::SlinchPerHour>    },
        {Unit::MassRate::PoundPerHour,
         ConversionsToStandard<Unit::MassRate, Unit::MassRate::PoundPerHour>     },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_MASS_RATE_HPP
