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

#ifndef PHQ_UNIT_ENERGY_HPP
#define PHQ_UNIT_ENERGY_HPP

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

// Energy units.
enum class Energy : int8_t {
  // Joule (J) energy unit.
  Joule,

  // Millijoule (mJ) energy unit.
  Millijoule,

  // Microjoule (μJ) energy unit.
  Microjoule,

  // Nanojoule (nJ) energy unit.
  Nanojoule,

  // Kilojoule (kJ) energy unit.
  Kilojoule,

  // Megajoule (MJ) energy unit.
  Megajoule,

  // Gigajoule (GJ) energy unit.
  Gigajoule,

  // Watt-minute (W·min) energy unit.
  WattMinute,

  // Watt-hour (W·hr) energy unit.
  WattHour,

  // Kilowatt-minute (kW·min) energy unit.
  KilowattMinute,

  // Kilowatt-hour (kW·hr) energy unit.
  KilowattHour,

  // Megawatt-minute (MW·min) energy unit.
  MegawattMinute,

  // Megawatt-hour (MW·hr) energy unit.
  MegawattHour,

  // Gigawatt-minute (GW·min) energy unit.
  GigawattMinute,

  // Gigawatt-hour (GW·hr) energy unit.
  GigawattHour,

  // Foot-pound (ft·lbf) energy unit.
  FootPound,

  // Inch-pound (in·lbf) energy unit.
  InchPound,

  // Calorie (cal) energy unit.
  Calorie,

  // Millicalorie (mcal) energy unit.
  Millicalorie,

  // Microcalorie (μcal) energy unit.
  Microcalorie,

  // Nanocalorie (ncal) energy unit.
  Nanocalorie,

  // Kilocalorie (kcal) energy unit.
  Kilocalorie,

  // Megacalorie (Mcal) energy unit.
  Megacalorie,

  // Gigacalorie (Gcal) energy unit.
  Gigacalorie,

  // Electronvolt (eV) energy unit.
  Electronvolt,

  // Millielectronvolt (meV) energy unit.
  Millielectronvolt,

  // Microelectronvolt (μeV) energy unit.
  Microelectronvolt,

  // Nanoelectronvolt (neV) energy unit.
  Nanoelectronvolt,

  // Kiloelectronvolt (keV) energy unit.
  Kiloelectronvolt,

  // Megaelectronvolt (MeV) energy unit.
  Megaelectronvolt,

  // Gigaelectronvolt (GeV) energy unit.
  Gigaelectronvolt,

  // British thermal unit (BTU) energy unit.
  BritishThermalUnit,
};

}  // namespace Unit

// Standard energy unit: joule (J).
template <>
inline constexpr const Unit::Energy Standard<Unit::Energy>{Unit::Energy::Joule};

// Physical dimension set of energy units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Energy>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1}}
};

inline std::ostream& operator<<(std::ostream& stream, const Unit::Energy unit) {
  stream << Abbreviation(unit);
  return stream;
}

namespace Internal {

template <>
inline const std::map<UnitSystem, Unit::Energy> ConsistentUnits<Unit::Energy>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Energy::Joule    },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Energy::Nanojoule},
    {UnitSystem::FootPoundSecondRankine,     Unit::Energy::FootPound},
    {UnitSystem::InchPoundSecondRankine,     Unit::Energy::InchPound},
};

template <>
inline const std::map<Unit::Energy, UnitSystem> RelatedUnitSystems<Unit::Energy>{
    {Unit::Energy::Joule,     UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Energy::Nanojoule, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Energy::FootPound, UnitSystem::FootPoundSecondRankine    },
    {Unit::Energy::InchPound, UnitSystem::InchPoundSecondRankine    },
};

template <>
inline const std::map<Unit::Energy, std::string_view> Abbreviations<Unit::Energy>{
    {Unit::Energy::Joule,              "J"     },
    {Unit::Energy::Millijoule,         "mJ"    },
    {Unit::Energy::Microjoule,         "μJ"    },
    {Unit::Energy::Nanojoule,          "nJ"    },
    {Unit::Energy::Kilojoule,          "kJ"    },
    {Unit::Energy::Megajoule,          "MJ"    },
    {Unit::Energy::Gigajoule,          "GJ"    },
    {Unit::Energy::WattMinute,         "W·min" },
    {Unit::Energy::WattHour,           "W·hr"  },
    {Unit::Energy::KilowattMinute,     "kW·min"},
    {Unit::Energy::KilowattHour,       "kW·hr" },
    {Unit::Energy::MegawattMinute,     "MW·min"},
    {Unit::Energy::MegawattHour,       "MW·hr" },
    {Unit::Energy::GigawattMinute,     "GW·min"},
    {Unit::Energy::GigawattHour,       "GW·hr" },
    {Unit::Energy::FootPound,          "ft·lbf"},
    {Unit::Energy::InchPound,          "in·lbf"},
    {Unit::Energy::Calorie,            "cal"   },
    {Unit::Energy::Millicalorie,       "mcal"  },
    {Unit::Energy::Microcalorie,       "μcal"  },
    {Unit::Energy::Nanocalorie,        "ncal"  },
    {Unit::Energy::Kilocalorie,        "kcal"  },
    {Unit::Energy::Megacalorie,        "Mcal"  },
    {Unit::Energy::Gigacalorie,        "Gcal"  },
    {Unit::Energy::Electronvolt,       "eV"    },
    {Unit::Energy::Millielectronvolt,  "meV"   },
    {Unit::Energy::Microelectronvolt,  "μeV"   },
    {Unit::Energy::Nanoelectronvolt,   "neV"   },
    {Unit::Energy::Kiloelectronvolt,   "keV"   },
    {Unit::Energy::Megaelectronvolt,   "MeV"   },
    {Unit::Energy::Gigaelectronvolt,   "GeV"   },
    {Unit::Energy::BritishThermalUnit, "BTU"   },
};

template <>
inline const std::unordered_map<std::string_view, Unit::Energy> Spellings<Unit::Energy>{
    {"J",          Unit::Energy::Joule             },
    {"N·m",        Unit::Energy::Joule             },
    {"N*m",        Unit::Energy::Joule             },
    {"kg·m^2/s^2", Unit::Energy::Joule             },
    {"kg*m^2/s^2", Unit::Energy::Joule             },
    {"kg·m2/s2",   Unit::Energy::Joule             },
    {"kg*m2/s2",   Unit::Energy::Joule             },
    {"W·s",        Unit::Energy::Joule             },
    {"W*s",        Unit::Energy::Joule             },
    {"mJ",         Unit::Energy::Millijoule        },
    {"μJ",         Unit::Energy::Microjoule        },
    {"uJ",         Unit::Energy::Microjoule        },
    {"nJ",         Unit::Energy::Nanojoule         },
    {"μN·mm",      Unit::Energy::Nanojoule         },
    {"μN*mm",      Unit::Energy::Nanojoule         },
    {"uN·mm",      Unit::Energy::Nanojoule         },
    {"uN*mm",      Unit::Energy::Nanojoule         },
    {"g·mm^2/s^2", Unit::Energy::Nanojoule         },
    {"g*mm^2/s^2", Unit::Energy::Nanojoule         },
    {"g·mm2/s2",   Unit::Energy::Nanojoule         },
    {"g*mm2/s2",   Unit::Energy::Nanojoule         },
    {"kJ",         Unit::Energy::Kilojoule         },
    {"MJ",         Unit::Energy::Megajoule         },
    {"GJ",         Unit::Energy::Gigajoule         },
    {"W·min",      Unit::Energy::WattMinute        },
    {"W*min",      Unit::Energy::WattMinute        },
    {"W·hr",       Unit::Energy::WattHour          },
    {"W*hr",       Unit::Energy::WattHour          },
    {"kW·min",     Unit::Energy::KilowattMinute    },
    {"kW*min",     Unit::Energy::KilowattMinute    },
    {"kW·hr",      Unit::Energy::KilowattHour      },
    {"kW*hr",      Unit::Energy::KilowattHour      },
    {"MW·min",     Unit::Energy::MegawattMinute    },
    {"MW*min",     Unit::Energy::MegawattMinute    },
    {"MW·hr",      Unit::Energy::MegawattHour      },
    {"MW*hr",      Unit::Energy::MegawattHour      },
    {"GW·min",     Unit::Energy::GigawattMinute    },
    {"GW*min",     Unit::Energy::GigawattMinute    },
    {"GW·hr",      Unit::Energy::GigawattHour      },
    {"GW*hr",      Unit::Energy::GigawattHour      },
    {"ft·lbf",     Unit::Energy::FootPound         },
    {"ft*lbf",     Unit::Energy::FootPound         },
    {"ft·lb",      Unit::Energy::FootPound         },
    {"ft*lb",      Unit::Energy::FootPound         },
    {"in·lbf",     Unit::Energy::InchPound         },
    {"in*lbf",     Unit::Energy::InchPound         },
    {"in·lb",      Unit::Energy::InchPound         },
    {"in*lb",      Unit::Energy::InchPound         },
    {"cal",        Unit::Energy::Calorie           },
    {"mcal",       Unit::Energy::Millicalorie      },
    {"μcal",       Unit::Energy::Microcalorie      },
    {"ucal",       Unit::Energy::Microcalorie      },
    {"ncal",       Unit::Energy::Nanocalorie       },
    {"kcal",       Unit::Energy::Kilocalorie       },
    {"Cal",        Unit::Energy::Kilocalorie       },
    {"Mcal",       Unit::Energy::Megacalorie       },
    {"Gcal",       Unit::Energy::Gigacalorie       },
    {"eV",         Unit::Energy::Electronvolt      },
    {"meV",        Unit::Energy::Millielectronvolt },
    {"μeV",        Unit::Energy::Microelectronvolt },
    {"ueV",        Unit::Energy::Microelectronvolt },
    {"neV",        Unit::Energy::Nanoelectronvolt  },
    {"keV",        Unit::Energy::Kiloelectronvolt  },
    {"MeV",        Unit::Energy::Megaelectronvolt  },
    {"GeV",        Unit::Energy::Gigaelectronvolt  },
    {"BTU",        Unit::Energy::BritishThermalUnit},
    {"btu",        Unit::Energy::BritishThermalUnit},
};

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Joule>::FromStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Joule>::ToStandard(
    Number& /*value*/) noexcept {}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millijoule>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millijoule>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microjoule>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microjoule>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanojoule>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanojoule>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kilojoule>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kilojoule>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megajoule>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megajoule>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigajoule>::FromStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000000001L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigajoule>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::WattMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::WattMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::WattHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::WattHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::KilowattMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::KilowattMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::KilowattHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::KilowattHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::MegawattMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::MegawattMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::MegawattHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::MegawattHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::GigawattMinute>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(60000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::GigawattMinute>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(60000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::GigawattHour>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(3600000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::GigawattHour>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(3600000000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::FootPound>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(0.3048L) * static_cast<Number>(0.45359237L)
            * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::FootPound>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.3048L) * static_cast<Number>(0.45359237L)
           * static_cast<Number>(9.80665L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::InchPound>::FromStandard(
    Number& value) noexcept {
  value /= (static_cast<Number>(0.0254L) * static_cast<Number>(0.45359237L)
            * static_cast<Number>(9.80665L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::InchPound>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.0254L) * static_cast<Number>(0.45359237L)
           * static_cast<Number>(9.80665L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Calorie>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(4.184L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Calorie>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(4.184L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millicalorie>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.004184L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millicalorie>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.004184L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microcalorie>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.000004184L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microcalorie>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000004184L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanocalorie>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(0.000000004184L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanocalorie>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(0.000000004184L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kilocalorie>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(4184.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kilocalorie>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(4184.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megacalorie>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(4184000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megacalorie>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(4184000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigacalorie>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(4184000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigacalorie>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(4184000000.0L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Electronvolt>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.602176634e-19L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Electronvolt>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.602176634e-19L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millielectronvolt>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.602176634e-22L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millielectronvolt>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.602176634e-22L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microelectronvolt>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.602176634e-25L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microelectronvolt>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.602176634e-25L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanoelectronvolt>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.602176634e-28L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanoelectronvolt>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.602176634e-28L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kiloelectronvolt>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.602176634e-16L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kiloelectronvolt>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.602176634e-16L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megaelectronvolt>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.602176634e-13L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megaelectronvolt>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.602176634e-13L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigaelectronvolt>::FromStandard(
    Number& value) noexcept {
  value /= static_cast<Number>(1.602176634e-10L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigaelectronvolt>::ToStandard(
    Number& value) noexcept {
  value *= static_cast<Number>(1.602176634e-10L);
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::BritishThermalUnit>::FromStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(1.8L) / (static_cast<Number>(4.1868L) * static_cast<Number>(453.59237L));
}

template <>
template <typename Number>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::BritishThermalUnit>::ToStandard(
    Number& value) noexcept {
  value *=
      static_cast<Number>(4.1868L) * static_cast<Number>(453.59237L) / static_cast<Number>(1.8L);
}

template <typename Number>
inline const std::map<Unit::Energy, std::function<void(Number* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Energy, Number>{
        {Unit::Energy::Joule,              Conversions<Unit::Energy, Unit::Energy::Joule>::FromStandard<Number>             },
        {Unit::Energy::Millijoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Millijoule>::FromStandard<Number>        },
        {Unit::Energy::Microjoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Microjoule>::FromStandard<Number>        },
        {Unit::Energy::Nanojoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Nanojoule>::FromStandard<Number>         },
        {Unit::Energy::Kilojoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Kilojoule>::FromStandard<Number>         },
        {Unit::Energy::Megajoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Megajoule>::FromStandard<Number>         },
        {Unit::Energy::Gigajoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Gigajoule>::FromStandard<Number>         },
        {Unit::Energy::WattMinute,
         Conversions<Unit::Energy,                                   Unit::Energy::WattMinute>::FromStandard<Number>        },
        {Unit::Energy::WattHour,
         Conversions<Unit::Energy,                                   Unit::Energy::WattHour>::FromStandard<Number>          },
        {Unit::Energy::KilowattMinute,
         Conversions<Unit::Energy,                                   Unit::Energy::KilowattMinute>::FromStandard<Number>    },
        {Unit::Energy::KilowattHour,
         Conversions<Unit::Energy,                                   Unit::Energy::KilowattHour>::FromStandard<Number>      },
        {Unit::Energy::MegawattMinute,
         Conversions<Unit::Energy,                                   Unit::Energy::MegawattMinute>::FromStandard<Number>    },
        {Unit::Energy::MegawattHour,
         Conversions<Unit::Energy,                                   Unit::Energy::MegawattHour>::FromStandard<Number>      },
        {Unit::Energy::GigawattMinute,
         Conversions<Unit::Energy,                                   Unit::Energy::GigawattMinute>::FromStandard<Number>    },
        {Unit::Energy::GigawattHour,
         Conversions<Unit::Energy,                                   Unit::Energy::GigawattHour>::FromStandard<Number>      },
        {Unit::Energy::FootPound,
         Conversions<Unit::Energy,                                   Unit::Energy::FootPound>::FromStandard<Number>         },
        {Unit::Energy::InchPound,
         Conversions<Unit::Energy,                                   Unit::Energy::InchPound>::FromStandard<Number>         },
        {Unit::Energy::Calorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Calorie>::FromStandard<Number>           },
        {Unit::Energy::Millicalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Millicalorie>::FromStandard<Number>      },
        {Unit::Energy::Microcalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Microcalorie>::FromStandard<Number>      },
        {Unit::Energy::Nanocalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Nanocalorie>::FromStandard<Number>       },
        {Unit::Energy::Kilocalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Kilocalorie>::FromStandard<Number>       },
        {Unit::Energy::Megacalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Megacalorie>::FromStandard<Number>       },
        {Unit::Energy::Gigacalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Gigacalorie>::FromStandard<Number>       },
        {Unit::Energy::Electronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Electronvolt>::FromStandard<Number>      },
        {Unit::Energy::Millielectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Millielectronvolt>::FromStandard<Number> },
        {Unit::Energy::Microelectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Microelectronvolt>::FromStandard<Number> },
        {Unit::Energy::Nanoelectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Nanoelectronvolt>::FromStandard<Number>  },
        {Unit::Energy::Kiloelectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Kiloelectronvolt>::FromStandard<Number>  },
        {Unit::Energy::Megaelectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Megaelectronvolt>::FromStandard<Number>  },
        {Unit::Energy::Gigaelectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Gigaelectronvolt>::FromStandard<Number>  },
        {Unit::Energy::BritishThermalUnit,
         Conversions<Unit::Energy,                                   Unit::Energy::BritishThermalUnit>::FromStandard<Number>},
};

template <typename Number>
inline const std::map<Unit::Energy,
                      std::function<void(Number* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Energy, Number>{
        {Unit::Energy::Joule,              Conversions<Unit::Energy, Unit::Energy::Joule>::ToStandard<Number>             },
        {Unit::Energy::Millijoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Millijoule>::ToStandard<Number>        },
        {Unit::Energy::Microjoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Microjoule>::ToStandard<Number>        },
        {Unit::Energy::Nanojoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Nanojoule>::ToStandard<Number>         },
        {Unit::Energy::Kilojoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Kilojoule>::ToStandard<Number>         },
        {Unit::Energy::Megajoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Megajoule>::ToStandard<Number>         },
        {Unit::Energy::Gigajoule,
         Conversions<Unit::Energy,                                   Unit::Energy::Gigajoule>::ToStandard<Number>         },
        {Unit::Energy::WattMinute,
         Conversions<Unit::Energy,                                   Unit::Energy::WattMinute>::ToStandard<Number>        },
        {Unit::Energy::WattHour,
         Conversions<Unit::Energy,                                   Unit::Energy::WattHour>::ToStandard<Number>          },
        {Unit::Energy::KilowattMinute,
         Conversions<Unit::Energy,                                   Unit::Energy::KilowattMinute>::ToStandard<Number>    },
        {Unit::Energy::KilowattHour,
         Conversions<Unit::Energy,                                   Unit::Energy::KilowattHour>::ToStandard<Number>      },
        {Unit::Energy::MegawattMinute,
         Conversions<Unit::Energy,                                   Unit::Energy::MegawattMinute>::ToStandard<Number>    },
        {Unit::Energy::MegawattHour,
         Conversions<Unit::Energy,                                   Unit::Energy::MegawattHour>::ToStandard<Number>      },
        {Unit::Energy::GigawattMinute,
         Conversions<Unit::Energy,                                   Unit::Energy::GigawattMinute>::ToStandard<Number>    },
        {Unit::Energy::GigawattHour,
         Conversions<Unit::Energy,                                   Unit::Energy::GigawattHour>::ToStandard<Number>      },
        {Unit::Energy::FootPound,
         Conversions<Unit::Energy,                                   Unit::Energy::FootPound>::ToStandard<Number>         },
        {Unit::Energy::InchPound,
         Conversions<Unit::Energy,                                   Unit::Energy::InchPound>::ToStandard<Number>         },
        {Unit::Energy::Calorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Calorie>::ToStandard<Number>           },
        {Unit::Energy::Millicalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Millicalorie>::ToStandard<Number>      },
        {Unit::Energy::Microcalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Microcalorie>::ToStandard<Number>      },
        {Unit::Energy::Nanocalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Nanocalorie>::ToStandard<Number>       },
        {Unit::Energy::Kilocalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Kilocalorie>::ToStandard<Number>       },
        {Unit::Energy::Megacalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Megacalorie>::ToStandard<Number>       },
        {Unit::Energy::Gigacalorie,
         Conversions<Unit::Energy,                                   Unit::Energy::Gigacalorie>::ToStandard<Number>       },
        {Unit::Energy::Electronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Electronvolt>::ToStandard<Number>      },
        {Unit::Energy::Millielectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Millielectronvolt>::ToStandard<Number> },
        {Unit::Energy::Microelectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Microelectronvolt>::ToStandard<Number> },
        {Unit::Energy::Nanoelectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Nanoelectronvolt>::ToStandard<Number>  },
        {Unit::Energy::Kiloelectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Kiloelectronvolt>::ToStandard<Number>  },
        {Unit::Energy::Megaelectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Megaelectronvolt>::ToStandard<Number>  },
        {Unit::Energy::Gigaelectronvolt,
         Conversions<Unit::Energy,                                   Unit::Energy::Gigaelectronvolt>::ToStandard<Number>  },
        {Unit::Energy::BritishThermalUnit,
         Conversions<Unit::Energy,                                   Unit::Energy::BritishThermalUnit>::ToStandard<Number>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ENERGY_HPP
