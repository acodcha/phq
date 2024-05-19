// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

// Volume rate units. Can represent a time rate of change of a volume or a
// volume flow rate.
enum class VolumeRate : int8_t {
  // Cubic nautical mile per second (nmi^3/s) volume rate unit.
  CubicNauticalMilePerSecond,

  // Cubic mile per second (mi^3/s) volume rate unit.
  CubicMilePerSecond,

  // Cubic kilometre per second (km^3/s) volume rate unit.
  CubicKilometrePerSecond,

  // Cubic metre per second (m^3/s) volume rate unit.
  CubicMetrePerSecond,

  // Cubic yard per second (yd^3/s) volume rate unit.
  CubicYardPerSecond,

  // Cubic foot per second (ft^3/s) volume rate unit.
  CubicFootPerSecond,

  // Cubic decimetre per second (dm^3/s) volume rate unit.
  CubicDecimetrePerSecond,

  // Litre per second (L/s) volume rate unit.
  LitrePerSecond,

  // Cubic inch per second (in^3/s) volume rate unit.
  CubicInchPerSecond,

  // Cubic centimetre per second (cm^3/s) volume rate unit.
  CubicCentimetrePerSecond,

  // Millilitre per second (mL/s) volume rate unit.
  MillilitrePerSecond,

  // Cubic millimetre per second (mm^3/s) volume rate unit.
  CubicMillimetrePerSecond,

  // Cubic milliinch per second (mil^3/s) volume rate unit.
  CubicMilliinchPerSecond,

  // Cubic micrometre per second (μm^3/s) volume rate unit.
  CubicMicrometrePerSecond,

  // Cubic microinch per second (μin^3/s) volume rate unit.
  CubicMicroinchPerSecond,

  // Cubic nautical mile per minute (nmi^3/min) volume rate unit.
  CubicNauticalMilePerMinute,

  // Cubic mile per minute (mi^3/min) volume rate unit.
  CubicMilePerMinute,

  // Cubic kilometre per minute (km^3/min) volume rate unit.
  CubicKilometrePerMinute,

  // Cubic metre per minute (m^3/min) volume rate unit.
  CubicMetrePerMinute,

  // Cubic yard per minute (yd^3/min) volume rate unit.
  CubicYardPerMinute,

  // Cubic foot per minute (ft^3/min) volume rate unit.
  CubicFootPerMinute,

  // Cubic decimetre per minute (dm^3/min) volume rate unit.
  CubicDecimetrePerMinute,

  // Litre per minute (L/min) volume rate unit.
  LitrePerMinute,

  // Cubic inch per minute (in^3/min) volume rate unit.
  CubicInchPerMinute,

  // Cubic centimetre per minute (cm^3/min) volume rate unit.
  CubicCentimetrePerMinute,

  // Millilitre per minute (mL/min) volume rate unit.
  MillilitrePerMinute,

  // Cubic millimetre per minute (mm^3/min) volume rate unit.
  CubicMillimetrePerMinute,

  // Cubic milliinch per minute (mil^3/min) volume rate unit.
  CubicMilliinchPerMinute,

  // Cubic micrometre per minute (μm^3/min) volume rate unit.
  CubicMicrometrePerMinute,

  // Cubic microinch per minute (μin^3/min) volume rate unit.
  CubicMicroinchPerMinute,

  // Cubic nautical mile per hour (nmi^3/hr) volume rate unit.
  CubicNauticalMilePerHour,

  // Cubic mile per hour (mi^3/hr) volume rate unit.
  CubicMilePerHour,

  // Cubic kilometre per hour (km^3/hr) volume rate unit.
  CubicKilometrePerHour,

  // Cubic metre per hour (m^3/hr) volume rate unit.
  CubicMetrePerHour,

  // Cubic yard per hour (yd^3/hr) volume rate unit.
  CubicYardPerHour,

  // Cubic foot per hour (ft^3/hr) volume rate unit.
  CubicFootPerHour,

  // Cubic decimetre per hour (dm^3/hr) volume rate unit.
  CubicDecimetrePerHour,

  // Litre per hour (L/hr) volume rate unit.
  LitrePerHour,

  // Cubic inch per hour (in^3/hr) volume rate unit.
  CubicInchPerHour,

  // Cubic centimetre per hour (cm^3/hr) volume rate unit.
  CubicCentimetrePerHour,

  // Millilitre per hour (mL/hr) volume rate unit.
  MillilitrePerHour,

  // Cubic millimetre per hour (mm^3/hr) volume rate unit.
  CubicMillimetrePerHour,

  // Cubic milliinch per hour (mil^3/hr) volume rate unit.
  CubicMilliinchPerHour,

  // Cubic micrometre per hour (μm^3/hr) volume rate unit.
  CubicMicrometrePerHour,

  // Cubic microinch per hour (μin^3/hr) volume rate unit.
  CubicMicroinchPerHour,
};

}  // namespace Unit

// Standard time-rate of volume unit: cubic metre per second (m^3/s).
template <>
inline constexpr const Unit::VolumeRate Standard<Unit::VolumeRate>{
    Unit::VolumeRate::CubicMetrePerSecond};

// Physical dimension set of time-rate of volume units.
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

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerSecond>::FromStandard(
    Number& value) noexcept {
  value /=
      (static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerSecond>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L)
            * static_cast<Number>(1609.344L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L)
           * static_cast<Number>(1609.344L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerSecond>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerSecond>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>::FromStandard(
    Number& value) noexcept {
  value /=
      (static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>::FromStandard(
    Number& value) noexcept {
  value /=
      (static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>::FromStandard(
    Number& value) noexcept {
  value /=
      (static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(0.0000254L) * static_cast<Number>(0.0000254L)
            * static_cast<Number>(0.0000254L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L) * static_cast<Number>(0.0000254L)
           * static_cast<Number>(0.0000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerSecond>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E18L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-18L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerSecond>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(0.0000000254L) * static_cast<Number>(0.0000000254L)
            * static_cast<Number>(0.0000000254L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerSecond>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L) * static_cast<Number>(0.0000000254L)
           * static_cast<Number>(0.0000000254L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L)
           / (static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L)
              * static_cast<Number>(1852.0L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L)
           * static_cast<Number>(1852.0L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L)
           / (static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L)
              * static_cast<Number>(1609.344L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L)
           * static_cast<Number>(1609.344L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerMinute>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L)
           / (static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L)
              * static_cast<Number>(0.9144L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L)
           * static_cast<Number>(0.9144L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L)
           / (static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L)
              * static_cast<Number>(0.3048L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L)
           * static_cast<Number>(0.3048L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) / static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L)
           / (static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L)
              * static_cast<Number>(0.0254L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L)
           * static_cast<Number>(0.0254L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) * static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) * static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) * static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L)
           / (static_cast<Number>(0.0000254L) * static_cast<Number>(0.0000254L)
              * static_cast<Number>(0.0000254L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L) * static_cast<Number>(0.0000254L)
           * static_cast<Number>(0.0000254L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L) * static_cast<Number>(1.0E18L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-18L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerMinute>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L)
           / (static_cast<Number>(0.0000000254L) * static_cast<Number>(0.0000000254L)
              * static_cast<Number>(0.0000000254L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L) * static_cast<Number>(0.0000000254L)
           * static_cast<Number>(0.0000000254L) / static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L)
           / (static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L)
              * static_cast<Number>(1852.0L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicNauticalMilePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1852.0L) * static_cast<Number>(1852.0L)
           * static_cast<Number>(1852.0L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L)
           / (static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L)
              * static_cast<Number>(1609.344L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1609.344L) * static_cast<Number>(1609.344L)
           * static_cast<Number>(1609.344L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicKilometrePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E9L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerHour>::ToStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L)
           / (static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L)
              * static_cast<Number>(0.9144L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.9144L) * static_cast<Number>(0.9144L)
           * static_cast<Number>(0.9144L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L)
           / (static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L)
              * static_cast<Number>(0.3048L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) * static_cast<Number>(0.3048L)
           * static_cast<Number>(0.3048L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicDecimetrePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) / static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L)
           / (static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L)
              * static_cast<Number>(0.0254L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) * static_cast<Number>(0.0254L)
           * static_cast<Number>(0.0254L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) * static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicCentimetrePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) * static_cast<Number>(1.0E6L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-6L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) * static_cast<Number>(1.0E9L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMillimetrePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-9L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L)
           / (static_cast<Number>(0.0000254L) * static_cast<Number>(0.0000254L)
              * static_cast<Number>(0.0000254L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMilliinchPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000254L) * static_cast<Number>(0.0000254L)
           * static_cast<Number>(0.0000254L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L) * static_cast<Number>(1.0E18L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicrometrePerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.0E-18L) / static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerHour>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L)
           / (static_cast<Number>(0.0000000254L) * static_cast<Number>(0.0000000254L)
              * static_cast<Number>(0.0000000254L));
}

template <>
template <typename Number>
inline constexpr void
Conversion<Unit::VolumeRate, Unit::VolumeRate::CubicMicroinchPerHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0000000254L) * static_cast<Number>(0.0000000254L)
           * static_cast<Number>(0.0000000254L) / static_cast<Number>(3600.0L);
}

template <typename Number>
inline const std::map<Unit::VolumeRate, std::function<void(Number* const, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::VolumeRate, Number>{
        {Unit::VolumeRate::CubicNauticalMilePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerSecond>::FromStandard<Number>                      },
        {Unit::VolumeRate::CubicMilePerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>::FromStandard<Number>},
        {Unit::VolumeRate::CubicKilometrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerSecond>::FromStandard<Number>                         },
        {Unit::VolumeRate::CubicMetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMetrePerSecond>::FromStandard<Number>                             },
        {Unit::VolumeRate::CubicYardPerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>::FromStandard<Number>},
        {Unit::VolumeRate::CubicFootPerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>::FromStandard<Number>},
        {Unit::VolumeRate::CubicDecimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerSecond>::FromStandard<Number>                         },
        {Unit::VolumeRate::LitrePerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>::FromStandard<Number>    },
        {Unit::VolumeRate::CubicInchPerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>::FromStandard<Number>},
        {Unit::VolumeRate::CubicCentimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerSecond>::FromStandard<Number>                        },
        {Unit::VolumeRate::MillilitrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::MillilitrePerSecond>::FromStandard<Number>                             },
        {Unit::VolumeRate::CubicMillimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerSecond>::FromStandard<Number>                        },
        {Unit::VolumeRate::CubicMilliinchPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerSecond>::FromStandard<Number>                         },
        {Unit::VolumeRate::CubicMicrometrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerSecond>::FromStandard<Number>                        },
        {Unit::VolumeRate::CubicMicroinchPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerSecond>::FromStandard<Number>                         },
        {Unit::VolumeRate::CubicNauticalMilePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerMinute>::FromStandard<Number>                      },
        {Unit::VolumeRate::CubicMilePerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerMinute>::FromStandard<Number>},
        {Unit::VolumeRate::CubicKilometrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerMinute>::FromStandard<Number>                         },
        {Unit::VolumeRate::CubicMetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMetrePerMinute>::FromStandard<Number>                             },
        {Unit::VolumeRate::CubicYardPerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerMinute>::FromStandard<Number>},
        {Unit::VolumeRate::CubicFootPerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerMinute>::FromStandard<Number>},
        {Unit::VolumeRate::CubicDecimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerMinute>::FromStandard<Number>                         },
        {Unit::VolumeRate::LitrePerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::LitrePerMinute>::FromStandard<Number>    },
        {Unit::VolumeRate::CubicInchPerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerMinute>::FromStandard<Number>},
        {Unit::VolumeRate::CubicCentimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerMinute>::FromStandard<Number>                        },
        {Unit::VolumeRate::MillilitrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::MillilitrePerMinute>::FromStandard<Number>                             },
        {Unit::VolumeRate::CubicMillimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerMinute>::FromStandard<Number>                        },
        {Unit::VolumeRate::CubicMilliinchPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerMinute>::FromStandard<Number>                         },
        {Unit::VolumeRate::CubicMicrometrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerMinute>::FromStandard<Number>                        },
        {Unit::VolumeRate::CubicMicroinchPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerMinute>::FromStandard<Number>                         },
        {Unit::VolumeRate::CubicNauticalMilePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerHour>::FromStandard<Number>                        },
        {Unit::VolumeRate::CubicMilePerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerHour>::FromStandard<Number>  },
        {Unit::VolumeRate::CubicKilometrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerHour>::FromStandard<Number>                           },
        {Unit::VolumeRate::CubicMetrePerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerHour>::FromStandard<Number> },
        {Unit::VolumeRate::CubicYardPerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerHour>::FromStandard<Number>  },
        {Unit::VolumeRate::CubicFootPerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerHour>::FromStandard<Number>  },
        {Unit::VolumeRate::CubicDecimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerHour>::FromStandard<Number>                           },
        {Unit::VolumeRate::LitrePerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>::FromStandard<Number>      },
        {Unit::VolumeRate::CubicInchPerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerHour>::FromStandard<Number>  },
        {Unit::VolumeRate::CubicCentimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerHour>::FromStandard<Number>                          },
        {Unit::VolumeRate::MillilitrePerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerHour>::FromStandard<Number> },
        {Unit::VolumeRate::CubicMillimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerHour>::FromStandard<Number>                          },
        {Unit::VolumeRate::CubicMilliinchPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerHour>::FromStandard<Number>                           },
        {Unit::VolumeRate::CubicMicrometrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerHour>::FromStandard<Number>                          },
        {Unit::VolumeRate::CubicMicroinchPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerHour>::FromStandard<Number>                           },
};

template <typename Number>
inline const std::map<Unit::VolumeRate, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::VolumeRate, Number>{
        {Unit::VolumeRate::CubicNauticalMilePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerSecond>::ToStandard<Number>                       },
        {Unit::VolumeRate::CubicMilePerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerSecond>::ToStandard<Number> },
        {Unit::VolumeRate::CubicKilometrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerSecond>::ToStandard<Number>                          },
        {Unit::VolumeRate::CubicMetrePerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerSecond>::ToStandard<Number>},
        {Unit::VolumeRate::CubicYardPerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerSecond>::ToStandard<Number> },
        {Unit::VolumeRate::CubicFootPerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerSecond>::ToStandard<Number> },
        {Unit::VolumeRate::CubicDecimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerSecond>::ToStandard<Number>                          },
        {Unit::VolumeRate::LitrePerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::LitrePerSecond>::ToStandard<Number>     },
        {Unit::VolumeRate::CubicInchPerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerSecond>::ToStandard<Number> },
        {Unit::VolumeRate::CubicCentimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerSecond>::ToStandard<Number>                         },
        {Unit::VolumeRate::MillilitrePerSecond,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerSecond>::ToStandard<Number>},
        {Unit::VolumeRate::CubicMillimetrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerSecond>::ToStandard<Number>                         },
        {Unit::VolumeRate::CubicMilliinchPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerSecond>::ToStandard<Number>                          },
        {Unit::VolumeRate::CubicMicrometrePerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerSecond>::ToStandard<Number>                         },
        {Unit::VolumeRate::CubicMicroinchPerSecond,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerSecond>::ToStandard<Number>                          },
        {Unit::VolumeRate::CubicNauticalMilePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerMinute>::ToStandard<Number>                       },
        {Unit::VolumeRate::CubicMilePerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerMinute>::ToStandard<Number> },
        {Unit::VolumeRate::CubicKilometrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerMinute>::ToStandard<Number>                          },
        {Unit::VolumeRate::CubicMetrePerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerMinute>::ToStandard<Number>},
        {Unit::VolumeRate::CubicYardPerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerMinute>::ToStandard<Number> },
        {Unit::VolumeRate::CubicFootPerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerMinute>::ToStandard<Number> },
        {Unit::VolumeRate::CubicDecimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerMinute>::ToStandard<Number>                          },
        {Unit::VolumeRate::LitrePerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::LitrePerMinute>::ToStandard<Number>     },
        {Unit::VolumeRate::CubicInchPerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerMinute>::ToStandard<Number> },
        {Unit::VolumeRate::CubicCentimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerMinute>::ToStandard<Number>                         },
        {Unit::VolumeRate::MillilitrePerMinute,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerMinute>::ToStandard<Number>},
        {Unit::VolumeRate::CubicMillimetrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerMinute>::ToStandard<Number>                         },
        {Unit::VolumeRate::CubicMilliinchPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerMinute>::ToStandard<Number>                          },
        {Unit::VolumeRate::CubicMicrometrePerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerMinute>::ToStandard<Number>                         },
        {Unit::VolumeRate::CubicMicroinchPerMinute,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerMinute>::ToStandard<Number>                          },
        {Unit::VolumeRate::CubicNauticalMilePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicNauticalMilePerHour>::ToStandard<Number>                         },
        {Unit::VolumeRate::CubicMilePerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicMilePerHour>::ToStandard<Number>   },
        {Unit::VolumeRate::CubicKilometrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicKilometrePerHour>::ToStandard<Number>                            },
        {Unit::VolumeRate::CubicMetrePerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicMetrePerHour>::ToStandard<Number>  },
        {Unit::VolumeRate::CubicYardPerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicYardPerHour>::ToStandard<Number>   },
        {Unit::VolumeRate::CubicFootPerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicFootPerHour>::ToStandard<Number>   },
        {Unit::VolumeRate::CubicDecimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicDecimetrePerHour>::ToStandard<Number>                            },
        {Unit::VolumeRate::LitrePerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::LitrePerHour>::ToStandard<Number>       },
        {Unit::VolumeRate::CubicInchPerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::CubicInchPerHour>::ToStandard<Number>   },
        {Unit::VolumeRate::CubicCentimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicCentimetrePerHour>::ToStandard<Number>                           },
        {Unit::VolumeRate::MillilitrePerHour,
         Conversions<Unit::VolumeRate, Unit::VolumeRate::MillilitrePerHour>::ToStandard<Number>  },
        {Unit::VolumeRate::CubicMillimetrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMillimetrePerHour>::ToStandard<Number>                           },
        {Unit::VolumeRate::CubicMilliinchPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMilliinchPerHour>::ToStandard<Number>                            },
        {Unit::VolumeRate::CubicMicrometrePerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicrometrePerHour>::ToStandard<Number>                           },
        {Unit::VolumeRate::CubicMicroinchPerHour,
         Conversions<Unit::VolumeRate,
         Unit::VolumeRate::CubicMicroinchPerHour>::ToStandard<Number>                            },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_VOLUME_RATE_HPP
