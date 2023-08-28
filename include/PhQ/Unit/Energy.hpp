// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_HPP

#include "../Unit.hpp"

namespace PhQ {

namespace Unit {

// Energy units.
enum class Energy : int8_t {
  Joule,
  Millijoule,
  Microjoule,
  Nanojoule,
  Kilojoule,
  Megajoule,
  Gigajoule,
  WattMinute,
  WattHour,
  KilowattMinute,
  KilowattHour,
  MegawattMinute,
  MegawattHour,
  GigawattMinute,
  GigawattHour,
  FootPound,
  InchPound,
  Calorie,
  Millicalorie,
  Microcalorie,
  Nanocalorie,
  Kilocalorie,
  Megacalorie,
  Gigacalorie,
  Electronvolt,
  Millielectronvolt,
  Microelectronvolt,
  Nanoelectronvolt,
  Kiloelectronvolt,
  Megaelectronvolt,
  Gigaelectronvolt,
  BritishThermalUnit,
};

}  // namespace Unit

// Standard energy unit: joule.
template<>
inline constexpr const Unit::Energy Standard<Unit::Energy>{Unit::Energy::Joule};

// Physical dimension set of energy units.
template<> inline constexpr const Dimensions RelatedDimensions<Unit::Energy>{
    Dimensions{Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1}}
};

namespace Internal {

template<>
inline const std::map<UnitSystem, Unit::Energy> ConsistentUnits<Unit::Energy>{
    {UnitSystem::MetreKilogramSecondKelvin,  Unit::Energy::Joule    },
    {UnitSystem::MillimetreGramSecondKelvin, Unit::Energy::Nanojoule},
    {UnitSystem::FootPoundSecondRankine,     Unit::Energy::FootPound},
    {UnitSystem::InchPoundSecondRankine,     Unit::Energy::InchPound},
};

template<>
inline const std::map<Unit::Energy, UnitSystem> RelatedUnitSystems<Unit::Energy>{
    {Unit::Energy::Joule,     UnitSystem::MetreKilogramSecondKelvin },
    {Unit::Energy::Nanojoule, UnitSystem::MillimetreGramSecondKelvin},
    {Unit::Energy::FootPound, UnitSystem::FootPoundSecondRankine    },
    {Unit::Energy::InchPound, UnitSystem::InchPoundSecondRankine    },
};

template<> inline const std::map<Unit::Energy, std::string_view>
    Abbreviations<Unit::Energy>{
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

template<>
inline const std::unordered_map<std::string_view, Unit::Energy> Spellings<
    Unit::Energy>{
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

template<>
inline constexpr void ConversionFromStandard<Unit::Energy, Unit::Energy::Joule>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Millijoule>(
    double& value) noexcept {
  value *= 1000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Microjoule>(
    double& value) noexcept {
  value *= 1000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Nanojoule>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Kilojoule>(
    double& value) noexcept {
  value *= 0.001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Megajoule>(
    double& value) noexcept {
  value *= 0.000001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Gigajoule>(
    double& value) noexcept {
  value *= 0.000000001;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::WattMinute>(
    double& value) noexcept {
  value /= 60.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::WattHour>(
    double& value) noexcept {
  value /= 3600.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::KilowattMinute>(
    double& value) noexcept {
  value /= 60000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::KilowattHour>(
    double& value) noexcept {
  value /= 3600000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::MegawattMinute>(
    double& value) noexcept {
  value /= 60000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::MegawattHour>(
    double& value) noexcept {
  value /= 3600000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::GigawattMinute>(
    double& value) noexcept {
  value /= 60000000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::GigawattHour>(
    double& value) noexcept {
  value /= 3600000000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::FootPound>(
    double& value) noexcept {
  value /= 0.3048 * 0.45359237 * 9.80665;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::InchPound>(
    double& value) noexcept {
  value /= 0.0254 * 0.45359237 * 9.80665;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Calorie>(
    double& value) noexcept {
  value /= 4.184;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Millicalorie>(
    double& value) noexcept {
  value /= 0.004184;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Microcalorie>(
    double& value) noexcept {
  value /= 0.000004184;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Nanocalorie>(
    double& value) noexcept {
  value /= 0.000000004184;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Kilocalorie>(
    double& value) noexcept {
  value /= 4184.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Megacalorie>(
    double& value) noexcept {
  value /= 4184000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Gigacalorie>(
    double& value) noexcept {
  value /= 4184000000.0;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Electronvolt>(
    double& value) noexcept {
  value /= 1.602176634e-19;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Millielectronvolt>(
    double& value) noexcept {
  value /= 1.602176634e-22;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Microelectronvolt>(
    double& value) noexcept {
  value /= 1.602176634e-25;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Nanoelectronvolt>(
    double& value) noexcept {
  value /= 1.602176634e-28;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Kiloelectronvolt>(
    double& value) noexcept {
  value /= 1.602176634e-16;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Megaelectronvolt>(
    double& value) noexcept {
  value /= 1.602176634e-13;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::Gigaelectronvolt>(
    double& value) noexcept {
  value /= 1.602176634e-10;
}

template<> inline constexpr void
ConversionFromStandard<Unit::Energy, Unit::Energy::BritishThermalUnit>(
    double& value) noexcept {
  value *= 1.8 / (4.1868 * 453.59237);
}

template<>
inline constexpr void ConversionToStandard<Unit::Energy, Unit::Energy::Joule>(
    double& value) noexcept {}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Millijoule>(
    double& value) noexcept {
  value *= 0.001;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Microjoule>(
    double& value) noexcept {
  value *= 0.000001;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Nanojoule>(
    double& value) noexcept {
  value *= 0.000000001;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Kilojoule>(
    double& value) noexcept {
  value *= 1000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Megajoule>(
    double& value) noexcept {
  value *= 1000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Gigajoule>(
    double& value) noexcept {
  value *= 1000000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::WattMinute>(
    double& value) noexcept {
  value *= 60.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::WattHour>(
    double& value) noexcept {
  value *= 3600.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::KilowattMinute>(
    double& value) noexcept {
  value *= 60000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::KilowattHour>(
    double& value) noexcept {
  value *= 3600000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::MegawattMinute>(
    double& value) noexcept {
  value *= 60000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::MegawattHour>(
    double& value) noexcept {
  value *= 3600000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::GigawattMinute>(
    double& value) noexcept {
  value *= 60000000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::GigawattHour>(
    double& value) noexcept {
  value *= 3600000000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::FootPound>(
    double& value) noexcept {
  value *= 0.3048 * 0.45359237 * 9.80665;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::InchPound>(
    double& value) noexcept {
  value *= 0.0254 * 0.45359237 * 9.80665;
}

template<>
inline constexpr void ConversionToStandard<Unit::Energy, Unit::Energy::Calorie>(
    double& value) noexcept {
  value *= 4.184;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Millicalorie>(
    double& value) noexcept {
  value *= 0.004184;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Microcalorie>(
    double& value) noexcept {
  value *= 0.000004184;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Nanocalorie>(
    double& value) noexcept {
  value *= 0.000000004184;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Kilocalorie>(
    double& value) noexcept {
  value *= 4184.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Megacalorie>(
    double& value) noexcept {
  value *= 4184000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Gigacalorie>(
    double& value) noexcept {
  value *= 4184000000.0;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Electronvolt>(
    double& value) noexcept {
  value *= 1.602176634e-19;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Millielectronvolt>(
    double& value) noexcept {
  value *= 1.602176634e-22;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Microelectronvolt>(
    double& value) noexcept {
  value *= 1.602176634e-25;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Nanoelectronvolt>(
    double& value) noexcept {
  value *= 1.602176634e-28;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Kiloelectronvolt>(
    double& value) noexcept {
  value *= 1.602176634e-16;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Megaelectronvolt>(
    double& value) noexcept {
  value *= 1.602176634e-13;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::Gigaelectronvolt>(
    double& value) noexcept {
  value *= 1.602176634e-10;
}

template<> inline constexpr void
ConversionToStandard<Unit::Energy, Unit::Energy::BritishThermalUnit>(
    double& value) noexcept {
  value *= 4.1868 * 453.59237 / 1.8;
}

template<> inline const std::map<
    Unit::Energy, std::function<void(double* values, const std::size_t size)>>
    MapOfConversionsFromStandard<Unit::Energy>{
        {Unit::Energy::Joule,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Joule>            },
        {Unit::Energy::Millijoule,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Millijoule>       },
        {Unit::Energy::Microjoule,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Microjoule>       },
        {Unit::Energy::Nanojoule,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Nanojoule>        },
        {Unit::Energy::Kilojoule,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Kilojoule>        },
        {Unit::Energy::Megajoule,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Megajoule>        },
        {Unit::Energy::Gigajoule,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Gigajoule>        },
        {Unit::Energy::WattMinute,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::WattMinute>       },
        {Unit::Energy::WattHour,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::WattHour>         },
        {Unit::Energy::KilowattMinute,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::KilowattMinute>   },
        {Unit::Energy::KilowattHour,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::KilowattHour>     },
        {Unit::Energy::MegawattMinute,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::MegawattMinute>   },
        {Unit::Energy::MegawattHour,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::MegawattHour>     },
        {Unit::Energy::GigawattMinute,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::GigawattMinute>   },
        {Unit::Energy::GigawattHour,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::GigawattHour>     },
        {Unit::Energy::FootPound,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::FootPound>        },
        {Unit::Energy::InchPound,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::InchPound>        },
        {Unit::Energy::Calorie,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Calorie>          },
        {Unit::Energy::Millicalorie,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Millicalorie>     },
        {Unit::Energy::Microcalorie,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Microcalorie>     },
        {Unit::Energy::Nanocalorie,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Nanocalorie>      },
        {Unit::Energy::Kilocalorie,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Kilocalorie>      },
        {Unit::Energy::Megacalorie,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Megacalorie>      },
        {Unit::Energy::Gigacalorie,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Gigacalorie>      },
        {Unit::Energy::Electronvolt,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Electronvolt>     },
        {Unit::Energy::Millielectronvolt,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Millielectronvolt>},
        {Unit::Energy::Microelectronvolt,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Microelectronvolt>},
        {Unit::Energy::Nanoelectronvolt,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Nanoelectronvolt> },
        {Unit::Energy::Kiloelectronvolt,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Kiloelectronvolt> },
        {Unit::Energy::Megaelectronvolt,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Megaelectronvolt> },
        {Unit::Energy::Gigaelectronvolt,
         ConversionsFromStandard<Unit::Energy, Unit::Energy::Gigaelectronvolt> },
        {Unit::Energy::BritishThermalUnit,
         ConversionsFromStandard<Unit::Energy,
         Unit::Energy::BritishThermalUnit>                                     },
};

template<>
inline const std::map<Unit::Energy, std::function<void(double* const values,
                                                       const std::size_t size)>>
    MapOfConversionsToStandard<Unit::Energy>{
        {Unit::Energy::Joule,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Joule>             },
        {Unit::Energy::Millijoule,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Millijoule>        },
        {Unit::Energy::Microjoule,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Microjoule>        },
        {Unit::Energy::Nanojoule,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Nanojoule>         },
        {Unit::Energy::Kilojoule,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Kilojoule>         },
        {Unit::Energy::Megajoule,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Megajoule>         },
        {Unit::Energy::Gigajoule,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Gigajoule>         },
        {Unit::Energy::WattMinute,
         ConversionsToStandard<Unit::Energy, Unit::Energy::WattMinute>        },
        {Unit::Energy::WattHour,
         ConversionsToStandard<Unit::Energy, Unit::Energy::WattHour>          },
        {Unit::Energy::KilowattMinute,
         ConversionsToStandard<Unit::Energy, Unit::Energy::KilowattMinute>    },
        {Unit::Energy::KilowattHour,
         ConversionsToStandard<Unit::Energy, Unit::Energy::KilowattHour>      },
        {Unit::Energy::MegawattMinute,
         ConversionsToStandard<Unit::Energy, Unit::Energy::MegawattMinute>    },
        {Unit::Energy::MegawattHour,
         ConversionsToStandard<Unit::Energy, Unit::Energy::MegawattHour>      },
        {Unit::Energy::GigawattMinute,
         ConversionsToStandard<Unit::Energy, Unit::Energy::GigawattMinute>    },
        {Unit::Energy::GigawattHour,
         ConversionsToStandard<Unit::Energy, Unit::Energy::GigawattHour>      },
        {Unit::Energy::FootPound,
         ConversionsToStandard<Unit::Energy, Unit::Energy::FootPound>         },
        {Unit::Energy::InchPound,
         ConversionsToStandard<Unit::Energy, Unit::Energy::InchPound>         },
        {Unit::Energy::Calorie,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Calorie>           },
        {Unit::Energy::Millicalorie,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Millicalorie>      },
        {Unit::Energy::Microcalorie,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Microcalorie>      },
        {Unit::Energy::Nanocalorie,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Nanocalorie>       },
        {Unit::Energy::Kilocalorie,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Kilocalorie>       },
        {Unit::Energy::Megacalorie,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Megacalorie>       },
        {Unit::Energy::Gigacalorie,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Gigacalorie>       },
        {Unit::Energy::Electronvolt,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Electronvolt>      },
        {Unit::Energy::Millielectronvolt,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Millielectronvolt> },
        {Unit::Energy::Microelectronvolt,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Microelectronvolt> },
        {Unit::Energy::Nanoelectronvolt,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Nanoelectronvolt>  },
        {Unit::Energy::Kiloelectronvolt,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Kiloelectronvolt>  },
        {Unit::Energy::Megaelectronvolt,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Megaelectronvolt>  },
        {Unit::Energy::Gigaelectronvolt,
         ConversionsToStandard<Unit::Energy, Unit::Energy::Gigaelectronvolt>  },
        {Unit::Energy::BritishThermalUnit,
         ConversionsToStandard<Unit::Energy, Unit::Energy::BritishThermalUnit>},
};

}  // namespace Internal

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_UNIT_ENERGY_HPP
