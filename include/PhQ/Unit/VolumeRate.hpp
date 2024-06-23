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

#ifndef PHQ_UNIT_VOLUME_RATE_HPP
#define PHQ_UNIT_VOLUME_RATE_HPP

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

/// \brief Volume rate units. Can represent a time rate of change of a volume or a volume flow rate.
enum class VolumeRate : int8_t {
  /// \brief Cubic nautical mile per second (nmi^3/s) volume rate unit.
  CubicNauticalMilePerSecond,

  /// \brief Cubic mile per second (mi^3/s) volume rate unit.
  CubicMilePerSecond,

  /// \brief Cubic kilometre per second (km^3/s) volume rate unit.
  CubicKilometrePerSecond,

  /// \brief Cubic metre per second (m^3/s) volume rate unit.
  CubicMetrePerSecond,

  /// \brief Cubic yard per second (yd^3/s) volume rate unit.
  CubicYardPerSecond,

  /// \brief Cubic foot per second (ft^3/s) volume rate unit.
  CubicFootPerSecond,

  /// \brief Cubic decimetre per second (dm^3/s) volume rate unit.
  CubicDecimetrePerSecond,

  /// \brief Litre per second (L/s) volume rate unit.
  LitrePerSecond,

  /// \brief Cubic inch per second (in^3/s) volume rate unit.
  CubicInchPerSecond,

  /// \brief Cubic centimetre per second (cm^3/s) volume rate unit.
  CubicCentimetrePerSecond,

  /// \brief Millilitre per second (mL/s) volume rate unit.
  MillilitrePerSecond,

  /// \brief Cubic millimetre per second (mm^3/s) volume rate unit.
  CubicMillimetrePerSecond,

  /// \brief Cubic milliinch per second (mil^3/s) volume rate unit.
  CubicMilliinchPerSecond,

  /// \brief Cubic micrometre per second (μm^3/s) volume rate unit.
  CubicMicrometrePerSecond,

  /// \brief Cubic microinch per second (μin^3/s) volume rate unit.
  CubicMicroinchPerSecond,

  /// \brief Cubic nautical mile per minute (nmi^3/min) volume rate unit.
  CubicNauticalMilePerMinute,

  /// \brief Cubic mile per minute (mi^3/min) volume rate unit.
  CubicMilePerMinute,

  /// \brief Cubic kilometre per minute (km^3/min) volume rate unit.
  CubicKilometrePerMinute,

  /// \brief Cubic metre per minute (m^3/min) volume rate unit.
  CubicMetrePerMinute,

  /// \brief Cubic yard per minute (yd^3/min) volume rate unit.
  CubicYardPerMinute,

  /// \brief Cubic foot per minute (ft^3/min) volume rate unit.
  CubicFootPerMinute,

  /// \brief Cubic decimetre per minute (dm^3/min) volume rate unit.
  CubicDecimetrePerMinute,

  /// \brief Litre per minute (L/min) volume rate unit.
  LitrePerMinute,

  /// \brief Cubic inch per minute (in^3/min) volume rate unit.
  CubicInchPerMinute,

  /// \brief Cubic centimetre per minute (cm^3/min) volume rate unit.
  CubicCentimetrePerMinute,

  /// \brief Millilitre per minute (mL/min) volume rate unit.
  MillilitrePerMinute,

  /// \brief Cubic millimetre per minute (mm^3/min) volume rate unit.
  CubicMillimetrePerMinute,

  /// \brief Cubic milliinch per minute (mil^3/min) volume rate unit.
  CubicMilliinchPerMinute,

  /// \brief Cubic micrometre per minute (μm^3/min) volume rate unit.
  CubicMicrometrePerMinute,

  /// \brief Cubic microinch per minute (μin^3/min) volume rate unit.
  CubicMicroinchPerMinute,

  /// \brief Cubic nautical mile per hour (nmi^3/hr) volume rate unit.
  CubicNauticalMilePerHour,

  /// \brief Cubic mile per hour (mi^3/hr) volume rate unit.
  CubicMilePerHour,

  /// \brief Cubic kilometre per hour (km^3/hr) volume rate unit.
  CubicKilometrePerHour,

  /// \brief Cubic metre per hour (m^3/hr) volume rate unit.
  CubicMetrePerHour,

  /// \brief Cubic yard per hour (yd^3/hr) volume rate unit.
  CubicYardPerHour,

  /// \brief Cubic foot per hour (ft^3/hr) volume rate unit.
  CubicFootPerHour,

  /// \brief Cubic decimetre per hour (dm^3/hr) volume rate unit.
  CubicDecimetrePerHour,

  /// \brief Litre per hour (L/hr) volume rate unit.
  LitrePerHour,

  /// \brief Cubic inch per hour (in^3/hr) volume rate unit.
  CubicInchPerHour,

  /// \brief Cubic centimetre per hour (cm^3/hr) volume rate unit.
  CubicCentimetrePerHour,

  /// \brief Millilitre per hour (mL/hr) volume rate unit.
  MillilitrePerHour,

  /// \brief Cubic millimetre per hour (mm^3/hr) volume rate unit.
  CubicMillimetrePerHour,

  /// \brief Cubic milliinch per hour (mil^3/hr) volume rate unit.
  CubicMilliinchPerHour,

  /// \brief Cubic micrometre per hour (μm^3/hr) volume rate unit.
  CubicMicrometrePerHour,

  /// \brief Cubic microinch per hour (μin^3/hr) volume rate unit.
  CubicMicroinchPerHour,
};

}  // namespace Unit

/// \brief Standard time-rate of volume unit: cubic metre per second (m^3/s).
template <>
inline constexpr const Unit::VolumeRate Standard<Unit::VolumeRate>{
    Unit::VolumeRate::CubicMetrePerSecond};

/// \brief Physical dimension set of time-rate of volume units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::VolumeRate>{
    Dimensions{Dimension::Time{-1}, Dimension::Length{3}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::VolumeRate unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::VolumeRate> ConsistentUnits<Unit::VolumeRate>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::VolumeRate::CubicMetrePerSecond     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::VolumeRate::CubicMillimetrePerSecond},
    {UnitSystem::FootPoundSecondRankine,     Unit::VolumeRate::CubicFootPerSecond      },
    {UnitSystem::InchPoundSecondRankine,     Unit::VolumeRate::CubicInchPerSecond      },
};

template <>
inline const std::map<Unit::VolumeRate, UnitSystem> RelatedUnitSystems<Unit::VolumeRate>{
    {Unit::VolumeRate::CubicMetrePerSecond,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::VolumeRate::CubicMillimetrePerSecond, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::VolumeRate::CubicFootPerSecond,       UnitSystem::FootPoundSecondRankine    },
    {Unit::VolumeRate::CubicInchPerSecond,       UnitSystem::InchPoundSecondRankine    },
};

// clang-format off

template <>
inline const std::map<Unit::VolumeRate, std::string_view> Abbreviations<Unit::VolumeRate>{
    {Unit::VolumeRate::CubicNauticalMilePerSecond, "nmi^3/s"  },
    {Unit::VolumeRate::CubicMilePerSecond,         "mi^3/s"   },
    {Unit::VolumeRate::CubicKilometrePerSecond,    "km^3/s"   },
    {Unit::VolumeRate::CubicMetrePerSecond,        "m^3/s"    },
    {Unit::VolumeRate::CubicYardPerSecond,         "yd^3/s"   },
    {Unit::VolumeRate::CubicFootPerSecond,         "ft^3/s"   },
    {Unit::VolumeRate::CubicDecimetrePerSecond,    "dm^3/s"   },
    {Unit::VolumeRate::LitrePerSecond,             "L/s"      },
    {Unit::VolumeRate::CubicInchPerSecond,         "in^3/s"   },
    {Unit::VolumeRate::CubicCentimetrePerSecond,   "cm^3/s"   },
    {Unit::VolumeRate::MillilitrePerSecond,        "mL/s"     },
    {Unit::VolumeRate::CubicMillimetrePerSecond,   "mm^3/s"   },
    {Unit::VolumeRate::CubicMilliinchPerSecond,    "mil^3/s"  },
    {Unit::VolumeRate::CubicMicrometrePerSecond,   "μm^3/s"   },
    {Unit::VolumeRate::CubicMicroinchPerSecond,    "μin^3/s"  },
    {Unit::VolumeRate::CubicNauticalMilePerMinute, "nmi^3/min"},
    {Unit::VolumeRate::CubicMilePerMinute,         "mi^3/min" },
    {Unit::VolumeRate::CubicKilometrePerMinute,    "km^3/min" },
    {Unit::VolumeRate::CubicMetrePerMinute,        "m^3/min"  },
    {Unit::VolumeRate::CubicYardPerMinute,         "yd^3/min" },
    {Unit::VolumeRate::CubicFootPerMinute,         "ft^3/min" },
    {Unit::VolumeRate::CubicDecimetrePerMinute,    "dm^3/min" },
    {Unit::VolumeRate::LitrePerMinute,             "L/min"    },
    {Unit::VolumeRate::CubicInchPerMinute,         "in^3/min" },
    {Unit::VolumeRate::CubicCentimetrePerMinute,   "cm^3/min" },
    {Unit::VolumeRate::MillilitrePerMinute,        "mL/min"   },
    {Unit::VolumeRate::CubicMillimetrePerMinute,   "mm^3/min" },
    {Unit::VolumeRate::CubicMilliinchPerMinute,    "mil^3/min"},
    {Unit::VolumeRate::CubicMicrometrePerMinute,   "μm^3/min" },
    {Unit::VolumeRate::CubicMicroinchPerMinute,    "μin^3/min"},
    {Unit::VolumeRate::CubicNauticalMilePerHour,   "nmi^3/hr" },
    {Unit::VolumeRate::CubicMilePerHour,           "mi^3/hr"  },
    {Unit::VolumeRate::CubicKilometrePerHour,      "km^3/hr"  },
    {Unit::VolumeRate::CubicMetrePerHour,          "m^3/hr"   },
    {Unit::VolumeRate::CubicYardPerHour,           "yd^3/hr"  },
    {Unit::VolumeRate::CubicFootPerHour,           "ft^3/hr"  },
    {Unit::VolumeRate::CubicDecimetrePerHour,      "dm^3/hr"  },
    {Unit::VolumeRate::LitrePerHour,               "L/hr"     },
    {Unit::VolumeRate::CubicInchPerHour,           "in^3/hr"  },
    {Unit::VolumeRate::CubicCentimetrePerHour,     "cm^3/hr"  },
    {Unit::VolumeRate::MillilitrePerHour,          "mL/hr"    },
    {Unit::VolumeRate::CubicMillimetrePerHour,     "mm^3/hr"  },
    {Unit::VolumeRate::CubicMilliinchPerHour,      "mil^3/hr" },
    {Unit::VolumeRate::CubicMicrometrePerHour,     "μm^3/hr"  },
    {Unit::VolumeRate::CubicMicroinchPerHour,      "μin^3/hr" },
};

template <>
inline const std::unordered_map<std::string_view, Unit::VolumeRate> Spellings<Unit::VolumeRate>{
    {"nmi^3/s",         Unit::VolumeRate::CubicNauticalMilePerSecond},
    {"nmi3/s",          Unit::VolumeRate::CubicNauticalMilePerSecond},
    {"mi^3/s",          Unit::VolumeRate::CubicMilePerSecond        },
    {"mi3/s",           Unit::VolumeRate::CubicMilePerSecond        },
    {"km^3/s",          Unit::VolumeRate::CubicKilometrePerSecond   },
    {"km3/s",           Unit::VolumeRate::CubicKilometrePerSecond   },
    {"m^3/s",           Unit::VolumeRate::CubicMetrePerSecond       },
    {"m3/s",            Unit::VolumeRate::CubicMetrePerSecond       },
    {"yd^3/s",          Unit::VolumeRate::CubicYardPerSecond        },
    {"yd3/s",           Unit::VolumeRate::CubicYardPerSecond        },
    {"ft^3/s",          Unit::VolumeRate::CubicFootPerSecond        },
    {"ft3/s",           Unit::VolumeRate::CubicFootPerSecond        },
    {"dm^3/s",          Unit::VolumeRate::CubicDecimetrePerSecond   },
    {"dm3/s",           Unit::VolumeRate::CubicDecimetrePerSecond   },
    {"L/s",             Unit::VolumeRate::LitrePerSecond            },
    {"in^3/s",          Unit::VolumeRate::CubicInchPerSecond        },
    {"in3/s",           Unit::VolumeRate::CubicInchPerSecond        },
    {"cm^3/s",          Unit::VolumeRate::CubicCentimetrePerSecond  },
    {"cm3/s",           Unit::VolumeRate::CubicCentimetrePerSecond  },
    {"mL/s",            Unit::VolumeRate::MillilitrePerSecond       },
    {"mm^3/s",          Unit::VolumeRate::CubicMillimetrePerSecond  },
    {"mm3/s",           Unit::VolumeRate::CubicMillimetrePerSecond  },
    {"millinch^3/s",    Unit::VolumeRate::CubicMilliinchPerSecond   },
    {"millinch3/s",     Unit::VolumeRate::CubicMilliinchPerSecond   },
    {"milliinch^3/s",   Unit::VolumeRate::CubicMilliinchPerSecond   },
    {"milliinch3/s",    Unit::VolumeRate::CubicMilliinchPerSecond   },
    {"mil^3/s",         Unit::VolumeRate::CubicMilliinchPerSecond   },
    {"mil3/s",          Unit::VolumeRate::CubicMilliinchPerSecond   },
    {"thou^3/s",        Unit::VolumeRate::CubicMilliinchPerSecond   },
    {"thou3/s",         Unit::VolumeRate::CubicMilliinchPerSecond   },
    {"μm^3/s",          Unit::VolumeRate::CubicMicrometrePerSecond  },
    {"μm3/s",           Unit::VolumeRate::CubicMicrometrePerSecond  },
    {"um^3/s",          Unit::VolumeRate::CubicMicrometrePerSecond  },
    {"um3/s",           Unit::VolumeRate::CubicMicrometrePerSecond  },
    {"μin^3/s",         Unit::VolumeRate::CubicMicroinchPerSecond   },
    {"μin3/s",          Unit::VolumeRate::CubicMicroinchPerSecond   },
    {"uin^3/s",         Unit::VolumeRate::CubicMicroinchPerSecond   },
    {"uin3/s",          Unit::VolumeRate::CubicMicroinchPerSecond   },
    {"nmi^3/min",       Unit::VolumeRate::CubicNauticalMilePerMinute},
    {"nmi3/min",        Unit::VolumeRate::CubicNauticalMilePerMinute},
    {"mi^3/min",        Unit::VolumeRate::CubicMilePerMinute        },
    {"mi3/min",         Unit::VolumeRate::CubicMilePerMinute        },
    {"km^3/min",        Unit::VolumeRate::CubicKilometrePerMinute   },
    {"km3/min",         Unit::VolumeRate::CubicKilometrePerMinute   },
    {"m^3/min",         Unit::VolumeRate::CubicMetrePerMinute       },
    {"m3/min",          Unit::VolumeRate::CubicMetrePerMinute       },
    {"yd^3/min",        Unit::VolumeRate::CubicYardPerMinute        },
    {"yd3/min",         Unit::VolumeRate::CubicYardPerMinute        },
    {"ft^3/min",        Unit::VolumeRate::CubicFootPerMinute        },
    {"ft3/min",         Unit::VolumeRate::CubicFootPerMinute        },
    {"dm^3/min",        Unit::VolumeRate::CubicDecimetrePerMinute   },
    {"dm3/min",         Unit::VolumeRate::CubicDecimetrePerMinute   },
    {"L/min",           Unit::VolumeRate::LitrePerMinute            },
    {"in^3/min",        Unit::VolumeRate::CubicInchPerMinute        },
    {"in3/min",         Unit::VolumeRate::CubicInchPerMinute        },
    {"cm^3/min",        Unit::VolumeRate::CubicCentimetrePerMinute  },
    {"cm3/min",         Unit::VolumeRate::CubicCentimetrePerMinute  },
    {"mL/min",          Unit::VolumeRate::MillilitrePerMinute       },
    {"mm^3/min",        Unit::VolumeRate::CubicMillimetrePerMinute  },
    {"mm3/min",         Unit::VolumeRate::CubicMillimetrePerMinute  },
    {"millinch^3/min",  Unit::VolumeRate::CubicMilliinchPerMinute   },
    {"millinch3/min",   Unit::VolumeRate::CubicMilliinchPerMinute   },
    {"milliinch^3/min", Unit::VolumeRate::CubicMilliinchPerMinute   },
    {"milliinch3/min",  Unit::VolumeRate::CubicMilliinchPerMinute   },
    {"mil^3/min",       Unit::VolumeRate::CubicMilliinchPerMinute   },
    {"mil3/min",        Unit::VolumeRate::CubicMilliinchPerMinute   },
    {"thou^3/min",      Unit::VolumeRate::CubicMilliinchPerMinute   },
    {"thou3/min",       Unit::VolumeRate::CubicMilliinchPerMinute   },
    {"μm^3/min",        Unit::VolumeRate::CubicMicrometrePerMinute  },
    {"μm3/min",         Unit::VolumeRate::CubicMicrometrePerMinute  },
    {"um^3/min",        Unit::VolumeRate::CubicMicrometrePerMinute  },
    {"um3/min",         Unit::VolumeRate::CubicMicrometrePerMinute  },
    {"μin^3/min",       Unit::VolumeRate::CubicMicroinchPerMinute   },
    {"μin3/min",        Unit::VolumeRate::CubicMicroinchPerMinute   },
    {"uin^3/min",       Unit::VolumeRate::CubicMicroinchPerMinute   },
    {"uin3/min",        Unit::VolumeRate::CubicMicroinchPerMinute   },
    {"nmi^3/hr",        Unit::VolumeRate::CubicNauticalMilePerHour  },
    {"nmi3/hr",         Unit::VolumeRate::CubicNauticalMilePerHour  },
    {"mi^3/hr",         Unit::VolumeRate::CubicMilePerHour          },
    {"mi3/hr",          Unit::VolumeRate::CubicMilePerHour          },
    {"km^3/hr",         Unit::VolumeRate::CubicKilometrePerHour     },
    {"km3/hr",          Unit::VolumeRate::CubicKilometrePerHour     },
    {"m^3/hr",          Unit::VolumeRate::CubicMetrePerHour         },
    {"m3/hr",           Unit::VolumeRate::CubicMetrePerHour         },
    {"yd^3/hr",         Unit::VolumeRate::CubicYardPerHour          },
    {"yd3/hr",          Unit::VolumeRate::CubicYardPerHour          },
    {"ft^3/hr",         Unit::VolumeRate::CubicFootPerHour          },
    {"ft3/hr",          Unit::VolumeRate::CubicFootPerHour          },
    {"dm^3/hr",         Unit::VolumeRate::CubicDecimetrePerHour     },
    {"dm3/hr",          Unit::VolumeRate::CubicDecimetrePerHour     },
    {"L/hr",            Unit::VolumeRate::LitrePerHour              },
    {"in^3/hr",         Unit::VolumeRate::CubicInchPerHour          },
    {"in3/hr",          Unit::VolumeRate::CubicInchPerHour          },
    {"cm^3/hr",         Unit::VolumeRate::CubicCentimetrePerHour    },
    {"cm3/hr",          Unit::VolumeRate::CubicCentimetrePerHour    },
    {"mL/hr",           Unit::VolumeRate::MillilitrePerHour         },
    {"mm^3/hr",         Unit::VolumeRate::CubicMillimetrePerHour    },
    {"mm3/hr",          Unit::VolumeRate::CubicMillimetrePerHour    },
    {"millinch^3/hr",   Unit::VolumeRate::CubicMilliinchPerHour     },
    {"millinch3/hr",    Unit::VolumeRate::CubicMilliinchPerHour     },
    {"milliinch^3/hr",  Unit::VolumeRate::CubicMilliinchPerHour     },
    {"milliinch3/hr",   Unit::VolumeRate::CubicMilliinchPerHour     },
    {"mil^3/hr",        Unit::VolumeRate::CubicMilliinchPerHour     },
    {"mil3/hr",         Unit::VolumeRate::CubicMilliinchPerHour     },
    {"thou^3/hr",       Unit::VolumeRate::CubicMilliinchPerHour     },
    {"thou3/hr",        Unit::VolumeRate::CubicMilliinchPerHour     },
    {"μm^3/hr",         Unit::VolumeRate::CubicMicrometrePerHour    },
    {"μm3/hr",          Unit::VolumeRate::CubicMicrometrePerHour    },
    {"um^3/hr",         Unit::VolumeRate::CubicMicrometrePerHour    },
    {"um3/hr",          Unit::VolumeRate::CubicMicrometrePerHour    },
    {"μin^3/hr",        Unit::VolumeRate::CubicMicroinchPerHour     },
    {"μin3/hr",         Unit::VolumeRate::CubicMicroinchPerHour     },
    {"uin^3/hr",        Unit::VolumeRate::CubicMicroinchPerHour     },
    {"uin3/hr",         Unit::VolumeRate::CubicMicroinchPerHour     },
};

// clang-format on

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L)
            * static_cast<NumericType>(1852.0L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L)
           * static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L)
            * static_cast<NumericType>(1609.344L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L)
           * static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerSecond>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerSecond>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L)
            * static_cast<NumericType>(0.9144L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L)
           * static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L)
            * static_cast<NumericType>(0.3048L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L)
           * static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L)
            * static_cast<NumericType>(0.0254L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L)
           * static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L)
            * static_cast<NumericType>(0.0000254L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L)
           * static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E18L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-18L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L)
            * static_cast<NumericType>(0.0000000254L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L)
           * static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L)
              * static_cast<NumericType>(1852.0L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L)
           * static_cast<NumericType>(1852.0L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L)
              * static_cast<NumericType>(1609.344L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L)
           * static_cast<NumericType>(1609.344L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L)
              * static_cast<NumericType>(0.9144L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L)
           * static_cast<NumericType>(0.9144L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L)
              * static_cast<NumericType>(0.3048L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L)
           * static_cast<NumericType>(0.3048L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) / static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L)
              * static_cast<NumericType>(0.0254L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L)
           * static_cast<NumericType>(0.0254L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) * static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) * static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) * static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L)
              * static_cast<NumericType>(0.0000254L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L)
           * static_cast<NumericType>(0.0000254L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L) * static_cast<NumericType>(1.0E18L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-18L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L)
           / (static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L)
              * static_cast<NumericType>(0.0000000254L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L)
           * static_cast<NumericType>(0.0000000254L) / static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L)
              * static_cast<NumericType>(1852.0L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L) * static_cast<NumericType>(1852.0L)
           * static_cast<NumericType>(1852.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L)
              * static_cast<NumericType>(1609.344L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) * static_cast<NumericType>(1609.344L)
           * static_cast<NumericType>(1609.344L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E9L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L)
              * static_cast<NumericType>(0.9144L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L) * static_cast<NumericType>(0.9144L)
           * static_cast<NumericType>(0.9144L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L)
              * static_cast<NumericType>(0.3048L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.3048L)
           * static_cast<NumericType>(0.3048L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L)
              * static_cast<NumericType>(0.0254L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.0254L)
           * static_cast<NumericType>(0.0254L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) * static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) * static_cast<NumericType>(1.0E6L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-6L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) * static_cast<NumericType>(1.0E9L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-9L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L)
              * static_cast<NumericType>(0.0000254L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L) * static_cast<NumericType>(0.0000254L)
           * static_cast<NumericType>(0.0000254L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) * static_cast<NumericType>(1.0E18L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.0E-18L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L)
           / (static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L)
              * static_cast<NumericType>(0.0000000254L));
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L) * static_cast<NumericType>(0.0000000254L)
           * static_cast<NumericType>(0.0000000254L) / static_cast<NumericType>(3600.0L);
}

template <typename NumericType>
inline const std::map<Unit::VolumeRate,
                      std::function<void(NumericType* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::VolumeRate, NumericType>{
        {Unit::VolumeRate::CubicNauticalMilePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerSecond>::FromStandard<NumericType>                },
        {Unit::VolumeRate::CubicMilePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilePerSecond>::FromStandard<NumericType>                        },
        {Unit::VolumeRate::CubicKilometrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerSecond>::FromStandard<NumericType>                   },
        {Unit::VolumeRate::CubicMetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMetrePerSecond>::FromStandard<NumericType>                       },
        {Unit::VolumeRate::CubicYardPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicYardPerSecond>::FromStandard<NumericType>                        },
        {Unit::VolumeRate::CubicFootPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicFootPerSecond>::FromStandard<NumericType>                        },
        {Unit::VolumeRate::CubicDecimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerSecond>::FromStandard<NumericType>                   },
        {Unit::VolumeRate::LitrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::LitrePerSecond>::FromStandard<NumericType>                            },
        {Unit::VolumeRate::CubicInchPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicInchPerSecond>::FromStandard<NumericType>                        },
        {Unit::VolumeRate::CubicCentimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerSecond>::FromStandard<NumericType>                  },
        {Unit::VolumeRate::MillilitrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::MillilitrePerSecond>::FromStandard<NumericType>                       },
        {Unit::VolumeRate::CubicMillimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerSecond>::FromStandard<NumericType>                  },
        {Unit::VolumeRate::CubicMilliinchPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerSecond>::FromStandard<NumericType>                   },
        {Unit::VolumeRate::CubicMicrometrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerSecond>::FromStandard<NumericType>                  },
        {Unit::VolumeRate::CubicMicroinchPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerSecond>::FromStandard<NumericType>                   },
        {Unit::VolumeRate::CubicNauticalMilePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerMinute>::FromStandard<NumericType>                },
        {Unit::VolumeRate::CubicMilePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilePerMinute>::FromStandard<NumericType>                        },
        {Unit::VolumeRate::CubicKilometrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerMinute>::FromStandard<NumericType>                   },
        {Unit::VolumeRate::CubicMetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMetrePerMinute>::FromStandard<NumericType>                       },
        {Unit::VolumeRate::CubicYardPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicYardPerMinute>::FromStandard<NumericType>                        },
        {Unit::VolumeRate::CubicFootPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicFootPerMinute>::FromStandard<NumericType>                        },
        {Unit::VolumeRate::CubicDecimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerMinute>::FromStandard<NumericType>                   },
        {Unit::VolumeRate::LitrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::LitrePerMinute>::FromStandard<NumericType>                            },
        {Unit::VolumeRate::CubicInchPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicInchPerMinute>::FromStandard<NumericType>                        },
        {Unit::VolumeRate::CubicCentimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerMinute>::FromStandard<NumericType>                  },
        {Unit::VolumeRate::MillilitrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::MillilitrePerMinute>::FromStandard<NumericType>                       },
        {Unit::VolumeRate::CubicMillimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerMinute>::FromStandard<NumericType>                  },
        {Unit::VolumeRate::CubicMilliinchPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerMinute>::FromStandard<NumericType>                   },
        {Unit::VolumeRate::CubicMicrometrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerMinute>::FromStandard<NumericType>                  },
        {Unit::VolumeRate::CubicMicroinchPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerMinute>::FromStandard<NumericType>                   },
        {Unit::VolumeRate::CubicNauticalMilePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerHour>::FromStandard<NumericType>                  },
        {Unit::VolumeRate::CubicMilePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilePerHour>::FromStandard<NumericType>                          },
        {Unit::VolumeRate::CubicKilometrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerHour>::FromStandard<NumericType>                     },
        {Unit::VolumeRate::CubicMetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMetrePerHour>::FromStandard<NumericType>                         },
        {Unit::VolumeRate::CubicYardPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicYardPerHour>::FromStandard<NumericType>                          },
        {Unit::VolumeRate::CubicFootPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicFootPerHour>::FromStandard<NumericType>                          },
        {Unit::VolumeRate::CubicDecimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerHour>::FromStandard<NumericType>                     },
        {Unit::VolumeRate::LitrePerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>::FromStandard<NumericType>},
        {Unit::VolumeRate::CubicInchPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicInchPerHour>::FromStandard<NumericType>                          },
        {Unit::VolumeRate::CubicCentimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerHour>::FromStandard<NumericType>                    },
        {Unit::VolumeRate::MillilitrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::MillilitrePerHour>::FromStandard<NumericType>                         },
        {Unit::VolumeRate::CubicMillimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerHour>::FromStandard<NumericType>                    },
        {Unit::VolumeRate::CubicMilliinchPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerHour>::FromStandard<NumericType>                     },
        {Unit::VolumeRate::CubicMicrometrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerHour>::FromStandard<NumericType>                    },
        {Unit::VolumeRate::CubicMicroinchPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerHour>::FromStandard<NumericType>                     },
};

template <typename NumericType>
inline const std::map<Unit::VolumeRate,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::VolumeRate, NumericType>{
        {Unit::VolumeRate::CubicNauticalMilePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerSecond>::ToStandard<NumericType>                  },
        {Unit::VolumeRate::CubicMilePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilePerSecond>::ToStandard<NumericType>                          },
        {Unit::VolumeRate::CubicKilometrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerSecond>::ToStandard<NumericType>                     },
        {Unit::VolumeRate::CubicMetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMetrePerSecond>::ToStandard<NumericType>                         },
        {Unit::VolumeRate::CubicYardPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicYardPerSecond>::ToStandard<NumericType>                          },
        {Unit::VolumeRate::CubicFootPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicFootPerSecond>::ToStandard<NumericType>                          },
        {Unit::VolumeRate::CubicDecimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerSecond>::ToStandard<NumericType>                     },
        {Unit::VolumeRate::LitrePerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>::ToStandard<NumericType>},
        {Unit::VolumeRate::CubicInchPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicInchPerSecond>::ToStandard<NumericType>                          },
        {Unit::VolumeRate::CubicCentimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerSecond>::ToStandard<NumericType>                    },
        {Unit::VolumeRate::MillilitrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::MillilitrePerSecond>::ToStandard<NumericType>                         },
        {Unit::VolumeRate::CubicMillimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerSecond>::ToStandard<NumericType>                    },
        {Unit::VolumeRate::CubicMilliinchPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerSecond>::ToStandard<NumericType>                     },
        {Unit::VolumeRate::CubicMicrometrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerSecond>::ToStandard<NumericType>                    },
        {Unit::VolumeRate::CubicMicroinchPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerSecond>::ToStandard<NumericType>                     },
        {Unit::VolumeRate::CubicNauticalMilePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerMinute>::ToStandard<NumericType>                  },
        {Unit::VolumeRate::CubicMilePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilePerMinute>::ToStandard<NumericType>                          },
        {Unit::VolumeRate::CubicKilometrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerMinute>::ToStandard<NumericType>                     },
        {Unit::VolumeRate::CubicMetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMetrePerMinute>::ToStandard<NumericType>                         },
        {Unit::VolumeRate::CubicYardPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicYardPerMinute>::ToStandard<NumericType>                          },
        {Unit::VolumeRate::CubicFootPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicFootPerMinute>::ToStandard<NumericType>                          },
        {Unit::VolumeRate::CubicDecimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerMinute>::ToStandard<NumericType>                     },
        {Unit::VolumeRate::LitrePerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::LitrePerMinute>::ToStandard<NumericType>},
        {Unit::VolumeRate::CubicInchPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicInchPerMinute>::ToStandard<NumericType>                          },
        {Unit::VolumeRate::CubicCentimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerMinute>::ToStandard<NumericType>                    },
        {Unit::VolumeRate::MillilitrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::MillilitrePerMinute>::ToStandard<NumericType>                         },
        {Unit::VolumeRate::CubicMillimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerMinute>::ToStandard<NumericType>                    },
        {Unit::VolumeRate::CubicMilliinchPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerMinute>::ToStandard<NumericType>                     },
        {Unit::VolumeRate::CubicMicrometrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerMinute>::ToStandard<NumericType>                    },
        {Unit::VolumeRate::CubicMicroinchPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerMinute>::ToStandard<NumericType>                     },
        {Unit::VolumeRate::CubicNauticalMilePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerHour>::ToStandard<NumericType>                    },
        {Unit::VolumeRate::CubicMilePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilePerHour>::ToStandard<NumericType>                            },
        {Unit::VolumeRate::CubicKilometrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerHour>::ToStandard<NumericType>                       },
        {Unit::VolumeRate::CubicMetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMetrePerHour>::ToStandard<NumericType>                           },
        {Unit::VolumeRate::CubicYardPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicYardPerHour>::ToStandard<NumericType>                            },
        {Unit::VolumeRate::CubicFootPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicFootPerHour>::ToStandard<NumericType>                            },
        {Unit::VolumeRate::CubicDecimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerHour>::ToStandard<NumericType>                       },
        {Unit::VolumeRate::LitrePerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>::ToStandard<NumericType>  },
        {Unit::VolumeRate::CubicInchPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicInchPerHour>::ToStandard<NumericType>                            },
        {Unit::VolumeRate::CubicCentimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerHour>::ToStandard<NumericType>                      },
        {Unit::VolumeRate::MillilitrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::MillilitrePerHour>::ToStandard<NumericType>                           },
        {Unit::VolumeRate::CubicMillimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerHour>::ToStandard<NumericType>                      },
        {Unit::VolumeRate::CubicMilliinchPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerHour>::ToStandard<NumericType>                       },
        {Unit::VolumeRate::CubicMicrometrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerHour>::ToStandard<NumericType>                      },
        {Unit::VolumeRate::CubicMicroinchPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerHour>::ToStandard<NumericType>                       },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_VOLUME_RATE_HPP
