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

#ifndef PHQ_UNIT_ACCELERATION_HPP
#define PHQ_UNIT_ACCELERATION_HPP

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

/// \brief Acceleration units.
enum class Acceleration : int8_t {
  /// \brief Nautical mile per square second (nmi/s^2) acceleration unit.
  NauticalMilePerSquareSecond,

  /// \brief Nautical mile per square minute (nmi/min^2) acceleration unit.
  NauticalMilePerSquareMinute,

  /// \brief Knot per hour (kn/hr) acceleration unit, also known as nautical mile per square hour.
  KnotPerHour,

  /// \brief Mile per square second (mi/s^2) acceleration unit.
  MilePerSquareSecond,

  /// \brief Mile per square minute (mi/min^2) acceleration unit.
  MilePerSquareMinute,

  /// \brief Mile per square hour (mi/hr^2) acceleration unit.
  MilePerSquareHour,

  /// \brief Kilometre per square second (km/s^2) acceleration unit.
  KilometrePerSquareSecond,

  /// \brief Kilometre per square minute (km/min^2) acceleration unit.
  KilometrePerSquareMinute,

  /// \brief Kilometre per square hour (km/hr^2) acceleration unit.
  KilometrePerSquareHour,

  /// \brief Metre per square second (m/s^2) acceleration unit.
  MetrePerSquareSecond,

  /// \brief Metre per square minute (m/min^2) acceleration unit.
  MetrePerSquareMinute,

  /// \brief Metre per square hour (m/hr^2) acceleration unit.
  MetrePerSquareHour,

  /// \brief Yard per square second (yd/s^2) acceleration unit.
  YardPerSquareSecond,

  /// \brief Yard per square minute (yd/min^2) acceleration unit.
  YardPerSquareMinute,

  /// \brief Yard per square hour (yd/hr^2) acceleration unit.
  YardPerSquareHour,

  /// \brief Foot per square second (ft/s^2) acceleration unit.
  FootPerSquareSecond,

  /// \brief Foot per square minute (ft/min^2) acceleration unit.
  FootPerSquareMinute,

  /// \brief Foot per square hour (ft/hr^2) acceleration unit.
  FootPerSquareHour,

  /// \brief Decimetre per square second (dm/s^2) acceleration unit.
  DecimetrePerSquareSecond,

  /// \brief Decimetre per square minute (dm/min^2) acceleration unit.
  DecimetrePerSquareMinute,

  /// \brief Decimetre per square hour (dm/hr^2) acceleration unit.
  DecimetrePerSquareHour,

  /// \brief Inch per square second (in/s^2) acceleration unit.
  InchPerSquareSecond,

  /// \brief Inch per square minute (in/min^2) acceleration unit.
  InchPerSquareMinute,

  /// \brief Inch per square hour (in/hr^2) acceleration unit.
  InchPerSquareHour,

  /// \brief Centimetre per square second (cm/s^2) acceleration unit.
  CentimetrePerSquareSecond,

  /// \brief Centimetre per square minute (cm/min^2) acceleration unit.
  CentimetrePerSquareMinute,

  /// \brief Centimetre per square hour (cm/hr^2) acceleration unit.
  CentimetrePerSquareHour,

  /// \brief Millimetre per square second (mm/s^2) acceleration unit.
  MillimetrePerSquareSecond,

  /// \brief Millimetre per square minute (mm/min^2) acceleration unit.
  MillimetrePerSquareMinute,

  /// \brief Millimetre per square hour (mm/hr^2) acceleration unit.
  MillimetrePerSquareHour,

  /// \brief Milliinch per square second (mil/s^2) acceleration unit.
  MilliinchPerSquareSecond,

  /// \brief Milliinch per square minute (mil/min^2) acceleration unit.
  MilliinchPerSquareMinute,

  /// \brief Milliinch per square hour (mil/hr^2) acceleration unit.
  MilliinchPerSquareHour,

  /// \brief Micrometre per square second (μm/s^2) acceleration unit.
  MicrometrePerSquareSecond,

  /// \brief Micrometre per square minute (μm/min^2) acceleration unit.
  MicrometrePerSquareMinute,

  /// \brief Micrometre per square hour (μm/hr^2) acceleration unit.
  MicrometrePerSquareHour,

  /// \brief Microinch per square second (μin/s^2) acceleration unit.
  MicroinchPerSquareSecond,

  /// \brief Microinch per square minute (μin/min^2) acceleration unit.
  MicroinchPerSquareMinute,

  /// \brief Microinch per square hour (μin/hr^2) acceleration unit.
  MicroinchPerSquareHour,
};

}  // namespace Unit

/// \brief Standard acceleration unit: metre per square second (m/s^2).
template <>
inline constexpr const Unit::Acceleration Standard<Unit::Acceleration>{
    Unit::Acceleration::MetrePerSquareSecond};

/// \brief Physical dimension set of acceleration units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Acceleration>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{0},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Acceleration unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Acceleration> ConsistentUnits<Unit::Acceleration>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Acceleration::MetrePerSquareSecond     },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Acceleration::MillimetrePerSquareSecond},
    {UnitSystem::FootPoundSecondRankine,     Unit::Acceleration::FootPerSquareSecond      },
    {UnitSystem::InchPoundSecondRankine,     Unit::Acceleration::InchPerSquareSecond      },
};

template <>
inline const std::map<Unit::Acceleration, UnitSystem> RelatedUnitSystems<Unit::Acceleration>{
    {Unit::Acceleration::MetrePerSquareSecond,      UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Acceleration::MillimetrePerSquareSecond, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Acceleration::FootPerSquareSecond,       UnitSystem::FootPoundSecondRankine    },
    {Unit::Acceleration::InchPerSquareSecond,       UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::Acceleration, std::string_view> Abbreviations<Unit::Acceleration>{
    {Unit::Acceleration::NauticalMilePerSquareSecond, "nmi/s^2"  },
    {Unit::Acceleration::NauticalMilePerSquareMinute, "nmi/min^2"},
    {Unit::Acceleration::KnotPerHour,                 "kn/hr"    },
    {Unit::Acceleration::MilePerSquareSecond,         "mi/s^2"   },
    {Unit::Acceleration::MilePerSquareMinute,         "mi/min^2" },
    {Unit::Acceleration::MilePerSquareHour,           "mi/hr^2"  },
    {Unit::Acceleration::KilometrePerSquareSecond,    "km/s^2"   },
    {Unit::Acceleration::KilometrePerSquareMinute,    "km/min^2" },
    {Unit::Acceleration::KilometrePerSquareHour,      "km/hr^2"  },
    {Unit::Acceleration::YardPerSquareSecond,         "yd/s^2"   },
    {Unit::Acceleration::YardPerSquareMinute,         "yd/min^2" },
    {Unit::Acceleration::YardPerSquareHour,           "yd/hr^2"  },
    {Unit::Acceleration::MetrePerSquareSecond,        "m/s^2"    },
    {Unit::Acceleration::MetrePerSquareMinute,        "m/min^2"  },
    {Unit::Acceleration::MetrePerSquareHour,          "m/hr^2"   },
    {Unit::Acceleration::FootPerSquareSecond,         "ft/s^2"   },
    {Unit::Acceleration::FootPerSquareMinute,         "ft/min^2" },
    {Unit::Acceleration::FootPerSquareHour,           "ft/hr^2"  },
    {Unit::Acceleration::DecimetrePerSquareSecond,    "dm/s^2"   },
    {Unit::Acceleration::DecimetrePerSquareMinute,    "dm/min^2" },
    {Unit::Acceleration::DecimetrePerSquareHour,      "dm/hr^2"  },
    {Unit::Acceleration::InchPerSquareSecond,         "in/s^2"   },
    {Unit::Acceleration::InchPerSquareMinute,         "in/min^2" },
    {Unit::Acceleration::InchPerSquareHour,           "in/hr^2"  },
    {Unit::Acceleration::CentimetrePerSquareSecond,   "cm/s^2"   },
    {Unit::Acceleration::CentimetrePerSquareMinute,   "cm/min^2" },
    {Unit::Acceleration::CentimetrePerSquareHour,     "cm/hr^2"  },
    {Unit::Acceleration::MillimetrePerSquareSecond,   "mm/s^2"   },
    {Unit::Acceleration::MillimetrePerSquareMinute,   "mm/min^2" },
    {Unit::Acceleration::MillimetrePerSquareHour,     "mm/hr^2"  },
    {Unit::Acceleration::MilliinchPerSquareSecond,    "mil/s^2"  },
    {Unit::Acceleration::MilliinchPerSquareMinute,    "mil/min^2"},
    {Unit::Acceleration::MilliinchPerSquareHour,      "mil/hr^2" },
    {Unit::Acceleration::MicrometrePerSquareSecond,   "μm/s^2"   },
    {Unit::Acceleration::MicrometrePerSquareMinute,   "μm/min^2" },
    {Unit::Acceleration::MicrometrePerSquareHour,     "μm/hr^2"  },
    {Unit::Acceleration::MicroinchPerSquareSecond,    "μin/s^2"  },
    {Unit::Acceleration::MicroinchPerSquareMinute,    "μin/min^2"},
    {Unit::Acceleration::MicroinchPerSquareHour,      "μin/hr^2" },
};

template <>
inline const std::unordered_map<std::string_view, Unit::Acceleration> Spellings<Unit::Acceleration>{
    {"nmi/s^2",           Unit::Acceleration::NauticalMilePerSquareSecond},
    {"nmi/s2",            Unit::Acceleration::NauticalMilePerSquareSecond},
    {"nmi/s/s",           Unit::Acceleration::NauticalMilePerSquareSecond},
    {"nmi/min^2",         Unit::Acceleration::NauticalMilePerSquareMinute},
    {"nmi/min2",          Unit::Acceleration::NauticalMilePerSquareMinute},
    {"nmi/min/min",       Unit::Acceleration::NauticalMilePerSquareMinute},
    {"kn/hr",             Unit::Acceleration::KnotPerHour                },
    {"nmi/hr^2",          Unit::Acceleration::KnotPerHour                },
    {"nmi/hr2",           Unit::Acceleration::KnotPerHour                },
    {"nmi/hr/hr",         Unit::Acceleration::KnotPerHour                },
    {"mi/s^2",            Unit::Acceleration::MilePerSquareSecond        },
    {"mi/s2",             Unit::Acceleration::MilePerSquareSecond        },
    {"mi/s/s",            Unit::Acceleration::MilePerSquareSecond        },
    {"mi/min^2",          Unit::Acceleration::MilePerSquareMinute        },
    {"mi/min2",           Unit::Acceleration::MilePerSquareMinute        },
    {"mi/min/min",        Unit::Acceleration::MilePerSquareMinute        },
    {"mi/hr^2",           Unit::Acceleration::MilePerSquareHour          },
    {"mi/hr2",            Unit::Acceleration::MilePerSquareHour          },
    {"mi/hr/hr",          Unit::Acceleration::MilePerSquareHour          },
    {"km/s^2",            Unit::Acceleration::KilometrePerSquareSecond   },
    {"km/s2",             Unit::Acceleration::KilometrePerSquareSecond   },
    {"km/s/s",            Unit::Acceleration::KilometrePerSquareSecond   },
    {"km/min^2",          Unit::Acceleration::KilometrePerSquareMinute   },
    {"km/min2",           Unit::Acceleration::KilometrePerSquareMinute   },
    {"km/min/min",        Unit::Acceleration::KilometrePerSquareMinute   },
    {"km/hr^2",           Unit::Acceleration::KilometrePerSquareHour     },
    {"km/hr2",            Unit::Acceleration::KilometrePerSquareHour     },
    {"km/hr/hr",          Unit::Acceleration::KilometrePerSquareHour     },
    {"yd/s^2",            Unit::Acceleration::YardPerSquareSecond        },
    {"yd/s2",             Unit::Acceleration::YardPerSquareSecond        },
    {"yd/s/s",            Unit::Acceleration::YardPerSquareSecond        },
    {"yd/min^2",          Unit::Acceleration::YardPerSquareMinute        },
    {"yd/min2",           Unit::Acceleration::YardPerSquareMinute        },
    {"yd/min/min",        Unit::Acceleration::YardPerSquareMinute        },
    {"yd/hr^2",           Unit::Acceleration::YardPerSquareHour          },
    {"yd/hr2",            Unit::Acceleration::YardPerSquareHour          },
    {"yd/hr/hr",          Unit::Acceleration::YardPerSquareHour          },
    {"m/s^2",             Unit::Acceleration::MetrePerSquareSecond       },
    {"m/s2",              Unit::Acceleration::MetrePerSquareSecond       },
    {"m/s/s",             Unit::Acceleration::MetrePerSquareSecond       },
    {"m/min^2",           Unit::Acceleration::MetrePerSquareMinute       },
    {"m/min2",            Unit::Acceleration::MetrePerSquareMinute       },
    {"m/min/min",         Unit::Acceleration::MetrePerSquareMinute       },
    {"m/hr^2",            Unit::Acceleration::MetrePerSquareHour         },
    {"m/hr2",             Unit::Acceleration::MetrePerSquareHour         },
    {"m/hr/hr",           Unit::Acceleration::MetrePerSquareHour         },
    {"ft/s^2",            Unit::Acceleration::FootPerSquareSecond        },
    {"ft/s2",             Unit::Acceleration::FootPerSquareSecond        },
    {"ft/s/s",            Unit::Acceleration::FootPerSquareSecond        },
    {"ft/min^2",          Unit::Acceleration::FootPerSquareMinute        },
    {"ft/min2",           Unit::Acceleration::FootPerSquareMinute        },
    {"ft/min/min",        Unit::Acceleration::FootPerSquareMinute        },
    {"ft/hr^2",           Unit::Acceleration::FootPerSquareHour          },
    {"ft/hr2",            Unit::Acceleration::FootPerSquareHour          },
    {"ft/hr/hr",          Unit::Acceleration::FootPerSquareHour          },
    {"dm/s^2",            Unit::Acceleration::DecimetrePerSquareSecond   },
    {"dm/s2",             Unit::Acceleration::DecimetrePerSquareSecond   },
    {"dm/s/s",            Unit::Acceleration::DecimetrePerSquareSecond   },
    {"dm/min^2",          Unit::Acceleration::DecimetrePerSquareMinute   },
    {"dm/min2",           Unit::Acceleration::DecimetrePerSquareMinute   },
    {"dm/min/min",        Unit::Acceleration::DecimetrePerSquareMinute   },
    {"dm/hr^2",           Unit::Acceleration::DecimetrePerSquareHour     },
    {"dm/hr2",            Unit::Acceleration::DecimetrePerSquareHour     },
    {"dm/hr/hr",          Unit::Acceleration::DecimetrePerSquareHour     },
    {"in/s^2",            Unit::Acceleration::InchPerSquareSecond        },
    {"in/s2",             Unit::Acceleration::InchPerSquareSecond        },
    {"in/s/s",            Unit::Acceleration::InchPerSquareSecond        },
    {"in/min^2",          Unit::Acceleration::InchPerSquareMinute        },
    {"in/min2",           Unit::Acceleration::InchPerSquareMinute        },
    {"in/min/min",        Unit::Acceleration::InchPerSquareMinute        },
    {"in/hr^2",           Unit::Acceleration::InchPerSquareHour          },
    {"in/hr2",            Unit::Acceleration::InchPerSquareHour          },
    {"in/hr/hr",          Unit::Acceleration::InchPerSquareHour          },
    {"cm/s^2",            Unit::Acceleration::CentimetrePerSquareSecond  },
    {"cm/s2",             Unit::Acceleration::CentimetrePerSquareSecond  },
    {"cm/s/s",            Unit::Acceleration::CentimetrePerSquareSecond  },
    {"cm/min^2",          Unit::Acceleration::CentimetrePerSquareMinute  },
    {"cm/min2",           Unit::Acceleration::CentimetrePerSquareMinute  },
    {"cm/min/min",        Unit::Acceleration::CentimetrePerSquareMinute  },
    {"cm/hr^2",           Unit::Acceleration::CentimetrePerSquareHour    },
    {"cm/hr2",            Unit::Acceleration::CentimetrePerSquareHour    },
    {"cm/hr/hr",          Unit::Acceleration::CentimetrePerSquareHour    },
    {"mm/s^2",            Unit::Acceleration::MillimetrePerSquareSecond  },
    {"mm/s2",             Unit::Acceleration::MillimetrePerSquareSecond  },
    {"mm/s/s",            Unit::Acceleration::MillimetrePerSquareSecond  },
    {"mm/min^2",          Unit::Acceleration::MillimetrePerSquareMinute  },
    {"mm/min2",           Unit::Acceleration::MillimetrePerSquareMinute  },
    {"mm/min/min",        Unit::Acceleration::MillimetrePerSquareMinute  },
    {"mm/hr^2",           Unit::Acceleration::MillimetrePerSquareHour    },
    {"mm/hr2",            Unit::Acceleration::MillimetrePerSquareHour    },
    {"mm/hr/hr",          Unit::Acceleration::MillimetrePerSquareHour    },
    {"milin/s^2",         Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milin/s2",          Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milin/s/s",         Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milliinch/s^2",     Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milliinch/s2",      Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milliinch/s/s",     Unit::Acceleration::MilliinchPerSquareSecond   },
    {"mil/s^2",           Unit::Acceleration::MilliinchPerSquareSecond   },
    {"mil/s2",            Unit::Acceleration::MilliinchPerSquareSecond   },
    {"mil/s/s",           Unit::Acceleration::MilliinchPerSquareSecond   },
    {"thou/s^2",          Unit::Acceleration::MilliinchPerSquareSecond   },
    {"thou/s2",           Unit::Acceleration::MilliinchPerSquareSecond   },
    {"thou/s/s",          Unit::Acceleration::MilliinchPerSquareSecond   },
    {"milin/min^2",       Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milin/min2",        Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milin/min/min",     Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milliinch/min^2",   Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milliinch/min2",    Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milliinch/min/min", Unit::Acceleration::MilliinchPerSquareMinute   },
    {"mil/min^2",         Unit::Acceleration::MilliinchPerSquareMinute   },
    {"mil/min2",          Unit::Acceleration::MilliinchPerSquareMinute   },
    {"mil/min/min",       Unit::Acceleration::MilliinchPerSquareMinute   },
    {"thou/min^2",        Unit::Acceleration::MilliinchPerSquareMinute   },
    {"thou/min2",         Unit::Acceleration::MilliinchPerSquareMinute   },
    {"thou/min/min",      Unit::Acceleration::MilliinchPerSquareMinute   },
    {"milin/hr^2",        Unit::Acceleration::MilliinchPerSquareHour     },
    {"milin/hr2",         Unit::Acceleration::MilliinchPerSquareHour     },
    {"milin/hr/hr",       Unit::Acceleration::MilliinchPerSquareHour     },
    {"milliinch/hr^2",    Unit::Acceleration::MilliinchPerSquareHour     },
    {"milliinch/hr2",     Unit::Acceleration::MilliinchPerSquareHour     },
    {"milliinch/hr/hr",   Unit::Acceleration::MilliinchPerSquareHour     },
    {"mil/hr^2",          Unit::Acceleration::MilliinchPerSquareHour     },
    {"mil/hr2",           Unit::Acceleration::MilliinchPerSquareHour     },
    {"mil/hr/hr",         Unit::Acceleration::MilliinchPerSquareHour     },
    {"thou/hr^2",         Unit::Acceleration::MilliinchPerSquareHour     },
    {"thou/hr2",          Unit::Acceleration::MilliinchPerSquareHour     },
    {"thou/hr/hr",        Unit::Acceleration::MilliinchPerSquareHour     },
    {"μm/s^2",            Unit::Acceleration::MicrometrePerSquareSecond  },
    {"μm/s2",             Unit::Acceleration::MicrometrePerSquareSecond  },
    {"μm/s/s",            Unit::Acceleration::MicrometrePerSquareSecond  },
    {"um/s^2",            Unit::Acceleration::MicrometrePerSquareSecond  },
    {"um/s2",             Unit::Acceleration::MicrometrePerSquareSecond  },
    {"um/s/s",            Unit::Acceleration::MicrometrePerSquareSecond  },
    {"μm/min^2",          Unit::Acceleration::MicrometrePerSquareMinute  },
    {"μm/min2",           Unit::Acceleration::MicrometrePerSquareMinute  },
    {"μm/min/min",        Unit::Acceleration::MicrometrePerSquareMinute  },
    {"um/min^2",          Unit::Acceleration::MicrometrePerSquareMinute  },
    {"um/min2",           Unit::Acceleration::MicrometrePerSquareMinute  },
    {"um/min/min",        Unit::Acceleration::MicrometrePerSquareMinute  },
    {"μm/hr^2",           Unit::Acceleration::MicrometrePerSquareHour    },
    {"μm/hr2",            Unit::Acceleration::MicrometrePerSquareHour    },
    {"μm/hr/hr",          Unit::Acceleration::MicrometrePerSquareHour    },
    {"um/hr^2",           Unit::Acceleration::MicrometrePerSquareHour    },
    {"um/hr2",            Unit::Acceleration::MicrometrePerSquareHour    },
    {"um/hr/hr",          Unit::Acceleration::MicrometrePerSquareHour    },
    {"μin/s^2",           Unit::Acceleration::MicroinchPerSquareSecond   },
    {"μin/s2",            Unit::Acceleration::MicroinchPerSquareSecond   },
    {"μin/s/s",           Unit::Acceleration::MicroinchPerSquareSecond   },
    {"uin/s^2",           Unit::Acceleration::MicroinchPerSquareSecond   },
    {"uin/s2",            Unit::Acceleration::MicroinchPerSquareSecond   },
    {"uin/s/s",           Unit::Acceleration::MicroinchPerSquareSecond   },
    {"μin/min^2",         Unit::Acceleration::MicroinchPerSquareMinute   },
    {"μin/min2",          Unit::Acceleration::MicroinchPerSquareMinute   },
    {"μin/min/min",       Unit::Acceleration::MicroinchPerSquareMinute   },
    {"uin/min^2",         Unit::Acceleration::MicroinchPerSquareMinute   },
    {"uin/min2",          Unit::Acceleration::MicroinchPerSquareMinute   },
    {"uin/min/min",       Unit::Acceleration::MicroinchPerSquareMinute   },
    {"μin/hr^2",          Unit::Acceleration::MicroinchPerSquareHour     },
    {"μin/hr2",           Unit::Acceleration::MicroinchPerSquareHour     },
    {"μin/hr/hr",         Unit::Acceleration::MicroinchPerSquareHour     },
    {"uin/hr^2",          Unit::Acceleration::MicroinchPerSquareHour     },
    {"uin/hr2",           Unit::Acceleration::MicroinchPerSquareHour     },
    {"uin/hr/hr",         Unit::Acceleration::MicroinchPerSquareHour     },
};

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::NauticalMilePerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Acceleration, Unit::Acceleration::KnotPerHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(12960000.0L) / static_cast<NumericType>(1852.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Acceleration, Unit::Acceleration::KnotPerHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1852.0L) / static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(12960000.0L) / static_cast<NumericType>(1609.344L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilePerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1609.344L) / static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3.6L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(12960.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::KilometrePerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L) / static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareSecond>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareSecond>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MetrePerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(12960000.0L) / static_cast<NumericType>(0.9144L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::YardPerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.9144L) / static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(12960000.0L) / static_cast<NumericType>(0.3048L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::FootPerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) / static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(10.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.1L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(36000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.1L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(129600000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::DecimetrePerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.1L) / static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(12960000.0L) / static_cast<NumericType>(0.0254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::InchPerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) / static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(100.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.01L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(360000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.01L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1296000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::CentimetrePerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.01L) / static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(12960000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MillimetrePerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L) / static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(12960000.0L) / static_cast<NumericType>(0.0000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MilliinchPerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000254L) / static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(12960000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicrometrePerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L) / static_cast<NumericType>(12960000.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareSecond>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareSecond>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareMinute>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L) / static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L) / static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareHour>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(12960000.0L) / static_cast<NumericType>(0.0000000254L);
}

template <>
template <typename NumericType>
inline constexpr void
Conversion<Unit::Acceleration, Unit::Acceleration::MicroinchPerSquareHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0000000254L) / static_cast<NumericType>(12960000.0L);
}

template <typename NumericType>
inline const std::map<Unit::Acceleration,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Acceleration, NumericType>{
        {Unit::Acceleration::NauticalMilePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::NauticalMilePerSquareSecond>::FromStandard<NumericType>},
        {Unit::Acceleration::NauticalMilePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::NauticalMilePerSquareMinute>::FromStandard<NumericType>},
        {Unit::Acceleration::KnotPerHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KnotPerHour>::FromStandard<NumericType>                },
        {Unit::Acceleration::MilePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareSecond>::FromStandard<NumericType>        },
        {Unit::Acceleration::MilePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareMinute>::FromStandard<NumericType>        },
        {Unit::Acceleration::MilePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareHour>::FromStandard<NumericType>          },
        {Unit::Acceleration::KilometrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareSecond>::FromStandard<NumericType>   },
        {Unit::Acceleration::KilometrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareMinute>::FromStandard<NumericType>   },
        {Unit::Acceleration::KilometrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareHour>::FromStandard<NumericType>     },
        {Unit::Acceleration::MetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareSecond>::FromStandard<NumericType>       },
        {Unit::Acceleration::MetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareMinute>::FromStandard<NumericType>       },
        {Unit::Acceleration::MetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareHour>::FromStandard<NumericType>         },
        {Unit::Acceleration::YardPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareSecond>::FromStandard<NumericType>        },
        {Unit::Acceleration::YardPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareMinute>::FromStandard<NumericType>        },
        {Unit::Acceleration::YardPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareHour>::FromStandard<NumericType>          },
        {Unit::Acceleration::FootPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareSecond>::FromStandard<NumericType>        },
        {Unit::Acceleration::FootPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareMinute>::FromStandard<NumericType>        },
        {Unit::Acceleration::FootPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareHour>::FromStandard<NumericType>          },
        {Unit::Acceleration::DecimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareSecond>::FromStandard<NumericType>   },
        {Unit::Acceleration::DecimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareMinute>::FromStandard<NumericType>   },
        {Unit::Acceleration::DecimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareHour>::FromStandard<NumericType>     },
        {Unit::Acceleration::InchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareSecond>::FromStandard<NumericType>        },
        {Unit::Acceleration::InchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareMinute>::FromStandard<NumericType>        },
        {Unit::Acceleration::InchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareHour>::FromStandard<NumericType>          },
        {Unit::Acceleration::CentimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareSecond>::FromStandard<NumericType>  },
        {Unit::Acceleration::CentimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareMinute>::FromStandard<NumericType>  },
        {Unit::Acceleration::CentimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareHour>::FromStandard<NumericType>    },
        {Unit::Acceleration::MillimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareSecond>::FromStandard<NumericType>  },
        {Unit::Acceleration::MillimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareMinute>::FromStandard<NumericType>  },
        {Unit::Acceleration::MillimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareHour>::FromStandard<NumericType>    },
        {Unit::Acceleration::MilliinchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareSecond>::FromStandard<NumericType>   },
        {Unit::Acceleration::MilliinchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareMinute>::FromStandard<NumericType>   },
        {Unit::Acceleration::MilliinchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareHour>::FromStandard<NumericType>     },
        {Unit::Acceleration::MicrometrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareSecond>::FromStandard<NumericType>  },
        {Unit::Acceleration::MicrometrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareMinute>::FromStandard<NumericType>  },
        {Unit::Acceleration::MicrometrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareHour>::FromStandard<NumericType>    },
        {Unit::Acceleration::MicroinchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareSecond>::FromStandard<NumericType>   },
        {Unit::Acceleration::MicroinchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareMinute>::FromStandard<NumericType>   },
        {Unit::Acceleration::MicroinchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareHour>::FromStandard<NumericType>     },
};

template <typename NumericType>
inline const std::map<Unit::Acceleration,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Acceleration, NumericType>{
        {Unit::Acceleration::NauticalMilePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::NauticalMilePerSquareSecond>::ToStandard<NumericType>                },
        {Unit::Acceleration::NauticalMilePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::NauticalMilePerSquareMinute>::ToStandard<NumericType>                },
        {Unit::Acceleration::KnotPerHour,
         Conversions<Unit::Acceleration, Unit::Acceleration::KnotPerHour>::ToStandard<NumericType>},
        {Unit::Acceleration::MilePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareSecond>::ToStandard<NumericType>                        },
        {Unit::Acceleration::MilePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareMinute>::ToStandard<NumericType>                        },
        {Unit::Acceleration::MilePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilePerSquareHour>::ToStandard<NumericType>                          },
        {Unit::Acceleration::KilometrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareSecond>::ToStandard<NumericType>                   },
        {Unit::Acceleration::KilometrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareMinute>::ToStandard<NumericType>                   },
        {Unit::Acceleration::KilometrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::KilometrePerSquareHour>::ToStandard<NumericType>                     },
        {Unit::Acceleration::MetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareSecond>::ToStandard<NumericType>                       },
        {Unit::Acceleration::MetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareMinute>::ToStandard<NumericType>                       },
        {Unit::Acceleration::MetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MetrePerSquareHour>::ToStandard<NumericType>                         },
        {Unit::Acceleration::YardPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareSecond>::ToStandard<NumericType>                        },
        {Unit::Acceleration::YardPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareMinute>::ToStandard<NumericType>                        },
        {Unit::Acceleration::YardPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::YardPerSquareHour>::ToStandard<NumericType>                          },
        {Unit::Acceleration::FootPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareSecond>::ToStandard<NumericType>                        },
        {Unit::Acceleration::FootPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareMinute>::ToStandard<NumericType>                        },
        {Unit::Acceleration::FootPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::FootPerSquareHour>::ToStandard<NumericType>                          },
        {Unit::Acceleration::DecimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareSecond>::ToStandard<NumericType>                   },
        {Unit::Acceleration::DecimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareMinute>::ToStandard<NumericType>                   },
        {Unit::Acceleration::DecimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::DecimetrePerSquareHour>::ToStandard<NumericType>                     },
        {Unit::Acceleration::InchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareSecond>::ToStandard<NumericType>                        },
        {Unit::Acceleration::InchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareMinute>::ToStandard<NumericType>                        },
        {Unit::Acceleration::InchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::InchPerSquareHour>::ToStandard<NumericType>                          },
        {Unit::Acceleration::CentimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareSecond>::ToStandard<NumericType>                  },
        {Unit::Acceleration::CentimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareMinute>::ToStandard<NumericType>                  },
        {Unit::Acceleration::CentimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::CentimetrePerSquareHour>::ToStandard<NumericType>                    },
        {Unit::Acceleration::MillimetrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareSecond>::ToStandard<NumericType>                  },
        {Unit::Acceleration::MillimetrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareMinute>::ToStandard<NumericType>                  },
        {Unit::Acceleration::MillimetrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MillimetrePerSquareHour>::ToStandard<NumericType>                    },
        {Unit::Acceleration::MilliinchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareSecond>::ToStandard<NumericType>                   },
        {Unit::Acceleration::MilliinchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareMinute>::ToStandard<NumericType>                   },
        {Unit::Acceleration::MilliinchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MilliinchPerSquareHour>::ToStandard<NumericType>                     },
        {Unit::Acceleration::MicrometrePerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareSecond>::ToStandard<NumericType>                  },
        {Unit::Acceleration::MicrometrePerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareMinute>::ToStandard<NumericType>                  },
        {Unit::Acceleration::MicrometrePerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicrometrePerSquareHour>::ToStandard<NumericType>                    },
        {Unit::Acceleration::MicroinchPerSquareSecond,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareSecond>::ToStandard<NumericType>                   },
        {Unit::Acceleration::MicroinchPerSquareMinute,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareMinute>::ToStandard<NumericType>                   },
        {Unit::Acceleration::MicroinchPerSquareHour,
         Conversions<Unit::Acceleration,
         Unit::Acceleration::MicroinchPerSquareHour>::ToStandard<NumericType>                     },
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ACCELERATION_HPP
