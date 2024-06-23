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

/// \brief Energy units.
enum class Energy : int8_t {
  /// \brief Joule (J) energy unit.
  Joule,

  /// \brief Millijoule (mJ) energy unit.
  Millijoule,

  /// \brief Microjoule (μJ) energy unit.
  Microjoule,

  /// \brief Nanojoule (nJ) energy unit.
  Nanojoule,

  /// \brief Kilojoule (kJ) energy unit.
  Kilojoule,

  /// \brief Megajoule (MJ) energy unit.
  Megajoule,

  /// \brief Gigajoule (GJ) energy unit.
  Gigajoule,

  /// \brief Watt-minute (W·min) energy unit.
  WattMinute,

  /// \brief Watt-hour (W·hr) energy unit.
  WattHour,

  /// \brief Kilowatt-minute (kW·min) energy unit.
  KilowattMinute,

  /// \brief Kilowatt-hour (kW·hr) energy unit.
  KilowattHour,

  /// \brief Megawatt-minute (MW·min) energy unit.
  MegawattMinute,

  /// \brief Megawatt-hour (MW·hr) energy unit.
  MegawattHour,

  /// \brief Gigawatt-minute (GW·min) energy unit.
  GigawattMinute,

  /// \brief Gigawatt-hour (GW·hr) energy unit.
  GigawattHour,

  /// \brief Foot-pound (ft·lbf) energy unit.
  FootPound,

  /// \brief Inch-pound (in·lbf) energy unit.
  InchPound,

  /// \brief Calorie (cal) energy unit.
  Calorie,

  /// \brief Millicalorie (mcal) energy unit.
  Millicalorie,

  /// \brief Microcalorie (μcal) energy unit.
  Microcalorie,

  /// \brief Nanocalorie (ncal) energy unit.
  Nanocalorie,

  /// \brief Kilocalorie (kcal) energy unit.
  Kilocalorie,

  /// \brief Megacalorie (Mcal) energy unit.
  Megacalorie,

  /// \brief Gigacalorie (Gcal) energy unit.
  Gigacalorie,

  /// \brief Electronvolt (eV) energy unit.
  Electronvolt,

  /// \brief Millielectronvolt (meV) energy unit.
  Millielectronvolt,

  /// \brief Microelectronvolt (μeV) energy unit.
  Microelectronvolt,

  /// \brief Nanoelectronvolt (neV) energy unit.
  Nanoelectronvolt,

  /// \brief Kiloelectronvolt (keV) energy unit.
  Kiloelectronvolt,

  /// \brief Megaelectronvolt (MeV) energy unit.
  Megaelectronvolt,

  /// \brief Gigaelectronvolt (GeV) energy unit.
  Gigaelectronvolt,

  /// \brief British thermal unit (BTU) energy unit.
  BritishThermalUnit,
};

}  // namespace Unit

/// \brief Standard energy unit: joule (J).
template <>
inline constexpr const Unit::Energy Standard<Unit::Energy>{Unit::Energy::Joule};

/// \brief Physical dimension set of energy units.
template <>
inline constexpr const Dimensions RelatedDimensions<Unit::Energy>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1},
               Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
               Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}}
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

// clang-format off

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

// clang-format on

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Joule>::FromStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Joule>::ToStandard(
    NumericType& /*value*/) noexcept {}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millijoule>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millijoule>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microjoule>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microjoule>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanojoule>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanojoule>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kilojoule>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kilojoule>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megajoule>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megajoule>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigajoule>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000000001L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigajoule>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::WattMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::WattMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::WattHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::WattHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::KilowattMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::KilowattMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::KilowattHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::KilowattHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::MegawattMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::MegawattMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::MegawattHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::MegawattHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::GigawattMinute>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(60000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::GigawattMinute>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(60000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::GigawattHour>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(3600000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::GigawattHour>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(3600000000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::FootPound>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.45359237L)
            * static_cast<NumericType>(9.80665L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::FootPound>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.3048L) * static_cast<NumericType>(0.45359237L)
           * static_cast<NumericType>(9.80665L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::InchPound>::FromStandard(
    NumericType& value) noexcept {
  value /= (static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.45359237L)
            * static_cast<NumericType>(9.80665L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::InchPound>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.0254L) * static_cast<NumericType>(0.45359237L)
           * static_cast<NumericType>(9.80665L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Calorie>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(4.184L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Calorie>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(4.184L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millicalorie>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.004184L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millicalorie>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.004184L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microcalorie>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.000004184L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microcalorie>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000004184L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanocalorie>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(0.000000004184L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanocalorie>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(0.000000004184L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kilocalorie>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(4184.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kilocalorie>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(4184.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megacalorie>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(4184000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megacalorie>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(4184000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigacalorie>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(4184000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigacalorie>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(4184000000.0L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Electronvolt>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.602176634e-19L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Electronvolt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.602176634e-19L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millielectronvolt>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.602176634e-22L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Millielectronvolt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.602176634e-22L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microelectronvolt>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.602176634e-25L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Microelectronvolt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.602176634e-25L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanoelectronvolt>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.602176634e-28L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Nanoelectronvolt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.602176634e-28L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kiloelectronvolt>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.602176634e-16L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Kiloelectronvolt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.602176634e-16L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megaelectronvolt>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.602176634e-13L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Megaelectronvolt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.602176634e-13L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigaelectronvolt>::FromStandard(
    NumericType& value) noexcept {
  value /= static_cast<NumericType>(1.602176634e-10L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::Gigaelectronvolt>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.602176634e-10L);
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::BritishThermalUnit>::FromStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(1.8L)
           / (static_cast<NumericType>(4.1868L) * static_cast<NumericType>(453.59237L));
}

template <>
template <typename NumericType>
inline constexpr void Conversion<Unit::Energy, Unit::Energy::BritishThermalUnit>::ToStandard(
    NumericType& value) noexcept {
  value *= static_cast<NumericType>(4.1868L) * static_cast<NumericType>(453.59237L)
           / static_cast<NumericType>(1.8L);
}

template <typename NumericType>
inline const std::map<Unit::Energy,
                      std::function<void(NumericType* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Energy, NumericType>{
        {Unit::Energy::Joule,
         Conversions<Unit::Energy, Unit::Energy::Joule>::FromStandard<NumericType>             },
        {Unit::Energy::Millijoule,
         Conversions<Unit::Energy, Unit::Energy::Millijoule>::FromStandard<NumericType>        },
        {Unit::Energy::Microjoule,
         Conversions<Unit::Energy, Unit::Energy::Microjoule>::FromStandard<NumericType>        },
        {Unit::Energy::Nanojoule,
         Conversions<Unit::Energy, Unit::Energy::Nanojoule>::FromStandard<NumericType>         },
        {Unit::Energy::Kilojoule,
         Conversions<Unit::Energy, Unit::Energy::Kilojoule>::FromStandard<NumericType>         },
        {Unit::Energy::Megajoule,
         Conversions<Unit::Energy, Unit::Energy::Megajoule>::FromStandard<NumericType>         },
        {Unit::Energy::Gigajoule,
         Conversions<Unit::Energy, Unit::Energy::Gigajoule>::FromStandard<NumericType>         },
        {Unit::Energy::WattMinute,
         Conversions<Unit::Energy, Unit::Energy::WattMinute>::FromStandard<NumericType>        },
        {Unit::Energy::WattHour,
         Conversions<Unit::Energy, Unit::Energy::WattHour>::FromStandard<NumericType>          },
        {Unit::Energy::KilowattMinute,
         Conversions<Unit::Energy, Unit::Energy::KilowattMinute>::FromStandard<NumericType>    },
        {Unit::Energy::KilowattHour,
         Conversions<Unit::Energy, Unit::Energy::KilowattHour>::FromStandard<NumericType>      },
        {Unit::Energy::MegawattMinute,
         Conversions<Unit::Energy, Unit::Energy::MegawattMinute>::FromStandard<NumericType>    },
        {Unit::Energy::MegawattHour,
         Conversions<Unit::Energy, Unit::Energy::MegawattHour>::FromStandard<NumericType>      },
        {Unit::Energy::GigawattMinute,
         Conversions<Unit::Energy, Unit::Energy::GigawattMinute>::FromStandard<NumericType>    },
        {Unit::Energy::GigawattHour,
         Conversions<Unit::Energy, Unit::Energy::GigawattHour>::FromStandard<NumericType>      },
        {Unit::Energy::FootPound,
         Conversions<Unit::Energy, Unit::Energy::FootPound>::FromStandard<NumericType>         },
        {Unit::Energy::InchPound,
         Conversions<Unit::Energy, Unit::Energy::InchPound>::FromStandard<NumericType>         },
        {Unit::Energy::Calorie,
         Conversions<Unit::Energy, Unit::Energy::Calorie>::FromStandard<NumericType>           },
        {Unit::Energy::Millicalorie,
         Conversions<Unit::Energy, Unit::Energy::Millicalorie>::FromStandard<NumericType>      },
        {Unit::Energy::Microcalorie,
         Conversions<Unit::Energy, Unit::Energy::Microcalorie>::FromStandard<NumericType>      },
        {Unit::Energy::Nanocalorie,
         Conversions<Unit::Energy, Unit::Energy::Nanocalorie>::FromStandard<NumericType>       },
        {Unit::Energy::Kilocalorie,
         Conversions<Unit::Energy, Unit::Energy::Kilocalorie>::FromStandard<NumericType>       },
        {Unit::Energy::Megacalorie,
         Conversions<Unit::Energy, Unit::Energy::Megacalorie>::FromStandard<NumericType>       },
        {Unit::Energy::Gigacalorie,
         Conversions<Unit::Energy, Unit::Energy::Gigacalorie>::FromStandard<NumericType>       },
        {Unit::Energy::Electronvolt,
         Conversions<Unit::Energy, Unit::Energy::Electronvolt>::FromStandard<NumericType>      },
        {Unit::Energy::Millielectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Millielectronvolt>::FromStandard<NumericType> },
        {Unit::Energy::Microelectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Microelectronvolt>::FromStandard<NumericType> },
        {Unit::Energy::Nanoelectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Nanoelectronvolt>::FromStandard<NumericType>  },
        {Unit::Energy::Kiloelectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Kiloelectronvolt>::FromStandard<NumericType>  },
        {Unit::Energy::Megaelectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Megaelectronvolt>::FromStandard<NumericType>  },
        {Unit::Energy::Gigaelectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Gigaelectronvolt>::FromStandard<NumericType>  },
        {Unit::Energy::BritishThermalUnit,
         Conversions<Unit::Energy, Unit::Energy::BritishThermalUnit>::FromStandard<NumericType>},
};

template <typename NumericType>
inline const std::map<Unit::Energy,
                      std::function<void(NumericType* const values, const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Energy, NumericType>{
        {Unit::Energy::Joule,
         Conversions<Unit::Energy, Unit::Energy::Joule>::ToStandard<NumericType>             },
        {Unit::Energy::Millijoule,
         Conversions<Unit::Energy, Unit::Energy::Millijoule>::ToStandard<NumericType>        },
        {Unit::Energy::Microjoule,
         Conversions<Unit::Energy, Unit::Energy::Microjoule>::ToStandard<NumericType>        },
        {Unit::Energy::Nanojoule,
         Conversions<Unit::Energy, Unit::Energy::Nanojoule>::ToStandard<NumericType>         },
        {Unit::Energy::Kilojoule,
         Conversions<Unit::Energy, Unit::Energy::Kilojoule>::ToStandard<NumericType>         },
        {Unit::Energy::Megajoule,
         Conversions<Unit::Energy, Unit::Energy::Megajoule>::ToStandard<NumericType>         },
        {Unit::Energy::Gigajoule,
         Conversions<Unit::Energy, Unit::Energy::Gigajoule>::ToStandard<NumericType>         },
        {Unit::Energy::WattMinute,
         Conversions<Unit::Energy, Unit::Energy::WattMinute>::ToStandard<NumericType>        },
        {Unit::Energy::WattHour,
         Conversions<Unit::Energy, Unit::Energy::WattHour>::ToStandard<NumericType>          },
        {Unit::Energy::KilowattMinute,
         Conversions<Unit::Energy, Unit::Energy::KilowattMinute>::ToStandard<NumericType>    },
        {Unit::Energy::KilowattHour,
         Conversions<Unit::Energy, Unit::Energy::KilowattHour>::ToStandard<NumericType>      },
        {Unit::Energy::MegawattMinute,
         Conversions<Unit::Energy, Unit::Energy::MegawattMinute>::ToStandard<NumericType>    },
        {Unit::Energy::MegawattHour,
         Conversions<Unit::Energy, Unit::Energy::MegawattHour>::ToStandard<NumericType>      },
        {Unit::Energy::GigawattMinute,
         Conversions<Unit::Energy, Unit::Energy::GigawattMinute>::ToStandard<NumericType>    },
        {Unit::Energy::GigawattHour,
         Conversions<Unit::Energy, Unit::Energy::GigawattHour>::ToStandard<NumericType>      },
        {Unit::Energy::FootPound,
         Conversions<Unit::Energy, Unit::Energy::FootPound>::ToStandard<NumericType>         },
        {Unit::Energy::InchPound,
         Conversions<Unit::Energy, Unit::Energy::InchPound>::ToStandard<NumericType>         },
        {Unit::Energy::Calorie,
         Conversions<Unit::Energy, Unit::Energy::Calorie>::ToStandard<NumericType>           },
        {Unit::Energy::Millicalorie,
         Conversions<Unit::Energy, Unit::Energy::Millicalorie>::ToStandard<NumericType>      },
        {Unit::Energy::Microcalorie,
         Conversions<Unit::Energy, Unit::Energy::Microcalorie>::ToStandard<NumericType>      },
        {Unit::Energy::Nanocalorie,
         Conversions<Unit::Energy, Unit::Energy::Nanocalorie>::ToStandard<NumericType>       },
        {Unit::Energy::Kilocalorie,
         Conversions<Unit::Energy, Unit::Energy::Kilocalorie>::ToStandard<NumericType>       },
        {Unit::Energy::Megacalorie,
         Conversions<Unit::Energy, Unit::Energy::Megacalorie>::ToStandard<NumericType>       },
        {Unit::Energy::Gigacalorie,
         Conversions<Unit::Energy, Unit::Energy::Gigacalorie>::ToStandard<NumericType>       },
        {Unit::Energy::Electronvolt,
         Conversions<Unit::Energy, Unit::Energy::Electronvolt>::ToStandard<NumericType>      },
        {Unit::Energy::Millielectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Millielectronvolt>::ToStandard<NumericType> },
        {Unit::Energy::Microelectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Microelectronvolt>::ToStandard<NumericType> },
        {Unit::Energy::Nanoelectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Nanoelectronvolt>::ToStandard<NumericType>  },
        {Unit::Energy::Kiloelectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Kiloelectronvolt>::ToStandard<NumericType>  },
        {Unit::Energy::Megaelectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Megaelectronvolt>::ToStandard<NumericType>  },
        {Unit::Energy::Gigaelectronvolt,
         Conversions<Unit::Energy, Unit::Energy::Gigaelectronvolt>::ToStandard<NumericType>  },
        {Unit::Energy::BritishThermalUnit,
         Conversions<Unit::Energy, Unit::Energy::BritishThermalUnit>::ToStandard<NumericType>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHQ_UNIT_ENERGY_HPP
